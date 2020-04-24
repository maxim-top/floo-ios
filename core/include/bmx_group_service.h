//-------------------------------------------------------------------------------------------------
// File    : bmx_group_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx group service define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_group_service_h
#define bmx_group_service_h

#include <functional>
#include "bmx_group.h"
#include "bmx_error.h"
#include "bmx_result_page.h"

namespace floo {

class BMXGroupServiceListener;

class EXPORT_API BMXGroupService {
public:

  typedef std::function<void(int percent)> Callback;

  /**
   * 创建群组选项
   **/
  struct CreateGroupOptions {
    CreateGroupOptions() {}
    CreateGroupOptions(const std::string& name, const std::string& description, bool isPublic = false) :
      mName(name), mDescription(description), mIsPublic(isPublic) {
    }

    std::string mName;                          // 群组名称
    std::string mDescription;                   // 群组描述
    bool mIsPublic;                             // 是否公开群
    std::string mMessage;                       // 建群时成员收到的邀请信息
    std::vector<int64_t> mMembers;              // 建群时添加的成员
  };

  typedef std::shared_ptr<CreateGroupOptions> CreateGroupOptionsPtr;

  virtual ~BMXGroupService() {}

  /**
   * 获取群组列表，如果设置了forceRefresh则从服务器拉取
   **/
  virtual BMXErrorCode search(BMXGroupList& list, bool forceRefresh) = 0;

  /**
   * 获取传入群组id的群组信息列表，如果设置了forceRefresh则从服务器拉取
   **/
  virtual BMXErrorCode search(const std::vector<int64_t>& groupIdList, BMXGroupList& list, bool forceRefresh) = 0;

  /**
   * 获取群信息，如果设置了forceRefresh则从服务器拉取
   **/
  virtual BMXErrorCode search(int64_t groupId, BMXGroupPtr& group, bool forceRefresh) = 0;

  /**
   * 创建群
   **/
  virtual BMXErrorCode create(const CreateGroupOptions& options, BMXGroupPtr& group) = 0;

  /**
   * 销毁群
   **/
  virtual BMXErrorCode destroy(BMXGroupPtr group) = 0;

  /**
   * 加入一个群，根据群设置可能需要管理员批准
   **/
  virtual BMXErrorCode join(BMXGroupPtr group, const std::string& message) = 0;

  /**
   * 退出群
   **/
  virtual BMXErrorCode leave(BMXGroupPtr group) = 0;

  /**
   * 获取群详情，从服务端拉取最新信息
   **/
  virtual BMXErrorCode getInfo(BMXGroupPtr group) = 0;

  /**
   * 获取群组成员详细信息
   **/
  virtual BMXErrorCode getMembersNickname(BMXGroupPtr group, const std::vector<int64_t>& members, BMXGroup::MemberList& list) = 0;

  /**
   * 分页获取群组邀请列表
   **/
  virtual BMXErrorCode getInvitationList(BMXGroupInvitationPagePtr& result, const std::string& cursor = "", int pageSize = 10) = 0;

  /**
   * 分页获取群组申请列表
   **/
  virtual BMXErrorCode getApplicationList(BMXGroupList list, BMXGroupApplicationPagePtr& result, const std::string& cursor = "", int pageSize = 10) = 0;

  /**
   * 分页获取群成员列表，如果设置了forceRefresh则从服务器拉取，单页最大数量为500.
   **/
  virtual BMXErrorCode getMembers(BMXGroupPtr group, BMXGroupMemberResultPagePtr& result, const std::string& cursor = "", int pageSize = 200) = 0;

  /**
   * 获取群成员列表，如果设置了forceRefresh则从服务器拉取，最多拉取1000人
   **/
  virtual BMXErrorCode getMembers(BMXGroupPtr group, BMXGroup::MemberList& list, bool forceRefresh) = 0;

  /**
   * 添加群成员
   **/
  virtual BMXErrorCode addMembers(BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& message) = 0;

  /**
   * 删除群成员
   **/
  virtual BMXErrorCode removeMembers(BMXGroupPtr group, const std::vector<int64_t>& members, const std::string& reason) = 0;

  /**
   * 添加管理员
   **/
  virtual BMXErrorCode addAdmins(BMXGroupPtr group, const std::vector<int64_t>& admins, const std::string& message) = 0;

  /**
   * 删除管理员
   **/
  virtual BMXErrorCode removeAdmins(BMXGroupPtr group, const std::vector<int64_t>& admins, const std::string& reason) = 0;

  /**
   * 获取Admins列表，如果设置了forceRefresh则从服务器拉取
   **/
  virtual BMXErrorCode getAdmins(BMXGroupPtr group, BMXGroup::MemberList& list, bool forceRefresh) = 0;

  /**
   * 添加黑名单
   **/
  virtual BMXErrorCode blockMembers(BMXGroupPtr group, const std::vector<int64_t>& members) = 0;

  /**
   * 从黑名单删除
   **/
  virtual BMXErrorCode unblockMembers(BMXGroupPtr group, const std::vector<int64_t>& members) = 0;

  /**
   * 分页获取黑名单
   **/
  virtual BMXErrorCode getBlockList(BMXGroupPtr group, BMXGroupMemberResultPagePtr& result, const std::string& cursor = "", int pageSize = 200) = 0;

  /**
   * 获取黑名单
   **/
  virtual BMXErrorCode getBlockList(BMXGroupPtr group, BMXGroup::MemberList& list, bool forceRefresh) = 0;

