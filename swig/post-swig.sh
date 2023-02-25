sed -i .bak 's/floo::BMXSDKConfig \*arg1 = (floo::BMXSDKConfig \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXSDKConfigPtr arg1 ;\n  floo::BMXSDKConfigPtr *argp1 = *(floo::BMXSDKConfigPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXConversation \*arg1 = (floo::BMXConversation \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXConversationPtr arg1 ;\n  floo::BMXConversationPtr *argp1 = *(floo::BMXConversationPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXClient \*arg1 = (floo::BMXClient \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXClientPtr arg1 ;\n  floo::BMXClientPtr *argp1 = *(floo::BMXClientPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXUserProfile \*arg1 = (floo::BMXUserProfile \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXUserProfilePtr arg1 ;\n  floo::BMXUserProfilePtr *argp1 = *(floo::BMXUserProfilePtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXMessage \*arg1 = (floo::BMXMessage \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXMessagePtr arg1 ;\n  floo::BMXMessagePtr *argp1 = *(floo::BMXMessagePtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRosterItem \*arg1 = (floo::BMXRosterItem \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRosterItemPtr arg1 ;\n  floo::BMXRosterItemPtr *argp1 = *(floo::BMXRosterItemPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXGroup \*arg1 = (floo::BMXGroup \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroupPtr arg1 ;\n  floo::BMXGroupPtr *argp1 = *(floo::BMXGroupPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXImageAttachment \*arg1 = (floo::BMXImageAttachment \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXImageAttachmentPtr arg1 ;\n  floo::BMXImageAttachmentPtr *argp1 = *(floo::BMXImageAttachmentPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXFileAttachment \*arg1 = (floo::BMXFileAttachment \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXFileAttachmentPtr arg1 ;\n  floo::BMXFileAttachmentPtr *argp1 = *(floo::BMXFileAttachmentPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXLocationAttachment \*arg1 = (floo::BMXLocationAttachment \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXLocationAttachmentPtr arg1 ;\n  floo::BMXLocationAttachmentPtr *argp1 = *(floo::BMXLocationAttachmentPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXVoiceAttachment \*arg1 = (floo::BMXVoiceAttachment \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXVoiceAttachmentPtr arg1 ;\n  floo::BMXVoiceAttachmentPtr *argp1 = *(floo::BMXVoiceAttachmentPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXVideoAttachment \*arg1 = (floo::BMXVideoAttachment \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXVideoAttachmentPtr arg1 ;\n  floo::BMXVideoAttachmentPtr *argp1 = *(floo::BMXVideoAttachmentPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXDevice \*arg1 = (floo::BMXDevice \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXDevicePtr arg1 ;\n  floo::BMXDevicePtr *argp1 = *(floo::BMXDevicePtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRosterService::Application \*arg1 = (floo::BMXRosterService::Application \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRosterService::ApplicationPtr arg1 ;\n  floo::BMXRosterService::ApplicationPtr *argp1 = *(floo::BMXRosterService::ApplicationPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXGroup::Application \*arg1 = (floo::BMXGroup::Application \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroup::ApplicationPtr arg1 ;\n  floo::BMXGroup::ApplicationPtr *argp1 = *(floo::BMXGroup::ApplicationPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXGroup::Invitation \*arg1 = (floo::BMXGroup::Invitation \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroup::InvitationPtr arg1 ;\n  floo::BMXGroup::InvitationPtr *argp1 = *(floo::BMXGroup::InvitationPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCSignalService::BMXPubRoomJoinOptions \*arg1 = (floo::BMXRTCSignalService::BMXPubRoomJoinOptions \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCSignalService::BMXPubRoomJoinOptionsPtr arg1 ;\n  floo::BMXRTCSignalService::BMXPubRoomJoinOptionsPtr *argp1 = *(floo::BMXRTCSignalService::BMXPubRoomJoinOptionsPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCSignalService::BMXRoomSubJoinOptions \*arg1 = (floo::BMXRTCSignalService::BMXRoomSubJoinOptions \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCSignalService::BMXRoomSubJoinOptionsPtr arg1 ;\n  floo::BMXRTCSignalService::BMXRoomSubJoinOptionsPtr *argp1 = *(floo::BMXRTCSignalService::BMXRoomSubJoinOptionsPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCSignalService::BMXRoomCreateOptions \*arg1 = (floo::BMXRTCSignalService::BMXRoomCreateOptions \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCSignalService::BMXRoomCreateOptionsPtr arg1 ;\n  floo::BMXRTCSignalService::BMXRoomCreateOptionsPtr *argp1 = *(floo::BMXRTCSignalService::BMXRoomCreateOptionsPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCSignalService::BMXRoomPubConfigureOptions \*arg1 = (floo::BMXRTCSignalService::BMXRoomPubConfigureOptions \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCSignalService::BMXRoomPubConfigureOptionsPtr arg1 ;\n  floo::BMXRTCSignalService::BMXRoomPubConfigureOptionsPtr *argp1 = *(floo::BMXRTCSignalService::BMXRoomPubConfigureOptionsPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCRoom \*arg1 = (floo::BMXRTCRoom \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCRoomPtr arg1 ;\n  floo::BMXRTCRoomPtr *argp1 = *(floo::BMXRTCRoomPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCSession \*arg1 = (floo::BMXRTCSession \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCSessionPtr arg1 ;\n  floo::BMXRTCSessionPtr *argp1 = *(floo::BMXRTCSessionPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRoomSDPInfo \*arg1 = (floo::BMXRoomSDPInfo \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRoomSDPInfoPtr arg1 ;\n  floo::BMXRoomSDPInfoPtr *argp1 = *(floo::BMXRoomSDPInfoPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXVideoCanvas \*arg1 = (floo::BMXVideoCanvas \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXVideoCanvasPtr arg1 ;\n  floo::BMXVideoCanvasPtr *argp1 = *(floo::BMXVideoCanvasPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXJanusPublisher \*arg1 = (floo::BMXJanusPublisher \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXJanusPublisherPtr arg1 ;\n  floo::BMXJanusPublisherPtr *argp1 = *(floo::BMXJanusPublisherPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXStream \*arg1 = (floo::BMXStream \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXStreamPtr arg1 ;\n  floo::BMXStreamPtr *argp1 = *(floo::BMXStreamPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXRTCEngine \*arg1 = (floo::BMXRTCEngine \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXRTCEnginePtr arg1 ;\n  floo::BMXRTCEnginePtr *argp1 = *(floo::BMXRTCEnginePtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXJanusStreamInfo \*arg1 = (floo::BMXJanusStreamInfo \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXJanusStreamInfoPtr arg1 ;\n  floo::BMXJanusStreamInfoPtr *argp1 = *(floo::BMXJanusStreamInfoPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm

