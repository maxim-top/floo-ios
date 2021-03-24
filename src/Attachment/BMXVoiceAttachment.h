// ----------------------------------------------------------------------
// File    : BMXVoiceAttachment.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/21 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXFileAttachment.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXVoiceAttachment : BMXFileAttachment

/**
 时长
 */
@property (nonatomic,assign) int duration;







/**
 初始化BMXFileAttachment

 @param path 音频路径
 @param displayName 显示
 @param duration 时长
 @return BMXFileAttachment
 */
- (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
                    duration:(NSInteger)duration
              conversationId:(NSString *)conversationId;


   

/// 初始化BMXFileAttachment
/// @param aData 音频Data
/// @param displayName 显示名称
/// @param duration 时长
/// @param conversationId 会话Id
- (instancetype)initWithData:(NSData *)aData
                 displayName:(NSString *)displayName
                  fileLength:(NSInteger)fileLength
                    duration:(NSInteger)duration
              conversationId:(NSString *)conversationId;


@end

NS_ASSUME_NONNULL_END
