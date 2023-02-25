# BMXConversation Class Reference

  **Inherits from** <a href="../Classes/BMXBaseObject.md">BMXBaseObject</a> :   
NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface 会话

## Instance Methods

<a name="//api/name/conversationId" title="conversationId"></a>
### conversationId

会话Id

`- (long long)conversationId`

#### Return Value
long long

#### Declared In
* `floo_proxy.h`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/editMessage" title="editMessage"></a>
### editMessage

编辑消息

`- (NSString *)editMessage`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/extension" title="extension"></a>
### extension

扩展信息

`- (NSString *)extension`

#### Return Value
NSString

#### Declared In
* `floo_proxy.h`

<a name="//api/name/insertMessageWithMsg:" title="insertMessageWithMsg:"></a>
### insertMessageWithMsg:

插入一条消息

`- (BMXErrorCode)insertMessageWithMsg:(BMXMessage *)*msg*`

#### Parameters

*msg*  
   插入的消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/insertMessageWithMsg:completion:" title="insertMessageWithMsg:completion:"></a>
### insertMessageWithMsg:completion:

插入一条消息

`- (void)insertMessageWithMsg:(BMXMessage *)*msg* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*msg*  
   插入的消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/isMuteNotification" title="isMuteNotification"></a>
### isMuteNotification

是否提醒用户消息,不提醒的情况下会话总未读数不会统计该会话计数。

`- (BOOL)isMuteNotification`

#### Return Value
BOOL

#### Declared In
* `floo_proxy.h`

<a name="//api/name/lastMsg" title="lastMsg"></a>
### lastMsg

最新消息

`- (BMXMessage *)lastMsg`

#### Return Value
<a href="../Classes/BMXMessage.md">BMXMessage</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/loadMessageWithMsgId:" title="loadMessageWithMsgId:"></a>
### loadMessageWithMsgId:

读取一条消息

`- (BMXMessage *)loadMessageWithMsgId:(long long)*msgId*`

#### Parameters

*msgId*  
   需要读取的消息的消息id  

#### Return Value
<a href="../Classes/BMXMessage.md">BMXMessage</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/loadMessageWithMsgId:completion:" title="loadMessageWithMsgId:completion:"></a>
### loadMessageWithMsgId:completion:

读取一条消息

`- (void)loadMessageWithMsgId:(long long)*msgId* completion:(void ( ^ ) ( BMXMessage *res , BMXError *aError ))*resBlock*`

#### Parameters

*msgId*  
   需要读取的消息的消息id  

#### Return Value
<a href="../Classes/BMXMessage.md">BMXMessage</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/loadMessagesWithRefMsgId:size:arg4:completion:" title="loadMessagesWithRefMsgId:size:arg4:completion:"></a>
### loadMessagesWithRefMsgId:size:arg4:completion:

加载消息，如果不指定则从最新消息开始

`- (void)loadMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* arg4:(BMXConversation_Direction)*arg4* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

#### Parameters

*refMsgId*  
   加载消息的起始id  

*size*  
   最大加载消息条数  

*result*  
   数据库返回的加载消息列表  

*Direction*  
   加载消息的方向，默认是加载更早的消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/loadMessagesWithRefMsgId:size:completion:" title="loadMessagesWithRefMsgId:size:completion:"></a>
### loadMessagesWithRefMsgId:size:completion:

搜索消息，如果不指定则从最新消息开始

`- (void)loadMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

#### Parameters

*size*  
   最大加载消息条数  

*refTime*  
   搜索消息的起始时间  

*result*  
   搜索到的消息结果列表  

*keywords*  
   搜索消息的关键字  

*Direction*  
   消息搜索方向，默认（Direction::Up）是从更早的消息中搜索  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/loadMessagesWithRefMsgId:size:result:" title="loadMessagesWithRefMsgId:size:result:"></a>
### loadMessagesWithRefMsgId:size:result:

`- (BMXErrorCode)loadMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* result:(BMXMessageList *)*result*`

<a name="//api/name/loadMessagesWithRefMsgId:size:result:arg4:" title="loadMessagesWithRefMsgId:size:result:arg4:"></a>
### loadMessagesWithRefMsgId:size:result:arg4:

加载消息，如果不指定则从最新消息开始

`- (BMXErrorCode)loadMessagesWithRefMsgId:(long long)*refMsgId* size:(unsigned long)*size* result:(BMXMessageList *)*result* arg4:(BMXConversation_Direction)*arg4*`

#### Parameters

*refMsgId*  
   加载消息的起始id  

*size*  
   最大加载消息条数  

*result*  
   数据库返回的加载消息列表  

*Direction*  
   加载消息的方向，默认是加载更早的消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/messageCount" title="messageCount"></a>
### messageCount

会话中所有消息的数量

`- (int)messageCount`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/refreshConversation" title="refreshConversation"></a>
### refreshConversation

读取数据库当前会话所有消息数量，强制更新conversation的消息总数和未读消息数。

`- (BMXErrorCode)refreshConversation`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/refreshConversationWithCompletion:" title="refreshConversationWithCompletion:"></a>
### refreshConversationWithCompletion:

读取数据库当前会话所有消息数量，强制更新conversation的消息总数和未读消息数。

`- (void)refreshConversationWithCompletion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeAllMessages" title="removeAllMessages"></a>
### removeAllMessages

