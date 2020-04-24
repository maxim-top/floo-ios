//----------------------------------------------------------------------
// File    : UserServiceListener.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/30 by hyt <yutong@bmxlabs.com>
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
#include "bmx_user_service_listener.h"
#import "BMXUserServiceProtocol.h"
#import "BMXDelegatesContainer.h"
#include "bmx_defines.h"



namespace floosdk {

    class UserServiceListener : public floo::BMXUserServiceListener {
        
    public:

        virtual void onConnectStatusChanged(floo::BMXConnectStatus status) override;
        virtual void onUserSignIn(floo::BMXUserProfilePtr profile) override;
        virtual void onUserSignOut(floo::BMXErrorCode error, int64_t userId) override;
        
        
        /**
         * 同步用户信息更新（其他设备操作发生用户信息变更）
         **/
        virtual void onInfoUpdated(floo::BMXUserProfilePtr profile) override;
        
        /**
         * 用户在其他设备上登陆
         **/
        virtual void onOtherDeviceSingIn(int deviceSN)  override;
        
        /**
         * 用户在其他设备上登出
         **/
        virtual void onOtherDeviceSingOut(int deviceSN)  override;

        virtual void addDelegate(id<BMXUserServiceProtocol> delegate, dispatch_queue_t queue);
        virtual void removeDelegate(id<BMXUserServiceProtocol> delegate);
        
        BMXDelegatesContainer<BMXUserServiceProtocol> *container;
        
    private:
        NSObject *containerLock;

    };
}
