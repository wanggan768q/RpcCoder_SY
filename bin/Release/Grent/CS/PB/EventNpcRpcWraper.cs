
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEventNpc.cs
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


//开始交互请求封装类
[System.Serializable]
public class EventNpcRpcBeginEventAskWraper
{

	//构造函数
	public EventNpcRpcBeginEventAskWraper()
	{
		 m_EventIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EventIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public EventNpcRpcBeginEventAsk ToPB()
	{
		EventNpcRpcBeginEventAsk v = new EventNpcRpcBeginEventAsk();
		v.EventIndex = m_EventIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventNpcRpcBeginEventAsk v)
	{
        if (v == null)
            return;
		m_EventIndex = v.EventIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventNpcRpcBeginEventAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventNpcRpcBeginEventAsk pb = ProtoBuf.Serializer.Deserialize<EventNpcRpcBeginEventAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//索引
	public int m_EventIndex;
	public int EventIndex
	{
		get { return m_EventIndex;}
		set { m_EventIndex = value; }
	}


};
//开始交互回应封装类
[System.Serializable]
public class EventNpcRpcBeginEventReplyWraper
{

	//构造函数
	public EventNpcRpcBeginEventReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public EventNpcRpcBeginEventReply ToPB()
	{
		EventNpcRpcBeginEventReply v = new EventNpcRpcBeginEventReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventNpcRpcBeginEventReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventNpcRpcBeginEventReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventNpcRpcBeginEventReply pb = ProtoBuf.Serializer.Deserialize<EventNpcRpcBeginEventReply>(protoMS);
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
//交互结束请求封装类
[System.Serializable]
public class EventNpcRpcEndEventAskWraper
{

	//构造函数
	public EventNpcRpcEndEventAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EventNpcRpcEndEventAsk ToPB()
	{
		EventNpcRpcEndEventAsk v = new EventNpcRpcEndEventAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventNpcRpcEndEventAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventNpcRpcEndEventAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventNpcRpcEndEventAsk pb = ProtoBuf.Serializer.Deserialize<EventNpcRpcEndEventAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//交互结束回应封装类
[System.Serializable]
public class EventNpcRpcEndEventReplyWraper
{

	//构造函数
	public EventNpcRpcEndEventReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public EventNpcRpcEndEventReply ToPB()
	{
		EventNpcRpcEndEventReply v = new EventNpcRpcEndEventReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventNpcRpcEndEventReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventNpcRpcEndEventReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventNpcRpcEndEventReply pb = ProtoBuf.Serializer.Deserialize<EventNpcRpcEndEventReply>(protoMS);
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
//活动开始通知封装类
[System.Serializable]
public class EventNpcRpcActivityBeginNotifyWraper
{

	//构造函数
	public EventNpcRpcActivityBeginNotifyWraper()
	{
		 m_StartTime = -1;
		 m_WayPoint = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_StartTime = -1;
		 m_WayPoint = -1;

	}

 	//转化成Protobuffer类型函数
	public EventNpcRpcActivityBeginNotify ToPB()
	{
		EventNpcRpcActivityBeginNotify v = new EventNpcRpcActivityBeginNotify();
		v.StartTime = m_StartTime;
		v.WayPoint = m_WayPoint;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventNpcRpcActivityBeginNotify v)
	{
        if (v == null)
            return;
		m_StartTime = v.StartTime;
		m_WayPoint = v.WayPoint;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventNpcRpcActivityBeginNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventNpcRpcActivityBeginNotify pb = ProtoBuf.Serializer.Deserialize<EventNpcRpcActivityBeginNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//开始时间
	public int m_StartTime;
	public int StartTime
	{
		get { return m_StartTime;}
		set { m_StartTime = value; }
	}
	//路点ID
	public int m_WayPoint;
	public int WayPoint
	{
		get { return m_WayPoint;}
		set { m_WayPoint = value; }
	}


};
