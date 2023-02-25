#include "bmx_group.h"
#include "bmx_roster_service.h"
struct BMXSDKConfigHostConfig {
    BMXSDKConfigHostConfig() {}
    BMXSDKConfigHostConfig(const std::string& im, int port, const std::string& rest) : imHost(im), imPort(port), restHost(rest) {}
    std::string imHost;
    int imPort;
    std::string restHost;
  };

  struct BMXGroupMember {
    BMXGroupMember(int64_t uid, const std::string& nickname, int64_t createTime) :
      mUid(uid), mGroupNickname(nickname), mCreateTime(createTime) {}
    virtual ~BMXGroupMember() {}

    int64_t mUid;
    std::string mGroupNickname;
    int64_t mCreateTime;
  };

  struct BMXGroupBannedMember {
    BMXGroupBannedMember() {}
    virtual ~BMXGroupBannedMember() {}

    int64_t mUid;
    std::string mGroupNickname;
    int64_t mCreateTime;
    int64_t mExpired;
  };

  struct BMXGroupSharedFile {
    BMXGroupSharedFile() {}
    virtual ~BMXGroupSharedFile() {}

    int64_t mFileId;
    int64_t mGroupId;
    int64_t mUploader;
    int mSize;
    int64_t mCreateTime;
    int64_t mUpdateTime;
    std::string mRatelUrl;  //群共享文件Ratel服务器Url
    std::string mUrl;       //群共享文件服务器Url
    std::string mPath;
    std::string mDisplayName;
    std::string mType;
  };

  struct BMXGroupAnnouncement {
    BMXGroupAnnouncement() {}
    virtual ~BMXGroupAnnouncement() {}

    std::string mTitle;
    std::string mContent;
    int64_t mAuthor;
    int64_t mCreateTime;
    int64_t mId;
  };

  struct BMXGroupInvitation {
    BMXGroupInvitation() {}
    ~BMXGroupInvitation() {}

    int64_t mGroupId;
    int64_t mInviterId;
    std::string mReason;
    floo::BMXGroup::InvitationStatus mStatus;
    int64_t mExpired;
  };

  struct BMXGroupApplication {
    BMXGroupApplication() {}
    ~BMXGroupApplication() {}

    int64_t mGroupId;
    int64_t mApplicationId;
    std::string mReason;
    floo::BMXGroup::ApplicationStatus mStatus;
    int64_t mExpired;
  };

  struct BMXGroupServiceCreateGroupOptions {
    BMXGroupServiceCreateGroupOptions() {}
    BMXGroupServiceCreateGroupOptions(const std::string& name, const std::string& description, bool isPublic = false, bool isChatroom = false) :
      mName(name), mDescription(description), mIsPublic(isPublic), mIsChatroom(isChatroom) {
    }

    std::string mName;                          // 群组名称
    std::string mDescription;                   // 群组描述
    bool mIsPublic;                             // 是否公开群
    bool mIsChatroom;                           // 是否创建聊天室
    std::string mMessage;                       // 建群时成员收到的邀请信息
    std::vector<int64_t> mMembers;              // 建群时添加的成员
  };

  struct BMXMessageAttachmentSize
  {
    BMXMessageAttachmentSize(double width = 0.0, double height = 0.0) : mWidth(width), mHeight(height) {}
    double mWidth;
    double mHeight;
  };


  struct BMXPushUserProfileMessagePushSetting {
    BMXPushUserProfileMessagePushSetting() {
      mPushEnabled = true;
      mSilenceStartTime = 0;
      mSilenceEndTime = 0;
      mPushStartTime = 0;
      mPushEndTime = 23;
    }

    // 推送设定
    /// 当APP未打开时是否允许推送
    bool mPushEnabled;

    /// 推送静默起始时间
    int mSilenceStartTime;

    /// 推送静默结束时间
    int mSilenceEndTime;

    /// 允许推送起始时间
    int mPushStartTime;

    /// 允许推送结束时间
    int mPushEndTime;
  };

  struct BMXRosterServiceApplication {
    BMXRosterServiceApplication() {}
    virtual ~BMXRosterServiceApplication() {}

    int64_t mRosterId;
    std::string mReason;
    floo::BMXRosterService::ApplicationStatus mStatus;
    int64_t mExpire;
  };

  struct BMXUserProfileAuthQuestion {
    BMXUserProfileAuthQuestion() {}

    /// 好友验证问题
    std::string mQuestion;

    /// 好友验证问题答案
    std::string mAnswer;
  };

  /**
   * @brief 用户消息设置
   **/
  struct BMXUserProfileMessageSetting {
    BMXUserProfileMessageSetting() {
      mPushEnabled = true;
      mPushDetail = true;
      mNotificationSound = true;
      mNotificationVibrate = true;
      mAutoDownloadAttachment = true;
      mSilenceStartTime = 0;
      mSilenceEndTime = 0;
      mPushStartTime = 0;
      mPushEndTime = 23;
    }

    // 推送设定
    /// 当APP未打开时是否允许推送
    bool mPushEnabled;

    /// 是否推送消息详情
    bool mPushDetail;

    /// 对方收到推送消息时显示的名称
    std::string mPushNickname;

    // 在线消息设定
    /// 收到消息时是否通过声音提醒
    bool mNotificationSound;

    /// 收到消息时是否通过震动提醒
    bool mNotificationVibrate;

    /// 收到消息时是否自动下载缩略图或者语音
    bool mAutoDownloadAttachment;

    /// 推送静默起始时间
    int mSilenceStartTime;

    /// 推送静默结束时间
    int mSilenceEndTime;

    /// 允许推送起始时间
    int mPushStartTime;

    /// 允许推送结束时间
    int mPushEndTime;
  };


