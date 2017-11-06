
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
//Boss死亡通知封装类
[System.Serializable]
public class EventRpcBossDiedNotifyWraper
{

	//构造函数
	public EventRpcBossDiedNotifyWraper()
	{
		 m_SceneId = -1;
		 m_ObjId = -1;
		 m_IsEndingBoss = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_ObjId = -1;
		 m_IsEndingBoss = false;

	}

 	//转化成Protobuffer类型函数
	public EventRpcBossDiedNotify ToPB()
	{
		EventRpcBossDiedNotify v = new EventRpcBossDiedNotify();
		v.SceneId = m_SceneId;
		v.ObjId = m_ObjId;
		v.IsEndingBoss = m_IsEndingBoss;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcBossDiedNotify v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_ObjId = v.ObjId;
		m_IsEndingBoss = v.IsEndingBoss;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcBossDiedNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcBossDiedNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcBossDiedNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//boss死亡的场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//Boss的ObjId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//是否是最终boss
	public bool m_IsEndingBoss;
	public bool IsEndingBoss
	{
		get { return m_IsEndingBoss;}
		set { m_IsEndingBoss = value; }
	}


};
