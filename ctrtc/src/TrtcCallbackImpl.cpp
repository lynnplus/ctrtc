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


#include "TrtcCallbackImpl.h"


TrtcCallbackImpl::TrtcCallbackImpl(const CTrtcCloudCallback *callback) : callback(callback) {}

TrtcCallbackImpl::~TrtcCallbackImpl() {
    callback= nullptr;
}

void TrtcCallbackImpl::onError(TXLiteAVError errCode, const char *errMsg, void *extraInfo) {
    if(callback== nullptr||callback->onError== nullptr){
        return;
    }
    callback->onError(callback->ctx,errCode,errMsg,extraInfo);
}

void TrtcCallbackImpl::onWarning(TXLiteAVWarning warningCode, const char *warningMsg, void *extraInfo) {
    if(callback== nullptr||callback->onWarning== nullptr){
        return;
    }
    callback->onWarning(callback->ctx,warningCode,warningMsg,extraInfo);
}

void TrtcCallbackImpl::onEnterRoom(int result) {
    if(callback== nullptr||callback->onEnterRoom== nullptr){
        return;
    }
    callback->onEnterRoom(callback->ctx,result);
}

void TrtcCallbackImpl::onExitRoom(int reason) {
    if(callback== nullptr||callback->onExitRoom== nullptr){
        return;
    }
    callback->onExitRoom(callback->ctx,reason);
}

void TrtcCallbackImpl::onRemoteUserEnterRoom(const char *userId) {
    if(callback== nullptr||callback->onRemoteUserEnterRoom== nullptr){
        return;
    }
    callback->onRemoteUserEnterRoom(callback->ctx,userId);
}

void TrtcCallbackImpl::onRemoteUserLeaveRoom(const char *userId, int reason) {
    if(callback== nullptr||callback->onRemoteUserLeaveRoom== nullptr){
        return;
    }
    callback->onRemoteUserLeaveRoom(callback->ctx,userId,reason);
}

void TrtcCallbackImpl::onSendFirstLocalVideoFrame(const TRTCVideoStreamType streamType) {
    if(callback== nullptr||callback->onSendFirstLocalVideoFrame== nullptr){
        return;
    }
    callback->onSendFirstLocalVideoFrame(callback->ctx,streamType);
}

void TrtcCallbackImpl::onSendFirstLocalAudioFrame() {
    if(callback== nullptr||callback->onSendFirstLocalAudioFrame== nullptr){
        return;
    }
    callback->onSendFirstLocalAudioFrame(callback->ctx);
}

void TrtcCallbackImpl::onConnectionLost() {
    if(callback== nullptr||callback->onConnectionLost== nullptr){
        return;
    }
    callback->onConnectionLost(callback->ctx);
}

void TrtcCallbackImpl::onTryToReconnect() {
    if(callback== nullptr||callback->onTryToReconnect== nullptr){
        return;
    }
    callback->onTryToReconnect(callback->ctx);
}

void TrtcCallbackImpl::onConnectionRecovery() {
    if(callback== nullptr||callback->onConnectionRecovery== nullptr){
        return;
    }
    callback->onConnectionRecovery(callback->ctx);
}