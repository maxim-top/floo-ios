
//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupApplication.m
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
    

#import "BMXGroupApplication.h"
#import "BMXGroupApplication+Private.h"
#import "BMXStringUtil.h"

@interface BMXGroupApplication ()

@property (nonatomic,assign) floo::BMXGroup::ApplicationPtr applicationPtr;

@end

@implementation BMXGroupApplication

- (long long)groupId {
    if (_applicationPtr != nullptr) {
        return _applicationPtr->mGroupId;
    }
    return 0;
}

- (long long)applicationId {
    if (_applicationPtr != nullptr) {
        return _applicationPtr->mApplicationId;
    }
    return 0;
}

- (long long)expiredTime {
    if (_applicationPtr != nullptr) {
        return _applicationPtr->mExpired;
    }
    return 0;
}

- (NSString *)reason {
    if (_applicationPtr != nullptr) {
        return [BMXStringUtil stdToNSString:_applicationPtr->mReason];
    }
    return nil;
}

- (BMXGroupApplicationStatus)applicationStatus {
    switch (_applicationPtr->mStatus) {
        case floo::BMXGroup::ApplicationStatus::Accepted :
            return BMXGroupApplicationStatusAccepted;
            break;
        case floo::BMXGroup::ApplicationStatus::Declined :
            return BMXGroupApplicationStatusDeclined;
            break;
        case floo::BMXGroup::ApplicationStatus::Pending :
            return BMXGroupApplicationStatusPending;
            break;
    }
}



@end

@implementation BMXGroupApplication (Private)

- (instancetype)initWithBMXGroupApplicationPtr:(floo::BMXGroup::ApplicationPtr)applicationPtr {
    if (self = [super init]) {
        _applicationPtr = applicationPtr;
    }
    return self;
}

- (floo::BMXGroup::ApplicationPtr)getApplicationPtr {
    return _applicationPtr;
}

@end


