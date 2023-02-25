# BMXRoomModerateOptions Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface modeate操作类型，主要用于房间管理员禁言/解禁其他参与者操作。
mUserId 操作用户id
mMuteAudio 是否禁音频
mMuteVideo 是否禁视频
mMuteData 是否禁数据

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

<a name="//api/name/getMMuteAudio" title="getMMuteAudio"></a>
### getMMuteAudio

`- (BOOL)getMMuteAudio`

<a name="//api/name/getMMuteData" title="getMMuteData"></a>
### getMMuteData

`- (BOOL)getMMuteData`

<a name="//api/name/getMMuteVideo" title="getMMuteVideo"></a>
### getMMuteVideo

`- (BOOL)getMMuteVideo`

<a name="//api/name/getMUserId" title="getMUserId"></a>
### getMUserId

`- (long long)getMUserId`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithUserId:" title="initWithUserId:"></a>
### initWithUserId:

`- (id)initWithUserId:(long long)*userId*`

<a name="//api/name/initWithUserId:muteAudio:" title="initWithUserId:muteAudio:"></a>
### initWithUserId:muteAudio:

`- (id)initWithUserId:(long long)*userId* muteAudio:(BOOL)*muteAudio*`

<a name="//api/name/initWithUserId:muteAudio:muteVideo:" title="initWithUserId:muteAudio:muteVideo:"></a>
### initWithUserId:muteAudio:muteVideo:

`- (id)initWithUserId:(long long)*userId* muteAudio:(BOOL)*muteAudio* muteVideo:(BOOL)*muteVideo*`

<a name="//api/name/initWithUserId:muteAudio:muteVideo:muteData:" title="initWithUserId:muteAudio:muteVideo:muteData:"></a>
### initWithUserId:muteAudio:muteVideo:muteData:

`- (id)initWithUserId:(long long)*userId* muteAudio:(BOOL)*muteAudio* muteVideo:(BOOL)*muteVideo* muteData:(BOOL)*muteData*`

<a name="//api/name/setMMuteAudio:" title="setMMuteAudio:"></a>
### setMMuteAudio:

`- (void)setMMuteAudio:(BOOL)*value*`

<a name="//api/name/setMMuteData:" title="setMMuteData:"></a>
### setMMuteData:

`- (void)setMMuteData:(BOOL)*value*`

<a name="//api/name/setMMuteVideo:" title="setMMuteVideo:"></a>
### setMMuteVideo:

`- (void)setMMuteVideo:(BOOL)*value*`

<a name="//api/name/setMUserId:" title="setMUserId:"></a>
### setMUserId:

`- (void)setMUserId:(long long)*value*`

