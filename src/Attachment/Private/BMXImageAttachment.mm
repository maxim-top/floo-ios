// ----------------------------------------------------------------------
// File    : BMXImageAttachment.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/20 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXImageAttachment.h"
#import "BMXMessageAttachment+Private.h"
#import "BMXClient.h"
#import "BMXStringUtil.h"
#import "BMXChatService+Private.h"
#include "bmx_image_attachment.h"
#include "bmx_client.h"
#include "bmx_chat_service.h"

@interface BMXImageAttachment ()

@property (nonatomic,assign) floo::BMXImageAttachmentPtr imageAttachmentPtr;

@end

@implementation BMXImageAttachment

- (instancetype)initWithData:(NSData *)aData
               thumbnailData:(NSData *)aThumbnailData
                        imageSize:(CGSize)imageSize
              conversationId:(NSString *)conversationId {
    
    
    NSString *localPath = nil;
    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
    NSString *fileName = [NSString stringWithFormat:@"%lld",time];
    if ([aData length]) {
        localPath = [self getLocalConversationId:conversationId fileName:fileName];
        [aData writeToFile:localPath atomically:YES];
    }
    
    self = [self initWithLocalPath:localPath thumbnailPath:@"" size:imageSize displayName:nil conversationId:conversationId];

    if (self) {
        if (aThumbnailData.length > 0) {
            NSString *thumbnailPath = [self getLocalConversationId:conversationId fileName:[NSString stringWithFormat:@"thumb_%@",fileName]];
            [aThumbnailData writeToFile:thumbnailPath atomically:YES];
            [self setsendThumbnailPath:thumbnailPath];
        }
    }
    
    
    return self;
}

- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                    thumbnailPath:(NSString *)aThumbnailPath
                             size:(CGSize)size
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId {
    self = [super init];
    if (self) {
//
        if (![aLocalPath containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
            NSData *data = [NSData dataWithContentsOfFile:aLocalPath];
            self = [self initWithData:data thumbnailData:nil imageSize:size conversationId:conversationId];
        } else {
        floo::BMXImageAttachment::Size tSize;
        tSize.mWidth = size.width;
        tSize.mHeight = size.height;
        self.imageAttachmentPtr = floo::BMXImageAttachmentPtr(new floo::BMXImageAttachment([aLocalPath UTF8String],tSize,[BMXStringUtil toStdString:aDisplayName]));
        }
        if (aThumbnailPath.length > 0) {
            if (![aLocalPath containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
                long long time = [[NSDate date] timeIntervalSince1970] * 1000;
                NSString *fileName = [NSString stringWithFormat:@"%lld",time];
                NSData *data = [NSData dataWithContentsOfFile:aThumbnailPath];
                NSString *thumbnailPath = [self getLocalConversationId:conversationId fileName:[NSString stringWithFormat:@"thumb_%@",fileName]];
                [data writeToFile:thumbnailPath atomically:YES];
                [self setsendThumbnailPath:thumbnailPath];
            }else {
                [self setsendThumbnailPath:aThumbnailPath];
            }
            
        }
//        [self setThumbnailPath:[BMXStringUtil stdToNSString:self.imageAttachmentPtr->thumbnailPath()]];
    }
    
    return self;
}



- (NSString *)getLocalConversationId:(NSString *)conversationId
                            fileName:(NSString *)fileName {
    
    NSString *base = [[[BMXClient sharedClient] chatService] getAttachmentDir];
    NSString *path = [[[BMXClient sharedClient] chatService] getAttachmentDirForConversationWith:conversationId];
    return [base stringByAppendingPathComponent:[path stringByAppendingPathComponent:fileName]];
}

- (NSString *)url {
    return [BMXStringUtil stdToNSString:self.imageAttachmentPtr->url()];
}


/**
 * 设置发送图片消息缩略图
 **/
- (void)setsendThumbnailPath:(NSString *)path {
    std::string pathStr = path ? [path cStringUsingEncoding:NSUTF8StringEncoding] : "";
    self.imageAttachmentPtr -> setThumbnail(pathStr);
    self.thumbnailPath = path;
}

/**
 * 设置接收图片消息缩略图
 **/
- (void)setReceiveThumbnailUrl:(NSString *)url
                 thumbnailSize:(CGSize)thumbnailSize
                    fileLength:(long long)fileLength {
    
    std::string urlStr = url ? [url cStringUsingEncoding:NSUTF8StringEncoding] : "";
    
//    self.imageAttachmentPtr -> setThumbnail(urlStr);
    self.thumbnailPath = url;
    
}

#pragma mark - getter
- (CGSize)pictureSize {
    return CGSizeMake(self.imageAttachmentPtr->size().mWidth, self.imageAttachmentPtr->size().mHeight);
}

- (BMXAttachmentDownloadStatus)thumbnailDownLoadStatus {
    return (BMXAttachmentDownloadStatus)self.imageAttachmentPtr -> downloadStatus();
}


- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr {
    return _imageAttachmentPtr;
}

- (NSString *)path {
    NSString *p = [BMXStringUtil stdToNSString:self.imageAttachmentPtr->path()];
    if (![p containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
        return [[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
    }
    return p;
}


- (NSString *)displayName {
    if (_imageAttachmentPtr) {
        return [BMXStringUtil stdToNSString:self.imageAttachmentPtr->displayName()];
    }
    return @"";
}

- (long long)fileLength {
    if (_imageAttachmentPtr) {
        return (long long)self.imageAttachmentPtr->fileLength();
    }
    return 0;
}

- (BMXAttachmentDownloadStatus)downLoadStatus {
    return (BMXAttachmentDownloadStatus)self.imageAttachmentPtr->downloadStatus();
}


//- (NSString *)thumbnailPath {
//
//    return [BMXStringUtil stdToNSString:_imageAttachmentPtr->thumbnailPath()];
//}


- (instancetype)initWithBMXMessageAttachment:(floo::BMXImageAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.imageAttachmentPtr = attachmentPtr;
            NSString *path = [BMXStringUtil stdToNSString:self.imageAttachmentPtr->thumbnailPath()];
            if (![path containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
                [self setReceiveThumbnailUrl:[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:path] thumbnailSize:[self pictureSize] fileLength:100];
            }else {
                
                 [self setReceiveThumbnailUrl:path thumbnailSize:[self pictureSize] fileLength:100];
                
            }
            
            
        }
    }
    return self;
    
}

#pragma mark - setter
//- (void)setPictureSize:(CGSize)pictureSize{
//    self.core->set
//}


@end
