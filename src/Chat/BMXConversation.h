// ----------------------------------------------------------------------
// File    : BMXConversationObject.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
// floo-ios, Copyright (C) 2018-2019   Maxim.Top
//
// ----------------------------------------------------------------------


#import <Foundation/Foundation.h>
#import "BMXMessageObject.h"

@class BMXError;

typedef enum {
    BMXConversationSingle = 0,     // 单聊
    BMXConversationGroup,     // 群聊
    BMXConversationSystem, // 系统通知
} BMXConversationType;

typedef enum {
    BMXMessageDirectionUp = 0, // 取更旧消息
    BMXMessageDirectionDown, // 取更新消息
} BMXMessageDirection;

NS_ASSUME_NONNULL_BEGIN

@interface BMXConversation : NSObject

/**
 会话Id
 */
@property (nonatomic,assign, readonly) long long conversationId;

/**
 会话类型
 */
@property (nonatomic,assign, readonly) BMXConversationType type;

/**
 最新消息
 */
@property (nonatomic, strong, readonly) BMXMessageObject *lastMessage;

/**
 未读消息数量
 */
@property (nonatomic,assign, readonly) NSInteger unreadNumber;

/**
 会话中所有消息数量
 */
@property (nonatomic,assign, readonly) NSInteger messageCount;


/**
 是否提醒用户消息,不提醒的情况下会话总未读数不会统计该会话计数。
 */
@property (nonatomic,assign) BOOL isMuteNotication;

/**
 扩展信息
 */
@property (nonatomic,copy) NSString *extensionJson;

/**
 * 编辑消息
 **/
@property (nonatomic,copy) NSString *editMessage;



/**
 设置消息播放状态（只对语音/视频消息有效）

 @param message message
 @param status 播放状态
 @param aCompletionBlock Result
 */
- (void)setMessagePlayedStatus:(BMXMessageObject *)message
                        status:(bool)status
                    completion:(void (^)(BMXMessageObject *aMessage, BMXError *error))aCompletionBlock;

/**
 设置消息未读状态，更新未读消息数, 本地

 @param message message
 @param status 是否已读
 @param aCompletionBlock Result
 */
- (void)setMessageReadStatus:(BMXMessageObject *)message
                              status:(BOOL)status
                  completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 把所有消息设置为已读，更新未读消息数
 */
- (void)setAllMessagesReadCompletion:(void(^)(BMXError *error))aCompletionBlock;


/// 更新一条数据库存储消息的扩展字段信息
/// @param message 需要更改扩展信息的消息此时msg部分已经更新扩展字椴信息
/// @param aCompletionBlock 更新结果
- (void)updateMessageExtension:(BMXMessageObject *)message
                    completion:(void(^)(BMXError *error))aCompletionBlock;
/**
 插入一条消息

 @param msg message
 @param aCompletionBlock Result
 */
- (void)insertMessage:(BMXMessageObject *)msg
           completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 读取一条消息

 @param msgId msgId
 @param aCompletionBlock Result
 */
- (void)loadMessage:(long long)msgId
completion:(void(^)(BMXMessageObject *message))aCompletionBlock;



/**
 删除会话中的所有消息

 @param aCompletionBlock Result
 */
- (void)removeAllMessagescompletion:(void(^)(BMXError *error))aCompletionBlock;


/**
 加载消息，从参考消息向前加载，如果不指定则从最新消息开始

 @param reMsgId 参考消息Id
 @param size size
 @param aCompletionBlock Result：MessageList
 */
- (void)loadMessageFromMessageId:(long long)reMsgId
                            size:(NSUInteger)size
                      completion:(void(^)(NSArray*messageList,
                                          BMXError *error))aCompletionBlock;

/**
 * 搜索消息，如果不指定则从最新消息开始
 **/
- (void)searchMessagesByKeyWords:(NSString *)keywords
               refTime:(NSTimeInterval)refTime
                  size:(NSUInteger)size
         directionType:(BMXMessageDirection)directionType
            completion:(void (^)(NSArray <BMXMessageObject *>*messageList, BMXError *error))aCompletionBlock;

/**
 * 按照类型搜索消息，如果不指定则从最新消息开始
 **/
- (void)searchMessagesBycontentType:(BMXContentType)contentType
                            refTime:(NSTimeInterval)refTime
                               size:(NSUInteger)size
                      directionType:(BMXMessageDirection)directionType
                         completion:(void (^)(NSArray <BMXMessageObject *>*messageList, BMXError *error))aCompletionBlock;
@end



NS_ASSUME_NONNULL_END
