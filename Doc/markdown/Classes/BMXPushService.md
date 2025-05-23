# BMXPushService Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 推送Service

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/bindDeviceTokenWithToken:" title="bindDeviceTokenWithToken:"></a>
### bindDeviceTokenWithToken:

推送绑定设备token。

`- (BMXErrorCode)bindDeviceTokenWithToken:(NSString *)*token*`

#### Parameters

*token*  
   设备的推送token  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/bindVoipTokenWithToken:" title="bindVoipTokenWithToken:"></a>
### bindVoipTokenWithToken:

推送绑定设备token。

`- (BMXErrorCode)bindVoipTokenWithToken:(NSString *)*token*`

#### Parameters

*token*  
   设备的推送token  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/clearAllNotifications" title="clearAllNotifications"></a>
### clearAllNotifications

清空下拉通知栏全部通知。

`- (void)clearAllNotifications`

#### Declared In
* `floo_proxy.h`

<a name="//api/name/clearNotificationWithNotificationId:" title="clearNotificationWithNotificationId:"></a>
### clearNotificationWithNotificationId:

清除指定id的通知。

`- (void)clearNotificationWithNotificationId:(long long)*notificationId*`

#### Parameters

*notificationId*  
   通知id  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/clearTagsWithOperationId:" title="clearTagsWithOperationId:"></a>
### clearTagsWithOperationId:

清空推送用户的标签。

`- (BMXErrorCode)clearTagsWithOperationId:(NSString *)*operationId*`

#### Parameters

*operationId*  
   操作id。在回调通知中对应通知提醒。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/deleteTagsWithTags:operationId:" title="deleteTagsWithTags:operationId:"></a>
### deleteTagsWithTags:operationId:

删除推送用户的标签。

`- (BMXErrorCode)deleteTagsWithTags:(TagList *)*tags* operationId:(NSString *)*operationId*`

#### Parameters

*tags*  
   要删除用户标签  

*operationId*  
   操作id。在回调通知中对应通知提醒。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getCert" title="getCert"></a>
### getCert

获取登陆后服务器返回的推送证书。

`- (NSString *)getCert`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getPushProfile:forceRefresh:" title="getPushProfile:forceRefresh:"></a>
### getPushProfile:forceRefresh:

获取推送用户详情，如果forceRefresh == true，则强制从服务端拉取

