//
//  ----------------------------------------------------------------------
//   File    :  BMXApplicationList.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/22 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXApplication.h"
#import "BMXApplication+Private.h"
#import "BMXStringUtil.h"

@interface BMXApplication ()

@property (nonatomic,assign) floo::BMXRosterService::ApplicationPtr ptr;

@end

@implementation BMXApplication

- (long long)rosterId {
    return (long long)_ptr->mRosterId;
}

- (NSString *)reason {
    return [BMXStringUtil stdToNSString:_ptr->mReason];
}

- (long long)expireTime {
    return (long long)_ptr->mExpire;
}

- (BMXApplicationStatus)applicationStatus {
    switch (_ptr->mStatus) {
        case floo::BMXRosterService::ApplicationStatus::Pending:
            return BMXApplicationStatusPending;
            break;
        case floo::BMXRosterService::ApplicationStatus::Accepted:
            return BMXApplicationStatusAccepted;
            break;
        case floo::BMXRosterService::ApplicationStatus::Declined:
            return BMXApplicationStatusDeclined;
            break;
    }
}

@end

@implementation BMXApplication (Private)
- (instancetype)initWithApplicationPtr:(floo::BMXRosterService::ApplicationPtr)applicationPtr {
    if (self = [super init]) {
        _ptr = applicationPtr;
        _rosterId = (long long)_ptr->mRosterId;
        _expireTime = (long long)_ptr->mExpire;
        _reason = [BMXStringUtil stdToNSString:_ptr->mReason];
    }
    return self;
}

@end

