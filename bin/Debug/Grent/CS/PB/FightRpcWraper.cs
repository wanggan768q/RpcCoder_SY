
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBFight.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//使用技能动作通知封装类
[System.Serializable]
public class FightRpcUseSkillActionNotifyWraper
{

	//构造函数
	public FightRpcUseSkillActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseSkillActionNotify ToPB()
	{
		FightRpcUseSkillActionNotify v = new FightRpcUseSkillActionNotify();
		v.ObjId = m_ObjId;
		v.ObjTargetId = m_ObjTargetId;
		v.SkillId = m_SkillId;
		v.CastingDir = m_CastingDir;
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;
		v.MomentIndex = m_MomentIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseSkillActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_ObjTargetId = v.ObjTargetId;
		m_SkillId = v.SkillId;
		m_CastingDir = v.CastingDir;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;
		m_MomentIndex = v.MomentIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUseSkillActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUseSkillActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcUseSkillActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//ObjTargetId
	public int m_ObjTargetId;
	public int ObjTargetId
	{
		get { return m_ObjTargetId;}
		set { m_ObjTargetId = value; }
	}
	//SkillId
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//施法方向
	public float m_CastingDir;
	public float CastingDir
	{
		get { return m_CastingDir;}
		set { m_CastingDir = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//Z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//技能段数
	public int m_MomentIndex;
	public int MomentIndex
	{
		get { return m_MomentIndex;}
		set { m_MomentIndex = value; }
	}


};
//显示经验通知封装类
[System.Serializable]
public class FightRpcShowExpActionNotifyWraper
{

	//构造函数
	public FightRpcShowExpActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcShowExpActionNotify ToPB()
	{
		FightRpcShowExpActionNotify v = new FightRpcShowExpActionNotify();
		v.ObjId = m_ObjId;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcShowExpActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcShowExpActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcShowExpActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcShowExpActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//获取到的经验值
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//buf通知封装类
[System.Serializable]
public class FightRpcBuffActionNotifyWraper
{

	//构造函数
	public FightRpcBuffActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_TargetId = -1;
		 m_OpType = -1;
		 m_BufId = -1;
		 m_RemainTime = -1;
		 m_BuffLv = -1;
		 m_Sn = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_TargetId = -1;
		 m_OpType = -1;
		 m_BufId = -1;
		 m_RemainTime = -1;
		 m_BuffLv = -1;
		 m_Sn = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcBuffActionNotify ToPB()
	{
		FightRpcBuffActionNotify v = new FightRpcBuffActionNotify();
		v.ObjId = m_ObjId;
		v.TargetId = m_TargetId;
		v.OpType = m_OpType;
		v.BufId = m_BufId;
		v.RemainTime = m_RemainTime;
		v.BuffLv = m_BuffLv;
		v.Sn = m_Sn;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcBuffActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_TargetId = v.TargetId;
		m_OpType = v.OpType;
		m_BufId = v.BufId;
		m_RemainTime = v.RemainTime;
		m_BuffLv = v.BuffLv;
		m_Sn = v.Sn;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcBuffActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcBuffActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcBuffActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//目标id
	public int m_TargetId;
	public int TargetId
	{
		get { return m_TargetId;}
		set { m_TargetId = value; }
	}
	//操作类型
	public int m_OpType;
	public int OpType
	{
		get { return m_OpType;}
		set { m_OpType = value; }
	}
	//bufid
	public int m_BufId;
	public int BufId
	{
		get { return m_BufId;}
		set { m_BufId = value; }
	}
	//剩余时间
	public int m_RemainTime;
	public int RemainTime
	{
		get { return m_RemainTime;}
		set { m_RemainTime = value; }
	}
	//buf 等级
	public int m_BuffLv;
	public int BuffLv
	{
		get { return m_BuffLv;}
		set { m_BuffLv = value; }
	}
	//buff序列号
	public int m_Sn;
	public int Sn
	{
		get { return m_Sn;}
		set { m_Sn = value; }
	}


};
//状态事件通知封装类
[System.Serializable]
public class FightRpcStateActionNotifyWraper
{

	//构造函数
	public FightRpcStateActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Type = -1;
		 m_Pos = new V3Wraper();
		 m_TargetPos = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Type = -1;
		 m_Pos = new V3Wraper();
		 m_TargetPos = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcStateActionNotify ToPB()
	{
		FightRpcStateActionNotify v = new FightRpcStateActionNotify();
		v.ObjId = m_ObjId;
		v.Type = m_Type;
		v.Pos = m_Pos.ToPB();
		v.TargetPos = m_TargetPos;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcStateActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Type = v.Type;
		m_Pos.FromPB(v.Pos);
		m_TargetPos = v.TargetPos;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcStateActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcStateActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcStateActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//状态类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//位置信息
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//目标位置信息
	public int m_TargetPos;
	public int TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}


};
//复活事件通知封装类
[System.Serializable]
public class FightRpcReviveActionNotifyWraper
{

	//构造函数
	public FightRpcReviveActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_CurHp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_CurHp = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcReviveActionNotify ToPB()
	{
		FightRpcReviveActionNotify v = new FightRpcReviveActionNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.CurHp = m_CurHp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcReviveActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_CurHp = v.CurHp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcReviveActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcReviveActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcReviveActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//复活后的位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//当前血量
	public int m_CurHp;
	public int CurHp
	{
		get { return m_CurHp;}
		set { m_CurHp = value; }
	}


};
//连击技能通知封装类
[System.Serializable]
public class FightRpcComboSkillActionNotifyWraper
{

	//构造函数
	public FightRpcComboSkillActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcComboSkillActionNotify ToPB()
	{
		FightRpcComboSkillActionNotify v = new FightRpcComboSkillActionNotify();
		v.ObjId = m_ObjId;
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcComboSkillActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcComboSkillActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcComboSkillActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcComboSkillActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//掉落通知封装类
[System.Serializable]
public class FightRpcDropActionNotifyWraper
{

	//构造函数
	public FightRpcDropActionNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public FightRpcDropActionNotify ToPB()
	{
		FightRpcDropActionNotify v = new FightRpcDropActionNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcDropActionNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcDropActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcDropActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcDropActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//使用道具通知封装类
[System.Serializable]
public class FightRpcUseItemActionNotifyWraper
{

	//构造函数
	public FightRpcUseItemActionNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseItemActionNotify ToPB()
	{
		FightRpcUseItemActionNotify v = new FightRpcUseItemActionNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseItemActionNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUseItemActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUseItemActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcUseItemActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//血量改变通知封装类
[System.Serializable]
public class FightRpcHpChangeActionNotifyWraper
{

	//构造函数
	public FightRpcHpChangeActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_CurHp = -1;
		 m_MaxHp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_CurHp = -1;
		 m_MaxHp = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcHpChangeActionNotify ToPB()
	{
		FightRpcHpChangeActionNotify v = new FightRpcHpChangeActionNotify();
		v.ObjId = m_ObjId;
		v.CurHp = m_CurHp;
		v.MaxHp = m_MaxHp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcHpChangeActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_CurHp = v.CurHp;
		m_MaxHp = v.MaxHp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcHpChangeActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcHpChangeActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcHpChangeActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//当前血
	public int m_CurHp;
	public int CurHp
	{
		get { return m_CurHp;}
		set { m_CurHp = value; }
	}
	//最大血
	public int m_MaxHp;
	public int MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}


};
//使用技能请求请求封装类
[System.Serializable]
public class FightRpcUseSkillAskWraper
{

	//构造函数
	public FightRpcUseSkillAskWraper()
	{
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseSkillAsk ToPB()
	{
		FightRpcUseSkillAsk v = new FightRpcUseSkillAsk();
		v.ObjTargetId = m_ObjTargetId;
		v.SkillId = m_SkillId;
		v.CastingDir = m_CastingDir;
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;
		v.MomentIndex = m_MomentIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseSkillAsk v)
	{
        if (v == null)
            return;
		m_ObjTargetId = v.ObjTargetId;
		m_SkillId = v.SkillId;
		m_CastingDir = v.CastingDir;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;
		m_MomentIndex = v.MomentIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUseSkillAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUseSkillAsk pb = ProtoBuf.Serializer.Deserialize<FightRpcUseSkillAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjTargetId
	public int m_ObjTargetId;
	public int ObjTargetId
	{
		get { return m_ObjTargetId;}
		set { m_ObjTargetId = value; }
	}
	//SkillId
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//施法方向
	public float m_CastingDir;
	public float CastingDir
	{
		get { return m_CastingDir;}
		set { m_CastingDir = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//Z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//技能段数
	public int m_MomentIndex;
	public int MomentIndex
	{
		get { return m_MomentIndex;}
		set { m_MomentIndex = value; }
	}


};
//使用技能请求回应封装类
[System.Serializable]
public class FightRpcUseSkillReplyWraper
{

	//构造函数
	public FightRpcUseSkillReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseSkillReply ToPB()
	{
		FightRpcUseSkillReply v = new FightRpcUseSkillReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseSkillReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUseSkillReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUseSkillReply pb = ProtoBuf.Serializer.Deserialize<FightRpcUseSkillReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//伤害事件通知封装类
[System.Serializable]
public class FightRpcHurtActionNotifyWraper
{

	//构造函数
	public FightRpcHurtActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = -1;
		 m_HurtValue = 0;
		 m_IsCritical = false;
		 m_Energy = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = -1;
		 m_HurtValue = 0;
		 m_IsCritical = false;
		 m_Energy = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcHurtActionNotify ToPB()
	{
		FightRpcHurtActionNotify v = new FightRpcHurtActionNotify();
		v.ObjId = m_ObjId;
		v.SegmentIndex = m_SegmentIndex;
		v.SkillId = m_SkillId;
		v.TargetObjId = m_TargetObjId;
		v.HurtValue = m_HurtValue;
		v.IsCritical = m_IsCritical;
		v.Energy = m_Energy;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcHurtActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SegmentIndex = v.SegmentIndex;
		m_SkillId = v.SkillId;
		m_TargetObjId = v.TargetObjId;
		m_HurtValue = v.HurtValue;
		m_IsCritical = v.IsCritical;
		m_Energy = v.Energy;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcHurtActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcHurtActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcHurtActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//伤害阶段
	public int m_SegmentIndex;
	public int SegmentIndex
	{
		get { return m_SegmentIndex;}
		set { m_SegmentIndex = value; }
	}
	//技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//目标id
	public int m_TargetObjId;
	public int TargetObjId
	{
		get { return m_TargetObjId;}
		set { m_TargetObjId = value; }
	}
	//伤害的值
	public int m_HurtValue;
	public int HurtValue
	{
		get { return m_HurtValue;}
		set { m_HurtValue = value; }
	}
	//是否暴击
	public bool m_IsCritical;
	public bool IsCritical
	{
		get { return m_IsCritical;}
		set { m_IsCritical = value; }
	}
	//能量
	public int m_Energy;
	public int Energy
	{
		get { return m_Energy;}
		set { m_Energy = value; }
	}


};
