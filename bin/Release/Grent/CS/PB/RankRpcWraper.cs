
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBRank.cs
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


//请求排行榜请求封装类
[System.Serializable]
public class RankRpcRankAskWraper
{

	//构造函数
	public RankRpcRankAskWraper()
	{
		 m_RankType = -1;
		 m_RankSubType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RankType = -1;
		 m_RankSubType = -1;

	}

 	//转化成Protobuffer类型函数
	public RankRpcRankAsk ToPB()
	{
		RankRpcRankAsk v = new RankRpcRankAsk();
		v.RankType = m_RankType;
		v.RankSubType = m_RankSubType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RankRpcRankAsk v)
	{
        if (v == null)
            return;
		m_RankType = v.RankType;
		m_RankSubType = v.RankSubType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RankRpcRankAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RankRpcRankAsk pb = ProtoBuf.Serializer.Deserialize<RankRpcRankAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//排行榜类型
	public int m_RankType;
	public int RankType
	{
		get { return m_RankType;}
		set { m_RankType = value; }
	}
	//子类型
	public int m_RankSubType;
	public int RankSubType
	{
		get { return m_RankSubType;}
		set { m_RankSubType = value; }
	}


};
//请求排行榜回应封装类
[System.Serializable]
public class RankRpcRankReplyWraper
{

	//构造函数
	public RankRpcRankReplyWraper()
	{
		 m_Result = -1;
		m_RankInfoList = new List<RankInfoWraper>();
		 m_RankIndex = -1;
		 m_MyValue = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RankInfoList = new List<RankInfoWraper>();
		 m_RankIndex = -1;
		 m_MyValue = -1;

	}

 	//转化成Protobuffer类型函数
	public RankRpcRankReply ToPB()
	{
		RankRpcRankReply v = new RankRpcRankReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RankInfoList.Count; i++)
			v.RankInfoList.Add( m_RankInfoList[i].ToPB());
		v.RankIndex = m_RankIndex;
		v.MyValue = m_MyValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RankRpcRankReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RankInfoList.Clear();
		for( int i=0; i<v.RankInfoList.Count; i++)
			m_RankInfoList.Add( new RankInfoWraper());
		for( int i=0; i<v.RankInfoList.Count; i++)
			m_RankInfoList[i].FromPB(v.RankInfoList[i]);
		m_RankIndex = v.RankIndex;
		m_MyValue = v.MyValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RankRpcRankReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RankRpcRankReply pb = ProtoBuf.Serializer.Deserialize<RankRpcRankReply>(protoMS);
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
	//排行榜信息
	public List<RankInfoWraper> m_RankInfoList;
	public int SizeRankInfoList()
	{
		return m_RankInfoList.Count;
	}
	public List<RankInfoWraper> GetRankInfoList()
	{
		return m_RankInfoList;
	}
	public RankInfoWraper GetRankInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_RankInfoList.Count)
			return new RankInfoWraper();
		return m_RankInfoList[Index];
	}
	public void SetRankInfoList( List<RankInfoWraper> v )
	{
		m_RankInfoList=v;
	}
	public void SetRankInfoList( int Index, RankInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RankInfoList.Count)
			return;
		m_RankInfoList[Index] = v;
	}
	public void AddRankInfoList( RankInfoWraper v )
	{
		m_RankInfoList.Add(v);
	}
	public void ClearRankInfoList( )
	{
		m_RankInfoList.Clear();
	}
	//自己的排名
	public int m_RankIndex;
	public int RankIndex
	{
		get { return m_RankIndex;}
		set { m_RankIndex = value; }
	}
	//我的
	public Int64 m_MyValue;
	public Int64 MyValue
	{
		get { return m_MyValue;}
		set { m_MyValue = value; }
	}


};