删除会话中的所有消息

`- (BMXErrorCode)removeAllMessages`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/removeAllMessagesWithCompletion:" title="removeAllMessagesWithCompletion:"></a>
### removeAllMessagesWithCompletion:

删除会话中的所有消息

`- (void)removeAllMessagesWithCompletion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchMessagesByKeyWordsWithKeywords:refTime:size:arg5:completion:" title="searchMessagesByKeyWordsWithKeywords:refTime:size:arg5:completion:"></a>
### searchMessagesByKeyWordsWithKeywords:refTime:size:arg5:completion:

搜索消息，如果不指定则从最新消息开始

`- (void)searchMessagesByKeyWordsWithKeywords:(NSString *)*keywords* refTime:(long long)*refTime* size:(unsigned long)*size* arg5:(BMXConversation_Direction)*arg5* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

#### Parameters

*keywords*  
   搜索消息的关键字  

*refTime*  
   搜索消息的起始时间  

*size*  
   最大加载消息条数  

*result*  
   搜索到的消息结果列表  

*Direction*  
   消息搜索方向，默认（Direction::Up）是从更早的消息中搜索  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Discussion
Deprecated. use searchMessagesByKeyWords instead.

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchMessagesByKeyWordsWithKeywords:refTime:size:completion:" title="searchMessagesByKeyWordsWithKeywords:refTime:size:completion:"></a>
### searchMessagesByKeyWordsWithKeywords:refTime:size:completion:

`- (void)searchMessagesByKeyWordsWithKeywords:(NSString *)*keywords* refTime:(long long)*refTime* size:(unsigned long)*size* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

<a name="//api/name/searchMessagesByKeyWordsWithKeywords:refTime:size:result:" title="searchMessagesByKeyWordsWithKeywords:refTime:size:result:"></a>
### searchMessagesByKeyWordsWithKeywords:refTime:size:result:

`- (BMXErrorCode)searchMessagesByKeyWordsWithKeywords:(NSString *)*keywords* refTime:(long long)*refTime* size:(unsigned long)*size* result:(BMXMessageList *)*result*`

<a name="//api/name/searchMessagesByKeyWordsWithKeywords:refTime:size:result:arg5:" title="searchMessagesByKeyWordsWithKeywords:refTime:size:result:arg5:"></a>
### searchMessagesByKeyWordsWithKeywords:refTime:size:result:arg5:

搜索消息，如果不指定则从最新消息开始

`- (BMXErrorCode)searchMessagesByKeyWordsWithKeywords:(NSString *)*keywords* refTime:(long long)*refTime* size:(unsigned long)*size* result:(BMXMessageList *)*result* arg5:(BMXConversation_Direction)*arg5*`

#### Parameters

*keywords*  
   搜索消息的关键字  

*refTime*  
   搜索消息的起始时间  

*size*  
   最大加载消息条数  

*result*  
   搜索到的消息结果列表  

*arg5*  
   消息搜索方向，默认（Direction::Up）是从更早的消息中搜索  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchMessagesByTypeWithType:refTime:size:arg5:completion:" title="searchMessagesByTypeWithType:refTime:size:arg5:completion:"></a>
### searchMessagesByTypeWithType:refTime:size:arg5:completion:

按照类型搜索消息，如果不指定则从最新消息开始

`- (void)searchMessagesByTypeWithType:(BMXMessage_ContentType)*type* refTime:(long long)*refTime* size:(unsigned long)*size* arg5:(BMXConversation_Direction)*arg5* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

#### Parameters

*type*  
   搜索消息的类型  

*refTime*  
   搜索消息的起始时间  

*size*  
   最大加载消息条数  

*result*  
   搜索到的消息结果列表  

*Direction*  
   消息搜索方向，默认（Direction::Up）是从更早的消息中搜索  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/searchMessagesByTypeWithType:refTime:size:completion:" title="searchMessagesByTypeWithType:refTime:size:completion:"></a>
### searchMessagesByTypeWithType:refTime:size:completion:

`- (void)searchMessagesByTypeWithType:(BMXMessage_ContentType)*type* refTime:(long long)*refTime* size:(unsigned long)*size* completion:(void ( ^ ) ( BMXMessageList *result , BMXError *aError ))*resBlock*`

<a name="//api/name/searchMessagesByTypeWithType:refTime:size:result:" title="searchMessagesByTypeWithType:refTime:size:result:"></a>
### searchMessagesByTypeWithType:refTime:size:result:

