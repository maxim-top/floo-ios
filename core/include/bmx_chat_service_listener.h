//-------------------------------------------------------------------------------------------------
// File    : bmx_chat_service_listener.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service listener define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_chat_service_listener_h
#define bmx_chat_service_listener_h

#include "bmx_message.h"
#include "bmx_conversation.h"
#include "bmx_error.h"

namespace floo {

class EXPORT_API BMXChatServiceListener {
public:
  /**
   * 析构函数
   **/
  virtual ~BMXChatServiceListener() {}

  /**
   * 消息发送状态发生变化
   **/
  virtual void onStatusChanged(BMXMessagePtr msg, BMXErrorCode error)  {}

  /**
   * 附件上传进度发送变化
   **/
  virtual void onAttachmentUploadProgressChanged(BMXMessagePtr msg, int percent)  {}

  /**
   * 消息撤回状态发送变化
   **/
  virtual void onRecallStatusChanged(BMXMessagePtr msg, BMXErrorCode error)  {}

  /**
   * 收到消息
   **/
  virtual void onReceive(const BMXMessageList& list)  {}

  /**
   * 收到系统通知消息
   **/
  virtual void onReceiveSystemMessages(const BMXMessageList& list)  {}

  /**
   * 收到消息已读回执
   **/
  virtual void onReceiveReadAcks(const BMXMessageList& list)  {}

  /**
   * 收到消息已送达回执
   **/
  virtual void onReceiveDeliverAcks(const BMXMessageList& list)  {}

  /**
   * 收到撤回消息
   **/
  virtual void onReceiveRecallMessages(const BMXMessageList& list)  {}

  /**
   * 收到消息已读取消（多设备其他设备同步消息已读状态变为未读）
   **/
  virtual void onReceiveReadCancels(const BMXMessageList& list) {}

  /**
   * 收到消息全部已读（多设备同步某消息之前消息全部设置为已读）
   **/
  virtual void onReceiveReadAllMessages(const BMXMessageList& list) {}

  /**
   * 收到删除消息 （多设备同步删除消息）
   **/
  virtual void onReceiveDeleteMessages(const BMXMessageList& list) {}

  /**
   * 附件下载状态发生变化
   **/
  virtual void onAttachmentStatusChanged(BMXMessagePtr msg, BMXErrorCode error, int percent)  {}

  /**
   * 拉取历史消息
   **/
  virtual void onRetrieveHistoryMessages(BMXConversationPtr conversation) {}
};

}

#endif /* bmx_chat_service_listener_h */
