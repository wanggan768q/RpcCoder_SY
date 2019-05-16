
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBActivity.cs
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


//精英怪信息通知封装类
[System.Serializable]
public class ActivityRpcEliteMonsterInfoNotifyWraper
{

	//构造函数
	public ActivityRpcEliteMonsterInfoNotifyWraper()
	{
		 m_State = -1;
		 m_Info = new EliteMonsterInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_State = -1;
		 m_Info = new EliteMonsterInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcEliteMonsterInfoNotify ToPB()
	{
		ActivityRpcEliteMonsterInfoNotify v = new ActivityRpcEliteMonsterInfoNotify();
		v.State = m_State;
		v.Info = m_Info.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcEliteMonsterInfoNotify v)
	{
        if (v == null)
            return;
		m_State = v.State;
		m_Info.FromPB(v.Info);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcEliteMonsterInfoNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcEliteMonsterInfoNotify pb = ProtoBuf.Serializer.Deserialize<ActivityRpcEliteMonsterInfoNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//信息
	public EliteMonsterInfoWraper m_Info;
	public EliteMonsterInfoWraper Info
	{
		get { return m_Info;}
		set { m_Info = value; }
	}


};
//生成对象请求封装类
[System.Serializable]
public class ActivityRpcCreateObjAskWraper
{

	//构造函数
	public ActivityRpcCreateObjAskWraper()
	{
		 m_CommonId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CommonId = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcCreateObjAsk ToPB()
	{
		ActivityRpcCreateObjAsk v = new ActivityRpcCreateObjAsk();
		v.CommonId = m_CommonId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcCreateObjAsk v)
	{
        if (v == null)
            return;
		m_CommonId = v.CommonId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcCreateObjAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcCreateObjAsk pb = ProtoBuf.Serializer.Deserialize<ActivityRpcCreateObjAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//当前id
	public int m_CommonId;
	public int CommonId
	{
		get { return m_CommonId;}
		set { m_CommonId = value; }
	}


};
//生成对象回应封装类
[System.Serializable]
public class ActivityRpcCreateObjReplyWraper
{

	//构造函数
	public ActivityRpcCreateObjReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcCreateObjReply ToPB()
	{
		ActivityRpcCreateObjReply v = new ActivityRpcCreateObjReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcCreateObjReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcCreateObjReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcCreateObjReply pb = ProtoBuf.Serializer.Deserialize<ActivityRpcCreateObjReply>(protoMS);
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
//活动开启前通知通知封装类
[System.Serializable]
public class ActivityRpcOpenActivityNotifyWraper
{

	//构造函数
	public ActivityRpcOpenActivityNotifyWraper()
	{
		 m_ActId = -1;
		 m_DiffTm = -1;
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ActId = -1;
		 m_DiffTm = -1;
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcOpenActivityNotify ToPB()
	{
		ActivityRpcOpenActivityNotify v = new ActivityRpcOpenActivityNotify();
		v.ActId = m_ActId;
		v.DiffTm = m_DiffTm;
		v.SceneId = m_SceneId;
		v.Pos = m_Pos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcOpenActivityNotify v)
	{
        if (v == null)
            return;
		m_ActId = v.ActId;
		m_DiffTm = v.DiffTm;
		m_SceneId = v.SceneId;
		m_Pos.FromPB(v.Pos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcOpenActivityNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcOpenActivityNotify pb = ProtoBuf.Serializer.Deserialize<ActivityRpcOpenActivityNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动id
	public int m_ActId;
	public int ActId
	{
		get { return m_ActId;}
		set { m_ActId = value; }
	}
	//活动开启前时间
	public int m_DiffTm;
	public int DiffTm
	{
		get { return m_DiffTm;}
		set { m_DiffTm = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//传送位置
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
//星耀王座进入请求封装类
[System.Serializable]
public class ActivityRpcXingyaoAskWraper
{

	//构造函数
	public ActivityRpcXingyaoAskWraper()
	{
		 m_NPCid = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NPCid = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcXingyaoAsk ToPB()
	{
		ActivityRpcXingyaoAsk v = new ActivityRpcXingyaoAsk();
		v.NPCid = m_NPCid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcXingyaoAsk v)
	{
        if (v == null)
            return;
		m_NPCid = v.NPCid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcXingyaoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcXingyaoAsk pb = ProtoBuf.Serializer.Deserialize<ActivityRpcXingyaoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//NPC
	public int m_NPCid;
	public int NPCid
	{
		get { return m_NPCid;}
		set { m_NPCid = value; }
	}


};
//星耀王座回应封装类
[System.Serializable]
public class ActivityRpcXingyaoReplyWraper
{

	//构造函数
	public ActivityRpcXingyaoReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcXingyaoReply ToPB()
	{
		ActivityRpcXingyaoReply v = new ActivityRpcXingyaoReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcXingyaoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcXingyaoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcXingyaoReply pb = ProtoBuf.Serializer.Deserialize<ActivityRpcXingyaoReply>(protoMS);
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
//活动时间信息通知封装类
[System.Serializable]
public class ActivityRpcActivityTimeNotifyWraper
{

	//构造函数
	public ActivityRpcActivityTimeNotifyWraper()
	{
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcActivityTimeNotify ToPB()
	{
		ActivityRpcActivityTimeNotify v = new ActivityRpcActivityTimeNotify();
		for (int i=0; i<(int)m_ActTimeList.Count; i++)
			v.ActTimeList.Add( m_ActTimeList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcActivityTimeNotify v)
	{
        if (v == null)
            return;
		m_ActTimeList.Clear();
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList.Add( new ActivityTimeWraper());
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList[i].FromPB(v.ActTimeList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcActivityTimeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcActivityTimeNotify pb = ProtoBuf.Serializer.Deserialize<ActivityRpcActivityTimeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动时间信息
	public List<ActivityTimeWraper> m_ActTimeList;
	public int SizeActTimeList()
	{
		return m_ActTimeList.Count;
	}
	public List<ActivityTimeWraper> GetActTimeList()
	{
		return m_ActTimeList;
	}
	public ActivityTimeWraper GetActTimeList(int Index)
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return new ActivityTimeWraper();
		return m_ActTimeList[Index];
	}
	public void SetActTimeList( List<ActivityTimeWraper> v )
	{
		m_ActTimeList=v;
	}
	public void SetActTimeList( int Index, ActivityTimeWraper v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return;
		m_ActTimeList[Index] = v;
	}
	public void AddActTimeList( ActivityTimeWraper v )
	{
		m_ActTimeList.Add(v);
	}
	public void ClearActTimeList( )
	{
		m_ActTimeList.Clear();
	}


};
//请求获取活动时间请求封装类
[System.Serializable]
public class ActivityRpcReqActivityTimeAskWraper
{

	//构造函数
	public ActivityRpcReqActivityTimeAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcReqActivityTimeAsk ToPB()
	{
		ActivityRpcReqActivityTimeAsk v = new ActivityRpcReqActivityTimeAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcReqActivityTimeAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcReqActivityTimeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcReqActivityTimeAsk pb = ProtoBuf.Serializer.Deserialize<ActivityRpcReqActivityTimeAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求获取活动时间回应封装类
[System.Serializable]
public class ActivityRpcReqActivityTimeReplyWraper
{

	//构造函数
	public ActivityRpcReqActivityTimeReplyWraper()
	{
		 m_Result = -1;
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcReqActivityTimeReply ToPB()
	{
		ActivityRpcReqActivityTimeReply v = new ActivityRpcReqActivityTimeReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ActTimeList.Count; i++)
			v.ActTimeList.Add( m_ActTimeList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcReqActivityTimeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ActTimeList.Clear();
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList.Add( new ActivityTimeWraper());
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList[i].FromPB(v.ActTimeList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcReqActivityTimeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcReqActivityTimeReply pb = ProtoBuf.Serializer.Deserialize<ActivityRpcReqActivityTimeReply>(protoMS);
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
	//活动时间信息
	public List<ActivityTimeWraper> m_ActTimeList;
	public int SizeActTimeList()
	{
		return m_ActTimeList.Count;
	}
	public List<ActivityTimeWraper> GetActTimeList()
	{
		return m_ActTimeList;
	}
	public ActivityTimeWraper GetActTimeList(int Index)
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return new ActivityTimeWraper();
		return m_ActTimeList[Index];
	}
	public void SetActTimeList( List<ActivityTimeWraper> v )
	{
		m_ActTimeList=v;
	}
	public void SetActTimeList( int Index, ActivityTimeWraper v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return;
		m_ActTimeList[Index] = v;
	}
	public void AddActTimeList( ActivityTimeWraper v )
	{
		m_ActTimeList.Add(v);
	}
	public void ClearActTimeList( )
	{
		m_ActTimeList.Clear();
	}


};
//星耀NPC请求封装类
[System.Serializable]
public class ActivityRpcXingyaoNPCAskWraper
{

	//构造函数
	public ActivityRpcXingyaoNPCAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcXingyaoNPCAsk ToPB()
	{
		ActivityRpcXingyaoNPCAsk v = new ActivityRpcXingyaoNPCAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcXingyaoNPCAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcXingyaoNPCAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcXingyaoNPCAsk pb = ProtoBuf.Serializer.Deserialize<ActivityRpcXingyaoNPCAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//星耀NPC回应封装类
[System.Serializable]
public class ActivityRpcXingyaoNPCReplyWraper
{

	//构造函数
	public ActivityRpcXingyaoNPCReplyWraper()
	{
		 m_Result = -1;
		 m_Sceneid = -1;
		 m_Waypoinid = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Sceneid = -1;
		 m_Waypoinid = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcXingyaoNPCReply ToPB()
	{
		ActivityRpcXingyaoNPCReply v = new ActivityRpcXingyaoNPCReply();
		v.Result = m_Result;
		v.Sceneid = m_Sceneid;
		v.Waypoinid = m_Waypoinid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcXingyaoNPCReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Sceneid = v.Sceneid;
		m_Waypoinid = v.Waypoinid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcXingyaoNPCReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcXingyaoNPCReply pb = ProtoBuf.Serializer.Deserialize<ActivityRpcXingyaoNPCReply>(protoMS);
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
	//场景ID
	public int m_Sceneid;
	public int Sceneid
	{
		get { return m_Sceneid;}
		set { m_Sceneid = value; }
	}
	//路点ID
	public int m_Waypoinid;
	public int Waypoinid
	{
		get { return m_Waypoinid;}
		set { m_Waypoinid = value; }
	}


};
//星耀高额奖励通知封装类
[System.Serializable]
public class ActivityRpcXingyaoRewardNotifyWraper
{

	//构造函数
	public ActivityRpcXingyaoRewardNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcXingyaoRewardNotify ToPB()
	{
		ActivityRpcXingyaoRewardNotify v = new ActivityRpcXingyaoRewardNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcXingyaoRewardNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcXingyaoRewardNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcXingyaoRewardNotify pb = ProtoBuf.Serializer.Deserialize<ActivityRpcXingyaoRewardNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//operation活动表时间通知封装类
[System.Serializable]
public class ActivityRpcOperationTimeNotifyWraper
{

	//构造函数
	public ActivityRpcOperationTimeNotifyWraper()
	{
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ActTimeList = new List<ActivityTimeWraper>();

	}

 	//转化成Protobuffer类型函数
	public ActivityRpcOperationTimeNotify ToPB()
	{
		ActivityRpcOperationTimeNotify v = new ActivityRpcOperationTimeNotify();
		for (int i=0; i<(int)m_ActTimeList.Count; i++)
			v.ActTimeList.Add( m_ActTimeList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityRpcOperationTimeNotify v)
	{
        if (v == null)
            return;
		m_ActTimeList.Clear();
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList.Add( new ActivityTimeWraper());
		for( int i=0; i<v.ActTimeList.Count; i++)
			m_ActTimeList[i].FromPB(v.ActTimeList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityRpcOperationTimeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityRpcOperationTimeNotify pb = ProtoBuf.Serializer.Deserialize<ActivityRpcOperationTimeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动时间信息
	public List<ActivityTimeWraper> m_ActTimeList;
	public int SizeActTimeList()
	{
		return m_ActTimeList.Count;
	}
	public List<ActivityTimeWraper> GetActTimeList()
	{
		return m_ActTimeList;
	}
	public ActivityTimeWraper GetActTimeList(int Index)
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return new ActivityTimeWraper();
		return m_ActTimeList[Index];
	}
	public void SetActTimeList( List<ActivityTimeWraper> v )
	{
		m_ActTimeList=v;
	}
	public void SetActTimeList( int Index, ActivityTimeWraper v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.Count)
			return;
		m_ActTimeList[Index] = v;
	}
	public void AddActTimeList( ActivityTimeWraper v )
	{
		m_ActTimeList.Add(v);
	}
	public void ClearActTimeList( )
	{
		m_ActTimeList.Clear();
	}


};
