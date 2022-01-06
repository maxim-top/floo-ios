// ----------------------------------------------------------------------
// File    : BMXMessage.h
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


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BMXMessageAttachment;
@class BMXMessageConfig;


typedef enum {
    BMXDeliveryStatusNew = 0,    // 新创建消息
    BMXDeliveryStatusDelivering, // 消息投递中
    BMXDeliveryStatusDeliveried, // 消息已投递
    BMXDeliveryStatusFailed,      // 消息投递失败
    BMXDeliveryStatusRecalled     //消息已撤回
} BMXDeliveryStatus;

typedef enum {
    BMXContentTypeText = 0,
    BMXContentTypeImage,
    BMXContentTypeVoice,
    BMXContentTypeVideo,
    BMXContentTypeFile,
    BMXContentTypeLocation,
    BMXContentTypeCommand,
    BMXContentTypeForward,
}BMXContentType;

typedef enum {
    DeliveryQosModeAtLastOnce = 0, // 最少投递一次
    DeliveryQosModeAtMostOnce, // 最多投递一次
    DeliveryQosModeExactlyOnce, // 仅投递一次
} DeliveryQosMode;


typedef enum {
    BMXMessageTypeSingle = 0, // 单聊消息
    BMXMessageTypeGroup, // 群聊消息
    BMXMessageTypeSystem, //系统消息
}BMXMessageType;

@interface BMXMessageObject : NSObject


@property (nonatomic, assign, readonly) long long msgId;

@property (nonatomic, assign, readonly) long long clientMsgId;

@property (nonatomic, assign, readonly) long long fromId;

@property (nonatomic, assign, readonly) long long toId;

@property (nonatomic, assign) long long conversationId;

@property (nonatomic, assign) BMXDeliveryStatus deliverystatus;

@property (nonatomic, assign) DeliveryQosMode qos;

@property (nonatomic, assign, readonly) BMXMessageType messageType;

@property (nonatomic, assign, readonly) long long serverTimestamp;

@property (nonatomic, assign) long long clientTimestamp;

@property (nonatomic, assign) BOOL isPlayed;

@property (nonatomic, assign) BOOL isReceiveMsg;
//全部消息是否已读
@property (nonatomic,assign) BOOL isRead;
//接受消息是否发送已读回执
@property (nonatomic,assign) BOOL isReadAcked;
//接受消息是否发送已送达
@property (nonatomic, assign) BOOL isDeliveryAcked;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, strong) BMXMessageConfig *messageconfig;

@property (nonatomic, copy) NSString *extensionJson;

@property (nonatomic, assign) BMXContentType contentType;

@property (nonatomic,copy) NSString *senderName;

//消息是否存在groupAck,在发送群组消息且需要群组成员发送已读回执的时候需要设置为true。
//@property (nonatomic,assign) BOOL enableGroupAck;

//群消息AckCount数目
@property (nonatomic,assign) int groupAckCount;

@property (nonatomic, strong, readonly) BMXMessageAttachment *attachment;


/**
 创建文本消息

 @param content 内容
 @param fromId 发送id
 @param toId 接收id
 @param mtype 消息类型
 @param conversationId 会话id
 @return BMXMessageObject
 */
- (instancetype)initWithBMXMessageText:(NSString *)content
                                fromId:(long long )fromId
                                  toId:(long long)toId
                                  type:(BMXMessageType)mtype
                        conversationId:(long long )conversationId;

/// 创建发送命令消息(命令消息通过content字段或者extension字段存放命令信息)
/// @param content 消息内容
/// @param fromId 消息发送者
/// @param toId 消息接收者
/// @param mtype 消息类型
/// @param conversationId 会话id
- (instancetype)initWithBMXCommandMessageText:(NSString *)content
                                       fromId:(long long )fromId
                                         toId:(long long)toId
                                         type:(BMXMessageType)mtype
                               conversationId:(long long )conversationId;

/**
 创建附件消息

 @param attachment BMXMessageAttachment
 @param fromId 发送id
 @param toId 接收id
 @param mtype 消息类型
 @param conversationId 会话id
 @return BMXMessageObject
 */
- (instancetype)initWithBMXMessageAttachment:(BMXMessageAttachment *)attachment
                                      fromId:(long long )fromId
                                        toId:(long long)toId
                                        type:(BMXMessageType)mtype
                              conversationId:(long long )conversationId;


/**
 创建接收文本消息

 @param content 内容
 @param msgId 消息id
 @param fromId 发送id
 @param toId 接收id
 @param mtype 消息类型
 @param conversationId 会话id
 @param timeStamp 时间戳
 @return BMXMessageObject
 */
- (instancetype)initWithRecieveBMXMessageText:(NSString *)content
                                        msgId:(long long)msgId
                                       fromId:(long long )fromId
                                         toId:(long long)toId
                                         type:(BMXMessageType)mtype
                               conversationId:(long long )conversationId
                                    timeStamp:(long long)timeStamp;



/// 创建收到的命令消息(命令消息通过content字段或者extension字段存放命令信息)
/// @param content 消息内容
/// @param msgId 消息id
/// @param fromId 消息发送者
/// @param toId 消息接收者
/// @param mtype 消息类型
/// @param conversationId 会话id
/// @param timeStamp 服务器时间戳
- (instancetype)initWithRecieveBMXMessageCommandMessageText:(NSString *)content
                                                       msgId:(long long)msgId
                                                                fromId:(long long )fromId
                                                                  toId:(long long)toId
                                                                  type:(BMXMessageType)mtype
                                                        conversationId:(long long )conversationId
                                                             timeStamp:(long long)timeStamp;

                                                         




/**
 创建接收附件消息

 @param attachment BMXMessageAttachment
 @param msgId 消息id
 @param fromId 发送id
 @param toId 接收id
 @param mtype 消息类型
 @param conversationId 会话id
 @param timeStamp 时间戳
 @return BMXMessageObject
 */
- (instancetype)initWithRecieveBMXMessageAttachment:(BMXMessageAttachment *)attachment
                                              msgId:(long long)msgId
                                             fromId:(long long )fromId
                                               toId:(long long)toId
                                               type:(BMXMessageType)mtype
                                     conversationId:(long long )conversationId
                                          timeStamp:(long long)timeStamp;


/**
 创建转发消息

 @param message BMXMessageObject
 @param fromId 发送id
 @param toId 接收id
 @param mtype 消息类型
 @param conversationId 会话id
 @return BMXMessageObject
 */
- (instancetype)initWithForwardMessage:(BMXMessageObject *)message
                                fromId:(long long )fromId
                                  toId:(long long)toId
                                  type:(BMXMessageType)mtype
                        conversationId:(long long )conversationId;




@end

NS_ASSUME_NONNULL_END
