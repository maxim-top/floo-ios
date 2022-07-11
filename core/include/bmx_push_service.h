//-------------------------------------------------------------------------------------------------
// File    : bmx_push_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service define file.
// Created : 13 July 2020 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_push_service_h
#define bmx_push_service_h

#include "bmx_message.h"
#include "bmx_error.h"
#include "bmx_push_user_profile.h"

namespace floo {

class BMXPushServiceListener;

class EXPORT_API BMXPushService {
public:

  /**
   * @brief push sdk状态
   **/
  enum class PushSdkStatus {
    /// 正在启动
    Starting = 1,
    /// 启动，在线
    Started,
    /// 停止
    Stoped,
    /// 离线
    Offline
  };

  /**
   * @brief 本地推送消息搜索方向
   **/
  enum class PushDirection {
    /// 取更旧消息
    Up,
    /// 取更新消息
    Down
  };

  virtual ~BMXPushService() {}

  /**
   @brief 初始化推送sdk。在仅使用推送的情况下使用该接口初始化推送sdk。在同时使用IM功能的时候直接在BMXClient调用登陆功能即可。config对象初始化的时候需要传入平台类型和设备id。
   @param alias 推送初始化使用的当前用户别名
   @param bmxToken 推送初始化的时候App传入的使用的用户的token，无用户的状态下不传入即可。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode start(const std::string& alias = "", const std::string& bmxToken = "") = 0;

  /**
   @brief 停止推送功能接口。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode stop() = 0;

  /**
   @brief 恢复推送功能接口。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode resume() = 0;

  /**
   @brief 解除用户别名绑定。
   @param alias 需要解除绑定的用户别名。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode unbindAlias(const std::string& alias) = 0;

  /**
   @brief 获取登陆后使用的用户token。
   @return std::stirng
   **/
  virtual const std::string& getToken() = 0;

  /**
   @brief 获取登陆后服务器返回的推送证书。
   @return std::stirng
   **/
  virtual const std::string& getCert() = 0;

  /**
   @brief 推送sdk当前的状态。
   @return PushSdkStatus
   **/
  virtual PushSdkStatus status() = 0;

  /**
   @brief 推送绑定设备token。
   @param token 设备的推送token
   @return BMXErrorCode
   **/
  virtual BMXErrorCode bindDeviceToken(const std::string& token) = 0;

  /**
   @brief 绑定推送设备的voiptoken。
   @param token 设备的voip推送token
   @return BMXErrorCode
   **/
  virtual BMXErrorCode bindVoipToken(const std::string& token) = 0;

  /**
   @brief 获取推送用户详情，如果forceRefresh == true，则强制从服务端拉取
   @param profile 推送用户profile信息，初始传入指向为空的shared_ptr对象，函数返回后从此处获取用户profile信息。
   @param forceRefresh 是否强制从服务器拉取，本地获取失败的情况下会自动从服务器拉取
   @return BMXErrorCode
   **/
  virtual BMXErrorCode getPushProfile(BMXPushUserProfilePtr& pushProfile, bool forceRefresh) = 0;

  /**
   @brief 设置推送用户的标签。
   @param tags 用户标签
   @param operationId 操作id。在回调通知中对应通知提醒。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setTags(const std::vector<std::string>& tags, const std::string& operationId) = 0;

  /**
   @brief 获取推送用户的标签。
   @param tags 用户标签
   @param operationId 操作id。在回调通知中对应通知提醒。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode getTags(std::vector<std::string>& tags, const std::string& operationId) = 0;

  /**
   @brief 删除推送用户的标签。
   @param tags 要删除用户标签
   @param operationId 操作id。在回调通知中对应通知提醒。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode deleteTags(const std::vector<std::string>& tags, const std::string& operationId) = 0;

  /**
   @brief 清空推送用户的标签。
   @param operationId 操作id。在回调通知中对应通知提醒。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode clearTags(const std::string& operationId) = 0;

  /**
   @brief 设置推送用户的未读角标。
   @param count 用户未读角标数
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setBadge(int count) = 0;

  /**
   @brief 设置推送启用状态。默认为使用推送。
   @param enable 推送的启用状态
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setPushMode(bool enable = true) = 0;

  /**
   @brief 设置允许推送时间。
   @param startHour 静默允许推送的起始时间小时
   @param endHour 静默允许推送的结束时间小时
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setPushTime(int startHour, int endHour) = 0;

  /**
   @brief 设置推送静默的起始结束时间。
   @param startHour 静默推送的起始时间小时
   @param endHour 静默推送的结束时间小时
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setSilenceTime(int startHour, int endHour) = 0;

  /**
   @brief 设置推送是否可以后台运行。默认是false。
   @param enable 推送后台运行状态。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setRunBackgroundMode(bool enable = false) = 0;

  /**
   @brief 设置推送的地理围栏功能是否运行。
   @param enable 地理围栏功能是否运行。
   @param isAllow 用户是否主动弹出用户定位请求。
   @return BMXErrorCode
   **/
  virtual BMXErrorCode setGeoFenceMode(bool enable = false, bool isAllow = false) = 0;

  /**
   @brief 清除指定id的通知。
   @param notificationId 通知id
   **/
  virtual void clearNotification(int64_t notificationId) = 0;

  /**
   @brief 清空下拉通知栏全部通知。
   **/
  virtual void clearAllNotifications() = 0;

  /**
   @brief 发送推送上行消息，消息状态变化会通过listener通知
   @param content 发送的上行推送消息内容
   **/
  virtual void sendMessage(const std::string& content) = 0;

  /**
   @brief 加载数据库本地存储的推送消息。如果不指定则从最新消息开始
   @param refMsgId 加载推送消息的起始id
   @param size 最大加载消息条数
   @param result 数据库返回的加载本地推送消息列表
   @param Direction 加载推送消息的方向，默认是加载更早的消息
   **/
  virtual BMXErrorCode loadLocalPushMessages(int64_t refMsgId, size_t size, BMXMessageList& result, PushDirection = PushDirection::Up) = 0;

  /**
   * @brief 添加推送监听者
   * @param listener 推送监听者
   **/
  virtual void addPushListener(BMXPushServiceListener* listener) = 0;

  /**
   * @brief 移除推送监听者
   * @param listener 推送监听者
   **/
  virtual void removePushListener(BMXPushServiceListener* listener) = 0;
};

}

#endif /* bmx_push_service_h */
