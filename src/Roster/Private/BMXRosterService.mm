//
// ----------------------------------------------------------------------
// File    : BMXRosterService.m
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

#import "BMXRosterService.h"
#import "RosterServiceListener.h"
#include <vector>
#import "BMXRoster+Private.h"
#import "BMXRoster.h"
#import "BMXError.h"
#import "BMXRosterManager.h"
#import "BMXStringUtil.h"
#import "BMXError+Private.h"
#import "BMXApplication.h"
#import "BMXApplication+Private.h"
#include "bmx_result_page.h"

@interface BMXRosterService ()

@property (nonatomic, assign) floo::BMXRosterService::ApplicationPtr applicationPtr;

@end

@implementation BMXRosterService

- (instancetype)initWithClientPtr:(floo::BMXClientPtr)aClientPtr {
    if (self = [super initWithClientPtr:aClientPtr]) {
        rostelistener = new floosdk::RosterServiceListener();
        if (rostelistener) {
            floo::BMXRosterService &rosterService = aClientPtr->getRosterService();
            rosterService.addRosterListener(rostelistener);
        }
    }
    return self;
}

#pragma mark -Delegate
- (void)addRosterListener:(id<BMXRosterServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    
    if ([listener conformsToProtocol:@protocol(BMXRosterServiceProtocol)]) {
        rostelistener->addDelegate(listener, nil);
    }
}

- (void)removeRosterListener:(id<BMXRosterServiceProtocol>)listener {
    if (listener == nil) {
        return;
    }
    
    if ([listener conformsToProtocol:@protocol(BMXRosterManager)]) {
        rostelistener->removeDelegate(listener);
    }
}

- (void)addDelegate:(id<BMXRosterServiceProtocol>)aDelegate delegateQueue:(dispatch_queue_t)aQueue {
    if (aDelegate == nil) {
        return;
    }
    if ([aDelegate conformsToProtocol:@protocol(BMXRosterServiceProtocol)]) {
        rostelistener->addDelegate(aDelegate, aQueue);
    }
}

- (void)addDelegate:(id<BMXRosterServiceProtocol>)aDelegate {
    [self addDelegate:aDelegate delegateQueue:nil];
}

- (void)removeDelegate:(id<BMXRosterServiceProtocol>)aDelegate{
    if (aDelegate == nil) {
        return;
    }
    if ([aDelegate conformsToProtocol:@protocol(BMXRosterServiceProtocol)]) {
        rostelistener-> removeDelegate(aDelegate);
    }
}

- (void)removeRosterListener {
    if (rostelistener) {
        clientPtr->getRosterService().removeRosterListener(rostelistener);
    }
}

