//-------------------------------------------------------------------------------------------------
// File    : bmx_client.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx client define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __bmx_client_h__
#define __bmx_client_h__

#include "bmx_sdk_config.h"
#include "bmx_network_listener.h"

namespace floo {

class BMXClient;
typedef std::shared_ptr<BMXClient> BMXClientPtr;

}

namespace floo {

class BMXRosterService;
class BMXGroupService;
class BMXChatService;
class BMXUserService;
class BMXNoticeService;

class EXPORT_API BMXClient : public BMXNetworkListener {
public:
  /**
   * 创建BMXClient
   **/
  static BMXClientPtr create(BMXSDKConfigPtr config);

  /**
   * 析构函数
   **/
  virtual ~BMXClient() {}

  /**
   * 获取SDK设置
   **/
  virtual BMXSDKConfigPtr getSDKConfig() = 0;

  /**
   * 获取用户Service
   **/
  virtual BMXUserService& getUserService() = 0;

  /**
   * 获取聊天Service
   **/
  virtual BMXChatService& getChatService() = 0;

  /**
   * 获取群组Service
   **/
  virtual BMXGroupService& getGroupService() = 0;

  /**
   * 获取好友Service
   **/
  virtual BMXRosterService& getRosterService() = 0;

  /**
   * 获取通知Service
   **/
  virtual BMXNoticeService& getNoticeService() = 0;

  /**
   * 处理网络状态发送变化
   **/
  virtual void onNetworkChanged(BMXNetworkType type, bool reconnect) = 0;

protected:
  BMXClient();

private:
  BMXClient(const BMXClient&);
  BMXClient& operator=(const BMXClient&);
};

}

#endif /* __bmx_client_h__ */
