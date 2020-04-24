//-------------------------------------------------------------------------------------------------
// File    : bmx_defines.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __bmx_defines_h__
#define __bmx_defines_h__

#include <cstdint>

//#if _MSC_VER
//#define snprintf _snprintf
//#endif

#if defined( _WIN32 )
#  if defined( MAXIM_EXPORTS ) || defined( DLL_EXPORT )
#    define EXPORT_API __declspec( dllexport )
#  else
#    if defined( MAXIM_IMPORTS ) || defined( DLL_IMPORT )
#      define EXPORT_API __declspec( dllimport )
#    endif
#  endif
#endif

#ifndef EXPORT_API
#  define EXPORT_API
#endif

#define MAXIM_ADMIN 1696
#define CONNECT_MAX_RETRY 3

namespace floo {

enum class BMXClientType {
  Unknown = 0, iOS, Android, Windows, macOS, Linux, Web
};

enum class BMXNetworkType {
  Mobile, Wifi, Cable, None
};

enum class BMXConnectStatus {
  Disconnected, Connected
};

enum class BMXSignInStatus {
  SignOut, SignIn
};

enum class BMXLogLevel {
  Error, Warning, Debug
};

}

#endif /* __bmx_defines_h__ */
