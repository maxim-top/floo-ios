// ----------------------------------------------------------------------
// File    : BMXMessage.mm
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/17 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------


#import "BMXMessageObject.h"

#import "BMXImageAttachment.h"
#import "BMXFileAttachment.h"
#import "BMXLocationAttachment.h"
#import "BMXVoiceAttachment.h"
#import "BMXVideoAttachment.h"

#import "BMXMessageObject+Private.h"
#import "BMXMessageAttachment+Private.h"
#import "BMXStringUtil.h"

#include "bmx_message.h"
#import "BMXMessageConfig+Private.h"

@interface BMXMessageObject ()

@property (nonatomic,assign) floo::BMXMessagePtr messagePtr ;

@end

@implementation BMXMessageObject

- (instancetype)initWithBMXMessageText:(NSString *)content
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                  type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId {
    if (self = [super init]) {
        self.content = content;
        self.conversationId = conversationId;
        
        std::string contentStr = [BMXStringUtil toStdString:content];
        self.messagePtr  =  floo::BMXMessage::createMessage(fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, contentStr);
    }
    return self;
}

- (instancetype)initWithBMXCommandMessageText:(NSString *)content
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                  type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId {
    if (self = [super init]) {
        self.content = content;
        self.conversationId = conversationId;
        
        std::string contentStr = [BMXStringUtil toStdString:content];
        self.messagePtr  =  floo::BMXMessage::createCommandMessage(fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, contentStr);
    }
    return self;
}

- (instancetype)initWithBMXMessageAttachment:(BMXMessageAttachment *)attachment
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                        type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId {
    if (self = [super init]) {
        _attachment = attachment;
        self.messagePtr = floo::BMXMessage::createMessage(fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, [_attachment getMessageAttachmentPtr]);
    }
    return self;
}

- (instancetype)initWithRecieveBMXMessageText:(NSString *)content
                                    msgId:(long long)msgId
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                        type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId
                                timeStamp:(long long)timeStamp{
    if (self = [super init]) {
        std::string contentStr = [BMXStringUtil toStdString:content];

        self.messagePtr = floo::BMXMessage::createMessage(msgId, fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, contentStr.c_str(), timeStamp);
    }
    return self;
}


- (instancetype)initWithRecieveBMXMessageCommandMessageText:(NSString *)content
                                                      msgId:(long long)msgId
                                                     fromId:(long long )fromId
                                                       toId:(long long)toId
                                                       type:(BMXMessageType)mtype
                                             conversationId:(long long )conversationId
                                                  timeStamp:(long long)timeStamp {
    
    if (self = [super init]) {
        std::string contentStr = [BMXStringUtil toStdString:content];

        self.messagePtr = floo::BMXMessage::createCommandMessage(msgId, fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, contentStr.c_str(), timeStamp);
        
    }
    return self;
    
}
                                                      

                                               


- (instancetype)initWithRecieveBMXMessageAttachment:(BMXMessageAttachment *)attachment
                                              msgId:(long long)msgId
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                        type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId
                                          timeStamp:(long long)timeStamp {
    if (self = [super init]) {
        _attachment = attachment;
        self.messagePtr = floo::BMXMessage::createMessage(msgId, fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId, [_attachment getMessageAttachmentPtr], timeStamp);
    }
    return self;
}


- (instancetype)initWithForwardMessage:(BMXMessageObject *)message
                                             fromId:(long long )fromId
                                               toId:(long long)toId
                                               type:(BMXMessageType)mtype
                                     conversationId:(long long )conversationId {
    if (self = [super init]) {
        self.messagePtr = floo::BMXMessage::createForwardMessage([message getMessagePtr], fromId, toId, (floo::BMXMessage::MessageType)mtype, conversationId);
    }
    return self;
}

- (long long)msgId {
    if (self.messagePtr != nullptr) {
        return (long long)self.messagePtr->msgId();
    }
    return 0;
}

- (long long)clientMsgId {
    if (self.messagePtr != nullptr) {
        return (long long)self.messagePtr->clientMsgId();
    }
    return 0;
}

- (void)setDeliverystatus:(BMXDeliveryStatus)deliverystatus {
    self.messagePtr->setDeliveryStatus((floo::BMXMessage::DeliveryStatus)deliverystatus);
}