`- (BMXErrorCode)getPushProfile:(BMXPushUserProfile *)*pushProfile* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*forceRefresh*  
   是否强制从服务器拉取，本地获取失败的情况下会自动从服务器拉取  

*profile*  
   推送用户profile信息，初始传入指向为空的shared_ptr对象，函数返回后从此处获取用户profile信息。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getTags:operationId:" title="getTags:operationId:"></a>
### getTags:operationId:

获取推送用户的标签。

`- (BMXErrorCode)getTags:(TagList *)*tags* operationId:(NSString *)*operationId*`

#### Parameters

*tags*  
   用户标签  

*operationId*  
   操作id。在回调通知中对应通知提醒。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getToken" title="getToken"></a>
### getToken

获取登陆后使用的用户token。

`- (NSString *)getToken`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/loadLocalPushMessagesWithRefMsgId:size:result:" title="loadLocalPushMessagesWithRefMsgId:size:result:"></a>
### loadLocalPushMessagesWithRefMsgId:size:result:

`- (BMXErrorCode)loadLocalPushMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* result:(BMXMessageList *)*result*`

<a name="//api/name/loadLocalPushMessagesWithRefMsgId:size:result:arg4:" title="loadLocalPushMessagesWithRefMsgId:size:result:arg4:"></a>
### loadLocalPushMessagesWithRefMsgId:size:result:arg4:

加载数据库本地存储的推送消息。如果不指定则从最新消息开始

`- (BMXErrorCode)loadLocalPushMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* result:(BMXMessageList *)*result* arg4:(BMXPushService_PushDirection)*arg4*`

#### Parameters

*refMsgId*  
   加载推送消息的起始id  

*size*  
   最大加载消息条数  

*result*  
   数据库返回的加载本地推送消息列表  

*arg4*  
   加载推送消息的方向，默认是加载更早的消息  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/resume" title="resume"></a>
### resume

恢复推送功能接口。

`- (BMXErrorCode)resume`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/sendMessageWithContent:" title="sendMessageWithContent:"></a>
### sendMessageWithContent:

发送推送上行消息，消息状态变化会通过listener通知

`- (void)sendMessageWithContent:(NSString *)*content*`

#### Parameters

*content*  
   发送的上行推送消息内容  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setBadge:" title="setBadge:"></a>
### setBadge:

设置推送用户的未读角标。

`- (BMXErrorCode)setBadge:(int)*count*`

#### Parameters

*count*  
   用户未读角标数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setGeoFenceMode" title="setGeoFenceMode"></a>
### setGeoFenceMode

`- (BMXErrorCode)setGeoFenceMode`

<a name="//api/name/setGeoFenceMode:" title="setGeoFenceMode:"></a>
### setGeoFenceMode:

`- (BMXErrorCode)setGeoFenceMode:(BOOL)*enable*`

<a name="//api/name/setGeoFenceMode:isAllow:" title="setGeoFenceMode:isAllow:"></a>
### setGeoFenceMode:isAllow:

设置推送的地理围栏功能是否运行。

`- (BMXErrorCode)setGeoFenceMode:(BOOL)*enable* isAllow:(BOOL)*isAllow*`

#### Parameters

*enable*  
   地理围栏功能是否运行。  

*isAllow*  
   用户是否主动弹出用户定位请求。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushMode" title="setPushMode"></a>
### setPushMode

设置允许推送时间。

`- (BMXErrorCode)setPushMode`

#### Parameters

*startHour*  
   静默允许推送的起始时间小时  

*endHour*  
   静默允许推送的结束时间小时  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushMode:" title="setPushMode:"></a>
### setPushMode:

设置推送启用状态。默认为使用推送。

`- (BMXErrorCode)setPushMode:(BOOL)*enable*`

#### Parameters

*enable*  
   推送的启用状态  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushTime:endHour:" title="setPushTime:endHour:"></a>
### setPushTime:endHour:

`- (BMXErrorCode)setPushTime:(int)*startHour* endHour:(int)*endHour*`

<a name="//api/name/setRunBackgroundMode" title="setRunBackgroundMode"></a>
### setRunBackgroundMode

`- (BMXErrorCode)setRunBackgroundMode`

<a name="//api/name/setRunBackgroundMode:" title="setRunBackgroundMode:"></a>
### setRunBackgroundMode:

设置推送是否可以后台运行。默认是false。

`- (BMXErrorCode)setRunBackgroundMode:(BOOL)*enable*`

#### Parameters

*enable*  
   推送后台运行状态。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setSilenceTime:endHour:" title="setSilenceTime:endHour:"></a>
### setSilenceTime:endHour:

设置推送静默的起始结束时间。

`- (BMXErrorCode)setSilenceTime:(int)*startHour* endHour:(int)*endHour*`

#### Parameters

*startHour*  
   静默推送的起始时间小时  

*endHour*  
   静默推送的结束时间小时  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setTags:operationId:" title="setTags:operationId:"></a>
### setTags:operationId:

设置推送用户的标签。

`- (BMXErrorCode)setTags:(TagList *)*tags* operationId:(NSString *)*operationId*`

#### Parameters

*tags*  
   用户标签  

*operationId*  
   操作id。在回调通知中对应通知提醒。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/start" title="start"></a>
### start

`- (BMXErrorCode)start`

<a name="//api/name/startWithAlias:" title="startWithAlias:"></a>
### startWithAlias:

`- (BMXErrorCode)startWithAlias:(NSString *)*alias*`

<a name="//api/name/startWithAlias:bmxToken:" title="startWithAlias:bmxToken:"></a>
### startWithAlias:bmxToken:

初始化推送sdk。在仅使用推送的情况下使用该接口初始化推送sdk。在同时使用IM功能的时候直接在BMXClient调用登陆功能即可。config对象初始化的时候需要传入平台类型和设备id。

`- (BMXErrorCode)startWithAlias:(NSString *)*alias* bmxToken:(NSString *)*bmxToken*`

#### Parameters

*alias*  
   推送初始化使用的当前用户别名  

*bmxToken*  
   推送初始化的时候App传入的使用的用户的token，无用户的状态下不传入即可。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/status" title="status"></a>
### status

推送sdk当前的状态。

`- (BMXPushService_PushSdkStatus)status`

#### Return Value
<a href="../Constants/BMXPushService_PushSdkStatus.md">BMXPushService_PushSdkStatus</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/stop" title="stop"></a>
### stop

停止推送功能接口。

`- (BMXErrorCode)stop`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unbindAliasWithAlias:" title="unbindAliasWithAlias:"></a>
### unbindAliasWithAlias:

解除用户别名绑定。

`- (BMXErrorCode)unbindAliasWithAlias:(NSString *)*alias*`

#### Parameters

*alias*  
   需要解除绑定的用户别名。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

