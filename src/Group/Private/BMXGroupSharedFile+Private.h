//
//  ----------------------------------------------------------------------
//   File    : BMXGroupSharedFile+Private.h
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
    

#import "BMXGroupSharedFile.h"
#include "bmx_group.h"

@protocol BMXGroupSharedFileDelegate <NSObject>
- (instancetype)initWithBMXGroupSharedFilePtr:(floo::BMXGroup::SharedFilePtr)SharedFilePtr;
- (floo::BMXGroup::SharedFilePtr)getGroupSharedFilePtr;

@end

@interface BMXGroupSharedFile (Private)<BMXGroupSharedFileDelegate>

@end

