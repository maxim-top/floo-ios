# BMXRTCEngine Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface RTC Engine

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/addDelegate:" title="addDelegate:"></a>
### addDelegate:

添加聊天监听者

`- (void)addDelegate:(id<BMXRTCEngineProtocol>)*aDelegate*`

#### Parameters

*listener*  
   聊天监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:delegateQueue:" title="addDelegate:delegateQueue:"></a>
### addDelegate:delegateQueue:

`- (void)addDelegate:(id<BMXRTCEngineProtocol>)*aDelegate* delegateQueue:(dispatch_queue_t)*aQueue*`

<a name="//api/name/addRTCEngineListener:" title="addRTCEngineListener:"></a>
### addRTCEngineListener:

`- (void)addRTCEngineListener:(id<BMXRTCEngineProtocol>)*listener*`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/destroy" title="destroy"></a>
### destroy

销毁音视频Engine

`- (void)destroy`

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getRTCConfig" title="getRTCConfig"></a>
### getRTCConfig

获取RTC设置

`- (BMXRTCConfig *)getRTCConfig`

#### Return Value
<a href="../Classes/BMXRTCConfig.md">BMXRTCConfig</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/joinRoomWithAuth:" title="joinRoomWithAuth:"></a>
### joinRoomWithAuth:

加入频道

`- (BMXErrorCode)joinRoomWithAuth:(BMXRoomAuth *)*auth*`

#### Parameters

*auth*  
   加入频道时的认证信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/leaveRoom" title="leaveRoom"></a>
### leaveRoom

离开频道

`- (BMXErrorCode)leaveRoom`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteLocalAudioWithMute:" title="muteLocalAudioWithMute:"></a>
### muteLocalAudioWithMute:

打开关闭本地音频

`- (BMXErrorCode)muteLocalAudioWithMute:(BOOL)*mute*`

#### Parameters

*mute*  
   true为打开，false为关闭  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteLocalVideoWithType:mute:" title="muteLocalVideoWithType:mute:"></a>
### muteLocalVideoWithType:mute:

打开关闭本地视频

`- (BMXErrorCode)muteLocalVideoWithType:(BMXVideoMediaType)*type* mute:(BOOL)*mute*`

#### Parameters

*type*  
   视频流类型  

*mute*  
   true为打开，false为关闭  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteRemoteAudioWithStream:mute:" title="muteRemoteAudioWithStream:mute:"></a>
### muteRemoteAudioWithStream:mute:

打开关闭远端音频

`- (BMXErrorCode)muteRemoteAudioWithStream:(BMXStream *)*stream* mute:(BOOL)*mute*`

#### Parameters

*stream*  
   远端流  

*mute*  
   true为打开，false为关闭  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteRemoteVideoWithStream:mute:" title="muteRemoteVideoWithStream:mute:"></a>
### muteRemoteVideoWithStream:mute:

打开关闭远端视频

`- (BMXErrorCode)muteRemoteVideoWithStream:(BMXStream *)*stream* mute:(BOOL)*mute*`

#### Parameters

*stream*  
   远端流  

*mute*  
   true为打开，false为关闭  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/publishWithType:hasVideo:hasAudio:" title="publishWithType:hasVideo:hasAudio:"></a>
### publishWithType:hasVideo:hasAudio:

发布流信息

`- (BMXErrorCode)publishWithType:(BMXVideoMediaType)*type* hasVideo:(BOOL)*hasVideo* hasAudio:(BOOL)*hasAudio*`

#### Parameters

*type*  
   流媒体类型  

*hasVideo*  
   是否存在视频流  

*hasAudio*  
   是否存在音频流  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeDelegate:" title="removeDelegate:"></a>
### removeDelegate:

移除聊天监听者

`- (void)removeDelegate:(id<BMXRTCEngineProtocol>)*aDelegate*`

#### Parameters

*listener*  
   聊天监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeRTCEngineListener:" title="removeRTCEngineListener:"></a>
### removeRTCEngineListener:

`- (void)removeRTCEngineListener:(id<BMXRTCEngineProtocol>)*listener*`

<a name="//api/name/setAudioProfile:" title="setAudioProfile:"></a>
### setAudioProfile:

设置音频编码格式

`- (BMXErrorCode)setAudioProfile:(BMXAudioProfile)*profile*`

#### Parameters

*profile*  
   音频编码格式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setRoomType:" title="setRoomType:"></a>
### setRoomType:

设置Room的类型

`- (BMXErrorCode)setRoomType:(BMXRoomType)*type*`

#### Parameters

*type*  
   Room类型  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setStreamRole:" title="setStreamRole:"></a>
### setStreamRole:

设置流操作权限

`- (BMXErrorCode)setStreamRole:(BMXStreamRole)*role*`

#### Parameters

*role*  
   操作权限，推流、拉流、推拉流。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setVideoCodec:" title="setVideoCodec:"></a>
### setVideoCodec:

设置视频编码格式类型

`- (BMXErrorCode)setVideoCodec:(BMXVideoCodec)*codec*`

#### Parameters

*codec*  
   VP8编码、H264编码  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setVideoProfile:" title="setVideoProfile:"></a>
### setVideoProfile:

设置视频编码格式类型

`- (BMXErrorCode)setVideoProfile:(BMXVideoConfig *)*videoConfig*`

#### Parameters

*codec*  
   VP8编码、H264编码  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/startPreviewWithCanvas:" title="startPreviewWithCanvas:"></a>
### startPreviewWithCanvas:

开启本地渲染

`- (BMXErrorCode)startPreviewWithCanvas:(BMXVideoCanvas *)*canvas*`

#### Parameters

*canvas*  
   画布属性信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/startRemoteViewWithCanvas:" title="startRemoteViewWithCanvas:"></a>
### startRemoteViewWithCanvas:

开启远端渲染

`- (BMXErrorCode)startRemoteViewWithCanvas:(BMXVideoCanvas *)*canvas*`

#### Parameters

*canvas*  
   画布属性信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/stopPreviewWithCanvas:" title="stopPreviewWithCanvas:"></a>
### stopPreviewWithCanvas:

停止本地渲染

`- (BMXErrorCode)stopPreviewWithCanvas:(BMXVideoCanvas *)*canvas*`

#### Parameters

*canvas*  
   画布属性信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/stopRemoteViewWithCanvas:" title="stopRemoteViewWithCanvas:"></a>
### stopRemoteViewWithCanvas:

停止远端渲染

`- (BMXErrorCode)stopRemoteViewWithCanvas:(BMXVideoCanvas *)*canvas*`

#### Parameters

*canvas*  
   画布属性信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/subscribeWithStream:" title="subscribeWithStream:"></a>
### subscribeWithStream:

订阅流信息

`- (BMXErrorCode)subscribeWithStream:(BMXStream *)*stream*`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/switchCamera" title="switchCamera"></a>
### switchCamera

切换摄像头

`- (BMXErrorCode)switchCamera`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unPublishWithType:" title="unPublishWithType:"></a>
### unPublishWithType:

停止发布流

`- (BMXErrorCode)unPublishWithType:(BMXVideoMediaType)*type*`

#### Parameters

*type*  
   流媒体类型  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unSubscribeWithStream:" title="unSubscribeWithStream:"></a>
### unSubscribeWithStream:

停止订阅流

`- (BMXErrorCode)unSubscribeWithStream:(BMXStream *)*stream*`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

