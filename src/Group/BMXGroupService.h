//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupService.h
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
    

#import "BMXService.h"
#import "BMXGroupServiceProtocol.h"
#import "BMXDelegatesContainer.h"
#import "BMXGroupManager.h"
#import "GroupServiceListener.h"
#include "bmx_group_service.h"

@interface BMXGroupService : BMXService <BMXGroupManager>
{
    floosdk::GroupServiceListener *groupListener;
}

@property (strong, nonatomic, readonly) BMXDelegatesContainer<BMXGroupServiceProtocol> *container;

- (void)removeGroupListener;

@end

