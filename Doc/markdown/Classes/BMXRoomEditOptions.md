# BMXRoomEditOptions Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 编辑房间参数信息
mNewDescription 新修改房间描述
mNewSecret 新修改房间属性所需密钥
mNewPin 新pin码
mNewIsPermanent 修改的是否是永久存在的房间属性(默认false)
mNewIsPrivate 修改的是否是私有的不可在列表中展示的属性（默认true）

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

<a name="//api/name/getMNewDescription" title="getMNewDescription"></a>
### getMNewDescription

`- (NSString *)getMNewDescription`

<a name="//api/name/getMNewIsPermanent" title="getMNewIsPermanent"></a>
### getMNewIsPermanent

`- (BOOL)getMNewIsPermanent`

<a name="//api/name/getMNewIsPrivate" title="getMNewIsPrivate"></a>
### getMNewIsPrivate

`- (BOOL)getMNewIsPrivate`

<a name="//api/name/getMNewPin" title="getMNewPin"></a>
### getMNewPin

`- (NSString *)getMNewPin`

<a name="//api/name/getMNewSecret" title="getMNewSecret"></a>
### getMNewSecret

`- (NSString *)getMNewSecret`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithNewDescription:" title="initWithNewDescription:"></a>
### initWithNewDescription:

`- (id)initWithNewDescription:(NSString *)*newDescription*`

<a name="//api/name/initWithNewDescription:newSecret:" title="initWithNewDescription:newSecret:"></a>
### initWithNewDescription:newSecret:

`- (id)initWithNewDescription:(NSString *)*newDescription* newSecret:(NSString *)*newSecret*`

<a name="//api/name/initWithNewDescription:newSecret:newPin:" title="initWithNewDescription:newSecret:newPin:"></a>
### initWithNewDescription:newSecret:newPin:

`- (id)initWithNewDescription:(NSString *)*newDescription* newSecret:(NSString *)*newSecret* newPin:(NSString *)*newPin*`

<a name="//api/name/initWithNewDescription:newSecret:newPin:newIsPermanent:" title="initWithNewDescription:newSecret:newPin:newIsPermanent:"></a>
### initWithNewDescription:newSecret:newPin:newIsPermanent:

`- (id)initWithNewDescription:(NSString *)*newDescription* newSecret:(NSString *)*newSecret* newPin:(NSString *)*newPin* newIsPermanent:(BOOL)*newIsPermanent*`

<a name="//api/name/initWithNewDescription:newSecret:newPin:newIsPermanent:newIsPrivate:" title="initWithNewDescription:newSecret:newPin:newIsPermanent:newIsPrivate:"></a>
### initWithNewDescription:newSecret:newPin:newIsPermanent:newIsPrivate:

`- (id)initWithNewDescription:(NSString *)*newDescription* newSecret:(NSString *)*newSecret* newPin:(NSString *)*newPin* newIsPermanent:(BOOL)*newIsPermanent* newIsPrivate:(BOOL)*newIsPrivate*`

<a name="//api/name/setMNewDescription:" title="setMNewDescription:"></a>
### setMNewDescription:

`- (void)setMNewDescription:(NSString *)*value*`

<a name="//api/name/setMNewIsPermanent:" title="setMNewIsPermanent:"></a>
### setMNewIsPermanent:

`- (void)setMNewIsPermanent:(BOOL)*value*`

<a name="//api/name/setMNewIsPrivate:" title="setMNewIsPrivate:"></a>
### setMNewIsPrivate:

`- (void)setMNewIsPrivate:(BOOL)*value*`

<a name="//api/name/setMNewPin:" title="setMNewPin:"></a>
### setMNewPin:

`- (void)setMNewPin:(NSString *)*value*`

<a name="//api/name/setMNewSecret:" title="setMNewSecret:"></a>
### setMNewSecret:

`- (void)setMNewSecret:(NSString *)*value*`

