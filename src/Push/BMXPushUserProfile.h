//
//  BMXPushUserProfile.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/11/19.
//  Copyright © 2020 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class BMXMessagePushSetting;

@interface BMXPushUserProfile : NSObject

/// 用户ID（唯一）
@property (nonatomic,assign, readonly) NSInteger userId;

/// 推送用户别名
@property (nonatomic,copy, readonly) NSString *pushAlias;

/// 推送用户token
@property (nonatomic,copy, readonly) NSString *pushToken;

/// 推送用户消息设定
@property (nonatomic, strong) BMXMessagePushSetting *setting;


@end

NS_ASSUME_NONNULL_END
