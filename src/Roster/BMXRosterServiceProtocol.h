//
// ----------------------------------------------------------------------
// File    : BMXRosterServiceProtocol.h
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

@class BMXRoster;

@protocol BMXRosterServiceProtocol <NSObject>

@optional

/**
 添加好友
 @param sponsorId 发起方
 @param recipientId 接受方
 */
- (void)friendAddedSponsorId:(long long)sponsorId recipientId:(long long)recipientId;

/**
    删除好友
 *  用户B删除与用户A的好友关系后，用户A会收到这个回调
 @param sponsorId 发起方
 @param recipientId 接受方
 */
- (void)friendRemovedSponsorId:(long long)sponsorId recipientId:(long long)recipientId;


/**
 *  收到加好友申请
 *  用户B申请加A为好友后，用户A会收到这个回调
 @param sponsorId 发起方
 @param recipientId 接受方
 @param message 好友邀请信息
 */
- (void)friendDidRecivedAppliedSponsorId:(long long)sponsorId
                             recipientId:(long long)recipientId
                                message:(NSString *)message;

/**
 * 加好友申请被通过了
 *  用户B同意用户A的加好友请求后，用户A会收到这个回调
 @param sponsorId 发起方
 @param recipientId 接受方
 */
- (void)friendDidApplicationAcceptedFromSponsorId:(long long)sponsorId
                                      recipientId:(long long)recipientId;

/**
 * 加好友申请被拒绝了
 * 用户B拒绝用户A的加好友请求后，用户A会收到这个回调
 @param sponsorId 发起方
 @param recipientId 接受方
 @param reason 拒绝理由
 */
- (void)friendDidApplicationDeclinedFromSponsorId:(long long)sponsorId
                                      recipientId:(long long)recipientId
                                       reson:(NSString *)reason;



/**
 * 添加黑名单

 @param sponsorId 发起方
 @param recipientId 接受方
 */
- (void)friendAddedtoBlockListSponsorId:(long long)sponsorId
                            recipientId:(long long)recipientId;


/**
 * 删除黑名单

 @param sponsorId 发起方
 @param recipientId  接受方
 */
- (void)friendRemovedFromBlockListSponsorId:(long long)sponsorId
                   recipientId:(long long)recipientId;

/**
 * 用户信息更新
 **/
- (void)rosterInfoDidUpdate:(BMXRoster *)roster;


@end

