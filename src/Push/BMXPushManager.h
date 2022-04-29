//
//  BMXPushManager.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/7/17.
//  Copyright © 2020 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMXPushServiceProtocol.h"

@class BMXMessageObject;

typedef enum : NSUInteger {
      /// 正在启动
    Starting = 1,
    /// 启动，在线
    Started,
    /// 停止
    Stoped,
    /// 离线
    Offline
    
} BMXPushSdkStatus;

typedef enum {
    BMXPushMessageDirectionUp = 0, // 取更旧消息
    BMXPushMessageDirectionDown, // 取更新消息
} BMXPushMessageDirection;



@class BMXMessageObject;
@class BMXError;
@class BMXPushUserProfile;


/**
 * 推送管理器
 **/
@protocol BMXPushManager <NSObject>

@required

- (void)addDelegate:(id<BMXPushServiceProtocol>)aDelegate;

- (void)addDelegate:(id<BMXPushServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id<BMXPushServiceProtocol>)aDelegate;


@optional


/// 初始化推送sdk。在仅使用推送的情况下使用该接口初始化推送sdk。在同时使用IM功能的时候直接在BMXClient调用登陆功能即可。config对象初始化的时候需要传入平台类型和设备id。
/// @param alias 推送初始化使用的当前用户别名
/// @param bmxToken 推送初始化的时候App传入的使用的用户的token。
- (void)startWithAlias:(NSString *)alias bmxToken:(NSString *)bmxToken;

/// 初始化推送sdk。在仅使用推送的情况下使用该接口初始化推送sdk。在同时使用IM功能的时候直接在BMXClient调用登陆功能即可。config对象初始化的时候需要传入平台类型和设备id。
/// @param alias 推送初始化使用的当前用户别名
- (void)startWithAlias:(NSString *)alias;

/// 初始化推送sdk。在仅使用推送的情况下使用该接口初始化推送sdk。在同时使用IM功能的时候直接在BMXClient调用登陆功能即可。config对象初始化的时候需要传入平台类型和设备id。
- (void)start;

/// 停止推送功能接口
- (void)stop;

/// 恢复推送功能接口。
- (void)resume;

/// 解除用户别名绑定。
/// @param alias 需要解除绑定的用户别名。
- (void)unbindAlias:(NSString *)alias;

/// 获取登陆后使用的用户token。
- (void)getToken;

/// 获取登陆后服务器返回的推送证书。
- (void)getCertification;

/// 推送sdk当前的状态。
- (BMXPushSdkStatus)status;

/// 推送绑定设备token。
/// @param deviceToken token 设备的推送token
/// @param aCompletionBlock 绑定回调
- (void)bindDeviceToken:(NSString *)deviceToken
             completion:(void(^)(BMXError *error))aCompletionBlock;


/// 获取推送用户详情，如果forceRefresh == true，则强制从服务端拉取
/// @param forceRefresh 是否强制从服务器拉取，本地获取失败的情况下会自动从服务器拉取
/// @param profile 推送用户profile信息，初始传入指向为空的shared_ptr对象，函数返回后从此处获取用户profile信息。
- (void)getPushProfileForceRefresh:(BOOL)forceRefresh
                        completion:(void (^)(BMXPushUserProfile *profile ,BMXError *aError))aCompletionBlock;

/// 设置推送用户的标签。
/// @param tags 用户标签
/// @param operationId 操作id。在回调通知中对应通知提醒。
- (void)setTags:(NSArray <NSString *> *)tags operationId:(NSString *)operationId;

/// 获取推送用户的标签。
/// @param operationId 操作id。在回调通知中对应通知提醒。
/// @param aCompletionBlock 获取回调
- (void)getTagsByOperationId:(NSString *)operationId
              withCompletion:(void(^)(NSArray *tags, BMXError *error))aCompletionBlock;

/// 删除推送用户的标签。
/// @param tags 要删除用户标签
/// @param operationId 操作id。在回调通知中对应通知提醒。
- (void)deleteTags:(NSArray <NSString *> *)tags operationId:(NSString *)operationId;

/// 清空推送用户的标签。
/// @param operationId 操作id。在回调通知中对应通知提醒。
- (void)clearTagsByOperationId:(NSString *)operationId;

/// 设置推送用户的未读角标。
/// @param count 用户未读角标数
- (void)setBadge:(int)count;

/// 设置推送启用状态。默认为使用推送。
/// @param enable 推送的启用状态
- (void)setPushMode:(BOOL)enable;

/// 设置允许推送时间。
/// @param startHour 静默允许推送的起始时间小时
/// @param endHour 静默允许推送的结束时间小时
- (void)setPushTimeStartHour:(int)startHour
                     endHour:(int)endHour;

/// 设置推送静默的起始结束时间。
/// @param startHour 静默推送的起始时间小时
/// @param endHour 静默推送的结束时间小时
- (void)setSlienceTimeStartHour:(int)startHour
                        endHour:(int)endHour;

///  用于移除在通知中心显示的指定推送
///  iOS 10 以上 支持通过identifier 移除指定推送
///  iOS 10 以下 identifier 设置为 0 ，则移除所有推送
/// @param notificationId 如果notificationId 置 0 ，则移除所有推送
- (void)clearNotification:(NSInteger)notificationId;


/// 用于移除在通知中心显示的所有推送
- (void)clearAllNotifications;

/// 发送推送上行消息，消息状态变化会通过listener通知
/// @param message 发送的上行推送消息内容
- (void)sendMessage:(NSString *)message;


/// 加载数据库本地存储的推送消息。如果不指定则从最新消息开始
/// @param reMsgId 加载推送消息的起始id
/// @param size 最大加载消息条数
/// @param directionType 数据库返回的加载本地推送消息列表
/// @param aCompletionBlock 加载推送消息的方向，默认是加载更早的消息
- (void)loadLocalPushMessagesFromMessageId:(long long)reMsgId
                                      size:(NSUInteger)size
                             directionType:(BMXPushMessageDirection)directionType
                                completion:(void(^)(NSArray *messageList, BMXError *error))aCompletionBlock;

/// 添加聊天监听者
/// @param listener 监听者
- (void)addPushListener:(id<BMXPushServiceProtocol>)listener;

/// 移除聊天监听者
/// @param listener 监听者
- (void)removePushListener:(id<BMXPushServiceProtocol>)listener;

 
@end

