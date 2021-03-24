// ----------------------------------------------------------------------
// File    : BMXSDKConfig.m
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/24 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXSDKConfig.h"
#import "BMXSDKConfig+Private.h"
#include "bmx_sdk_config.h"
#import "BMXDefinesTransform.h"
#import "BMXStringUtil.h"
#import "BMXHostConfig.h"
#import "BMXHostConfig+Private.h"

#import <UIKit/UIKit.h>


#define SDKVersion  @""

@interface BMXSDKConfig ()

@property (nonatomic, assign) floo::BMXSDKConfigPtr ptr;

@end

@implementation BMXSDKConfig

- (instancetype)initConfigWithDataDir:(NSString *)dataDir
                             cacheDir:(NSString *)cacheDir
                         pushCertName:(NSString *)pushCertName
                            userAgent:(NSString *)userAgent {
    if (self = [super init]) {
        floo::BMXClientType type = floo::BMXClientType::iOS;
        std::string dataDirStr = dataDir ? [dataDir cStringUsingEncoding:NSUTF8StringEncoding] : "";
        std::string cacheDirStr = cacheDir ? [cacheDir cStringUsingEncoding:NSUTF8StringEncoding] : "";
        NSString* phoneVersion = [[UIDevice currentDevice] systemVersion];
        NSLog(@"手机系统版本: %@", phoneVersion);
        
        // app版本
        NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
        NSString *app_Version = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
        self.ptr = floo:: BMXSDKConfigPtr(new floo::BMXSDKConfig(type,
                                                                   [BMXStringUtil toStdString:phoneVersion],
                                                                   dataDirStr,
                                                                   cacheDirStr,
                                                                   [BMXStringUtil toStdString:app_Version],
                                                                   [BMXStringUtil toStdString:pushCertName],
                                                                   [BMXStringUtil toStdString:userAgent]));
    }
    return self;
}

- (BOOL)enableDeliveryAck {
    return (BOOL)self.ptr->enableDeliveryAck();
}

- (BOOL)consoleOutput {
    return (BOOL)self.ptr->getConsoleOutput();
}

- (NSString *)userAgent {
    return [BMXStringUtil stdToNSString:self.ptr->getUserAgent()];
}

- (NSString *)dataDir {
    return [NSString stringWithUTF8String:self.ptr->getDataDir().c_str()];
}

- (NSString *)cacheDir {
    return [NSString stringWithUTF8String:self.ptr->getCacheDir().c_str()];
}

- (NSString *)vsn {
    return [NSString stringWithUTF8String:self.ptr->getVsn().c_str()];
}

- (NSString *)sdkVersion {
    return [BMXStringUtil stdToNSString:self.ptr->getSDKVersion()];
}

- (NSString *)pushCertName {
    return [BMXStringUtil stdToNSString:self.ptr->getPushCertName()];
}

- (BMXLogLevel)logoLevelType {
    return [BMXDefinesTransform transformBMXLogLevel:self.ptr->getLogLevel()];
}

- (BOOL)loadAllServerConversations {
    return (BOOL)self.ptr->getLoadAllServerConversations();
}

- (NSString *)deviceUUID {
    return [BMXStringUtil stdToNSString:self.ptr->getDeviceUuid()];
}

- (BMXHostConfig *)hostConfig {
    
//    NSString *rest = [BMXStringUtil stdToNSString:self.ptr->getHostConfig().restHost];
//    NSString *import = [NSString stringWithFormat:@"%d", self.ptr->getHostConfig().imPort];
//    NSString *imHost = [BMXStringUtil stdToNSString:self.ptr->getHostConfig().imHost];
    
    return [[BMXHostConfig alloc] initWithBMXHostConfigPtr:self.ptr->getHostConfig()];
}

- (BOOL)verifyCertificate {
    return (BOOL)self.ptr->getVerifyCertificate();
}


- (BOOL)enableDNS {
    return (BOOL)self.ptr->getEnableDNS();
}

- (NSString *)userDNSAddress {
    return [BMXStringUtil stdToNSString:self.ptr->getUserDNSAddress()];
}

- (NSString *)appID {
    return [BMXStringUtil stdToNSString:self.ptr->getAppID()];
}

- (NSString *)appSecret {
    return [BMXStringUtil stdToNSString:self.ptr->getAppSecret()];
}

- (NSString *)debugLogRecevierID {
    return [NSString stringWithFormat:@"%lld", self.ptr->getDebugLogReceiverId()];
}

- (void)setEnableDeliveryAck:(BOOL)enableDeliveryAck {
    self.ptr -> setEnableDeliveryAck((bool)enableDeliveryAck);
}

- (void)setLogoLevelType:(BMXLogLevel)logoLevelType {
    self.ptr -> setLogLevel([BMXDefinesTransform oc_transformBMXLogLevel:logoLevelType]);
}

- (void)setConsoleOutput:(BOOL)ConsoleOutput {
    self.ptr -> setConsoleOutput((bool)ConsoleOutput);
}

- (void)setHostConfig:(BMXHostConfig *)hostConfig {
    self.ptr -> setHostConfig([hostConfig getHostConfig]);
}

- (void)setLoadAllServerConversations:(BOOL)loadAllServerConversations {
    self.ptr -> setLoadAllServerConversations((bool)loadAllServerConversations);
}

- (void)setDeviceUUID:(NSString *)deviceUUID {
    self.ptr->setDeviceUuid([BMXStringUtil toStdString:deviceUUID]);
}

- (void)setVerifyCertificate:(BOOL)verifyCertificate {
    self.ptr->setVerifyCertificate((bool)verifyCertificate);
}

- (void)setEnableDNS:(BOOL)enableDNS {
    self.ptr->setEnableDNS((bool)enableDNS);
}

- (void)setUserDNSAddress:(NSString *)userDNSAddress {
    self.ptr->setUserDNSAddress([BMXStringUtil toStdString:userDNSAddress]);
}

- (void)setAppID:(NSString *)appID {
    self.ptr->setAppID([BMXStringUtil toStdString:appID]);
}

- (void)setDebugLogRecevierID:(NSString *)debugLogRecevierID {
    self.ptr->setDebugLogReceiverId((int64_t)[debugLogRecevierID integerValue]);
}

- (void)setPushCertName:(NSString *)pushCertName {
    self.ptr->setPushCertName([BMXStringUtil toStdString:pushCertName]);
}

- (void)setAppSecret:(NSString *)appSecret {
    self.ptr->setAppSecret([BMXStringUtil toStdString:appSecret]);
}

@end

@implementation BMXSDKConfig (Private)



- (floo::BMXSDKConfigPtr)getBMXSDKConfigPtr {
    return _ptr;
}

- (nonnull instancetype)initWith:(floo::BMXSDKConfigPtr)configPtr {
    if (self = [super init]) {
        _ptr= configPtr;
    }
    return self;

}

@end
