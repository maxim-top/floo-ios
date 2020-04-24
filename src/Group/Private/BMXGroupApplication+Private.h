//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupApplication+Private.h
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
    

#import "BMXGroupApplication.h"
#include "bmx_group.h"

@protocol BMXGroupApplicationDelegate <NSObject>

- (instancetype)initWithBMXGroupApplicationPtr:(floo::BMXGroup::ApplicationPtr)applicationPtr;
- (floo::BMXGroup::ApplicationPtr)getApplicationPtr;

@end

@interface BMXGroupApplication (Private)<BMXGroupApplicationDelegate>

@end

