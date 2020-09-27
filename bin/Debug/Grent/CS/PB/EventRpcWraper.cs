
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEvent.cs
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


//ObjMove通知封装类
[System.Serializable]
public class EventRpcMoveNotifyWraper
{

	//构造函数
	public EventRpcMoveNotifyWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcMoveNotify ToPB()
	{
		EventRpcMoveNotify v = new EventRpcMoveNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcMoveNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcMoveNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcMoveNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcMoveNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
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
//ObjStopMove通知封装类
[System.Serializable]
public class EventRpcStopMoveNotifyWraper
{

	//构造函数
	public EventRpcStopMoveNotifyWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_Type = -1;
		 m_BrakeRush = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3IntWraper();
		 m_Dir = (float)-1;
		 m_Type = -1;
		 m_BrakeRush = false;

	}

 	//转化成Protobuffer类型函数
	public EventRpcStopMoveNotify ToPB()
	{
		EventRpcStopMoveNotify v = new EventRpcStopMoveNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.Type = m_Type;
		v.BrakeRush = m_BrakeRush;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcStopMoveNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;
		m_Type = v.Type;
		m_BrakeRush = v.BrakeRush;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcStopMoveNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcStopMoveNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcStopMoveNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
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
	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//刹停
	public bool m_BrakeRush;
	public bool BrakeRush
	{
		get { return m_BrakeRush;}
		set { m_BrakeRush = value; }
	}


};
//属性改变通知封装类
[System.Serializable]
public class EventRpcObjAttrChangeNotifyWraper
{

	//构造函数
	public EventRpcObjAttrChangeNotifyWraper()
	{
		 m_Speed = (float)-1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_ConfigId = -1;
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Speed = (float)-1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_ConfigId = -1;
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public EventRpcObjAttrChangeNotify ToPB()
	{
		EventRpcObjAttrChangeNotify v = new EventRpcObjAttrChangeNotify();
		v.Speed = m_Speed;
		v.Hp = m_Hp;
		v.Status = m_Status;
		v.ConfigId = m_ConfigId;
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcObjAttrChangeNotify v)
	{
        if (v == null)
            return;
		m_Speed = v.Speed;
		m_Hp = v.Hp;
		m_Status = v.Status;
		m_ConfigId = v.ConfigId;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcObjAttrChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcObjAttrChangeNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcObjAttrChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//speed
	public float m_Speed;
	public float Speed
	{
		get { return m_Speed;}
		set { m_Speed = value; }
	}
	//Hp
	public Int64 m_Hp;
	public Int64 Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//NpcId改变
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//对象id
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//货币的变化通知通知封装类
[System.Serializable]
public class EventRpcCoinChangeNotifyWraper
{

	//构造函数
	public EventRpcCoinChangeNotifyWraper()
	{
		 m_Type = -1;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcCoinChangeNotify ToPB()
	{
		EventRpcCoinChangeNotify v = new EventRpcCoinChangeNotify();
		v.Type = m_Type;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcCoinChangeNotify v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcCoinChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcCoinChangeNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcCoinChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//值
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//按点移动通知封装类
[System.Serializable]
public class EventRpcMovePosNotifyWraper
{

	//构造函数
	public EventRpcMovePosNotifyWraper()
	{
		 m_ObjId = 0;
		m_PosList = new List<Vector3IntWraper>();
		 m_Dir = (float)-1;
		 m_IsAllowChangeRunAnimation = true;
		 m_Follow = -1;
		 m_IsLookAtMoving = true;
		 m_FromX = -1;
		 m_FromZ = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		m_PosList = new List<Vector3IntWraper>();
		 m_Dir = (float)-1;
		 m_IsAllowChangeRunAnimation = true;
		 m_Follow = -1;
		 m_IsLookAtMoving = true;
		 m_FromX = -1;
		 m_FromZ = -1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcMovePosNotify ToPB()
	{
		EventRpcMovePosNotify v = new EventRpcMovePosNotify();
		v.ObjId = m_ObjId;
		for (int i=0; i<(int)m_PosList.Count; i++)
			v.PosList.Add( m_PosList[i].ToPB());
		v.Dir = m_Dir;
		v.IsAllowChangeRunAnimation = m_IsAllowChangeRunAnimation;
		v.Follow = m_Follow;
		v.IsLookAtMoving = m_IsLookAtMoving;
		v.FromX = m_FromX;
		v.FromZ = m_FromZ;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcMovePosNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_PosList.Clear();
		for( int i=0; i<v.PosList.Count; i++)
			m_PosList.Add( new Vector3IntWraper());
		for( int i=0; i<v.PosList.Count; i++)
			m_PosList[i].FromPB(v.PosList[i]);
		m_Dir = v.Dir;
		m_IsAllowChangeRunAnimation = v.IsAllowChangeRunAnimation;
		m_Follow = v.Follow;
		m_IsLookAtMoving = v.IsLookAtMoving;
		m_FromX = v.FromX;
		m_FromZ = v.FromZ;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcMovePosNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcMovePosNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcMovePosNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
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
	//是否允许切换Run动画
	public bool m_IsAllowChangeRunAnimation;
	public bool IsAllowChangeRunAnimation
	{
		get { return m_IsAllowChangeRunAnimation;}
		set { m_IsAllowChangeRunAnimation = value; }
	}
	//是否跟随状态
	public int m_Follow;
	public int Follow
	{
		get { return m_Follow;}
		set { m_Follow = value; }
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
//朝向通知封装类
[System.Serializable]
public class EventRpcDirNotifyWraper
{

	//构造函数
	public EventRpcDirNotifyWraper()
	{
		 m_ObjId = 0;
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcDirNotify ToPB()
	{
		EventRpcDirNotify v = new EventRpcDirNotify();
		v.ObjId = m_ObjId;
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcDirNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcDirNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcDirNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcDirNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//objId
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//朝向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
//开始淡出效果通知封装类
[System.Serializable]
public class EventRpcStartFadeoutNotifyWraper
{

	//构造函数
	public EventRpcStartFadeoutNotifyWraper()
	{
		 m_ObjId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;

	}

 	//转化成Protobuffer类型函数
	public EventRpcStartFadeoutNotify ToPB()
	{
		EventRpcStartFadeoutNotify v = new EventRpcStartFadeoutNotify();
		v.ObjId = m_ObjId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcStartFadeoutNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcStartFadeoutNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcStartFadeoutNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcStartFadeoutNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjGuid
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}


};
//通知表演开始通知封装类
[System.Serializable]
public class EventRpcCinematicStartNotifyWraper
{

	//构造函数
	public EventRpcCinematicStartNotifyWraper()
	{
		 m_Text = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Text = -1;

	}

 	//转化成Protobuffer类型函数
	public EventRpcCinematicStartNotify ToPB()
	{
		EventRpcCinematicStartNotify v = new EventRpcCinematicStartNotify();
		v.Text = m_Text;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcCinematicStartNotify v)
	{
        if (v == null)
            return;
		m_Text = v.Text;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcCinematicStartNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcCinematicStartNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcCinematicStartNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//Text
	public int m_Text;
	public int Text
	{
		get { return m_Text;}
		set { m_Text = value; }
	}


};
//通知表演结束通知封装类
[System.Serializable]
public class EventRpcCinematicEndNotifyWraper
{

	//构造函数
	public EventRpcCinematicEndNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EventRpcCinematicEndNotify ToPB()
	{
		EventRpcCinematicEndNotify v = new EventRpcCinematicEndNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EventRpcCinematicEndNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EventRpcCinematicEndNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EventRpcCinematicEndNotify pb = ProtoBuf.Serializer.Deserialize<EventRpcCinematicEndNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
