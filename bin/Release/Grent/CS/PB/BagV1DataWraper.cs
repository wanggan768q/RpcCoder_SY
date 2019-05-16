
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBBag.cs
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


//Item数据库存储结构封装类
[System.Serializable]
public class BagItemDBWraperV1
{

	//构造函数
	public BagItemDBWraperV1()
	{
		 m_Guid = -1;
		 m_Lock = false;
		 m_OverlayCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = -1;
		 m_Lock = false;
		 m_OverlayCount = -1;

	}

 	//转化成Protobuffer类型函数
	public BagItemDBV1 ToPB()
	{
		BagItemDBV1 v = new BagItemDBV1();
		v.Guid = m_Guid;
		v.Lock = m_Lock;
		v.OverlayCount = m_OverlayCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagItemDBV1 v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Lock = v.Lock;
		m_OverlayCount = v.OverlayCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagItemDBV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagItemDBV1 pb = ProtoBuf.Serializer.Deserialize<BagItemDBV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public int m_Guid;
	public int Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//Lock
	public bool m_Lock;
	public bool Lock
	{
		get { return m_Lock;}
		set { m_Lock = value; }
	}
	//OverlayCount
	public int m_OverlayCount;
	public int OverlayCount
	{
		get { return m_OverlayCount;}
		set { m_OverlayCount = value; }
	}


};
