//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupBannedMember.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/24 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMXGroupBannedMember : NSObject

@property (nonatomic, readonly) NSInteger uid;
@property (nonatomic, copy, readonly) NSString *groupNickname;
@property (nonatomic, readonly) long long createTime;
@property (nonatomic, readonly) long long expiredTime;


@end

NS_ASSUME_NONNULL_END
