//
//  ----------------------------------------------------------------------
//   File    :  BMXHostConfig+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/8 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXHostConfig.h"
#include "bmx_sdk_config.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BMXHostConfigDelegate <NSObject>

- (floo::BMXSDKConfig::HostConfig)getHostConfig;

@end

@interface BMXHostConfig (Private)<BMXHostConfigDelegate>
- (instancetype)initWithBMXHostConfigPtr:(floo::BMXSDKConfig::HostConfig)hostConfig;


@end

NS_ASSUME_NONNULL_END
