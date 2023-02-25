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
static const std::string kSilence = "silence";                          // bool
static const std::string kBadge = "badge";                              // int
static const std::string kUsername = "username";                        // string

static const std::string kRTCAction = "action";                         // string
static const std::string kRTCCallType = "type";                         // int
static const std::string kRTCRoomId = "roomId";                         // int64_t
static const std::string kRTCInitiator = "initiator";                   // int64_t
static const std::string kRTCCallId = "callId";                         // string
static const std::string kRTCRoomType = "roomType";                     // int
static const std::string kRTCPin = "pin";                               // string

class BMXMessageConfig;
typedef std::shared_ptr<BMXMessageConfig> BMXMessageConfigPtr;

/**
 * @brief 消息配置
 **/
class EXPORT_API BMXMessageConfig : public BMXBaseObject {
public:

  /**
   * @brief 当前读取的Badge数字的操作类型
   **/
  enum class BadgeCountType {
    /// 读取Badge计数的操作类型为增加或减少。正数为增加负数为减少
    Change,
    /// 设置Badge的计数为当前的计数值
    Set
  };

  /**
   * @brief RTC通话类型
   */
  enum class RTCCallType {
    /// 语音通话
    AudioCall,
    /// 视频通话
    VideoCall
  };

  /**
   * @brief RTC通话房间类型
   */
  enum class RTCRoomType {
    /// 会议模式
    Communication,
    /// 直播模式
    Broadcast
  };

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
   * @brief 获取当前的推送消息是否是静默消息
   * @return bool
   **/
  bool isSilence();

  /**
   * @brief 获取当前的推送消息中badge计数
   * @return BadgeCountType
   **/
  BadgeCountType getBadgeCountType();

  /**
   * @brief 获取当前的推送消息中badge计数
   * @return int
   **/
  int getBadgeCount(int count);

  /**
  * @brief 设置用户名
  * @param username
  **/
  void setUsername(const std::string& username);

  /**
  * @brief 获得用户名
  * @return std::string
  **/
  std::string getUsername();

  /**
  * @brief 设置呼叫消息信息
  * @param calltype 通话类型（语音电话、视频电话）
  * @param roomId 房间id
  * @param initiator 发起者id
  * @param roomType 房间类型（会议模式，直播模式）
  * @param pin 加入房间的pin码
  **/
  void setRTCCallInfo(RTCCallType calltype, int64_t roomId, int64_t initiator, RTCRoomType roomType, const std::string& pin);

  /**
  * @brief 设置接通消息信息
  * @param callId 通话id
  **/
  void setRTCPickupInfo(const std::string& callId);

  /**
  * @brief 设置挂断消息信息
  * @param callId 通话id
  **/
  void setRTCHangupInfo(const std::string& callId);

  /**
  * @brief 获得RTC相关操作类型信息（呼叫、接通、挂断等）。
  * @return int
  **/
  std::string getRTCAction();

  /**
  * @brief 获得RTC相关通话类型（音频通话、视频通话类型）。
  * @return RTCCallType
  **/
  RTCCallType getRTCCallType();

  /**
  * @brief 获得RTC相关房间id信息。
  * @return int64_t
  **/
  int64_t getRTCRoomId();

  /**
  * @brief 获得RTC相关发起者id信息。
  * @return int64_t
  **/
  int64_t getRTCInitiator();

  /**
  * @brief 获得RTC相关callId信息。
  * @return std::string
  **/
  std::string getRTCCallId();

  /**
  * @brief 获得RTC相关房间类型信息。
  * @return RTCRoomType
  **/
  RTCRoomType getRTCRoomType();

  /**
  * @brief 获得RTC相关pin码信息。
  * @return std::string
  **/
  std::string getRTCPin();

  /**
   * @brief 序列化操作
   * @return std::string
   **/
  std::string serialize() const;

  static BMXMessageConfigPtr createMessageConfig(bool mentionAll);

  friend std::string encodeBMXMessageConfig(BMXMessageConfigPtr);
  friend BMXMessageConfigPtr decodeBMXMessageConfig(const std::string& config);

private:

  BMXMessageConfig() : mMentionAll(false), mIsSilence(false), mBadgeType(BMXMessageConfig::BadgeCountType::Change), mBadgeCount(0), mUsername("") {}

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
  bool mIsSilence;
  BadgeCountType mBadgeType;
  int mBadgeCount;
  std::string mUsername;
  std::string mRTCAction;
  RTCCallType mRTCCallType;
  int64_t mRTCRoomId;
  int64_t mRTCInitiator;
  std::string mRTCCallId;
  RTCRoomType mRTCRoomType;
  std::string mRTCPin;
};

std::string encodeBMXMessageConfig(BMXMessageConfigPtr);
BMXMessageConfigPtr decodeBMXMessageConfig(const std::string& config);

}

#endif /* bmx_message_config_h */
