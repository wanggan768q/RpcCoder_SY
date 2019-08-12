// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CurrencyRpc.proto

#ifndef PROTOBUF_CurrencyRpc_2eproto__INCLUDED
#define PROTOBUF_CurrencyRpc_2eproto__INCLUDED

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
void  protobuf_AddDesc_CurrencyRpc_2eproto();
void protobuf_AssignDesc_CurrencyRpc_2eproto();
void protobuf_ShutdownFile_CurrencyRpc_2eproto();

class CurrencyRpcTransfromAsk;
class CurrencyRpcTransfromReply;
class CurrencyRpcShowAsk;
class CurrencyRpcShowReply;

// ===================================================================

class CurrencyRpcTransfromAsk : public ::google::protobuf::Message {
 public:
  CurrencyRpcTransfromAsk();
  virtual ~CurrencyRpcTransfromAsk();

  CurrencyRpcTransfromAsk(const CurrencyRpcTransfromAsk& from);

  inline CurrencyRpcTransfromAsk& operator=(const CurrencyRpcTransfromAsk& from) {
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
  static const CurrencyRpcTransfromAsk& default_instance();

  void Swap(CurrencyRpcTransfromAsk* other);

  // implements Message ----------------------------------------------

  CurrencyRpcTransfromAsk* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CurrencyRpcTransfromAsk& from);
  void MergeFrom(const CurrencyRpcTransfromAsk& from);
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

  // optional int32 To_type = 1 [default = -1];
  inline bool has_to_type() const;
  inline void clear_to_type();
  static const int kToTypeFieldNumber = 1;
  inline ::google::protobuf::int32 to_type() const;
  inline void set_to_type(::google::protobuf::int32 value);

  // optional int32 From_type = 2 [default = -1];
  inline bool has_from_type() const;
  inline void clear_from_type();
  static const int kFromTypeFieldNumber = 2;
  inline ::google::protobuf::int32 from_type() const;
  inline void set_from_type(::google::protobuf::int32 value);

  // optional int64 From_num = 3 [default = 0];
  inline bool has_from_num() const;
  inline void clear_from_num();
  static const int kFromNumFieldNumber = 3;
  inline ::google::protobuf::int64 from_num() const;
  inline void set_from_num(::google::protobuf::int64 value);

  // optional int64 Diamond_bind_num = 4 [default = 0];
  inline bool has_diamond_bind_num() const;
  inline void clear_diamond_bind_num();
  static const int kDiamondBindNumFieldNumber = 4;
  inline ::google::protobuf::int64 diamond_bind_num() const;
  inline void set_diamond_bind_num(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:CurrencyRpcTransfromAsk)
 private:
  inline void set_has_to_type();
  inline void clear_has_to_type();
  inline void set_has_from_type();
  inline void clear_has_from_type();
  inline void set_has_from_num();
  inline void clear_has_from_num();
  inline void set_has_diamond_bind_num();
  inline void clear_has_diamond_bind_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 to_type_;
  ::google::protobuf::int32 from_type_;
  ::google::protobuf::int64 from_num_;
  ::google::protobuf::int64 diamond_bind_num_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_CurrencyRpc_2eproto();
  friend void protobuf_AssignDesc_CurrencyRpc_2eproto();
  friend void protobuf_ShutdownFile_CurrencyRpc_2eproto();

  void InitAsDefaultInstance();
  static CurrencyRpcTransfromAsk* default_instance_;
};
// -------------------------------------------------------------------

class CurrencyRpcTransfromReply : public ::google::protobuf::Message {
 public:
  CurrencyRpcTransfromReply();
  virtual ~CurrencyRpcTransfromReply();

  CurrencyRpcTransfromReply(const CurrencyRpcTransfromReply& from);

  inline CurrencyRpcTransfromReply& operator=(const CurrencyRpcTransfromReply& from) {
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
  static const CurrencyRpcTransfromReply& default_instance();

  void Swap(CurrencyRpcTransfromReply* other);

  // implements Message ----------------------------------------------

  CurrencyRpcTransfromReply* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CurrencyRpcTransfromReply& from);
  void MergeFrom(const CurrencyRpcTransfromReply& from);
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

  // optional int32 Result = 1 [default = -9999];
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // optional int32 Reward_type = 2 [default = -1];
  inline bool has_reward_type() const;
  inline void clear_reward_type();
  static const int kRewardTypeFieldNumber = 2;
  inline ::google::protobuf::int32 reward_type() const;
  inline void set_reward_type(::google::protobuf::int32 value);

