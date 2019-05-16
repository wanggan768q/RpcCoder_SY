
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBVechicle.cs
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


//退出载具请求封装类
[System.Serializable]
public class VechicleRpcQuitVechileAskWraper
{

	//构造函数
	public VechicleRpcQuitVechileAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public VechicleRpcQuitVechileAsk ToPB()
	{
		VechicleRpcQuitVechileAsk v = new VechicleRpcQuitVechileAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(VechicleRpcQuitVechileAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<VechicleRpcQuitVechileAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		VechicleRpcQuitVechileAsk pb = ProtoBuf.Serializer.Deserialize<VechicleRpcQuitVechileAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//退出载具回应封装类
[System.Serializable]
public class VechicleRpcQuitVechileReplyWraper
{

	//构造函数
	public VechicleRpcQuitVechileReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public VechicleRpcQuitVechileReply ToPB()
	{
		VechicleRpcQuitVechileReply v = new VechicleRpcQuitVechileReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(VechicleRpcQuitVechileReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<VechicleRpcQuitVechileReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		VechicleRpcQuitVechileReply pb = ProtoBuf.Serializer.Deserialize<VechicleRpcQuitVechileReply>(protoMS);
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
