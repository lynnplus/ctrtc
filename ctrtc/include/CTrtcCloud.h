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


#ifndef CTRTC_CTRTCCLOUD_H
#define CTRTC_CTRTCCLOUD_H


#include "CTypeDef.h"
#include "CTrtcCloudCallback.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef void *CTrtcCloud;

API void startTrtcLocalTest(CTrtcCloud obj);

API CTrtcCloud getTrtcGlobalShareInstance();
API void destroyTrtcGlobalShareInstance();

API CTrtcCloud createTrtcSubCloud();
API void destroyTrtcSubCloud(CTrtcCloud obj);

API void addTrtcCallback(CTrtcCloud obj, CTrtcCloudCallback *callback);
API void removeTrtcCallback(CTrtcCloud obj, CTrtcCloudCallback *callback);

API void setTrtcVideoEncoderParam(CTrtcCloud obj, CTRTCVideoEncParam *param);

API const char *getTrtcSDKVersion(CTrtcCloud obj);
API void setTrtcConsoleEnabled(CTrtcCloud obj, bool enable);
API void setTrtcLogCompressEnabled(CTrtcCloud obj, bool enable);
API void setTrtcLogDirPath(CTrtcCloud obj, const char *path);
API void setTrtcLogLevel(CTrtcCloud obj, CTRTCLogLevel level);

API void enterTrtcRoom(CTrtcCloud obj, const CTRTCParams *param, CTRTCAppScene scene);
API void exitTrtcRoom(CTrtcCloud obj);
API void setTrtcDefaultStreamRecvMode(CTrtcCloud obj, bool autoRecvAudio, bool autoRecvVideo);

API void enableTrtcCustomVideoCapture(CTrtcCloud obj, CTRTCVideoStreamType streamType, bool enable);
API void enableTrtcCustomAudioCapture(CTrtcCloud obj, bool enable);

API uint64_t generateTrtcCustomPTS(CTrtcCloud obj);


API void
sendTrtcCustomVideoData(CTrtcCloud obj, CTRTCVideoStreamType streamType, int width, int height, char *i420Buffer,
                        int length, uint64_t timestamp, CTRTCVideoRotation rotation);

API void muteTrtcLocalVideo(CTrtcCloud obj, CTRTCVideoStreamType streamType, bool mute);
API void muteTrtcLocalAudio(CTrtcCloud obj, bool mute);


#ifdef __cplusplus
}
#endif


#endif //CTRTC_CTRTCCLOUD_H
