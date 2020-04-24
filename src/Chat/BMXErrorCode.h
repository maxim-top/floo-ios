// ----------------------------------------------------------------------
// File    : BMXErrorCode.h
// Author  : hyt <yutong@bmxlabs.com>
// Purpose :
// Created : 2018/11/26 by hyt <yutong@bmxlabs.com>
//
// ----------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
// ----------------------------------------------------------------------

typedef NS_ENUM(NSUInteger, BMXErrorCode) {
    BMXNoError,
    
    BMXGeneralError,
    BMXInvalidParam,
    BMXNotFound,

    BMXUserNotLogin,
    BMXUserAlreadyLogin,
    BMXUserAuthFailed,
    BMXUserPermissionDenied,
    BMXUserNotExist,
    BMXUserAlreadyExist,
    BMXUserFrozen,
    BMXUserBanned,
    BMXUserRemoved,
    BMXUserTooManyDevice,
    BMXUserPasswordChanged,
    BMXUserKickedBySameDevice,
    BMXUserKickedByOtherDevices,
    BMXUserAbnormal,
    BMXUserCancel,
    
    BMXInvalidVerificationCode,
    BMXInvalidRequestParameter,
    BMXInvalidUserNameParameter,
    BMXMissingAccessToken,
    BMXCurrentUserIsInRoster,
    BMXCurrentUserIsInBlocklist,
    BMXAnswerFailed,
    BMXInvalidToken,
    
    BMXRosterNotFriend,
    BMXRosterBlockListExist,
    BMXRosterRejectApplication,
    
    BMXGroupServerDbError,
    BMXGroupNotExist,
    BMXGroupNotMemberFound,
    BMXGroupMsgNotifyTypeUnknown,
    BMXGroupOwnerCannotLeave,
    BMXGroupTransferNotAllowed,
    BMXGroupRecoveryMode,
    BMXGroupExceedLimitGlobal,
    BMXGroupExceedLimitUserCreate,
    BMXGroupExceedLimitUserJoin,
    BMXGroupCapacityExceedLimit,
    BMXGroupMemberPermissionRequired,
    BMXGroupAdminPermissionRequired,
    BMXGroupOwnerPermissionRequired,
    BMXGroupApplicationExpiredOrHandled,
    BMXGroupInvitationExpiredOrHandled,
    BMXGroupKickTooManyTimes,
    BMXGroupMemberExist,
    BMXGroupBlockListExist,
    BMXGroupAnnouncementNotFound,
    BMXGroupAnnouncementForbidden,
    BMXGroupSharedFileNotFound,
    BMXGroupSharedFileOperateNotAllowed,
    BMXGroupMemberBanned,

    BMXSignInCancelled,
    BMXSignInTimeout,
    BMXSignInFailed,
    
    BMXDbOperationFailed,
    
    BMXMessageInvalid,
    BMXMessageOutRecallTime,
    BMXMessageRecallDisabled,
    BMXMessageCensored,
    BMXMessageInvalidType,
    
    BMXServerNotReachable,
    BMXServerUnknownError,
    BMXServerInvalid,
    BMXServerDecryptionFailed,
    BMXServerEncryptMethodUnsupported,
    BMXServerBusy,
    BMXServerNeedRetry,
    BMXServerTimeOut,
    BMXServerConnectFailed,
    BMXServerDNSFailed,
    BMXServerNeedReconnected,
    BMXServerFileUploadUnknownError,
    BMXServerFileDownloadUnknownError,
    BMXServerInvalidLicense,
    BMXServerLicenseLimit,
    BMXServerAppFrozen,
    BMXServerTooManyRequest,
    BMXServerNotAllowOpenRegister,
    BMXServerFireplaceUnknownError,
    BMXServerResponseInvalid,
    BMXServerInvalidUploadUrl

};

