//
//  BMXPushService.m
//  MaxIM
//
//  Created by 韩雨桐 on 2020/8/21.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "BMXPushService.h"

#import <UIKit/UIKit.h>

#import "BMXChatService+Private.h"
#import "BMXError.h"
#import "BMXError+Private.h"
#import "BMXMessageObject.h"
#import "BMXConversation.h"
#import "BMXMessageObject+Private.h"
#import "BMXConversation+Private.h"
#import "BMXStringUtil.h"
#include "bmx_push_service.h"
#import "BMXPushUserProfile.h"
#import "BMXPushUserProfile+Private.h"
#import <UserNotifications/UNUserNotificationCenter.h>


@implementation BMXPushService


- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super initWithClientPtr:aClientPtr]) {
        pushListener = new floosdk::PushServiceListener();
        if (pushListener) {
            floo::BMXPushService &pushService = aClientPtr->getPushService();
            pushService.addPushListener(pushListener);
        }
    }
    return self;
}

- (void)start {
    self->clientPtr->getPushService().start();
}

- (void)startWithAlias:(NSString *)alias bmxToken:(NSString *)bmxToken {
    self->clientPtr->getPushService().start([BMXStringUtil toStdString:alias],
                                            [BMXStringUtil toStdString:bmxToken]);
}

- (void)startWithAlias:(NSString *)alias {
    self->clientPtr->getPushService().start([BMXStringUtil toStdString:alias]);
}

- (void)stop {
    self->clientPtr->getPushService().stop();
}

- (void)resume {
    self->clientPtr->getPushService().resume();
}

- (void)unbindAlias:(NSString *)alias {
    self->clientPtr->getPushService().unbindAlias([BMXStringUtil toStdString:alias]);
}

- (void)getToken{
    self->clientPtr->getPushService().getToken();
}

- (void)getCertification {
    self->clientPtr->getPushService().getCert();
}

- (BMXPushSdkStatus)status {
    return  (BMXPushSdkStatus)self->clientPtr->getPushService().status();
}


- (void)bindDeviceToken:(NSString *)deviceToken
        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return   self->clientPtr->getPushService().bindDeviceToken([BMXStringUtil toStdString:deviceToken]);
    } completion:aCompletionBlock];
}

//- (void)bindVoipToken:(NSString *)token;

- (void)getPushProfileForceRefresh:(BOOL)forceRefresh
                        completion:(void (^)(BMXPushUserProfile *profile ,BMXError *aError))aCompletionBlock {
    [self handleProfile:^floo::BMXErrorCode(floo::BMXPushUserProfilePtr &profilePtr) {
        return self->clientPtr->getPushService().getPushProfile(profilePtr, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)setTags:(NSArray <NSString *> *)tags operationId:(NSString *)operationId {
    
    std::vector<std::string> list;
    for(NSString *tag in tags){
        if ([tag length] > 0) {
            list.push_back([BMXStringUtil toStdString:tag]);
        }
    }
    self->clientPtr->getPushService().setTags(list, [BMXStringUtil toStdString:operationId]);
}

- (void)getTagsByOperationId:(NSString *)operationId
              withCompletion:(void(^)(NSArray *tags, BMXError *error))aCompletionBlock {
    [self handleData:^floo::BMXErrorCode(std::vector<std::string> &list) {
       return self->clientPtr->getPushService().getTags(list, [BMXStringUtil toStdString:operationId]);
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


- (void)handleProfile:(floo::BMXErrorCode (^)(floo::BMXPushUserProfilePtr &profilePtr))aRequest
           completion:(void (^)(BMXPushUserProfile *profile ,BMXError *aError))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        floo::BMXPushUserProfilePtr ptr;
        floo::BMXErrorCode err = aRequest(ptr);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        BMXPushUserProfile *pro;

        if (!error) {
            pro = [[BMXPushUserProfile alloc] initWithBMXPushUserProfilePtr:ptr];
        }
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(pro , error);
            });
        }
    });
}


- (void)handleData:(floo::BMXErrorCode (^)(std::vector<std::string> &list))aRequest
                   completion:(void (^)(NSArray *tags, BMXError *error))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        std::vector<std::string> list;
        floo::BMXErrorCode err = aRequest(list);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        NSMutableArray *taglist = nil;
        if (!error) {
            taglist = [NSMutableArray array];
            for (std::string tag : list) {
                if (!tag.empty()) {
                    [taglist addObject:[BMXStringUtil stdToNSString:tag]];
                }
            }
        }
        
        if (aCompletionBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock([NSArray arrayWithArray:taglist], error);
            });
        }
    });
}

