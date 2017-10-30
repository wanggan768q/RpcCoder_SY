// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PublicStruct.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "PublicStruct.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* CharacterInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CharacterInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_PublicStruct_2eproto() {
  protobuf_AddDesc_PublicStruct_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "PublicStruct.proto");
  GOOGLE_CHECK(file != NULL);
  CharacterInfo_descriptor_ = file->message_type(0);
  static const int CharacterInfo_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CharacterInfo, roleid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CharacterInfo, nickname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CharacterInfo, configid_),
  };
  CharacterInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CharacterInfo_descriptor_,
      CharacterInfo::default_instance_,
      CharacterInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CharacterInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CharacterInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CharacterInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_PublicStruct_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CharacterInfo_descriptor_, &CharacterInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_PublicStruct_2eproto() {
  delete CharacterInfo::default_instance_;
  delete CharacterInfo_reflection_;
}

void protobuf_AddDesc_PublicStruct_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022PublicStruct.proto\"J\n\rCharacterInfo\022\021\n"
    "\006RoleId\030\001 \001(\004:\0010\022\020\n\010Nickname\030\002 \001(\t\022\024\n\010Co"
    "nfigId\030\003 \001(\021:\002-1", 96);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PublicStruct.proto", &protobuf_RegisterTypes);
  CharacterInfo::default_instance_ = new CharacterInfo();
  CharacterInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_PublicStruct_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_PublicStruct_2eproto {
  StaticDescriptorInitializer_PublicStruct_2eproto() {
    protobuf_AddDesc_PublicStruct_2eproto();
  }
} static_descriptor_initializer_PublicStruct_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CharacterInfo::kRoleIdFieldNumber;
const int CharacterInfo::kNicknameFieldNumber;
const int CharacterInfo::kConfigIdFieldNumber;
#endif  // !_MSC_VER

CharacterInfo::CharacterInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void CharacterInfo::InitAsDefaultInstance() {
}

CharacterInfo::CharacterInfo(const CharacterInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void CharacterInfo::SharedCtor() {
  _cached_size_ = 0;
  roleid_ = GOOGLE_ULONGLONG(0);
  nickname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  configid_ = -1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CharacterInfo::~CharacterInfo() {
  SharedDtor();
}

void CharacterInfo::SharedDtor() {
  if (nickname_ != &::google::protobuf::internal::kEmptyString) {
    delete nickname_;
  }
  if (this != default_instance_) {
  }
}

void CharacterInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CharacterInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CharacterInfo_descriptor_;
}

const CharacterInfo& CharacterInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_PublicStruct_2eproto();
  return *default_instance_;
}

CharacterInfo* CharacterInfo::default_instance_ = NULL;

CharacterInfo* CharacterInfo::New() const {
  return new CharacterInfo;
}

void CharacterInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    roleid_ = GOOGLE_ULONGLONG(0);
    if (has_nickname()) {
      if (nickname_ != &::google::protobuf::internal::kEmptyString) {
        nickname_->clear();
      }
    }
    configid_ = -1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CharacterInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 RoleId = 1 [default = 0];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &roleid_)));
          set_has_roleid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_Nickname;
        break;
      }

      // optional string Nickname = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_Nickname:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nickname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->nickname().data(), this->nickname().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_ConfigId;
        break;
      }

      // optional sint32 ConfigId = 3 [default = -1];
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_ConfigId:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &configid_)));
          set_has_configid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void CharacterInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint64 RoleId = 1 [default = 0];
  if (has_roleid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->roleid(), output);
  }

  // optional string Nickname = 2;
  if (has_nickname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->nickname().data(), this->nickname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->nickname(), output);
  }

  // optional sint32 ConfigId = 3 [default = -1];
  if (has_configid()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(3, this->configid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* CharacterInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional uint64 RoleId = 1 [default = 0];
  if (has_roleid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->roleid(), target);
  }

  // optional string Nickname = 2;
  if (has_nickname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->nickname().data(), this->nickname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->nickname(), target);
  }

  // optional sint32 ConfigId = 3 [default = -1];
  if (has_configid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(3, this->configid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int CharacterInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint64 RoleId = 1 [default = 0];
    if (has_roleid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->roleid());
    }

    // optional string Nickname = 2;
    if (has_nickname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nickname());
    }

    // optional sint32 ConfigId = 3 [default = -1];
    if (has_configid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->configid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CharacterInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CharacterInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CharacterInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CharacterInfo::MergeFrom(const CharacterInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_roleid()) {
      set_roleid(from.roleid());
    }
    if (from.has_nickname()) {
      set_nickname(from.nickname());
    }
    if (from.has_configid()) {
      set_configid(from.configid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CharacterInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CharacterInfo::CopyFrom(const CharacterInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CharacterInfo::IsInitialized() const {

  return true;
}

void CharacterInfo::Swap(CharacterInfo* other) {
  if (other != this) {
    std::swap(roleid_, other->roleid_);
    std::swap(nickname_, other->nickname_);
    std::swap(configid_, other->configid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CharacterInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CharacterInfo_descriptor_;
  metadata.reflection = CharacterInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
