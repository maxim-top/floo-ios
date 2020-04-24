//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupMember.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/6 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

@interface BMXGroupMember : NSObject

@property (nonatomic, readonly) NSInteger uid;
@property (nonatomic, copy, readonly) NSString *groupNickname;
@property (nonatomic, readonly) long long createTime;

@end
