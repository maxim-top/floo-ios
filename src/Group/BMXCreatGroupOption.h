//
//  ----------------------------------------------------------------------
//   File    :  BMXCreatGroupOption.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/7 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>
#import "BMXGroup.h"

@class BMXGroupMember;

@interface BMXCreatGroupOption : NSObject


/**
 群名称
 */
@property (nonatomic,copy) NSString *name;


/**
 群描述
 */
@property (nonatomic,copy) NSString *groupDescription;

/**
 是否聊天室
 */
@property (nonatomic, assign) BOOL isChatroom;

/**
 建群时成员收到的邀请信息
 */
@property (nonatomic,copy) NSString *message;


/**
 群头像本地路径
 */
@property (nonatomic,copy) NSString *avatarPath;

/**
 群公告
 */
@property (nonatomic,copy) NSString *announcement;

/**
 建群时添加的成员
 */
@property (nonatomic,strong) NSArray *members;


/**
 群扩展信息
 */
@property (nonatomic,copy) NSString *extion;


/**
 创建群实体

 @param name 必填
 @param groupDescription 非必填
 @return BMXCreatGroupOption
 */
- (instancetype)initWithGroupName:(NSString *)name
                 groupDescription:(NSString *)groupDescription
                         isPublic:(BOOL)isPublic;

@end

