// ----------------------------------------------------------------------
// File    : BMXDefines.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/25 by hyt <yutong@bmxlabs.com>
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

typedef NS_ENUM(NSUInteger, BMXNetworkType) {
    BMXNetworkTypeMobile,
    BMXNetworkTypeWifi,
    BMXNetworkTypeCable,
    BMXNetworkTypeNone
};

typedef NS_ENUM(NSUInteger, BMXConnectStatus) {
    BMXConnectStatusDisconnected,
    BMXConnectStatusConnected,
};

typedef NS_ENUM(NSUInteger, BMXSignInStatus) {
    BMXSignInStatusSignOut,
    BMXSignInStatusSignIn,
};

typedef NS_ENUM(NSUInteger, BMXLogLevel) {
    BMXLogLevelError,
    BMXLogLevelWarning,
    BMXLogLevelDebug,
};


