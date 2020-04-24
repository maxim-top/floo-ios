//
// ----------------------------------------------------------------------
// File    : BMXService.h
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

#import <Foundation/Foundation.h>
#include "bmx_client.h"


NS_ASSUME_NONNULL_BEGIN

@interface BMXService : NSObject
{
    floo::BMXClientPtr clientPtr;
}

//- (instancetype)initWithClient:(floo::BMXClient *)aClient;
- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr;

- (void)addDelegate:(id)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id)aDelegate;


@end

NS_ASSUME_NONNULL_END
