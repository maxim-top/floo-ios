# BMXRosterService Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 好友Service

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/acceptWithRosterId:" title="acceptWithRosterId:"></a>
### acceptWithRosterId:

接受加好友申请

`- (BMXErrorCode)acceptWithRosterId:(long long)*rosterId*`

#### Parameters

*rosterId*  
   申请加为好友的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/acceptWithRosterId:completion:" title="acceptWithRosterId:completion:"></a>
### acceptWithRosterId:completion:

接受加好友申请

`- (void)acceptWithRosterId:(long long)*rosterId* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   申请加为好友的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:" title="addDelegate:"></a>
### addDelegate:

添加好友变化监听者

`- (void)addDelegate:(id<BMXRosterServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   好友变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/addDelegate:delegateQueue:" title="addDelegate:delegateQueue:"></a>
### addDelegate:delegateQueue:

`- (void)addDelegate:(id<BMXRosterServiceProtocol>)*aDelegate* delegateQueue:(dispatch_queue_t)*aQueue*`

<a name="//api/name/addRosterListener:" title="addRosterListener:"></a>
### addRosterListener:

添加好友变化监听者

`- (void)addRosterListener:(id<BMXRosterServiceProtocol>)*listener*`

#### Parameters

*listener*  
   好友变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/applyWithRosterId:message:" title="applyWithRosterId:message:"></a>
### applyWithRosterId:message:

`- (BMXErrorCode)applyWithRosterId:(long long)*rosterId* message:(NSString *)*message*`

<a name="//api/name/applyWithRosterId:message:authAnswer:" title="applyWithRosterId:message:authAnswer:"></a>
### applyWithRosterId:message:authAnswer:

申请添加好友

`- (BMXErrorCode)applyWithRosterId:(long long)*rosterId* message:(NSString *)*message* authAnswer:(NSString *)*authAnswer*`

#### Parameters

*rosterId*  
   申请添加的用户id  

*message*  
   好友申请信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/applyWithRosterId:message:authAnswer:completion:" title="applyWithRosterId:message:authAnswer:completion:"></a>
### applyWithRosterId:message:authAnswer:completion:

申请添加好友

`- (void)applyWithRosterId:(long long)*rosterId* message:(NSString *)*message* authAnswer:(NSString *)*authAnswer* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   申请添加的用户id  

*message*  
   好友申请信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/applyWithRosterId:message:completion:" title="applyWithRosterId:message:completion:"></a>
### applyWithRosterId:message:completion:

`- (void)applyWithRosterId:(long long)*rosterId* message:(NSString *)*message* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

<a name="//api/name/blockWithRosterId:" title="blockWithRosterId:"></a>
### blockWithRosterId:

加入黑名单

`- (BMXErrorCode)blockWithRosterId:(long long)*rosterId*`

#### Parameters

*rosterId*  
   加入黑名单的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/blockWithRosterId:completion:" title="blockWithRosterId:completion:"></a>
### blockWithRosterId:completion:

加入黑名单

`- (void)blockWithRosterId:(long long)*rosterId* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   加入黑名单的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/declineWithRosterId:reason:" title="declineWithRosterId:reason:"></a>
### declineWithRosterId:reason:

拒绝加好友申请

`- (BMXErrorCode)declineWithRosterId:(long long)*rosterId* reason:(NSString *)*reason*`

#### Parameters

*rosterId*  
   申请加为好友的用户id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/declineWithRosterId:reason:completion:" title="declineWithRosterId:reason:completion:"></a>
### declineWithRosterId:reason:completion:

拒绝加好友申请

`- (void)declineWithRosterId:(long long)*rosterId* reason:(NSString *)*reason* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   申请加为好友的用户id  

*reason*  
   拒绝的原因  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithItem:thumbnail:callback:" title="downloadAvatarWithItem:thumbnail:callback:"></a>
### downloadAvatarWithItem:thumbnail:callback:

下载头像

`- (BMXErrorCode)downloadAvatarWithItem:(BMXRosterItem *)*item* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback*`

#### Parameters

*item*  
   用户信息  

*thumbnail*  
   是否下载缩略图，ture为缩略图，false为原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/downloadAvatarWithItem:thumbnail:callback:completion:" title="downloadAvatarWithItem:thumbnail:callback:completion:"></a>
### downloadAvatarWithItem:thumbnail:callback:completion:

下载头像

`- (void)downloadAvatarWithItem:(BMXRosterItem *)*item* thumbnail:(BOOL)*thumbnail* callback:(void ( ^ ) ( int progress ))*callback* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*item*  
   用户信息  

*thumbnail*  
   是否下载缩略图，ture为缩略图，false为原图  

*callback*  
   下载回调函数  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRosterByIdWithRosterId:forceRefresh:completion:" title="fetchRosterByIdWithRosterId:forceRefresh:completion:"></a>
### fetchRosterByIdWithRosterId:forceRefresh:completion:

通过联系人id搜索用户

`- (void)fetchRosterByIdWithRosterId:(long long)*rosterId* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItem *item , BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   搜索的好友id  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRosterByIdWithRosterId:forceRefresh:item:" title="fetchRosterByIdWithRosterId:forceRefresh:item:"></a>
### fetchRosterByIdWithRosterId:forceRefresh:item:

通过联系人id搜索用户

`- (BMXErrorCode)fetchRosterByIdWithRosterId:(long long)*rosterId* forceRefresh:(BOOL)*forceRefresh* item:(BMXRosterItem *)*item*`

#### Parameters

*rosterId*  
   搜索的好友id  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRosterByNameWithName:forceRefresh:completion:" title="fetchRosterByNameWithName:forceRefresh:completion:"></a>
### fetchRosterByNameWithName:forceRefresh:completion:

通过用户名搜索用户

`- (void)fetchRosterByNameWithName:(NSString *)*name* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItem *item , BMXError *error ))*aCompletionBlock*`

#### Parameters

*name*  
   搜索的用户名  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRosterByNameWithName:forceRefresh:item:" title="fetchRosterByNameWithName:forceRefresh:item:"></a>
### fetchRosterByNameWithName:forceRefresh:item:

通过用户名搜索用户

`- (BMXErrorCode)fetchRosterByNameWithName:(NSString *)*name* forceRefresh:(BOOL)*forceRefresh* item:(BMXRosterItem *)*item*`

#### Parameters

*name*  
   搜索的用户名  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRostersByIdListWithRosterIdList:forceRefresh:completion:" title="fetchRostersByIdListWithRosterIdList:forceRefresh:completion:"></a>
### fetchRostersByIdListWithRosterIdList:forceRefresh:completion:

通过联系人id列表批量搜索用户

`- (void)fetchRostersByIdListWithRosterIdList:(ListOfLongLong *)*rosterIdList* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItemList *list , BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterIdList*  
   需要搜索的用户id列表  

*forceRefresh*  
   是否强制从服务器获取，为true则强制从服务器获取  

*list*  
   返回的好友信息列表，传入空列表函数返回后从此处获取返回的好友信息列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/fetchRostersByIdListWithRosterIdList:list:forceRefresh:" title="fetchRostersByIdListWithRosterIdList:list:forceRefresh:"></a>
### fetchRostersByIdListWithRosterIdList:list:forceRefresh:

通过联系人id列表批量搜索用户

`- (BMXErrorCode)fetchRostersByIdListWithRosterIdList:(ListOfLongLong *)*rosterIdList* list:(BMXRosterItemList *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*rosterIdList*  
   需要搜索的用户id列表  

*list*  
   返回的好友信息列表，传入空列表函数返回后从此处获取返回的好友信息列表  

*forceRefresh*  
   是否强制从服务器获取，为true则强制从服务器获取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/get:completion:" title="get:completion:"></a>
### get:completion:

获取好友列表，如果forceRefresh == true，则强制从服务端拉取

`- (void)get:(BOOL)*forceRefresh* completion:(void ( ^ ) ( ListOfLongLong *list , BMXError *error ))*aCompletionBlock*`

#### Parameters

*forceRefresh*  
   是否从服务器读取数据，true为强制从服务器获取，false情况下本地读取列表为空的情况下会自动从服务器读取  

*list*  
   好友id列表，传入空列表函数返回后从此处获取返回的好友id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/get:forceRefresh:" title="get:forceRefresh:"></a>
### get:forceRefresh:

获取好友列表，如果forceRefresh == true，则强制从服务端拉取

`- (BMXErrorCode)get:(ListOfLongLong *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*list*  
   好友id列表，传入空列表函数返回后从此处获取返回的好友id列表  

*forceRefresh*  
   是否从服务器读取数据，true为强制从服务器获取，false情况下本地读取列表为空的情况下会自动从服务器读取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getApplicationList:completion:" title="getApplicationList:completion:"></a>
### getApplicationList:completion:

`- (void)getApplicationList:(NSString *)*cursor* completion:(void ( ^ ) ( BMXRosterApplicationResultPage *res , BMXError *error ))*aCompletionBlock*`

<a name="//api/name/getApplicationList:cursor:" title="getApplicationList:cursor:"></a>
### getApplicationList:cursor:

`- (BMXErrorCode)getApplicationList:(BMXRosterApplicationResultPage *)*result* cursor:(NSString *)*cursor*`

<a name="//api/name/getApplicationList:cursor:pageSize:" title="getApplicationList:cursor:pageSize:"></a>
### getApplicationList:cursor:pageSize:

获取申请添加好友列表

`- (BMXErrorCode)getApplicationList:(BMXRosterApplicationResultPage *)*result* cursor:(NSString *)*cursor* pageSize:(int)*pageSize*`

#### Parameters

*result*  
   返回的申请好友列表信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getApplicationList:pageSize:completion:" title="getApplicationList:pageSize:completion:"></a>
### getApplicationList:pageSize:completion:

获取申请添加好友列表

`- (void)getApplicationList:(NSString *)*cursor* pageSize:(int)*pageSize* completion:(void ( ^ ) ( BMXRosterApplicationResultPage *res , BMXError *error ))*aCompletionBlock*`

#### Parameters

*cursor*  
   分页获取的起始cursor，第一次传入为空，后续传入上次操作返回的result中的cursor  

*pageSize*  
   分页大小  

*result*  
   返回的申请好友列表信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:completion:" title="getBlockList:completion:"></a>
### getBlockList:completion:

获取黑名单，如果forceRefresh == true，则强制从服务端拉取

`- (void)getBlockList:(BOOL)*forceRefresh* completion:(void ( ^ ) ( ListOfLongLong *list , BMXError *error ))*aCompletionBlock*`

#### Parameters

*forceRefresh*  
   是否从服务器读取数据，true为强制从服务器获取，false情况下本地读取列表为空的情况下会自动从服务器读取  

*list*  
   好友id列表，传入空列表函数返回后从此处获取返回的黑名单id列表  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/getBlockList:forceRefresh:" title="getBlockList:forceRefresh:"></a>
### getBlockList:forceRefresh:

获取黑名单，如果forceRefresh == true，则强制从服务端拉取

`- (BMXErrorCode)getBlockList:(ListOfLongLong *)*list* forceRefresh:(BOOL)*forceRefresh*`

#### Parameters

*list*  
   好友id列表，传入空列表函数返回后从此处获取返回的黑名单id列表  

*forceRefresh*  
   是否从服务器读取数据，true为强制从服务器获取，false情况下本地读取列表为空的情况下会自动从服务器读取  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/removeDelegate:" title="removeDelegate:"></a>
### removeDelegate:

移除好友变化监听者

`- (void)removeDelegate:(id<BMXRosterServiceProtocol>)*aDelegate*`

#### Parameters

*listener*  
   好友变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeRosterListener:" title="removeRosterListener:"></a>
### removeRosterListener:

移除好友变化监听者

`- (void)removeRosterListener:(id<BMXRosterServiceProtocol>)*listener*`

#### Parameters

*listener*  
   好友变化监听者  

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeWithRosterId:" title="removeWithRosterId:"></a>
### removeWithRosterId:

删除好友

`- (BMXErrorCode)removeWithRosterId:(long long)*rosterId*`

#### Parameters

*rosterId*  
   删除的好友id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeWithRosterId:completion:" title="removeWithRosterId:completion:"></a>
### removeWithRosterId:completion:

删除好友

`- (void)removeWithRosterId:(long long)*rosterId* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   删除的好友id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchWithName:forceRefresh:completion:" title="searchWithName:forceRefresh:completion:"></a>
### searchWithName:forceRefresh:completion:

`- (void)searchWithName:(NSString *)*name* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItem *item , BMXError *error ))*aCompletionBlock*`

<a name="//api/name/searchWithName:forceRefresh:item:" title="searchWithName:forceRefresh:item:"></a>
### searchWithName:forceRefresh:item:

`- (BMXErrorCode)searchWithName:(NSString *)*name* forceRefresh:(BOOL)*forceRefresh* item:(BMXRosterItem *)*item*`

<a name="//api/name/searchWithRosterId:forceRefresh:completion:" title="searchWithRosterId:forceRefresh:completion:"></a>
### searchWithRosterId:forceRefresh:completion:

搜索用户

`- (void)searchWithRosterId:(long long)*rosterId* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItem *item , BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   搜索的好友id  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Discussion
Deprecated. use fetchRosterById instead.

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchWithRosterId:forceRefresh:item:" title="searchWithRosterId:forceRefresh:item:"></a>
### searchWithRosterId:forceRefresh:item:

搜索用户

`- (BMXErrorCode)searchWithRosterId:(long long)*rosterId* forceRefresh:(BOOL)*forceRefresh* item:(BMXRosterItem *)*item*`

#### Parameters

*rosterId*  
   搜索的好友id  

*forceRefresh*  
   为true强制从服务器获取，为false情况下查询结果为空时自动从服务器获取。  

*item*  
   查询返回的用户的信息，传入指向为空的shared_ptr对象函数执行后会自动赋值。  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Discussion
Deprecated. use fetchRosterById instead.

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchWithRosterIdList:forceRefresh:completion:" title="searchWithRosterIdList:forceRefresh:completion:"></a>
### searchWithRosterIdList:forceRefresh:completion:

`- (void)searchWithRosterIdList:(ListOfLongLong *)*rosterIdList* forceRefresh:(BOOL)*forceRefresh* completion:(void ( ^ ) ( BMXRosterItemList *list , BMXError *error ))*aCompletionBlock*`

<a name="//api/name/searchWithRosterIdList:list:forceRefresh:" title="searchWithRosterIdList:list:forceRefresh:"></a>
### searchWithRosterIdList:list:forceRefresh:

`- (BMXErrorCode)searchWithRosterIdList:(ListOfLongLong *)*rosterIdList* list:(BMXRosterItemList *)*list* forceRefresh:(BOOL)*forceRefresh*`

<a name="//api/name/setItemAlias:alias:" title="setItemAlias:alias:"></a>
### setItemAlias:alias:

更新好友别名

`- (BMXErrorCode)setItemAlias:(BMXRosterItem *)*item* alias:(NSString *)*alias*`

#### Parameters

*item*  
   用户信息  

*alias*  
   好友别名  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemAlias:alias:completion:" title="setItemAlias:alias:completion:"></a>
### setItemAlias:alias:completion:

更新好友别名

`- (void)setItemAlias:(BMXRosterItem *)*item* alias:(NSString *)*alias* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*item*  
   用户信息  

*alias*  
   好友别名  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemExtension:extension:" title="setItemExtension:extension:"></a>
### setItemExtension:extension:

更新好友服务器扩展信息

`- (BMXErrorCode)setItemExtension:(BMXRosterItem *)*item* extension:(NSString *)*extension*`

#### Parameters

*item*  
   用户信息  

*extension*  
   服务器扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemExtension:extension:completion:" title="setItemExtension:extension:completion:"></a>
### setItemExtension:extension:completion:

更新好友服务器扩展信息

`- (void)setItemExtension:(BMXRosterItem *)*item* extension:(NSString *)*extension* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*item*  
   用户信息  

*extension*  
   服务器扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemLocalExtension:extension:" title="setItemLocalExtension:extension:"></a>
### setItemLocalExtension:extension:

更新好友本地扩展信息

`- (BMXErrorCode)setItemLocalExtension:(BMXRosterItem *)*item* extension:(NSString *)*extension*`

#### Parameters

*item*  
   用户信息  

*extension*  
   本地扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemLocalExtension:extension:completion:" title="setItemLocalExtension:extension:completion:"></a>
### setItemLocalExtension:extension:completion:

更新好友本地扩展信息

`- (void)setItemLocalExtension:(BMXRosterItem *)*item* extension:(NSString *)*extension* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*item*  
   用户信息  

*extension*  
   本地扩展信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemMuteNotification:status:" title="setItemMuteNotification:status:"></a>
### setItemMuteNotification:status:

设置是否拒收用户消息

`- (BMXErrorCode)setItemMuteNotification:(BMXRosterItem *)*item* status:(BOOL)*status*`

#### Parameters

*item*  
   用户信息  

*status*  
   是否拒收用户消息，true拒收，false不拒收  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setItemMuteNotification:status:completion:" title="setItemMuteNotification:status:completion:"></a>
### setItemMuteNotification:status:completion:

设置是否拒收用户消息

`- (void)setItemMuteNotification:(BMXRosterItem *)*item* status:(BOOL)*status* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*item*  
   用户信息  

*status*  
   是否拒收用户消息，true拒收，false不拒收  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unblockWithRosterId:" title="unblockWithRosterId:"></a>
### unblockWithRosterId:

从黑名单移除

`- (BMXErrorCode)unblockWithRosterId:(long long)*rosterId*`

#### Parameters

*rosterId*  
   从黑名单移除的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unblockWithRosterId:completion:" title="unblockWithRosterId:completion:"></a>
### unblockWithRosterId:completion:

从黑名单移除

`- (void)unblockWithRosterId:(long long)*rosterId* completion:(void ( ^ ) ( BMXError *error ))*aCompletionBlock*`

#### Parameters

*rosterId*  
   从黑名单移除的用户id  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

