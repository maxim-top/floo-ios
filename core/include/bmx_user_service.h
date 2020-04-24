//-------------------------------------------------------------------------------------------------
// File    : bmx_user_service.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx user service define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_user_service_h
#define bmx_user_service_h

#include <functional>
#include "bmx_user_profile.h"
#include "bmx_device.h"

namespace floo {

class BMXUserServiceListener;

class EXPORT_API BMXUserService {
public:
  virtual ~BMXUserService() {}

  typedef std::function<void(int percent)> Callback;

  /**
   * 注册新用户，mobile、verifyCode和password是必填参数
   **/
  virtual BMXErrorCode signUpNewUser(const std::string& mobile, const std::string& verifyCode, const std::string& password, const std::string& username, BMXUserProfilePtr& bmxUserProfilePtr) = 0;
  /**
   * 通过用户名登录
   **/
  virtual BMXErrorCode signInByName(const std::string& name, const std::string& password) = 0;

  /**
   * 通过手机号登录
   **/
  virtual BMXErrorCode signInByPhone(const std::string& phone, const std::string& password) = 0;

  /**
   * 通过用户ID登录
   **/
  virtual BMXErrorCode signInById(int64_t, const std::string& password) = 0;

  /**
   * 通过id和token登陆
   **/
	virtual BMXErrorCode signInByToken(int64_t uid, const std::string& token) = 0;

  /**
   * 通过用户名快速登录（要求之前成功登录过，登录速度较快）
   **/
  virtual BMXErrorCode fastSignInByName(const std::string& name, const std::string& password) = 0;
  
  /**
   * 通过电话号码快速登录（要求之前成功登录过，登录速度较快）
   **/
  virtual BMXErrorCode fastSignInByPhone(const std::string& phone, const std::string& password) = 0;

  /**
   * 通过用户ID快速登录（要求之前成功登录过，登录速度较快）
   **/
  virtual BMXErrorCode fastSignInById(int64_t uid, const std::string& password) = 0;

  /**
   * 退出登录
   **/
  virtual BMXErrorCode signOut() = 0;

  /**
   * 强制重新连接
   **/
  virtual void reconnect() = 0;

  /**
   * 获取当前和服务器的连接状态
   **/
  virtual BMXConnectStatus connectStatus() = 0;

  /**
   * 获取当前的登录状态
   **/
  virtual BMXSignInStatus signInStatus() = 0;

  /**
   * 绑定设备推送token
   **/
  virtual BMXErrorCode bindDevice(const std::string& token) = 0;
  /**
  * 获取设备列表
  * @param deviceList
  * @return
  */
  virtual BMXErrorCode getDeviceList(BMXDeviceList& deviceList) = 0;

  /**
   * 删除设备
   * @param device_sn
   * @return
   */
  virtual BMXErrorCode deleteDevice(int32_t device_sn) = 0;

  /**
   * 获取用户详情，如果forceRefresh == true，则强制从服务端拉取
   **/
  virtual BMXErrorCode getProfile(BMXUserProfilePtr& profile, bool forceRefresh) = 0;
  /**
   * 设置昵称
   **/
  virtual BMXErrorCode setNickname(const std::string& nickname) = 0;

  /**
   * 上传头像
   **/
  virtual BMXErrorCode uploadAvatar(const std::string& avatarPath, Callback callback) = 0;

  /**
   * 下载头像，默认下载缩略图
   **/
    virtual BMXErrorCode downloadAvatar(BMXUserProfilePtr profile, bool thumbnail = true, Callback callback = [](int){}) = 0;

  /**
   * 设置电话号码
   **/
  virtual BMXErrorCode setMobilePhone(const std::string& phone) = 0;

  /**
   * 设置公开扩展信息
   **/
  virtual BMXErrorCode setPublicInfo(const std::string& publicInfo) = 0;

  /**
   * 设置私有扩展信息
   **/
  virtual BMXErrorCode setPrivateInfo(const std::string& privateInfo) = 0;

  /**
   * 设置加好友验证方式
   **/
  virtual BMXErrorCode setAddFriendAuthMode(BMXUserProfile::AddFriendAuthMode mode) = 0;
  /**
   * 设置加好友验证问题
   **/
  virtual BMXErrorCode setAuthQuestion(const BMXUserProfile::AuthQuestion& authQuestion) = 0;

  /**
   * 设置是否允许推送
   **/
  virtual BMXErrorCode setEnablePush(bool enable) = 0;

  /**
   * 设置是否推送详情
   **/
  virtual BMXErrorCode setEnablePushDetaile(bool enable) = 0;

  /**
   * 设置推送昵称
   **/
  virtual BMXErrorCode setPushNickname(const std::string& nickname) = 0;

  /**
   * 设置收到新消息是否声音提醒
   **/
  virtual BMXErrorCode setNotificationSound(bool enable) = 0;

  /**
   * 设置收到新消息是否震动
   **/
  virtual BMXErrorCode setNotificationVibrate(bool enable) = 0;

  /**
   * 设置是否自动缩略图和语音附件
   **/
  virtual BMXErrorCode setAutoDownloadAttachment(bool enable) = 0;

  /**
   * 设置是否自动同意入群邀请
   **/
  virtual BMXErrorCode setAutoAcceptGroupInvite(bool enable) = 0;

  /**
   * 添加用户状态监听者
   **/
  virtual void addUserListener(BMXUserServiceListener* listener) = 0;

  /**
   * 移除用户状态监听者
   **/
  virtual void removeUserListener(BMXUserServiceListener* listener) = 0;

protected:
  BMXUserService() {}
};

}

#endif /* bmx_user_service_h */
