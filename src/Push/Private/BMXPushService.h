//
//  BMXPushService.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/8/21.
//  Copyright © 2020 hyt. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "BMXService.h"
#import "BMXPushServiceProtocol.h"
#import "BMXService.h"
#import "PushServiceListener.h"
#import "BMXDelegatesContainer.h"
#import "BMXPushManager.h"
NS_ASSUME_NONNULL_BEGIN



@class BMXClient;

@interface BMXPushService : BMXService <BMXPushManager>
{
    floosdk::PushServiceListener *pushListener;
}

@property (strong, nonatomic, readonly) BMXDelegatesContainer<BMXPushServiceProtocol> *container;

- (void)removePushListener;

@end


NS_ASSUME_NONNULL_END
