# BMXRTCRoom Class Reference

  **Inherits from** <a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface RTC room(room 归属于某一个session，session不存在了room肯定不存在，room不存在时session可能存在)

## Instance Methods

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/isPrivate" title="isPrivate"></a>
### isPrivate

room 是否为私有

`- (BOOL)isPrivate`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/permanent" title="permanent"></a>
### permanent

room permanent 是否为永久性房间

`- (BOOL)permanent`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/pin" title="pin"></a>
### pin

room pin

`- (NSString *)pin`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/roomDescription" title="roomDescription"></a>
### roomDescription

room 描述

`- (NSString *)roomDescription`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/roomId" title="roomId"></a>
### roomId

`- (long long)roomId`

<a name="//api/name/roomPrivateId" title="roomPrivateId"></a>
### roomPrivateId

用户在当前的room中与当前用户唯一关联的id，在其它成员想要订阅当前用户在该room的pub流时必须使用该数字。现在不需要实现

`- (long long)roomPrivateId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/roomSecret" title="roomSecret"></a>
### roomSecret

room secret

`- (NSString *)roomSecret`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPin:" title="setPin:"></a>
### setPin:

设置room的pin。pin可以从IM的信令交互处获得。

`- (void)setPin:(NSString *)*pin*`

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setRoomSecret:" title="setRoomSecret:"></a>
### setRoomSecret:

设置room的secret。secret可以从IM的信令交互处获得

`- (void)setRoomSecret:(NSString *)*roomSecret*`

#### Declared In
* `floo_proxy.h`

