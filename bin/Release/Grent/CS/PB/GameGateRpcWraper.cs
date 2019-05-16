
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBGameGate.cs
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


//GameGateChangeScene通知封装类
[System.Serializable]
public class GameGateRpcGameGateChangeSceneNotifyWraper
{

	//构造函数
	public GameGateRpcGameGateChangeSceneNotifyWraper()
	{
		 m_RoleID = 0;
		 m_ServerID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_ServerID = -1;

	}

 	//转化成Protobuffer类型函数
	public GameGateRpcGameGateChangeSceneNotify ToPB()
	{
		GameGateRpcGameGateChangeSceneNotify v = new GameGateRpcGameGateChangeSceneNotify();
		v.RoleID = m_RoleID;
		v.ServerID = m_ServerID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameGateRpcGameGateChangeSceneNotify v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_ServerID = v.ServerID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameGateRpcGameGateChangeSceneNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameGateRpcGameGateChangeSceneNotify pb = ProtoBuf.Serializer.Deserialize<GameGateRpcGameGateChangeSceneNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//ServerID
	public int m_ServerID;
	public int ServerID
	{
		get { return m_ServerID;}
		set { m_ServerID = value; }
	}


};
