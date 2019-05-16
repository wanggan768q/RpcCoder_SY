
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBTreasureMap.cs
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


//同步请求封装类
[System.Serializable]
public class TreasureMapRpcTreasureMapSyncAskWraper
{

	//构造函数
	public TreasureMapRpcTreasureMapSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TreasureMapRpcTreasureMapSyncAsk ToPB()
	{
		TreasureMapRpcTreasureMapSyncAsk v = new TreasureMapRpcTreasureMapSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureMapRpcTreasureMapSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureMapRpcTreasureMapSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureMapRpcTreasureMapSyncAsk pb = ProtoBuf.Serializer.Deserialize<TreasureMapRpcTreasureMapSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class TreasureMapRpcTreasureMapSyncReplyWraper
{

	//构造函数
	public TreasureMapRpcTreasureMapSyncReplyWraper()
	{
		 m_Result = -1;
		 m_TreasureMapId = -1;
		 m_HighTreasureMapId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureMapId = -1;
		 m_HighTreasureMapId = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureMapRpcTreasureMapSyncReply ToPB()
	{
		TreasureMapRpcTreasureMapSyncReply v = new TreasureMapRpcTreasureMapSyncReply();
		v.Result = m_Result;
		v.TreasureMapId = m_TreasureMapId;
		v.HighTreasureMapId = m_HighTreasureMapId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureMapRpcTreasureMapSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureMapId = v.TreasureMapId;
		m_HighTreasureMapId = v.HighTreasureMapId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureMapRpcTreasureMapSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureMapRpcTreasureMapSyncReply pb = ProtoBuf.Serializer.Deserialize<TreasureMapRpcTreasureMapSyncReply>(protoMS);
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
	//藏宝图ID
	public int m_TreasureMapId;
	public int TreasureMapId
	{
		get { return m_TreasureMapId;}
		set { m_TreasureMapId = value; }
	}
	//高级藏宝图ID
	public int m_HighTreasureMapId;
	public int HighTreasureMapId
	{
		get { return m_HighTreasureMapId;}
		set { m_HighTreasureMapId = value; }
	}


};
//变化通知封装类
[System.Serializable]
public class TreasureMapRpcTreasureMapChangeNotifyWraper
{

	//构造函数
	public TreasureMapRpcTreasureMapChangeNotifyWraper()
	{
		 m_TreasureMapId = -1;
		 m_HighTreasureMapId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TreasureMapId = -1;
		 m_HighTreasureMapId = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureMapRpcTreasureMapChangeNotify ToPB()
	{
		TreasureMapRpcTreasureMapChangeNotify v = new TreasureMapRpcTreasureMapChangeNotify();
		v.TreasureMapId = m_TreasureMapId;
		v.HighTreasureMapId = m_HighTreasureMapId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureMapRpcTreasureMapChangeNotify v)
	{
        if (v == null)
            return;
		m_TreasureMapId = v.TreasureMapId;
		m_HighTreasureMapId = v.HighTreasureMapId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureMapRpcTreasureMapChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureMapRpcTreasureMapChangeNotify pb = ProtoBuf.Serializer.Deserialize<TreasureMapRpcTreasureMapChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_TreasureMapId;
	public int TreasureMapId
	{
		get { return m_TreasureMapId;}
		set { m_TreasureMapId = value; }
	}
	//高级藏宝图ID
	public int m_HighTreasureMapId;
	public int HighTreasureMapId
	{
		get { return m_HighTreasureMapId;}
		set { m_HighTreasureMapId = value; }
	}


};
