
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBCampFigth.cs
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


//MilitaryBroken请求封装类
[System.Serializable]
public class CampFigthRpcMilitaryBrokenAskWraper
{

	//构造函数
	public CampFigthRpcMilitaryBrokenAskWraper()
	{
		 m_RoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcMilitaryBrokenAsk ToPB()
	{
		CampFigthRpcMilitaryBrokenAsk v = new CampFigthRpcMilitaryBrokenAsk();
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcMilitaryBrokenAsk v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcMilitaryBrokenAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcMilitaryBrokenAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcMilitaryBrokenAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//roleid
	public int m_RoleID;
	public int RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//MilitaryBroken回应封装类
[System.Serializable]
public class CampFigthRpcMilitaryBrokenReplyWraper
{

	//构造函数
	public CampFigthRpcMilitaryBrokenReplyWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Exp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Exp = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcMilitaryBrokenReply ToPB()
	{
		CampFigthRpcMilitaryBrokenReply v = new CampFigthRpcMilitaryBrokenReply();
		v.Result = m_Result;
		v.Rank = m_Rank;
		v.Star = m_Star;
		v.Exp = m_Exp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcMilitaryBrokenReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Rank = v.Rank;
		m_Star = v.Star;
		m_Exp = v.Exp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcMilitaryBrokenReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcMilitaryBrokenReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcMilitaryBrokenReply>(protoMS);
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
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//Star
	public int m_Star;
	public int Star
	{
		get { return m_Star;}
		set { m_Star = value; }
	}
	//Exp
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}


};
//CampFightContribution通知封装类
[System.Serializable]
public class CampFigthRpcCampFightContributionNotifyWraper
{

	//构造函数
	public CampFigthRpcCampFightContributionNotifyWraper()
	{
		 m_Camp = -1;
		 m_ContributionValue = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Camp = -1;
		 m_ContributionValue = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcCampFightContributionNotify ToPB()
	{
		CampFigthRpcCampFightContributionNotify v = new CampFigthRpcCampFightContributionNotify();
		v.Camp = m_Camp;
		v.ContributionValue = m_ContributionValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcCampFightContributionNotify v)
	{
        if (v == null)
            return;
		m_Camp = v.Camp;
		m_ContributionValue = v.ContributionValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcCampFightContributionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcCampFightContributionNotify pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcCampFightContributionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//Camp
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//ContributionValue
	public int m_ContributionValue;
	public int ContributionValue
	{
		get { return m_ContributionValue;}
		set { m_ContributionValue = value; }
	}


};
//ObjKillBroadcast通知封装类
[System.Serializable]
public class CampFigthRpcObjKillBroadcastNotifyWraper
{

	//构造函数
	public CampFigthRpcObjKillBroadcastNotifyWraper()
	{
		 m_KillerObjID = -1;
		 m_KillerName = -1;
		 m_DeadObjID = -1;
		 m_DeadObjResID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KillerObjID = -1;
		 m_KillerName = -1;
		 m_DeadObjID = -1;
		 m_DeadObjResID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcObjKillBroadcastNotify ToPB()
	{
		CampFigthRpcObjKillBroadcastNotify v = new CampFigthRpcObjKillBroadcastNotify();
		v.KillerObjID = m_KillerObjID;
		v.KillerName = m_KillerName;
		v.DeadObjID = m_DeadObjID;
		v.DeadObjResID = m_DeadObjResID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcObjKillBroadcastNotify v)
	{
        if (v == null)
            return;
		m_KillerObjID = v.KillerObjID;
		m_KillerName = v.KillerName;
		m_DeadObjID = v.DeadObjID;
		m_DeadObjResID = v.DeadObjResID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcObjKillBroadcastNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcObjKillBroadcastNotify pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcObjKillBroadcastNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//KillerObjID
	public int m_KillerObjID;
	public int KillerObjID
	{
		get { return m_KillerObjID;}
		set { m_KillerObjID = value; }
	}
	//KillerName
	public int m_KillerName;
	public int KillerName
	{
		get { return m_KillerName;}
		set { m_KillerName = value; }
	}
	//DeadObjID
	public int m_DeadObjID;
	public int DeadObjID
	{
		get { return m_DeadObjID;}
		set { m_DeadObjID = value; }
	}
	//DeadObjResID
	public int m_DeadObjResID;
	public int DeadObjResID
	{
		get { return m_DeadObjResID;}
		set { m_DeadObjResID = value; }
	}


};
//NpcBirth通知封装类
[System.Serializable]
public class CampFigthRpcNpcBirthNotifyWraper
{

	//构造函数
	public CampFigthRpcNpcBirthNotifyWraper()
	{
		 m_Camp = -1;
		 m_BirthObjID = -1;
		 m_BirthObjResID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Camp = -1;
		 m_BirthObjID = -1;
		 m_BirthObjResID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcNpcBirthNotify ToPB()
	{
		CampFigthRpcNpcBirthNotify v = new CampFigthRpcNpcBirthNotify();
		v.Camp = m_Camp;
		v.BirthObjID = m_BirthObjID;
		v.BirthObjResID = m_BirthObjResID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcNpcBirthNotify v)
	{
        if (v == null)
            return;
		m_Camp = v.Camp;
		m_BirthObjID = v.BirthObjID;
		m_BirthObjResID = v.BirthObjResID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcNpcBirthNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcNpcBirthNotify pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcNpcBirthNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//Camp
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//BirthObjID
	public int m_BirthObjID;
	public int BirthObjID
	{
		get { return m_BirthObjID;}
		set { m_BirthObjID = value; }
	}
	//BirthObjResID
	public int m_BirthObjResID;
	public int BirthObjResID
	{
		get { return m_BirthObjResID;}
		set { m_BirthObjResID = value; }
	}


};
//GetMilitaryValue请求封装类
[System.Serializable]
public class CampFigthRpcGetMilitaryValueAskWraper
{

	//构造函数
	public CampFigthRpcGetMilitaryValueAskWraper()
	{
		 m_RoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcGetMilitaryValueAsk ToPB()
	{
		CampFigthRpcGetMilitaryValueAsk v = new CampFigthRpcGetMilitaryValueAsk();
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcGetMilitaryValueAsk v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcGetMilitaryValueAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcGetMilitaryValueAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcGetMilitaryValueAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public int m_RoleID;
	public int RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//GetMilitaryValue回应封装类
[System.Serializable]
public class CampFigthRpcGetMilitaryValueReplyWraper
{

	//构造函数
	public CampFigthRpcGetMilitaryValueReplyWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Exp = -1;
		 m_Curseason = -1;
		 m_TodayHornor = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Exp = -1;
		 m_Curseason = -1;
		 m_TodayHornor = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcGetMilitaryValueReply ToPB()
	{
		CampFigthRpcGetMilitaryValueReply v = new CampFigthRpcGetMilitaryValueReply();
		v.Result = m_Result;
		v.Rank = m_Rank;
		v.Star = m_Star;
		v.Exp = m_Exp;
		v.Curseason = m_Curseason;
		v.TodayHornor = m_TodayHornor;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcGetMilitaryValueReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Rank = v.Rank;
		m_Star = v.Star;
		m_Exp = v.Exp;
		m_Curseason = v.Curseason;
		m_TodayHornor = v.TodayHornor;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcGetMilitaryValueReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcGetMilitaryValueReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcGetMilitaryValueReply>(protoMS);
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
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//Star
	public int m_Star;
	public int Star
	{
		get { return m_Star;}
		set { m_Star = value; }
	}
	//Exp
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//当前赛季
	public int m_Curseason;
	public int Curseason
	{
		get { return m_Curseason;}
		set { m_Curseason = value; }
	}
	//今日获得荣誉值
	public int m_TodayHornor;
	public int TodayHornor
	{
		get { return m_TodayHornor;}
		set { m_TodayHornor = value; }
	}


};
//KillDeadInfo通知封装类
[System.Serializable]
public class CampFigthRpcKillDeadInfoNotifyWraper
{

	//构造函数
	public CampFigthRpcKillDeadInfoNotifyWraper()
	{
		 m_KillNum = -1;
		 m_DeadNum = -1;
		 m_Rank = -1;
		 m_Exp = -1;
		 m_Star = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KillNum = -1;
		 m_DeadNum = -1;
		 m_Rank = -1;
		 m_Exp = -1;
		 m_Star = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcKillDeadInfoNotify ToPB()
	{
		CampFigthRpcKillDeadInfoNotify v = new CampFigthRpcKillDeadInfoNotify();
		v.KillNum = m_KillNum;
		v.DeadNum = m_DeadNum;
		v.Rank = m_Rank;
		v.Exp = m_Exp;
		v.Star = m_Star;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcKillDeadInfoNotify v)
	{
        if (v == null)
            return;
		m_KillNum = v.KillNum;
		m_DeadNum = v.DeadNum;
		m_Rank = v.Rank;
		m_Exp = v.Exp;
		m_Star = v.Star;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcKillDeadInfoNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcKillDeadInfoNotify pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcKillDeadInfoNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//KillNum
	public int m_KillNum;
	public int KillNum
	{
		get { return m_KillNum;}
		set { m_KillNum = value; }
	}
	//DeadNum
	public int m_DeadNum;
	public int DeadNum
	{
		get { return m_DeadNum;}
		set { m_DeadNum = value; }
	}
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//Exp
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//Star
	public int m_Star;
	public int Star
	{
		get { return m_Star;}
		set { m_Star = value; }
	}


};
//Worship请求封装类
[System.Serializable]
public class CampFigthRpcWorshipAskWraper
{

	//构造函数
	public CampFigthRpcWorshipAskWraper()
	{
		 m_WorshipRoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_WorshipRoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcWorshipAsk ToPB()
	{
		CampFigthRpcWorshipAsk v = new CampFigthRpcWorshipAsk();
		v.WorshipRoleID = m_WorshipRoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcWorshipAsk v)
	{
        if (v == null)
            return;
		m_WorshipRoleID = v.WorshipRoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcWorshipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcWorshipAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcWorshipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//WorshipRoleID
	public int m_WorshipRoleID;
	public int WorshipRoleID
	{
		get { return m_WorshipRoleID;}
		set { m_WorshipRoleID = value; }
	}


};
//Worship回应封装类
[System.Serializable]
public class CampFigthRpcWorshipReplyWraper
{

	//构造函数
	public CampFigthRpcWorshipReplyWraper()
	{
		 m_Result = -1;
		 m_WorshipRoleID = -1;
		 m_WorshipCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_WorshipRoleID = -1;
		 m_WorshipCount = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcWorshipReply ToPB()
	{
		CampFigthRpcWorshipReply v = new CampFigthRpcWorshipReply();
		v.Result = m_Result;
		v.WorshipRoleID = m_WorshipRoleID;
		v.WorshipCount = m_WorshipCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcWorshipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_WorshipRoleID = v.WorshipRoleID;
		m_WorshipCount = v.WorshipCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcWorshipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcWorshipReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcWorshipReply>(protoMS);
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
	//WorshipRoleID
	public int m_WorshipRoleID;
	public int WorshipRoleID
	{
		get { return m_WorshipRoleID;}
		set { m_WorshipRoleID = value; }
	}
	//WorshipCount
	public int m_WorshipCount;
	public int WorshipCount
	{
		get { return m_WorshipCount;}
		set { m_WorshipCount = value; }
	}


};
//WorshipRank请求封装类
[System.Serializable]
public class CampFigthRpcWorshipRankAskWraper
{

	//构造函数
	public CampFigthRpcWorshipRankAskWraper()
	{
		 m_RoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcWorshipRankAsk ToPB()
	{
		CampFigthRpcWorshipRankAsk v = new CampFigthRpcWorshipRankAsk();
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcWorshipRankAsk v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcWorshipRankAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcWorshipRankAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcWorshipRankAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public int m_RoleID;
	public int RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//WorshipRank回应封装类
[System.Serializable]
public class CampFigthRpcWorshipRankReplyWraper
{

	//构造函数
	public CampFigthRpcWorshipRankReplyWraper()
	{
		 m_Result = -1;
		m_RoleDatas = new List<WorshipPlayerDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RoleDatas = new List<WorshipPlayerDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcWorshipRankReply ToPB()
	{
		CampFigthRpcWorshipRankReply v = new CampFigthRpcWorshipRankReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RoleDatas.Count; i++)
			v.RoleDatas.Add( m_RoleDatas[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcWorshipRankReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleDatas.Clear();
		for( int i=0; i<v.RoleDatas.Count; i++)
			m_RoleDatas.Add( new WorshipPlayerDataWraper());
		for( int i=0; i<v.RoleDatas.Count; i++)
			m_RoleDatas[i].FromPB(v.RoleDatas[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcWorshipRankReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcWorshipRankReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcWorshipRankReply>(protoMS);
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
	//RoleDatas
	public List<WorshipPlayerDataWraper> m_RoleDatas;
	public int SizeRoleDatas()
	{
		return m_RoleDatas.Count;
	}
	public List<WorshipPlayerDataWraper> GetRoleDatas()
	{
		return m_RoleDatas;
	}
	public WorshipPlayerDataWraper GetRoleDatas(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleDatas.Count)
			return new WorshipPlayerDataWraper();
		return m_RoleDatas[Index];
	}
	public void SetRoleDatas( List<WorshipPlayerDataWraper> v )
	{
		m_RoleDatas=v;
	}
	public void SetRoleDatas( int Index, WorshipPlayerDataWraper v )
	{
		if(Index<0 || Index>=(int)m_RoleDatas.Count)
			return;
		m_RoleDatas[Index] = v;
	}
	public void AddRoleDatas( WorshipPlayerDataWraper v )
	{
		m_RoleDatas.Add(v);
	}
	public void ClearRoleDatas( )
	{
		m_RoleDatas.Clear();
	}


};
//新赛季通知封装类
[System.Serializable]
public class CampFigthRpcNewSeasonNotifyWraper
{

	//构造函数
	public CampFigthRpcNewSeasonNotifyWraper()
	{
		 m_Rank = -1;
		 m_Star = -1;
		 m_RankIndex = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();
		 m_Lastseason = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Rank = -1;
		 m_Star = -1;
		 m_RankIndex = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();
		 m_Lastseason = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcNewSeasonNotify ToPB()
	{
		CampFigthRpcNewSeasonNotify v = new CampFigthRpcNewSeasonNotify();
		v.Rank = m_Rank;
		v.Star = m_Star;
		v.RankIndex = m_RankIndex;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i].ToPB());
		v.Lastseason = m_Lastseason;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcNewSeasonNotify v)
	{
        if (v == null)
            return;
		m_Rank = v.Rank;
		m_Star = v.Star;
		m_RankIndex = v.RankIndex;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add( new PvpBattleRewardInfoWraper());
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList[i].FromPB(v.RewardList[i]);
		m_Lastseason = v.Lastseason;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcNewSeasonNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcNewSeasonNotify pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcNewSeasonNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//段位
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//星级
	public int m_Star;
	public int Star
	{
		get { return m_Star;}
		set { m_Star = value; }
	}
	//排名
	public int m_RankIndex;
	public int RankIndex
	{
		get { return m_RankIndex;}
		set { m_RankIndex = value; }
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
	//上一赛季
	public int m_Lastseason;
	public int Lastseason
	{
		get { return m_Lastseason;}
		set { m_Lastseason = value; }
	}


};
//同步段位奖励请求封装类
[System.Serializable]
public class CampFigthRpcSyncRankRewardAskWraper
{

	//构造函数
	public CampFigthRpcSyncRankRewardAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcSyncRankRewardAsk ToPB()
	{
		CampFigthRpcSyncRankRewardAsk v = new CampFigthRpcSyncRankRewardAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcSyncRankRewardAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcSyncRankRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcSyncRankRewardAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcSyncRankRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步段位奖励回应封装类
[System.Serializable]
public class CampFigthRpcSyncRankRewardReplyWraper
{

	//构造函数
	public CampFigthRpcSyncRankRewardReplyWraper()
	{
		 m_Result = -1;
		m_RankRewardList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RankRewardList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcSyncRankRewardReply ToPB()
	{
		CampFigthRpcSyncRankRewardReply v = new CampFigthRpcSyncRankRewardReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RankRewardList.Count; i++)
			v.RankRewardList.Add( m_RankRewardList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcSyncRankRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RankRewardList.Clear();
		for( int i=0; i<v.RankRewardList.Count; i++)
			m_RankRewardList.Add(v.RankRewardList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcSyncRankRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcSyncRankRewardReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcSyncRankRewardReply>(protoMS);
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
	//已领取的奖励
	public List<int> m_RankRewardList;
	public int SizeRankRewardList()
	{
		return m_RankRewardList.Count;
	}
	public List<int> GetRankRewardList()
	{
		return m_RankRewardList;
	}
	public int GetRankRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RankRewardList.Count)
			return -1;
		return m_RankRewardList[Index];
	}
	public void SetRankRewardList( List<int> v )
	{
		m_RankRewardList=v;
	}
	public void SetRankRewardList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_RankRewardList.Count)
			return;
		m_RankRewardList[Index] = v;
	}
	public void AddRankRewardList( int v=-1 )
	{
		m_RankRewardList.Add(v);
	}
	public void ClearRankRewardList( )
	{
		m_RankRewardList.Clear();
	}


};
//获取段位奖励请求封装类
[System.Serializable]
public class CampFigthRpcGetRankRewardAskWraper
{

	//构造函数
	public CampFigthRpcGetRankRewardAskWraper()
	{
		 m_Rank = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Rank = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcGetRankRewardAsk ToPB()
	{
		CampFigthRpcGetRankRewardAsk v = new CampFigthRpcGetRankRewardAsk();
		v.Rank = m_Rank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcGetRankRewardAsk v)
	{
        if (v == null)
            return;
		m_Rank = v.Rank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcGetRankRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcGetRankRewardAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcGetRankRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//段位
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}


};
//获取段位奖励回应封装类
[System.Serializable]
public class CampFigthRpcGetRankRewardReplyWraper
{

	//构造函数
	public CampFigthRpcGetRankRewardReplyWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Rank = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcGetRankRewardReply ToPB()
	{
		CampFigthRpcGetRankRewardReply v = new CampFigthRpcGetRankRewardReply();
		v.Result = m_Result;
		v.Rank = m_Rank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcGetRankRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Rank = v.Rank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcGetRankRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcGetRankRewardReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcGetRankRewardReply>(protoMS);
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
	//领取的段位
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}


};
//进入战场请求封装类
[System.Serializable]
public class CampFigthRpcEnterBattleSceneAskWraper
{

	//构造函数
	public CampFigthRpcEnterBattleSceneAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcEnterBattleSceneAsk ToPB()
	{
		CampFigthRpcEnterBattleSceneAsk v = new CampFigthRpcEnterBattleSceneAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcEnterBattleSceneAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcEnterBattleSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcEnterBattleSceneAsk pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcEnterBattleSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//进入战场回应封装类
[System.Serializable]
public class CampFigthRpcEnterBattleSceneReplyWraper
{

	//构造函数
	public CampFigthRpcEnterBattleSceneReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public CampFigthRpcEnterBattleSceneReply ToPB()
	{
		CampFigthRpcEnterBattleSceneReply v = new CampFigthRpcEnterBattleSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CampFigthRpcEnterBattleSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CampFigthRpcEnterBattleSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CampFigthRpcEnterBattleSceneReply pb = ProtoBuf.Serializer.Deserialize<CampFigthRpcEnterBattleSceneReply>(protoMS);
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
