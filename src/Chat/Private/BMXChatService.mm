// ----------------------------------------------------------------------
// File    : BMXChatService.m
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


#import "BMXChatService.h"
#import "BMXChatService+Private.h"
#import "BMXError.h"
#import "BMXError+Private.h"
#import "BMXMessageObject.h"
#import "BMXConversation.h"
#import "BMXMessageObject+Private.h"
#import "BMXConversation+Private.h"
#import "BMXStringUtil.h"
#include "bmx_chat_service.h"


@implementation BMXChatService

- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super initWithClientPtr:aClientPtr]) {
        chatListener = new floosdk::ChatServiceListener();
        if (chatListener) {
            floo::BMXChatService &chatService = aClientPtr->getChatService();
            chatService.addChatListener(chatListener);
        }
    }
    return self;
}

- (void)handleMessage:(BMXMessageObject *)aMessage
              aIsSend:(BOOL)aIsSend
              handler:(void (^)(floo::BMXMessagePtr coreMsg))aHandler
           completion:(void (^)(BMXMessageObject *message, BMXError *error))aCompletionBlock {

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BMXError *error = nil;
        if (!aMessage) {
            error = [BMXError errorCode:BMXMessageInvalid];
        } else {
            floo::BMXMessagePtr corePtr = [self p_getCorePtrWithMessage:aMessage error:&error];
            if (!error) {
                aHandler(corePtr);
                return;
            }
        }
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(aMessage, error);
            });
        }
    });
}

- (void)sendMessageReadAck:(BMXMessageObject *)aMessage
                completion:(void (^)(BMXMessageObject *aMessage, BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BMXError *error = nil;
        floo::BMXMessagePtr msgPtr = [aMessage getMessagePtr];
        if(msgPtr) {
            self->clientPtr->getChatService().ackMessage(msgPtr);
        }
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(aMessage, error);
            });
        }
    });

}

/**
 发送消息，消息状态变化会通过listener通知
 **/
- (void)sendMessage:(BMXMessageObject *)message {
    self->clientPtr->getChatService().sendMessage([message getMessagePtr]);
}

/**
 重新发送消息，消息状态变化会通过listener通知
 **/
- (void)resendMessage:(BMXMessageObject *)message
           completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock {
    [self handleMessage:message aIsSend:YES handler:^(floo::BMXMessagePtr coreMsg) {
        self->clientPtr->getChatService().resendMessage([message getMessagePtr]);
    } completion:aCompletionBlock];
}

/**
 撤回消息，消息状态变化会通过listener通知
 **/
- (void)recallMessage:(BMXMessageObject *)message
           completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock {
    [self handleMessage:message aIsSend:YES handler:^(floo::BMXMessagePtr coreMsg) {
        self->clientPtr->getChatService().recallMessage([message getMessagePtr]);
    } completion:aCompletionBlock];
}

- (void)forwardMessage:(BMXMessageObject *)message {
    clientPtr->getChatService().forwardMessage([message getMessagePtr]);
}

/**
 * 发送已读回执
 **/
- (void)ackMessage:(BMXMessageObject *)message {
    self->clientPtr->getChatService().ackMessage([message getMessagePtr]);
}

/**
 * 标记此消息为未读，该消息同步到当前用户的所有设备
 **/
- (void)readCancel:(BMXMessageObject *)message {
    clientPtr->getChatService().readCancel([message getMessagePtr]);
}

/**
 * 标记此消息及之前全部消息为已读，该消息同步到当前用户的所有设备
 **/
- (void)readAllMessage:(BMXMessageObject *)message {
    clientPtr->getChatService(). readAllMessage([message getMessagePtr]);
}


/**
 * 下载缩略图，下载状态变化和进度通过listener通知
 **/
- (void)downloadThumbnail:(BMXMessageObject *)message
                 strategy:(ThumbnailStrategy)strategy {
        self->clientPtr->getChatService().downloadThumbnail([message getMessagePtr], (floo::BMXChatService::ThumbnailStrategy)strategy);
}


/**
 *  发送送达回执
 **/
- (void)ackMessageDelivered:(BMXMessageObject *)message {
        self->clientPtr->getChatService().ackMessageDelivered([message getMessagePtr]);
}

/**
 *  上传或下载中的文件数
 **/
- (int)transferingNum{
    return self->clientPtr->getChatService().transferingNum();
}


/**
 * 下载附件，下载状态变化和进度通过listener通知
 **/
- (void)downloadAttachment:(BMXMessageObject *)message {
    self->clientPtr->getChatService().downloadAttachment([message getMessagePtr]);
}

/**
 * 插入消息
 **/

