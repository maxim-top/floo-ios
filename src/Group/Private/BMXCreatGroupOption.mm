
//
//  ----------------------------------------------------------------------
//   File    :  BMXCreatGroupOption.m
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
    

#import "BMXCreatGroupOption.h"
#import "BMXStringUtil.h"
#import "BMXGroupMember+Private.h"
#import "BMXGroupMember.h"
#import "BMXCreatGroupOption+Private.h"
#include "bmx_group_service.h"

@interface BMXCreatGroupOption ()


@property (nonatomic,assign) floo::BMXGroupService::CreateGroupOptions *option;
#warning - hyt 释放该指针

@end

@implementation BMXCreatGroupOption
- (instancetype)initWithGroupName:(NSString *)name
                 groupDescription:(NSString *)groupDescription
                         isPublic:(BOOL)isPublic {
    if (self = [super init]) {
        self.option = new floo::BMXGroupService::CreateGroupOptions([BMXStringUtil toStdString:name], [BMXStringUtil toStdString:groupDescription],(bool)isPublic);
    }
    return self;
}

- (void)setName:(NSString *)name {
    self.option->mName = [BMXStringUtil toStdString:name];
}

- (void)setGroupDescription:(NSString *)groupDescription {
    self.option->mDescription = [BMXStringUtil toStdString:groupDescription];
}

- (void)setMessage:(NSString *)message {
    self.option->mMessage = [BMXStringUtil toStdString:message];
}

- (void)setMembers:(NSArray<BMXGroupMember *> *)members {
    std::vector<int64_t> memberlist;
    for (NSString *userId in members) {
        memberlist.push_back([userId longLongValue]);
    }
    self.option->mMembers = memberlist;
}

@end

@implementation BMXCreatGroupOption (Private)

- (floo::BMXGroupService::CreateGroupOptions *)getBMXCreatGroupOption {
    return self.option;
}

- (instancetype)initWithBMXCreatGroupOption:(floo::BMXGroupService::CreateGroupOptions *)createGroupOption {
    if (self = [super init]) {
        _option = createGroupOption;
    }
    return self;
}

@end