sed -i .bak 's/floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > \*arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > \*) 0 ;/long long larg1 = (long long)imarg1;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > > arg1 ;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > > *argp1 = *(std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > > **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > \*arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > \*) 0 ;/long long larg1 = (long long)imarg1;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > > arg1 ;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > > *argp1 = *(std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > > **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > \*arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > \*) 0 ;/long long larg1 = (long long)imarg1;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > > arg1 ;\n  std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > > *argp1 = *(std::shared_ptr< floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > > **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm

sed -i .bak 's/BMXGroupMember \*arg1 = (BMXGroupMember \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroup::MemberPtr arg1 ;\n  floo::BMXGroup::MemberPtr *argp1 = *(floo::BMXGroup::MemberPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/BMXGroupBannedMember \*arg1 = (BMXGroupBannedMember \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroup::BannedMemberPtr arg1 ;\n  floo::BMXGroup::BannedMemberPtr *argp1 = *(floo::BMXGroup::BannedMemberPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm
sed -i .bak 's/BMXGroupServiceCreateGroupOptions \*arg1 = (BMXGroupServiceCreateGroupOptions \*) 0 ;/long long larg1 = (long long)imarg1;\n  floo::BMXGroupService::CreateGroupOptionsPtr arg1 ;\n  floo::BMXGroupService::CreateGroupOptionsPtr *argp1 = *(floo::BMXGroupService::CreateGroupOptionsPtr **)\&larg1;\n  if (argp1) arg1 = *argp1;/g' floo_wrap.mm

