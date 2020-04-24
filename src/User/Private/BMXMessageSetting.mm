
//
//  ----------------------------------------------------------------------
//   File    :  BMXMessageSetting.m
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
#import "BMXMessageSetting+Private.h"
#import "BMXStringUtil.h"
#include "bmx_user_profile.h"

@interface BMXMessageSetting ()

@property (nonatomic,assign) floo::BMXUserProfile::MessageSetting settingS;

@end

@implementation BMXMessageSetting

- (BOOL)mPushEnabled {
    return (BOOL)_settingS.mPushEnabled;
}

- (BOOL)mPushDetail {
    return (BOOL)_settingS.mPushDetail;
}

- (BOOL)mNotificationSound {
    return (BOOL)_settingS.mNotificationSound;
}

- (BOOL)mNotificationVibrate {
    return (BOOL)_settingS.mNotificationVibrate;
}

- (BOOL)mAutoDownloadAttachment {
    return (BOOL)_settingS.mAutoDownloadAttachment;
}

- (NSString *)pushNickname {
    return [BMXStringUtil stdToNSString:_settingS.mPushNickname];
}

@end

@implementation BMXMessageSetting (Private)
- (instancetype)initWithBMXMessageSettingPtr:(floo::BMXUserProfile::MessageSetting)setting {
    if (self = [super init]) {
        _settingS = setting;
    }
    return self;    
}

- (floo::BMXUserProfile::MessageSetting)getBMXMessageSettingPtr {
    return _settingS;
}
@end