  // optional int64 Reward_num = 3 [default = 0];
  inline bool has_reward_num() const;
  inline void clear_reward_num();
  static const int kRewardNumFieldNumber = 3;
  inline ::google::protobuf::int64 reward_num() const;
  inline void set_reward_num(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:CurrencyRpcTransfromReply)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  inline void set_has_reward_type();
  inline void clear_has_reward_type();
  inline void set_has_reward_num();
  inline void clear_has_reward_num();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 result_;
  ::google::protobuf::int32 reward_type_;
  ::google::protobuf::int64 reward_num_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_CurrencyRpc_2eproto();
  friend void protobuf_AssignDesc_CurrencyRpc_2eproto();
  friend void protobuf_ShutdownFile_CurrencyRpc_2eproto();

  void InitAsDefaultInstance();
  static CurrencyRpcTransfromReply* default_instance_;
};
// -------------------------------------------------------------------

class CurrencyRpcShowAsk : public ::google::protobuf::Message {
 public:
  CurrencyRpcShowAsk();
  virtual ~CurrencyRpcShowAsk();

  CurrencyRpcShowAsk(const CurrencyRpcShowAsk& from);

  inline CurrencyRpcShowAsk& operator=(const CurrencyRpcShowAsk& from) {
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
  static const CurrencyRpcShowAsk& default_instance();

  void Swap(CurrencyRpcShowAsk* other);

  // implements Message ----------------------------------------------

  CurrencyRpcShowAsk* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CurrencyRpcShowAsk& from);
  void MergeFrom(const CurrencyRpcShowAsk& from);
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

  // @@protoc_insertion_point(class_scope:CurrencyRpcShowAsk)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_CurrencyRpc_2eproto();
  friend void protobuf_AssignDesc_CurrencyRpc_2eproto();
  friend void protobuf_ShutdownFile_CurrencyRpc_2eproto();

  void InitAsDefaultInstance();
  static CurrencyRpcShowAsk* default_instance_;
};
// -------------------------------------------------------------------

class CurrencyRpcShowReply : public ::google::protobuf::Message {
 public:
  CurrencyRpcShowReply();
  virtual ~CurrencyRpcShowReply();

  CurrencyRpcShowReply(const CurrencyRpcShowReply& from);

  inline CurrencyRpcShowReply& operator=(const CurrencyRpcShowReply& from) {
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
  static const CurrencyRpcShowReply& default_instance();

  void Swap(CurrencyRpcShowReply* other);

  // implements Message ----------------------------------------------

  CurrencyRpcShowReply* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CurrencyRpcShowReply& from);
  void MergeFrom(const CurrencyRpcShowReply& from);
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

  // optional int32 Result = 1 [default = -1];
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // repeated .Resource ShowResources = 2;
  inline int showresources_size() const;
  inline void clear_showresources();
  static const int kShowResourcesFieldNumber = 2;
  inline const ::Resource& showresources(int index) const;
  inline ::Resource* mutable_showresources(int index);
  inline ::Resource* add_showresources();
  inline const ::google::protobuf::RepeatedPtrField< ::Resource >&
      showresources() const;
  inline ::google::protobuf::RepeatedPtrField< ::Resource >*
      mutable_showresources();

  // @@protoc_insertion_point(class_scope:CurrencyRpcShowReply)
 private:
  inline void set_has_result();
  inline void clear_has_result();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::Resource > showresources_;
  ::google::protobuf::int32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_CurrencyRpc_2eproto();
  friend void protobuf_AssignDesc_CurrencyRpc_2eproto();
  friend void protobuf_ShutdownFile_CurrencyRpc_2eproto();

  void InitAsDefaultInstance();
  static CurrencyRpcShowReply* default_instance_;
};
// ===================================================================


// ===================================================================

// CurrencyRpcTransfromAsk

// optional int32 To_type = 1 [default = -1];
inline bool CurrencyRpcTransfromAsk::has_to_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CurrencyRpcTransfromAsk::set_has_to_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CurrencyRpcTransfromAsk::clear_has_to_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CurrencyRpcTransfromAsk::clear_to_type() {
  to_type_ = -1;
  clear_has_to_type();
}
inline ::google::protobuf::int32 CurrencyRpcTransfromAsk::to_type() const {
  return to_type_;
}
inline void CurrencyRpcTransfromAsk::set_to_type(::google::protobuf::int32 value) {
  set_has_to_type();
  to_type_ = value;
}

// optional int32 From_type = 2 [default = -1];
inline bool CurrencyRpcTransfromAsk::has_from_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CurrencyRpcTransfromAsk::set_has_from_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CurrencyRpcTransfromAsk::clear_has_from_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CurrencyRpcTransfromAsk::clear_from_type() {
  from_type_ = -1;
  clear_has_from_type();
}
inline ::google::protobuf::int32 CurrencyRpcTransfromAsk::from_type() const {
  return from_type_;
}
inline void CurrencyRpcTransfromAsk::set_from_type(::google::protobuf::int32 value) {
  set_has_from_type();
  from_type_ = value;
}

