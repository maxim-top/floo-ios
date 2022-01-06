//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupService.m
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
    

#import "BMXGroupService.h"
#import "GroupServiceListener.h"
#import "BMXStringUtil.h"
#import "BMXError+Private.h"
#import "BMXGroup+Private.h"
#import "BMXGroupMember.h"
#import "BMXGroupMember+Private.h"
#import "BMXGroupSharedFile+Private.h"
#import "BMXGroupSharedFile.h"
#import "BMXCreatGroupOption+Private.h"
#import "BMXGroupAnnounment.h"
#import "BMXGroupAnnounment+Private.h"
#import "BMXGroupMember.h"
#import "BMXGroupMember+Private.h"
#import "BMXGroupApplication.h"
#import "BMXGroupApplication+Private.h"
#import "BMXGroupInvitation.h"
#import "BMXGroupInvitation+Private.h"
#import "BMXGroupBannedMember+Private.h"

#import "BMXClient.h"
#include "bmx_result_page.h"

@implementation BMXGroupService

- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super initWithClientPtr:aClientPtr]) {
        groupListener = new floosdk::GroupServiceListener();
        if (groupListener) {
            floo::BMXGroupService &groupService = aClientPtr->getGroupService();
            groupService.addGroupListener(groupListener);
        }
    }
    return self;
}

/**
 获取群组列表

 @param forceRefresh 如果设置了forceRefresh则从服务器拉取
 @param aCompletionBlock GroupList, Error
 */
- (void)getGroupListForceRefresh:(BOOL)forceRefresh
                      completion:(void(^)(NSArray *groupList,
                                          BMXError *error))aCompletionBlock {
    [self handleGroupListRequst:^floo::BMXErrorCode(floo::BMXGroupList &clist) {
        return self->clientPtr->getGroupService().search(clist, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

/**
 * 获取传入群组id的群组信息列表，如果设置了forceRefresh则从服务器拉取
 **/
- (void)getGroupInfoByGroupIdArray:(NSArray<NSNumber *> *)groupIdArray
                  forceRefresh:(BOOL)forceRefresh
                   completion:(void (^)(NSArray *aGroups, BMXError *aError))aCompletionBlock {
    [self handleGroupListRequst:^floo::BMXErrorCode(floo::BMXGroupList &clist) {
        std::vector<int64_t> groupIds;
        for (NSNumber *groupid in groupIdArray) {
            groupIds.push_back((long long)[groupid longLongValue]);
        }
        return self->clientPtr->getGroupService().search(groupIds, clist, (bool)forceRefresh);
    } completion:aCompletionBlock];

}

/**
 获取群信息，从本地读取

 @param groupId groupId
 @param aCompletionBlock Group,Error
 */
- (void)getGroupInfoByGroupId:(long long)groupId
                 forceRefresh:(BOOL)forceRefresh
                   completion:(void(^)(BMXGroup *group,
                                       BMXError *error))aCompletionBlock{ 
    [self handleGroup:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().search(int64_t(groupId), groupPtr, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)getGroupByName:(NSString *)name
            completion:(void(^)(NSArray *groupList,
                                BMXError *error))aCompletionBlock {
    [self handleGroupListRequst:^floo::BMXErrorCode(floo::BMXGroupList &clist) {
        return self->clientPtr->getGroupService().search(clist,[BMXStringUtil toStdString:name]);
    } completion:aCompletionBlock];
}

/**
 创建群
 
 @param option BMXCreatGroupOption
 @param aCompletionBlock Group info ,Error
 */
- (void)creatGroupWithCreateGroupOption:(BMXCreatGroupOption *)option
                             completion:(void(^)(BMXGroup *group,
                                                 BMXError *error))aCompletionBlock {
    [self handleCreateGroup:^floo::BMXErrorCode(floo::BMXGroupService::CreateGroupOptions *cOption,
                                                floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().create(*[option getBMXCreatGroupOption], groupPtr);
    } completion:aCompletionBlock];
}

/**
 销毁群(群主权限)

 @param group BMXGroup
 @param aCompletionBlock Error
 */
- (void)destroyGroup:(BMXGroup *)group
          completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().destroy([group getBMXGroupPtr]);
    } completion:aCompletionBlock];
}

/**
 加入一个群，根据群设置可能需要管理员批准

 @param group BMXGroup
 @param message 申请信息
 @param aCompletionBlock Error
 */
- (void)joinGroup:(BMXGroup *)group
          message:(NSString *)message
       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return  self->clientPtr->getGroupService().join([group getBMXGroupPtr],
                                                  [BMXStringUtil toStdString:message]);
    } completion:aCompletionBlock];
    
}

