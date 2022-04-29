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
    BMXNoError = 0,
    
    BMXGeneralError,
    BMXInvalidParam,
    BMXNotFound,
    BMXDbOperationFailed,
    BMXSignInCancelled,
    BMXSignInTimeout,
    BMXSignInFailed,

    BMXUserNotLogin = 100,
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
    BMXUserOldPasswordNotMatch,

    BMXPushTokenInvalid = 200,
    BMXPushAliasBindByOtherUser,
    BMXPushAliasTokenNotMatch,

    BMXInvalidVerificationCode = 300,
    BMXInvalidRequestParameter,
    BMXInvalidUserNameParameter,
    BMXMissingAccessToken,
    BMXCurrentUserIsInRoster,
    BMXCurrentUserIsInBlocklist,
    BMXAnswerFailed,
    BMXInvalidToken,
    BMXInvalidFileSign,
    BMXInvalidFileObjectType,
    BMXInvalidFileUploadToType,
    BMXInvalidFileDownloadUrl,

    BMXMessageInvalid = 400,
    BMXMessageOutRecallTime,
    BMXMessageRecallDisabled,
    BMXMessageCensored,
    BMXMessageInvalidType,

    BMXRosterNotFriend = 500,
    BMXRosterBlockListExist,
    BMXRosterRejectApplication,

    BMXGroupServerDbError = 600,
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

    BMXServerNotReachable = 700,
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
    BMXServerInvalidUploadUrl,
    BMXServerAppLicenseInvalid,
    BMXServerAppLicenseExpired,
    BMXServerAppLicenseExceedLimit,
    BMXServerAppIdMissing,
    BMXServerAppIdInvalid,
    BMXServerAppSignInvalid,
    BMXServerAppNotifierNotExist,
    BMXServerNoClusterInfoForClusterId,
    BMXServerFileDownloadFailure,
    BMXServerAppStatusNotNormal,

};

