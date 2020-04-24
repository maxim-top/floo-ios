//-------------------------------------------------------------------------------------------------
// File    : bmx_user_profile.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user profile define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_user_profile_h
#define bmx_user_profile_h

#include "bmx_base_object.h"

namespace floo {

class EXPORT_API BMXUserProfile: public BMXBaseObject {

public:
  /**
   * 对方申请加好友时的验证方式
   **/
  enum class AddFriendAuthMode {
    Open,             // 无需验证，任何人可以加为好友
    NeedApproval,     // 需要同意方可加为好友
    AnswerQuestion,   // 需要回答问题正确方可加为好友
    RejectAll         // 拒绝所有加好友申请
  };

  /**
   * 添加好友时的校验问题
   **/
  struct AuthQuestion {
    AuthQuestion() {}

    std::string mQuestion;
    std::string mAnswer;
  };

  struct MessageSetting {
    MessageSetting() {
      mPushEnabled = true;
      mPushDetail = true;
      mNotificationSound = true;
      mNotificationVibrate = true;
      mAutoDownloadAttachment = true;
    }

    // 推送设定
    /**
     * 当APP未打开时是否允许推送
     **/
    bool mPushEnabled;

    /**
     * 是否推送消息详情
     **/
    bool mPushDetail;

    /**
     * 对方收到推送消息时显示的名称
     **/
    std::string mPushNickname;

    // 在线消息设定
    /**
     * 收到消息时是否通过声音提醒
     **/
    bool mNotificationSound;

    /**
     * 收到消息时是否通过震动提醒
     **/
    bool mNotificationVibrate;

    /**
     * 收到消息时是否自动下载缩略图或者语音
     **/
    bool mAutoDownloadAttachment;
  };

  /**
   * 用户类型
   **/
  enum class UserCategory {
    Normal,         // 普通用户
    Advanced        // 高级用户
  };

  /**
   * 析构函数
   **/
  virtual ~BMXUserProfile() {}

  /**
   * 用户ID（唯一）
   **/
  virtual int64_t userId() = 0;

  virtual UserCategory category() = 0;

  /**
   * 用户名（唯一）
   **/
  virtual const std::string& username() = 0;

  /**
   * 用户昵称
   **/
  virtual const std::string& nickname() = 0;

  /**
   * 用户头像
   **/
  virtual std::string avatarUrl() = 0;

  /**
   * 用户头像本地存储路径
   **/
  virtual std::string avatarPath() = 0;

  /**
   * 用户头像缩略图本地存储路径
   **/
  virtual std::string avatarThumbnailPath() = 0;

  /**
   * 用户手机
   **/
  virtual const std::string& mobilePhone() = 0;

  /**
   * 用户公开扩展信息，好友可见
   **/
  virtual const JSON& publicInfo() = 0;

  /**
   * 用户私有扩展信息，好友不可见
   **/
  virtual const JSON& privateInfo() = 0;

  /**
   * 加好友校验方式
   **/
  virtual AddFriendAuthMode addFriendAuthMode() = 0;

  /**
   * 添加好友时的验证问题
   **/
  virtual const AuthQuestion& authQuestion() = 0;

  /**
   * 用户消息设定
   **/
  virtual const MessageSetting& messageSetting() = 0;

  /**
   * 收到群组邀请进群时是否自动同意进群
   **/
  virtual bool isAutoAcceptGroupInvite() = 0;

  /**
   * 用户当前设备的序列号
   **/
  virtual int deviceSN() = 0;

protected:
  BMXUserProfile() {}

private:
  BMXUserProfile(const BMXUserProfile&);
  BMXUserProfile& operator=(const BMXUserProfile&);
};

typedef std::shared_ptr<BMXUserProfile> BMXUserProfilePtr;
}

#endif /* bmx_user_profile_h */
