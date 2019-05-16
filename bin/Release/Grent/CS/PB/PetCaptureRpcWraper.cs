
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBPetCapture.cs
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


//宠物捕获请求封装类
[System.Serializable]
public class PetCaptureRpcCaptureAskWraper
{

	//构造函数
	public PetCaptureRpcCaptureAskWraper()
	{
		 m_BallType = 1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BallType = 1;

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcCaptureAsk ToPB()
	{
		PetCaptureRpcCaptureAsk v = new PetCaptureRpcCaptureAsk();
		v.BallType = m_BallType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcCaptureAsk v)
	{
        if (v == null)
            return;
		m_BallType = v.BallType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcCaptureAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcCaptureAsk pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcCaptureAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//精灵球道具类型
	public int m_BallType;
	public int BallType
	{
		get { return m_BallType;}
		set { m_BallType = value; }
	}


};
//宠物捕获回应封装类
[System.Serializable]
public class PetCaptureRpcCaptureReplyWraper
{

	//构造函数
	public PetCaptureRpcCaptureReplyWraper()
	{
		 m_Result = -1;
		 m_CreatureId = -1;
		 m_PetId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_CreatureId = -1;
		 m_PetId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcCaptureReply ToPB()
	{
		PetCaptureRpcCaptureReply v = new PetCaptureRpcCaptureReply();
		v.Result = m_Result;
		v.CreatureId = m_CreatureId;
		v.PetId = m_PetId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcCaptureReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_CreatureId = v.CreatureId;
		m_PetId = v.PetId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcCaptureReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcCaptureReply pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcCaptureReply>(protoMS);
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
	//宠物模型id
	public int m_CreatureId;
	public int CreatureId
	{
		get { return m_CreatureId;}
		set { m_CreatureId = value; }
	}
	//掉落宠物id
	public int m_PetId;
	public int PetId
	{
		get { return m_PetId;}
		set { m_PetId = value; }
	}


};
//捕获到宠物广播通知封装类
[System.Serializable]
public class PetCaptureRpcCapturePetNotifyWraper
{

	//构造函数
	public PetCaptureRpcCapturePetNotifyWraper()
	{
		 m_PetId = -1;
		 m_NickName = "";
		 m_RoleId = -1;
		 m_CreatureId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PetId = -1;
		 m_NickName = "";
		 m_RoleId = -1;
		 m_CreatureId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcCapturePetNotify ToPB()
	{
		PetCaptureRpcCapturePetNotify v = new PetCaptureRpcCapturePetNotify();
		v.PetId = m_PetId;
		v.NickName = m_NickName;
		v.RoleId = m_RoleId;
		v.CreatureId = m_CreatureId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcCapturePetNotify v)
	{
        if (v == null)
            return;
		m_PetId = v.PetId;
		m_NickName = v.NickName;
		m_RoleId = v.RoleId;
		m_CreatureId = v.CreatureId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcCapturePetNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcCapturePetNotify pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcCapturePetNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//捕获到宠物id
	public int m_PetId;
	public int PetId
	{
		get { return m_PetId;}
		set { m_PetId = value; }
	}
	//捕获到宠物人昵称
	public string m_NickName;
	public string NickName
	{
		get { return m_NickName;}
		set { m_NickName = value; }
	}
	//捕获到宠物角色id
	public int m_RoleId;
	public int RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//宠物模型id
	public int m_CreatureId;
	public int CreatureId
	{
		get { return m_CreatureId;}
		set { m_CreatureId = value; }
	}


};
//宠物捕获登录通知封装类
[System.Serializable]
public class PetCaptureRpcLoginNotifyWraper
{

	//构造函数
	public PetCaptureRpcLoginNotifyWraper()
	{
		 m_WayPoint = -1;
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_WayPoint = -1;
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcLoginNotify ToPB()
	{
		PetCaptureRpcLoginNotify v = new PetCaptureRpcLoginNotify();
		v.WayPoint = m_WayPoint;
		v.SceneId = m_SceneId;
		v.Pos = m_Pos.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcLoginNotify v)
	{
        if (v == null)
            return;
		m_WayPoint = v.WayPoint;
		m_SceneId = v.SceneId;
		m_Pos.FromPB(v.Pos);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcLoginNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcLoginNotify pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcLoginNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//宠物捕获npc刷新路点
	public int m_WayPoint;
	public int WayPoint
	{
		get { return m_WayPoint;}
		set { m_WayPoint = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//npc位置
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
//宠物npc位置请求封装类
[System.Serializable]
public class PetCaptureRpcPetLocationAskWraper
{

	//构造函数
	public PetCaptureRpcPetLocationAskWraper()
	{
		 m_LineId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LineId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcPetLocationAsk ToPB()
	{
		PetCaptureRpcPetLocationAsk v = new PetCaptureRpcPetLocationAsk();
		v.LineId = m_LineId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcPetLocationAsk v)
	{
        if (v == null)
            return;
		m_LineId = v.LineId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcPetLocationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcPetLocationAsk pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcPetLocationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//分线id
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
	}


};
//宠物npc位置回应封装类
[System.Serializable]
public class PetCaptureRpcPetLocationReplyWraper
{

	//构造函数
	public PetCaptureRpcPetLocationReplyWraper()
	{
		 m_Result = -1;
		 m_Pos = new Vector3Wraper();
		 m_SceneId = -1;
		 m_WayPoint = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Pos = new Vector3Wraper();
		 m_SceneId = -1;
		 m_WayPoint = -1;

	}

 	//转化成Protobuffer类型函数
	public PetCaptureRpcPetLocationReply ToPB()
	{
		PetCaptureRpcPetLocationReply v = new PetCaptureRpcPetLocationReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.SceneId = m_SceneId;
		v.WayPoint = m_WayPoint;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetCaptureRpcPetLocationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Pos.FromPB(v.Pos);
		m_SceneId = v.SceneId;
		m_WayPoint = v.WayPoint;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetCaptureRpcPetLocationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetCaptureRpcPetLocationReply pb = ProtoBuf.Serializer.Deserialize<PetCaptureRpcPetLocationReply>(protoMS);
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
	//坐标
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//路点
	public int m_WayPoint;
	public int WayPoint
	{
		get { return m_WayPoint;}
		set { m_WayPoint = value; }
	}


};
