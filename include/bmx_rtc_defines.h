//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_defines.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_defines_h
#define bmx_rtc_defines_h

#include <memory>
#include <string>
#include <vector>
#include "bmx_defines.h"

namespace floo {

enum class BMXSDKType {
  /// BMX
  BMXRTC,
  /// UCloud
  UCloudRTC
};

/**
 * @brief 音视频SDK模式
 **/
enum class BMXSDKMode {
  ///正常模式
  Normal,
  ///测试模式
  Test
};

/**
 * @brief 房间类型
 **/
enum class BMXRoomType {
  /// 会议模式
  Communication,
  /// 直播模式
  Broadcast
};

/**
 * @brief 角色模式
 **/
enum class BMXStreamRole {
  /// 推流发布角色
  Publish,
  /// 拉流订阅角色
  Subscribe,
  /// 两者都有
  Both
};

/**
 * @brief 视频编码类型
 **/
enum class BMXVideoCodec {
  ///VP8
  VP8,
  ///H264
  H264
};

/**
 * @brief 视频分辨率
 **/
enum class BMXVideoProfile {
  ///未定义
  None,
  ///240*180分辨率
  Profile_240_180,
  ///320*180分辨率
  Profile_320_180,
  ///320*240分辨率
  Profile_320_240,
  ///480*360分辨率
  Profile_480_360,
  ///640*360分辨率
  Profile_640_360,
  ///640*480分辨率
  Profile_640_480,
  ///960*720分辨率
  Profile_960_720,
  ///1280*720分辨率
  Profile_1280_720,
  ///1920*1080分辨率
  Profile_1920_1080
};

/**
 * @brief 视频属性配置
 **/
struct BMXVideoConfig {
  int width;
  int height;
  int frameRate;
  BMXVideoProfile profile;
};
typedef std::shared_ptr<BMXVideoConfig> BMXVideoConfigPtr;

/**
 * @brief 音频分辨率
 **/
enum class BMXAudioProfile {
  ///默认值，单声道，32k码率
  Default,
  /// 单声道，64k码率
  Stand,
  /// 双声道，标准立体声，80k码率
  Stand_Stereo,
  /// 单声道，高音质，96k码率
  Hight,
  /// 双声道，高音质，128k码率
  Hight_Stereo,
};

/**
 * @brief 认证信息
 **/
struct BMXRoomAuth {
  int64_t mRoomId;
  std::string mToken;
  std::string mOptionalInfo;
  int64_t mUserId;
};
typedef std::shared_ptr<BMXRoomAuth> BMXRoomAuthPtr;

/**
 * @brief 视频源类型
 **/
enum class BMXVideoMediaType {
  /// None
  None,
  /// 摄像头
  Camera,
  /// 屏幕
  Screen,
};

enum class BMXTrackType {
  ///音频流
  Audio,
  ///视频流
  Video
};

/**
 * @brief 流信息
 **/
struct BMXStream {
  int64_t mUserId;
  std::string mStreamId;
  BMXVideoMediaType mMediaType;
  bool mEnableVideo;
  bool mEnableAudio;
  bool mEnableData;
  bool mMuteVideo;
  bool mMuteAudio;
};
typedef std::shared_ptr<BMXStream> BMXStreamPtr;

/**
 * @brief 渲染模式
 **/
enum class BMXRenderMode {
  /// 默认平铺
  Default,
  /// 保持比例
  Fit,
  /// 拉伸平铺
  Fill
};

/**
 * @brief 镜像模式
 **/
enum class BMXMirrorMode {
  /// 默认模式
  Default,
  /// 打开镜像模式
  Enable,
  /// 关闭镜像模式
  Disable
};

/**
 * @brief 绘制
 **/
struct BMXVideoCanvas {
  void* mView;
  int64_t mUserId;
  BMXStreamPtr mStream;
  BMXRenderMode mRenderMode;
  BMXMirrorMode mMirrodMode;
};
typedef std::shared_ptr<BMXVideoCanvas> BMXVideoCanvasPtr;

struct BMXStreamStats {
  int mUserId;
  std::string mStreamId;
  BMXVideoMediaType mMediaType;
  BMXTrackType mTrackType;
  int mAudioBitrate;
  int mVideoBitrate;
  int mWidth;
  int mHeight;
  int mFrameRate;
  float mPacketLostRate;
};
typedef std::shared_ptr<BMXStreamStats> BMXStreamStatsPtr;


struct BMXJanusStreamInfo {
  BMXJanusStreamInfo() {}
  int64_t mFeedId;
  std::string mFeedDisplay;
  std::string mFeedMid;
  std::string mType;
  std::string mMid;
  std::string mCodec;
  int mMindex;
  bool mTalking;
  bool mActive;
  bool mReady;
  bool mSend;
};
typedef std::shared_ptr<BMXJanusStreamInfo> BMXJanusStreamInfoPtr;
typedef std::vector<BMXJanusStreamInfoPtr> BMXRTCStreams;


/**
  * @brief 房间活跃成员信息
  */
struct BMXRoomParticipant {
  BMXRoomParticipant() {}
  int64_t mUserId;          // 用户id
  std::string mDisplay;     // 用户描述
  bool mIsPublisher;        // 是否是发布者
  bool mIstalking;          // 是否正在讲话
};
typedef std::shared_ptr<BMXRoomParticipant> BMXRoomParticipantPtr;
typedef std::vector<BMXRoomParticipantPtr> BMXRTCRoomParticipants;


struct BMXJanusPublisher {
  BMXJanusPublisher(int64_t userId) : mUserId(userId) {}
  int64_t mUserId;
  std::string mDisplay;
  std::string mAudioCodec;
  std::string mVideoCodec;
  bool mSimulcast;
  bool mTalking;
  BMXRTCStreams streams;
};
typedef std::shared_ptr<BMXJanusPublisher> BMXJanusPublisherPtr;
typedef std::vector<BMXJanusPublisherPtr> BMXRTCPublishers;


/**
 * @brief sdk类型
 */
enum class BMXRoomSDPType {
  /// 请求类型
  Offer,
  /// 应答类型
  Answer,
};

/**
 * @brief SDP信息
 */
struct BMXRoomSDPInfo {
  BMXRoomSDPInfo() {}
  std::string sdp;              // sdp 详细信息
  BMXRoomSDPType type;          // sdp 类型
};
typedef std::shared_ptr<BMXRoomSDPInfo> BMXRoomSDPInfoPtr;

}

#endif /* bmx_rtc_defines_h */