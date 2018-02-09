
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEvent.cs
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


//ObjMove通知封装类
[System.Serializable]
public class EventRpcMoveNotifyWraper
{

	//构造函数
	public EventRpcMoveNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcMoveNotify ToPB()
	{
		EventRpcMoveNotify v = new EventRpcMoveNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcMoveNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcMoveNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcMoveNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcMoveNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//ObjStopMove通知封装类
[System.Serializable]
public class EventRpcStopMoveNotifyWraper
{

	//构造函数
	public EventRpcStopMoveNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcStopMoveNotify ToPB()
	{
		EventRpcStopMoveNotify v = new EventRpcStopMoveNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcStopMoveNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcStopMoveNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcStopMoveNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcStopMoveNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//属性改变通知封装类
[System.Serializable]
public class EventRpcObjAttrChangeNotifyWraper
{

	//构造函数
	public EventRpcObjAttrChangeNotifyWraper()
	{
		 m_Speed = (float)-1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_ConfigId = -1;
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Speed = (float)-1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_ConfigId = -1;
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcObjAttrChangeNotify ToPB()
	{
		EventRpcObjAttrChangeNotify v = new EventRpcObjAttrChangeNotify();
		v.Speed = m_Speed;
		v.Hp = m_Hp;
		v.Status = m_Status;
		v.ConfigId = m_ConfigId;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcObjAttrChangeNotify v)
	{
        if (v == null)
            return;
		m_Speed = v.Speed;
		m_Hp = v.Hp;
		m_Status = v.Status;
		m_ConfigId = v.ConfigId;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcObjAttrChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcObjAttrChangeNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcObjAttrChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//speed
	public float m_Speed;
	public float Speed
	{
		get { return m_Speed;}
		set { m_Speed = value; }
	}
	//Hp
	public Int64 m_Hp;
	public Int64 Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//NpcId改变
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//对象id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
