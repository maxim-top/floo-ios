# BMXUserService Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 用户Service

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

添加用户状态监听者

`- (void)addDelegate:(id<BMXUserServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   用户状态监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:delegateQueue:" title="addDelegate:delegateQueue:"></a>
### addDelegate:delegateQueue:

`- (void)addDelegate:(id<BMXUserServiceProtocol>)*aDelegate* delegateQueue:(dispatch_queue_t)*aQueue*`

<a name="//api/name/bindDeviceWithToken:" title="bindDeviceWithToken:"></a>
### bindDeviceWithToken:

绑定设备推送token

`- (BMXErrorCode)bindDeviceWithToken:(NSString *)*token*`

#### Parameters

*token*  
   设备token  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/bindDeviceWithToken:completion:" title="bindDeviceWithToken:completion:"></a>
### bindDeviceWithToken:completion:

绑定设备推送token

`- (void)bindDeviceWithToken:(NSString *)*token* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*token*  
   设备token  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/deleteDeviceWithDeviceSn:" title="deleteDeviceWithDeviceSn:"></a>
### deleteDeviceWithDeviceSn:

删除设备

`- (BMXErrorCode)deleteDeviceWithDeviceSn:(int)*device_sn*`

#### Parameters

*device_sn*  
   设备序列号  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/deleteDeviceWithDeviceSn:completion:" title="deleteDeviceWithDeviceSn:completion:"></a>
### deleteDeviceWithDeviceSn:completion:

删除设备

`- (void)deleteDeviceWithDeviceSn:(int)*device_sn* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*device_sn*  
   设备序列号  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithProfile:thumbnail:callback:" title="downloadAvatarWithProfile:thumbnail:callback:"></a>
### downloadAvatarWithProfile:thumbnail:callback:

下载头像，默认下载缩略图

`- (BMXErrorCode)downloadAvatarWithProfile:(BMXUserProfile *)*profile* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback*`

#### Parameters

*profile*  
   用户profile  

*thumbnail*  
   是否下载缩略图，true下载缩略图，false下载原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithProfile:thumbnail:callback:completion:" title="downloadAvatarWithProfile:thumbnail:callback:completion:"></a>
### downloadAvatarWithProfile:thumbnail:callback:completion:

下载头像，默认下载缩略图

`- (void)downloadAvatarWithProfile:(BMXUserProfile *)*profile* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*profile*  
   用户profile  

*thumbnail*  
   是否下载缩略图，true下载缩略图，false下载原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDeviceList:" title="getDeviceList:"></a>
### getDeviceList:

获取设备列表

`- (BMXErrorCode)getDeviceList:(BMXDeviceList *)*deviceList*`

#### Parameters

*deviceList*  
   设备列表，传入空列表函数返回后从此处获取返回的设备列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDeviceListWithCompletion:" title="getDeviceListWithCompletion:"></a>
### getDeviceListWithCompletion:

获取设备列表

`- (void)getDeviceListWithCompletion:(void ( ^ ) ( BMXDeviceList *deviceList , BMXError *aError ))*resBlock*`

#### Parameters

*deviceList*  
   设备列表，传入空列表函数返回后从此处获取返回的设备列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getProfile:completion:" title="getProfile:completion:"></a>
### getProfile:completion:

获取用户详情，如果forceRefresh == true，则强制从服务端拉取

`- (void)getProfile:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXUserProfile *profile , BMXError *aError ))*resBlock*`

#### Parameters

*forceRefresh*  
   是否强制从服务器拉取，本地获取失败的情况下会自动从服务器拉取  

*profile*  
   用户profile信息，初始传入指向为空的shared_ptr对象，函数返回后从此处获取用户profile信息。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getProfile:forceRefresh:" title="getProfile:forceRefresh:"></a>
### getProfile:forceRefresh:

获取用户详情，如果forceRefresh == true，则强制从服务端拉取

