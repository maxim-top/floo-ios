// ----------------------------------------------------------------------
// File    : BMXStringUtil.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/12/1 by hyt <yutong@bmxlabs.com>
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
#include <string>


@interface BMXStringUtil : NSObject

/*
 *  NSString类型转换为string类型
 */
+ (std::string)toStdString:(NSString *)aStr;

/*
 *  string类型转换为NSString类型
 */
+ (NSString *)stdToNSString:(const std::string&)aStr;



+ (NSString *)cacheFilePath;





@end

