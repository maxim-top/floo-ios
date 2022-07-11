//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx rtc service listener define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_service_h
#define bmx_rtc_service_h

#include "bmx_rtc_engine.h"
#include "bmx_message.h"
#include "bmx_rtc_signal_service.h"

namespace floo {

class BMXRTCEngine;
class BMXRTCServiceListener;

class EXPORT_API BMXRTCService {
public:

  /**
  * @brief 析构函数
  **/
  virtual ~BMXRTCService() {}

  /**
   * @brief 初始化并存储engine对象实例
   * @param engine BMXRTCEngine对象实例指针
   */
  virtual void setupRTCEngine(BMXRTCEngine* engine) = 0;

  /**
   * @brief 获取存储的engine对象实例
   * @return BMXRTCEngine* 
   */
  virtual BMXRTCEngine* getRTCEngine() = 0;

  /**
  * @brief 获取BMXRTCSignalService的信令服务service（只有BMXRTCEngine需要使用该信令service，第三方RTCEngine对象不需要）
  **/
  virtual BMXRTCSignalService& getBMXRTCSignalService() = 0;

  /**
  * @brief 发送消息，用来RTCService层进行交互信令发送的操作。
  * @param msg 发送的信息消息，消息的类型仅为信令消息
  **/
  virtual void sendRTCNotice(BMXMessagePtr msg) = 0;

  /**
  * @brief 添加RTCService回调监听
  * @param listener RTCService监听器
  **/
  virtual void addRTCServiceListener(BMXRTCServiceListener* listener) = 0;

  /**
  * @brief 移除RTCService回调监听
  * @param listener RTCService监听器
  **/
  virtual void removeRTCServiceListener(BMXRTCServiceListener* listener) = 0;

protected:
  BMXRTCService() {}
};

}

#endif