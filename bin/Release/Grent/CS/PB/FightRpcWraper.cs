
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
		 m_CustomSkiData = new CustomSkiDataWraper();

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
		 m_CustomSkiData = new CustomSkiDataWraper();

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
		v.CustomSkiData = m_CustomSkiData.ToPB();

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
		m_CustomSkiData.FromPB(v.CustomSkiData);

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
	//动画key 设置
	public CustomSkiDataWraper m_CustomSkiData;
	public CustomSkiDataWraper CustomSkiData
	{
		get { return m_CustomSkiData;}
		set { m_CustomSkiData = value; }
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
		 m_Info = new BuffInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Info = new BuffInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public FightRpcBuffActionNotify ToPB()
	{
		FightRpcBuffActionNotify v = new FightRpcBuffActionNotify();
		v.Info = m_Info.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcBuffActionNotify v)
	{
        if (v == null)
            return;
		m_Info.FromPB(v.Info);

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

	//buf信息
	public BuffInfoWraper m_Info;
	public BuffInfoWraper Info
	{
		get { return m_Info;}
		set { m_Info = value; }
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
		 m_Pos = new Vector3Wraper();
		 m_TargetPos = -1;
		 m_State = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Type = -1;
		 m_Pos = new Vector3Wraper();
		 m_TargetPos = -1;
		 m_State = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcStateActionNotify ToPB()
	{
		FightRpcStateActionNotify v = new FightRpcStateActionNotify();
		v.ObjId = m_ObjId;
		v.Type = m_Type;
		v.Pos = m_Pos.ToPB();
		v.TargetPos = m_TargetPos;
		v.State = m_State;

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
		m_State = v.State;

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
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
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
	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
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
		 m_Pos = new Vector3Wraper();
		 m_CurHp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new Vector3Wraper();
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
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
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
		 m_IncrementHp = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_IncrementHp = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcHpChangeActionNotify ToPB()
	{
		FightRpcHpChangeActionNotify v = new FightRpcHpChangeActionNotify();
		v.ObjId = m_ObjId;
		v.IncrementHp = m_IncrementHp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcHpChangeActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_IncrementHp = v.IncrementHp;

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
	//增量血
	public int m_IncrementHp;
	public int IncrementHp
	{
		get { return m_IncrementHp;}
		set { m_IncrementHp = value; }
	}


};
//使用技能请求请求封装类
[System.Serializable]
public class FightRpcUseSkillAskWraper
{

	//构造函数
	public FightRpcUseSkillAskWraper()
	{
		m_ObjTargetId = new List<int>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;
		 m_CustomSkiData = new CustomSkiDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ObjTargetId = new List<int>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;
		 m_CustomSkiData = new CustomSkiDataWraper();

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseSkillAsk ToPB()
	{
		FightRpcUseSkillAsk v = new FightRpcUseSkillAsk();
		for (int i=0; i<(int)m_ObjTargetId.Count; i++)
			v.ObjTargetId.Add( m_ObjTargetId[i]);
		v.SkillId = m_SkillId;
		v.CastingDir = m_CastingDir;
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;
		v.MomentIndex = m_MomentIndex;
		v.CustomSkiData = m_CustomSkiData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseSkillAsk v)
	{
        if (v == null)
            return;
		m_ObjTargetId.Clear();
		for( int i=0; i<v.ObjTargetId.Count; i++)
			m_ObjTargetId.Add(v.ObjTargetId[i]);
		m_SkillId = v.SkillId;
		m_CastingDir = v.CastingDir;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;
		m_MomentIndex = v.MomentIndex;
		m_CustomSkiData.FromPB(v.CustomSkiData);

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
	public List<int> m_ObjTargetId;
	public int SizeObjTargetId()
	{
		return m_ObjTargetId.Count;
	}
	public List<int> GetObjTargetId()
	{
		return m_ObjTargetId;
	}
	public int GetObjTargetId(int Index)
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return -1;
		return m_ObjTargetId[Index];
	}
	public void SetObjTargetId( List<int> v )
	{
		m_ObjTargetId=v;
	}
	public void SetObjTargetId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return;
		m_ObjTargetId[Index] = v;
	}
	public void AddObjTargetId( int v=-1 )
	{
		m_ObjTargetId.Add(v);
	}
	public void ClearObjTargetId( )
	{
		m_ObjTargetId.Clear();
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
	//动画key 设置
	public CustomSkiDataWraper m_CustomSkiData;
	public CustomSkiDataWraper CustomSkiData
	{
		get { return m_CustomSkiData;}
		set { m_CustomSkiData = value; }
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
		 m_IsDodge = false;
		 m_IsMiss = false;
		 m_IsHurtState = false;

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
		 m_IsDodge = false;
		 m_IsMiss = false;
		 m_IsHurtState = false;

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
		v.IsDodge = m_IsDodge;
		v.IsMiss = m_IsMiss;
		v.IsHurtState = m_IsHurtState;

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
		m_IsDodge = v.IsDodge;
		m_IsMiss = v.IsMiss;
		m_IsHurtState = v.IsHurtState;

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
	//是否格挡
	public bool m_IsDodge;
	public bool IsDodge
	{
		get { return m_IsDodge;}
		set { m_IsDodge = value; }
	}
	//是否闪避了
	public bool m_IsMiss;
	public bool IsMiss
	{
		get { return m_IsMiss;}
		set { m_IsMiss = value; }
	}
	//是否受击了
	public bool m_IsHurtState;
	public bool IsHurtState
	{
		get { return m_IsHurtState;}
		set { m_IsHurtState = value; }
	}


};
//战斗击 退、飞、撞、拉 通知通知封装类
[System.Serializable]
public class FightRpcRepelActionNotifyWraper
{

	//构造函数
	public FightRpcRepelActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = -1;
		 m_SkiTargetPos = new Vector3Wraper();
		 m_IsPlayerDiaup = true;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = -1;
		 m_SkiTargetPos = new Vector3Wraper();
		 m_IsPlayerDiaup = true;

	}

 	//转化成Protobuffer类型函数
	public FightRpcRepelActionNotify ToPB()
	{
		FightRpcRepelActionNotify v = new FightRpcRepelActionNotify();
		v.ObjId = m_ObjId;
		v.SegmentIndex = m_SegmentIndex;
		v.SkillId = m_SkillId;
		v.TargetObjId = m_TargetObjId;
		v.SkiTargetPos = m_SkiTargetPos.ToPB();
		v.IsPlayerDiaup = m_IsPlayerDiaup;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcRepelActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SegmentIndex = v.SegmentIndex;
		m_SkillId = v.SkillId;
		m_TargetObjId = v.TargetObjId;
		m_SkiTargetPos.FromPB(v.SkiTargetPos);
		m_IsPlayerDiaup = v.IsPlayerDiaup;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcRepelActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcRepelActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcRepelActionNotify>(protoMS);
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
	//目标位置
	public Vector3Wraper m_SkiTargetPos;
	public Vector3Wraper SkiTargetPos
	{
		get { return m_SkiTargetPos;}
		set { m_SkiTargetPos = value; }
	}
	//是否播放动画
	public bool m_IsPlayerDiaup;
	public bool IsPlayerDiaup
	{
		get { return m_IsPlayerDiaup;}
		set { m_IsPlayerDiaup = value; }
	}


};
//obj死亡通知通知封装类
[System.Serializable]
public class FightRpcObjDeadActionNotifyWraper
{

	//构造函数
	public FightRpcObjDeadActionNotifyWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcObjDeadActionNotify ToPB()
	{
		FightRpcObjDeadActionNotify v = new FightRpcObjDeadActionNotify();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcObjDeadActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcObjDeadActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcObjDeadActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcObjDeadActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//死亡的objID
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//战斗辅助tips通知封装类
[System.Serializable]
public class FightRpcFightTipsNotifyWraper
{

	//构造函数
	public FightRpcFightTipsNotifyWraper()
	{
		 m_TipsID = -1;
		 m_Durtion = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TipsID = -1;
		 m_Durtion = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcFightTipsNotify ToPB()
	{
		FightRpcFightTipsNotify v = new FightRpcFightTipsNotify();
		v.TipsID = m_TipsID;
		v.Durtion = m_Durtion;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcFightTipsNotify v)
	{
        if (v == null)
            return;
		m_TipsID = v.TipsID;
		m_Durtion = v.Durtion;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcFightTipsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcFightTipsNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcFightTipsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//tipsID
	public int m_TipsID;
	public int TipsID
	{
		get { return m_TipsID;}
		set { m_TipsID = value; }
	}
	//持续时间
	public int m_Durtion;
	public int Durtion
	{
		get { return m_Durtion;}
		set { m_Durtion = value; }
	}


};
//BuffList通知封装类
[System.Serializable]
public class FightRpcBuffListNotifyWraper
{

	//构造函数
	public FightRpcBuffListNotifyWraper()
	{
		m_BuffList = new List<BuffInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_BuffList = new List<BuffInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public FightRpcBuffListNotify ToPB()
	{
		FightRpcBuffListNotify v = new FightRpcBuffListNotify();
		for (int i=0; i<(int)m_BuffList.Count; i++)
			v.BuffList.Add( m_BuffList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcBuffListNotify v)
	{
        if (v == null)
            return;
		m_BuffList.Clear();
		for( int i=0; i<v.BuffList.Count; i++)
			m_BuffList.Add( new BuffInfoWraper());
		for( int i=0; i<v.BuffList.Count; i++)
			m_BuffList[i].FromPB(v.BuffList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcBuffListNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcBuffListNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcBuffListNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//bufflist
	public List<BuffInfoWraper> m_BuffList;
	public int SizeBuffList()
	{
		return m_BuffList.Count;
	}
	public List<BuffInfoWraper> GetBuffList()
	{
		return m_BuffList;
	}
	public BuffInfoWraper GetBuffList(int Index)
	{
		if(Index<0 || Index>=(int)m_BuffList.Count)
			return new BuffInfoWraper();
		return m_BuffList[Index];
	}
	public void SetBuffList( List<BuffInfoWraper> v )
	{
		m_BuffList=v;
	}
	public void SetBuffList( int Index, BuffInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_BuffList.Count)
			return;
		m_BuffList[Index] = v;
	}
	public void AddBuffList( BuffInfoWraper v )
	{
		m_BuffList.Add(v);
	}
	public void ClearBuffList( )
	{
		m_BuffList.Clear();
	}


};
//减少cd通知封装类
[System.Serializable]
public class FightRpcReduceCDNotifyWraper
{

	//构造函数
	public FightRpcReduceCDNotifyWraper()
	{
		 m_SkillId = -1;
		 m_ModTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillId = -1;
		 m_ModTime = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcReduceCDNotify ToPB()
	{
		FightRpcReduceCDNotify v = new FightRpcReduceCDNotify();
		v.SkillId = m_SkillId;
		v.ModTime = m_ModTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcReduceCDNotify v)
	{
        if (v == null)
            return;
		m_SkillId = v.SkillId;
		m_ModTime = v.ModTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcReduceCDNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcReduceCDNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcReduceCDNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能ID
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//修改的时间
	public int m_ModTime;
	public int ModTime
	{
		get { return m_ModTime;}
		set { m_ModTime = value; }
	}


};
//复活通知通知封装类
[System.Serializable]
public class FightRpcReliveNotifyNotifyWraper
{

	//构造函数
	public FightRpcReliveNotifyNotifyWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcReliveNotifyNotify ToPB()
	{
		FightRpcReliveNotifyNotify v = new FightRpcReliveNotifyNotify();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcReliveNotifyNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcReliveNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcReliveNotifyNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcReliveNotifyNotify>(protoMS);
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


};
