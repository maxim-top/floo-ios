// ----------------------------------------------------------------------
// File    : BMXUserProfile.h
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

#import <Foundation/Foundation.h>
@class BMXAuthQuestion;
@class BMXMessageSetting;


typedef enum {
    BMXAddFriendAuthModeOpen = 0,           // 无需验证，任何人可以加为好友
    BMXAddFriendAuthModeNeedApproval,   // 需要同意方可加为好友
    BMXAddFriendAuthModeAnswerQuestion, // 需要回答问题正确方可加为好友
    BMXAddFriendAuthModeRejectAll       // 拒绝所有加好友申请
} BMXAddFriendAuthMode;

typedef enum {
    BMXUserCategoryNormal = 0, // 普通用户
    BMXUserCategoryAdvanced,  // 高级用户
} BMXUserCategory;

@interface BMXUserProfile : NSObject


/**
 用户id
 */
@property (nonatomic,assign) long long userId;

/**
 用户级别
 */
@property (nonatomic,assign) BMXUserCategory userCategory;

/**
 用户名
 */
@property (nonatomic,copy) NSString *userName;

/**
 昵称
 */
@property (nonatomic,copy) NSString *nickName;

/**
 头像url
 */
@property (nonatomic,copy) NSString *avatarUrl;

/**
 头像本地路径
 */
@property (nonatomic,copy) NSString *avatarPath;

/**
 头像缩略图url
 */
@property (nonatomic,copy) NSString *avatarThumbnailUrl;

/**
 头像缩略图本地路径
 */
@property (nonatomic,copy) NSString *avatarThumbnailPath;

/**
 手机号
 */
@property (nonatomic,copy) NSString *mobilePhone;

/**
  用户邮箱
 */
@property (nonatomic,copy) NSString *email;

/**
 公开信息
 */
@property (nonatomic,copy) NSString *publicInfoJson;

/**
 私密信息
 */
@property (nonatomic,copy) NSString *privateInfoJson;

/**
 验证问题
 */
@property (nonatomic, strong) BMXAuthQuestion *authQuestion;

/**
 消息设置
 */
@property (nonatomic, strong) BMXMessageSetting *messageSetting;

/**
 好友验证模式
 */
@property (nonatomic, assign) BMXAddFriendAuthMode addFriendAuthMode;

/**
 自动接收群邀请
 */
@property (nonatomic,assign) BOOL isAutoAcceptGroupInvite;


@end

