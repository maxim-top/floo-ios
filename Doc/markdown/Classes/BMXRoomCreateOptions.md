# BMXRoomCreateOptions Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 创建房间参数信息
mRoomId 房间ID
mDescription 房间描述
mSecret 修改或者删除房间需要的密钥
mPin 加密房间的pin码
mIsPermanent 是否是永久存在的房间(默认false)
mIsPrivate 是否是私有的不可在列表中展示的（默认true）

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

<a name="//api/name/getMDescription" title="getMDescription"></a>
### getMDescription

`- (NSString *)getMDescription`

<a name="//api/name/getMIsPermanent" title="getMIsPermanent"></a>
### getMIsPermanent

`- (BOOL)getMIsPermanent`

<a name="//api/name/getMIsPrivate" title="getMIsPrivate"></a>
### getMIsPrivate

`- (BOOL)getMIsPrivate`

<a name="//api/name/getMPin" title="getMPin"></a>
### getMPin

`- (NSString *)getMPin`

<a name="//api/name/getMRoomId" title="getMRoomId"></a>
### getMRoomId

`- (long long)getMRoomId`

<a name="//api/name/getMSecret" title="getMSecret"></a>
### getMSecret

`- (NSString *)getMSecret`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithRoomId:" title="initWithRoomId:"></a>
### initWithRoomId:

`- (id)initWithRoomId:(int)*roomId*`

<a name="//api/name/initWithRoomId:description:" title="initWithRoomId:description:"></a>
### initWithRoomId:description:

`- (id)initWithRoomId:(int)*roomId* description:(NSString *)*description*`

<a name="//api/name/initWithRoomId:description:secret:" title="initWithRoomId:description:secret:"></a>
### initWithRoomId:description:secret:

`- (id)initWithRoomId:(int)*roomId* description:(NSString *)*description* secret:(NSString *)*secret*`

<a name="//api/name/initWithRoomId:description:secret:pin:" title="initWithRoomId:description:secret:pin:"></a>
### initWithRoomId:description:secret:pin:

`- (id)initWithRoomId:(int)*roomId* description:(NSString *)*description* secret:(NSString *)*secret* pin:(NSString *)*pin*`

<a name="//api/name/initWithRoomId:description:secret:pin:isPermanent:" title="initWithRoomId:description:secret:pin:isPermanent:"></a>
### initWithRoomId:description:secret:pin:isPermanent:

`- (id)initWithRoomId:(int)*roomId* description:(NSString *)*description* secret:(NSString *)*secret* pin:(NSString *)*pin* isPermanent:(BOOL)*isPermanent*`

<a name="//api/name/initWithRoomId:description:secret:pin:isPermanent:isPrivate:" title="initWithRoomId:description:secret:pin:isPermanent:isPrivate:"></a>
### initWithRoomId:description:secret:pin:isPermanent:isPrivate:

`- (id)initWithRoomId:(int)*roomId* description:(NSString *)*description* secret:(NSString *)*secret* pin:(NSString *)*pin* isPermanent:(BOOL)*isPermanent* isPrivate:(BOOL)*isPrivate*`

<a name="//api/name/setMDescription:" title="setMDescription:"></a>
### setMDescription:

`- (void)setMDescription:(NSString *)*value*`

<a name="//api/name/setMIsPermanent:" title="setMIsPermanent:"></a>
### setMIsPermanent:

`- (void)setMIsPermanent:(BOOL)*value*`

<a name="//api/name/setMIsPrivate:" title="setMIsPrivate:"></a>
### setMIsPrivate:

`- (void)setMIsPrivate:(BOOL)*value*`

<a name="//api/name/setMPin:" title="setMPin:"></a>
### setMPin:

`- (void)setMPin:(NSString *)*value*`

<a name="//api/name/setMRoomId:" title="setMRoomId:"></a>
### setMRoomId:

`- (void)setMRoomId:(long long)*value*`

<a name="//api/name/setMSecret:" title="setMSecret:"></a>
### setMSecret:

`- (void)setMSecret:(NSString *)*value*`

