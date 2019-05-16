
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBSmallMap.cs
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


//新的对象创建通知封装类
[System.Serializable]
public class SmallMapRpcNewObjNotifyWraper
{

	//构造函数
	public SmallMapRpcNewObjNotifyWraper()
	{
		 m_ObjId = -1;
		 m_DataId = -1;
		 m_WorldPos = new Vector3Wraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_DataId = -1;
		 m_WorldPos = new Vector3Wraper();

	}

 	//转化成Protobuffer类型函数
	public SmallMapRpcNewObjNotify ToPB()
	{
		SmallMapRpcNewObjNotify v = new SmallMapRpcNewObjNotify();
		v.ObjId = m_ObjId;
		v.DataId = m_DataId;
		v.WorldPos = m_WorldPos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SmallMapRpcNewObjNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_DataId = v.DataId;
		m_WorldPos.FromPB(v.WorldPos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SmallMapRpcNewObjNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SmallMapRpcNewObjNotify pb = ProtoBuf.Serializer.Deserialize<SmallMapRpcNewObjNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//objID
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//DataId
	public int m_DataId;
	public int DataId
	{
		get { return m_DataId;}
		set { m_DataId = value; }
	}
	//位置信息
	public Vector3Wraper m_WorldPos;
	public Vector3Wraper WorldPos
	{
		get { return m_WorldPos;}
		set { m_WorldPos = value; }
	}


};
//删除obj通知封装类
[System.Serializable]
public class SmallMapRpcDelObjNotifyWraper
{

	//构造函数
	public SmallMapRpcDelObjNotifyWraper()
	{
		 m_ObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public SmallMapRpcDelObjNotify ToPB()
	{
		SmallMapRpcDelObjNotify v = new SmallMapRpcDelObjNotify();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SmallMapRpcDelObjNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SmallMapRpcDelObjNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SmallMapRpcDelObjNotify pb = ProtoBuf.Serializer.Deserialize<SmallMapRpcDelObjNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//objId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
