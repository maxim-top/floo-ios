// ----------------------------------------------------------------------
// File    : BMXVideoAttachment.h
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

//#import <Foundation/Foundation.h>
#import "BMXFileAttachment.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXVideoAttachment : BMXFileAttachment

/**
 video大小
 */
@property (nonatomic) CGSize videoSize;

/**
 时长
 */
@property (nonatomic,assign) int duration;

/**
 缩略图路径
 */
@property (nonatomic,copy) NSString *thumbnailPath;

/**
 缩略图url
 */
@property (nonatomic,copy) NSString *thumbnailUrl;


/**
 thumbnail文件大小
 */
@property (nonatomic) long long thumbnailFileLength;

/**
 视频下载状态
 */
@property (nonatomic,assign) BMXAttachmentDownloadStatus thumbnaildownLoadStatus;


- (instancetype)initWithData:(NSData *)aData
                    duration:(int)duration
                   videoSize:(CGSize)videoSize
                 displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId;

- (instancetype)initWithData:(NSData *)aData
                    duration:(int)duration
                   videoSize:(CGSize)videoSize
                 displayName:(NSString *)displayName
               thumbnailData:(NSData *)thumbnailData
              conversationId:(NSString *)conversationId;

- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                         duration:(int)duration
                             size:(CGSize)size
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId;

- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                         duration:(int)duration
                             size:(CGSize)size
                    thumbnailPath:(NSString *)thumbnailPath
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId;


@end

NS_ASSUME_NONNULL_END
