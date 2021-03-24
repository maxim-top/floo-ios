// ----------------------------------------------------------------------
// File    : BMXVoiceAttachment.m
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

#import "BMXVoiceAttachment.h"
#import "BMXStringUtil.h"
#import "BMXClient.h"
#include "bmx_voice_attachment.h"
@interface BMXVoiceAttachment ()

@property (nonatomic,assign) floo::BMXVoiceAttachmentPtr ptr;

@end

@implementation BMXVoiceAttachment

- (instancetype)initWithData:(NSData *)aData
                 displayName:(NSString *)displayName
                  fileLength:(NSInteger)fileLength
                    duration:(NSInteger)duration
              conversationId:(NSString *)conversationId {
    
    NSString *localPath = nil;
    long long time = [[NSDate date] timeIntervalSince1970] * 1000;
    NSString *fileName = [NSString stringWithFormat:@"%lld",time];
    if ([aData length]) {
        localPath = [self getLocalConversationId:conversationId fileName:fileName];
        [aData writeToFile:localPath atomically:YES];
    }
    self = [self initWithPath:localPath displayName:displayName duration:duration conversationId:conversationId];
    return self;
}

- (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
                    duration:(NSInteger)duration
              conversationId:(NSString *)conversationId {
    if (self = [self init]) {
        
        if (![path containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
            NSData *data = [NSData dataWithContentsOfFile:path];
            self = [self initWithData:data displayName:displayName fileLength:data.length duration:duration conversationId:conversationId];
        } else {
            self.ptr = floo::BMXVoiceAttachmentPtr(new floo::BMXVoiceAttachment([BMXStringUtil toStdString:path], (int)duration,
                                                                            [BMXStringUtil toStdString:displayName]));
        }
    }
    return self;
}

- (NSString *)getLocalConversationId:(NSString *)conversationId
                            fileName:(NSString *)fileName {
    
    NSString *base = [[[BMXClient sharedClient] chatService] getAttachmentDir];
    NSString *path = [[[BMXClient sharedClient] chatService] getAttachmentDirForConversationWith:conversationId];
    return [base stringByAppendingPathComponent:[path stringByAppendingPathComponent:fileName]];
    
}

- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr {
    return _ptr;
}

- (NSString *)url {
    if (_ptr) {
        return [BMXStringUtil stdToNSString:self.ptr->url()];
    }
    return @"";
}

- (NSString *)displayName {
    if (_ptr) {
        return [BMXStringUtil stdToNSString:self.ptr->displayName()];
    }
    return @"";
}

- (long long)fileLength {
    if (_ptr) {
        return (long long)self.ptr->fileLength();
    }
    return 0;
}

- (BMXAttachmentDownloadStatus)downLoadStatus {
    return (BMXAttachmentDownloadStatus)self.ptr->downloadStatus();
}

- (int)duration {
    return self.ptr->duration();
}

- (NSString *)path {
    NSString *p = [BMXStringUtil stdToNSString:self.ptr->path()];
    if (![p containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
       return[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
    }
    return p;
}

- (instancetype)initWithBMXMessageAttachment:(floo::BMXVoiceAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.ptr = attachmentPtr;
            NSString *path = [BMXStringUtil stdToNSString:self.ptr->path()];
               if (![path containsString:[BMXClient sharedClient].chatService.getAttachmentDir]) {
                  path  = [[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:path];
               }
            [self setPath:path];
            
        }
    }
    return self;
    
}

@end
