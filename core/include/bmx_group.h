//-------------------------------------------------------------------------------------------------
// File    : bmx_group.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx group define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_group_h__
#define bmx_group_h__

#include <vector>
#include "bmx_base_object.h"

namespace floo {

class EXPORT_API BMXGroup: public BMXBaseObject {
public:

  /**
   * 群成员
   **/
  struct Member {
    Member(int64_t uid, const std::string& nickname, int64_t createTime) :
      mUid(uid), mGroupNickname(nickname), mCreateTime(createTime) {}
    virtual ~Member() {}

    int64_t mUid;
    std::string mGroupNickname;
    int64_t mCreateTime;
  };
  typedef std::shared_ptr<Member> MemberPtr;
  typedef std::vector<MemberPtr> MemberList;

  /**
   * 群禁言成员
   **/
  struct BannedMember {
    BannedMember() {}
    virtual ~BannedMember() {}

    int64_t mUid;
    std::string mGroupNickname;
    int64_t mCreateTime;
    int64_t mExpired;
  };
  typedef std::shared_ptr<BannedMember> BannedMemberPtr;
  typedef std::vector<BannedMemberPtr> BannedMemberList;

  /**
   * 群共享文件
   **/
  struct SharedFile {
    SharedFile() {}
    virtual ~SharedFile() {}

    int64_t mFileId;
    int64_t mGroupId;
    int64_t mUploader;
    int mSize;
    int64_t mCreateTime;
    int64_t mUpdateTime;
    std::string mUrl;
    std::string mPath;
    std::string mDisplayName;
    std::string mType;
  };
  typedef std::shared_ptr<SharedFile> SharedFilePtr;
  typedef std::vector<SharedFilePtr> SharedFileList;

  /**
   * 群公告
   **/
  struct Announcement {
    Announcement() {}
    virtual ~Announcement() {}

    std::string mTitle;
    std::string mContent;
    int64_t mAuthor;
    int64_t mCreateTime;
    int64_t mId;
  };
  typedef std::shared_ptr<Announcement> AnnouncementPtr;
  typedef std::vector<AnnouncementPtr> AnnouncementList;

  /**
   * 群邀请状态
   **/
  enum class InvitationStatus {
    Pending,        // 请求待处理
    Accepted,       // 请求已接受
    Declined        // 请求已拒绝
  };

  /**
   * 群邀请
   **/
  struct Invitation {
    Invitation() {}
    ~Invitation() {}

    int64_t mGroupId;
    int64_t mInviterId;
    std::string mReason;
    InvitationStatus mStatus;
    int64_t mExpired;
  };
  typedef std::shared_ptr<Invitation> InvitationPtr;
  typedef std::vector<InvitationPtr> InvitationList;

  /**
   * 群申请状态
   **/
  enum class ApplicationStatus {
    Pending,        // 请求待处理
    Accepted,       // 请求已接受
    Declined        // 请求已拒绝
  };

  /**
   * 群申请
   **/
  struct Application {
    Application() {}
    ~Application() {}

    int64_t mGroupId;
    int64_t mApplicationId;
    std::string mReason;
    ApplicationStatus mStatus;
    int64_t mExpired;
  };
  typedef std::shared_ptr<Application> ApplicationPtr;
  typedef std::vector<ApplicationPtr> ApplicationList;

  /**
   * 消息通知类型
   **/
  enum class MsgPushMode {
    All,                  // 通知所有群消息
    None,                 // 所有消息都不通知
    AdminOrAt,            // 只通知管理员或者被@消息
    Admin,                // 只通知知管理员消息
    At                    // 只通知被@消息
  };

  /**
   * 群信息修改模式
   **/
  enum class ModifyMode {
    Open,                // 所有群成员都可以修改
    AdminOnly           // 只有管理员可以
  };

  /**
   * 进群验证方式
   **/
  enum class JoinAuthMode {
    Open,             // 无需验证
    NeedApproval,     // 需要管理员批准
    RejectAll         // 拒绝所有申请
  };

