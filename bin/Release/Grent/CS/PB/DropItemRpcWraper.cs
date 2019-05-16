
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBDropItem.cs
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


//掉落通知通知封装类
[System.Serializable]
public class DropItemRpcDropTtemsNotifyWraper
{

	//构造函数
	public DropItemRpcDropTtemsNotifyWraper()
	{
		m_Dropitems = new List<DropItemWraper>();
		 m_KillObjID = -1;
		 m_KillerObjID = -1;
		 m_OwnerObjID = -1;
		 m_Pos = new Vector3Wraper();
		 m_NetWorkType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Dropitems = new List<DropItemWraper>();
		 m_KillObjID = -1;
		 m_KillerObjID = -1;
		 m_OwnerObjID = -1;
		 m_Pos = new Vector3Wraper();
		 m_NetWorkType = -1;

	}

 	//转化成Protobuffer类型函数
	public DropItemRpcDropTtemsNotify ToPB()
	{
		DropItemRpcDropTtemsNotify v = new DropItemRpcDropTtemsNotify();
		for (int i=0; i<(int)m_Dropitems.Count; i++)
			v.Dropitems.Add( m_Dropitems[i].ToPB());
		v.KillObjID = m_KillObjID;
		v.KillerObjID = m_KillerObjID;
		v.OwnerObjID = m_OwnerObjID;
		v.Pos = m_Pos.ToPB();
		v.NetWorkType = m_NetWorkType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DropItemRpcDropTtemsNotify v)
	{
        if (v == null)
            return;
		m_Dropitems.Clear();
		for( int i=0; i<v.Dropitems.Count; i++)
			m_Dropitems.Add( new DropItemWraper());
		for( int i=0; i<v.Dropitems.Count; i++)
			m_Dropitems[i].FromPB(v.Dropitems[i]);
		m_KillObjID = v.KillObjID;
		m_KillerObjID = v.KillerObjID;
		m_OwnerObjID = v.OwnerObjID;
		m_Pos.FromPB(v.Pos);
		m_NetWorkType = v.NetWorkType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DropItemRpcDropTtemsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DropItemRpcDropTtemsNotify pb = ProtoBuf.Serializer.Deserialize<DropItemRpcDropTtemsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//掉落物品
	public List<DropItemWraper> m_Dropitems;
	public int SizeDropitems()
	{
		return m_Dropitems.Count;
	}
	public List<DropItemWraper> GetDropitems()
	{
		return m_Dropitems;
	}
	public DropItemWraper GetDropitems(int Index)
	{
		if(Index<0 || Index>=(int)m_Dropitems.Count)
			return new DropItemWraper();
		return m_Dropitems[Index];
	}
	public void SetDropitems( List<DropItemWraper> v )
	{
		m_Dropitems=v;
	}
	public void SetDropitems( int Index, DropItemWraper v )
	{
		if(Index<0 || Index>=(int)m_Dropitems.Count)
			return;
		m_Dropitems[Index] = v;
	}
	public void AddDropitems( DropItemWraper v )
	{
		m_Dropitems.Add(v);
	}
	public void ClearDropitems( )
	{
		m_Dropitems.Clear();
	}
	//死亡怪物ID
	public int m_KillObjID;
	public int KillObjID
	{
		get { return m_KillObjID;}
		set { m_KillObjID = value; }
	}
	//主角ID
	public int m_KillerObjID;
	public int KillerObjID
	{
		get { return m_KillerObjID;}
		set { m_KillerObjID = value; }
	}
	//所属ID
	public int m_OwnerObjID;
	public int OwnerObjID
	{
		get { return m_OwnerObjID;}
		set { m_OwnerObjID = value; }
	}
	//Pos
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//掉落广播类型
	public int m_NetWorkType;
	public int NetWorkType
	{
		get { return m_NetWorkType;}
		set { m_NetWorkType = value; }
	}


};
