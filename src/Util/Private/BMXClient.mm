// ----------------------------------------------------------------------
// File    : BMXClient.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/25 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXClient.h"
#import "BMXUserService.h"
#import "BMXChatService.h"
#import "BMXRosterService.h"
#import "BMXGroupService.h"
#import "BMXStringUtil.h"
#import "BMXPushService.h"

#include "bmx_client.h"
#import "BMXSDKConfig.h"
#import "BMXSDKConfig+Private.h"
#import "BMXError+Private.h"
#import "BMXUserProfile+Private.h"

static BMXClient *sharedClient = nil;

@interface BMXClient ()
{
    floo::BMXClientPtr clientPtr;
    BOOL _initialized;
    NSObject *_initializeLock;

}

@property (nonatomic, assign, readonly) BOOL isInitialized;


@end

@implementation BMXClient

@synthesize userService = _userService;
@synthesize chatService = _chatService;
@synthesize rosterService = _rosterService;
@synthesize groupService = _groupService;
@synthesize pushService = _pushService;

- (instancetype)init {
    if (self = [super init]) {
        _initialized = NO;
        _initializeLock = [[NSObject alloc] init];

    }
    return self;
}


+ (instancetype)sharedClient {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedClient = [[BMXClient alloc] init];
    });
    
    return sharedClient;
}

- (void)registerWithSDKConfig:(BMXSDKConfig *)config {
    @synchronized (_initializeLock) {
        do {
            if (_initialized) {
                break;
            }
            clientPtr = floo::BMXClient::create([config getBMXSDKConfigPtr]);
            _initialized = YES;
            [self initManager];
        } while (0);
    }
}

+ (void)initializeSDKConfig:(BMXSDKConfig *)config {
    BMXClient *client = [BMXClient sharedClient];
    client->clientPtr = floo::BMXClient::create([config getBMXSDKConfigPtr]);
}

- (void)initManager {
    [self pushService];
    [self chatService];
    [self rosterService];
    [self groupService];
    [self userService];
}

- (BMXSDKConfig *)sdkConfig {
    BMXClient *client = [BMXClient sharedClient];
    return [[BMXSDKConfig alloc] initWith:client->clientPtr->getSDKConfig()];
}

+ (NSString *)getCacheDir {
    BMXClient *client = [BMXClient sharedClient];
    return [BMXStringUtil stdToNSString:client->clientPtr->getSDKConfig()->getCacheDir()];
}

- (void)networkDidChangedType:(BMXNetworkType)type reconnect:(BOOL)reconnect {
    BMXClient *client = [BMXClient sharedClient];
    client->clientPtr->onNetworkChanged((floo::BMXNetworkType)type, (bool)reconnect);
}

- (void)disConnect {
    BMXClient *client = [BMXClient sharedClient];
    client->clientPtr->disconnect();
}

- (void)changeAppID:(NSString *)appID
         completion:(void (^)(BMXError *error))aCompletionBlock {
    
    [self handle:^floo::BMXErrorCode {
        BMXClient *client = [BMXClient sharedClient];
        return client->clientPtr->changeAppId([BMXStringUtil toStdString:appID]);
    } completion:aCompletionBlock];
    
    
}

- (id<BMXUserManager>)userService {
    if (!self.isInitialized) {
        return nil;
    }
    if (_userService == nil) {
        _userService = [[BMXUserService alloc] initWithClientPtr:clientPtr];
    }
    return _userService;
}

- (id<BMXChatManager>)chatService {
    if (!self.isInitialized) {
        return nil;
    }
    
    if (_chatService == nil) {
        _chatService = [[BMXChatService alloc] initWithClientPtr:clientPtr];
    }
    return _chatService;
}

- (id<BMXRosterManager>)rosterService {
    if (!self.isInitialized) {
        return nil;
    }
    if (_rosterService == nil) {
        _rosterService = [[BMXRosterService alloc] initWithClientPtr:clientPtr];
    }
    return _rosterService;
}

