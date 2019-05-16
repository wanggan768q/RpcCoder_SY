
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBFunctionTutorial.cs
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


//同步请求封装类
[System.Serializable]
public class FunctionTutorialRpcSyncFunctionStepAskWraper
{

	//构造函数
	public FunctionTutorialRpcSyncFunctionStepAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcSyncFunctionStepAsk ToPB()
	{
		FunctionTutorialRpcSyncFunctionStepAsk v = new FunctionTutorialRpcSyncFunctionStepAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcSyncFunctionStepAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcSyncFunctionStepAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcSyncFunctionStepAsk pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcSyncFunctionStepAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class FunctionTutorialRpcSyncFunctionStepReplyWraper
{

	//构造函数
	public FunctionTutorialRpcSyncFunctionStepReplyWraper()
	{
		 m_Result = -1;
		m_FunctionList = new List<int>();
		m_ActiveFunctionList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_FunctionList = new List<int>();
		m_ActiveFunctionList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcSyncFunctionStepReply ToPB()
	{
		FunctionTutorialRpcSyncFunctionStepReply v = new FunctionTutorialRpcSyncFunctionStepReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_FunctionList.Count; i++)
			v.FunctionList.Add( m_FunctionList[i]);
		for (int i=0; i<(int)m_ActiveFunctionList.Count; i++)
			v.ActiveFunctionList.Add( m_ActiveFunctionList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcSyncFunctionStepReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FunctionList.Clear();
		for( int i=0; i<v.FunctionList.Count; i++)
			m_FunctionList.Add(v.FunctionList[i]);
		m_ActiveFunctionList.Clear();
		for( int i=0; i<v.ActiveFunctionList.Count; i++)
			m_ActiveFunctionList.Add(v.ActiveFunctionList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcSyncFunctionStepReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcSyncFunctionStepReply pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcSyncFunctionStepReply>(protoMS);
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
	//已完成步骤Id
	public List<int> m_FunctionList;
	public int SizeFunctionList()
	{
		return m_FunctionList.Count;
	}
	public List<int> GetFunctionList()
	{
		return m_FunctionList;
	}
	public int GetFunctionList(int Index)
	{
		if(Index<0 || Index>=(int)m_FunctionList.Count)
			return -1;
		return m_FunctionList[Index];
	}
	public void SetFunctionList( List<int> v )
	{
		m_FunctionList=v;
	}
	public void SetFunctionList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_FunctionList.Count)
			return;
		m_FunctionList[Index] = v;
	}
	public void AddFunctionList( int v=-1 )
	{
		m_FunctionList.Add(v);
	}
	public void ClearFunctionList( )
	{
		m_FunctionList.Clear();
	}
	//激活的
	public List<int> m_ActiveFunctionList;
	public int SizeActiveFunctionList()
	{
		return m_ActiveFunctionList.Count;
	}
	public List<int> GetActiveFunctionList()
	{
		return m_ActiveFunctionList;
	}
	public int GetActiveFunctionList(int Index)
	{
		if(Index<0 || Index>=(int)m_ActiveFunctionList.Count)
			return -1;
		return m_ActiveFunctionList[Index];
	}
	public void SetActiveFunctionList( List<int> v )
	{
		m_ActiveFunctionList=v;
	}
	public void SetActiveFunctionList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ActiveFunctionList.Count)
			return;
		m_ActiveFunctionList[Index] = v;
	}
	public void AddActiveFunctionList( int v=-1 )
	{
		m_ActiveFunctionList.Add(v);
	}
	public void ClearActiveFunctionList( )
	{
		m_ActiveFunctionList.Clear();
	}


};
//完成请求封装类
[System.Serializable]
public class FunctionTutorialRpcFinishStepAskWraper
{

	//构造函数
	public FunctionTutorialRpcFinishStepAskWraper()
	{
		 m_FunctionID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FunctionID = -1;

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcFinishStepAsk ToPB()
	{
		FunctionTutorialRpcFinishStepAsk v = new FunctionTutorialRpcFinishStepAsk();
		v.FunctionID = m_FunctionID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcFinishStepAsk v)
	{
        if (v == null)
            return;
		m_FunctionID = v.FunctionID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcFinishStepAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcFinishStepAsk pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcFinishStepAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//步骤ID
	public int m_FunctionID;
	public int FunctionID
	{
		get { return m_FunctionID;}
		set { m_FunctionID = value; }
	}


};
//完成回应封装类
[System.Serializable]
public class FunctionTutorialRpcFinishStepReplyWraper
{

	//构造函数
	public FunctionTutorialRpcFinishStepReplyWraper()
	{
		 m_Result = -1;
		 m_FunctionID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_FunctionID = -1;

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcFinishStepReply ToPB()
	{
		FunctionTutorialRpcFinishStepReply v = new FunctionTutorialRpcFinishStepReply();
		v.Result = m_Result;
		v.FunctionID = m_FunctionID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcFinishStepReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FunctionID = v.FunctionID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcFinishStepReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcFinishStepReply pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcFinishStepReply>(protoMS);
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
	//完成的ID
	public int m_FunctionID;
	public int FunctionID
	{
		get { return m_FunctionID;}
		set { m_FunctionID = value; }
	}


};
//激活步骤请求封装类
[System.Serializable]
public class FunctionTutorialRpcActiveStepAskWraper
{

	//构造函数
	public FunctionTutorialRpcActiveStepAskWraper()
	{
		 m_FunctionID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FunctionID = -1;

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcActiveStepAsk ToPB()
	{
		FunctionTutorialRpcActiveStepAsk v = new FunctionTutorialRpcActiveStepAsk();
		v.FunctionID = m_FunctionID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcActiveStepAsk v)
	{
        if (v == null)
            return;
		m_FunctionID = v.FunctionID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcActiveStepAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcActiveStepAsk pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcActiveStepAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//引导ID
	public int m_FunctionID;
	public int FunctionID
	{
		get { return m_FunctionID;}
		set { m_FunctionID = value; }
	}


};
//激活步骤回应封装类
[System.Serializable]
public class FunctionTutorialRpcActiveStepReplyWraper
{

	//构造函数
	public FunctionTutorialRpcActiveStepReplyWraper()
	{
		 m_Result = -1;
		 m_FunctionID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_FunctionID = -1;

	}

 	//转化成Protobuffer类型函数
	public FunctionTutorialRpcActiveStepReply ToPB()
	{
		FunctionTutorialRpcActiveStepReply v = new FunctionTutorialRpcActiveStepReply();
		v.Result = m_Result;
		v.FunctionID = m_FunctionID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FunctionTutorialRpcActiveStepReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FunctionID = v.FunctionID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FunctionTutorialRpcActiveStepReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FunctionTutorialRpcActiveStepReply pb = ProtoBuf.Serializer.Deserialize<FunctionTutorialRpcActiveStepReply>(protoMS);
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
	//引导ID
	public int m_FunctionID;
	public int FunctionID
	{
		get { return m_FunctionID;}
		set { m_FunctionID = value; }
	}


};
