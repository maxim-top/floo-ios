//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupInvitation+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/5 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupInvitation.h"
#include "bmx_group.h"

@protocol BMXGroupInvitationDelegate <NSObject>

- (instancetype)initWithBMXGroupInvitationPtr:(floo::BMXGroup::InvitationPtr)invitationPtr;
- (floo::BMXGroup::InvitationPtr)getInvitationPtr;

@end

@interface BMXGroupInvitation (Private)<BMXGroupInvitationDelegate>

@end

