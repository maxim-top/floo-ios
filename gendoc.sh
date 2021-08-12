#!/bin/bash
appledoc \
--output ./Doc \
-i *.m \
-i /BMXApplication.h \
-i /BMXAuthQuestion.h \
-i /BMXError.h \
-i /BMXGroupAnnounment.h \
-i /BMXGroupApplication.h \
-i /BMXGroupBannedMember.h \
-i /BMXGroupInvitation.h \
-i /BMXGroupMember.h \
-i /BMXMessagePageObject.h \
-i /BMXMessagePushSetting.h \
-i /BMXGroupSharedFile.h \
-i /BMXHostConfig.h \
--project-name "floo-iOS" \
--project-company "美信拓扑" \
--no-create-docset \
--keep-undocumented-objects \
--keep-undocumented-members \
--no-warn-undocumented-object \
--no-warn-undocumented-member \
../Products/floo-ios/floo/floo-ios.framework/Headers
