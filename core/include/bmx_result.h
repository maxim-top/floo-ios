//-------------------------------------------------------------------------------------------------
// File    : bmx_result.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx result page define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef _bmx_result_h_
#define _bmx_result_h_

#include <memory>
#include "bmx_defines.h"
#include "bmx_error.h"

namespace floo {

template <typename V>
class EXPORT_API BMXResult {
public:
  BMXResult(BMXErrorCode error) : errorCode(error) {}
  BMXResult(std::shared_ptr<V> v) : value(v), errorCode(BMXErrorCode::NoError) {}
  virtual ~BMXResult() {}

  const std::shared_ptr<V> value;
  const BMXErrorCode errorCode;
};

}

#endif /* _bmx_result_h_ */
