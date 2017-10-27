
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBLogin.cs
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


//连接验证请求封装类
[System.Serializable]
public class LoginRpcConnectAskWraper
{

	//构造函数
	public LoginRpcConnectAskWraper()
	{
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcConnectAsk ToPB()
	{
		LoginRpcConnectAsk v = new LoginRpcConnectAsk();
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcConnectAsk v)
	{
        if (v == null)
            return;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcConnectAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcConnectAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcConnectAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//连接类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//连接验证回应封装类
[System.Serializable]
public class LoginRpcConnectReplyWraper
{

	//构造函数
	public LoginRpcConnectReplyWraper()
	{
		 m_Result = -9999;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcConnectReply ToPB()
	{
		LoginRpcConnectReply v = new LoginRpcConnectReply();
		v.Result = m_Result;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcConnectReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcConnectReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcConnectReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcConnectReply>(protoMS);
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
	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//登录请求封装类
[System.Serializable]
public class LoginRpcLoginAskWraper
{

	//构造函数
	public LoginRpcLoginAskWraper()
	{
		 m_Username = "";
		 m_Passwd = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Username = "";
		 m_Passwd = "";

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginAsk ToPB()
	{
		LoginRpcLoginAsk v = new LoginRpcLoginAsk();
		v.Username = m_Username;
		v.Passwd = m_Passwd;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginAsk v)
	{
        if (v == null)
            return;
		m_Username = v.Username;
		m_Passwd = v.Passwd;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//用户名
	public string m_Username;
	public string Username
	{
		get { return m_Username;}
		set { m_Username = value; }
	}
	//密码
	public string m_Passwd;
	public string Passwd
	{
		get { return m_Passwd;}
		set { m_Passwd = value; }
	}


};
//登录回应封装类
[System.Serializable]
public class LoginRpcLoginReplyWraper
{

	//构造函数
	public LoginRpcLoginReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginReply ToPB()
	{
		LoginRpcLoginReply v = new LoginRpcLoginReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginReply>(protoMS);
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
	//用户ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
