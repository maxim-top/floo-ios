# BMXRTCConfig Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface RTC设置管理

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/getAudioOnlyMode" title="getAudioOnlyMode"></a>
### getAudioOnlyMode

获取是否纯音频模式

`- (BOOL)getAudioOnlyMode`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAutoPublishMode" title="getAutoPublishMode"></a>
### getAutoPublishMode

获取是否自动发布模式

`- (BOOL)getAutoPublishMode`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAutoSubscribeMode" title="getAutoSubscribeMode"></a>
### getAutoSubscribeMode

获取是否自动发布模式

`- (BOOL)getAutoSubscribeMode`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getEnableLocalAudio" title="getEnableLocalAudio"></a>
### getEnableLocalAudio

获取本地音频是否发布

`- (BOOL)getEnableLocalAudio`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getEnableLocalVideo" title="getEnableLocalVideo"></a>
### getEnableLocalVideo

获取本地视频是否发布

`- (BOOL)getEnableLocalVideo`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getLogLevel" title="getLogLevel"></a>
### getLogLevel

获取音视频日志等级

`- (BMXLogLevel)getLogLevel`

#### Return Value
<a href="../Constants/BMXLogLevel.md">BMXLogLevel</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getSDKMode" title="getSDKMode"></a>
### getSDKMode

获取音视频SDK模式

`- (BMXSDKMode)getSDKMode`

#### Return Value
<a href="../Constants/BMXSDKMode.md">BMXSDKMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getVersion" title="getVersion"></a>
### getVersion

获取音视频SDK版本号

`- (NSString *)getVersion`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/setAudioOnlyMode:" title="setAudioOnlyMode:"></a>
### setAudioOnlyMode:

设置是否纯音频模式

`- (void)setAudioOnlyMode:(BOOL)*audioOnly*`

#### Parameters

*bool*  
   是否纯音频  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoPublishMode:" title="setAutoPublishMode:"></a>
### setAutoPublishMode:

设置是否自动发布模式

`- (void)setAutoPublishMode:(BOOL)*autoPublish*`

#### Parameters

*bool*  
   是否自动发布  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoSubscribeMode:" title="setAutoSubscribeMode:"></a>
### setAutoSubscribeMode:

设置是否自动订阅模式

`- (void)setAutoSubscribeMode:(BOOL)*autoSubscribe*`

#### Parameters

*bool*  
   是否自动订阅  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableLocalAudio:" title="setEnableLocalAudio:"></a>
### setEnableLocalAudio:

设置本地音频是否发布

`- (void)setEnableLocalAudio:(BOOL)*enableLocalAudio*`

#### Parameters

*bool*  
   本地音频是否发布  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableLocalVideo:" title="setEnableLocalVideo:"></a>
### setEnableLocalVideo:

设置本地视频是否发布

`- (void)setEnableLocalVideo:(BOOL)*enableLocalVideo*`

#### Parameters

*enableLocalVideo*  
   本地视频是否发布  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setLogLevel:" title="setLogLevel:"></a>
### setLogLevel:

设置音视频log等级

`- (void)setLogLevel:(BMXLogLevel)*level*`

#### Parameters

*level*  
   log日志等级  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setSDKMode:" title="setSDKMode:"></a>
### setSDKMode:

设置音视频SDK模式

`- (void)setSDKMode:(BMXSDKMode)*mode*`

#### Parameters

*mode*  
   音视频模式  

#### Declared In
* `floo_proxy.h`

