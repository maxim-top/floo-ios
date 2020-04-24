//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupMember+Private.h
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
    

#import "BMXGroupMember.h"
#include "bmx_group.h"


NS_ASSUME_NONNULL_BEGIN
@protocol BMXGroupMemberDelegate <NSObject>

- (instancetype)initWithBMXGroupMemberPtr:(floo::BMXGroup::MemberPtr)gmember;
- (floo::BMXGroup::MemberPtr)getGroupMemberPtr;

@end

@interface BMXGroupMember (Private)<BMXGroupMemberDelegate>

@end

NS_ASSUME_NONNULL_END
