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



//v3封装类
class V3Wraper : public DataWraperInterface 
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

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


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
class CharacterInfoWraper : public DataWraperInterface 
{
public:
	//构造函数
	CharacterInfoWraper()
	{
		
		m_RoleId = 0;
		m_Nickname = "";
		m_ConfigId = -1;

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

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const CharacterInfo& v)
	{
		m_RoleId = v.roleid();
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();

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

};

#endif