/**
 退出群

 @param group BMXGroup
 @param aCompletionBlock Error
 */
- (void)leaveGroup:(BMXGroup *)group
        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().leave([group getBMXGroupPtr]);
    } completion:aCompletionBlock];
}

/**
 获取群详情，从服务端拉取最新信息

 @param group BMXGroup
 @param aCompletionBlock  BMXGroup,BMXError
 */
- (void)loadGroupInfo:(BMXGroup *)group
           completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock {
    [self handleGroup:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().getInfo([group getBMXGroupPtr]);
    } completion:aCompletionBlock];
}

/**
 * 获取群组成员昵称
 **/
- (void)getMembersNickName:(BMXGroup *)group
              memberIdlist:(NSArray<NSNumber *> *)memberIdlist
                completion:(void (^)(NSArray *aGroupMembers, BMXError *aError))aCompletionBlock {
    [self handleGroupDetailRequst:^floo::BMXErrorCode(floo::BMXGroup::MemberList &clist) {
        std::vector<int64_t> members;
        for (NSNumber *userId in memberIdlist) {
            members.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().getMembersNickname([group getBMXGroupPtr], members, clist);
    } completion:aCompletionBlock];
}

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
                                   BMXError *error))aCompletionBlock {
    [self handleInvitationPageResult:^floo::BMXErrorCode(floo::BMXGroupInvitationPagePtr &ptr) {
        return self->clientPtr->getGroupService().getInvitationList(ptr);
    } completion:aCompletionBlock];
}

/**
 * 分页获取群组申请列表
 **/
- (void)getApplicationListByCursor:(NSString *)cursor
                  pageSize:(int)pageSize
                completion:(void(^)(NSArray *applicationList,
                                    NSString *cursor,
                                    long long offset,
                                    BMXError *error))aCompletionBlock {
    [self handleApplicationPageResult:^floo::BMXErrorCode(floo::BMXGroupApplicationPagePtr &ptr) {
        std::vector<floo::BMXGroupPtr> groups;
        return  self->clientPtr->getGroupService().getApplicationList(groups, ptr);
    } completion:aCompletionBlock];
   
}

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
                               BMXError *error))aCompletionBlock {
    [self handleMemberPageResult:^floo::BMXErrorCode(floo::BMXGroupMemberResultPagePtr &ptr) {
        return self->clientPtr->getGroupService().getMembers([group getBMXGroupPtr], ptr);
    } completion:aCompletionBlock];
}

/**
 获取群成员列表

 @param group BMXGroup
 @param forceRefresh 如果设置了forceRefresh则从服务器拉取
 @param aCompletionBlock List:BMXGroupMember ,BMXError
 */
- (void)getMembers:(BMXGroup *)group
      forceRefresh:(BOOL)forceRefresh
        completion:(void(^)(NSArray<BMXGroupMember *> *groupList,
                            BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(nil, error);
    }
    [self handleGroupMembersRequest:^floo::BMXErrorCode(floo::BMXGroup::MemberList &mList) {
        return  self->clientPtr->getGroupService().getMembers([group getBMXGroupPtr],
                                                              mList,
                                                              (bool)forceRefresh);
    } completion:aCompletionBlock];
}

/**
 添加群成员

 @param group BMXGroup
 @param memberIdlist memberList
 @param message 添加信息
 @param aCompletionBlock BMXError
 */
- (void)addMembersToGroup:(BMXGroup *)group
             memberIdlist:(NSArray<NSNumber *> *)memberIdlist
                  message:(NSString *)message
               completion:(void(^)(BMXError *error))aCompletionBlock{
      [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> members;
        for (NSNumber *userId in memberIdlist) {
            members.push_back([userId longLongValue]);
        }
          return self->clientPtr->getGroupService().addMembers([group getBMXGroupPtr],
                                                               members,
                                                               [BMXStringUtil toStdString:message]);
    } completion:aCompletionBlock];
}

/**
 删除群成员

 @param group BMXGroup
 @param memberList memberlist
 @param reason reason
 @param aCompletionBlock  BMXError
 */
- (void)removeMembers:(BMXGroup *)group
           memberlist:(NSArray<NSNumber *> *)memberList
               reason:(NSString *)reason
           completion:(void(^)(BMXError *error))aCompletionBlock {
    if (memberList.count == 0) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> members;
        for (NSNumber *userId in memberList) {
            members.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().addMembers([group getBMXGroupPtr],
                                                             members, [BMXStringUtil
                                                                       toStdString:reason]);
    } completion:aCompletionBlock];
    
}

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
       completion:(void(^)(BMXError *error))aCompletionBlock {
    if (admins.count == 0) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> adminList;
        for (NSNumber *userId in admins) {
            adminList.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().addAdmins([group getBMXGroupPtr],
                                                            adminList,
                                                            [BMXStringUtil toStdString:message]);
    } completion:aCompletionBlock];
}


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
          completion:(void(^)(BMXError *error))aCompletionBlock {
    if (admins.count == 0) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> adminList;
        for (NSNumber *userId in admins) {
            adminList.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().removeAdmins([group getBMXGroupPtr],
                                                               adminList,
                                                               [BMXStringUtil toStdString:reason]);
    } completion:aCompletionBlock];
}

