//
// ----------------------------------------------------------------------
// File    : BMXSDKConfig+Private.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/12/1 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------
//

#import "BMXSDKConfig.h"
#include "bmx_sdk_config.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BMXSDKConfigDelegate <NSObject>

- (instancetype)initWith:(floo::BMXSDKConfigPtr)configPtr;
- (floo::BMXSDKConfigPtr)getBMXSDKConfigPtr;

@end

@interface BMXSDKConfig (Private)<BMXSDKConfigDelegate>



@end

NS_ASSUME_NONNULL_END
