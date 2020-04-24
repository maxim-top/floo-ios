//
//  BMXMessageConfig.m
//  MaxIM
//
//  Created by 韩雨桐 on 2019/11/20.
//  Copyright © 2019 hyt. All rights reserved.
//

#import "BMXMessageConfig.h"
#import "BMXMessageConfig+Private.h"
#import "BMXStringUtil.h"

@interface BMXMessageConfig ()

@property (nonatomic, assign) floo::BMXMessageConfigPtr ptr;


@end

@implementation BMXMessageConfig

- (instancetype)initConfigWithMentionAll:(BOOL)isMentionAll {
    if (self = [super init]) {
        self.ptr= floo::BMXMessageConfig::createMessageConfig((bool)isMentionAll);
    }
    return self;
}

- (BOOL)mentionAll {
    return (bool)_ptr->getMentionAll();
}

- (void)setMentionAll:(BOOL)mentionAll {
    self.ptr->setMentionAll((bool)mentionAll);
}

- (void)setMentionList:(NSArray<NSString *> *)mentionList {
    std:: vector<int64_t> mentionMenmberIds;
    for (NSString *rostId in mentionList) {
        mentionMenmberIds.push_back([rostId longLongValue]);
    }
    self.ptr->setMentionList(mentionMenmberIds);
}

- (NSArray<NSString *> *)mentionList {
    std:: vector<int64_t> mentionMenmberIds = _ptr->getMentionList();
    NSMutableArray *aList = nil;
    aList = [NSMutableArray array];
    for (int64_t rostId : mentionMenmberIds) {
        NSString *idstr = [NSString stringWithFormat:@"%lld", rostId];
        [aList addObject:idstr];
    }
    return aList;
}

- (NSString *)mentionMessage {
    return [BMXStringUtil stdToNSString:_ptr->getMentionedMessage()];
}

- (void)setMentionMessage:(NSString *)mentionMessage {
    self.ptr->setMentionedMessage([BMXStringUtil toStdString:mentionMessage]);
}

- (NSString *)pushMessage {
    return [BMXStringUtil stdToNSString:_ptr->getPushMessage()];
}

- (void)setPushMessage:(NSString *)pushMessage {
    self.ptr->setPushMessage([BMXStringUtil toStdString:pushMessage]);
}

- (NSString *)senderName {
    return [BMXStringUtil stdToNSString:_ptr->getSenderNickname()];
}

- (void)setSenderName:(NSString *)senderName {
    self.ptr->setSenderNickname([BMXStringUtil toStdString:senderName]);
}

- (NSArray<NSString *> *)groupMemberList {
    std:: vector<int64_t> groupMenmberIds = _ptr->getGroupMemberList();
    NSMutableArray *aList = nil;
    aList = [NSMutableArray array];
    for (int64_t rostId : groupMenmberIds) {
        NSString *idstr = [NSString stringWithFormat:@"%lld", rostId];
        [aList addObject:idstr];
    }
    return aList;
}

- (void)setGroupMemberList:(NSArray<NSString *> *)groupMemberList {
    std:: vector<int64_t> groupMenmberIds;
    for (NSString *rostId in groupMemberList) {
        groupMenmberIds.push_back([rostId longLongValue]);
    }
    self.ptr->setMentionList(groupMenmberIds);
}

- (void)addGroupMember:(NSString *)rosterId {
    _ptr->addGroupMember((int64_t)[rosterId integerValue]);
}

- (void)removeGroupMember:(NSString *)rosterId {
    _ptr->removeGroupMember((int64_t)[rosterId integerValue]);
}

- (void)clealerGroupMemberList {
    _ptr->clearGroupMemberList();
}

@end


@implementation BMXMessageConfig (Private)

- (instancetype)initWithBMXMessageConfigPtr:(floo::BMXMessageConfigPtr)messageConfigPtr {
    if (self = [super init]) {
        _ptr = messageConfigPtr;
    }
    return self;
}

- (floo::BMXMessageConfigPtr)getBMXMessageConfigPtr {
    return _ptr;
}


@end


