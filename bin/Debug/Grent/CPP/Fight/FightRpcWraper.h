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
	RPC_CODE_FIGHT_REPELACTION_NOTIFY            = 962,	//战斗-->战斗击 退、飞、撞、拉 通知-->通知
	RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY          = 963,	//战斗-->obj死亡通知-->通知
	RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY              = 964,	//战斗-->战斗辅助tips-->通知
	RPC_CODE_FIGHT_BUFFLIST_NOTIFY               = 965,	//战斗-->BuffList-->通知
	RPC_CODE_FIGHT_REDUCECD_NOTIFY               = 966,	//战斗-->减少cd-->通知
	RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY           = 967,	//战斗-->复活通知-->通知
	RPC_CODE_FIGHT_SKILLCD_NOTIFY                = 968,	//战斗-->技能同步cd-->通知
	RPC_CODE_FIGHT_AUTOCOMBATMONSTER_NOTIFY      = 969,	//战斗-->自动杀怪-->通知
	RPC_CODE_FIGHT_TRANSLATEACTION_NOTIFY        = 970,	//战斗-->战斗位移-->通知
	RPC_CODE_FIGHT_CANTADDBUFFTIP_NOTIFY         = 971,	//战斗-->添加buff失败提示-->通知
	RPC_CODE_FIGHT_ATTACKWARNING_NOTIFY          = 972,	//战斗-->生成预警圈-->通知
	RPC_CODE_FIGHT_INTERRUPTACTION_NOTIFY        = 973,	//战斗-->技能打断事件-->通知
	RPC_CODE_FIGHT_SKILLPREPARE_REQUEST          = 974,	//战斗-->技能蓄力请求-->请求
	RPC_CODE_FIGHT_SKILLPREPAREACTION_NOTIFY     = 975,	//战斗-->蓄力技能通知-->通知
	RPC_CODE_FIGHT_CHAINMAGICJUMP_NOTIFY         = 976,	//战斗-->链式法术跳跃-->通知
	RPC_CODE_FIGHT_BLACKHOLEACTION_NOTIFY        = 977,	//战斗-->黑洞拉拽效果-->通知
	RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST      = 978,	//战斗-->循环动作取消-->请求
	RPC_CODE_FIGHT_LOOPACTIONCANCELOTHER_NOTIFY  = 979,	//战斗-->循环动作取消广播-->通知
	RPC_CODE_FIGHT_SKILLLIST_NOTIFY              = 980,	//战斗-->SkillList-->通知
	RPC_CODE_FIGHT_USEPETSKILL_REQUEST           = 981,	//战斗-->使用宠物技能-->请求
	RPC_CODE_FIGHT_REMOVEMODIFYSKILL_NOTIFY      = 982,	//战斗-->RemoveModifySkill-->通知
	RPC_CODE_FIGHT_LINKMAGICACTION_NOTIFY        = 983,	//战斗-->链接magic效果-->通知
	RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST       = 984,	//战斗-->怪物交互-->请求


};


