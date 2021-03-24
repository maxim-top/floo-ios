//
//  ----------------------------------------------------------------------
//   File    :  BMXMessageSetting+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/3 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXMessageSetting.h"
#include "bmx_user_profile.h"

NS_ASSUME_NONNULL_BEGIN
@protocol BMXMessageSettingDelegate <NSObject>

- (instancetype)initWithBMXMessageSettingPtr:(floo::BMXUserProfile::MessageSetting)ptr;

- (floo::BMXUserProfile::MessageSetting)getBMXMessageSettingPtr;

@end

@interface BMXMessageSetting (Private)<BMXMessageSettingDelegate>


@end

NS_ASSUME_NONNULL_END
