//----------------------------------------------------------------------
// File    : BMXConversationObject.m
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
#import "BMXStringUtil.h"
#include "bmx_file_attachment.h"
#import "BMXClient.h"
#include "bmx_image_attachment.h"


@interface BMXFileAttachment ()

@property (nonatomic,assign) floo::BMXFileAttachmentPtr core;

@end

@implementation BMXFileAttachment

- (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId {
    if (self = [super init]) {
        if (![path containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
            NSData *data = [NSData dataWithContentsOfFile:path];
            self = [self initWithData:data displayName:displayName conversationId:conversationId];
            
        }else {
            std::string pathString = path ? [path cStringUsingEncoding:NSUTF8StringEncoding] : "";
            std::string displayNameString = displayName ? [displayName cStringUsingEncoding:NSUTF8StringEncoding] : "";
            self.core = floo::BMXFileAttachmentPtr(new floo::BMXFileAttachment(pathString, displayNameString));
            
        }
        
    }
    return self;
}

- (instancetype)initWithData:(NSData *)aData
                 displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId {
    NSString *localPath = nil;
    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
    if ([aData length]) {
        NSString *dirName = [NSString stringWithFormat:@"%lld",time];
        NSString *dir = [self getLocalConversationId:conversationId fileName:dirName];
        localPath = [NSString stringWithFormat:@"%@/%@",dir,displayName];
        NSFileManager *fileManager = [NSFileManager defaultManager];
        [fileManager createDirectoryAtPath:dir withIntermediateDirectories:YES attributes:nil error:nil];
        [aData writeToFile:localPath atomically:YES];
    }
    self = [self initWithPath:localPath displayName:displayName conversationId:conversationId];
    return self;
}

- (NSString *)getLocalConversationId:(NSString *)conversationId
                            fileName:(NSString *)fileName {
    NSString *base = [[[BMXClient sharedClient] chatService] getAttachmentDir];
    NSString *path = [[[BMXClient sharedClient] chatService] getAttachmentDirForConversationWith:conversationId];
    return [base stringByAppendingPathComponent:[path stringByAppendingPathComponent:fileName]];
}

- (instancetype)initWithBMXMessageAttachment:(floo::BMXFileAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.core = attachmentPtr;
            NSString *path = [BMXStringUtil stdToNSString:self.core->path()];
            if (![path containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
                self.path = [[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:path];
            }
        }
    }
    return self;
}


- (NSString *)path {
    NSString *p = [BMXStringUtil stdToNSString:self.core->path()];
    if (![p containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
        return [[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
    }
    return p;
}


- (NSString *)displayName {
    return [BMXStringUtil stdToNSString:self.core->displayName()];
}

- (NSString *)url {
    return [BMXStringUtil stdToNSString:self.core->url()];
}

- (long long)fileLength {
    if (self.core != nullptr) {
        return (long long)self.core->fileLength();
    }
    return 0;
}

- (BMXAttachmentDownloadStatus)downLoadStatus {
    return (BMXAttachmentDownloadStatus)self.core->downloadStatus();
}

- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr {
    return _core;
}

- (floo::BMXFileAttachmentPtr)getCore {
    return _core;
}

@end
