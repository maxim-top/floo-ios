//
//  ----------------------------------------------------------------------
//   File    :  BMXMessageSetting.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/3 by HYT yutong@bmxlabs.com
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

@interface BMXMessageSetting : NSObject


/**
 推送开关
 */
@property (nonatomic,assign, readonly) BOOL mPushEnabled;

/**
 推送详情
 */
@property (nonatomic,assign, readonly) BOOL mPushDetail;

/**
 对方收到推送消息时显示的名称
 */
@property (nonatomic,copy) NSString *pushNickname;

/**
 推送声音
 */
@property (nonatomic,assign, readonly) BOOL mNotificationSound;

/**
 推送通知震动
 */
@property (nonatomic,assign, readonly) BOOL mNotificationVibrate;

/**
 自动下载附件
 */
@property (nonatomic,assign, readonly) BOOL mAutoDownloadAttachment;

@end

NS_ASSUME_NONNULL_END
