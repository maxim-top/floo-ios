%module(directors="1") floo
%{
#include "bmx_error.h"
#include "bmx_defines.h"
#include "bmx_device.h"
#include "bmx_base_object.h"
#include "structs4swig.h"
#include "bmx_message_attachment.h"
#include "bmx_message_config.h"
#include "bmx_message.h"
#include "bmx_conversation.h"
#include "bmx_sdk_config.h"
#include "bmx_network_listener.h"
#include "bmx_chat_service.h"
#include "bmx_chat_service_listener.h"
#include "bmx_push_service.h"
#include "bmx_push_service_listener.h"
#include "bmx_client.h"
#include "bmx_file_attachment.h"
#include "bmx_group.h"
#include "bmx_group_service.h"
#include "bmx_image_attachment.h"
#include "bmx_location_attachment.h"
#include "bmx_result_page.h"
#include "bmx_roster_item.h"
#include "bmx_roster_service.h"
#include "bmx_roster_service_listener.h"
#include "bmx_user_profile.h"
#include "user_profile_impl.h"
#include "bmx_user_service.h"
#include "bmx_user_service_listener.h"
#include "bmx_video_attachment.h"
#include "bmx_voice_attachment.h"
#include "bmx_group_service_listener.h"
#include "bmx_rtc_defines.h"
#include "bmx_rtc_config.h"
#include "bmx_rtc_engine.h"
#include "bmx_rtc_engine_listener.h"
#include "bmx_rtc_room.h"
#include "bmx_rtc_service.h"
#include "bmx_rtc_service_listener.h"
#include "bmx_rtc_session.h"
#include "bmx_rtc_signal_service.h"
#include "bmx_rtc_signal_service_listener.h"
#include <utility>
%}

%include "stdint.i"
%include "objc.swg"
%include "objcenums.swg"
%include "objcruntime.swg"


%typemap(out) int64_t * %{
  *(int64_t **)&$result = $1; /* cast C ptr into jlong */
%}

%include "std_vector.i"
%include "std_string.i"
%template(BMXMessageList) std::vector<std::shared_ptr<floo::BMXMessage>>;
%template(TagList) std::vector<std::string>;

typedef floo::BMXConversation::Type BMXConversationType;

%template(BMXConversationList) std::vector<std::shared_ptr<floo::BMXConversation>>;

%template(BMXDeviceList) std::vector<std::shared_ptr<floo::BMXDevice>>;

%template(BMXGroupList) std::vector<std::shared_ptr<floo::BMXGroup>>;
%template(BMXGroupMemberList) std::vector<std::shared_ptr<BMXGroupMember>>;
%template(BMXGroupBannedMemberList) std::vector<std::shared_ptr<BMXGroupBannedMember>>;
%template(BMXGroupSharedFileList) std::vector<std::shared_ptr<BMXGroupSharedFile>>;
%template(BMXGroupAnnouncementList) std::vector<std::shared_ptr<BMXGroupAnnouncement>>;
%template(BMXRosterServiceApplicationList) std::vector<std::shared_ptr<BMXRosterServiceApplication>>;
%template(BMXGroupApplicationList) std::vector<std::shared_ptr<BMXGroupApplication>>;
%template(BMXGroupInvitationList) std::vector<std::shared_ptr<BMXGroupInvitation>>;

%template(ListOfLongLong) std::vector<long long>;

%include "bmx_error.h"
%include "bmx_defines.h"
%include "bmx_device.h"
%include "bmx_base_object.h"
%include "structs4swig.h"
%include "bmx_message_attachment.h"
%include "bmx_message_config.h"
%include "bmx_message.h"
%include "bmx_conversation.h"
%include "bmx_sdk_config.h"
%include "bmx_network_listener.h"
%include "bmx_chat_service.h"
%include "bmx_chat_service_listener.h"
%include "bmx_push_service.h"
%include "bmx_push_service_listener.h"
%include "bmx_client.h"
%include "bmx_file_attachment.h"
%include "bmx_rtc_defines.h"
%include "bmx_rtc_config.h"
%include "bmx_rtc_engine.h"
%include "bmx_rtc_engine_listener.h"
%include "bmx_rtc_room.h"
%include "bmx_rtc_service.h"
%include "bmx_rtc_service_listener.h"
%include "bmx_rtc_session.h"
%include "bmx_rtc_signal_service.h"
%include "bmx_rtc_signal_service_listener.h"

