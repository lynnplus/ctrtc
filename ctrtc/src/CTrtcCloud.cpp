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



#include "CTrtcCloud.h"
#include "ITRTCCloud.h"

CTrtcCloud getTrtcGlobalShareInstance() {
    ITRTCCloud *cloud = getTRTCShareInstance();
    return cloud;
}

void destroyTrtcGlobalShareInstance() {
    destroyTRTCShareInstance();
}

CTrtcCloud createTrtcSubCloud() {
    ITRTCCloud *cloud = getTRTCShareInstance();
    return cloud->createSubCloud();
}

void destroyTrtcSubCloud(CTrtcCloud obj) {
    auto *subCloud = static_cast<ITRTCCloud *>(obj);
    ITRTCCloud *cloud = getTRTCShareInstance();
    cloud->destroySubCloud(subCloud);
}

const char *getTrtcSDKVersion(CTrtcCloud obj) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    return cloud->getSDKVersion();
}

void setTrtcConsoleEnabled(CTrtcCloud obj, bool enable) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setConsoleEnabled(enable);
}

void setTrtcLogCompressEnabled(CTrtcCloud obj, bool enable) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setLogCompressEnabled(enable);
}

void setTrtcLogDirPath(CTrtcCloud obj, const char *path) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setLogDirPath(path);
}

void setTrtcLogLevel(CTrtcCloud obj, CTRTCLogLevel level) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setLogLevel(static_cast<TRTCLogLevel>(level));
}

void setLogCallback(CTrtcCloud obj) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    //cloud->setLogCallback();
}

void addTrtcCallback(CTrtcCloud obj, CTrtcCloudCallback *callback) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->addCallback(static_cast<ITRTCCloudCallback *>(callback->proxy));
}

void removeTrtcCallback(CTrtcCloud obj, CTrtcCloudCallback *callback) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->removeCallback(static_cast<ITRTCCloudCallback *>(callback->proxy));
}

void setTrtcVideoEncoderParam(CTrtcCloud obj, CTRTCVideoEncParam *param) {
    TRTCVideoEncParam encParam;
    encParam.videoResolution = static_cast<TRTCVideoResolution>(param->videoResolution);
    encParam.videoBitrate = param->videoBitrate;
    encParam.videoFps = param->videoFps;
    encParam.enableAdjustRes = param->enableAdjustRes;
    encParam.minVideoBitrate = param->minVideoBitrate;
    encParam.resMode = static_cast<TRTCVideoResolutionMode>(param->resMode);
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setVideoEncoderParam(encParam);
}

void enterTrtcRoom(CTrtcCloud obj, const CTRTCParams *param, CTRTCAppScene scene) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    liteav::TRTCParams trtcParams;
    trtcParams.role = static_cast<TRTCRoleType>(param->role);
    trtcParams.roomId = param->roomId;
    trtcParams.sdkAppId = param->sdkAppId;
    trtcParams.userId = param->userId;
    trtcParams.strRoomId = param->strRoomId;
    trtcParams.businessInfo = param->businessInfo;
    trtcParams.privateMapKey = param->privateMapKey;
    trtcParams.userSig = param->userSig;
    cloud->enterRoom(trtcParams, static_cast<TRTCAppScene>(scene));
}

void startTrtcLocalTest(CTrtcCloud obj) {
    getTRTCShareInstance()->startLocalAudio(liteav::TRTCAudioQualityDefault);
    getTRTCShareInstance()->startLocalPreview(nullptr);
}

void exitTrtcRoom(CTrtcCloud obj) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->exitRoom();
}

void setTrtcDefaultStreamRecvMode(CTrtcCloud obj, bool autoRecvAudio, bool autoRecvVideo) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->setDefaultStreamRecvMode(autoRecvAudio, autoRecvVideo);
}

void enableTrtcCustomVideoCapture(CTrtcCloud obj, CTRTCVideoStreamType streamType, bool enable) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->enableCustomVideoCapture(static_cast<TRTCVideoStreamType>(streamType), enable);
}

void enableTrtcCustomAudioCapture(CTrtcCloud obj, bool enable) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->enableCustomAudioCapture(enable);
}

uint64_t generateTrtcCustomPTS(CTrtcCloud obj) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    return cloud->generateCustomPTS();
}

void sendTrtcCustomVideoData(CTrtcCloud obj, CTRTCVideoStreamType streamType, int width, int height, char *i420Buffer,
                             int length, uint64_t timestamp, CTRTCVideoRotation rotation) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    liteav::TRTCVideoFrame frame;
    frame.bufferType = liteav::TRTCVideoBufferType_Buffer;
    frame.videoFormat = liteav::TRTCVideoPixelFormat_I420;
    frame.data = i420Buffer;
    frame.length = length;
    frame.width = width;
    frame.height = height;
    frame.rotation = static_cast<TRTCVideoRotation>(rotation);
    frame.timestamp = timestamp;
    cloud->sendCustomVideoData(static_cast<TRTCVideoStreamType>(streamType), &frame);
}

void muteTrtcLocalVideo(CTrtcCloud obj, CTRTCVideoStreamType streamType, bool mute) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->muteLocalVideo(static_cast<TRTCVideoStreamType>(streamType), mute);
}

void muteTrtcLocalAudio(CTrtcCloud obj, bool mute) {
    auto *cloud = static_cast<ITRTCCloud *>(obj);
    cloud->muteLocalAudio(mute);
}
