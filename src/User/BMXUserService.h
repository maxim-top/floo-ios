// ----------------------------------------------------------------------
// File    : BMXUserService.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/29 by hyt <yutong@bmxlabs.com>
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
#import "BMXUserProfile.h"
#import "UserServiceListener.h"
#import "BMXUserManager.h"
#include "bmx_user_service.h"

@interface BMXUserService : BMXService<BMXUserManager>
{
    floosdk::UserServiceListener *userServiceListener;
}

@property (nonatomic, strong) BMXDelegatesContainer<BMXUserServiceProtocol> *container;

- (void)removeRosterListener;

@end


