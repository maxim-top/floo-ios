//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupServiceListener.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/6 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "GroupServiceListener.h"
#import "BMXGroup.h"
#import "BMXGroup+Private.h"
#import "BMXStringUtil.h"
#import "BMXGroupSharedFile.h"
#import "BMXGroupSharedFile+Private.h"
#import "BMXGroupAnnounment+Private.h"

namespace floosdk {
    
    /**
     * 多设备同步创建群组
     **/
    void GroupServiceListener:: onGroupCreate(floo::BMXGroupPtr group) {
        if (group && container) {
            BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
            [container groupDidCreated:g];
        }
    }
    
    
    /**
     * 退出了某群
     **/
     void GroupServiceListener:: onGroupLeft(floo::BMXGroupPtr group,
                                             const std::string& reason) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSString *reasonStr = [BMXStringUtil stdToNSString:reason];
             [container groupLeft:g reason:reasonStr];
         }
    }
    
    /**
     * 收到入群邀请
     **/
     void GroupServiceListener:: onInvitated(int64_t groupId, int64_t inviter, const std::string& message) {
         if (container) {
             NSString *messageStr = [BMXStringUtil stdToNSString:message];
             [container groupDidRecieveInviter:(NSInteger)inviter groupId:(NSInteger)groupId message:messageStr];
         }
    }
    
    /**
     * 入群邀请被接受
     **/
     void GroupServiceListener:: onInvitationAccepted(floo::BMXGroupPtr group,
                                                      int64_t inviteeId) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupInvitationAccepted:g inviteeId:(NSInteger)inviteeId];
         }
    }
    
    /**
     * 入群申请被拒绝
     **/
     void GroupServiceListener:: onInvitationDeclined(floo::BMXGroupPtr group,
                                                      int64_t inviteeId, const
                                                      std::string& reason) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupInvitationAccepted:g inviteeId:(NSInteger)inviteeId];
         }
    }
    
    /**
     * 收到入群申请
     **/
     void GroupServiceListener:: onApplied(floo::BMXGroupPtr group,
                                           int64_t applicantId,
                                           const std::string& message) {
         
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSString *messageStr = [BMXStringUtil stdToNSString:message];
             [container groupDidRecieveApplied:g
                                   applicantId:(NSInteger)applicantId
                                       message:messageStr];
         }
    }
    
    /**
     * 入群申请被接受
     **/
     void GroupServiceListener:: onApplicationAccepted(floo::BMXGroupPtr group,
                                                       int64_t approver) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupApplicationAccepted:g approver:(NSInteger)approver];
         }
    }
    
    /**
     * 入群申请被拒绝
     **/
     void GroupServiceListener:: onApplicationDeclined(floo::BMXGroupPtr group,
                                                       int64_t approver,
                                                       const std::string& reason) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSString *reasonStr = [BMXStringUtil stdToNSString:reason];
             [container groupApplicationDeclined:g approver:(NSInteger)approver reason:reasonStr];
         }
    }
    
    /**
     * 群成员被禁言
     **/
     void GroupServiceListener:: onMembersBanned(floo::BMXGroupPtr group, const std::vector<int64_t> &members, int64_t duration) {
         if (container && members.size()) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSMutableArray *groupIdList = [NSMutableArray array];
             for(int64_t userId : members) {
                 [groupIdList addObject:[NSNumber numberWithLongLong:(long long)userId]];
             }
             [container groupMembersMutedGroup:g members:groupIdList duration:duration];
         }
    }
    
    /**
     * 群成员被解除禁言
     **/
     void GroupServiceListener:: onMembersUnbanned(floo::BMXGroupPtr group, const std::vector<int64_t>& members) {
         if (container && members.size()) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSMutableArray *groupIdList = [NSMutableArray array];
             for(int64_t userId : members) {
                 [groupIdList addObject:[NSNumber numberWithLongLong:(long long)userId]];
             }
             [container groupMembersUnMutedGroup:g Unmuted:groupIdList];
         }

    }
    /**
     * 加入新成员
     **/
     void GroupServiceListener:: onMemberJoined(floo::BMXGroupPtr group, int64_t memberId, int64_t inviter) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupMemberJoined:g memberId:(NSInteger)memberId inviter:(NSInteger)inviter];
         }
    }
    
    /**
     * 群成员退出
     **/
     void GroupServiceListener:: onMemberLeft(floo::BMXGroupPtr group, int64_t memberId, const std::string& reason) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSString *reasonStr = [BMXStringUtil stdToNSString:reason];
             [container groupMemberLeft:g memberId:(NSInteger)memberId reason:reasonStr];
         }
    }
    
    /**
     * 添加了新管理员
     **/
    void GroupServiceListener:: onAdminsAdded(floo::BMXGroupPtr group, const std::vector<int64_t>& members) {
         if (container && members.size()) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSMutableArray *groupIdList = [NSMutableArray array];
             for(int64_t userId : members) {
                 [groupIdList addObject: [NSNumber numberWithLongLong:(long long)userId]];
             }
             [container groupAdminsAddedGroup:g members:groupIdList];
         }
     };
    
    /**
     * 移除了管理员
     **/
    void GroupServiceListener:: onAdminsRemoved(floo::BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& reason) {
         if (container && members.size()) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             NSMutableArray *groupIdList = [NSMutableArray array];
             for(int64_t userId : members) {
                 [groupIdList addObject:[NSNumber numberWithLongLong: (long long)userId]];
             }
             [container groupAdminsRemovedFromGroup:g members:groupIdList reason:[BMXStringUtil stdToNSString:reason]];
         }
        
     };
    /**
     * 成为群主
     **/
     void GroupServiceListener:: onOwnerAssigned(floo::BMXGroupPtr group) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupOwnerAssigned:g];
         }
     };
    
    /**
     * 群组信息变更
     **/
     void GroupServiceListener:: onGroupInfoUpdate(floo::BMXGroupPtr group, floo::BMXGroup::UpdateInfoType type) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             [container groupInfoDidUpdate:g updateInfoType:(BMXGroupUpdateInfoType)type];
         }
    }
    
    /**
     * 群成员更改群内昵称
     **/
    void GroupServiceListener:: onMemberChangeNickName(floo::BMXGroupPtr group, int64_t memberId, const std::string& nickName) {
        if (container && group) {
            BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
            [container groupMemberDidChangeNickName:g memberId:(long long)memberId nickName:[BMXStringUtil stdToNSString:nickName]];
        }
    }


    /**
     * 收到群公告
     **/
     void GroupServiceListener:: onAnnouncementUpdate(floo::BMXGroupPtr group, floo::BMXGroup::AnnouncementPtr announcement) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             BMXGroupAnnounment *ann = [[BMXGroupAnnounment alloc] initWithBMXGroupAnnounmentPtr:announcement];
             [container groupAnnouncementUpdate:g announcement:ann];
         }
     };
    
    /**
     * 收到共享文件
     **/
     void GroupServiceListener:: onSharedFileUploaded(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             BMXGroupSharedFile *file = [[BMXGroupSharedFile alloc] initWithBMXGroupSharedFilePtr:sharedFile];
             [container groupSharedFileUploaded:g sharedFile:file];
         }
     };
    
    /**
     * 删除了共享文件
     **/
     void GroupServiceListener:: onSharedFileDeleted(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) {
         if (container && group) {
             BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
             BMXGroupSharedFile *file = [[BMXGroupSharedFile alloc] initWithBMXGroupSharedFilePtr:sharedFile];
             [container groupSharedFileDeleted:g sharedFile:file];
         }
        
     };
    
    /**
     * 共享文件更新文件名
     **/
    void GroupServiceListener::onSharedFileUpdated(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) {
        if (container && group) {
            BMXGroup *g = [[BMXGroup alloc] initWithBMXGroupPtr:group];
            BMXGroupSharedFile *file = [[BMXGroupSharedFile alloc] initWithBMXGroupSharedFilePtr:sharedFile];
            [container groupShareFileDidUpdated:g sharedFile:file];
        }
    }
    
    void GroupServiceListener::addDelegate(id<BMXGroupServiceProtocol> delegate, dispatch_queue_t queue) {
        if (!container) {
            container = [(BMXDelegatesContainer<BMXGroupServiceProtocol> *)[BMXDelegatesContainer alloc] init];
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
    
    void GroupServiceListener::removeDelegate(id<BMXGroupServiceProtocol> delegate) {
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