sed -i .bak '/arg1 = (floo::BMXSDKConfig \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXConversation \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXClient \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXUserProfile \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXMessage \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRosterItem \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXGroup \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXImageAttachment \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXFileAttachment \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXLocationAttachment \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXVoiceAttachment \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXVideoAttachment \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXDevice \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRosterService::Application \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXGroup::Application \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXGroup::Invitation \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCSignalService::BMXPubRoomJoinOptions \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCSignalService::BMXRoomSubJoinOptions \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCSignalService::BMXRoomCreateOptions \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCSignalService::BMXRoomPubConfigureOptions \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCRoom \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCSession \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRoomSDPInfo \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXVideoCanvas \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXJanusPublisher \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXStream \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXRTCEngine \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXJanusStreamInfo \*)imarg1;/d' floo_wrap.mm

sed -i .bak '/arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > \*)imarg1;/d' floo_wrap.mm

sed -i .bak '/arg1 = (BMXGroupMember \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (BMXGroupBannedMember \*)imarg1;/d' floo_wrap.mm
sed -i .bak '/arg1 = (BMXGroupServiceCreateGroupOptions \*)imarg1;/d' floo_wrap.mm

sed -i .bak 's/(floo::BMXImageAttachment const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXFileAttachment const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXLocationAttachment const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXVoiceAttachment const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXVideoAttachment const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXResultPage< std::shared_ptr< floo::BMXRosterService::Application > > const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Application > > const \*)//g' floo_wrap.mm
sed -i .bak 's/(floo::BMXResultPage< std::shared_ptr< floo::BMXGroup::Invitation > > const \*)//g' floo_wrap.mm

sed -i .bak 's/temp = new floo::BMXClientPtr((const floo::BMXClientPtr \&)result);/long long lresult;\n  \*(floo::BMXClientPtr \*\*)\&lresult = result \? new floo::BMXClientPtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXMessageAttachmentPtr((const floo::BMXMessageAttachmentPtr \&)result);/long long lresult;\n  \*(floo::BMXMessageAttachmentPtr \*\*)\&lresult = result \? new floo::BMXMessageAttachmentPtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXMessageConfigPtr((const floo::BMXMessageConfigPtr \&)result);/long long lresult;\n  \*(floo::BMXMessageConfigPtr \*\*)\&lresult = result \? new floo::BMXMessageConfigPtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXMessagePtr((const floo::BMXMessagePtr \&)result);/long long lresult;\n  \*(floo::BMXMessagePtr \*\*)\&lresult = result \? new floo::BMXMessagePtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXConversationPtr((const floo::BMXConversationPtr \&)result);/long long lresult;\n  \*(floo::BMXConversationPtr \*\*)\&lresult = result \? new floo::BMXConversationPtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXSDKConfigPtr((const floo::BMXSDKConfigPtr \&)result);/long long lresult;\n  \*(floo::BMXSDKConfigPtr \*\*)\&lresult = result \? new floo::BMXSDKConfigPtr(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm
sed -i .bak 's/temp = new floo::BMXConversationList((const floo::BMXConversationList \&)result);/long long lresult;\n  \*(floo::BMXConversationList \*\*)\&lresult = result \? new floo::BMXConversationList(result) : 0;\n  imresult = (void\*)lresult;/g' floo_wrap.mm

sed -i .bak '/imresult = \*(typeof(imresult)\*)\&temp;/d' floo_wrap.mm

sed -i .bak 's/SwigValueWrapper< std::shared_ptr< floo::BMXMessage > > result/std::shared_ptr< floo::BMXMessage > result/g' floo_wrap.mm
sed -i .bak 's/SwigValueWrapper< std::shared_ptr< floo::BMXConversation > > result/std::shared_ptr< floo::BMXConversation > result/g' floo_wrap.mm
sed -i .bak 's/SwigValueWrapper< std::shared_ptr< floo::BMXSDKConfig > > result/std::shared_ptr< floo::BMXSDKConfig > result/g' floo_wrap.mm
sed -i .bak 's/SwigValueWrapper< std::shared_ptr< floo::BMXMessageAttachment > > result/std::shared_ptr< floo::BMXMessageAttachment > result/g' floo_wrap.mm
sed -i .bak 's/SwigValueWrapper< std::shared_ptr< floo::BMXMessageConfig > > result/std::shared_ptr< floo::BMXMessageConfig > result/g' floo_wrap.mm

