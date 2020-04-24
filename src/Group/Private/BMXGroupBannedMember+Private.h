//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupBannedMember+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/24 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupBannedMember.h"
#include "bmx_group.h"


NS_ASSUME_NONNULL_BEGIN

@interface BMXGroupBannedMember (Private)

- (instancetype)initWithBMXGroupBannedMemberPtr:(floo::BMXGroup::BannedMemberPtr)bannedMember;
- (floo::BMXGroup::BannedMemberPtr)getGroupBannedMemberPtr;

@end

NS_ASSUME_NONNULL_END
