
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBBaseAttr.cs
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


//同步玩家数据请求封装类
[System.Serializable]
public class BaseAttrRpcSyncDataAskWraper
{

	//构造函数
	public BaseAttrRpcSyncDataAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public BaseAttrRpcSyncDataAsk ToPB()
	{
		BaseAttrRpcSyncDataAsk v = new BaseAttrRpcSyncDataAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrRpcSyncDataAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrRpcSyncDataAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrRpcSyncDataAsk pb = ProtoBuf.Serializer.Deserialize<BaseAttrRpcSyncDataAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步玩家数据回应封装类
[System.Serializable]
public class BaseAttrRpcSyncDataReplyWraper
{

	//构造函数
	public BaseAttrRpcSyncDataReplyWraper()
	{
		 m_Result = -9999;
		 m_UpdateData = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_UpdateData = new byte[0];

	}

 	//转化成Protobuffer类型函数
	public BaseAttrRpcSyncDataReply ToPB()
	{
		BaseAttrRpcSyncDataReply v = new BaseAttrRpcSyncDataReply();
		v.Result = m_Result;
		v.UpdateData = m_UpdateData;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrRpcSyncDataReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_UpdateData = v.UpdateData;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrRpcSyncDataReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrRpcSyncDataReply pb = ProtoBuf.Serializer.Deserialize<BaseAttrRpcSyncDataReply>(protoMS);
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
	//同步数据
	public byte[] m_UpdateData;
	public byte[] UpdateData
	{
		get { return m_UpdateData;}
		set { m_UpdateData = value; }
	}


};
//数据推送通知封装类
[System.Serializable]
public class BaseAttrRpcSyncNotifyWraper
{

	//构造函数
	public BaseAttrRpcSyncNotifyWraper()
	{
		 m_ObjId = -1;
		 m_UpdateData = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_UpdateData = new byte[0];

	}

 	//转化成Protobuffer类型函数
	public BaseAttrRpcSyncNotify ToPB()
	{
		BaseAttrRpcSyncNotify v = new BaseAttrRpcSyncNotify();
		v.ObjId = m_ObjId;
		v.UpdateData = m_UpdateData;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrRpcSyncNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_UpdateData = v.UpdateData;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrRpcSyncNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrRpcSyncNotify pb = ProtoBuf.Serializer.Deserialize<BaseAttrRpcSyncNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//更新数据
	public byte[] m_UpdateData;
	public byte[] UpdateData
	{
		get { return m_UpdateData;}
		set { m_UpdateData = value; }
	}


};
