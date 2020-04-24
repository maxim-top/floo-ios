//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupAnnounment.h
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
    

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMXGroupAnnounment : NSObject

@property (nonatomic,assign) long long groupId;
@property (nonatomic,copy) NSString *tittle;
@property (nonatomic,assign) long long author;
@property (nonatomic,assign) long long createTime;
@property (nonatomic,copy) NSString *content;


@end

NS_ASSUME_NONNULL_END
