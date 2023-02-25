# BMXGroupService Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 群组Service

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/acceptApplicationWithGroup:applicantId:" title="acceptApplicationWithGroup:applicantId:"></a>
### acceptApplicationWithGroup:applicantId:

接受入群申请

`- (BMXErrorCode)acceptApplicationWithGroup:(BMXGroup *)*group* applicantId:(long long)*applicantId*`

#### Parameters

*group*  
   进行操作的群组  

*applicantId*  
   申请进群的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/acceptApplicationWithGroup:applicantId:completion:" title="acceptApplicationWithGroup:applicantId:completion:"></a>
### acceptApplicationWithGroup:applicantId:completion:

接受入群申请

`- (void)acceptApplicationWithGroup:(BMXGroup *)*group* applicantId:(long long)*applicantId* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*applicantId*  
   申请进群的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/acceptInvitationWithGroup:inviter:" title="acceptInvitationWithGroup:inviter:"></a>
### acceptInvitationWithGroup:inviter:

接受入群邀请

`- (BMXErrorCode)acceptInvitationWithGroup:(BMXGroup *)*group* inviter:(long long)*inviter*`

#### Parameters

*group*  
   进行操作的群组  

*inviter*  
   邀请者id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/acceptInvitationWithGroup:inviter:completion:" title="acceptInvitationWithGroup:inviter:completion:"></a>
### acceptInvitationWithGroup:inviter:completion:

接受入群邀请

`- (void)acceptInvitationWithGroup:(BMXGroup *)*group* inviter:(long long)*inviter* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*inviter*  
   邀请者id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addAdminsWithGroup:admins:message:" title="addAdminsWithGroup:admins:message:"></a>
### addAdminsWithGroup:admins:message:

添加管理员

`- (BMXErrorCode)addAdminsWithGroup:(BMXGroup *)*group* admins:(ListOfLongLong *)*admins* message:(NSString *)*message*`

#### Parameters

*group*  
   进行操作的群组  

*admins*  
   要添加为管理员的成员id列表  

*message*  
   添加为管理员的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addAdminsWithGroup:admins:message:completion:" title="addAdminsWithGroup:admins:message:completion:"></a>
### addAdminsWithGroup:admins:message:completion:

添加管理员

