# BMXRTCSignalService Class Reference

  **Inherits from** NSObject  
  **Declared in** floo_proxy.h  

## Overview

@interface RTC Signal Service

## Properties

<a name="//api/name/swigCMemOwn" title="swigCMemOwn"></a>
### swigCMemOwn

`@property (nonatomic) BOOL swigCMemOwn`

<a name="//api/name/swigCPtr" title="swigCPtr"></a>
### swigCPtr

`@property (nonatomic) void *swigCPtr`

<a title="Instance Methods" name="instance_methods"></a>
## Instance Methods

<a name="//api/name/addDelegate:" title="addDelegate:"></a>
### addDelegate:

`- (void)addDelegate:(id<BMXRTCSignalServiceProtocol>)*aDelegate*`

<a name="//api/name/addDelegate:delegateQueue:" title="addDelegate:delegateQueue:"></a>
### addDelegate:delegateQueue:

`- (void)addDelegate:(id<BMXRTCSignalServiceProtocol>)*aDelegate* delegateQueue:(dispatch_queue_t)*aQueue*`

<a name="//api/name/addRTCSignalListener:" title="addRTCSignalListener:"></a>
### addRTCSignalListener:

`- (void)addRTCSignalListener:(id<BMXRTCSignalServiceProtocol>)*listener*`

<a name="//api/name/allowedWithSession:room:options:" title="allowedWithSession:room:options:"></a>
### allowedWithSession:room:options:

`- (void)allowedWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* options:(BMXRoomAllowdOptions *)*options*`

<a name="//api/name/attachSessionWithSession:type:" title="attachSessionWithSession:type:"></a>
### attachSessionWithSession:type:

`- (void)attachSessionWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type*`

<a name="//api/name/createRoomWithSession:options:" title="createRoomWithSession:options:"></a>
### createRoomWithSession:options:

`- (void)createRoomWithSession:(BMXRTCSession *)*session* options:(BMXRoomCreateOptions *)*options*`

<a name="//api/name/createSession" title="createSession"></a>
### createSession

`- (void)createSession`

<a name="//api/name/dealloc" title="dealloc"></a>
### dealloc

`- (void)dealloc`

<a name="//api/name/destroyRoomWithSession:room:" title="destroyRoomWithSession:room:"></a>
### destroyRoomWithSession:room:

`- (void)destroyRoomWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room*`

<a name="//api/name/destroyRoomWithSession:room:isPermanent:" title="destroyRoomWithSession:room:isPermanent:"></a>
### destroyRoomWithSession:room:isPermanent:

`- (void)destroyRoomWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* isPermanent:(BOOL)*isPermanent*`

<a name="//api/name/destroySessionWithSession:" title="destroySessionWithSession:"></a>
### destroySessionWithSession:

`- (void)destroySessionWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/detachSessionWithSession:type:" title="detachSessionWithSession:type:"></a>
### detachSessionWithSession:type:

`- (void)detachSessionWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type*`

<a name="//api/name/editRoomWithSession:room:options:" title="editRoomWithSession:room:options:"></a>
### editRoomWithSession:room:options:

`- (void)editRoomWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* options:(BMXRoomEditOptions *)*options*`

<a name="//api/name/hangUpSessionWithSession:" title="hangUpSessionWithSession:"></a>
### hangUpSessionWithSession:

`- (void)hangUpSessionWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/initWithCptr:swigOwnCObject:" title="initWithCptr:swigOwnCObject:"></a>
### initWithCptr:swigOwnCObject:

`- (id)initWithCptr:(void *)*cptr* swigOwnCObject:(BOOL)*ownCObject*`

<a name="//api/name/isExistsRoomWithSession:roomId:" title="isExistsRoomWithSession:roomId:"></a>
### isExistsRoomWithSession:roomId:

`- (void)isExistsRoomWithSession:(BMXRTCSession *)*session* roomId:(long long)*roomId*`

<a name="//api/name/kickParticipantsWithSession:room:userId:" title="kickParticipantsWithSession:room:userId:"></a>
### kickParticipantsWithSession:room:userId:

`- (void)kickParticipantsWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* userId:(long long)*userId*`

<a name="//api/name/leaveRoomWithSession:" title="leaveRoomWithSession:"></a>
### leaveRoomWithSession:

`- (void)leaveRoomWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/listRoomWithSession:" title="listRoomWithSession:"></a>
### listRoomWithSession:

`- (void)listRoomWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/listRoomparticipantsWithSession:room:" title="listRoomparticipantsWithSession:room:"></a>
### listRoomparticipantsWithSession:room:

