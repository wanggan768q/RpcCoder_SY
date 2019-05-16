
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEquipSlot.cs
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


//同步装备槽相关请求封装类
[System.Serializable]
public class EquipSlotRpcSyncEquipSlotAskWraper
{

	//构造函数
	public EquipSlotRpcSyncEquipSlotAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcSyncEquipSlotAsk ToPB()
	{
		EquipSlotRpcSyncEquipSlotAsk v = new EquipSlotRpcSyncEquipSlotAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcSyncEquipSlotAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcSyncEquipSlotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcSyncEquipSlotAsk pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcSyncEquipSlotAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步装备槽相关回应封装类
[System.Serializable]
public class EquipSlotRpcSyncEquipSlotReplyWraper
{

	//构造函数
	public EquipSlotRpcSyncEquipSlotReplyWraper()
	{
		 m_Result = -1;
		m_EquipSlotData = new List<EquipSlotInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_EquipSlotData = new List<EquipSlotInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcSyncEquipSlotReply ToPB()
	{
		EquipSlotRpcSyncEquipSlotReply v = new EquipSlotRpcSyncEquipSlotReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_EquipSlotData.Count; i++)
			v.EquipSlotData.Add( m_EquipSlotData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcSyncEquipSlotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipSlotData.Clear();
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData.Add( new EquipSlotInfoWraper());
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData[i].FromPB(v.EquipSlotData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcSyncEquipSlotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcSyncEquipSlotReply pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcSyncEquipSlotReply>(protoMS);
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
	//装备槽信息
	public List<EquipSlotInfoWraper> m_EquipSlotData;
	public int SizeEquipSlotData()
	{
		return m_EquipSlotData.Count;
	}
	public List<EquipSlotInfoWraper> GetEquipSlotData()
	{
		return m_EquipSlotData;
	}
	public EquipSlotInfoWraper GetEquipSlotData(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return new EquipSlotInfoWraper();
		return m_EquipSlotData[Index];
	}
	public void SetEquipSlotData( List<EquipSlotInfoWraper> v )
	{
		m_EquipSlotData=v;
	}
	public void SetEquipSlotData( int Index, EquipSlotInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return;
		m_EquipSlotData[Index] = v;
	}
	public void AddEquipSlotData( EquipSlotInfoWraper v )
	{
		m_EquipSlotData.Add(v);
	}
	public void ClearEquipSlotData( )
	{
		m_EquipSlotData.Clear();
	}


};
//装备槽强化请求封装类
[System.Serializable]
public class EquipSlotRpcEnhanceEquipSlotAskWraper
{

	//构造函数
	public EquipSlotRpcEnhanceEquipSlotAskWraper()
	{
		 m_Slot_Type = -1;
		m_CostItemList = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Slot_Type = -1;
		m_CostItemList = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcEnhanceEquipSlotAsk ToPB()
	{
		EquipSlotRpcEnhanceEquipSlotAsk v = new EquipSlotRpcEnhanceEquipSlotAsk();
		v.Slot_Type = m_Slot_Type;
		for (int i=0; i<(int)m_CostItemList.Count; i++)
			v.CostItemList.Add( m_CostItemList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcEnhanceEquipSlotAsk v)
	{
        if (v == null)
            return;
		m_Slot_Type = v.Slot_Type;
		m_CostItemList.Clear();
		for( int i=0; i<v.CostItemList.Count; i++)
			m_CostItemList.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.CostItemList.Count; i++)
			m_CostItemList[i].FromPB(v.CostItemList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcEnhanceEquipSlotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcEnhanceEquipSlotAsk pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcEnhanceEquipSlotAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}
	//消耗物品列表
	public List<ItemSimpleDataWraper> m_CostItemList;
	public int SizeCostItemList()
	{
		return m_CostItemList.Count;
	}
	public List<ItemSimpleDataWraper> GetCostItemList()
	{
		return m_CostItemList;
	}
	public ItemSimpleDataWraper GetCostItemList(int Index)
	{
		if(Index<0 || Index>=(int)m_CostItemList.Count)
			return new ItemSimpleDataWraper();
		return m_CostItemList[Index];
	}
	public void SetCostItemList( List<ItemSimpleDataWraper> v )
	{
		m_CostItemList=v;
	}
	public void SetCostItemList( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_CostItemList.Count)
			return;
		m_CostItemList[Index] = v;
	}
	public void AddCostItemList( ItemSimpleDataWraper v )
	{
		m_CostItemList.Add(v);
	}
	public void ClearCostItemList( )
	{
		m_CostItemList.Clear();
	}


};
//装备槽强化回应封装类
[System.Serializable]
public class EquipSlotRpcEnhanceEquipSlotReplyWraper
{

	//构造函数
	public EquipSlotRpcEnhanceEquipSlotReplyWraper()
	{
		 m_Result = -1;
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		 m_Slot_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		 m_Slot_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcEnhanceEquipSlotReply ToPB()
	{
		EquipSlotRpcEnhanceEquipSlotReply v = new EquipSlotRpcEnhanceEquipSlotReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_EquipSlotData.Count; i++)
			v.EquipSlotData.Add( m_EquipSlotData[i].ToPB());
		v.Slot_Type = m_Slot_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcEnhanceEquipSlotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipSlotData.Clear();
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData.Add( new EquipSlotInfoWraper());
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData[i].FromPB(v.EquipSlotData[i]);
		m_Slot_Type = v.Slot_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcEnhanceEquipSlotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcEnhanceEquipSlotReply pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcEnhanceEquipSlotReply>(protoMS);
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
	//装备槽信息
	public List<EquipSlotInfoWraper> m_EquipSlotData;
	public int SizeEquipSlotData()
	{
		return m_EquipSlotData.Count;
	}
	public List<EquipSlotInfoWraper> GetEquipSlotData()
	{
		return m_EquipSlotData;
	}
	public EquipSlotInfoWraper GetEquipSlotData(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return new EquipSlotInfoWraper();
		return m_EquipSlotData[Index];
	}
	public void SetEquipSlotData( List<EquipSlotInfoWraper> v )
	{
		m_EquipSlotData=v;
	}
	public void SetEquipSlotData( int Index, EquipSlotInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return;
		m_EquipSlotData[Index] = v;
	}
	public void AddEquipSlotData( EquipSlotInfoWraper v )
	{
		m_EquipSlotData.Add(v);
	}
	public void ClearEquipSlotData( )
	{
		m_EquipSlotData.Clear();
	}
	//槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}


};
//装备槽升星请求封装类
[System.Serializable]
public class EquipSlotRpcUpStarEquipSlotAskWraper
{

	//构造函数
	public EquipSlotRpcUpStarEquipSlotAskWraper()
	{
		 m_Slot_Type = -1;
		 m_IsProtection = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Slot_Type = -1;
		 m_IsProtection = false;

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcUpStarEquipSlotAsk ToPB()
	{
		EquipSlotRpcUpStarEquipSlotAsk v = new EquipSlotRpcUpStarEquipSlotAsk();
		v.Slot_Type = m_Slot_Type;
		v.IsProtection = m_IsProtection;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcUpStarEquipSlotAsk v)
	{
        if (v == null)
            return;
		m_Slot_Type = v.Slot_Type;
		m_IsProtection = v.IsProtection;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcUpStarEquipSlotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcUpStarEquipSlotAsk pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcUpStarEquipSlotAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}
	//是否保底
	public bool m_IsProtection;
	public bool IsProtection
	{
		get { return m_IsProtection;}
		set { m_IsProtection = value; }
	}


};
//装备槽升星回应封装类
[System.Serializable]
public class EquipSlotRpcUpStarEquipSlotReplyWraper
{

	//构造函数
	public EquipSlotRpcUpStarEquipSlotReplyWraper()
	{
		 m_Result = -1;
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		 m_Slot_Type = -1;
		 m_UpStarResult = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		 m_Slot_Type = -1;
		 m_UpStarResult = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcUpStarEquipSlotReply ToPB()
	{
		EquipSlotRpcUpStarEquipSlotReply v = new EquipSlotRpcUpStarEquipSlotReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_EquipSlotStarList.Count; i++)
			v.EquipSlotStarList.Add( m_EquipSlotStarList[i].ToPB());
		v.Slot_Type = m_Slot_Type;
		v.UpStarResult = m_UpStarResult;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcUpStarEquipSlotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipSlotStarList.Clear();
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList.Add( new EquipSlotStarInfoWraper());
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList[i].FromPB(v.EquipSlotStarList[i]);
		m_Slot_Type = v.Slot_Type;
		m_UpStarResult = v.UpStarResult;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcUpStarEquipSlotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcUpStarEquipSlotReply pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcUpStarEquipSlotReply>(protoMS);
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
	//装备槽星级列表
	public List<EquipSlotStarInfoWraper> m_EquipSlotStarList;
	public int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.Count;
	}
	public List<EquipSlotStarInfoWraper> GetEquipSlotStarList()
	{
		return m_EquipSlotStarList;
	}
	public EquipSlotStarInfoWraper GetEquipSlotStarList(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return new EquipSlotStarInfoWraper();
		return m_EquipSlotStarList[Index];
	}
	public void SetEquipSlotStarList( List<EquipSlotStarInfoWraper> v )
	{
		m_EquipSlotStarList=v;
	}
	public void SetEquipSlotStarList( int Index, EquipSlotStarInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return;
		m_EquipSlotStarList[Index] = v;
	}
	public void AddEquipSlotStarList( EquipSlotStarInfoWraper v )
	{
		m_EquipSlotStarList.Add(v);
	}
	public void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.Clear();
	}
	//槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}
	//升星结果
	public int m_UpStarResult;
	public int UpStarResult
	{
		get { return m_UpStarResult;}
		set { m_UpStarResult = value; }
	}


};
//同步装备槽星请求封装类
[System.Serializable]
public class EquipSlotRpcSyncEquipSlotStarAskWraper
{

	//构造函数
	public EquipSlotRpcSyncEquipSlotStarAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcSyncEquipSlotStarAsk ToPB()
	{
		EquipSlotRpcSyncEquipSlotStarAsk v = new EquipSlotRpcSyncEquipSlotStarAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcSyncEquipSlotStarAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcSyncEquipSlotStarAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcSyncEquipSlotStarAsk pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcSyncEquipSlotStarAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步装备槽星回应封装类
[System.Serializable]
public class EquipSlotRpcSyncEquipSlotStarReplyWraper
{

	//构造函数
	public EquipSlotRpcSyncEquipSlotStarReplyWraper()
	{
		 m_Result = -1;
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipSlotRpcSyncEquipSlotStarReply ToPB()
	{
		EquipSlotRpcSyncEquipSlotStarReply v = new EquipSlotRpcSyncEquipSlotStarReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_EquipSlotStarList.Count; i++)
			v.EquipSlotStarList.Add( m_EquipSlotStarList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotRpcSyncEquipSlotStarReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipSlotStarList.Clear();
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList.Add( new EquipSlotStarInfoWraper());
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList[i].FromPB(v.EquipSlotStarList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotRpcSyncEquipSlotStarReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotRpcSyncEquipSlotStarReply pb = ProtoBuf.Serializer.Deserialize<EquipSlotRpcSyncEquipSlotStarReply>(protoMS);
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
	//装备槽星级列表
	public List<EquipSlotStarInfoWraper> m_EquipSlotStarList;
	public int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.Count;
	}
	public List<EquipSlotStarInfoWraper> GetEquipSlotStarList()
	{
		return m_EquipSlotStarList;
	}
	public EquipSlotStarInfoWraper GetEquipSlotStarList(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return new EquipSlotStarInfoWraper();
		return m_EquipSlotStarList[Index];
	}
	public void SetEquipSlotStarList( List<EquipSlotStarInfoWraper> v )
	{
		m_EquipSlotStarList=v;
	}
	public void SetEquipSlotStarList( int Index, EquipSlotStarInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return;
		m_EquipSlotStarList[Index] = v;
	}
	public void AddEquipSlotStarList( EquipSlotStarInfoWraper v )
	{
		m_EquipSlotStarList.Add(v);
	}
	public void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.Clear();
	}


};
