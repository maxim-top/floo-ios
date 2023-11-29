# floo-ios版本更新记录
[蓝莺IM](https://www.lanyingim.com/)，是由美信拓扑团队研发的新一代即时通讯云服务，SDK设计简单集成方便，服务采用云原生技术和多云架构，私有云也可按月付费。

## v4.2.3 - 2023/11/23
1. 解决bug：最近消息未过滤RTC信令。

## v4.2.2 - 2023/11/22
1. 解决bug：通话中断标志错误。

## v4.2.1 - 2023/11/20
1. 新功能：通话中断标志。

## v4.2.0 - 2023/11/17
1. 新功能：通话记录消息。

## v4.1.1 - 2023/10/31
1. 新功能：流式消息Append和Replace功能。

## v4.0.4 - 2023/07/01
1. 解决bug：发送位置消息时失败。
2. 新功能：推送消息本地化。

## v4.0.3 - 2023/05/15
1. 解决bug：偶现的崩溃。
2. 解决bug：事件监听器未正确移除。
3. 新功能：启用后台远程通知服务，实现振铃功能。
4. 新接口：是否在通话中。
5. 新接口：当前通话对方ID。

## v4.0.2 - 2023/02/25
1. 解决bug：应用安装后第一次登录时，未读消息数展示错误。
2. 解决bug：视频消息存储出错。

## v4.0.1 - 2023/02/21
1. 解决bug：撤回消息失败。
2. 优化：切换账号耗时长。

## v4.0.0 - 2023/02/11
1. 优化：用swig-objc生成iOS包装代码。

## v3.16.1 - 2022/08/30
1. 解决bug：自定义头像地址解析失败。

## v3.15.1 - 2022/08/17
1. 解决bug：登录之前打开会话时闪退。

## v3.14.1 - 2022/08/15
1. 优化：更新DNS配置加载策略。
2. 优化：增加本地数据库忙超时配置，减少出错重试。
3. 解决bug：多客户端实例引起的数据库解密失败。
4. 解决bug：收到透传消息时闪退。
5. 解决bug：收到错误格式的消息体时闪退。

## v3.13.1 - 2022/07/19
1. 优化获取群信息中群成员数和群容量的策略。

## v3.11.1 - 2022/07/11
1. 优化：推送账号与IM账号共存时会话列表获取策略。
2. 新功能：HTTP客户端使用DNS服务指定的IP列表。
3. 新功能：删除账号。
4. 新功能：设置日志级别。

## v3.10.1 - 2022/06/07
1. 解决bug：BMXSDKConfig接口名称拼写错误。

## v3.9.1 - 2022/04/24
1. 优化：错误代码分组。
2. 优化：默认日志级别改为错误级。
3. 解决bug：本地加密耗时长。

## v3.8.1 - 2022/01/04
1. 新功能：发送消息时携带用户名，方便在未获取到对方用户信息时显示用户名。
2. 新功能：根据图片和视频的原始尺寸生成缩略图（原来是固定大小）。
3. 新功能：支持aws S3作为文件存储服务器。
4. 新功能：获取当前正在上传或者下载中的文件数。
5. 新接口：发送送达回执。方便应用开发者自行发送送达回执。
6. 优化：减小openssl库的尺寸。
7. 解决bug：有文件上传或者下载任务时登出一直阻塞。

## v3.7.0 - 2021/11/12
1. 新功能：获取消息客户端ID，方便开发者定位消息，更新消息状态

## v3.6.0 - 2021/11/12
1. 新功能：群组全员禁言/解除全员禁言
2. 解决bug：群描述获取失败

## v3.5.0 - 2021/08/05
1. 解决bug：上传文件时multipart/formdata里的文件名错误

## v3.4.0 - 2021/07/16

变更：

1. 各种服务监听器释放时自动从服务上移除，避免崩溃
2. 解决bug：本地数据库从未加密版本升级到加密版本时初次运行崩溃



## v3.0 - 2020/11/21

新增：

1. 推送服务功能，详情见官网

2. 新增用户退出接口，该接口不需要提供UserID。

   目前退出登录以下两种方式可供选择：

	```
	
	/**
	 * 退出登录, 需要提供userID
 	**/
 	
	- (void)signOutID:(NSInteger)userID
	ignoreUnbindDevice:(BOOL)ignoreUnbindDevice
   			 completion:(void(^)(BMXError *error))aCompletionBlock;

	/**
	 * 退出登录
 	**/

	- (void)signOutignoreUnbindDevice:(BOOL)ignoreUnbindDevice
   								completion:(void(^)(BMXError *error))aCompletionBlock;
   
	```
	 
    
## v2.2.3 - 2020/05/19

新增：

1. 新增BMXVoiceAttachment的通过二进制流初始化attachment方法
		
	```

	/// 初始化BMXFileAttachment
	/// @param aData 音频Data
	/// @param displayName 显示名称
	/// @param duration 时长
	/// @param conversationId 会话Id
	- (instancetype)initWithData:(NSData *)aData
                     displayName:(NSString *)displayName
                      fileLength:(NSInteger)fileLength
                        duration:(NSInteger)duration
                  conversationId:(NSString *)conversationId;

	```


变更：

1. 变更BMXVoiceAttachment的通过路径初始化attachment方法， 新增conversationId参数


    ```
    /**
    初始化BMXFileAttachment

    @param path 音频路径
    @param displayName 显示
    @param duration 时长
    @return BMXFileAttachment
    */
    - (instancetype)initWithPath:(NSString *)path
                 displayName:(NSString *)displayName
                    duration:(NSInteger)duration
              conversationId:(NSString *)conversationId;

    ```


## v2.2.2 - 2020/05/07

变更：

1. 新增BMXHostConfig的属性setter方法

	```

	@property (nonatomic,copy) NSString *imHost;    
	@property (nonatomic,assign) int mPort;
	@property (nonatomic,copy) NSString *restHost;

	- (instancetype)initWithRestHostConfig:(NSString *)restHost imPort:(int)imPort imHost:(NSString *)imHost;

	```


## v2.1.1 - 2020/03/27

变更：

1. 统一参数类型：接口参数为群组id的数组或者好友id的数组，将数组内NSString类型统一为NSNumber类型

2. 搜索消息接口命名变更为searchMessagesByKeyWords：   
    searchMessages -> searchMessagesByKeyWords

	```
	/**
	 * 搜索消息
	 **/
	- (void)searchMessagesByKeyWords:(NSString *)keywords
	               refTime:(NSTimeInterval)refTime
	                  size:(NSUInteger)size
	         directionType:(BMXMessageDirection)directionType
	            completion:(void (^)(NSArray *array, BMXError 		*error))aCompletionBlock;
	
	```



## v2.1.0 - 2020/03/17

新增:

1. 会话：新增更新会话中消息的扩展字段接口

	```
	/// 更新一条数据库存储消息的扩展字段信息
	/// @param message 需要更改扩展信息的消息此时msg部分已经更新扩展字椴信息
	/// @param aCompletionBlock 更新结果
	- (void)updateMessageExtension:(BMXMessageObject *)message
	                    completion:(void(^)(BMXError *error))aCompletionBlock;
	```

2. 命令消息：新增创建命令消息的接口
	
	```
	/// 创建发送命令消息(命令消息通过content字段或者extension字段存放命令信息)
	/// @param content 消息内容
	/// @param fromId 消息发送者
	/// @param toId 消息接收者
	/// @param mtype 消息类型
	/// @param conversationId 会话id
	- (instancetype)initWithBMXCommandMessageText:(NSString *)content
	                                       fromId:(long long )fromId
	                                         toId:(long long)toId
	                                         type:(BMXMessageType)mtype
	                               conversationId:(long long )conversationId;
	```

3.  新增收到命令消息通知接口

	```
	/**
	 * 收到命令消息
	 **/
	- (void)receivedCommandMessages:(NSArray<BMXMessageObject*> *)messages;
	```
	


