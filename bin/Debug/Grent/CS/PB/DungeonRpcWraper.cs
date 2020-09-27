
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
		 m_Exploits = new DungeonExploitsWraper();
		 m_Exp = -1;
		m_UiItemInfoList = new List<ItemObjWraper>();
		 m_Gold = -1;
		 m_DungeonPassTime = -1;
		 m_ForceRetreatSceneTime = -1;
		 m_RemainTime = -1;
		 m_Starbattleid = -1;
		 m_SceneType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SettlementResult = -1;
		 m_Exploits = new DungeonExploitsWraper();
		 m_Exp = -1;
		m_UiItemInfoList = new List<ItemObjWraper>();
		 m_Gold = -1;
		 m_DungeonPassTime = -1;
		 m_ForceRetreatSceneTime = -1;
		 m_RemainTime = -1;
		 m_Starbattleid = -1;
		 m_SceneType = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcSettlementNotify ToPB()
	{
		DungeonRpcSettlementNotify v = new DungeonRpcSettlementNotify();
		v.SettlementResult = m_SettlementResult;
		v.Exploits = m_Exploits.ToPB();
		v.Exp = m_Exp;
		for (int i=0; i<(int)m_UiItemInfoList.Count; i++)
			v.UiItemInfoList.Add( m_UiItemInfoList[i].ToPB());
		v.Gold = m_Gold;
		v.DungeonPassTime = m_DungeonPassTime;
		v.ForceRetreatSceneTime = m_ForceRetreatSceneTime;
		v.RemainTime = m_RemainTime;
		v.Starbattleid = m_Starbattleid;
		v.SceneType = m_SceneType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcSettlementNotify v)
	{
        if (v == null)
            return;
		m_SettlementResult = v.SettlementResult;
		m_Exploits.FromPB(v.Exploits);
		m_Exp = v.Exp;
		m_UiItemInfoList.Clear();
		for( int i=0; i<v.UiItemInfoList.Count; i++)
			m_UiItemInfoList.Add( new ItemObjWraper());
		for( int i=0; i<v.UiItemInfoList.Count; i++)
			m_UiItemInfoList[i].FromPB(v.UiItemInfoList[i]);
		m_Gold = v.Gold;
		m_DungeonPassTime = v.DungeonPassTime;
		m_ForceRetreatSceneTime = v.ForceRetreatSceneTime;
		m_RemainTime = v.RemainTime;
		m_Starbattleid = v.Starbattleid;
		m_SceneType = v.SceneType;

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
	//战绩数据
	public DungeonExploitsWraper m_Exploits;
	public DungeonExploitsWraper Exploits
	{
		get { return m_Exploits;}
		set { m_Exploits = value; }
	}
	//本局经验
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//物品信息
	public List<ItemObjWraper> m_UiItemInfoList;
	public int SizeUiItemInfoList()
	{
		return m_UiItemInfoList.Count;
	}
	public List<ItemObjWraper> GetUiItemInfoList()
	{
		return m_UiItemInfoList;
	}
	public ItemObjWraper GetUiItemInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_UiItemInfoList.Count)
			return new ItemObjWraper();
		return m_UiItemInfoList[Index];
	}
	public void SetUiItemInfoList( List<ItemObjWraper> v )
	{
		m_UiItemInfoList=v;
	}
	public void SetUiItemInfoList( int Index, ItemObjWraper v )
	{
		if(Index<0 || Index>=(int)m_UiItemInfoList.Count)
			return;
		m_UiItemInfoList[Index] = v;
	}
	public void AddUiItemInfoList( ItemObjWraper v )
	{
		m_UiItemInfoList.Add(v);
	}
	public void ClearUiItemInfoList( )
	{
		m_UiItemInfoList.Clear();
	}
	//金钱
	public int m_Gold;
	public int Gold
	{
		get { return m_Gold;}
		set { m_Gold = value; }
	}
	//通过时间
	public int m_DungeonPassTime;
	public int DungeonPassTime
	{
		get { return m_DungeonPassTime;}
		set { m_DungeonPassTime = value; }
	}
	//什么时候强制离开副本
	public Int64 m_ForceRetreatSceneTime;
	public Int64 ForceRetreatSceneTime
	{
		get { return m_ForceRetreatSceneTime;}
		set { m_ForceRetreatSceneTime = value; }
	}
	//剩下在副本里面的时间
	public Int64 m_RemainTime;
	public Int64 RemainTime
	{
		get { return m_RemainTime;}
		set { m_RemainTime = value; }
	}
	//星耀NPCid
	public int m_Starbattleid;
	public int Starbattleid
	{
		get { return m_Starbattleid;}
		set { m_Starbattleid = value; }
	}
	//场景的类型
	public int m_SceneType;
	public int SceneType
	{
		get { return m_SceneType;}
		set { m_SceneType = value; }
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
		 m_BeginTime = 0;
		 m_Data = new DungeonDataWraper();
		 m_Exploits = new DungeonExploitsWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BeginTime = 0;
		 m_Data = new DungeonDataWraper();
		 m_Exploits = new DungeonExploitsWraper();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonDataNotify ToPB()
	{
		DungeonRpcDungeonDataNotify v = new DungeonRpcDungeonDataNotify();
		v.BeginTime = m_BeginTime;
		v.Data = m_Data.ToPB();
		v.Exploits = m_Exploits.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonDataNotify v)
	{
        if (v == null)
            return;
		m_BeginTime = v.BeginTime;
		m_Data.FromPB(v.Data);
		m_Exploits.FromPB(v.Exploits);

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
	//副本数据
	public DungeonDataWraper m_Data;
	public DungeonDataWraper Data
	{
		get { return m_Data;}
		set { m_Data = value; }
	}
	//战绩数据
	public DungeonExploitsWraper m_Exploits;
	public DungeonExploitsWraper Exploits
	{
		get { return m_Exploits;}
		set { m_Exploits = value; }
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
		 m_Exploits = new DungeonExploitsWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Data = new DungeonDataWraper();
		 m_Exploits = new DungeonExploitsWraper();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonSyncReply ToPB()
	{
		DungeonRpcDungeonSyncReply v = new DungeonRpcDungeonSyncReply();
		v.Result = m_Result;
		v.Data = m_Data.ToPB();
		v.Exploits = m_Exploits.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Data.FromPB(v.Data);
		m_Exploits.FromPB(v.Exploits);

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
	//战绩数据
	public DungeonExploitsWraper m_Exploits;
	public DungeonExploitsWraper Exploits
	{
		get { return m_Exploits;}
		set { m_Exploits = value; }
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
//场景操作1请求封装类
[System.Serializable]
public class DungeonRpcSceneOperator1AskWraper
{

	//构造函数
	public DungeonRpcSceneOperator1AskWraper()
	{
		 m_OpCode = 0;
		 m_OpExtraParam = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OpCode = 0;
		 m_OpExtraParam = 0;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcSceneOperator1Ask ToPB()
	{
		DungeonRpcSceneOperator1Ask v = new DungeonRpcSceneOperator1Ask();
		v.OpCode = m_OpCode;
		v.OpExtraParam = m_OpExtraParam;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcSceneOperator1Ask v)
	{
        if (v == null)
            return;
		m_OpCode = v.OpCode;
		m_OpExtraParam = v.OpExtraParam;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcSceneOperator1Ask>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcSceneOperator1Ask pb = ProtoBuf.Serializer.Deserialize<DungeonRpcSceneOperator1Ask>(protoMS);
		FromPB(pb);
		return true;
	}

	//0:转罗盘，1翻牌子
	public int m_OpCode;
	public int OpCode
	{
		get { return m_OpCode;}
		set { m_OpCode = value; }
	}
	//额外参数
	public int m_OpExtraParam;
	public int OpExtraParam
	{
		get { return m_OpExtraParam;}
		set { m_OpExtraParam = value; }
	}


};
//场景操作1回应封装类
[System.Serializable]
public class DungeonRpcSceneOperator1ReplyWraper
{

	//构造函数
	public DungeonRpcSceneOperator1ReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcSceneOperator1Reply ToPB()
	{
		DungeonRpcSceneOperator1Reply v = new DungeonRpcSceneOperator1Reply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcSceneOperator1Reply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcSceneOperator1Reply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcSceneOperator1Reply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcSceneOperator1Reply>(protoMS);
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
//强制进入下一层通知封装类
[System.Serializable]
public class DungeonRpcForceEnterNextDungeonLayerNotifyWraper
{

	//构造函数
	public DungeonRpcForceEnterNextDungeonLayerNotifyWraper()
	{
		 m_NextLayer = 1;
		 m_Breward = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NextLayer = 1;
		 m_Breward = false;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcForceEnterNextDungeonLayerNotify ToPB()
	{
		DungeonRpcForceEnterNextDungeonLayerNotify v = new DungeonRpcForceEnterNextDungeonLayerNotify();
		v.NextLayer = m_NextLayer;
		v.Breward = m_Breward;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcForceEnterNextDungeonLayerNotify v)
	{
        if (v == null)
            return;
		m_NextLayer = v.NextLayer;
		m_Breward = v.Breward;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcForceEnterNextDungeonLayerNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcForceEnterNextDungeonLayerNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcForceEnterNextDungeonLayerNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//下一层是多少层
	public int m_NextLayer;
	public int NextLayer
	{
		get { return m_NextLayer;}
		set { m_NextLayer = value; }
	}
	//本层是否奖励(公会副本)
	public bool m_Breward;
	public bool Breward
	{
		get { return m_Breward;}
		set { m_Breward = value; }
	}


};
//副本更新通知封装类
[System.Serializable]
public class DungeonRpcDungeonRewardUpdateNotifyWraper
{

	//构造函数
	public DungeonRpcDungeonRewardUpdateNotifyWraper()
	{
		m_OpenRoleIdList = new List<UInt64>();
		 m_NewRoleId = 0;
		 m_NewIndex = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		m_OpenRoleIdList = new List<UInt64>();
		 m_NewRoleId = 0;
		 m_NewIndex = 0;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonRewardUpdateNotify ToPB()
	{
		DungeonRpcDungeonRewardUpdateNotify v = new DungeonRpcDungeonRewardUpdateNotify();
		for (int i=0; i<(int)m_OpenRoleIdList.Count; i++)
			v.OpenRoleIdList.Add( m_OpenRoleIdList[i]);
		v.NewRoleId = m_NewRoleId;
		v.NewIndex = m_NewIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonRewardUpdateNotify v)
	{
        if (v == null)
            return;
		m_OpenRoleIdList.Clear();
		for( int i=0; i<v.OpenRoleIdList.Count; i++)
			m_OpenRoleIdList.Add(v.OpenRoleIdList[i]);
		m_NewRoleId = v.NewRoleId;
		m_NewIndex = v.NewIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonRewardUpdateNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonRewardUpdateNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonRewardUpdateNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家的唯一id列表
	public List<UInt64> m_OpenRoleIdList;
	public int SizeOpenRoleIdList()
	{
		return m_OpenRoleIdList.Count;
	}
	public List<UInt64> GetOpenRoleIdList()
	{
		return m_OpenRoleIdList;
	}
	public UInt64 GetOpenRoleIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_OpenRoleIdList.Count)
			return 0;
		return m_OpenRoleIdList[Index];
	}
	public void SetOpenRoleIdList( List<UInt64> v )
	{
		m_OpenRoleIdList=v;
	}
	public void SetOpenRoleIdList( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_OpenRoleIdList.Count)
			return;
		m_OpenRoleIdList[Index] = v;
	}
	public void AddOpenRoleIdList( UInt64 v=0 )
	{
		m_OpenRoleIdList.Add(v);
	}
	public void ClearOpenRoleIdList( )
	{
		m_OpenRoleIdList.Clear();
	}
	//新翻牌的人
	public UInt64 m_NewRoleId;
	public UInt64 NewRoleId
	{
		get { return m_NewRoleId;}
		set { m_NewRoleId = value; }
	}
	//下标
	public int m_NewIndex;
	public int NewIndex
	{
		get { return m_NewIndex;}
		set { m_NewIndex = value; }
	}


};
//全部层胜利通知封装类
[System.Serializable]
public class DungeonRpcVictoryOfAllLayerNotifyWraper
{

	//构造函数
	public DungeonRpcVictoryOfAllLayerNotifyWraper()
	{
		 m_LastLayer = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LastLayer = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcVictoryOfAllLayerNotify ToPB()
	{
		DungeonRpcVictoryOfAllLayerNotify v = new DungeonRpcVictoryOfAllLayerNotify();
		v.LastLayer = m_LastLayer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcVictoryOfAllLayerNotify v)
	{
        if (v == null)
            return;
		m_LastLayer = v.LastLayer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcVictoryOfAllLayerNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcVictoryOfAllLayerNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcVictoryOfAllLayerNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//最后层数
	public int m_LastLayer;
	public int LastLayer
	{
		get { return m_LastLayer;}
		set { m_LastLayer = value; }
	}


};
//层数开始通知封装类
[System.Serializable]
public class DungeonRpcLayerBeginNotifyWraper
{

	//构造函数
	public DungeonRpcLayerBeginNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcLayerBeginNotify ToPB()
	{
		DungeonRpcLayerBeginNotify v = new DungeonRpcLayerBeginNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcLayerBeginNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcLayerBeginNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcLayerBeginNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcLayerBeginNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//当前层结算通知封装类
[System.Serializable]
public class DungeonRpcLayerSettlementNotifyWraper
{

	//构造函数
	public DungeonRpcLayerSettlementNotifyWraper()
	{
		 m_NextLayer = 1;
		m_RewardList = new List<PBUIRewardDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NextLayer = 1;
		m_RewardList = new List<PBUIRewardDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcLayerSettlementNotify ToPB()
	{
		DungeonRpcLayerSettlementNotify v = new DungeonRpcLayerSettlementNotify();
		v.NextLayer = m_NextLayer;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcLayerSettlementNotify v)
	{
        if (v == null)
            return;
		m_NextLayer = v.NextLayer;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add( new PBUIRewardDataWraper());
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList[i].FromPB(v.RewardList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcLayerSettlementNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcLayerSettlementNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcLayerSettlementNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//下一层是多少层
	public int m_NextLayer;
	public int NextLayer
	{
		get { return m_NextLayer;}
		set { m_NextLayer = value; }
	}
	//奖励列表
	public List<PBUIRewardDataWraper> m_RewardList;
	public int SizeRewardList()
	{
		return m_RewardList.Count;
	}
	public List<PBUIRewardDataWraper> GetRewardList()
	{
		return m_RewardList;
	}
	public PBUIRewardDataWraper GetRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return new PBUIRewardDataWraper();
		return m_RewardList[Index];
	}
	public void SetRewardList( List<PBUIRewardDataWraper> v )
	{
		m_RewardList=v;
	}
	public void SetRewardList( int Index, PBUIRewardDataWraper v )
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return;
		m_RewardList[Index] = v;
	}
	public void AddRewardList( PBUIRewardDataWraper v )
	{
		m_RewardList.Add(v);
	}
	public void ClearRewardList( )
	{
		m_RewardList.Clear();
	}


};
//场景操作通知通知封装类
[System.Serializable]
public class DungeonRpcSceneOperatorNNotifyWraper
{

	//构造函数
	public DungeonRpcSceneOperatorNNotifyWraper()
	{
		 m_OpCode = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OpCode = 0;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcSceneOperatorNNotify ToPB()
	{
		DungeonRpcSceneOperatorNNotify v = new DungeonRpcSceneOperatorNNotify();
		v.OpCode = m_OpCode;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcSceneOperatorNNotify v)
	{
        if (v == null)
            return;
		m_OpCode = v.OpCode;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcSceneOperatorNNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcSceneOperatorNNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcSceneOperatorNNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//0:转罗盘，1翻牌子
	public int m_OpCode;
	public int OpCode
	{
		get { return m_OpCode;}
		set { m_OpCode = value; }
	}


};
//进入爬塔副本通知封装类
[System.Serializable]
public class DungeonRpcEnterLayerDungeonNotifyWraper
{

	//构造函数
	public DungeonRpcEnterLayerDungeonNotifyWraper()
	{
		 m_CurrentLayer = -1;
		 m_CurentLayerRemainTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CurrentLayer = -1;
		 m_CurentLayerRemainTime = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcEnterLayerDungeonNotify ToPB()
	{
		DungeonRpcEnterLayerDungeonNotify v = new DungeonRpcEnterLayerDungeonNotify();
		v.CurrentLayer = m_CurrentLayer;
		v.CurentLayerRemainTime = m_CurentLayerRemainTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcEnterLayerDungeonNotify v)
	{
        if (v == null)
            return;
		m_CurrentLayer = v.CurrentLayer;
		m_CurentLayerRemainTime = v.CurentLayerRemainTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcEnterLayerDungeonNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcEnterLayerDungeonNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcEnterLayerDungeonNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//当前层
	public int m_CurrentLayer;
	public int CurrentLayer
	{
		get { return m_CurrentLayer;}
		set { m_CurrentLayer = value; }
	}
	//当前层剩余时间
	public int m_CurentLayerRemainTime;
	public int CurentLayerRemainTime
	{
		get { return m_CurentLayerRemainTime;}
		set { m_CurentLayerRemainTime = value; }
	}


};
//副本战绩数据通知封装类
[System.Serializable]
public class DungeonRpcDungeonExploitsNotifyWraper
{

	//构造函数
	public DungeonRpcDungeonExploitsNotifyWraper()
	{
		 m_Exploits = new DungeonExploitsWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Exploits = new DungeonExploitsWraper();

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcDungeonExploitsNotify ToPB()
	{
		DungeonRpcDungeonExploitsNotify v = new DungeonRpcDungeonExploitsNotify();
		v.Exploits = m_Exploits.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcDungeonExploitsNotify v)
	{
        if (v == null)
            return;
		m_Exploits.FromPB(v.Exploits);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcDungeonExploitsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcDungeonExploitsNotify pb = ProtoBuf.Serializer.Deserialize<DungeonRpcDungeonExploitsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//战绩数据
	public DungeonExploitsWraper m_Exploits;
	public DungeonExploitsWraper Exploits
	{
		get { return m_Exploits;}
		set { m_Exploits = value; }
	}


};
//使用机器人组队进副本请求封装类
[System.Serializable]
public class DungeonRpcCreateDungeonWithRobotAskWraper
{

	//构造函数
	public DungeonRpcCreateDungeonWithRobotAskWraper()
	{
		 m_DungeonConfigId = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DungeonConfigId = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonWithRobotAsk ToPB()
	{
		DungeonRpcCreateDungeonWithRobotAsk v = new DungeonRpcCreateDungeonWithRobotAsk();
		v.DungeonConfigId = m_DungeonConfigId;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonWithRobotAsk v)
	{
        if (v == null)
            return;
		m_DungeonConfigId = v.DungeonConfigId;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateDungeonWithRobotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateDungeonWithRobotAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateDungeonWithRobotAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//HumanRoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//使用机器人组队进副本回应封装类
[System.Serializable]
public class DungeonRpcCreateDungeonWithRobotReplyWraper
{

	//构造函数
	public DungeonRpcCreateDungeonWithRobotReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonWithRobotReply ToPB()
	{
		DungeonRpcCreateDungeonWithRobotReply v = new DungeonRpcCreateDungeonWithRobotReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonWithRobotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcCreateDungeonWithRobotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcCreateDungeonWithRobotReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcCreateDungeonWithRobotReply>(protoMS);
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
//使用挑战次数请求封装类
[System.Serializable]
public class DungeonRpcUseBossNumAskWraper
{

	//构造函数
	public DungeonRpcUseBossNumAskWraper()
	{
		 m_BUse = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BUse = false;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcUseBossNumAsk ToPB()
	{
		DungeonRpcUseBossNumAsk v = new DungeonRpcUseBossNumAsk();
		v.BUse = m_BUse;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcUseBossNumAsk v)
	{
        if (v == null)
            return;
		m_BUse = v.BUse;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcUseBossNumAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcUseBossNumAsk pb = ProtoBuf.Serializer.Deserialize<DungeonRpcUseBossNumAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//是否使用
	public bool m_BUse;
	public bool BUse
	{
		get { return m_BUse;}
		set { m_BUse = value; }
	}


};
//使用挑战次数回应封装类
[System.Serializable]
public class DungeonRpcUseBossNumReplyWraper
{

	//构造函数
	public DungeonRpcUseBossNumReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcUseBossNumReply ToPB()
	{
		DungeonRpcUseBossNumReply v = new DungeonRpcUseBossNumReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcUseBossNumReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonRpcUseBossNumReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonRpcUseBossNumReply pb = ProtoBuf.Serializer.Deserialize<DungeonRpcUseBossNumReply>(protoMS);
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
