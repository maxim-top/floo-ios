# BMXVideoAttachment Class Reference

  **Inherits from** <a href="../Classes/BMXFileAttachment.md">BMXFileAttachment</a> :   
<a href="../Classes/BMXMessageAttachment.md">BMXMessageAttachment</a> :   
<a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 视频消息附件

## Class Methods

<a name="//api/name/dynamicCastWithAttachment:" title="dynamicCastWithAttachment:"></a>
### dynamicCastWithAttachment:

消息附件强制转换为视频附件

`+ (BMXVideoAttachment *)dynamicCastWithAttachment:(BMXMessageAttachment *)*attachment*`

#### Parameters

*attachment*  
   附件  

#### Return Value
BMXVideoAttachment

#### Declared In
* `floo_proxy.h`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/clone" title="clone"></a>
### clone

克隆函数

`- (BMXMessageAttachment *)clone`

#### Return Value
<a href="../Classes/BMXMessageAttachment.md">BMXMessageAttachment</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/duration" title="duration"></a>
### duration

视频片段时长

`- (int)duration`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithPath:duration:size:" title="initWithPath:duration:size:"></a>
### initWithPath:duration:size:

`- (id)initWithPath:(NSString *)*path* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size*`

<a name="//api/name/initWithPath:duration:size:displayName:" title="initWithPath:duration:size:displayName:"></a>
### initWithPath:duration:size:displayName:

构造函数，构建发送视频消息附件

`- (id)initWithPath:(NSString *)*path* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size* displayName:(NSString *)*displayName*`

#### Parameters

*path*  
   文件的本地路径  

*duration*  
   视频片段时长  

*size*  
   视频大小，宽度和高度  

*displayName*  
   文件展示名  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithPath:thumbnailPath:duration:size:" title="initWithPath:thumbnailPath:duration:size:"></a>
### initWithPath:thumbnailPath:duration:size:

`- (id)initWithPath:(NSString *)*path* thumbnailPath:(NSString *)*thumbnailPath* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size*`

<a name="//api/name/initWithPath:thumbnailPath:duration:size:displayName:" title="initWithPath:thumbnailPath:duration:size:displayName:"></a>
### initWithPath:thumbnailPath:duration:size:displayName:

构造函数，构建发送视频消息附件

`- (id)initWithPath:(NSString *)*path* thumbnailPath:(NSString *)*thumbnailPath* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size* displayName:(NSString *)*displayName*`

#### Parameters

*path*  
   文件的本地路径  

*thumbnailPath*  
   缩略图文件的本地路径  

*duration*  
   视频片段时长  

*size*  
   视频大小，宽度和高度  

*displayName*  
   文件展示名  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithRatelUrl:duration:size:displayName:fileLength:" title="initWithRatelUrl:duration:size:displayName:fileLength:"></a>
### initWithRatelUrl:duration:size:displayName:fileLength:

构造函数，构建接收视频消息附件

`- (id)initWithRatelUrl:(NSString *)*ratelUrl* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size* displayName:(NSString *)*displayName* fileLength:(long long)*fileLength*`

#### Parameters

*ratelUrl*  
   ratel文件服务器地址  

*duration*  
   视频片段时长  

*size*  
   视频大小，宽度和高度  

*displayName*  
   文件展示名  

*fileLength*  
   文件大小  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithRatelUrl:thumbnailRatelUrl:duration:size:displayName:fileLength:" title="initWithRatelUrl:thumbnailRatelUrl:duration:size:displayName:fileLength:"></a>
### initWithRatelUrl:thumbnailRatelUrl:duration:size:displayName:fileLength:

构造函数，构建接收视频消息附件

`- (id)initWithRatelUrl:(NSString *)*ratelUrl* thumbnailRatelUrl:(NSString *)*thumbnailRatelUrl* duration:(int)*duration* size:(BMXMessageAttachmentSize *)*size* displayName:(NSString *)*displayName* fileLength:(long long)*fileLength*`

#### Parameters

*ratelUrl*  
   ratel文件服务器地址  

*thumbnailRatelUrl*  
   缩略图ratel文件服务器地址  

*duration*  
   视频片段时长  

*size*  
   视频大小，宽度和高度  

*displayName*  
   文件展示名  

*fileLength*  
   文件大小  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setThumbnail:" title="setThumbnail:"></a>
### setThumbnail:

设置发送视频片段消息缩略图

`- (void)setThumbnail:(NSString *)*path*`

#### Parameters

*path*  
   视频片段消息缩略图  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setThumbnailRatelUrl:" title="setThumbnailRatelUrl:"></a>
### setThumbnailRatelUrl:

设置发送视频片段消息缩略图ratel服务器路径

`- (void)setThumbnailRatelUrl:(NSString *)*thumbnailRatelUrl*`

#### Parameters

*thumbnailRatelUrl*  
   视频片段消息缩略图服务器路径  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/size" title="size"></a>
### size

视频大小，宽度和高度

`- (BMXMessageAttachmentSize *)size`

#### Return Value
<a href="../Classes/BMXMessageAttachmentSize.md">BMXMessageAttachmentSize</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/thumbnailDownloadStatus" title="thumbnailDownloadStatus"></a>
### thumbnailDownloadStatus

缩略图下载状态

`- (BMXMessageAttachment_DownloadStatus)thumbnailDownloadStatus`

#### Return Value
DownloadStatus

#### Declared In
* `floo_proxy.h`

<a name="//api/name/thumbnailPath" title="thumbnailPath"></a>
### thumbnailPath

缩略图本地路径

`- (NSString *)thumbnailPath`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/thumbnailRatelUrl" title="thumbnailRatelUrl"></a>
### thumbnailRatelUrl

缩略图ratel服务器路径

`- (NSString *)thumbnailRatelUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/thumbnailUrl" title="thumbnailUrl"></a>
### thumbnailUrl

远程缩略图使用URL

`- (NSString *)thumbnailUrl`

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

