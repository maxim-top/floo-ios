//
//  ----------------------------------------------------------------------
//   File    :  BMXApplicationList.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2018/12/22 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

typedef enum {
    BMXApplicationStatusPending, //请求待处理
    BMXApplicationStatusAccepted, //请求已接受
    BMXApplicationStatusDeclined, //请求已拒绝
}BMXApplicationStatus;

@interface BMXApplication : NSObject

@property (nonatomic,assign) long long rosterId;
@property (nonatomic,copy) NSString *reason;
@property (nonatomic,assign) BMXApplicationStatus applicationStatus;
@property (nonatomic, assign) long long expireTime;

@end