- (void)getAdmins:(BMXGroup *)group
     forceRefresh:(BOOL)forceRefresh
       completion:(void(^)(NSArray<BMXGroupMember *> *,BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(nil,error);
    }
    [self handleGroupMembersRequest:^floo::BMXErrorCode(floo::BMXGroup::MemberList &mList) {
        return self->clientPtr->getGroupService().getAdmins([group getBMXGroupPtr],
                                                            mList,
                                                            (bool)forceRefresh);
    } completion:aCompletionBlock];
}


- (void)blockMembers:(BMXGroup *)group
             members:(NSArray <NSNumber *>*)members
          completion:(void(^)(BMXError *error))aCompletionBlock {
    if (members.count == 0) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> blockMembers;
        for (NSNumber *userId in members) {
            blockMembers.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().blockMembers([group getBMXGroupPtr],
                                                               blockMembers);
    } completion:aCompletionBlock];
    
}

- (void)unblockMember:(BMXGroup *)group
              members:(NSArray<NSNumber *>*)members
           completion:(void(^)(BMXError *error))aCompletionBlock {
    if (members.count == 0) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> blockMembers;
        for (NSNumber *userId in members) {
            blockMembers.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().unblockMembers([group getBMXGroupPtr],
                                                                 blockMembers);
    } completion:aCompletionBlock];
    
}

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
                              BMXError *error))aCompletionBlock {
    [self handleMemberPageResult:^floo::BMXErrorCode(floo::BMXGroupMemberResultPagePtr &ptr) {
        return self->clientPtr->getGroupService().getBlockList([group getBMXGroupPtr], ptr);
    } completion:aCompletionBlock];
}

- (void)getBlockListByGroup:(BMXGroup *)group
               forceRefresh:(BOOL)forceRefresh
                 completion:(void(^)(NSArray<BMXGroupMember *> *,BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(nil, error);
    }
    [self handleGroupMembersRequest:^floo::BMXErrorCode(floo::BMXGroup::MemberList &mList) {
        return self->clientPtr->getGroupService().getBlockList([group getBMXGroupPtr], mList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)banMembers:(NSArray <NSNumber *>*)members
             group:(BMXGroup *)group
            reason:(NSString *)reason
          duration:(long long)duration
        completion:(void(^)(BMXError *error))aCompletionBlock {
    if (!group || [members count]) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> bannedMembers;
        for (NSNumber *userId in members) {
            bannedMembers.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().banMembers([group getBMXGroupPtr],
                                                                          bannedMembers,
                                                                          int64_t(duration),
                                                                          [BMXStringUtil toStdString:reason]);
    } completion:aCompletionBlock];
}

- (void)banGroup:(BMXGroup *)group
          duration:(long long)duration
        completion:(void(^)(BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().banGroup([group getBMXGroupPtr],
                                                                          int64_t(duration));
    } completion:aCompletionBlock];
}

- (void)unbanMembersByGroup:(BMXGroup *)group
                     members:(NSArray <NSNumber *>*)members
                      reason:(NSString *)reason
                  completion:(void(^)(BMXError *error))aCompletionBlock {
    if (!group || [members count]) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> bannedMembers;
        for (NSNumber *userId in members) {
            bannedMembers.push_back([userId longLongValue]);
        }
        return self->clientPtr->getGroupService().unbanMembers([group getBMXGroupPtr],
                                                          bannedMembers);
    } completion:aCompletionBlock];
    
}

- (void)unbanGroup:(BMXGroup *)group
        completion:(void(^)(BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().unbanGroup([group getBMXGroupPtr]);
    } completion:aCompletionBlock];
}

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
                                   BMXError *error))aCompletionBlock {
    [self handlebannedMemberPageResult:^floo::BMXErrorCode(floo::BMXGroupBannedMemberResultPagePtr &ptr) {
        return self->clientPtr->getGroupService().getBannedMembers([group getBMXGroupPtr], ptr);
    } completion:aCompletionBlock];
}

