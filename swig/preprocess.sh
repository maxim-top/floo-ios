sed -i.bak 's/virtual const MessageSetting& messageSetting() = 0;/virtual const BMXUserProfileMessageSetting\& messageSetting() = 0;/g' floo/include/bmx_user_profile.h
sed -i.bak 's/virtual const AuthQuestion& authQuestion() = 0;/virtual const BMXUserProfileAuthQuestion\& authQuestion() = 0;/g' floo/include/bmx_user_profile.h
sed -i.bak 's/void setHostConfig(const HostConfig& config);/void setHostConfig(const BMXSDKConfigHostConfig\& config);/g' floo/include/bmx_sdk_config.h
sed -i.bak 's/const HostConfig& getHostConfig();/const BMXSDKConfigHostConfig\& getHostConfig();/g' floo/include/bmx_sdk_config.h
sed -i.bak 's/typedef std::shared_ptr<Member> MemberPtr;/typedef std::shared_ptr<BMXGroupMember> MemberPtr;/g' floo/include/bmx_group.h
sed -i.bak 's/typedef std::shared_ptr<BannedMember> BannedMemberPtr;/typedef std::shared_ptr<BMXGroupBannedMember> BannedMemberPtr;/g' floo/include/bmx_group.h
sed -i.bak 's/typedef std::shared_ptr<SharedFile> SharedFilePtr;/typedef std::shared_ptr<BMXGroupSharedFile> SharedFilePtr;/g' floo/include/bmx_group.h
sed -i.bak 's/typedef std::shared_ptr<Application> ApplicationPtr;/typedef std::shared_ptr<BMXGroupApplication> ApplicationPtr;/g' floo/include/bmx_group.h
sed -i.bak 's/typedef std::shared_ptr<Application> ApplicationPtr;/typedef std::shared_ptr<BMXRosterServiceApplication> ApplicationPtr;/g' floo/include/bmx_roster_service.h
sed -i.bak 's/typedef std::shared_ptr<Announcement> AnnouncementPtr/typedef std::shared_ptr<BMXGroupAnnouncement> AnnouncementPtr/g' floo/include/bmx_group.h
sed -i.bak 's/typedef std::shared_ptr<Invitation> InvitationPtr/typedef std::shared_ptr<BMXGroupInvitation> InvitationPtr/g' floo/include/bmx_group.h
sed -i.bak 's/BMXUserProfile::AuthQuestion/BMXUserProfileAuthQuestion/g' floo/include/bmx_user_service.h
sed -i.bak 's/BMXUserProfilePtr profile, bool thumbnail = true, Callback callback = ...int.../BMXUserProfilePtr profile, bool thumbnail, Callback callback/g' floo/include/bmx_user_service.h
sed -i.bak 's/BMXRosterItemPtr item, bool thumbnail = true, Callback callback = ...int.../BMXRosterItemPtr item, bool thumbnail, Callback callback/g' floo/include/bmx_roster_service.h
sed -i.bak 's/BMXGroupPtr group,  bool thumbnail = true, Callback callback = ...int.../BMXGroupPtr group,  bool thumbnail, Callback callback/g' floo/include/bmx_group_service.h
sed -i.bak 's/EXPORT_API std::string getErrorMessage/std::string getErrorMessage/g' floo/include/bmx_error.h
#sed -i.bak 's///g' floo/include/bmx_group.h
