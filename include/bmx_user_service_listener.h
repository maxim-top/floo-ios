//-------------------------------------------------------------------------------------------------
// File    : bmx_user_service_listener.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user service listener define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_user_service_listener_h
#define bmx_user_service_listener_h

#include "bmx_sdk_config.h"
#include "bmx_defines.h"
#include "bmx_user_profile.h"
#include "bmx_error.h"
#include "bmx_user_service.h"

namespace floo {

class BMXUserService;

/**
 * @brief 用户状态监听者
 **/
class EXPORT_API BMXUserServiceListener {
public:
  /**
   * @brief 构造函数
   **/
  BMXUserServiceListener() : mService(nullptr) {}

  /**
   * @brief 析构函数
   **/
  virtual ~BMXUserServiceListener() {
    if (mService != nullptr) {
      mService->removeUserListener(this);
    }
  }

  /**
   * @brief 链接状态发生变化
   * @param status 连接状态
   **/
  virtual void onConnectStatusChanged(BMXConnectStatus status) {}

  /**
   * @brief 用户登陆
   * @param profile 用户profile
   **/
  virtual void onUserSignIn(BMXUserProfilePtr profile) {}

  /**
   * @brief 用户登出
   * @param error 状态错误码
   **/
  virtual void onUserSignOut(BMXErrorCode error, int64_t userId) {}

  /**
   * @brief 同步用户信息更新（其他设备操作发生用户信息变更）
   * @param profile 用户profile
   **/
  virtual void onInfoUpdated(BMXUserProfilePtr profile) {}

  /**
   * @brief 用户在其他设备上登陆
   * @param deviceSN 设备序列号
   **/
  virtual void onOtherDeviceSingIn(int deviceSN) {}

  /**
   * @brief 用户在其他设备上登出
   * @param deviceSN 设备序列号
   **/
  virtual void onOtherDeviceSingOut(int deviceSN) {}

public:
  /**
   * @brief 注册BMXUserServiceListener绑定到的BMXUserService（SDK内部自动注册）
   * @param service BMXUserService
   **/
  void registerUserService(BMXUserService* service) {
    mService = service;
  }

protected:
  BMXUserService* mService;
};

}

#endif /* bmx_user_service_listener_h */