- (void)getBannedMembersByGroup:(BMXGroup *)group
                    completion:(void(^)(NSArray<BMXGroupBannedMember *> *bannedMemberList,
                                        BMXError *error))aCompletionBlock {
    [self handleGroupBannedMembersRequest:^floo::BMXErrorCode(floo::BMXGroup::BannedMemberList &mList) {
        return self->clientPtr->getGroupService().getBannedMembers([group getBMXGroupPtr], mList);
    } completion:aCompletionBlock];
}

- (void)muteMessageByGroup:(BMXGroup *)group
                    msgMuteMode:(BMXGroupMsgMuteMode)msgMuteMode
                 completion:(void(^)(BMXError *error))aCompletionBlock {

    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().muteMessage([group getBMXGroupPtr], (floo::BMXGroup::MsgMuteMode)msgMuteMode);
    } completion:aCompletionBlock];
    
}


- (void)acceptApplicationByGroup:(BMXGroup *)group
                     applicantId:(long long)applicantId
                      completion:(void(^)(BMXError *error))aCompletionBlock {
//    if (!group || !applicantId) {
//        BMXError *error = [BMXError errorCode:BMXInvalidParam];
//        aCompletionBlock(error);
//    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().acceptApplication([group getBMXGroupPtr],
                                                                    (int64_t)applicantId);
    } completion:aCompletionBlock];
    
}

- (void)declineApplicationByGroup:(BMXGroup *)group
                           applicantId:(long long)applicantId
                       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().declineApplication([group getBMXGroupPtr],
                                                                     (int64_t)applicantId);
    } completion:aCompletionBlock];
}

/**
 * 接受入群邀请
 **/
- (void)acceptInvitationByGroup:(BMXGroup *)group
                        inviter:(long long)inviter
                     completion:(void(^)(BMXError *error))aCompletionBlock {
    
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return  self->clientPtr->getGroupService().acceptInvitation([group getBMXGroupPtr],(int64_t) inviter);
    } completion:aCompletionBlock];
    
}

/**
 * 拒绝入群邀请
 **/
- (void)declineInvitationByGroup:(BMXGroup *)group
                         inviter:(long long)inviter
                      completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().declineInvitation([group getBMXGroupPtr], (int64_t)inviter);
    } completion:aCompletionBlock];
}

- (void)transferOwnerByGroup:(BMXGroup *)group
                  newOwnerId:(long long)newOwnerId
                  completion:(void(^)(BMXError *error))aCompletionBlock {
    if (!group || !newOwnerId) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(error);
    }
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().transferOwner([group getBMXGroupPtr],
                                                                (int64_t)newOwnerId);
    } completion:aCompletionBlock];
}

- (void)uploadSharedFileToGroup:(BMXGroup *)group
                    filePathStr:(NSString *)filePathStr
                    displayName:(NSString *)displayName
                     extionName:(NSString *)extionName
                       progress:(void(^)(int progress, BMXError *error))aProgress
                     completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXErrorCode code = self->clientPtr->getGroupService().uploadSharedFile([group getBMXGroupPtr],
                                                                                      [BMXStringUtil toStdString:filePathStr],
                                                                                      [BMXStringUtil toStdString:displayName],
                                                                                      [BMXStringUtil toStdString:extionName],[=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
            });
        });
        
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aCompletion(nil, error);
            });
        }else {
            aCompletion(group, nil);
        }
    });
}

- (void)removeSharedFileFromGroup:(BMXGroup *)group
                         file:(BMXGroupSharedFile *)file
                       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().removeSharedFile([group getBMXGroupPtr],
                                                             [file getGroupSharedFilePtr]);
    } completion:aCompletionBlock];
}

- (void)downloadSharedFileFromGroup:(BMXGroup *)group
                          shareFile:(BMXGroupSharedFile *)shareFile
                           progress:(void(^)(int progress, BMXError *error))aProgress
                         completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXErrorCode code = self->clientPtr->getGroupService().downloadSharedFile([group getBMXGroupPtr],
                                                                                        [shareFile getGroupSharedFilePtr],[=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
            });
        });
        
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aCompletion(nil, error);
            });
        }else {
            aCompletion(group, nil);
        }
    });
}

