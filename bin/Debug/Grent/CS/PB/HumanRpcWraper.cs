
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
//移动检测通知封装类
[System.Serializable]
public class HumanRpcMoveCheckNotifyWraper
{

	//构造函数
	public HumanRpcMoveCheckNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveCheckNotify ToPB()
	{
		HumanRpcMoveCheckNotify v = new HumanRpcMoveCheckNotify();
		v.ObjId = m_ObjId;
		v.Dir = m_Dir;
		v.X = m_X;
		v.Y = m_Y;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMoveCheckNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Dir = v.Dir;
		m_X = v.X;
		m_Y = v.Y;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMoveCheckNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMoveCheckNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcMoveCheckNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//x位置
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//y位置
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}


};
//按照点来移动通知封装类
[System.Serializable]
public class HumanRpcMoveByPosNotifyWraper
{

	//构造函数
	public HumanRpcMoveByPosNotifyWraper()
	{
		 m_ObjId = -1;
		 m_TargetX = (float)-1;
		 m_TargetY = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_TargetX = (float)-1;
		 m_TargetY = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveByPosNotify ToPB()
	{
		HumanRpcMoveByPosNotify v = new HumanRpcMoveByPosNotify();
		v.ObjId = m_ObjId;
		v.TargetX = m_TargetX;
		v.TargetY = m_TargetY;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMoveByPosNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_TargetX = v.TargetX;
		m_TargetY = v.TargetY;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMoveByPosNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMoveByPosNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcMoveByPosNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标ID
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//目标位置
	public float m_TargetX;
	public float TargetX
	{
		get { return m_TargetX;}
		set { m_TargetX = value; }
	}
	//目标位置
	public float m_TargetY;
	public float TargetY
	{
		get { return m_TargetY;}
		set { m_TargetY = value; }
	}


};
//Respawn请求封装类
[System.Serializable]
public class HumanRpcRespawnAskWraper
{

	//构造函数
	public HumanRpcRespawnAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRespawnAsk ToPB()
	{
		HumanRpcRespawnAsk v = new HumanRpcRespawnAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRespawnAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRespawnAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRespawnAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcRespawnAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//Respawn回应封装类
[System.Serializable]
public class HumanRpcRespawnReplyWraper
{

	//构造函数
	public HumanRpcRespawnReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRespawnReply ToPB()
	{
		HumanRpcRespawnReply v = new HumanRpcRespawnReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRespawnReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRespawnReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRespawnReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcRespawnReply>(protoMS);
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
