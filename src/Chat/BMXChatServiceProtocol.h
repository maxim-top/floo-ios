// ----------------------------------------------------------------------
// File    : BMXChatServiceProtocol.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/26 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------
#import <Foundation/Foundation.h>

@class BMXMessageObject;
@class BMXError;
@class BMXConversation;

@protocol BMXChatServiceProtocol <NSObject>


@optional

/**
 * 消息发送状态发生变化
 **/
- (void)messageStatusChanged:(BMXMessageObject *)message
            error:(BMXError *)error;

/**
 * 附件上传进度发送变化
 **/
- (void)messageAttachmentUploadProgressChanged:(BMXMessageObject *)message
                                percent:(int)percent;

/**
 * 消息撤回状态发送变化
 **/
- (void)messageRecallStatusDidChanged:(BMXMessageObject *)message
                      error:(BMXError *)error;

/**
 * 收到消息
 **/
- (void)receivedMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到命令消息
 **/
- (void)receivedCommandMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到系统通知消息
 **/
- (void)receivedSystemMessages:(NSArray<BMXMessageObject*> *)messages;


/**
 * 收到消息已读回执
 **/
- (void)receivedReadAcks:(NSArray<BMXMessageObject*> *)messages;


/**
 * 收到消息已送达回执
 **/
- (void)receivedDeliverAcks:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到撤回消息
 **/
- (void)receivedRecallMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到消息已读取消（多设备其他设备同步消息已读状态变为未读）
 **/
- (void)receiveReadCancelsMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到消息全部已读（多设备同步某消息之前消息全部设置为已读）
 **/
- (void)receiveReadAllMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 收到删除消息 （多设备同步删除消息）
 **/
- (void)receiveDeleteMessages:(NSArray<BMXMessageObject*> *)messages;

/**
 * 附件下载状态发生变化
 **/
- (void)messageAttachmentStatusDidChanged:(BMXMessageObject *)message
                          error:(BMXError*)error
                        percent:(int)percent;

/**
 * 拉取历史消息
 **/
- (void)retrieveHistoryMessagesConversation:(BMXConversation *)conversation;


/**
 已经加载完未读会话列表
 */
- (void)loadAllConversationDidFinished;

/**
 本地创建新会话成功

 @param conversation 新创建的本地会话
 @param message 会话的最新消息，存在返回不存在返回为空
 */
- (void)conversationDidCreatedConversation:(BMXConversation *)conversation message:(BMXMessageObject *)message;


/**
 删除会话

 @param conversationId 删除的本地会话id
 @param error 状态错误码
 */
- (void)conversationDidDeletedConversationId:(NSInteger)conversationId error:(BMXError*)error;

/**
 * @brief 更新总未读数
 * @param conversationId 删除的本地会话id
 * @param error 状态错误码
 **/


/**
 更新总未读数

 @param unreadCount 未读数
 */
- (void)conversationTotalCountChanged:(NSInteger)unreadCount;

@end


