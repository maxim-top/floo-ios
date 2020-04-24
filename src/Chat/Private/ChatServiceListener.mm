// ----------------------------------------------------------------------
// File    : BMXChatManagerListener.m
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

//

#import "ChatServiceListener.h"
#import "BMXMessageObject.h"
#import "BMXMessageObject+Private.h"
#import "BMXError+Private.h"
#import "BMXConversation+Private.h"

namespace floosdk {
    void ChatServiceListener :: onStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error) {
        if (container && msg) {
            BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            [container messageStatusChanged:message error:[BMXError bmx_ErrorWith:error]];
        }
    }
    
    void ChatServiceListener :: onAttachmentUploadProgressChanged(floo::BMXMessagePtr msg, int percent) {
        if (container && msg) {
            BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            [container messageAttachmentUploadProgressChanged:message  percent:percent];
        }
    }
    
    void ChatServiceListener :: onRecallStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error) {
        if (container && msg) {
            BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            [container messageRecallStatusDidChanged:message error:[BMXError bmx_ErrorWith:error]];
        }
    }
    
    void ChatServiceListener :: onReceive(const floo::BMXMessageList &list) {
        if (list.size() && container) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedMessages:messages];
        }
    }

    void ChatServiceListener:: onReceiveCommandMessages(const floo::BMXMessageList& list) {
        if (list.size() && container) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedCommandMessages:messages];
        }
    
    
    }
    
    /**
     * 收到系统通知消息
     **/
    void ChatServiceListener :: onReceiveSystemMessages(const floo::BMXMessageList& list)  {
        if (container && list.size() ) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedMessages:messages];
        }
    }
    
    /**
     * 收到消息已读回执
     **/
    void ChatServiceListener :: onReceiveReadAcks(const floo::BMXMessageList& list)   {
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedReadAcks:messages];
        }
    }
    
    /**
     * 收到消息已送达回执
     **/
    void ChatServiceListener ::  onReceiveDeliverAcks(const floo::BMXMessageList& list)  {
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedDeliverAcks:messages];
        }
    }
    
    /**
     * 收到撤回消息
     **/
    void ChatServiceListener ::  onReceiveRecallMessages(const floo::BMXMessageList& list) {
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receivedRecallMessages:messages];
        }
    }
    
    
    /**
     * 收到消息已读取消（多设备其他设备同步消息已读状态变为未读）
     **/
    void ChatServiceListener :: onReceiveReadCancels(const floo::BMXMessageList& list) {
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receiveReadCancelsMessages:messages];
        }
        
    }
    
    /**
     * 收到消息全部已读（多设备同步某消息之前消息全部设置为已读）
     **/
    void ChatServiceListener ::onReceiveReadAllMessages(const floo::BMXMessageList& list) {
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receiveReadAllMessages:messages];
        }
        
    }
    
    /**
     * 收到删除消息 （多设备同步删除消息）
     **/
    void ChatServiceListener :: onReceiveDeleteMessages(const floo::BMXMessageList& list){
        if (container && list.size()) {
            NSMutableArray *messages = [NSMutableArray array];
            floo::BMXMessageList::const_iterator ite = list.begin();
            for (; ite != list.end(); ++ite) {
                if ((*ite).get() != nullptr) {
                    BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                    [messages addObject:message];
                }
            }
            [container receiveDeleteMessages:messages];
        }
    }
    
    /**
     * 附件下载状态发生变化
     **/
    void ChatServiceListener ::  onAttachmentStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error, int percent) {
        if (container) {
            BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            [container messageAttachmentStatusDidChanged:message error:[BMXError bmx_ErrorWith:error] percent:percent];
        }
    }
    
    void ChatServiceListener:: onRetrieveHistoryMessages(floo::BMXConversationPtr conversation) {
        if (container) {
            BMXConversation *c = [[BMXConversation alloc] initWithConversationPtr:conversation];
            [container retrieveHistoryMessagesConversation:c];
        }
    }
    
    void ChatServiceListener:: onLoadAllConversation() {
        if (container) {
            [container loadAllConversationDidFinished];
        }
    }
    
    void ChatServiceListener:: onConversationCreate(floo::BMXConversationPtr conversation, floo::BMXMessagePtr msg) {
        if (container) {
            BMXConversation *c = [[BMXConversation alloc] initWithConversationPtr:conversation];
            BMXMessageObject *m = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            [container conversationDidCreatedConversation:c message:m];
        }
    }
    
    
    void ChatServiceListener:: onConversationDelete(int64_t conversationId, floo::BMXErrorCode error) {
        if (container) {
            [container conversationDidDeletedConversationId:(NSInteger)conversationId error:[BMXError bmx_ErrorWith:error]];
        }
    }
    
    void ChatServiceListener:: onTotalUnreadCountChanged(int unreadCount) {
        if (container) {
            [container conversationTotalCountChanged:(NSInteger)unreadCount];
        }
    }

    
    
    void ChatServiceListener::addDelegate(id<BMXChatServiceProtocol> delegate, dispatch_queue_t queue) {
        if (!container) {
            container = [(BMXDelegatesContainer<BMXChatServiceProtocol> *)[BMXDelegatesContainer alloc] init];
        }
        
        if (!containerLock) {
            containerLock = [[NSObject alloc] init];
        }
        
        if (delegate) {
            if (!queue) {
                queue = dispatch_get_main_queue();
            }
            
            @synchronized (containerLock) {
                [container addDelegate:delegate delegateQueue:queue];
            }
        }
    }
    
    void ChatServiceListener::removeDelegate(id<BMXChatServiceProtocol> delegate) {
        if (container && delegate) {
            if (!containerLock) {
                containerLock = [[NSObject alloc] init];
            }
            
            @synchronized (containerLock) {
                [container removeDelegate:delegate];
            }
            
        }
    }
    
}

