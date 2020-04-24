
//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupAnnounment.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/30 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupAnnounment.h"
#include "bmx_group.h"
#import "BMXStringUtil.h"

@interface BMXGroupAnnounment ()

@property (nonatomic, assign) floo::BMXGroup::AnnouncementPtr ptr;

@end

@implementation BMXGroupAnnounment

- (instancetype)init {
    return nil;
}

//@property (nonatomic,copy) NSString *groupId;
//@property (nonatomic,copy) NSString *tittle;
//@property (nonatomic,copy) NSString *promulgator;
//@property (nonatomic,copy) NSString *createTime;

- (long long)groupId {
    if (_ptr.get()) {
        return _ptr->mId;
    }
    return 0;
}

- (NSString *)tittle {
    if (_ptr.get()) {
        return [BMXStringUtil stdToNSString:_ptr->mTitle];
    }
    return nil;
}

- (long long)author {
    if (_ptr.get()) {
        return _ptr->mAuthor;
    }
    return 0;
}

- (long long)createTime {
    if (_ptr.get()) {
        return _ptr->mCreateTime;
    }
    return 0;
}

- (NSString *)content {
    if (_ptr.get()) {
        return [BMXStringUtil stdToNSString:_ptr->mContent];
    }
    return nil;
}



@end


@implementation BMXGroupAnnounment (Private)
- (instancetype)initWithBMXGroupAnnounmentPtr:(floo::BMXGroup::AnnouncementPtr)announcementPtr {
    
    if (self = [super init]) {
        _ptr = announcementPtr;
    }
    return self;
    
}
- (floo::BMXGroup::AnnouncementPtr)getannouncementPtr {
    return _ptr;
}


@end
