#
#    Copyright (c) 2021 Project CHIP Authors
#    All rights reserved.
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#

# Needed to use types in type hints before they are fully defined.
from __future__ import annotations

import ctypes
from dataclasses import dataclass, field
from typing import *
from ctypes import *
from rich.pretty import pprint
import json
import logging
import builtins
import base64
import chip.exceptions
from chip import ChipDeviceCtrl
import copy


class FabricAdmin:
    ''' Administers a specific fabric as identified by the tuple of RCAC subject public key and Fabric ID.
        The Fabric ID can be passed into the constructor while the RCAC and ICAC are generated.
        The Fabric ID *does not* have to be unique across multiple FabricAdmin instances as
        it is scoped to the key pair used by the root CA and whose public key is in the RCAC.

        Each admin is identified by an 'admin index' that is unique to the running
        process. This is used to store credential information to disk so that
        it can be easily loaded later if neccessary (see 'Persistence' below for more details)

        When vending ChipDeviceController instances on a given fabric, each controller instance
        is associated with a unique fabric index. In the underlying FabricTable, each FabricInfo
        instance can be treated as unique identities that can collide on the same logical fabric.

        >> C++ Binding Details

        Each instance of the fabric admin is associated with a single instance
        of the OperationalCredentialsAdapter. This adapter instance implements
        the OperationalCredentialsDelegate and is meant to provide a Python
        adapter to the functions in that delegate so that the fabric admin
        can in turn, provide users the ability to generate their own NOCs for devices
        on the network (not implemented yet). For now, it relies on the in-built
        ExampleOperationalCredentialsIssuer to do that.

        TODO: Add support for FabricAdmin to permit callers to hook up their own GenerateNOC
              logic.

        >> Persistence

        Specifically, each instance persists its fabric ID and admin
        index to storage. This is in addition to the persistence built into the ExampleOperationalCredentialsIssuer that persists details
        about the RCAC/ICAC and associated keys as well. This facilitates re-construction of a fabric admin on subsequent
        boot for a given fabric and ensuring it automatically picks up the right ICAC/RCAC details as well.
    '''

    activeAdminIndexList = set()
    activeAdmins = set()

    @classmethod
    def _Handle(cls):
        return chip.native.GetLibraryHandle()

    def AllocateNextAdminIndex(self):
        ''' Allocate the next un-used admin index.
        '''
        nextAdminIndex = 1
        while nextAdminIndex in FabricAdmin.activeAdminIndexList:
            nextAdminIndex = nextAdminIndex + 1
        return nextAdminIndex

    def __init__(self, vendorId: int, adminIndex: int = None, fabricId: int = 1):
        ''' Creates a valid FabricAdmin object with valid RCAC/ICAC, and registers itself as an OperationalCredentialsDelegate
            for other parts of the system (notably, DeviceController) to vend NOCs.

            vendorId:       Valid operational Vendor ID associated with this fabric.
            adminIndex:     Local index to be associated with this fabric. This is NOT the fabric index. Each controller on the fabric
                            is assigned a unique fabric index.

                            If omitted, one will be automatically assigned.

            fabricId:       Fabric ID to be associated with this fabric. This is scoped to the public key of the resultant
                            root generated by the underlying ExampleOperationalCredentialsIssuer.
        '''
        self._handle = chip.native.GetLibraryHandle()

        if (vendorId is None or vendorId == 0):
            raise ValueError(
                f"Invalid VendorID ({vendorId}) provided!")

        self._vendorId = vendorId
        self._fabricId = fabricId

        if (adminIndex is None):
            self._adminIndex = self.AllocateNextAdminIndex()
        else:
            if (adminIndex in FabricAdmin.activeAdminIndexList):
                raise ValueError(
                    f"AdminIndex {adminIndex} is already being managed by an existing FabricAdmin object!")

            self._adminIndex = adminIndex

        FabricAdmin.activeAdminIndexList.add(self._adminIndex)

        print(
            f"New FabricAdmin: FabricId: 0x{self._fabricId:016X}, AdminIndex: {self._adminIndex}, VendorId = 0x{self.vendorId:04X}")
        self._Handle().pychip_OpCreds_InitializeDelegate.restype = c_void_p

        self.closure = builtins.chipStack.Call(
            lambda: self._Handle().pychip_OpCreds_InitializeDelegate(
                ctypes.py_object(self), ctypes.c_uint32(self._adminIndex))
        )

        if (self.closure is None):
            raise ValueError("Encountered error initializing OpCreds adapter")

        #
        # Persist details to storage (read modify write).
        #
        try:
            adminList = builtins.chipStack.GetStorageManager().GetReplKey('fabricAdmins')
        except KeyError:
            adminList = {str(self._adminIndex): {'fabricId': self._fabricId}}
            builtins.chipStack.GetStorageManager().SetReplKey('fabricAdmins', adminList)

        adminList[str(self._adminIndex)] = {'fabricId': self._fabricId, 'vendorId': self.vendorId}
        builtins.chipStack.GetStorageManager().SetReplKey('fabricAdmins', adminList)

        self._isActive = True
        self.nextControllerId = 112233

        FabricAdmin.activeAdmins.add(self)

    def NewController(self, nodeId: int = None, paaTrustStorePath: str = "", useTestCommissioner: bool = False):
        ''' Vend a new controller on this fabric seeded with the right fabric details.
        '''
        if (not(self._isActive)):
            raise RuntimeError(
                f"FabricAdmin object was previously shutdown and is no longer valid!")

        if (nodeId is None):
            nodeId = self.nextControllerId
            self.nextControllerId = self.nextControllerId + 1

        print(
            f"Allocating new controller with FabricId: 0x{self._fabricId:016X}, NodeId: 0x{nodeId:016X}")

        controller = ChipDeviceCtrl.ChipDeviceController(
            self.closure, self._fabricId, nodeId, self.vendorId, paaTrustStorePath, useTestCommissioner, fabricAdmin=self)
        return controller

    def ShutdownAll():
        ''' Shuts down all active fabrics, but without deleting them from storage.
        '''
        activeAdmins = copy.copy(FabricAdmin.activeAdmins)

        for admin in activeAdmins:
            admin.Shutdown(False)

        FabricAdmin.activeAdmins.clear()

    def Shutdown(self, deleteFromStorage: bool = True):
        ''' Shutdown this fabric and free up its resources. This is important since relying
            solely on the destructor will not guarantee relishining of C++-side resources.

            deleteFromStorage:      Whether to delete this fabric's details from persistent storage.
        '''
        if (self._isActive):
            builtins.chipStack.Call(
                lambda: self._Handle().pychip_OpCreds_FreeDelegate(
                    ctypes.c_void_p(self.closure))
            )

            FabricAdmin.activeAdminIndexList.remove(self._adminIndex)

            if (deleteFromStorage):
                adminList = builtins.chipStack.GetStorageManager().GetReplKey('fabricAdmins')
                del(adminList[str(self._adminIndex)])
                if (len(adminList) == 0):
                    adminList = None

                builtins.chipStack.GetStorageManager().SetReplKey('fabricAdmins', adminList)

            FabricAdmin.activeAdmins.remove(self)
            self._isActive = False

    def __del__(self):
        self.Shutdown(False)

    @property
    def vendorId(self) -> int:
        return self._vendorId

    @property
    def fabricId(self) -> int:
        return self._fabricId

    @property
    def adminIndex(self) -> int:
        return self._adminIndex