#pragma mark - RosterService
- (void)getRosterListforceRefresh:(BOOL)forceRefresh
                       completion:(void (^)(NSArray *rostIdList, BMXError *error))aCompletionBlock { 
    [self handleRosters:^floo::BMXErrorCode(std::vector<int64_t> &idList) {
        return self->clientPtr->getRosterService().get(idList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

- (void)searchByRosterId:(long long)rosterId
            forceRefresh:(BOOL)forceRefresh
              completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletionBlock {
    
    [self handleRoster:^floo::BMXErrorCode(floo::BMXRosterItemPtr &itemPtr) {
        return self->clientPtr->getRosterService().search((int64_t)rosterId, (bool)forceRefresh, itemPtr);
    } completion:aCompletionBlock];
}

- (void)searchByRoserName:(NSString *)name
             forceRefresh:(BOOL)forceRefresh
               completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletionBlock {
    
    [self handleRoster:^floo::BMXErrorCode(floo::BMXRosterItemPtr &itemPtr) {
        return self->clientPtr->getRosterService().search([BMXStringUtil toStdString:name], (bool)forceRefresh, itemPtr);
    } completion:aCompletionBlock];
}

- (void)searchRostersByRosterIdList:(NSArray<NSNumber *> *)rosterIdList
                       forceRefresh:(BOOL)forceRefresh
                         completion:(void (^)(NSArray <BMXRoster *>*rosterList, BMXError *error))aCompletionBlock {
    
    [self handleSearchRosters:^floo::BMXErrorCode(std::vector<floo::BMXRosterItemPtr> &itemList) {
        std:: vector<int64_t> rosterIds;
        for (NSNumber *rostId in rosterIdList) {
            rosterIds.push_back([rostId longLongValue]);
        }
        return  self->clientPtr->getRosterService().search(rosterIds, itemList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

/**
 * 更新好友别名
 **/
- (void)updateItemAliasByRoster:(BMXRoster *)roster
                      aliasJson:(NSString *)aliasJson
                     completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock {
    [self handleUpdateRoster:^floo::BMXErrorCode(floo::BMXRosterItemPtr &rostPtr) {
        std::string jsonStr = [BMXStringUtil toStdString:aliasJson];
        return self->clientPtr->getRosterService().setItemAlias([roster getBMXRosterPtr], jsonStr);
    } completion:aCompletionBlock];
}

- (void)muteNotificationByRoster:(BMXRoster *)roster
            muteNotificationStatus:(BOOL)muteNotificationStatus
             completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock {
    [self handleRoster:^floo::BMXErrorCode(floo::BMXRosterItemPtr &itemPtr) {
        return self->clientPtr->getRosterService().setItemMuteNotification([roster getBMXRosterPtr], (bool)muteNotificationStatus);
    } completion:aCompletionBlock];
    
}

/**
 * 获取申请添加好友列表
 **/
- (void)getApplicationListWithCursor:(NSString *)cursor
                            pageSize:(int)pageSize
                          completion:(void(^)(NSArray *applicationList,
                                              NSString *cursor,
                                              int offset,
                                              BMXError *error))aCompletionBlock {
    [self handleAppication:^floo::BMXErrorCode(floo::BMXRosterService::BMXRosterApplicationResultPagePtr &ptr) {
      return self->clientPtr->getRosterService().getApplicationList(ptr, [BMXStringUtil toStdString:cursor], pageSize);
    } completion:aCompletionBlock];
}

- (void)downloadAvatarWithRoster:(BMXRoster *)roster
                         progress:(void(^)(int progress, BMXError *error))aProgress
                       completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletion {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        floo::BMXErrorCode code = self->clientPtr->getRosterService().downloadAvatar([roster getBMXRosterPtr], true,[=](int percent){
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
            aCompletion(roster, nil);
        }
    });
}

- (void)handleAppication:(floo::BMXErrorCode (^)(floo::BMXRosterService::BMXRosterApplicationResultPagePtr &ptr))handle
              completion:(void(^)(NSArray *applicationList,
                                  NSString *cursor,
                                  int offset,
                                  BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXRosterService::BMXRosterApplicationResultPagePtr result;
            floo::BMXErrorCode err = handle(result);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            NSMutableArray *applicationList = [NSMutableArray array];
            int resultOffset = 0;
            NSString *resultCursor = nil;
            if (!error) {
                resultOffset = result->offset();
                resultCursor = [BMXStringUtil stdToNSString: result->cursor()];
                
                for (floo::BMXRosterService::ApplicationPtr ptr : result->result()) {
                    BMXApplication *mApplication = [[BMXApplication alloc] initWithApplicationPtr:ptr];
                    [applicationList addObject:mApplication];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(applicationList, resultCursor, resultOffset,error);
            });
        });
    }
}

- (void)handleUpdateRoster:(floo::BMXErrorCode (^)(floo::BMXRosterItemPtr &rostPtr))param
                completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXRosterItemPtr rostPtr;
            floo::BMXErrorCode err = param(rostPtr);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            BMXRoster *rost = nil;
            if (!error) {
               rost = [[BMXRoster alloc] initWithBMXRosterPtr:rostPtr];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(rost, error);
            });
        });
    }
}

- (void)updateItemExtensionByRoster:(BMXRoster *)roster
                      extensionJson:(NSString *)extensionJson
                         completion:(void(^)(BMXRoster *roster,
                                             NSString *extensionJson))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
        std::string json = extensionJson ? [extensionJson cStringUsingEncoding:kCFStringEncodingUTF8] : "";
        error = self->clientPtr->getRosterService().setItemExtension([roster getBMXRosterPtr], json);
        return [roster getBMXRosterPtr];
    } completion:^(BMXRoster *roster, BMXError *aError) {
            aCompletionBlock(roster, roster.json_alias);
    }];
}

- (void)updateItemLocalExtensionByRoster:(BMXRoster *)roster
                      localExtensionJson:(NSString *)localExtensionJson
                              completion:(void(^)(BMXRoster *roster,  BMXError *error))aCompletionBlock {
    [self handleUpdateRoster:^floo::BMXErrorCode(floo::BMXRosterItemPtr &rostPtr) {
         return self->clientPtr->getRosterService().setItemLocalExtension([roster getBMXRosterPtr], [BMXStringUtil toStdString:localExtensionJson]);
    } completion:aCompletionBlock];
    
}

- (void)applyAddRoster:(long long)roster
                reason:(NSString *)reason
            completion:(void(^)(BMXRoster *roster, BMXError *error))aCompletionBlock {
    [self handleRosterApply:^floo::BMXErrorCode(floo::BMXRosterItemPtr ptr) {
        return self->clientPtr->getRosterService().apply(roster, [BMXStringUtil toStdString:reason]);
    } completion:aCompletionBlock];
    
}

- (void)removeRosterById:(long long)rostId withCompletion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
         floo::BMXRosterItemPtr contact;
        error = self->clientPtr->getRosterService().remove(rostId);
        return nil;
    } completion:^(BMXRoster *roster, BMXError *aError) {
        aCompletionBlock(aError);
    }];
}

- (void)acceptRosterById:(NSInteger)rosterId withCompletion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
        floo::BMXRosterItemPtr contact;
        error = self->clientPtr->getRosterService().accept((long long)rosterId);
        return nil;
    } completion:^(BMXRoster *roster, BMXError *aError) {
        aCompletionBlock(aError);
    }];
}

