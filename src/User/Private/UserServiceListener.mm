// ----------------------------------------------------------------------
// File    : UserServiceListener.m
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

#import "UserServiceListener.h"
#import "BMXDefinesTransform.h"
#import "BMXUserProfile+Private.h"
#import "BMXError+Private.h"

namespace floosdk {
    
    void UserServiceListener:: onConnectStatusChanged(floo::BMXConnectStatus status){
        if (container) {
            [container connectStatusDidChanged:[BMXDefinesTransform transformBMXConnectStatus:status]];
        }
    };
    
    void UserServiceListener:: onUserSignIn(floo::BMXUserProfilePtr profile) {
        if (container) {
            BMXUserProfile *profileModel = [[BMXUserProfile alloc] initWithBMXUserProfilePtr:profile];
            [container userSignIn:profileModel];
        }
        
    };
    
    void UserServiceListener:: onUserSignOut(floo::BMXErrorCode error, int64_t userId) {
        if (container) {
            BMXError *errorCode = [BMXError bmx_ErrorWith:error];
            [container userSignOut:errorCode userId:(long long)userId];
        }
    };
    
    /**
     * 同步用户信息更新（其他设备操作发生用户信息变更）
     **/
    void UserServiceListener:: onInfoUpdated(floo::BMXUserProfilePtr profile)  {
        if (container) {
            BMXUserProfile *profileModel = [[BMXUserProfile alloc] initWithBMXUserProfilePtr:profile];
            [container userInfoDidUpdated:profileModel];
        }
    }
    
    /**
     * 用户在其他设备上登陆
     **/
    void UserServiceListener:: onOtherDeviceSingIn(int deviceSN) {
        if (container) {
            [container userOtherDeviceDidSignIn:deviceSN];
        }
    }
    
    /**
     * 用户在其他设备上登出
     **/
    void UserServiceListener:: onOtherDeviceSingOut(int deviceSN) {
        if (container) {
            [container userOtherDeviceDidSignOut:deviceSN];
        }
    }
    
    void UserServiceListener::addDelegate(id<BMXUserServiceProtocol> delegate, dispatch_queue_t queue) {
        if (!container) {
            container = [(BMXDelegatesContainer<BMXUserServiceProtocol> *)[BMXDelegatesContainer alloc] init];
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
    };
    
    void UserServiceListener::removeDelegate(id<BMXUserServiceProtocol> delegate) {
        if (container && delegate) {
            if (!containerLock) {
                containerLock = [[NSObject alloc] init];
            }
            
            @synchronized (containerLock) {
                [container removeDelegate:delegate];
            }
            
        }
    };
    
    
    
 
}

