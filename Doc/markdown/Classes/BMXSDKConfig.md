# BMXSDKConfig Class Reference

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

<a name="//api/name/carryUsernameInMessage" title="carryUsernameInMessage"></a>
### carryUsernameInMessage

发送消息的config中是否携带

`- (BOOL)carryUsernameInMessage`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/enableDeliveryAck" title="enableDeliveryAck"></a>
### enableDeliveryAck

是否发送消息送达回执

`- (BOOL)enableDeliveryAck`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAppID" title="getAppID"></a>
### getAppID

获取用户的appID。

`- (NSString *)getAppID`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAppSecret" title="getAppSecret"></a>
### getAppSecret

获取用户的appSecret。

`- (NSString *)getAppSecret`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getCacheDir" title="getCacheDir"></a>
### getCacheDir

获取缓存数据存储路径，比如用户头像

`- (NSString *)getCacheDir`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getClientType" title="getClientType"></a>
### getClientType

客户端类型

`- (BMXClientType)getClientType`

#### Return Value
<a href="../Constants/BMXClientType.md">BMXClientType</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getConsoleOutput" title="getConsoleOutput"></a>
### getConsoleOutput

Log是否输出到Console

`- (BOOL)getConsoleOutput`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDBCryptoKey" title="getDBCryptoKey"></a>
### getDBCryptoKey

获取设备的本地数据库加密密钥。

`- (NSString *)getDBCryptoKey`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDataDir" title="getDataDir"></a>
### getDataDir

获取聊天数据存储路径，包含消息、附件等

`- (NSString *)getDataDir`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDebugLogReceiverId" title="getDebugLogReceiverId"></a>
### getDebugLogReceiverId

获取调试log接收着账号(仅用于SDK调试，接收客户端log日志使用)

