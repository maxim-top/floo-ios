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

/**
 * @brief SDK设置管理
 **/
class EXPORT_API BMXSDKConfig {
public:
  /**
   * @brief 服务设置
   * @param imHost IM服务器地址
   * @param imPort IM服务器端口
   * @param restHost ratel服务器地址
   * @param path 读取的本地配置文件的位置
   **/
  struct HostConfig {
    HostConfig() {}
    HostConfig(const std::string& im, int port, const std::string& rest, const std::string& rtc) : imHost(im), imPort(port), restHost(rest), rtcHost(rtc) {}
    HostConfig(const std::string& hostConfig) : config(hostConfig) {}
    std::string imHost;
    int imPort;
    std::string restHost;
    std::string rtcHost;
    std::string config;
  };

  /**
   * @brief 构造函数
   * @param type 客户端类型
   * @param vsn 客户端OS版本
   * @param dataDir 聊天数据存储路径
   * @param cacheDir 缓存数据存储路径
   * @param SDKVersion SDK版本
   * @param pushCertName Push证书名字
   * @param userAgent 用户代理信息
   * @param deliveryAck 是否发送消息送达回执
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
   * @brief 构造函数
   * @param type 客户端类型
   * @param vsn 客户端OS版本
   * @param dataDir 聊天数据存储路径
   * @param cacheDir 缓存数据存储路径
   * @param SDKVersion SDK版本
   * @param pushCertName Push证书名字
   * @param userAgent 用户代理信息
   * @param appId 用户的appId
   * @param appSecret 用户的appSecret（对于使用推送的用户，必须同时设置appId和appSecret）
   * @param deliveryAck 是否发送消息送达回执
   **/
  BMXSDKConfig(BMXClientType type,
               const std::string& vsn,
               const std::string &dataDir,
               const std::string &cacheDir,
               const std::string &SDKVersion,
               const std::string &pushCertName,
               const std::string &userAgent,
               const std::string &appId,
               const std::string &appSecret,
               bool deliveryAck = false);

  /**
   * @brief 析构函数
   **/
  virtual ~BMXSDKConfig();

  /**
   * @brief 获取聊天数据存储路径，包含消息、附件等
   * @return std::string
   **/
  const std::string& getDataDir();

  /**
   * @brief 获取缓存数据存储路径，比如用户头像
   * @return std::string
   **/
  const std::string& getCacheDir();

  /**
   * @brief 客户端类型
   * @return BMXClientType
   **/
  BMXClientType getClientType();

  /**
   * @brief 客户端OS版本
   * @return std::string
   **/
  const std::string& getVsn();

  /**
   * @brief SDK版本
   * @return std::string
   **/
  const std::string& getSDKVersion();

  /**
   * @brief 获取Push证书名字
   * @return std::string
   **/
  const std::string& getPushCertName();

  /**
   * @brief 设置Push证书名字
   * @return std::string
   **/
  void setPushCertName(const std::string&);

  /**
   * @brief 获取用户代理信息
   * @return std::string
   **/
  const std::string& getUserAgent();

  /**
   * @brief 发送消息的config中是否携带
   * @return bool
   **/
  bool carryUsernameInMessage();

  /**
   * @brief 设置发送消息的config中是否携带用户名
   * @param bool 设置是否在送消息的config中携带用户名
   **/
  void setCarryUsernameInMessage(bool);

  /**
   * @brief 是否发送消息送达回执
   * @return bool
   **/
  bool enableDeliveryAck();

  /**
   * @brief 设置是否发送消息送达回执
   * @param bool 是否发送消息送达回执
   **/
  void setEnableDeliveryAck(bool);

  /**
   * @brief Log输出等级
   * @return BMXLogLevel
   **/
  BMXLogLevel getLogLevel();

  /**
   * @brief 设置Log输出等级
   * @param BMXLogLevel Log输出等级
   **/
  void setLogLevel(BMXLogLevel);

  /**
   * @brief Log是否输出到Console
   * @return bool
   **/
  bool getConsoleOutput();

  /**
   * @brief 设置Log是否输出到Console
   * @param bool 设置Log是否输出到Console
   **/
  void setConsoleOutput(bool);

  /**
   * @brief 设置服务器配置
   * @param config 服务器配置
   **/
  void setHostConfig(const HostConfig& config);

  /**
   * @brief 获取服务器配置
   * @return HostConfig
   **/
  const HostConfig& getHostConfig();

  /**
   * @brief 是否根据服务器返回未读列表创建所有会话.
   * @return bool
   **/
  bool getLoadAllServerConversations();

