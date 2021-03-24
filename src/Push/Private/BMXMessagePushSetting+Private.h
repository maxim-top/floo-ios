//
//  BMXMessagePushSetting+Private.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "BMXMessagePushSetting.h"
#include "bmx_push_user_profile.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BMXMessagePushSettingDelegate <NSObject>

- (instancetype)initWithBMXMessagePushSettingPtr:(floo::BMXPushUserProfile::MessagePushSetting)ptr;

- (floo::BMXPushUserProfile::MessagePushSetting)getBMXMessageSettingPtr;

@end

@interface BMXMessagePushSetting (Private) <BMXMessagePushSettingDelegate>


@end


NS_ASSUME_NONNULL_END
