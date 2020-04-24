//-------------------------------------------------------------------------------------------------
// File    : bmx_message_config.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx result page define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_message_config_h
#define bmx_message_config_h

#include <memory>
#include <string>
#include <vector>
#include "bmx_defines.h"

namespace floo {

static const std::string kMentionAll = "mentionAll";              // bool
static const std::string kMentionList = "mentionList";            // vector<int64_t>
static const std::string kMentionedMessage = "mentionedMessage";  // string
static const std::string kPushMessage = "pushMessage";            // string
static const std::string kSenderNickname = "senderNickname";      // string

struct BMXMessageConfig {
  BMXMessageConfig() : mentionAll(false) {}
  virtual ~BMXMessageConfig() {}

  std::string serialize() const;

  bool mentionAll;
  std::vector<int64_t> mentionList;
  std::string mentionedMessage;
  std::string pushMessage;
  std::string senderNickname;
};

typedef std::shared_ptr<BMXMessageConfig> BMXMessageConfigPtr;

}

#endif /* bmx_message_config_h */
