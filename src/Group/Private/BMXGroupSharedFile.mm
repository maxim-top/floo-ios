//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupSharedFile.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/6 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXGroupSharedFile.h"
#import "BMXGroupSharedFile+Private.h"
#import "BMXStringUtil.h"
#include "bmx_group.h"

@interface BMXGroupSharedFile ()

@property (nonatomic,assign) floo::BMXGroup::SharedFilePtr ptr;


@end

@implementation BMXGroupSharedFile

- (long long)fileId {
    if (_ptr != nullptr) {
        return (int64_t)_ptr->mFileId;
    }
    return 0;
}

- (long long)groupId {
    if (_ptr != nullptr) {
        return (int64_t)_ptr->mGroupId;
    }
    return 0;
}

- (long long)upLoader {
    if (_ptr != nullptr) {
        return (int64_t)_ptr->mUploader;
    }
    return 0;
}

- (int)fileSize {
    if (_ptr != nullptr) {
        return (int)_ptr->mSize;
    }
    return 0;
}

- (long long)createTime {
    if (_ptr != nullptr) {
        return (int64_t)_ptr->mCreateTime;
    }
    return 0;
}

- (long long)updateTime {
    if (_ptr != nullptr) {
        return (int64_t)_ptr->mUpdateTime;
    }
    return 0;
}


- (NSString *)url {
    if (_ptr != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->mUrl];
    }
    return nil;
}

- (NSString *)displayName {
    if (_ptr != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->mDisplayName];
    }
    return nil;
}

- (NSString *)path {
    if (_ptr != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->mPath];
    }
    return nil;
}

- (NSString *)type {
    if (_ptr != nullptr) {
        return [BMXStringUtil stdToNSString:_ptr->mType];
    }
    return nil;
}



@end

@implementation BMXGroupSharedFile (Private)

- (floo::BMXGroup::SharedFilePtr)getGroupSharedFilePtr {
    return _ptr;
}

- (instancetype)initWithBMXGroupSharedFilePtr:(floo::BMXGroup::SharedFilePtr)sharedFilePtr {
    if (self = [super init]) {
        _ptr = sharedFilePtr;
    }
    return self;

}

@end
