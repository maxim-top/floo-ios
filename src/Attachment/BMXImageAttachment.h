// ----------------------------------------------------------------------
// File    : BMXImageAttachment.h
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

#import "BMXFileAttachment.h"

@interface BMXImageAttachment : BMXFileAttachment

@property (nonatomic,copy) NSString *thumbnailPath;
@property (nonatomic,assign)  long long thumbnailFileLength;
@property (nonatomic) CGSize thumbnailSize;
@property (nonatomic) CGSize pictureSize;

@property (nonatomic,assign) BMXAttachmentDownloadStatus thumbnailDownLoadStatus;

- (instancetype)initWithData:(NSData *)aData
               thumbnailData:(NSData *)aThumbnailData
                   imageSize:(CGSize)imageSize
              conversationId:(NSString *)conversationId;

- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                    thumbnailPath:(NSString *)aThumbnailPath
                             size:(CGSize)size
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId;
/**
 * 设置接收图片消息缩略图
 **/
- (void)setReceiveThumbnailUrl:(NSString *)url
                 thumbnailSize:(CGSize)thumbnailSize
                    fileLength:(long long)fileLength;

/**
 * 设置发送图片消息缩略图
 **/
- (void)setsendThumbnailPath:(NSString *)path;


@end

 