- (void)getSharedFilesListByGroup:(BMXGroup *)group
                     forceRefresh:(BOOL)forceRefresh
                       completion:(void(^)(NSArray<BMXGroupSharedFile *> *sharedFileList, BMXError *error))aCompletionBlock {
    [self handleGroupFileListRequest:^floo::BMXErrorCode(floo::BMXGroup::SharedFileList &mList) {
        return self->clientPtr->getGroupService().getSharedFilesList([group getBMXGroupPtr], mList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)deleteAnnouncementWithGroup:(BMXGroup *)group
                     announcementId:(long long)announcementId
                         completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock {
    [self handleGroup:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().deleteAnnouncement([group getBMXGroupPtr], announcementId);
    } completion:aCompletionBlock];
}


- (void)getLatestAnnouncementWithGroup:(BMXGroup *)group
                          forceRefresh:(BOOL)forceRefresh
                            completion:(void(^)(BMXGroupAnnounment *groupAnnounment, BMXError *error))aCompletionBlock {
    [self handleGroupAnnoucment:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr, floo::BMXGroup::AnnouncementPtr &announcementPtr) {
      return self->clientPtr->getGroupService().getLatestAnnouncement([group getBMXGroupPtr], announcementPtr, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

/**
 * 获取群公告列表
 **/
- (void)getAnnouncementListWithGroup:(BMXGroup *)group
                        forceRefresh:(BOOL)forceRefresh
                          completion:(void(^)(NSArray *annoucmentArray, BMXError *error))aCompletionBlock {
    [self handleGroupAnnoucments:^floo::BMXErrorCode(floo::BMXGroup::AnnouncementList &cList) {
        return self->clientPtr->getGroupService().getAnnouncementList([group getBMXGroupPtr], cList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)removeMembersWithGroup:(BMXGroup *)group
                    memberlist:(NSArray *)memberList
                        reason:(NSString *)reason
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupRequest:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        std::vector<int64_t> members;
        for (NSString *userId in memberList) {
            members.push_back([userId longLongValue]);
        }
      return  self->clientPtr->getGroupService().removeMembers([group getBMXGroupPtr], members, [BMXStringUtil toStdString:reason]);
    } completion:aCompletionBlock];
    
}


- (void)editGroupAnnouncement:(BMXGroup *)group
                        title:(NSString *)title
                      content:(NSString *)content
                   completion:(void(^)(BMXGroup *group, BMXError *error))aCompletionBlock {
    [self handleGroup:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().editAnnouncement([group getBMXGroupPtr], [BMXStringUtil toStdString:title], [BMXStringUtil toStdString:content]);
    } completion:aCompletionBlock];
}

- (void)setGroupName:(BMXGroup *)group
                name:(NSString *)name
          completion:(void(^)(BMXGroup *group,BMXError *error))aCompletionBlock {
    if (!group) {
        BMXError *error = [BMXError errorCode:BMXInvalidParam];
        aCompletionBlock(nil, error);
    }
    [self handleGroup:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setName([group getBMXGroupPtr], [BMXStringUtil toStdString:name]);
    } completion:aCompletionBlock];
    
}

- (void)setGroupDescription:(BMXGroup *)group
                description:(NSString *)description
                 completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setDescription([group getBMXGroupPtr], [BMXStringUtil toStdString:description]);
    } completion:aCompletionBlock];
    
}

- (void)setGroupExtensionWithGroup:(BMXGroup *)group
                         extension:(NSString *)extension
                        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
       return self->clientPtr->getGroupService().setExtension([group getBMXGroupPtr], [BMXStringUtil toStdString:extension]);
    } completion:aCompletionBlock];
}

- (void)setMyNicknameWithGroup:(BMXGroup *)group
                     nickName:(NSString *)nickName
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setMyNickname([group getBMXGroupPtr], [BMXStringUtil toStdString:nickName]);
    } completion:aCompletionBlock];
}


- (void)setMsgPushModeWithGroup:(BMXGroup *)group
                          mode:(BMXGroupMsgPushMode)mode
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setMsgPushMode([group getBMXGroupPtr], (floo::BMXGroup::MsgPushMode)mode);
    } completion:aCompletionBlock];
}

- (void)setJoinAuthModeWithGroup:(BMXGroup *)group
                    joinAuthMode:(BMXGroupJoinAuthMode)mode
                      completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return  self->clientPtr->getGroupService().setJoinAuthMode([group getBMXGroupPtr], (floo::BMXGroup::JoinAuthMode)mode);
    } completion:aCompletionBlock];
    
}

- (void)setInviteModeWithGroup:(BMXGroup *)group
                          mode:(BMXGroupInviteMode)inviteMode
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setInviteMode([group getBMXGroupPtr], (floo::BMXGroup::InviteMode)inviteMode);
    } completion:aCompletionBlock];
}

/**
 设置是否允许群成员设置群信息
 
 @param group 进行操作的群组
 @param enable 是否允许操作
 @param aCompletionBlock  BMXError
 */
- (void)setAllowMemberModifyWithGroup:(BMXGroup *)group
                               enable:(BOOL)enable
                           completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setAllowMemberModify([group getBMXGroupPtr], (bool)enable);
    } completion:aCompletionBlock];
}

