/**
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

#ifndef CHIP_DEVICE_CONTROLLER_STARTUP_PARAMS_H
#define CHIP_DEVICE_CONTROLLER_STARTUP_PARAMS_H

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CHIPKeypair;

@interface CHIPDeviceControllerStartupParams : NSObject
/**
 * Keypair used to sign operational certificates.  This is the root CA keypair
 * if not using an intermediate CA, the intermediate CA's keypair otherwise.
 */
@property (strong, nonatomic, readonly) id<CHIPKeypair> nocSigner;
/**
 * Fabric id for the controller.  Must be set to a nonzero value.  This is
 * scoped by the root public key, which is determined as follows:
 *
 * * If an intermediate CA is being used, the root public key is the public key
 *   of the root certificate (which must be known in that case).
 *
 * * If an intermediate CA is not being used, the root public key is the public
 *   key of the nocSigner keypair.
 */
@property (nonatomic, readonly) uint64_t fabricId;
/**
 * IPK to use for the controller's fabric.  Allowed to change from the last time
 * a controller was started on this fabric if a new IPK has been distributed to
 * all the devices the controller wants to interact with.
 */
@property (strong, nonatomic, readonly) NSData * ipk;

/**
 * Vendor ID (allocated by the Connectivity Standards Alliance) for
 * this controller.
 *
 * If not nil, must not be the "standard" vendor id (0).
 *
 * When creating a new fabric:
 *
 * * Must not be nil.
 *
 * When using an existing fabric:
 *
 * * Will override existing value if not nil. Otherwise existing value will be
 *   used.
 */
@property (strong, nonatomic, nullable) NSNumber * vendorId;

/**
 * Node id for this controller.
 *
 * If not nil, must be a valid Matter operational node id.
 *
 * When creating a new fabric:
 *
 * * Allowed to be nil to indicate that a random node id should be generated.
 *
 * When using an existing fabric:
 *
 * * Allowed to be nil to indicate that the existing operational identity (node
 *   id and operational keys) should be used.
 *
 * * If not nil, a new operational certificate will be generated for the
 *   provided node id (even if that matches the existing node id), using a new
 *   operational key.
 *
 */
@property (strong, nonatomic, nullable) NSNumber * nodeId;

// TODO: Add something here for CATs?

/**
 * Root certificate, in X.509 DER form, to use.
 *
 * Must not be nil if an intermediate CA is being used, to allow determination
 * of the root public key.
 *
 * If not nil, and if an intermediate CA is not being used, the public key of
 * this certificate must match the public key of nocSigner.
 *
 * When creating a new fabric:
 *
 * * May be nil if an intermediate CA is not being used.  In that case the
 *   nocSigner keypair, which is the keypair for the root certificate, will be
 *   used to generate and sign a root certificate, with a random issuer id.  In
 *   this case, the fabricId will be included in the root certificate's subject
 *   DN.
 *
 * When using an existing fabric:
 *
 * * May be nil if an intermediate CA is not being used.  In that case, the
 *   existing root certificate for the fabric will be used.
 *
 * * If not nil must satisfy the following properties:
 *
 *   1) The public key must match the public key of the existing root
 *      certificate.
 *   2) The subject DN must match the subject DN of the existing root
 *      certificate.
 */
@property (strong, nonatomic, nullable) NSData * rootCertificate;

/**
 * Intermediate certificate, in X.509 DER form, to use.
 *
 * If not nil, rootCertificate must not be nil, and the intermediate certificate
 * must be signed by rootCertificate.
 *
 * If not nil, the public key of this certificate must match the public key of
 * nocSigner.
 *
 * When creating a new fabric:
 *
 * * Must not be nil if an intermediate CA is being used.
 *
 * * Must be nil if an intermediate CA is not being used.
 *
 * When using an existing fabric:
 *
 * * If not nil, will be used as the intermediate certificate for issuing
 *   operational certificates.
 *
 * * If nil:
 *
 *   * If there is an existing intermediate certificate, and it matches the
 *     nocSigner public key, the existing intermediate certificate will be used.
 *
 *   * Otherwise the fabric will not use an intermediate certificate.  This
 *     allows switching from using an intermediate CA to not using one.
 *
 */
@property (strong, nonatomic, nullable) NSData * intermediateCertificate;

- (instancetype)init NS_UNAVAILABLE;

/**
 * fabricId must be set to a valid (i.e. nonzero) value.
 *
 * ipk must be 16 bytes in length
 */
- (instancetype)initWithKeypair:(id<CHIPKeypair>)nocSigner fabricId:(uint64_t)fabricId ipk:(NSData *)ipk;

@end

NS_ASSUME_NONNULL_END

#endif // CHIP_DEVICE_CONTROLLER_STARTUP_PARAMS_H
