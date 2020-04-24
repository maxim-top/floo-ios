

//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupInvitation.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/5 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupInvitation.h"
#import "BMXGroupInvitation+Private.h"
#import "BMXStringUtil.h"

@interface BMXGroupInvitation ()

@property (nonatomic,assign) floo::BMXGroup::InvitationPtr invitationPtr ;

@end

@implementation BMXGroupInvitation

- (long long)groupId {
    if (_invitationPtr != nullptr) {
        return _invitationPtr->mGroupId;
    }
    return 0;
}

- (long long)inviterId {
    if (_invitationPtr != nullptr) {
        return _invitationPtr->mInviterId;
    }
    return 0;
}

- (long long)expiredTime {
    if (_invitationPtr != nullptr) {
        return _invitationPtr->mExpired;
    }
    return 0;
}

- (NSString *)reason {
    if (_invitationPtr != nullptr) {
        return [BMXStringUtil stdToNSString:_invitationPtr->mReason];
    }
    return nil;
}

- (BMXGroupInvitationStatus)invitationStatus {
    return (BMXGroupInvitationStatus)_invitationPtr->mStatus;
}

@end

@implementation BMXGroupInvitation (Private)

- (instancetype)initWithBMXGroupInvitationPtr:(floo::BMXGroup::InvitationPtr)invitationPtr {
    if (self = [super init]) {
        _invitationPtr = invitationPtr;
    }
    return self;
}

- (floo::BMXGroup::InvitationPtr)getInvitationPtr {
    return _invitationPtr;
}


@end


