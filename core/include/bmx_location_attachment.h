//-------------------------------------------------------------------------------------------------
// File    : bmx_location_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message location attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_location_attachment_h
#define bmx_location_attachment_h

#include "bmx_message_attachment.h"

namespace floo {

template <typename T> class Encoder;
template <typename T> class Decoder;
class EXPORT_API BMXLocationAttachment : public BMXMessageAttachment
{
public:
  /**
   * 构造函数
   **/
  BMXLocationAttachment(double latitude, double longitude, const std::string& address);

  /**
   * 析构函数
   **/
  virtual ~BMXLocationAttachment() {}

  virtual Type type() const { return Type::Location; }

  virtual BMXMessageAttachmentPtr clone() const;

  /**
   * 纬度
   **/
  double latitude() const;

  /**
   * 经度
   **/
  double longitude() const;

  /**
   * 地址
   **/
  const std::string& address() const;

private:
  double mLatitude;
  double mLongitude;
  std::string mAddress;
  friend class Encoder<BMXLocationAttachment>;
  friend class Decoder<BMXLocationAttachment>;
};

typedef std::shared_ptr<BMXLocationAttachment> BMXLocationAttachmentPtr;
}

#endif /* bmx_location_attachment_h */