`- (void)addAdminsWithGroup:(BMXGroup *)*group* admins:(ListOfLongLong *)*admins* message:(NSString *)*message* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*admins*  
   要添加为管理员的成员id列表  

*message*  
   添加为管理员的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:" title="addDelegate:"></a>
### addDelegate:

添加群组变化监听者

`- (void)addDelegate:(id<BMXGroupServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   群组变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:delegateQueue:" title="addDelegate:delegateQueue:"></a>
### addDelegate:delegateQueue:

`- (void)addDelegate:(id<BMXGroupServiceProtocol>)*aDelegate* delegateQueue:(dispatch_queue_t)*aQueue*`

<a name="//api/name/addGroupListener:" title="addGroupListener:"></a>
### addGroupListener:

添加群组变化监听者

`- (void)addGroupListener:(id<BMXGroupServiceProtocol>)*listener*`

#### Parameters

*listener*  
   群组变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addMembersWithGroup:members:message:" title="addMembersWithGroup:members:message:"></a>
### addMembersWithGroup:members:message:

添加群成员

`- (BMXErrorCode)addMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* message:(NSString *)*message*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要添加进群的成员id列表  

*message*  
   添加成员原因信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addMembersWithGroup:members:message:completion:" title="addMembersWithGroup:members:message:completion:"></a>
### addMembersWithGroup:members:message:completion:

添加群成员

`- (void)addMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* message:(NSString *)*message* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要添加进群的成员id列表  

*message*  
   添加成员原因信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/banGroupWithGroup:duration:" title="banGroupWithGroup:duration:"></a>
### banGroupWithGroup:duration:

全员禁言，当前服务器时间加上禁言时长后计算出全员禁言到期时间（只有管理和群主可以发言）

`- (BMXErrorCode)banGroupWithGroup:(BMXGroup *)*group* duration:(long long)*duration*`

#### Parameters

*group*  
   进行操作的群组  

*duration*  
   禁言时长(分钟)  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/banGroupWithGroup:duration:completion:" title="banGroupWithGroup:duration:completion:"></a>
### banGroupWithGroup:duration:completion:

全员禁言，当前服务器时间加上禁言时长后计算出全员禁言到期时间（只有管理和群主可以发言）

`- (void)banGroupWithGroup:(BMXGroup *)*group* duration:(long long)*duration* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*duration*  
   禁言时长(分钟)  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/banMembersWithGroup:members:duration:" title="banMembersWithGroup:members:duration:"></a>
### banMembersWithGroup:members:duration:

`- (BMXErrorCode)banMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* duration:(long long)*duration*`

<a name="//api/name/banMembersWithGroup:members:duration:reason:" title="banMembersWithGroup:members:duration:reason:"></a>
### banMembersWithGroup:members:duration:reason:

禁言

`- (BMXErrorCode)banMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* duration:(long long)*duration* reason:(NSString *)*reason*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   被禁言的群成员id列表  

*duration*  
   禁言时长  

*reason*  
   禁言原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/banMembersWithGroup:members:duration:reason:completion:" title="banMembersWithGroup:members:duration:reason:completion:"></a>
### banMembersWithGroup:members:duration:reason:completion:

禁言

`- (void)banMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* duration:(long long)*duration* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   被禁言的群成员id列表  

*duration*  
   禁言时长  

*reason*  
   禁言原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/blockMembersWithGroup:members:" title="blockMembersWithGroup:members:"></a>
### blockMembersWithGroup:members:

添加黑名单

`- (BMXErrorCode)blockMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要加入黑名单的群成员id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/blockMembersWithGroup:members:completion:" title="blockMembersWithGroup:members:completion:"></a>
### blockMembersWithGroup:members:completion:

添加黑名单

`- (void)blockMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要加入黑名单的群成员id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/cancelDownloadSharedFileWithGroup:sharedFile:" title="cancelDownloadSharedFileWithGroup:sharedFile:"></a>
### cancelDownloadSharedFileWithGroup:sharedFile:

取消下载群共享文件

`- (BMXErrorCode)cancelDownloadSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   下载的群共享文件  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/cancelDownloadSharedFileWithGroup:sharedFile:completion:" title="cancelDownloadSharedFileWithGroup:sharedFile:completion:"></a>
### cancelDownloadSharedFileWithGroup:sharedFile:completion:

取消下载群共享文件

`- (void)cancelDownloadSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   下载的群共享文件  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/cancelUploadSharedFileWithGroup:filePath:" title="cancelUploadSharedFileWithGroup:filePath:"></a>
### cancelUploadSharedFileWithGroup:filePath:

取消上传群共享文件

`- (BMXErrorCode)cancelUploadSharedFileWithGroup:(BMXGroup *)*group* filePath:(NSString *)*filePath*`

#### Parameters

*group*  
   进行操作的群组  

*filePath*  
   文件的本地路径  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/cancelUploadSharedFileWithGroup:filePath:completion:" title="cancelUploadSharedFileWithGroup:filePath:completion:"></a>
### cancelUploadSharedFileWithGroup:filePath:completion:

取消上传群共享文件

`- (void)cancelUploadSharedFileWithGroup:(BMXGroup *)*group* filePath:(NSString *)*filePath* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*filePath*  
   文件的本地路径  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/changeSharedFileNameWithGroup:sharedFile:name:" title="changeSharedFileNameWithGroup:sharedFile:name:"></a>
### changeSharedFileNameWithGroup:sharedFile:name:

修改群共享文件名称

`- (BMXErrorCode)changeSharedFileNameWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* name:(NSString *)*name*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   进行更改的群共享文件  

*name*  
   修改的群共享文件名称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/changeSharedFileNameWithGroup:sharedFile:name:completion:" title="changeSharedFileNameWithGroup:sharedFile:name:completion:"></a>
### changeSharedFileNameWithGroup:sharedFile:name:completion:

修改群共享文件名称

`- (void)changeSharedFileNameWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* name:(NSString *)*name* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   进行更改的群共享文件  

*name*  
   修改的群共享文件名称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/createWithOptions:completion:" title="createWithOptions:completion:"></a>
### createWithOptions:completion:

创建群

`- (void)createWithOptions:(BMXGroupServiceCreateGroupOptions *)*options* completion:(void ( ^ ) ( BMXGroup *res , BMXError *aError ))*resBlock*`

#### Parameters

*options*  
   创建群组时传入的参数选项  

*group*  
   创建返回的结果，传入指向为空的shared_ptr对象函数执行后从此获取返回结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/createWithOptions:group:" title="createWithOptions:group:"></a>
### createWithOptions:group:

创建群

`- (BMXErrorCode)createWithOptions:(BMXGroupServiceCreateGroupOptions *)*options* group:(BMXGroup *)*group*`

#### Parameters

*options*  
   创建群组时传入的参数选项  

*group*  
   创建返回的结果，传入指向为空的shared_ptr对象函数执行后从此获取返回结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/declineApplicationWithGroup:applicantId:" title="declineApplicationWithGroup:applicantId:"></a>
### declineApplicationWithGroup:applicantId:

`- (BMXErrorCode)declineApplicationWithGroup:(BMXGroup *)*group* applicantId:(long long)*applicantId*`

<a name="//api/name/declineApplicationWithGroup:applicantId:reason:" title="declineApplicationWithGroup:applicantId:reason:"></a>
### declineApplicationWithGroup:applicantId:reason:

拒绝入群申请

`- (BMXErrorCode)declineApplicationWithGroup:(BMXGroup *)*group* applicantId:(long long)*applicantId* reason:(NSString *)*reason*`

#### Parameters

*group*  
   进行操作的群组  

*applicantId*  
   申请进群的用户id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/declineApplicationWithGroup:applicantId:reason:completion:" title="declineApplicationWithGroup:applicantId:reason:completion:"></a>
### declineApplicationWithGroup:applicantId:reason:completion:

拒绝入群申请

`- (void)declineApplicationWithGroup:(BMXGroup *)*group* applicantId:(long long)*applicantId* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*applicantId*  
   申请进群的用户id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/declineInvitationWithGroup:inviter:" title="declineInvitationWithGroup:inviter:"></a>
### declineInvitationWithGroup:inviter:

`- (BMXErrorCode)declineInvitationWithGroup:(BMXGroup *)*group* inviter:(long long)*inviter*`

<a name="//api/name/declineInvitationWithGroup:inviter:reason:" title="declineInvitationWithGroup:inviter:reason:"></a>
### declineInvitationWithGroup:inviter:reason:

拒绝入群邀请

`- (BMXErrorCode)declineInvitationWithGroup:(BMXGroup *)*group* inviter:(long long)*inviter* reason:(NSString *)*reason*`

#### Parameters

*group*  
   进行操作的群组  

*inviter*  
   邀请者id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/declineInvitationWithGroup:inviter:reason:completion:" title="declineInvitationWithGroup:inviter:reason:completion:"></a>
### declineInvitationWithGroup:inviter:reason:completion:

拒绝入群邀请

`- (void)declineInvitationWithGroup:(BMXGroup *)*group* inviter:(long long)*inviter* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*inviter*  
   邀请者id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/deleteAnnouncementWithGroup:announcementId:" title="deleteAnnouncementWithGroup:announcementId:"></a>
### deleteAnnouncementWithGroup:announcementId:

删除群公告

`- (BMXErrorCode)deleteAnnouncementWithGroup:(BMXGroup *)*group* announcementId:(long long)*announcementId*`

#### Parameters

*group*  
   进行操作的群组  

*announcementId*  
   删除的群公告id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/deleteAnnouncementWithGroup:announcementId:completion:" title="deleteAnnouncementWithGroup:announcementId:completion:"></a>
### deleteAnnouncementWithGroup:announcementId:completion:

删除群公告

`- (void)deleteAnnouncementWithGroup:(BMXGroup *)*group* announcementId:(long long)*announcementId* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*announcementId*  
   删除的群公告id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/destroyWithGroup:" title="destroyWithGroup:"></a>
### destroyWithGroup:

销毁群

`- (BMXErrorCode)destroyWithGroup:(BMXGroup *)*group*`

#### Parameters

*group*  
   要销毁的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/destroyWithGroup:completion:" title="destroyWithGroup:completion:"></a>
### destroyWithGroup:completion:

销毁群

`- (void)destroyWithGroup:(BMXGroup *)*group* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   要销毁的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithGroup:thumbnail:callback:" title="downloadAvatarWithGroup:thumbnail:callback:"></a>
### downloadAvatarWithGroup:thumbnail:callback:

下载群头像

`- (BMXErrorCode)downloadAvatarWithGroup:(BMXGroup *)*group* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback*`

#### Parameters

*group*  
   进行操作的群组  

*thumbnail*  
   设置为true下载缩略图，false下载原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithGroup:thumbnail:callback:completion:" title="downloadAvatarWithGroup:thumbnail:callback:completion:"></a>
### downloadAvatarWithGroup:thumbnail:callback:completion:

下载群头像

`- (void)downloadAvatarWithGroup:(BMXGroup *)*group* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*thumbnail*  
   设置为true下载缩略图，false下载原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadSharedFileWithGroup:sharedFile:arg3:" title="downloadSharedFileWithGroup:sharedFile:arg3:"></a>
### downloadSharedFileWithGroup:sharedFile:arg3:

下载群共享文件

`- (BMXErrorCode)downloadSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* arg3:(void ( ^ ) ( int progress ))*arg3*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   下载的群共享文件  

*Callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadSharedFileWithGroup:sharedFile:arg3:completion:" title="downloadSharedFileWithGroup:sharedFile:arg3:completion:"></a>
### downloadSharedFileWithGroup:sharedFile:arg3:completion:

下载群共享文件

`- (void)downloadSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* arg3:(void ( ^ ) ( int progress ))*arg3* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   下载的群共享文件  

*Callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/editAnnouncementWithGroup:title:content:" title="editAnnouncementWithGroup:title:content:"></a>
### editAnnouncementWithGroup:title:content:

设置群公告

`- (BMXErrorCode)editAnnouncementWithGroup:(BMXGroup *)*group* title:(NSString *)*title* content:(NSString *)*content*`

#### Parameters

*group*  
   进行操作的群组  

*title*  
   群公告的标题  

*content*  
   群公告的内容  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/editAnnouncementWithGroup:title:content:completion:" title="editAnnouncementWithGroup:title:content:completion:"></a>
### editAnnouncementWithGroup:title:content:completion:

设置群公告

`- (void)editAnnouncementWithGroup:(BMXGroup *)*group* title:(NSString *)*title* content:(NSString *)*content* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*title*  
   群公告的标题  

*content*  
   群公告的内容  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchGroupByIdWithGroupId:forceRefresh:completion:" title="fetchGroupByIdWithGroupId:forceRefresh:completion:"></a>
### fetchGroupByIdWithGroupId:forceRefresh:completion:

通过群组id获取群信息，如果设置了forceRefresh则从服务器拉取

`- (void)fetchGroupByIdWithGroupId:(long long)*groupId* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroup *res , BMXError *aError ))*resBlock*`

#### Parameters

*groupId*  
   要搜索的群组id  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*group*  
   搜索返回的群组信息，传入指向为空的shared_ptr对象函数执行后从此获取返回结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchGroupByIdWithGroupId:group:forceRefresh:" title="fetchGroupByIdWithGroupId:group:forceRefresh:"></a>
### fetchGroupByIdWithGroupId:group:forceRefresh:

通过群组id获取群信息，如果设置了forceRefresh则从服务器拉取

`- (BMXErrorCode)fetchGroupByIdWithGroupId:(long long)*groupId* group:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*groupId*  
   要搜索的群组id  

*group*  
   搜索返回的群组信息，传入指向为空的shared_ptr对象函数执行后从此获取返回结果  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchGroupsByIdListWithGroupIdList:forceRefresh:completion:" title="fetchGroupsByIdListWithGroupIdList:forceRefresh:completion:"></a>
### fetchGroupsByIdListWithGroupIdList:forceRefresh:completion:

通过传入群组的id列表获取群组信息列表，如果设置了forceRefresh则从服务器拉取

`- (void)fetchGroupsByIdListWithGroupIdList:(ListOfLongLong *)*groupIdList* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupList *res , BMXError *aError ))*resBlock*`

#### Parameters

*groupIdList*  
   群组id列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群组详细信息列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchGroupsByIdListWithGroupIdList:list:forceRefresh:" title="fetchGroupsByIdListWithGroupIdList:list:forceRefresh:"></a>
### fetchGroupsByIdListWithGroupIdList:list:forceRefresh:

通过传入群组的id列表获取群组信息列表，如果设置了forceRefresh则从服务器拉取

`- (BMXErrorCode)fetchGroupsByIdListWithGroupIdList:(ListOfLongLong *)*groupIdList* list:(BMXGroupList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*groupIdList*  
   群组id列表  

*list*  
   群组详细信息列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchLocalGroupsByName:completion:" title="fetchLocalGroupsByName:completion:"></a>
### fetchLocalGroupsByName:completion:

通过群名称查询本地群信息，从本地数据库中通过群名称查询获取群组

`- (void)fetchLocalGroupsByName:(NSString *)*name* completion:(void ( ^ ) ( BMXGroupList *res , BMXError *aError ))*resBlock*`

#### Parameters

*name*  
   查询的群名称关键字  

*list*  
   搜索结果返回的群列表信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchLocalGroupsByNameWithList:name:" title="fetchLocalGroupsByNameWithList:name:"></a>
### fetchLocalGroupsByNameWithList:name:

通过群名称查询本地群信息，从本地数据库中通过群名称查询获取群组

`- (BMXErrorCode)fetchLocalGroupsByNameWithList:(BMXGroupList *)*list* name:(NSString *)*name*`

#### Parameters

*list*  
   搜索结果返回的群列表信息  

*name*  
   查询的群名称关键字  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/get:completion:" title="get:completion:"></a>
### get:completion:

获取群组列表，如果设置了forceRefresh则从服务器拉取

`- (void)get:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupList *res , BMXError *aError ))*resBlock*`

#### Parameters

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群组id列表，传入空列表函数返回后从此处获取返回的群组id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/get:forceRefresh:" title="get:forceRefresh:"></a>
### get:forceRefresh:

获取群组列表，如果设置了forceRefresh则从服务器拉取

`- (BMXErrorCode)get:(BMXGroupList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*list*  
   群组id列表，传入空列表函数返回后从此处获取返回的群组id列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAdmins:forceRefresh:completion:" title="getAdmins:forceRefresh:completion:"></a>
### getAdmins:forceRefresh:completion:

获取Admins列表，如果设置了forceRefresh则从服务器拉取

`- (void)getAdmins:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupMemberList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群管理员列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAdmins:list:forceRefresh:" title="getAdmins:list:forceRefresh:"></a>
### getAdmins:list:forceRefresh:

获取Admins列表，如果设置了forceRefresh则从服务器拉取

`- (BMXErrorCode)getAdmins:(BMXGroup *)*group* list:(BMXGroupMemberList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群管理员列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAnnouncementList:forceRefresh:completion:" title="getAnnouncementList:forceRefresh:completion:"></a>
### getAnnouncementList:forceRefresh:completion:

获取群公告列表

`- (void)getAnnouncementList:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupAnnouncementList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群公告列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getAnnouncementList:list:forceRefresh:" title="getAnnouncementList:list:forceRefresh:"></a>
### getAnnouncementList:list:forceRefresh:

获取群公告列表

`- (BMXErrorCode)getAnnouncementList:(BMXGroup *)*group* list:(BMXGroupAnnouncementList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群公告列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getApplicationList:cursor:pageSize:completion:" title="getApplicationList:cursor:pageSize:completion:"></a>
### getApplicationList:cursor:pageSize:completion:

分页获取群组申请列表

`- (void)getApplicationList:(BMXGroupList *)*list* cursor:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXGroupApplicationPage *res , BMXError *aError ))*resBlock*`

#### Parameters

*list*  
   需要获取群组申请列表信息的群组id列表  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   分页获取的群组申请列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getApplicationList:result:" title="getApplicationList:result:"></a>
### getApplicationList:result:

`- (BMXErrorCode)getApplicationList:(BMXGroupList *)*list* result:(BMXGroupApplicationPage *)*result*`

<a name="//api/name/getApplicationList:result:cursor:" title="getApplicationList:result:cursor:"></a>
### getApplicationList:result:cursor:

`- (BMXErrorCode)getApplicationList:(BMXGroupList *)*list* result:(BMXGroupApplicationPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getApplicationList:result:cursor:pageSize:" title="getApplicationList:result:cursor:pageSize:"></a>
### getApplicationList:result:cursor:pageSize:

分页获取群组申请列表

`- (BMXErrorCode)getApplicationList:(BMXGroupList *)*list* result:(BMXGroupApplicationPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*list*  
   需要获取群组申请列表信息的群组id列表  

*result*  
   分页获取的群组申请列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBannedMembers:completion:" title="getBannedMembers:completion:"></a>
### getBannedMembers:completion:

获取禁言列表

`- (void)getBannedMembers:(BMXGroup *)*group* completion:(void ( ^ ) ( BMXGroupBannedMemberList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群禁言列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBannedMembers:cursor:pageSize:completion:" title="getBannedMembers:cursor:pageSize:completion:"></a>
### getBannedMembers:cursor:pageSize:completion:

分页获取禁言列表

`- (void)getBannedMembers:(BMXGroup *)*group* cursor:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXGroupBannedMemberResultPage *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   分页获取的禁言列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBannedMembers:list:" title="getBannedMembers:list:"></a>
### getBannedMembers:list:

获取禁言列表

`- (BMXErrorCode)getBannedMembers:(BMXGroup *)*group* list:(BMXGroupBannedMemberList *)*list*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群禁言列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBannedMembers:result:" title="getBannedMembers:result:"></a>
### getBannedMembers:result:

`- (BMXErrorCode)getBannedMembers:(BMXGroup *)*group* result:(BMXGroupBannedMemberResultPage *)*result*`

<a name="//api/name/getBannedMembers:result:cursor:" title="getBannedMembers:result:cursor:"></a>
### getBannedMembers:result:cursor:

`- (BMXErrorCode)getBannedMembers:(BMXGroup *)*group* result:(BMXGroupBannedMemberResultPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getBannedMembers:result:cursor:pageSize:" title="getBannedMembers:result:cursor:pageSize:"></a>
### getBannedMembers:result:cursor:pageSize:

分页获取禁言列表

`- (BMXErrorCode)getBannedMembers:(BMXGroup *)*group* result:(BMXGroupBannedMemberResultPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*group*  
   进行操作的群组  

*result*  
   分页获取的禁言列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:cursor:pageSize:completion:" title="getBlockList:cursor:pageSize:completion:"></a>
### getBlockList:cursor:pageSize:completion:

分页获取黑名单

`- (void)getBlockList:(BMXGroup *)*group* cursor:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXGroupMemberResultPage *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   分页获取的黑名单列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:forceRefresh:completion:" title="getBlockList:forceRefresh:completion:"></a>
### getBlockList:forceRefresh:completion:

获取黑名单

`- (void)getBlockList:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupMemberList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群黑名单列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:list:forceRefresh:" title="getBlockList:list:forceRefresh:"></a>
### getBlockList:list:forceRefresh:

获取黑名单

`- (BMXErrorCode)getBlockList:(BMXGroup *)*group* list:(BMXGroupMemberList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群黑名单列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:result:" title="getBlockList:result:"></a>
### getBlockList:result:

`- (BMXErrorCode)getBlockList:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result*`

<a name="//api/name/getBlockList:result:cursor:" title="getBlockList:result:cursor:"></a>
### getBlockList:result:cursor:

`- (BMXErrorCode)getBlockList:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getBlockList:result:cursor:pageSize:" title="getBlockList:result:cursor:pageSize:"></a>
### getBlockList:result:cursor:pageSize:

分页获取黑名单

`- (BMXErrorCode)getBlockList:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*group*  
   进行操作的群组  

*result*  
   分页获取的黑名单列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getInfo:" title="getInfo:"></a>
### getInfo:

获取群详情，从服务端拉取最新信息

`- (BMXErrorCode)getInfo:(BMXGroup *)*group*`

#### Parameters

*group*  
   要获取群组最新信息的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getInfo:completion:" title="getInfo:completion:"></a>
### getInfo:completion:

获取群详情，从服务端拉取最新信息

`- (void)getInfo:(BMXGroup *)*group* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   要获取群组最新信息的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getInvitationList:" title="getInvitationList:"></a>
### getInvitationList:

`- (BMXErrorCode)getInvitationList:(BMXGroupInvitationPage *)*result*`

<a name="//api/name/getInvitationList:cursor:" title="getInvitationList:cursor:"></a>
### getInvitationList:cursor:

`- (BMXErrorCode)getInvitationList:(BMXGroupInvitationPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getInvitationList:cursor:pageSize:" title="getInvitationList:cursor:pageSize:"></a>
### getInvitationList:cursor:pageSize:

分页获取群组邀请列表

`- (BMXErrorCode)getInvitationList:(BMXGroupInvitationPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*result*  
   分页获取的群组邀请列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getInvitationList:pageSize:completion:" title="getInvitationList:pageSize:completion:"></a>
### getInvitationList:pageSize:completion:

分页获取群组邀请列表

`- (void)getInvitationList:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXGroupInvitationPage *res , BMXError *aError ))*resBlock*`

#### Parameters

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   分页获取的群组邀请列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getLatestAnnouncement:announcement:forceRefresh:" title="getLatestAnnouncement:announcement:forceRefresh:"></a>
### getLatestAnnouncement:announcement:forceRefresh:

获取最新的群公告

`- (BMXErrorCode)getLatestAnnouncement:(BMXGroup *)*group* announcement:(BMXGroupAnnouncement *)*announcement* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*announcement*  
   最新的群组公告，传入指向为空的shared_ptr对象函数返回后从此处获取最新的群组公告  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getLatestAnnouncement:announcement:forceRefresh:completion:" title="getLatestAnnouncement:announcement:forceRefresh:completion:"></a>
### getLatestAnnouncement:announcement:forceRefresh:completion:

获取最新的群公告

`- (void)getLatestAnnouncement:(BMXGroup *)*group* announcement:(BMXGroupAnnouncement *)*announcement* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupAnnouncement *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*announcement*  
   最新的群组公告，传入指向为空的shared_ptr对象函数返回后从此处获取最新的群组公告  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembers:cursor:pageSize:completion:" title="getMembers:cursor:pageSize:completion:"></a>
### getMembers:cursor:pageSize:completion:

分页获取群成员列表，如果设置了forceRefresh则从服务器拉取，单页最大数量为500.

`- (void)getMembers:(BMXGroup *)*group* cursor:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXGroupMemberResultPage *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   分页获取的群成员列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembers:forceRefresh:completion:" title="getMembers:forceRefresh:completion:"></a>
### getMembers:forceRefresh:completion:

获取群成员列表，如果设置了forceRefresh则从服务器拉取，最多拉取1000人

`- (void)getMembers:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupMemberList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群成员列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembers:list:forceRefresh:" title="getMembers:list:forceRefresh:"></a>
### getMembers:list:forceRefresh:

获取群成员列表，如果设置了forceRefresh则从服务器拉取，最多拉取1000人

`- (BMXErrorCode)getMembers:(BMXGroup *)*group* list:(BMXGroupMemberList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群成员列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembers:result:" title="getMembers:result:"></a>
### getMembers:result:

`- (BMXErrorCode)getMembers:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result*`

<a name="//api/name/getMembers:result:cursor:" title="getMembers:result:cursor:"></a>
### getMembers:result:cursor:

`- (BMXErrorCode)getMembers:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getMembers:result:cursor:pageSize:" title="getMembers:result:cursor:pageSize:"></a>
### getMembers:result:cursor:pageSize:

分页获取群成员列表，如果设置了forceRefresh则从服务器拉取，单页最大数量为500.

`- (BMXErrorCode)getMembers:(BMXGroup *)*group* result:(BMXGroupMemberResultPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*group*  
   进行操作的群组  

*result*  
   分页获取的群成员列表，传入指向为空的shared_ptr对象函数执行后从此处获取结果  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembersNickname:members:completion:" title="getMembersNickname:members:completion:"></a>
### getMembersNickname:members:completion:

获取群组成员详细信息

`- (void)getMembersNickname:(BMXGroup *)*group* members:(ListOfLongLong *)*members* completion:(void ( ^ ) ( BMXGroupMemberList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要获取群组成员信息详情的群成员id  

*list*  
   返回的群成员详细，传入空列表在函数操作后从此处获取群成员详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getMembersNickname:members:list:" title="getMembersNickname:members:list:"></a>
### getMembersNickname:members:list:

获取群组成员详细信息

`- (BMXErrorCode)getMembersNickname:(BMXGroup *)*group* members:(ListOfLongLong *)*members* list:(BMXGroupMemberList *)*list*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要获取群组成员信息详情的群成员id  

*list*  
   返回的群成员详细，传入空列表在函数操作后从此处获取群成员详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getSharedFilesList:forceRefresh:completion:" title="getSharedFilesList:forceRefresh:completion:"></a>
### getSharedFilesList:forceRefresh:completion:

获取群共享文件列表

`- (void)getSharedFilesList:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroupSharedFileList *res , BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

*list*  
   群共享文件列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getSharedFilesList:list:forceRefresh:" title="getSharedFilesList:list:forceRefresh:"></a>
### getSharedFilesList:list:forceRefresh:

获取群共享文件列表

`- (BMXErrorCode)getSharedFilesList:(BMXGroup *)*group* list:(BMXGroupSharedFileList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*group*  
   进行操作的群组  

*list*  
   群共享文件列表，传入空列表函数返回后从此处获取返回的群组详细信息列表  

*forceRefresh*  
   设置为true强制从服务器获取，本地获取失败的情况sdk会自动从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/joinWithGroup:message:" title="joinWithGroup:message:"></a>
### joinWithGroup:message:

加入一个群，根据群设置可能需要管理员批准

`- (BMXErrorCode)joinWithGroup:(BMXGroup *)*group* message:(NSString *)*message*`

#### Parameters

*group*  
   要加入的群组  

*message*  
   申请入群的信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/joinWithGroup:message:completion:" title="joinWithGroup:message:completion:"></a>
### joinWithGroup:message:completion:

加入一个群，根据群设置可能需要管理员批准

`- (void)joinWithGroup:(BMXGroup *)*group* message:(NSString *)*message* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   要加入的群组  

*message*  
   申请入群的信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/leaveWithGroup:" title="leaveWithGroup:"></a>
### leaveWithGroup:

退出群

`- (BMXErrorCode)leaveWithGroup:(BMXGroup *)*group*`

#### Parameters

*group*  
   要退出的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/leaveWithGroup:completion:" title="leaveWithGroup:completion:"></a>
### leaveWithGroup:completion:

退出群

`- (void)leaveWithGroup:(BMXGroup *)*group* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   要退出的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteMessageWithGroup:mode:" title="muteMessageWithGroup:mode:"></a>
### muteMessageWithGroup:mode:

设置是否屏蔽群消息

`- (BMXErrorCode)muteMessageWithGroup:(BMXGroup *)*group* mode:(BMXGroup_MsgMuteMode)*mode*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群屏蔽的模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/muteMessageWithGroup:mode:completion:" title="muteMessageWithGroup:mode:completion:"></a>
### muteMessageWithGroup:mode:completion:

设置是否屏蔽群消息

`- (void)muteMessageWithGroup:(BMXGroup *)*group* mode:(BMXGroup_MsgMuteMode)*mode* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群屏蔽的模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeAdminsWithGroup:admins:reason:" title="removeAdminsWithGroup:admins:reason:"></a>
### removeAdminsWithGroup:admins:reason:

删除管理员

`- (BMXErrorCode)removeAdminsWithGroup:(BMXGroup *)*group* admins:(ListOfLongLong *)*admins* reason:(NSString *)*reason*`

#### Parameters

*group*  
   进行操作的群组  

*admins*  
   要从管理员移除的成员id列表  

*reason*  
   要移除管理员的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeAdminsWithGroup:admins:reason:completion:" title="removeAdminsWithGroup:admins:reason:completion:"></a>
### removeAdminsWithGroup:admins:reason:completion:

删除管理员

`- (void)removeAdminsWithGroup:(BMXGroup *)*group* admins:(ListOfLongLong *)*admins* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*admins*  
   要从管理员移除的成员id列表  

*reason*  
   要移除管理员的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeDelegate:" title="removeDelegate:"></a>
### removeDelegate:

移除群组变化监听者

`- (void)removeDelegate:(id<BMXGroupServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   群组变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeGroupListener:" title="removeGroupListener:"></a>
### removeGroupListener:

移除群组变化监听者

`- (void)removeGroupListener:(id<BMXGroupServiceProtocol>)*listener*`

#### Parameters

*listener*  
   群组变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeMembersWithGroup:members:reason:" title="removeMembersWithGroup:members:reason:"></a>
### removeMembersWithGroup:members:reason:

删除群成员

`- (BMXErrorCode)removeMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* reason:(NSString *)*reason*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要删除的群组成员id列表  

*reason*  
   删除的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeMembersWithGroup:members:reason:completion:" title="removeMembersWithGroup:members:reason:completion:"></a>
### removeMembersWithGroup:members:reason:completion:

删除群成员

`- (void)removeMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   要删除的群组成员id列表  

*reason*  
   删除的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeSharedFileWithGroup:sharedFile:" title="removeSharedFileWithGroup:sharedFile:"></a>
### removeSharedFileWithGroup:sharedFile:

移除群共享文件

`- (BMXErrorCode)removeSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   删除的群共享文件  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeSharedFileWithGroup:sharedFile:completion:" title="removeSharedFileWithGroup:sharedFile:completion:"></a>
### removeSharedFileWithGroup:sharedFile:completion:

移除群共享文件

`- (void)removeSharedFileWithGroup:(BMXGroup *)*group* sharedFile:(BMXGroupSharedFile *)*sharedFile* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*sharedFile*  
   删除的群共享文件  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchWithGroupId:forceRefresh:completion:" title="searchWithGroupId:forceRefresh:completion:"></a>
### searchWithGroupId:forceRefresh:completion:

`- (void)searchWithGroupId:(long long)*groupId* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXGroup *res , BMXError *aError ))*resBlock*`

<a name="//api/name/searchWithGroupId:group:forceRefresh:" title="searchWithGroupId:group:forceRefresh:"></a>
### searchWithGroupId:group:forceRefresh:

`- (BMXErrorCode)searchWithGroupId:(long long)*groupId* group:(BMXGroup *)*group* forceRefresh:(BOOL)*forceRefresh*`

<a name="//api/name/searchWithGroupIdList:list:forceRefresh:" title="searchWithGroupIdList:list:forceRefresh:"></a>
### searchWithGroupIdList:list:forceRefresh:

`- (BMXErrorCode)searchWithGroupIdList:(ListOfLongLong *)*groupIdList* list:(BMXGroupList *)*list* forceRefresh:(BOOL)*forceRefresh*`

<a name="//api/name/searchWithList:forceRefresh:" title="searchWithList:forceRefresh:"></a>
### searchWithList:forceRefresh:

`- (BMXErrorCode)searchWithList:(BMXGroupList *)*list* forceRefresh:(BOOL)*forceRefresh*`

<a name="//api/name/searchWithList:name:" title="searchWithList:name:"></a>
### searchWithList:name:

`- (BMXErrorCode)searchWithList:(BMXGroupList *)*list* name:(NSString *)*name*`

<a name="//api/name/setAllowMemberModify:enable:" title="setAllowMemberModify:enable:"></a>
### setAllowMemberModify:enable:

设置是否允许群成员设置群信息

`- (BMXErrorCode)setAllowMemberModify:(BMXGroup *)*group* enable:(BOOL)*enable*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否允许操作  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAllowMemberModify:enable:completion:" title="setAllowMemberModify:enable:completion:"></a>
### setAllowMemberModify:enable:completion:

设置是否允许群成员设置群信息

`- (void)setAllowMemberModify:(BMXGroup *)*group* enable:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否允许操作  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAvatar:avatarPath:arg3:" title="setAvatar:avatarPath:arg3:"></a>
### setAvatar:avatarPath:arg3:

设置群头像

`- (BMXErrorCode)setAvatar:(BMXGroup *)*group* avatarPath:(NSString *)*avatarPath* arg3:(void ( ^ ) ( int progress ))*arg3*`

#### Parameters

*group*  
   进行操作的群组  

*avatarPath*  
   群头像文件的本地路径  

*Callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAvatar:avatarPath:arg3:completion:" title="setAvatar:avatarPath:arg3:completion:"></a>
### setAvatar:avatarPath:arg3:completion:

设置群头像

`- (void)setAvatar:(BMXGroup *)*group* avatarPath:(NSString *)*avatarPath* arg3:(void ( ^ ) ( int progress ))*arg3* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*avatarPath*  
   群头像文件的本地路径  

*Callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setDescription:description:" title="setDescription:description:"></a>
### setDescription:description:

设置群描述信息

`- (BMXErrorCode)setDescription:(BMXGroup *)*group* description:(NSString *)*description*`

#### Parameters

*group*  
   进行操作的群组  

*description*  
   群组描述  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setDescription:description:completion:" title="setDescription:description:completion:"></a>
### setDescription:description:completion:

设置群描述信息

`- (void)setDescription:(BMXGroup *)*group* description:(NSString *)*description* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*description*  
   群组描述  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableReadAck:enable:" title="setEnableReadAck:enable:"></a>
### setEnableReadAck:enable:

设置是否开启群消息已读功能

`- (BMXErrorCode)setEnableReadAck:(BMXGroup *)*group* enable:(BOOL)*enable*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否开启  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEnableReadAck:enable:completion:" title="setEnableReadAck:enable:completion:"></a>
### setEnableReadAck:enable:completion:

设置是否开启群消息已读功能

`- (void)setEnableReadAck:(BMXGroup *)*group* enable:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否开启  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setExtension:extension:" title="setExtension:extension:"></a>
### setExtension:extension:

设置群扩展信息

`- (BMXErrorCode)setExtension:(BMXGroup *)*group* extension:(NSString *)*extension*`

#### Parameters

*group*  
   进行操作的群组  

*extension*  
   群组的扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setExtension:extension:completion:" title="setExtension:extension:completion:"></a>
### setExtension:extension:completion:

设置群扩展信息

`- (void)setExtension:(BMXGroup *)*group* extension:(NSString *)*extension* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*extension*  
   群组的扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setHistoryVisible:enable:" title="setHistoryVisible:enable:"></a>
### setHistoryVisible:enable:

设置群成员是否开可见群历史聊天记录

`- (BMXErrorCode)setHistoryVisible:(BMXGroup *)*group* enable:(BOOL)*enable*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否开启  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setHistoryVisible:enable:completion:" title="setHistoryVisible:enable:completion:"></a>
### setHistoryVisible:enable:completion:

设置群成员是否开可见群历史聊天记录

`- (void)setHistoryVisible:(BMXGroup *)*group* enable:(BOOL)*enable* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*enable*  
   是否开启  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setInviteMode:mode:" title="setInviteMode:mode:"></a>
### setInviteMode:mode:

设置邀请模式

`- (BMXErrorCode)setInviteMode:(BMXGroup *)*group* mode:(BMXGroup_InviteMode)*mode*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群组的邀请模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setInviteMode:mode:completion:" title="setInviteMode:mode:completion:"></a>
### setInviteMode:mode:completion:

设置邀请模式

`- (void)setInviteMode:(BMXGroup *)*group* mode:(BMXGroup_InviteMode)*mode* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群组的邀请模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setJoinAuthMode:mode:" title="setJoinAuthMode:mode:"></a>
### setJoinAuthMode:mode:

设置入群审批模式

`- (BMXErrorCode)setJoinAuthMode:(BMXGroup *)*group* mode:(BMXGroup_JoinAuthMode)*mode*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   入群审批模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setJoinAuthMode:mode:completion:" title="setJoinAuthMode:mode:completion:"></a>
### setJoinAuthMode:mode:completion:

设置入群审批模式

`- (void)setJoinAuthMode:(BMXGroup *)*group* mode:(BMXGroup_JoinAuthMode)*mode* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   入群审批模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMsgPushMode:mode:" title="setMsgPushMode:mode:"></a>
### setMsgPushMode:mode:

设置群消息通知模式

`- (BMXErrorCode)setMsgPushMode:(BMXGroup *)*group* mode:(BMXGroup_MsgPushMode)*mode*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群消息通知模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMsgPushMode:mode:completion:" title="setMsgPushMode:mode:completion:"></a>
### setMsgPushMode:mode:completion:

设置群消息通知模式

`- (void)setMsgPushMode:(BMXGroup *)*group* mode:(BMXGroup_MsgPushMode)*mode* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*mode*  
   群消息通知模式  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMyNickname:nickname:" title="setMyNickname:nickname:"></a>
### setMyNickname:nickname:

设置在群里的昵称

`- (BMXErrorCode)setMyNickname:(BMXGroup *)*group* nickname:(NSString *)*nickname*`

#### Parameters

*group*  
   进行操作的群组  

*nickname*  
   用户在群组内的昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMyNickname:nickname:completion:" title="setMyNickname:nickname:completion:"></a>
### setMyNickname:nickname:completion:

设置在群里的昵称

`- (void)setMyNickname:(BMXGroup *)*group* nickname:(NSString *)*nickname* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*nickname*  
   用户在群组内的昵称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setName:name:" title="setName:name:"></a>
### setName:name:

设置群名称

`- (BMXErrorCode)setName:(BMXGroup *)*group* name:(NSString *)*name*`

#### Parameters

*group*  
   进行操作的群组  

*name*  
   群组名称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setName:name:completion:" title="setName:name:completion:"></a>
### setName:name:completion:

设置群名称

`- (void)setName:(BMXGroup *)*group* name:(NSString *)*name* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*name*  
   群组名称  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/transferOwnerWithGroup:newOwnerId:" title="transferOwnerWithGroup:newOwnerId:"></a>
### transferOwnerWithGroup:newOwnerId:

转移群主

`- (BMXErrorCode)transferOwnerWithGroup:(BMXGroup *)*group* newOwnerId:(long long)*newOwnerId*`

#### Parameters

*group*  
   进行操作的群组  

*newOwnerId*  
   转让为新群主的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/transferOwnerWithGroup:newOwnerId:completion:" title="transferOwnerWithGroup:newOwnerId:completion:"></a>
### transferOwnerWithGroup:newOwnerId:completion:

转移群主

`- (void)transferOwnerWithGroup:(BMXGroup *)*group* newOwnerId:(long long)*newOwnerId* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*newOwnerId*  
   转让为新群主的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unbanGroupWithGroup:" title="unbanGroupWithGroup:"></a>
### unbanGroupWithGroup:

全员解除禁言

`- (BMXErrorCode)unbanGroupWithGroup:(BMXGroup *)*group*`

#### Parameters

*group*  
   进行操作的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unbanGroupWithGroup:completion:" title="unbanGroupWithGroup:completion:"></a>
### unbanGroupWithGroup:completion:

全员解除禁言

`- (void)unbanGroupWithGroup:(BMXGroup *)*group* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unbanMembersWithGroup:members:" title="unbanMembersWithGroup:members:"></a>
### unbanMembersWithGroup:members:

解除禁言

`- (BMXErrorCode)unbanMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   被解除禁言的群成员id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unbanMembersWithGroup:members:completion:" title="unbanMembersWithGroup:members:completion:"></a>
### unbanMembersWithGroup:members:completion:

解除禁言

`- (void)unbanMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   被解除禁言的群成员id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unblockMembersWithGroup:members:" title="unblockMembersWithGroup:members:"></a>
### unblockMembersWithGroup:members:

从黑名单删除

`- (BMXErrorCode)unblockMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   从黑名单移除的用户id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unblockMembersWithGroup:members:completion:" title="unblockMembersWithGroup:members:completion:"></a>
### unblockMembersWithGroup:members:completion:

从黑名单删除

`- (void)unblockMembersWithGroup:(BMXGroup *)*group* members:(ListOfLongLong *)*members* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*members*  
   从黑名单移除的用户id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:" title="uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:"></a>
### uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:

添加群共享文件

`- (BMXErrorCode)uploadSharedFileWithGroup:(BMXGroup *)*group* filePath:(NSString *)*filePath* displayName:(NSString *)*displayName* extensionName:(NSString *)*extensionName* arg5:(void ( ^ ) ( int progress ))*arg5*`

#### Parameters

*group*  
   进行操作的群组  

*filePath*  
   文件的本地路径  

*displayName*  
   文件的展示名  

*extensionName*  
   文件的扩展名  

*Callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:completion:" title="uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:completion:"></a>
### uploadSharedFileWithGroup:filePath:displayName:extensionName:arg5:completion:

添加群共享文件

`- (void)uploadSharedFileWithGroup:(BMXGroup *)*group* filePath:(NSString *)*filePath* displayName:(NSString *)*displayName* extensionName:(NSString *)*extensionName* arg5:(void ( ^ ) ( int progress ))*arg5* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*group*  
   进行操作的群组  

*filePath*  
   文件的本地路径  

*displayName*  
   文件的展示名  

*extensionName*  
   文件的扩展名  

*Callback*  
   上传回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

