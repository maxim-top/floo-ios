
//
// ----------------------------------------------------------------------
// File    : BMXRosterServiceListener.m
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


#import "RosterServiceListener.h"
#import "BMXStringUtil.h"
#import "BMXRoster.h"
#import "BMXRoster+Private.h"


namespace floosdk {
    
    void RosterServiceListener :: onFriendAdded(int64_t sponsorId, int64_t recipientId) {
        if (container) {
            [container friendAddedSponsorId:(long long)sponsorId recipientId:(long long)recipientId];
        }
    };
    
    void RosterServiceListener :: onFriendRemoved(int64_t sponsorId, int64_t recipientId) {
        if (container) {
            [container friendRemovedSponsorId:(long long)sponsorId recipientId:(long long)recipientId];
        }
    };
    
    void RosterServiceListener:: onApplied(int64_t sponsorId, int64_t recipientId, const std::string &message) {
        if (container) {
            [container friendDidRecivedAppliedSponsorId:(long long)sponsorId recipientId:(long long)recipientId message:[BMXStringUtil stdToNSString:message]];
        }
    };
    
    void RosterServiceListener:: onApplicationAccepted(int64_t sponsorId, int64_t recipientId) {
        if (container) {
            [container friendDidApplicationAcceptedFromSponsorId:(long long)sponsorId recipientId:(long long)recipientId];
        }
        
    };
    
    void RosterServiceListener:: onApplicationDeclined(int64_t sponsorId, int64_t recipientId, const std::string &reason) {
        if (container) {
            [container friendDidApplicationDeclinedFromSponsorId:(long long)sponsorId recipientId:(long long)recipientId reson:[BMXStringUtil stdToNSString:reason]];
        }
    };
    
    
    /**
     * 添加黑名单
     **/
    void RosterServiceListener:: onBlockListAdded(int64_t sponsorId, int64_t recipientId) {
        if (container) {
            [container friendAddedtoBlockListSponsorId:(long long)sponsorId recipientId:(long long)recipientId];
        }
    }
    
    /**
     * 删除黑名单
     **/
     void RosterServiceListener:: onBlockListRemoved(int64_t sponsorId, int64_t recipientId) {
         if (container) {
             [container friendRemovedFromBlockListSponsorId:(long long)sponsorId recipientId:(long long)recipientId];
         }
    }
    
    void RosterServiceListener::onRosterInfoUpdate(floo:: BMXRosterItemPtr item) {
         if (container) {
             BMXRoster *roster = [[BMXRoster alloc] initWithBMXRosterPtr:item];
             [container rosterInfoDidUpdate: roster];
         }
    }

    
    void RosterServiceListener::addDelegate(id<BMXRosterServiceProtocol> delegate, dispatch_queue_t queue) {
        if (!container) {
            container = [(BMXDelegatesContainer<BMXRosterServiceProtocol> *)[BMXDelegatesContainer alloc] init];
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
    
    void RosterServiceListener::removeDelegate(id<BMXRosterServiceProtocol> delegate) {
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

