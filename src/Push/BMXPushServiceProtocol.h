//
//  BMXPushServiceProtocol.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/7/29.
//  Copyright © 2020 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BMXMessageObject;
@class BMXError;

@protocol BMXPushServiceProtocol <NSObject>

@optional

/// Push初始化完成通知。
/// @param bmxToken bmxToken
- (void)pushStartDidFinished:(NSString *)bmxToken;

/// Push功能停止通知。
- (void)pushStartDidStopped;

/// Push初始化完成后获取推送证书。
/// @param certification 推送证书
- (void)certRetrieved:(NSString *)certification;

/// 设置用户推送标签成功回调。
/// @param operationId 操作id
- (void)setTagsDidFinished:(NSString *)operationId;

/// 获取用户推送标签成功回调。
/// @param operationId 操作id
- (void)getTagsDidFinished:(NSString *)operationId;

/// 删除用户推送标签成功回调
/// @param operationId 操作id
- (void)deleteTagsDidFinished:(NSString *)operationId;

/// 清空用户推送成功回调。
/// @param operationId 操作id
- (void)clearedTags:(NSString *)operationId;

/// 接收到新的Push通知
/// @param messages Push通知列表
- (void)receivedPush:(NSArray<BMXMessageObject *> *)messages;

/// 发送Push上行消息状态变化通知。
/// @param message 发生状态变化的上行消息
/// @param error 状态错误码
- (void)pushMessageStatusChanged:(BMXMessageObject *)message error:(BMXError *)error;

@end

NS_ASSUME_NONNULL_END