sed -i .bak 's/std::shared_ptr< BMXGroupSharedFile >/std::shared_ptr< floo::BMXGroup::SharedFile >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXGroupAnnouncement >/std::shared_ptr< floo::BMXGroup::Announcement >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXGroupApplication >/std::shared_ptr< floo::BMXGroup::Application >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXGroupInvitation >/std::shared_ptr< floo::BMXGroup::Invitation >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXRosterServiceApplication >/std::shared_ptr< floo::BMXRosterService::Application >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXGroupMember >/std::shared_ptr< floo::BMXGroup::Member >/g' floo_wrap.mm
sed -i .bak 's/std::shared_ptr< BMXGroupBannedMember >/std::shared_ptr< floo::BMXGroup::BannedMember >/g' floo_wrap.mm

sed -i .bak 's/BMXGroupMember \*/floo::BMXGroup::Member \*/g' floo_wrap.mm
sed -i .bak 's/new BMXGroupMember/new floo::BMXGroup::Member/g' floo_wrap.mm

sed -i .bak 's/BMXGroupSharedFile \*/floo::BMXGroup::SharedFile \*/g' floo_wrap.mm
sed -i .bak 's/new BMXGroupSharedFile/new floo::BMXGroup::SharedFile/g' floo_wrap.mm

sed -i .bak 's/BMXGroupAnnouncement \*/floo::BMXGroup::Announcement \*/g' floo_wrap.mm
sed -i .bak 's/new BMXGroupAnnouncement/new floo::BMXGroup::Announcement/g' floo_wrap.mm

sed -i .bak 's/BMXGroupApplication \*/floo::BMXGroup::Application \*/g' floo_wrap.mm
sed -i .bak 's/new BMXGroupApplication/new floo::BMXGroup::Application/g' floo_wrap.mm

sed -i .bak 's/BMXGroupInvitation \*/floo::BMXGroup::Invitation \*/g' floo_wrap.mm
sed -i .bak 's/new BMXGroupInvitation/new floo::BMXGroup::Invitation/g' floo_wrap.mm

sed -i .bak 's/BMXRosterServiceApplication \*/floo::BMXRosterService::Application \*/g' floo_wrap.mm
sed -i .bak 's/new BMXRosterServiceApplication/new floo::BMXRosterService::Application/g' floo_wrap.mm

sed -i .bak 's/\([^:_]\)\(BMXRoom[a-zA-Z]*Options\)/\1floo::BMXRTCSignalService::\2/g' floo_wrap.mm
sed -i .bak 's/\([^:_]\)\(BMXPubRoom[a-zA-Z]*Options\)/\1floo::BMXRTCSignalService::\2/g' floo_wrap.mm
sed -i .bak 's/AllowedAction/floo::BMXRTCSignalService::AllowedAction/g' floo_wrap.mm



sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_BMXGroupMember_t/BMXGroupMember/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_BMXGroupMember_t/BMXGroupMember/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_BMXGroupBannedMember_t/BMXGroupBannedMember/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_BMXGroupBannedMember_t/BMXGroupBannedMember/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_floo__\(.*\)_t/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_floo__\(.*\)_t/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_\(.*\)_t/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_std__shared_ptrT_\(.*\)_t/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_p_\(.*\)Ptr/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_\(.*\)Ptr/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_std__shared_ptrT_floo__\(.*\)_t/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_std__shared_ptrT_floo__\(.*\)_t/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_std__shared_ptrT_\(.*\)_t/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_std__shared_ptrT_\(.*\)_t/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_p_floo__BMXPushUserProfile__MessagePushSetting/BMXPushUserProfileMessagePushSetting/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_p_floo__BMXPushUserProfile__MessagePushSetting/BMXPushUserProfileMessagePushSetting/g' floo_proxy.mm


sed -i .bak 's/SWIGTYPE_[a-zA-Z_]*\(BMX[a-zA-Z]*\)_t/\1/g' floo_proxy.mm
sed -i .bak 's/SWIGTYPE_[a-zA-Z_]*\(BMX[a-zA-Z]*\)/\1/g' floo_proxy.mm

sed -i .bak 's/SWIGTYPE_[a-zA-Z_]*\(BMX[a-zA-Z]*\)_t/\1/g' floo_proxy.h
sed -i .bak 's/SWIGTYPE_[a-zA-Z_]*\(BMX[a-zA-Z]*\)/\1/g' floo_proxy.h