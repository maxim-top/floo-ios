// ----------------------------------------------------------------------
// File    : BMXError.m
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



#import "BMXError.h"
#import "BMXErrorCode.h"
#import "BMXError+Private.h"
#include "bmx_error.h"
#import "BMXStringUtil.h"

@interface BMXError ()


@end

@implementation BMXError : NSObject

+ (instancetype)errorCode:(BMXErrorCode)code {
    BMXError *error = [[BMXError alloc] initWith:code];
    return error;
}

- (instancetype)initWith:(BMXErrorCode)code {
    if (self = [super init]) {
        _errorCode = code;
    }
    return self;
}

- (NSString *)errorMessage {
    std::string s =floo::getErrorMessage((floo::BMXErrorCode)_errorCode);
    return [BMXStringUtil stdToNSString:s];

}

@end
//
@implementation BMXError (Private)

+ (instancetype)bmx_ErrorWith:(floo::BMXErrorCode)errorCode {
    if (errorCode == floo::BMXErrorCode::NoError) {
        return nil;
    }
    return [BMXError errorCode:[self translateErrorCode:errorCode]];
}

//- (instancetype)initWithcode:()

+ (BMXErrorCode)translateErrorCode:(floo::BMXErrorCode)from {
    return (BMXErrorCode)from;
}


@end
