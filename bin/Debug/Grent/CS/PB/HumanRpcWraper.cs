
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBHuman.cs
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


//human move请求封装类
[System.Serializable]
public class HumanRpcMoveAskWraper
{

	//构造函数
	public HumanRpcMoveAskWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveAsk ToPB()
	{
		HumanRpcMoveAsk v = new HumanRpcMoveAsk();
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMoveAsk v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;
		m_X = v.X;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMoveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMoveAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcMoveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//CurPosX
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//CurPosZ
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//human move回应封装类
[System.Serializable]
public class HumanRpcMoveReplyWraper
{

	//构造函数
	public HumanRpcMoveReplyWraper()
	{
		 m_Result = -9999;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveReply ToPB()
	{
		HumanRpcMoveReply v = new HumanRpcMoveReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMoveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMoveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMoveReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcMoveReply>(protoMS);
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
	//当前位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//客户端停止移动请求封装类
[System.Serializable]
public class HumanRpcStopMoveAskWraper
{

	//构造函数
	public HumanRpcStopMoveAskWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStopMoveAsk ToPB()
	{
		HumanRpcStopMoveAsk v = new HumanRpcStopMoveAsk();
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcStopMoveAsk v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;
		m_X = v.X;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcStopMoveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcStopMoveAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcStopMoveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//CurPosX
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//CurPosZ
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//客户端停止移动回应封装类
[System.Serializable]
public class HumanRpcStopMoveReplyWraper
{

	//构造函数
	public HumanRpcStopMoveReplyWraper()
	{
		 m_Result = -9999;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStopMoveReply ToPB()
	{
		HumanRpcStopMoveReply v = new HumanRpcStopMoveReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcStopMoveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcStopMoveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcStopMoveReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcStopMoveReply>(protoMS);
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
	//当前位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//移动验证请求封装类
[System.Serializable]
public class HumanRpcMovementVerificationAskWraper
{

	//构造函数
	public HumanRpcMovementVerificationAskWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMovementVerificationAsk ToPB()
	{
		HumanRpcMovementVerificationAsk v = new HumanRpcMovementVerificationAsk();
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMovementVerificationAsk v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;
		m_X = v.X;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMovementVerificationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMovementVerificationAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcMovementVerificationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//CurPosX
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//CurPosZ
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//移动验证回应封装类
[System.Serializable]
public class HumanRpcMovementVerificationReplyWraper
{

	//构造函数
	public HumanRpcMovementVerificationReplyWraper()
	{
		 m_Result = -9999;
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMovementVerificationReply ToPB()
	{
		HumanRpcMovementVerificationReply v = new HumanRpcMovementVerificationReply();
		v.Result = m_Result;
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMovementVerificationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Dir = v.Dir;
		m_X = v.X;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMovementVerificationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMovementVerificationReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcMovementVerificationReply>(protoMS);
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
	//移动方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//CurPosX
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//CurPosZ
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//客户端位置校验通知封装类
[System.Serializable]
public class HumanRpcCGMoveCheckNotifyWraper
{

	//构造函数
	public HumanRpcCGMoveCheckNotifyWraper()
	{
		 m_Dir = (float)0;
		 m_Pos = new V3Wraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)0;
		 m_Pos = new V3Wraper();

	}

 	//转化成Protobuffer类型函数
	public HumanRpcCGMoveCheckNotify ToPB()
	{
		HumanRpcCGMoveCheckNotify v = new HumanRpcCGMoveCheckNotify();
		v.Dir = m_Dir;
		v.Pos = m_Pos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcCGMoveCheckNotify v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;
		m_Pos.FromPB(v.Pos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcCGMoveCheckNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcCGMoveCheckNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcCGMoveCheckNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
//服务器位置校验通知通知封装类
[System.Serializable]
public class HumanRpcGCMoveCheckNotifyWraper
{

	//构造函数
	public HumanRpcGCMoveCheckNotifyWraper()
	{
		 m_Dir = (float)-1;
		 m_Pos = new V3Wraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_Pos = new V3Wraper();

	}

 	//转化成Protobuffer类型函数
	public HumanRpcGCMoveCheckNotify ToPB()
	{
		HumanRpcGCMoveCheckNotify v = new HumanRpcGCMoveCheckNotify();
		v.Dir = m_Dir;
		v.Pos = m_Pos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcGCMoveCheckNotify v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;
		m_Pos.FromPB(v.Pos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcGCMoveCheckNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcGCMoveCheckNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcGCMoveCheckNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
