//
//  ----------------------------------------------------------------------
//   File    : BMXGroupServiceProtocol.h
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

@class BMXGroupAnnounment;

@protocol BMXGroupServiceProtocol <NSObject>

/**
 * 多设备同步创建群组
 **/
- (void)groupDidCreated:(BMXGroup *)group;

/**
 退出了某群
 */
- (void)groupLeft:(BMXGroup *)group reason:(NSString *)reason;

/**
 * 收到入群邀请
 **/
- (void)groupDidRecieveInviter:(NSInteger)inviter groupId:(NSInteger)groupId message:(NSString *)message;

/**
 * 入群邀请被接受
 **/
- (void)groupInvitationAccepted:(BMXGroup *)group inviteeId:(NSInteger)inviteeId;

/**
 * 入群申请被拒绝
 **/
- (void)groupInvitationDeclined:(BMXGroup *)group
                      inviteeId:(NSInteger)inviteeId
                         reason:(NSString *)reason;
/**
 * 收到入群申请
 **/
- (void)groupDidRecieveApplied:(BMXGroup *)group
                   applicantId:(NSInteger)applicantId
                       message:(NSString *)message;

/**
 * 入群申请被接受
 **/
- (void)groupApplicationAccepted:(BMXGroup *)group
                        approver:(NSInteger)approver;

/**
 * 入群申请被拒绝
 **/
- (void)groupApplicationDeclined:(BMXGroup *)group
                        approver:(NSInteger)approver
                          reason:(NSString *)reason;

/**
 * 群成员被禁言
 **/
- (void)groupMembersMutedGroup:(BMXGroup *)group
                  members:(NSArray<NSNumber *> *)members
                      duration:(NSInteger)duration;

/**
 * 群成员被解除禁言
 **/
- (void)groupMembersUnMutedGroup:(BMXGroup *)group
                         Unmuted:(NSArray<NSNumber *> *)members;

/**
 * 加入新成员
 **/
- (void)groupMemberJoined:(BMXGroup *)group
                 memberId:(NSInteger)memberId
                  inviter:(NSInteger)inviter;

/**
 * 群成员退出
 **/
- (void)groupMemberLeft:(BMXGroup *)group
               memberId:(NSInteger)memberId
                reason:(NSString *)reason;

/**
 * 添加了新管理员
 **/
- (void)groupAdminsAddedGroup:(BMXGroup *)group
                      members:(NSArray<NSNumber *> *)members;

/**
 * 移除了管理员
 **/
- (void)groupAdminsRemovedFromGroup:(BMXGroup *)group
                            members:(NSArray<NSNumber *> *)members
                             reason:(NSString *)reason;

/**
 * 成为群主
 **/
- (void)groupOwnerAssigned:(BMXGroup *)group;

/**
 * 群组信息变更
 **/
- (void)groupInfoDidUpdate:(BMXGroup *)group
            updateInfoType:(BMXGroupUpdateInfoType)type;

/**
 * 群成员更改群内昵称
 **/
- (void)groupMemberDidChangeNickName:(BMXGroup *)group
                       memberId:(long long)memberId
                      nickName:(NSString *)nickName;

/**
 * 收到群公告
 **/
- (void)groupAnnouncementUpdate:(BMXGroup *)group
                   announcement:(BMXGroupAnnounment *)announcement;

/**
 * 收到共享文件
 **/
- (void)groupSharedFileUploaded:(BMXGroup *)group
                  sharedFile:(BMXGroupSharedFile *)sharedFile;

/**
 * 删除了共享文件
 **/
- (void)groupSharedFileDeleted:(BMXGroup *)group
                    sharedFile:(BMXGroupSharedFile *)sharedFile;


/**
 * 共享文件更新文件名
 **/
- (void)groupShareFileDidUpdated:(BMXGroup *)group
                      sharedFile:(BMXGroupSharedFile *)sharedFile;



@end
