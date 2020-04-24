// ----------------------------------------------------------------------
// File    : BMXError.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/26 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
// floo-ios, Copyright (C) 2018-2019   Maxim.Top
//
// ----------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "BMXErrorCode.h"

@interface BMXError : NSObject

@property (nonatomic,assign) BMXErrorCode errorCode;
@property (nonatomic,copy) NSString *errorMessage;

+ (instancetype)errorCode:(BMXErrorCode)code;

@end


