//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_config.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx sdk configuration define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_config_h
#define bmx_rtc_config_h

#include <string>
#include <memory>
#include <mutex>
#include "bmx_rtc_defines.h"

namespace floo {

/**
 * @brief RTC设置管理
 **/
class EXPORT_API BMXRTCConfig {
public:

  BMXRTCConfig();

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCConfig();

  /**
   * @brief 获取音视频SDK版本号
   * @return std::string
   **/
  std::string getVersion();

  /**
   * @brief 设置音视频log等级
   * @param level log日志等级
   **/
  void setLogLevel(BMXLogLevel level);

  /**
   * @brief 获取音视频日志等级
   * @return BMXLogLevel
   **/
  BMXLogLevel getLogLevel();

  /**
   * @brief 设置音视频SDK模式
   * @param mode 音视频模式
   **/
  void setSDKMode(BMXSDKMode mode);

  /**
   * @brief 获取音视频SDK模式
   * @return BMXSDKMode
   **/
  BMXSDKMode getSDKMode();

  /**
   * @brief 设置是否自动发布模式
   * @param bool 是否自动发布
   **/
  void setAutoPublishMode(bool autoPublish);

  /**
   * @brief 获取是否自动发布模式
   * @return bool
   **/
  bool getAutoPublishMode();

  /**
   * @brief 设置是否自动订阅模式
   * @param bool 是否自动订阅
   **/
  void setAutoSubscribeMode(bool autoSubscribe);

  /**
   * @brief 获取是否自动发布模式
   * @return bool
   **/
  bool getAutoSubscribeMode();

  /**
   * @brief 设置是否纯音频模式
   * @param bool 是否纯音频
   **/
  void setAudioOnlyMode(bool audioOnly);

  /**
   * @brief 获取是否纯音频模式
   * @return bool
   **/
  bool getAudioOnlyMode();

  /**
   * @brief 设置本地音频是否发布
   * @param bool 本地音频是否发布
   **/
  void setEnableLocalAudio(bool enableLocalAudio);

  /**
   * @brief 获取本地音频是否发布
   * @return bool
   **/
  bool getEnableLocalAudio();

  /**
   * @brief 设置本地视频是否发布
   * @param enableLocalVideo 本地视频是否发布
   **/
  void setEnableLocalVideo(bool enableLocalVideo);

  /**
   * @brief 获取本地视频是否发布
   * @return bool
   **/
  bool getEnableLocalVideo();

private:
  std::recursive_mutex mMutex;
  std::string mVersion;
  BMXLogLevel mLogLevel;
  BMXSDKMode mMode; 
  bool mAutoPublish;
  bool mAutoSubscribe;
  bool mAudioOnly;
  bool mEnableLocalAudio;
  bool mEnableLocalVideo;

};

typedef std::shared_ptr<BMXRTCConfig> BMXRTCConfigPtr;

}

#endif /* bmx_rtc_config_h */