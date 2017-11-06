
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_DungeonConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcCreateDungeonReply ToPB()
	{
		DungeonRpcCreateDungeonReply v = new DungeonRpcCreateDungeonReply();
		v.Result = m_Result;
		v.DungeonConfigId = m_DungeonConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcCreateDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonConfigId = v.DungeonConfigId;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public DungeonRpcExitDungeonReply ToPB()
	{
		DungeonRpcExitDungeonReply v = new DungeonRpcExitDungeonReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonRpcExitDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

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


};
