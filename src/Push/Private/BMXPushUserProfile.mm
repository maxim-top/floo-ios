//
//  BMXPushUserProfile.m
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "BMXPushUserProfile.h"
#import "BMXStringUtil.h"
#import "BMXMessagePushSetting+Private.h"
#import "BMXPushUserProfile+Private.h"
#import "bmx_push_user_profile.h"

@interface BMXPushUserProfile ()

@property (nonatomic,assign) floo::BMXPushUserProfilePtr ptr;


@end

@implementation BMXPushUserProfile

- (NSInteger)userId {
    if (_ptr.get() != nullptr) {
        return (NSInteger)_ptr->userId();
    }
    return 0;
}

- (NSString *)pushAlias {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->pushAlias()];
    }
    return nil;
}

- (NSString *)pushToken {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->pushToken()];
    }
    return nil;
}

- (BMXMessagePushSetting *)setting {
    if (_ptr.get() != nullptr) {
        BMXMessagePushSetting *setting  = [[BMXMessagePushSetting alloc] initWithBMXMessagePushSettingPtr:_ptr->messagePushSetting()];
        return setting;
    }
    return nil;
}

@end

@implementation BMXPushUserProfile  (Private)

- (instancetype)initWithBMXPushUserProfilePtr:(floo::BMXPushUserProfilePtr)ptr {
    if (self = [super init]) {
        _ptr = ptr;
    }
    return self;

}

- (floo::BMXPushUserProfilePtr)getBMXUserProfilePtr {
    return _ptr;
}


@end
