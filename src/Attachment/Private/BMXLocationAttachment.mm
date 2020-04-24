//
//  BMXLocationAttachment.m
//  MaxIM
//
//  Created by hyt on 2018/11/17.
//  Copyright © 2018年 hyt. All rights reserved.
//

#import "BMXLocationAttachment.h"
#import "BMXMessageAttachment.h"
#include "bmx_location_attachment.h"


@interface BMXLocationAttachment ()

@property (nonatomic,assign) floo::BMXLocationAttachmentPtr core;

@end

@implementation BMXLocationAttachment

- (instancetype)initWithLatitude:(double)aLatitude
                       longitude:(double)aLongitude
                         address:(NSString *)aAddress {
    if (self = [super init]) {
        std::string string = aAddress ? [aAddress cStringUsingEncoding:NSUTF8StringEncoding] : "";
        self.core  = floo::BMXLocationAttachmentPtr(new floo::BMXLocationAttachment(aLatitude, aLongitude, string));
    }
    return self;
}
#pragma mark - getter
- (BMXAttachmentType)type{
    return BMXMessageAttactmentTypeLocation;
}

- (double)latitude {
    return self.core ->latitude();
}

- (double)longitude {
    return self.core ->longitude();
}

- (NSString *)address {
    return [NSString stringWithUTF8String:self.core ->address().c_str()];
}

- (floo::BMXLocationAttachmentPtr)getCore  {
    return self.core ;
}

- (floo::BMXLocationAttachmentPtr)getMessageAttachmentPtr {
    
    return self.core;
}

- (instancetype)initWithBMXMessageAttachment:(floo::BMXLocationAttachmentPtr)attachmentPtr {
    if (self = [super init]) {
        if (attachmentPtr) {
            self.core = attachmentPtr;
        }
    }
    return self;
    
}

@end
