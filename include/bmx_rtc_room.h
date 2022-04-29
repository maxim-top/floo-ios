//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_session.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx sdk rtc session define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_room_h
#define bmx_rtc_room_h

#include <vector>
#include "bmx_base_object.h"

namespace floo {

/**
 * @brief RTC room(room 归属于某一个session，session不存在了room肯定不存在，room不存在时session可能存在)
 **/

class EXPORT_API BMXRTCRoom: public BMXBaseObject {
public:
  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCRoom() {}

  /**
  * @brief room id
  * @return int64_t
  **/
  virtual int64_t roomId() = 0;

  /**
  * @brief 设置room的secret。secret可以从IM的信令交互处获得
  **/
  virtual void setRoomSecret(const std::string& roomSecret) = 0;

  /**
  * @brief room secret
  * @return std::string
  **/
  virtual std::string roomSecret() = 0;

  /**
  * @brief 设置room的pin。pin可以从IM的信令交互处获得。
  **/
  virtual void setPin(const std::string& pin) = 0;

  /**
  * @brief room pin
  * @return std::string
  **/
  virtual std::string pin() = 0;

  /**
  * @brief room permanent 是否为永久性房间
  * @return bool
  **/
  virtual bool permanent() = 0;

  /**
  * @brief room 是否为私有
  * @return bool
  **/
  virtual bool isPrivate() = 0;

  /**
  * @brief room 描述
  * @return std::string
  **/
  virtual std::string roomDescription() = 0;

  /**
  * @brief 用户在当前的room中与当前用户唯一关联的id，在其它成员想要订阅当前用户在该room的pub流时必须使用该数字。现在不需要实现
  * @return int64_t
  **/
  virtual int64_t roomPrivateId() = 0;

protected:
  BMXRTCRoom() {}

private:
  BMXRTCRoom(const BMXRTCRoom&);
  BMXRTCRoom& operator=(const BMXRTCRoom&);
};

typedef std::shared_ptr<BMXRTCRoom> BMXRTCRoomPtr;
typedef std::vector<BMXRTCRoomPtr> BMXRTCRooms;

}

#endif