- (void )insetMessages:(NSArray<BMXMessageObject *> *)list
            completion:(void(^)(BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BMXError *error = nil;
        floo::BMXMessageList messageList;
        for(BMXMessageObject *message in list){
            if ([message isKindOfClass:[BMXMessageObject class]]) {
                floo::BMXMessagePtr m = [message getMessagePtr];
                if (m.get()) {
                    messageList.push_back(m);
                }
            }
        }
        
        if(messageList.size()){
            self->clientPtr->getChatService().insertMessages(messageList);
        }
        
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error);
            });
        }
    });
}

/**
 * 读取一条消息
 **/
- (void)getMessage:(NSInteger)messageId
        completion:(void(^)(BMXMessageObject *message, BMXError *error))aCompletionBlock {
   
    [self handleMessageWith:^floo::BMXMessagePtr(floo::BMXErrorCode &error) {
        return  self->clientPtr->getChatService().getMessage((int64_t) messageId);
    } completion:aCompletionBlock];
    
 }


- (void)handleMessageWith:(floo::BMXMessagePtr (^)(floo::BMXErrorCode &error))param
               completion:(void (^)(BMXMessageObject *message, BMXError *aError))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode err;
            BMXMessageObject *messgae;
            floo::BMXMessagePtr msg = param(err);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                messgae = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(messgae, error);
            });
        });
        
    }
}



/**
 * 删除会话
 **/
- (void)deleteConversationByConversationId:(NSInteger)conversationId
                               synchronize:(BOOL)synchronize {
    self->clientPtr->getChatService().deleteConversation((int64_t)conversationId, (bool)synchronize);
}


/**
 * 打开一个会话
 **/
- (BMXConversation *) openConversation:(NSInteger)conversationId type:(BMXConversationType)type createIfNotExist:(bool)create {
//  floo::BMXConversation::Type converType = [BMXConversation oc_transforBMXConversationType:type];
  floo::BMXConversationPtr ptr =  clientPtr->getChatService().openConversation((int64_t)conversationId, (floo::BMXConversation::Type)type, create);
    return [[BMXConversation alloc] initWithConversationPtr:ptr];
}

- (void)removeMessage:(BMXMessageObject *)message
synchronizeDeviceForce:(BOOL)synchronizeDeviceForce {
    self->clientPtr->getChatService().removeMessage([message getMessagePtr], (bool)synchronizeDeviceForce);
}

/**
 * 获取所有会话
 **/
- (void)getAllConversationsWithCompletion:(void(^)(NSArray *conversations))aCompletionBlock {
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSMutableArray *conversationArray = nil;
        floo::BMXConversationList ptrs = self->clientPtr->getChatService().getAllConversations();
        conversationArray = [NSMutableArray array];
        for (floo::BMXConversationPtr ptr : ptrs) {
            BMXConversation *conversation = [[BMXConversation alloc]initWithConversationPtr:ptr];
            [conversationArray addObject:conversation];
        }
        
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(conversationArray);
        }); 
    });
}

- (void)getAllConversationsUnreadCountWithCompletion:(void(^)(int count))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        int count = self->clientPtr->getChatService().getAllConversationsUnreadCount();
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(count);
        });
    });
}

/**
 * 拉取历史消息
 **/
- (void)retrieveHistoryBMXconversation:(BMXConversation *)conversation
                                 msgId:(long long)msgId
                                  size:(NSUInteger)size
                       completion:(void(^)(NSArray *messageListms, BMXError *error))aCompletionBlock {
    [self handlehistoryMessages:^floo::BMXErrorCode(floo::BMXMessageList &result) {
        return self->clientPtr->getChatService().retrieveHistoryMessages([conversation getConersationPtr], msgId, size, result);
    } completion:aCompletionBlock];
}

/**
 * 搜索消息
 **/
- (void)searchMessagesByKeyWords:(NSString *)keywords
               refTime:(NSTimeInterval)refTime
                  size:(NSUInteger)size
         directionType:(BMXMessageDirection)directionType
            completion:(void (^)(NSArray *array, BMXError *error))aCompletionBlock {
    
    [self handleLoadMessages:^floo::BMXErrorCode(std::vector<floo::BMXMessageList> &itemList) {
        return self->clientPtr->getChatService().searchMessages([BMXStringUtil toStdString:keywords],
                                                                (int64_t)refTime,
                                                                size,
                                                                itemList);
    } completion:aCompletionBlock];
}

/**
 获取发送的群组消息已读用户id列表

 @param message 需要获取已读用户id列表的消息
 @param aCompletionBlock 对该条消息已读的用户id列表，初始传入为空列表
 */
- (void)getGroupAckMessageUserIdListWithMessage:(BMXMessageObject *)message
                                     completion:(void(^)(NSArray *groupMemberIdList, BMXError *error))aCompletionBlock {
    [self handleGroupAckMessages:^floo::BMXErrorCode(std::vector<int64_t> &list) {
        return self->clientPtr->getChatService().getGroupAckMessageUserIdList([message getMessagePtr], list);
    } completion:aCompletionBlock];
}

