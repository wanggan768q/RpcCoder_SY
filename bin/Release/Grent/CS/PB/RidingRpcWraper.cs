
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBRiding.cs
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


//上马请求封装类
[System.Serializable]
public class RidingRpcRidingAskWraper
{

	//构造函数
	public RidingRpcRidingAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public RidingRpcRidingAsk ToPB()
	{
		RidingRpcRidingAsk v = new RidingRpcRidingAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RidingRpcRidingAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RidingRpcRidingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RidingRpcRidingAsk pb = ProtoBuf.Serializer.Deserialize<RidingRpcRidingAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//上马回应封装类
[System.Serializable]
public class RidingRpcRidingReplyWraper
{

	//构造函数
	public RidingRpcRidingReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public RidingRpcRidingReply ToPB()
	{
		RidingRpcRidingReply v = new RidingRpcRidingReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RidingRpcRidingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RidingRpcRidingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RidingRpcRidingReply pb = ProtoBuf.Serializer.Deserialize<RidingRpcRidingReply>(protoMS);
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
//下马请求封装类
[System.Serializable]
public class RidingRpcUnRidingAskWraper
{

	//构造函数
	public RidingRpcUnRidingAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public RidingRpcUnRidingAsk ToPB()
	{
		RidingRpcUnRidingAsk v = new RidingRpcUnRidingAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RidingRpcUnRidingAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RidingRpcUnRidingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RidingRpcUnRidingAsk pb = ProtoBuf.Serializer.Deserialize<RidingRpcUnRidingAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//下马回应封装类
[System.Serializable]
public class RidingRpcUnRidingReplyWraper
{

	//构造函数
	public RidingRpcUnRidingReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public RidingRpcUnRidingReply ToPB()
	{
		RidingRpcUnRidingReply v = new RidingRpcUnRidingReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RidingRpcUnRidingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RidingRpcUnRidingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RidingRpcUnRidingReply pb = ProtoBuf.Serializer.Deserialize<RidingRpcUnRidingReply>(protoMS);
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