`- (void)listRoomparticipantsWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room*`

<a name="//api/name/moderateWithSession:room:options:" title="moderateWithSession:room:options:"></a>
### moderateWithSession:room:options:

`- (void)moderateWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* options:(BMXRoomModerateOptions *)*options*`

<a name="//api/name/pubConfigueWithSession:options:sdp:" title="pubConfigueWithSession:options:sdp:"></a>
### pubConfigueWithSession:options:sdp:

`- (void)pubConfigueWithSession:(BMXRTCSession *)*session* options:(BMXRoomPubConfigureOptions *)*options* sdp:(BMXRoomSDPInfo *)*sdp*`

<a name="//api/name/pubJoinRoomWithSession:options:" title="pubJoinRoomWithSession:options:"></a>
### pubJoinRoomWithSession:options:

`- (void)pubJoinRoomWithSession:(BMXRTCSession *)*session* options:(BMXPubRoomJoinOptions *)*options*`

<a name="//api/name/pubPublishWithSession:options:sdp:" title="pubPublishWithSession:options:sdp:"></a>
### pubPublishWithSession:options:sdp:

`- (void)pubPublishWithSession:(BMXRTCSession *)*session* options:(BMXRoomPubConfigureOptions *)*options* sdp:(BMXRoomSDPInfo *)*sdp*`

<a name="//api/name/pubUnPublishWithSession:" title="pubUnPublishWithSession:"></a>
### pubUnPublishWithSession:

`- (void)pubUnPublishWithSession:(BMXRTCSession *)*session*`

<a name="//api/name/removeDelegate:" title="removeDelegate:"></a>
### removeDelegate:

`- (void)removeDelegate:(id<BMXRTCSignalServiceProtocol>)*aDelegate*`

<a name="//api/name/removeRTCSignalListener:" title="removeRTCSignalListener:"></a>
### removeRTCSignalListener:

`- (void)removeRTCSignalListener:(id<BMXRTCSignalServiceProtocol>)*listener*`

<a name="//api/name/subConfigureWithSession:options:sdp:" title="subConfigureWithSession:options:sdp:"></a>
### subConfigureWithSession:options:sdp:

`- (void)subConfigureWithSession:(BMXRTCSession *)*session* options:(BMXRoomSubConfigureOptions *)*options* sdp:(BMXRoomSDPInfo *)*sdp*`

<a name="//api/name/subJoinRoomWithSession:options:" title="subJoinRoomWithSession:options:"></a>
### subJoinRoomWithSession:options:

`- (void)subJoinRoomWithSession:(BMXRTCSession *)*session* options:(BMXRoomSubJoinOptions *)*options*`

<a name="//api/name/subPauseWithSession:room:" title="subPauseWithSession:room:"></a>
### subPauseWithSession:room:

`- (void)subPauseWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room*`

<a name="//api/name/subStartWithSession:room:sdp:" title="subStartWithSession:room:sdp:"></a>
### subStartWithSession:room:sdp:

`- (void)subStartWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* sdp:(BMXRoomSDPInfo *)*sdp*`

<a name="//api/name/subSwitchWithSession:options:" title="subSwitchWithSession:options:"></a>
### subSwitchWithSession:options:

`- (void)subSwitchWithSession:(BMXRTCSession *)*session* options:(BMXRoomSubSwitchOptions *)*options*`

<a name="//api/name/subUnsubscribeWithSession:room:streams:" title="subUnsubscribeWithSession:room:streams:"></a>
### subUnsubscribeWithSession:room:streams:

`- (void)subUnsubscribeWithSession:(BMXRTCSession *)*session* room:(BMXRTCRoom *)*room* streams:(BMXRTCStreams *)*streams*`

<a name="//api/name/trickleCompletedWithSession:type:" title="trickleCompletedWithSession:type:"></a>
### trickleCompletedWithSession:type:

`- (void)trickleCompletedWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type*`

<a name="//api/name/trickleWithSession:type:sdpMid:sdpMLineIndex:candidate:" title="trickleWithSession:type:sdpMid:sdpMLineIndex:candidate:"></a>
### trickleWithSession:type:sdpMid:sdpMLineIndex:candidate:

`- (void)trickleWithSession:(BMXRTCSession *)*session* type:(BMXRTCSignalService_HandlerType)*type* sdpMid:(NSString *)*sdpMid* sdpMLineIndex:(int)*sdpMLineIndex* candidate:(NSString *)*candidate*`

