//
//  BMXMessagePushSetting.m
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "BMXMessagePushSetting.h"

#import "BMXMessagePushSetting+Private.h"
#import "BMXStringUtil.h"
#include "bmx_push_user_profile.h"

@interface BMXMessagePushSetting ()

@property (nonatomic,assign) floo::BMXPushUserProfile::MessagePushSetting settingS;

@end


@implementation BMXMessagePushSetting

- (BOOL)pushEnabled {
    return _settingS.mPushEnabled;
}

- (NSInteger)silenceStartTime {
    return (NSInteger)_settingS.mSilenceStartTime;
}

- (NSInteger)silenceEndTime {
    return (NSInteger)_settingS.mSilenceEndTime;
}

- (NSInteger)pushStartTime {
    return (NSInteger)_settingS.mPushStartTime;
}

- (NSInteger)mPushEndTime {
    return (NSInteger)_settingS.mPushEndTime;
}

@end


@implementation BMXMessagePushSetting (Private)


- (instancetype)initWithBMXMessagePushSettingPtr:(floo::BMXPushUserProfile::MessagePushSetting)ptr {
    if (self = [super init]) {
        _settingS = ptr;
    }
    return self;

}

- (floo::BMXPushUserProfile::MessagePushSetting)getBMXMessageSettingPtr {
    return _settingS;
}
@end
