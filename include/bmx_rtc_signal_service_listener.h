//-------------------------------------------------------------------------------------------------
// File    : bmx_rtc_service_listener.h
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

#ifndef bmx_rtc_signal_service_listener_h
#define bmx_rtc_signal_service_listener_h

#include "bmx_error.h"
#include "bmx_rtc_defines.h"
#include "bmx_rtc_session.h"
#include "bmx_rtc_room.h"

namespace floo {

class BMXRTCSignalService;

/**
 * @RTC Manager监听者
 **/
class EXPORT_API BMXRTCSignalServiceListener {
public:
  /**
   * @brief 构造函数
   **/
  BMXRTCSignalServiceListener() : mService(nullptr) {} 

  /**
   * @brief 析构函数
   **/
  virtual ~BMXRTCSignalServiceListener() {
    if (mService != nullptr) {
      mService->removeBMXRTCSignalServiceListener(this);
    }
  }

  /**
   * @brief createSession函数的回调函数
   * @param session 操作的session，创建成功返回新建session，失败的情况下返回空对象
   * @param error 错误码详情，在创建失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串。
   **/
  virtual void onSessionCreate(BMXRTCSessionPtr session, int error, const std::string reason) {}

  /**
   * @brief attachSession函数的执行回调函数
   * @param session 操作的session对象
   * @param type 操作的handler类型
   * @param error 错误码详情，在失败的情况下返回详细的错误码 
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串.
   */
  virtual void onSessionAttach(BMXRTCSessionPtr session, BMXRTCSignalService::HandlerType type, int error, const std::string reason) {}

  /**
   * @brief message create信令执行回调函数。
   * @param session 操作的session对象
   * @param room 创建返回的room对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串.
   */
  virtual void onRoomCreate(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int error, const std::string& reason) {}

  /**
   * @brief message destroy信令执行回调函数。
   * @param session 操作的session对象
   * @param roomId 销毁的room的Id
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串.
   */
  virtual void onRoomDestroy(BMXRTCSessionPtr session, int64_t roomId, int error, const std::string& reason) {}

  /**
   * @brief message edit信令执行回调函数。
   * @param session 操作的session对象
   * @param room 创建返回的room对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomEdit(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int error, const std::string& reason) {}

  /**
   * @brief message exist信令执行回调函数。
   * @param session 操作的session对象
   * @param roomId 操作的room的Id
   * @param exist 是否存在
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomExist(BMXRTCSessionPtr session, int64_t roomId, bool exist, int error, const std::string& reason) {}

  /**
   * @brief message allowed信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param tokens 返回的token列表
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomAllowed(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const std::vector<std::string>& tokens, int error, const std::string& reason) {}

  /**
   * @brief message kick信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param userId 操作的用户id
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomKick(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int64_t userId, int error, const std::string& reason) {}

  /**
   * @brief message moderate信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param userId 操作的用户id
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomModerate(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int64_t userId, int error, const std::string& reason) {}

  /**
   * @brief message list信令执行回调函数。
   * @param session 操作的session对象
   * @param rooms 操作返回的的room对象vector
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomList(BMXRTCSessionPtr session, const BMXRTCRooms& rooms, int error, const std::string& reason) {}

  /**
   * @brief message listparticipants信令执行回调函数。
   * @param session 操作的session对象
   * @param rooms 操作的room对象
   * @param participants 返回的房间内成员列表
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onRoomListParticipants(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const BMXRTCRoomParticipants& participants, int error, const std::string& reason) {}

  /**
   * @brief messgae join as publisher信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param publishers 返回的发布者信息
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onPubJoinRoom(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const BMXRTCPublishers& publishers, int error, const std::string& reason) {}

  /**
   * @brief 其它发布者加入到房间内触发回调。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param publishers 返回的发布者信息
   */
  virtual void onOtherPubJoinRoom(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const BMXRTCPublishers& publishers) {}

  /**
   * @brief message publisheh or configure as publisher信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param sdp sdp信息对象
   * @param streams 返回的流对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onPubConfigure(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomSDPInfoPtr sdp, const BMXRTCStreams streams, int error, const std::string& reason) {}

  /**
   * @brief message publisher unpublish信令执行回调函数。
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param senderId unpublish操作的发起者，在不是当前用户的情况下为收到其他用户发起的通知。
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onPubUnPublish(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int senderId, int error, const std::string& reason) {}

  /**
   * @brief 当前session的发布流webrtc建立完毕(当ICE candidate操作成功，成功建立peerconnection链接时触发)
   * @param session 操作的用户id
   **/
  virtual void onPublishWebrtcUp(BMXRTCSessionPtr session) {}

