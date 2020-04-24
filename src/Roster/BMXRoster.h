//
// ----------------------------------------------------------------------
// File    : BMXRosterItem.h
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


typedef enum {
    BMXRosterRelationFriend,       // 好友
    BMXRosterRelationDeleted,      // 被删除
    BMXRosterRelationStranger,     // 陌生人
    BMXRosterRelationonBlockd,    // 被加入黑名单
} BMXRosterRelation;


@interface BMXRoster : NSObject

/**
 好友Id
 */
@property (nonatomic,assign, readonly) long long rosterId;

/**
 好友名
 */
@property (nonatomic,copy, readonly) NSString *userName;

/**
 好友昵称
 */
@property (nonatomic,copy, readonly) NSString *nickName;

/**
 好友头像
 */
@property (nonatomic,copy, readonly) NSString *avatarUrl;

/**
 好友头像本地存储路径
 */
@property (nonatomic,copy, readonly) NSString *avatarPath;

/**
 好友头像缩略图本地存储路径
 */
@property (nonatomic,copy, readonly) NSString *avatarThumbnailPath;


/**
  扩展信息，用户设置的好友可以看到的信息，比如地址，个性签名等
 */
@property (nonatomic,copy, readonly) NSString *json_PublicInfo;

/**
 用户对好友添加的备注等信息
 */
@property (nonatomic, copy, readonly) NSString *json_alias;

/**
 用户的服务器扩展信息
 */
@property (nonatomic,copy, readonly) NSString *json_ext;

/**
 用户的本地扩展信息
 */
@property (nonatomic,copy, readonly) NSString *json_localExt;

/**
 是否提醒用户消息
 */
@property (nonatomic, assign, readonly) BOOL isMuteNotification;

/**
 联系人关系
 */
@property (nonatomic,assign, readonly) BMXRosterRelation rosterRelation;

@end

