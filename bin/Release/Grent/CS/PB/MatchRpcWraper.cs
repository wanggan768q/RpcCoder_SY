
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBMatch.cs
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


//匹配请求封装类
[System.Serializable]
public class MatchRpcAutoMatchAskWraper
{

	//构造函数
	public MatchRpcAutoMatchAskWraper()
	{
		 m_MatchInfo = new PlayerMatchDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MatchInfo = new PlayerMatchDataWraper();

	}

 	//转化成Protobuffer类型函数
	public MatchRpcAutoMatchAsk ToPB()
	{
		MatchRpcAutoMatchAsk v = new MatchRpcAutoMatchAsk();
		v.MatchInfo = m_MatchInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcAutoMatchAsk v)
	{
        if (v == null)
            return;
		m_MatchInfo.FromPB(v.MatchInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcAutoMatchAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcAutoMatchAsk pb = ProtoBuf.Serializer.Deserialize<MatchRpcAutoMatchAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//匹配参数
	public PlayerMatchDataWraper m_MatchInfo;
	public PlayerMatchDataWraper MatchInfo
	{
		get { return m_MatchInfo;}
		set { m_MatchInfo = value; }
	}


};
//匹配回应封装类
[System.Serializable]
public class MatchRpcAutoMatchReplyWraper
{

	//构造函数
	public MatchRpcAutoMatchReplyWraper()
	{
		 m_Result = -1;
		 m_MatchInfo = new PlayerMatchDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_MatchInfo = new PlayerMatchDataWraper();

	}

 	//转化成Protobuffer类型函数
	public MatchRpcAutoMatchReply ToPB()
	{
		MatchRpcAutoMatchReply v = new MatchRpcAutoMatchReply();
		v.Result = m_Result;
		v.MatchInfo = m_MatchInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcAutoMatchReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_MatchInfo.FromPB(v.MatchInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcAutoMatchReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcAutoMatchReply pb = ProtoBuf.Serializer.Deserialize<MatchRpcAutoMatchReply>(protoMS);
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
	//匹配参数
	public PlayerMatchDataWraper m_MatchInfo;
	public PlayerMatchDataWraper MatchInfo
	{
		get { return m_MatchInfo;}
		set { m_MatchInfo = value; }
	}


};
//取消匹配请求封装类
[System.Serializable]
public class MatchRpcCancelMatchAskWraper
{

	//构造函数
	public MatchRpcCancelMatchAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MatchRpcCancelMatchAsk ToPB()
	{
		MatchRpcCancelMatchAsk v = new MatchRpcCancelMatchAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcCancelMatchAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcCancelMatchAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcCancelMatchAsk pb = ProtoBuf.Serializer.Deserialize<MatchRpcCancelMatchAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//取消匹配回应封装类
[System.Serializable]
public class MatchRpcCancelMatchReplyWraper
{

	//构造函数
	public MatchRpcCancelMatchReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcCancelMatchReply ToPB()
	{
		MatchRpcCancelMatchReply v = new MatchRpcCancelMatchReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcCancelMatchReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcCancelMatchReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcCancelMatchReply pb = ProtoBuf.Serializer.Deserialize<MatchRpcCancelMatchReply>(protoMS);
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
//取消匹配通知通知封装类
[System.Serializable]
public class MatchRpcCancelMatchNotifyNotifyWraper
{

	//构造函数
	public MatchRpcCancelMatchNotifyNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MatchRpcCancelMatchNotifyNotify ToPB()
	{
		MatchRpcCancelMatchNotifyNotify v = new MatchRpcCancelMatchNotifyNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcCancelMatchNotifyNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcCancelMatchNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcCancelMatchNotifyNotify pb = ProtoBuf.Serializer.Deserialize<MatchRpcCancelMatchNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//开始准备进入房间通知封装类
[System.Serializable]
public class MatchRpcPrepareRoomNotifyWraper
{

	//构造函数
	public MatchRpcPrepareRoomNotifyWraper()
	{
		 m_ReadyRoom = new PBMatchRoomWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ReadyRoom = new PBMatchRoomWraper();

	}

 	//转化成Protobuffer类型函数
	public MatchRpcPrepareRoomNotify ToPB()
	{
		MatchRpcPrepareRoomNotify v = new MatchRpcPrepareRoomNotify();
		v.ReadyRoom = m_ReadyRoom.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcPrepareRoomNotify v)
	{
        if (v == null)
            return;
		m_ReadyRoom.FromPB(v.ReadyRoom);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcPrepareRoomNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcPrepareRoomNotify pb = ProtoBuf.Serializer.Deserialize<MatchRpcPrepareRoomNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//准备界面
	public PBMatchRoomWraper m_ReadyRoom;
	public PBMatchRoomWraper ReadyRoom
	{
		get { return m_ReadyRoom;}
		set { m_ReadyRoom = value; }
	}


};
//准备请求封装类
[System.Serializable]
public class MatchRpcReadyAskWraper
{

	//构造函数
	public MatchRpcReadyAskWraper()
	{
		 m_MatchType = -1;
		 m_RoomId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MatchType = -1;
		 m_RoomId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcReadyAsk ToPB()
	{
		MatchRpcReadyAsk v = new MatchRpcReadyAsk();
		v.MatchType = m_MatchType;
		v.RoomId = m_RoomId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcReadyAsk v)
	{
        if (v == null)
            return;
		m_MatchType = v.MatchType;
		m_RoomId = v.RoomId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcReadyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcReadyAsk pb = ProtoBuf.Serializer.Deserialize<MatchRpcReadyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//匹配类型
	public int m_MatchType;
	public int MatchType
	{
		get { return m_MatchType;}
		set { m_MatchType = value; }
	}
	//房间的id
	public UInt64 m_RoomId;
	public UInt64 RoomId
	{
		get { return m_RoomId;}
		set { m_RoomId = value; }
	}


};
//准备回应封装类
[System.Serializable]
public class MatchRpcReadyReplyWraper
{

	//构造函数
	public MatchRpcReadyReplyWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcReadyReply ToPB()
	{
		MatchRpcReadyReply v = new MatchRpcReadyReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcReadyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcReadyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcReadyReply pb = ProtoBuf.Serializer.Deserialize<MatchRpcReadyReply>(protoMS);
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
	//玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//取消准备请求封装类
[System.Serializable]
public class MatchRpcCancelReadyAskWraper
{

	//构造函数
	public MatchRpcCancelReadyAskWraper()
	{
		 m_MatchType = -1;
		 m_RoomId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MatchType = -1;
		 m_RoomId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcCancelReadyAsk ToPB()
	{
		MatchRpcCancelReadyAsk v = new MatchRpcCancelReadyAsk();
		v.MatchType = m_MatchType;
		v.RoomId = m_RoomId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcCancelReadyAsk v)
	{
        if (v == null)
            return;
		m_MatchType = v.MatchType;
		m_RoomId = v.RoomId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcCancelReadyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcCancelReadyAsk pb = ProtoBuf.Serializer.Deserialize<MatchRpcCancelReadyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//匹配类型
	public int m_MatchType;
	public int MatchType
	{
		get { return m_MatchType;}
		set { m_MatchType = value; }
	}
	//房间的id
	public UInt64 m_RoomId;
	public UInt64 RoomId
	{
		get { return m_RoomId;}
		set { m_RoomId = value; }
	}


};
//取消准备回应封装类
[System.Serializable]
public class MatchRpcCancelReadyReplyWraper
{

	//构造函数
	public MatchRpcCancelReadyReplyWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcCancelReadyReply ToPB()
	{
		MatchRpcCancelReadyReply v = new MatchRpcCancelReadyReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcCancelReadyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcCancelReadyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcCancelReadyReply pb = ProtoBuf.Serializer.Deserialize<MatchRpcCancelReadyReply>(protoMS);
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
	//玩家Id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//房间取消通知封装类
[System.Serializable]
public class MatchRpcRoomCancelNotifyWraper
{

	//构造函数
	public MatchRpcRoomCancelNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MatchRpcRoomCancelNotify ToPB()
	{
		MatchRpcRoomCancelNotify v = new MatchRpcRoomCancelNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcRoomCancelNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcRoomCancelNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcRoomCancelNotify pb = ProtoBuf.Serializer.Deserialize<MatchRpcRoomCancelNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//成员准备通知封装类
[System.Serializable]
public class MatchRpcMemberReadyNotifyWraper
{

	//构造函数
	public MatchRpcMemberReadyNotifyWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRpcMemberReadyNotify ToPB()
	{
		MatchRpcMemberReadyNotify v = new MatchRpcMemberReadyNotify();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRpcMemberReadyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRpcMemberReadyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRpcMemberReadyNotify pb = ProtoBuf.Serializer.Deserialize<MatchRpcMemberReadyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//准备的玩家
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