`- (BMXErrorCode)getProfile:(BMXUserProfile *)*profile* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*profile*  
   用户profile信息，初始传入指向为空的shared_ptr对象，函数返回后从此处获取用户profile信息。  

*forceRefresh*  
   是否强制从服务器拉取，本地获取失败的情况下会自动从服务器拉取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/removeDelegate:" title="removeDelegate:"></a>
### removeDelegate:

移除用户状态监听者

`- (void)removeDelegate:(id<BMXUserServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   用户状态监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAddFriendAuthMode:" title="setAddFriendAuthMode:"></a>
### setAddFriendAuthMode:

设置加好友验证方式

`- (BMXErrorCode)setAddFriendAuthMode:(BMXUserProfile_AddFriendAuthMode)*mode*`

#### Parameters

*mode*  
   加好友验证方式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAddFriendAuthMode:completion:" title="setAddFriendAuthMode:completion:"></a>
### setAddFriendAuthMode:completion:

设置加好友验证方式

`- (void)setAddFriendAuthMode:(BMXUserProfile_AddFriendAuthMode)*mode* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*mode*  
   加好友验证方式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAuthQuestion:" title="setAuthQuestion:"></a>
### setAuthQuestion:

设置加好友验证问题

`- (BMXErrorCode)setAuthQuestion:(BMXUserProfileAuthQuestion *)*authQuestion*`

#### Parameters

*authQuestion*  
   加好友验证问题  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAuthQuestion:completion:" title="setAuthQuestion:completion:"></a>
### setAuthQuestion:completion:

设置加好友验证问题

`- (void)setAuthQuestion:(BMXUserProfileAuthQuestion *)*authQuestion* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*authQuestion*  
   加好友验证问题  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoAcceptGroupInvite:" title="setAutoAcceptGroupInvite:"></a>
### setAutoAcceptGroupInvite:

设置是否自动同意入群邀请

`- (BMXErrorCode)setAutoAcceptGroupInvite:(BOOL)*enable*`

#### Parameters

*enable*  
   是否自动同意入群邀请，true同意，false不同意  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoAcceptGroupInvite:completion:" title="setAutoAcceptGroupInvite:completion:"></a>
### setAutoAcceptGroupInvite:completion:

设置是否自动同意入群邀请

`- (void)setAutoAcceptGroupInvite:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   是否自动同意入群邀请，true同意，false不同意  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoDownloadAttachment:" title="setAutoDownloadAttachment:"></a>
### setAutoDownloadAttachment:

设置是否自动缩略图和语音附件

`- (BMXErrorCode)setAutoDownloadAttachment:(BOOL)*enable*`

#### Parameters

*enable*  
   是否自动缩略图和语音附件，true自动下载，false不会自动下载  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAutoDownloadAttachment:completion:" title="setAutoDownloadAttachment:completion:"></a>
### setAutoDownloadAttachment:completion:

设置是否自动缩略图和语音附件

`- (void)setAutoDownloadAttachment:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   是否自动缩略图和语音附件，true自动下载，false不会自动下载  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnablePush:" title="setEnablePush:"></a>
### setEnablePush:

设置是否允许推送

`- (BMXErrorCode)setEnablePush:(BOOL)*enable*`

#### Parameters

*enable*  
   是否允许推送，true推送，false不推送  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnablePush:completion:" title="setEnablePush:completion:"></a>
### setEnablePush:completion:

设置是否允许推送

`- (void)setEnablePush:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   是否允许推送，true推送，false不推送  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnablePushDetaile:" title="setEnablePushDetaile:"></a>
### setEnablePushDetaile:

设置是否推送详情

`- (BMXErrorCode)setEnablePushDetaile:(BOOL)*enable*`

#### Parameters

*enable*  
   是否推送详情，true推送，false不推送  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnablePushDetaile:completion:" title="setEnablePushDetaile:completion:"></a>
### setEnablePushDetaile:completion:

设置是否推送详情

`- (void)setEnablePushDetaile:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   是否推送详情，true推送，false不推送  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNickname:" title="setNickname:"></a>
### setNickname:

设置昵称

`- (BMXErrorCode)setNickname:(NSString *)*nickname*`

#### Parameters

*nickname*  
   用户昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNickname:completion:" title="setNickname:completion:"></a>
### setNickname:completion:

设置昵称

`- (void)setNickname:(NSString *)*nickname* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*nickname*  
   用户昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNotificationSound:" title="setNotificationSound:"></a>
### setNotificationSound:

设置收到新消息是否声音提醒

`- (BMXErrorCode)setNotificationSound:(BOOL)*enable*`

#### Parameters

*enable*  
   收到新消息是否声音提醒，true提醒，false不提醒  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNotificationSound:completion:" title="setNotificationSound:completion:"></a>
### setNotificationSound:completion:

设置收到新消息是否声音提醒

`- (void)setNotificationSound:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   收到新消息是否声音提醒，true提醒，false不提醒  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNotificationVibrate:" title="setNotificationVibrate:"></a>
### setNotificationVibrate:

设置收到新消息是否震动

`- (BMXErrorCode)setNotificationVibrate:(BOOL)*enable*`

#### Parameters

*enable*  
   收到新消息是否震动，true震动，false不震动  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setNotificationVibrate:completion:" title="setNotificationVibrate:completion:"></a>
### setNotificationVibrate:completion:

设置收到新消息是否震动

`- (void)setNotificationVibrate:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*enable*  
   收到新消息是否震动，true震动，false不震动  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPrivateInfo:" title="setPrivateInfo:"></a>
### setPrivateInfo:

设置私有扩展信息

`- (BMXErrorCode)setPrivateInfo:(NSString *)*privateInfo*`

#### Parameters

*privateInfo*  
   私有扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPrivateInfo:completion:" title="setPrivateInfo:completion:"></a>
### setPrivateInfo:completion:

设置私有扩展信息

`- (void)setPrivateInfo:(NSString *)*privateInfo* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*privateInfo*  
   私有扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPublicInfo:" title="setPublicInfo:"></a>
### setPublicInfo:

设置公开扩展信息

`- (BMXErrorCode)setPublicInfo:(NSString *)*publicInfo*`

#### Parameters

*publicInfo*  
   公开扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPublicInfo:completion:" title="setPublicInfo:completion:"></a>
### setPublicInfo:completion:

设置公开扩展信息

`- (void)setPublicInfo:(NSString *)*publicInfo* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*publicInfo*  
   公开扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushAlias:bmxPushToken:" title="setPushAlias:bmxPushToken:"></a>
### setPushAlias:bmxPushToken:

@brief

`- (BMXErrorCode)setPushAlias:(NSString *)*alias* bmxPushToken:(NSString *)*bmxPushToken*`

#### Parameters

*nickname*  
   推送昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Discussion
@brief

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushAlias:bmxPushToken:completion:" title="setPushAlias:bmxPushToken:completion:"></a>
### setPushAlias:bmxPushToken:completion:

@brief

`- (void)setPushAlias:(NSString *)*alias* bmxPushToken:(NSString *)*bmxPushToken* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*nickname*  
   推送昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Discussion
@brief

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushNickname:" title="setPushNickname:"></a>
### setPushNickname:

设置推送昵称

`- (BMXErrorCode)setPushNickname:(NSString *)*nickname*`

#### Parameters

*nickname*  
   推送昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushNickname:completion:" title="setPushNickname:completion:"></a>
### setPushNickname:completion:

设置推送昵称

`- (void)setPushNickname:(NSString *)*nickname* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*nickname*  
   推送昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/uploadAvatarWithAvatarPath:callback:" title="uploadAvatarWithAvatarPath:callback:"></a>
### uploadAvatarWithAvatarPath:callback:

上传头像

`- (BMXErrorCode)uploadAvatarWithAvatarPath:(NSString *)*avatarPath* callback:(void ( ^ ) ( int progress ))*callback*`

#### Parameters

*avatarPath*  
   上传头像的本地地址  

*callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/uploadAvatarWithAvatarPath:callback:completion:" title="uploadAvatarWithAvatarPath:callback:completion:"></a>
### uploadAvatarWithAvatarPath:callback:completion:

上传头像

`- (void)uploadAvatarWithAvatarPath:(NSString *)*avatarPath* callback:(void ( ^ ) ( int progress ))*callback* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*avatarPath*  
   上传头像的本地地址  

*callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

