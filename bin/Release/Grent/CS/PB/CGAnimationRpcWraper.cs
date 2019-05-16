
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBCGAnimation.cs
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


//动画开始播放请求封装类
[System.Serializable]
public class CGAnimationRpcCgPlayAskWraper
{

	//构造函数
	public CGAnimationRpcCgPlayAskWraper()
	{
		 m_CgId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CgId = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgPlayAsk ToPB()
	{
		CGAnimationRpcCgPlayAsk v = new CGAnimationRpcCgPlayAsk();
		v.CgId = m_CgId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgPlayAsk v)
	{
        if (v == null)
            return;
		m_CgId = v.CgId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgPlayAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgPlayAsk pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgPlayAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//动画ID
	public int m_CgId;
	public int CgId
	{
		get { return m_CgId;}
		set { m_CgId = value; }
	}


};
//动画开始播放回应封装类
[System.Serializable]
public class CGAnimationRpcCgPlayReplyWraper
{

	//构造函数
	public CGAnimationRpcCgPlayReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgPlayReply ToPB()
	{
		CGAnimationRpcCgPlayReply v = new CGAnimationRpcCgPlayReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgPlayReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgPlayReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgPlayReply pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgPlayReply>(protoMS);
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
//通知通知封装类
[System.Serializable]
public class CGAnimationRpcCgPlayNotifyNotifyWraper
{

	//构造函数
	public CGAnimationRpcCgPlayNotifyNotifyWraper()
	{
		 m_RoleId = 0;
		 m_CgId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_CgId = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgPlayNotifyNotify ToPB()
	{
		CGAnimationRpcCgPlayNotifyNotify v = new CGAnimationRpcCgPlayNotifyNotify();
		v.RoleId = m_RoleId;
		v.CgId = m_CgId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgPlayNotifyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_CgId = v.CgId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgPlayNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgPlayNotifyNotify pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgPlayNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//动画ID
	public int m_CgId;
	public int CgId
	{
		get { return m_CgId;}
		set { m_CgId = value; }
	}


};
//结束通知通知封装类
[System.Serializable]
public class CGAnimationRpcCgOverNotifyNotifyWraper
{

	//构造函数
	public CGAnimationRpcCgOverNotifyNotifyWraper()
	{
		 m_RoleId = 0;
		 m_CgId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_CgId = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgOverNotifyNotify ToPB()
	{
		CGAnimationRpcCgOverNotifyNotify v = new CGAnimationRpcCgOverNotifyNotify();
		v.RoleId = m_RoleId;
		v.CgId = m_CgId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgOverNotifyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_CgId = v.CgId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgOverNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgOverNotifyNotify pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgOverNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色Id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//动画Id
	public int m_CgId;
	public int CgId
	{
		get { return m_CgId;}
		set { m_CgId = value; }
	}


};
//跳过CG请求封装类
[System.Serializable]
public class CGAnimationRpcCgSkipAskWraper
{

	//构造函数
	public CGAnimationRpcCgSkipAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgSkipAsk ToPB()
	{
		CGAnimationRpcCgSkipAsk v = new CGAnimationRpcCgSkipAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgSkipAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgSkipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgSkipAsk pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgSkipAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//跳过CG回应封装类
[System.Serializable]
public class CGAnimationRpcCgSkipReplyWraper
{

	//构造函数
	public CGAnimationRpcCgSkipReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcCgSkipReply ToPB()
	{
		CGAnimationRpcCgSkipReply v = new CGAnimationRpcCgSkipReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcCgSkipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcCgSkipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcCgSkipReply pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcCgSkipReply>(protoMS);
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
//脚本播放通知封装类
[System.Serializable]
public class CGAnimationRpcScriptPlayNotifyWraper
{

	//构造函数
	public CGAnimationRpcScriptPlayNotifyWraper()
	{
		 m_CasterGuid = 0;
		 m_AnimantionName = "";
		 m_Time = (float)-1;
		 m_IsLoop = -1;
		 m_SingleTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CasterGuid = 0;
		 m_AnimantionName = "";
		 m_Time = (float)-1;
		 m_IsLoop = -1;
		 m_SingleTime = -1;

	}

 	//转化成Protobuffer类型函数
	public CGAnimationRpcScriptPlayNotify ToPB()
	{
		CGAnimationRpcScriptPlayNotify v = new CGAnimationRpcScriptPlayNotify();
		v.CasterGuid = m_CasterGuid;
		v.AnimantionName = m_AnimantionName;
		v.Time = m_Time;
		v.IsLoop = m_IsLoop;
		v.SingleTime = m_SingleTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CGAnimationRpcScriptPlayNotify v)
	{
        if (v == null)
            return;
		m_CasterGuid = v.CasterGuid;
		m_AnimantionName = v.AnimantionName;
		m_Time = v.Time;
		m_IsLoop = v.IsLoop;
		m_SingleTime = v.SingleTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CGAnimationRpcScriptPlayNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CGAnimationRpcScriptPlayNotify pb = ProtoBuf.Serializer.Deserialize<CGAnimationRpcScriptPlayNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//释放者
	public UInt64 m_CasterGuid;
	public UInt64 CasterGuid
	{
		get { return m_CasterGuid;}
		set { m_CasterGuid = value; }
	}
	//动画名称
	public string m_AnimantionName;
	public string AnimantionName
	{
		get { return m_AnimantionName;}
		set { m_AnimantionName = value; }
	}
	//总时长
	public float m_Time;
	public float Time
	{
		get { return m_Time;}
		set { m_Time = value; }
	}
	//是否循环
	public int m_IsLoop;
	public int IsLoop
	{
		get { return m_IsLoop;}
		set { m_IsLoop = value; }
	}
	//单个时长
	public int m_SingleTime;
	public int SingleTime
	{
		get { return m_SingleTime;}
		set { m_SingleTime = value; }
	}


};
