//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_engine_listener.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service listener define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_engine_listener_h
#define bmx_rtc_engine_listener_h

#include "bmx_rtc_defines.h"
#include "bmx_error.h"

namespace floo {

/**
 * @brief RTC监听者
 **/
class EXPORT_API BMXRTCEngineListener {
public:
  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCEngineListener(){}

  /**
   * @brief 用户加入房间回调
   * @param info 通知信息
   * @param roomId 房间Id
   * @param error 错误码信息
   **/
  virtual void onJoinRoom(const std::string& info, int64_t roomId, BMXErrorCode error) {}

  /**
   * @brief 用户离开房间回调
   * @param info 通知信息
   * @param roomId 房间Id
   * @param error 错误码信息
   * @param reason 离开原因
   **/
  virtual void onLeaveRoom(const std::string& info, int64_t roomId, BMXErrorCode error, const std::string& reason) {}

  /**
   * @brief断线重新加入房间回调
   * @param roomId 房间Id
   * @param error 错误码信息
   **/  
  virtual void onRejoining(int64_t roomId, BMXErrorCode error) {}

  /**
   * @brief 重新加入房间完成回调
   * @param info 通知信息
   * @param roomId 房间Id
   * @param error 错误码信息
   **/
  virtual void onReJoinRoom(const std::string& info, int64_t roomId, BMXErrorCode error) {}

  /**
   * @brief 其他用户加入房间回调
   * @param roomId 房间Id
   * @param usedId 用户id
   **/
  virtual void onMemberJoined(int64_t roomId, int64_t usedId) {}

  /**
   * @brief 其他用户离开房间回调
   * @param roomId 房间Id
   * @param userId 用户Id
   * @param reason 离开原因
   **/
  virtual void onMemberExited(int64_t roomId, int64_t usedId, const std::string& reason) {}

  /**
   * @brief 本地流发布回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onLocalPublish(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 本地流停止发布回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onLocalUnPublish(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 远程流发布回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onRemotePublish(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 远程流停止发布回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onRemoteUnPublish(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 订阅流回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onSubscribe(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 停止订阅流回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onUnSubscribe(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 远端流信息变更通知
   * @param stream 流信息
   * @param trackType 音轨或者视频轨类型
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onRemoteTrackNotify(BMXStreamPtr stream, BMXTrackType trackType, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 本地音频或视频启用禁用通知回调
   * @param stream 流信息
   * @param trackType 音轨或者视频轨类型
   * @param mute 启用或禁用
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onLocalStreamMuteRsp(BMXStreamPtr stream, BMXTrackType trackType, bool mute, const std::string& info, BMXErrorCode error) {}
  
  /**
   * @brief 远端音频或视频启用禁用通知回调
   * @param stream 流信息
   * @param trackType 音轨或者视频轨类型
   * @param mute 启用或禁用
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onRemoteStreamMuteRsp(BMXStreamPtr stream, BMXTrackType trackType, bool mute, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 发送端统计信息回调
   * @param streamStats 本地流统计信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onSendRTCStats(BMXStreamStatsPtr streamStats, const std::string& info, BMXErrorCode error) {}


  /**
   * @brief 远端统计信息回调
   * @param streamStats 远端流统计信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onRemoteRTCStats(BMXStreamStatsPtr streamStats, const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 本地音量调节回调
   * @param volume 音量信息
   **/
  virtual void onLocalAudioLevel(int volume) {}

  /**
   * @brief 远端音量调节回复
   * @param userId 用户id
   * @param volume 音量信息
   **/
  virtual void onRemoteAudioLevel(int64_t userId, int volume) {}

  /**
   * @brief 被踢信息回调
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onKickoff(const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 警告信息回调
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onWarning(const std::string& info, BMXErrorCode error) {}

  /**
   * @brief 错误信息回调
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onError(const std::string& info, BMXErrorCode error) {}

    /**
   * @brief 网络质量回调
   * @param stream 流信息
   * @param info 通知信息
   * @param error 错误码信息
   **/
  virtual void onNetworkQuality(BMXStreamPtr stream, const std::string& info, BMXErrorCode error) {}
};

}

#endif /* bmx_rtc_engine_listener_h */