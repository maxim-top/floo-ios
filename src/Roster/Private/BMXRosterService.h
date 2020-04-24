//
// ----------------------------------------------------------------------
// File    : BMXRosterService.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------
//

#import <Foundation/Foundation.h>

#import "BMXService.h"
#import "RosterServiceListener.h"
#import "BMXRosterManager.h"

#include "bmx_roster_item.h"
#include "bmx_roster_service.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXRosterService : BMXService <BMXRosterManager>
{
    floosdk::RosterServiceListener *rostelistener;
}

@property (nonatomic, strong) BMXDelegatesContainer<BMXRosterServiceProtocol> *container;

- (void)removeRosterListener;

@end

NS_ASSUME_NONNULL_END
