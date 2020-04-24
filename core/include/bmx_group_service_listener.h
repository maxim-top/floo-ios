//-------------------------------------------------------------------------------------------------
// File    : bmx_group_service_listener.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx group service listener define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_group_service_listener_h
#define bmx_group_service_listener_h

#include "bmx_group.h"

namespace floo {

class EXPORT_API BMXGroupServiceListener {
public:
  /**
   * 析构函数
   **/
  virtual ~BMXGroupServiceListener() {}

  /**
   * 多设备同步创建群组
   **/
  virtual void onGroupCreate(BMXGroupPtr group) {}

  /**
   * 群列表更新了
   **/
  virtual void onGroupListUpdate(const BMXGroupList& list)  {}

  /**
   * 加入了某群
   **/
  virtual void onGroupJoined(BMXGroupPtr group)  {}

  /**
   * 退出了某群
   **/
  virtual void onGroupLeft(BMXGroupPtr group, const std::string& reason)  {}

  /**
   * 收到入群邀请
   **/
  virtual void onInvitated(int64_t groupId, int64_t inviter, const std::string& message)  {}

  /**
   * 入群邀请被接受
   **/
  virtual void onInvitationAccepted(BMXGroupPtr group, int64_t inviteeId)  {}

  /**
   * 入群申请被拒绝
   **/
  virtual void onInvitationDeclined(BMXGroupPtr group, int64_t inviteeId, const std::string& reason)  {}

  /**
   * 收到入群申请
   **/
  virtual void onApplied(BMXGroupPtr group, int64_t applicantId, const std::string& message)  {}

  /**
   * 入群申请被接受
   **/
  virtual void onApplicationAccepted(BMXGroupPtr group, int64_t approver)  {}

  /**
   * 入群申请被拒绝
   **/
  virtual void onApplicationDeclined(BMXGroupPtr group, int64_t approver, const std::string& reason)  {}

  /**
   * 群成员被禁言
   **/
  virtual void onMembersBanned(BMXGroupPtr group, const std::vector<int64_t>& members, int64_t duration)  {}

  /**
   * 群成员被解除禁言
   **/
  virtual void onMembersUnbanned(BMXGroupPtr group, const std::vector<int64_t>& members)  {}

  /**
   * 加入新成员
   **/
  virtual void onMemberJoined(BMXGroupPtr group, int64_t memberId, int64_t inviter)  {}

  /**
   * 群成员退出
   **/
  virtual void onMemberLeft(BMXGroupPtr group, int64_t memberId, const std::string& reason)  {}

  /**
   * 添加了新管理员
   **/
  virtual void onAdminsAdded(BMXGroupPtr group, const std::vector<int64_t>& members)  {}

  /**
   * 移除了管理员
   **/
  virtual void onAdminsRemoved(BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& reason)  {}

  /**
   * 成为群主
   **/
  virtual void onOwnerAssigned(BMXGroupPtr group)  {}

  /**
   * 群组信息变更
   **/
  virtual void onGroupInfoUpdate(BMXGroupPtr group, BMXGroup::UpdateInfoType type) {}

  /**
   * 群成员更改群内昵称
   **/
  virtual void onMemberChangeNickName(BMXGroupPtr group, int64_t memberId, const std::string& nickName) {}

  /**
   * 收到群公告
   **/
  virtual void onAnnouncementUpdate(BMXGroupPtr group, BMXGroup::AnnouncementPtr announcement) {}

  /**
   * 收到共享文件
   **/
  virtual void onSharedFileUploaded(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  /**
   * 删除了共享文件
   **/
  virtual void onSharedFileDeleted(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  /**
   * 共享文件更新文件名
   **/
  virtual void onSharedFileUpdated(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) {}

  /**
   * 添加黑名单
   **/
  virtual void onBlockListAdded(BMXGroupPtr group, const std::vector<int64_t>& members) {}

  /**
   * 删除黑名单
   **/
  virtual void onBlockListRemoved(BMXGroupPtr group, const std::vector<int64_t>& members) {}
};

}

#endif /* bmx_group_service_listener_h */
