# BMXPubRoomJoinOptions Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 发布模式加入房间的参数
mUserId 用户id
mRoomId 准备加入的roomId
mRoomPin 准备加入的room的pin，可选
mDescription 用户描述，可选
mToken 用户token，可选

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

<a name="//api/name/getMRoomId" title="getMRoomId"></a>
### getMRoomId

`- (long long)getMRoomId`

<a name="//api/name/getMRoomPin" title="getMRoomPin"></a>
### getMRoomPin

`- (NSString *)getMRoomPin`

<a name="//api/name/getMToken" title="getMToken"></a>
### getMToken

`- (NSString *)getMToken`

<a name="//api/name/getMUserId" title="getMUserId"></a>
### getMUserId

`- (long long)getMUserId`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithUserId:roomId:" title="initWithUserId:roomId:"></a>
### initWithUserId:roomId:

`- (id)initWithUserId:(long long)*userId* roomId:(long long)*roomId*`

<a name="//api/name/initWithUserId:roomId:pin:" title="initWithUserId:roomId:pin:"></a>
### initWithUserId:roomId:pin:

`- (id)initWithUserId:(long long)*userId* roomId:(long long)*roomId* pin:(NSString *)*pin*`

<a name="//api/name/initWithUserId:roomId:pin:description:" title="initWithUserId:roomId:pin:description:"></a>
### initWithUserId:roomId:pin:description:

`- (id)initWithUserId:(long long)*userId* roomId:(long long)*roomId* pin:(NSString *)*pin* description:(NSString *)*description*`

<a name="//api/name/initWithUserId:roomId:pin:description:token:" title="initWithUserId:roomId:pin:description:token:"></a>
### initWithUserId:roomId:pin:description:token:

`- (id)initWithUserId:(long long)*userId* roomId:(long long)*roomId* pin:(NSString *)*pin* description:(NSString *)*description* token:(NSString *)*token*`

<a name="//api/name/setMDescription:" title="setMDescription:"></a>
### setMDescription:

`- (void)setMDescription:(NSString *)*value*`

<a name="//api/name/setMRoomId:" title="setMRoomId:"></a>
### setMRoomId:

`- (void)setMRoomId:(long long)*value*`

<a name="//api/name/setMRoomPin:" title="setMRoomPin:"></a>
### setMRoomPin:

`- (void)setMRoomPin:(NSString *)*value*`

<a name="//api/name/setMToken:" title="setMToken:"></a>
### setMToken:

`- (void)setMToken:(NSString *)*value*`

<a name="//api/name/setMUserId:" title="setMUserId:"></a>
### setMUserId:

`- (void)setMUserId:(long long)*value*`

