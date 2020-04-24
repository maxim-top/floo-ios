//-------------------------------------------------------------------------------------------------
// File    : bmx_result_page.h
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

#ifndef bmx_result_page_h
#define bmx_result_page_h

#include <vector>
#include <string>

#include "bmx_base_object.h"
#include "bmx_group.h"

namespace floo
{

template<typename T>
class EXPORT_API BMXResultPage : public BMXBaseObject
{
public:
  /**
   * 构造函数
   **/
  BMXResultPage() : mOffset(-1) {}

  /**
   * 构造函数
   **/
  BMXResultPage(const std::vector<T> &result, int64_t offset) :
    mResult(result), mOffset(offset) {}

  /**
   * 构造函数
   **/
  BMXResultPage(const std::vector<T> &result, std::string cursor) :
    mResult(result), mCursor(cursor), mOffset(-1) {}

  /**
   * 构造函数
   **/
  BMXResultPage(const BMXResultPage& from) :
    mResult(from.mResult), mCursor(from.mCursor), mOffset(from.mOffset) {}

  /**
   * 构造函数
   **/
  BMXResultPage(BMXResultPage&& from) :
    mResult(std::move(from.mResult)), mCursor(from.mCursor), mOffset(from.mOffset) {}

  BMXResultPage& operator=(const BMXResultPage& from) {
    if (this != &from) {
      mResult = from.mResult;
      mCursor = from.mCursor;
      mOffset = from.mOffset;
    }
    return *this;
  }

  /**
   * 析构函数
   **/
  virtual ~BMXResultPage() {};

  size_t count() const { return mResult.size(); }
  int64_t offset() const { return mOffset; }
  const std::string& cursor() const { return mCursor; }
  const std::vector<T>& result() const { return mResult; }

private:
  std::vector<T> mResult;
  std::string mCursor;
  int64_t mOffset;
};

typedef BMXResultPage<BMXGroup::MemberPtr> BMXGroupMemberResultPage;
typedef std::shared_ptr<BMXGroupMemberResultPage> BMXGroupMemberResultPagePtr;

typedef BMXResultPage<BMXGroup::BannedMemberPtr> BMXGroupBannedMemberResultPage;
typedef std::shared_ptr<BMXGroupBannedMemberResultPage> BMXGroupBannedMemberResultPagePtr;

typedef BMXResultPage<BMXGroup::InvitationPtr> BMXGroupInvitationPage;
typedef std::shared_ptr<BMXGroupInvitationPage> BMXGroupInvitationPagePtr;

typedef BMXResultPage<BMXGroup::ApplicationPtr> BMXGroupApplicationPage;
typedef std::shared_ptr<BMXGroupApplicationPage> BMXGroupApplicationPagePtr;

}

#endif /* bmx_result_page_h */
