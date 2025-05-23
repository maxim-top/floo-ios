# BMXFileAttachment Class Reference

  **Inherits from** <a href="../Classes/BMXMessageAttachment.md">BMXMessageAttachment</a> :   
<a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 消息文件附件

## Class Methods

<a name="//api/name/dynamicCastWithAttachment:" title="dynamicCastWithAttachment:"></a>
### dynamicCastWithAttachment:

消息附件强制转换为文件附件

`+ (BMXFileAttachment *)dynamicCastWithAttachment:(BMXMessageAttachment *)*attachment*`

#### Parameters

*attachment*  
   附件  

#### Return Value
BMXFileAttachment

#### Declared In
* `floo_proxy.h`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/clone" title="clone"></a>
### clone

`- (BMXMessageAttachment *)clone`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/displayName" title="displayName"></a>
### displayName

显示名

`- (NSString *)displayName`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadStatus" title="downloadStatus"></a>
### downloadStatus

附件下载状态

`- (BMXMessageAttachment_DownloadStatus)downloadStatus`

#### Return Value
<a href="../Constants/BMXMessageAttachment_DownloadStatus.md">BMXMessageAttachment_DownloadStatus</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fileLength" title="fileLength"></a>
### fileLength

文件长度

`- (long long)fileLength`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithData:displayName:conversationId:" title="initWithData:displayName:conversationId:"></a>
### initWithData:displayName:conversationId:

`- (id)initWithData:(NSData *)*aData* displayName:(NSString *)*displayName* conversationId:(long long)*conversationId*`

<a name="//api/name/initWithPath:" title="initWithPath:"></a>
### initWithPath:

`- (id)initWithPath:(NSString *)*path*`

<a name="//api/name/initWithPath:displayName:" title="initWithPath:displayName:"></a>
### initWithPath:displayName:

构造函数，构建发送文件消息附件

`- (id)initWithPath:(NSString *)*path* displayName:(NSString *)*displayName*`

#### Parameters

*path*  
   文件的本地路径  

*displayName*  
   文件展示名  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithRatelUrl:displayName:fileLength:" title="initWithRatelUrl:displayName:fileLength:"></a>
### initWithRatelUrl:displayName:fileLength:

构造函数，构建接收文件消息附件

`- (id)initWithRatelUrl:(NSString *)*ratelUrl* displayName:(NSString *)*displayName* fileLength:(long long)*fileLength*`

#### Parameters

*ratelUrl*  
   ratel文件服务器地址  

*displayName*  
   文件展示名  

*fileLength*  
   文件大小  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/path" title="path"></a>
### path

本地路径

`- (NSString *)path`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/ratelUrl" title="ratelUrl"></a>
### ratelUrl

远程ratel使用URL

`- (NSString *)ratelUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/type" title="type"></a>
### type

返回文件类型

`- (BMXMessageAttachment_Type)type`

#### Return Value
<a href="../Constants/BMXMessageAttachment_Type.md">BMXMessageAttachment_Type</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/url" title="url"></a>
### url

远程使用URL

`- (NSString *)url`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

