
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBBulletScreen.cs
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


//弹幕设置请求封装类
[System.Serializable]
public class BulletScreenRpcBulletScreenOptAskWraper
{

	//构造函数
	public BulletScreenRpcBulletScreenOptAskWraper()
	{
		 m_BulletScreenType = -1;
		 m_OptType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BulletScreenType = -1;
		 m_OptType = -1;

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcBulletScreenOptAsk ToPB()
	{
		BulletScreenRpcBulletScreenOptAsk v = new BulletScreenRpcBulletScreenOptAsk();
		v.BulletScreenType = m_BulletScreenType;
		v.OptType = m_OptType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcBulletScreenOptAsk v)
	{
        if (v == null)
            return;
		m_BulletScreenType = v.BulletScreenType;
		m_OptType = v.OptType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcBulletScreenOptAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcBulletScreenOptAsk pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcBulletScreenOptAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//弹幕设置场景(1组队 2过场)
	public int m_BulletScreenType;
	public int BulletScreenType
	{
		get { return m_BulletScreenType;}
		set { m_BulletScreenType = value; }
	}
	//关闭打开(1关闭 2打开)
	public int m_OptType;
	public int OptType
	{
		get { return m_OptType;}
		set { m_OptType = value; }
	}


};
//弹幕设置回应封装类
[System.Serializable]
public class BulletScreenRpcBulletScreenOptReplyWraper
{

	//构造函数
	public BulletScreenRpcBulletScreenOptReplyWraper()
	{
		 m_Result = -1;
		 m_BulletScreenType = -1;
		 m_OptType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_BulletScreenType = -1;
		 m_OptType = -1;

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcBulletScreenOptReply ToPB()
	{
		BulletScreenRpcBulletScreenOptReply v = new BulletScreenRpcBulletScreenOptReply();
		v.Result = m_Result;
		v.BulletScreenType = m_BulletScreenType;
		v.OptType = m_OptType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcBulletScreenOptReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_BulletScreenType = v.BulletScreenType;
		m_OptType = v.OptType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcBulletScreenOptReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcBulletScreenOptReply pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcBulletScreenOptReply>(protoMS);
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
	//弹幕设置场景(1组队 2过场)
	public int m_BulletScreenType;
	public int BulletScreenType
	{
		get { return m_BulletScreenType;}
		set { m_BulletScreenType = value; }
	}
	//关闭打开(1关闭 2打开)
	public int m_OptType;
	public int OptType
	{
		get { return m_OptType;}
		set { m_OptType = value; }
	}


};
//过场动画弹幕请求请求封装类
[System.Serializable]
public class BulletScreenRpcCGBulletScreenAskWraper
{

	//构造函数
	public BulletScreenRpcCGBulletScreenAskWraper()
	{
		 m_CGid = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CGid = -1;

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcCGBulletScreenAsk ToPB()
	{
		BulletScreenRpcCGBulletScreenAsk v = new BulletScreenRpcCGBulletScreenAsk();
		v.CGid = m_CGid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcCGBulletScreenAsk v)
	{
        if (v == null)
            return;
		m_CGid = v.CGid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcCGBulletScreenAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcCGBulletScreenAsk pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcCGBulletScreenAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//过场ID
	public int m_CGid;
	public int CGid
	{
		get { return m_CGid;}
		set { m_CGid = value; }
	}


};
//过场动画弹幕请求回应封装类
[System.Serializable]
public class BulletScreenRpcCGBulletScreenReplyWraper
{

	//构造函数
	public BulletScreenRpcCGBulletScreenReplyWraper()
	{
		 m_Result = -1;
		m_BulletScreenContent = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_BulletScreenContent = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcCGBulletScreenReply ToPB()
	{
		BulletScreenRpcCGBulletScreenReply v = new BulletScreenRpcCGBulletScreenReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_BulletScreenContent.Count; i++)
			v.BulletScreenContent.Add( m_BulletScreenContent[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcCGBulletScreenReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_BulletScreenContent.Clear();
		for( int i=0; i<v.BulletScreenContent.Count; i++)
			m_BulletScreenContent.Add(v.BulletScreenContent[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcCGBulletScreenReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcCGBulletScreenReply pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcCGBulletScreenReply>(protoMS);
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
	//弹幕内容
	public List<string> m_BulletScreenContent;
	public int SizeBulletScreenContent()
	{
		return m_BulletScreenContent.Count;
	}
	public List<string> GetBulletScreenContent()
	{
		return m_BulletScreenContent;
	}
	public string GetBulletScreenContent(int Index)
	{
		if(Index<0 || Index>=(int)m_BulletScreenContent.Count)
			return "";
		return m_BulletScreenContent[Index];
	}
	public void SetBulletScreenContent( List<string> v )
	{
		m_BulletScreenContent=v;
	}
	public void SetBulletScreenContent( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_BulletScreenContent.Count)
			return;
		m_BulletScreenContent[Index] = v;
	}
	public void AddBulletScreenContent( string v )
	{
		m_BulletScreenContent.Add(v);
	}
	public void ClearBulletScreenContent( )
	{
		m_BulletScreenContent.Clear();
	}


};
//发布过场弹幕请求封装类
[System.Serializable]
public class BulletScreenRpcSendBulletScreenCGAskWraper
{

	//构造函数
	public BulletScreenRpcSendBulletScreenCGAskWraper()
	{
		 m_CGid = -1;
		 m_Content = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CGid = -1;
		 m_Content = "";

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcSendBulletScreenCGAsk ToPB()
	{
		BulletScreenRpcSendBulletScreenCGAsk v = new BulletScreenRpcSendBulletScreenCGAsk();
		v.CGid = m_CGid;
		v.Content = m_Content;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcSendBulletScreenCGAsk v)
	{
        if (v == null)
            return;
		m_CGid = v.CGid;
		m_Content = v.Content;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcSendBulletScreenCGAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcSendBulletScreenCGAsk pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcSendBulletScreenCGAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//过场ID
	public int m_CGid;
	public int CGid
	{
		get { return m_CGid;}
		set { m_CGid = value; }
	}
	//发布内容
	public string m_Content;
	public string Content
	{
		get { return m_Content;}
		set { m_Content = value; }
	}


};
//发布过场弹幕回应封装类
[System.Serializable]
public class BulletScreenRpcSendBulletScreenCGReplyWraper
{

	//构造函数
	public BulletScreenRpcSendBulletScreenCGReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public BulletScreenRpcSendBulletScreenCGReply ToPB()
	{
		BulletScreenRpcSendBulletScreenCGReply v = new BulletScreenRpcSendBulletScreenCGReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BulletScreenRpcSendBulletScreenCGReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BulletScreenRpcSendBulletScreenCGReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BulletScreenRpcSendBulletScreenCGReply pb = ProtoBuf.Serializer.Deserialize<BulletScreenRpcSendBulletScreenCGReply>(protoMS);
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
