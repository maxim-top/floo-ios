# BMXRTCSignalServiceProtocol Protocol Reference

  **Conforms to** NSObject  
  **Declared in** floo_proxy.h  

## Instance Methods

<a name="//api/name/onHangupWithSession:senderId:reason:" title="onHangupWithSession:senderId:reason:"></a>
### onHangupWithSession:senderId:reason:

`- (void)onHangupWithSession:(BMXRTCSession *)*session* senderId:(long long)*senderId* reason:(NSString *)*reason*`

<a name="//api/name/onLeaveRoomWithSession:roomId:senderId:error:reason:" title="onLeaveRoomWithSession:roomId:senderId:error:reason:"></a>
### onLeaveRoomWithSession:roomId:senderId:error:reason:

`- (void)onLeaveRoomWithSession:(BMXRTCSession *)*session* roomId:(long long)*roomId* senderId:(long long)*senderId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onMediaInfoWithSession:senderId:type:receiving:mid:" title="onMediaInfoWithSession:senderId:type:receiving:mid:"></a>
### onMediaInfoWithSession:senderId:type:receiving:mid:

`- (void)onMediaInfoWithSession:(BMXRTCSession *)*session* senderId:(long long)*senderId* type:(BMXTrackType)*type* receiving:(BOOL)*receiving* mid:(NSString *)*mid*`

<a name="//api/name/onOtherPubJoinRoomWithSession:room:publishers:" title="onOtherPubJoinRoomWithSession:room:publishers:"></a>
### onOtherPubJoinRoomWithSession:room:publishers:

`- (void)onOtherPubJoinRoomWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* publishers:(BMXRTCPublishers *)*publishers*`

<a name="//api/name/onPubConfigureWithSession:room:sdp:streams:error:reason:" title="onPubConfigureWithSession:room:sdp:streams:error:reason:"></a>
### onPubConfigureWithSession:room:sdp:streams:error:reason:

`- (void)onPubConfigureWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* sdp:(BMXRoomSDPInfo *)*sdp* streams:(BMXRTCStreams *)*streams* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onPubJoinRoomWithSession:room:publishers:error:reason:" title="onPubJoinRoomWithSession:room:publishers:error:reason:"></a>
### onPubJoinRoomWithSession:room:publishers:error:reason:

`- (void)onPubJoinRoomWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* publishers:(BMXRTCPublishers *)*publishers* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onPubUnPublishWithSession:room:senderId:error:reason:" title="onPubUnPublishWithSession:room:senderId:error:reason:"></a>
### onPubUnPublishWithSession:room:senderId:error:reason:

`- (void)onPubUnPublishWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* senderId:(int)*senderId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onPublishWebrtcUpWithSession:" title="onPublishWebrtcUpWithSession:"></a>
### onPublishWebrtcUpWithSession:

`- (void)onPublishWebrtcUpWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/onRoomAllowedWithSession:room:tokens:error:reason:" title="onRoomAllowedWithSession:room:tokens:error:reason:"></a>
### onRoomAllowedWithSession:room:tokens:error:reason:

`- (void)onRoomAllowedWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* tokens:(TagList *)*tokens* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomCreateWithSession:room:error:reason:" title="onRoomCreateWithSession:room:error:reason:"></a>
### onRoomCreateWithSession:room:error:reason:

`- (void)onRoomCreateWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomDestroyWithSession:roomId:error:reason:" title="onRoomDestroyWithSession:roomId:error:reason:"></a>
### onRoomDestroyWithSession:roomId:error:reason:

`- (void)onRoomDestroyWithSession:(BMXRTCSession *)*session* roomId:(long long)*roomId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomEditWithSession:room:error:reason:" title="onRoomEditWithSession:room:error:reason:"></a>
### onRoomEditWithSession:room:error:reason:

`- (void)onRoomEditWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomExistWithSession:roomId:exist:error:reason:" title="onRoomExistWithSession:roomId:exist:error:reason:"></a>
### onRoomExistWithSession:roomId:exist:error:reason:

`- (void)onRoomExistWithSession:(BMXRTCSession *)*session* roomId:(long long)*roomId* exist:(BOOL)*exist* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomKickWithSession:room:userId:error:reason:" title="onRoomKickWithSession:room:userId:error:reason:"></a>
### onRoomKickWithSession:room:userId:error:reason:

