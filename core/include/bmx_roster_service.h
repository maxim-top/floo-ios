//-------------------------------------------------------------------------------------------------
// File    : bmx_roster_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx roster service define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_roster_service_h
#define bmx_roster_service_h

#include <vector>
#include <functional>
#include "bmx_base_object.h"
#include "bmx_roster_item.h"
#include "bmx_result_page.h"

namespace floo {

class BMXRosterServiceListener;

class EXPORT_API BMXRosterService {
public:

  /**
   * 请求状态
   **/
  enum class ApplicationStatus {
    Pending,          // 请求待处理
    Accepted,         // 请求已接受
    Declined          // 请求已拒绝
  };

  /**
   * 好友邀请
   **/
  struct Application {
    Application() {}
    virtual ~Application() {}

    int64_t mRosterId;
    std::string mReason;
    ApplicationStatus mStatus;
    int64_t mExpire;
  };
  typedef std::shared_ptr<Application> ApplicationPtr;
  typedef std::vector<ApplicationPtr> ApplicationList;
  typedef BMXResultPage<ApplicationPtr> BMXRosterApplicationResultPage;
  typedef std::shared_ptr<BMXRosterApplicationResultPage> BMXRosterApplicationResultPagePtr;

  virtual ~BMXRosterService() {}

  typedef std::function<void(int percent)> Callback;

  /**
   * 获取好友列表，如果forceRefresh == true，则强制从服务端拉取
   **/
  virtual BMXErrorCode get(std::vector<int64_t>& list, bool forceRefresh) = 0;

  /**
   * 搜索用户
   **/
  virtual BMXErrorCode search(int64_t rosterId, bool forceRefresh, BMXRosterItemPtr& item) = 0;
  /**
   * 搜索用户
   **/
  virtual BMXErrorCode search(const std::string& name, bool forceRefresh, BMXRosterItemPtr& item) = 0;
  /**
   * 批量搜索用户
   **/
  virtual BMXErrorCode search(const std::vector<int64_t>& rosterIdList, BMXRosterList& list, bool forceRefresh) = 0;

  /**
   * 更新好友本地扩展信息
   **/
  virtual BMXErrorCode setItemLocalExtension(BMXRosterItemPtr item, const JSON& extension) = 0;

  /**
   * 更新好友服务器扩展信息
   **/
  virtual BMXErrorCode setItemExtension(BMXRosterItemPtr item, const JSON& extension) = 0;

  /**
   * 更新好友别名
   **/
  virtual BMXErrorCode setItemAlias(BMXRosterItemPtr item, const JSON& alias) = 0;

  /**
   * 设置是否拒收用户消息
   **/
  virtual BMXErrorCode setItemMuteNotification(BMXRosterItemPtr item, bool status) = 0;

  /**
   * 获取申请添加好友列表
   **/
  virtual BMXErrorCode getApplicationList(BMXRosterApplicationResultPagePtr& result, const std::string& cursor, int pageSize = 10) = 0;

  /**
   * 申请添加好友
   **/
  virtual BMXErrorCode apply(int64_t rosterId, const std::string& message) = 0;

  /**
   * 删除好友
   **/
  virtual BMXErrorCode remove(int64_t rosterId) = 0;

  /**
   * 接受加好友申请
   **/
  virtual BMXErrorCode accept(int64_t rosterId) = 0;

  /**
   * 拒绝加好友申请
   **/
  virtual BMXErrorCode decline(int64_t rosterId, const std::string& reason) = 0;

  /**
   * 加入黑名单
   **/
  virtual BMXErrorCode block(int64_t rosterId) = 0;

  /**
   * 从黑名单移除
   **/
  virtual BMXErrorCode unblock(int64_t rosterId) = 0;

  /**
   * 获取黑名单，如果forceRefresh == true，则强制从服务端拉取
   **/
  virtual BMXErrorCode getBlockList(std::vector<int64_t>& list, bool forceRefresh) = 0;

  /**
   * 下载头像
   **/
  virtual BMXErrorCode downloadAvatar(BMXRosterItemPtr item, bool thumbnail = true, Callback callback = [](int){}) = 0;

  /**
   * 添加好友变化监听者
   **/
  virtual void addRosterListener(BMXRosterServiceListener* listener) = 0;

  /**
   * 移除好友变化监听者
   **/
  virtual void removeRosterListener(BMXRosterServiceListener* listener) = 0;

protected:
  BMXRosterService() {}
};

}

#endif /* bmx_roster_service_h */
