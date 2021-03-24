

//
//  ----------------------------------------------------------------------
//   File    :  BMXHostConfig.m
//   Author  : HYT yutong@bmxlabs.com
//   Purpose :
//   Created : 2019/1/4 by HYT yutong@bmxlabs.com
//
//  ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//  ----------------------------------------------------------------------
    

#import "BMXHostConfig.h"
#import "BMXStringUtil.h"
#include "bmx_sdk_config.h"
#import "BMXHostConfig+Private.h"

@interface BMXHostConfig ()

@property (nonatomic,assign) floo::BMXSDKConfig::HostConfig hostConfig;

@end

@implementation BMXHostConfig


- (instancetype)initWithRestHostConfig:(NSString *)restHost imPort:(int)imPort imHost:(NSString *)imHost {
    if (self = [super init]) {
        self.hostConfig = floo::BMXSDKConfig::HostConfig([BMXStringUtil toStdString:imHost], imPort, [BMXStringUtil toStdString:restHost]);
    }
    return self;
}

- (void)setMPort:(int)mPort {
    _hostConfig.imPort = mPort;
}

- (void)setImHost:(NSString *)imHost {
    _hostConfig.imHost = [BMXStringUtil toStdString:imHost];
}

- (void)setRestHost:(NSString *)restHost {
    _hostConfig.restHost = [BMXStringUtil toStdString:restHost];
}

- (NSString *)restHost {
    return [BMXStringUtil stdToNSString:_hostConfig.restHost];
    
}

- (NSString *)imHost {
    return [BMXStringUtil stdToNSString:_hostConfig.imHost];

}

- (int)mPort {
    return _hostConfig.imPort;

}
@end

@implementation BMXHostConfig (Private)

- (floo::BMXSDKConfig::HostConfig)getHostConfig {
    return _hostConfig;
}

- (instancetype)initWithBMXHostConfigPtr:(floo::BMXSDKConfig::HostConfig)hostConfig {
    if (self = [super init]) {
        _hostConfig = hostConfig;
    }
    return self;

}


@end
