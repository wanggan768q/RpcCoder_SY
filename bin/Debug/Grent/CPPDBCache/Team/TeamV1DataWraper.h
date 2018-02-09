/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     SyncWraperTeam.h
* Author:       郭晓波
* Description:  Team同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TEAM_H
#define __SYNC_WRAPER_TEAM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TeamV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//Member封装类
class TeamMemberWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TeamMemberWraperV1>
{
public:
	//构造函数
	TeamMemberWraperV1()
	{
		SetDataWraper( this );

		m_RoleId = 0;
		m_SceneId = -1;
		m_Level = -1;
		m_Name = "";
		m_ConfigId = -1;
		m_Hp = -1;
		m_Mp = -1;
		m_Status = -1;

	}
	//赋值构造函数
	TeamMemberWraperV1(const TeamMemberV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberV1 ToPB() const
	{
		TeamMemberV1 v;
		v.set_roleid( m_RoleId );
		v.set_sceneid( m_SceneId );
		v.set_level( m_Level );
		v.set_name( m_Name );
		v.set_configid( m_ConfigId );
		v.set_hp( m_Hp );
		v.set_mp( m_Mp );
		v.set_status( m_Status );

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
		TeamMemberV1 pb;
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
	void Init(const TeamMemberV1& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();
		m_Level = v.level();
		m_Name = v.name();
		m_ConfigId = v.configid();
		m_Hp = v.hp();
		m_Mp = v.mp();
		m_Status = v.status();

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

};

#endif
