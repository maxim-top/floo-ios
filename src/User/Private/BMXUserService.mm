//----------------------------------------------------------------------
// File    : BMXUserService.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/29 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

#import "BMXUserService.h"
#import "BMXStringUtil.h"
#import "BMXUserProfile+Private.h"
#import "BMXError+Private.h"
#import "BMXAuthQuestion.h"

#include "bmx_user_profile.h"
#include "bmx_user_service.h"
#import "BMXClient.h"
#import "BMXDevice+Private.h"


@interface BMXUserService ()


@end

@implementation BMXUserService

- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super init]) {
        userServiceListener = new floosdk::UserServiceListener();
        clientPtr = aClientPtr;
        if (userServiceListener) {
            floo::BMXUserService &userService = aClientPtr->getUserService();
            userService.addUserListener(userServiceListener);
        }
    }
    return self;
}


- (void)bindDevice:(NSString *)token
        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return  self->clientPtr->getUserService().bindDevice([BMXStringUtil toStdString:token]);
    } completion:aCompletionBlock];
}

/**
 * 获取设备列表
 */
- (void)getDeviceListCompletion:(void(^)(BMXError *error,NSArray *deviceList))aCompletionBlock {

    [self handleDeviceList:^floo::BMXErrorCode(floo::BMXDeviceList &deviceList) {
        return  self->clientPtr->getUserService().getDeviceList(deviceList);
    } Completion:aCompletionBlock];

}

/**
 * 删除设备
 */
- (void)deleteDeviceByDeviceSN:(NSInteger)deviceSN
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().deleteDevice((int32_t)deviceSN);
    } completion:aCompletionBlock];
}

- (void)getProfileForceRefresh:(BOOL)forceRefresh
                    completion:(void (^)(BMXUserProfile *profile ,BMXError *aError))aCompletionBlock {
    [self handleProfile:^floo::BMXErrorCode(floo::BMXUserProfilePtr &profilePtr) {
        return self->clientPtr->getUserService().getProfile(profilePtr, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

/**
 * 设置昵称
 **/
- (void)setNickname:(NSString *)nickname
         completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setNickname([BMXStringUtil toStdString:nickname]);
    } completion:aCompletionBlock];
}

/**
 上传头像
 
 @param avatarData 头像
 @param aProgress 上传进度
 */
- (void)uploadAvatarWithData:(NSData *)avatarData
                    progress:(void(^)(int progress, BMXError *error))aProgress {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        NSString *localPath = nil;
        long long time = [[NSDate date] timeIntervalSince1970] * 1000;
        NSString *fileName = [NSString stringWithFormat:@"%lld",time];
        if ([avatarData length]) {
            localPath = [[BMXClient getCacheDir] stringByAppendingPathComponent:fileName];
            [avatarData writeToFile:localPath atomically:YES];
        }
        
        floo::BMXErrorCode code = self->clientPtr->getUserService().uploadAvatar([BMXStringUtil toStdString:localPath], [=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
            });
        });
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aProgress(0, error);
            });
        }
    });
}

- (void)downloadAvatarWithProfile:(BMXUserProfile *)profile
                        thumbnail:(BOOL)thumbnail
                         progress:(void(^)(int progress, BMXError *error))aProgress
                       completion:(void(^)(BMXUserProfile *profile, BMXError *error))aCompletion {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        floo::BMXErrorCode code = self->clientPtr->getUserService().downloadAvatar([profile getBMXUserProfilePtr], (bool)thumbnail, [=](int percent){
            dispatch_async(dispatch_get_main_queue(), ^{
                aProgress(percent, nil);
                
            });
        });
        
        if (code != floo::BMXErrorCode::NoError) {
            dispatch_async(dispatch_get_main_queue(), ^{
                BMXError *error = [BMXError bmx_ErrorWith:code];
                aCompletion(nil, error);
            });
        }else {
            aCompletion(profile, nil);
        }
    });
}

/**
 设置公开扩展信息
 
 @param publicInfo string
 */
- (void)setPublicInfo:(NSString *)publicInfo
           completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return  self->clientPtr->getUserService().setPublicInfo([BMXStringUtil toStdString:publicInfo]);
    } completion:aCompletionBlock];
   
}

/**
 设置私有扩展信息
 
 @param privateInfo string
 */
- (void)setPrivateInfo:(NSString *)privateInfo
            completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setPrivateInfo([BMXStringUtil toStdString:privateInfo]);
    } completion:aCompletionBlock];
}

/**
 设置加好友验证方式
 
 @param addFriendAuthMode BMXAddFriendAuthMode
 */
- (void)setAddFriendAuthMode:(BMXAddFriendAuthMode)addFriendAuthMode
                  completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setAddFriendAuthMode((floo::BMXUserProfile::AddFriendAuthMode)addFriendAuthMode);
    } completion:aCompletionBlock];
}

