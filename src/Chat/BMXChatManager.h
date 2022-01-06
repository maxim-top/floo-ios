// ----------------------------------------------------------------------
// File    : BMXChatProtocol.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------


#import "BMXConversation.h"
#import "BMXChatServiceProtocol.h"


/**
 * 缩略图生成策略,
 **/
typedef enum {
    ThirdpartyServerCreate = 1,     // 第三方服务器生成
    LocalServerCreate,              // 本地服务器生成
} ThumbnailStrategy;


@class BMXMessageObject;
@class BMXError;
@class BMXMessagePageObject;



@protocol BMXChatManager <NSObject>

@required

- (void)addDelegate:(id<BMXChatServiceProtocol>)aDelegate;

- (void)addDelegate:(id<BMXChatServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id<BMXChatServiceProtocol>)aDelegate;


@optional
/**
 发送消息，消息状态变化会通过listener通知
 **/
- (void)sendMessage:(BMXMessageObject *)message;

/**
 重新发送消息，消息状态变化会通过listener通知
 **/
- (void)resendMessage:(BMXMessageObject *)message
           completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock;

/**
 撤回消息，消息状态变化会通过listener通知
 **/
- (void)recallMessage:(BMXMessageObject *)message
           completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock;

///**
// 合并转发消息
// **/
//- (void)forwardMessage:(NSArray *)messageList
//  conversationReceiver:(BMXConversation *)conversationReceiver
//            completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock;

/**
 简单转发消息，用户应当通过BMXMessagse::createForwardMessage()先创建转发消息
 **/
- (void)forwardMessage:(BMXMessageObject *)message;

/**
 * 发送已读回执
 **/
- (void)ackMessage:(BMXMessageObject *)message;

/**
 *  发送送达回执
 **/
- (void)ackMessageDelivered:(BMXMessageObject *)message;

/**
 *  上传或下载中的文件数
 **/
- (int)transferingNum;

/**
 * 标记此消息为未读，该消息同步到当前用户的所有设备
 **/
- (void)readCancel:(BMXMessageObject *)message;

/**
 * 标记此消息及之前全部消息为已读，该消息同步到当前用户的所有设备
 **/
- (void)readAllMessage:(BMXMessageObject *)message;

/**
 * 下载缩略图，下载状态变化和进度通过listener通知
 * 缩略图生成策略，1 - 第三方服务器生成， 2 - 本地服务器生成，默认值是 1。
 **/
- (void)downloadThumbnail:(BMXMessageObject *)message
                 strategy:(ThumbnailStrategy)strategy;

/**
 * 下载附件，下载状态变化和进度通过listener通知
 **/
- (void)downloadAttachment:(BMXMessageObject *)message;

/**
 * 插入消息
 **/

- (void)insetMessages:(NSArray<BMXMessageObject *> *)list
            completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 读取一条消息
 **/
- (void)getMessage:(NSInteger)messageId
        completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock;

/**
 * 删除此消息，该消息同步到当前用户的其它设备
 **/
- (void)removeMessage:(BMXMessageObject *)message
synchronizeDeviceForce:(BOOL)synchronizeDeviceForce;

/**
 * 删除会话
 **/
- (void)deleteConversationByConversationId:(NSInteger)conversationId
                               synchronize:(BOOL)synchronize;

/**
 * 打开一个会话
 **/
- (BMXConversation *)openConversation:(NSInteger)conversationId type:(BMXConversationType)type createIfNotExist:(bool)create;

/**
 * 获取附件保存路径
 **/
- (NSString *)getAttachmentDir;

/**
 * 获取会话的附件保存路径
 **/
- (NSString *)getAttachmentDirForConversationWith:(NSString *)conversationId;

/**
 * 获取所有会话
 **/
- (void)getAllConversationsWithCompletion:(void(^)(NSArray *conversations))aCompletionBlock;


/**
 获取所有会话的全部未读数（标记为屏蔽的个人和群组的未读数不统计在内）

 @param aCompletionBlock count
 */
- (void)getAllConversationsUnreadCountWithCompletion:(void(^)(int count))aCompletionBlock;

/**
 * 拉取历史消息
 **/
- (void)retrieveHistoryBMXconversation:(BMXConversation *)conversation
                                 msgId:(long long)msgId
                                  size:(NSUInteger)size
                            completion:(void(^)(NSArray *messageListms, BMXError *error))aCompletionBlock;

/**
 * 搜索消息
 **/
- (void)searchMessagesByKeyWords:(NSString *)keywords
               refTime:(NSTimeInterval)refTime
                  size:(NSUInteger)size
         directionType:(BMXMessageDirection)directionType
            completion:(void (^)(NSArray *array, BMXError *error))aCompletionBlock;

/**
 获取发送的群组消息已读用户id列表

 @param message 需要获取已读用户id列表的消息
 @param aCompletionBlock 对该条消息已读的用户id列表，初始传入为空列表
 */
- (void)getGroupAckMessageUserIdListWithMessage:(BMXMessageObject *)message
                                     completion:(void(^)(NSArray *groupMemberIdList, BMXError *error))aCompletionBlock;

/**
 获取发送的群组消息未读用户id列表

 @param message 需要获取未读用户id列表的消息
 @param aCompletionBlock 对该条消息未读的用户id列表，初始传入为空列表
 */
- (void)getGroupAckMessageUnreadUserIdListWithMessage:(BMXMessageObject *)message
                                     completion:(void(^)(NSArray *groupMemberIdList, BMXError *error))aCompletionBlock;

/**
 * 添加聊天监听者
 **/
- (void)addChatListener:(id<BMXChatServiceProtocol>)listener;

/**
 * 移除聊天监听者
 **/
- (void)removeChatListener:(id<BMXChatServiceProtocol>)listener;


@end
