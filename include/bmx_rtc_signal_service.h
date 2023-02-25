//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_manager_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx chat service define file.
// Created : 16 Apr 2021 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_rtc_signal_service_h
#define bmx_rtc_signal_service_h

#include "bmx_error.h"
#include "bmx_rtc_session.h"
#include "bmx_rtc_room.h"
#include "bmx_rtc_defines.h"

namespace floo {

class BMXRTCSignalServiceListener;

/**
 * @brief RTC Signal Service
 **/
class EXPORT_API BMXRTCSignalService {
public:

  /**
   * @brief 创建房间参数信息
   */
  struct BMXRoomCreateOptions {
    BMXRoomCreateOptions(int roomId = 0, const std::string& description = "", const std::string& secret = "", const std::string& pin = "", bool isPermanent = false, bool isPrivate = true) : 
      mRoomId(roomId), mDescription(description), mSecret(secret), mPin(pin), mIsPermanent(isPermanent), mIsPrivate(isPrivate) {
    }
    int64_t mRoomId;                   // 房间ID
    std::string mDescription;          // 房间描述
    std::string mSecret;               // 修改或者删除房间需要的密钥
    std::string mPin;                  // 加密房间的pin码
    bool mIsPermanent;                 // 是否是永久存在的房间(默认false)
    bool mIsPrivate;                   // 是否是私有的不可在列表中展示的（默认true）
  };
  typedef std::shared_ptr<BMXRoomCreateOptions> BMXRoomCreateOptionsPtr;

  /**
 * @brief attach 或 detach操作的handler type类型
 */
  enum class HandlerType {
    publishType,              //attachSession类型为发布者。服务器返回发布者handler。
    subscribeType,            //attachSession类型为订阅者。服务器返回订阅者handler。
  };

  /**
   * @brief 编辑房间参数信息
   */
  struct BMXRoomEditOptions {
    BMXRoomEditOptions(const std::string& newDescription = "", const std::string& newSecret = "", const std::string& newPin = "", bool newIsPermanent = false, bool newIsPrivate = true) : 
      mNewDescription(newDescription), mNewSecret(newSecret), mNewPin(newPin), mNewIsPermanent(newIsPermanent), mNewIsPrivate(newIsPrivate) {
    }
    std::string mNewDescription;        // 新修改房间描述
    std::string mNewSecret;             // 新修改房间属性所需密钥
    std::string mNewPin;                // 新pin码
    bool mNewIsPermanent;               // 修改的是否是永久存在的房间属性(默认false)
    bool mNewIsPrivate;                 // 修改的是否是私有的不可在列表中展示的属性（默认true）
  };
  typedef std::shared_ptr<BMXRoomEditOptions> BMXRoomEditOptionsPtr;

  /**
   * @brief Allowed操作执行的操作类型
   */
  enum class AllowedAction {
    /// 允许操作
    EnableAction,
    /// 禁止操作
    DisableAction,
    /// 添加操作
    AddAction,
    /// 删除操作
    RemoveAction,
  };

  /**
   * @brief allow操作参数
   */ 
  struct BMXRoomAllowdOptions {
    BMXRoomAllowdOptions() {}
    AllowedAction action;                // 操作类型
    std::vector<std::string> tokens;     // token 列表
  };
  typedef std::shared_ptr<BMXRoomAllowdOptions> BMXRoomAllowdOptionsPtr;

  /**
   * @brief modeate操作类型，主要用于房间管理员禁言/解禁其他参与者操作。
   */
  struct BMXRoomModerateOptions {
    BMXRoomModerateOptions() {}
    BMXRoomModerateOptions(int64_t userId, bool muteAudio = false, bool muteVideo = false, bool muteData = false) : 
      mUserId(userId), mMuteAudio(muteAudio), mMuteVideo(muteVideo), mMuteData(muteData) {
    } 
    int64_t mUserId;        // 操作用户id
    bool mMuteAudio;        // 是否禁言音频
    bool mMuteVideo;        // 是否禁言视频
    bool mMuteData;         // 是否禁言数据
  };
  typedef std::shared_ptr<BMXRoomModerateOptions> BMXRoomModerateOptionsPtr;