/**
 设置加好友验证问题
 
 @param authQuestion BMXAuthQuestion
 */
- (void)setAuthQuestion:(BMXAuthQuestion *)authQuestion
             completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        floo::BMXUserProfile::AuthQuestion question = floo::BMXUserProfile::AuthQuestion();
        question.mQuestion = [BMXStringUtil toStdString:authQuestion.mQuestion];
        question.mAnswer = [BMXStringUtil toStdString:authQuestion.mAnswer];
        return self->clientPtr->getUserService().setAuthQuestion(question);
    } completion:aCompletionBlock];
    
}

/**
 * 设置推送昵称
 **/
- (void)setsetPushNickname:(NSString *)nickname
                completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setPushNickname([BMXStringUtil toStdString:nickname]);
    } completion:aCompletionBlock];
}


/**
 设置是否允许推送
 
 @param enablePushStatus BOOL
 */
- (void)setEnablePushStatus:(BOOL)enablePushStatus
                 completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setEnablePush((bool)enablePushStatus);
    } completion:aCompletionBlock];
}

/**
 设置是否推送详情
 
 @param enablePushDetail BOOL
 */
- (void)setEnablePushDetail:(BOOL)enablePushDetail
                 completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setEnablePushDetaile((bool)enablePushDetail);
    } completion:aCompletionBlock];
}

/**
 设置收到新消息是否声音提醒
 
 @param notificationSound BOOL
 */
- (void)setNotificationSound:(BOOL)notificationSound
                  completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setNotificationSound((bool)notificationSound);
    } completion:aCompletionBlock];
}

/**
 设置收到新消息是否震动
 
 @param notificationVibrate BOOL
 */
- (void)setNotificationVibrate:(BOOL)notificationVibrate
                    completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setNotificationVibrate((bool)notificationVibrate);
    } completion:aCompletionBlock];
}

/**
 设置是否自动缩略图和语音附件
 
 @param autoDownloadAttachment BOOL
 */
- (void)setAutoDownloadAttachment:(BOOL)autoDownloadAttachment
                       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setAutoDownloadAttachment((bool)autoDownloadAttachment);
    } completion:aCompletionBlock];
}

/**
 设置是否自动同意入群邀请
 
 @param autoAcceptGroupInvite BOOL
 */
- (void)setAutoAcceptGroupInvite:(BOOL)autoAcceptGroupInvite
                      completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->getUserService().setAutoAcceptGroupInvite((bool)autoAcceptGroupInvite);
    } completion:aCompletionBlock];
}


- (void)handle:(floo::BMXErrorCode(^)())handle
    completion:(void(^)(BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode errorP = handle();
            BMXError *error = [BMXError bmx_ErrorWith:errorP];
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error);
            });
        });
    }
}

- (void)handleProfile:(floo::BMXErrorCode (^)(floo::BMXUserProfilePtr &profilePtr))aRequest
           completion:(void (^)(BMXUserProfile *profile ,BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXUserProfilePtr ptr;
        floo::BMXErrorCode err = aRequest(ptr);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXUserProfile *pro;

        if (!error) {
          pro = [[BMXUserProfile alloc] initWithBMXUserProfilePtr:ptr];
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(pro , error);
            });
        }
    });
}

- (void)handleDeviceList:(floo::BMXErrorCode (^)(floo::BMXDeviceList &deviceList))aRequest
              Completion:(void(^)(BMXError *error,NSArray *deviceList))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSMutableArray *deviceArray = nil;
        floo::BMXDeviceList deviceList;
        floo::BMXErrorCode err = aRequest(deviceList);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            deviceArray = [NSMutableArray array];
            for (floo::BMXDevicePtr devicePtr : deviceList) {
                BMXDevice *device = [[BMXDevice alloc] initWithBMXDevicePtr:devicePtr];
                [deviceArray addObject:device];
            }
        }

        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error, deviceArray);
            });
        }
        
    });
}

- (void)addDelegate:(id<BMXUserServiceProtocol>)aDelegate {
    [self addDelegate:aDelegate delegateQueue:nil];
}

- (void)addDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)aQueue {
    if (aDelegate == nil) {
        return;
    }
    if ([aDelegate conformsToProtocol:@protocol(BMXUserServiceProtocol)]) {
        userServiceListener->addDelegate(aDelegate, aQueue);
    }
}

- (void)removeDelegate:(id<BMXUserServiceProtocol>)aDelegate {
    if (aDelegate == nil) {
        return;
    }
    if ([aDelegate conformsToProtocol:@protocol(BMXUserServiceProtocol)]) {
        userServiceListener-> removeDelegate(aDelegate);
    }
}

- (void)removeRosterListener {
    if (userServiceListener) {
        clientPtr->getUserService().removeUserListener(userServiceListener);
    }
}

@end
