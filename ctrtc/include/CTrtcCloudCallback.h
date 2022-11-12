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

#ifndef CTRTC_CTRTCCLOUDCALLBACK_H
#define CTRTC_CTRTCCLOUDCALLBACK_H


#include "CTypeDef.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void(*TrtcCBErrorFunc)(void *ctx, int errCode, const char *errMsg, void *extraInfo);
typedef void(*TrtcCBWarnFunc)(void *ctx, int warningCode, const char *warningMsg, void *extraInfo);
typedef void(*TrtcCBEnterRoomFunc)(void *ctx, int result);
typedef void(*TrtcCBExitRoomFunc)(void *ctx, int reason);
typedef void(*TrtcCBRemoteUserEnterRoomFunc)(void *ctx, const char *userId);
typedef void(*TrtcCBRemoteUserLeaveRoomFunc)(void *ctx, const char *userId, int reason);
typedef void(*TrtcCBSendFirstLocalVideoFrameFunc)(void *ctx, int streamType);
typedef void(*TrtcCBSendFirstLocalAudioFrameFunc)(void *ctx);

typedef void(*TrtcCBConnectionLostFunc)(void *ctx);
typedef void(*TrtcCBTryToReconnectFunc)(void *ctx);
typedef void(*TrtcCBConnectionRecoveryFunc)(void *ctx);

typedef void(*TrtcLogCallbackFunc)(void *ctx, const char *log, CTRTCLogLevel level, const char *module);


typedef struct {
    void *ctx;
    void *proxy;
    TrtcCBErrorFunc onError;
    TrtcCBWarnFunc onWarning;
    TrtcCBEnterRoomFunc onEnterRoom;
    TrtcCBExitRoomFunc onExitRoom;
    TrtcCBRemoteUserEnterRoomFunc onRemoteUserEnterRoom;
    TrtcCBRemoteUserLeaveRoomFunc onRemoteUserLeaveRoom;
    TrtcCBSendFirstLocalVideoFrameFunc onSendFirstLocalVideoFrame;
    TrtcCBSendFirstLocalAudioFrameFunc onSendFirstLocalAudioFrame;
    TrtcCBConnectionLostFunc onConnectionLost;
    TrtcCBTryToReconnectFunc onTryToReconnect;
    TrtcCBConnectionRecoveryFunc onConnectionRecovery;

} CTrtcCloudCallback;

API CTrtcCloudCallback *createTrtcCallback(void *ctx);
API void destroyTrtcCallback(CTrtcCloudCallback *cb);

#ifdef __cplusplus
}
#endif


#endif //CTRTC_CTRTCCLOUDCALLBACK_H