- (id<BMXGroupManager>)groupService {
    if (!self.isInitialized) {
        return nil;
    }
    if (_groupService == nil) {
        _groupService = [[BMXGroupService alloc] initWithClientPtr:clientPtr];
    }
    return _groupService;
}

- (id<BMXPushManager>)pushService {
    if (!self.isInitialized) {
        return nil;
    }
    if (_pushService == nil) {
        _pushService = [[BMXPushService alloc] initWithClientPtr:clientPtr];
    }
    return _pushService;
}


- (void)signUpNewUser:(NSString *)userName
             password:(NSString *)password
           completion:(void (^)(BMXUserProfile *profile, BMXError *error))aCompletionBlock {
    [self handleSignUp:^floo::BMXErrorCode(floo::BMXUserProfilePtr &itemPtr) {
        return self->clientPtr->signUpNewUser([BMXStringUtil toStdString:userName], [BMXStringUtil toStdString:password], itemPtr);
    } completion:aCompletionBlock];
}

- (void)signInByName:(NSString *)userName
            password:(NSString *)password
          completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->signInByName([BMXStringUtil toStdString:userName], [BMXStringUtil toStdString:password]);
    } completion:aCompletionBlock];
}

- (void)signInById:(long long)userId password:(NSString *)password
        completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleSignInById:userId password:password completion:aCompletionBlock];
}

- (void)fastSignInById:(long long)uid
              password:(NSString *)password
            completion:(void(^)(BMXError *error))aCompletionBlock {
    
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->fastSignInById(uid, [BMXStringUtil toStdString:password]);
    } completion:aCompletionBlock];
}

- (void)fastSignInByName:(NSString *)name
                password:(NSString *)password
              completion:(void (^)(BMXError *))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return  self->clientPtr->fastSignInByName([BMXStringUtil toStdString:name],
                                                                   [BMXStringUtil toStdString:password]);
    } completion:aCompletionBlock];
}

/**
 * 退出登录
 **/
- (void)signOutID:(NSInteger)userID
ignoreUnbindDevice:(BOOL)ignoreUnbindDevice
       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->signOut((bool)ignoreUnbindDevice);
    } completion:aCompletionBlock];
}

/**
 * 删除账号
 **/
- (void)deleteAccountWithPassword:(NSString *)password
       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->deleteAccount([BMXStringUtil toStdString:password]);
    } completion:aCompletionBlock];
}


- (void)signOutignoreUnbindDevice:(BOOL)ignoreUnbindDevice
                       completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handle:^floo::BMXErrorCode{
        return self->clientPtr->signOut((bool)ignoreUnbindDevice);
    } completion:aCompletionBlock];
    
}

- (void)initializeServerConfig:(BOOL)isLocal {
    self->clientPtr->initializeServerConfig((bool)isLocal);
}

- (void)handleSignUp:(floo::BMXErrorCode(^)(floo::BMXUserProfilePtr &itemPtr))param
          completion:(void (^)(BMXUserProfile *profile, BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            BMXUserProfile *profile;
            floo::BMXUserProfilePtr profilePtr;
            floo::BMXErrorCode err = param(profilePtr);
            
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                profile = [[BMXUserProfile alloc] initWithBMXUserProfilePtr:profilePtr];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(profile, error);
            });
        });
    }
}

- (void)handleSignInById:(long long)userId
                password:(NSString *)password
              completion:(void(^)(BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode errorP = self->clientPtr->signInById((int64_t)userId, [BMXStringUtil toStdString:password]);
            BMXError *error = [BMXError bmx_ErrorWith:errorP];
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(error);
            });
        });
    }
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

- (void)reconnect {
    clientPtr->reconnect();
}

- (BMXConnectStatus)connectStatus {
    return (BMXConnectStatus) clientPtr->connectStatus();
}

- (BMXSignInStatus)signInStatus {
    return (BMXSignInStatus)clientPtr->signInStatus();
}

- (BOOL)isInitialized {
    @synchronized (_initializeLock) {
        return _initialized;
    }
}

@end
