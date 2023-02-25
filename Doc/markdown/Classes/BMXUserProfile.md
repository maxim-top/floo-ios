# BMXUserProfile Class Reference

  **Inherits from** <a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 用户Profile

## Instance Methods

<a name="//api/name/addFriendAuthMode" title="addFriendAuthMode"></a>
### addFriendAuthMode

加好友校验方式

`- (BMXUserProfile_AddFriendAuthMode)addFriendAuthMode`

#### Return Value
<a href="../Constants/BMXUserProfile_AddFriendAuthMode.md">BMXUserProfile_AddFriendAuthMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/authQuestion" title="authQuestion"></a>
### authQuestion

添加好友时的验证问题

`- (BMXUserProfileAuthQuestion *)authQuestion`

#### Return Value
AuthQuestion

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarPath" title="avatarPath"></a>
### avatarPath

用户头像本地存储路径

`- (NSString *)avatarPath`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarRatelUrl" title="avatarRatelUrl"></a>
### avatarRatelUrl

用户ratel服务器头像url

`- (NSString *)avatarRatelUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarThumbnailPath" title="avatarThumbnailPath"></a>
### avatarThumbnailPath

用户头像缩略图本地存储路径

`- (NSString *)avatarThumbnailPath`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarUrl" title="avatarUrl"></a>
### avatarUrl

用户头像url

`- (NSString *)avatarUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/category" title="category"></a>
### category

用户策略

`- (BMXUserProfile_UserCategory)category`

#### Return Value
<a href="../Constants/BMXUserProfile_UserCategory.md">BMXUserProfile_UserCategory</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/email" title="email"></a>
### email

用户邮箱

`- (NSString *)email`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/isAutoAcceptGroupInvite" title="isAutoAcceptGroupInvite"></a>
### isAutoAcceptGroupInvite

收到群组邀请进群时是否自动同意进群

`- (BOOL)isAutoAcceptGroupInvite`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/messageSetting" title="messageSetting"></a>
### messageSetting

用户消息设定

`- (BMXUserProfileMessageSetting *)messageSetting`

#### Return Value
<a href="../Classes/BMXUserProfileMessageSetting.md">BMXUserProfileMessageSetting</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/mobilePhone" title="mobilePhone"></a>
### mobilePhone

用户手机

`- (NSString *)mobilePhone`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/nickname" title="nickname"></a>
### nickname

用户昵称

`- (NSString *)nickname`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/privateInfo" title="privateInfo"></a>
### privateInfo

用户私有扩展信息，好友不可见

`- (NSString *)privateInfo`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/publicInfo" title="publicInfo"></a>
### publicInfo

用户公开扩展信息，好友可见

`- (NSString *)publicInfo`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/userId" title="userId"></a>
### userId

用户ID（唯一）

`- (long long)userId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/username" title="username"></a>
### username

用户名（唯一）

`- (NSString *)username`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

