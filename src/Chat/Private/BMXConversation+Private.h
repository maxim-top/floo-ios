// ----------------------------------------------------------------------
// File    : BMXConversation+Private.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/12/4 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------



#import "BMXConversation.h"
#include "bmx_conversation.h"

@protocol BMXConversationPrivateDelegate <NSObject>

@optional

- (instancetype _Nullable )initWithConversationPtr:(floo::BMXConversationPtr)conversationPtr;

- (floo::BMXConversationPtr)getConersationPtr;

@end


NS_ASSUME_NONNULL_BEGIN

@interface BMXConversation (Private)<BMXConversationPrivateDelegate>

//
//+ (floo::BMXConversation::Type)oc_transforBMXConversationType:(BMXConversationType)type;
//
//+ (BMXConversationType)transforBMXConversationType:(floo::BMXConversation::Type)type;

@end

NS_ASSUME_NONNULL_END
