//
// ----------------------------------------------------------------------
// File    : BMXDefinesTransform.h
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

#import <Foundation/Foundation.h>
#include "bmx_defines.h"
#import "BMXDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXDefinesTransform : NSObject

+ (floo::BMXNetworkType)oc_transformBMXNetworkType:(BMXNetworkType)type;

+ (floo::BMXConnectStatus)oc_transformBMXConnectStatus:(BMXConnectStatus)status;

+ (floo::BMXSignInStatus)oc_transformBMXSignInStatus:(BMXSignInStatus)status;

+ (floo::BMXLogLevel)oc_transformBMXLogLevel:(BMXLogLevel)logLevel;



+ (BMXLogLevel)transformBMXLogLevel:(floo::BMXLogLevel)logLevel;

+ (BMXNetworkType)transformBMXNetworkType:(floo::BMXNetworkType)type;

+ (BMXConnectStatus)transformBMXConnectStatus:(floo::BMXConnectStatus)status;

+ (BMXSignInStatus)transformBMXSignInStatus:(floo::BMXSignInStatus)status;







@end

NS_ASSUME_NONNULL_END
