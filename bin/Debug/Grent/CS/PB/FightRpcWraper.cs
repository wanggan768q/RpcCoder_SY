
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
		 m_ObjId = 0;
		 m_ObjTargetId = 0;
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
		 m_ObjId = 0;
		 m_ObjTargetId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//ObjTargetId
	public UInt64 m_ObjTargetId;
	public UInt64 ObjTargetId
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
		 m_ObjId = 0;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
		 m_ObjId = 0;
		 m_Type = -1;
		 m_Pos = new Vector3Wraper();
		 m_TargetPos = -1;
		 m_State = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_CurHp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
		 m_ObjId = 0;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
		 m_ObjId = 0;
		 m_IncrementHp = 0;
		 m_CasterId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_IncrementHp = 0;
		 m_CasterId = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcHpChangeActionNotify ToPB()
	{
		FightRpcHpChangeActionNotify v = new FightRpcHpChangeActionNotify();
		v.ObjId = m_ObjId;
		v.IncrementHp = m_IncrementHp;
		v.CasterId = m_CasterId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcHpChangeActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_IncrementHp = v.IncrementHp;
		m_CasterId = v.CasterId;

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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
	//释放者
	public UInt64 m_CasterId;
	public UInt64 CasterId
	{
		get { return m_CasterId;}
		set { m_CasterId = value; }
	}


};
//使用技能请求请求封装类
[System.Serializable]
public class FightRpcUseSkillAskWraper
{

	//构造函数
	public FightRpcUseSkillAskWraper()
	{
		m_ObjTargetId = new List<UInt64>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;
		 m_CustomSkiData = new CustomSkiDataWraper();
		 m_CurrentPos = new Vector3IntWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ObjTargetId = new List<UInt64>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;
		 m_MomentIndex = -1;
		 m_CustomSkiData = new CustomSkiDataWraper();
		 m_CurrentPos = new Vector3IntWraper();

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
		v.CurrentPos = m_CurrentPos.ToPB();

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
		m_CurrentPos.FromPB(v.CurrentPos);

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
	public List<UInt64> m_ObjTargetId;
	public int SizeObjTargetId()
	{
		return m_ObjTargetId.Count;
	}
	public List<UInt64> GetObjTargetId()
	{
		return m_ObjTargetId;
	}
	public UInt64 GetObjTargetId(int Index)
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return 0;
		return m_ObjTargetId[Index];
	}
	public void SetObjTargetId( List<UInt64> v )
	{
		m_ObjTargetId=v;
	}
	public void SetObjTargetId( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return;
		m_ObjTargetId[Index] = v;
	}
	public void AddObjTargetId( UInt64 v=0 )
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
	//当前位置
	public Vector3IntWraper m_CurrentPos;
	public Vector3IntWraper CurrentPos
	{
		get { return m_CurrentPos;}
		set { m_CurrentPos = value; }
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

	//重置函数
	public void ResetWraper()
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
		v.AttackId = m_AttackId;
		v.IsDead = m_IsDead;

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
		m_AttackId = v.AttackId;
		m_IsDead = v.IsDead;

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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
	public UInt64 m_TargetObjId;
	public UInt64 TargetObjId
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
	//当前伤害的AttackId
	public int m_AttackId;
	public int AttackId
	{
		get { return m_AttackId;}
		set { m_AttackId = value; }
	}
	//目标是否死亡
	public bool m_IsDead;
	public bool IsDead
	{
		get { return m_IsDead;}
		set { m_IsDead = value; }
	}


};
//战斗击 退、飞、撞、拉 通知通知封装类
[System.Serializable]
public class FightRpcRepelActionNotifyWraper
{

