// ----------------------------------------------------------------------
// File    : BMXUserProtocol.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/30 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//


#import <Foundation/Foundation.h>
#import "BMXDefines.h"

@class BMXUserProfile;
@class BMXError;

@protocol BMXUserServiceProtocol <NSObject>

@optional

/**
 链接状态发生变化

 @param status 网络状态
 */
- (void)connectStatusDidChanged:(BMXConnectStatus)status;

/**
 用户登陆

 @param userProflie 用户信息
 */
- (void)userSignIn:(BMXUserProfile *)userProflie;


/**
 用户登出

 @param error 错误码
 */
- (void)userSignOut:(BMXError *)error userId:(long long)userId;

/**
 * 同步用户信息更新（其他设备操作发生用户信息变更）
 **/
- (void)userInfoDidUpdated:(BMXUserProfile *)userProflie;

/**
 * 用户在其他设备上登陆
 **/
- (void)userOtherDeviceDidSignIn:(NSInteger)deviceSN;

/**
 * 用户在其他设备上登出
 **/
- (void)userOtherDeviceDidSignOut:(NSInteger)deviceSN;

@end
