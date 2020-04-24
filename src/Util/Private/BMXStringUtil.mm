// ----------------------------------------------------------------------
// File    : BMXStringUtil.m
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

#import "BMXStringUtil.h"



@implementation BMXStringUtil

+ (std::string)toStdString:(NSString *)aStr {
    id value = aStr;
    if (value == [NSNull null] || aStr == nil) {
        aStr = @"";
    }
    
    return [aStr UTF8String];
}

+ (NSString *)stdToNSString:(const std::string&)aStr {
    NSString *ret = [NSString stringWithUTF8String:aStr.c_str()];
    return ret ? ret : @"";
}


+ (NSString *)cacheFilePath {
    
    return @"";
    
//    NSString *uuidString = [NSString stringWithFormat:@"%@", [[NSUUID new] UUIDString]];
//    NSString *name = [uuidString stringByAppendingString:@".png"];
    
//    NSString *bufferDir = [BMXStringUtil dataBufferPath];
//    NSString *filePath = [[NSString alloc] initWithFormat:@"%@/%@", bufferDir, name];
    
    
//    return filePath;
    
//    //sdkconfig path
//    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
//    path = [path stringByAppendingPathComponent:@"flooSDK"];
//
//    NSFileManager *fileManager = [NSFileManager defaultManager];
//    if (![fileManager fileExistsAtPath:path]) {
//        [fileManager createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
//    }

    
    
//    NSString* srcPath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"jpeg" inDirectory:nil forLocalization:nil];
//    std::string base = _client->getChatService().attachmentDir();
//    std::string cp = _client->getChatService().attachmentDirForConversation(toId);
//    std::string name = [[[NSUUID new] UUIDString] STDString] + ".png";
//    std::string dstPath = base + cp + name;
//    [[NSFileManager defaultManager] copyItemAtPath:srcPath toPath:[NSString stringFromSTDString:dstPath] error:nil];
    
    
}


//+ (NSString *)dataBufferPath {
//    NSString *workPath = [[EMClient sharedClient].options workPath];
//    NSString *bufferDir = [workPath stringByAppendingString:@"/chatbuffer"];
//    NSFileManager *fm = [NSFileManager defaultManager];
//    if (![fm fileExistsAtPath:bufferDir]) {
//        [fm createDirectoryAtPath:bufferDir withIntermediateDirectories:YES attributes:nil error:nil];
//    }
//
//    return bufferDir;
//}

@end
