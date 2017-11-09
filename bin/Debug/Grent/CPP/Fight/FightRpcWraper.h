/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperFight.h
* Author:       郭晓波
* Description:  战斗RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_FIGHT_H
#define __RPC_WRAPER_FIGHT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "FightRpc.pb.h"



//战斗类的枚举定义
enum ConstFightE
{
	MODULE_ID_FIGHT                              = 9,	//战斗模块ID
	RPC_CODE_FIGHT_USESKILLACTION_NOTIFY         = 951,	//战斗-->使用技能动作-->通知


};


//使用技能动作通知封装类
class FightRpcUseSkillActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcUseSkillActionNotifyWraper()
	{
		
		m_ObjTargetId = -1;
		m_SkillId = -1;
		m_X = -1;
		m_Y = -1;
		m_Dir = -1;

	}
	//赋值构造函数
	FightRpcUseSkillActionNotifyWraper(const FightRpcUseSkillActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseSkillActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseSkillActionNotify ToPB() const
	{
		FightRpcUseSkillActionNotify v;
		v.set_objtargetid( m_ObjTargetId );
		v.set_skillid( m_SkillId );
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_dir( m_Dir );

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
		FightRpcUseSkillActionNotify pb;
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
	void Init(const FightRpcUseSkillActionNotify& v)
	{
		m_ObjTargetId = v.objtargetid();
		m_SkillId = v.skillid();
		m_X = v.x();
		m_Y = v.y();
		m_Dir = v.dir();

	}

private:
	//objId
	INT32 m_ObjTargetId;
public:
	void SetObjTargetId( INT32 v)
	{
		m_ObjTargetId=v;
	}
	INT32 GetObjTargetId()
	{
		return m_ObjTargetId;
	}
	INT32 GetObjTargetId() const
	{
		return m_ObjTargetId;
	}
private:
	//技能id
	INT32 m_SkillId;
public:
	void SetSkillId( INT32 v)
	{
		m_SkillId=v;
	}
	INT32 GetSkillId()
	{
		return m_SkillId;
	}
	INT32 GetSkillId() const
	{
		return m_SkillId;
	}
private:
	//技能释放目标点
	INT32 m_X;
public:
	void SetX( INT32 v)
	{
		m_X=v;
	}
	INT32 GetX()
	{
		return m_X;
	}
	INT32 GetX() const
	{
		return m_X;
	}
private:
	//技能释放目标点
	INT32 m_Y;
public:
	void SetY( INT32 v)
	{
		m_Y=v;
	}
	INT32 GetY()
	{
		return m_Y;
	}
	INT32 GetY() const
	{
		return m_Y;
	}
private:
	//技能释放方向
	INT32 m_Dir;
public:
	void SetDir( INT32 v)
	{
		m_Dir=v;
	}
	INT32 GetDir()
	{
		return m_Dir;
	}
	INT32 GetDir() const
	{
		return m_Dir;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FightRpcUseSkillActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_USESKILLACTION_NOTIFY};};


#endif