// optional int64 From_num = 3 [default = 0];
inline bool CurrencyRpcTransfromAsk::has_from_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CurrencyRpcTransfromAsk::set_has_from_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CurrencyRpcTransfromAsk::clear_has_from_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CurrencyRpcTransfromAsk::clear_from_num() {
  from_num_ = GOOGLE_LONGLONG(0);
  clear_has_from_num();
}
inline ::google::protobuf::int64 CurrencyRpcTransfromAsk::from_num() const {
  return from_num_;
}
inline void CurrencyRpcTransfromAsk::set_from_num(::google::protobuf::int64 value) {
  set_has_from_num();
  from_num_ = value;
}

// optional int64 Diamond_bind_num = 4 [default = 0];
inline bool CurrencyRpcTransfromAsk::has_diamond_bind_num() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CurrencyRpcTransfromAsk::set_has_diamond_bind_num() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CurrencyRpcTransfromAsk::clear_has_diamond_bind_num() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CurrencyRpcTransfromAsk::clear_diamond_bind_num() {
  diamond_bind_num_ = GOOGLE_LONGLONG(0);
  clear_has_diamond_bind_num();
}
inline ::google::protobuf::int64 CurrencyRpcTransfromAsk::diamond_bind_num() const {
  return diamond_bind_num_;
}
inline void CurrencyRpcTransfromAsk::set_diamond_bind_num(::google::protobuf::int64 value) {
  set_has_diamond_bind_num();
  diamond_bind_num_ = value;
}

// -------------------------------------------------------------------

// CurrencyRpcTransfromReply

// optional int32 Result = 1 [default = -9999];
inline bool CurrencyRpcTransfromReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CurrencyRpcTransfromReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CurrencyRpcTransfromReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CurrencyRpcTransfromReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 CurrencyRpcTransfromReply::result() const {
  return result_;
}
inline void CurrencyRpcTransfromReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// optional int32 Reward_type = 2 [default = -1];
inline bool CurrencyRpcTransfromReply::has_reward_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CurrencyRpcTransfromReply::set_has_reward_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CurrencyRpcTransfromReply::clear_has_reward_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CurrencyRpcTransfromReply::clear_reward_type() {
  reward_type_ = -1;
  clear_has_reward_type();
}
inline ::google::protobuf::int32 CurrencyRpcTransfromReply::reward_type() const {
  return reward_type_;
}
inline void CurrencyRpcTransfromReply::set_reward_type(::google::protobuf::int32 value) {
  set_has_reward_type();
  reward_type_ = value;
}

// optional int64 Reward_num = 3 [default = 0];
inline bool CurrencyRpcTransfromReply::has_reward_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CurrencyRpcTransfromReply::set_has_reward_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CurrencyRpcTransfromReply::clear_has_reward_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CurrencyRpcTransfromReply::clear_reward_num() {
  reward_num_ = GOOGLE_LONGLONG(0);
  clear_has_reward_num();
}
inline ::google::protobuf::int64 CurrencyRpcTransfromReply::reward_num() const {
  return reward_num_;
}
inline void CurrencyRpcTransfromReply::set_reward_num(::google::protobuf::int64 value) {
  set_has_reward_num();
  reward_num_ = value;
}

// -------------------------------------------------------------------

// CurrencyRpcShowAsk

// -------------------------------------------------------------------

// CurrencyRpcShowReply

// optional int32 Result = 1 [default = -1];
inline bool CurrencyRpcShowReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CurrencyRpcShowReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CurrencyRpcShowReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CurrencyRpcShowReply::clear_result() {
  result_ = -1;
  clear_has_result();
}
inline ::google::protobuf::int32 CurrencyRpcShowReply::result() const {
  return result_;
}
inline void CurrencyRpcShowReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// repeated .Resource ShowResources = 2;
inline int CurrencyRpcShowReply::showresources_size() const {
  return showresources_.size();
}
inline void CurrencyRpcShowReply::clear_showresources() {
  showresources_.Clear();
}
inline const ::Resource& CurrencyRpcShowReply::showresources(int index) const {
  return showresources_.Get(index);
}
inline ::Resource* CurrencyRpcShowReply::mutable_showresources(int index) {
  return showresources_.Mutable(index);
}
inline ::Resource* CurrencyRpcShowReply::add_showresources() {
  return showresources_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Resource >&
CurrencyRpcShowReply::showresources() const {
  return showresources_;
}
inline ::google::protobuf::RepeatedPtrField< ::Resource >*
CurrencyRpcShowReply::mutable_showresources() {
  return &showresources_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CurrencyRpc_2eproto__INCLUDED