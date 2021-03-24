// ----------------------------------------------------------------------
// File    : BMXVideoAttachment.m
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

#import "BMXVideoAttachment.h"
#import "BMXMessageAttachment+Private.h"
#include "bmx_video_attachment.h"
#import "BMXStringUtil.h"
#import "BMXClient.h"
//#import <AVFoundation/AVFoundation.h>
//#import <CoreServices/CoreServices.h>

@interface BMXVideoAttachment ()

@property (nonatomic) floo::BMXVideoAttachmentPtr core;

@end


@implementation BMXVideoAttachment

- (instancetype)initWithData:(NSData *)aData
                    duration:(int)duration
                   videoSize:(CGSize)videoSize
                 displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId {
    
    NSString *localPath = nil;
    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
    NSString *fileName = [NSString stringWithFormat:@"%lld",time];
    if ([aData length]) {
        localPath = [self getLocalConversationId:conversationId fileName:fileName];
        [aData writeToFile:localPath atomically:YES];
    }
    
    self = [self initWithLocalPath:localPath duration:duration size:videoSize  displayName:displayName conversationId:conversationId];
    if (self) {
        //TODO
        //NSString *thumbnailPath = [self getLocalConversationId:conversationId fileName:[NSString stringWithFormat:@"thumb_%@",fileName]];
        //[aThumbnailData writeToFile:thumbnailPath atomically:YES];
        //[self setsendThumbnailPath:thumbnailPath];
    }
    
    return self;
}


- (instancetype)initWithData:(NSData *)aData
                    duration:(int)duration
                   videoSize:(CGSize)videoSize
                 displayName:(NSString *)displayName
               thumbnailData:(NSData *)thumbnailData
              conversationId:(NSString *)conversationId {
    NSString *localPath = nil;
    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
    NSString *fileName = [NSString stringWithFormat:@"%lld",time];
    if ([aData length]) {
        localPath = [self getLocalConversationId:conversationId fileName:fileName];
        [aData writeToFile:localPath atomically:YES];
    }
    
    NSString *athumbnailPath;
    if ([thumbnailData length]) {
        athumbnailPath = [self getLocalConversationId:conversationId fileName:[NSString stringWithFormat:@"thumb_%@",fileName]];
        [thumbnailData writeToFile:athumbnailPath atomically:YES];
    }
    self = [self initWithLocalPath:localPath duration:duration size:videoSize thumbnailPath:athumbnailPath displayName:displayName conversationId:conversationId];
    
    
    return self;
}

- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                         duration:(int)duration
                             size:(CGSize)size
                    thumbnailPath:(NSString *)thumbnailPath
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId {
    self = [super init];
    if (self) {
        
        if (![aLocalPath containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
            NSData *data = [NSData dataWithContentsOfFile:aLocalPath];
            self = [self initWithData:data duration:duration videoSize:size displayName:aDisplayName conversationId:conversationId];
            if (thumbnailPath.length > 0) {
                if (![thumbnailPath containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
                    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
                    NSString *fileName = [NSString stringWithFormat:@"%lld",time];
                    NSData *data = [NSData dataWithContentsOfFile:thumbnailPath];
                    NSString *thumbnailPath = [self getLocalConversationId:conversationId fileName:[NSString stringWithFormat:@"thumb_%@",fileName]];
                    [data writeToFile:thumbnailPath atomically:YES];
                    [self setsendThumbnailPath:thumbnailPath];
                } else  {
                    [self setsendThumbnailPath:thumbnailPath];
                }
            }
        }else {
            
            floo::BMXVideoAttachment::Size tSize;
            tSize.mWidth = size.width;
            tSize.mHeight = size.height;
            self.core = floo::BMXVideoAttachmentPtr(new floo::BMXVideoAttachment([BMXStringUtil toStdString:aLocalPath],[BMXStringUtil toStdString:thumbnailPath],duration,tSize,[BMXStringUtil toStdString:aDisplayName]));
        }
        
    }
    return self;
}


- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                         duration:(int)duration
                             size:(CGSize)size
                      displayName:(NSString *)aDisplayName
                   conversationId:(NSString *)conversationId{
    self = [super init];
    if (self) {
        
        if (![aLocalPath containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
            NSData *data = [NSData dataWithContentsOfFile:aLocalPath];
            self = [self initWithData:data duration:duration videoSize:size displayName:aDisplayName conversationId:conversationId];
        }else  {
            floo::BMXVideoAttachment::Size tSize;
            tSize.mWidth = size.width;
            tSize.mHeight = size.height;
            self.core = floo::BMXVideoAttachmentPtr(new floo::BMXVideoAttachment([BMXStringUtil toStdString:aLocalPath],duration,tSize,[BMXStringUtil toStdString:aDisplayName]));
        }
    }
    
    return self;
}

- (instancetype)initWithBMXMessageAttachment:(floo::BMXVideoAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.core = attachmentPtr;
            [self setPath:[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:[BMXStringUtil stdToNSString:_core->path()]]];
            
        }
    }
    return self;
    
}

- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr {
    return _core;
}

/**
 * 设置发送图片消息缩略图
 **/
- (void)setsendThumbnailPath:(NSString *)path {
    self.core -> setThumbnail([BMXStringUtil toStdString:path]);
    self.thumbnailPath = path;
}

- (NSString *)getLocalConversationId:(NSString *)conversationId
                            fileName:(NSString *)fileName {
    
    NSString *base = [[[BMXClient sharedClient] chatService] getAttachmentDir];
    NSString *path = [[[BMXClient sharedClient] chatService] getAttachmentDirForConversationWith:conversationId];
    return [base stringByAppendingPathComponent:[path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.mp4",fileName]]];
}


- (NSString *)path {
    NSString *p = [BMXStringUtil stdToNSString:self.core->path()];
    if (![p containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
        return[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
    }
    return p;
}
#pragma mark - getter
- (CGSize)videoSize {
    return CGSizeMake(self.core->size().mWidth, self.core->size().mHeight);
}

- (NSString *)url {
    if (_core) {
        return [BMXStringUtil stdToNSString:self.core->url()];
    }
    return @"";
}

- (NSString *)displayName {
    if (_core) {
        return [BMXStringUtil stdToNSString:self.core->displayName()];
    }
    return @"";
}

- (long long)fileLength {
    if (_core) {
        return (long long)self.core->fileLength();
    }
    return 0;
}

- (BMXAttachmentDownloadStatus)downLoadStatus {
    return (BMXAttachmentDownloadStatus)self.core->downloadStatus();
}

- (int)duration {
    return self.core->duration();
}

- (NSString *)thumbnailPath {
    NSString *p = [BMXStringUtil stdToNSString:self.core->thumbnailPath()];
    if (![p containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
        return[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
        //        MAXLog(@"%@", [[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p]);
    }
    return p;
}

- (BMXAttachmentDownloadStatus)thumbnaildownLoadStatus {
    return (BMXAttachmentDownloadStatus)self.core->thumbnailDownloadStatus();
}

//#pragma mark - setter
//- (void)setThumbnailPath:(NSString *)thumbnailPath {
//    self.core->setThumbnail([BMXStringUtil toStdString:thumbnailPath]);
//}

@end
