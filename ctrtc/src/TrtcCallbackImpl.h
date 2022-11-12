/*
 * Copyright (c) 2022 Lynn <lynnplus90@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//

#ifndef CTRTC_TRTCCALLBACKIMPL_H
#define CTRTC_TRTCCALLBACKIMPL_H


#include "TRTCCloudCallback.h"
#include "CTrtcCloudCallback.h"

class TrtcCallbackImpl : public ITRTCCloudCallback {

public:
    explicit TrtcCallbackImpl(const CTrtcCloudCallback *callback);

    ~TrtcCallbackImpl() override;

private:
    const CTrtcCloudCallback *callback;

public:
    void onError(TXLiteAVError errCode, const char *errMsg, void *extraInfo) override;

    void onWarning(TXLiteAVWarning warningCode, const char *warningMsg, void *extraInfo) override;

    void onEnterRoom(int result) override;

    void onExitRoom(int reason) override;

    void onRemoteUserEnterRoom(const char *userId) override;

    void onRemoteUserLeaveRoom(const char *userId, int reason) override;

    void onSendFirstLocalVideoFrame(TRTCVideoStreamType streamType) override;

    void onSendFirstLocalAudioFrame() override;

    void onConnectionLost() override;

    void onTryToReconnect() override;

    void onConnectionRecovery() override;
};


#endif //CTRTC_TRTCCALLBACKIMPL_H
