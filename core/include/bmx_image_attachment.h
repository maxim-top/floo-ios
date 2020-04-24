//-------------------------------------------------------------------------------------------------
// File    : bmx_image_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message image attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_image_attachment_h
#define bmx_image_attachment_h

#include "bmx_file_attachment.h"

namespace floo {

template <typename T> class Encoder;
template <typename T> class Decoder;
class EXPORT_API BMXImageAttachment : public BMXFileAttachment
{
public:

  /**
   * 构造函数
   **/
  BMXImageAttachment(const std::string& path, const Size& size, const std::string& displayName = "");

  /**
   * 构造函数
   **/
  BMXImageAttachment(const std::string& url, const Size& size, const std::string& displayName, int64_t fileLength);

  /**
   * 析构函数
   **/
  virtual ~BMXImageAttachment() {}

  virtual Type type() const { return Type::Image; }

  virtual BMXMessageAttachmentPtr clone() const;

  /**
   * 图片大小
   **/
  const Size& size() const;

  /**
   * 设置发送图片消息缩略图
   **/
  void setThumbnail(const std::string& path);

  /**
   * 缩略图本地路径
   **/
  const std::string& thumbnailPath() const;

  /**
   * 缩略图下载状态
   **/
  DownloadStatus thumbnailDownloadStatus() const;

private:
  BMXImageAttachment(const BMXImageAttachment&);
  BMXImageAttachment& operator=(const BMXImageAttachment&);
  //Image size
  Size mSize;

  //Thumbnail
  std::string mThumbnailPath;
  DownloadStatus mThumbnailDownloadStatus;
  friend class Encoder<BMXImageAttachment>;
  friend class Decoder<BMXImageAttachment>;
};
typedef std::shared_ptr<BMXImageAttachment> BMXImageAttachmentPtr;
}

#endif /* bmx_image_attachment_h */