  /**
   * 邀请入群模式
   **/
  enum class InviteMode {
    Open,           // 所有人都可以邀请他人进群
    AdminOnly       // 只有管理员可以邀请他人进群
  };

  enum class UpdateInfoType {
    UnKnown,              // 默认初始化值
    Name,                 // 修改群名称
    Description,          // 修改群描述
    Avatar,               // 修改群头像
    Owner,                // 修改群主
    Ext,                  // 修改群扩展
    NickName,             // 群成员修改群名片
    ModifyMode,           // 修改群信息模式
    JoinAuthMode,         // 修改进群验证方式
    InviteMode,           // 修改邀请入群模式
    MsgPushMode,          // 修改群消息推送类型
    MsgMuteMode           // 修改是否提醒消息
  };

  /**
   * 群组状态
   **/
  enum class GroupStatus {
    Normal,         // 群组状态正常
    Destroyed,      // 群组已销毁
  };

  enum class MsgMuteMode {
    None,               // 不屏蔽
    MuteNotification,   // 屏蔽本地消息通知
    MuteChat            // 屏蔽消息，不接收消息
  };

  /**
   * 析构函数
   **/
  virtual ~BMXGroup() {}

  /**
   * 群Id
   **/
  virtual int64_t groupId() = 0;

  /**
   * 在群里的昵称
   **/
  virtual const std::string& myNickname() = 0;

  /**
   * 群名称
   **/
  virtual const std::string& name() = 0;

  /**
   * 群描述
   **/
  virtual const std::string& description() = 0;

  /**
   * 群头像
   **/
  virtual std::string avatarUrl() = 0;

  /**
   * 群头像下载后的本地路径
   **/
  virtual std::string avatarPath() = 0;

  /**
   * 群头像缩略图下载后的本地路径
   **/
  virtual std::string avatarThumbnailPath() = 0;

  /**
   * 群创建时间
   **/
  virtual int64_t createTime() = 0;

  /**
   * 群扩展信息
   **/
  virtual const JSON& extension() = 0;

  /**
   * 群Owner
   **/
  virtual int64_t ownerId() = 0;

  /**
   * 最大人数
   **/
  virtual int capacity() = 0;

  /**
   * 群成员数量，包含Owner，admins 和members
   **/
  virtual int membersCount() = 0;

  /**
   * 群管理员数量
   **/
  virtual int adminsCount() = 0;

  /**
   * 黑名单数量
   **/
  virtual int blockListSize() = 0;

  /**
   * 禁言数量
   **/
  virtual int bannedListSize() = 0;

  /**
   * 群共享文件数量
   **/
  virtual int sharedFilesCount() = 0;

  /**
   * 最新群公告id
   **/
  virtual int64_t latestAnnouncementId() = 0;

  /**
   * 群消息通知类型
   **/
  virtual MsgPushMode msgPushMode() = 0;

  /**
   * 群信息修改模式
   **/
  virtual ModifyMode modifyMode() = 0;

  /**
   * 入群审批模式
   **/
  virtual JoinAuthMode joinAuthMode() = 0;

  /**
   * 入群邀请模式
   **/
  virtual InviteMode inviteMode() = 0;

  /**
   * 群消息屏蔽模式
   **/
  virtual MsgMuteMode msgMuteMode() = 0;

  /**
   * 当前群组的状态。（Normal 正常， Destroyed 以销毁）
   **/
  virtual GroupStatus groupStatus() = 0;

  /**
   * 当前用户是否是群成员
   **/
  virtual bool isMember() = 0;

protected:
  BMXGroup() {}

private:
  BMXGroup(const BMXGroup&);
  BMXGroup& operator=(const BMXGroup&);
};

typedef std::shared_ptr<BMXGroup> BMXGroupPtr;
typedef std::vector<BMXGroupPtr> BMXGroupList;

}

#endif /* bmx_group_h__ */