  /**
   * @brief 发布模式加入房间的参数
   */
  struct BMXPubRoomJoinOptions {
    BMXPubRoomJoinOptions() {}
    BMXPubRoomJoinOptions(int64_t userId, int64_t roomId, const std::string& pin = "", const std::string& description = "", const std::string& token = "") : 
      mUserId(userId), mRoomId(roomId), mRoomPin(pin), mDescription(description), mToken(token) {
    }
    int64_t mUserId;              // 用户id
    int64_t mRoomId;               // 准备加入的roomId
    std::string mRoomPin;         // 准备加入的room的pin，可选
    std::string mDescription;     // 用户描述，可选
    std::string mToken;           // 用户token，可选
  };
  typedef std::shared_ptr<BMXPubRoomJoinOptions> BMXPubRoomJoinOptionsPtr;

  /**
   * @brief 房间配置参数
   */
  struct BMXRoomPubConfigureOptions {
    BMXRoomPubConfigureOptions(bool enableAudio = true, bool enableVideo = true,
                               int width = 0, int height = 0, int bitrate = 0,
                               bool enableData = true, const std::string& display = "") :
      mEnableAudio(enableAudio), mEnableVideo(enableVideo),
      mWidth(width), mHeight(height), mBitrate(bitrate),
      mEnableData(enableData), mDisplay(display) {
    }
    bool mEnableAudio;            // 是否启用音频
    bool mEnableVideo;            // 是否启用视频
    bool mEnableData;             // 是否启用数据
    std::string mDisplay;         // 用户描述
    int mWidth;                   // 视频宽度
    int mHeight;                  // 视频高度
    int mBitrate;                 // 视频帧率
  };
  typedef std::shared_ptr<BMXRoomPubConfigureOptions> BMXRoomPubConfigureOptionsPtr;

  /**
   * @brief 订阅模式加入房间参数信息
   */
  struct BMXRoomSubJoinOptions {
    BMXRoomSubJoinOptions() {}
    BMXRoomSubJoinOptions(BMXRTCStreams& janusStreams, int64_t privateId= 0, bool enableAudio = true, bool enableVideo = true, bool enableData = true, bool autoClosePc = true) :
      mPrivateId(privateId), mEnableAudio(enableAudio), mEnableVideo(enableVideo), mEnableData(enableData), mAutoClosePc(autoClosePc) {
      for (auto item : janusStreams) {
        streams.push_back(item);
      }
    }
    int64_t mUserId;              // 用户id
    int64_t mRoomId;               // 准备加入的roomId
    std::string mRoomPin;         // 准备加入的room的pin，可选
    std::string mDescription;     // 用户描述，可选
    std::string mToken;           // 用户token，可选
    int64_t mPrivateId;           // 发布者对于此次请求产生的唯一id。默认不需要。除非room配置为必须
    bool    mEnableAudio;         // 是否启用音频
    bool    mEnableVideo;         // 是否启用视频
    bool    mEnableData;          // 是否启用数据
    bool    mAutoClosePc;         // 发布者离开时是否自动关闭当前的peer connection
    BMXRTCStreams streams;
  };
  typedef std::shared_ptr<BMXRoomSubJoinOptions> BMXRoomSubJoinOptionsPtr;

  /**
   * @brief 订阅模式更新房间参数信息
   */
  struct BMXRoomSubConfigureOptions {
    BMXRoomSubConfigureOptions(bool enableAudio = true, bool enableVideo = true, bool enableData = true) : 
      mEnableAudio(enableAudio), mEnableVideo(enableVideo) , mEnableData(enableData) {
    }
    bool    mEnableAudio;     // 是否启用音频
    bool    mEnableVideo;     // 是否启用视频
    bool    mEnableData;      // 是否启用数据
  };
  typedef std::shared_ptr<BMXRoomSubConfigureOptions> BMXRoomSubConfigureOptionsPtr;

