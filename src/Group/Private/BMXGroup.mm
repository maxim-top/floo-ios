//
//  BMXGroup.m
//  MaxIM
//
//  Created by hyt on 2018/11/24.
//  Copyright © 2018年  . All rights reserved.
//

#import "BMXGroup.h"
#import "BMXGroup+Private.h"
#import "BMXGroupMember+Private.h"
#import "BMXGroupSharedFile+Private.h"
#import "BMXGroupAnnounment+Private.h"
#import "BMXStringUtil.h"
#import "BMXGroupMember.h"
#import "BMXGroupSharedFile.h"
#include "bmx_group.h"

@interface BMXGroup ()

@property (nonatomic,assign) floo::BMXGroupPtr ptr;

@end

@implementation BMXGroup

- (instancetype)init {
    return nil;
}

- (long long)groupId {
    if (_ptr.get() != nullptr) {
        return (long long)_ptr->groupId();
    }
    return 0;
}

- (BMXGroupType)groupType {
    return (BMXGroupType)_ptr->groupType();
}

- (NSString *)myNickName {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->myNickname()];
    }
    return nil;
}
- (NSString *)name {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->name()];
    }
    return nil;
}

- (NSString *)groupDescription {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->description()];
    }
    return nil;
}

- (NSString *)avatarUrl {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->avatarUrl()];
    }
    return nil;
}

- (NSString *)avatarPath {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->avatarPath()];
    }
    return nil;
}


- (NSString *)avatarThumbnailPath {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->avatarThumbnailPath()];
    }
    return nil;
}

- (long long)creatTime {
    if (_ptr.get() != nullptr) {
        return (long long)_ptr->createTime();
        
    }
    return 0;
}

- (NSString *)jsonextension {
    if (_ptr.get() != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->extension()];
    }
    return nil;
}

- (NSInteger)ownerId {
    if (_ptr.get() != nullptr) {
        return (NSInteger)_ptr->ownerId();
    }
    return 0;
}

- (NSInteger)capactiy {
    if (_ptr.get() != nullptr) {
        return (NSInteger)_ptr->capacity();
    }
    return 0;
}

- (NSInteger)membersCount {
    if (_ptr.get() != nullptr) {
        return (NSInteger)_ptr->membersCount();
    }
    return 0;
}

- (NSInteger)adminsCount {
    if (_ptr.get() != nullptr) {
        return (NSInteger)_ptr->adminsCount();
    }
    return 0;
}

- (NSInteger)sharedFilesCount {
    if (_ptr.get() !=  nullptr) {
        return (NSInteger)_ptr->sharedFilesCount();
    }
    return 0;
}

- (BMXGroupMsgMuteMode)msgMuteMode {
    return (BMXGroupMsgMuteMode)_ptr->msgMuteMode();
}

- (BMXGroupModifyMode)modifyMode {
    return (BMXGroupModifyMode)_ptr->modifyMode();
}

- (BMXGroupMsgPushMode)msgPushMode {
    return (BMXGroupMsgPushMode)_ptr->msgPushMode();
}

- (BMXGroupJoinAuthMode)joinAuthMode {
    return (BMXGroupJoinAuthMode)_ptr->joinAuthMode();
}

- (BMXGroupInviteMode)inviteMode {
    return (BMXGroupInviteMode)_ptr->inviteMode();
}

- (BOOL)enableReadAck {
    return (BOOL)_ptr->enableReadAck();
}

- (BOOL)historyVisible {
    return (BOOL)_ptr->historyVisible();
}

- (BMXGroupStatus)groupStatus {
    return (BMXGroupStatus)_ptr->groupStatus();
}

- (BMXGroupMemberRoleType)roleType {
    return (BMXGroupMemberRoleType)_ptr->roleType();
}

- (BOOL)isMember {
    return (BOOL)_ptr->isMember();
}

- (long long)banExpireTime {
    if (_ptr.get() != nullptr) {
        return (long long)_ptr->banExpireTime();
    }
    return 0;
}

@end

@implementation BMXGroup (Private)
- (floo::BMXGroupPtr)getBMXGroupPtr {
    return _ptr;
}

+ (instancetype)groupWithBMXGroupPtr:(floo::BMXGroupPtr)ptr  {
    if (ptr.get() == nullptr) {
        return nil;
    }
    return [[BMXGroup alloc] initWithBMXGroupPtr:ptr];
}

- (instancetype)initWithBMXGroupPtr:(floo::BMXGroupPtr)ptr {
    if (self = [super init]) {
        _ptr = ptr;
    }
    return self;
}

@end



