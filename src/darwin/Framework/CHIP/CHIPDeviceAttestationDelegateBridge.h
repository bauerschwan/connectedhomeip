/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

#include <lib/core/NodeId.h>
#include <platform/CHIPDeviceBuildConfig.h>

#include <CHIP/CHIPDeviceAttestationDelegate.h>
#include <credentials/attestation_verifier/DeviceAttestationDelegate.h>

@class CHIPDeviceController;

NS_ASSUME_NONNULL_BEGIN

class CHIPDeviceAttestationDelegateBridge : public chip::Credentials::DeviceAttestationDelegate {
public:
    CHIPDeviceAttestationDelegateBridge(CHIPDeviceController * deviceController,
        id<CHIPDeviceAttestationDelegate> deviceAttestationDelegate, dispatch_queue_t queue,
        chip::Optional<uint16_t> expiryTimeoutSecs)
        : mResult(chip::Credentials::AttestationVerificationResult::kSuccess)
        , mDeviceController(deviceController)
        , mDeviceAttestationDelegate(deviceAttestationDelegate)
        , mQueue(queue)
        , mExpiryTimeoutSecs(expiryTimeoutSecs)
    {
    }

    ~CHIPDeviceAttestationDelegateBridge() {}

    chip::Optional<uint16_t> FailSafeExpiryTimeoutSecs() const override { return mExpiryTimeoutSecs; }

    void OnDeviceAttestationFailed(chip::Controller::DeviceCommissioner * deviceCommissioner, chip::DeviceProxy * device,
        chip::Credentials::AttestationVerificationResult attestationResult) override;

    chip::Credentials::AttestationVerificationResult attestationVerificationResult() const { return mResult; }

private:
    chip::Credentials::AttestationVerificationResult mResult;
    CHIPDeviceController * __weak mDeviceController;
    id<CHIPDeviceAttestationDelegate> mDeviceAttestationDelegate;
    dispatch_queue_t mQueue;
    chip::Optional<uint16_t> mExpiryTimeoutSecs;
};

NS_ASSUME_NONNULL_END