  /**
   * @brief 订阅模式切换媒体源
   */
  struct BMXRoomSubSwitchOptions {
    BMXRoomSubSwitchOptions() {}
    BMXRoomSubSwitchOptions(int64_t feedId, bool enableAudio = true, bool enableVideo = true, bool enableData = true) : 
      mFeedId(feedId), mEnableAudio(enableAudio), mEnableVideo(enableVideo), mEnableData(enableData) {
    }
    int64_t mFeedId;          // 发布者的ID
    bool    mEnableAudio;     // 是否启用音频
    bool    mEnableVideo;     // 是否启用视频
    bool    mEnableData;      // 是否启用数据
  };
  typedef std::shared_ptr<BMXRoomSubSwitchOptions> BMXRoomSubSwitchOptionsPtr;

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCSignalService() {}

  /**
   * @brief RTC session初始化函数，发起创建session请求
  **/
  virtual void createSession() = 0;

  /**
   * @brief RTC session初始化函数，用来获取服务器产生的session的hander 
   * @param session 操作的session
   * @param type handler的操作类型
  **/
  virtual void attachSession(BMXRTCSessionPtr session, HandlerType type) = 0;

  /**
  * @brief 创建RTC会议房间
  * @param session 操作的session
  * @param option 创建房间参数信息
  **/
  virtual void createRoom(BMXRTCSessionPtr session, BMXRoomCreateOptionsPtr options) = 0;

  /**
  * @brief 删除RTC会议房间
  * @param session 操作的session
  * @param room 操作的room
  * @param isPermanent 是否是永久存在的房间
  **/
  virtual void destroyRoom(BMXRTCSessionPtr session, BMXRTCRoomPtr room, bool isPermanent = false) = 0;

  /**
   * @brief 编辑会议房间信息
   * @param session 操作的session
   * @param room 操作的room
   * @param options 编辑房间参数信息
   */
  virtual void editRoom(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomEditOptionsPtr options) = 0;

  /**
   * @brief 会议房间是否存在
   * @param session 操作的session
   * @param roomId 操作的roomId
   */
  virtual void isExistsRoom(BMXRTCSessionPtr session, int64_t roomId) = 0;

  /**
   * @brief 出入管理。用于配置是否启用token验证，添加或移除允许进入房间的用户。
   * @param session 操作的session
   * @param room 操作的room
   * @param options 操作类型
   */
  virtual void allowed(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomAllowdOptionsPtr options) = 0;

  /**
   * @brief 踢出房间
   * @param session 操作的session
   * @param room 操作的room
   * @param userId 被踢用户id
   */
  virtual void kickParticipants(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int64_t userId) = 0;

  /**
   * @brief 管理员禁言/解禁其他房间成员操作。
   * @param session 操作的session
   * @param room 操作的room
   * @param options 禁言操作数据
   */
  virtual void moderate(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomModerateOptionsPtr options) = 0;

  /**
   * @brief 列出当前服务器可访问房间
   * 
   * @param session 操作的session
   */
  virtual void listRoom(BMXRTCSessionPtr session) = 0;

  /**
   * @brief 列出当前房间中活跃的用户
   * 
   * @param session 操作的session
   * @param room 操作的room
   */
  virtual void listRoomparticipants(BMXRTCSessionPtr session, BMXRTCRoomPtr room) = 0;

  /**
   * @brief RTC SDP信息交互指令
   * @param session 操作的session
   * @param type handler的操作类型
   * @param sdpMid sdp信息
   * @param sdpMLineIndex sdp相关信息
   * @param candidate candidate详细信息
   **/
  virtual void trickle(BMXRTCSessionPtr session, HandlerType type, const std::string& sdpMid, int32_t sdpMLineIndex, const std::string& candidate) = 0;

  /**
   * @brief RTC SDP信息交互信息结束
   * @param session 操作的session
   * @param type handler的操作类型
   **/
  virtual void trickleCompleted(BMXRTCSessionPtr session, HandlerType type) = 0;

    /**
   * @brief 加入房间请求
   * @param session 操作的session
   * @param options 操作的请求参数 
   */
  virtual void pubJoinRoom(BMXRTCSessionPtr session, BMXPubRoomJoinOptionsPtr options) = 0;

  /**
   * @brief 发布操作（优先推荐使用configure替代该功能）
   * @param session 操作的session
   * @param options 操作的请求参数
   * @param sdp     sdp信息（这里必须是offer类型）
   */
  virtual void pubPublish(BMXRTCSessionPtr session, BMXRoomPubConfigureOptionsPtr options, BMXRoomSDPInfoPtr sdp) = 0; 

