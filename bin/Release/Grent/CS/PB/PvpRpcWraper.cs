
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBPvp.cs
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


//Rank请求封装类
[System.Serializable]
public class PvpRpcRankAskWraper
{

	//构造函数
	public PvpRpcRankAskWraper()
	{
		 m_PvpType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PvpType = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcRankAsk ToPB()
	{
		PvpRpcRankAsk v = new PvpRpcRankAsk();
		v.PvpType = m_PvpType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcRankAsk v)
	{
        if (v == null)
            return;
		m_PvpType = v.PvpType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcRankAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcRankAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcRankAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//PvpType
	public int m_PvpType;
	public int PvpType
	{
		get { return m_PvpType;}
		set { m_PvpType = value; }
	}


};
//Rank回应封装类
[System.Serializable]
public class PvpRpcRankReplyWraper
{

	//构造函数
	public PvpRpcRankReplyWraper()
	{
		 m_Result = -1;
		m_RankList = new List<PvpPlayerInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RankList = new List<PvpPlayerInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public PvpRpcRankReply ToPB()
	{
		PvpRpcRankReply v = new PvpRpcRankReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RankList.Count; i++)
			v.RankList.Add( m_RankList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcRankReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RankList.Clear();
		for( int i=0; i<v.RankList.Count; i++)
			m_RankList.Add( new PvpPlayerInfoWraper());
		for( int i=0; i<v.RankList.Count; i++)
			m_RankList[i].FromPB(v.RankList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcRankReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcRankReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcRankReply>(protoMS);
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
	//RankList
	public List<PvpPlayerInfoWraper> m_RankList;
	public int SizeRankList()
	{
		return m_RankList.Count;
	}
	public List<PvpPlayerInfoWraper> GetRankList()
	{
		return m_RankList;
	}
	public PvpPlayerInfoWraper GetRankList(int Index)
	{
		if(Index<0 || Index>=(int)m_RankList.Count)
			return new PvpPlayerInfoWraper();
		return m_RankList[Index];
	}
	public void SetRankList( List<PvpPlayerInfoWraper> v )
	{
		m_RankList=v;
	}
	public void SetRankList( int Index, PvpPlayerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RankList.Count)
			return;
		m_RankList[Index] = v;
	}
	public void AddRankList( PvpPlayerInfoWraper v )
	{
		m_RankList.Add(v);
	}
	public void ClearRankList( )
	{
		m_RankList.Clear();
	}


};
//Match请求封装类
[System.Serializable]
public class PvpRpcMatchAskWraper
{

	//构造函数
	public PvpRpcMatchAskWraper()
	{
		 m_PvpType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PvpType = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchAsk ToPB()
	{
		PvpRpcMatchAsk v = new PvpRpcMatchAsk();
		v.PvpType = m_PvpType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchAsk v)
	{
        if (v == null)
            return;
		m_PvpType = v.PvpType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//PvpType
	public int m_PvpType;
	public int PvpType
	{
		get { return m_PvpType;}
		set { m_PvpType = value; }
	}


};
//Match回应封装类
[System.Serializable]
public class PvpRpcMatchReplyWraper
{

	//构造函数
	public PvpRpcMatchReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchReply ToPB()
	{
		PvpRpcMatchReply v = new PvpRpcMatchReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchReply>(protoMS);
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
//匹配的通知通知封装类
[System.Serializable]
public class PvpRpcMatchNotifyNotifyWraper
{

	//构造函数
	public PvpRpcMatchNotifyNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchNotifyNotify ToPB()
	{
		PvpRpcMatchNotifyNotify v = new PvpRpcMatchNotifyNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchNotifyNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchNotifyNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//MatchCancle请求封装类
[System.Serializable]
public class PvpRpcMatchCancleAskWraper
{

	//构造函数
	public PvpRpcMatchCancleAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchCancleAsk ToPB()
	{
		PvpRpcMatchCancleAsk v = new PvpRpcMatchCancleAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchCancleAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchCancleAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchCancleAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchCancleAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//MatchCancle回应封装类
[System.Serializable]
public class PvpRpcMatchCancleReplyWraper
{

	//构造函数
	public PvpRpcMatchCancleReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchCancleReply ToPB()
	{
		PvpRpcMatchCancleReply v = new PvpRpcMatchCancleReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchCancleReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchCancleReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchCancleReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchCancleReply>(protoMS);
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
//取消匹配通知通知封装类
[System.Serializable]
public class PvpRpcMatchCancleNotifyNotifyWraper
{

	//构造函数
	public PvpRpcMatchCancleNotifyNotifyWraper()
	{
		 m_RoleId = 0;
		 m_Name = "";
		 m_Reason = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Name = "";
		 m_Reason = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchCancleNotifyNotify ToPB()
	{
		PvpRpcMatchCancleNotifyNotify v = new PvpRpcMatchCancleNotifyNotify();
		v.RoleId = m_RoleId;
		v.Name = m_Name;
		v.Reason = m_Reason;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchCancleNotifyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Name = v.Name;
		m_Reason = v.Reason;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchCancleNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchCancleNotifyNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchCancleNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//取消者的ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//原因
	public int m_Reason;
	public int Reason
	{
		get { return m_Reason;}
		set { m_Reason = value; }
	}


};
//PlayerReady请求封装类
[System.Serializable]
public class PvpRpcPlayerReadyAskWraper
{

	//构造函数
	public PvpRpcPlayerReadyAskWraper()
	{
		 m_OpreationType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OpreationType = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPlayerReadyAsk ToPB()
	{
		PvpRpcPlayerReadyAsk v = new PvpRpcPlayerReadyAsk();
		v.OpreationType = m_OpreationType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPlayerReadyAsk v)
	{
        if (v == null)
            return;
		m_OpreationType = v.OpreationType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPlayerReadyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPlayerReadyAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcPlayerReadyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//取消或确认
	public int m_OpreationType;
	public int OpreationType
	{
		get { return m_OpreationType;}
		set { m_OpreationType = value; }
	}


};
//PlayerReady回应封装类
[System.Serializable]
public class PvpRpcPlayerReadyReplyWraper
{

	//构造函数
	public PvpRpcPlayerReadyReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPlayerReadyReply ToPB()
	{
		PvpRpcPlayerReadyReply v = new PvpRpcPlayerReadyReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPlayerReadyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPlayerReadyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPlayerReadyReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcPlayerReadyReply>(protoMS);
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
//玩家准备的通知通知封装类
[System.Serializable]
public class PvpRpcPlayerReadyNotifyNotifyWraper
{

	//构造函数
	public PvpRpcPlayerReadyNotifyNotifyWraper()
	{
		 m_RoleId = 0;
		 m_OpType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_OpType = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPlayerReadyNotifyNotify ToPB()
	{
		PvpRpcPlayerReadyNotifyNotify v = new PvpRpcPlayerReadyNotifyNotify();
		v.RoleId = m_RoleId;
		v.OpType = m_OpType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPlayerReadyNotifyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_OpType = v.OpType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPlayerReadyNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPlayerReadyNotifyNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcPlayerReadyNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//操作类型
	public int m_OpType;
	public int OpType
	{
		get { return m_OpType;}
		set { m_OpType = value; }
	}


};
//等待确认超时通知封装类
[System.Serializable]
public class PvpRpcReadyFaildNotifyWraper
{

	//构造函数
	public PvpRpcReadyFaildNotifyWraper()
	{
		 m_Reason = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Reason = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcReadyFaildNotify ToPB()
	{
		PvpRpcReadyFaildNotify v = new PvpRpcReadyFaildNotify();
		v.Reason = m_Reason;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcReadyFaildNotify v)
	{
        if (v == null)
            return;
		m_Reason = v.Reason;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcReadyFaildNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcReadyFaildNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcReadyFaildNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//原因
	public int m_Reason;
	public int Reason
	{
		get { return m_Reason;}
		set { m_Reason = value; }
	}
	//角色ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//PvpBattleStart通知封装类
[System.Serializable]
public class PvpRpcPvpBattleStartNotifyWraper
{

	//构造函数
	public PvpRpcPvpBattleStartNotifyWraper()
	{
		 m_LeftKill = -1;
		 m_RightKill = -1;
		 m_NeedKill = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LeftKill = -1;
		 m_RightKill = -1;
		 m_NeedKill = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPvpBattleStartNotify ToPB()
	{
		PvpRpcPvpBattleStartNotify v = new PvpRpcPvpBattleStartNotify();
		v.LeftKill = m_LeftKill;
		v.RightKill = m_RightKill;
		v.NeedKill = m_NeedKill;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPvpBattleStartNotify v)
	{
        if (v == null)
            return;
		m_LeftKill = v.LeftKill;
		m_RightKill = v.RightKill;
		m_NeedKill = v.NeedKill;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPvpBattleStartNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPvpBattleStartNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcPvpBattleStartNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//左侧阵营击杀数量
	public int m_LeftKill;
	public int LeftKill
	{
		get { return m_LeftKill;}
		set { m_LeftKill = value; }
	}
	//右侧阵营击杀数量
	public int m_RightKill;
	public int RightKill
	{
		get { return m_RightKill;}
		set { m_RightKill = value; }
	}
	//需要击杀多少人
	public int m_NeedKill;
	public int NeedKill
	{
		get { return m_NeedKill;}
		set { m_NeedKill = value; }
	}


};
//PvpBattleEnd通知封装类
[System.Serializable]
public class PvpRpcPvpBattleEndNotifyWraper
{

	//构造函数
	public PvpRpcPvpBattleEndNotifyWraper()
	{
		 m_BattleEndInfo = new PvpBattleEndInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BattleEndInfo = new PvpBattleEndInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPvpBattleEndNotify ToPB()
	{
		PvpRpcPvpBattleEndNotify v = new PvpRpcPvpBattleEndNotify();
		v.BattleEndInfo = m_BattleEndInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPvpBattleEndNotify v)
	{
        if (v == null)
            return;
		m_BattleEndInfo.FromPB(v.BattleEndInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPvpBattleEndNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPvpBattleEndNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcPvpBattleEndNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//结算信息
	public PvpBattleEndInfoWraper m_BattleEndInfo;
	public PvpBattleEndInfoWraper BattleEndInfo
	{
		get { return m_BattleEndInfo;}
		set { m_BattleEndInfo = value; }
	}


};
//匹配完成通知封装类
[System.Serializable]
public class PvpRpcMatchSucessNotifyWraper
{

	//构造函数
	public PvpRpcMatchSucessNotifyWraper()
	{
		m_LeftTeam = new List<PvpPlayerInfoWraper>();
		m_RightTeam = new List<PvpPlayerInfoWraper>();
		 m_Time = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_LeftTeam = new List<PvpPlayerInfoWraper>();
		m_RightTeam = new List<PvpPlayerInfoWraper>();
		 m_Time = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcMatchSucessNotify ToPB()
	{
		PvpRpcMatchSucessNotify v = new PvpRpcMatchSucessNotify();
		for (int i=0; i<(int)m_LeftTeam.Count; i++)
			v.LeftTeam.Add( m_LeftTeam[i].ToPB());
		for (int i=0; i<(int)m_RightTeam.Count; i++)
			v.RightTeam.Add( m_RightTeam[i].ToPB());
		v.Time = m_Time;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcMatchSucessNotify v)
	{
        if (v == null)
            return;
		m_LeftTeam.Clear();
		for( int i=0; i<v.LeftTeam.Count; i++)
			m_LeftTeam.Add( new PvpPlayerInfoWraper());
		for( int i=0; i<v.LeftTeam.Count; i++)
			m_LeftTeam[i].FromPB(v.LeftTeam[i]);
		m_RightTeam.Clear();
		for( int i=0; i<v.RightTeam.Count; i++)
			m_RightTeam.Add( new PvpPlayerInfoWraper());
		for( int i=0; i<v.RightTeam.Count; i++)
			m_RightTeam[i].FromPB(v.RightTeam[i]);
		m_Time = v.Time;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcMatchSucessNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcMatchSucessNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcMatchSucessNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//左边队伍
	public List<PvpPlayerInfoWraper> m_LeftTeam;
	public int SizeLeftTeam()
	{
		return m_LeftTeam.Count;
	}
	public List<PvpPlayerInfoWraper> GetLeftTeam()
	{
		return m_LeftTeam;
	}
	public PvpPlayerInfoWraper GetLeftTeam(int Index)
	{
		if(Index<0 || Index>=(int)m_LeftTeam.Count)
			return new PvpPlayerInfoWraper();
		return m_LeftTeam[Index];
	}
	public void SetLeftTeam( List<PvpPlayerInfoWraper> v )
	{
		m_LeftTeam=v;
	}
	public void SetLeftTeam( int Index, PvpPlayerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_LeftTeam.Count)
			return;
		m_LeftTeam[Index] = v;
	}
	public void AddLeftTeam( PvpPlayerInfoWraper v )
	{
		m_LeftTeam.Add(v);
	}
	public void ClearLeftTeam( )
	{
		m_LeftTeam.Clear();
	}
	//右侧队伍
	public List<PvpPlayerInfoWraper> m_RightTeam;
	public int SizeRightTeam()
	{
		return m_RightTeam.Count;
	}
	public List<PvpPlayerInfoWraper> GetRightTeam()
	{
		return m_RightTeam;
	}
	public PvpPlayerInfoWraper GetRightTeam(int Index)
	{
		if(Index<0 || Index>=(int)m_RightTeam.Count)
			return new PvpPlayerInfoWraper();
		return m_RightTeam[Index];
	}
	public void SetRightTeam( List<PvpPlayerInfoWraper> v )
	{
		m_RightTeam=v;
	}
	public void SetRightTeam( int Index, PvpPlayerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RightTeam.Count)
			return;
		m_RightTeam[Index] = v;
	}
	public void AddRightTeam( PvpPlayerInfoWraper v )
	{
		m_RightTeam.Add(v);
	}
	public void ClearRightTeam( )
	{
		m_RightTeam.Clear();
	}
	//倒计时
	public int m_Time;
	public int Time
	{
		get { return m_Time;}
		set { m_Time = value; }
	}


};
//段位变化通知封装类
[System.Serializable]
public class PvpRpcRankChangeNotifyWraper
{

	//构造函数
	public PvpRpcRankChangeNotifyWraper()
	{
		 m_PvpType = -1;
		 m_BeforeRank = -1;
		 m_AfterRank = -1;
		 m_BeforeStar = -1;
		 m_AfterStar = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PvpType = -1;
		 m_BeforeRank = -1;
		 m_AfterRank = -1;
		 m_BeforeStar = -1;
		 m_AfterStar = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcRankChangeNotify ToPB()
	{
		PvpRpcRankChangeNotify v = new PvpRpcRankChangeNotify();
		v.PvpType = m_PvpType;
		v.BeforeRank = m_BeforeRank;
		v.AfterRank = m_AfterRank;
		v.BeforeStar = m_BeforeStar;
		v.AfterStar = m_AfterStar;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcRankChangeNotify v)
	{
        if (v == null)
            return;
		m_PvpType = v.PvpType;
		m_BeforeRank = v.BeforeRank;
		m_AfterRank = v.AfterRank;
		m_BeforeStar = v.BeforeStar;
		m_AfterStar = v.AfterStar;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcRankChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcRankChangeNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcRankChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_PvpType;
	public int PvpType
	{
		get { return m_PvpType;}
		set { m_PvpType = value; }
	}
	//之前段位
	public int m_BeforeRank;
	public int BeforeRank
	{
		get { return m_BeforeRank;}
		set { m_BeforeRank = value; }
	}
	//之后段位
	public int m_AfterRank;
	public int AfterRank
	{
		get { return m_AfterRank;}
		set { m_AfterRank = value; }
	}
	//星级
	public int m_BeforeStar;
	public int BeforeStar
	{
		get { return m_BeforeStar;}
		set { m_BeforeStar = value; }
	}
	//星级
	public int m_AfterStar;
	public int AfterStar
	{
		get { return m_AfterStar;}
		set { m_AfterStar = value; }
	}


};
//返回请求封装类
[System.Serializable]
public class PvpRpcReturnLastSceneAskWraper
{

	//构造函数
	public PvpRpcReturnLastSceneAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PvpRpcReturnLastSceneAsk ToPB()
	{
		PvpRpcReturnLastSceneAsk v = new PvpRpcReturnLastSceneAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcReturnLastSceneAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcReturnLastSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcReturnLastSceneAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcReturnLastSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//返回回应封装类
[System.Serializable]
public class PvpRpcReturnLastSceneReplyWraper
{

	//构造函数
	public PvpRpcReturnLastSceneReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcReturnLastSceneReply ToPB()
	{
		PvpRpcReturnLastSceneReply v = new PvpRpcReturnLastSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcReturnLastSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcReturnLastSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcReturnLastSceneReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcReturnLastSceneReply>(protoMS);
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
//通知开始时间通知封装类
[System.Serializable]
public class PvpRpcArenaStartTimeNotifyWraper
{

	//构造函数
	public PvpRpcArenaStartTimeNotifyWraper()
	{
		 m_NeedTime = -1;
		 m_TimeStamp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NeedTime = -1;
		 m_TimeStamp = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcArenaStartTimeNotify ToPB()
	{
		PvpRpcArenaStartTimeNotify v = new PvpRpcArenaStartTimeNotify();
		v.NeedTime = m_NeedTime;
		v.TimeStamp = m_TimeStamp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcArenaStartTimeNotify v)
	{
        if (v == null)
            return;
		m_NeedTime = v.NeedTime;
		m_TimeStamp = v.TimeStamp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcArenaStartTimeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcArenaStartTimeNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcArenaStartTimeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//剩余时间 秒
	public int m_NeedTime;
	public int NeedTime
	{
		get { return m_NeedTime;}
		set { m_NeedTime = value; }
	}
	//时间戳 
	public int m_TimeStamp;
	public int TimeStamp
	{
		get { return m_TimeStamp;}
		set { m_TimeStamp = value; }
	}


};
//更新击杀数量通知封装类
[System.Serializable]
public class PvpRpcUpdateKillCountNotifyWraper
{

	//构造函数
	public PvpRpcUpdateKillCountNotifyWraper()
	{
		 m_LeftTeamKill = -1;
		 m_RightTeamKill = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LeftTeamKill = -1;
		 m_RightTeamKill = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcUpdateKillCountNotify ToPB()
	{
		PvpRpcUpdateKillCountNotify v = new PvpRpcUpdateKillCountNotify();
		v.LeftTeamKill = m_LeftTeamKill;
		v.RightTeamKill = m_RightTeamKill;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcUpdateKillCountNotify v)
	{
        if (v == null)
            return;
		m_LeftTeamKill = v.LeftTeamKill;
		m_RightTeamKill = v.RightTeamKill;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcUpdateKillCountNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcUpdateKillCountNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcUpdateKillCountNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//左方杀人数
	public int m_LeftTeamKill;
	public int LeftTeamKill
	{
		get { return m_LeftTeamKill;}
		set { m_LeftTeamKill = value; }
	}
	//右侧杀人数
	public int m_RightTeamKill;
	public int RightTeamKill
	{
		get { return m_RightTeamKill;}
		set { m_RightTeamKill = value; }
	}


};
//剩余时间通知封装类
[System.Serializable]
public class PvpRpcArenaLeftTimeNotifyWraper
{

	//构造函数
	public PvpRpcArenaLeftTimeNotifyWraper()
	{
		 m_LeftTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LeftTime = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcArenaLeftTimeNotify ToPB()
	{
		PvpRpcArenaLeftTimeNotify v = new PvpRpcArenaLeftTimeNotify();
		v.LeftTime = m_LeftTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcArenaLeftTimeNotify v)
	{
        if (v == null)
            return;
		m_LeftTime = v.LeftTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcArenaLeftTimeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcArenaLeftTimeNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcArenaLeftTimeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//剩余时间
	public int m_LeftTime;
	public int LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}


};
//上个赛季的排行请求封装类
[System.Serializable]
public class PvpRpcLastRankAskWraper
{

	//构造函数
	public PvpRpcLastRankAskWraper()
	{
		 m_PvpType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PvpType = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcLastRankAsk ToPB()
	{
		PvpRpcLastRankAsk v = new PvpRpcLastRankAsk();
		v.PvpType = m_PvpType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcLastRankAsk v)
	{
        if (v == null)
            return;
		m_PvpType = v.PvpType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcLastRankAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcLastRankAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcLastRankAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_PvpType;
	public int PvpType
	{
		get { return m_PvpType;}
		set { m_PvpType = value; }
	}


};
//上个赛季的排行回应封装类
[System.Serializable]
public class PvpRpcLastRankReplyWraper
{

	//构造函数
	public PvpRpcLastRankReplyWraper()
	{
		 m_Result = -1;
		m_RankList = new List<PvpPlayerInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RankList = new List<PvpPlayerInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public PvpRpcLastRankReply ToPB()
	{
		PvpRpcLastRankReply v = new PvpRpcLastRankReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RankList.Count; i++)
			v.RankList.Add( m_RankList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcLastRankReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RankList.Clear();
		for( int i=0; i<v.RankList.Count; i++)
			m_RankList.Add( new PvpPlayerInfoWraper());
		for( int i=0; i<v.RankList.Count; i++)
			m_RankList[i].FromPB(v.RankList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcLastRankReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcLastRankReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcLastRankReply>(protoMS);
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
	//排行信息
	public List<PvpPlayerInfoWraper> m_RankList;
	public int SizeRankList()
	{
		return m_RankList.Count;
	}
	public List<PvpPlayerInfoWraper> GetRankList()
	{
		return m_RankList;
	}
	public PvpPlayerInfoWraper GetRankList(int Index)
	{
		if(Index<0 || Index>=(int)m_RankList.Count)
			return new PvpPlayerInfoWraper();
		return m_RankList[Index];
	}
	public void SetRankList( List<PvpPlayerInfoWraper> v )
	{
		m_RankList=v;
	}
	public void SetRankList( int Index, PvpPlayerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RankList.Count)
			return;
		m_RankList[Index] = v;
	}
	public void AddRankList( PvpPlayerInfoWraper v )
	{
		m_RankList.Add(v);
	}
	public void ClearRankList( )
	{
		m_RankList.Clear();
	}


};
//新赛季通知通知封装类
[System.Serializable]
public class PvpRpcNewSeasonNotifyWraper
{

	//构造函数
	public PvpRpcNewSeasonNotifyWraper()
	{
		 m_LastRank = -1;
		 m_LastStar = -1;
		 m_LastRanking = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LastRank = -1;
		 m_LastStar = -1;
		 m_LastRanking = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public PvpRpcNewSeasonNotify ToPB()
	{
		PvpRpcNewSeasonNotify v = new PvpRpcNewSeasonNotify();
		v.LastRank = m_LastRank;
		v.LastStar = m_LastStar;
		v.LastRanking = m_LastRanking;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcNewSeasonNotify v)
	{
        if (v == null)
            return;
		m_LastRank = v.LastRank;
		m_LastStar = v.LastStar;
		m_LastRanking = v.LastRanking;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add( new PvpBattleRewardInfoWraper());
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList[i].FromPB(v.RewardList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcNewSeasonNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcNewSeasonNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcNewSeasonNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//上赛季段位
	public int m_LastRank;
	public int LastRank
	{
		get { return m_LastRank;}
		set { m_LastRank = value; }
	}
	//上赛季星级
	public int m_LastStar;
	public int LastStar
	{
		get { return m_LastStar;}
		set { m_LastStar = value; }
	}
	//上赛季排名
	public int m_LastRanking;
	public int LastRanking
	{
		get { return m_LastRanking;}
		set { m_LastRanking = value; }
	}
	//奖励列表
	public List<PvpBattleRewardInfoWraper> m_RewardList;
	public int SizeRewardList()
	{
		return m_RewardList.Count;
	}
	public List<PvpBattleRewardInfoWraper> GetRewardList()
	{
		return m_RewardList;
	}
	public PvpBattleRewardInfoWraper GetRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return new PvpBattleRewardInfoWraper();
		return m_RewardList[Index];
	}
	public void SetRewardList( List<PvpBattleRewardInfoWraper> v )
	{
		m_RewardList=v;
	}
	public void SetRewardList( int Index, PvpBattleRewardInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return;
		m_RewardList[Index] = v;
	}
	public void AddRewardList( PvpBattleRewardInfoWraper v )
	{
		m_RewardList.Add(v);
	}
	public void ClearRewardList( )
	{
		m_RewardList.Clear();
	}


};
//领取奖励请求封装类
[System.Serializable]
public class PvpRpcGetSeasonRewardAskWraper
{

	//构造函数
	public PvpRpcGetSeasonRewardAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PvpRpcGetSeasonRewardAsk ToPB()
	{
		PvpRpcGetSeasonRewardAsk v = new PvpRpcGetSeasonRewardAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcGetSeasonRewardAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcGetSeasonRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcGetSeasonRewardAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcGetSeasonRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//领取奖励回应封装类
[System.Serializable]
public class PvpRpcGetSeasonRewardReplyWraper
{

	//构造函数
	public PvpRpcGetSeasonRewardReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcGetSeasonRewardReply ToPB()
	{
		PvpRpcGetSeasonRewardReply v = new PvpRpcGetSeasonRewardReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcGetSeasonRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcGetSeasonRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcGetSeasonRewardReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcGetSeasonRewardReply>(protoMS);
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
//请求战斗信息请求封装类
[System.Serializable]
public class PvpRpcPvpBattleInfoSyncAskWraper
{

	//构造函数
	public PvpRpcPvpBattleInfoSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPvpBattleInfoSyncAsk ToPB()
	{
		PvpRpcPvpBattleInfoSyncAsk v = new PvpRpcPvpBattleInfoSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPvpBattleInfoSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPvpBattleInfoSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPvpBattleInfoSyncAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcPvpBattleInfoSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求战斗信息回应封装类
[System.Serializable]
public class PvpRpcPvpBattleInfoSyncReplyWraper
{

	//构造函数
	public PvpRpcPvpBattleInfoSyncReplyWraper()
	{
		 m_Result = -1;
		 m_BattleInfo = new PvpBattleInfoWraper();
		 m_Season = -1;
		 m_RankIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_BattleInfo = new PvpBattleInfoWraper();
		 m_Season = -1;
		 m_RankIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcPvpBattleInfoSyncReply ToPB()
	{
		PvpRpcPvpBattleInfoSyncReply v = new PvpRpcPvpBattleInfoSyncReply();
		v.Result = m_Result;
		v.BattleInfo = m_BattleInfo.ToPB();
		v.Season = m_Season;
		v.RankIndex = m_RankIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcPvpBattleInfoSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_BattleInfo.FromPB(v.BattleInfo);
		m_Season = v.Season;
		m_RankIndex = v.RankIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcPvpBattleInfoSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcPvpBattleInfoSyncReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcPvpBattleInfoSyncReply>(protoMS);
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
	//战斗信息
	public PvpBattleInfoWraper m_BattleInfo;
	public PvpBattleInfoWraper BattleInfo
	{
		get { return m_BattleInfo;}
		set { m_BattleInfo = value; }
	}
	//当前赛季
	public int m_Season;
	public int Season
	{
		get { return m_Season;}
		set { m_Season = value; }
	}
	//排名
	public int m_RankIndex;
	public int RankIndex
	{
		get { return m_RankIndex;}
		set { m_RankIndex = value; }
	}


};
//重连通知封装类
[System.Serializable]
public class PvpRpcReconnectNotifyWraper
{

	//构造函数
	public PvpRpcReconnectNotifyWraper()
	{
		 m_NeedKill = -1;
		 m_ArenaState = -1;
		 m_LeftTime = -1;
		 m_LeftKill = -1;
		 m_RightKill = -1;
		 m_Camp = -1;
		 m_TimeStamp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NeedKill = -1;
		 m_ArenaState = -1;
		 m_LeftTime = -1;
		 m_LeftKill = -1;
		 m_RightKill = -1;
		 m_Camp = -1;
		 m_TimeStamp = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcReconnectNotify ToPB()
	{
		PvpRpcReconnectNotify v = new PvpRpcReconnectNotify();
		v.NeedKill = m_NeedKill;
		v.ArenaState = m_ArenaState;
		v.LeftTime = m_LeftTime;
		v.LeftKill = m_LeftKill;
		v.RightKill = m_RightKill;
		v.Camp = m_Camp;
		v.TimeStamp = m_TimeStamp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcReconnectNotify v)
	{
        if (v == null)
            return;
		m_NeedKill = v.NeedKill;
		m_ArenaState = v.ArenaState;
		m_LeftTime = v.LeftTime;
		m_LeftKill = v.LeftKill;
		m_RightKill = v.RightKill;
		m_Camp = v.Camp;
		m_TimeStamp = v.TimeStamp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcReconnectNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcReconnectNotify pb = ProtoBuf.Serializer.Deserialize<PvpRpcReconnectNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//需要杀人数
	public int m_NeedKill;
	public int NeedKill
	{
		get { return m_NeedKill;}
		set { m_NeedKill = value; }
	}
	//竞技场状态
	public int m_ArenaState;
	public int ArenaState
	{
		get { return m_ArenaState;}
		set { m_ArenaState = value; }
	}
	//剩余时间
	public int m_LeftTime;
	public int LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}
	//左侧阵营击杀数量
	public int m_LeftKill;
	public int LeftKill
	{
		get { return m_LeftKill;}
		set { m_LeftKill = value; }
	}
	//右侧阵营击杀数量
	public int m_RightKill;
	public int RightKill
	{
		get { return m_RightKill;}
		set { m_RightKill = value; }
	}
	//阵营
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//时间戳
	public int m_TimeStamp;
	public int TimeStamp
	{
		get { return m_TimeStamp;}
		set { m_TimeStamp = value; }
	}


};
//获取奖励请求封装类
[System.Serializable]
public class PvpRpcGetRewardAskWraper
{

	//构造函数
	public PvpRpcGetRewardAskWraper()
	{
		 m_PvPType = -1;
		 m_Rank = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PvPType = -1;
		 m_Rank = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpRpcGetRewardAsk ToPB()
	{
		PvpRpcGetRewardAsk v = new PvpRpcGetRewardAsk();
		v.PvPType = m_PvPType;
		v.Rank = m_Rank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcGetRewardAsk v)
	{
        if (v == null)
            return;
		m_PvPType = v.PvPType;
		m_Rank = v.Rank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcGetRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcGetRewardAsk pb = ProtoBuf.Serializer.Deserialize<PvpRpcGetRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//战斗类型
	public int m_PvPType;
	public int PvPType
	{
		get { return m_PvPType;}
		set { m_PvPType = value; }
	}
	//段位
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}


};
//获取奖励回应封装类
[System.Serializable]
public class PvpRpcGetRewardReplyWraper
{

	//构造函数
	public PvpRpcGetRewardReplyWraper()
	{
		 m_Result = -1;
		m_RewardList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RewardList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public PvpRpcGetRewardReply ToPB()
	{
		PvpRpcGetRewardReply v = new PvpRpcGetRewardReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpRpcGetRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add(v.RewardList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpRpcGetRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpRpcGetRewardReply pb = ProtoBuf.Serializer.Deserialize<PvpRpcGetRewardReply>(protoMS);
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
	//已领过的
	public List<int> m_RewardList;
	public int SizeRewardList()
	{
		return m_RewardList.Count;
	}
	public List<int> GetRewardList()
	{
		return m_RewardList;
	}
	public int GetRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return -1;
		return m_RewardList[Index];
	}
	public void SetRewardList( List<int> v )
	{
		m_RewardList=v;
	}
	public void SetRewardList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return;
		m_RewardList[Index] = v;
	}
	public void AddRewardList( int v=-1 )
	{
		m_RewardList.Add(v);
	}
	public void ClearRewardList( )
	{
		m_RewardList.Clear();
	}


};
