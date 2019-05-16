
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBWorldBoss.cs
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


//世界BOSS信息请求封装类
[System.Serializable]
public class WorldBossRpcWorldBossInfoAskWraper
{

	//构造函数
	public WorldBossRpcWorldBossInfoAskWraper()
	{
		 m_BossID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BossID = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRpcWorldBossInfoAsk ToPB()
	{
		WorldBossRpcWorldBossInfoAsk v = new WorldBossRpcWorldBossInfoAsk();
		v.BossID = m_BossID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRpcWorldBossInfoAsk v)
	{
        if (v == null)
            return;
		m_BossID = v.BossID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRpcWorldBossInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRpcWorldBossInfoAsk pb = ProtoBuf.Serializer.Deserialize<WorldBossRpcWorldBossInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//世界BOSSID
	public int m_BossID;
	public int BossID
	{
		get { return m_BossID;}
		set { m_BossID = value; }
	}


};
//世界BOSS信息回应封装类
[System.Serializable]
public class WorldBossRpcWorldBossInfoReplyWraper
{

	//构造函数
	public WorldBossRpcWorldBossInfoReplyWraper()
	{
		 m_Result = -1;
		m_WorldBossInfos = new List<WorldBossInfoWraper>();
		 m_BossID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_WorldBossInfos = new List<WorldBossInfoWraper>();
		 m_BossID = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRpcWorldBossInfoReply ToPB()
	{
		WorldBossRpcWorldBossInfoReply v = new WorldBossRpcWorldBossInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_WorldBossInfos.Count; i++)
			v.WorldBossInfos.Add( m_WorldBossInfos[i].ToPB());
		v.BossID = m_BossID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRpcWorldBossInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_WorldBossInfos.Clear();
		for( int i=0; i<v.WorldBossInfos.Count; i++)
			m_WorldBossInfos.Add( new WorldBossInfoWraper());
		for( int i=0; i<v.WorldBossInfos.Count; i++)
			m_WorldBossInfos[i].FromPB(v.WorldBossInfos[i]);
		m_BossID = v.BossID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRpcWorldBossInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRpcWorldBossInfoReply pb = ProtoBuf.Serializer.Deserialize<WorldBossRpcWorldBossInfoReply>(protoMS);
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
	//世界BOSS信息
	public List<WorldBossInfoWraper> m_WorldBossInfos;
	public int SizeWorldBossInfos()
	{
		return m_WorldBossInfos.Count;
	}
	public List<WorldBossInfoWraper> GetWorldBossInfos()
	{
		return m_WorldBossInfos;
	}
	public WorldBossInfoWraper GetWorldBossInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_WorldBossInfos.Count)
			return new WorldBossInfoWraper();
		return m_WorldBossInfos[Index];
	}
	public void SetWorldBossInfos( List<WorldBossInfoWraper> v )
	{
		m_WorldBossInfos=v;
	}
	public void SetWorldBossInfos( int Index, WorldBossInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_WorldBossInfos.Count)
			return;
		m_WorldBossInfos[Index] = v;
	}
	public void AddWorldBossInfos( WorldBossInfoWraper v )
	{
		m_WorldBossInfos.Add(v);
	}
	public void ClearWorldBossInfos( )
	{
		m_WorldBossInfos.Clear();
	}
	//bossID
	public int m_BossID;
	public int BossID
	{
		get { return m_BossID;}
		set { m_BossID = value; }
	}


};
//世界BOSS伤害排行信息请求封装类
[System.Serializable]
public class WorldBossRpcWorldBossRankInfoAskWraper
{

	//构造函数
	public WorldBossRpcWorldBossRankInfoAskWraper()
	{
		 m_BossID = -1;
		 m_Occupation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BossID = -1;
		 m_Occupation = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRpcWorldBossRankInfoAsk ToPB()
	{
		WorldBossRpcWorldBossRankInfoAsk v = new WorldBossRpcWorldBossRankInfoAsk();
		v.BossID = m_BossID;
		v.Occupation = m_Occupation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRpcWorldBossRankInfoAsk v)
	{
        if (v == null)
            return;
		m_BossID = v.BossID;
		m_Occupation = v.Occupation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRpcWorldBossRankInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRpcWorldBossRankInfoAsk pb = ProtoBuf.Serializer.Deserialize<WorldBossRpcWorldBossRankInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//BossID
	public int m_BossID;
	public int BossID
	{
		get { return m_BossID;}
		set { m_BossID = value; }
	}
	//职业
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}


};
//世界BOSS伤害排行信息回应封装类
[System.Serializable]
public class WorldBossRpcWorldBossRankInfoReplyWraper
{

