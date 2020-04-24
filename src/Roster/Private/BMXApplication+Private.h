//
//  ----------------------------------------------------------------------
//   File    :  BMXApplication+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/22 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXApplication.h"
#include "bmx_roster_service.h"

@protocol BMXApplicationDelegate <NSObject>

@optional
- (instancetype)initWithApplicationPtr:(floo::BMXRosterService::ApplicationPtr)applicationPtr;
- (floo::BMXRosterService::ApplicationPtr)getApplicationPtr;
@end


@interface BMXApplication (Private)<BMXApplicationDelegate>

@end

