//
//  BMXGroup.h
//  MaxIM
//
//  Created by hyt on 2018/11/24.
//  Copyright © 2018年  . All rights reserved.
//

#import <Foundation/Foundation.h>

@class BMXGroupSharedFile;
@class BMXGroupMember;
@class BMXGroupAnnounment;

/**
 * 消息通知类型
 **/
typedef enum {
    BMXGroupMsgPushModeAll = 0,       // 通知所有群消息
    BMXGroupMsgPushModeNone,      // 所有消息都不通知
    BMXGroupMsgPushModeAdminOrAt, // 只通知管理员或者被@消息
    BMXGroupMsgPushModeAdmin,     // 只通知知管理员消息
    BMXGroupMsgPushModeAt         // 只通知被@消息
} BMXGroupMsgPushMode;

/**
 * 群信息修改模式
 **/
typedef enum {
    BMXGroupModifyModeAdminOnly = 0,
    BMXGroupModifyModeOpen,
} BMXGroupModifyMode;


/**
 * 进群验证方式
 **/
typedef enum  {
    BMXGroupJoinAuthOpen = 0,
    BMXGroupJoinAuthNeedApproval,
    BMXGroupJoinAuthRejectAll,
} BMXGroupJoinAuthMode;

/**
 * 邀请入群模式
 **/
typedef enum {
    BMXGroupInviteModeAdminOnly = 0,// 只有管理员可以
    BMXGroupInviteModeOpen, // 所有群成员都可以修改

} BMXGroupInviteMode;


typedef enum {
    BMXGroupUpdateInfoTypeUnKnown = 0,        // 默认初始化值
    BMXGroupUpdateInfoTypeName,           // 修改群名称
    BMXGroupUpdateInfoTypeDescription,    // 修改群描述
    BMXGroupUpdateInfoTypeAvatar,         // 修改群头像
    BMXGroupUpdateInfoTypeOwner,          // 修改群主
    BMXGroupUpdateInfoTypeExt,            // 修改群扩展
    BMXGroupUpdateInfoTypeNickName,       // 群成员修改群名片
    BMXGroupUpdateInfoTypeModifyMode,     // 修改群信息模式
    BMXGroupUpdateInfoTypeJoinAuthMode,   // 修改进群验证方式
    BMXGroupUpdateInfoTypeInviteMode,     // 修改邀请入群模式
    BMXGroupUpdateInfoTypeMsgPushMode,          // 修改群消息推送类型
    BMXGroupUpdateInfoTypeMsgMuteMode,          // 修改是否提醒消息
    BMXGroupUpdateInfoTypeReadAckMode,          // 是否开启群消息已读功能
    BMXGroupUpdateInfoTypeHistoryVisibleMode,   // 新群成员是否可见群历史聊天记录
    
} BMXGroupUpdateInfoType;

/**
 * 群组状态
 **/
typedef enum {
    BMXGroupNormal,         // 群组状态正常
    BMXGroupDestroyed,      // 群组已销毁
} BMXGroupStatus;


typedef enum  {
    BMXGroupMsgMuteModeNone, // 不屏蔽
    BMXGroupMsgMuteModeMuteNotification, // 屏蔽本地消息通知
    BMXGroupMsgMuteModeMuteChat, // 屏蔽消息，不接收消息
} BMXGroupMsgMuteMode;

typedef enum {
    /// 群成员
    BMXGroupMemberRoleTypeMember,
    /// 群管理员
    BMXGroupMemberRoleTypeAdmin,
    /// 群主
    BMXGroupMemberRoleTypeOwner,
    /// 非群成员
    BMXGroupMemberRoleTypeNotGroupMember
} BMXGroupMemberRoleType;

typedef enum {
    /// 私有群组
    BMXGroupTypePrivate,
    /// 公开群组(现在暂时没有开放次类型群组)
    BMXGroupTypePublic,
    /// 聊天室
    BMXGroupTypeChatroom,
} BMXGroupType;

@interface BMXGroup : NSObject
/**
 * 群Id
 **/
@property (nonatomic,assign, readonly) long long groupId;


@property (nonatomic, assign, readonly) BMXGroupType groupType;

/**
 * 在群里的昵称
 **/
@property (nonatomic,copy, readonly) NSString *myNickName;

/**
 * 群名称
 **/
@property (nonatomic, copy, readonly) NSString *name;

/**
 * 群描述
 **/
@property (nonatomic, copy, readonly) NSString *groupDescription;

/**
 * 群头像
 **/
@property (nonatomic,copy, readonly) NSString *avatarUrl;

/**
 * 群头像下载后的本地路径
 **/
@property (nonatomic,copy, readonly) NSString *avatarPath;

/**
 * 群头像缩略图
 **/
@property (nonatomic,copy, readonly) NSString *avatarThumbnailUrl;

/**
 * 群头像缩略图下载后的本地路径
 **/
@property (nonatomic,copy, readonly) NSString *avatarThumbnailPath;

/**
 * 群创建时间
 **/
@property (nonatomic,readonly) long long creatTime;

/**
 * 群扩展信息
 **/
@property (nonatomic, copy, readonly) NSString *jsonextension;


@property (nonatomic, strong, readonly) BMXGroupSharedFile *shareFile;

/**
 * 群成员
 **/
@property (nonatomic, assign, readonly) NSInteger ownerId;


@property (nonatomic, strong) BMXGroupAnnounment *annountment;

/**
 * 最大人数
 **/
@property (nonatomic, assign, readonly) NSInteger capactiy;

/**
 * 群成员数量，包含Owner，admins 和members
 **/
@property (nonatomic, assign, readonly) NSInteger membersCount;

/**
 * 群管理员数量
 **/
@property (nonatomic, assign, readonly) NSInteger adminsCount;

/**
 * 群共享文件数量
 **/
@property (nonatomic, assign, readonly) NSInteger sharedFilesCount;

/**
 群消息通知类型
 */
@property (nonatomic,assign, readonly) BMXGroupMsgPushMode msgPushMode;

/**
 群信息修改模式
 */
@property (nonatomic,assign, readonly) BMXGroupModifyMode modifyMode;

/**
 入群审批模式
 */
@property (nonatomic,assign, readonly) BMXGroupJoinAuthMode joinAuthMode;

/**
 入群邀请模式
 */
@property (nonatomic,assign, readonly) BMXGroupInviteMode inviteMode;

/**
 是否开启群消息已读功能
 */
@property (nonatomic,assign) BOOL enableReadAck;

/**
 是否可以加载显示历史聊天记录
 */
@property (nonatomic,assign) BOOL historyVisible;


/**
 * 群消息屏蔽模式
 **/
@property (nonatomic, assign) BMXGroupMsgMuteMode msgMuteMode;

/**
 * 当前群组的状态。（Normal 正常， Destroyed 以销毁）
 **/
@property (nonatomic,assign) BMXGroupStatus groupStatus;

@property (nonatomic,assign,readonly) BOOL isMember;

@property (nonatomic,assign) BMXGroupMemberRoleType roleType;

@end


