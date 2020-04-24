//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupManager.h
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
#import "BMXError.h"
#import "BMXGroup.h"
#import "BMXCreatGroupOption.h"
#import "BMXGroupInvitation.h"

@class BMXGroupSharedFile;
@class GroupServiceListener;
@class BMXGroupBannedMember;


@protocol BMXGroupManager <NSObject>

@required

- (void)addDelegate:(id<BMXGroupServiceProtocol>)aDelegate;

- (void)addDelegate:(id<BMXGroupServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id<BMXGroupServiceProtocol>)aDelegate;

@optional

/**
 获取群组列表

 @param forceRefresh 如果设置了forceRefresh则从服务器拉取
 @param aCompletionBlock GroupList, Error
 */
- (void)getGroupListForceRefresh:(BOOL)forceRefresh
                      completion:(void(^)(NSArray *groupList,
                                          BMXError *error))aCompletionBlock;


/**
 获取群信息

 @param groupId  群id
 @param forceRefresh 如果设置了forceRefresh则从服务器拉取
 @param aCompletionBlock 群
 */
- (void)getGroupInfoByGroupId:(long long)groupId
                 forceRefresh:(BOOL)forceRefresh
                   completion:(void(^)(BMXGroup *group,
                                       BMXError *error))aCompletionBlock;

/**
 * 获取传入群组id的群组信息列表，如果设置了forceRefresh则从服务器拉取
 **/
- (void)getGroupInfoByGroupIdArray:(NSArray<NSNumber *> *)groupIdArray
                      forceRefresh:(BOOL)forceRefresh
                        completion:(void (^)(NSArray *aGroups, BMXError *aError))aCompletionBlock;

/**
 通过群名称查询本地群信息，从本地数据库中通过群名称查询获取群组

 @param name 查询的群名称关键字
 @param aCompletionBlock  搜索结果返回的群列表信息,BMXErrorCode
 */
- (void)getGroupByName:(NSString *)name
            completion:(void(^)(NSArray *groupList,
                                BMXError *error))aCompletionBlock;

/**
 创建群

 @param option BMXCreatGroupOption
 @param aCompletionBlock Group info ,Error
 */
- (void)creatGroupWithCreateGroupOption:(BMXCreatGroupOption *)option
                             completion:(void(^)(BMXGroup *group,
                                                 BMXError *error))aCompletionBlock;

/**
 销毁群(群主权限)
 
 @param group BMXGroup
 @param aCompletionBlock Error
 */
- (void)destroyGroup:(BMXGroup *)group
          completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 加入一个群，根据群设置可能需要管理员批准

 @param group BMXGroup
 @param message 申请信息
 @param aCompletionBlock Error
 */
- (void)joinGroup:(BMXGroup *)group
          message:(NSString *)message
       completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 退出群

 @param group BMXGroup
 @param aCompletionBlock Error
 */
- (void)leaveGroup:(BMXGroup *)group
        completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 获取群详情，从服务端拉取最新信息

 @param group BMXGroup
 @param aCompletionBlock  BMXGroup,BMXError
 */
- (void)loadGroupInfo:(BMXGroup *)group
          completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock;


/**
 * 批量获取群组成员昵称
 **/
- (void)getMembersNickName:(BMXGroup *)group
              memberIdlist:(NSArray<NSNumber *> *)memberIdlist
                completion:(void (^)(NSArray *aGroupMembers, BMXError *aError))aCompletionBlock;



/**
 分页获取群组邀请列表

 @param cursor string
 @param pageSize int
 @param aCompletionBlock NSArray<BMXGroupInvitation *> *invitationList,
 */
- (void)getInvitationListByCursor:(NSString *)cursor
                         pageSize:(int)pageSize
               completion:(void(^)(NSArray *invitationList,
                                   NSString *cursor,
                                   long long offset,
                                   BMXError *error))aCompletionBlock;



/**
 * 分页获取群组申请列表
 **/
- (void)getApplicationListByCursor:(NSString *)cursor
                             pageSize:(int)pageSize
                           completion:(void(^)(NSArray *applicationList,
                                               NSString *cursor,
                                               long long offset,
                                               BMXError *error))aCompletionBlock;

/**
 分页获取群成员列表

 @param group BMXGroup
 @param cursor String
 @param pageSize int
 @param aCompletionBlock NSArray<BMXGroupMember *> *memberList,
 */
- (void)getMemberList:(BMXGroup *)group
               cursor:(NSString *)cursor
             pageSize:(int)pageSize
           completion:(void(^)(NSArray *memberList,
                               NSString *cursor,
                               long long offset,
                               BMXError *error))aCompletionBlock;



/**
 获取群成员列表，

 @param group BMXGroup
 @param forceRefresh 如果设置了forceRefresh则从服务器拉取，最多拉取1000人
 @param aCompletionBlock List:BMXGroupMember ,BMXError
 */
- (void)getMembers:(BMXGroup *)group
      forceRefresh:(BOOL)forceRefresh
        completion:(void(^)(NSArray<BMXGroupMember *> *groupList,
                            BMXError *error))aCompletionBlock;

