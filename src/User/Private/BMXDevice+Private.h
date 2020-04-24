//
//  ----------------------------------------------------------------------
//   File    :  BMXDevice+Private.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/2/2 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXDevice.h"
#include "bmx_device.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXDevice (Private)

- (instancetype)initWithBMXDevicePtr:(floo::BMXDevicePtr)ptr;

- (floo::BMXDevicePtr)getBMXDevicePtr;


@end

NS_ASSUME_NONNULL_END
