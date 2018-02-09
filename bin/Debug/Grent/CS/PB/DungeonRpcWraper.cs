
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBDungeon.cs
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


//CreateDungeon请求封装类
[System.Serializable]
public class DungeonRpcCreateDungeonAskWraper
{

	//构造函数
	public DungeonRpcCreateDungeonAskWraper()
	{
		 m_RoleId = 0;
		 m_DungeonConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_DungeonConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonAsk ToPB()
	{
		DungeonRpcCreateDungeonAsk v = new DungeonRpcCreateDungeonAsk();
		v.RoleId = m_RoleId;
		v.DungeonConfigId = m_DungeonConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_DungeonConfigId = v.DungeonConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateDungeonAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateDungeonAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//HumanRoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}


};
//CreateDungeon回应封装类
[System.Serializable]
public class DungeonRpcCreateDungeonReplyWraper
{

	//构造函数
	public DungeonRpcCreateDungeonReplyWraper()
	{
		 m_Result = -9999;
		 m_DungeonConfigId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_DungeonConfigId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonReply ToPB()
	{
		DungeonRpcCreateDungeonReply v = new DungeonRpcCreateDungeonReply();
		v.Result = m_Result;
		v.DungeonConfigId = m_DungeonConfigId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonConfigId = v.DungeonConfigId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateDungeonReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateDungeonReply>(protoMS);
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
	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//退出副本请求封装类
[System.Serializable]
public class DungeonRpcExitDungeonAskWraper
{

	//构造函数
	public DungeonRpcExitDungeonAskWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcExitDungeonAsk ToPB()
	{
		DungeonRpcExitDungeonAsk v = new DungeonRpcExitDungeonAsk();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcExitDungeonAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcExitDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcExitDungeonAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcExitDungeonAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//HumanRoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//退出副本回应封装类
[System.Serializable]
public class DungeonRpcExitDungeonReplyWraper
{

	//构造函数
	public DungeonRpcExitDungeonReplyWraper()
	{
		 m_Result = -9999;
		 m_SceneConfigId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_SceneConfigId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcExitDungeonReply ToPB()
	{
		DungeonRpcExitDungeonReply v = new DungeonRpcExitDungeonReply();
		v.Result = m_Result;
		v.SceneConfigId = m_SceneConfigId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcExitDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SceneConfigId = v.SceneConfigId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcExitDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcExitDungeonReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcExitDungeonReply>(protoMS);
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
	//SceneConfigId
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//队长创建副本以后通知我请求封装类
[System.Serializable]
public class DungeonRpcInformCreateDungeonAskWraper
{

	//构造函数
	public DungeonRpcInformCreateDungeonAskWraper()
	{
		 m_RoleId = 0;
		 m_TargetSceneId = -1;
		 m_DungeonConfigId = -1;
		 m_CurSceneId = -1;
		 m_Result = -9999;
		m_RoleIds = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_TargetSceneId = -1;
		 m_DungeonConfigId = -1;
		 m_CurSceneId = -1;
		 m_Result = -9999;
		m_RoleIds = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcInformCreateDungeonAsk ToPB()
	{
		DungeonRpcInformCreateDungeonAsk v = new DungeonRpcInformCreateDungeonAsk();
		v.RoleId = m_RoleId;
		v.TargetSceneId = m_TargetSceneId;
		v.DungeonConfigId = m_DungeonConfigId;
		v.CurSceneId = m_CurSceneId;
		v.Result = m_Result;
		for (int i=0; i<(int)m_RoleIds.Count; i++)
			v.RoleIds.Add( m_RoleIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcInformCreateDungeonAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_TargetSceneId = v.TargetSceneId;
		m_DungeonConfigId = v.DungeonConfigId;
		m_CurSceneId = v.CurSceneId;
		m_Result = v.Result;
		m_RoleIds.Clear();
		for( int i=0; i<v.RoleIds.Count; i++)
			m_RoleIds.Add(v.RoleIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcInformCreateDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcInformCreateDungeonAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcInformCreateDungeonAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}
	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//队员当前场景
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//玩家的唯一id
	public List<UInt64> m_RoleIds;
	public int SizeRoleIds()
	{
		return m_RoleIds.Count;
	}
	public List<UInt64> GetRoleIds()
	{
		return m_RoleIds;
	}
	public UInt64 GetRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return 0;
		return m_RoleIds[Index];
	}
	public void SetRoleIds( List<UInt64> v )
	{
		m_RoleIds=v;
	}
	public void SetRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return;
		m_RoleIds[Index] = v;
	}
	public void AddRoleIds( UInt64 v=0 )
	{
		m_RoleIds.Add(v);
	}
	public void ClearRoleIds( )
	{
		m_RoleIds.Clear();
	}


};
//队长创建副本以后通知我回应封装类
[System.Serializable]
public class DungeonRpcInformCreateDungeonReplyWraper
{

	//构造函数
	public DungeonRpcInformCreateDungeonReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcInformCreateDungeonReply ToPB()
	{
		DungeonRpcInformCreateDungeonReply v = new DungeonRpcInformCreateDungeonReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcInformCreateDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcInformCreateDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcInformCreateDungeonReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcInformCreateDungeonReply>(protoMS);
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
//Settlement通知封装类
[System.Serializable]
public class DungeonRpcSettlementNotifyWraper
{

	//构造函数
	public DungeonRpcSettlementNotifyWraper()
	{
		 m_SettlementResult = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SettlementResult = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcSettlementNotify ToPB()
	{
		DungeonRpcSettlementNotify v = new DungeonRpcSettlementNotify();
		v.SettlementResult = m_SettlementResult;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcSettlementNotify v)
	{
        if (v == null)
            return;
		m_SettlementResult = v.SettlementResult;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcSettlementNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcSettlementNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcSettlementNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//SettlementResult
	public int m_SettlementResult;
	public int SettlementResult
	{
		get { return m_SettlementResult;}
		set { m_SettlementResult = value; }
	}


};
//进入副本通知请求封装类
[System.Serializable]
public class DungeonRpcEnterDungeonAskWraper
{

	//构造函数
	public DungeonRpcEnterDungeonAskWraper()
	{
		 m_SceneId = -1;
		 m_DungeonConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_DungeonConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcEnterDungeonAsk ToPB()
	{
		DungeonRpcEnterDungeonAsk v = new DungeonRpcEnterDungeonAsk();
		v.SceneId = m_SceneId;
		v.DungeonConfigId = m_DungeonConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcEnterDungeonAsk v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_DungeonConfigId = v.DungeonConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcEnterDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcEnterDungeonAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcEnterDungeonAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}


};
//进入副本通知回应封装类
[System.Serializable]
public class DungeonRpcEnterDungeonReplyWraper
{

	//构造函数
	public DungeonRpcEnterDungeonReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcEnterDungeonReply ToPB()
	{
		DungeonRpcEnterDungeonReply v = new DungeonRpcEnterDungeonReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcEnterDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcEnterDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcEnterDungeonReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcEnterDungeonReply>(protoMS);
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
