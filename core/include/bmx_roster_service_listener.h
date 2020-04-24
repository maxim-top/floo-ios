//-------------------------------------------------------------------------------------------------
// File    : bmx_roster_service_listener.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx roster service listener define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_roster_service_listener_h
#define bmx_roster_service_listener_h

#include "bmx_roster_item.h"

namespace floo {

class EXPORT_API BMXRosterServiceListener {
public:
  /**
   * 析构函数
   **/
  virtual ~BMXRosterServiceListener() {}

  /**
   * 添加好友
   **/
  virtual void onFriendAdded(int64_t sponsorId, int64_t recipientId) {}

  /**
   * 删除好友
   **/
  virtual void onFriendRemoved(int64_t sponsorId, int64_t recipientId) {}

  /**
   * 收到加好友申请
   **/
  virtual void onApplied(int64_t sponsorId, int64_t recipientId, const std::string& message) {}

  /**
   * 加好友申请被通过了
   **/
  virtual void onApplicationAccepted(int64_t sponsorId, int64_t recipientId) {}

  /**
   * 加好友申请被拒绝了
   **/
  virtual void onApplicationDeclined(int64_t sponsorId, int64_t recipientId, const std::string& reason) {}

  /**
   * 添加黑名单
   **/
  virtual void onBlockListAdded(int64_t sponsorId, int64_t recipientId) {}

  /**
   * 删除黑名单
   **/
  virtual void onBlockListRemoved(int64_t sponsorId, int64_t recipientId) {}

  /**
   * 用户信息更新
   **/
  virtual void onRosterInfoUpdate(BMXRosterItemPtr item) {}
};

}

#endif /* bmx_roster_service_listener_h */
