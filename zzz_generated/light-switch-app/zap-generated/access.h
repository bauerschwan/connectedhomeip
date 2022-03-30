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

// Prevent multiple inclusion
#pragma once

#include <app/util/privilege-storage.h>

// Prevent changing generated format
// clang-format off

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, attribute, privilege) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__CLUSTER { \
    31, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    31, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
}

// Parallel array data (cluster, *attribute*, privilege) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__ATTRIBUTE { \
    0, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    1, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    0, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
}

// Parallel array data (cluster, attribute, *privilege*) for read attribute
#define GENERATED_ACCESS_READ_ATTRIBUTE__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Attribute: NOCs, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, attribute, privilege) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__CLUSTER { \
    31, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    31, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
}

// Parallel array data (cluster, *attribute*, privilege) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__ATTRIBUTE { \
    0, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    1, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
}

// Parallel array data (cluster, attribute, *privilege*) for write attribute
#define GENERATED_ACCESS_WRITE_ATTRIBUTE__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: ACL, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Attribute: Extension, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, command, privilege) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__CLUSTER { \
    62, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    62, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

// Parallel array data (cluster, *command*, privilege) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__COMMAND { \
    0, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    2, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    4, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    6, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    7, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    9, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    10, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    11, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    12, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

// Parallel array data (cluster, command, *privilege*) for invoke command
#define GENERATED_ACCESS_INVOKE_COMMAND__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AttestationRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: CertificateChainRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: CSRRequest, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AddNOC, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: UpdateNOC, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: UpdateFabricLabel, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: RemoveFabric, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: AddTrustedRootCertificate, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Operational Credentials, Command: RemoveTrustedRootCertificate, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// Parallel array data (*cluster*, event, privilege) for read event
#define GENERATED_ACCESS_READ_EVENT__CLUSTER { \
    31, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    31, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

// Parallel array data (cluster, *event*, privilege) for read event
#define GENERATED_ACCESS_READ_EVENT__EVENT { \
    0, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    1, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

// Parallel array data (cluster, event, *privilege*) for read event
#define GENERATED_ACCESS_READ_EVENT__PRIVILEGE { \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Event: AccessControlEntryChanged, Privilege: administer */ \
    kMatterAccessPrivilegeAdminister, /* Cluster: Access Control, Event: AccessControlExtensionChanged, Privilege: administer */ \
}

////////////////////////////////////////////////////////////////////////////////

// clang-format on
