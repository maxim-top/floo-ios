//----------------------------------------------------------------------
// File    : BMXDefinesTransform.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/26 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXDefinesTransform.h"

@implementation BMXDefinesTransform


+ (floo::BMXNetworkType)oc_transformBMXNetworkType:(BMXNetworkType)type {
    if (type == BMXNetworkTypeMobile) {
        return floo::BMXNetworkType::Mobile;
    } else  if (type == BMXNetworkTypeWifi) {
        return floo::BMXNetworkType::Wifi;
    } else if (type == BMXNetworkTypeCable) {
        return floo::BMXNetworkType::Cable;
    } else {
        return floo::BMXNetworkType::None;
    }
    
}

+ (floo::BMXConnectStatus)oc_transformBMXConnectStatus:(BMXConnectStatus)status {
    if (status == BMXConnectStatusDisconnected) {
        return floo::BMXConnectStatus::Disconnected;
    } else {
        return floo::BMXConnectStatus::Connected;
    }
    
}

+ (floo::BMXSignInStatus)oc_transformBMXSignInStatus:(BMXSignInStatus)status {
    if (status == BMXSignInStatusSignOut) {
        return floo::BMXSignInStatus::SignOut;
    } else if (status == BMXSignInStatusSigningIn) {
        return floo::BMXSignInStatus::SigningIn;
    } else {
        return floo::BMXSignInStatus::SignIn;
    }
}

+ (floo::BMXLogLevel)oc_transformBMXLogLevel:(BMXLogLevel)logLevel {
    
    if (logLevel == BMXLogLevelError) {
        return floo::BMXLogLevel::Error;
    } else if (logLevel == BMXLogLevelWarning) {
        return floo::BMXLogLevel::Warning;
    } else {
        return floo::BMXLogLevel::Debug;
    }
}

+ (BMXLogLevel)transformBMXLogLevel:(floo::BMXLogLevel)logLevel {
    if (logLevel == floo::BMXLogLevel::Error) {
        return  BMXLogLevelError;
    } else if (logLevel == floo::BMXLogLevel::Warning) {
        return BMXLogLevelWarning;
    } else {
        return BMXLogLevelDebug;
    }
}

+ (BMXNetworkType)transformBMXNetworkType:(floo::BMXNetworkType)type {
    if (type == floo::BMXNetworkType::Mobile) {
        return BMXNetworkTypeMobile;
    } else if (type == floo::BMXNetworkType::Wifi) {
        return BMXNetworkTypeWifi;
    } else if (type == floo::BMXNetworkType::Cable) {
        return BMXNetworkTypeCable;
    } else {
        return BMXNetworkTypeNone;
    }
}

+ (BMXConnectStatus)transformBMXConnectStatus:(floo::BMXConnectStatus)status {
    if (status == floo::BMXConnectStatus::Disconnected) {
        return BMXConnectStatusDisconnected;
    } else {
        return BMXConnectStatusConnected;
    }
}

+ (BMXSignInStatus)transformBMXSignInStatus:(floo::BMXSignInStatus)status {
    if (status == floo::BMXSignInStatus::SignOut) {
        return BMXSignInStatusSignOut;
    } else {
        return BMXSignInStatusSignIn;
    }
}

@end
