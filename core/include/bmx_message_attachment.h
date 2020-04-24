//-------------------------------------------------------------------------------------------------
// File    : bmx_message_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_message_attachment_h
#define bmx_message_attachment_h

#include <string>
#include <memory>
#include "bmx_base_object.h"

namespace floo {

class EXPORT_API BMXMessageAttachment : public BMXBaseObject
{
public:

  /**
   * 附件类型
   **/
  enum class Type
  {
    Image = 1,      // 图片
    Voice,          // 语音
    Video,          // 视频片段
    File,           // 文件
    Location,       // 位置
    Command,        // 命令消息
    Forward,        // 转发消息
  };

  /**
   * 附件下载状态
   **/
  enum class DownloadStatus
  {
    Downloaing,     // 下载中
    Successed,      // 下载成功
    Failed,         // 下载失败
    NotStart        // 下载尚未开始
  };

  /**
   * 图片/视频大小
   **/
  struct Size
  {
    Size(double width = 0.0, double height = 0.0) : mWidth(width), mHeight(height) {}
    double mWidth;
    double mHeight;
  };

  /**
   * 构造函数
   **/
  BMXMessageAttachment() {}

  /**
   * 析构函数
   **/
  virtual ~BMXMessageAttachment() {}

  /**
   * 附件类型
   **/
  virtual Type type() const = 0;

  /**
   * 复制附件
   **/
  virtual std::shared_ptr<BMXMessageAttachment> clone() const = 0;

private:
  BMXMessageAttachment& operator=(const BMXMessageAttachment&);
};

typedef std::shared_ptr<BMXMessageAttachment> BMXMessageAttachmentPtr;

}

#endif /* bmx_message_attachment_h */
