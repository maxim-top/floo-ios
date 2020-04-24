// ----------------------------------------------------------------------
// File    : BMXChatService.h
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


#import <Foundation/Foundation.h>
#import "BMXChatServiceProtocol.h"
#import "BMXService.h"
#import "ChatServiceListener.h"
#import "BMXDelegatesContainer.h"
#import "BMXChatManager.h"

NS_ASSUME_NONNULL_BEGIN

@class BMXClient;
@interface BMXChatService : BMXService <BMXChatManager>
{
    floosdk::ChatServiceListener *chatListener;
}

@property (strong, nonatomic, readonly) BMXDelegatesContainer<BMXChatServiceProtocol> *container;

- (void)removeChatListener;

@end

NS_ASSUME_NONNULL_END
