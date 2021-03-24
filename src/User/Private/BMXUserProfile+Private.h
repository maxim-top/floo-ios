//
//  BMXUserProfile+Private.h
//  MaxIM
//
//  Created by hyt on 2018/12/4.
//  Copyright © 2018年 cao lihui. All rights reserved.
//

#import "BMXUserProfile.h"
#include "bmx_user_profile.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXUserProfile (Private)

- (instancetype)initWithBMXUserProfilePtr:(floo::BMXUserProfilePtr)ptr;

- (floo::BMXUserProfilePtr)getBMXUserProfilePtr;

@end


NS_ASSUME_NONNULL_END
