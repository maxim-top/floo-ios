//
//  ----------------------------------------------------------------------
//   File    :  BMXHostConfig.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/4 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

@interface BMXHostConfig : NSObject

@property (nonatomic,copy) NSString *imHost;
@property (nonatomic,assign) int mPort;
@property (nonatomic,copy) NSString *restHost;

- (instancetype)initWithRestHostConfig:(NSString *)restHost imPort:(int)imPort imHost:(NSString *)imHost;

@end
