//
//  ----------------------------------------------------------------------
//   File    :  BMXRoster+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/10 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    


#import "BMXRoster.h"
#include "bmx_roster_item.h"



@interface BMXRoster (Private)

- (instancetype)initWithBMXRosterPtr:(floo::BMXRosterItemPtr)rostItemPtr;

- (floo::BMXRosterItemPtr)getBMXRosterPtr;

//+ (instancetype)rosterPtr:(floo::BMXRosterItemPtr)rostItemPtr;


@end


