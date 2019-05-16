
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBGate.cs
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


//Ping请求封装类
[System.Serializable]
public class GateRpcPingAskWraper
{

	//构造函数
	public GateRpcPingAskWraper()
	{
		 m_Sequence = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Sequence = 0;

	}

 	//转化成Protobuffer类型函数
	public GateRpcPingAsk ToPB()
	{
		GateRpcPingAsk v = new GateRpcPingAsk();
		v.Sequence = m_Sequence;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GateRpcPingAsk v)
	{
        if (v == null)
            return;
		m_Sequence = v.Sequence;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GateRpcPingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GateRpcPingAsk pb = ProtoBuf.Serializer.Deserialize<GateRpcPingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//序列
	public UInt64 m_Sequence;
	public UInt64 Sequence
	{
		get { return m_Sequence;}
		set { m_Sequence = value; }
	}


};
//Ping回应封装类
[System.Serializable]
public class GateRpcPingReplyWraper
{

	//构造函数
	public GateRpcPingReplyWraper()
	{
		 m_Result = -1;
		 m_Sequence = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Sequence = 0;

	}

 	//转化成Protobuffer类型函数
	public GateRpcPingReply ToPB()
	{
		GateRpcPingReply v = new GateRpcPingReply();
		v.Result = m_Result;
		v.Sequence = m_Sequence;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GateRpcPingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Sequence = v.Sequence;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GateRpcPingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GateRpcPingReply pb = ProtoBuf.Serializer.Deserialize<GateRpcPingReply>(protoMS);
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
	//序列
	public UInt64 m_Sequence;
	public UInt64 Sequence
	{
		get { return m_Sequence;}
		set { m_Sequence = value; }
	}


};