  /**
   * @brief message subscriber join信令执行回调函数。 
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param sdp sdp信息对象
   * @param senderId 操作发起者id
   * @param streams 返回的流对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubJoinRoomUpdate(BMXRTCSessionPtr session, BMXRTCRoomPtr room, BMXRoomSDPInfoPtr sdp, int64_t senderId, const BMXRTCStreams streams, int error, const std::string& reason) {}

  /**
   * @brief message subscriber start信令执行回调函数
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubStart(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int error, const std::string& reason) {}

  /**
   * @brief message subscriber pause信令执行回调函数
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubPause(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int error, const std::string& reason) {}

  /**
   * @brief  message subscriber unsubscribe 信令执行回调函数
   * 
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param streams 操作的streams对象列表
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubUnsubscribe(BMXRTCSessionPtr session, BMXRTCRoomPtr room, const BMXRTCStreams streams, int error, const std::string& reason) {}

  /**
   * @brief message subscriber 
   * 
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubConfigure(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int error, const std::string& reason) {}

  /**
   * @brief message subscriber switch 信令执行回调函数
   * @param session 操作的session对象
   * @param room 操作的room对象
   * @param publisher 新switch到的发布者id
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onSubSwitch(BMXRTCSessionPtr session, BMXRTCRoomPtr room, int64_t publisher, int error, const std::string& reason) {}

  /**
   * @brief message leave 信令执行回调函数
   * @param session 操作的session对象
   * @param roomId 退出的房间id
   * @param senderId 退出房间的成员id。
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   */
  virtual void onLeaveRoom(BMXRTCSessionPtr session, int64_t roomId, int64_t senderId, int error, const std::string reason) {}

  /**
   * @brief 订阅流的webrtc建立完毕(当ICE candidate操作成功，成功建立peerconnection链接时触发)
   * @param session 操作的session
   * @param senderId 订阅的发布者id
   **/
  virtual void onSubscribeWebrtcUp(BMXRTCSessionPtr session, int64_t senderId) {}

  /**
   * @brief webrtc媒体信息通知
   * @param session 操作的session
   * @param senderId 订阅的发布者id
   * @param type 媒体通知的类型
   * @param receiving 是否正在接收
   **/
  virtual void onMediaInfo(BMXRTCSessionPtr session, int64_t senderId, BMXTrackType type, bool receiving, const std::string& mid) {}

  /**
   * @brief webrtc错误报告通知
   * @param session 操作的session
   * @param senderId 订阅的发布者id
   * @param uplink 是否正在上传
   * @param nacks 上一秒钟的nacks数值
   **/
  virtual void onSlowlink(BMXRTCSessionPtr session, int64_t senderId, bool uplink, int nacks) {}

  /**
   * @brief webrtc被挂断通知(不是整个session的挂断通知，是unpublish类似操作的webrtc挂断通知)
   * @param session 操作的session
   * @param senderId 发起挂断的用户id
   * @param reason 挂断的原因（正常挂断reason为“DTLS alert”）
   **/
  virtual void onHangup(BMXRTCSessionPtr session, int64_t senderId, const std::string& reason) {}

  /**
   * @brief webrtc挂断通知(SDK主动发起hangup请求之后接收到的hangup响应）
   * @param session 操作的session
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   **/
  virtual void onSessionHangup(BMXRTCSessionPtr session, int64_t error, const std::string& reason) {}

  /**
   * @brief webrtc session销毁插件的回调通知
   * @param session 操作的session
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   **/
  virtual void onSessionDetach(BMXRTCSessionPtr session, BMXRTCSignalService::HandlerType type, int error, const std::string reason) {}

  /**
   * @brief webrtc session销毁的回调通知
   * @param sessionId 操作的session
   * @param error 错误码详情，在失败的情况下返回详细的错误码
   * @param reason 服务器返回的错误失败的详细原因，失败下有效，正常为空字符串
   **/
  virtual void onSessionDestroy(int64_t sessionId, int error, const std::string reason) {}

public:
  void registerRTCSignalService(BMXRTCSignalService* service) {
    mService = service;
  }

protected:
  BMXRTCSignalService* mService;
};

}

#endif
