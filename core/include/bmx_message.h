//-------------------------------------------------------------------------------------------------
// File    : bmx_message.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __bmx_message_h__
#define __bmx_message_h__

#include <vector>
#include <memory>
#include <mutex>
#include "bmx_base_object.h"
#include "bmx_message_attachment.h"

namespace floo {
class BMXMessage;
typedef std::shared_ptr<BMXMessage> BMXMessagePtr;
typedef std::vector<BMXMessagePtr> BMXMessageList;
class BMXChatService;
class EXPORT_API BMXMessage : public BMXBaseObject
{
public:
  /**
   *  消息投递状态
   **/
  enum class DeliveryStatus {
    New,              // 新创建消息
    Delivering,       // 消息投递中
    Deliveried,       // 消息已投递
    Failed,           // 消息投递失败
    Recalled          // 消息已撤回
  };

  /**
   *  消息类型
   **/
  enum class MessageType {
    Single,     // 单聊消息
    Group,      // 群聊消息
  };

  /**
   *  消息内容类型
   **/
  enum class ContentType {
    Text,       // 文本消息
    Image,      // 图片消息
    Voice,      // 语音消息
    Video,      // 视频片段消息
    File,       // 文件消息
    Location,   // 位置消息
    Command,    // 命令消息
    Forward,    // 转发消息
  };

  /**
   *  消息投递质量
   **/
  enum class DeliveryQos {
    AtLastOnce,       // 最少投递一次
    AtMostOnce,       // 最多投递一次
    ExactlyOnce       // 仅投递一次
  };

  /**
   * 析构函数
   **/
  virtual ~BMXMessage();

  /**
   * 消息唯一ID
   **/
  int64_t msgId();

  /**
   * 消息发送方ID
   **/
  int64_t fromId();

  /**
   * 消息接收方ID
   */
  int64_t toId();

  /**
   * 消息类型
   */
  MessageType type();

  /**
   * 消息所属会话ID
   */
  int64_t conversationId();

  /**
   * 消息投递状态
   */
  DeliveryStatus deliveryStatus();

  /**
   * 设置消息投递状态
   */
  void setDeliveryStatus(DeliveryStatus);

  /**
   * 消息时间戳（服务端收到时的时间）
   */
  int64_t serverTimestamp();

  /**
   * 设置时间戳（服务端收到时的时间）
   */
  void setServerTimestamp(int64_t);

  /**
   * 本地时间戳（消息创建或者收到时的本地时间）
   */
  int64_t clientTimestamp();

  /**
   * 设置消息本地时间戳
   */
  void setClientTimestamp(int64_t);

  /**
   * 语音或者视频消息是否播放过，仅对收到的音视频消息有效
   */
  bool isPlayed();

  /**
   * 设置语音或者视频消息是否播放过，仅对收到的音视频消息有效
   */
  void setIsPlayed(bool);

  /**
   * 是否接收的消息
   */
  bool isReceiveMsg();

  /**
   * 设置是否接收的消息
   */
  void setIsReceiveMsg(bool);

  /**
   * 消息是否已读标志
   */
  bool isRead();

  /**
   * 消息是否已读标志
   */
  void setIsRead(bool);

  /**
   * 对于发送方表示是否收到了已读回执，对于接收方表示是否发送了已读回执
   */
  bool isReadAcked();

  /**
   * 设置已读回执
   */
  void setIsReadAcked(bool);

  /**
   * 对于发送方表示消息是否已投递到对方，对于接收方表示是否发送了消息已到达回执
   */
  bool isDeliveryAcked();

  /**
   * 设置投递回执
   */
  void setIsDeliveryAcked(bool);

  /**
   * 消息文本内容
   */
  const std::string& content();

  /**
   * 消息文本内容
   */
  void setContent(const std::string& content);

  /**
   * 消息内容类型，如果带附件就表示附件类型，不带附件就是文本类型
   */
  ContentType contentType();

  /**
   * 消息附件，BMXMessage拥有附件的所有权，负责释放
   */
  BMXMessageAttachmentPtr attachment();

  /**
   * 消息的推送设置
   */
  const JSON& config();

  /**
   * 设置消息推送设置
   */
  void setConfig(const JSON&);

  /**
   * 消息扩展信息
   */
  const JSON& extension();

  /**
   * 设置消息扩展信息
   */
  void setExtension(const JSON&);

  /**
   * 消息投递QOS
   */
  DeliveryQos deliveryQos();

  /**
   * 设置消息投递QOS
   */
  void setDeliveryQos(DeliveryQos qos);

public:
  /**
   * 创建文本消息
   **/
  static BMXMessagePtr createMessage(int64_t from, int64_t to, MessageType type, int64_t conversationId, const std::string& content);

  /**
   * 创建附件消息
   **/
  static BMXMessagePtr createMessage(int64_t from, int64_t to, MessageType type, int64_t conversationId, BMXMessageAttachmentPtr attachment);

  /**
   * 创建收到的消息
   **/
  static BMXMessagePtr createMessage(int64_t msgId, int64_t from, int64_t to, MessageType type, int64_t conversationId, const std::string& content, int64_t serverTimestamp);

  /**
   * 创建收到的消息
   **/
  static BMXMessagePtr createMessage(int64_t msgId, int64_t from, int64_t to, MessageType type, int64_t conversationId, BMXMessageAttachmentPtr attachment, int64_t serverTimestamp);

  /**
   * 创建转发消息
   **/
  static BMXMessagePtr createForwardMessage(BMXMessagePtr msg, int64_t from, int64_t to, MessageType type, int64_t conversationId);

private:
  BMXMessage(const BMXMessage&);
  BMXMessage(const BMXMessage&&);
  BMXMessage& operator=(const BMXMessage&);
  BMXMessage(int64_t msgId, int64_t from, int64_t to, MessageType type, int64_t conversationId, ContentType contentType);
  friend BMXChatService;

  int64_t mMsgId;
  int64_t mFromId;
  int64_t mToId;
  MessageType mType;
  int64_t mConversationId;
  DeliveryStatus mDeliveryStatus;
  int64_t mClientTimestamp;
  int64_t mServerTimestamp;
  bool mIsPlayed;
  bool mIsReceiveMsg;
  bool mIsRead;
  bool mIsReadAcked;
  bool mIsDeliveryAcked;
  std::string mContent;
  ContentType mContentType;
  BMXMessageAttachmentPtr mAttachment;
  JSON mConfig;
  JSON mExtension;
  DeliveryQos mDeliveryQos;
  std::recursive_mutex mMutex;
};

}
#endif /* __bmx_message_h__ */
