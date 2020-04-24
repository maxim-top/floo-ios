//
//  ----------------------------------------------------------------------
//   File    :  BMXCreatGroupOption+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/9 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXCreatGroupOption.h"
#include "bmx_group_service.h"

@protocol BMXCreatGroupOptionDelegate <NSObject>

- (floo::BMXGroupService::CreateGroupOptions *)getBMXCreatGroupOption;

- (instancetype)initWithBMXCreatGroupOption:(floo::BMXGroupService::CreateGroupOptions *)createGroupOption;

@end

@interface BMXCreatGroupOption (Private)<BMXCreatGroupOptionDelegate>


@end

