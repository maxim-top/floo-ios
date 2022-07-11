// ----------------------------------------------------------------------
// File    : BMXSDKConfig.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/24 by hyt <yutong@bmxlabs.com>
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
@class BMXOSSConfig;
@class BMXHostConfig;

NS_ASSUME_NONNULL_BEGIN


@interface BMXSDKConfig : NSObject

@property (nonatomic, copy, readonly) NSString *dataDir;

@property (nonatomic, copy, readonly) NSString *cacheDir;

@property (nonatomic, copy, readonly) NSString *vsn;

@property (nonatomic, copy, readonly) NSString *sdkVersion;

@property (nonatomic, copy) NSString *pushCertName;

@property (nonatomic,copy, readonly) NSString *userAgent;

@property (nonatomic,assign) BOOL enableDeliveryAck;

/**
 * 获取和设置是否在消息config字段里携带username功能（方便在未获取到对方user info时展示其用户名），默认是关闭的。
 **/
@property (nonatomic,assign) BOOL carryUsernameInMessage;

@property (nonatomic, assign) BMXLogLevel logLevelType;

@property (nonatomic, assign) BOOL consoleOutput;

@property (nonatomic, strong) BMXHostConfig *hostConfig;

@property (nonatomic,assign) BOOL loadAllServerConversations;

/**
 * 获取设备的唯一识别码,如果使用数据库
 **/
@property (nonatomic,copy) NSString *deviceUUID;

@property (nonatomic,assign) BOOL verifyCertificate;

/**
 * 获取是否启用dns功能,设置是否启用dns功能，默认是开启的。
 **/
@property (nonatomic,assign) BOOL enableDNS;

/**
 * 获取用户自定义dns服务器地址,设置用户自定义dns服务器地址，在用户设置了dns服务器的情况下优先使用用户dns。
 **/
@property (nonatomic,copy) NSString *userDNSAddress;

/**
 * 获取用户的appId, 设置用户的appId。
 **/
@property (nonatomic,copy) NSString *appID;


@property (nonatomic, strong) NSString *appSecret;


/**
 设置调试log接收账号(仅用于SDK调试，接收客户端log日志使用)
 */
@property (nonatomic,copy) NSString *debugLogRecevierID;


- (instancetype)initConfigWithDataDir:(NSString *)dataDir
                             cacheDir:(NSString *)cacheDir
                         pushCertName:(NSString *)pushCertName
                            userAgent:(NSString *)userAgent;

@end

NS_ASSUME_NONNULL_END
