//-------------------------------------------------------------------------------------------------
// File    : bmx_push_user_profile.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user profile define file.
// Created : 27 Sep 2020 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_push_user_profile_h
#define bmx_push_user_profile_h

#include "bmx_base_object.h"

namespace floo {

/**
 * @brief Push用户Profile
 **/

class EXPORT_API BMXPushUserProfile: public BMXBaseObject {

public:
  struct MessagePushSetting {
    MessagePushSetting() {
      mPushEnabled = true;
      mSilenceStartTime = 0;
      mSilenceEndTime = 0;
      mPushStartTime = 0;
      mPushEndTime = 23;
    }

    // 推送设定
    /// 当APP未打开时是否允许推送
    bool mPushEnabled;

    /// 推送静默起始时间
    int mSilenceStartTime;

    /// 推送静默结束时间
    int mSilenceEndTime;

    /// 允许推送起始时间
    int mPushStartTime;

    /// 允许推送结束时间
    int mPushEndTime;
  };

  /**
   * @brief 析构函数
   **/
  virtual ~BMXPushUserProfile() {}

  /**
   * @brief 用户ID（唯一）
   * @return int64_t
   **/
  virtual int64_t userId() = 0;

  /**
   * @brief 推送用户别名
   * @return std::string
   **/
  virtual std::string pushAlias() = 0;

  /**
   * @brief 推送用户token
   * @return std::string
   **/
  virtual std::string pushToken() = 0;

  /**
   * @brief 推送用户消息设定
   * @return MessagePushSetting
   **/
  virtual const MessagePushSetting& messagePushSetting() = 0;

protected:
  BMXPushUserProfile() {}

private:
  BMXPushUserProfile(const BMXPushUserProfile&);
  BMXPushUserProfile& operator=(const BMXPushUserProfile&);
};

typedef std::shared_ptr<BMXPushUserProfile> BMXPushUserProfilePtr;

}

#endif /* bmx_push_profile_h */