%exception floo::BMXFileAttachment::dynamic_cast(floo::BMXMessageAttachment *attachment) {
  $action
    if (!result) {
      jclass excep = jenv->FindClass("java/lang/ClassCastException");
      if (excep) {
        jenv->ThrowNew(excep, "dynamic_cast exception");
      }
    }
}
%extend floo::BMXFileAttachment {
  static floo::BMXFileAttachment *dynamic_cast(floo::BMXMessageAttachment *attachment) {
    return dynamic_cast<floo::BMXFileAttachment *>(attachment);
  }
};

%include "bmx_group.h"
%include "bmx_group_service.h"
%include "bmx_image_attachment.h"
%exception floo::BMXImageAttachment::dynamic_cast(floo::BMXMessageAttachment *attachment) {
  $action
    if (!result) {
      jclass excep = jenv->FindClass("java/lang/ClassCastException");
      if (excep) {
        jenv->ThrowNew(excep, "dynamic_cast exception");
      }
    }
}
%extend floo::BMXImageAttachment {
  static floo::BMXImageAttachment *dynamic_cast(floo::BMXMessageAttachment *attachment) {
    return dynamic_cast<floo::BMXImageAttachment *>(attachment);
  }
};

%include "bmx_location_attachment.h"
%exception floo::BMXLocationAttachment::dynamic_cast(floo::BMXMessageAttachment *attachment) {
  $action
    if (!result) {
      jclass excep = jenv->FindClass("java/lang/ClassCastException");
      if (excep) {
        jenv->ThrowNew(excep, "dynamic_cast exception");
      }
    }
}
%extend floo::BMXLocationAttachment {
  static floo::BMXLocationAttachment *dynamic_cast(floo::BMXMessageAttachment *attachment) {
    return dynamic_cast<floo::BMXLocationAttachment *>(attachment);
  }
};

%include "bmx_roster_service.h"
%include "bmx_result_page.h"
%template(BMXMessagePage) floo::BMXResultPage<std::shared_ptr<floo::BMXMessage>>;
%template(BMXGroupMemberResultPage)  floo::BMXResultPage<BMXGroup::MemberPtr>;
%template(BMXGroupBannedMemberResultPage)  floo::BMXResultPage<BMXGroup::BannedMemberPtr>;
%template(BMXRosterApplicationResultPage) floo::BMXResultPage<std::shared_ptr<BMXRosterServiceApplication>>;
%template(BMXGroupApplicationPage) floo::BMXResultPage<std::shared_ptr<BMXGroupApplication>>;
%template(BMXGroupInvitationPage) floo::BMXResultPage<std::shared_ptr<BMXGroupInvitation>>;

%template(BMXMessageListList) std::vector<std::vector<std::shared_ptr<floo::BMXMessage>>>;
%include "bmx_roster_item.h"
%template(BMXRosterItemList) std::vector<std::shared_ptr<floo::BMXRosterItem>>;
%include "bmx_roster_service_listener.h"
%include "bmx_user_profile.h"
%include "bmx_user_service.h"
%include "bmx_user_service_listener.h"
%include "bmx_video_attachment.h"
%exception floo::BMXVideoAttachment::dynamic_cast(floo::BMXMessageAttachment *attachment) {
  $action
    if (!result) {
      jclass excep = jenv->FindClass("java/lang/ClassCastException");
      if (excep) {
        jenv->ThrowNew(excep, "dynamic_cast exception");
      }
    }
}
%extend floo::BMXVideoAttachment {
  static floo::BMXVideoAttachment *dynamic_cast(floo::BMXMessageAttachment *attachment) {
    return dynamic_cast<floo::BMXVideoAttachment *>(attachment);
  }
};


%include "bmx_voice_attachment.h"
%exception floo::BMXVoiceAttachment::dynamic_cast(floo::BMXMessageAttachment *attachment) {
  $action
    if (!result) {
      jclass excep = jenv->FindClass("java/lang/ClassCastException");
      if (excep) {
        jenv->ThrowNew(excep, "dynamic_cast exception");
      }
    }
}
%extend floo::BMXVoiceAttachment {
  static floo::BMXVoiceAttachment *dynamic_cast(floo::BMXMessageAttachment *attachment) {
    return dynamic_cast<floo::BMXVoiceAttachment *>(attachment);
  }
};


%include "bmx_group_service_listener.h"
%include "bmx_push_user_profile.h"

%template(BMXRTCStreams) std::vector<std::shared_ptr<floo::BMXJanusStreamInfo>>;
%template(BMXRTCRoomParticipants) std::vector<std::shared_ptr<floo::BMXRoomParticipant>>;
%template(BMXRTCPublishers) std::vector<std::shared_ptr<floo::BMXJanusPublisher>>;
%template(BMXRTCRooms) std::vector<std::shared_ptr<floo::BMXRTCRoom>>;
