
//
//  BMXUserProfile.m
//  MaxIM
//
//  Created by hyt on 2018/12/4.
//  Copyright © 2018年 cao lihui. All rights reserved.
//

#import "BMXUserProfile.h"
#import "BMXUserProfile+Private.h"
#import "BMXMessageSetting+Private.h"
#include "bmx_user_profile.h"
#import "BMXAuthQuestion.h"


@interface BMXUserProfile ()

@property (nonatomic, assign) floo::BMXUserProfilePtr ptr;

@end


@implementation BMXUserProfile

- (long long)userId {
    if (_ptr.get() != nullptr) {
        return (long long)_ptr->userId();
        
    }
    return 0;
}

- (NSString *)userName {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->username().c_str()];
    }
    return nil;
}

- (NSString *)nickName {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->nickname().c_str()];
    }
    return nil;
}


- (NSString *)avatarUrl {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->avatarUrl().c_str()];
    }
    return nil;
}

- (NSString *)avatarPath {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->avatarPath().c_str()];
    }
    return nil;
}

- (NSString *)avatarThumbnailPath {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->avatarThumbnailPath().c_str()];
    }
    return nil;
}

- (NSString *)mobilePhone {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->mobilePhone().c_str()];
    }
    return nil;
}

- (NSString *)publicInfoJson {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->publicInfo().c_str()];
    }
    return nil;
}

- (NSString *)privateInfoJson {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->privateInfo().c_str()];
    }
    return nil;
}

- (BMXAuthQuestion *)authQuestion {
    if (_ptr.get() != nullptr) {
        _authQuestion = [[BMXAuthQuestion alloc] init];
        _authQuestion.mQuestion = [NSString stringWithUTF8String:_ptr->authQuestion().mQuestion.c_str()] ;
        _authQuestion.mAnswer = [NSString stringWithUTF8String:_ptr->authQuestion().mAnswer.c_str()];
        return _authQuestion;

    }
    return nil;
}

- (BMXMessageSetting *)messageSetting {
    if (_ptr.get() != nullptr) {
        BMXMessageSetting *setting  = [[BMXMessageSetting alloc] initWithBMXMessageSettingPtr:_ptr->messageSetting()];
        return setting;
    }
    return nil;
}

- (BMXAddFriendAuthMode)addFriendAuthMode {
    if (_ptr.get() != nullptr) {
        return (BMXAddFriendAuthMode)_ptr->addFriendAuthMode();
    }
    return BMXAddFriendAuthModeOpen;
}

- (BOOL)isAutoAcceptGroupInvite {
    if (_ptr.get() != nullptr) {
        return (BOOL)_ptr->isAutoAcceptGroupInvite();
    }
    return YES;
}

@end

@implementation BMXUserProfile (Private)

- (instancetype)initWithBMXUserProfilePtr:(floo::BMXUserProfilePtr)ptr {
    if (self = [super init]) {
        if (ptr) {
            _ptr = ptr;
        }
    }
    return self;
}

- (floo::BMXUserProfilePtr)getBMXUserProfilePtr {
    return _ptr;
}

@end