- (void)getGroupAckMessageUnreadUserIdListWithMessage:(BMXMessageObject *)message
                                           completion:(void(^)(NSArray *groupMemberIdList, BMXError *error))aCompletionBlock {
    [self handleGroupAckMessages:^floo::BMXErrorCode(std::vector<int64_t> &list) {
        return self->clientPtr->getChatService().getGroupAckMessageUnreadUserIdList([message getMessagePtr], list);
    } completion:aCompletionBlock];
    
}

- (void)addChatListener:(id<BMXChatServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    
    if ([listener conformsToProtocol:@protocol(BMXChatServiceProtocol)]) {
        chatListener->addDelegate(listener, nil);
    }
}

- (void)addDelegate:(id<BMXChatServiceProtocol>)aDelegate { 
    [self addDelegate:aDelegate delegateQueue:nil];
}

- (void)addDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)aQueue {
    if ([aDelegate conformsToProtocol:@protocol(BMXChatServiceProtocol)]) {
        chatListener->addDelegate(aDelegate, aQueue);
    }
}

- (void)removeChatListener:(id<BMXChatServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    
    if ([listener conformsToProtocol:@protocol(BMXChatManager)]) {
        chatListener->removeDelegate(listener);
    }
}

- (void)removeChatListener {
    if (chatListener) {
        clientPtr->getChatService().removeChatListener(chatListener);
    }
}

- (NSString *)getAttachmentDir {
    return [BMXStringUtil stdToNSString:clientPtr->getChatService().attachmentDir()];
}

- (NSString *)getAttachmentDirForConversationWith:(NSString *)conversationId {
    return [BMXStringUtil stdToNSString:clientPtr->getChatService().attachmentDirForConversation([conversationId longLongValue])];

}

- (floo::BMXMessagePtr)p_getCorePtrWithMessage:(BMXMessageObject *)aMessage
   error:(BMXError **)pError {
    BMXError *error = nil;
    floo::BMXMessagePtr corePtr = nullptr;
        do {
            if (aMessage == nil) {
                error = [BMXError errorCode:BMXMessageInvalid];
                break;
            }
    
            corePtr = [aMessage getMessagePtr];
            if (!corePtr) {
                error = [BMXError errorCode:BMXMessageInvalid];
                break;
            }
        } while (0);
    
        if (pError) {
            *pError = error;
        }
    corePtr = [aMessage getMessagePtr];
    
    return corePtr;
}


- (void)handleLoadMessages:(floo::BMXErrorCode (^)(std::vector<floo::BMXMessageList> &result))handle
                completion:(void (^)(NSArray *, BMXError *))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSMutableArray *resultArray = nil;
        NSMutableArray *messageArray = nil;
        std::vector<floo::BMXMessageList> result;
        floo::BMXErrorCode err = handle(result);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            resultArray = [NSMutableArray array];
            for (floo::BMXMessageList list : result) {
                messageArray = [NSMutableArray array];
                for (floo::BMXMessagePtr ptr : list ) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:ptr];
                    [messageArray addObject:message];
                }
                [resultArray addObject:messageArray];
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(resultArray,error);
        });
    });
    
}


- (void)handlehistoryMessages:(floo::BMXErrorCode (^)(floo::BMXMessageList &result))handle
                completion:(void (^)(NSArray *, BMXError *))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSMutableArray *resultArray = nil;
        floo::BMXMessageList mlist;
        floo::BMXErrorCode err = handle(mlist);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            resultArray = [NSMutableArray array];
            for (floo::BMXMessagePtr ptr : mlist) {
                BMXMessageObject *m = [[BMXMessageObject alloc] initWithMessagePtr:ptr];
                [resultArray addObject:m];
            }
        }
                   
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(resultArray,error);
        });
    });
    
}

- (void)handleGroupAckMessages:(floo::BMXErrorCode (^)(std::vector<int64_t> &list))handle
                    completion:(void(^)(NSArray *groupMemberIdList, BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSMutableArray *resultArray = nil;
        std::vector<int64_t>  mIdList;
        floo::BMXErrorCode err = handle(mIdList);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            resultArray = [NSMutableArray array];
            for (int64_t mId : mIdList) {
                [resultArray addObject:[NSString stringWithFormat:@"%lld", mId]];
            }
        }
        
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(resultArray,error);
        });
    });
    
}

- (void)handleResult:(floo::BMXErrorCode (^)())handle
                completion:(void (^)(BMXError *))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXErrorCode err = handle();
        BMXError *error = [BMXError bmx_ErrorWith:err];
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(error);
        });
    });
    
}

@end


@implementation BMXChatService (Private)
- (NSString *)attachmentDir {
    return [BMXStringUtil stdToNSString:clientPtr->getChatService().attachmentDir()];
}

@end
