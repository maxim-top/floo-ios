// ----------------------------------------------------------------------
// File    : BMXConversationObject.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/28 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//
#import <Foundation/Foundation.h>
#import "BMXDefines.h"
#import "BMXUserServiceProtocol.h"
#import "BMXUserProfile.h"
@class BMXMessageSetting;
@class BMXError;

@protocol BMXUserManager <NSObject>

@required
- (void)addDelegate:(id<BMXUserServiceProtocol>)aDelegate;

- (void)addDelegate:(id<BMXUserServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id<BMXUserServiceProtocol>)aDelegate;

@optional



/**
 * 绑定设备推送token
 **/
- (void)bindDevice:(NSString *)token
        completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 获取设备列表
 */
- (void)getDeviceListCompletion:(void(^)(BMXError *error,NSArray *deviceList))aCompletionBlock;
/**
 * 删除设备
 */
- (void)deleteDeviceByDeviceSN:(NSInteger)deviceSN
                    completion:(void(^)(BMXError *error))aCompletionBlock;
/**
 * 获取用户详情
 **/
- (void)getProfileForceRefresh:(BOOL)forceRefresh
                    completion:(void (^)(BMXUserProfile *profile ,BMXError *aError))aCompletionBlock;

/**
 * 设置昵称
 **/
- (void)setNickname:(NSString *)nickname completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 上传头像

 @param avatarData 头像
 @param aProgressBlock 上传进度
 */
- (void)uploadAvatarWithData:(NSData *)avatarData
                    progress:(void(^)(int progress, BMXError *error))aProgressBlock;


/**
 下载头像

 @param profile 用户信息
 @param aProgress 下载进度
 @param aCompletion 回调
 */
- (void)downloadAvatarWithProfile:(BMXUserProfile *)profile
                        thumbnail:(BOOL)thumbnail
                         progress:(void(^)(int progress, BMXError *error))aProgress
                       completion:(void(^)(BMXUserProfile *profile, BMXError *error))aCompletion;

/**
 设置公开扩展信息

 @param publicInfo string
 */
- (void)setPublicInfo:(NSString *)publicInfo
           completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置私有扩展信息

 @param privateInfo string
 */
- (void)setPrivateInfo:(NSString *)privateInfo
            completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置加好友验证方式

 @param addFriendAuthMode BMXAddFriendAuthMode
 */
- (void)setAddFriendAuthMode:(BMXAddFriendAuthMode)addFriendAuthMode
                  completion:(void(^)(BMXError *error))aCompletionBlock;

/**
设置加好友验证问题

 @param authQuestion BMXAuthQuestion
 */
- (void)setAuthQuestion:(BMXAuthQuestion *)authQuestion
             completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置是否允许推送

 @param enablePushStatus BOOL
 */
- (void)setEnablePushStatus:(BOOL)enablePushStatus
                 completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置是否推送详情

 @param enablePushDetail BOOL
 */
- (void)setEnablePushDetail:(BOOL)enablePushDetail
                       completion:(void(^)(BMXError *error))aCompletionBlock;
/**
 * 设置推送昵称
 **/
- (void)setsetPushNickname:(NSString *)nickname
                completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置收到新消息是否声音提醒
 
 @param notificationSound BOO
 */
- (void)setNotificationSound:(BOOL)notificationSound
                  completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置收到新消息是否震动
 
 @param notificationVibrate BOOL
 */
- (void)setNotificationVibrate:(BOOL)notificationVibrate
                    completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 设置是否自动缩略图和语音附件

 @param autoDownloadAttachment BOOL
 */
- (void)setAutoDownloadAttachment:(BOOL)autoDownloadAttachment
                       completion:(void(^)(BMXError *error))aCompletionBlock;
/**
 设置是否自动同意入群邀请

 @param autoAcceptGroupInvite BOOL
 */
- (void)setAutoAcceptGroupInvite:(BOOL)autoAcceptGroupInvite
                      completion:(void(^)(BMXError *error))aCompletionBlock;

@end
