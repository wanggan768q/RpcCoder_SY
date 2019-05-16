
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBItemOperation.cs
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


//道具分解界面初始化请求封装类
[System.Serializable]
public class ItemOperationRpcItemResolveSettingSyncAskWraper
{

	//构造函数
	public ItemOperationRpcItemResolveSettingSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemResolveSettingSyncAsk ToPB()
	{
		ItemOperationRpcItemResolveSettingSyncAsk v = new ItemOperationRpcItemResolveSettingSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemResolveSettingSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemResolveSettingSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemResolveSettingSyncAsk pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemResolveSettingSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//道具分解界面初始化回应封装类
[System.Serializable]
public class ItemOperationRpcItemResolveSettingSyncReplyWraper
{

	//构造函数
	public ItemOperationRpcItemResolveSettingSyncReplyWraper()
	{
		 m_Result = -9999;
		m_Setting = new List<ItemResolveDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Setting = new List<ItemResolveDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemResolveSettingSyncReply ToPB()
	{
		ItemOperationRpcItemResolveSettingSyncReply v = new ItemOperationRpcItemResolveSettingSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Setting.Count; i++)
			v.Setting.Add( m_Setting[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemResolveSettingSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Setting.Clear();
		for( int i=0; i<v.Setting.Count; i++)
			m_Setting.Add( new ItemResolveDataWraper());
		for( int i=0; i<v.Setting.Count; i++)
			m_Setting[i].FromPB(v.Setting[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemResolveSettingSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemResolveSettingSyncReply pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemResolveSettingSyncReply>(protoMS);
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
	//设置列表
	public List<ItemResolveDataWraper> m_Setting;
	public int SizeSetting()
	{
		return m_Setting.Count;
	}
	public List<ItemResolveDataWraper> GetSetting()
	{
		return m_Setting;
	}
	public ItemResolveDataWraper GetSetting(int Index)
	{
		if(Index<0 || Index>=(int)m_Setting.Count)
			return new ItemResolveDataWraper();
		return m_Setting[Index];
	}
	public void SetSetting( List<ItemResolveDataWraper> v )
	{
		m_Setting=v;
	}
	public void SetSetting( int Index, ItemResolveDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Setting.Count)
			return;
		m_Setting[Index] = v;
	}
	public void AddSetting( ItemResolveDataWraper v )
	{
		m_Setting.Add(v);
	}
	public void ClearSetting( )
	{
		m_Setting.Clear();
	}


};
//道具分解请求封装类
[System.Serializable]
public class ItemOperationRpcItemResolveAskWraper
{

	//构造函数
	public ItemOperationRpcItemResolveAskWraper()
	{
		 m_ItemPos = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemPos = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemResolveAsk ToPB()
	{
		ItemOperationRpcItemResolveAsk v = new ItemOperationRpcItemResolveAsk();
		v.ItemPos = m_ItemPos;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemResolveAsk v)
	{
        if (v == null)
            return;
		m_ItemPos = v.ItemPos;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemResolveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemResolveAsk pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemResolveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具的位置
	public int m_ItemPos;
	public int ItemPos
	{
		get { return m_ItemPos;}
		set { m_ItemPos = value; }
	}
	//分解道具数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//道具分解回应封装类
[System.Serializable]
public class ItemOperationRpcItemResolveReplyWraper
{

	//构造函数
	public ItemOperationRpcItemResolveReplyWraper()
	{
		 m_Result = -9999;
		 m_ItemID = -1;
		m_ItemSimpleDataList = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ItemID = -1;
		m_ItemSimpleDataList = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemResolveReply ToPB()
	{
		ItemOperationRpcItemResolveReply v = new ItemOperationRpcItemResolveReply();
		v.Result = m_Result;
		v.ItemID = m_ItemID;
		for (int i=0; i<(int)m_ItemSimpleDataList.Count; i++)
			v.ItemSimpleDataList.Add( m_ItemSimpleDataList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemResolveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemID = v.ItemID;
		m_ItemSimpleDataList.Clear();
		for( int i=0; i<v.ItemSimpleDataList.Count; i++)
			m_ItemSimpleDataList.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.ItemSimpleDataList.Count; i++)
			m_ItemSimpleDataList[i].FromPB(v.ItemSimpleDataList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemResolveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemResolveReply pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemResolveReply>(protoMS);
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
	//道具唯一ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//道具简易数据列表
	public List<ItemSimpleDataWraper> m_ItemSimpleDataList;
	public int SizeItemSimpleDataList()
	{
		return m_ItemSimpleDataList.Count;
	}
	public List<ItemSimpleDataWraper> GetItemSimpleDataList()
	{
		return m_ItemSimpleDataList;
	}
	public ItemSimpleDataWraper GetItemSimpleDataList(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemSimpleDataList.Count)
			return new ItemSimpleDataWraper();
		return m_ItemSimpleDataList[Index];
	}
	public void SetItemSimpleDataList( List<ItemSimpleDataWraper> v )
	{
		m_ItemSimpleDataList=v;
	}
	public void SetItemSimpleDataList( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemSimpleDataList.Count)
			return;
		m_ItemSimpleDataList[Index] = v;
	}
	public void AddItemSimpleDataList( ItemSimpleDataWraper v )
	{
		m_ItemSimpleDataList.Add(v);
	}
	public void ClearItemSimpleDataList( )
	{
		m_ItemSimpleDataList.Clear();
	}


};
//更改设置请求封装类
[System.Serializable]
public class ItemOperationRpcChangeSettingAskWraper
{

	//构造函数
	public ItemOperationRpcChangeSettingAskWraper()
	{
		m_SettingList = new List<ItemResolveDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SettingList = new List<ItemResolveDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcChangeSettingAsk ToPB()
	{
		ItemOperationRpcChangeSettingAsk v = new ItemOperationRpcChangeSettingAsk();
		for (int i=0; i<(int)m_SettingList.Count; i++)
			v.SettingList.Add( m_SettingList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcChangeSettingAsk v)
	{
        if (v == null)
            return;
		m_SettingList.Clear();
		for( int i=0; i<v.SettingList.Count; i++)
			m_SettingList.Add( new ItemResolveDataWraper());
		for( int i=0; i<v.SettingList.Count; i++)
			m_SettingList[i].FromPB(v.SettingList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcChangeSettingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcChangeSettingAsk pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcChangeSettingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//设置列表
	public List<ItemResolveDataWraper> m_SettingList;
	public int SizeSettingList()
	{
		return m_SettingList.Count;
	}
	public List<ItemResolveDataWraper> GetSettingList()
	{
		return m_SettingList;
	}
	public ItemResolveDataWraper GetSettingList(int Index)
	{
		if(Index<0 || Index>=(int)m_SettingList.Count)
			return new ItemResolveDataWraper();
		return m_SettingList[Index];
	}
	public void SetSettingList( List<ItemResolveDataWraper> v )
	{
		m_SettingList=v;
	}
	public void SetSettingList( int Index, ItemResolveDataWraper v )
	{
		if(Index<0 || Index>=(int)m_SettingList.Count)
			return;
		m_SettingList[Index] = v;
	}
	public void AddSettingList( ItemResolveDataWraper v )
	{
		m_SettingList.Add(v);
	}
	public void ClearSettingList( )
	{
		m_SettingList.Clear();
	}


};
//更改设置回应封装类
[System.Serializable]
public class ItemOperationRpcChangeSettingReplyWraper
{

	//构造函数
	public ItemOperationRpcChangeSettingReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcChangeSettingReply ToPB()
	{
		ItemOperationRpcChangeSettingReply v = new ItemOperationRpcChangeSettingReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcChangeSettingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcChangeSettingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcChangeSettingReply pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcChangeSettingReply>(protoMS);
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
//一键分解请求封装类
[System.Serializable]
public class ItemOperationRpcBatchResolveAskWraper
{

	//构造函数
	public ItemOperationRpcBatchResolveAskWraper()
	{
		 m_Qulity = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Qulity = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcBatchResolveAsk ToPB()
	{
		ItemOperationRpcBatchResolveAsk v = new ItemOperationRpcBatchResolveAsk();
		v.Qulity = m_Qulity;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcBatchResolveAsk v)
	{
        if (v == null)
            return;
		m_Qulity = v.Qulity;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcBatchResolveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcBatchResolveAsk pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcBatchResolveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//一键分解的品质类别
	public int m_Qulity;
	public int Qulity
	{
		get { return m_Qulity;}
		set { m_Qulity = value; }
	}


};
//一键分解回应封装类
[System.Serializable]
public class ItemOperationRpcBatchResolveReplyWraper
{

	//构造函数
	public ItemOperationRpcBatchResolveReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcBatchResolveReply ToPB()
	{
		ItemOperationRpcBatchResolveReply v = new ItemOperationRpcBatchResolveReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcBatchResolveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcBatchResolveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcBatchResolveReply pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcBatchResolveReply>(protoMS);
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
//道具合成请求封装类
[System.Serializable]
public class ItemOperationRpcItemCompoundAskWraper
{

	//构造函数
	public ItemOperationRpcItemCompoundAskWraper()
	{
		 m_ItemConfID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemConfID = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemCompoundAsk ToPB()
	{
		ItemOperationRpcItemCompoundAsk v = new ItemOperationRpcItemCompoundAsk();
		v.ItemConfID = m_ItemConfID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemCompoundAsk v)
	{
        if (v == null)
            return;
		m_ItemConfID = v.ItemConfID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemCompoundAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemCompoundAsk pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemCompoundAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//合成道具的confID
	public int m_ItemConfID;
	public int ItemConfID
	{
		get { return m_ItemConfID;}
		set { m_ItemConfID = value; }
	}


};
//道具合成回应封装类
[System.Serializable]
public class ItemOperationRpcItemCompoundReplyWraper
{

	//构造函数
	public ItemOperationRpcItemCompoundReplyWraper()
	{
		 m_Result = -9999;
		 m_ItemConfID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ItemConfID = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemOperationRpcItemCompoundReply ToPB()
	{
		ItemOperationRpcItemCompoundReply v = new ItemOperationRpcItemCompoundReply();
		v.Result = m_Result;
		v.ItemConfID = m_ItemConfID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemOperationRpcItemCompoundReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemConfID = v.ItemConfID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemOperationRpcItemCompoundReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemOperationRpcItemCompoundReply pb = ProtoBuf.Serializer.Deserialize<ItemOperationRpcItemCompoundReply>(protoMS);
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
	//合成道具的confID
	public int m_ItemConfID;
	public int ItemConfID
	{
		get { return m_ItemConfID;}
		set { m_ItemConfID = value; }
	}


};
