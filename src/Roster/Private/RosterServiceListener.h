//
// ----------------------------------------------------------------------
// File    : BMXRosterServiceListener.h
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
//

#import <Foundation/Foundation.h>
#import "BMXDelegatesContainer.h"
#include "bmx_roster_service_listener.h"
#include "bmx_roster_item.h"
#import "BMXRosterServiceProtocol.h"

namespace floosdk {
    
    class RosterServiceListener : public floo::BMXRosterServiceListener {
    
    public:

        /**
         * 添加好友
         **/
        virtual void onFriendAdded(int64_t sponsorId, int64_t recipientId) override;
        
        /**
         * 删除好友
         **/
        virtual void onFriendRemoved(int64_t sponsorId, int64_t recipientId) override;
        
        /**
         * 收到加好友申请
         **/
        virtual void onApplied(int64_t sponsorId, int64_t recipientId, const std::string& message) override;
        
        /**
         * 加好友申请被通过了
         **/
        virtual void onApplicationAccepted(int64_t sponsorId, int64_t recipientId) override;
        
        /**
         * 加好友申请被拒绝了
         **/
        virtual void onApplicationDeclined(int64_t sponsorId, int64_t recipientId, const std::string& reason) override;
        
        /**
         * 添加黑名单
         **/
        virtual void onBlockListAdded(int64_t sponsorId, int64_t recipientId) override;
        
        /**
         * 删除黑名单
         **/
        virtual void onBlockListRemoved(int64_t sponsorId, int64_t recipientId) override;
        
        
        /**
         * 用户信息更新
         **/
        virtual void onRosterInfoUpdate(floo:: BMXRosterItemPtr item) override;
        
        virtual void addDelegate(id<BMXRosterServiceProtocol> delegate, dispatch_queue_t queue);
        
        virtual void removeDelegate(id<BMXRosterServiceProtocol> delegate);
        
        BMXDelegatesContainer<BMXRosterServiceProtocol> *container;
        
        
    private:
        NSObject *containerLock;
        
    };
}



