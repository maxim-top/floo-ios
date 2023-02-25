# BMXDevice Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 设备信息

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

<a name="//api/name/deviceSN" title="deviceSN"></a>
### deviceSN

设备序列号

`- (int)deviceSN`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/isCurrentDevice" title="isCurrentDevice"></a>
### isCurrentDevice

是否是当前设备

`- (BOOL)isCurrentDevice`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/platform" title="platform"></a>
### platform

软件平台

`- (int)platform`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setUserAgent:" title="setUserAgent:"></a>
### setUserAgent:

设置用户代理信息

`- (void)setUserAgent:(NSString *)*userAgent*`

#### Parameters

*userAgent*  
   用户代理信息  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/userAgent" title="userAgent"></a>
### userAgent

用户代理信息

`- (NSString *)userAgent`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/userId" title="userId"></a>
### userId

用户id

`- (long long)userId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

