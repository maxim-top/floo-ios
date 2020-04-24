//-------------------------------------------------------------------------------------------------
// File    : bmx_voice_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx voice attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_voice_attachment_h
#define bmx_voice_attachment_h

#include "bmx_file_attachment.h"

namespace floo {

template <typename T> class Encoder;
template <typename T> class Decoder;
class EXPORT_API BMXVoiceAttachment : public BMXFileAttachment
{
public:

  /**
   * 构造函数
   **/
  BMXVoiceAttachment(const std::string& path, int duration, const std::string& displayName = "");

  /**
   * 构造函数
   **/
  BMXVoiceAttachment(const std::string &url, int duration, const std::string& displayName, int64_t fileLength);

  /**
   * 析构函数
   **/
  virtual ~BMXVoiceAttachment() {}

  virtual Type type() const { return Type::Voice; }

  virtual BMXMessageAttachmentPtr clone() const;

  /**
   * 语音时长
   **/
  int32_t duration() const;

private:
  int32_t mDuration;
  friend class Encoder<BMXVoiceAttachment>;
  friend class Decoder<BMXVoiceAttachment>;
};
typedef std::shared_ptr<BMXVoiceAttachment> BMXVoiceAttachmentPtr;
}

#endif /* bmx_voice_attachment_h */
