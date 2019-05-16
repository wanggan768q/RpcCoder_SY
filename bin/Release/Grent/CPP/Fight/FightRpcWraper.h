/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperFight.h
* Author:       甘业清
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


};


//伤害事件通知封装类
class FightRpcHurtActionNotifyWraper : public DataWraperInterface 
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
		m_IsDodge = false;
		m_IsMiss = false;
		m_IsHurtState = false;

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

};
//战斗击 退、飞、撞、拉 通知通知封装类
class FightRpcRepelActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcRepelActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SegmentIndex = -1;
		m_SkillId = -1;
		m_TargetObjId = -1;
		m_SkiTargetPos = Vector3Wraper();
		m_IsPlayerDiaup = true;

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
	void Init(const FightRpcRepelActionNotify& v)
	{
		m_ObjId = v.objid();
		m_SegmentIndex = v.segmentindex();
		m_SkillId = v.skillid();
		m_TargetObjId = v.targetobjid();
		m_SkiTargetPos = v.skitargetpos();
		m_IsPlayerDiaup = v.isplayerdiaup();

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

};
//使用技能请求请求封装类
class FightRpcUseSkillAskWraper : public DataWraperInterface 
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

	}

private:
	//ObjTargetId
	vector<INT32> m_ObjTargetId;
public:
	int SizeObjTargetId()
	{
		return m_ObjTargetId.size();
	}
	const vector<INT32>& GetObjTargetId() const
	{
		return m_ObjTargetId;
	}
	INT32 GetObjTargetId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return INT32();
		}
		return m_ObjTargetId[Index];
	}
	void SetObjTargetId( const vector<INT32>& v )
	{
		m_ObjTargetId=v;
	}
	void ClearObjTargetId( )
	{
		m_ObjTargetId.clear();
	}
	void SetObjTargetId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.size())
		{
			assert(false);
			return;
		}
		m_ObjTargetId[Index] = v;
	}
	void AddObjTargetId( INT32 v = -1 )
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

};
//使用技能请求回应封装类
class FightRpcUseSkillReplyWraper : public DataWraperInterface 
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
class FightRpcObjDeadActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcObjDeadActionNotifyWraper()
	{
		
		m_ObjId = -1;

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
	void Init(const FightRpcObjDeadActionNotify& v)
	{
		m_ObjId = v.objid();

	}

private:
	//死亡的objID
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

};
//减少cd通知封装类
class FightRpcReduceCDNotifyWraper : public DataWraperInterface 
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
//复活通知通知封装类
class FightRpcReliveNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcReliveNotifyNotifyWraper()
	{
		
		m_ObjId = -1;

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
	void Init(const FightRpcReliveNotifyNotify& v)
	{
		m_ObjId = v.objid();

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

};
//战斗辅助tips通知封装类
class FightRpcFightTipsNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcFightTipsNotifyWraper()
	{
		
		m_TipsID = -1;
		m_Durtion = -1;

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
	void Init(const FightRpcFightTipsNotify& v)
	{
		m_TipsID = v.tipsid();
		m_Durtion = v.durtion();

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

};
//BuffList通知封装类
class FightRpcBuffListNotifyWraper : public DataWraperInterface 
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
//buf通知封装类
class FightRpcBuffActionNotifyWraper : public DataWraperInterface 
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
//状态事件通知封装类
class FightRpcStateActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcStateActionNotifyWraper()
	{
		
		m_ObjId = -1;
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
//使用技能动作通知封装类
class FightRpcUseSkillActionNotifyWraper : public DataWraperInterface 
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
//显示经验通知封装类
class FightRpcShowExpActionNotifyWraper : public DataWraperInterface 
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
//复活事件通知封装类
class FightRpcReviveActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcReviveActionNotifyWraper()
	{
		
		m_ObjId = -1;
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
//使用道具通知封装类
class FightRpcUseItemActionNotifyWraper : public DataWraperInterface 
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
	void Init(const FightRpcUseItemActionNotify& v)
	{

	}


};
//血量改变通知封装类
class FightRpcHpChangeActionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FightRpcHpChangeActionNotifyWraper()
	{
		
		m_ObjId = -1;
		m_IncrementHp = 0;

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
	void Init(const FightRpcHpChangeActionNotify& v)
	{
		m_ObjId = v.objid();
		m_IncrementHp = v.incrementhp();

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

};
//连击技能通知封装类
class FightRpcComboSkillActionNotifyWraper : public DataWraperInterface 
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
//掉落通知封装类
class FightRpcDropActionNotifyWraper : public DataWraperInterface 
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
	void Init(const FightRpcDropActionNotify& v)
	{

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


#endif
