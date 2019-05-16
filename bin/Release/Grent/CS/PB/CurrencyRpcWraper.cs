
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBCurrency.cs
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


//货币兑换请求封装类
[System.Serializable]
public class CurrencyRpcTransfromAskWraper
{

	//构造函数
	public CurrencyRpcTransfromAskWraper()
	{
		 m_To_type = -1;
		 m_From_type = -1;
		 m_From_num = 0;
		 m_Diamond_bind_num = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_To_type = -1;
		 m_From_type = -1;
		 m_From_num = 0;
		 m_Diamond_bind_num = 0;

	}

 	//转化成Protobuffer类型函数
	public CurrencyRpcTransfromAsk ToPB()
	{
		CurrencyRpcTransfromAsk v = new CurrencyRpcTransfromAsk();
		v.To_type = m_To_type;
		v.From_type = m_From_type;
		v.From_num = m_From_num;
		v.Diamond_bind_num = m_Diamond_bind_num;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CurrencyRpcTransfromAsk v)
	{
        if (v == null)
            return;
		m_To_type = v.To_type;
		m_From_type = v.From_type;
		m_From_num = v.From_num;
		m_Diamond_bind_num = v.Diamond_bind_num;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CurrencyRpcTransfromAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CurrencyRpcTransfromAsk pb = ProtoBuf.Serializer.Deserialize<CurrencyRpcTransfromAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//兑换目标类型
	public int m_To_type;
	public int To_type
	{
		get { return m_To_type;}
		set { m_To_type = value; }
	}
	//兑换来源类型
	public int m_From_type;
	public int From_type
	{
		get { return m_From_type;}
		set { m_From_type = value; }
	}
	//兑换来源数量
	public Int64 m_From_num;
	public Int64 From_num
	{
		get { return m_From_num;}
		set { m_From_num = value; }
	}
	//绑定钻石使用数量
	public Int64 m_Diamond_bind_num;
	public Int64 Diamond_bind_num
	{
		get { return m_Diamond_bind_num;}
		set { m_Diamond_bind_num = value; }
	}


};
//货币兑换回应封装类
[System.Serializable]
public class CurrencyRpcTransfromReplyWraper
{

	//构造函数
	public CurrencyRpcTransfromReplyWraper()
	{
		 m_Result = -9999;
		 m_Reward_type = -1;
		 m_Reward_num = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Reward_type = -1;
		 m_Reward_num = 0;

	}

 	//转化成Protobuffer类型函数
	public CurrencyRpcTransfromReply ToPB()
	{
		CurrencyRpcTransfromReply v = new CurrencyRpcTransfromReply();
		v.Result = m_Result;
		v.Reward_type = m_Reward_type;
		v.Reward_num = m_Reward_num;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CurrencyRpcTransfromReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Reward_type = v.Reward_type;
		m_Reward_num = v.Reward_num;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CurrencyRpcTransfromReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CurrencyRpcTransfromReply pb = ProtoBuf.Serializer.Deserialize<CurrencyRpcTransfromReply>(protoMS);
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
	//获得货币类型
	public int m_Reward_type;
	public int Reward_type
	{
		get { return m_Reward_type;}
		set { m_Reward_type = value; }
	}
	//获得货币数量
	public Int64 m_Reward_num;
	public Int64 Reward_num
	{
		get { return m_Reward_num;}
		set { m_Reward_num = value; }
	}


};
//货币展示请求封装类
[System.Serializable]
public class CurrencyRpcShowAskWraper
{

	//构造函数
	public CurrencyRpcShowAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public CurrencyRpcShowAsk ToPB()
	{
		CurrencyRpcShowAsk v = new CurrencyRpcShowAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CurrencyRpcShowAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CurrencyRpcShowAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CurrencyRpcShowAsk pb = ProtoBuf.Serializer.Deserialize<CurrencyRpcShowAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//货币展示回应封装类
[System.Serializable]
public class CurrencyRpcShowReplyWraper
{

	//构造函数
	public CurrencyRpcShowReplyWraper()
	{
		 m_Result = -1;
		m_ShowResources = new List<ResourceWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ShowResources = new List<ResourceWraper>();

	}

 	//转化成Protobuffer类型函数
	public CurrencyRpcShowReply ToPB()
	{
		CurrencyRpcShowReply v = new CurrencyRpcShowReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ShowResources.Count; i++)
			v.ShowResources.Add( m_ShowResources[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CurrencyRpcShowReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ShowResources.Clear();
		for( int i=0; i<v.ShowResources.Count; i++)
			m_ShowResources.Add( new ResourceWraper());
		for( int i=0; i<v.ShowResources.Count; i++)
			m_ShowResources[i].FromPB(v.ShowResources[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CurrencyRpcShowReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CurrencyRpcShowReply pb = ProtoBuf.Serializer.Deserialize<CurrencyRpcShowReply>(protoMS);
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
	//展示货币信息
	public List<ResourceWraper> m_ShowResources;
	public int SizeShowResources()
	{
		return m_ShowResources.Count;
	}
	public List<ResourceWraper> GetShowResources()
	{
		return m_ShowResources;
	}
	public ResourceWraper GetShowResources(int Index)
	{
		if(Index<0 || Index>=(int)m_ShowResources.Count)
			return new ResourceWraper();
		return m_ShowResources[Index];
	}
	public void SetShowResources( List<ResourceWraper> v )
	{
		m_ShowResources=v;
	}
	public void SetShowResources( int Index, ResourceWraper v )
	{
		if(Index<0 || Index>=(int)m_ShowResources.Count)
			return;
		m_ShowResources[Index] = v;
	}
	public void AddShowResources( ResourceWraper v )
	{
		m_ShowResources.Add(v);
	}
	public void ClearShowResources( )
	{
		m_ShowResources.Clear();
	}


};
