//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupSharedFile.h
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

@interface BMXGroupSharedFile : NSObject

@property (nonatomic) long long fileId;
@property (nonatomic) long long groupId;
@property (nonatomic) long long upLoader;
@property (nonatomic, assign) int fileSize;

@property (nonatomic, assign) long long createTime;
@property (nonatomic) long long updateTime;

@property (nonatomic,copy) NSString *url;
@property (nonatomic,copy) NSString *displayName;
@property (nonatomic,copy) NSString *type;
@property (nonatomic,copy) NSString *path;

@end
