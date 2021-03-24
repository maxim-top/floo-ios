//
//  BMXMessagePushSetting.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMXMessagePushSetting : NSObject

/// 推送设定
@property (nonatomic, assign) BOOL pushEnabled;

/// 当APP未打开时是否允许推送
@property (nonatomic, assign) NSInteger silenceStartTime;

/// 推送静默结束时间
@property (nonatomic, assign) NSInteger silenceEndTime;

/// 允许推送起始时间
@property (nonatomic, assign) NSInteger pushStartTime;

/// 允许推送结束时间
@property (nonatomic, assign) NSInteger mPushEndTime;


@end

NS_ASSUME_NONNULL_END