/**
  添加群成员

 @param group BMXGroup
 @param memberIdlist  id数组
 @param message 添加信息
 @param aCompletionBlock BMXError
 */
- (void)addMembersToGroup:(BMXGroup *)group
               memberIdlist:(NSArray<NSNumber *> *)memberIdlist
                  message:(NSString *)message
               completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 删除群成员

 @param group BMXGroup
 @param memberList memberlist
 @param reason reason
 @param aCompletionBlock  BMXError
 */
- (void)removeMembersWithGroup:(BMXGroup *)group
                    memberlist:(NSArray<NSNumber *> *)memberList
                        reason:(NSString *)reason
                    completion:(void(^)(BMXError *error))aCompletionBlock;


/**
  添加管理员

 @param group BMXGroup
 @param admins Array：id
 @param message String
 @param aCompletionBlock BMXError
 */
- (void)addAdmins:(BMXGroup *)group
           admins:(NSArray<NSNumber *> *)admins
          message:(NSString *)message
       completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 删除管理员

 @param group BMXGroup
 @param admins Array：id
 @param reason String
 @param aCompletionBlock BMXError
 */
- (void)removeAdmins:(BMXGroup *)group
              admins:(NSArray<NSNumber *> *)admins
              reason:(NSString *)reason
          completion:(void(^)(BMXError *error))aCompletionBlock;


/**
  获取Admins列表，如果设置了forceRefresh则从服务器拉取
 */
- (void)getAdmins:(BMXGroup *)group
     forceRefresh:(BOOL)forceRefresh
       completion:(void(^)(NSArray<BMXGroupMember *> *,BMXError *error))aCompletionBlock;

/**
 * 添加黑名单
 **/
- (void)blockMembers:(BMXGroup *)group
             members:(NSArray <NSNumber *>*)members
          completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 从黑名单删除
 **/
- (void)unblockMember:(BMXGroup *)group
              members:(NSArray<NSNumber *>*)members
           completion:(void(^)(BMXError *error))aCompletionBlock;

/**
  分页获取黑名单

 @param cursor string
 @param pageSize int
 @param aCompletionBlock NSArray<BMXGroupMember *> *memberList,
 */
- (void)getBlockList:(BMXGroup *)group
                    cursor:(NSString *)cursor
                 pageSize:(int)pageSize
               completion:(void(^)(NSArray *memberList,
                                   NSString *cursor,
                                   long long offset,
                                   BMXError *error))aCompletionBlock;


/**
 * 获取黑名单
 **/
- (void)getBlockListByGroup:(BMXGroup *)group
        forceRefresh:(BOOL)forceRefresh
          completion:(void(^)(NSArray<BMXGroupMember *> *,BMXError *error))aCompletionBlock;

/**
 * 禁言
 **/
- (void)banMembers:(NSArray <NSNumber *>*)members
              group:(BMXGroup *)group
             reason:(NSString *)reason
           duration:(long long)duration
         completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 解除禁言
 **/
- (void)unbanMembersByGroup:(BMXGroup *)group
                     members:(NSArray <NSNumber *>*)members
                      reason:(NSString *)reason
                  completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 分页获取禁言列表

 @param cursor string
 @param pageSize int
 @param aCompletionBlock NSArray<BMXGroupMember *> *memberList
 */
- (void)getbannedMemberListGroup:(BMXGroup *)group
                        cursor:(NSString *)cursor
                      pageSize:(int)pageSize
                    completion:(void(^)(NSArray *memberList,
                                        NSString *cursor,
                                        long long offset,
                                        BMXError *error))aCompletionBlock;



/**
 * 获取禁言列表
 **/
- (void)getBannedMembersByGroup:(BMXGroup *)group
                    completion:(void(^)(NSArray<BMXGroupBannedMember *> *bannedMemberList,
                                        BMXError *error))aCompletionBlock;
/**
 * 屏蔽群消息
 **/
- (void)muteMessageByGroup:(BMXGroup *)group
               msgMuteMode:(BMXGroupMsgMuteMode)msgMuteMode
                completion:(void(^)(BMXError *error))aCompletionBlock;



/**
 * 接受入群申请
 **/
- (void)acceptApplicationByGroup:(BMXGroup *)group
                     applicantId:(long long)applicantId
                      completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 拒绝入群申请
 **/
- (void)declineApplicationByGroup:(BMXGroup *)group
                      applicantId:(long long)applicantId
                       completion:(void(^)(BMXError *error))aCompletionBlock;
/**
 * 接受入群邀请
 **/
- (void)acceptInvitationByGroup:(BMXGroup *)group
                        inviter:(long long)inviter
                     completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 * 拒绝入群邀请
 **/
- (void)declineInvitationByGroup:(BMXGroup *)group
                         inviter:(long long)inviter
                      completion:(void(^)(BMXError *error))aCompletionBlock;



/**
 * 转移群主
 **/
- (void)transferOwnerByGroup:(BMXGroup *)group
                  newOwnerId:(long long)newOwnerId
                  completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 * 添加群共享文件
 **/
