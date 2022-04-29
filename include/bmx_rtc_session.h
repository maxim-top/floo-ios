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

#ifndef bmx_rtc_session_h
#define bmx_rtc_session_h

#include <vector>
#include "bmx_base_object.h"

namespace floo {

/**
 * @brief RTC session
 **/
class EXPORT_API BMXRTCSession: public BMXBaseObject {
public:
  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCSession() {}

  /**
  * @brief sessionId
  * @return int64_t
  **/
  virtual int64_t sessionId() = 0;

  /**
  * @brief publisher handlerId
  * @return int64_t
  **/
  virtual int64_t pubHandlerId() = 0;

  /**
  * @brief subscriber handlerId
  * @return int64_t
  **/
  virtual int64_t subHandlerId() = 0;

protected:
  BMXRTCSession() {}

private:
  BMXRTCSession(const BMXRTCSession&);
  BMXRTCSession& operator=(const BMXRTCSession&);
};

typedef std::shared_ptr<BMXRTCSession> BMXRTCSessionPtr;

}

#endif
