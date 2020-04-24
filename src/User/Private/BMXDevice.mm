

//
//  ----------------------------------------------------------------------
//   File    :  BMXDevice.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/31 by HYT yutong@bmxlabs.com
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
#import "BMXStringUtil.h"
#import "BMXDevice+Private.h"

@interface BMXDevice ()

@property (nonatomic,assign) floo::BMXDevicePtr ptr;

@end

@implementation BMXDevice


- (int)deviceSN {
    if (_ptr != nullptr) {
        return (int)_ptr->deviceSN();
    }
    return 0;
}

- (long long)userId {
    if (_ptr != nullptr) {
        return _ptr->userId();
    }
    return 0;
}

- (int)platform {
    if (_ptr != nullptr) {
        return (int)_ptr->platform();
    }
    return 0;
}

- (NSString *)userAgent {
    if (_ptr != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->userAgent()];
    }
    return nil;
}

- (BOOL)isCurrentDevice {
    return (BOOL)_ptr->isCurrentDevice();
}

@end

@implementation BMXDevice (Private)

- (instancetype)initWithBMXDevicePtr:(floo::BMXDevicePtr)ptr {
    if (self = [super init]) {
        if (ptr) {
            _ptr = ptr;
        }
    }
    return self;
}

- (floo::BMXDevicePtr)getBMXDevicePtr {
    return _ptr;
}



@end
