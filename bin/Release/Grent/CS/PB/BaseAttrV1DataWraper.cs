
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBBaseAttr.cs
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


//ObjData封装类
[System.Serializable]
public class BaseAttrObjDataWraperV1
{

	//构造函数
	public BaseAttrObjDataWraperV1()
	{
		 m_ObjType = -1;
		 m_ConfigId = -1;
		 m_State = -1;
		 m_OwnerObjId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjType = -1;
		 m_ConfigId = -1;
		 m_State = -1;
		 m_OwnerObjId = -1;

	}

 	//转化成Protobuffer类型函数
	public BaseAttrObjDataV1 ToPB()
	{
		BaseAttrObjDataV1 v = new BaseAttrObjDataV1();
		v.ObjType = m_ObjType;
		v.ConfigId = m_ConfigId;
		v.State = m_State;
		v.OwnerObjId = m_OwnerObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrObjDataV1 v)
	{
        if (v == null)
            return;
		m_ObjType = v.ObjType;
		m_ConfigId = v.ConfigId;
		m_State = v.State;
		m_OwnerObjId = v.OwnerObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrObjDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrObjDataV1 pb = ProtoBuf.Serializer.Deserialize<BaseAttrObjDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_ObjType;
	public int ObjType
	{
		get { return m_ObjType;}
		set { m_ObjType = value; }
	}
	//config id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//obj状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//拥有者
	public int m_OwnerObjId;
	public int OwnerObjId
	{
		get { return m_OwnerObjId;}
		set { m_OwnerObjId = value; }
	}


};
