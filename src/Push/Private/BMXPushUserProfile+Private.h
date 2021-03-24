//
//  BMXPushUserProfile+Private.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "BMXPushUserProfile.h"
#include "bmx_push_user_profile.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXPushUserProfile (Private)

- (instancetype)initWithBMXPushUserProfilePtr:(floo::BMXPushUserProfilePtr)ptr;

- (floo::BMXPushUserProfilePtr)getBMXUserProfilePtr;


@end

NS_ASSUME_NONNULL_END
