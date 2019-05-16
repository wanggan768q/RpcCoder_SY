
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
		 m_SceneConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonReply ToPB()
	{
		DungeonRpcCreateDungeonReply v = new DungeonRpcCreateDungeonReply();
		v.Result = m_Result;
		v.DungeonConfigId = m_DungeonConfigId;
		v.SceneConfigId = m_SceneConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonConfigId = v.DungeonConfigId;
		m_SceneConfigId = v.SceneConfigId;

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
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
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
//战况信息通知封装类
[System.Serializable]
public class DungeonRpcDungeonDataNotifyWraper
{

	//构造函数
	public DungeonRpcDungeonDataNotifyWraper()
	{
		 m_BeginTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BeginTime = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonDataNotify ToPB()
	{
		DungeonRpcDungeonDataNotify v = new DungeonRpcDungeonDataNotify();
		v.BeginTime = m_BeginTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonDataNotify v)
	{
        if (v == null)
            return;
		m_BeginTime = v.BeginTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonDataNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonDataNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonDataNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//副本开始时间
	public int m_BeginTime;
	public int BeginTime
	{
		get { return m_BeginTime;}
		set { m_BeginTime = value; }
	}


};
//副本数据请求请求封装类
[System.Serializable]
public class DungeonRpcDungeonSyncAskWraper
{

	//构造函数
	public DungeonRpcDungeonSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonSyncAsk ToPB()
	{
		DungeonRpcDungeonSyncAsk v = new DungeonRpcDungeonSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonSyncAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//副本数据请求回应封装类
[System.Serializable]
public class DungeonRpcDungeonSyncReplyWraper
{

	//构造函数
	public DungeonRpcDungeonSyncReplyWraper()
	{
		 m_Result = -1;
		 m_Data = new DungeonDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Data = new DungeonDataWraper();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonSyncReply ToPB()
	{
		DungeonRpcDungeonSyncReply v = new DungeonRpcDungeonSyncReply();
		v.Result = m_Result;
		v.Data = m_Data.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Data.FromPB(v.Data);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonSyncReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonSyncReply>(protoMS);
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
	//副本数据
	public DungeonDataWraper m_Data;
	public DungeonDataWraper Data
	{
		get { return m_Data;}
		set { m_Data = value; }
	}


};
//副本挑战信息请求封装类
[System.Serializable]
public class DungeonRpcDungeonListInfoAskWraper
{

	//构造函数
	public DungeonRpcDungeonListInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonListInfoAsk ToPB()
	{
		DungeonRpcDungeonListInfoAsk v = new DungeonRpcDungeonListInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonListInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonListInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonListInfoAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonListInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//副本挑战信息回应封装类
[System.Serializable]
public class DungeonRpcDungeonListInfoReplyWraper
{

	//构造函数
	public DungeonRpcDungeonListInfoReplyWraper()
	{
		 m_Result = -1;
		m_DungeonBossData = new List<DungeonBossInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_DungeonBossData = new List<DungeonBossInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonListInfoReply ToPB()
	{
		DungeonRpcDungeonListInfoReply v = new DungeonRpcDungeonListInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_DungeonBossData.Count; i++)
			v.DungeonBossData.Add( m_DungeonBossData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonListInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonBossData.Clear();
		for( int i=0; i<v.DungeonBossData.Count; i++)
			m_DungeonBossData.Add( new DungeonBossInfoWraper());
		for( int i=0; i<v.DungeonBossData.Count; i++)
			m_DungeonBossData[i].FromPB(v.DungeonBossData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonListInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonListInfoReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonListInfoReply>(protoMS);
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
	//副本BOSS挑战数据
	public List<DungeonBossInfoWraper> m_DungeonBossData;
	public int SizeDungeonBossData()
	{
		return m_DungeonBossData.Count;
	}
	public List<DungeonBossInfoWraper> GetDungeonBossData()
	{
		return m_DungeonBossData;
	}
	public DungeonBossInfoWraper GetDungeonBossData(int Index)
	{
		if(Index<0 || Index>=(int)m_DungeonBossData.Count)
			return new DungeonBossInfoWraper();
		return m_DungeonBossData[Index];
	}
	public void SetDungeonBossData( List<DungeonBossInfoWraper> v )
	{
		m_DungeonBossData=v;
	}
	public void SetDungeonBossData( int Index, DungeonBossInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_DungeonBossData.Count)
			return;
		m_DungeonBossData[Index] = v;
	}
	public void AddDungeonBossData( DungeonBossInfoWraper v )
	{
		m_DungeonBossData.Add(v);
	}
	public void ClearDungeonBossData( )
	{
		m_DungeonBossData.Clear();
	}


};
//创建序章副本请求封装类
[System.Serializable]
public class DungeonRpcCreateTutorialAskWraper
{

	//构造函数
	public DungeonRpcCreateTutorialAskWraper()
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
	public DungeonRpcCreateTutorialAsk ToPB()
	{
		DungeonRpcCreateTutorialAsk v = new DungeonRpcCreateTutorialAsk();
		v.RoleId = m_RoleId;
		v.DungeonConfigId = m_DungeonConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateTutorialAsk v)
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
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateTutorialAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateTutorialAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateTutorialAsk>(protoMS);
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
//创建序章副本回应封装类
[System.Serializable]
public class DungeonRpcCreateTutorialReplyWraper
{

	//构造函数
	public DungeonRpcCreateTutorialReplyWraper()
	{
		 m_Result = -1;
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateTutorialReply ToPB()
	{
		DungeonRpcCreateTutorialReply v = new DungeonRpcCreateTutorialReply();
		v.Result = m_Result;
		v.DungeonConfigId = m_DungeonConfigId;
		v.SceneConfigId = m_SceneConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateTutorialReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonConfigId = v.DungeonConfigId;
		m_SceneConfigId = v.SceneConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateTutorialReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateTutorialReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateTutorialReply>(protoMS);
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
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
	}


};
//强制退出序章请求封装类
[System.Serializable]
public class DungeonRpcQuitTutorialAskWraper
{

	//构造函数
	public DungeonRpcQuitTutorialAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcQuitTutorialAsk ToPB()
	{
		DungeonRpcQuitTutorialAsk v = new DungeonRpcQuitTutorialAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcQuitTutorialAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcQuitTutorialAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcQuitTutorialAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcQuitTutorialAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//强制退出序章回应封装类
[System.Serializable]
public class DungeonRpcQuitTutorialReplyWraper
{

	//构造函数
	public DungeonRpcQuitTutorialReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcQuitTutorialReply ToPB()
	{
		DungeonRpcQuitTutorialReply v = new DungeonRpcQuitTutorialReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcQuitTutorialReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcQuitTutorialReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcQuitTutorialReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcQuitTutorialReply>(protoMS);
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
//副本目标通知封装类
[System.Serializable]
public class DungeonRpcDungeonTargetNotifyWraper
{

	//构造函数
	public DungeonRpcDungeonTargetNotifyWraper()
	{
		m_DungeonTarget = new List<DungeonTargetWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_DungeonTarget = new List<DungeonTargetWraper>();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonTargetNotify ToPB()
	{
		DungeonRpcDungeonTargetNotify v = new DungeonRpcDungeonTargetNotify();
		for (int i=0; i<(int)m_DungeonTarget.Count; i++)
			v.DungeonTarget.Add( m_DungeonTarget[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonTargetNotify v)
	{
        if (v == null)
            return;
		m_DungeonTarget.Clear();
		for( int i=0; i<v.DungeonTarget.Count; i++)
			m_DungeonTarget.Add( new DungeonTargetWraper());
		for( int i=0; i<v.DungeonTarget.Count; i++)
			m_DungeonTarget[i].FromPB(v.DungeonTarget[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonTargetNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonTargetNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonTargetNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//DungeonTarget
	public List<DungeonTargetWraper> m_DungeonTarget;
	public int SizeDungeonTarget()
	{
		return m_DungeonTarget.Count;
	}
	public List<DungeonTargetWraper> GetDungeonTarget()
	{
		return m_DungeonTarget;
	}
	public DungeonTargetWraper GetDungeonTarget(int Index)
	{
		if(Index<0 || Index>=(int)m_DungeonTarget.Count)
			return new DungeonTargetWraper();
		return m_DungeonTarget[Index];
	}
	public void SetDungeonTarget( List<DungeonTargetWraper> v )
	{
		m_DungeonTarget=v;
	}
	public void SetDungeonTarget( int Index, DungeonTargetWraper v )
	{
		if(Index<0 || Index>=(int)m_DungeonTarget.Count)
			return;
		m_DungeonTarget[Index] = v;
	}
	public void AddDungeonTarget( DungeonTargetWraper v )
	{
		m_DungeonTarget.Add(v);
	}
	public void ClearDungeonTarget( )
	{
		m_DungeonTarget.Clear();
	}


};
//副本子任务完成情况通知封装类
[System.Serializable]
public class DungeonRpcTargetContentChangeNotifyWraper
{

	//构造函数
	public DungeonRpcTargetContentChangeNotifyWraper()
	{
		 m_Index = -1;
		 m_SubIndex = -1;
		 m_CurCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_SubIndex = -1;
		 m_CurCount = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcTargetContentChangeNotify ToPB()
	{
		DungeonRpcTargetContentChangeNotify v = new DungeonRpcTargetContentChangeNotify();
		v.Index = m_Index;
		v.SubIndex = m_SubIndex;
		v.CurCount = m_CurCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcTargetContentChangeNotify v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_SubIndex = v.SubIndex;
		m_CurCount = v.CurCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcTargetContentChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcTargetContentChangeNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcTargetContentChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标序号
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//子任务序号
	public int m_SubIndex;
	public int SubIndex
	{
		get { return m_SubIndex;}
		set { m_SubIndex = value; }
	}
	//当前完成情况
	public int m_CurCount;
	public int CurCount
	{
		get { return m_CurCount;}
		set { m_CurCount = value; }
	}


};
//副本提示通知封装类
[System.Serializable]
public class DungeonRpcDungeon_NotifyNotifyWraper
{

	//构造函数
	public DungeonRpcDungeon_NotifyNotifyWraper()
	{
		 m_TextId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TextId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeon_NotifyNotify ToPB()
	{
		DungeonRpcDungeon_NotifyNotify v = new DungeonRpcDungeon_NotifyNotify();
		v.TextId = m_TextId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeon_NotifyNotify v)
	{
        if (v == null)
            return;
		m_TextId = v.TextId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeon_NotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeon_NotifyNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeon_NotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//副本提示id
	public int m_TextId;
	public int TextId
	{
		get { return m_TextId;}
		set { m_TextId = value; }
	}


};
