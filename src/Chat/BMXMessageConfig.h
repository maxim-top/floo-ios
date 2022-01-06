//
//  BMXMessageConfig.h
//  MaxIM
//
//  Created by 韩雨桐 on 2019/11/20.
//  Copyright © 2019 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMXMessageConfig : NSObject

@property (nonatomic, assign) BOOL mentionAll;
@property (nonatomic, strong) NSArray<NSString *> *mentionList;
@property (nonatomic,copy) NSString *mentionMessage;
@property (nonatomic,copy) NSString *pushMessage;
@property (nonatomic,copy) NSString *senderName;
@property (nonatomic, strong) NSArray<NSString *> *groupMemberList;

- (instancetype)initConfigWithMentionAll:(BOOL)isMentionAll;
- (void)addGroupMember:(NSString *)rosterId;
- (void)removeGroupMember:(NSString *)rosterId;
- (void)clealerGroupMemberList;
- (NSString*)username;

@end

NS_ASSUME_NONNULL_END
