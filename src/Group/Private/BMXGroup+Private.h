//
//  ----------------------------------------------------------------------
//   File    :  BMXGroup+Private.h
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
    

#import "BMXGroup.h"
#include "bmx_group.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BMXGroupDelegate <NSObject>


@end

@interface BMXGroup (Private)


- (instancetype)initWithBMXGroupPtr:(floo::BMXGroupPtr)ptr;

+ (instancetype)groupWithBMXGroupPtr:(floo::BMXGroupPtr)ptr;

- (floo::BMXGroupPtr)getBMXGroupPtr;


@end

NS_ASSUME_NONNULL_END
