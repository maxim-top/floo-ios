//-------------------------------------------------------------------------------------------------
// File    : bmx_push_service_listener.h
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

#ifndef bmx_push_service_listener_h
#define bmx_push_service_listener_h

#include "bmx_message.h"
#include "bmx_error.h"
#include "bmx_push_service.h"

namespace floo {

class BMXPushService;
/**
 * @brief 推送服务监听者
 */
class EXPORT_API BMXPushServiceListener {
public:

  /**
   * @brief 构造函数
   **/
  BMXPushServiceListener() : mService(nullptr) {}

  /**
   * @brief 析构函数
   **/
  virtual ~BMXPushServiceListener() {
    if (mService != nullptr) {
      mService->removePushListener(this);
    }
  }

  /**
   * @brief Push初始化完成通知。
   * @param bmxToken 当前push使用bmxToken
   **/
  virtual void onPushStart(const std::string bmxToken) {}

  /**
   * @brief Push功能停止通知。
   **/
  virtual void onPushStop() {}

  /**
   * @brief Push初始化完成后获取推送证书。
   * @param cert 从服务器获取的推送证书
   **/
  virtual void onCertRetrieved(const std::string cert) {}

  /**
   * @brief 设置用户推送成功回调。
   * @param operationId 操作id
   **/
  virtual void onSetTags(const std::string& operationId) {}

  /**
   * @brief 获取用户推送成功回调。
   * @param operationId 操作id
   **/
  virtual void onGetTags(const std::string& operationId) {}

  /**
   * @brief 删除用户推送成功回调。
   * @param operationId 操作id
   **/
  virtual void onDeleteTags(const std::string& operationId) {}

  /**
   * @brief 清空用户推送成功回调。
   * @param operationId 操作id
   **/
  virtual void onClearTags(const std::string& operationId) {}

  /**
   * @brief 接收到新的Push通知。
   * @param list Push通知列表
   **/
  virtual void onReceivePush(const BMXMessageList& list) {}

  /**
   * @brief 发送Push上行消息状态变化通知。
   * @param msg 发生状态变化的上行消息
   * @param error 状态错误码
   **/
  virtual void onStatusChanged(BMXMessagePtr msg, BMXErrorCode error) {}

public:
  /**
   * @brief 注册BMXPushServiceListener绑定到的BMXPushService（SDK内部自动注册）
   * @param service BMXPushService
   **/
  void registerPushService(BMXPushService* service) {
    mService = service;
  }

protected:
  BMXPushService* mService;
};

}

#endif /* bmx_push_service_listener_h */