  /**
   * @brief 取消发布
   * @param session 操作的session
   */
  virtual void pubUnPublish(BMXRTCSessionPtr session) = 0;

  /**
   * @brief 更新配置操作，该操作同时包含publish功能，但是可以同时更改配置信息，功能更强大。推荐使用pubConfigue
   * @param session 操作的session
   * @param options 操作的请求参数
   * @param sdp     sdp信息（这里必须是offer类型）
   */
  virtual void pubConfigue(BMXRTCSessionPtr session, BMXRoomPubConfigureOptionsPtr options, BMXRoomSDPInfoPtr sdp) = 0;

  /**
   * @brief 订阅模式加入房间（在房间中收到其他发布者加入时需要订阅的情况下调用）
   * @param session 操作的session
   * @param options 操作的请求参数
   */
  virtual void subJoinRoom(BMXRTCSessionPtr session, BMXRoomSubJoinOptionsPtr options) = 0;

  /**
   * @brief 开始订阅（在调用subPause暂停后再次恢复订阅的时候可以不传入sdp信息）subConfigure功能更强大推荐使用subConfigure替代。
   * @param session 操作的session
   * @param room 操作的room
   * @param sdp sdp信息（这里必须是answer类型的sdp信息）
   */
  virtual void subStart(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomSDPInfoPtr sdp) = 0;

  /**
   * @brief 暂停订阅
   * @param session 操作的session
   * @param room 操作的room
   */
  virtual void subPause(BMXRTCSessionPtr session, BMXRTCRoomPtr room) = 0;

  /**
   * @brief 停止订阅（在接收到发布者停止发布后调用）
   * @param session 操作的session
   * @param room 操作的room
   * @param streams 停止操作的streams
   */
  virtual void subUnsubscribe(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const BMXRTCStreams& streams) = 0;

  /**
   * @brief 更新配置操作，该操作同时包含subStart功能，但是可以同时更改配置信息，功能更强大。推荐使用subConfigure
   * @param session 操作的session
   * @param options 操作的请求参数
   * @param sdp sdp信息（这里必须是answer类型的sdp信息）
   */
  virtual void subConfigure(BMXRTCSessionPtr session, BMXRoomSubConfigureOptionsPtr options, BMXRoomSDPInfoPtr sdp) = 0;

  /**
   * @brief 切换订阅 （视频、视频和数据需要同时切换。两个目标发布者必须使用一样的配置，比如一样的编码器、一样的数据格式）
   * @param session 操作的session
   * @param options 操作的请求参数
   */
  virtual void subSwitch(BMXRTCSessionPtr session, BMXRoomSubSwitchOptionsPtr options) = 0;

  /**
   * @brief 离开房间操作
   * @param session 操作的session
   **/
  virtual void leaveRoom(BMXRTCSessionPtr session) = 0;

  /**
   * @brief 挂断session操作，挂断后会挂断与当前session关联的PeerConnection，但是可以保留当前的handle。
   * @param session 操作的session
   **/
  virtual void hangUpSession(BMXRTCSessionPtr session) = 0;

  /**
 * @brief 销毁当前session的plugin handler，与attach指令相反。
 * @param session 操作的session
 * @param type handler的操作类型
 **/
  virtual void detachSession(BMXRTCSessionPtr session, HandlerType type) = 0;

  /**
   * @brief 销毁当前session
   * @param session 操作的session
   **/
  virtual void destroySession(BMXRTCSessionPtr session) = 0;

  /**
   * @brief 添加BMXRTCSignalServiceListener监听
   * @param listener 监听listener
   */
  virtual void addBMXRTCSignalServiceListener(BMXRTCSignalServiceListener* listener) = 0;

  /**
   * @brief 移除BMXRTCSignalServiceListener监听
   * @param listener 监听listener
   */
  virtual void removeBMXRTCSignalServiceListener(BMXRTCSignalServiceListener* listener) = 0;

protected:
  BMXRTCSignalService() {}
};

}

#endif /* bmx_rtc_manager_service_h */
