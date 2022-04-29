//
// ----------------------------------------------------------------------
// File    : BMXRosterProtocol.h
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

#import "BMXRosterServiceProtocol.h"
#import "BMXError.h"
@class BMXRoster;
@class BMXRosterManagerListener;


@protocol BMXRosterManager <NSObject>

@required

- (void)addDelegate:(id<BMXRosterServiceProtocol>)aDelegate;

- (void)addDelegate:(id<BMXRosterServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue;

- (void)removeDelegate:(id<BMXRosterServiceProtocol>)aDelegate;

@optional


/**
 * 获取好友列表
 @param forceRefresh 如果forceRefresh == true，则强制从服务端拉取
 @param aCompletionBlock 好友列表
 */
- (void)getRosterListforceRefresh:(BOOL)forceRefresh
                       completion:(void (^)(NSArray *rostIdList,
                                            BMXError *error))aCompletionBlock;

/**
 通过好友ID搜索
 @param rosterId 好友ID
 @param aCompletionBlock 好友
 */
- (void)searchByRosterId:(long long)rosterId
            forceRefresh:(BOOL)forceRefresh
              completion:(void(^)(BMXRoster *roster,
                                  BMXError *error))aCompletionBlock;
/**
 通过好友Name搜索
 @param name  好友name
 @param aCompletionBlock 好友
 */
- (void)searchByRoserName:(NSString *)name
             forceRefresh:(BOOL)forceRefresh
               completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletionBlock;

/**
 批量搜索用户

 @param rosterIdList  id
 @param forceRefresh  如果forceRefresh == true，则强制从服务端拉取
 @param aCompletionBlock rosterList,error
 */
- (void)searchRostersByRosterIdList:(NSArray<NSNumber *> *)rosterIdList
                       forceRefresh:(BOOL)forceRefresh
                         completion:(void (^)(NSArray <BMXRoster *>*rosterList,
                                              BMXError *error))aCompletionBlock;


/**
 更新好友扩展信息
 */
- (void)updateItemExtensionByRoster:(BMXRoster *)roster
                      extensionJson:(NSString *)extensionJson
                         completion:(void(^)(BMXRoster *roster,
                                             NSString *extensionJson))aCompletionBlock;
/**
 * 更新好友本地扩展信息
 **/
- (void)updateItemLocalExtensionByRoster:(BMXRoster *)roster
                      localExtensionJson:(NSString *)localExtensionJson
                              completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock;

/**
 * 更新好友别名
 **/
- (void)updateItemAliasByRoster:(BMXRoster *)roster
                      aliasJson:(NSString *)aliasJson
                     completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletionBlock;

/**
 * 设置是否拒收用户消息
 **/
- (void)muteNotificationByRoster:(BMXRoster *)roster
          muteNotificationStatus:(BOOL)muteNotificationStatus
                      completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock;


/**
 * 获取申请添加好友列表
 **/
- (void)getApplicationListWithCursor:(NSString *)cursor
                            pageSize:(int)pageSize
                          completion:(void(^)(NSArray *applicationList,
                                              NSString *cursor,
                                              int offset,
                                              BMXError *error))aCompletionBlock ;

/**
 * 申请添加好友
 **/
- (void)applyAddRoster:(long long)roster
                reason:(NSString *)reason
            completion:(void(^)(BMXRoster *roster,
                                BMXError *error))aCompletionBlock;

/**
 * 删除好友
 **/
- (void)removeRosterById:(long long)rostId
          withCompletion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 接受加好友申请
 **/
- (void)acceptRosterById:(NSInteger)rosterId
          withCompletion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 拒绝加好友申请
 **/
- (void)declineRosterById:(NSInteger)rosterId
               withReason:(NSString *)reason
               completion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 加入黑名单
 **/
- (void)addToBlockList:(long long)rosterId
        withCompletion:(void(^)(BMXError *error))aCompletionBlock;

/**
 * 从黑名单移除
 **/
- (void)removeRosterFromBlockList:(NSInteger)rostId
                   withCompletion:(void(^)(BMXError *error))aCompletionBlock;


/**
 * 下载头像
 **/
- (void)downloadAvatarWithRoster:(BMXRoster *)roster
                        isThumbnail:(BOOL)isThumbnail
                        progress:(void(^)(int progress, BMXError *error))aProgress
                      completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletion;
/**
 * 获取黑名单
 @param forceRefresh 如果forceRefresh == true，则强制从服务端拉取
 @param aCompletionBlock BlockList ,Error
 */
- (void)getBlockListforceRefresh:(BOOL)forceRefresh
                      completion:(void(^)(NSArray *blockList,
                                          BMXError *error))aCompletionBlock;
/**
 * 添加好友变化监听者
 **/
- (void)addRosterListener:(id<BMXRosterServiceProtocol>)listener;

/**
 * 移除好友变化监听者
 **/
- (void)removeRosterListener:(id<BMXRosterServiceProtocol>)listener;


@end
