# BMXSDKConfigHostConfig Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface SDK设置管理

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

<a name="//api/name/getImHost" title="getImHost"></a>
### getImHost

`- (NSString *)getImHost`

<a name="//api/name/getImPort" title="getImPort"></a>
### getImPort

`- (int)getImPort`

<a name="//api/name/getRestHost" title="getRestHost"></a>
### getRestHost

`- (NSString *)getRestHost`

<a name="//api/name/init" title="init"></a>
### init

`- (id)init`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithIm:port:rest:" title="initWithIm:port:rest:"></a>
### initWithIm:port:rest:

构造函数

`- (id)initWithIm:(NSString *)*im* port:(int)*port* rest:(NSString *)*rest*`

#### Parameters

*im*  
   Fireplace 服务器地址  

*port*  
   Fireplace 服务器端口  

*rest*  
   Ratel 服务基地址  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setImHost:" title="setImHost:"></a>
### setImHost:

`- (void)setImHost:(NSString *)*value*`

<a name="//api/name/setImPort:" title="setImPort:"></a>
### setImPort:

`- (void)setImPort:(int)*value*`

<a name="//api/name/setRestHost:" title="setRestHost:"></a>
### setRestHost:

`- (void)setRestHost:(NSString *)*value*`

