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


#ifndef CTRTC_CTYPEDEF_H
#define CTRTC_CTYPEDEF_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>


#ifdef API_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

typedef enum {
    TRTCRoleAnchor = 20,
    TRTCRoleAudience = 21,
} CTRTCRoleType;

typedef enum {
    TRTCAppSceneVideoCall = 0,
    TRTCAppSceneLIVE = 1,
    TRTCAppSceneAudioCall = 2,
    TRTCAppSceneVoiceChatRoom = 3,
} CTRTCAppScene;

typedef enum {
    TRTCVideoStreamTypeBig = 0,
    TRTCVideoStreamTypeSmall = 1,
    TRTCVideoStreamTypeSub = 2,
} CTRTCVideoStreamType;

typedef enum {
    TRTCVideoBufferType_Unknown = 0,
    TRTCVideoBufferType_Buffer = 1,
    TRTCVideoBufferType_Texture = 3,

} CTRTCVideoBufferType;

typedef enum {
    TRTCVideoRotation0 = 0,
    TRTCVideoRotation90 = 1,
    TRTCVideoRotation180 = 2,
    TRTCVideoRotation270 = 3,
} CTRTCVideoRotation;

typedef enum {
    TRTCVideoResolutionModeLandscape = 0,
    TRTCVideoResolutionModePortrait = 1,
} CTRTCVideoResolutionMode;

typedef enum {
    TRTCLogLevelVerbose = 0,
    TRTCLogLevelDebug = 1,
    TRTCLogLevelInfo = 2,
    TRTCLogLevelWarn = 3,
    TRTCLogLevelError = 4,
    TRTCLogLevelFatal = 5,
    TRTCLogLevelNone = 6,
} CTRTCLogLevel;


typedef struct {
    uint64_t sdkAppId;
    const char *userId;
    const char *userSig;

    uint32_t roomId;

    const char *strRoomId;

    CTRTCRoleType role;

    const char *streamId;

    const char *userDefineRecordId;

    const char *privateMapKey;

    const char *businessInfo;
} CTRTCParams;

typedef struct {
    int videoResolution;
    CTRTCVideoResolutionMode resMode;
    uint32_t videoFps;
    uint32_t videoBitrate;
    uint32_t minVideoBitrate;
    bool enableAdjustRes;
} CTRTCVideoEncParam;

#ifdef __cplusplus
}
#endif


#endif //CTRTC_CTYPEDEF_H
