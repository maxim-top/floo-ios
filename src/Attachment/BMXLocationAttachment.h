//
//  BMXLocationAttachment.h
//  MaxIM
//
//  Created by hyt on 2018/11/17.
//  Copyright © 2018年 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMXMessageAttachment.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXLocationAttachment : BMXMessageAttachment

/*
 *  \~chinese
 *  纬度
 *
 *  \~english
 *  Location latitude
 */
@property (nonatomic) double latitude;

/*
 *  \~chinese
 *  经度
 *
 *  \~english
 *  Loctaion longitude
 */
@property (nonatomic) double longitude;

/**
 地址
 */
@property (nonatomic,copy) NSString *address;


/**
 初始化BMXLocationAttachment

 @param aLatitude 纬度
 @param aLongitude 经度
 @param aAddress 地址
 @return BMXLocationAttachment
 */
- (instancetype)initWithLatitude:(double)aLatitude
                       longitude:(double)aLongitude
                         address:(NSString *)aAddress;





@end

NS_ASSUME_NONNULL_END
