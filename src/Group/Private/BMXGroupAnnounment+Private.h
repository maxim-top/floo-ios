//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupAnnounment+Private.h
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

NS_ASSUME_NONNULL_BEGIN

@interface BMXGroupAnnounment (Private)

- (instancetype)initWithBMXGroupAnnounmentPtr:(floo::BMXGroup::AnnouncementPtr)announcementPtr;
- (floo::BMXGroup::AnnouncementPtr)getannouncementPtr;

@end

NS_ASSUME_NONNULL_END
