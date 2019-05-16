
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBMercenary.cs
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


//入队请求封装类
[System.Serializable]
public class MercenaryRpcInQueueAskWraper
{

	//构造函数
	public MercenaryRpcInQueueAskWraper()
	{
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcInQueueAsk ToPB()
	{
		MercenaryRpcInQueueAsk v = new MercenaryRpcInQueueAsk();
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcInQueueAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcInQueueAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcInQueueAsk pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcInQueueAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//入队佣兵id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
//入队回应封装类
[System.Serializable]
public class MercenaryRpcInQueueReplyWraper
{

	//构造函数
	public MercenaryRpcInQueueReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcInQueueReply ToPB()
	{
		MercenaryRpcInQueueReply v = new MercenaryRpcInQueueReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcInQueueReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcInQueueReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcInQueueReply pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcInQueueReply>(protoMS);
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
//出队请求封装类
[System.Serializable]
public class MercenaryRpcOutQueueAskWraper
{

	//构造函数
	public MercenaryRpcOutQueueAskWraper()
	{
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcOutQueueAsk ToPB()
	{
		MercenaryRpcOutQueueAsk v = new MercenaryRpcOutQueueAsk();
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcOutQueueAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcOutQueueAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcOutQueueAsk pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcOutQueueAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//出队佣兵id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
//出队回应封装类
[System.Serializable]
public class MercenaryRpcOutQueueReplyWraper
{

	//构造函数
	public MercenaryRpcOutQueueReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcOutQueueReply ToPB()
	{
		MercenaryRpcOutQueueReply v = new MercenaryRpcOutQueueReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcOutQueueReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcOutQueueReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcOutQueueReply pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcOutQueueReply>(protoMS);
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
//自动配置请求封装类
[System.Serializable]
public class MercenaryRpcAutoSetAskWraper
{

	//构造函数
	public MercenaryRpcAutoSetAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcAutoSetAsk ToPB()
	{
		MercenaryRpcAutoSetAsk v = new MercenaryRpcAutoSetAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcAutoSetAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcAutoSetAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcAutoSetAsk pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcAutoSetAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//自动配置回应封装类
[System.Serializable]
public class MercenaryRpcAutoSetReplyWraper
{

	//构造函数
	public MercenaryRpcAutoSetReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcAutoSetReply ToPB()
	{
		MercenaryRpcAutoSetReply v = new MercenaryRpcAutoSetReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcAutoSetReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcAutoSetReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcAutoSetReply pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcAutoSetReply>(protoMS);
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
//佣兵信息请求封装类
[System.Serializable]
public class MercenaryRpcInfoAskWraper
{

	//构造函数
	public MercenaryRpcInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcInfoAsk ToPB()
	{
		MercenaryRpcInfoAsk v = new MercenaryRpcInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcInfoAsk pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//佣兵信息回应封装类
[System.Serializable]
public class MercenaryRpcInfoReplyWraper
{

	//构造函数
	public MercenaryRpcInfoReplyWraper()
	{
		 m_Result = -1;
		m_Mercenary = new List<MercenaryInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Mercenary = new List<MercenaryInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public MercenaryRpcInfoReply ToPB()
	{
		MercenaryRpcInfoReply v = new MercenaryRpcInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Mercenary.Count; i++)
			v.Mercenary.Add( m_Mercenary[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryRpcInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Mercenary.Clear();
		for( int i=0; i<v.Mercenary.Count; i++)
			m_Mercenary.Add( new MercenaryInfoWraper());
		for( int i=0; i<v.Mercenary.Count; i++)
			m_Mercenary[i].FromPB(v.Mercenary[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryRpcInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryRpcInfoReply pb = ProtoBuf.Serializer.Deserialize<MercenaryRpcInfoReply>(protoMS);
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
	//佣兵信息
	public List<MercenaryInfoWraper> m_Mercenary;
	public int SizeMercenary()
	{
		return m_Mercenary.Count;
	}
	public List<MercenaryInfoWraper> GetMercenary()
	{
		return m_Mercenary;
	}
	public MercenaryInfoWraper GetMercenary(int Index)
	{
		if(Index<0 || Index>=(int)m_Mercenary.Count)
			return new MercenaryInfoWraper();
		return m_Mercenary[Index];
	}
	public void SetMercenary( List<MercenaryInfoWraper> v )
	{
		m_Mercenary=v;
	}
	public void SetMercenary( int Index, MercenaryInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Mercenary.Count)
			return;
		m_Mercenary[Index] = v;
	}
	public void AddMercenary( MercenaryInfoWraper v )
	{
		m_Mercenary.Add(v);
	}
	public void ClearMercenary( )
	{
		m_Mercenary.Clear();
	}


};
