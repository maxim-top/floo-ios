//
// ----------------------------------------------------------------------
// File    : BMXRosterItem.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------
//

#import "BMXRoster.h"
#import "BMXRoster+Private.h"
#import "BMXStringUtil.h"


@interface BMXRoster ()

@property (nonatomic, assign) floo::BMXRosterItemPtr ptr;

@end

@implementation BMXRoster
- (long long)rosterId {
    if (_ptr.get() != nullptr) {
        return (long long)_ptr->rosterId();
    }
    return 0;
}

- (NSString *)userName {
    if (_ptr.get() != nullptr) {
        NSString *str = [BMXStringUtil stdToNSString:_ptr->username()];

        return str;
        
    }
    return nil;
}

- (NSString *)nickName {
    if (_ptr.get() != nullptr) {
        NSString *str = [BMXStringUtil stdToNSString:_ptr->nickname()];
        return str;
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

- (NSString *)json_alias {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->alias().c_str()];
    }
    return nil;
}

- (NSString *)json_PublicInfo {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->publicInfo().c_str()];
    }
    return nil;
}

- (NSString *)json_ext {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->ext().c_str()];
    }
    return nil;
}

- (NSString *)json_localExt {
    if (_ptr.get() != nullptr) {
        return [NSString stringWithUTF8String:_ptr->localExt().c_str()];
    }
    return nil;
}

- (BOOL)isMuteNotification {
    if (_ptr.get() != nullptr) {
        return (BOOL)_ptr->isMuteNotification();
    }
    return NO;
}

- (BMXRosterRelation)rosterRelation {
    return (BMXRosterRelation)_ptr->relation();
}

@end

@implementation BMXRoster (Private)

- (instancetype)initWithBMXRosterPtr:(floo::BMXRosterItemPtr)rostItemPtr {
    if (self = [super init]) {
        _ptr = rostItemPtr;
    }
    return self;
}

- (floo::BMXRosterItemPtr)getBMXRosterPtr {
    return _ptr;
}

@end
