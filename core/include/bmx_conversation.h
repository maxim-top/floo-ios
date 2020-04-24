//-------------------------------------------------------------------------------------------------
// File    : bmx_conversation.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx conversation define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_conversation_h__
#define bmx_conversation_h__

#include "bmx_base_object.h"
#include "bmx_message.h"
#include "bmx_result_page.h"
#include "bmx_error.h"

namespace floo {

typedef BMXResultPage<std::shared_ptr<BMXMessage>> BMXMessagePage;
class BMXConversation : public BMXBaseObject {
public:
  /**
   * 会话类型
   **/
  enum class Type {
    Single,     // 单聊
    Group,      // 群聊
  };

  enum class Direction {
    Up,       // 取更旧消息
    Down      // 取更新消息
  };

  /**
   * 析构函数
   **/
  virtual ~BMXConversation() {}

  /**
   * 会话Id
   **/
  virtual int64_t conversationId() = 0;

  /**
   * 会话类型
   **/
  virtual Type type() = 0;

  /**
   * 最新消息
   **/
  virtual BMXMessagePtr lastMsg() = 0;

  /**
   * 未读消息数
   **/
  virtual int32_t unreadNumber() = 0;

  /**
   * 会话中所有消息的数量
   **/
  virtual int32_t messageCount() = 0;

  /**
   * 扩展信息
   **/
  virtual const JSON& extension() = 0;

  /**
   * 设置扩展信息
   **/
  virtual BMXErrorCode setExtension(const std::string& ext) = 0;

  /**
   * 编辑消息
   **/
  virtual const std::string& editMessage() = 0;

  /**
   * 设置编辑消息
   **/
  virtual BMXErrorCode setEditMessage(const std::string& editMessage) = 0;

  /**
   * 设置消息播放状态（只对语音/视频消息有效）
   **/
  virtual BMXErrorCode setMessagePlayedStatus(BMXMessagePtr msg, bool status) = 0;

  /**
   * 设置消息未读状态，更新未读消息数
   **/
  virtual BMXErrorCode setMessageReadStatus(BMXMessagePtr msg, bool status) = 0;

  /**
   * 把所有消息设置为已读，更新未读消息数
   **/
  virtual BMXErrorCode setAllMessagesRead() = 0;

  /**
   * 插入一条消息
   **/
  virtual BMXErrorCode insertMessage(BMXMessagePtr msg) = 0;

  /**
   * 读取一条消息
   **/
  virtual BMXMessagePtr loadMessage(int64_t msgId) = 0;

  /**
   * 删除会话中的所有消息
   **/
  virtual BMXErrorCode removeAllMessages() = 0;

  /**
   * 加载消息，如果不指定则从最新消息开始
   **/
  virtual BMXErrorCode loadMessages(int64_t refMsgId, size_t size, BMXMessageList& result, Direction = Direction::Up) = 0;

  /**
   * 搜索消息，如果不指定则从最新消息开始
   **/
  virtual BMXErrorCode searchMessages(const std::string& keywords, int64_t refTime, size_t size, BMXMessageList& result, Direction = Direction::Up) = 0;

  /**
   * 按照类型搜索消息，如果不指定则从最新消息开始
   **/
  virtual BMXErrorCode searchMessages(BMXMessage::ContentType type, int64_t refTime, size_t size, BMXMessageList& result, Direction = Direction::Up) = 0;

protected:
  BMXConversation() {}

private:
  BMXConversation(const BMXConversation&);
  BMXConversation& operator=(const BMXConversation&);
};

typedef std::shared_ptr<BMXConversation> BMXConversationPtr;
typedef std::vector<BMXConversationPtr> BMXConversationList;
}

#endif /* bmx_conversation_h__ */
