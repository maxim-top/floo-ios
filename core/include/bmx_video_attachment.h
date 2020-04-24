//-------------------------------------------------------------------------------------------------
// File    : bmx_video_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx video attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_video_attachment_h
#define bmx_video_attachment_h

#include "bmx_file_attachment.h"

namespace floo {

template <typename T> class Encoder;
template <typename T> class Decoder;
class EXPORT_API BMXVideoAttachment : public BMXFileAttachment
{
public:

  /**
   * 构造函数
   **/
  BMXVideoAttachment(const std::string& path, int duration, const Size& size, const std::string& displayName = "");

  /**
   * 构造函数
   **/
  BMXVideoAttachment(const std::string &url, int duration, const Size& size, const std::string& displayName, int64_t fileLength);

  /**
   * 析构函数
   */
  virtual ~BMXVideoAttachment() {}

  virtual Type type() const { return Type::Video; }

  virtual BMXMessageAttachmentPtr clone() const;

  /**
   * 视频大小
   **/
  const Size& size() const;

  /**
   * 视频片段时长
   **/
  int32_t duration() const;

  /**
   * 设置发送视频片段消息缩略图
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
  BMXVideoAttachment(const BMXVideoAttachment&);
  BMXVideoAttachment& operator=(const BMXVideoAttachment&);

  //Video
  Size mSize;
  int mDuration;

  //Snapshot
  std::string mThumbnailPath;
  DownloadStatus mThumbnailDownloadStatus;
  friend class Encoder<BMXVideoAttachment>;
  friend class Decoder<BMXVideoAttachment>;
};
typedef std::shared_ptr<BMXVideoAttachment> BMXVideoAttachmentPtr;
}

#endif /* bmx_video_attachment_h */
