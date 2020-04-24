//-------------------------------------------------------------------------------------------------
// File    : bmx_chat_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_chat_service_h
#define bmx_chat_service_h

#include "bmx_message.h"
#include "bmx_conversation.h"
#include "bmx_error.h"
#include "bmx_result_page.h"

namespace floo {

class BMXChatServiceListener;

class EXPORT_API BMXChatService {
public:

  /**
   * 缩略图生成策略,
   **/
  enum class ThumbnailStrategy {
    ThirdpartyServerCreate = 1,     // 第三方服务器生成
    LocalServerCreate,              // 本地服务器生成
  };

  virtual ~BMXChatService() {}

  /**
   发送消息，消息状态变化会通过listener通知
   **/
  virtual void sendMessage(BMXMessagePtr msg) = 0;

  /**
   重新发送消息，消息状态变化会通过listener通知
   **/
  virtual void resendMessage(BMXMessagePtr msg) = 0;

  /**
   撤回消息，消息状态变化会通过listener通知
   **/
  virtual void recallMessage(BMXMessagePtr msg) = 0;

  /**
   合并转发消息
   **/
  virtual BMXErrorCode forwardMessage(const BMXMessageList &list, BMXConversationPtr to, BMXMessagePtr &newMsg) = 0;

  /**
   简单转发消息，用户应当通过BMXMessage::createForwardMessage()先创建转发消息
   **/
  virtual void forwardMessage(BMXMessagePtr msg) = 0;

  /**
   * 发送已读回执
   **/
  virtual void ackMessage(BMXMessagePtr msg) = 0;

  /**
   * 标记此消息为未读，该消息同步到当前用户的所有设备
   **/
  virtual void readCancel(BMXMessagePtr msg) = 0;

  /**
   * 标记此消息及之前全部消息为已读，该消息同步到当前用户的所有设备
   **/
  virtual void readAllMessage(BMXMessagePtr msg) = 0;

  /**
   * 删除此消息，该消息同步到当前用户的其它设备
   **/
  virtual void removeMessage(BMXMessagePtr msg, bool synchronize = true) = 0;

  /**
   * 下载缩略图，下载状态变化和进度通过listener通知
   * 缩略图生成策略，1 - 第三方服务器生成， 2 - 本地服务器生成，默认值是 1。
   **/
  virtual void downloadThumbnail(BMXMessagePtr msg, ThumbnailStrategy strategy = ThumbnailStrategy::ThirdpartyServerCreate) = 0;

  /**
   * 下载附件，下载状态变化和进度通过listener通知
   **/
  virtual void downloadAttachment(BMXMessagePtr msg) = 0;

  /**
   * 插入消息
   **/
  virtual BMXErrorCode insertMessages(const BMXMessageList& list) = 0;

  /**
   * 读取一条消息
   **/
  virtual BMXMessagePtr getMessage(int64_t msgId) = 0;

  /**
   * 删除会话
   **/
  virtual BMXErrorCode deleteConversation(int64_t conversationId) = 0;

  /**
   * 打开一个会话
   **/
  virtual BMXConversationPtr openConversation(int64_t conversationId, BMXConversation::Type type, bool createIfNotExist = true) = 0;

  /**
   * 获取附件保存路径
   **/
  virtual std::string attachmentDir() = 0;

  /**
   * 获取会话的附件保存路径
   **/
  virtual std::string attachmentDirForConversation(int64_t conversationId) = 0;

  /**
   * 获取所有会话
   **/
  virtual BMXConversationList getAllConversations() = 0;

  /**
   * 拉取历史消息
   **/
  virtual BMXErrorCode retrieveHistoryMessages(BMXConversationPtr conversation, int64_t refMsgId, size_t size, BMXMessageList& result) = 0;

  /**
   * 搜索消息
   **/
  virtual BMXErrorCode searchMessages(const std::string& keywords, int64_t refTime, size_t size, std::vector<BMXMessageList>& result, BMXConversation::Direction = BMXConversation::Direction::Up) = 0;

  /**
   * 添加聊天监听者
   **/
  virtual void addChatListener(BMXChatServiceListener* listener) = 0;

  /**
   * 移除聊天监听者
   **/
  virtual void removeChatListener(BMXChatServiceListener* listener) = 0;

protected:
  BMXChatService() {}
  void updateMessageId(BMXMessagePtr msg, int64_t newId);
};

}

#endif /* bmx_chat_service_h */
