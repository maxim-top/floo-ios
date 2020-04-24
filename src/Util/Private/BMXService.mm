//
// ----------------------------------------------------------------------
// File    : BMXService.m
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

#import "BMXService.h"




@implementation BMXService

- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super init]) {
        clientPtr = aClientPtr;
    }
    return self;
}

- (void)addDelegate:(id)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue {
    if (aDelegate == nil) {
        return;
    }
}

- (void)removeDelegate:(id)aDelegate {
    if (aDelegate == nil) {
        return;
    }
}



//- (BOOL)isConnected {
//    return client_->isConnected();
//}


@end