	//构造函数
	public FightRpcRepelActionNotifyWraper()
	{
		 m_ObjId = 0;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = 0;
		 m_SkiTargetPos = new Vector3Wraper();
		 m_IsPlayerDiaup = true;
		 m_Speed = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_SegmentIndex = -1;
		 m_SkillId = -1;
		 m_TargetObjId = 0;
		 m_SkiTargetPos = new Vector3Wraper();
		 m_IsPlayerDiaup = true;
		 m_Speed = (float)0;

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
		v.Speed = m_Speed;

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
		m_Speed = v.Speed;

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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
	public UInt64 m_TargetObjId;
	public UInt64 TargetObjId
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
	//击退速度
	public float m_Speed;
	public float Speed
	{
		get { return m_Speed;}
		set { m_Speed = value; }
	}


};
//obj死亡通知通知封装类
[System.Serializable]
public class FightRpcObjDeadActionNotifyWraper
{

	//构造函数
	public FightRpcObjDeadActionNotifyWraper()
	{
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;

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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
		 m_TypeID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TipsID = -1;
		 m_Durtion = -1;
		 m_TypeID = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcFightTipsNotify ToPB()
	{
		FightRpcFightTipsNotify v = new FightRpcFightTipsNotify();
		v.TipsID = m_TipsID;
		v.Durtion = m_Durtion;
		v.TypeID = m_TypeID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcFightTipsNotify v)
	{
        if (v == null)
            return;
		m_TipsID = v.TipsID;
		m_Durtion = v.Durtion;
		m_TypeID = v.TypeID;

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
	//类型
	public int m_TypeID;
	public int TypeID
	{
		get { return m_TypeID;}
		set { m_TypeID = value; }
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
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;

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
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//技能同步cd通知封装类
[System.Serializable]
public class FightRpcSkillCDNotifyWraper
{

	//构造函数
	public FightRpcSkillCDNotifyWraper()
	{
		m_SkillCDInfo = new List<SkillCDInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SkillCDInfo = new List<SkillCDInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public FightRpcSkillCDNotify ToPB()
	{
		FightRpcSkillCDNotify v = new FightRpcSkillCDNotify();
		for (int i=0; i<(int)m_SkillCDInfo.Count; i++)
			v.SkillCDInfo.Add( m_SkillCDInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcSkillCDNotify v)
	{
        if (v == null)
            return;
		m_SkillCDInfo.Clear();
		for( int i=0; i<v.SkillCDInfo.Count; i++)
			m_SkillCDInfo.Add( new SkillCDInfoWraper());
		for( int i=0; i<v.SkillCDInfo.Count; i++)
			m_SkillCDInfo[i].FromPB(v.SkillCDInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillCDNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcSkillCDNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcSkillCDNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能cd信息
	public List<SkillCDInfoWraper> m_SkillCDInfo;
	public int SizeSkillCDInfo()
	{
		return m_SkillCDInfo.Count;
	}
	public List<SkillCDInfoWraper> GetSkillCDInfo()
	{
		return m_SkillCDInfo;
	}
	public SkillCDInfoWraper GetSkillCDInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillCDInfo.Count)
			return new SkillCDInfoWraper();
		return m_SkillCDInfo[Index];
	}
	public void SetSkillCDInfo( List<SkillCDInfoWraper> v )
	{
		m_SkillCDInfo=v;
	}
	public void SetSkillCDInfo( int Index, SkillCDInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_SkillCDInfo.Count)
			return;
		m_SkillCDInfo[Index] = v;
	}
	public void AddSkillCDInfo( SkillCDInfoWraper v )
	{
		m_SkillCDInfo.Add(v);
	}
	public void ClearSkillCDInfo( )
	{
		m_SkillCDInfo.Clear();
	}


};
//自动杀怪通知封装类
[System.Serializable]
public class FightRpcAutoCombatMonsterNotifyWraper
{

	//构造函数
	public FightRpcAutoCombatMonsterNotifyWraper()
	{
		 m_MonsterGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MonsterGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcAutoCombatMonsterNotify ToPB()
	{
		FightRpcAutoCombatMonsterNotify v = new FightRpcAutoCombatMonsterNotify();
		v.MonsterGuid = m_MonsterGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcAutoCombatMonsterNotify v)
	{
        if (v == null)
            return;
		m_MonsterGuid = v.MonsterGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcAutoCombatMonsterNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcAutoCombatMonsterNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcAutoCombatMonsterNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//怪物的Guid
	public UInt64 m_MonsterGuid;
	public UInt64 MonsterGuid
	{
		get { return m_MonsterGuid;}
		set { m_MonsterGuid = value; }
	}


};
//战斗位移通知封装类
[System.Serializable]
public class FightRpcTranslateActionNotifyWraper
{

	//构造函数
	public FightRpcTranslateActionNotifyWraper()
	{
		 m_ObjId = 0;
		 m_TargetPos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_SkillId = -1;
		 m_CommandIndex = -1;
		 m_IsEnd = false;
		 m_Speed = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_TargetPos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_SkillId = -1;
		 m_CommandIndex = -1;
		 m_IsEnd = false;
		 m_Speed = (float)0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcTranslateActionNotify ToPB()
	{
		FightRpcTranslateActionNotify v = new FightRpcTranslateActionNotify();
		v.ObjId = m_ObjId;
		v.TargetPos = m_TargetPos.ToPB();
		v.Dir = m_Dir;
		v.SkillId = m_SkillId;
		v.CommandIndex = m_CommandIndex;
		v.IsEnd = m_IsEnd;
		v.Speed = m_Speed;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcTranslateActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_TargetPos.FromPB(v.TargetPos);
		m_Dir = v.Dir;
		m_SkillId = v.SkillId;
		m_CommandIndex = v.CommandIndex;
		m_IsEnd = v.IsEnd;
		m_Speed = v.Speed;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcTranslateActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcTranslateActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcTranslateActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//对象GUID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//目标位置
	public Vector3Wraper m_TargetPos;
	public Vector3Wraper TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}
	//位移后朝向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//技能Id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//索引
	public int m_CommandIndex;
	public int CommandIndex
	{
		get { return m_CommandIndex;}
		set { m_CommandIndex = value; }
	}
	//是否结束
	public bool m_IsEnd;
	public bool IsEnd
	{
		get { return m_IsEnd;}
		set { m_IsEnd = value; }
	}
	//位移速度
	public float m_Speed;
	public float Speed
	{
		get { return m_Speed;}
		set { m_Speed = value; }
	}


};
//添加buff失败提示通知封装类
[System.Serializable]
public class FightRpcCantAddBuffTipNotifyWraper
{

	//构造函数
	public FightRpcCantAddBuffTipNotifyWraper()
	{
		 m_BuffId = -1;
		 m_CasterId = 0;
		 m_ObjId = 0;
		 m_Sn = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuffId = -1;
		 m_CasterId = 0;
		 m_ObjId = 0;
		 m_Sn = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcCantAddBuffTipNotify ToPB()
	{
		FightRpcCantAddBuffTipNotify v = new FightRpcCantAddBuffTipNotify();
		v.BuffId = m_BuffId;
		v.CasterId = m_CasterId;
		v.ObjId = m_ObjId;
		v.Sn = m_Sn;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcCantAddBuffTipNotify v)
	{
        if (v == null)
            return;
		m_BuffId = v.BuffId;
		m_CasterId = v.CasterId;
		m_ObjId = v.ObjId;
		m_Sn = v.Sn;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcCantAddBuffTipNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcCantAddBuffTipNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcCantAddBuffTipNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//buffId
	public int m_BuffId;
	public int BuffId
	{
		get { return m_BuffId;}
		set { m_BuffId = value; }
	}
	//Buff释放者ID
	public UInt64 m_CasterId;
	public UInt64 CasterId
	{
		get { return m_CasterId;}
		set { m_CasterId = value; }
	}
	//buff接收者id
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//buff序列号
	public int m_Sn;
	public int Sn
	{
		get { return m_Sn;}
		set { m_Sn = value; }
	}


};
//生成预警圈通知封装类
[System.Serializable]
public class FightRpcAttackWarningNotifyWraper
{

	//构造函数
	public FightRpcAttackWarningNotifyWraper()
	{
		 m_AttackId = -1;
		 m_Caster = 0;
		m_TargetList = new List<UInt64>();
		 m_TargetPos = new Vector3Wraper();
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AttackId = -1;
		 m_Caster = 0;
		m_TargetList = new List<UInt64>();
		 m_TargetPos = new Vector3Wraper();
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcAttackWarningNotify ToPB()
	{
		FightRpcAttackWarningNotify v = new FightRpcAttackWarningNotify();
		v.AttackId = m_AttackId;
		v.Caster = m_Caster;
		for (int i=0; i<(int)m_TargetList.Count; i++)
			v.TargetList.Add( m_TargetList[i]);
		v.TargetPos = m_TargetPos.ToPB();
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcAttackWarningNotify v)
	{
        if (v == null)
            return;
		m_AttackId = v.AttackId;
		m_Caster = v.Caster;
		m_TargetList.Clear();
		for( int i=0; i<v.TargetList.Count; i++)
			m_TargetList.Add(v.TargetList[i]);
		m_TargetPos.FromPB(v.TargetPos);
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcAttackWarningNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcAttackWarningNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcAttackWarningNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//attackID
	public int m_AttackId;
	public int AttackId
	{
		get { return m_AttackId;}
		set { m_AttackId = value; }
	}
	//释放者id
	public UInt64 m_Caster;
	public UInt64 Caster
	{
		get { return m_Caster;}
		set { m_Caster = value; }
	}
	//打击列表
	public List<UInt64> m_TargetList;
	public int SizeTargetList()
	{
		return m_TargetList.Count;
	}
	public List<UInt64> GetTargetList()
	{
		return m_TargetList;
	}
	public UInt64 GetTargetList(int Index)
	{
		if(Index<0 || Index>=(int)m_TargetList.Count)
			return 0;
		return m_TargetList[Index];
	}
	public void SetTargetList( List<UInt64> v )
	{
		m_TargetList=v;
	}
	public void SetTargetList( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_TargetList.Count)
			return;
		m_TargetList[Index] = v;
	}
	public void AddTargetList( UInt64 v=0 )
	{
		m_TargetList.Add(v);
	}
	public void ClearTargetList( )
	{
		m_TargetList.Clear();
	}
	//attack 目标点
	public Vector3Wraper m_TargetPos;
	public Vector3Wraper TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}
	//技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//技能打断事件通知封装类
[System.Serializable]
public class FightRpcInterruptActionNotifyWraper
{

	//构造函数
	public FightRpcInterruptActionNotifyWraper()
	{
		 m_Caster = 0;
		 m_Interrupter = 0;
		m_Skill = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Caster = 0;
		 m_Interrupter = 0;
		m_Skill = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public FightRpcInterruptActionNotify ToPB()
	{
		FightRpcInterruptActionNotify v = new FightRpcInterruptActionNotify();
		v.Caster = m_Caster;
		v.Interrupter = m_Interrupter;
		for (int i=0; i<(int)m_Skill.Count; i++)
			v.Skill.Add( m_Skill[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcInterruptActionNotify v)
	{
        if (v == null)
            return;
		m_Caster = v.Caster;
		m_Interrupter = v.Interrupter;
		m_Skill.Clear();
		for( int i=0; i<v.Skill.Count; i++)
			m_Skill.Add(v.Skill[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcInterruptActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcInterruptActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcInterruptActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能释放者
	public UInt64 m_Caster;
	public UInt64 Caster
	{
		get { return m_Caster;}
		set { m_Caster = value; }
	}
	//打断者
	public UInt64 m_Interrupter;
	public UInt64 Interrupter
	{
		get { return m_Interrupter;}
		set { m_Interrupter = value; }
	}
	//打断技能id
	public List<int> m_Skill;
	public int SizeSkill()
	{
		return m_Skill.Count;
	}
	public List<int> GetSkill()
	{
		return m_Skill;
	}
	public int GetSkill(int Index)
	{
		if(Index<0 || Index>=(int)m_Skill.Count)
			return -1;
		return m_Skill[Index];
	}
	public void SetSkill( List<int> v )
	{
		m_Skill=v;
	}
	public void SetSkill( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Skill.Count)
			return;
		m_Skill[Index] = v;
	}
	public void AddSkill( int v=-1 )
	{
		m_Skill.Add(v);
	}
	public void ClearSkill( )
	{
		m_Skill.Clear();
	}


};
//技能蓄力请求请求封装类
[System.Serializable]
public class FightRpcSkillPrepareAskWraper
{

	//构造函数
	public FightRpcSkillPrepareAskWraper()
	{
		 m_SkillId = -1;
		 m_Type = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillId = -1;
		 m_Type = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcSkillPrepareAsk ToPB()
	{
		FightRpcSkillPrepareAsk v = new FightRpcSkillPrepareAsk();
		v.SkillId = m_SkillId;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcSkillPrepareAsk v)
	{
        if (v == null)
            return;
		m_SkillId = v.SkillId;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillPrepareAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcSkillPrepareAsk pb = ProtoBuf.Serializer.Deserialize<FightRpcSkillPrepareAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//SkillId
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//Type
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//技能蓄力请求回应封装类
[System.Serializable]
public class FightRpcSkillPrepareReplyWraper
{

	//构造函数
	public FightRpcSkillPrepareReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcSkillPrepareReply ToPB()
	{
		FightRpcSkillPrepareReply v = new FightRpcSkillPrepareReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcSkillPrepareReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillPrepareReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcSkillPrepareReply pb = ProtoBuf.Serializer.Deserialize<FightRpcSkillPrepareReply>(protoMS);
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
//蓄力技能通知通知封装类
[System.Serializable]
public class FightRpcSkillPrepareActionNotifyWraper
{

	//构造函数
	public FightRpcSkillPrepareActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcSkillPrepareActionNotify ToPB()
	{
		FightRpcSkillPrepareActionNotify v = new FightRpcSkillPrepareActionNotify();
		v.ObjId = m_ObjId;
		v.SkillId = m_SkillId;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcSkillPrepareActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SkillId = v.SkillId;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillPrepareActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcSkillPrepareActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcSkillPrepareActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public Int64 m_ObjId;
	public Int64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//SkillId
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//Type
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//链式法术跳跃通知封装类
[System.Serializable]
public class FightRpcChainMagicJumpNotifyWraper
{

	//构造函数
	public FightRpcChainMagicJumpNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;
		 m_JumpFromObjId = -1;
		 m_JumpToObjId = -1;
		 m_AttackId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SkillId = -1;
		 m_JumpFromObjId = -1;
		 m_JumpToObjId = -1;
		 m_AttackId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcChainMagicJumpNotify ToPB()
	{
		FightRpcChainMagicJumpNotify v = new FightRpcChainMagicJumpNotify();
		v.ObjId = m_ObjId;
		v.SkillId = m_SkillId;
		v.JumpFromObjId = m_JumpFromObjId;
		v.JumpToObjId = m_JumpToObjId;
		v.AttackId = m_AttackId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcChainMagicJumpNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SkillId = v.SkillId;
		m_JumpFromObjId = v.JumpFromObjId;
		m_JumpToObjId = v.JumpToObjId;
		m_AttackId = v.AttackId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcChainMagicJumpNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcChainMagicJumpNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcChainMagicJumpNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public Int64 m_ObjId;
	public Int64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//SkillId
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//起始ObjId
	public Int64 m_JumpFromObjId;
	public Int64 JumpFromObjId
	{
		get { return m_JumpFromObjId;}
		set { m_JumpFromObjId = value; }
	}
	//终止ObjId
	public Int64 m_JumpToObjId;
	public Int64 JumpToObjId
	{
		get { return m_JumpToObjId;}
		set { m_JumpToObjId = value; }
	}
	//AttackId
	public int m_AttackId;
	public int AttackId
	{
		get { return m_AttackId;}
		set { m_AttackId = value; }
	}


};
//黑洞拉拽效果通知封装类
[System.Serializable]
public class FightRpcBlackHoleActionNotifyWraper
{

	//构造函数
	public FightRpcBlackHoleActionNotifyWraper()
	{
		 m_ObjId = -1;
		 m_ToX = (float)-1;
		 m_ToZ = (float)-1;
		 m_Speed = (float)-1;
		 m_Apply = false;
		 m_Type = -1;
		 m_TargetObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_ToX = (float)-1;
		 m_ToZ = (float)-1;
		 m_Speed = (float)-1;
		 m_Apply = false;
		 m_Type = -1;
		 m_TargetObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcBlackHoleActionNotify ToPB()
	{
		FightRpcBlackHoleActionNotify v = new FightRpcBlackHoleActionNotify();
		v.ObjId = m_ObjId;
		v.ToX = m_ToX;
		v.ToZ = m_ToZ;
		v.Speed = m_Speed;
		v.Apply = m_Apply;
		v.Type = m_Type;
		v.TargetObjId = m_TargetObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcBlackHoleActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_ToX = v.ToX;
		m_ToZ = v.ToZ;
		m_Speed = v.Speed;
		m_Apply = v.Apply;
		m_Type = v.Type;
		m_TargetObjId = v.TargetObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcBlackHoleActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcBlackHoleActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcBlackHoleActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public Int64 m_ObjId;
	public Int64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//目标点x
	public float m_ToX;
	public float ToX
	{
		get { return m_ToX;}
		set { m_ToX = value; }
	}
	//目标坐标z
	public float m_ToZ;
	public float ToZ
	{
		get { return m_ToZ;}
		set { m_ToZ = value; }
	}
	//速度
	public float m_Speed;
	public float Speed
	{
		get { return m_Speed;}
		set { m_Speed = value; }
	}
	//true=开始 false=结束
	public bool m_Apply;
	public bool Apply
	{
		get { return m_Apply;}
		set { m_Apply = value; }
	}
	//0=拉 1=推
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//目标ID
	public UInt64 m_TargetObjId;
	public UInt64 TargetObjId
	{
		get { return m_TargetObjId;}
		set { m_TargetObjId = value; }
	}


};
//循环动作取消请求封装类
[System.Serializable]
public class FightRpcLoopActionCancelAskWraper
{

	//构造函数
	public FightRpcLoopActionCancelAskWraper()
	{
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcLoopActionCancelAsk ToPB()
	{
		FightRpcLoopActionCancelAsk v = new FightRpcLoopActionCancelAsk();
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcLoopActionCancelAsk v)
	{
        if (v == null)
            return;
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcLoopActionCancelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcLoopActionCancelAsk pb = ProtoBuf.Serializer.Deserialize<FightRpcLoopActionCancelAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能Id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//循环动作取消广播通知封装类
[System.Serializable]
public class FightRpcLoopActionCancelOtherNotifyWraper
{

	//构造函数
	public FightRpcLoopActionCancelOtherNotifyWraper()
	{
		 m_ObjId = 0;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcLoopActionCancelOtherNotify ToPB()
	{
		FightRpcLoopActionCancelOtherNotify v = new FightRpcLoopActionCancelOtherNotify();
		v.ObjId = m_ObjId;
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcLoopActionCancelOtherNotify v)
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
		ProtoBuf.Serializer.Serialize<FightRpcLoopActionCancelOtherNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcLoopActionCancelOtherNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcLoopActionCancelOtherNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//技能Id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//循环动作取消回应封装类
[System.Serializable]
public class FightRpcLoopActionCancelReplyWraper
{

	//构造函数
	public FightRpcLoopActionCancelReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcLoopActionCancelReply ToPB()
	{
		FightRpcLoopActionCancelReply v = new FightRpcLoopActionCancelReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcLoopActionCancelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcLoopActionCancelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcLoopActionCancelReply pb = ProtoBuf.Serializer.Deserialize<FightRpcLoopActionCancelReply>(protoMS);
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
//SkillList通知封装类
[System.Serializable]
public class FightRpcSkillListNotifyWraper
{

	//构造函数
	public FightRpcSkillListNotifyWraper()
	{
		m_SkillList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SkillList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public FightRpcSkillListNotify ToPB()
	{
		FightRpcSkillListNotify v = new FightRpcSkillListNotify();
		for (int i=0; i<(int)m_SkillList.Count; i++)
			v.SkillList.Add( m_SkillList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcSkillListNotify v)
	{
        if (v == null)
            return;
		m_SkillList.Clear();
		for( int i=0; i<v.SkillList.Count; i++)
			m_SkillList.Add(v.SkillList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillListNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcSkillListNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcSkillListNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//skillList
	public List<int> m_SkillList;
	public int SizeSkillList()
	{
		return m_SkillList.Count;
	}
	public List<int> GetSkillList()
	{
		return m_SkillList;
	}
	public int GetSkillList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return -1;
		return m_SkillList[Index];
	}
	public void SetSkillList( List<int> v )
	{
		m_SkillList=v;
	}
	public void SetSkillList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return;
		m_SkillList[Index] = v;
	}
	public void AddSkillList( int v=-1 )
	{
		m_SkillList.Add(v);
	}
	public void ClearSkillList( )
	{
		m_SkillList.Clear();
	}


};
//使用宠物技能请求封装类
[System.Serializable]
public class FightRpcUsePetSkillAskWraper
{

	//构造函数
	public FightRpcUsePetSkillAskWraper()
	{
		m_ObjTargetId = new List<UInt64>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_CurrentPos = new Vector3IntWraper();
		 m_TargetPos = new Vector3IntWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ObjTargetId = new List<UInt64>();
		 m_SkillId = -1;
		 m_CastingDir = (float)-1;
		 m_CurrentPos = new Vector3IntWraper();
		 m_TargetPos = new Vector3IntWraper();

	}

 	//转化成Protobuffer类型函数
	public FightRpcUsePetSkillAsk ToPB()
	{
		FightRpcUsePetSkillAsk v = new FightRpcUsePetSkillAsk();
		for (int i=0; i<(int)m_ObjTargetId.Count; i++)
			v.ObjTargetId.Add( m_ObjTargetId[i]);
		v.SkillId = m_SkillId;
		v.CastingDir = m_CastingDir;
		v.CurrentPos = m_CurrentPos.ToPB();
		v.TargetPos = m_TargetPos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUsePetSkillAsk v)
	{
        if (v == null)
            return;
		m_ObjTargetId.Clear();
		for( int i=0; i<v.ObjTargetId.Count; i++)
			m_ObjTargetId.Add(v.ObjTargetId[i]);
		m_SkillId = v.SkillId;
		m_CastingDir = v.CastingDir;
		m_CurrentPos.FromPB(v.CurrentPos);
		m_TargetPos.FromPB(v.TargetPos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUsePetSkillAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUsePetSkillAsk pb = ProtoBuf.Serializer.Deserialize<FightRpcUsePetSkillAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjTargetId
	public List<UInt64> m_ObjTargetId;
	public int SizeObjTargetId()
	{
		return m_ObjTargetId.Count;
	}
	public List<UInt64> GetObjTargetId()
	{
		return m_ObjTargetId;
	}
	public UInt64 GetObjTargetId(int Index)
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return 0;
		return m_ObjTargetId[Index];
	}
	public void SetObjTargetId( List<UInt64> v )
	{
		m_ObjTargetId=v;
	}
	public void SetObjTargetId( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_ObjTargetId.Count)
			return;
		m_ObjTargetId[Index] = v;
	}
	public void AddObjTargetId( UInt64 v=0 )
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
	//CastingDir
	public float m_CastingDir;
	public float CastingDir
	{
		get { return m_CastingDir;}
		set { m_CastingDir = value; }
	}
	//CurrentPos
	public Vector3IntWraper m_CurrentPos;
	public Vector3IntWraper CurrentPos
	{
		get { return m_CurrentPos;}
		set { m_CurrentPos = value; }
	}
	//TargetPos
	public Vector3IntWraper m_TargetPos;
	public Vector3IntWraper TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}


};
//使用宠物技能回应封装类
[System.Serializable]
public class FightRpcUsePetSkillReplyWraper
{

	//构造函数
	public FightRpcUsePetSkillReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcUsePetSkillReply ToPB()
	{
		FightRpcUsePetSkillReply v = new FightRpcUsePetSkillReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUsePetSkillReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUsePetSkillReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUsePetSkillReply pb = ProtoBuf.Serializer.Deserialize<FightRpcUsePetSkillReply>(protoMS);
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
//RemoveModifySkill通知封装类
[System.Serializable]
public class FightRpcRemoveModifySkillNotifyWraper
{

	//构造函数
	public FightRpcRemoveModifySkillNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public FightRpcRemoveModifySkillNotify ToPB()
	{
		FightRpcRemoveModifySkillNotify v = new FightRpcRemoveModifySkillNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcRemoveModifySkillNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcRemoveModifySkillNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcRemoveModifySkillNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcRemoveModifySkillNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//链接magic效果通知封装类
[System.Serializable]
public class FightRpcLinkMagicActionNotifyWraper
{

	//构造函数
	public FightRpcLinkMagicActionNotifyWraper()
	{
		 m_ObjId = 0;
		 m_LinkerId = 0;
		 m_AttackId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_LinkerId = 0;
		 m_AttackId = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcLinkMagicActionNotify ToPB()
	{
		FightRpcLinkMagicActionNotify v = new FightRpcLinkMagicActionNotify();
		v.ObjId = m_ObjId;
		v.LinkerId = m_LinkerId;
		v.AttackId = m_AttackId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcLinkMagicActionNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_LinkerId = v.LinkerId;
		m_AttackId = v.AttackId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcLinkMagicActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcLinkMagicActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcLinkMagicActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//objId
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//链接者id
	public UInt64 m_LinkerId;
	public UInt64 LinkerId
	{
		get { return m_LinkerId;}
		set { m_LinkerId = value; }
	}
	//attackId
	public int m_AttackId;
	public int AttackId
	{
		get { return m_AttackId;}
		set { m_AttackId = value; }
	}


};
//怪物交互请求封装类
[System.Serializable]
public class FightRpcMonsterInteractAskWraper
{

	//构造函数
	public FightRpcMonsterInteractAskWraper()
	{
		 m_TargetId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TargetId = 0;

	}

 	//转化成Protobuffer类型函数
	public FightRpcMonsterInteractAsk ToPB()
	{
		FightRpcMonsterInteractAsk v = new FightRpcMonsterInteractAsk();
		v.TargetId = m_TargetId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcMonsterInteractAsk v)
	{
        if (v == null)
            return;
		m_TargetId = v.TargetId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcMonsterInteractAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcMonsterInteractAsk pb = ProtoBuf.Serializer.Deserialize<FightRpcMonsterInteractAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标id
	public UInt64 m_TargetId;
	public UInt64 TargetId
	{
		get { return m_TargetId;}
		set { m_TargetId = value; }
	}


};
//怪物交互回应封装类
[System.Serializable]
public class FightRpcMonsterInteractReplyWraper
{

	//构造函数
	public FightRpcMonsterInteractReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcMonsterInteractReply ToPB()
	{
		FightRpcMonsterInteractReply v = new FightRpcMonsterInteractReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcMonsterInteractReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcMonsterInteractReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcMonsterInteractReply pb = ProtoBuf.Serializer.Deserialize<FightRpcMonsterInteractReply>(protoMS);
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
