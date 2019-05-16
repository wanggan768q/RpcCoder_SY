
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBExpressionAction.cs
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


//数据同步请求封装类
[System.Serializable]
public class ExpressionActionRpcSyncAskWraper
{

	//构造函数
	public ExpressionActionRpcSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcSyncAsk ToPB()
	{
		ExpressionActionRpcSyncAsk v = new ExpressionActionRpcSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcSyncAsk pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//数据同步回应封装类
[System.Serializable]
public class ExpressionActionRpcSyncReplyWraper
{

	//构造函数
	public ExpressionActionRpcSyncReplyWraper()
	{
		 m_Result = -1;
		m_ExpressionActionList = new List<ExpressionActionInfoWraper>();
		m_ExpressionWheelList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ExpressionActionList = new List<ExpressionActionInfoWraper>();
		m_ExpressionWheelList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcSyncReply ToPB()
	{
		ExpressionActionRpcSyncReply v = new ExpressionActionRpcSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ExpressionActionList.Count; i++)
			v.ExpressionActionList.Add( m_ExpressionActionList[i].ToPB());
		for (int i=0; i<(int)m_ExpressionWheelList.Count; i++)
			v.ExpressionWheelList.Add( m_ExpressionWheelList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ExpressionActionList.Clear();
		for( int i=0; i<v.ExpressionActionList.Count; i++)
			m_ExpressionActionList.Add( new ExpressionActionInfoWraper());
		for( int i=0; i<v.ExpressionActionList.Count; i++)
			m_ExpressionActionList[i].FromPB(v.ExpressionActionList[i]);
		m_ExpressionWheelList.Clear();
		for( int i=0; i<v.ExpressionWheelList.Count; i++)
			m_ExpressionWheelList.Add(v.ExpressionWheelList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcSyncReply pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcSyncReply>(protoMS);
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
	//表情信息
	public List<ExpressionActionInfoWraper> m_ExpressionActionList;
	public int SizeExpressionActionList()
	{
		return m_ExpressionActionList.Count;
	}
	public List<ExpressionActionInfoWraper> GetExpressionActionList()
	{
		return m_ExpressionActionList;
	}
	public ExpressionActionInfoWraper GetExpressionActionList(int Index)
	{
		if(Index<0 || Index>=(int)m_ExpressionActionList.Count)
			return new ExpressionActionInfoWraper();
		return m_ExpressionActionList[Index];
	}
	public void SetExpressionActionList( List<ExpressionActionInfoWraper> v )
	{
		m_ExpressionActionList=v;
	}
	public void SetExpressionActionList( int Index, ExpressionActionInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ExpressionActionList.Count)
			return;
		m_ExpressionActionList[Index] = v;
	}
	public void AddExpressionActionList( ExpressionActionInfoWraper v )
	{
		m_ExpressionActionList.Add(v);
	}
	public void ClearExpressionActionList( )
	{
		m_ExpressionActionList.Clear();
	}
	//轮盘
	public List<int> m_ExpressionWheelList;
	public int SizeExpressionWheelList()
	{
		return m_ExpressionWheelList.Count;
	}
	public List<int> GetExpressionWheelList()
	{
		return m_ExpressionWheelList;
	}
	public int GetExpressionWheelList(int Index)
	{
		if(Index<0 || Index>=(int)m_ExpressionWheelList.Count)
			return -1;
		return m_ExpressionWheelList[Index];
	}
	public void SetExpressionWheelList( List<int> v )
	{
		m_ExpressionWheelList=v;
	}
	public void SetExpressionWheelList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ExpressionWheelList.Count)
			return;
		m_ExpressionWheelList[Index] = v;
	}
	public void AddExpressionWheelList( int v=-1 )
	{
		m_ExpressionWheelList.Add(v);
	}
	public void ClearExpressionWheelList( )
	{
		m_ExpressionWheelList.Clear();
	}


};
//设置轮盘请求封装类
[System.Serializable]
public class ExpressionActionRpcSetWheelAskWraper
{

	//构造函数
	public ExpressionActionRpcSetWheelAskWraper()
	{
		 m_Index = -1;
		 m_ActionId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_ActionId = -1;

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcSetWheelAsk ToPB()
	{
		ExpressionActionRpcSetWheelAsk v = new ExpressionActionRpcSetWheelAsk();
		v.Index = m_Index;
		v.ActionId = m_ActionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcSetWheelAsk v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_ActionId = v.ActionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcSetWheelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcSetWheelAsk pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcSetWheelAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//表情ID
	public int m_ActionId;
	public int ActionId
	{
		get { return m_ActionId;}
		set { m_ActionId = value; }
	}


};
//设置轮盘回应封装类
[System.Serializable]
public class ExpressionActionRpcSetWheelReplyWraper
{

	//构造函数
	public ExpressionActionRpcSetWheelReplyWraper()
	{
		 m_Result = -1;
		m_WheelList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_WheelList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcSetWheelReply ToPB()
	{
		ExpressionActionRpcSetWheelReply v = new ExpressionActionRpcSetWheelReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_WheelList.Count; i++)
			v.WheelList.Add( m_WheelList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcSetWheelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_WheelList.Clear();
		for( int i=0; i<v.WheelList.Count; i++)
			m_WheelList.Add(v.WheelList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcSetWheelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcSetWheelReply pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcSetWheelReply>(protoMS);
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
	//轮盘信息
	public List<int> m_WheelList;
	public int SizeWheelList()
	{
		return m_WheelList.Count;
	}
	public List<int> GetWheelList()
	{
		return m_WheelList;
	}
	public int GetWheelList(int Index)
	{
		if(Index<0 || Index>=(int)m_WheelList.Count)
			return -1;
		return m_WheelList[Index];
	}
	public void SetWheelList( List<int> v )
	{
		m_WheelList=v;
	}
	public void SetWheelList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_WheelList.Count)
			return;
		m_WheelList[Index] = v;
	}
	public void AddWheelList( int v=-1 )
	{
		m_WheelList.Add(v);
	}
	public void ClearWheelList( )
	{
		m_WheelList.Clear();
	}


};
//使用表情请求封装类
[System.Serializable]
public class ExpressionActionRpcUseActionAskWraper
{

	//构造函数
	public ExpressionActionRpcUseActionAskWraper()
	{
		 m_ActionId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ActionId = -1;

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcUseActionAsk ToPB()
	{
		ExpressionActionRpcUseActionAsk v = new ExpressionActionRpcUseActionAsk();
		v.ActionId = m_ActionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcUseActionAsk v)
	{
        if (v == null)
            return;
		m_ActionId = v.ActionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcUseActionAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcUseActionAsk pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcUseActionAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//表情ID
	public int m_ActionId;
	public int ActionId
	{
		get { return m_ActionId;}
		set { m_ActionId = value; }
	}


};
//使用表情回应封装类
[System.Serializable]
public class ExpressionActionRpcUseActionReplyWraper
{

	//构造函数
	public ExpressionActionRpcUseActionReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcUseActionReply ToPB()
	{
		ExpressionActionRpcUseActionReply v = new ExpressionActionRpcUseActionReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcUseActionReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcUseActionReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcUseActionReply pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcUseActionReply>(protoMS);
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
//使用表情通知通知封装类
[System.Serializable]
public class ExpressionActionRpcUseActionNotifyNotifyWraper
{

	//构造函数
	public ExpressionActionRpcUseActionNotifyNotifyWraper()
	{
		 m_ObjId = -1;
		 m_ActionId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_ActionId = -1;

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionRpcUseActionNotifyNotify ToPB()
	{
		ExpressionActionRpcUseActionNotifyNotify v = new ExpressionActionRpcUseActionNotifyNotify();
		v.ObjId = m_ObjId;
		v.ActionId = m_ActionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionRpcUseActionNotifyNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_ActionId = v.ActionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionRpcUseActionNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionRpcUseActionNotifyNotify pb = ProtoBuf.Serializer.Deserialize<ExpressionActionRpcUseActionNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色Id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//动作ID
	public int m_ActionId;
	public int ActionId
	{
		get { return m_ActionId;}
		set { m_ActionId = value; }
	}


};
