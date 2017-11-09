
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBWorldServer.cs
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


//通知世界服务器切换场景请求封装类
[System.Serializable]
public class WorldServerRpcChangeSceneAskWraper
{

	//构造函数
	public WorldServerRpcChangeSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeSceneAsk ToPB()
	{
		WorldServerRpcChangeSceneAsk v = new WorldServerRpcChangeSceneAsk();
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;
		v.MemId = m_MemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;
		m_MemId = v.MemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeSceneAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeSceneAsk>(protoMS);
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
	//场景id
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}
	//玩家的内存id
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}


};
//通知世界服务器切换场景回应封装类
[System.Serializable]
public class WorldServerRpcChangeSceneReplyWraper
{

	//构造函数
	public WorldServerRpcChangeSceneReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeSceneReply ToPB()
	{
		WorldServerRpcChangeSceneReply v = new WorldServerRpcChangeSceneReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;
		v.MemId = m_MemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;
		m_MemId = v.MemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeSceneReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeSceneReply>(protoMS);
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
	//玩家的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}
	//玩家的内存id
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}


};
//进入场景请求封装类
[System.Serializable]
public class WorldServerRpcEnterSceneAskWraper
{

	//构造函数
	public WorldServerRpcEnterSceneAskWraper()
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
	public WorldServerRpcEnterSceneAsk ToPB()
	{
		WorldServerRpcEnterSceneAsk v = new WorldServerRpcEnterSceneAsk();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcEnterSceneAsk v)
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
		ProtoBuf.Serializer.Serialize<WorldServerRpcEnterSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcEnterSceneAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcEnterSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色id
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
//进入场景回应封装类
[System.Serializable]
public class WorldServerRpcEnterSceneReplyWraper
{

	//构造函数
	public WorldServerRpcEnterSceneReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcEnterSceneReply ToPB()
	{
		WorldServerRpcEnterSceneReply v = new WorldServerRpcEnterSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcEnterSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcEnterSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcEnterSceneReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcEnterSceneReply>(protoMS);
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
