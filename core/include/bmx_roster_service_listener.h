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
#include "bmx_roster_service.h"

namespace floo {

class BMXRosterService;

/**
 * @brief 好友变化监听者
 **/
class EXPORT_API BMXRosterServiceListener {
public:
  /**
   * @brief 构造函数
   **/
  BMXRosterServiceListener() : mService(nullptr) {}

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRosterServiceListener() {
    if (mService != nullptr) {
      mService->removeRosterListener(this);
    }
  }

  /**
   * @brief 添加好友
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   **/
  virtual void onFriendAdded(int64_t sponsorId, int64_t recipientId) {}

  /**
   * @brief 删除好友
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   **/
  virtual void onFriendRemoved(int64_t sponsorId, int64_t recipientId) {}

  /**
   * @brief 收到加好友申请
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   * @param message 好友申请消息
   **/
  virtual void onApplied(int64_t sponsorId, int64_t recipientId, const std::string& message) {}

  /**
   * @brief 加好友申请被通过了
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   **/
  virtual void onApplicationAccepted(int64_t sponsorId, int64_t recipientId) {}

  /**
   * @brief 加好友申请被拒绝了
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   * @param reason 申请拒绝原因
   **/
  virtual void onApplicationDeclined(int64_t sponsorId, int64_t recipientId, const std::string& reason) {}

  /**
   * @brief 添加黑名单
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   **/
  virtual void onBlockListAdded(int64_t sponsorId, int64_t recipientId) {}

  /**
   * @brief 删除黑名单
   * @param sponsorId 操作的发起者
   * @param recipientId 操作的接受者
   **/
  virtual void onBlockListRemoved(int64_t sponsorId, int64_t recipientId) {}

  /**
   * @brief 用户信息更新
   * @param item 更新的好友信息
   **/
  virtual void onRosterInfoUpdate(BMXRosterItemPtr item) {}

  /**
   * @brief 客户端从服务器拉取到新联系人时触发，用于用户联系人列表更新，从SDK调用本地获取联系人即可取得全部成员信息
   **/
  virtual void onRosterListUpdate() {}

public:
  /**
   * @brief 注册BMXRosterServiceListener绑定到的BMXRosterService（SDK内部自动注册）
   * @param service BMXRosterService
   **/
  void registerRosterService(BMXRosterService* service) {
    mService = service;
  }

protected:
  BMXRosterService* mService;
};

}

#endif /* bmx_roster_service_listener_h */
