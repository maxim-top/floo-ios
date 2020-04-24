// ----------------------------------------------------------------------
// File    : BMXConversationObject.m
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
#import "BMXConversation+Private.h"
#import "BMXMessageObject+Private.h"
#import "BMXError.h"
#import "BMXError+Private.h"
#import "BMXStringUtil.h"
#import "BMXClient.h"
#include "bmx_conversation.h"

@interface BMXConversation ()

@property (nonatomic, assign) floo::BMXConversationPtr conversationPtr;

@end

@implementation BMXConversation

- (instancetype)init {
    if (self = [super init]) {
        
        
    }
    return self;

}


/**
 设置消息播放状态（只对语音/视频消息有效）
 
 @param message message
 @param status 播放状态
 @param aCompletionBlock Result
 */
- (void)setMessagePlayedStatus:(BMXMessageObject *)message
                        status:(bool)status
                    completion:(void (^)(BMXMessageObject *aMessage, BMXError *error))aCompletionBlock {

    [self handleLoadMessageStatus:^floo::BMXErrorCode(floo::BMXMessagePtr &ptr) {
        return self->_conversationPtr->setMessagePlayedStatus([message getMessagePtr], (bool)status);
    } completion:aCompletionBlock];
}

/**
 设置消息未读状态，更新未读消息数
 
 @param message message
 @param status 未读状态
 @param aCompletionBlock Result
 */
- (void)setMessageReadStatus:(BMXMessageObject *)message
                      status:(BOOL)status
                  completion:(void(^)(BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode err = self->_conversationPtr->setMessageReadStatus([message getMessagePtr], (bool)status);
            BMXError *errorCode = [BMXError bmx_ErrorWith:err];
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(errorCode);
            });
        });
    }
    
}

- (void)setAllMessagesReadCompletion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleAllMessage:^floo::BMXErrorCode{
        return self->_conversationPtr->setAllMessagesRead();
    } completion:aCompletionBlock];
}



/// 更新一条数据库存储消息的扩展字段信息
/// @param message 需要更改扩展信息的消息此时msg部分已经更新扩展字椴信息
- (void)updateMessageExtension:(BMXMessageObject *)message
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            
            floo::BMXErrorCode err = self->_conversationPtr->updateMessageExtension([message getMessagePtr]);
            BMXError *errorCode = [BMXError bmx_ErrorWith:err];
            
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(errorCode);
            });
        });
    }
}


/**
 插入一条消息
 
 @param msg message
 @param aCompletionBlock Result
 */
- (void)insertMessage:(BMXMessageObject *)msg
           completion:(void(^)(BMXError *error))aCompletionBlock {
    
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            
            floo::BMXErrorCode err = self->_conversationPtr->insertMessage([msg getMessagePtr]);
            BMXError *errorCode = [BMXError bmx_ErrorWith:err];
            
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(errorCode);
            });
        });
    }
    
}


/**
 读取一条消息
 
 @param msgId msgId
 @param aCompletionBlock Result
 */
- (void)loadMessage:(long long)msgId
         completion:(void (^)(BMXMessageObject *message))aCompletionBlock {
    [self handleLoadMessage:^floo::BMXMessagePtr{
        return  self->_conversationPtr->loadMessage(msgId);
    } completion:aCompletionBlock];
}

/**
 删除会话中的所有消息
 
 @param aCompletionBlock Result
 */
- (void)removeAllMessagescompletion:(void(^)(BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode err = self->_conversationPtr->removeAllMessages();
            BMXError *errorCode = [BMXError bmx_ErrorWith:err];
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(errorCode);
            });
        });
    }
}


/**
 加载消息，从参考消息向前加载，如果不指定则从最新消息开始
 
 @param reMsgId 参考消息Id
 @param size size
 @param aCompletionBlock Result：MessageList
 */
- (void)loadMessageFromMessageId:(long long)reMsgId
                            size:(NSUInteger)size
                      completion:(void(^)(NSArray*messageList,
                                          BMXError *error))aCompletionBlock {
    
    [self handleLoadMessages:^floo::BMXErrorCode(std::vector<floo::BMXMessagePtr> &itemList) {
        return self->_conversationPtr->loadMessages(reMsgId, size, itemList);
    } completion:aCompletionBlock];
    
}

- (void)searchMessagesByKeyWords:(NSString *)keywords
               refTime:(NSTimeInterval)refTime
                  size:(NSUInteger)size
         directionType:(BMXMessageDirection)directionType
            completion:(void (^)(NSArray <BMXMessageObject *>*messageList, BMXError *error))aCompletionBlock {
    [self handleLoadMessages:^floo::BMXErrorCode(std::vector<floo::BMXMessagePtr> &itemList) {
        return self->_conversationPtr->searchMessages([BMXStringUtil toStdString:keywords], (int64_t)refTime, size, itemList, (floo::BMXConversation::Direction)directionType);
    } completion:aCompletionBlock];
}

