//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupServiceListener.h
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
    

#import <Foundation/Foundation.h>
#import "BMXDelegatesContainer.h"
#import "BMXGroupServiceProtocol.h"
#include "bmx_group_service_listener.h"


namespace floosdk {
    
    class GroupServiceListener : public floo::BMXGroupServiceListener {
    public:
        
        /**
         * 多设备同步创建群组
         **/
        virtual void onGroupCreate(floo::BMXGroupPtr group)  override;
        
        /**
         * 退出了某群
         **/
        virtual void onGroupLeft(floo::BMXGroupPtr group, const std::string& reason)  override;
        
        /**
         * 收到入群邀请
         **/
        virtual void onInvitated(int64_t groupId, int64_t inviter, const std::string& message)  override;
        
        /**
         * 入群邀请被接受
         **/
        virtual void onInvitationAccepted(floo::BMXGroupPtr group, int64_t inviteeId)  override;
        
        /**
         * 入群申请被拒绝
         **/
        virtual void onInvitationDeclined(floo::BMXGroupPtr group, int64_t inviteeId, const std::string& reason)  override;
        
        /**
         * 收到入群申请
         **/
        virtual void onApplied(floo::BMXGroupPtr group, int64_t applicantId, const std::string& message)  override;
        
        /**
         * 入群申请被接受
         **/
        virtual void onApplicationAccepted(floo::BMXGroupPtr group, int64_t approver)  override;
        
        /**
         * 入群申请被拒绝
         **/
        virtual void onApplicationDeclined(floo::BMXGroupPtr group, int64_t approver, const std::string& reason)  override;
        
        /**
         * 群成员被禁言
         **/
        virtual void onMembersBanned(floo::BMXGroupPtr group, const std::vector<int64_t>& members, int64_t duration)  override;
        
        /**
         * 群成员被解除禁言
         **/
        virtual void onMembersUnbanned(floo::BMXGroupPtr group, const std::vector<int64_t>& members)  override;
        
        /**
         * 加入新成员
         **/
        virtual void onMemberJoined(floo::BMXGroupPtr group, int64_t memberId, int64_t inviter)  override;
        
        /**
         * 群成员退出
         **/
        virtual void onMemberLeft(floo::BMXGroupPtr group, int64_t memberId, const std::string& reason)  override;
        
        /**
         * 添加了新管理员
         **/
        virtual void onAdminsAdded(floo::BMXGroupPtr group, const std::vector<int64_t>& members)  override;
        
        /**
         * 移除了管理员
         **/
        virtual void onAdminsRemoved(floo::BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& reason)  override;
        
        /**
         * 成为群主
         **/
        virtual void onOwnerAssigned(floo::BMXGroupPtr group)  override;
        
        /**
         * 群组信息变更
         **/
        virtual void onGroupInfoUpdate(floo::BMXGroupPtr group, floo::BMXGroup::UpdateInfoType type) override;
        
        /**
         * 群成员更改群内昵称
         **/
        virtual void onMemberChangeNickName(floo::BMXGroupPtr group, int64_t memberId, const std::string& nickName) override;
        
        /**
         * 收到群公告
         **/
        virtual void onAnnouncementUpdate(floo::BMXGroupPtr group, floo::BMXGroup::AnnouncementPtr announcement) override;

        /**
         * 收到共享文件
         **/
        virtual void onSharedFileUploaded(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) override;
        
        /**
         * 删除了共享文件
         **/
        virtual void onSharedFileDeleted(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) override;
        
        
        /**
         * 共享文件更新文件名
         **/
        virtual void onSharedFileUpdated(floo::BMXGroupPtr group, floo::BMXGroup::SharedFilePtr sharedFile) override;
        
        
        virtual void addDelegate(id<BMXGroupServiceProtocol> delegate, dispatch_queue_t queue);
        
        virtual void removeDelegate(id<BMXGroupServiceProtocol> delegate);
        
        BMXDelegatesContainer<BMXGroupServiceProtocol> *container;
        
    private:
        NSObject *containerLock;
        
    };
    
}
