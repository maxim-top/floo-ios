//----------------------------------------------------------------------
// File    : BMXError+Private.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXError.h"
#include "bmx_error.h"


NS_ASSUME_NONNULL_BEGIN

@interface BMXError (Private)

+ (instancetype)bmx_ErrorWith:(floo::BMXErrorCode)errorCode;
@end

NS_ASSUME_NONNULL_END
