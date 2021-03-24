//-------------------------------------------------------------------------------------------------
// File    : bmx_defines.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __bmx_defines_h__
#define __bmx_defines_h__

#include <cstdint>

//#if _MSC_VER
//#define snprintf _snprintf
//#endif

#if defined( _WIN32 )
#  if defined( MAXIM_EXPORTS ) || defined( DLL_EXPORT )
#    define EXPORT_API __declspec( dllexport )
#  else
#    if defined( MAXIM_IMPORTS ) || defined( DLL_IMPORT )
#      define EXPORT_API __declspec( dllimport )
#    endif
#  endif
#endif

#ifndef EXPORT_API
#  define EXPORT_API
#endif

#define CONNECT_MAX_RETRY 3

namespace floo {

/**
 * @brief 客户端类型
 **/
enum class BMXClientType {
  /// 未知客户端类型
  Unknown = 0,
  /// IOS端
  iOS,
  /// Android端
  Android,
  /// Windows PC 端
  Windows,
  /// Mac PC 端
  macOS,
  /// Linux PC 端
  Linux,
  /// Web端
  Web
};

/**
 * @brief 网络类型
 **/
enum class BMXNetworkType {
  /// 移动网络
  Mobile,
  /// Wifi
  Wifi,
  /// 有线电视电缆
  Cable,
  /// 未知类型
  None
};

/**
 * @brief 网络连接状态
 **/
enum class BMXConnectStatus {
  /// 未连接状态
  Disconnected,
  /// 连接状态
  Connected
};

/**
 * @brief 登录状态
 **/
enum class BMXSignInStatus {
  /// 未登录状态
  SignOut,
  /// 登录状态
  SignIn
};

/**
 * @brief 日志级别
 **/
enum class BMXLogLevel {
  /// 错误级别
  Error,
  /// 警告级别
  Warning,
  /// 调试级别
  Debug
};

/**
 * @brief 推送的提供商类型 1-APNS，2-华为，3-小米，4-魅族，5-VIVO， 6-OPPO
 **/
enum class BMXPushProviderType {
  /// 未知客户端类型
  Unknown = 0,
  // 苹果 APNS
  APNS,
  // 华为
  HuaWei,
  // 小米
  XiaoMi,
  // 魅族
  MeiZu,
  // VIVO
  VIVO,
  // OPPO
  OPPS
};

/**
 * @brief 推送的运行环境类型 0,开发环境 1,生产环境
 **/
enum class BMXPushEnvironmentType {
  // 开发环境
  Development = 0,
  // 生产环境
  Production
};

}

#endif /* __bmx_defines_h__ */