	//构造函数
	public WorldBossRpcWorldBossRankInfoReplyWraper()
	{
		 m_Result = -1;
		m_RankInfo = new List<WorldBossRankInfoWraper>();
		 m_LastKillName = "";
		 m_MaxDamageName = "";
		 m_MyRank = -1;
		 m_Occupation = -1;
		 m_BossID = -1;
		 m_MyOccupationRank = -1;
		 m_MyScore = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RankInfo = new List<WorldBossRankInfoWraper>();
		 m_LastKillName = "";
		 m_MaxDamageName = "";
		 m_MyRank = -1;
		 m_Occupation = -1;
		 m_BossID = -1;
		 m_MyOccupationRank = -1;
		 m_MyScore = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRpcWorldBossRankInfoReply ToPB()
	{
		WorldBossRpcWorldBossRankInfoReply v = new WorldBossRpcWorldBossRankInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RankInfo.Count; i++)
			v.RankInfo.Add( m_RankInfo[i].ToPB());
		v.LastKillName = m_LastKillName;
		v.MaxDamageName = m_MaxDamageName;
		v.MyRank = m_MyRank;
		v.Occupation = m_Occupation;
		v.BossID = m_BossID;
		v.MyOccupationRank = m_MyOccupationRank;
		v.MyScore = m_MyScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRpcWorldBossRankInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RankInfo.Clear();
		for( int i=0; i<v.RankInfo.Count; i++)
			m_RankInfo.Add( new WorldBossRankInfoWraper());
		for( int i=0; i<v.RankInfo.Count; i++)
			m_RankInfo[i].FromPB(v.RankInfo[i]);
		m_LastKillName = v.LastKillName;
		m_MaxDamageName = v.MaxDamageName;
		m_MyRank = v.MyRank;
		m_Occupation = v.Occupation;
		m_BossID = v.BossID;
		m_MyOccupationRank = v.MyOccupationRank;
		m_MyScore = v.MyScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRpcWorldBossRankInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRpcWorldBossRankInfoReply pb = ProtoBuf.Serializer.Deserialize<WorldBossRpcWorldBossRankInfoReply>(protoMS);
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
	public List<WorldBossRankInfoWraper> m_RankInfo;
	public int SizeRankInfo()
	{
		return m_RankInfo.Count;
	}
	public List<WorldBossRankInfoWraper> GetRankInfo()
	{
		return m_RankInfo;
	}
	public WorldBossRankInfoWraper GetRankInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_RankInfo.Count)
			return new WorldBossRankInfoWraper();
		return m_RankInfo[Index];
	}
	public void SetRankInfo( List<WorldBossRankInfoWraper> v )
	{
		m_RankInfo=v;
	}
	public void SetRankInfo( int Index, WorldBossRankInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RankInfo.Count)
			return;
		m_RankInfo[Index] = v;
	}
	public void AddRankInfo( WorldBossRankInfoWraper v )
	{
		m_RankInfo.Add(v);
	}
	public void ClearRankInfo( )
	{
		m_RankInfo.Clear();
	}
	//最后一击玩家名字
	public string m_LastKillName;
	public string LastKillName
	{
		get { return m_LastKillName;}
		set { m_LastKillName = value; }
	}
	//最大伤害玩家名字
	public string m_MaxDamageName;
	public string MaxDamageName
	{
		get { return m_MaxDamageName;}
		set { m_MaxDamageName = value; }
	}
	//个人排名
	public int m_MyRank;
	public int MyRank
	{
		get { return m_MyRank;}
		set { m_MyRank = value; }
	}
	//职业
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}
	//BossID
	public int m_BossID;
	public int BossID
	{
		get { return m_BossID;}
		set { m_BossID = value; }
	}
	//个人职业排名
	public int m_MyOccupationRank;
	public int MyOccupationRank
	{
		get { return m_MyOccupationRank;}
		set { m_MyOccupationRank = value; }
	}
	//个人积分
	public int m_MyScore;
	public int MyScore
	{
		get { return m_MyScore;}
		set { m_MyScore = value; }
	}


};
