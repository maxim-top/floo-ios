// ----------------------------------------------------------------------
// File    : BMXFileAttachment.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/20 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

//

#import "BMXMessageAttachment.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMXFileAttachment : BMXMessageAttachment


/**
 本地路径
 */
@property (nonatomic,copy) NSString *path;

/**
 显示名称
 */
@property (nonatomic,copy) NSString *displayName;

/**
 文件url
 */
@property (nonatomic,copy) NSString *url;

/**
 文件大小
 */
@property (nonatomic,assign) long long fileLength;

/**
 下载状态
 */
@property (nonatomic,assign) BMXAttachmentDownloadStatus downLoadStatus;


/**
 初始化文件BMXFileAttachment

 @param aData 文件数据
 @param displayName 文件名称
 @param conversationId 会话id
 @return BMXFileAttachment
 */
- (instancetype)initWithData:(NSData *)aData
                   displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId;

/// 初始化文件BMXFileAttachment
/// @param path 文件路径
/// @param displayName 文件名称
/// @param conversationId 会话id
- (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
              conversationId:(NSString *)conversationId;



@end

NS_ASSUME_NONNULL_END
