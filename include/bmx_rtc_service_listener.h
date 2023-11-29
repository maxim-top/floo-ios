//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_service_listener.h
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

#ifndef bmx_rtc_service_listener_h
#define bmx_rtc_service_listener_h

#include "bmx_message.h"
#include "bmx_error.h"
#include "bmx_rtc_service.h"

namespace floo {

class BMXRTCService;

/**
 * @brief RTCService状态监听者
 **/
class EXPORT_API BMXRTCServiceListener {
public:

  /**
   * @brief 构造函数
   **/
  BMXRTCServiceListener() : mService(nullptr) {}

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCServiceListener() {
    if (mService != nullptr) {
      mService->removeRTCServiceListener(this);
    }
  }

  /**
   * @brief 发送信令消息状态变化
   * @param msg 发生变化的信令消息
   * @param error 
   **/
  virtual void onRTCMessageStatusChanged(BMXMessagePtr msg, BMXErrorCode error)  {}

  /**
   * @brief 接收到通话请求消息
   * @param msg 
   **/
  virtual void onRTCCallMessageReceive(BMXMessagePtr msg) {}

  /**
   * @brief 接收到接通消息
   * @param msg 
   **/
  virtual void onRTCPickupMessageReceive(BMXMessagePtr msg) {}

  /**
   * @brief 接收到挂断消息
   * @param msg 
   **/
  virtual void onRTCHangupMessageReceive(BMXMessagePtr msg) {}

  /**
   * @brief 接收到统计消息
   * @param msg 
   **/
  virtual void onRTCRecordMessageReceive(BMXMessagePtr msg) {}
public:
  void registerRTCService(BMXRTCService* service) {
    mService = service;
  }

protected:
  BMXRTCService* mService;
};

}

#endif