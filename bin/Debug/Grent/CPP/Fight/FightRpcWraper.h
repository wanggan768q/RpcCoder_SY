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
	RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY          = 952,	//战斗-->显示经验-->通知
	RPC_CODE_FIGHT_BUFFACTION_NOTIFY             = 953,	//战斗-->buf-->通知
	RPC_CODE_FIGHT_STATEACTION_NOTIFY            = 954,	//战斗-->状态事件-->通知
	RPC_CODE_FIGHT_REVIVEACTION_NOTIFY           = 955,	//战斗-->复活事件-->通知
	RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY       = 956,	//战斗-->连击技能-->通知
	RPC_CODE_FIGHT_DROPACTION_NOTIFY             = 957,	//战斗-->掉落-->通知
	RPC_CODE_FIGHT_USEITEMACTION_NOTIFY          = 958,	//战斗-->使用道具-->通知
	RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY         = 959,	//战斗-->血量改变-->通知
	RPC_CODE_FIGHT_USESKILL_REQUEST              = 960,	//战斗-->使用技能请求-->请求
	RPC_CODE_FIGHT_HURTACTION_NOTIFY             = 961,	//战斗-->伤害事件-->通知


};


//血量改变通知封装类
class FightRpcHpChangeActionNotifyWraper
{
public:
	//构造函数
	FightRpcHpChangeActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_CurHp = -1;
		m_MaxHp = -1;

	}
	//赋值构造函数
	FightRpcHpChangeActionNotifyWraper(const FightRpcHpChangeActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcHpChangeActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcHpChangeActionNotify ToPB() const
	{
		FightRpcHpChangeActionNotify v;
		v.set_objid( m_ObjId );
		v.set_curhp( m_CurHp );
		v.set_maxhp( m_MaxHp );

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
		FightRpcHpChangeActionNotify pb;
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
	void Init(const FightRpcHpChangeActionNotify& v)
	{
		m_ObjId = v.objid();
		m_CurHp = v.curhp();
		m_MaxHp = v.maxhp();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//当前血
	INT32 m_CurHp;
public:
	void SetCurHp( INT32 v)
	{
		m_CurHp=v;
	}
	INT32 GetCurHp()
	{
		return m_CurHp;
	}
	INT32 GetCurHp() const
	{
		return m_CurHp;
	}
private:
	//最大血
	INT32 m_MaxHp;
public:
	void SetMaxHp( INT32 v)
	{
		m_MaxHp=v;
	}
	INT32 GetMaxHp()
	{
		return m_MaxHp;
	}
	INT32 GetMaxHp() const
	{
		return m_MaxHp;
	}

};
//使用道具通知封装类
class FightRpcUseItemActionNotifyWraper
{
public:
	//构造函数
	FightRpcUseItemActionNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcUseItemActionNotifyWraper(const FightRpcUseItemActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseItemActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseItemActionNotify ToPB() const
	{
		FightRpcUseItemActionNotify v;

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
		FightRpcUseItemActionNotify pb;
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
	void Init(const FightRpcUseItemActionNotify& v)
	{

	}


};
//掉落通知封装类
class FightRpcDropActionNotifyWraper
{
public:
	//构造函数
	FightRpcDropActionNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcDropActionNotifyWraper(const FightRpcDropActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcDropActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcDropActionNotify ToPB() const
	{
		FightRpcDropActionNotify v;

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
		FightRpcDropActionNotify pb;
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
	void Init(const FightRpcDropActionNotify& v)
	{

	}


};
//伤害事件通知封装类
class FightRpcHurtActionNotifyWraper
{
public:
	//构造函数
	FightRpcHurtActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SegmentIndex = -1;
		m_SkillId = -1;
		m_TargetObjId = -1;
		m_HurtValue = 0;
		m_IsCritical = false;
		m_Energy = -1;

	}
	//赋值构造函数
	FightRpcHurtActionNotifyWraper(const FightRpcHurtActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcHurtActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcHurtActionNotify ToPB() const
	{
		FightRpcHurtActionNotify v;
		v.set_objid( m_ObjId );
		v.set_segmentindex( m_SegmentIndex );
		v.set_skillid( m_SkillId );
		v.set_targetobjid( m_TargetObjId );
		v.set_hurtvalue( m_HurtValue );
		v.set_iscritical( m_IsCritical );
		v.set_energy( m_Energy );

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
		FightRpcHurtActionNotify pb;
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
	void Init(const FightRpcHurtActionNotify& v)
	{
		m_ObjId = v.objid();
		m_SegmentIndex = v.segmentindex();
		m_SkillId = v.skillid();
		m_TargetObjId = v.targetobjid();
		m_HurtValue = v.hurtvalue();
		m_IsCritical = v.iscritical();
		m_Energy = v.energy();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//伤害阶段
	INT32 m_SegmentIndex;
public:
	void SetSegmentIndex( INT32 v)
	{
		m_SegmentIndex=v;
	}
	INT32 GetSegmentIndex()
	{
		return m_SegmentIndex;
	}
	INT32 GetSegmentIndex() const
	{
		return m_SegmentIndex;
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
	//目标id
	INT32 m_TargetObjId;
public:
	void SetTargetObjId( INT32 v)
	{
		m_TargetObjId=v;
	}
	INT32 GetTargetObjId()
	{
		return m_TargetObjId;
	}
	INT32 GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//伤害的值
	INT32 m_HurtValue;
public:
	void SetHurtValue( INT32 v)
	{
		m_HurtValue=v;
	}
	INT32 GetHurtValue()
	{
		return m_HurtValue;
	}
	INT32 GetHurtValue() const
	{
		return m_HurtValue;
	}
private:
	//是否暴击
	bool m_IsCritical;
public:
	void SetIsCritical( bool v)
	{
		m_IsCritical=v;
	}
	bool GetIsCritical()
	{
		return m_IsCritical;
	}
	bool GetIsCritical() const
	{
		return m_IsCritical;
	}
private:
	//能量
	INT32 m_Energy;
public:
	void SetEnergy( INT32 v)
	{
		m_Energy=v;
	}
	INT32 GetEnergy()
	{
		return m_Energy;
	}
	INT32 GetEnergy() const
	{
		return m_Energy;
	}

};
//使用技能请求回应封装类
class FightRpcUseSkillReplyWraper
{
public:
	//构造函数
	FightRpcUseSkillReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	FightRpcUseSkillReplyWraper(const FightRpcUseSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseSkillReply ToPB() const
	{
		FightRpcUseSkillReply v;
		v.set_result( m_Result );

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
		FightRpcUseSkillReply pb;
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
	void Init(const FightRpcUseSkillReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//使用技能请求请求封装类
class FightRpcUseSkillAskWraper
{
public:
	//构造函数
	FightRpcUseSkillAskWraper()
	{
		
		m_ObjTargetId = -1;
		m_SkillId = -1;
		m_CastingDir = -1;
		m_X = -1;
		m_Y = -1;
		m_Z = -1;
		m_MomentIndex = -1;

	}
	//赋值构造函数
	FightRpcUseSkillAskWraper(const FightRpcUseSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseSkillAsk ToPB() const
	{
		FightRpcUseSkillAsk v;
		v.set_objtargetid( m_ObjTargetId );
		v.set_skillid( m_SkillId );
		v.set_castingdir( m_CastingDir );
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );
		v.set_momentindex( m_MomentIndex );

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
		FightRpcUseSkillAsk pb;
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
	void Init(const FightRpcUseSkillAsk& v)
	{
		m_ObjTargetId = v.objtargetid();
		m_SkillId = v.skillid();
		m_CastingDir = v.castingdir();
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();
		m_MomentIndex = v.momentindex();

	}

private:
	//ObjTargetId
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
	//SkillId
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
	//施法方向
	float m_CastingDir;
public:
	void SetCastingDir( float v)
	{
		m_CastingDir=v;
	}
	float GetCastingDir()
	{
		return m_CastingDir;
	}
	float GetCastingDir() const
	{
		return m_CastingDir;
	}
private:
	//X
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
	//Y
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
	//Z
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
private:
	//技能段数
	INT32 m_MomentIndex;
public:
	void SetMomentIndex( INT32 v)
	{
		m_MomentIndex=v;
	}
	INT32 GetMomentIndex()
	{
		return m_MomentIndex;
	}
	INT32 GetMomentIndex() const
	{
		return m_MomentIndex;
	}

};
//buf通知封装类
class FightRpcBuffActionNotifyWraper
{
public:
	//构造函数
	FightRpcBuffActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_TargetId = -1;
		m_OpType = -1;
		m_BufId = -1;
		m_RemainTime = -1;
		m_BuffLv = -1;
		m_Sn = -1;

	}
	//赋值构造函数
	FightRpcBuffActionNotifyWraper(const FightRpcBuffActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcBuffActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcBuffActionNotify ToPB() const
	{
		FightRpcBuffActionNotify v;
		v.set_objid( m_ObjId );
		v.set_targetid( m_TargetId );
		v.set_optype( m_OpType );
		v.set_bufid( m_BufId );
		v.set_remaintime( m_RemainTime );
		v.set_bufflv( m_BuffLv );
		v.set_sn( m_Sn );

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
		FightRpcBuffActionNotify pb;
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
	void Init(const FightRpcBuffActionNotify& v)
	{
		m_ObjId = v.objid();
		m_TargetId = v.targetid();
		m_OpType = v.optype();
		m_BufId = v.bufid();
		m_RemainTime = v.remaintime();
		m_BuffLv = v.bufflv();
		m_Sn = v.sn();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//目标id
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//操作类型
	INT32 m_OpType;
public:
	void SetOpType( INT32 v)
	{
		m_OpType=v;
	}
	INT32 GetOpType()
	{
		return m_OpType;
	}
	INT32 GetOpType() const
	{
		return m_OpType;
	}
private:
	//bufid
	INT32 m_BufId;
public:
	void SetBufId( INT32 v)
	{
		m_BufId=v;
	}
	INT32 GetBufId()
	{
		return m_BufId;
	}
	INT32 GetBufId() const
	{
		return m_BufId;
	}
private:
	//剩余时间
	INT32 m_RemainTime;
public:
	void SetRemainTime( INT32 v)
	{
		m_RemainTime=v;
	}
	INT32 GetRemainTime()
	{
		return m_RemainTime;
	}
	INT32 GetRemainTime() const
	{
		return m_RemainTime;
	}
private:
	//buf 等级
	INT32 m_BuffLv;
public:
	void SetBuffLv( INT32 v)
	{
		m_BuffLv=v;
	}
	INT32 GetBuffLv()
	{
		return m_BuffLv;
	}
	INT32 GetBuffLv() const
	{
		return m_BuffLv;
	}
private:
	//buff序列号
	INT32 m_Sn;
public:
	void SetSn( INT32 v)
	{
		m_Sn=v;
	}
	INT32 GetSn()
	{
		return m_Sn;
	}
	INT32 GetSn() const
	{
		return m_Sn;
	}

};
//显示经验通知封装类
class FightRpcShowExpActionNotifyWraper
{
public:
	//构造函数
	FightRpcShowExpActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Value = -1;

	}
	//赋值构造函数
	FightRpcShowExpActionNotifyWraper(const FightRpcShowExpActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcShowExpActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcShowExpActionNotify ToPB() const
	{
		FightRpcShowExpActionNotify v;
		v.set_objid( m_ObjId );
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
		FightRpcShowExpActionNotify pb;
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
	void Init(const FightRpcShowExpActionNotify& v)
	{
		m_ObjId = v.objid();
		m_Value = v.value();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//获取到的经验值
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}

};
//使用技能动作通知封装类
class FightRpcUseSkillActionNotifyWraper
{
public:
	//构造函数
	FightRpcUseSkillActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_ObjTargetId = -1;
		m_SkillId = -1;
		m_CastingDir = -1;
		m_X = -1;
		m_Y = -1;
		m_Z = -1;
		m_MomentIndex = -1;

	}
	//赋值构造函数
	FightRpcUseSkillActionNotifyWraper(const FightRpcUseSkillActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseSkillActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseSkillActionNotify ToPB() const
	{
		FightRpcUseSkillActionNotify v;
		v.set_objid( m_ObjId );
		v.set_objtargetid( m_ObjTargetId );
		v.set_skillid( m_SkillId );
		v.set_castingdir( m_CastingDir );
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );
		v.set_momentindex( m_MomentIndex );

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
	void Init(const FightRpcUseSkillActionNotify& v)
	{
		m_ObjId = v.objid();
		m_ObjTargetId = v.objtargetid();
		m_SkillId = v.skillid();
		m_CastingDir = v.castingdir();
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();
		m_MomentIndex = v.momentindex();

	}

private:
	//ObjId
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//ObjTargetId
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
	//SkillId
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
	//施法方向
	float m_CastingDir;
public:
	void SetCastingDir( float v)
	{
		m_CastingDir=v;
	}
	float GetCastingDir()
	{
		return m_CastingDir;
	}
	float GetCastingDir() const
	{
		return m_CastingDir;
	}
private:
	//X
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
	//Y
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
	//Z
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
private:
	//技能段数
	INT32 m_MomentIndex;
public:
	void SetMomentIndex( INT32 v)
	{
		m_MomentIndex=v;
	}
	INT32 GetMomentIndex()
	{
		return m_MomentIndex;
	}
	INT32 GetMomentIndex() const
	{
		return m_MomentIndex;
	}

};
//连击技能通知封装类
class FightRpcComboSkillActionNotifyWraper
{
public:
	//构造函数
	FightRpcComboSkillActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;

	}
	//赋值构造函数
	FightRpcComboSkillActionNotifyWraper(const FightRpcComboSkillActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcComboSkillActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcComboSkillActionNotify ToPB() const
	{
		FightRpcComboSkillActionNotify v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );

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
		FightRpcComboSkillActionNotify pb;
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
	void Init(const FightRpcComboSkillActionNotify& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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

};
//复活事件通知封装类
class FightRpcReviveActionNotifyWraper
{
public:
	//构造函数
	FightRpcReviveActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_CurHp = -1;

	}
	//赋值构造函数
	FightRpcReviveActionNotifyWraper(const FightRpcReviveActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcReviveActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcReviveActionNotify ToPB() const
	{
		FightRpcReviveActionNotify v;
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_curhp( m_CurHp );

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
		FightRpcReviveActionNotify pb;
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
	void Init(const FightRpcReviveActionNotify& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_CurHp = v.curhp();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//复活后的位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//当前血量
	INT32 m_CurHp;
public:
	void SetCurHp( INT32 v)
	{
		m_CurHp=v;
	}
	INT32 GetCurHp()
	{
		return m_CurHp;
	}
	INT32 GetCurHp() const
	{
		return m_CurHp;
	}

};
//状态事件通知封装类
class FightRpcStateActionNotifyWraper
{
public:
	//构造函数
	FightRpcStateActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Type = -1;
		m_Pos = V3Wraper();
		m_TargetPos = -1;

	}
	//赋值构造函数
	FightRpcStateActionNotifyWraper(const FightRpcStateActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcStateActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcStateActionNotify ToPB() const
	{
		FightRpcStateActionNotify v;
		v.set_objid( m_ObjId );
		v.set_type( m_Type );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_targetpos( m_TargetPos );

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
		FightRpcStateActionNotify pb;
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
	void Init(const FightRpcStateActionNotify& v)
	{
		m_ObjId = v.objid();
		m_Type = v.type();
		m_Pos = v.pos();
		m_TargetPos = v.targetpos();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//状态类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//位置信息
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//目标位置信息
	INT32 m_TargetPos;
public:
	void SetTargetPos( INT32 v)
	{
		m_TargetPos=v;
	}
	INT32 GetTargetPos()
	{
		return m_TargetPos;
	}
	INT32 GetTargetPos() const
	{
		return m_TargetPos;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FightRpcUseSkillActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_USESKILLACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcShowExpActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcBuffActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_BUFFACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcStateActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_STATEACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcReviveActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_REVIVEACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcComboSkillActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcDropActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_DROPACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcUseItemActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_USEITEMACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcHpChangeActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcHurtActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_HURTACTION_NOTIFY};};


#endif
