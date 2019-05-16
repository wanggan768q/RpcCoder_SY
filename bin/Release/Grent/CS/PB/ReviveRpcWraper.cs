
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBRevive.cs
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


//死亡信息通知封装类
[System.Serializable]
public class ReviveRpcDieNotifyNotifyWraper
{

	//构造函数
	public ReviveRpcDieNotifyNotifyWraper()
	{
		 m_KillerId = -1;
		 m_KillerName = "";
		 m_LeftTime = -1;
		 m_KillerType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KillerId = -1;
		 m_KillerName = "";
		 m_LeftTime = -1;
		 m_KillerType = -1;

	}

 	//转化成Protobuffer类型函数
	public ReviveRpcDieNotifyNotify ToPB()
	{
		ReviveRpcDieNotifyNotify v = new ReviveRpcDieNotifyNotify();
		v.KillerId = m_KillerId;
		v.KillerName = m_KillerName;
		v.LeftTime = m_LeftTime;
		v.KillerType = m_KillerType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ReviveRpcDieNotifyNotify v)
	{
        if (v == null)
            return;
		m_KillerId = v.KillerId;
		m_KillerName = v.KillerName;
		m_LeftTime = v.LeftTime;
		m_KillerType = v.KillerType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ReviveRpcDieNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ReviveRpcDieNotifyNotify pb = ProtoBuf.Serializer.Deserialize<ReviveRpcDieNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//击杀者ID
	public int m_KillerId;
	public int KillerId
	{
		get { return m_KillerId;}
		set { m_KillerId = value; }
	}
	//击杀者名字
	public string m_KillerName;
	public string KillerName
	{
		get { return m_KillerName;}
		set { m_KillerName = value; }
	}
	//就近复活CD时间
	public int m_LeftTime;
	public int LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}
	//击杀者类型
	public int m_KillerType;
	public int KillerType
	{
		get { return m_KillerType;}
		set { m_KillerType = value; }
	}


};
//请求复活请求封装类
[System.Serializable]
public class ReviveRpcSceneReviveAskWraper
{

	//构造函数
	public ReviveRpcSceneReviveAskWraper()
	{
		 m_ReviveType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ReviveType = -1;

	}

 	//转化成Protobuffer类型函数
	public ReviveRpcSceneReviveAsk ToPB()
	{
		ReviveRpcSceneReviveAsk v = new ReviveRpcSceneReviveAsk();
		v.ReviveType = m_ReviveType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ReviveRpcSceneReviveAsk v)
	{
        if (v == null)
            return;
		m_ReviveType = v.ReviveType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ReviveRpcSceneReviveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ReviveRpcSceneReviveAsk pb = ProtoBuf.Serializer.Deserialize<ReviveRpcSceneReviveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//复活类型
	public int m_ReviveType;
	public int ReviveType
	{
		get { return m_ReviveType;}
		set { m_ReviveType = value; }
	}


};
//请求复活回应封装类
[System.Serializable]
public class ReviveRpcSceneReviveReplyWraper
{

	//构造函数
	public ReviveRpcSceneReviveReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ReviveRpcSceneReviveReply ToPB()
	{
		ReviveRpcSceneReviveReply v = new ReviveRpcSceneReviveReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ReviveRpcSceneReviveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ReviveRpcSceneReviveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ReviveRpcSceneReviveReply pb = ProtoBuf.Serializer.Deserialize<ReviveRpcSceneReviveReply>(protoMS);
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
