
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBRedDot.cs
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
public class RedDotRpcSyncRedDotAskWraper
{

	//构造函数
	public RedDotRpcSyncRedDotAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public RedDotRpcSyncRedDotAsk ToPB()
	{
		RedDotRpcSyncRedDotAsk v = new RedDotRpcSyncRedDotAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotRpcSyncRedDotAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotRpcSyncRedDotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotRpcSyncRedDotAsk pb = ProtoBuf.Serializer.Deserialize<RedDotRpcSyncRedDotAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class RedDotRpcSyncRedDotReplyWraper
{

	//构造函数
	public RedDotRpcSyncRedDotReplyWraper()
	{
		 m_Result = -1;
		m_RedDotInfoList = new List<RedDotInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RedDotInfoList = new List<RedDotInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public RedDotRpcSyncRedDotReply ToPB()
	{
		RedDotRpcSyncRedDotReply v = new RedDotRpcSyncRedDotReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RedDotInfoList.Count; i++)
			v.RedDotInfoList.Add( m_RedDotInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotRpcSyncRedDotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RedDotInfoList.Clear();
		for( int i=0; i<v.RedDotInfoList.Count; i++)
			m_RedDotInfoList.Add( new RedDotInfoWraper());
		for( int i=0; i<v.RedDotInfoList.Count; i++)
			m_RedDotInfoList[i].FromPB(v.RedDotInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotRpcSyncRedDotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotRpcSyncRedDotReply pb = ProtoBuf.Serializer.Deserialize<RedDotRpcSyncRedDotReply>(protoMS);
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
	//红点列表
	public List<RedDotInfoWraper> m_RedDotInfoList;
	public int SizeRedDotInfoList()
	{
		return m_RedDotInfoList.Count;
	}
	public List<RedDotInfoWraper> GetRedDotInfoList()
	{
		return m_RedDotInfoList;
	}
	public RedDotInfoWraper GetRedDotInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_RedDotInfoList.Count)
			return new RedDotInfoWraper();
		return m_RedDotInfoList[Index];
	}
	public void SetRedDotInfoList( List<RedDotInfoWraper> v )
	{
		m_RedDotInfoList=v;
	}
	public void SetRedDotInfoList( int Index, RedDotInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RedDotInfoList.Count)
			return;
		m_RedDotInfoList[Index] = v;
	}
	public void AddRedDotInfoList( RedDotInfoWraper v )
	{
		m_RedDotInfoList.Add(v);
	}
	public void ClearRedDotInfoList( )
	{
		m_RedDotInfoList.Clear();
	}


};
//删除红点请求封装类
[System.Serializable]
public class RedDotRpcRemoveRedDotAskWraper
{

	//构造函数
	public RedDotRpcRemoveRedDotAskWraper()
	{
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public RedDotRpcRemoveRedDotAsk ToPB()
	{
		RedDotRpcRemoveRedDotAsk v = new RedDotRpcRemoveRedDotAsk();
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotRpcRemoveRedDotAsk v)
	{
        if (v == null)
            return;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotRpcRemoveRedDotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotRpcRemoveRedDotAsk pb = ProtoBuf.Serializer.Deserialize<RedDotRpcRemoveRedDotAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//删除红点回应封装类
[System.Serializable]
public class RedDotRpcRemoveRedDotReplyWraper
{

	//构造函数
	public RedDotRpcRemoveRedDotReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public RedDotRpcRemoveRedDotReply ToPB()
	{
		RedDotRpcRemoveRedDotReply v = new RedDotRpcRemoveRedDotReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotRpcRemoveRedDotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotRpcRemoveRedDotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotRpcRemoveRedDotReply pb = ProtoBuf.Serializer.Deserialize<RedDotRpcRemoveRedDotReply>(protoMS);
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
//更新通知封装类
[System.Serializable]
public class RedDotRpcUpdateRedDotNotifyWraper
{

	//构造函数
	public RedDotRpcUpdateRedDotNotifyWraper()
	{
		 m_RedDotInfo = new RedDotInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RedDotInfo = new RedDotInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public RedDotRpcUpdateRedDotNotify ToPB()
	{
		RedDotRpcUpdateRedDotNotify v = new RedDotRpcUpdateRedDotNotify();
		v.RedDotInfo = m_RedDotInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotRpcUpdateRedDotNotify v)
	{
        if (v == null)
            return;
		m_RedDotInfo.FromPB(v.RedDotInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotRpcUpdateRedDotNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotRpcUpdateRedDotNotify pb = ProtoBuf.Serializer.Deserialize<RedDotRpcUpdateRedDotNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//需要更新的红点信息
	public RedDotInfoWraper m_RedDotInfo;
	public RedDotInfoWraper RedDotInfo
	{
		get { return m_RedDotInfo;}
		set { m_RedDotInfo = value; }
	}


};