  /**
   * 禁言
   **/
  virtual BMXErrorCode banMembers(BMXGroupPtr group, const std::vector<int64_t>& members, int64_t duration, const std::string& reason = "") = 0;

  /**
   * 解除禁言
   **/
  virtual BMXErrorCode unbanMembers(BMXGroupPtr group, const std::vector<int64_t>& members) = 0;

  /**
   * 分页获取禁言列表
   **/
  virtual BMXErrorCode getBannedMembers(BMXGroupPtr group, BMXGroupBannedMemberResultPagePtr& result, const std::string& cursor = "", int pageSize = 200) = 0;

  /**
   * 获取禁言列表
   **/
  virtual BMXErrorCode getBannedMembers(BMXGroupPtr group, BMXGroup::BannedMemberList& list) = 0;

  /**
   * 设置是否屏蔽群消息
   **/
  virtual BMXErrorCode muteMessage(BMXGroupPtr group, BMXGroup::MsgMuteMode mode) = 0;

  /**
   * 接受入群申请
   **/
  virtual BMXErrorCode acceptApplication(BMXGroupPtr group, int64_t applicantId) = 0;

  /**
   * 拒绝入群申请
   **/
  virtual BMXErrorCode declineApplication(BMXGroupPtr group, int64_t applicantId, const std::string& reason = "") = 0;

  /**
   * 接受入群邀请
   **/
  virtual BMXErrorCode acceptInvitation(BMXGroupPtr group, int64_t inviter) = 0;

  /**
   * 拒绝入群邀请
   **/
  virtual BMXErrorCode declineInvitation(BMXGroupPtr group, int64_t inviter, const std::string& reason = "") = 0;

  /**
   * 转移群主
   **/
  virtual BMXErrorCode transferOwner(BMXGroupPtr group, int64_t newOwnerId) = 0;

  /**
   * 添加群共享文件
   **/
  virtual BMXErrorCode uploadSharedFile(BMXGroupPtr group, const std::string& filePath, const std::string& displayName, const std::string& extensionName, Callback) = 0;

  /**
   * 移除群共享文件
   **/
  virtual BMXErrorCode removeSharedFile(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile) = 0;

  /**
   * 下载群共享文件
   **/
  virtual BMXErrorCode downloadSharedFile(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile, Callback) = 0;

  /**
   * 获取群共享文件列表
   **/
  virtual BMXErrorCode getSharedFilesList(BMXGroupPtr group, BMXGroup::SharedFileList& list, bool forceRefresh) = 0;

  /**
   * 获取共享文件名称
   **/
  virtual BMXErrorCode changeSharedFileName(BMXGroupPtr group, BMXGroup::SharedFilePtr sharedFile, const std::string& name) = 0;

  /**
   * 获取最新的群公告
   **/
  virtual BMXErrorCode getLatestAnnouncement(BMXGroupPtr group, BMXGroup::AnnouncementPtr& announcement, bool forceRefresh) = 0;

  /**
   * 获取群公告列表
   **/
  virtual BMXErrorCode getAnnouncementList(BMXGroupPtr group, BMXGroup::AnnouncementList& list, bool forceRefresh) = 0;

  /**
   * 设置群公告
   **/
  virtual BMXErrorCode editAnnouncement(BMXGroupPtr group, const std::string& title, const std::string& content) = 0;

  /**
   * 获取群公告列表
   **/
  virtual BMXErrorCode deleteAnnouncement(BMXGroupPtr group, int64_t announcementId) = 0;

  /**
   * 设置群名称
   **/
  virtual BMXErrorCode setName(BMXGroupPtr group, const std::string& name) = 0;

  /**
   * 设置群描述信息
   **/
  virtual BMXErrorCode setDescription(BMXGroupPtr group, const std::string& description) = 0;

  /**
   * 设置群扩展信息
   **/
  virtual BMXErrorCode setExtension(BMXGroupPtr group, const std::string& extension) = 0;

  /**
   * 设置在群里的昵称
   **/
  virtual BMXErrorCode setMyNickname(BMXGroupPtr group, const std::string& nickname) = 0;

  /**
   * 设置群消息通知模式
   **/
  virtual BMXErrorCode setMsgPushMode(BMXGroupPtr group, BMXGroup::MsgPushMode mode) = 0;

  /**
   * 设置入群审批模式
   **/
  virtual BMXErrorCode setJoinAuthMode(BMXGroupPtr group, BMXGroup::JoinAuthMode mode) = 0;

  /**
   * 设置邀请模式
   **/
  virtual BMXErrorCode setInviteMode(BMXGroupPtr group, BMXGroup::InviteMode mode) = 0;

  /**
   * 设置群头像
   **/
  virtual BMXErrorCode setAvatar(BMXGroupPtr group, const std::string& avatarPath, Callback) = 0;

  /**
   * 下载群头像
   **/
    virtual BMXErrorCode downloadAvatar(BMXGroupPtr group,  bool thumbnail = true, Callback callback = [](int){}) = 0;

  /**
   * 添加群组变化监听者
   **/
  virtual void addGroupListener(BMXGroupServiceListener* listener) = 0;

  /**
   * 移除群组变化监听者
   **/
  virtual void removeGroupListener(BMXGroupServiceListener* listener) = 0;

protected:
  BMXGroupService() {}
};

}

#endif /* bmx_group_service_h */