- (void)setServerTimestamp:(long long)serverTimestamp {
    self.messagePtr->setServerTimestamp(serverTimestamp);
}

- (long long)clientTimestamp {
    if (self.messagePtr != nullptr) {
        return self.messagePtr->clientTimestamp();
    }
    return 0;
}

- (void)setClientTimestamp:(long long)clientTimestamp {
    self.messagePtr->setClientTimestamp(clientTimestamp);
}

- (void)setIsPlayed:(BOOL)isPlayed {
    bool tmp = isPlayed ? true : false;
    self.messagePtr->setIsPlayed(tmp);
}

- (void)setIsReceiveMsg:(BOOL)isReceiveMsg {
    bool tmp = isReceiveMsg ? true : false;
    self.messagePtr->setIsReceiveMsg(tmp);
}

- (void)setIsRead:(BOOL)isRead {
    bool tmp = isRead ? true : false;
    self.messagePtr->setIsRead(tmp);
}

- (void)setIsReadAcked:(BOOL)isReadAcked {
    bool tmp = isReadAcked ? true : false;
    self.messagePtr->setIsReadAcked(tmp);
}

-  (void)setIsDeliveryAcked:(BOOL)isDeliveryAcked{
    bool tmp = isDeliveryAcked ? true : false;
    self.messagePtr->setIsDeliveryAcked(tmp);
}

- (BMXMessageConfig *)messageconfig {
    floo::BMXMessageConfigPtr ptr = _messagePtr->config();
    if (ptr == nullptr) {
        return nil;
    }
    BMXMessageConfig *config = [[BMXMessageConfig alloc] initWithBMXMessageConfigPtr:ptr];
    return config;
}

- (void)setMessageconfig:(BMXMessageConfig *)messageconfig {
    self.messagePtr->setConfig([messageconfig getBMXMessageConfigPtr]);
}

- (BMXDeliveryStatus)deliverystatus {
    return (BMXDeliveryStatus)self.messagePtr->deliveryStatus();
}

- (BOOL)isDeliveryAcked {
    return (BOOL)self.messagePtr->isDeliveryAcked();
}

- (BOOL)isReadAcked {
    return (BOOL)self.messagePtr->isReadAcked();
}

- (BOOL)isRead {
    return (BOOL)self.messagePtr->isRead();
}

- (BOOL)isReceiveMsg {
    return (BOOL)self.messagePtr->isReceiveMsg();
}

- (BOOL)isPlayed {
    return (BOOL)self.messagePtr->isPlayed();
}

- (NSString *)senderName {
    if (self.messagePtr == nullptr) {
        return @"";
    }
    return [BMXStringUtil stdToNSString:self.messagePtr->senderName()];
}

- (void)setSenderName:(NSString *)senderName {
    self.messagePtr->setSenderName([BMXStringUtil toStdString:senderName]);
}


- (BMXContentType)contentType {
    return (BMXContentType)self.messagePtr->contentType();
}

- (NSString *)content {
    if (self.messagePtr == nullptr) {
        return @"";
    }
    return [BMXStringUtil stdToNSString:self.messagePtr->content()];
}

- (NSString *)extensionJson {
    if (self.messagePtr == nullptr) {
        return @"";
    }
    return [BMXStringUtil stdToNSString:self.messagePtr->extension()];
}

- (void)setExtensionJson:(NSString *)extensionJson {
    self.messagePtr->setExtension([BMXStringUtil toStdString:extensionJson]);
}

- (void)setQos:(DeliveryQosMode)qos{
    self.messagePtr->setDeliveryQos([BMXMessageObject oc_transformDeliveryQosMode:qos]);
}

- (long long)fromId {
    return (long long)self.messagePtr->fromId();
}

- (long long)serverTimestamp {
    if (self.messagePtr != nullptr) {
        return self.messagePtr->serverTimestamp();
    }
    return 0;
}

- (long long)conversationId {
    return self.messagePtr->conversationId();
}

- (long long)toId {
    return (long long)self.messagePtr->toId();
}

- (BMXMessageType)messageType {
    return (BMXMessageType)self.messagePtr->type();
}