`- (BMXErrorCode)searchMessagesByTypeWithType:(BMXMessage_ContentType)*type* refTime:(long long)*refTime* size:(unsigned long)*size* result:(BMXMessageList *)*result*`

<a name="//api/name/searchMessagesByTypeWithType:refTime:size:result:arg5:" title="searchMessagesByTypeWithType:refTime:size:result:arg5:"></a>
### searchMessagesByTypeWithType:refTime:size:result:arg5:

按照类型搜索消息，如果不指定则从最新消息开始

`- (BMXErrorCode)searchMessagesByTypeWithType:(BMXMessage_ContentType)*type* refTime:(long long)*refTime* size:(unsigned long)*size* result:(BMXMessageList *)*result* arg5:(BMXConversation_Direction)*arg5*`

#### Parameters

*type*  
   搜索消息的类型  

*refTime*  
   搜索消息的起始时间  

*size*  
   最大加载消息条数  

*result*  
   搜索到的消息结果列表  

*Direction*  
   消息搜索方向，默认（Direction::Up）是从更早的消息中搜索  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAllMessagesRead" title="setAllMessagesRead"></a>
### setAllMessagesRead

把所有消息设置为已读，更新未读消息数

`- (BMXErrorCode)setAllMessagesRead`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setAllMessagesReadWithCompletion:" title="setAllMessagesReadWithCompletion:"></a>
### setAllMessagesReadWithCompletion:

把所有消息设置为已读，更新未读消息数

`- (void)setAllMessagesReadWithCompletion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setEditMessage:" title="setEditMessage:"></a>
### setEditMessage:

设置编辑消息

`- (BMXErrorCode)setEditMessage:(NSString *)*editMessage*`

#### Parameters

*editMessage*  
   会话正在编辑的文本消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setExtension:" title="setExtension:"></a>
### setExtension:

设置扩展信息

`- (BMXErrorCode)setExtension:(NSString *)*ext*`

#### Parameters

*ext*  
   会话扩展消息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMessagePlayedStatus:status:" title="setMessagePlayedStatus:status:"></a>
### setMessagePlayedStatus:status:

设置消息播放状态（只对语音/视频消息有效）

`- (BMXErrorCode)setMessagePlayedStatus:(BMXMessage *)*msg* status:(BOOL)*status*`

#### Parameters

*msg*  
   需要设置播放状态的消息  

*status*  
   消息是否已经播放  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMessagePlayedStatus:status:completion:" title="setMessagePlayedStatus:status:completion:"></a>
### setMessagePlayedStatus:status:completion:

设置消息播放状态（只对语音/视频消息有效）

`- (void)setMessagePlayedStatus:(BMXMessage *)*msg* status:(BOOL)*status* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*msg*  
   需要设置播放状态的消息  

*status*  
   消息是否已经播放  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMessageReadStatus:status:" title="setMessageReadStatus:status:"></a>
### setMessageReadStatus:status:

设置消息未读状态，更新未读消息数

`- (BMXErrorCode)setMessageReadStatus:(BMXMessage *)*msg* status:(BOOL)*status*`

#### Parameters

*msg*  
   需要设置消息已读状态的消息  

*status*  
   消息是否设置已读  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/setMessageReadStatus:status:completion:" title="setMessageReadStatus:status:completion:"></a>
### setMessageReadStatus:status:completion:

设置消息未读状态，更新未读消息数

`- (void)setMessageReadStatus:(BMXMessage *)*msg* status:(BOOL)*status* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*msg*  
   需要设置消息已读状态的消息  

*status*  
   消息是否设置已读  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/type" title="type"></a>
### type

会话类型

`- (BMXConversation_Type)type`

#### Return Value
<a href="../Constants/BMXConversation_Type.md">BMXConversation_Type</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/unreadNumber" title="unreadNumber"></a>
### unreadNumber

未读消息数

`- (int)unreadNumber`

#### Return Value
int

#### Declared In
* `floo_proxy.h`

<a name="//api/name/updateMessageExtensionWithMsg:" title="updateMessageExtensionWithMsg:"></a>
### updateMessageExtensionWithMsg:

更新一条数据库存储消息的扩展字段信息

`- (BMXErrorCode)updateMessageExtensionWithMsg:(BMXMessage *)*msg*`

#### Parameters

*msg*  
   需要更改扩展信息的消息此时msg部分已经更新扩展字椴信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

<a name="//api/name/updateMessageExtensionWithMsg:completion:" title="updateMessageExtensionWithMsg:completion:"></a>
### updateMessageExtensionWithMsg:completion:

更新一条数据库存储消息的扩展字段信息

`- (void)updateMessageExtensionWithMsg:(BMXMessage *)*msg* completion:(void ( ^ ) ( BMXError *aError ))*resBlock*`

#### Parameters

*msg*  
   需要更改扩展信息的消息此时msg部分已经更新扩展字椴信息  

#### Return Value
<a href="../Constants/BMXErrorCode.md">BMXErrorCode</a>

#### Declared In
* `floo_proxy.h`