/**
 设置是否开启群消息已读功能
 
 @param group 进行操作的群组
 @param enable 是否开启
 @param aCompletionBlock BMXError
 */
- (void)setEnableReadAckWithGroup:(BMXGroup *)group
                           enable:(BOOL)enable
                       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setEnableReadAck([group getBMXGroupPtr], (bool)enable);
    } completion:aCompletionBlock];
}

/**
 设置群成员是否开可见群历史聊天记录
 
 @param group 进行操作的群组
 @param enable 是否开启
 @param aCompletionBlock BMXError
 */
- (void)setHistoryVisibleWithGroup:(BMXGroup *)group
                            enable:(BOOL)enable
                        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleGroupSetting:^floo::BMXErrorCode(floo::BMXGroupPtr &groupPtr) {
        return self->clientPtr->getGroupService().setHistoryVisible([group getBMXGroupPtr], (bool)enable);
    } completion:aCompletionBlock];
}

- (void)setAvatarWithGroup:(BMXGroup *)group
                avatarData:(NSData *)avatarData
                  progress:(void(^)(int progress, BMXError *error))aProgress
                completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        NSString *localPath = @"";
        long long time = [[NSDate date] timeIntervalSince1970] * 1000;
        NSString *fileName = [NSString stringWithFormat:@"%lld",time];
        if ([avatarData length]) {
            localPath = [[BMXClient getCacheDir] stringByAppendingPathComponent:fileName];
            [avatarData writeToFile:localPath atomically:YES];
        }
        
        floo::BMXErrorCode code = self->clientPtr->getGroupService().setAvatar([group getBMXGroupPtr], [BMXStringUtil toStdString:localPath], [=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
            });
        });
        
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aCompletion(nil, error);
            });
        }else {
            aCompletion(group, nil);
        }
    });
}

- (void)downloadAvatarWithGroup:(BMXGroup *)group
                       progress:(void(^)(int progress, BMXError *error))aProgress
                     completion:(void(^)(BMXGroup *resultGroup, BMXError *error))aCompletion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXErrorCode code = self->clientPtr->getGroupService().downloadAvatar([group getBMXGroupPtr], true,[=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
            });
        });
        
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aCompletion(nil, error);
            });
        }else {
            aCompletion(group, nil);
        }
    });
}


- (void)addGroupListener:(id<BMXGroupServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    if ([listener conformsToProtocol:@protocol(BMXGroupServiceProtocol)]) {
        groupListener->addDelegate(listener, nil);
    }
}

- (void)removeGroupListener:(id<BMXGroupServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    
    if ([listener conformsToProtocol:@protocol(BMXGroupServiceProtocol)]) {
        groupListener->removeDelegate(listener);
    }
}

- (void)removeGroupListener {
    if (groupListener) {
        clientPtr->getGroupService().removeGroupListener(groupListener);
    }
}

- (void)addDelegate:(id<BMXGroupServiceProtocol>)aDelegate {
    [self addDelegate:aDelegate delegateQueue:nil];
}

- (void)addDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)aQueue {
    if (aDelegate == nil) {
        return;
    }
    
    if ([aDelegate conformsToProtocol:@protocol(BMXGroupServiceProtocol) ]) {
        groupListener->addDelegate(aDelegate, aQueue);
    }
    
}

- (void)handleGroupFileRequest:(floo::BMXErrorCode (^)(floo::BMXGroup::SharedFilePtr shareFilePtr))aRequest
                    completion:(void(^)(BMXGroupSharedFile *file,
                                       BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::SharedFilePtr shareFilePtr;
        floo::BMXErrorCode err = aRequest(shareFilePtr);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXGroupSharedFile *file = nil;
        if (!error) {
            file =[[BMXGroupSharedFile alloc] initWithBMXGroupSharedFilePtr:shareFilePtr];
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(file,error);
            });
        }
    });
}


- (void)handleGroupFileListRequest:(floo::BMXErrorCode (^)(floo::BMXGroup::SharedFileList &mList))aRequest
                       completion:(void(^)(NSArray *array,
                                           BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::SharedFileList list;
        floo::BMXErrorCode err = aRequest(list);
        NSMutableArray *memberList = nil;
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            memberList = [NSMutableArray array];
            for (floo::BMXGroup::SharedFilePtr file : list) {
                BMXGroupSharedFile *f = [[BMXGroupSharedFile alloc] initWithBMXGroupSharedFilePtr:file];
                [memberList addObject:f];
            }
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(memberList,error);
            });
        }
    });
}

