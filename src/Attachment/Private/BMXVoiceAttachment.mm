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

- (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
                    duration:(NSInteger)duration {
    if (self = [self init]) {
        self.ptr = floo::BMXVoiceAttachmentPtr(new floo::BMXVoiceAttachment([BMXStringUtil toStdString:path], (int)duration,
                                                                            [BMXStringUtil toStdString:displayName]));
    }
    return self;
}


- (instancetype)initWithUrlStr:(NSString *)url
                   displayName:(NSString *)displayName
                    fileLength:(NSInteger)fileLength
                      duration:(NSInteger)duration {
    
    if (self = [super initWithUrlStr:url displayName:displayName fileLength:fileLength]) {
        self.ptr = floo::BMXVoiceAttachmentPtr(new floo::BMXVoiceAttachment([BMXStringUtil toStdString:url], (int)duration,
                                                                            [BMXStringUtil toStdString:displayName], (int64_t)fileLength));
    }
    return self;
}

- (floo::BMXMessageAttachmentPtr)getMessageAttachmentPtr {
    return _ptr;
}


- (int)duration {
    return self.ptr->duration();
}

- (NSString *)path {
    NSString *p = [BMXStringUtil stdToNSString:self.ptr->path()];
    if (![p containsString:@"Documents/ChatData"]) {
       return[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:p];
    }
    return p;
}

- (instancetype)initWithBMXMessageAttachment:(floo::BMXVoiceAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.ptr = attachmentPtr;
            [self setPath:[[BMXClient sharedClient].chatService.getAttachmentDir stringByAppendingPathComponent:[BMXStringUtil stdToNSString:_ptr->path()]]];
            
        }
    }
    return self;
    
}

@end
