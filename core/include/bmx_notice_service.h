//-------------------------------------------------------------------------------------------------
// File    : bmx_notice_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx notice service define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_notice_service_h
#define bmx_notice_service_h

#include "bmx_defines.h"

namespace floo {

class BMXNoticeServiceListener;

class EXPORT_API BMXNoticeService {
public:
  virtual ~BMXNoticeService() {}

  /**
   * 添加通知监听
   **/
  virtual void addNoticeListener(BMXNoticeServiceListener* listener) = 0;

  /**
   * 移除通知监听
   **/
  virtual void removeNoticeListener(BMXNoticeServiceListener* listener) = 0;
  
protected:
  BMXNoticeService() {}
};

}

#endif /* bmx_notice_service_h */