- (void)searchMessagesBycontentType:(BMXContentType)contentType
                            refTime:(NSTimeInterval)refTime
                               size:(NSUInteger)size
                      directionType:(BMXMessageDirection)directionType
                         completion:(void (^)(NSArray <BMXMessageObject *>*messageList, BMXError *error))aCompletionBlock {
    
    [self handleLoadMessages:^floo::BMXErrorCode(std::vector<floo::BMXMessagePtr> &itemList) {
        return self->_conversationPtr->searchMessages((floo::BMXMessage::ContentType)contentType, (int64_t)refTime, size, itemList, (floo::BMXConversation::Direction)directionType);
    } completion:aCompletionBlock];
    
}

- (void)handleLoadMessage:(floo::BMXMessagePtr (^)())handle
               completion:(void (^)(BMXMessageObject *aMessage))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXMessagePtr messagePtr = handle();
        BMXMessageObject *message =[[BMXMessageObject alloc] initWithMessagePtr:messagePtr];
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(message);
        });
    });
    
}

- (void)handleAllMessage:(floo::BMXErrorCode (^)())handle
                     completion:(void (^)(BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXErrorCode code = handle();
        BMXError *error = [BMXError bmx_ErrorWith:code];
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock( error);
        });
    });
    
}

- (void)handleLoadMessageStatus:(floo::BMXErrorCode (^)(floo::BMXMessagePtr &ptr))handle
                     completion:(void (^)(BMXMessageObject *aMessage, BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXMessagePtr messagePtr;
        floo::BMXErrorCode code = handle(messagePtr);
        BMXError *error = [BMXError bmx_ErrorWith:code];
        BMXMessageObject *message;
        if (!error) {
            message = [[BMXMessageObject alloc] initWithMessagePtr:messagePtr];
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(message, error);
        });
    });
    
}

- (void)handleLoadMessages:(floo::BMXErrorCode (^)(std::vector<floo::BMXMessagePtr> &itemList))handle
               completion:(void (^)(NSArray <BMXMessageObject *>*, BMXError *))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
          NSMutableArray *messageArray = nil;
        std::vector<floo::BMXMessagePtr> list;
        floo::BMXErrorCode err = handle(list);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            messageArray = [NSMutableArray array];
            for (floo::BMXMessagePtr messagePtr : list) {
                BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:messagePtr];
                [messageArray addObject:message];
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(messageArray,error);
        });
    });
    
}

#pragma - setter

- (void)setExtensionJson:(NSString *)extensionJson {
    _conversationPtr->setExtension([BMXStringUtil toStdString:extensionJson]);
}

- (void)setEditMessage:(NSString *)editMessage {
    _conversationPtr->setEditMessage([BMXStringUtil toStdString:editMessage]);
}

#pragma mark getter
- (long long)conversationId {
    return self.conversationPtr->conversationId();
}

- (BMXConversationType)type {
    return  (BMXConversationType)self.conversationPtr->type();
}

- (BMXMessageObject *)lastMessage {
    if (self.conversationPtr->lastMsg() != nullptr) {
        BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:self.conversationPtr->lastMsg()];
        return message;

    }
    
    return nil;
        

}

- (NSInteger)unreadNumber {
    if (self.conversationPtr) {
        return (NSInteger)self.conversationPtr->unreadNumber();
    }
    return 0;
}

- (NSInteger)messageCount {
    if (self.conversationPtr != nullptr) {
        return (NSInteger)self.conversationPtr->messageCount();
    }
    return 0;
}

- (BOOL)isMuteNotication {
    
    return (BOOL)self.conversationPtr->isMuteNotification();
}

- (NSString *)extensionJson {
    if (self.conversationPtr != nullptr) {
        return [BMXStringUtil stdToNSString:self.conversationPtr->extension()];
    }
    return @"";
}

- (NSString *)editMessage {
    if (self.conversationPtr != nullptr) {
        return [BMXStringUtil stdToNSString:self.conversationPtr->editMessage()];
    }
    return @"";
}

@end

@implementation BMXConversation (Private)
- (instancetype)initWithConversationPtr:(floo::BMXConversationPtr)conversationPtr {
    if (self = [self init]) {
        _conversationPtr = conversationPtr;
    }
    return self;
}

- (floo::BMXConversationPtr)getConersationPtr {
    return _conversationPtr;
}


@end
