//-------------------------------------------------------------------------------------------------
// File    : bmx_sdk_config.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx sdk configuration define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_sdk_config_h
#define bmx_sdk_config_h

#include <string>
#include <memory>
#include <mutex>
#include "bmx_defines.h"

namespace floo {

class EXPORT_API BMXSDKConfig {
public:
  /**
   * 服务设置
   **/
  struct HostConfig {
    HostConfig() {}
    HostConfig(const std::string& im, int port, const std::string& rest) : imHost(im), imPort(port), restHost(rest) {}
    std::string imHost;
    int imPort;
    std::string restHost;
  };

  /**
   * 构造函数
   **/
  BMXSDKConfig(BMXClientType type,
               const std::string& vsn,
               const std::string &dataDir,
               const std::string &cacheDir,
               const std::string &SDKVersion,
               const std::string &pushCertName,
               const std::string &userAgent,
               bool deliveryAck = false);

  /**
   * 析构函数
   **/
  virtual ~BMXSDKConfig();

  /**
   * 获取聊天数据存储路径，包含消息、附件等
   **/
  const std::string& getDataDir();

  /**
   * 获取缓存数据存储路径，比如用户头像
   **/
  const std::string& getCacheDir();

  /**
   * 客户端类型
   **/
  BMXClientType getClientType();

  /**
   * 客户端OS版本
   **/
  const std::string& getVsn();

  /**
   * SDK版本
   **/
  const std::string& getSDKVersion();

  /**
   * 获取Push证书名字
   **/
  const std::string& getPushCertName();

  /**
   * 获取用户代理信息
   **/
  const std::string& getUserAgent();

  /**
   * 是否发送消息送达回执
   **/
  bool enableDeliveryAck();

  /**
   * 设置是否发送消息送达回执
   **/
  void setEnableDeliveryAck(bool);

  /**
   * Log输出等级
   **/
  BMXLogLevel getLogLevel();

  /**
   * 设置Log输出等级
   **/
  void setLogLevel(BMXLogLevel);

  /**
   * Log是否输出到Console
   **/
  bool getConsoleOutput();

  /**
   * 设置Log是否输出到Console
   **/
  void setConsoleOutput(bool);

  /**
   * 设置服务器配置
   **/
  void setHostConfig(const HostConfig& config);

  /**
   * 获取服务器配置
   **/
  const HostConfig& getHostConfig();

  /**
   * 是否根据服务器返回未读列表创建所有会话.
   **/
  bool getLoadAllServerConversations();

  /**
   * 是否根据服务器返回未读列表创建所有会话，默认为false，只会创建有未读消息的会话。
   **/
  void setLoadAllServerConversations(bool enable = false);

  /**
   * 获取设备的唯一识别码
   **/
  const std::string& getDeviceUuid();

  /**
   * 设置设备的唯一识别码，在app卸载之前应该始终保持一致，app删除后再次安装时可以产生不同的设备识别码。
   **/
  void setDeviceUuid(const std::string &uuid);

  /**
   * 获取https请求是否验证服务器端证书。
   **/
  bool getVerifyCertificate();

  /**
   * 设置https请求是否验证服务器端证书。
   **/
  void setVerifyCertificate(bool verify = true);

  /**
   * 获取是否启用dns功能。
   **/
  bool getEnableDNS();

  /**
   * 设置是否启用dns功能，默认是开启的。
   **/
  void setEnableDNS(bool enable = true);

  /**
   * 获取用户自定义dns服务器地址。
   **/
  std::string getUserDNSAddress();

  /**
   * 设置用户自定义dns服务器地址，在用户设置了dns服务器的情况下优先使用用户dns。
   **/
  void setUserDNSAddress(const std::string &dns);

  /**
   * 获取用户的appId。
   **/
  std::string getAppKey();

  /**
   * 设置用户的appId。
   **/
  void setAppKey(const std::string &appKey);

private:
  std::recursive_mutex mMutex;
  std::string mDataDir;
  std::string mCacheDir;
  std::string mVsn;
  std::string mSDKVersion;
  BMXClientType mClientType;
  BMXLogLevel mLogLevel;
  bool mConsoleOutput;
  std::string mPushCertName;
  std::string mUserAgent;
  bool mEnableDeliveryAck;
  HostConfig mHostConfig;
  bool mLoadAllServerConversations;
  std::string mDeviceUuid;
  bool mVerifyCertificate;
  bool mEnableDNS;
  std::string mDNSAddress;
  std::string mAppKey;
};

typedef std::shared_ptr<BMXSDKConfig> BMXSDKConfigPtr;

}

#endif /* bmx_sdk_config_h */
