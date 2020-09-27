
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
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Z = (float)-1;
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveAsk ToPB()
	{
		HumanRpcMoveAsk v = new HumanRpcMoveAsk();
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;
		v.ObjId = m_ObjId;

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
		m_ObjId = v.ObjId;

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
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
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
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMoveReply ToPB()
	{
		HumanRpcMoveReply v = new HumanRpcMoveReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjId = m_ObjId;

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
		m_ObjId = v.ObjId;

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
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
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
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
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
		 m_X = -1;
		 m_Z = -1;
		 m_ObjId = 0;
		 m_BrakeRush = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = (float)-1;
		 m_X = -1;
		 m_Z = -1;
		 m_ObjId = 0;
		 m_BrakeRush = false;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStopMoveAsk ToPB()
	{
		HumanRpcStopMoveAsk v = new HumanRpcStopMoveAsk();
		v.Dir = m_Dir;
		v.X = m_X;
		v.Z = m_Z;
		v.ObjId = m_ObjId;
		v.BrakeRush = m_BrakeRush;

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
		m_ObjId = v.ObjId;
		m_BrakeRush = v.BrakeRush;

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
	public int m_X;
	public int X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//CurPosZ
	public int m_Z;
	public int Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//是否刹停
	public bool m_BrakeRush;
	public bool BrakeRush
	{
		get { return m_BrakeRush;}
		set { m_BrakeRush = value; }
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
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStopMoveReply ToPB()
	{
		HumanRpcStopMoveReply v = new HumanRpcStopMoveReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjId = m_ObjId;

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
		m_ObjId = v.ObjId;

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
	public Vector3IntWraper m_Pos;
	public Vector3IntWraper Pos
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
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//移动检测通知封装类
[System.Serializable]
public class HumanRpcMoveCheckNotifyWraper
{

	//构造函数
	public HumanRpcMoveCheckNotifyWraper()
	{
		 m_ObjId = 0;
		 m_Dir = (float)-1;
		 m_X = (float)-1;
		 m_Y = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
//Respawn请求封装类
[System.Serializable]
public class HumanRpcRespawnAskWraper
{

	//构造函数
	public HumanRpcRespawnAskWraper()
	{
		 m_ReviveType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ReviveType = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRespawnAsk ToPB()
	{
		HumanRpcRespawnAsk v = new HumanRpcRespawnAsk();
		v.ReviveType = m_ReviveType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRespawnAsk v)
	{
        if (v == null)
            return;
		m_ReviveType = v.ReviveType;

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

	//复活类型
	public int m_ReviveType;
	public int ReviveType
	{
		get { return m_ReviveType;}
		set { m_ReviveType = value; }
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
		 m_ReviveType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ReviveType = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRespawnReply ToPB()
	{
		HumanRpcRespawnReply v = new HumanRpcRespawnReply();
		v.Result = m_Result;
		v.ReviveType = m_ReviveType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRespawnReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ReviveType = v.ReviveType;

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
	//复活类型
	public int m_ReviveType;
	public int ReviveType
	{
		get { return m_ReviveType;}
		set { m_ReviveType = value; }
	}


};
//复活其他玩家通知通知封装类
[System.Serializable]
public class HumanRpcRespawnOtherNotifyWraper
{

	//构造函数
	public HumanRpcRespawnOtherNotifyWraper()
	{
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRespawnOtherNotify ToPB()
	{
		HumanRpcRespawnOtherNotify v = new HumanRpcRespawnOtherNotify();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRespawnOtherNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRespawnOtherNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRespawnOtherNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcRespawnOtherNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//MovePos请求封装类
[System.Serializable]
public class HumanRpcMovePosAskWraper
{

	//构造函数
	public HumanRpcMovePosAskWraper()
	{
		m_PosList = new List<Vector3IntWraper>();
		 m_Dir = (float)-1;
		 m_ObjId = 0;
		 m_IsAllowChangeRunAnimation = true;
		 m_IsLookAtMoving = true;
		 m_FromX = -1;
		 m_FromZ = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_PosList = new List<Vector3IntWraper>();
		 m_Dir = (float)-1;
		 m_ObjId = 0;
		 m_IsAllowChangeRunAnimation = true;
		 m_IsLookAtMoving = true;
		 m_FromX = -1;
		 m_FromZ = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMovePosAsk ToPB()
	{
		HumanRpcMovePosAsk v = new HumanRpcMovePosAsk();
		for (int i=0; i<(int)m_PosList.Count; i++)
			v.PosList.Add( m_PosList[i].ToPB());
		v.Dir = m_Dir;
		v.ObjId = m_ObjId;
		v.IsAllowChangeRunAnimation = m_IsAllowChangeRunAnimation;
		v.IsLookAtMoving = m_IsLookAtMoving;
		v.FromX = m_FromX;
		v.FromZ = m_FromZ;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMovePosAsk v)
	{
        if (v == null)
            return;
		m_PosList.Clear();
		for( int i=0; i<v.PosList.Count; i++)
			m_PosList.Add( new Vector3IntWraper());
		for( int i=0; i<v.PosList.Count; i++)
			m_PosList[i].FromPB(v.PosList[i]);
		m_Dir = v.Dir;
		m_ObjId = v.ObjId;
		m_IsAllowChangeRunAnimation = v.IsAllowChangeRunAnimation;
		m_IsLookAtMoving = v.IsLookAtMoving;
		m_FromX = v.FromX;
		m_FromZ = v.FromZ;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMovePosAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMovePosAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcMovePosAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要移动的位置
	public List<Vector3IntWraper> m_PosList;
	public int SizePosList()
	{
		return m_PosList.Count;
	}
	public List<Vector3IntWraper> GetPosList()
	{
		return m_PosList;
	}
	public Vector3IntWraper GetPosList(int Index)
	{
		if(Index<0 || Index>=(int)m_PosList.Count)
			return new Vector3IntWraper();
		return m_PosList[Index];
	}
	public void SetPosList( List<Vector3IntWraper> v )
	{
		m_PosList=v;
	}
	public void SetPosList( int Index, Vector3IntWraper v )
	{
		if(Index<0 || Index>=(int)m_PosList.Count)
			return;
		m_PosList[Index] = v;
	}
	public void AddPosList( Vector3IntWraper v )
	{
		m_PosList.Add(v);
	}
	public void ClearPosList( )
	{
		m_PosList.Clear();
	}
	//Dir
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//是否允许切换Run动画
	public bool m_IsAllowChangeRunAnimation;
	public bool IsAllowChangeRunAnimation
	{
		get { return m_IsAllowChangeRunAnimation;}
		set { m_IsAllowChangeRunAnimation = value; }
	}
	//是否朝向移动目标点
	public bool m_IsLookAtMoving;
	public bool IsLookAtMoving
	{
		get { return m_IsLookAtMoving;}
		set { m_IsLookAtMoving = value; }
	}
	//起始点X坐标
	public int m_FromX;
	public int FromX
	{
		get { return m_FromX;}
		set { m_FromX = value; }
	}
	//起始点Z坐标
	public int m_FromZ;
	public int FromZ
	{
		get { return m_FromZ;}
		set { m_FromZ = value; }
	}


};
//MovePos回应封装类
[System.Serializable]
public class HumanRpcMovePosReplyWraper
{

	//构造函数
	public HumanRpcMovePosReplyWraper()
	{
		 m_Result = -1;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMovePosReply ToPB()
	{
		HumanRpcMovePosReply v = new HumanRpcMovePosReply();
		v.Result = m_Result;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMovePosReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMovePosReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMovePosReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcMovePosReply>(protoMS);
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
	//PosList
	public Vector3IntWraper m_Pos;
	public Vector3IntWraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//Dir
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//死亡通知通知封装类
[System.Serializable]
public class HumanRpcRoleDieNotifyWraper
{

	//构造函数
	public HumanRpcRoleDieNotifyWraper()
	{
		 m_KillerGuid = -1;
		 m_KillerName = "";
		 m_KillerType = -1;
		 m_RevieCDTime = -1;
		 m_DungeonReviveCounts = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KillerGuid = -1;
		 m_KillerName = "";
		 m_KillerType = -1;
		 m_RevieCDTime = -1;
		 m_DungeonReviveCounts = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRoleDieNotify ToPB()
	{
		HumanRpcRoleDieNotify v = new HumanRpcRoleDieNotify();
		v.KillerGuid = m_KillerGuid;
		v.KillerName = m_KillerName;
		v.KillerType = m_KillerType;
		v.RevieCDTime = m_RevieCDTime;
		v.DungeonReviveCounts = m_DungeonReviveCounts;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRoleDieNotify v)
	{
        if (v == null)
            return;
		m_KillerGuid = v.KillerGuid;
		m_KillerName = v.KillerName;
		m_KillerType = v.KillerType;
		m_RevieCDTime = v.RevieCDTime;
		m_DungeonReviveCounts = v.DungeonReviveCounts;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRoleDieNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRoleDieNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcRoleDieNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//击杀者ID
	public Int64 m_KillerGuid;
	public Int64 KillerGuid
	{
		get { return m_KillerGuid;}
		set { m_KillerGuid = value; }
	}
	//击杀者名字
	public string m_KillerName;
	public string KillerName
	{
		get { return m_KillerName;}
		set { m_KillerName = value; }
	}
	//击杀者类型
	public int m_KillerType;
	public int KillerType
	{
		get { return m_KillerType;}
		set { m_KillerType = value; }
	}
	//就近复活CD时间
	public int m_RevieCDTime;
	public int RevieCDTime
	{
		get { return m_RevieCDTime;}
		set { m_RevieCDTime = value; }
	}
	//本次副本原地复活次数
	public int m_DungeonReviveCounts;
	public int DungeonReviveCounts
	{
		get { return m_DungeonReviveCounts;}
		set { m_DungeonReviveCounts = value; }
	}


};
//改变动画状态 纯客户端通知封装类
[System.Serializable]
public class HumanRpcChangeAnimationStateNotifyWraper
{

	//构造函数
	public HumanRpcChangeAnimationStateNotifyWraper()
	{
		 m_AnimationState = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AnimationState = false;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcChangeAnimationStateNotify ToPB()
	{
		HumanRpcChangeAnimationStateNotify v = new HumanRpcChangeAnimationStateNotify();
		v.AnimationState = m_AnimationState;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcChangeAnimationStateNotify v)
	{
        if (v == null)
            return;
		m_AnimationState = v.AnimationState;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcChangeAnimationStateNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcChangeAnimationStateNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcChangeAnimationStateNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//动画状态 具体值由客户端定
	public bool m_AnimationState;
	public bool AnimationState
	{
		get { return m_AnimationState;}
		set { m_AnimationState = value; }
	}


};
//玩家功能预告请求封装类
[System.Serializable]
public class HumanRpcFuncNoticeAskWraper
{

	//构造函数
	public HumanRpcFuncNoticeAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public HumanRpcFuncNoticeAsk ToPB()
	{
		HumanRpcFuncNoticeAsk v = new HumanRpcFuncNoticeAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcFuncNoticeAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcFuncNoticeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcFuncNoticeAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcFuncNoticeAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//玩家功能预告回应封装类
[System.Serializable]
public class HumanRpcFuncNoticeReplyWraper
{

	//构造函数
	public HumanRpcFuncNoticeReplyWraper()
	{
		 m_Result = -1;
		 m_FuncIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_FuncIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcFuncNoticeReply ToPB()
	{
		HumanRpcFuncNoticeReply v = new HumanRpcFuncNoticeReply();
		v.Result = m_Result;
		v.FuncIndex = m_FuncIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcFuncNoticeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FuncIndex = v.FuncIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcFuncNoticeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcFuncNoticeReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcFuncNoticeReply>(protoMS);
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
	//功能索引
	public int m_FuncIndex;
	public int FuncIndex
	{
		get { return m_FuncIndex;}
		set { m_FuncIndex = value; }
	}


};
//玩家功能预告请求封装类
[System.Serializable]
public class HumanRpcFuncNoticeChangeAskWraper
{

	//构造函数
	public HumanRpcFuncNoticeChangeAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public HumanRpcFuncNoticeChangeAsk ToPB()
	{
		HumanRpcFuncNoticeChangeAsk v = new HumanRpcFuncNoticeChangeAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcFuncNoticeChangeAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcFuncNoticeChangeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcFuncNoticeChangeAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcFuncNoticeChangeAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//玩家功能预告回应封装类
[System.Serializable]
public class HumanRpcFuncNoticeChangeReplyWraper
{

	//构造函数
	public HumanRpcFuncNoticeChangeReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcFuncNoticeChangeReply ToPB()
	{
		HumanRpcFuncNoticeChangeReply v = new HumanRpcFuncNoticeChangeReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcFuncNoticeChangeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcFuncNoticeChangeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcFuncNoticeChangeReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcFuncNoticeChangeReply>(protoMS);
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
//客户端属性双向通知通知封装类
[System.Serializable]
public class HumanRpcClientAttributesNotifyWraper
{

	//构造函数
	public HumanRpcClientAttributesNotifyWraper()
	{
		 m_ObjId = 0;
		 m_IsTouchJoyStick = false;
		 m_IsHold = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_IsTouchJoyStick = false;
		 m_IsHold = false;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcClientAttributesNotify ToPB()
	{
		HumanRpcClientAttributesNotify v = new HumanRpcClientAttributesNotify();
		v.ObjId = m_ObjId;
		v.IsTouchJoyStick = m_IsTouchJoyStick;
		v.IsHold = m_IsHold;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcClientAttributesNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_IsTouchJoyStick = v.IsTouchJoyStick;
		m_IsHold = v.IsHold;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcClientAttributesNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcClientAttributesNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcClientAttributesNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//摇杆
	public bool m_IsTouchJoyStick;
	public bool IsTouchJoyStick
	{
		get { return m_IsTouchJoyStick;}
		set { m_IsTouchJoyStick = value; }
	}
	//hold
	public bool m_IsHold;
	public bool IsHold
	{
		get { return m_IsHold;}
		set { m_IsHold = value; }
	}


};
//加速检测通知封装类
[System.Serializable]
public class HumanRpcTimeCheckNotifyWraper
{

	//构造函数
	public HumanRpcTimeCheckNotifyWraper()
	{
		 m_Data = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Data = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcTimeCheckNotify ToPB()
	{
		HumanRpcTimeCheckNotify v = new HumanRpcTimeCheckNotify();
		v.Data = m_Data;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcTimeCheckNotify v)
	{
        if (v == null)
            return;
		m_Data = v.Data;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcTimeCheckNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcTimeCheckNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcTimeCheckNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//随机数据
	public Int64 m_Data;
	public Int64 Data
	{
		get { return m_Data;}
		set { m_Data = value; }
	}


};
//移动标志刷新通知封装类
[System.Serializable]
public class HumanRpcMotionFlagsNotifyWraper
{

	//构造函数
	public HumanRpcMotionFlagsNotifyWraper()
	{
		 m_ObjId = 0;
		 m_MotionFlags = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_MotionFlags = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcMotionFlagsNotify ToPB()
	{
		HumanRpcMotionFlagsNotify v = new HumanRpcMotionFlagsNotify();
		v.ObjId = m_ObjId;
		v.MotionFlags = m_MotionFlags;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcMotionFlagsNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_MotionFlags = v.MotionFlags;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcMotionFlagsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcMotionFlagsNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcMotionFlagsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//对象ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//移动标记
	public int m_MotionFlags;
	public int MotionFlags
	{
		get { return m_MotionFlags;}
		set { m_MotionFlags = value; }
	}


};
//疾跑请求封装类
[System.Serializable]
public class HumanRpcRushAskWraper
{

	//构造函数
	public HumanRpcRushAskWraper()
	{
		 m_Apply = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Apply = false;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRushAsk ToPB()
	{
		HumanRpcRushAsk v = new HumanRpcRushAsk();
		v.Apply = m_Apply;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRushAsk v)
	{
        if (v == null)
            return;
		m_Apply = v.Apply;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRushAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRushAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcRushAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//开关
	public bool m_Apply;
	public bool Apply
	{
		get { return m_Apply;}
		set { m_Apply = value; }
	}


};
//疾跑回应封装类
[System.Serializable]
public class HumanRpcRushReplyWraper
{

	//构造函数
	public HumanRpcRushReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcRushReply ToPB()
	{
		HumanRpcRushReply v = new HumanRpcRushReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcRushReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcRushReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcRushReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcRushReply>(protoMS);
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
//盯防请求封装类
[System.Serializable]
public class HumanRpcStareAskWraper
{

	//构造函数
	public HumanRpcStareAskWraper()
	{
		 m_Apply = false;
		 m_TargetID = 0;
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Apply = false;
		 m_TargetID = 0;
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStareAsk ToPB()
	{
		HumanRpcStareAsk v = new HumanRpcStareAsk();
		v.Apply = m_Apply;
		v.TargetID = m_TargetID;
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcStareAsk v)
	{
        if (v == null)
            return;
		m_Apply = v.Apply;
		m_TargetID = v.TargetID;
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcStareAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcStareAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcStareAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//开关
	public bool m_Apply;
	public bool Apply
	{
		get { return m_Apply;}
		set { m_Apply = value; }
	}
	//目标对象ID
	public UInt64 m_TargetID;
	public UInt64 TargetID
	{
		get { return m_TargetID;}
		set { m_TargetID = value; }
	}
	//停止盯防时朝向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//盯防回应封装类
[System.Serializable]
public class HumanRpcStareReplyWraper
{

	//构造函数
	public HumanRpcStareReplyWraper()
	{
		 m_Result = -1;
		 m_TargetID = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TargetID = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcStareReply ToPB()
	{
		HumanRpcStareReply v = new HumanRpcStareReply();
		v.Result = m_Result;
		v.TargetID = m_TargetID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcStareReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TargetID = v.TargetID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcStareReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcStareReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcStareReply>(protoMS);
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
	//目标对象ID
	public UInt64 m_TargetID;
	public UInt64 TargetID
	{
		get { return m_TargetID;}
		set { m_TargetID = value; }
	}


};
//瞬移通知封装类
[System.Serializable]
public class HumanRpcChangePositionNotifyWraper
{

	//构造函数
	public HumanRpcChangePositionNotifyWraper()
	{
		 m_ObjID = 0;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjID = 0;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcChangePositionNotify ToPB()
	{
		HumanRpcChangePositionNotify v = new HumanRpcChangePositionNotify();
		v.ObjID = m_ObjID;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcChangePositionNotify v)
	{
        if (v == null)
            return;
		m_ObjID = v.ObjID;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcChangePositionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcChangePositionNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcChangePositionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//对象ID
	public UInt64 m_ObjID;
	public UInt64 ObjID
	{
		get { return m_ObjID;}
		set { m_ObjID = value; }
	}
	//坐标
	public Vector3IntWraper m_Pos;
	public Vector3IntWraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//属性变化值通知封装类
[System.Serializable]
public class HumanRpcAttrChangeNotifyWraper
{

	//构造函数
	public HumanRpcAttrChangeNotifyWraper()
	{
		 m_AttrType = -1;
		 m_Value = -1;
		 m_Playerguid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AttrType = -1;
		 m_Value = -1;
		 m_Playerguid = 0;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcAttrChangeNotify ToPB()
	{
		HumanRpcAttrChangeNotify v = new HumanRpcAttrChangeNotify();
		v.AttrType = m_AttrType;
		v.Value = m_Value;
		v.Playerguid = m_Playerguid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcAttrChangeNotify v)
	{
        if (v == null)
            return;
		m_AttrType = v.AttrType;
		m_Value = v.Value;
		m_Playerguid = v.Playerguid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcAttrChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcAttrChangeNotify pb = ProtoBuf.Serializer.Deserialize<HumanRpcAttrChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性类型
	public int m_AttrType;
	public int AttrType
	{
		get { return m_AttrType;}
		set { m_AttrType = value; }
	}
	//变化值
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}
	//playerguid
	public UInt64 m_Playerguid;
	public UInt64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}


};
//托管请求封装类
[System.Serializable]
public class HumanRpcTrusteeshipAskWraper
{

	//构造函数
	public HumanRpcTrusteeshipAskWraper()
	{
		 m_Open = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Open = false;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcTrusteeshipAsk ToPB()
	{
		HumanRpcTrusteeshipAsk v = new HumanRpcTrusteeshipAsk();
		v.Open = m_Open;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcTrusteeshipAsk v)
	{
        if (v == null)
            return;
		m_Open = v.Open;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcTrusteeshipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcTrusteeshipAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcTrusteeshipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//托管或者取消托管
	public bool m_Open;
	public bool Open
	{
		get { return m_Open;}
		set { m_Open = value; }
	}


};
//托管回应封装类
[System.Serializable]
public class HumanRpcTrusteeshipReplyWraper
{

	//构造函数
	public HumanRpcTrusteeshipReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcTrusteeshipReply ToPB()
	{
		HumanRpcTrusteeshipReply v = new HumanRpcTrusteeshipReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcTrusteeshipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcTrusteeshipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcTrusteeshipReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcTrusteeshipReply>(protoMS);
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
//改名请求封装类
[System.Serializable]
public class HumanRpcChangePlayerNameAskWraper
{

	//构造函数
	public HumanRpcChangePlayerNameAskWraper()
	{
		 m_PlayerName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PlayerName = "";

	}

 	//转化成Protobuffer类型函数
	public HumanRpcChangePlayerNameAsk ToPB()
	{
		HumanRpcChangePlayerNameAsk v = new HumanRpcChangePlayerNameAsk();
		v.PlayerName = m_PlayerName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcChangePlayerNameAsk v)
	{
        if (v == null)
            return;
		m_PlayerName = v.PlayerName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcChangePlayerNameAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcChangePlayerNameAsk pb = ProtoBuf.Serializer.Deserialize<HumanRpcChangePlayerNameAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//新名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}


};
//改名回应封装类
[System.Serializable]
public class HumanRpcChangePlayerNameReplyWraper
{

	//构造函数
	public HumanRpcChangePlayerNameReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public HumanRpcChangePlayerNameReply ToPB()
	{
		HumanRpcChangePlayerNameReply v = new HumanRpcChangePlayerNameReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(HumanRpcChangePlayerNameReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HumanRpcChangePlayerNameReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		HumanRpcChangePlayerNameReply pb = ProtoBuf.Serializer.Deserialize<HumanRpcChangePlayerNameReply>(protoMS);
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
