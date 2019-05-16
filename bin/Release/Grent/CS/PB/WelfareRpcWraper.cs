
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBWelfare.cs
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


//累计登陆福利请求封装类
[System.Serializable]
public class WelfareRpcAccumulateSignInAskWraper
{

	//构造函数
	public WelfareRpcAccumulateSignInAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcAccumulateSignInAsk ToPB()
	{
		WelfareRpcAccumulateSignInAsk v = new WelfareRpcAccumulateSignInAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcAccumulateSignInAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcAccumulateSignInAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcAccumulateSignInAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcAccumulateSignInAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//累计登陆福利回应封装类
[System.Serializable]
public class WelfareRpcAccumulateSignInReplyWraper
{

	//构造函数
	public WelfareRpcAccumulateSignInReplyWraper()
	{
		 m_Result = -1;
		m_AccumulateList = new List<AccumulateSignInfoWraper>();
		 m_AccumulateDays = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_AccumulateList = new List<AccumulateSignInfoWraper>();
		 m_AccumulateDays = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcAccumulateSignInReply ToPB()
	{
		WelfareRpcAccumulateSignInReply v = new WelfareRpcAccumulateSignInReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_AccumulateList.Count; i++)
			v.AccumulateList.Add( m_AccumulateList[i].ToPB());
		v.AccumulateDays = m_AccumulateDays;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcAccumulateSignInReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AccumulateList.Clear();
		for( int i=0; i<v.AccumulateList.Count; i++)
			m_AccumulateList.Add( new AccumulateSignInfoWraper());
		for( int i=0; i<v.AccumulateList.Count; i++)
			m_AccumulateList[i].FromPB(v.AccumulateList[i]);
		m_AccumulateDays = v.AccumulateDays;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcAccumulateSignInReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcAccumulateSignInReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcAccumulateSignInReply>(protoMS);
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
	//累计登陆信息
	public List<AccumulateSignInfoWraper> m_AccumulateList;
	public int SizeAccumulateList()
	{
		return m_AccumulateList.Count;
	}
	public List<AccumulateSignInfoWraper> GetAccumulateList()
	{
		return m_AccumulateList;
	}
	public AccumulateSignInfoWraper GetAccumulateList(int Index)
	{
		if(Index<0 || Index>=(int)m_AccumulateList.Count)
			return new AccumulateSignInfoWraper();
		return m_AccumulateList[Index];
	}
	public void SetAccumulateList( List<AccumulateSignInfoWraper> v )
	{
		m_AccumulateList=v;
	}
	public void SetAccumulateList( int Index, AccumulateSignInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_AccumulateList.Count)
			return;
		m_AccumulateList[Index] = v;
	}
	public void AddAccumulateList( AccumulateSignInfoWraper v )
	{
		m_AccumulateList.Add(v);
	}
	public void ClearAccumulateList( )
	{
		m_AccumulateList.Clear();
	}
	//累计登陆天数
	public int m_AccumulateDays;
	public int AccumulateDays
	{
		get { return m_AccumulateDays;}
		set { m_AccumulateDays = value; }
	}


};
//领取累计登陆奖励请求封装类
[System.Serializable]
public class WelfareRpcAccumulateGetRewardAskWraper
{

	//构造函数
	public WelfareRpcAccumulateGetRewardAskWraper()
	{
		 m_ID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcAccumulateGetRewardAsk ToPB()
	{
		WelfareRpcAccumulateGetRewardAsk v = new WelfareRpcAccumulateGetRewardAsk();
		v.ID = m_ID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcAccumulateGetRewardAsk v)
	{
        if (v == null)
            return;
		m_ID = v.ID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcAccumulateGetRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcAccumulateGetRewardAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcAccumulateGetRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}


};
//领取累计登陆奖励回应封装类
[System.Serializable]
public class WelfareRpcAccumulateGetRewardReplyWraper
{

	//构造函数
	public WelfareRpcAccumulateGetRewardReplyWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcAccumulateGetRewardReply ToPB()
	{
		WelfareRpcAccumulateGetRewardReply v = new WelfareRpcAccumulateGetRewardReply();
		v.Result = m_Result;
		v.RewardID = m_RewardID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcAccumulateGetRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RewardID = v.RewardID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcAccumulateGetRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcAccumulateGetRewardReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcAccumulateGetRewardReply>(protoMS);
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
	//奖励ID
	public int m_RewardID;
	public int RewardID
	{
		get { return m_RewardID;}
		set { m_RewardID = value; }
	}


};
//今日在线福利请求封装类
[System.Serializable]
public class WelfareRpcOnlineBonusAskWraper
{

	//构造函数
	public WelfareRpcOnlineBonusAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcOnlineBonusAsk ToPB()
	{
		WelfareRpcOnlineBonusAsk v = new WelfareRpcOnlineBonusAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcOnlineBonusAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcOnlineBonusAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcOnlineBonusAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcOnlineBonusAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//今日在线福利回应封装类
[System.Serializable]
public class WelfareRpcOnlineBonusReplyWraper
{

	//构造函数
	public WelfareRpcOnlineBonusReplyWraper()
	{
		 m_Result = -1;
		m_OnlineBonusList = new List<OnlineInfoWraper>();
		 m_TodayOnlineTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_OnlineBonusList = new List<OnlineInfoWraper>();
		 m_TodayOnlineTime = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcOnlineBonusReply ToPB()
	{
		WelfareRpcOnlineBonusReply v = new WelfareRpcOnlineBonusReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_OnlineBonusList.Count; i++)
			v.OnlineBonusList.Add( m_OnlineBonusList[i].ToPB());
		v.TodayOnlineTime = m_TodayOnlineTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcOnlineBonusReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_OnlineBonusList.Clear();
		for( int i=0; i<v.OnlineBonusList.Count; i++)
			m_OnlineBonusList.Add( new OnlineInfoWraper());
		for( int i=0; i<v.OnlineBonusList.Count; i++)
			m_OnlineBonusList[i].FromPB(v.OnlineBonusList[i]);
		m_TodayOnlineTime = v.TodayOnlineTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcOnlineBonusReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcOnlineBonusReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcOnlineBonusReply>(protoMS);
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
	//今日在线福利信息
	public List<OnlineInfoWraper> m_OnlineBonusList;
	public int SizeOnlineBonusList()
	{
		return m_OnlineBonusList.Count;
	}
	public List<OnlineInfoWraper> GetOnlineBonusList()
	{
		return m_OnlineBonusList;
	}
	public OnlineInfoWraper GetOnlineBonusList(int Index)
	{
		if(Index<0 || Index>=(int)m_OnlineBonusList.Count)
			return new OnlineInfoWraper();
		return m_OnlineBonusList[Index];
	}
	public void SetOnlineBonusList( List<OnlineInfoWraper> v )
	{
		m_OnlineBonusList=v;
	}
	public void SetOnlineBonusList( int Index, OnlineInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_OnlineBonusList.Count)
			return;
		m_OnlineBonusList[Index] = v;
	}
	public void AddOnlineBonusList( OnlineInfoWraper v )
	{
		m_OnlineBonusList.Add(v);
	}
	public void ClearOnlineBonusList( )
	{
		m_OnlineBonusList.Clear();
	}
	//今日在线时间
	public int m_TodayOnlineTime;
	public int TodayOnlineTime
	{
		get { return m_TodayOnlineTime;}
		set { m_TodayOnlineTime = value; }
	}


};
//领取今日在线奖励请求封装类
[System.Serializable]
public class WelfareRpcOnlineGetRewardAskWraper
{

	//构造函数
	public WelfareRpcOnlineGetRewardAskWraper()
	{
		 m_ID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcOnlineGetRewardAsk ToPB()
	{
		WelfareRpcOnlineGetRewardAsk v = new WelfareRpcOnlineGetRewardAsk();
		v.ID = m_ID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcOnlineGetRewardAsk v)
	{
        if (v == null)
            return;
		m_ID = v.ID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcOnlineGetRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcOnlineGetRewardAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcOnlineGetRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}


};
//领取今日在线奖励回应封装类
[System.Serializable]
public class WelfareRpcOnlineGetRewardReplyWraper
{

	//构造函数
	public WelfareRpcOnlineGetRewardReplyWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcOnlineGetRewardReply ToPB()
	{
		WelfareRpcOnlineGetRewardReply v = new WelfareRpcOnlineGetRewardReply();
		v.Result = m_Result;
		v.RewardID = m_RewardID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcOnlineGetRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RewardID = v.RewardID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcOnlineGetRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcOnlineGetRewardReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcOnlineGetRewardReply>(protoMS);
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
	//奖励ID
	public int m_RewardID;
	public int RewardID
	{
		get { return m_RewardID;}
		set { m_RewardID = value; }
	}


};
//等级福利请求封装类
[System.Serializable]
public class WelfareRpcLevelBonusAskWraper
{

	//构造函数
	public WelfareRpcLevelBonusAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcLevelBonusAsk ToPB()
	{
		WelfareRpcLevelBonusAsk v = new WelfareRpcLevelBonusAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcLevelBonusAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcLevelBonusAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcLevelBonusAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcLevelBonusAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//等级福利回应封装类
[System.Serializable]
public class WelfareRpcLevelBonusReplyWraper
{

	//构造函数
	public WelfareRpcLevelBonusReplyWraper()
	{
		 m_Result = -1;
		m_LevelBonusList = new List<LevelInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_LevelBonusList = new List<LevelInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcLevelBonusReply ToPB()
	{
		WelfareRpcLevelBonusReply v = new WelfareRpcLevelBonusReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_LevelBonusList.Count; i++)
			v.LevelBonusList.Add( m_LevelBonusList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcLevelBonusReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_LevelBonusList.Clear();
		for( int i=0; i<v.LevelBonusList.Count; i++)
			m_LevelBonusList.Add( new LevelInfoWraper());
		for( int i=0; i<v.LevelBonusList.Count; i++)
			m_LevelBonusList[i].FromPB(v.LevelBonusList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcLevelBonusReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcLevelBonusReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcLevelBonusReply>(protoMS);
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
	//等级福利信息
	public List<LevelInfoWraper> m_LevelBonusList;
	public int SizeLevelBonusList()
	{
		return m_LevelBonusList.Count;
	}
	public List<LevelInfoWraper> GetLevelBonusList()
	{
		return m_LevelBonusList;
	}
	public LevelInfoWraper GetLevelBonusList(int Index)
	{
		if(Index<0 || Index>=(int)m_LevelBonusList.Count)
			return new LevelInfoWraper();
		return m_LevelBonusList[Index];
	}
	public void SetLevelBonusList( List<LevelInfoWraper> v )
	{
		m_LevelBonusList=v;
	}
	public void SetLevelBonusList( int Index, LevelInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_LevelBonusList.Count)
			return;
		m_LevelBonusList[Index] = v;
	}
	public void AddLevelBonusList( LevelInfoWraper v )
	{
		m_LevelBonusList.Add(v);
	}
	public void ClearLevelBonusList( )
	{
		m_LevelBonusList.Clear();
	}


};
//领取等级福利奖励请求封装类
[System.Serializable]
public class WelfareRpcLevelBonusRewardAskWraper
{

	//构造函数
	public WelfareRpcLevelBonusRewardAskWraper()
	{
		 m_ID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcLevelBonusRewardAsk ToPB()
	{
		WelfareRpcLevelBonusRewardAsk v = new WelfareRpcLevelBonusRewardAsk();
		v.ID = m_ID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcLevelBonusRewardAsk v)
	{
        if (v == null)
            return;
		m_ID = v.ID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcLevelBonusRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcLevelBonusRewardAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcLevelBonusRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}


};
//领取等级福利奖励回应封装类
[System.Serializable]
public class WelfareRpcLevelBonusRewardReplyWraper
{

	//构造函数
	public WelfareRpcLevelBonusRewardReplyWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcLevelBonusRewardReply ToPB()
	{
		WelfareRpcLevelBonusRewardReply v = new WelfareRpcLevelBonusRewardReply();
		v.Result = m_Result;
		v.RewardID = m_RewardID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcLevelBonusRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RewardID = v.RewardID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcLevelBonusRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcLevelBonusRewardReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcLevelBonusRewardReply>(protoMS);
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
	//奖励ID
	public int m_RewardID;
	public int RewardID
	{
		get { return m_RewardID;}
		set { m_RewardID = value; }
	}


};
//签到福利请求封装类
[System.Serializable]
public class WelfareRpcMonthSignInBonusAskWraper
{

	//构造函数
	public WelfareRpcMonthSignInBonusAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcMonthSignInBonusAsk ToPB()
	{
		WelfareRpcMonthSignInBonusAsk v = new WelfareRpcMonthSignInBonusAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcMonthSignInBonusAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcMonthSignInBonusAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcMonthSignInBonusAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcMonthSignInBonusAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//签到福利回应封装类
[System.Serializable]
public class WelfareRpcMonthSignInBonusReplyWraper
{

	//构造函数
	public WelfareRpcMonthSignInBonusReplyWraper()
	{
		 m_Result = -1;
		 m_Year = -1;
		 m_Month = -1;
		 m_Date = -1;
		 m_FixSignInTimes = -1;
		m_MonthSignInList = new List<MonthSignInInfoWraper>();
		 m_Day = -1;
		 m_TodaySignIn = false;
		 m_FixSignInDays = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Year = -1;
		 m_Month = -1;
		 m_Date = -1;
		 m_FixSignInTimes = -1;
		m_MonthSignInList = new List<MonthSignInInfoWraper>();
		 m_Day = -1;
		 m_TodaySignIn = false;
		 m_FixSignInDays = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcMonthSignInBonusReply ToPB()
	{
		WelfareRpcMonthSignInBonusReply v = new WelfareRpcMonthSignInBonusReply();
		v.Result = m_Result;
		v.Year = m_Year;
		v.Month = m_Month;
		v.Date = m_Date;
		v.FixSignInTimes = m_FixSignInTimes;
		for (int i=0; i<(int)m_MonthSignInList.Count; i++)
			v.MonthSignInList.Add( m_MonthSignInList[i].ToPB());
		v.Day = m_Day;
		v.TodaySignIn = m_TodaySignIn;
		v.FixSignInDays = m_FixSignInDays;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcMonthSignInBonusReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Year = v.Year;
		m_Month = v.Month;
		m_Date = v.Date;
		m_FixSignInTimes = v.FixSignInTimes;
		m_MonthSignInList.Clear();
		for( int i=0; i<v.MonthSignInList.Count; i++)
			m_MonthSignInList.Add( new MonthSignInInfoWraper());
		for( int i=0; i<v.MonthSignInList.Count; i++)
			m_MonthSignInList[i].FromPB(v.MonthSignInList[i]);
		m_Day = v.Day;
		m_TodaySignIn = v.TodaySignIn;
		m_FixSignInDays = v.FixSignInDays;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcMonthSignInBonusReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcMonthSignInBonusReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcMonthSignInBonusReply>(protoMS);
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
	//年
	public int m_Year;
	public int Year
	{
		get { return m_Year;}
		set { m_Year = value; }
	}
	//月
	public int m_Month;
	public int Month
	{
		get { return m_Month;}
		set { m_Month = value; }
	}
	//日
	public int m_Date;
	public int Date
	{
		get { return m_Date;}
		set { m_Date = value; }
	}
	//补签剩余次数
	public int m_FixSignInTimes;
	public int FixSignInTimes
	{
		get { return m_FixSignInTimes;}
		set { m_FixSignInTimes = value; }
	}
	//签到福利信息
	public List<MonthSignInInfoWraper> m_MonthSignInList;
	public int SizeMonthSignInList()
	{
		return m_MonthSignInList.Count;
	}
	public List<MonthSignInInfoWraper> GetMonthSignInList()
	{
		return m_MonthSignInList;
	}
	public MonthSignInInfoWraper GetMonthSignInList(int Index)
	{
		if(Index<0 || Index>=(int)m_MonthSignInList.Count)
			return new MonthSignInInfoWraper();
		return m_MonthSignInList[Index];
	}
	public void SetMonthSignInList( List<MonthSignInInfoWraper> v )
	{
		m_MonthSignInList=v;
	}
	public void SetMonthSignInList( int Index, MonthSignInInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_MonthSignInList.Count)
			return;
		m_MonthSignInList[Index] = v;
	}
	public void AddMonthSignInList( MonthSignInInfoWraper v )
	{
		m_MonthSignInList.Add(v);
	}
	public void ClearMonthSignInList( )
	{
		m_MonthSignInList.Clear();
	}
	//周几
	public int m_Day;
	public int Day
	{
		get { return m_Day;}
		set { m_Day = value; }
	}
	//今天是否签到
	public bool m_TodaySignIn;
	public bool TodaySignIn
	{
		get { return m_TodaySignIn;}
		set { m_TodaySignIn = value; }
	}
	//可补签的最后一天
	public int m_FixSignInDays;
	public int FixSignInDays
	{
		get { return m_FixSignInDays;}
		set { m_FixSignInDays = value; }
	}


};
//签到请求封装类
[System.Serializable]
public class WelfareRpcMonthSignInRewardAskWraper
{

	//构造函数
	public WelfareRpcMonthSignInRewardAskWraper()
	{
		 m_ID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcMonthSignInRewardAsk ToPB()
	{
		WelfareRpcMonthSignInRewardAsk v = new WelfareRpcMonthSignInRewardAsk();
		v.ID = m_ID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcMonthSignInRewardAsk v)
	{
        if (v == null)
            return;
		m_ID = v.ID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcMonthSignInRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcMonthSignInRewardAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcMonthSignInRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}


};
//签到回应封装类
[System.Serializable]
public class WelfareRpcMonthSignInRewardReplyWraper
{

	//构造函数
	public WelfareRpcMonthSignInRewardReplyWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;
		 m_FixSignInTimes = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RewardID = -1;
		 m_FixSignInTimes = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcMonthSignInRewardReply ToPB()
	{
		WelfareRpcMonthSignInRewardReply v = new WelfareRpcMonthSignInRewardReply();
		v.Result = m_Result;
		v.RewardID = m_RewardID;
		v.FixSignInTimes = m_FixSignInTimes;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcMonthSignInRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RewardID = v.RewardID;
		m_FixSignInTimes = v.FixSignInTimes;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcMonthSignInRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcMonthSignInRewardReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcMonthSignInRewardReply>(protoMS);
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
	//奖励ID
	public int m_RewardID;
	public int RewardID
	{
		get { return m_RewardID;}
		set { m_RewardID = value; }
	}
	//可补签天数
	public int m_FixSignInTimes;
	public int FixSignInTimes
	{
		get { return m_FixSignInTimes;}
		set { m_FixSignInTimes = value; }
	}


};
//今日签到提醒通知封装类
[System.Serializable]
public class WelfareRpcTodaySignInNotifyWraper
{

	//构造函数
	public WelfareRpcTodaySignInNotifyWraper()
	{
		 m_TodaySignIn = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TodaySignIn = false;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcTodaySignInNotify ToPB()
	{
		WelfareRpcTodaySignInNotify v = new WelfareRpcTodaySignInNotify();
		v.TodaySignIn = m_TodaySignIn;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcTodaySignInNotify v)
	{
        if (v == null)
            return;
		m_TodaySignIn = v.TodaySignIn;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcTodaySignInNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcTodaySignInNotify pb = ProtoBuf.Serializer.Deserialize<WelfareRpcTodaySignInNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//今日是否已签到
	public bool m_TodaySignIn;
	public bool TodaySignIn
	{
		get { return m_TodaySignIn;}
		set { m_TodaySignIn = value; }
	}


};
//运营登录活动通知封装类
[System.Serializable]
public class WelfareRpcSpecLoginNotifyWraper
{

	//构造函数
	public WelfareRpcSpecLoginNotifyWraper()
	{
		m_SpecLogin = new List<SpecLoginInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SpecLogin = new List<SpecLoginInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcSpecLoginNotify ToPB()
	{
		WelfareRpcSpecLoginNotify v = new WelfareRpcSpecLoginNotify();
		for (int i=0; i<(int)m_SpecLogin.Count; i++)
			v.SpecLogin.Add( m_SpecLogin[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcSpecLoginNotify v)
	{
        if (v == null)
            return;
		m_SpecLogin.Clear();
		for( int i=0; i<v.SpecLogin.Count; i++)
			m_SpecLogin.Add( new SpecLoginInfoWraper());
		for( int i=0; i<v.SpecLogin.Count; i++)
			m_SpecLogin[i].FromPB(v.SpecLogin[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcSpecLoginNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcSpecLoginNotify pb = ProtoBuf.Serializer.Deserialize<WelfareRpcSpecLoginNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//运营登录活动消息
	public List<SpecLoginInfoWraper> m_SpecLogin;
	public int SizeSpecLogin()
	{
		return m_SpecLogin.Count;
	}
	public List<SpecLoginInfoWraper> GetSpecLogin()
	{
		return m_SpecLogin;
	}
	public SpecLoginInfoWraper GetSpecLogin(int Index)
	{
		if(Index<0 || Index>=(int)m_SpecLogin.Count)
			return new SpecLoginInfoWraper();
		return m_SpecLogin[Index];
	}
	public void SetSpecLogin( List<SpecLoginInfoWraper> v )
	{
		m_SpecLogin=v;
	}
	public void SetSpecLogin( int Index, SpecLoginInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_SpecLogin.Count)
			return;
		m_SpecLogin[Index] = v;
	}
	public void AddSpecLogin( SpecLoginInfoWraper v )
	{
		m_SpecLogin.Add(v);
	}
	public void ClearSpecLogin( )
	{
		m_SpecLogin.Clear();
	}


};
//运营登录活动领取奖励请求封装类
[System.Serializable]
public class WelfareRpcSpecLoginRewardAskWraper
{

	//构造函数
	public WelfareRpcSpecLoginRewardAskWraper()
	{
		 m_Id = -1;
		 m_Index = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Index = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcSpecLoginRewardAsk ToPB()
	{
		WelfareRpcSpecLoginRewardAsk v = new WelfareRpcSpecLoginRewardAsk();
		v.Id = m_Id;
		v.Index = m_Index;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcSpecLoginRewardAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Index = v.Index;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcSpecLoginRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcSpecLoginRewardAsk pb = ProtoBuf.Serializer.Deserialize<WelfareRpcSpecLoginRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}


};
//运营登录活动领取奖励回应封装类
[System.Serializable]
public class WelfareRpcSpecLoginRewardReplyWraper
{

	//构造函数
	public WelfareRpcSpecLoginRewardReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareRpcSpecLoginRewardReply ToPB()
	{
		WelfareRpcSpecLoginRewardReply v = new WelfareRpcSpecLoginRewardReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareRpcSpecLoginRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareRpcSpecLoginRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareRpcSpecLoginRewardReply pb = ProtoBuf.Serializer.Deserialize<WelfareRpcSpecLoginRewardReply>(protoMS);
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
