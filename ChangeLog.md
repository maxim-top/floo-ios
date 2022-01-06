# floo-ios更新日志

## v3.8.0 - 2022/01/04
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
	


