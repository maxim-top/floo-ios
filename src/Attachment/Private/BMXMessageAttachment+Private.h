// ----------------------------------------------------------------------
// File    : BMXConversationObject.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/12/1 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXMessageAttachment.h"
#include "bmx_message_attachment.h"


@protocol BMXMessageAttachmentPrivateDelegate <NSObject>

@optional
- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr;
- (instancetype)initWithBMXMessageAttachment:(floo::BMXMessageAttachmentPtr)attachmentPtr;

@end

@interface BMXMessageAttachment (Private)<BMXMessageAttachmentPrivateDelegate>



@end