- (void)declineRosterById:(NSInteger)rosterId withReason:(NSString *)reason completion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
        floo::BMXRosterItemPtr contact;
        std::string reasonString = reason ? [reason cStringUsingEncoding:kCFStringEncodingUTF8] : "";
        error = self->clientPtr->getRosterService().decline((long long)rosterId, reasonString);
        return nil;
    } completion:^(BMXRoster *roster, BMXError *aError) {
        aCompletionBlock(aError);
    }];
    
}

- (void)addToBlockList:(long long)rosterId  withCompletion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
        floo::BMXRosterItemPtr contact;
        error = self->clientPtr->getRosterService().block(rosterId);
        return nil;
    } completion:^(BMXRoster *roster, BMXError *aError) {
        aCompletionBlock(aError);
    }];
}

- (void)removeRosterFromBlockList:(NSInteger)rostId withCompletion:(void(^)(BMXError *error))aCompletionBlock {
    [self handleRosterParam:^floo::BMXRosterItemPtr(floo::BMXErrorCode &error) {
        floo::BMXRosterItemPtr contact;
        error = self->clientPtr->getRosterService().unblock((long long)rostId);
        return nil;
    } completion:^(BMXRoster *roster, BMXError *aError) {
        aCompletionBlock(aError);
    }];
}

- (void)getBlockListforceRefresh:(BOOL)forceRefresh
                      completion:(void(^)(NSArray *blockList, BMXError *error))aCompletionBlock {
    [self handleRostersParam:^floo::BMXErrorCode(std::vector<int64_t> &idList) {
        return self->clientPtr->getRosterService().getBlockList(idList, (bool)forceRefresh);
    } completion:aCompletionBlock];
}

#pragma mark - handle
- (void)handleRostersParam:(floo::BMXErrorCode (^)(std::vector<int64_t> &idList))param
                completion:(void(^)(NSArray *blockList, BMXError *error))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            NSMutableArray *blockList = nil;
            std::vector<int64_t> blockIdList;
            floo::BMXErrorCode err = param(blockIdList);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                blockList = [NSMutableArray array];
                for (int64_t rostId : blockIdList) {
                    NSString *idstr = [NSString stringWithFormat:@"%lld", rostId];
                    [blockList addObject:idstr];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(blockList, error);
            });
        });
    }
}

- (void)handleRosters:(floo::BMXErrorCode (^)(std::vector<int64_t> &idList))param
       completion:(void (^)(NSArray *, BMXError *))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            NSMutableArray *rosterArray = nil;
            std::vector<int64_t> ids;
            floo::BMXErrorCode err = param(ids);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                rosterArray = [NSMutableArray array];
                for (int64_t rosterId : ids) {
                    [rosterArray addObject:[NSString stringWithFormat:@"%lld", rosterId]];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(rosterArray, error);
            });
        });
    }
}

- (void)handleSearchRosters:(floo::BMXErrorCode (^)(std::vector<floo::BMXRosterItemPtr> &itemList))param
           completion:(void (^)(NSArray <BMXRoster *>*, BMXError *))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            NSMutableArray *rosterArray = nil;
            std::vector<floo::BMXRosterItemPtr> list;
            floo::BMXErrorCode err = param(list);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                rosterArray = [NSMutableArray array];
                for (floo::BMXRosterItemPtr rosterPtr : list) {
                    BMXRoster *roster = [[BMXRoster alloc] initWithBMXRosterPtr:rosterPtr];
                    [rosterArray addObject:roster];
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(rosterArray, error);
            });
        });
    }
}


- (void)handleRosterApply:(floo::BMXErrorCode (^)(floo::BMXRosterItemPtr ptr))param
               completion:(void (^)(BMXRoster *roster, BMXError *aError))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXRosterItemPtr rosterptr;
            floo::BMXErrorCode err = param(rosterptr);
            BMXRoster *roster;
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                roster = [[BMXRoster alloc] initWithBMXRosterPtr:rosterptr];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(roster, error);
            });
        });
    }
}


- (void)handleRosterParam:(floo::BMXRosterItemPtr (^)(floo::BMXErrorCode &error))param
               completion:(void (^)(BMXRoster *roster, BMXError *aError))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXErrorCode err;
            BMXRoster *roster;
            floo::BMXRosterItemPtr contact = param(err);
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                roster = [[BMXRoster alloc] initWithBMXRosterPtr:contact];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(roster, error);
            });
        });
    }
}

- (void)handleRoster:(floo::BMXErrorCode(^)(floo::BMXRosterItemPtr &itemPtr))param
               completion:(void (^)(BMXRoster *roster, BMXError *aError))aCompletionBlock {
    if (aCompletionBlock) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            floo::BMXRosterItemPtr rostPtr;
            floo::BMXErrorCode err = param(rostPtr);
            BMXRoster *roster;
            BMXError *error = [BMXError bmx_ErrorWith:err];
            if (!error) {
                roster = [[BMXRoster alloc] initWithBMXRosterPtr:rostPtr];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                aCompletionBlock(roster, error);
            });
        });
    }
}


@end


