//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupMember.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/6 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupMember.h"
#import "BMXGroupMember+Private.h"
#import "BMXStringUtil.h"
@interface BMXGroupMember ()

@property (nonatomic,assign) floo::BMXGroup::MemberPtr memberPtr;

@end

@implementation BMXGroupMember

- (instancetype)init {
    return nil;
}

- (NSInteger)uid {
    if (_memberPtr != nullptr) {
        return _memberPtr->mUid;
    }
    return 0;
}

- (NSString *)groupNickname {
    if (_memberPtr != nullptr) {
        return [BMXStringUtil stdToNSString:_memberPtr->mGroupNickname];
    }
    return nil;
}

- (long long)createTime {
    if (_memberPtr != nullptr) {
        return _memberPtr->mCreateTime;
    }
    return 0;
}

@end

@implementation BMXGroupMember (Private)
- (floo::BMXGroup::MemberPtr)getGroupMemberPtr {
    return _memberPtr;
}

- (instancetype)initWithBMXGroupMemberPtr:(floo::BMXGroup::MemberPtr)groupMember {
    if (self = [super init]) {
        _memberPtr = groupMember;
    }
    return self;
    
}

@end
