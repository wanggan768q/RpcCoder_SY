/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     SyncWraperBaseAttr.h
* Author:       郭晓波
* Description:  基础数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_BASEATTR_H
#define __SYNC_WRAPER_BASEATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "BaseAttrV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//玩家基础数据封装类
class BaseAttrUserDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<BaseAttrUserDataWraperV1>
{
public:
	//构造函数
	BaseAttrUserDataWraperV1()
	{
		SetDataWraper( this );

		m_Exp = -1;
		m_Level = -1;
		m_ServerTime = -1;
		m_RoleId = -1;

	}
	//赋值构造函数
	BaseAttrUserDataWraperV1(const BaseAttrUserDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrUserDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrUserDataV1 ToPB() const
	{
		BaseAttrUserDataV1 v;
		v.set_exp( m_Exp );
		v.set_level( m_Level );
		v.set_servertime( m_ServerTime );
		v.set_roleid( m_RoleId );

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
		BaseAttrUserDataV1 pb;
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
	void Init(const BaseAttrUserDataV1& v)
	{
		m_Exp = v.exp();
		m_Level = v.level();
		m_ServerTime = v.servertime();
		m_RoleId = v.roleid();

	}

private:
	//经验
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//玩家等级
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
	//服务器时间
	INT32 m_ServerTime;
public:
	void SetServerTime( INT32 v)
	{
		m_ServerTime=v;
	}
	INT32 GetServerTime()
	{
		return m_ServerTime;
	}
	INT32 GetServerTime() const
	{
		return m_ServerTime;
	}
private:
	//人物唯一ID
	INT32 m_RoleId;
public:
	void SetRoleId( INT32 v)
	{
		m_RoleId=v;
	}
	INT32 GetRoleId()
	{
		return m_RoleId;
	}
	INT32 GetRoleId() const
	{
		return m_RoleId;
	}

};

#endif
