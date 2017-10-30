
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBServerModel.cs
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


//服务器使用登录请求封装类
[System.Serializable]
public class ServerModelRpcLoginAskWraper
{

	//构造函数
	public ServerModelRpcLoginAskWraper()
	{
		 m_Result = -1;
		 m_Type = -1;
		 m_TestString = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Type = -1;
		 m_TestString = "";

	}

 	//转化成Protobuffer类型函数
	public ServerModelRpcLoginAsk ToPB()
	{
		ServerModelRpcLoginAsk v = new ServerModelRpcLoginAsk();
		v.Result = m_Result;
		v.Type = m_Type;
		v.TestString = m_TestString;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ServerModelRpcLoginAsk v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Type = v.Type;
		m_TestString = v.TestString;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ServerModelRpcLoginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ServerModelRpcLoginAsk pb = ProtoBuf.Serializer.Deserialize<ServerModelRpcLoginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//1111
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//连接类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//TestString
	public string m_TestString;
	public string TestString
	{
		get { return m_TestString;}
		set { m_TestString = value; }
	}


};
//服务器使用登录回应封装类
[System.Serializable]
public class ServerModelRpcLoginReplyWraper
{

	//构造函数
	public ServerModelRpcLoginReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public ServerModelRpcLoginReply ToPB()
	{
		ServerModelRpcLoginReply v = new ServerModelRpcLoginReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ServerModelRpcLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ServerModelRpcLoginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ServerModelRpcLoginReply pb = ProtoBuf.Serializer.Deserialize<ServerModelRpcLoginReply>(protoMS);
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