- (int)groupAckCount {
    return self.messagePtr->groupAckCount();
}

@end


@implementation BMXMessageObject (Private)

- (instancetype)initWithMessagePtr:(floo::BMXMessagePtr)messagePtr {
    if (self = [super init]) {
        if (messagePtr) {
            _messagePtr = messagePtr;
            

            floo::BMXMessageAttachmentPtr attmentPtr = messagePtr->attachment();
            //transform
            if (messagePtr->contentType() == floo::BMXMessage::ContentType::Text  ) {//text message common message
                
                self.contentType = BMXContentTypeText;
                self.content =  [NSString stringWithUTF8String: messagePtr->content().c_str()];
            }
            else if ( messagePtr->contentType() == floo::BMXMessage::ContentType::Command) {
                self.contentType = BMXContentTypeCommand;
                self.content =  [NSString stringWithUTF8String: messagePtr->content().c_str()];
            }
            else if (messagePtr->contentType() == floo::BMXMessage::ContentType::Image) {//image message
                 self.contentType = BMXContentTypeImage;
                 self.content =  [NSString stringWithUTF8String: messagePtr->content().c_str()];
                _attachment = [[BMXImageAttachment alloc] initWithBMXMessageAttachment:attmentPtr];
            }
            else if (messagePtr->contentType() ==  floo::BMXMessage::ContentType::Video) {//video message
                self.contentType = BMXContentTypeVideo;
                self.content =  [NSString stringWithUTF8String: messagePtr->content().c_str()];
                _attachment = [[BMXVideoAttachment alloc] initWithBMXMessageAttachment:attmentPtr];
            }
            else if (messagePtr->contentType() ==  floo::BMXMessage::ContentType::Location) {//location message
                   self.contentType = BMXContentTypeLocation;
                self.content =  [NSString stringWithUTF8String: messagePtr->content().c_str()];
                _attachment = [[BMXLocationAttachment alloc] initWithBMXMessageAttachment:attmentPtr];
            }
            else if (messagePtr->contentType() ==  floo::BMXMessage::ContentType::Voice) {//voice message
                self.contentType = BMXContentTypeVoice;
                self.content = [NSString stringWithUTF8String: messagePtr->content().c_str()];
                _attachment = [[BMXVoiceAttachment alloc] initWithBMXMessageAttachment:attmentPtr];
            }
            else if (messagePtr->contentType() ==  floo::BMXMessage::ContentType::File) {//file message
                 self.contentType = BMXContentTypeFile;
                _attachment = [[BMXFileAttachment alloc] initWithBMXMessageAttachment:attmentPtr];
            }
            
        }
    }
    return self;

}

- (floo::BMXMessagePtr)getMessagePtr {
    return _messagePtr;
}

+ (floo::BMXMessage::DeliveryStatus)oc_transformBMXDeliveryStatus:(BMXDeliveryStatus)status {
    if (status == BMXDeliveryStatusNew) {
        return floo::BMXMessage::DeliveryStatus::New;
    } else if (status == BMXDeliveryStatusDelivering) {
        return floo::BMXMessage::DeliveryStatus::Delivering;
    } else {
        return floo::BMXMessage::DeliveryStatus::Deliveried;
    }
}

+ (floo::BMXMessage::DeliveryQos)oc_transformDeliveryQosMode:(DeliveryQosMode)status {
    if (status == DeliveryQosModeAtLastOnce) {
        return floo::BMXMessage::DeliveryQos::AtLastOnce;
    } else if (status == DeliveryQosModeAtMostOnce) {
        return floo::BMXMessage::DeliveryQos::AtMostOnce;
    } else {
        return floo::BMXMessage::DeliveryQos::ExactlyOnce;
    }
}

+ (BMXDeliveryStatus)transformDeliveryQosMode:(floo::BMXMessage::DeliveryStatus)status {
    if (status == floo::BMXMessage::DeliveryStatus::New) {
        return  BMXDeliveryStatusNew;
    } else if (status == floo::BMXMessage::DeliveryStatus::Delivering) {
        return BMXDeliveryStatusDelivering;
    } else {
        return BMXDeliveryStatusDeliveried;
    }
}

@end