`- (void)onRoomKickWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* userId:(long long)*userId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomListParticipantsWithSession:room:participants:error:reason:" title="onRoomListParticipantsWithSession:room:participants:error:reason:"></a>
### onRoomListParticipantsWithSession:room:participants:error:reason:

`- (void)onRoomListParticipantsWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* participants:(BMXRTCRoomParticipants *)*participants* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomListWithSession:rooms:error:reason:" title="onRoomListWithSession:rooms:error:reason:"></a>
### onRoomListWithSession:rooms:error:reason:

`- (void)onRoomListWithSession:(BMXRTCSession *)*session* rooms:(BMXRTCRooms *)*rooms* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onRoomModerateWithSession:room:userId:error:reason:" title="onRoomModerateWithSession:room:userId:error:reason:"></a>
### onRoomModerateWithSession:room:userId:error:reason:

`- (void)onRoomModerateWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* userId:(long long)*userId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSessionAttachWithSession:type:error:reason:" title="onSessionAttachWithSession:type:error:reason:"></a>
### onSessionAttachWithSession:type:error:reason:

`- (void)onSessionAttachWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSessionCreateWithSession:error:reason:" title="onSessionCreateWithSession:error:reason:"></a>
### onSessionCreateWithSession:error:reason:

`- (void)onSessionCreateWithSession:(BMXRTCSession *)*session* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSessionDestroyWithSessionId:error:reason:" title="onSessionDestroyWithSessionId:error:reason:"></a>
### onSessionDestroyWithSessionId:error:reason:

`- (void)onSessionDestroyWithSessionId:(long long)*sessionId* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSessionDetachWithSession:type:error:reason:" title="onSessionDetachWithSession:type:error:reason:"></a>
### onSessionDetachWithSession:type:error:reason:

`- (void)onSessionDetachWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSessionHangupWithSession:error:reason:" title="onSessionHangupWithSession:error:reason:"></a>
### onSessionHangupWithSession:error:reason:

`- (void)onSessionHangupWithSession:(BMXRTCSession *)*session* error:(long long)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSlowlinkWithSession:senderId:uplink:nacks:" title="onSlowlinkWithSession:senderId:uplink:nacks:"></a>
### onSlowlinkWithSession:senderId:uplink:nacks:

`- (void)onSlowlinkWithSession:(BMXRTCSession *)*session* senderId:(long long)*senderId* uplink:(BOOL)*uplink* nacks:(int)*nacks*`

<a name="//api/name/onSubConfigureWithSession:room:error:reason:" title="onSubConfigureWithSession:room:error:reason:"></a>
### onSubConfigureWithSession:room:error:reason:

`- (void)onSubConfigureWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubJoinRoomUpdateWithSession:room:sdp:senderId:streams:error:reason:" title="onSubJoinRoomUpdateWithSession:room:sdp:senderId:streams:error:reason:"></a>
### onSubJoinRoomUpdateWithSession:room:sdp:senderId:streams:error:reason:

`- (void)onSubJoinRoomUpdateWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* sdp:(BMXRoomSDPInfo *)*sdp* senderId:(long long)*senderId* streams:(BMXRTCStreams *)*streams* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubPauseWithSession:room:error:reason:" title="onSubPauseWithSession:room:error:reason:"></a>
### onSubPauseWithSession:room:error:reason:

`- (void)onSubPauseWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubStartWithSession:room:error:reason:" title="onSubStartWithSession:room:error:reason:"></a>
### onSubStartWithSession:room:error:reason:

`- (void)onSubStartWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubSwitchWithSession:room:publisher:error:reason:" title="onSubSwitchWithSession:room:publisher:error:reason:"></a>
### onSubSwitchWithSession:room:publisher:error:reason:

`- (void)onSubSwitchWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* publisher:(long long)*publisher* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubUnsubscribeWithSession:room:streams:error:reason:" title="onSubUnsubscribeWithSession:room:streams:error:reason:"></a>
### onSubUnsubscribeWithSession:room:streams:error:reason:

`- (void)onSubUnsubscribeWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* streams:(BMXRTCStreams *)*streams* error:(int)*error* reason:(NSString *)*reason*`

<a name="//api/name/onSubscribeWebrtcUpWithSession:senderId:" title="onSubscribeWebrtcUpWithSession:senderId:"></a>
### onSubscribeWebrtcUpWithSession:senderId:

`- (void)onSubscribeWebrtcUpWithSession:(BMXRTCSession *)*session* senderId:(long long)*senderId*`

