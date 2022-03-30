/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#pragma once

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app/InteractionModelEngine.h>
#include <app/data-model/DecodableList.h>
#include <app/util/af-enums.h>
#include <app/util/attribute-filter.h>
#include <app/util/im-client-callbacks.h>
#include <inttypes.h>
#include <lib/support/FunctionTraits.h>
#include <lib/support/Span.h>

// List specific responses
void ApplicationBasicClusterAllowedVendorListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                 chip::Callback::Cancelable * onSuccessCallback,
                                                                 chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationBasicAllowedVendorListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::VendorId> & data);
void ApplicationBasicClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                    chip::Callback::Cancelable * onSuccessCallback,
                                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationBasicGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ApplicationBasicClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                   chip::Callback::Cancelable * onSuccessCallback,
                                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationBasicAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ApplicationBasicClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                             chip::Callback::Cancelable * onSuccessCallback,
                                                             chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationBasicAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void ContentLauncherClusterAcceptHeaderListAttributeFilter(chip::TLV::TLVReader * data,
                                                           chip::Callback::Cancelable * onSuccessCallback,
                                                           chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherAcceptHeaderListAttributeCallback)(void * context,
                                                                 const chip::app::DataModel::DecodableList<chip::CharSpan> & data);
void ContentLauncherClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                   chip::Callback::Cancelable * onSuccessCallback,
                                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ContentLauncherClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                  chip::Callback::Cancelable * onSuccessCallback,
                                                                  chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ContentLauncherClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                            chip::Callback::Cancelable * onSuccessCallback,
                                                            chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void GeneralCommissioningClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                        chip::Callback::Cancelable * onSuccessCallback,
                                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralCommissioningGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void GeneralCommissioningClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                       chip::Callback::Cancelable * onSuccessCallback,
                                                                       chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralCommissioningAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void GeneralCommissioningClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                 chip::Callback::Cancelable * onSuccessCallback,
                                                                 chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralCommissioningAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void KeypadInputClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                               chip::Callback::Cancelable * onSuccessCallback,
                                                               chip::Callback::Cancelable * onFailureCallback);
typedef void (*KeypadInputGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void KeypadInputClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                              chip::Callback::Cancelable * onSuccessCallback,
                                                              chip::Callback::Cancelable * onFailureCallback);
typedef void (*KeypadInputAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void KeypadInputClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*KeypadInputAttributeListListAttributeCallback)(void * context,
                                                              const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void ModeSelectClusterSupportedModesListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*ModeSelectSupportedModesListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::ModeSelect::Structs::ModeOptionStruct::DecodableType> & data);
void ModeSelectClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                              chip::Callback::Cancelable * onSuccessCallback,
                                                              chip::Callback::Cancelable * onFailureCallback);
typedef void (*ModeSelectGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ModeSelectClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                             chip::Callback::Cancelable * onSuccessCallback,
                                                             chip::Callback::Cancelable * onFailureCallback);
typedef void (*ModeSelectAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ModeSelectClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                       chip::Callback::Cancelable * onFailureCallback);
typedef void (*ModeSelectAttributeListListAttributeCallback)(void * context,
                                                             const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void OperationalCredentialsClusterFabricsListAttributeFilter(chip::TLV::TLVReader * data,
                                                             chip::Callback::Cancelable * onSuccessCallback,
                                                             chip::Callback::Cancelable * onFailureCallback);
typedef void (*OperationalCredentialsFabricsListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::OperationalCredentials::Structs::FabricDescriptor::DecodableType> & data);
void OperationalCredentialsClusterTrustedRootCertificatesListAttributeFilter(chip::TLV::TLVReader * data,
                                                                             chip::Callback::Cancelable * onSuccessCallback,
                                                                             chip::Callback::Cancelable * onFailureCallback);
typedef void (*OperationalCredentialsTrustedRootCertificatesListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::ByteSpan> & data);
void RelativeHumidityMeasurementClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                               chip::Callback::Cancelable * onSuccessCallback,
                                                                               chip::Callback::Cancelable * onFailureCallback);
typedef void (*RelativeHumidityMeasurementGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void RelativeHumidityMeasurementClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                              chip::Callback::Cancelable * onSuccessCallback,
                                                                              chip::Callback::Cancelable * onFailureCallback);
typedef void (*RelativeHumidityMeasurementAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void RelativeHumidityMeasurementClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                        chip::Callback::Cancelable * onSuccessCallback,
                                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*RelativeHumidityMeasurementAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void SwitchClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*SwitchGeneratedCommandListListAttributeCallback)(void * context,
                                                                const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void SwitchClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                         chip::Callback::Cancelable * onSuccessCallback,
                                                         chip::Callback::Cancelable * onFailureCallback);
typedef void (*SwitchAcceptedCommandListListAttributeCallback)(void * context,
                                                               const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void SwitchClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*SwitchAttributeListListAttributeCallback)(void * context,
                                                         const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void TargetNavigatorClusterTargetListListAttributeFilter(chip::TLV::TLVReader * data,
                                                         chip::Callback::Cancelable * onSuccessCallback,
                                                         chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorTargetListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::TargetNavigator::Structs::TargetInfo::DecodableType> & data);
void TargetNavigatorClusterGeneratedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                   chip::Callback::Cancelable * onSuccessCallback,
                                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void TargetNavigatorClusterAcceptedCommandListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                  chip::Callback::Cancelable * onSuccessCallback,
                                                                  chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void TargetNavigatorClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                            chip::Callback::Cancelable * onSuccessCallback,
                                                            chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
void ThermostatUserInterfaceConfigurationClusterGeneratedCommandListListAttributeFilter(
    chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback, chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThermostatUserInterfaceConfigurationGeneratedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ThermostatUserInterfaceConfigurationClusterAcceptedCommandListListAttributeFilter(
    chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback, chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThermostatUserInterfaceConfigurationAcceptedCommandListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::CommandId> & data);
void ThermostatUserInterfaceConfigurationClusterAttributeListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                                 chip::Callback::Cancelable * onSuccessCallback,
                                                                                 chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThermostatUserInterfaceConfigurationAttributeListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::AttributeId> & data);
