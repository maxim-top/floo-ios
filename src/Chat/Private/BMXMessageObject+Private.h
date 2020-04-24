// ----------------------------------------------------------------------
// File    : BMXMessageObject+Private.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/29 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------


#import "BMXMessageObject.h"

//#include "BMXMessageObject+Private.h"
#include "bmx_message.h"

@protocol BMXMessageObjectPrivateDelegate <NSObject>

@optional

- (instancetype)initWithMessagePtr:(floo::BMXMessagePtr)messagePtr;

- (floo::BMXMessagePtr)getMessagePtr;

@end

@interface BMXMessageObject (Private)<BMXMessageObjectPrivateDelegate>




+ (floo::BMXMessage::DeliveryQos)oc_transformDeliveryQosMode:(DeliveryQosMode)status;

+ (BMXDeliveryStatus)transformDeliveryQosMode:(floo::BMXMessage::DeliveryStatus)status;



@end
