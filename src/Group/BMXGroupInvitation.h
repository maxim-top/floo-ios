//
//  ----------------------------------------------------------------------
//   File    :  BMXGroupInvitation.h
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/5 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    BMXGroupInvitationStatusPending,
    BMXGroupInvitationStatusAccepted,
    BMXGroupInvitationStatusDeclined,
} BMXGroupInvitationStatus;

NS_ASSUME_NONNULL_BEGIN

@interface BMXGroupInvitation : NSObject

@property (nonatomic,assign, readonly) long long groupId;
@property (nonatomic,assign, readonly) long long inviterId;
@property (nonatomic,assign, readonly) long long expiredTime;
@property (nonatomic,copy, readonly) NSString *reason;
@property (nonatomic,assign, readonly) BMXGroupInvitationStatus invitationStatus;




@end

NS_ASSUME_NONNULL_END
