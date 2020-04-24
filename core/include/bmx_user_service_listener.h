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

namespace floo {

class EXPORT_API BMXUserServiceListener {
public:
  virtual ~BMXUserServiceListener() {}

  /**
   * 链接状态发生变化
   **/
  virtual void onConnectStatusChanged(BMXConnectStatus status) {}

  /**
   * 用户登陆
   **/
  virtual void onUserSignIn(BMXUserProfilePtr profile) {}

  /**
   * 用户登出
   **/
  virtual void onUserSignOut(BMXErrorCode error) {}

  /**
   * 同步用户信息更新（其他设备操作发生用户信息变更）
   **/
  virtual void onInfoUpdated(BMXUserProfilePtr profile) {}

  /**
   * 用户在其他设备上登陆
   **/
  virtual void onOtherDeviceSingIn(int deviceSN) {}

  /**
   * 用户在其他设备上登出
   **/
  virtual void onOtherDeviceSingOut(int deviceSN) {}
};

}

#endif /* bmx_user_service_listener_h */