- (void)deleteTags:(NSArray <NSString *> *)tags operationId:(NSString *)operationId {
    std::vector<std::string> list;
    for(NSString *tag in tags){
        if ([tag length] > 0) {
            list.push_back([BMXStringUtil toStdString:tag]);
        }
    }
    self->clientPtr->getPushService().deleteTags(list, [BMXStringUtil toStdString:operationId]);

}

- (void)clearTagsByOperationId:(NSString *)operationId {
    self->clientPtr->getPushService().clearTags([BMXStringUtil toStdString:operationId]);
}

- (void)setBadge:(int)count {
    self->clientPtr->getPushService().setBadge(count);
}

- (void)setPushMode:(BOOL)enable {
    self->clientPtr->getPushService().setPushMode((bool)enable);
}

- (void)setPushTimeStartHour:(int)startHour
                     endHour:(int)endHour {
    self->clientPtr->getPushService().setPushTime(startHour, endHour);
}

- (void)setSlienceTimeStartHour:(int)startHour
                        endHour:(int)endHour {
    self->clientPtr->getPushService().setSilenceTime(startHour, endHour);
}

//- (void)setRunBackgroundMode:(BOOL)enable {
//    self->clientPtr->getPushService().setRunBackgroundMode((bool)enable);
//}

- (void)clearNotification:(NSInteger)notificationId {
    if (notificationId <= 0) {
        [self clearAllNotifications];
    }else {
        if (@available(iOS 10.0, *)) {
            [[UNUserNotificationCenter currentNotificationCenter] removeDeliveredNotificationsWithIdentifiers:@[[NSString stringWithFormat:@"%ld",notificationId]]];
        }
    }
    
}

- (void)clearAllNotifications {
    
    if (@available(iOS 10.0, *)) {
        [[UNUserNotificationCenter currentNotificationCenter] removeAllDeliveredNotifications];
    } else {
        [[UIApplication sharedApplication] setApplicationIconBadgeNumber:-1];
    }
}

- (void)sendMessage:(NSString *)message {
    self->clientPtr->getPushService().sendMessage([BMXStringUtil toStdString:message]);
}

- (void)loadLocalPushMessagesFromMessageId:(long long)reMsgId
                                      size:(NSUInteger)size
                             directionType:(BMXPushMessageDirection)directionType
                                completion:(void(^)(NSArray *messageList, BMXError *error))aCompletionBlock {
    [self handleLoadMessages:^floo::BMXErrorCode(std::vector<floo::BMXMessagePtr> &itemList) {
        return self->clientPtr->getPushService().loadLocalPushMessages((int64_t)reMsgId, size, itemList, (floo::BMXPushService::PushDirection)directionType);
    } completion:aCompletionBlock];
}

- (void)handleLoadMessages:(floo::BMXErrorCode (^)(std::vector<floo::BMXMessagePtr> &itemList))handle
               completion:(void (^)(NSArray <BMXMessageObject *>*, BMXError *))aCompletionBlock {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
          NSMutableArray *messageArray = nil;
        std::vector<floo::BMXMessagePtr> list;
        floo::BMXErrorCode err = handle(list);
        BMXError *error = [BMXError bmx_ErrorWith:err];
        if (!error) {
            messageArray = [NSMutableArray array];
            for (floo::BMXMessagePtr messagePtr : list) {
                BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:messagePtr];
                [messageArray addObject:message];
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            aCompletionBlock(messageArray,error);
        });
    });
    
}

- (void)addDelegate:(id<BMXPushServiceProtocol>)aDelegate {
    [self addDelegate:aDelegate delegateQueue:nil];
}

- (void)addDelegate:(id)aDelegate delegateQueue:(dispatch_queue_t)aQueue {
    
    if (aDelegate == nil) {
        return;
    }
    
    if ([aDelegate conformsToProtocol:@protocol(BMXPushServiceProtocol)]) {
        pushListener->addDelegate(aDelegate, aQueue);
        
    }
}

- (void)removeDelegate:(id<BMXPushServiceProtocol>)aDelegate {
    if (aDelegate == nil) {
        return;
    }
    if ([aDelegate conformsToProtocol:@protocol(BMXPushServiceProtocol)]) {
        pushListener-> removeDelegate(aDelegate);
    }
}


- (void)removePushListener {
    if (pushListener) {
        clientPtr->getPushService().removePushListener(pushListener);
    }
}

- (void)addPushListener:(id<BMXPushServiceProtocol>)listener {
    if (listener == nil) {
           return;
       }

       if ([listener conformsToProtocol:@protocol(BMXPushServiceProtocol)]) {
           pushListener->addDelegate(listener, nil);
       }
}

- (void)removePushListener:(id<BMXPushServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }

    if ([listener conformsToProtocol:@protocol(BMXPushManager)]) {
        pushListener->removeDelegate(listener);
    }
}

 





@end
