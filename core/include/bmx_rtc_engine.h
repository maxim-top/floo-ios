//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_engine_interface.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_engine_interface_h
#define bmx_rtc_engine_interface_h

#include "bmx_rtc_defines.h"
#include "bmx_rtc_config.h"
#include "bmx_rtc_engine_listener.h"
#include "bmx_error.h"

namespace floo {

/**
 * @brief RTC Engine声明
 **/
class EXPORT_API BMXRTCEngine {
public:
  /**
   * @brief 创建BMXRTCEngine对象
   * @param config 客户端本地已经创建好的BMXSDKConfig SDK配置对象
   * @return BMXClientPtr
   **/
  //static BMXRTCEnginePtr createEngine(BMXRTCConfigPtr config);

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCEngine() {}

  /**
   * @brief 销毁音视频Engine
   **/
  virtual void destroy() = 0;

  /**
   * @brief 添加聊天监听者
   * @param listener 聊天监听者
   **/
  virtual void addRTCEngineListener(BMXRTCEngineListener* listener) = 0;

  /**
   * @brief 移除聊天监听者
   * @param listener 聊天监听者
   **/
  virtual void removeRTCEngineListener(BMXRTCEngineListener* listener) = 0;

  /**
   * @brief 获取RTC设置
   * @return BMXRTCConfigPtr
   **/
  virtual BMXRTCConfigPtr getRTCConfig() = 0;

  /**
   * @brief 设置Room的类型
   * @param type Room类型
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode setRoomType(BMXRoomType type) = 0;

  /**
   * @brief 设置流操作权限
   * @param role 操作权限，推流、拉流、推拉流。
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode setStreamRole(BMXStreamRole role) = 0;

  /**
   * @brief 设置视频编码格式类型
   * @param codec VP8编码、H264编码
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode setVideoCodec(BMXVideoCodec codec) = 0;

  /**
   * @brief 设置视频编码格式类型
   * @param codec VP8编码、H264编码
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode setVideoProfile(BMXVideoConfigPtr videoConfig) = 0;

  /**
   * @brief 设置音频编码格式
   * @param profile 音频编码格式
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode setAudioProfile(BMXAudioProfile profile) = 0;

  /**
   * @brief 加入频道
   * @param auth 加入频道时的认证信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode joinRoom(BMXRoomAuthPtr auth) = 0;

  /**
   * @brief 离开频道
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode leaveRoom() = 0;

  /**
   * @brief 发布流信息
   * @param type 流媒体类型
   * @param hasVideo 是否存在视频流
   * @param hasAudio 是否存在音频流
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode publish(BMXVideoMediaType type, bool hasVideo, bool hasAudio) = 0;

  /**
   * @brief 停止发布流
   * @param type 流媒体类型
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode unPublish(BMXVideoMediaType type) = 0;

  /**
   * @brief 订阅流信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode subscribe(BMXStreamPtr stream) = 0;

  /**
   * @brief 停止订阅流
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode unSubscribe(BMXStreamPtr stream) = 0;

  /**
   * @brief 开启本地渲染
   * @param canvas 画布属性信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode startPreview(BMXVideoCanvasPtr canvas) = 0;

  /**
   * @brief 停止本地渲染
   * @param canvas 画布属性信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode stopPreview(BMXVideoCanvasPtr canvas) = 0;

  /**
   * @brief 开启远端渲染
   * @param canvas 画布属性信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode startRemoteView(BMXVideoCanvasPtr canvas) = 0;

  /**
   * @brief 停止远端渲染
   * @param canvas 画布属性信息
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode stopRemoteView(BMXVideoCanvasPtr canvas) = 0;

  /**
   * @brief 打开关闭本地音频
   * @param mute true为打开，false为关闭
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode muteLocalAudio(bool mute) = 0;

  /**
   * @brief 打开关闭本地视频
   * @param type 视频流类型
   * @param mute true为打开，false为关闭
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode muteLocalVideo(BMXVideoMediaType type, bool mute) = 0;

  /**
   * @brief 打开关闭远端音频
   * @param stream 远端流
   * @param mute true为打开，false为关闭
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode muteRemoteAudio(BMXStreamPtr stream, bool mute) = 0;

  /**
   * @brief 打开关闭远端视频
   * @param stream 远端流
   * @param mute true为打开，false为关闭
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode muteRemoteVideo(BMXStreamPtr stream, bool mute) = 0;

  /**
   * @brief 切换摄像头
   * @return BMXErrorCode
   **/
  virtual BMXErrorCode switchCamera() = 0;

protected:
  BMXRTCEngine() {}

private:
  BMXRTCEngine(const BMXRTCEngine&);
  BMXRTCEngine& operator=(const BMXRTCEngine&);
};

typedef std::shared_ptr<BMXRTCEngine> BMXRTCEnginePtr;

}

#endif /*bmx_rtc_engine_interface_h*/
