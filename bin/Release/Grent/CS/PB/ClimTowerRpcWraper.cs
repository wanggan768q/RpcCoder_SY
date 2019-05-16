
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBClimTower.cs
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


//玩法开启规则通知封装类
[System.Serializable]
public class ClimTowerRpcOpenRuleNotifyWraper
{

	//构造函数
	public ClimTowerRpcOpenRuleNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcOpenRuleNotify ToPB()
	{
		ClimTowerRpcOpenRuleNotify v = new ClimTowerRpcOpenRuleNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcOpenRuleNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcOpenRuleNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcOpenRuleNotify pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcOpenRuleNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//挑战请求封装类
[System.Serializable]
public class ClimTowerRpcChallengeAskWraper
{

	//构造函数
	public ClimTowerRpcChallengeAskWraper()
	{
		 m_Layer = 1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Layer = 1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcChallengeAsk ToPB()
	{
		ClimTowerRpcChallengeAsk v = new ClimTowerRpcChallengeAsk();
		v.Layer = m_Layer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcChallengeAsk v)
	{
        if (v == null)
            return;
		m_Layer = v.Layer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcChallengeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcChallengeAsk pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcChallengeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//挑战层
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}


};
//挑战回应封装类
[System.Serializable]
public class ClimTowerRpcChallengeReplyWraper
{

	//构造函数
	public ClimTowerRpcChallengeReplyWraper()
	{
		 m_Result = -1;
		 m_DungeonId = -1;
		 m_SceneId = -1;
		 m_WayPoint = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_DungeonId = -1;
		 m_SceneId = -1;
		 m_WayPoint = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcChallengeReply ToPB()
	{
		ClimTowerRpcChallengeReply v = new ClimTowerRpcChallengeReply();
		v.Result = m_Result;
		v.DungeonId = m_DungeonId;
		v.SceneId = m_SceneId;
		v.WayPoint = m_WayPoint;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcChallengeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DungeonId = v.DungeonId;
		m_SceneId = v.SceneId;
		m_WayPoint = v.WayPoint;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcChallengeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcChallengeReply pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcChallengeReply>(protoMS);
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
	//副本id
	public int m_DungeonId;
	public int DungeonId
	{
		get { return m_DungeonId;}
		set { m_DungeonId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//路点
	public int m_WayPoint;
	public int WayPoint
	{
		get { return m_WayPoint;}
		set { m_WayPoint = value; }
	}


};
//进入爬塔活动请求封装类
[System.Serializable]
public class ClimTowerRpcEnterAskWraper
{

	//构造函数
	public ClimTowerRpcEnterAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcEnterAsk ToPB()
	{
		ClimTowerRpcEnterAsk v = new ClimTowerRpcEnterAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcEnterAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcEnterAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcEnterAsk pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcEnterAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//进入爬塔活动回应封装类
[System.Serializable]
public class ClimTowerRpcEnterReplyWraper
{

	//构造函数
	public ClimTowerRpcEnterReplyWraper()
	{
		 m_Result = -1;
		 m_EnterInfo = new ClimTowerInfoWraper();
		 m_RemainTimes = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_EnterInfo = new ClimTowerInfoWraper();
		 m_RemainTimes = 0;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcEnterReply ToPB()
	{
		ClimTowerRpcEnterReply v = new ClimTowerRpcEnterReply();
		v.Result = m_Result;
		v.EnterInfo = m_EnterInfo.ToPB();
		v.RemainTimes = m_RemainTimes;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcEnterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EnterInfo.FromPB(v.EnterInfo);
		m_RemainTimes = v.RemainTimes;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcEnterReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcEnterReply pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcEnterReply>(protoMS);
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
	//进入爬塔挑战
	public ClimTowerInfoWraper m_EnterInfo;
	public ClimTowerInfoWraper EnterInfo
	{
		get { return m_EnterInfo;}
		set { m_EnterInfo = value; }
	}
	//剩余挑战次数
	public int m_RemainTimes;
	public int RemainTimes
	{
		get { return m_RemainTimes;}
		set { m_RemainTimes = value; }
	}


};
//获取排行榜信息请求封装类
[System.Serializable]
public class ClimTowerRpcRankAskWraper
{

	//构造函数
	public ClimTowerRpcRankAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcRankAsk ToPB()
	{
		ClimTowerRpcRankAsk v = new ClimTowerRpcRankAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcRankAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcRankAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcRankAsk pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcRankAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//获取排行榜信息回应封装类
[System.Serializable]
public class ClimTowerRpcRankReplyWraper
{

	//构造函数
	public ClimTowerRpcRankReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcRankReply ToPB()
	{
		ClimTowerRpcRankReply v = new ClimTowerRpcRankReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcRankReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcRankReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcRankReply pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcRankReply>(protoMS);
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
//首次通关奖励领奖请求封装类
[System.Serializable]
public class ClimTowerRpcFirstVicRewardAskWraper
{

	//构造函数
	public ClimTowerRpcFirstVicRewardAskWraper()
	{
		 m_Layer = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Layer = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcFirstVicRewardAsk ToPB()
	{
		ClimTowerRpcFirstVicRewardAsk v = new ClimTowerRpcFirstVicRewardAsk();
		v.Layer = m_Layer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcFirstVicRewardAsk v)
	{
        if (v == null)
            return;
		m_Layer = v.Layer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcFirstVicRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcFirstVicRewardAsk pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcFirstVicRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//领取哪一层奖励
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}


};
//首次通关奖励领奖回应封装类
[System.Serializable]
public class ClimTowerRpcFirstVicRewardReplyWraper
{

	//构造函数
	public ClimTowerRpcFirstVicRewardReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcFirstVicRewardReply ToPB()
	{
		ClimTowerRpcFirstVicRewardReply v = new ClimTowerRpcFirstVicRewardReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcFirstVicRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcFirstVicRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcFirstVicRewardReply pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcFirstVicRewardReply>(protoMS);
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
//下一层通知通知封装类
[System.Serializable]
public class ClimTowerRpcNextLayerNotifyWraper
{

	//构造函数
	public ClimTowerRpcNextLayerNotifyWraper()
	{
		 m_CurLayer = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CurLayer = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcNextLayerNotify ToPB()
	{
		ClimTowerRpcNextLayerNotify v = new ClimTowerRpcNextLayerNotify();
		v.CurLayer = m_CurLayer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcNextLayerNotify v)
	{
        if (v == null)
            return;
		m_CurLayer = v.CurLayer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcNextLayerNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcNextLayerNotify pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcNextLayerNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//当前层
	public int m_CurLayer;
	public int CurLayer
	{
		get { return m_CurLayer;}
		set { m_CurLayer = value; }
	}


};
//挑战结束通知封装类
[System.Serializable]
public class ClimTowerRpcChallengeEndNotifyWraper
{

	//构造函数
	public ClimTowerRpcChallengeEndNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcChallengeEndNotify ToPB()
	{
		ClimTowerRpcChallengeEndNotify v = new ClimTowerRpcChallengeEndNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcChallengeEndNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcChallengeEndNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcChallengeEndNotify pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcChallengeEndNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//每波怪物刷新通知通知封装类
[System.Serializable]
public class ClimTowerRpcWaveRefreshNotifyWraper
{

	//构造函数
	public ClimTowerRpcWaveRefreshNotifyWraper()
	{
		 m_AllWaves = -1;
		 m_CurWave = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AllWaves = -1;
		 m_CurWave = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerRpcWaveRefreshNotify ToPB()
	{
		ClimTowerRpcWaveRefreshNotify v = new ClimTowerRpcWaveRefreshNotify();
		v.AllWaves = m_AllWaves;
		v.CurWave = m_CurWave;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerRpcWaveRefreshNotify v)
	{
        if (v == null)
            return;
		m_AllWaves = v.AllWaves;
		m_CurWave = v.CurWave;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerRpcWaveRefreshNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerRpcWaveRefreshNotify pb = ProtoBuf.Serializer.Deserialize<ClimTowerRpcWaveRefreshNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//总共几波怪物
	public int m_AllWaves;
	public int AllWaves
	{
		get { return m_AllWaves;}
		set { m_AllWaves = value; }
	}
	//当前怪物波数
	public int m_CurWave;
	public int CurWave
	{
		get { return m_CurWave;}
		set { m_CurWave = value; }
	}


};
