
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBLobbyServer.cs
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


//获取服务器列表请求封装类
[System.Serializable]
public class LobbyServerRpcGetServerListAskWraper
{

	//构造函数
	public LobbyServerRpcGetServerListAskWraper()
	{
		 m_Sdk_user_id = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Sdk_user_id = "";

	}

 	//转化成Protobuffer类型函数
	public LobbyServerRpcGetServerListAsk ToPB()
	{
		LobbyServerRpcGetServerListAsk v = new LobbyServerRpcGetServerListAsk();
		v.Sdk_user_id = m_Sdk_user_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LobbyServerRpcGetServerListAsk v)
	{
        if (v == null)
            return;
		m_Sdk_user_id = v.Sdk_user_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LobbyServerRpcGetServerListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LobbyServerRpcGetServerListAsk pb = ProtoBuf.Serializer.Deserialize<LobbyServerRpcGetServerListAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//sdk_user_id
	public string m_Sdk_user_id;
	public string Sdk_user_id
	{
		get { return m_Sdk_user_id;}
		set { m_Sdk_user_id = value; }
	}


};
//获取服务器列表回应封装类
[System.Serializable]
public class LobbyServerRpcGetServerListReplyWraper
{

	//构造函数
	public LobbyServerRpcGetServerListReplyWraper()
	{
		 m_Result = -1;
		m_Server_list = new List<ServerInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Server_list = new List<ServerInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public LobbyServerRpcGetServerListReply ToPB()
	{
		LobbyServerRpcGetServerListReply v = new LobbyServerRpcGetServerListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Server_list.Count; i++)
			v.Server_list.Add( m_Server_list[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LobbyServerRpcGetServerListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Server_list.Clear();
		for( int i=0; i<v.Server_list.Count; i++)
			m_Server_list.Add( new ServerInfoWraper());
		for( int i=0; i<v.Server_list.Count; i++)
			m_Server_list[i].FromPB(v.Server_list[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LobbyServerRpcGetServerListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LobbyServerRpcGetServerListReply pb = ProtoBuf.Serializer.Deserialize<LobbyServerRpcGetServerListReply>(protoMS);
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
	//服务器列表
	public List<ServerInfoWraper> m_Server_list;
	public int SizeServer_list()
	{
		return m_Server_list.Count;
	}
	public List<ServerInfoWraper> GetServer_list()
	{
		return m_Server_list;
	}
	public ServerInfoWraper GetServer_list(int Index)
	{
		if(Index<0 || Index>=(int)m_Server_list.Count)
			return new ServerInfoWraper();
		return m_Server_list[Index];
	}
	public void SetServer_list( List<ServerInfoWraper> v )
	{
		m_Server_list=v;
	}
	public void SetServer_list( int Index, ServerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Server_list.Count)
			return;
		m_Server_list[Index] = v;
	}
	public void AddServer_list( ServerInfoWraper v )
	{
		m_Server_list.Add(v);
	}
	public void ClearServer_list( )
	{
		m_Server_list.Clear();
	}


};