- (void)handleGroupMembersRequest:(floo::BMXErrorCode (^)(floo::BMXGroup::MemberList &mList))aRequest
                       completion:(void(^)(NSArray *array,
                                           BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::MemberList list;
        floo::BMXErrorCode err = aRequest(list);
        NSMutableArray *memberList = nil;
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            memberList = [NSMutableArray array];
            for (floo::BMXGroup::MemberPtr member : list) {
                BMXGroupMember *m = [[BMXGroupMember alloc] initWithBMXGroupMemberPtr:member];
                [memberList addObject:m];
            }
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(memberList,error);
            });
        }
    });
}

- (void)handleGroupBannedMembersRequest:(floo::BMXErrorCode (^)(floo::BMXGroup::BannedMemberList &mList))aRequest
                       completion:(void(^)(NSArray *array,
                                           BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::BannedMemberList list;
        floo::BMXErrorCode err = aRequest(list);
        NSMutableArray *memberList = nil;
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            memberList = [NSMutableArray array];
            for (floo::BMXGroup::BannedMemberPtr member : list) {
                BMXGroupBannedMember *m = [[BMXGroupBannedMember alloc] initWithBMXGroupBannedMemberPtr:member];
                [memberList addObject:m];
            }
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(memberList,error);
            });
        }
    });
}

- (void)handleGroupListRequst:(floo::BMXErrorCode (^)(floo::BMXGroupList &clist))aRequest
                   completion:(void (^)(NSArray *aGroups, BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroupList groups;
        floo::BMXErrorCode err = aRequest(groups);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        NSMutableArray *groupList = nil;
        if (!error) {
            groupList = [NSMutableArray array];
            for (floo::BMXGroupPtr group : groups) {
                if (group.get() != nullptr) {
                    [groupList addObject:[BMXGroup groupWithBMXGroupPtr:group]];
                }
            }
        }
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock([NSArray arrayWithArray:groupList], error);
            });
        }
    });
}

- (void)handleGroupDetailRequst:(floo::BMXErrorCode (^)(floo::BMXGroup::MemberList &clist))aRequest
                   completion:(void (^)(NSArray *aGroupMembers, BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::MemberList members;
        floo::BMXErrorCode err = aRequest(members);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        NSMutableArray *groupMembersList = nil;
        if (!error) {
            groupMembersList = [NSMutableArray array];
            for (floo::BMXGroup::MemberPtr  memberPtr: members) {
                if (memberPtr.get() != nullptr) {
                    BMXGroupMember *member = [[BMXGroupMember alloc] initWithBMXGroupMemberPtr:memberPtr];
                    [groupMembersList addObject:member];
                }
            }
        }

        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock([NSArray arrayWithArray:groupMembersList], error);
            });
        }
    });
}

- (void)handleGroupRequest:(floo::BMXErrorCode (^)(floo::BMXGroupPtr &groupPtr))aRequest
                   completion:(void (^)(BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroupPtr g;
        floo::BMXErrorCode err = aRequest(g);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error);
            });
        }
    });
}
- (void)handleGroupAnnoucment:(floo::BMXErrorCode (^)(floo::BMXGroupPtr &groupPtr, floo::BMXGroup::AnnouncementPtr &announcementPtr))handle
                   completion:(void(^)(BMXGroupAnnounment *groupAnnounment, BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                floo::BMXGroupPtr groupPtr;
        floo::BMXGroup::AnnouncementPtr ptr;
        floo::BMXErrorCode err = handle(groupPtr, ptr);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXGroupAnnounment *ann =  nil;
        if (!error) {
            ann = [[BMXGroupAnnounment alloc] initWithBMXGroupAnnounmentPtr:ptr];
            
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(ann, error);
            });
        }
    });
}

- (void)handleGroupAnnoucments:(floo::BMXErrorCode (^)(floo::BMXGroup::AnnouncementList &cList))handle
                   completion:(void(^)(NSArray *annoucmentArray, BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroup::AnnouncementList list;
        floo::BMXErrorCode err = handle(list);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        NSMutableArray *annList = [NSMutableArray array];
        if (!error) {
            for (floo::BMXGroup::AnnouncementPtr annPtr: list) {
                if (annPtr.get() != nullptr) {
                    BMXGroupAnnounment *a = [[BMXGroupAnnounment alloc] initWithBMXGroupAnnounmentPtr:annPtr];
                    [annList addObject:a];
                }
            }
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(annList, error);
            });
        }
    });
}

- (void)handleGroup:(floo::BMXErrorCode (^)(floo::BMXGroupPtr &groupPtr))handle
         completion:(void(^)(BMXGroup *group,
                             BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroupPtr group;
        floo::BMXErrorCode err = handle(group);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXGroup *groupM = nil;
        if (!error) {
            groupM =[[BMXGroup alloc] initWithBMXGroupPtr:group];
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(groupM, error);
            });
        }
    });
}