`- (long long)getDebugLogReceiverId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getDeviceUuid" title="getDeviceUuid"></a>
### getDeviceUuid

获取设备的唯一识别码

`- (NSString *)getDeviceUuid`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getEnableDNS" title="getEnableDNS"></a>
### getEnableDNS

获取是否启用dns功能。

`- (BOOL)getEnableDNS`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getHostConfig" title="getHostConfig"></a>
### getHostConfig

获取服务器配置

`- (BMXSDKConfigHostConfig *)getHostConfig`

#### Return Value
<a href="../Classes/BMXSDKConfigHostConfig.md">BMXSDKConfigHostConfig</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getLoadAllServerConversations" title="getLoadAllServerConversations"></a>
### getLoadAllServerConversations

是否根据服务器返回未读列表创建所有会话.

`- (BOOL)getLoadAllServerConversations`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getLogLevel" title="getLogLevel"></a>
### getLogLevel

Log输出等级

`- (BMXLogLevel)getLogLevel`

#### Return Value
<a href="../Constants/BMXLogLevel.md">BMXLogLevel</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getPushCertName" title="getPushCertName"></a>
### getPushCertName

获取Push证书名字

`- (NSString *)getPushCertName`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getPushEnvironmentType" title="getPushEnvironmentType"></a>
### getPushEnvironmentType

获取用户的推送环境类型。

`- (BMXPushEnvironmentType)getPushEnvironmentType`

#### Return Value
<a href="../Constants/BMXPushEnvironmentType.md">BMXPushEnvironmentType</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getPushProviderType" title="getPushProviderType"></a>
### getPushProviderType

获取用户的推送提供商类型。

`- (BMXPushProviderType)getPushProviderType`

#### Return Value
<a href="../Constants/BMXPushProviderType.md">BMXPushProviderType</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getSDKVersion" title="getSDKVersion"></a>
### getSDKVersion

SDK版本

`- (NSString *)getSDKVersion`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getUserAgent" title="getUserAgent"></a>
### getUserAgent

获取用户代理信息

`- (NSString *)getUserAgent`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getUserDNSAddress" title="getUserDNSAddress"></a>
### getUserDNSAddress

获取用户自定义dns服务器地址。

`- (NSString *)getUserDNSAddress`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getVerifyCertificate" title="getVerifyCertificate"></a>
### getVerifyCertificate

获取https请求是否验证服务器端证书。

`- (BOOL)getVerifyCertificate`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getVsn" title="getVsn"></a>
### getVsn

客户端OS版本

`- (NSString *)getVsn`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:" title="initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:"></a>
### initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:

`- (id)initWithType:(BMXClientType)*type* vsn:(NSString *)*vsn* dataDir:(NSString *)*dataDir* cacheDir:(NSString *)*cacheDir* sDKVersion:(NSString *)*SDKVersion* pushCertName:(NSString *)*pushCertName* userAgent:(NSString *)*userAgent*`

<a name="//api/name/initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:" title="initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:"></a>
### initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:

`- (id)initWithType:(BMXClientType)*type* vsn:(NSString *)*vsn* dataDir:(NSString *)*dataDir* cacheDir:(NSString *)*cacheDir* sDKVersion:(NSString *)*SDKVersion* pushCertName:(NSString *)*pushCertName* userAgent:(NSString *)*userAgent* appId:(NSString *)*appId* appSecret:(NSString *)*appSecret*`

<a name="//api/name/initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:deliveryAck:" title="initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:deliveryAck:"></a>
### initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:appId:appSecret:deliveryAck:

构造函数

`- (id)initWithType:(BMXClientType)*type* vsn:(NSString *)*vsn* dataDir:(NSString *)*dataDir* cacheDir:(NSString *)*cacheDir* sDKVersion:(NSString *)*SDKVersion* pushCertName:(NSString *)*pushCertName* userAgent:(NSString *)*userAgent* appId:(NSString *)*appId* appSecret:(NSString *)*appSecret* deliveryAck:(BOOL)*deliveryAck*`

#### Parameters

*type*  
   客户端类型  

*vsn*  
   客户端OS版本  

*dataDir*  
   聊天数据存储路径  

*cacheDir*  
   缓存数据存储路径  

*SDKVersion*  
   SDK版本  

*pushCertName*  
   Push证书名字  

*userAgent*  
   用户代理信息  

*appId*  
   用户的appId  

*appSecret*  
   用户的appSecret（对于使用推送的用户，必须同时设置appId和appSecret）  

*deliveryAck*  
   是否发送消息送达回执  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:deliveryAck:" title="initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:deliveryAck:"></a>
### initWithType:vsn:dataDir:cacheDir:sDKVersion:pushCertName:userAgent:deliveryAck:

构造函数

`- (id)initWithType:(BMXClientType)*type* vsn:(NSString *)*vsn* dataDir:(NSString *)*dataDir* cacheDir:(NSString *)*cacheDir* sDKVersion:(NSString *)*SDKVersion* pushCertName:(NSString *)*pushCertName* userAgent:(NSString *)*userAgent* deliveryAck:(BOOL)*deliveryAck*`

#### Parameters

*type*  
   客户端类型  

*vsn*  
   客户端OS版本  

*dataDir*  
   聊天数据存储路径  

*cacheDir*  
   缓存数据存储路径  

*SDKVersion*  
   SDK版本  

*pushCertName*  
   Push证书名字  

*userAgent*  
   用户代理信息  

*deliveryAck*  
   是否发送消息送达回执  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAppID:" title="setAppID:"></a>
### setAppID:

设置用户的appID。

`- (void)setAppID:(NSString *)*appID*`

#### Parameters

*appID*  
   用户的appID  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAppSecret:" title="setAppSecret:"></a>
### setAppSecret:

设置用户的appSecret。

`- (void)setAppSecret:(NSString *)*appSecret*`

#### Parameters

*appID*  
   用户的appSecret  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setCarryUsernameInMessage:" title="setCarryUsernameInMessage:"></a>
### setCarryUsernameInMessage:

设置发送消息的config中是否携带用户名

`- (void)setCarryUsernameInMessage:(BOOL)*arg1*`

#### Parameters

*bool*  
   设置是否在送消息的config中携带用户名  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setConsoleOutput:" title="setConsoleOutput:"></a>
### setConsoleOutput:

设置Log是否输出到Console

`- (void)setConsoleOutput:(BOOL)*arg1*`

#### Parameters

*bool*  
   设置Log是否输出到Console  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setDBCryptoKey:" title="setDBCryptoKey:"></a>
### setDBCryptoKey:

设置本地数据库的加密密钥，在app卸载之前应该始终保持一直，app删除后再次安装时可以产生不同的密钥。用于本地数据库加密。

`- (void)setDBCryptoKey:(NSString *)*cryptoKey*`

#### Parameters

*cryptoKey*  
   本地数据库的加密密钥。  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setDebugLogReceiverId:" title="setDebugLogReceiverId:"></a>
### setDebugLogReceiverId:

设置调试log接收账号(仅用于SDK调试，接收客户端log日志使用)

`- (void)setDebugLogReceiverId:(long long)*uid*`

#### Parameters

*uid*  
   调试log接收者id  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setDeviceUuid:" title="setDeviceUuid:"></a>
### setDeviceUuid:

设置设备的唯一识别码，在app卸载之前应该始终保持一致，app删除后再次安装时可以产生不同的设备识别码。

`- (void)setDeviceUuid:(NSString *)*uuid*`

#### Parameters

*uuid*  
   设备的唯一识别码。  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableDNS" title="setEnableDNS"></a>
### setEnableDNS

`- (void)setEnableDNS`

<a name="//api/name/setEnableDNS:" title="setEnableDNS:"></a>
### setEnableDNS:

设置是否启用dns功能，默认是开启的。

`- (void)setEnableDNS:(BOOL)*enable*`

#### Parameters

*enable*  
   是否启用dns功能  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableDeliveryAck:" title="setEnableDeliveryAck:"></a>
### setEnableDeliveryAck:

设置是否发送消息送达回执

`- (void)setEnableDeliveryAck:(BOOL)*arg1*`

#### Parameters

*bool*  
   是否发送消息送达回执  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnvironmentType:" title="setEnvironmentType:"></a>
### setEnvironmentType:

设置用户的推送环境类型。

`- (void)setEnvironmentType:(BMXPushEnvironmentType)*type*`

#### Parameters

*type*  
   用户的推送环境类型  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setHostConfig:" title="setHostConfig:"></a>
### setHostConfig:

设置服务器配置

`- (void)setHostConfig:(BMXSDKConfigHostConfig *)*config*`

#### Parameters

*config*  
   服务器配置  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setLoadAllServerConversations" title="setLoadAllServerConversations"></a>
### setLoadAllServerConversations

`- (void)setLoadAllServerConversations`

<a name="//api/name/setLoadAllServerConversations:" title="setLoadAllServerConversations:"></a>
### setLoadAllServerConversations:

是否根据服务器返回未读列表创建所有会话，默认为false，只会创建有未读消息的会话。

`- (void)setLoadAllServerConversations:(BOOL)*enable*`

#### Parameters

*enable*  
   是否根据服务器返回未读列表创建所有会话  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setLogLevel:" title="setLogLevel:"></a>
### setLogLevel:

设置Log输出等级

`- (void)setLogLevel:(BMXLogLevel)*arg1*`

#### Parameters

*BMXLogLevel*  
   Log输出等级  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushCertName:" title="setPushCertName:"></a>
### setPushCertName:

设置Push证书名字

`- (void)setPushCertName:(NSString *)*arg1*`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setPushProviderType:" title="setPushProviderType:"></a>
### setPushProviderType:

设置用户的推送提供商类型。

`- (void)setPushProviderType:(BMXPushProviderType)*type*`

#### Parameters

*type*  
   用户的推送提供商类型  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setUserDNSAddress:" title="setUserDNSAddress:"></a>
### setUserDNSAddress:

设置用户自定义dns服务器地址，在用户设置了dns服务器的情况下优先使用用户dns。

`- (void)setUserDNSAddress:(NSString *)*dns*`

#### Parameters

*dns*  
   用户自定义dns服务器地址  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setVerifyCertificate" title="setVerifyCertificate"></a>
### setVerifyCertificate

`- (void)setVerifyCertificate`

<a name="//api/name/setVerifyCertificate:" title="setVerifyCertificate:"></a>
### setVerifyCertificate:

设置https请求是否验证服务器端证书。

`- (void)setVerifyCertificate:(BOOL)*verify*`

#### Parameters

*verify*  
   https请求是否验证服务器端证书  

#### Discussion
设置https请求是否验证服务器端证书。

#### Declared In
* `floo_proxy.h`

