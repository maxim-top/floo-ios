//
//  BMXMessageAttactment.h
//  MaxIM
//
//  Created by hyt on 2018/11/20.
//  Copyright © 2018年 hyt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BMXAttachmentType) {
    BMXMessageAttactmentTypeLocation,
    BMXMessageAttactmentTypeFile,
    BMXMessageAttactmentTypeVoice,
    BMXMessageAttactmentTypeImage,
    BMXMessageAttactmentTypeVideo
};

typedef NS_ENUM(NSUInteger, BMXAttachmentDownloadStatus) {
    BMXAttachmentDownloadStatusDownloaing,
    BMXAttachmentDownloadStatusSuccessed,
    BMXAttachmentDownloadStatusFailed,     // 下载失败
    BMXAttachmentDownloadStatusNotStart,   // 下载尚未开始
    BMXAttachmentDownloadStatusCanceled,    /// 下载被取消

};

/**
 * 消息附件
 **/
@interface BMXMessageAttachment : NSObject

@property (nonatomic) CGSize size;

- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
