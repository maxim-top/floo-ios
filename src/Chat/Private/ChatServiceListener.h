// ----------------------------------------------------------------------
// File    : BMXRosterServiceListener.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/24 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------


#import <Foundation/Foundation.h>

#include "bmx_chat_service_listener.h"
#import "BMXChatServiceProtocol.h"
#import "BMXDelegatesContainer.h"


namespace floosdk {
    
    class ChatServiceListener : public floo::BMXChatServiceListener {
        
    public:
        
        /**
         * 消息发送状态发生变化
         **/
        virtual void onStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error)  override;
        
        /**
         * 附件上传进度发送变化
         **/
        virtual void onAttachmentUploadProgressChanged(floo::BMXMessagePtr msg, int percent)  override;
        
        /**
         * 消息撤回状态发送变化
         **/
        virtual void onRecallStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error)  override;
        
        /**
         * 收到消息
         **/
        virtual void onReceive(const floo::BMXMessageList& list)  override;
        
        /**
         * @brief 收到命令消息
         **/
        virtual void onReceiveCommandMessages(const floo::BMXMessageList& list) override;

        
        /**
         * 收到系统通知消息
         **/
        virtual void onReceiveSystemMessages(const floo::BMXMessageList& list)  override;
        
        /**
         * 收到消息已读回执
         **/
        virtual void onReceiveReadAcks(const floo::BMXMessageList& list)  override;
        
        /**
         * 收到消息已送达回执
         **/
        virtual void onReceiveDeliverAcks(const floo::BMXMessageList& list)  override;
        
        /**
         * 收到撤回消息
         **/
        virtual void onReceiveRecallMessages(const floo::BMXMessageList& list)  override;
        
        /**
         * 收到消息已读取消（多设备其他设备同步消息已读状态变为未读）
         **/
        virtual void onReceiveReadCancels(const floo::BMXMessageList& list) override;
        
        /**
         * 收到消息全部已读（多设备同步某消息之前消息全部设置为已读）
         **/
        virtual void onReceiveReadAllMessages(const floo::BMXMessageList& list) override;
        
        /**
         * 收到删除消息 （多设备同步删除消息）
         **/
        virtual void onReceiveDeleteMessages(const floo::BMXMessageList& list) override;
        
        /**
         * 附件下载状态发生变化
         **/
        virtual void onAttachmentStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error, int percent)  override;
        
        /**
         * 拉取历史消息
         **/
        virtual void onRetrieveHistoryMessages(floo::BMXConversationPtr conversation) override;

        virtual void onLoadAllConversation() override;
        
        virtual void onConversationCreate(floo::BMXConversationPtr conversation, floo::BMXMessagePtr msg) override;
        
        virtual void onConversationDelete(int64_t conversationId, floo:: BMXErrorCode error) override;
        
        virtual void onTotalUnreadCountChanged(int unreadCount) override;


        //delegate
        virtual void addDelegate(id<BMXChatServiceProtocol> delegate, dispatch_queue_t queue);
        virtual void removeDelegate(id<BMXChatServiceProtocol> delegate);
        
        BMXDelegatesContainer<BMXChatServiceProtocol> *container;
        //
    private:
        NSObject *containerLock;
    };
}



