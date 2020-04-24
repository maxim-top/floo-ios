//-------------------------------------------------------------------------------------------------
// File    : bmx_file_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message file attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_file_attachment_h
#define bmx_file_attachment_h

#include "bmx_message_attachment.h"

namespace floo {

template <typename T> class Encoder;
template <typename T> class Decoder;
class EXPORT_API BMXFileAttachment : public BMXMessageAttachment
{
public:

  /**
   * 构造函数
   **/
  BMXFileAttachment(const std::string& path, const std::string& displayName = "");

  /**
   * 构造函数
   **/
  BMXFileAttachment(const std::string &url, const std::string& displayName, int64_t fileLength);

  /**
   * 析构函数
   **/
  virtual ~BMXFileAttachment() {}

  virtual Type type() const { return Type::File; }

  virtual BMXMessageAttachmentPtr clone() const;

  /**
   * 本地路径
   **/
  const std::string& path() const;

  /**
   * 显示名
   **/
  const std::string& displayName() const;

  /**
   * 远程URL
   **/
  const std::string& url() const;

  /**
   * 文件长度
   **/
  int64_t fileLength() const;

  /**
   * 附件下载状态
   **/
  DownloadStatus downloadStatus() const;

protected:
  std::string mPath;
  std::string mDisplayName;
  std::string mUrl;
  int64_t mFileLength;
  DownloadStatus mDownloadStatus;

private:
  friend class Encoder<BMXFileAttachment>;
  friend class Decoder<BMXFileAttachment>;
};

typedef std::shared_ptr<BMXFileAttachment> BMXFileAttachmentPtr;
}

#endif /* bmx_file_attachment_h */
