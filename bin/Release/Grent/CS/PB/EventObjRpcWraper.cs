
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEventObj.cs
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


//EventBegin请求封装类
[System.Serializable]
public class EventObjRpcEventBeginAskWraper
{

	//构造函数
	public EventObjRpcEventBeginAskWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventBeginAsk ToPB()
	{
		EventObjRpcEventBeginAsk v = new EventObjRpcEventBeginAsk();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventBeginAsk v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventBeginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventBeginAsk pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventBeginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//EventBegin回应封装类
[System.Serializable]
public class EventObjRpcEventBeginReplyWraper
{

	//构造函数
	public EventObjRpcEventBeginReplyWraper()
	{
		 m_Result = -9999;
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventBeginReply ToPB()
	{
		EventObjRpcEventBeginReply v = new EventObjRpcEventBeginReply();
		v.Result = m_Result;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventBeginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventBeginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventBeginReply pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventBeginReply>(protoMS);
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
	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//EventEnd请求封装类
[System.Serializable]
public class EventObjRpcEventEndAskWraper
{

	//构造函数
	public EventObjRpcEventEndAskWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventEndAsk ToPB()
	{
		EventObjRpcEventEndAsk v = new EventObjRpcEventEndAsk();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventEndAsk v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventEndAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventEndAsk pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventEndAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//EventEnd回应封装类
[System.Serializable]
public class EventObjRpcEventEndReplyWraper
{

	//构造函数
	public EventObjRpcEventEndReplyWraper()
	{
		 m_Result = -9999;
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventEndReply ToPB()
	{
		EventObjRpcEventEndReply v = new EventObjRpcEventEndReply();
		v.Result = m_Result;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventEndReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventEndReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventEndReply pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventEndReply>(protoMS);
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
	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//EventStop请求封装类
[System.Serializable]
public class EventObjRpcEventStopAskWraper
{

	//构造函数
	public EventObjRpcEventStopAskWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventStopAsk ToPB()
	{
		EventObjRpcEventStopAsk v = new EventObjRpcEventStopAsk();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventStopAsk v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventStopAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventStopAsk pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventStopAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//EventStop回应封装类
[System.Serializable]
public class EventObjRpcEventStopReplyWraper
{

	//构造函数
	public EventObjRpcEventStopReplyWraper()
	{
		 m_Result = -1;
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventStopReply ToPB()
	{
		EventObjRpcEventStopReply v = new EventObjRpcEventStopReply();
		v.Result = m_Result;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventStopReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventStopReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventStopReply pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventStopReply>(protoMS);
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
	//id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//交互停止通知通知封装类
[System.Serializable]
public class EventObjRpcEventStopNotifyNotifyWraper
{

	//构造函数
	public EventObjRpcEventStopNotifyNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EventObjRpcEventStopNotifyNotify ToPB()
	{
		EventObjRpcEventStopNotifyNotify v = new EventObjRpcEventStopNotifyNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventObjRpcEventStopNotifyNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventObjRpcEventStopNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventObjRpcEventStopNotifyNotify pb = ProtoBuf.Serializer.Deserialize<EventObjRpcEventStopNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
