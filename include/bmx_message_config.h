//-------------------------------------------------------------------------------------------------
// File    : bmx_message_config.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx result page define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_message_config_h
#define bmx_message_config_h

#include <memory>
#include <string>
#include <mutex>
#include <vector>
#include "bmx_defines.h"
#include "bmx_base_object.h"

namespace floo {

static const std::string kMentionAll = "mentionAll";                    // bool
static const std::string kMentionList = "mentionList";                  // vector<int64_t>
static const std::string kMentionedMessage = "mentionedMessage";        // string
static const std::string kPushMessage = "pushMessage";                  // string
static const std::string kSenderNickname = "senderNickname";            // string
static const std::string kGroupAck = "groupAck";                        // bool
static const std::string kGroupMemberList = "groupMemberList";          // vector<int64_t>
static const std::string kIOSConfig = "ios";                            // string
static const std::string kAndroidConfig = "android";                    // string
static const std::string kPushShowBeginTime = "show_begin_time";        // int
static const std::string kPushShowEndTime = "show_end_time";            // int
static const std::string kPushTitle = "title";                          // string

class BMXMessageConfig;
typedef std::shared_ptr<BMXMessageConfig> BMXMessageConfigPtr;

/**
 * @brief 消息配置
 **/
class EXPORT_API BMXMessageConfig : public BMXBaseObject {
public:
  virtual ~BMXMessageConfig() {}

  /**
   * @brief 设置是否@全员
   * @param mentionAll
   **/
  void setMentionAll(bool mentionAll);

  /**
   * @brief 获取是否@全员
   * @return bool
   **/
  bool getMentionAll();

  /**
   * @brief 设置通知成员id列表
   * @param mentionList
   **/
  void setMentionList(const std::vector<int64_t>& mentionList);
  
  /**
   * @brief 获取@成员列表
   * @return std::vector<int64_t>
   **/
  std::vector<int64_t> getMentionList();

  /**
   * @brief 设置@消息
   * @param mentionedMessage
   **/
  void setMentionedMessage(const std::string &mentionedMessage);

  /**
   * @brief 获取@消息
   * @return std::string
   **/
  std::string getMentionedMessage();

  /**
   * @brief 设置推送消息
   * @param pushMessage
   **/
  void setPushMessage(const std::string &pushMessage);

  /**
   * @brief 获取推送消息
   * @return std::string
   **/
  std::string getPushMessage();

  /**
   * @brief 设置发送者昵称
   * @param senderNickname
   **/
  void setSenderNickname(const std::string &senderNickname);

  /**
   * @brief 获取发送者昵称
   * @return std::string
   **/
  std::string getSenderNickname();

  /**
   * @brief 设置需要群已读消息的群成员id列表
   * @param groupMemberList
   **/
  void setGroupMemberList(const std::vector<int64_t>& groupMemberList);
  
  /**
   * @brief 获取需要群已读消息的群成员id列表
   * @return std::vector<int64_t>
   **/
  std::vector<int64_t> getGroupMemberList();

  /**
   * @brief 添加群已读消息的群成员id列表成员
   **/
  void addGroupMember(int64_t id);

  /**
   * @brief 清除需要群已读消息的群成员id列表成员
   * @return std::vector<int64_t>
   **/
  void removeGroupMember(int64_t id);

  /**
   * @brief 清空群已读消息的群成员id列表
   **/
  void clearGroupMemberList();

    /**
   * @brief 设置IOS系统配置信息
   * @param iosConfig
   **/
  void setIOSConfig(const std::string& iosConfig);

  /**
   * @brief 获取IOS系统配置信息
   * @return std::string
   **/
  std::string getIOSConfig();

  /**
   * @brief 设置Android系统配置信息
   * @param androidConfig
   **/
  void setAndroidConfig(const std::string& androidConfig);

  /**
   * @brief 获取Android系统配置信息
   * @return std::string
   **/
  std::string getAndroidConfig();

  /**
   * @brief 设置推送显示开始时间
   * @param beginTime
   **/
  void setPushShowBeginTime(int beginTime);

  /**
   * @brief 获取推送显示开始时间
   * @return int
   **/
  int getPushShowBeginTime();

  /**
   * @brief 设置推送显示结束时间
   * @param endTime
   **/
  void setPushShowEndTime(int endTime);

  /**
   * @brief 获取推送显示结束时间
   * @return int
   **/
  int getPushShowEndTime();

  /**
   * @brief 设置推送标题
   * @param pushTitle
   **/
  void setPushTitle(const std::string& pushTitle);

  /**
   * @brief 获取推送标题
   * @return std::string
   **/
  std::string getPushTitle();

  /**
   * @brief 序列化操作
   * @return std::string
   **/
  std::string serialize() const;

  static BMXMessageConfigPtr createMessageConfig(bool mentionAll);

  friend std::string encodeBMXMessageConfig(BMXMessageConfigPtr);
  friend BMXMessageConfigPtr decodeBMXMessageConfig(const std::string& config);

private:
  
  BMXMessageConfig() : mMentionAll(false) {}

  std::recursive_mutex mMutex;
  bool mMentionAll;
  std::vector<int64_t> mMentionList;
  std::string mMentionedMessage;
  std::string mPushMessage;
  std::string mSenderNickname;
  std::vector<int64_t> mGroupMemberList;
  std::string mIOSConfig;
  std::string mAndroidConfig;
  int mPushShowBeginTime;
  int mPushShowEndTime;
  std::string mPushTitle;
};

std::string encodeBMXMessageConfig(BMXMessageConfigPtr);
BMXMessageConfigPtr decodeBMXMessageConfig(const std::string& config);

}

#endif /* bmx_message_config_h */
