//-------------------------------------------------------------------------------------------------
// File    : bmx_roster_item.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx roster item define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_roster_item_h
#define bmx_roster_item_h

#include <vector>
#include "bmx_base_object.h"

namespace floo {

class EXPORT_API BMXRosterItem : public BMXBaseObject {
public:
  enum class RosterRelation {
    Friend,       // 好友
    Deleted,      // 被删除
    Stranger,     // 陌生人
    Blocked,      // 被加入黑名单
  };

  /**
   * 析构函数
   **/
  virtual ~BMXRosterItem() {}

  /**
   * 好友Id
   **/
  virtual int64_t rosterId() = 0;

  /**
   * 好友名
   **/
  virtual const std::string& username() = 0;

  /**
   * 好友昵称
   **/
  virtual const std::string& nickname() = 0;

  /**
   * 好友头像
   **/
  virtual std::string avatarUrl() = 0;

  /**
   * 好友头像本地存储路径
   **/
  virtual std::string avatarPath() = 0;

  /**
   * 好友头像缩略图本地存储路径
   **/
  virtual std::string avatarThumbnailPath() = 0;

  /**
   * 扩展信息，用户设置的好友可以看到的信息，比如地址，个性签名等
   **/
  virtual const JSON& publicInfo() = 0;

  /**
   * 用户对好友添加的备注等信息
   **/
  virtual const JSON& alias() = 0;

  /**
   * 用户的服务器扩展信息
   **/
  virtual const JSON& ext() = 0;

  /**
   * 用户的本地扩展信息
   **/
  virtual const JSON& localExt() = 0;

  /**
   * 联系人关系
   **/
  virtual RosterRelation relation() = 0;

  /**
   * 是否提醒用户消息
   **/
  virtual bool isMuteNotification() = 0;

protected:
  BMXRosterItem() {}

private:
  BMXRosterItem(const BMXRosterItem&);
  BMXRosterItem& operator=(const BMXRosterItem&);
};

typedef std::shared_ptr<BMXRosterItem> BMXRosterItemPtr;
typedef std::vector<BMXRosterItemPtr> BMXRosterList;
}

#endif /* bmx_roster_item_h */