  /**
   * @brief 是否根据服务器返回未读列表创建所有会话，默认为false，只会创建有未读消息的会话。
   * @param enable 是否根据服务器返回未读列表创建所有会话
   **/
  void setLoadAllServerConversations(bool enable = false);

  /**
   * @brief 获取设备的唯一识别码
   * @return std::string
   **/
  const std::string& getDeviceUuid();

  /**
   * @brief 设置设备的唯一识别码，在app卸载之前应该始终保持一致，app删除后再次安装时可以产生不同的设备识别码。
   * @param uuid 设备的唯一识别码。
   **/
  void setDeviceUuid(const std::string &uuid);

  /**
   * @brief 获取设备的本地数据库加密密钥。
   * @return std::string
   **/
  const std::string& getDBCryptoKey();

  /**
   * @brief 设置本地数据库的加密密钥，在app卸载之前应该始终保持一直，app删除后再次安装时可以产生不同的密钥。用于本地数据库加密。
   * @param cryptoKey 本地数据库的加密密钥。
   **/
  void setDBCryptoKey(const std::string &cryptoKey);

  /**
   * @brief 获取https请求是否验证服务器端证书。
   * @return bool
   **/
  bool getVerifyCertificate();

  /**
   * 设置https请求是否验证服务器端证书。
   * @param verify https请求是否验证服务器端证书
   **/
  void setVerifyCertificate(bool verify = true);

  /**
   * @brief 获取是否启用dns功能。
   * @return bool
   **/
  bool getEnableDNS();

  /**
   * @brief 设置是否启用dns功能，默认是开启的。
   * @param enable 是否启用dns功能
   **/
  void setEnableDNS(bool enable = true);

  /**
   * @brief 获取用户自定义dns服务器地址。
   * @return std::string
   **/
  std::string getUserDNSAddress();

  /**
   * @brief 设置用户自定义dns服务器地址，在用户设置了dns服务器的情况下优先使用用户dns。
   * @param dns 用户自定义dns服务器地址
   **/
  void setUserDNSAddress(const std::string &dns);

  /**
   * @brief 获取用户的appID。
   * @return std::string
   **/
  std::string getAppID();

  /**
   * @brief 设置用户的appID。
   * @param appID 用户的appID
   **/
  void setAppID(const std::string &appID);

  /**
   * @brief 获取用户的appSecret。
   * @return std::string
   **/
  std::string getAppSecret();

  /**
   * @brief 设置用户的appSecret。
   * @param appID 用户的appSecret
   **/
  void setAppSecret(const std::string &appSecret);

  /**
   * @brief 获取用户的推送提供商类型。
   * @return BMXPushProviderType
   **/
  BMXPushProviderType getPushProviderType();

  /**
   * @brief 设置用户的推送提供商类型。
   * @param type 用户的推送提供商类型
   **/
  void setPushProviderType(BMXPushProviderType type);

  /**
   * @brief 获取用户的推送环境类型。
   * @return BMXPushEnvironmentType
   **/
  BMXPushEnvironmentType getPushEnvironmentType();

  /**
   * @brief 设置用户的推送环境类型。
   * @param type 用户的推送环境类型
   **/
  void setEnvironmentType(BMXPushEnvironmentType type);

  /**
   * @brief 获取调试log接收着账号(仅用于SDK调试，接收客户端log日志使用)
   * @return int64_t
   **/
  int64_t getDebugLogReceiverId();

  /**
   * @brief 设置调试log接收账号(仅用于SDK调试，接收客户端log日志使用)
   * @param uid 调试log接收者id
   **/
  void setDebugLogReceiverId(int64_t uid);

  /**
   * @brief 获取当前 appid 对应的 app 级别的应用设置
   * @return std::string
   **/
  std::string getAppConfig();

  /**
   * @brief 设置当前 appid 对应的 app 级别的应用设置
   * @param config 获取的 config 的 json 配置内容
   **/
  void setAppConfig(const std::string &config);

private:
  void LoadLocalAppConfig();
  void saveLocalAppConfig(const std::string& config);

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
  bool mCarryUsername;
  bool mEnableDeliveryAck;
  HostConfig mHostConfig;
  bool mLoadAllServerConversations;
  std::string mDeviceUuid;
  std::string mDBCryptoKey;
  bool mVerifyCertificate;
  bool mEnableDNS;
  std::string mDNSAddress;
  std::string mAppID;
  std::string mAppSecret;
  BMXPushProviderType mPushProviderType;
  BMXPushEnvironmentType mPushEnvironmentType;
  int64_t mLogReceiverId;
  std::string mAppConfig;
  std::string mAppconfigFilePath;
};

typedef std::shared_ptr<BMXSDKConfig> BMXSDKConfigPtr;

}

#endif /* bmx_sdk_config_h */