- (void)uploadSharedFileToGroup:(BMXGroup *)group
                    filePathStr:(NSString *)filePathStr
                    displayName:(NSString *)displayName
                     extionName:(NSString *)extionName
                       progress:(void(^)(int progress, BMXError *error))aProgress
                     completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion;

/**
 * 移除群共享文件
 **/
- (void)removeSharedFileFromGroup:(BMXGroup *)group
                             file:(BMXGroupSharedFile *)file
                       completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 下载群共享文件
 **/
- (void)downloadSharedFileFromGroup:(BMXGroup *)group
                          shareFile:(BMXGroupSharedFile *)shareFile
                           progress:(void(^)(int progress, BMXError *error))aProgress
                         completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion;

/**
 * 获取群共享文件列表
 **/
- (void)getSharedFilesListByGroup:(BMXGroup *)group
                     forceRefresh:(BOOL)forceRefresh
                       completion:(void(^)(NSArray<BMXGroupSharedFile *> *sharedFileList, BMXError *error))aCompletionBlock;


/**
 * 获取最新的群公告
 **/
- (void)getLatestAnnouncementWithGroup:(BMXGroup *)group
                          forceRefresh:(BOOL)forceRefresh
                            completion:(void(^)(BMXGroupAnnounment *groupAnnounment, BMXError *error))aCompletionBlock;

/**
 * 获取群公告列表
 **/
- (void)getAnnouncementListWithGroup:(BMXGroup *)group
                        forceRefresh:(BOOL)forceRefresh
                          completion:(void(^)(NSArray *annoucmentArray, BMXError *error))aCompletionBlock;

/**
 * 设置群公告
 **/
- (void)editGroupAnnouncement:(BMXGroup *)group
                        title:(NSString *)title
                      content:(NSString *)content
                   completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock;


/**
 * 删除群公告
 **/
- (void)deleteAnnouncementWithGroup:(BMXGroup *)group
                     announcementId:(long long)announcementId
                         completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock;

/**
 * 设置群名称
 **/
- (void)setGroupName:(BMXGroup *)group
                name:(NSString *)name
          completion:(void(^)(BMXGroup *group,BMXError *error))aCompletionBlock;

/**
 * 设置群描述信息
 **/
- (void)setGroupDescription:(BMXGroup *)group
           description:(NSString *)description
            completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 设置群扩展信息
 **/
- (void)setGroupExtensionWithGroup:(BMXGroup *)group
                         extension:(NSString *)extension
                        completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 设置在群里的昵称
 **/
- (void)setMyNicknameWithGroup:(BMXGroup *)group
                      nickName:(NSString *)nickName
                    completion:(void(^)(BMXError *error))aCompletionBlock ;

/**
 * 设置群消息通知模式
 **/
- (void)setMsgPushModeWithGroup:(BMXGroup *)group
                          mode:(BMXGroupMsgPushMode)mode
                    completion:(void(^)(BMXError *error))aCompletionBlock ;

/**
 * 设置入群审批模式
 **/
- (void)setJoinAuthModeWithGroup:(BMXGroup *)group
                    joinAuthMode:(BMXGroupJoinAuthMode)mode
                      completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 设置邀请模式
 **/
- (void)setInviteModeWithGroup:(BMXGroup *)group
                          mode:(BMXGroupInviteMode)inviteMode
                    completion:(void(^)(BMXError *error))aCompletionBlock;


/**
 设置是否允许群成员设置群信息

 @param group 进行操作的群组
 @param enable 是否允许操作
 @param aCompletionBlock  BMXError
 */
- (void)setAllowMemberModifyWithGroup:(BMXGroup *)group
                                enable:(BOOL)enable
                           completion:(void(^)(BMXError *error))aCompletionBlock;

/**
设置是否开启群消息已读功能

 @param group 进行操作的群组
 @param enable 是否开启
 @param aCompletionBlock BMXError
 */
- (void)setEnableReadAckWithGroup:(BMXGroup *)group
                           enable:(BOOL)enable
                       completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置群成员是否开可见群历史聊天记录

 @param group 进行操作的群组
 @param enable 是否开启
 @param aCompletionBlock BMXError
 */
- (void)setHistoryVisibleWithGroup:(BMXGroup *)group
                            enable:(BOOL)enable
                        completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 设置群头像
 **/
- (void)setAvatarWithGroup:(BMXGroup *)group
                avatarData:(NSData *)avatarData
                  progress:(void(^)(int progress, BMXError *error))aProgress
                completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion;

/**
 * 下载群头像
 **/
- (void)downloadAvatarWithGroup:(BMXGroup *)group
                        progress:(void(^)(int progress, BMXError *error))aProgress
                      completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion;


/**
 * 添加群组变化监听者
 **/
- (void)addGroupListener:(id<BMXGroupServiceProtocol>)listener;

/**
 * 移除群组变化监听者
 **/
- (void)removeGroupListener:(id<BMXGroupServiceProtocol>)listener;





@end
