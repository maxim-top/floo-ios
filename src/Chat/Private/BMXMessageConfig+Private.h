//
//  BMXMessageConfig+Private.h
//  MaxIM
//
//  Created by 韩雨桐 on 2019/11/21.
//  Copyright © 2019 hyt. All rights reserved.
//

#import "BMXMessageConfig.h"
#include "bmx_message_config.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BMXMessageConfigDelegate <NSObject>

- (instancetype)initWithBMXMessageConfigPtr:(floo::BMXMessageConfigPtr)messageConfigPtr;
- (floo::BMXMessageConfigPtr)getBMXMessageConfigPtr;

@end


@interface BMXMessageConfig (Private) <BMXMessageConfigDelegate>


@end

NS_ASSUME_NONNULL_END
