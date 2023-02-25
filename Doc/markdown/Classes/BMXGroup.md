# BMXGroup Class Reference

  **Inherits from** <a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 群组

## Instance Methods

<a name="//api/name/adminsCount" title="adminsCount"></a>
### adminsCount

群管理员数量

`- (int)adminsCount`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarPath" title="avatarPath"></a>
### avatarPath

群头像下载后的本地路径

`- (NSString *)avatarPath`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarRatelUrl" title="avatarRatelUrl"></a>
### avatarRatelUrl

群头像Ratel服务器Url

`- (NSString *)avatarRatelUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarThumbnailPath" title="avatarThumbnailPath"></a>
### avatarThumbnailPath

群头像缩略图下载后的本地路径

`- (NSString *)avatarThumbnailPath`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarThumbnailUrl" title="avatarThumbnailUrl"></a>
### avatarThumbnailUrl

群头像缩略图服务器Url

`- (NSString *)avatarThumbnailUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/avatarUrl" title="avatarUrl"></a>
### avatarUrl

群头像服务器Url

`- (NSString *)avatarUrl`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/banExpireTime" title="banExpireTime"></a>
### banExpireTime

群组全员禁言到期时间

`- (long long)banExpireTime`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/bannedListSize" title="bannedListSize"></a>
### bannedListSize

禁言数量

`- (int)bannedListSize`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/blockListSize" title="blockListSize"></a>
### blockListSize

黑名单数量

`- (int)blockListSize`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/capacity" title="capacity"></a>
### capacity

最大人数

`- (int)capacity`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/createTime" title="createTime"></a>
### createTime

群创建时间

`- (long long)createTime`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/description" title="description"></a>
### description

群描述

`- (NSString *)description`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/enableReadAck" title="enableReadAck"></a>
### enableReadAck

是否开启群消息已读功能

`- (BOOL)enableReadAck`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/extension" title="extension"></a>
### extension

群扩展信息

`- (NSString *)extension`

#### Return Value
JSON(std::string)

#### Declared In
* `floo_proxy.h`

<a name="//api/name/groupId" title="groupId"></a>
### groupId

群Id

`- (long long)groupId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/groupStatus" title="groupStatus"></a>
### groupStatus

当前群组的状态。（Normal 正常， Destroyed 以销毁）

`- (BMXGroup_GroupStatus)groupStatus`

#### Return Value
<a href="../Constants/BMXGroup_GroupStatus.md">BMXGroup_GroupStatus</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/groupType" title="groupType"></a>
### groupType

当前群组的群组类型（Private 私有群组，Public 公开群组，Chatroom 聊天室）

`- (BMXGroup_GroupType)groupType`

#### Return Value
<a href="../Constants/BMXGroup_GroupType.md">BMXGroup_GroupType</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/historyVisible" title="historyVisible"></a>
### historyVisible

是否可以加载显示历史聊天记录

`- (BOOL)historyVisible`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/inviteMode" title="inviteMode"></a>
### inviteMode

入群邀请模式

`- (BMXGroup_InviteMode)inviteMode`

#### Return Value
<a href="../Constants/BMXGroup_InviteMode.md">BMXGroup_InviteMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/isMember" title="isMember"></a>
### isMember

当前用户是否是群成员

`- (BOOL)isMember`

#### Return Value
BOOL

#### Discussion
Deprecated use <a href="#//api/name/roleType">roleType</a> instead.

#### Declared In
* `floo_proxy.h`

<a name="//api/name/joinAuthMode" title="joinAuthMode"></a>
### joinAuthMode

入群审批模式

`- (BMXGroup_JoinAuthMode)joinAuthMode`

#### Return Value
<a href="../Constants/BMXGroup_JoinAuthMode.md">BMXGroup_JoinAuthMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/latestAnnouncementId" title="latestAnnouncementId"></a>
### latestAnnouncementId

最新群公告id

`- (long long)latestAnnouncementId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/membersCount" title="membersCount"></a>
### membersCount

群成员数量，包含Owner，admins 和members

`- (int)membersCount`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/modifyMode" title="modifyMode"></a>
### modifyMode

群信息修改模式

`- (BMXGroup_ModifyMode)modifyMode`

#### Return Value
<a href="../Constants/BMXGroup_ModifyMode.md">BMXGroup_ModifyMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/msgMuteMode" title="msgMuteMode"></a>
### msgMuteMode

群消息屏蔽模式

`- (BMXGroup_MsgMuteMode)msgMuteMode`

#### Return Value
<a href="../Constants/BMXGroup_MsgMuteMode.md">BMXGroup_MsgMuteMode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/msgPushMode" title="msgPushMode"></a>
### msgPushMode

群消息通知类型

`- (BMXGroup_MsgPushMode)msgPushMode`

#### Return Value
MsgPushMode

#### Declared In
* `floo_proxy.h`

<a name="//api/name/myNickname" title="myNickname"></a>
### myNickname

在群里的昵称

`- (NSString *)myNickname`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/name" title="name"></a>
### name

群名称

`- (NSString *)name`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/ownerId" title="ownerId"></a>
### ownerId

群Owner

`- (long long)ownerId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/roleType" title="roleType"></a>
### roleType

成员在群组内的角色类型

`- (BMXGroup_MemberRoleType)roleType`

#### Return Value
<a href="../Constants/BMXGroup_MemberRoleType.md">BMXGroup_MemberRoleType</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/sharedFilesCount" title="sharedFilesCount"></a>
### sharedFilesCount

群共享文件数量

`- (int)sharedFilesCount`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

