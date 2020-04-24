//
//  ----------------------------------------------------------------------
//   File    :  BMXDevice.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/31 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMXDevice : NSObject


/**
 设备序列号
 */
@property (nonatomic,assign, readonly) int deviceSN;

/**
 用户id
 */
@property (nonatomic,assign, readonly) long long userId;

/**
 平台
 */
@property (nonatomic,assign, readonly) int platform;

/**
 UA
 */
@property (nonatomic,copy) NSString *userAgent;

/**
 是否是当前设备
 */
@property (nonatomic,assign, readonly) BOOL isCurrentDevice;

@end

NS_ASSUME_NONNULL_END
