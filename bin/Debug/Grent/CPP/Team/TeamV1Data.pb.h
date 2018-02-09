// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TeamV1Data.proto

#ifndef PROTOBUF_TeamV1Data_2eproto__INCLUDED
#define PROTOBUF_TeamV1Data_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "PublicStruct.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_TeamV1Data_2eproto();
void protobuf_AssignDesc_TeamV1Data_2eproto();
void protobuf_ShutdownFile_TeamV1Data_2eproto();

class TeamMemberV1;

// ===================================================================

class TeamMemberV1 : public ::google::protobuf::Message {
 public:
  TeamMemberV1();
  virtual ~TeamMemberV1();

  TeamMemberV1(const TeamMemberV1& from);

  inline TeamMemberV1& operator=(const TeamMemberV1& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TeamMemberV1& default_instance();

  void Swap(TeamMemberV1* other);

  // implements Message ----------------------------------------------

  TeamMemberV1* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TeamMemberV1& from);
  void MergeFrom(const TeamMemberV1& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 RoleId = 1 [default = 0];
  inline bool has_roleid() const;
  inline void clear_roleid();
  static const int kRoleIdFieldNumber = 1;
  inline ::google::protobuf::uint64 roleid() const;
  inline void set_roleid(::google::protobuf::uint64 value);

  // optional sint32 SceneId = 2 [default = -1];
  inline bool has_sceneid() const;
  inline void clear_sceneid();
  static const int kSceneIdFieldNumber = 2;
  inline ::google::protobuf::int32 sceneid() const;
  inline void set_sceneid(::google::protobuf::int32 value);

  // optional sint32 Level = 3 [default = -1];
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 3;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional string Name = 4;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 4;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional sint32 ConfigId = 5 [default = -1];
  inline bool has_configid() const;
  inline void clear_configid();
  static const int kConfigIdFieldNumber = 5;
  inline ::google::protobuf::int32 configid() const;
  inline void set_configid(::google::protobuf::int32 value);

  // optional sint32 Hp = 6 [default = -1];
  inline bool has_hp() const;
  inline void clear_hp();
  static const int kHpFieldNumber = 6;
  inline ::google::protobuf::int32 hp() const;
  inline void set_hp(::google::protobuf::int32 value);

  // optional sint32 Mp = 7 [default = -1];
  inline bool has_mp() const;
  inline void clear_mp();
  static const int kMpFieldNumber = 7;
  inline ::google::protobuf::int32 mp() const;
  inline void set_mp(::google::protobuf::int32 value);

  // optional sint32 Status = 8 [default = -1];
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 8;
  inline ::google::protobuf::int32 status() const;
  inline void set_status(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:TeamMemberV1)
 private:
  inline void set_has_roleid();
  inline void clear_has_roleid();
  inline void set_has_sceneid();
  inline void clear_has_sceneid();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_configid();
  inline void clear_has_configid();
  inline void set_has_hp();
  inline void clear_has_hp();
  inline void set_has_mp();
  inline void clear_has_mp();
  inline void set_has_status();
  inline void clear_has_status();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 roleid_;
  ::google::protobuf::int32 sceneid_;
  ::google::protobuf::int32 level_;
  ::std::string* name_;
  ::google::protobuf::int32 configid_;
  ::google::protobuf::int32 hp_;
  ::google::protobuf::int32 mp_;
  ::google::protobuf::int32 status_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_TeamV1Data_2eproto();
  friend void protobuf_AssignDesc_TeamV1Data_2eproto();
  friend void protobuf_ShutdownFile_TeamV1Data_2eproto();

  void InitAsDefaultInstance();
  static TeamMemberV1* default_instance_;
};
// ===================================================================


// ===================================================================

// TeamMemberV1

// optional uint64 RoleId = 1 [default = 0];
inline bool TeamMemberV1::has_roleid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TeamMemberV1::set_has_roleid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TeamMemberV1::clear_has_roleid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TeamMemberV1::clear_roleid() {
  roleid_ = GOOGLE_ULONGLONG(0);
  clear_has_roleid();
}
inline ::google::protobuf::uint64 TeamMemberV1::roleid() const {
  return roleid_;
}
inline void TeamMemberV1::set_roleid(::google::protobuf::uint64 value) {
  set_has_roleid();
  roleid_ = value;
}

// optional sint32 SceneId = 2 [default = -1];
inline bool TeamMemberV1::has_sceneid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TeamMemberV1::set_has_sceneid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TeamMemberV1::clear_has_sceneid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TeamMemberV1::clear_sceneid() {
  sceneid_ = -1;
  clear_has_sceneid();
}
inline ::google::protobuf::int32 TeamMemberV1::sceneid() const {
  return sceneid_;
}
inline void TeamMemberV1::set_sceneid(::google::protobuf::int32 value) {
  set_has_sceneid();
  sceneid_ = value;
}

// optional sint32 Level = 3 [default = -1];
inline bool TeamMemberV1::has_level() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TeamMemberV1::set_has_level() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TeamMemberV1::clear_has_level() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TeamMemberV1::clear_level() {
  level_ = -1;
  clear_has_level();
}
inline ::google::protobuf::int32 TeamMemberV1::level() const {
  return level_;
}
inline void TeamMemberV1::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// optional string Name = 4;
inline bool TeamMemberV1::has_name() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void TeamMemberV1::set_has_name() {
  _has_bits_[0] |= 0x00000008u;
}
inline void TeamMemberV1::clear_has_name() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void TeamMemberV1::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& TeamMemberV1::name() const {
  return *name_;
}
inline void TeamMemberV1::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void TeamMemberV1::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void TeamMemberV1::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TeamMemberV1::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* TeamMemberV1::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TeamMemberV1::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional sint32 ConfigId = 5 [default = -1];
inline bool TeamMemberV1::has_configid() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void TeamMemberV1::set_has_configid() {
  _has_bits_[0] |= 0x00000010u;
}
inline void TeamMemberV1::clear_has_configid() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void TeamMemberV1::clear_configid() {
  configid_ = -1;
  clear_has_configid();
}
inline ::google::protobuf::int32 TeamMemberV1::configid() const {
  return configid_;
}
inline void TeamMemberV1::set_configid(::google::protobuf::int32 value) {
  set_has_configid();
  configid_ = value;
}

// optional sint32 Hp = 6 [default = -1];
inline bool TeamMemberV1::has_hp() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void TeamMemberV1::set_has_hp() {
  _has_bits_[0] |= 0x00000020u;
}
inline void TeamMemberV1::clear_has_hp() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void TeamMemberV1::clear_hp() {
  hp_ = -1;
  clear_has_hp();
}
inline ::google::protobuf::int32 TeamMemberV1::hp() const {
  return hp_;
}
inline void TeamMemberV1::set_hp(::google::protobuf::int32 value) {
  set_has_hp();
  hp_ = value;
}

// optional sint32 Mp = 7 [default = -1];
inline bool TeamMemberV1::has_mp() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void TeamMemberV1::set_has_mp() {
  _has_bits_[0] |= 0x00000040u;
}
inline void TeamMemberV1::clear_has_mp() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void TeamMemberV1::clear_mp() {
  mp_ = -1;
  clear_has_mp();
}
inline ::google::protobuf::int32 TeamMemberV1::mp() const {
  return mp_;
}
inline void TeamMemberV1::set_mp(::google::protobuf::int32 value) {
  set_has_mp();
  mp_ = value;
}

// optional sint32 Status = 8 [default = -1];
inline bool TeamMemberV1::has_status() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void TeamMemberV1::set_has_status() {
  _has_bits_[0] |= 0x00000080u;
}
inline void TeamMemberV1::clear_has_status() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void TeamMemberV1::clear_status() {
  status_ = -1;
  clear_has_status();
}
inline ::google::protobuf::int32 TeamMemberV1::status() const {
  return status_;
}
inline void TeamMemberV1::set_status(::google::protobuf::int32 value) {
  set_has_status();
  status_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_TeamV1Data_2eproto__INCLUDED