- (void)handleCreateGroup:(floo::BMXErrorCode (^)(floo::BMXGroupService::CreateGroupOptions *cOption,
                                                  floo::BMXGroupPtr &groupPtr))handle
               completion:(void(^)(BMXGroup *group,
                             BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroupService::CreateGroupOptions *createOption = nullptr;
        floo::BMXGroupPtr group;
        floo::BMXErrorCode err = handle(createOption, group);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXGroup *groupM = nil;
        if (!error) {
            groupM =[[BMXGroup alloc] initWithBMXGroupPtr:group];
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(groupM, error);
            });
        }
    });
}

- (void)handleGroupSetting:(floo::BMXErrorCode (^)(floo::BMXGroupPtr &groupPtr))handle
               completion:(void(^)(BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXGroupPtr group;
        floo::BMXErrorCode err = handle(group);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error);
            });
        }
    });
}

- (void)handleMemberPageResult:(floo::BMXErrorCode (^)(floo::BMXGroupMemberResultPagePtr &ptr))handle
              completion:(void(^)(NSArray *memberList,
                                  NSString *cursor,
                                  long long offset,
                                  BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXGroupMemberResultPagePtr result;
            floo::BMXErrorCode err = handle(result);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            NSMutableArray *list = [NSMutableArray array];
            int64_t resultOffset = 0;
            NSString *resultCursor = nil;
            if (!error) {
                resultOffset = result->offset();
                resultCursor = [BMXStringUtil stdToNSString: result->cursor()];
                
                for (floo::BMXGroup::MemberPtr ptr : result->result()) {
                    BMXGroupMember *member = [[BMXGroupMember alloc] initWithBMXGroupMemberPtr:ptr];
                    [list addObject:member];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(list, resultCursor, resultOffset,error);
            });
        });
    }
}

- (void)handlebannedMemberPageResult:(floo::BMXErrorCode (^)(floo::BMXGroupBannedMemberResultPagePtr &ptr))handle
                    completion:(void(^)(NSArray *memberList,
                                        NSString *cursor,
                                        long long offset,
                                        BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXGroupBannedMemberResultPagePtr result;
            floo::BMXErrorCode err = handle(result);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            NSMutableArray *list = [NSMutableArray array];
            int64_t resultOffset = 0;
            NSString *resultCursor = nil;
            if (!error) {
                resultOffset = result->offset();
                resultCursor = [BMXStringUtil stdToNSString: result->cursor()];
                
                for (floo::BMXGroup::BannedMemberPtr ptr : result->result()) {
                    BMXGroupBannedMember *member = [[BMXGroupBannedMember alloc] initWithBMXGroupBannedMemberPtr:ptr];
                    [list addObject:member];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(list, resultCursor, resultOffset,error);
            });
        });
    }
}

- (void)handleApplicationPageResult:(floo::BMXErrorCode (^)(floo::BMXGroupApplicationPagePtr &ptr))handle
                    completion:(void(^)(NSArray *applicationList,
                                        NSString *cursor,
                                        long long offset,
                                        BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXGroupApplicationPagePtr result;
            floo::BMXErrorCode err = handle(result);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            NSMutableArray *list = [NSMutableArray array];
            int64_t resultOffset = 0;
            NSString *resultCursor = nil;
            if (!error) {
                resultOffset = result->offset();
                resultCursor = [BMXStringUtil stdToNSString: result->cursor()];
                
                for (floo::BMXGroup::ApplicationPtr ptr : result->result()) {
                    BMXGroupApplication *application = [[BMXGroupApplication alloc] initWithBMXGroupApplicationPtr:ptr];
                    [list addObject:application];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(list, resultCursor, resultOffset,error);
            });
        });
    }
}


- (void)handleInvitationPageResult:(floo::BMXErrorCode (^)(floo::BMXGroupInvitationPagePtr &ptr))handle
                         completion:(void(^)(NSArray *invitationList,
                                             NSString *cursor,
                                             long long offset,
                                             BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXGroupInvitationPagePtr result;
            floo::BMXErrorCode err = handle(result);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            NSMutableArray *list = [NSMutableArray array];
            int64_t resultOffset = 0;
            NSString *resultCursor = nil;
            if (!error) {
                resultOffset = result->offset();
                resultCursor = [BMXStringUtil stdToNSString: result->cursor()];
                
                for (floo::BMXGroup::InvitationPtr ptr : result->result()) {
                    BMXGroupInvitation *invitation = [[BMXGroupInvitation alloc] initWithBMXGroupInvitationPtr:ptr];
                    [list addObject:invitation];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(list, resultCursor, resultOffset,error);
            });
        });
    }
}


@end

