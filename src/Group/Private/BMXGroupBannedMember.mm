
//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupBannedMember.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/24 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupBannedMember.h"
#import "BMXStringUtil.h"
#import "BMXGroupBannedMember+Private.h"

@interface BMXGroupBannedMember ()

@property (nonatomic,assign) floo::BMXGroup::BannedMemberPtr bannedMemberPtr;

@end

@implementation BMXGroupBannedMember

- (NSInteger)uid {
    if (_bannedMemberPtr != nullptr) {
        return _bannedMemberPtr->mUid;
    }
    return 0;
}

- (NSString *)groupNickname {
    if (_bannedMemberPtr != nullptr) {
        return [BMXStringUtil stdToNSString:_bannedMemberPtr->mGroupNickname];
    }
    return nil;
}

- (long long)createTime {
    if (_bannedMemberPtr != nullptr) {
        return _bannedMemberPtr->mCreateTime;
    }
    return 0;
}

- (long long)expiredTime {
    if (_bannedMemberPtr != nullptr) {
        return _bannedMemberPtr->mExpired;
    }
    return 0;
}

@end

@implementation BMXGroupBannedMember (Private)

- (instancetype)initWithBMXGroupBannedMemberPtr:(floo::BMXGroup::BannedMemberPtr)bannedMember {
    if (self = [super init]) {
        _bannedMemberPtr = bannedMember;
    }
    return self;
}

- (floo::BMXGroup::BannedMemberPtr)getGroupBannedMemberPtr {
    return _bannedMemberPtr;
}


@end