//蓄力技能通知通知封装类
class FightRpcSkillPrepareActionNotifyWraper
{
public:
	//构造函数
	FightRpcSkillPrepareActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_Type = -1;

	}
	//赋值构造函数
	FightRpcSkillPrepareActionNotifyWraper(const FightRpcSkillPrepareActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcSkillPrepareActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcSkillPrepareActionNotify ToPB() const
	{
		FightRpcSkillPrepareActionNotify v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_type( m_Type );

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
		FightRpcSkillPrepareActionNotify pb;
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
	void Init(const FightRpcSkillPrepareActionNotify& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_Type = v.type();

	}

private:
	//ObjId
	int64_t m_ObjId;
public:
	void SetObjId( int64_t v)
	{
		m_ObjId=v;
	}
	int64_t GetObjId()
	{
		return m_ObjId;
	}
	int64_t GetObjId() const
	{
		return m_ObjId;
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
	//Type
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

};
//技能蓄力请求回应封装类
class FightRpcSkillPrepareReplyWraper
{
public:
	//构造函数
	FightRpcSkillPrepareReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightRpcSkillPrepareReplyWraper(const FightRpcSkillPrepareReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcSkillPrepareReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcSkillPrepareReply ToPB() const
	{
		FightRpcSkillPrepareReply v;
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
		FightRpcSkillPrepareReply pb;
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
	void Init(const FightRpcSkillPrepareReply& v)
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
//黑洞拉拽效果通知封装类
class FightRpcBlackHoleActionNotifyWraper
{
public:
	//构造函数
	FightRpcBlackHoleActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_ToX = -1;
		m_ToZ = -1;
		m_Speed = -1;
		m_Apply = false;
		m_Type = -1;
		m_TargetObjId = 0;

	}
	//赋值构造函数
	FightRpcBlackHoleActionNotifyWraper(const FightRpcBlackHoleActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcBlackHoleActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcBlackHoleActionNotify ToPB() const
	{
		FightRpcBlackHoleActionNotify v;
		v.set_objid( m_ObjId );
		v.set_tox( m_ToX );
		v.set_toz( m_ToZ );
		v.set_speed( m_Speed );
		v.set_apply( m_Apply );
		v.set_type( m_Type );
		v.set_targetobjid( m_TargetObjId );

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
		FightRpcBlackHoleActionNotify pb;
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
	void Init(const FightRpcBlackHoleActionNotify& v)
	{
		m_ObjId = v.objid();
		m_ToX = v.tox();
		m_ToZ = v.toz();
		m_Speed = v.speed();
		m_Apply = v.apply();
		m_Type = v.type();
		m_TargetObjId = v.targetobjid();

	}

private:
	//ObjId
	int64_t m_ObjId;
public:
	void SetObjId( int64_t v)
	{
		m_ObjId=v;
	}
	int64_t GetObjId()
	{
		return m_ObjId;
	}
	int64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//目标点x
	float m_ToX;
public:
	void SetToX( float v)
	{
		m_ToX=v;
	}
	float GetToX()
	{
		return m_ToX;
	}
	float GetToX() const
	{
		return m_ToX;
	}
private:
	//目标坐标z
	float m_ToZ;
public:
	void SetToZ( float v)
	{
		m_ToZ=v;
	}
	float GetToZ()
	{
		return m_ToZ;
	}
	float GetToZ() const
	{
		return m_ToZ;
	}
private:
	//速度
	float m_Speed;
public:
	void SetSpeed( float v)
	{
		m_Speed=v;
	}
	float GetSpeed()
	{
		return m_Speed;
	}
	float GetSpeed() const
	{
		return m_Speed;
	}
private:
	//true=开始 false=结束
	bool m_Apply;
public:
	void SetApply( bool v)
	{
		m_Apply=v;
	}
	bool GetApply()
	{
		return m_Apply;
	}
	bool GetApply() const
	{
		return m_Apply;
	}
private:
	//0=拉 1=推
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
	//目标ID
	uint64_t m_TargetObjId;
public:
	void SetTargetObjId( uint64_t v)
	{
		m_TargetObjId=v;
	}
	uint64_t GetTargetObjId()
	{
		return m_TargetObjId;
	}
	uint64_t GetTargetObjId() const
	{
		return m_TargetObjId;
	}

};
//链式法术跳跃通知封装类
class FightRpcChainMagicJumpNotifyWraper
{
public:
	//构造函数
	FightRpcChainMagicJumpNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SkillId = -1;
		m_JumpFromObjId = -1;
		m_JumpToObjId = -1;
		m_AttackId = -1;

	}
	//赋值构造函数
	FightRpcChainMagicJumpNotifyWraper(const FightRpcChainMagicJumpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcChainMagicJumpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcChainMagicJumpNotify ToPB() const
	{
		FightRpcChainMagicJumpNotify v;
		v.set_objid( m_ObjId );
		v.set_skillid( m_SkillId );
		v.set_jumpfromobjid( m_JumpFromObjId );
		v.set_jumptoobjid( m_JumpToObjId );
		v.set_attackid( m_AttackId );

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
		FightRpcChainMagicJumpNotify pb;
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
	void Init(const FightRpcChainMagicJumpNotify& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();
		m_JumpFromObjId = v.jumpfromobjid();
		m_JumpToObjId = v.jumptoobjid();
		m_AttackId = v.attackid();

	}

private:
	//ObjId
	int64_t m_ObjId;
public:
	void SetObjId( int64_t v)
	{
		m_ObjId=v;
	}
	int64_t GetObjId()
	{
		return m_ObjId;
	}
	int64_t GetObjId() const
	{
		return m_ObjId;
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
	//起始ObjId
	int64_t m_JumpFromObjId;
public:
	void SetJumpFromObjId( int64_t v)
	{
		m_JumpFromObjId=v;
	}
	int64_t GetJumpFromObjId()
	{
		return m_JumpFromObjId;
	}
	int64_t GetJumpFromObjId() const
	{
		return m_JumpFromObjId;
	}
private:
	//终止ObjId
	int64_t m_JumpToObjId;
public:
	void SetJumpToObjId( int64_t v)
	{
		m_JumpToObjId=v;
	}
	int64_t GetJumpToObjId()
	{
		return m_JumpToObjId;
	}
	int64_t GetJumpToObjId() const
	{
		return m_JumpToObjId;
	}
private:
	//AttackId
	INT32 m_AttackId;
public:
	void SetAttackId( INT32 v)
	{
		m_AttackId=v;
	}
	INT32 GetAttackId()
	{
		return m_AttackId;
	}
	INT32 GetAttackId() const
	{
		return m_AttackId;
	}

};
//技能蓄力请求请求封装类
class FightRpcSkillPrepareAskWraper
{
public:
	//构造函数
	FightRpcSkillPrepareAskWraper()
	{
		
		m_SkillId = -1;
		m_Type = 0;

	}
	//赋值构造函数
	FightRpcSkillPrepareAskWraper(const FightRpcSkillPrepareAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcSkillPrepareAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcSkillPrepareAsk ToPB() const
	{
		FightRpcSkillPrepareAsk v;
		v.set_skillid( m_SkillId );
		v.set_type( m_Type );

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
		FightRpcSkillPrepareAsk pb;
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
	void Init(const FightRpcSkillPrepareAsk& v)
	{
		m_SkillId = v.skillid();
		m_Type = v.type();

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
	//Type
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

};
//添加buff失败提示通知封装类
class FightRpcCantAddBuffTipNotifyWraper
{
public:
	//构造函数
	FightRpcCantAddBuffTipNotifyWraper()
	{
		
		m_BuffId = -1;
		m_CasterId = 0;
		m_ObjId = 0;
		m_Sn = -1;

	}
	//赋值构造函数
	FightRpcCantAddBuffTipNotifyWraper(const FightRpcCantAddBuffTipNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcCantAddBuffTipNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcCantAddBuffTipNotify ToPB() const
	{
		FightRpcCantAddBuffTipNotify v;
		v.set_buffid( m_BuffId );
		v.set_casterid( m_CasterId );
		v.set_objid( m_ObjId );
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
		FightRpcCantAddBuffTipNotify pb;
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
	void Init(const FightRpcCantAddBuffTipNotify& v)
	{
		m_BuffId = v.buffid();
		m_CasterId = v.casterid();
		m_ObjId = v.objid();
		m_Sn = v.sn();

	}

private:
	//buffId
	INT32 m_BuffId;
public:
	void SetBuffId( INT32 v)
	{
		m_BuffId=v;
	}
	INT32 GetBuffId()
	{
		return m_BuffId;
	}
	INT32 GetBuffId() const
	{
		return m_BuffId;
	}
private:
	//Buff释放者ID
	uint64_t m_CasterId;
public:
	void SetCasterId( uint64_t v)
	{
		m_CasterId=v;
	}
	uint64_t GetCasterId()
	{
		return m_CasterId;
	}
	uint64_t GetCasterId() const
	{
		return m_CasterId;
	}
private:
	//buff接收者id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
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
//战斗位移通知封装类
class FightRpcTranslateActionNotifyWraper
{
public:
	//构造函数
	FightRpcTranslateActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_TargetPos = Vector3Wraper();
		m_Dir = -1;
		m_SkillId = -1;
		m_CommandIndex = -1;
		m_IsEnd = false;
		m_Speed = 0;

	}
	//赋值构造函数
	FightRpcTranslateActionNotifyWraper(const FightRpcTranslateActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcTranslateActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcTranslateActionNotify ToPB() const
	{
		FightRpcTranslateActionNotify v;
		v.set_objid( m_ObjId );
		*v.mutable_targetpos()= m_TargetPos.ToPB();
		v.set_dir( m_Dir );
		v.set_skillid( m_SkillId );
		v.set_commandindex( m_CommandIndex );
		v.set_isend( m_IsEnd );
		v.set_speed( m_Speed );

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
		FightRpcTranslateActionNotify pb;
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
	void Init(const FightRpcTranslateActionNotify& v)
	{
		m_ObjId = v.objid();
		m_TargetPos = v.targetpos();
		m_Dir = v.dir();
		m_SkillId = v.skillid();
		m_CommandIndex = v.commandindex();
		m_IsEnd = v.isend();
		m_Speed = v.speed();

	}

private:
	//对象GUID
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//目标位置
	Vector3Wraper m_TargetPos;
public:
	void SetTargetPos( const Vector3Wraper& v)
	{
		m_TargetPos=v;
	}
	Vector3Wraper GetTargetPos()
	{
		return m_TargetPos;
	}
	Vector3Wraper GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//位移后朝向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//技能Id
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
	//索引
	INT32 m_CommandIndex;
public:
	void SetCommandIndex( INT32 v)
	{
		m_CommandIndex=v;
	}
	INT32 GetCommandIndex()
	{
		return m_CommandIndex;
	}
	INT32 GetCommandIndex() const
	{
		return m_CommandIndex;
	}
private:
	//是否结束
	bool m_IsEnd;
public:
	void SetIsEnd( bool v)
	{
		m_IsEnd=v;
	}
	bool GetIsEnd()
	{
		return m_IsEnd;
	}
	bool GetIsEnd() const
	{
		return m_IsEnd;
	}
private:
	//位移速度
	float m_Speed;
public:
	void SetSpeed( float v)
	{
		m_Speed=v;
	}
	float GetSpeed()
	{
		return m_Speed;
	}
	float GetSpeed() const
	{
		return m_Speed;
	}

};
//技能打断事件通知封装类
class FightRpcInterruptActionNotifyWraper
{
public:
	//构造函数
	FightRpcInterruptActionNotifyWraper()
	{
		
		m_Caster = 0;
		m_Interrupter = 0;

	}
	//赋值构造函数
	FightRpcInterruptActionNotifyWraper(const FightRpcInterruptActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcInterruptActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcInterruptActionNotify ToPB() const
	{
		FightRpcInterruptActionNotify v;
		v.set_caster( m_Caster );
		v.set_interrupter( m_Interrupter );
		v.mutable_skill()->Reserve(m_Skill.size());
		for (int i=0; i<(int)m_Skill.size(); i++)
		{
			v.add_skill(m_Skill[i]);
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
		FightRpcInterruptActionNotify pb;
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
	void Init(const FightRpcInterruptActionNotify& v)
	{
		m_Caster = v.caster();
		m_Interrupter = v.interrupter();
		m_Skill.clear();
		m_Skill.reserve(v.skill_size());
		for( int i=0; i<v.skill_size(); i++)
			m_Skill.push_back(v.skill(i));

	}

private:
	//技能释放者
	uint64_t m_Caster;
public:
	void SetCaster( uint64_t v)
	{
		m_Caster=v;
	}
	uint64_t GetCaster()
	{
		return m_Caster;
	}
	uint64_t GetCaster() const
	{
		return m_Caster;
	}
private:
	//打断者
	uint64_t m_Interrupter;
public:
	void SetInterrupter( uint64_t v)
	{
		m_Interrupter=v;
	}
	uint64_t GetInterrupter()
	{
		return m_Interrupter;
	}
	uint64_t GetInterrupter() const
	{
		return m_Interrupter;
	}
private:
	//打断技能id
	vector<INT32> m_Skill;
public:
	int SizeSkill()
	{
		return m_Skill.size();
	}
	const vector<INT32>& GetSkill() const
	{
		return m_Skill;
	}
	INT32 GetSkill(int Index) const
	{
		if(Index<0 || Index>=(int)m_Skill.size())
		{
			assert(false);
			return INT32();
		}
		return m_Skill[Index];
	}
	void SetSkill( const vector<INT32>& v )
	{
		m_Skill=v;
	}
	void ClearSkill( )
	{
		m_Skill.clear();
	}
	void SetSkill( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_Skill.size())
		{
			assert(false);
			return;
		}
		m_Skill[Index] = v;
	}
	void AddSkill( INT32 v = -1 )
	{
		m_Skill.push_back(v);
	}

};
//生成预警圈通知封装类
class FightRpcAttackWarningNotifyWraper
{
public:
	//构造函数
	FightRpcAttackWarningNotifyWraper()
	{
		
		m_AttackId = -1;
		m_Caster = 0;
		m_TargetPos = Vector3Wraper();
		m_SkillId = -1;

	}
	//赋值构造函数
	FightRpcAttackWarningNotifyWraper(const FightRpcAttackWarningNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcAttackWarningNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcAttackWarningNotify ToPB() const
	{
		FightRpcAttackWarningNotify v;
		v.set_attackid( m_AttackId );
		v.set_caster( m_Caster );
		v.mutable_targetlist()->Reserve(m_TargetList.size());
		for (int i=0; i<(int)m_TargetList.size(); i++)
		{
			v.add_targetlist(m_TargetList[i]);
		}
		*v.mutable_targetpos()= m_TargetPos.ToPB();
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
		FightRpcAttackWarningNotify pb;
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
	void Init(const FightRpcAttackWarningNotify& v)
	{
		m_AttackId = v.attackid();
		m_Caster = v.caster();
		m_TargetList.clear();
		m_TargetList.reserve(v.targetlist_size());
		for( int i=0; i<v.targetlist_size(); i++)
			m_TargetList.push_back(v.targetlist(i));
		m_TargetPos = v.targetpos();
		m_SkillId = v.skillid();

	}

private:
	//attackID
	INT32 m_AttackId;
public:
	void SetAttackId( INT32 v)
	{
		m_AttackId=v;
	}
	INT32 GetAttackId()
	{
		return m_AttackId;
	}
	INT32 GetAttackId() const
	{
		return m_AttackId;
	}
private:
	//释放者id
	uint64_t m_Caster;
public:
	void SetCaster( uint64_t v)
	{
		m_Caster=v;
	}
	uint64_t GetCaster()
	{
		return m_Caster;
	}
	uint64_t GetCaster() const
	{
		return m_Caster;
	}
private:
	//打击列表
	vector<uint64_t> m_TargetList;
public:
	int SizeTargetList()
	{
		return m_TargetList.size();
	}
	const vector<uint64_t>& GetTargetList() const
	{
		return m_TargetList;
	}
	uint64_t GetTargetList(int Index) const
	{
		if(Index<0 || Index>=(int)m_TargetList.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_TargetList[Index];
	}
	void SetTargetList( const vector<uint64_t>& v )
	{
		m_TargetList=v;
	}
	void ClearTargetList( )
	{
		m_TargetList.clear();
	}
	void SetTargetList( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_TargetList.size())
		{
			assert(false);
			return;
		}
		m_TargetList[Index] = v;
	}
	void AddTargetList( uint64_t v = 0 )
	{
		m_TargetList.push_back(v);
	}
private:
	//attack 目标点
	Vector3Wraper m_TargetPos;
public:
	void SetTargetPos( const Vector3Wraper& v)
	{
		m_TargetPos=v;
	}
	Vector3Wraper GetTargetPos()
	{
		return m_TargetPos;
	}
	Vector3Wraper GetTargetPos() const
	{
		return m_TargetPos;
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
//循环动作取消请求封装类
class FightRpcLoopActionCancelAskWraper
{
public:
	//构造函数
	FightRpcLoopActionCancelAskWraper()
	{
		
		m_SkillId = -1;

	}
	//赋值构造函数
	FightRpcLoopActionCancelAskWraper(const FightRpcLoopActionCancelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcLoopActionCancelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcLoopActionCancelAsk ToPB() const
	{
		FightRpcLoopActionCancelAsk v;
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
		FightRpcLoopActionCancelAsk pb;
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
	void Init(const FightRpcLoopActionCancelAsk& v)
	{
		m_SkillId = v.skillid();

	}

private:
	//技能Id
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
//链接magic效果通知封装类
class FightRpcLinkMagicActionNotifyWraper
{
public:
	//构造函数
	FightRpcLinkMagicActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_LinkerId = 0;
		m_AttackId = -1;

	}
	//赋值构造函数
	FightRpcLinkMagicActionNotifyWraper(const FightRpcLinkMagicActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcLinkMagicActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcLinkMagicActionNotify ToPB() const
	{
		FightRpcLinkMagicActionNotify v;
		v.set_objid( m_ObjId );
		v.set_linkerid( m_LinkerId );
		v.set_attackid( m_AttackId );

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
		FightRpcLinkMagicActionNotify pb;
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
	void Init(const FightRpcLinkMagicActionNotify& v)
	{
		m_ObjId = v.objid();
		m_LinkerId = v.linkerid();
		m_AttackId = v.attackid();

	}

private:
	//objId
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//链接者id
	uint64_t m_LinkerId;
public:
	void SetLinkerId( uint64_t v)
	{
		m_LinkerId=v;
	}
	uint64_t GetLinkerId()
	{
		return m_LinkerId;
	}
	uint64_t GetLinkerId() const
	{
		return m_LinkerId;
	}
private:
	//attackId
	INT32 m_AttackId;
public:
	void SetAttackId( INT32 v)
	{
		m_AttackId=v;
	}
	INT32 GetAttackId()
	{
		return m_AttackId;
	}
	INT32 GetAttackId() const
	{
		return m_AttackId;
	}

};
//RemoveModifySkill通知封装类
class FightRpcRemoveModifySkillNotifyWraper
{
public:
	//构造函数
	FightRpcRemoveModifySkillNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcRemoveModifySkillNotifyWraper(const FightRpcRemoveModifySkillNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcRemoveModifySkillNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcRemoveModifySkillNotify ToPB() const
	{
		FightRpcRemoveModifySkillNotify v;

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
		FightRpcRemoveModifySkillNotify pb;
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
	void Init(const FightRpcRemoveModifySkillNotify& v)
	{

	}


};
//怪物交互回应封装类
class FightRpcMonsterInteractReplyWraper
{
public:
	//构造函数
	FightRpcMonsterInteractReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightRpcMonsterInteractReplyWraper(const FightRpcMonsterInteractReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcMonsterInteractReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcMonsterInteractReply ToPB() const
	{
		FightRpcMonsterInteractReply v;
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
		FightRpcMonsterInteractReply pb;
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
	void Init(const FightRpcMonsterInteractReply& v)
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
//怪物交互请求封装类
class FightRpcMonsterInteractAskWraper
{
public:
	//构造函数
	FightRpcMonsterInteractAskWraper()
	{
		
		m_TargetId = 0;

	}
	//赋值构造函数
	FightRpcMonsterInteractAskWraper(const FightRpcMonsterInteractAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcMonsterInteractAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcMonsterInteractAsk ToPB() const
	{
		FightRpcMonsterInteractAsk v;
		v.set_targetid( m_TargetId );

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
		FightRpcMonsterInteractAsk pb;
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
	void Init(const FightRpcMonsterInteractAsk& v)
	{
		m_TargetId = v.targetid();

	}

private:
	//目标id
	uint64_t m_TargetId;
public:
	void SetTargetId( uint64_t v)
	{
		m_TargetId=v;
	}
	uint64_t GetTargetId()
	{
		return m_TargetId;
	}
	uint64_t GetTargetId() const
	{
		return m_TargetId;
	}

};
//使用宠物技能回应封装类
class FightRpcUsePetSkillReplyWraper
{
public:
	//构造函数
	FightRpcUsePetSkillReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightRpcUsePetSkillReplyWraper(const FightRpcUsePetSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUsePetSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUsePetSkillReply ToPB() const
	{
		FightRpcUsePetSkillReply v;
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
		FightRpcUsePetSkillReply pb;
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
	void Init(const FightRpcUsePetSkillReply& v)
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
//循环动作取消回应封装类
class FightRpcLoopActionCancelReplyWraper
{
public:
	//构造函数
	FightRpcLoopActionCancelReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FightRpcLoopActionCancelReplyWraper(const FightRpcLoopActionCancelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcLoopActionCancelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcLoopActionCancelReply ToPB() const
	{
		FightRpcLoopActionCancelReply v;
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
		FightRpcLoopActionCancelReply pb;
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
	void Init(const FightRpcLoopActionCancelReply& v)
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
//循环动作取消广播通知封装类
class FightRpcLoopActionCancelOtherNotifyWraper
{
public:
	//构造函数
	FightRpcLoopActionCancelOtherNotifyWraper()
	{
		
		m_ObjId = 0;
		m_SkillId = -1;

	}
	//赋值构造函数
	FightRpcLoopActionCancelOtherNotifyWraper(const FightRpcLoopActionCancelOtherNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcLoopActionCancelOtherNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcLoopActionCancelOtherNotify ToPB() const
	{
		FightRpcLoopActionCancelOtherNotify v;
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
		FightRpcLoopActionCancelOtherNotify pb;
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
	void Init(const FightRpcLoopActionCancelOtherNotify& v)
	{
		m_ObjId = v.objid();
		m_SkillId = v.skillid();

	}

private:
	//ObjID
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//技能Id
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
//使用宠物技能请求封装类
class FightRpcUsePetSkillAskWraper
{
public:
	//构造函数
	FightRpcUsePetSkillAskWraper()
	{
		
		m_SkillId = -1;
		m_CastingDir = -1;
		m_CurrentPos = Vector3IntWraper();
		m_TargetPos = Vector3IntWraper();

	}
	//赋值构造函数
	FightRpcUsePetSkillAskWraper(const FightRpcUsePetSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUsePetSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUsePetSkillAsk ToPB() const
	{
		FightRpcUsePetSkillAsk v;
		v.mutable_objtargetid()->Reserve(m_ObjTargetId.size());
		for (int i=0; i<(int)m_ObjTargetId.size(); i++)
		{
			v.add_objtargetid(m_ObjTargetId[i]);
		}
		v.set_skillid( m_SkillId );
		v.set_castingdir( m_CastingDir );
		*v.mutable_currentpos()= m_CurrentPos.ToPB();
		*v.mutable_targetpos()= m_TargetPos.ToPB();

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
		FightRpcUsePetSkillAsk pb;
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
	void Init(const FightRpcUsePetSkillAsk& v)
	{
		m_ObjTargetId.clear();
		m_ObjTargetId.reserve(v.objtargetid_size());
		for( int i=0; i<v.objtargetid_size(); i++)
			m_ObjTargetId.push_back(v.objtargetid(i));
		m_SkillId = v.skillid();
		m_CastingDir = v.castingdir();
		m_CurrentPos = v.currentpos();
		m_TargetPos = v.targetpos();

	}

private:
	//ObjTargetId
	vector<uint64_t> m_ObjTargetId;
public:
	int SizeObjTargetId()
	{
		return m_ObjTargetId.size();
	}
	const vector<uint64_t>& GetObjTargetId() const
	{
		return m_ObjTargetId;
	}
	uint64_t GetObjTargetId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_ObjTargetId[Index];
	}
	void SetObjTargetId( const vector<uint64_t>& v )
	{
		m_ObjTargetId=v;
	}
	void ClearObjTargetId( )
	{
		m_ObjTargetId.clear();
	}
	void SetObjTargetId( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return;
		}
		m_ObjTargetId[Index] = v;
	}
	void AddObjTargetId( uint64_t v = 0 )
	{
		m_ObjTargetId.push_back(v);
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
	//CastingDir
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
	//CurrentPos
	Vector3IntWraper m_CurrentPos;
public:
	void SetCurrentPos( const Vector3IntWraper& v)
	{
		m_CurrentPos=v;
	}
	Vector3IntWraper GetCurrentPos()
	{
		return m_CurrentPos;
	}
	Vector3IntWraper GetCurrentPos() const
	{
		return m_CurrentPos;
	}
private:
	//TargetPos
	Vector3IntWraper m_TargetPos;
public:
	void SetTargetPos( const Vector3IntWraper& v)
	{
		m_TargetPos=v;
	}
	Vector3IntWraper GetTargetPos()
	{
		return m_TargetPos;
	}
	Vector3IntWraper GetTargetPos() const
	{
		return m_TargetPos;
	}

};
//SkillList通知封装类
class FightRpcSkillListNotifyWraper
{
public:
	//构造函数
	FightRpcSkillListNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcSkillListNotifyWraper(const FightRpcSkillListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcSkillListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcSkillListNotify ToPB() const
	{
		FightRpcSkillListNotify v;
		v.mutable_skilllist()->Reserve(m_SkillList.size());
		for (int i=0; i<(int)m_SkillList.size(); i++)
		{
			v.add_skilllist(m_SkillList[i]);
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
		FightRpcSkillListNotify pb;
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
	void Init(const FightRpcSkillListNotify& v)
	{
		m_SkillList.clear();
		m_SkillList.reserve(v.skilllist_size());
		for( int i=0; i<v.skilllist_size(); i++)
			m_SkillList.push_back(v.skilllist(i));

	}

private:
	//skillList
	vector<INT32> m_SkillList;
public:
	int SizeSkillList()
	{
		return m_SkillList.size();
	}
	const vector<INT32>& GetSkillList() const
	{
		return m_SkillList;
	}
	INT32 GetSkillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return INT32();
		}
		return m_SkillList[Index];
	}
	void SetSkillList( const vector<INT32>& v )
	{
		m_SkillList=v;
	}
	void ClearSkillList( )
	{
		m_SkillList.clear();
	}
	void SetSkillList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return;
		}
		m_SkillList[Index] = v;
	}
	void AddSkillList( INT32 v = -1 )
	{
		m_SkillList.push_back(v);
	}

};
//自动杀怪通知封装类
class FightRpcAutoCombatMonsterNotifyWraper
{
public:
	//构造函数
	FightRpcAutoCombatMonsterNotifyWraper()
	{
		
		m_MonsterGuid = 0;

	}
	//赋值构造函数
	FightRpcAutoCombatMonsterNotifyWraper(const FightRpcAutoCombatMonsterNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcAutoCombatMonsterNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcAutoCombatMonsterNotify ToPB() const
	{
		FightRpcAutoCombatMonsterNotify v;
		v.set_monsterguid( m_MonsterGuid );

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
		FightRpcAutoCombatMonsterNotify pb;
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
	void Init(const FightRpcAutoCombatMonsterNotify& v)
	{
		m_MonsterGuid = v.monsterguid();

	}

private:
	//怪物的Guid
	uint64_t m_MonsterGuid;
public:
	void SetMonsterGuid( uint64_t v)
	{
		m_MonsterGuid=v;
	}
	uint64_t GetMonsterGuid()
	{
		return m_MonsterGuid;
	}
	uint64_t GetMonsterGuid() const
	{
		return m_MonsterGuid;
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
//连击技能通知封装类
class FightRpcComboSkillActionNotifyWraper
{
public:
	//构造函数
	FightRpcComboSkillActionNotifyWraper()
	{
		
		m_ObjId = 0;
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
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
//血量改变通知封装类
class FightRpcHpChangeActionNotifyWraper
{
public:
	//构造函数
	FightRpcHpChangeActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_IncrementHp = 0;
		m_CasterId = 0;

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
		v.set_incrementhp( m_IncrementHp );
		v.set_casterid( m_CasterId );

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
		m_IncrementHp = v.incrementhp();
		m_CasterId = v.casterid();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//增量血
	INT32 m_IncrementHp;
public:
	void SetIncrementHp( INT32 v)
	{
		m_IncrementHp=v;
	}
	INT32 GetIncrementHp()
	{
		return m_IncrementHp;
	}
	INT32 GetIncrementHp() const
	{
		return m_IncrementHp;
	}
private:
	//释放者
	uint64_t m_CasterId;
public:
	void SetCasterId( uint64_t v)
	{
		m_CasterId=v;
	}
	uint64_t GetCasterId()
	{
		return m_CasterId;
	}
	uint64_t GetCasterId() const
	{
		return m_CasterId;
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
//复活事件通知封装类
class FightRpcReviveActionNotifyWraper
{
public:
	//构造函数
	FightRpcReviveActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_Pos = Vector3Wraper();
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
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//复活后的位置
	Vector3Wraper m_Pos;
public:
	void SetPos( const Vector3Wraper& v)
	{
		m_Pos=v;
	}
	Vector3Wraper GetPos()
	{
		return m_Pos;
	}
	Vector3Wraper GetPos() const
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
//显示经验通知封装类
class FightRpcShowExpActionNotifyWraper
{
public:
	//构造函数
	FightRpcShowExpActionNotifyWraper()
	{
		
		m_ObjId = 0;
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
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
		
		m_ObjId = 0;
		m_ObjTargetId = 0;
		m_SkillId = -1;
		m_CastingDir = -1;
		m_X = -1;
		m_Y = -1;
		m_Z = -1;
		m_MomentIndex = -1;
		m_CustomSkiData = CustomSkiDataWraper();

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
		*v.mutable_customskidata()= m_CustomSkiData.ToPB();

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
		m_CustomSkiData = v.customskidata();

	}

private:
	//ObjId
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//ObjTargetId
	uint64_t m_ObjTargetId;
public:
	void SetObjTargetId( uint64_t v)
	{
		m_ObjTargetId=v;
	}
	uint64_t GetObjTargetId()
	{
		return m_ObjTargetId;
	}
	uint64_t GetObjTargetId() const
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
private:
	//动画key 设置
	CustomSkiDataWraper m_CustomSkiData;
public:
	void SetCustomSkiData( const CustomSkiDataWraper& v)
	{
		m_CustomSkiData=v;
	}
	CustomSkiDataWraper GetCustomSkiData()
	{
		return m_CustomSkiData;
	}
	CustomSkiDataWraper GetCustomSkiData() const
	{
		return m_CustomSkiData;
	}

};
//状态事件通知封装类
class FightRpcStateActionNotifyWraper
{
public:
	//构造函数
	FightRpcStateActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_Type = -1;
		m_Pos = Vector3Wraper();
		m_TargetPos = -1;
		m_State = -1;

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
		v.set_state( m_State );

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
		m_State = v.state();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
	Vector3Wraper m_Pos;
public:
	void SetPos( const Vector3Wraper& v)
	{
		m_Pos=v;
	}
	Vector3Wraper GetPos()
	{
		return m_Pos;
	}
	Vector3Wraper GetPos() const
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
private:
	//状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}

};
//buf通知封装类
class FightRpcBuffActionNotifyWraper
{
public:
	//构造函数
	FightRpcBuffActionNotifyWraper()
	{
		
		m_Info = BuffInfoWraper();

	}
	//赋值构造函数
	FightRpcBuffActionNotifyWraper(const FightRpcBuffActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcBuffActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcBuffActionNotify ToPB() const
	{
		FightRpcBuffActionNotify v;
		*v.mutable_info()= m_Info.ToPB();

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
		m_Info = v.info();

	}

private:
	//buf信息
	BuffInfoWraper m_Info;
public:
	void SetInfo( const BuffInfoWraper& v)
	{
		m_Info=v;
	}
	BuffInfoWraper GetInfo()
	{
		return m_Info;
	}
	BuffInfoWraper GetInfo() const
	{
		return m_Info;
	}

};
//使用技能请求请求封装类
class FightRpcUseSkillAskWraper
{
public:
	//构造函数
	FightRpcUseSkillAskWraper()
	{
		
		m_SkillId = -1;
		m_CastingDir = -1;
		m_X = -1;
		m_Y = -1;
		m_Z = -1;
		m_MomentIndex = -1;
		m_CustomSkiData = CustomSkiDataWraper();
		m_CurrentPos = Vector3IntWraper();

	}
	//赋值构造函数
	FightRpcUseSkillAskWraper(const FightRpcUseSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcUseSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcUseSkillAsk ToPB() const
	{
		FightRpcUseSkillAsk v;
		v.mutable_objtargetid()->Reserve(m_ObjTargetId.size());
		for (int i=0; i<(int)m_ObjTargetId.size(); i++)
		{
			v.add_objtargetid(m_ObjTargetId[i]);
		}
		v.set_skillid( m_SkillId );
		v.set_castingdir( m_CastingDir );
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );
		v.set_momentindex( m_MomentIndex );
		*v.mutable_customskidata()= m_CustomSkiData.ToPB();
		*v.mutable_currentpos()= m_CurrentPos.ToPB();

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
		m_ObjTargetId.clear();
		m_ObjTargetId.reserve(v.objtargetid_size());
		for( int i=0; i<v.objtargetid_size(); i++)
			m_ObjTargetId.push_back(v.objtargetid(i));
		m_SkillId = v.skillid();
		m_CastingDir = v.castingdir();
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();
		m_MomentIndex = v.momentindex();
		m_CustomSkiData = v.customskidata();
		m_CurrentPos = v.currentpos();

	}

private:
	//ObjTargetId
	vector<uint64_t> m_ObjTargetId;
public:
	int SizeObjTargetId()
	{
		return m_ObjTargetId.size();
	}
	const vector<uint64_t>& GetObjTargetId() const
	{
		return m_ObjTargetId;
	}
	uint64_t GetObjTargetId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_ObjTargetId[Index];
	}
	void SetObjTargetId( const vector<uint64_t>& v )
	{
		m_ObjTargetId=v;
	}
	void ClearObjTargetId( )
	{
		m_ObjTargetId.clear();
	}
	void SetObjTargetId( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return;
		}
		m_ObjTargetId[Index] = v;
	}
	void AddObjTargetId( uint64_t v = 0 )
	{
		m_ObjTargetId.push_back(v);
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
private:
	//动画key 设置
	CustomSkiDataWraper m_CustomSkiData;
public:
	void SetCustomSkiData( const CustomSkiDataWraper& v)
	{
		m_CustomSkiData=v;
	}
	CustomSkiDataWraper GetCustomSkiData()
	{
		return m_CustomSkiData;
	}
	CustomSkiDataWraper GetCustomSkiData() const
	{
		return m_CustomSkiData;
	}
private:
	//当前位置
	Vector3IntWraper m_CurrentPos;
public:
	void SetCurrentPos( const Vector3IntWraper& v)
	{
		m_CurrentPos=v;
	}
	Vector3IntWraper GetCurrentPos()
	{
		return m_CurrentPos;
	}
	Vector3IntWraper GetCurrentPos() const
	{
		return m_CurrentPos;
	}

};
//减少cd通知封装类
class FightRpcReduceCDNotifyWraper
{
public:
	//构造函数
	FightRpcReduceCDNotifyWraper()
	{
		
		m_SkillId = -1;
		m_ModTime = -1;

	}
	//赋值构造函数
	FightRpcReduceCDNotifyWraper(const FightRpcReduceCDNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcReduceCDNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcReduceCDNotify ToPB() const
	{
		FightRpcReduceCDNotify v;
		v.set_skillid( m_SkillId );
		v.set_modtime( m_ModTime );

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
		FightRpcReduceCDNotify pb;
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
	void Init(const FightRpcReduceCDNotify& v)
	{
		m_SkillId = v.skillid();
		m_ModTime = v.modtime();

	}

private:
	//技能ID
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
	//修改的时间
	INT32 m_ModTime;
public:
	void SetModTime( INT32 v)
	{
		m_ModTime=v;
	}
	INT32 GetModTime()
	{
		return m_ModTime;
	}
	INT32 GetModTime() const
	{
		return m_ModTime;
	}

};
//BuffList通知封装类
class FightRpcBuffListNotifyWraper
{
public:
	//构造函数
	FightRpcBuffListNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcBuffListNotifyWraper(const FightRpcBuffListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcBuffListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcBuffListNotify ToPB() const
	{
		FightRpcBuffListNotify v;
		v.mutable_bufflist()->Reserve(m_BuffList.size());
		for (int i=0; i<(int)m_BuffList.size(); i++)
		{
			*v.add_bufflist() = m_BuffList[i].ToPB();
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
		FightRpcBuffListNotify pb;
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
	void Init(const FightRpcBuffListNotify& v)
	{
		m_BuffList.clear();
		m_BuffList.reserve(v.bufflist_size());
		for( int i=0; i<v.bufflist_size(); i++)
			m_BuffList.push_back(v.bufflist(i));

	}

private:
	//bufflist
	vector<BuffInfoWraper> m_BuffList;
public:
	int SizeBuffList()
	{
		return m_BuffList.size();
	}
	const vector<BuffInfoWraper>& GetBuffList() const
	{
		return m_BuffList;
	}
	BuffInfoWraper GetBuffList(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffList.size())
		{
			assert(false);
			return BuffInfoWraper();
		}
		return m_BuffList[Index];
	}
	void SetBuffList( const vector<BuffInfoWraper>& v )
	{
		m_BuffList=v;
	}
	void ClearBuffList( )
	{
		m_BuffList.clear();
	}
	void SetBuffList( int Index, const BuffInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_BuffList.size())
		{
			assert(false);
			return;
		}
		m_BuffList[Index] = v;
	}
	void AddBuffList( const BuffInfoWraper& v )
	{
		m_BuffList.push_back(v);
	}

};
//技能同步cd通知封装类
class FightRpcSkillCDNotifyWraper
{
public:
	//构造函数
	FightRpcSkillCDNotifyWraper()
	{
		

	}
	//赋值构造函数
	FightRpcSkillCDNotifyWraper(const FightRpcSkillCDNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcSkillCDNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcSkillCDNotify ToPB() const
	{
		FightRpcSkillCDNotify v;
		v.mutable_skillcdinfo()->Reserve(m_SkillCDInfo.size());
		for (int i=0; i<(int)m_SkillCDInfo.size(); i++)
		{
			*v.add_skillcdinfo() = m_SkillCDInfo[i].ToPB();
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
		FightRpcSkillCDNotify pb;
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
	void Init(const FightRpcSkillCDNotify& v)
	{
		m_SkillCDInfo.clear();
		m_SkillCDInfo.reserve(v.skillcdinfo_size());
		for( int i=0; i<v.skillcdinfo_size(); i++)
			m_SkillCDInfo.push_back(v.skillcdinfo(i));

	}

private:
	//技能cd信息
	vector<SkillCDInfoWraper> m_SkillCDInfo;
public:
	int SizeSkillCDInfo()
	{
		return m_SkillCDInfo.size();
	}
	const vector<SkillCDInfoWraper>& GetSkillCDInfo() const
	{
		return m_SkillCDInfo;
	}
	SkillCDInfoWraper GetSkillCDInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillCDInfo.size())
		{
			assert(false);
			return SkillCDInfoWraper();
		}
		return m_SkillCDInfo[Index];
	}
	void SetSkillCDInfo( const vector<SkillCDInfoWraper>& v )
	{
		m_SkillCDInfo=v;
	}
	void ClearSkillCDInfo( )
	{
		m_SkillCDInfo.clear();
	}
	void SetSkillCDInfo( int Index, const SkillCDInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillCDInfo.size())
		{
			assert(false);
			return;
		}
		m_SkillCDInfo[Index] = v;
	}
	void AddSkillCDInfo( const SkillCDInfoWraper& v )
	{
		m_SkillCDInfo.push_back(v);
	}

};
//复活通知通知封装类
class FightRpcReliveNotifyNotifyWraper
{
public:
	//构造函数
	FightRpcReliveNotifyNotifyWraper()
	{
		
		m_ObjId = 0;

	}
	//赋值构造函数
	FightRpcReliveNotifyNotifyWraper(const FightRpcReliveNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcReliveNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcReliveNotifyNotify ToPB() const
	{
		FightRpcReliveNotifyNotify v;
		v.set_objid( m_ObjId );

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
		FightRpcReliveNotifyNotify pb;
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
	void Init(const FightRpcReliveNotifyNotify& v)
	{
		m_ObjId = v.objid();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}

};
//战斗辅助tips通知封装类
class FightRpcFightTipsNotifyWraper
{
public:
	//构造函数
	FightRpcFightTipsNotifyWraper()
	{
		
		m_TipsID = -1;
		m_Durtion = -1;
		m_TypeID = -1;

	}
	//赋值构造函数
	FightRpcFightTipsNotifyWraper(const FightRpcFightTipsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcFightTipsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcFightTipsNotify ToPB() const
	{
		FightRpcFightTipsNotify v;
		v.set_tipsid( m_TipsID );
		v.set_durtion( m_Durtion );
		v.set_typeid( m_TypeID );

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
		FightRpcFightTipsNotify pb;
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
	void Init(const FightRpcFightTipsNotify& v)
	{
		m_TipsID = v.tipsid();
		m_Durtion = v.durtion();
		m_TypeID = v.typeid();

	}

private:
	//tipsID
	INT32 m_TipsID;
public:
	void SetTipsID( INT32 v)
	{
		m_TipsID=v;
	}
	INT32 GetTipsID()
	{
		return m_TipsID;
	}
	INT32 GetTipsID() const
	{
		return m_TipsID;
	}
private:
	//持续时间
	INT32 m_Durtion;
public:
	void SetDurtion( INT32 v)
	{
		m_Durtion=v;
	}
	INT32 GetDurtion()
	{
		return m_Durtion;
	}
	INT32 GetDurtion() const
	{
		return m_Durtion;
	}
private:
	//类型
	INT32 m_TypeID;
public:
	void SetTypeID( INT32 v)
	{
		m_TypeID=v;
	}
	INT32 GetTypeID()
	{
		return m_TypeID;
	}
	INT32 GetTypeID() const
	{
		return m_TypeID;
	}

};
//伤害事件通知封装类
class FightRpcHurtActionNotifyWraper
{
public:
	//构造函数
	FightRpcHurtActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_SegmentIndex = -1;
		m_SkillId = -1;
		m_TargetObjId = 0;
		m_HurtValue = 0;
		m_IsCritical = false;
		m_IsDodge = false;
		m_IsMiss = false;
		m_IsHurtState = false;
		m_AttackId = -1;
		m_IsDead = false;

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
		v.set_isdodge( m_IsDodge );
		v.set_ismiss( m_IsMiss );
		v.set_ishurtstate( m_IsHurtState );
		v.set_attackid( m_AttackId );
		v.set_isdead( m_IsDead );

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
		m_IsDodge = v.isdodge();
		m_IsMiss = v.ismiss();
		m_IsHurtState = v.ishurtstate();
		m_AttackId = v.attackid();
		m_IsDead = v.isdead();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
	uint64_t m_TargetObjId;
public:
	void SetTargetObjId( uint64_t v)
	{
		m_TargetObjId=v;
	}
	uint64_t GetTargetObjId()
	{
		return m_TargetObjId;
	}
	uint64_t GetTargetObjId() const
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
	//是否格挡
	bool m_IsDodge;
public:
	void SetIsDodge( bool v)
	{
		m_IsDodge=v;
	}
	bool GetIsDodge()
	{
		return m_IsDodge;
	}
	bool GetIsDodge() const
	{
		return m_IsDodge;
	}
private:
	//是否闪避了
	bool m_IsMiss;
public:
	void SetIsMiss( bool v)
	{
		m_IsMiss=v;
	}
	bool GetIsMiss()
	{
		return m_IsMiss;
	}
	bool GetIsMiss() const
	{
		return m_IsMiss;
	}
private:
	//是否受击了
	bool m_IsHurtState;
public:
	void SetIsHurtState( bool v)
	{
		m_IsHurtState=v;
	}
	bool GetIsHurtState()
	{
		return m_IsHurtState;
	}
	bool GetIsHurtState() const
	{
		return m_IsHurtState;
	}
private:
	//当前伤害的AttackId
	INT32 m_AttackId;
public:
	void SetAttackId( INT32 v)
	{
		m_AttackId=v;
	}
	INT32 GetAttackId()
	{
		return m_AttackId;
	}
	INT32 GetAttackId() const
	{
		return m_AttackId;
	}
private:
	//目标是否死亡
	bool m_IsDead;
public:
	void SetIsDead( bool v)
	{
		m_IsDead=v;
	}
	bool GetIsDead()
	{
		return m_IsDead;
	}
	bool GetIsDead() const
	{
		return m_IsDead;
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
//obj死亡通知通知封装类
class FightRpcObjDeadActionNotifyWraper
{
public:
	//构造函数
	FightRpcObjDeadActionNotifyWraper()
	{
		
		m_ObjId = 0;

	}
	//赋值构造函数
	FightRpcObjDeadActionNotifyWraper(const FightRpcObjDeadActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcObjDeadActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcObjDeadActionNotify ToPB() const
	{
		FightRpcObjDeadActionNotify v;
		v.set_objid( m_ObjId );

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
		FightRpcObjDeadActionNotify pb;
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
	void Init(const FightRpcObjDeadActionNotify& v)
	{
		m_ObjId = v.objid();

	}

private:
	//死亡的objID
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}

};
//战斗击 退、飞、撞、拉 通知通知封装类
class FightRpcRepelActionNotifyWraper
{
public:
	//构造函数
	FightRpcRepelActionNotifyWraper()
	{
		
		m_ObjId = 0;
		m_SegmentIndex = -1;
		m_SkillId = -1;
		m_TargetObjId = 0;
		m_SkiTargetPos = Vector3Wraper();
		m_IsPlayerDiaup = true;
		m_Speed = 0;

	}
	//赋值构造函数
	FightRpcRepelActionNotifyWraper(const FightRpcRepelActionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const FightRpcRepelActionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FightRpcRepelActionNotify ToPB() const
	{
		FightRpcRepelActionNotify v;
		v.set_objid( m_ObjId );
		v.set_segmentindex( m_SegmentIndex );
		v.set_skillid( m_SkillId );
		v.set_targetobjid( m_TargetObjId );
		*v.mutable_skitargetpos()= m_SkiTargetPos.ToPB();
		v.set_isplayerdiaup( m_IsPlayerDiaup );
		v.set_speed( m_Speed );

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
		FightRpcRepelActionNotify pb;
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
	void Init(const FightRpcRepelActionNotify& v)
	{
		m_ObjId = v.objid();
		m_SegmentIndex = v.segmentindex();
		m_SkillId = v.skillid();
		m_TargetObjId = v.targetobjid();
		m_SkiTargetPos = v.skitargetpos();
		m_IsPlayerDiaup = v.isplayerdiaup();
		m_Speed = v.speed();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
	uint64_t m_TargetObjId;
public:
	void SetTargetObjId( uint64_t v)
	{
		m_TargetObjId=v;
	}
	uint64_t GetTargetObjId()
	{
		return m_TargetObjId;
	}
	uint64_t GetTargetObjId() const
	{
		return m_TargetObjId;
	}
private:
	//目标位置
	Vector3Wraper m_SkiTargetPos;
public:
	void SetSkiTargetPos( const Vector3Wraper& v)
	{
		m_SkiTargetPos=v;
	}
	Vector3Wraper GetSkiTargetPos()
	{
		return m_SkiTargetPos;
	}
	Vector3Wraper GetSkiTargetPos() const
	{
		return m_SkiTargetPos;
	}
private:
	//是否播放动画
	bool m_IsPlayerDiaup;
public:
	void SetIsPlayerDiaup( bool v)
	{
		m_IsPlayerDiaup=v;
	}
	bool GetIsPlayerDiaup()
	{
		return m_IsPlayerDiaup;
	}
	bool GetIsPlayerDiaup() const
	{
		return m_IsPlayerDiaup;
	}
private:
	//击退速度
	float m_Speed;
public:
	void SetSpeed( float v)
	{
		m_Speed=v;
	}
	float GetSpeed()
	{
		return m_Speed;
	}
	float GetSpeed() const
	{
		return m_Speed;
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
template<> struct MessageIdT<FightRpcRepelActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_REPELACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcObjDeadActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcFightTipsNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY};};
template<> struct MessageIdT<FightRpcBuffListNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_BUFFLIST_NOTIFY};};
template<> struct MessageIdT<FightRpcReduceCDNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_REDUCECD_NOTIFY};};
template<> struct MessageIdT<FightRpcReliveNotifyNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillCDNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_SKILLCD_NOTIFY};};
template<> struct MessageIdT<FightRpcAutoCombatMonsterNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_AUTOCOMBATMONSTER_NOTIFY};};
template<> struct MessageIdT<FightRpcTranslateActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_TRANSLATEACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcCantAddBuffTipNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_CANTADDBUFFTIP_NOTIFY};};
template<> struct MessageIdT<FightRpcAttackWarningNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_ATTACKWARNING_NOTIFY};};
template<> struct MessageIdT<FightRpcInterruptActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_INTERRUPTACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillPrepareActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_SKILLPREPAREACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcChainMagicJumpNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_CHAINMAGICJUMP_NOTIFY};};
template<> struct MessageIdT<FightRpcBlackHoleActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_BLACKHOLEACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcLoopActionCancelOtherNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_LOOPACTIONCANCELOTHER_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillListNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_SKILLLIST_NOTIFY};};
template<> struct MessageIdT<FightRpcRemoveModifySkillNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_REMOVEMODIFYSKILL_NOTIFY};};
template<> struct MessageIdT<FightRpcLinkMagicActionNotifyWraper>{ enum{ID=RPC_CODE_FIGHT_LINKMAGICACTION_NOTIFY};};


#endif
