/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     PubWraperClass.h
* Author:       郭晓波
* Description:  公共数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __PUB_WRAPER_CLASS_H
#define __PUB_WRAPER_CLASS_H

#include "BASE.h"
#include "PublicStruct.pb.h"
#include "DataWraperInterface.h"



//ItemAttr封装类
class ItemAttrWraper
{
public:
	//构造函数
	ItemAttrWraper()
	{
		

	}
	//赋值构造函数
	ItemAttrWraper(const ItemAttr& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemAttr& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemAttr ToPB() const
	{
		ItemAttr v;
		v.mutable_baseattr()->Reserve(m_BaseAttr.size());
		for (int i=0; i<(int)m_BaseAttr.size(); i++)
		{
			*v.add_baseattr() = m_BaseAttr[i].ToPB();
		}
		v.mutable_extraattr()->Reserve(m_ExtraAttr.size());
		for (int i=0; i<(int)m_ExtraAttr.size(); i++)
		{
			*v.add_extraattr() = m_ExtraAttr[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ItemAttr pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemAttr& v)
	{
		m_BaseAttr.clear();
		m_BaseAttr.reserve(v.baseattr_size());
		for( int i=0; i<v.baseattr_size(); i++)
			m_BaseAttr.push_back(v.baseattr(i));
		m_ExtraAttr.clear();
		m_ExtraAttr.reserve(v.extraattr_size());
		for( int i=0; i<v.extraattr_size(); i++)
			m_ExtraAttr.push_back(v.extraattr(i));

	}

private:
	//基础属性
	vector<AttrKeyValueWraper> m_BaseAttr;
public:
	int SizeBaseAttr()
	{
		return m_BaseAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetBaseAttr() const
	{
		return m_BaseAttr;
	}
	AttrKeyValueWraper GetBaseAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_BaseAttr[Index];
	}
	void SetBaseAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_BaseAttr=v;
	}
	void ClearBaseAttr( )
	{
		m_BaseAttr.clear();
	}
	void SetBaseAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return;
		}
		m_BaseAttr[Index] = v;
	}
	void AddBaseAttr( const AttrKeyValueWraper& v )
	{
		m_BaseAttr.push_back(v);
	}
private:
	//ExtraAttr
	vector<AttrKeyValueWraper> m_ExtraAttr;
public:
	int SizeExtraAttr()
	{
		return m_ExtraAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetExtraAttr() const
	{
		return m_ExtraAttr;
	}
	AttrKeyValueWraper GetExtraAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_ExtraAttr[Index];
	}
	void SetExtraAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_ExtraAttr=v;
	}
	void ClearExtraAttr( )
	{
		m_ExtraAttr.clear();
	}
	void SetExtraAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return;
		}
		m_ExtraAttr[Index] = v;
	}
	void AddExtraAttr( const AttrKeyValueWraper& v )
	{
		m_ExtraAttr.push_back(v);
	}

};
//ChatMsg封装类
class ChatMsgWraper
{
public:
	//构造函数
	ChatMsgWraper()
	{
		
		m_Chat_content = "";
		m_Chat_voice_url = "";
		m_Chat_voice_secs = -1;

	}
	//赋值构造函数
	ChatMsgWraper(const ChatMsg& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatMsg& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatMsg ToPB() const
	{
		ChatMsg v;
		v.set_chat_content( m_Chat_content );
		v.set_chat_voice_url( m_Chat_voice_url );
		v.set_chat_voice_secs( m_Chat_voice_secs );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ChatMsg pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatMsg& v)
	{
		m_Chat_content = v.chat_content();
		m_Chat_voice_url = v.chat_voice_url();
		m_Chat_voice_secs = v.chat_voice_secs();

	}

private:
	//文字内容
	string m_Chat_content;
public:
	void SetChat_content( const string& v)
	{
		m_Chat_content=v;
	}
	string GetChat_content()
	{
		return m_Chat_content;
	}
	string GetChat_content() const
	{
		return m_Chat_content;
	}
private:
	//音频URL
	string m_Chat_voice_url;
public:
	void SetChat_voice_url( const string& v)
	{
		m_Chat_voice_url=v;
	}
	string GetChat_voice_url()
	{
		return m_Chat_voice_url;
	}
	string GetChat_voice_url() const
	{
		return m_Chat_voice_url;
	}
private:
	//音频秒数
	INT32 m_Chat_voice_secs;
public:
	void SetChat_voice_secs( INT32 v)
	{
		m_Chat_voice_secs=v;
	}
	INT32 GetChat_voice_secs()
	{
		return m_Chat_voice_secs;
	}
	INT32 GetChat_voice_secs() const
	{
		return m_Chat_voice_secs;
	}

};
//AttrKeyValue封装类
class AttrKeyValueWraper
{
public:
	//构造函数
	AttrKeyValueWraper()
	{
		
		m_Key = -1;
		m_Value = -1;

	}
	//赋值构造函数
	AttrKeyValueWraper(const AttrKeyValue& v){ Init(v); }
	//等号重载函数
	void operator = (const AttrKeyValue& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AttrKeyValue ToPB() const
	{
		AttrKeyValue v;
		v.set_key( m_Key );
		v.set_value( m_Value );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		AttrKeyValue pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AttrKeyValue& v)
	{
		m_Key = v.key();
		m_Value = v.value();

	}

private:
	//属性的key
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//Value
	INT64 m_Value;
public:
	void SetValue( INT64 v)
	{
		m_Value=v;
	}
	INT64 GetValue()
	{
		return m_Value;
	}
	INT64 GetValue() const
	{
		return m_Value;
	}

};
//ItemData封装类
class ItemDataWraper
{
public:
	//构造函数
	ItemDataWraper()
	{
		
		m_Guid = 0;
		m_IsLock = false;
		m_OverlayCount = -1;
		m_ConfigId = -1;
		m_Attr = ItemAttrWraper();
		m_BattleScore = -1;
		m_IsNull = false;

	}
	//赋值构造函数
	ItemDataWraper(const ItemData& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemData ToPB() const
	{
		ItemData v;
		v.set_guid( m_Guid );
		v.set_islock( m_IsLock );
		v.set_overlaycount( m_OverlayCount );
		v.set_configid( m_ConfigId );
		*v.mutable_attr()= m_Attr.ToPB();
		v.set_battlescore( m_BattleScore );
		v.set_isnull( m_IsNull );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ItemData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemData& v)
	{
		m_Guid = v.guid();
		m_IsLock = v.islock();
		m_OverlayCount = v.overlaycount();
		m_ConfigId = v.configid();
		m_Attr = v.attr();
		m_BattleScore = v.battlescore();
		m_IsNull = v.isnull();

	}

private:
	//物品GUID
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//物品锁
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}
private:
	//物品叠加数量
	INT32 m_OverlayCount;
public:
	void SetOverlayCount( INT32 v)
	{
		m_OverlayCount=v;
	}
	INT32 GetOverlayCount()
	{
		return m_OverlayCount;
	}
	INT32 GetOverlayCount() const
	{
		return m_OverlayCount;
	}
private:
	//物品表的id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//装备属性
	ItemAttrWraper m_Attr;
public:
	void SetAttr( const ItemAttrWraper& v)
	{
		m_Attr=v;
	}
	ItemAttrWraper GetAttr()
	{
		return m_Attr;
	}
	ItemAttrWraper GetAttr() const
	{
		return m_Attr;
	}
private:
	//装备评分
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//是否是空
	bool m_IsNull;
public:
	void SetIsNull( bool v)
	{
		m_IsNull=v;
	}
	bool GetIsNull()
	{
		return m_IsNull;
	}
	bool GetIsNull() const
	{
		return m_IsNull;
	}

};
//ItemObj封装类
class ItemObjWraper
{
public:
	//构造函数
	ItemObjWraper()
	{
		
		m_Pos = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	ItemObjWraper(const ItemObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemObj ToPB() const
	{
		ItemObj v;
		v.set_pos( m_Pos );
		*v.mutable_itemdata()= m_ItemData.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ItemObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemObj& v)
	{
		m_Pos = v.pos();
		m_ItemData = v.itemdata();

	}

private:
	//Pos
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//ItemData
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//ChatInfo封装类
class ChatInfoWraper
{
public:
	//构造函数
	ChatInfoWraper()
	{
		
		m_Player_name = "";
		m_Player_guid = 0;
		m_Avatar_id = -1;
		m_Avatar_frame_id = -1;
		m_Config_id = -1;
		m_Timestamp = 0;
		m_Chat_msg = ChatMsgWraper();

	}
	//赋值构造函数
	ChatInfoWraper(const ChatInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatInfo ToPB() const
	{
		ChatInfo v;
		v.set_player_name( m_Player_name );
		v.set_player_guid( m_Player_guid );
		v.set_avatar_id( m_Avatar_id );
		v.set_avatar_frame_id( m_Avatar_frame_id );
		v.set_config_id( m_Config_id );
		v.set_timestamp( m_Timestamp );
		*v.mutable_chat_msg()= m_Chat_msg.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ChatInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatInfo& v)
	{
		m_Player_name = v.player_name();
		m_Player_guid = v.player_guid();
		m_Avatar_id = v.avatar_id();
		m_Avatar_frame_id = v.avatar_frame_id();
		m_Config_id = v.config_id();
		m_Timestamp = v.timestamp();
		m_Chat_msg = v.chat_msg();

	}

private:
	//玩家名字
	string m_Player_name;
public:
	void SetPlayer_name( const string& v)
	{
		m_Player_name=v;
	}
	string GetPlayer_name()
	{
		return m_Player_name;
	}
	string GetPlayer_name() const
	{
		return m_Player_name;
	}
private:
	//玩家GUID
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}
private:
	//头像ID
	INT32 m_Avatar_id;
public:
	void SetAvatar_id( INT32 v)
	{
		m_Avatar_id=v;
	}
	INT32 GetAvatar_id()
	{
		return m_Avatar_id;
	}
	INT32 GetAvatar_id() const
	{
		return m_Avatar_id;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id;
public:
	void SetAvatar_frame_id( INT32 v)
	{
		m_Avatar_frame_id=v;
	}
	INT32 GetAvatar_frame_id()
	{
		return m_Avatar_frame_id;
	}
	INT32 GetAvatar_frame_id() const
	{
		return m_Avatar_frame_id;
	}
private:
	//角色配置ID
	INT32 m_Config_id;
public:
	void SetConfig_id( INT32 v)
	{
		m_Config_id=v;
	}
	INT32 GetConfig_id()
	{
		return m_Config_id;
	}
	INT32 GetConfig_id() const
	{
		return m_Config_id;
	}
private:
	//时间戳
	uint64_t m_Timestamp;
public:
	void SetTimestamp( uint64_t v)
	{
		m_Timestamp=v;
	}
	uint64_t GetTimestamp()
	{
		return m_Timestamp;
	}
	uint64_t GetTimestamp() const
	{
		return m_Timestamp;
	}
private:
	//聊天消息
	ChatMsgWraper m_Chat_msg;
public:
	void SetChat_msg( const ChatMsgWraper& v)
	{
		m_Chat_msg=v;
	}
	ChatMsgWraper GetChat_msg()
	{
		return m_Chat_msg;
	}
	ChatMsgWraper GetChat_msg() const
	{
		return m_Chat_msg;
	}

};
//TeamMemberInfo封装类
class TeamMemberInfoWraper
{
public:
	//构造函数
	TeamMemberInfoWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;
		m_Level = -1;
		m_Name = "";
		m_ConfigId = -1;
		m_Hp = -1;
		m_Mp = -1;
		m_Status = -1;
		m_MemId = -1;
		m_MaxHp = -1;
		m_MaxMp = -1;

	}
	//赋值构造函数
	TeamMemberInfoWraper(const TeamMemberInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberInfo ToPB() const
	{
		TeamMemberInfo v;
		v.set_roleid( m_RoleId );
		v.set_sceneid( m_SceneId );
		v.set_level( m_Level );
		v.set_name( m_Name );
		v.set_configid( m_ConfigId );
		v.set_hp( m_Hp );
		v.set_mp( m_Mp );
		v.set_status( m_Status );
		v.set_memid( m_MemId );
		v.set_maxhp( m_MaxHp );
		v.set_maxmp( m_MaxMp );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		TeamMemberInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamMemberInfo& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();
		m_Level = v.level();
		m_Name = v.name();
		m_ConfigId = v.configid();
		m_Hp = v.hp();
		m_Mp = v.mp();
		m_Status = v.status();
		m_MemId = v.memid();
		m_MaxHp = v.maxhp();
		m_MaxMp = v.maxmp();

	}

private:
	//队员RoleId
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//队员场景id
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//队员等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//name
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//configid
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//生命值
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//Mp
	INT32 m_Mp;
public:
	void SetMp( INT32 v)
	{
		m_Mp=v;
	}
	INT32 GetMp()
	{
		return m_Mp;
	}
	INT32 GetMp() const
	{
		return m_Mp;
	}
private:
	//Status
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//生命值
	INT64 m_MaxHp;
public:
	void SetMaxHp( INT64 v)
	{
		m_MaxHp=v;
	}
	INT64 GetMaxHp()
	{
		return m_MaxHp;
	}
	INT64 GetMaxHp() const
	{
		return m_MaxHp;
	}
private:
	//生命值
	INT64 m_MaxMp;
public:
	void SetMaxMp( INT64 v)
	{
		m_MaxMp=v;
	}
	INT64 GetMaxMp()
	{
		return m_MaxMp;
	}
	INT64 GetMaxMp() const
	{
		return m_MaxMp;
	}

};
//ChatChannelData封装类
class ChatChannelDataWraper
{
public:
	//构造函数
	ChatChannelDataWraper()
	{
		
		m_Chat_channel = -1;

	}
	//赋值构造函数
	ChatChannelDataWraper(const ChatChannelData& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatChannelData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatChannelData ToPB() const
	{
		ChatChannelData v;
		v.set_chat_channel( m_Chat_channel );
		v.mutable_chat_infos()->Reserve(m_Chat_infos.size());
		for (int i=0; i<(int)m_Chat_infos.size(); i++)
		{
			*v.add_chat_infos() = m_Chat_infos[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ChatChannelData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatChannelData& v)
	{
		m_Chat_channel = v.chat_channel();
		m_Chat_infos.clear();
		m_Chat_infos.reserve(v.chat_infos_size());
		for( int i=0; i<v.chat_infos_size(); i++)
			m_Chat_infos.push_back(v.chat_infos(i));

	}

private:
	//聊天频道
	INT32 m_Chat_channel;
public:
	void SetChat_channel( INT32 v)
	{
		m_Chat_channel=v;
	}
	INT32 GetChat_channel()
	{
		return m_Chat_channel;
	}
	INT32 GetChat_channel() const
	{
		return m_Chat_channel;
	}
private:
	//聊天消息列表
	vector<ChatInfoWraper> m_Chat_infos;
public:
	int SizeChat_infos()
	{
		return m_Chat_infos.size();
	}
	const vector<ChatInfoWraper>& GetChat_infos() const
	{
		return m_Chat_infos;
	}
	ChatInfoWraper GetChat_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Chat_infos.size())
		{
			assert(false);
			return ChatInfoWraper();
		}
		return m_Chat_infos[Index];
	}
	void SetChat_infos( const vector<ChatInfoWraper>& v )
	{
		m_Chat_infos=v;
	}
	void ClearChat_infos( )
	{
		m_Chat_infos.clear();
	}
	void SetChat_infos( int Index, const ChatInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Chat_infos.size())
		{
			assert(false);
			return;
		}
		m_Chat_infos[Index] = v;
	}
	void AddChat_infos( const ChatInfoWraper& v )
	{
		m_Chat_infos.push_back(v);
	}

};
//BagData封装类
class BagDataWraper
{
public:
	//构造函数
	BagDataWraper()
	{
		
		m_BagType = -1;
		m_CurCapacity = -1;

	}
	//赋值构造函数
	BagDataWraper(const BagData& v){ Init(v); }
	//等号重载函数
	void operator = (const BagData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagData ToPB() const
	{
		BagData v;
		v.mutable_items()->Reserve(m_Items.size());
		for (int i=0; i<(int)m_Items.size(); i++)
		{
			*v.add_items() = m_Items[i].ToPB();
		}
		v.set_bagtype( m_BagType );
		v.set_curcapacity( m_CurCapacity );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BagData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BagData& v)
	{
		m_Items.clear();
		m_Items.reserve(v.items_size());
		for( int i=0; i<v.items_size(); i++)
			m_Items.push_back(v.items(i));
		m_BagType = v.bagtype();
		m_CurCapacity = v.curcapacity();

	}

private:
	//物品列表
	vector<ItemObjWraper> m_Items;
public:
	int SizeItems()
	{
		return m_Items.size();
	}
	const vector<ItemObjWraper>& GetItems() const
	{
		return m_Items;
	}
	ItemObjWraper GetItems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_Items[Index];
	}
	void SetItems( const vector<ItemObjWraper>& v )
	{
		m_Items=v;
	}
	void ClearItems( )
	{
		m_Items.clear();
	}
	void SetItems( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return;
		}
		m_Items[Index] = v;
	}
	void AddItems( const ItemObjWraper& v )
	{
		m_Items.push_back(v);
	}
private:
	//背包类型:0背包,1仓库,2临时背包
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}
private:
	//当前的容量
	INT32 m_CurCapacity;
public:
	void SetCurCapacity( INT32 v)
	{
		m_CurCapacity=v;
	}
	INT32 GetCurCapacity()
	{
		return m_CurCapacity;
	}
	INT32 GetCurCapacity() const
	{
		return m_CurCapacity;
	}

};
//TeamInfo封装类
class TeamInfoWraper
{
public:
	//构造函数
	TeamInfoWraper()
	{
		
		m_LeaderRoleId = 0;
		m_TeamId = -1;
		m_TeamType = -1;

	}
	//赋值构造函数
	TeamInfoWraper(const TeamInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamInfo ToPB() const
	{
		TeamInfo v;
		v.mutable_members()->Reserve(m_Members.size());
		for (int i=0; i<(int)m_Members.size(); i++)
		{
			*v.add_members() = m_Members[i].ToPB();
		}
		v.set_leaderroleid( m_LeaderRoleId );
		v.set_teamid( m_TeamId );
		v.set_teamtype( m_TeamType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		TeamInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamInfo& v)
	{
		m_Members.clear();
		m_Members.reserve(v.members_size());
		for( int i=0; i<v.members_size(); i++)
			m_Members.push_back(v.members(i));
		m_LeaderRoleId = v.leaderroleid();
		m_TeamId = v.teamid();
		m_TeamType = v.teamtype();

	}

private:
	//Members
	vector<TeamMemberInfoWraper> m_Members;
public:
	int SizeMembers()
	{
		return m_Members.size();
	}
	const vector<TeamMemberInfoWraper>& GetMembers() const
	{
		return m_Members;
	}
	TeamMemberInfoWraper GetMembers(int Index) const
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return TeamMemberInfoWraper();
		}
		return m_Members[Index];
	}
	void SetMembers( const vector<TeamMemberInfoWraper>& v )
	{
		m_Members=v;
	}
	void ClearMembers( )
	{
		m_Members.clear();
	}
	void SetMembers( int Index, const TeamMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return;
		}
		m_Members[Index] = v;
	}
	void AddMembers( const TeamMemberInfoWraper& v )
	{
		m_Members.push_back(v);
	}
private:
	//LeaderRoleId
	uint64_t m_LeaderRoleId;
public:
	void SetLeaderRoleId( uint64_t v)
	{
		m_LeaderRoleId=v;
	}
	uint64_t GetLeaderRoleId()
	{
		return m_LeaderRoleId;
	}
	uint64_t GetLeaderRoleId() const
	{
		return m_LeaderRoleId;
	}
private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//TeamType
	INT32 m_TeamType;
public:
	void SetTeamType( INT32 v)
	{
		m_TeamType=v;
	}
	INT32 GetTeamType()
	{
		return m_TeamType;
	}
	INT32 GetTeamType() const
	{
		return m_TeamType;
	}

};
//v3封装类
class V3Wraper
{
public:
	//构造函数
	V3Wraper()
	{
		
		m_X = -1;
		m_Y = -1;
		m_Z = -1;

	}
	//赋值构造函数
	V3Wraper(const V3& v){ Init(v); }
	//等号重载函数
	void operator = (const V3& v){ Init(v); }
 	//转化成Protobuffer类型函数
	V3 ToPB() const
	{
		V3 v;
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		V3 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const V3& v)
	{
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();

	}

private:
	//x
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}
private:
	//z
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//角色信息封装类
class CharacterInfoWraper
{
public:
	//构造函数
	CharacterInfoWraper()
	{
		
		m_RoleId = 0;
		m_Nickname = "";
		m_ConfigId = -1;
		m_Hp = -1;
		m_HpMax = -1;
		m_Level = -1;

	}
	//赋值构造函数
	CharacterInfoWraper(const CharacterInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const CharacterInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CharacterInfo ToPB() const
	{
		CharacterInfo v;
		v.set_roleid( m_RoleId );
		v.set_nickname( m_Nickname );
		v.set_configid( m_ConfigId );
		v.set_hp( m_Hp );
		v.set_hpmax( m_HpMax );
		v.set_level( m_Level );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		CharacterInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CharacterInfo& v)
	{
		m_RoleId = v.roleid();
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();
		m_Hp = v.hp();
		m_HpMax = v.hpmax();
		m_Level = v.level();

	}

private:
	//roleID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//昵称
	string m_Nickname;
public:
	void SetNickname( const string& v)
	{
		m_Nickname=v;
	}
	string GetNickname()
	{
		return m_Nickname;
	}
	string GetNickname() const
	{
		return m_Nickname;
	}
private:
	//配置表id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//血量
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//血量上限
	INT32 m_HpMax;
public:
	void SetHpMax( INT32 v)
	{
		m_HpMax=v;
	}
	INT32 GetHpMax()
	{
		return m_HpMax;
	}
	INT32 GetHpMax() const
	{
		return m_HpMax;
	}
private:
	//Level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}

};
//OnlineUserInfo封装类
class OnlineUserInfoWraper
{
public:
	//构造函数
	OnlineUserInfoWraper()
	{
		
		m_RoleId = 0;
		m_Level = -1;
		m_Scene_id = -1;
		m_Memid = -1;

	}
	//赋值构造函数
	OnlineUserInfoWraper(const OnlineUserInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const OnlineUserInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OnlineUserInfo ToPB() const
	{
		OnlineUserInfo v;
		v.set_roleid( m_RoleId );
		v.set_level( m_Level );
		v.set_scene_id( m_Scene_id );
		v.set_memid( m_Memid );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		OnlineUserInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const OnlineUserInfo& v)
	{
		m_RoleId = v.roleid();
		m_Level = v.level();
		m_Scene_id = v.scene_id();
		m_Memid = v.memid();

	}

private:
	//RoleId
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//scene_id
	INT32 m_Scene_id;
public:
	void SetScene_id( INT32 v)
	{
		m_Scene_id=v;
	}
	INT32 GetScene_id()
	{
		return m_Scene_id;
	}
	INT32 GetScene_id() const
	{
		return m_Scene_id;
	}
private:
	//Memid
	INT32 m_Memid;
public:
	void SetMemid( INT32 v)
	{
		m_Memid=v;
	}
	INT32 GetMemid()
	{
		return m_Memid;
	}
	INT32 GetMemid() const
	{
		return m_Memid;
	}

};

#endif
