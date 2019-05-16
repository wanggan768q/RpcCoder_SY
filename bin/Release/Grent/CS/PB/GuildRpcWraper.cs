
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBGuild.cs
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


//公会基本信息请求封装类
[System.Serializable]
public class GuildRpcGuildBaseInfoAskWraper
{

	//构造函数
	public GuildRpcGuildBaseInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcGuildBaseInfoAsk ToPB()
	{
		GuildRpcGuildBaseInfoAsk v = new GuildRpcGuildBaseInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcGuildBaseInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcGuildBaseInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcGuildBaseInfoAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcGuildBaseInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//公会基本信息回应封装类
[System.Serializable]
public class GuildRpcGuildBaseInfoReplyWraper
{

	//构造函数
	public GuildRpcGuildBaseInfoReplyWraper()
	{
		 m_Result = -1;
		 m_GuildBaseInfo = new GuildInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildBaseInfo = new GuildInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcGuildBaseInfoReply ToPB()
	{
		GuildRpcGuildBaseInfoReply v = new GuildRpcGuildBaseInfoReply();
		v.Result = m_Result;
		v.GuildBaseInfo = m_GuildBaseInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcGuildBaseInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildBaseInfo.FromPB(v.GuildBaseInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcGuildBaseInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcGuildBaseInfoReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcGuildBaseInfoReply>(protoMS);
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
	//公会信息
	public GuildInfoWraper m_GuildBaseInfo;
	public GuildInfoWraper GuildBaseInfo
	{
		get { return m_GuildBaseInfo;}
		set { m_GuildBaseInfo = value; }
	}


};
//逐出成员请求封装类
[System.Serializable]
public class GuildRpcKickMemberAskWraper
{

	//构造函数
	public GuildRpcKickMemberAskWraper()
	{
		 m_Guid = -1;
		 m_KickReason = "";
		 m_ReasonType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = -1;
		 m_KickReason = "";
		 m_ReasonType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcKickMemberAsk ToPB()
	{
		GuildRpcKickMemberAsk v = new GuildRpcKickMemberAsk();
		v.Guid = m_Guid;
		v.KickReason = m_KickReason;
		v.ReasonType = m_ReasonType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcKickMemberAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_KickReason = v.KickReason;
		m_ReasonType = v.ReasonType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcKickMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcKickMemberAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcKickMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public int m_Guid;
	public int Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//逐出理由
	public string m_KickReason;
	public string KickReason
	{
		get { return m_KickReason;}
		set { m_KickReason = value; }
	}
	//理由枚举
	public int m_ReasonType;
	public int ReasonType
	{
		get { return m_ReasonType;}
		set { m_ReasonType = value; }
	}


};
//逐出成员回应封装类
[System.Serializable]
public class GuildRpcKickMemberReplyWraper
{

	//构造函数
	public GuildRpcKickMemberReplyWraper()
	{
		 m_Result = -1;
		 m_Guid = -1;
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Guid = -1;
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcKickMemberReply ToPB()
	{
		GuildRpcKickMemberReply v = new GuildRpcKickMemberReply();
		v.Result = m_Result;
		v.Guid = m_Guid;
		v.OnlineCount = m_OnlineCount;
		v.MemberCount = m_MemberCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcKickMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Guid = v.Guid;
		m_OnlineCount = v.OnlineCount;
		m_MemberCount = v.MemberCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcKickMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcKickMemberReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcKickMemberReply>(protoMS);
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
	//Guid
	public int m_Guid;
	public int Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//在线人数
	public int m_OnlineCount;
	public int OnlineCount
	{
		get { return m_OnlineCount;}
		set { m_OnlineCount = value; }
	}
	//成员数量
	public int m_MemberCount;
	public int MemberCount
	{
		get { return m_MemberCount;}
		set { m_MemberCount = value; }
	}


};
//逐出公会推送通知封装类
[System.Serializable]
public class GuildRpcKickMemberNotifyNotifyWraper
{

	//构造函数
	public GuildRpcKickMemberNotifyNotifyWraper()
	{
		 m_KickReason = "";
		 m_ReasonType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KickReason = "";
		 m_ReasonType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcKickMemberNotifyNotify ToPB()
	{
		GuildRpcKickMemberNotifyNotify v = new GuildRpcKickMemberNotifyNotify();
		v.KickReason = m_KickReason;
		v.ReasonType = m_ReasonType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcKickMemberNotifyNotify v)
	{
        if (v == null)
            return;
		m_KickReason = v.KickReason;
		m_ReasonType = v.ReasonType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcKickMemberNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcKickMemberNotifyNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcKickMemberNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//逐出理由
	public string m_KickReason;
	public string KickReason
	{
		get { return m_KickReason;}
		set { m_KickReason = value; }
	}
	//理由枚举
	public int m_ReasonType;
	public int ReasonType
	{
		get { return m_ReasonType;}
		set { m_ReasonType = value; }
	}


};
//请假或取消请求封装类
[System.Serializable]
public class GuildRpcAskVacationAskWraper
{

	//构造函数
	public GuildRpcAskVacationAskWraper()
	{
		 m_Guid = -1;
		 m_Reason = "";
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = -1;
		 m_Reason = "";
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskVacationAsk ToPB()
	{
		GuildRpcAskVacationAsk v = new GuildRpcAskVacationAsk();
		v.Guid = m_Guid;
		v.Reason = m_Reason;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskVacationAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Reason = v.Reason;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskVacationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskVacationAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskVacationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public int m_Guid;
	public int Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//请假理由
	public string m_Reason;
	public string Reason
	{
		get { return m_Reason;}
		set { m_Reason = value; }
	}
	//请假推送类型（1请假，2取消请假）
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//请假或取消回应封装类
[System.Serializable]
public class GuildRpcAskVacationReplyWraper
{

	//构造函数
	public GuildRpcAskVacationReplyWraper()
	{
		 m_Result = -1;
		 m_Guid = -1;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Guid = -1;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskVacationReply ToPB()
	{
		GuildRpcAskVacationReply v = new GuildRpcAskVacationReply();
		v.Result = m_Result;
		v.Guid = m_Guid;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskVacationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Guid = v.Guid;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskVacationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskVacationReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskVacationReply>(protoMS);
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
	//Guid
	public int m_Guid;
	public int Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//请假推送类型（1请假，2取消请假）
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//请假广播通知（广播给管理者）封装类
[System.Serializable]
public class GuildRpcVacationNotifyWraper
{

	//构造函数
	public GuildRpcVacationNotifyWraper()
	{
		 m_VacationInfo = new GuildVacationInfoWraper();
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_VacationInfo = new GuildVacationInfoWraper();
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcVacationNotify ToPB()
	{
		GuildRpcVacationNotify v = new GuildRpcVacationNotify();
		v.VacationInfo = m_VacationInfo.ToPB();
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcVacationNotify v)
	{
        if (v == null)
            return;
		m_VacationInfo.FromPB(v.VacationInfo);
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcVacationNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcVacationNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcVacationNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//请假信息
	public GuildVacationInfoWraper m_VacationInfo;
	public GuildVacationInfoWraper VacationInfo
	{
		get { return m_VacationInfo;}
		set { m_VacationInfo = value; }
	}
	//请假推送类型（1请假，2取消请假）
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//请假广播（广播给请假人）通知封装类
[System.Serializable]
public class GuildRpcReplyVacationNotifyWraper
{

	//构造函数
	public GuildRpcReplyVacationNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcReplyVacationNotify ToPB()
	{
		GuildRpcReplyVacationNotify v = new GuildRpcReplyVacationNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcReplyVacationNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcReplyVacationNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcReplyVacationNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcReplyVacationNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求公会申请列表请求封装类
[System.Serializable]
public class GuildRpcAskApplyListAskWraper
{

	//构造函数
	public GuildRpcAskApplyListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskApplyListAsk ToPB()
	{
		GuildRpcAskApplyListAsk v = new GuildRpcAskApplyListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskApplyListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskApplyListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskApplyListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskApplyListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求公会申请列表回应封装类
[System.Serializable]
public class GuildRpcAskApplyListReplyWraper
{

	//构造函数
	public GuildRpcAskApplyListReplyWraper()
	{
		 m_Result = -1;
		m_GuildMemberTinyInfoList = new List<GuildMemberTinyInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GuildMemberTinyInfoList = new List<GuildMemberTinyInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskApplyListReply ToPB()
	{
		GuildRpcAskApplyListReply v = new GuildRpcAskApplyListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GuildMemberTinyInfoList.Count; i++)
			v.GuildMemberTinyInfoList.Add( m_GuildMemberTinyInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskApplyListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildMemberTinyInfoList.Clear();
		for( int i=0; i<v.GuildMemberTinyInfoList.Count; i++)
			m_GuildMemberTinyInfoList.Add( new GuildMemberTinyInfoWraper());
		for( int i=0; i<v.GuildMemberTinyInfoList.Count; i++)
			m_GuildMemberTinyInfoList[i].FromPB(v.GuildMemberTinyInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskApplyListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskApplyListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskApplyListReply>(protoMS);
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
	//申请入会玩家简要信息列表
	public List<GuildMemberTinyInfoWraper> m_GuildMemberTinyInfoList;
	public int SizeGuildMemberTinyInfoList()
	{
		return m_GuildMemberTinyInfoList.Count;
	}
	public List<GuildMemberTinyInfoWraper> GetGuildMemberTinyInfoList()
	{
		return m_GuildMemberTinyInfoList;
	}
	public GuildMemberTinyInfoWraper GetGuildMemberTinyInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuildMemberTinyInfoList.Count)
			return new GuildMemberTinyInfoWraper();
		return m_GuildMemberTinyInfoList[Index];
	}
	public void SetGuildMemberTinyInfoList( List<GuildMemberTinyInfoWraper> v )
	{
		m_GuildMemberTinyInfoList=v;
	}
	public void SetGuildMemberTinyInfoList( int Index, GuildMemberTinyInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_GuildMemberTinyInfoList.Count)
			return;
		m_GuildMemberTinyInfoList[Index] = v;
	}
	public void AddGuildMemberTinyInfoList( GuildMemberTinyInfoWraper v )
	{
		m_GuildMemberTinyInfoList.Add(v);
	}
	public void ClearGuildMemberTinyInfoList( )
	{
		m_GuildMemberTinyInfoList.Clear();
	}


};
//入会操作请求封装类
[System.Serializable]
public class GuildRpcApplyGuildOperationAskWraper
{

	//构造函数
	public GuildRpcApplyGuildOperationAskWraper()
	{
		 m_Guid = 0;
		 m_Operation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_Operation = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyGuildOperationAsk ToPB()
	{
		GuildRpcApplyGuildOperationAsk v = new GuildRpcApplyGuildOperationAsk();
		v.Guid = m_Guid;
		v.Operation = m_Operation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyGuildOperationAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Operation = v.Operation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyGuildOperationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyGuildOperationAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyGuildOperationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	public int m_Operation;
	public int Operation
	{
		get { return m_Operation;}
		set { m_Operation = value; }
	}


};
//入会操作回应封装类
[System.Serializable]
public class GuildRpcApplyGuildOperationReplyWraper
{

	//构造函数
	public GuildRpcApplyGuildOperationReplyWraper()
	{
		 m_Result = -1;
		 m_Operation = -1;
		m_MemberInfoList = new List<GuildMemberInfoWraper>();
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Operation = -1;
		m_MemberInfoList = new List<GuildMemberInfoWraper>();
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyGuildOperationReply ToPB()
	{
		GuildRpcApplyGuildOperationReply v = new GuildRpcApplyGuildOperationReply();
		v.Result = m_Result;
		v.Operation = m_Operation;
		for (int i=0; i<(int)m_MemberInfoList.Count; i++)
			v.MemberInfoList.Add( m_MemberInfoList[i].ToPB());
		v.OnlineCount = m_OnlineCount;
		v.MemberCount = m_MemberCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyGuildOperationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Operation = v.Operation;
		m_MemberInfoList.Clear();
		for( int i=0; i<v.MemberInfoList.Count; i++)
			m_MemberInfoList.Add( new GuildMemberInfoWraper());
		for( int i=0; i<v.MemberInfoList.Count; i++)
			m_MemberInfoList[i].FromPB(v.MemberInfoList[i]);
		m_OnlineCount = v.OnlineCount;
		m_MemberCount = v.MemberCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyGuildOperationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyGuildOperationReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyGuildOperationReply>(protoMS);
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
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	public int m_Operation;
	public int Operation
	{
		get { return m_Operation;}
		set { m_Operation = value; }
	}
	//操作列表
	public List<GuildMemberInfoWraper> m_MemberInfoList;
	public int SizeMemberInfoList()
	{
		return m_MemberInfoList.Count;
	}
	public List<GuildMemberInfoWraper> GetMemberInfoList()
	{
		return m_MemberInfoList;
	}
	public GuildMemberInfoWraper GetMemberInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_MemberInfoList.Count)
			return new GuildMemberInfoWraper();
		return m_MemberInfoList[Index];
	}
	public void SetMemberInfoList( List<GuildMemberInfoWraper> v )
	{
		m_MemberInfoList=v;
	}
	public void SetMemberInfoList( int Index, GuildMemberInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_MemberInfoList.Count)
			return;
		m_MemberInfoList[Index] = v;
	}
	public void AddMemberInfoList( GuildMemberInfoWraper v )
	{
		m_MemberInfoList.Add(v);
	}
	public void ClearMemberInfoList( )
	{
		m_MemberInfoList.Clear();
	}
	//在线人数
	public int m_OnlineCount;
	public int OnlineCount
	{
		get { return m_OnlineCount;}
		set { m_OnlineCount = value; }
	}
	//成员数量
	public int m_MemberCount;
	public int MemberCount
	{
		get { return m_MemberCount;}
		set { m_MemberCount = value; }
	}


};
//申请入会推送（推送给申请者）通知封装类
[System.Serializable]
public class GuildRpcApplyGuildNotifyWraper
{

	//构造函数
	public GuildRpcApplyGuildNotifyWraper()
	{
		 m_GuildID = 0;
		 m_GuildName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildID = 0;
		 m_GuildName = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyGuildNotify ToPB()
	{
		GuildRpcApplyGuildNotify v = new GuildRpcApplyGuildNotify();
		v.GuildID = m_GuildID;
		v.GuildName = m_GuildName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyGuildNotify v)
	{
        if (v == null)
            return;
		m_GuildID = v.GuildID;
		m_GuildName = v.GuildName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyGuildNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyGuildNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyGuildNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会ID
	public UInt64 m_GuildID;
	public UInt64 GuildID
	{
		get { return m_GuildID;}
		set { m_GuildID = value; }
	}
	//公会名字
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}


};
//限制入会条件请求封装类
[System.Serializable]
public class GuildRpcApplyLimitSettingAskWraper
{

	//构造函数
	public GuildRpcApplyLimitSettingAskWraper()
	{
		 m_IsAutoJoin = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_IsAutoJoin = false;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyLimitSettingAsk ToPB()
	{
		GuildRpcApplyLimitSettingAsk v = new GuildRpcApplyLimitSettingAsk();
		v.IsAutoJoin = m_IsAutoJoin;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyLimitSettingAsk v)
	{
        if (v == null)
            return;
		m_IsAutoJoin = v.IsAutoJoin;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyLimitSettingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyLimitSettingAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyLimitSettingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//是否允许自动入会
	public bool m_IsAutoJoin;
	public bool IsAutoJoin
	{
		get { return m_IsAutoJoin;}
		set { m_IsAutoJoin = value; }
	}


};
//限制入会条件回应封装类
[System.Serializable]
public class GuildRpcApplyLimitSettingReplyWraper
{

	//构造函数
	public GuildRpcApplyLimitSettingReplyWraper()
	{
		 m_Result = -1;
		 m_IsAutoJoin = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_IsAutoJoin = false;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyLimitSettingReply ToPB()
	{
		GuildRpcApplyLimitSettingReply v = new GuildRpcApplyLimitSettingReply();
		v.Result = m_Result;
		v.IsAutoJoin = m_IsAutoJoin;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyLimitSettingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_IsAutoJoin = v.IsAutoJoin;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyLimitSettingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyLimitSettingReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyLimitSettingReply>(protoMS);
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
	//是否允许自动入会
	public bool m_IsAutoJoin;
	public bool IsAutoJoin
	{
		get { return m_IsAutoJoin;}
		set { m_IsAutoJoin = value; }
	}


};
//权限列表申请请求封装类
[System.Serializable]
public class GuildRpcAskJurisdictionListAskWraper
{

	//构造函数
	public GuildRpcAskJurisdictionListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskJurisdictionListAsk ToPB()
	{
		GuildRpcAskJurisdictionListAsk v = new GuildRpcAskJurisdictionListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskJurisdictionListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskJurisdictionListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskJurisdictionListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskJurisdictionListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//权限列表申请回应封装类
[System.Serializable]
public class GuildRpcAskJurisdictionListReplyWraper
{

	//构造函数
	public GuildRpcAskJurisdictionListReplyWraper()
	{
		 m_Result = -1;
		m_JurisdictionList = new List<GuildOfficeJurisdictionWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_JurisdictionList = new List<GuildOfficeJurisdictionWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskJurisdictionListReply ToPB()
	{
		GuildRpcAskJurisdictionListReply v = new GuildRpcAskJurisdictionListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_JurisdictionList.Count; i++)
			v.JurisdictionList.Add( m_JurisdictionList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskJurisdictionListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JurisdictionList.Clear();
		for( int i=0; i<v.JurisdictionList.Count; i++)
			m_JurisdictionList.Add( new GuildOfficeJurisdictionWraper());
		for( int i=0; i<v.JurisdictionList.Count; i++)
			m_JurisdictionList[i].FromPB(v.JurisdictionList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskJurisdictionListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskJurisdictionListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskJurisdictionListReply>(protoMS);
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
	//权限列表
	public List<GuildOfficeJurisdictionWraper> m_JurisdictionList;
	public int SizeJurisdictionList()
	{
		return m_JurisdictionList.Count;
	}
	public List<GuildOfficeJurisdictionWraper> GetJurisdictionList()
	{
		return m_JurisdictionList;
	}
	public GuildOfficeJurisdictionWraper GetJurisdictionList(int Index)
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.Count)
			return new GuildOfficeJurisdictionWraper();
		return m_JurisdictionList[Index];
	}
	public void SetJurisdictionList( List<GuildOfficeJurisdictionWraper> v )
	{
		m_JurisdictionList=v;
	}
	public void SetJurisdictionList( int Index, GuildOfficeJurisdictionWraper v )
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.Count)
			return;
		m_JurisdictionList[Index] = v;
	}
	public void AddJurisdictionList( GuildOfficeJurisdictionWraper v )
	{
		m_JurisdictionList.Add(v);
	}
	public void ClearJurisdictionList( )
	{
		m_JurisdictionList.Clear();
	}


};
//设置权限请求封装类
[System.Serializable]
public class GuildRpcSetJurisdictionAskWraper
{

	//构造函数
	public GuildRpcSetJurisdictionAskWraper()
	{
		 m_SetList = new GuildOfficeJurisdictionWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SetList = new GuildOfficeJurisdictionWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSetJurisdictionAsk ToPB()
	{
		GuildRpcSetJurisdictionAsk v = new GuildRpcSetJurisdictionAsk();
		v.SetList = m_SetList.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSetJurisdictionAsk v)
	{
        if (v == null)
            return;
		m_SetList.FromPB(v.SetList);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSetJurisdictionAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSetJurisdictionAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcSetJurisdictionAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//权限列表
	public GuildOfficeJurisdictionWraper m_SetList;
	public GuildOfficeJurisdictionWraper SetList
	{
		get { return m_SetList;}
		set { m_SetList = value; }
	}


};
//设置权限回应封装类
[System.Serializable]
public class GuildRpcSetJurisdictionReplyWraper
{

	//构造函数
	public GuildRpcSetJurisdictionReplyWraper()
	{
		 m_Result = -1;
		 m_SetList = new GuildOfficeJurisdictionWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_SetList = new GuildOfficeJurisdictionWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSetJurisdictionReply ToPB()
	{
		GuildRpcSetJurisdictionReply v = new GuildRpcSetJurisdictionReply();
		v.Result = m_Result;
		v.SetList = m_SetList.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSetJurisdictionReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SetList.FromPB(v.SetList);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSetJurisdictionReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSetJurisdictionReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcSetJurisdictionReply>(protoMS);
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
	//权限列表
	public GuildOfficeJurisdictionWraper m_SetList;
	public GuildOfficeJurisdictionWraper SetList
	{
		get { return m_SetList;}
		set { m_SetList = value; }
	}


};
//请假审批列表请求封装类
[System.Serializable]
public class GuildRpcAskVacationListAskWraper
{

	//构造函数
	public GuildRpcAskVacationListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskVacationListAsk ToPB()
	{
		GuildRpcAskVacationListAsk v = new GuildRpcAskVacationListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskVacationListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskVacationListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskVacationListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskVacationListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请假审批列表回应封装类
[System.Serializable]
public class GuildRpcAskVacationListReplyWraper
{

	//构造函数
	public GuildRpcAskVacationListReplyWraper()
	{
		 m_Result = -1;
		m_VacationList = new List<GuildVacationInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_VacationList = new List<GuildVacationInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskVacationListReply ToPB()
	{
		GuildRpcAskVacationListReply v = new GuildRpcAskVacationListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_VacationList.Count; i++)
			v.VacationList.Add( m_VacationList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskVacationListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_VacationList.Clear();
		for( int i=0; i<v.VacationList.Count; i++)
			m_VacationList.Add( new GuildVacationInfoWraper());
		for( int i=0; i<v.VacationList.Count; i++)
			m_VacationList[i].FromPB(v.VacationList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskVacationListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskVacationListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskVacationListReply>(protoMS);
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
	//请假列表
	public List<GuildVacationInfoWraper> m_VacationList;
	public int SizeVacationList()
	{
		return m_VacationList.Count;
	}
	public List<GuildVacationInfoWraper> GetVacationList()
	{
		return m_VacationList;
	}
	public GuildVacationInfoWraper GetVacationList(int Index)
	{
		if(Index<0 || Index>=(int)m_VacationList.Count)
			return new GuildVacationInfoWraper();
		return m_VacationList[Index];
	}
	public void SetVacationList( List<GuildVacationInfoWraper> v )
	{
		m_VacationList=v;
	}
	public void SetVacationList( int Index, GuildVacationInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_VacationList.Count)
			return;
		m_VacationList[Index] = v;
	}
	public void AddVacationList( GuildVacationInfoWraper v )
	{
		m_VacationList.Add(v);
	}
	public void ClearVacationList( )
	{
		m_VacationList.Clear();
	}


};
//请假操作请求封装类
[System.Serializable]
public class GuildRpcVacationGuildOperationAskWraper
{

	//构造函数
	public GuildRpcVacationGuildOperationAskWraper()
	{
		 m_Guid = 0;
		 m_Operation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_Operation = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcVacationGuildOperationAsk ToPB()
	{
		GuildRpcVacationGuildOperationAsk v = new GuildRpcVacationGuildOperationAsk();
		v.Guid = m_Guid;
		v.Operation = m_Operation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcVacationGuildOperationAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Operation = v.Operation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcVacationGuildOperationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcVacationGuildOperationAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcVacationGuildOperationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	public int m_Operation;
	public int Operation
	{
		get { return m_Operation;}
		set { m_Operation = value; }
	}


};
//请假操作回应封装类
[System.Serializable]
public class GuildRpcVacationGuildOperationReplyWraper
{

	//构造函数
	public GuildRpcVacationGuildOperationReplyWraper()
	{
		 m_Result = -1;
		 m_Guid = 0;
		 m_Operation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Guid = 0;
		 m_Operation = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcVacationGuildOperationReply ToPB()
	{
		GuildRpcVacationGuildOperationReply v = new GuildRpcVacationGuildOperationReply();
		v.Result = m_Result;
		v.Guid = m_Guid;
		v.Operation = m_Operation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcVacationGuildOperationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Guid = v.Guid;
		m_Operation = v.Operation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcVacationGuildOperationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcVacationGuildOperationReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcVacationGuildOperationReply>(protoMS);
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
	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	public int m_Operation;
	public int Operation
	{
		get { return m_Operation;}
		set { m_Operation = value; }
	}


};
//申请推送（广播给管理者）通知封装类
[System.Serializable]
public class GuildRpcApplyGuildToOfficeNotifyWraper
{

	//构造函数
	public GuildRpcApplyGuildToOfficeNotifyWraper()
	{
		 m_GuildMemberTinyInfo = new GuildMemberTinyInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildMemberTinyInfo = new GuildMemberTinyInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcApplyGuildToOfficeNotify ToPB()
	{
		GuildRpcApplyGuildToOfficeNotify v = new GuildRpcApplyGuildToOfficeNotify();
		v.GuildMemberTinyInfo = m_GuildMemberTinyInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcApplyGuildToOfficeNotify v)
	{
        if (v == null)
            return;
		m_GuildMemberTinyInfo.FromPB(v.GuildMemberTinyInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcApplyGuildToOfficeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcApplyGuildToOfficeNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcApplyGuildToOfficeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//申请入会玩家信息
	public GuildMemberTinyInfoWraper m_GuildMemberTinyInfo;
	public GuildMemberTinyInfoWraper GuildMemberTinyInfo
	{
		get { return m_GuildMemberTinyInfo;}
		set { m_GuildMemberTinyInfo = value; }
	}


};
//请求公会建筑信息请求封装类
[System.Serializable]
public class GuildRpcAskBuildingInfoAskWraper
{

	//构造函数
	public GuildRpcAskBuildingInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskBuildingInfoAsk ToPB()
	{
		GuildRpcAskBuildingInfoAsk v = new GuildRpcAskBuildingInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskBuildingInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskBuildingInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskBuildingInfoAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskBuildingInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求公会建筑信息回应封装类
[System.Serializable]
public class GuildRpcAskBuildingInfoReplyWraper
{

	//构造函数
	public GuildRpcAskBuildingInfoReplyWraper()
	{
		 m_Result = -1;
		m_BuildingInfoList = new List<GuildBuildingInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_BuildingInfoList = new List<GuildBuildingInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskBuildingInfoReply ToPB()
	{
		GuildRpcAskBuildingInfoReply v = new GuildRpcAskBuildingInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_BuildingInfoList.Count; i++)
			v.BuildingInfoList.Add( m_BuildingInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskBuildingInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_BuildingInfoList.Clear();
		for( int i=0; i<v.BuildingInfoList.Count; i++)
			m_BuildingInfoList.Add( new GuildBuildingInfoWraper());
		for( int i=0; i<v.BuildingInfoList.Count; i++)
			m_BuildingInfoList[i].FromPB(v.BuildingInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskBuildingInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskBuildingInfoReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskBuildingInfoReply>(protoMS);
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
	//公会建筑信息列表
	public List<GuildBuildingInfoWraper> m_BuildingInfoList;
	public int SizeBuildingInfoList()
	{
		return m_BuildingInfoList.Count;
	}
	public List<GuildBuildingInfoWraper> GetBuildingInfoList()
	{
		return m_BuildingInfoList;
	}
	public GuildBuildingInfoWraper GetBuildingInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_BuildingInfoList.Count)
			return new GuildBuildingInfoWraper();
		return m_BuildingInfoList[Index];
	}
	public void SetBuildingInfoList( List<GuildBuildingInfoWraper> v )
	{
		m_BuildingInfoList=v;
	}
	public void SetBuildingInfoList( int Index, GuildBuildingInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_BuildingInfoList.Count)
			return;
		m_BuildingInfoList[Index] = v;
	}
	public void AddBuildingInfoList( GuildBuildingInfoWraper v )
	{
		m_BuildingInfoList.Add(v);
	}
	public void ClearBuildingInfoList( )
	{
		m_BuildingInfoList.Clear();
	}


};
//公会建筑升级请求封装类
[System.Serializable]
public class GuildRpcBuildingLvUpAskWraper
{

	//构造函数
	public GuildRpcBuildingLvUpAskWraper()
	{
		 m_BuildingType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuildingType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildingLvUpAsk ToPB()
	{
		GuildRpcBuildingLvUpAsk v = new GuildRpcBuildingLvUpAsk();
		v.BuildingType = m_BuildingType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildingLvUpAsk v)
	{
        if (v == null)
            return;
		m_BuildingType = v.BuildingType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildingLvUpAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildingLvUpAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildingLvUpAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}


};
//公会建筑升级回应封装类
[System.Serializable]
public class GuildRpcBuildingLvUpReplyWraper
{

	//构造函数
	public GuildRpcBuildingLvUpReplyWraper()
	{
		 m_Result = -1;
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();
		 m_GuildMoney = -1;
		 m_GuildResource = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();
		 m_GuildMoney = -1;
		 m_GuildResource = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildingLvUpReply ToPB()
	{
		GuildRpcBuildingLvUpReply v = new GuildRpcBuildingLvUpReply();
		v.Result = m_Result;
		v.GuildBuildingInfo = m_GuildBuildingInfo.ToPB();
		v.GuildMoney = m_GuildMoney;
		v.GuildResource = m_GuildResource;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildingLvUpReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildBuildingInfo.FromPB(v.GuildBuildingInfo);
		m_GuildMoney = v.GuildMoney;
		m_GuildResource = v.GuildResource;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildingLvUpReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildingLvUpReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildingLvUpReply>(protoMS);
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
	//公会建筑信息
	public GuildBuildingInfoWraper m_GuildBuildingInfo;
	public GuildBuildingInfoWraper GuildBuildingInfo
	{
		get { return m_GuildBuildingInfo;}
		set { m_GuildBuildingInfo = value; }
	}
	//公会资金
	public int m_GuildMoney;
	public int GuildMoney
	{
		get { return m_GuildMoney;}
		set { m_GuildMoney = value; }
	}
	//公会资源
	public int m_GuildResource;
	public int GuildResource
	{
		get { return m_GuildResource;}
		set { m_GuildResource = value; }
	}


};
//公会建筑加速升级请求封装类
[System.Serializable]
public class GuildRpcBuildingLvSpeedUpAskWraper
{

	//构造函数
	public GuildRpcBuildingLvSpeedUpAskWraper()
	{
		 m_BuildingType = -1;
		 m_Time = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuildingType = -1;
		 m_Time = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildingLvSpeedUpAsk ToPB()
	{
		GuildRpcBuildingLvSpeedUpAsk v = new GuildRpcBuildingLvSpeedUpAsk();
		v.BuildingType = m_BuildingType;
		v.Time = m_Time;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildingLvSpeedUpAsk v)
	{
        if (v == null)
            return;
		m_BuildingType = v.BuildingType;
		m_Time = v.Time;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildingLvSpeedUpAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildingLvSpeedUpAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildingLvSpeedUpAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}
	//加速时间
	public int m_Time;
	public int Time
	{
		get { return m_Time;}
		set { m_Time = value; }
	}


};
//公会建筑加速升级回应封装类
[System.Serializable]
public class GuildRpcBuildingLvSpeedUpReplyWraper
{

	//构造函数
	public GuildRpcBuildingLvSpeedUpReplyWraper()
	{
		 m_Result = -1;
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildingLvSpeedUpReply ToPB()
	{
		GuildRpcBuildingLvSpeedUpReply v = new GuildRpcBuildingLvSpeedUpReply();
		v.Result = m_Result;
		v.GuildBuildingInfo = m_GuildBuildingInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildingLvSpeedUpReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildBuildingInfo.FromPB(v.GuildBuildingInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildingLvSpeedUpReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildingLvSpeedUpReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildingLvSpeedUpReply>(protoMS);
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
	//公会建筑信息
	public GuildBuildingInfoWraper m_GuildBuildingInfo;
	public GuildBuildingInfoWraper GuildBuildingInfo
	{
		get { return m_GuildBuildingInfo;}
		set { m_GuildBuildingInfo = value; }
	}


};
//建筑贡献榜请求请求封装类
[System.Serializable]
public class GuildRpcAskBuildingContributionListAskWraper
{

	//构造函数
	public GuildRpcAskBuildingContributionListAskWraper()
	{
		 m_BuildingType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuildingType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskBuildingContributionListAsk ToPB()
	{
		GuildRpcAskBuildingContributionListAsk v = new GuildRpcAskBuildingContributionListAsk();
		v.BuildingType = m_BuildingType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskBuildingContributionListAsk v)
	{
        if (v == null)
            return;
		m_BuildingType = v.BuildingType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskBuildingContributionListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskBuildingContributionListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskBuildingContributionListAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}


};
//建筑贡献榜请求回应封装类
[System.Serializable]
public class GuildRpcAskBuildingContributionListReplyWraper
{

	//构造函数
	public GuildRpcAskBuildingContributionListReplyWraper()
	{
		 m_Result = -1;
		m_ContributionList = new List<GuildBuildingContributionInfoWraper>();
		 m_BuildingType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContributionList = new List<GuildBuildingContributionInfoWraper>();
		 m_BuildingType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskBuildingContributionListReply ToPB()
	{
		GuildRpcAskBuildingContributionListReply v = new GuildRpcAskBuildingContributionListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContributionList.Count; i++)
			v.ContributionList.Add( m_ContributionList[i].ToPB());
		v.BuildingType = m_BuildingType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskBuildingContributionListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContributionList.Clear();
		for( int i=0; i<v.ContributionList.Count; i++)
			m_ContributionList.Add( new GuildBuildingContributionInfoWraper());
		for( int i=0; i<v.ContributionList.Count; i++)
			m_ContributionList[i].FromPB(v.ContributionList[i]);
		m_BuildingType = v.BuildingType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskBuildingContributionListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskBuildingContributionListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskBuildingContributionListReply>(protoMS);
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
	//贡献榜列表
	public List<GuildBuildingContributionInfoWraper> m_ContributionList;
	public int SizeContributionList()
	{
		return m_ContributionList.Count;
	}
	public List<GuildBuildingContributionInfoWraper> GetContributionList()
	{
		return m_ContributionList;
	}
	public GuildBuildingContributionInfoWraper GetContributionList(int Index)
	{
		if(Index<0 || Index>=(int)m_ContributionList.Count)
			return new GuildBuildingContributionInfoWraper();
		return m_ContributionList[Index];
	}
	public void SetContributionList( List<GuildBuildingContributionInfoWraper> v )
	{
		m_ContributionList=v;
	}
	public void SetContributionList( int Index, GuildBuildingContributionInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ContributionList.Count)
			return;
		m_ContributionList[Index] = v;
	}
	public void AddContributionList( GuildBuildingContributionInfoWraper v )
	{
		m_ContributionList.Add(v);
	}
	public void ClearContributionList( )
	{
		m_ContributionList.Clear();
	}
	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}


};
//建筑可升级推送（推送管理者）通知封装类
[System.Serializable]
public class GuildRpcBuildingCanLvUpNotifyWraper
{

	//构造函数
	public GuildRpcBuildingCanLvUpNotifyWraper()
	{
		 m_BuildingType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuildingType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildingCanLvUpNotify ToPB()
	{
		GuildRpcBuildingCanLvUpNotify v = new GuildRpcBuildingCanLvUpNotify();
		v.BuildingType = m_BuildingType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildingCanLvUpNotify v)
	{
        if (v == null)
            return;
		m_BuildingType = v.BuildingType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildingCanLvUpNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildingCanLvUpNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildingCanLvUpNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}


};
//获取公会事件列表请求封装类
[System.Serializable]
public class GuildRpcAskGuildEventListAskWraper
{

	//构造函数
	public GuildRpcAskGuildEventListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildEventListAsk ToPB()
	{
		GuildRpcAskGuildEventListAsk v = new GuildRpcAskGuildEventListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildEventListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildEventListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildEventListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildEventListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//获取公会事件列表回应封装类
[System.Serializable]
public class GuildRpcAskGuildEventListReplyWraper
{

	//构造函数
	public GuildRpcAskGuildEventListReplyWraper()
	{
		 m_Result = -1;
		m_GuildEventList = new List<GuildEventWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GuildEventList = new List<GuildEventWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildEventListReply ToPB()
	{
		GuildRpcAskGuildEventListReply v = new GuildRpcAskGuildEventListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GuildEventList.Count; i++)
			v.GuildEventList.Add( m_GuildEventList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildEventListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildEventList.Clear();
		for( int i=0; i<v.GuildEventList.Count; i++)
			m_GuildEventList.Add( new GuildEventWraper());
		for( int i=0; i<v.GuildEventList.Count; i++)
			m_GuildEventList[i].FromPB(v.GuildEventList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildEventListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildEventListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildEventListReply>(protoMS);
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
	//公会事件列表
	public List<GuildEventWraper> m_GuildEventList;
	public int SizeGuildEventList()
	{
		return m_GuildEventList.Count;
	}
	public List<GuildEventWraper> GetGuildEventList()
	{
		return m_GuildEventList;
	}
	public GuildEventWraper GetGuildEventList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuildEventList.Count)
			return new GuildEventWraper();
		return m_GuildEventList[Index];
	}
	public void SetGuildEventList( List<GuildEventWraper> v )
	{
		m_GuildEventList=v;
	}
	public void SetGuildEventList( int Index, GuildEventWraper v )
	{
		if(Index<0 || Index>=(int)m_GuildEventList.Count)
			return;
		m_GuildEventList[Index] = v;
	}
	public void AddGuildEventList( GuildEventWraper v )
	{
		m_GuildEventList.Add(v);
	}
	public void ClearGuildEventList( )
	{
		m_GuildEventList.Clear();
	}


};
//获取公会列表请求封装类
[System.Serializable]
public class GuildRpcAskGuildInfoListAskWraper
{

	//构造函数
	public GuildRpcAskGuildInfoListAskWraper()
	{
		 m_PageIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PageIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildInfoListAsk ToPB()
	{
		GuildRpcAskGuildInfoListAsk v = new GuildRpcAskGuildInfoListAsk();
		v.PageIndex = m_PageIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildInfoListAsk v)
	{
        if (v == null)
            return;
		m_PageIndex = v.PageIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildInfoListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildInfoListAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildInfoListAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//页码（索引从1开始）
	public int m_PageIndex;
	public int PageIndex
	{
		get { return m_PageIndex;}
		set { m_PageIndex = value; }
	}


};
//获取公会列表回应封装类
[System.Serializable]
public class GuildRpcAskGuildInfoListReplyWraper
{

	//构造函数
	public GuildRpcAskGuildInfoListReplyWraper()
	{
		 m_Result = -1;
		m_GuildInfoList = new List<GuildInfoWraper>();
		 m_PageIndex = -1;
		 m_TotalGuildCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GuildInfoList = new List<GuildInfoWraper>();
		 m_PageIndex = -1;
		 m_TotalGuildCount = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildInfoListReply ToPB()
	{
		GuildRpcAskGuildInfoListReply v = new GuildRpcAskGuildInfoListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GuildInfoList.Count; i++)
			v.GuildInfoList.Add( m_GuildInfoList[i].ToPB());
		v.PageIndex = m_PageIndex;
		v.TotalGuildCount = m_TotalGuildCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildInfoListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildInfoList.Clear();
		for( int i=0; i<v.GuildInfoList.Count; i++)
			m_GuildInfoList.Add( new GuildInfoWraper());
		for( int i=0; i<v.GuildInfoList.Count; i++)
			m_GuildInfoList[i].FromPB(v.GuildInfoList[i]);
		m_PageIndex = v.PageIndex;
		m_TotalGuildCount = v.TotalGuildCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildInfoListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildInfoListReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildInfoListReply>(protoMS);
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
	//公会信息列表
	public List<GuildInfoWraper> m_GuildInfoList;
	public int SizeGuildInfoList()
	{
		return m_GuildInfoList.Count;
	}
	public List<GuildInfoWraper> GetGuildInfoList()
	{
		return m_GuildInfoList;
	}
	public GuildInfoWraper GetGuildInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.Count)
			return new GuildInfoWraper();
		return m_GuildInfoList[Index];
	}
	public void SetGuildInfoList( List<GuildInfoWraper> v )
	{
		m_GuildInfoList=v;
	}
	public void SetGuildInfoList( int Index, GuildInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.Count)
			return;
		m_GuildInfoList[Index] = v;
	}
	public void AddGuildInfoList( GuildInfoWraper v )
	{
		m_GuildInfoList.Add(v);
	}
	public void ClearGuildInfoList( )
	{
		m_GuildInfoList.Clear();
	}
	//页码（索引从1开始）
	public int m_PageIndex;
	public int PageIndex
	{
		get { return m_PageIndex;}
		set { m_PageIndex = value; }
	}
	//本服务器公会总数
	public int m_TotalGuildCount;
	public int TotalGuildCount
	{
		get { return m_TotalGuildCount;}
		set { m_TotalGuildCount = value; }
	}


};
//搜索公会请求封装类
[System.Serializable]
public class GuildRpcSearchGuildAskWraper
{

	//构造函数
	public GuildRpcSearchGuildAskWraper()
	{
		 m_Text = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Text = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSearchGuildAsk ToPB()
	{
		GuildRpcSearchGuildAsk v = new GuildRpcSearchGuildAsk();
		v.Text = m_Text;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSearchGuildAsk v)
	{
        if (v == null)
            return;
		m_Text = v.Text;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSearchGuildAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSearchGuildAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcSearchGuildAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//输入的文本
	public string m_Text;
	public string Text
	{
		get { return m_Text;}
		set { m_Text = value; }
	}


};
//搜索公会回应封装类
[System.Serializable]
public class GuildRpcSearchGuildReplyWraper
{

	//构造函数
	public GuildRpcSearchGuildReplyWraper()
	{
		 m_Result = -1;
		m_GuildInfoList = new List<GuildInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GuildInfoList = new List<GuildInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSearchGuildReply ToPB()
	{
		GuildRpcSearchGuildReply v = new GuildRpcSearchGuildReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GuildInfoList.Count; i++)
			v.GuildInfoList.Add( m_GuildInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSearchGuildReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildInfoList.Clear();
		for( int i=0; i<v.GuildInfoList.Count; i++)
			m_GuildInfoList.Add( new GuildInfoWraper());
		for( int i=0; i<v.GuildInfoList.Count; i++)
			m_GuildInfoList[i].FromPB(v.GuildInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSearchGuildReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSearchGuildReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcSearchGuildReply>(protoMS);
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
	//查找后的公会列表
	public List<GuildInfoWraper> m_GuildInfoList;
	public int SizeGuildInfoList()
	{
		return m_GuildInfoList.Count;
	}
	public List<GuildInfoWraper> GetGuildInfoList()
	{
		return m_GuildInfoList;
	}
	public GuildInfoWraper GetGuildInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.Count)
			return new GuildInfoWraper();
		return m_GuildInfoList[Index];
	}
	public void SetGuildInfoList( List<GuildInfoWraper> v )
	{
		m_GuildInfoList=v;
	}
	public void SetGuildInfoList( int Index, GuildInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.Count)
			return;
		m_GuildInfoList[Index] = v;
	}
	public void AddGuildInfoList( GuildInfoWraper v )
	{
		m_GuildInfoList.Add(v);
	}
	public void ClearGuildInfoList( )
	{
		m_GuildInfoList.Clear();
	}


};
//申请入会请求封装类
[System.Serializable]
public class GuildRpcJoinGuildAskWraper
{

	//构造函数
	public GuildRpcJoinGuildAskWraper()
	{
		 m_Guid = 0;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcJoinGuildAsk ToPB()
	{
		GuildRpcJoinGuildAsk v = new GuildRpcJoinGuildAsk();
		v.Guid = m_Guid;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcJoinGuildAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcJoinGuildAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcJoinGuildAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcJoinGuildAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//1申请，2一键加入
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//申请入会回应封装类
[System.Serializable]
public class GuildRpcJoinGuildReplyWraper
{

	//构造函数
	public GuildRpcJoinGuildReplyWraper()
	{
		 m_Result = -1;
		 m_Guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Guid = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcJoinGuildReply ToPB()
	{
		GuildRpcJoinGuildReply v = new GuildRpcJoinGuildReply();
		v.Result = m_Result;
		v.Guid = m_Guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcJoinGuildReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Guid = v.Guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcJoinGuildReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcJoinGuildReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcJoinGuildReply>(protoMS);
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
	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}


};
//建立公会请求封装类
[System.Serializable]
public class GuildRpcCreateGuildAskWraper
{

	//构造函数
	public GuildRpcCreateGuildAskWraper()
	{
		 m_GuildName = "";
		 m_GuildCreed = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildName = "";
		 m_GuildCreed = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcCreateGuildAsk ToPB()
	{
		GuildRpcCreateGuildAsk v = new GuildRpcCreateGuildAsk();
		v.GuildName = m_GuildName;
		v.GuildCreed = m_GuildCreed;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcCreateGuildAsk v)
	{
        if (v == null)
            return;
		m_GuildName = v.GuildName;
		m_GuildCreed = v.GuildCreed;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcCreateGuildAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcCreateGuildAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcCreateGuildAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会名称
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//公会宗旨
	public string m_GuildCreed;
	public string GuildCreed
	{
		get { return m_GuildCreed;}
		set { m_GuildCreed = value; }
	}


};
//建立公会回应封装类
[System.Serializable]
public class GuildRpcCreateGuildReplyWraper
{

	//构造函数
	public GuildRpcCreateGuildReplyWraper()
	{
		 m_Result = -1;
		 m_GuildBaseInfo = new GuildInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildBaseInfo = new GuildInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcCreateGuildReply ToPB()
	{
		GuildRpcCreateGuildReply v = new GuildRpcCreateGuildReply();
		v.Result = m_Result;
		v.GuildBaseInfo = m_GuildBaseInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcCreateGuildReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildBaseInfo.FromPB(v.GuildBaseInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcCreateGuildReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcCreateGuildReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcCreateGuildReply>(protoMS);
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
	//公会信息
	public GuildInfoWraper m_GuildBaseInfo;
	public GuildInfoWraper GuildBaseInfo
	{
		get { return m_GuildBaseInfo;}
		set { m_GuildBaseInfo = value; }
	}


};
//更换公会旗帜请求封装类
[System.Serializable]
public class GuildRpcChangeFlagAskWraper
{

	//构造函数
	public GuildRpcChangeFlagAskWraper()
	{
		 m_FlagConfigID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FlagConfigID = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcChangeFlagAsk ToPB()
	{
		GuildRpcChangeFlagAsk v = new GuildRpcChangeFlagAsk();
		v.FlagConfigID = m_FlagConfigID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcChangeFlagAsk v)
	{
        if (v == null)
            return;
		m_FlagConfigID = v.FlagConfigID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcChangeFlagAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcChangeFlagAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcChangeFlagAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//旗帜ID
	public int m_FlagConfigID;
	public int FlagConfigID
	{
		get { return m_FlagConfigID;}
		set { m_FlagConfigID = value; }
	}


};
//更换公会旗帜回应封装类
[System.Serializable]
public class GuildRpcChangeFlagReplyWraper
{

	//构造函数
	public GuildRpcChangeFlagReplyWraper()
	{
		 m_Result = -1;
		 m_GuildMoney = -1;
		 m_Flag = new GuildFlagWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildMoney = -1;
		 m_Flag = new GuildFlagWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcChangeFlagReply ToPB()
	{
		GuildRpcChangeFlagReply v = new GuildRpcChangeFlagReply();
		v.Result = m_Result;
		v.GuildMoney = m_GuildMoney;
		v.Flag = m_Flag.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcChangeFlagReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildMoney = v.GuildMoney;
		m_Flag.FromPB(v.Flag);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcChangeFlagReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcChangeFlagReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcChangeFlagReply>(protoMS);
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
	//公会资金
	public int m_GuildMoney;
	public int GuildMoney
	{
		get { return m_GuildMoney;}
		set { m_GuildMoney = value; }
	}
	//公会旗帜
	public GuildFlagWraper m_Flag;
	public GuildFlagWraper Flag
	{
		get { return m_Flag;}
		set { m_Flag = value; }
	}


};
//公会改名请求封装类
[System.Serializable]
public class GuildRpcGuildChangeNameAskWraper
{

	//构造函数
	public GuildRpcGuildChangeNameAskWraper()
	{
		 m_GuildNewName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildNewName = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcGuildChangeNameAsk ToPB()
	{
		GuildRpcGuildChangeNameAsk v = new GuildRpcGuildChangeNameAsk();
		v.GuildNewName = m_GuildNewName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcGuildChangeNameAsk v)
	{
        if (v == null)
            return;
		m_GuildNewName = v.GuildNewName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcGuildChangeNameAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcGuildChangeNameAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcGuildChangeNameAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会新名字
	public string m_GuildNewName;
	public string GuildNewName
	{
		get { return m_GuildNewName;}
		set { m_GuildNewName = value; }
	}


};
//公会改名回应封装类
[System.Serializable]
public class GuildRpcGuildChangeNameReplyWraper
{

	//构造函数
	public GuildRpcGuildChangeNameReplyWraper()
	{
		 m_Result = -1;
		 m_GuildNewName = "";
		 m_GuildOldName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GuildNewName = "";
		 m_GuildOldName = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcGuildChangeNameReply ToPB()
	{
		GuildRpcGuildChangeNameReply v = new GuildRpcGuildChangeNameReply();
		v.Result = m_Result;
		v.GuildNewName = m_GuildNewName;
		v.GuildOldName = m_GuildOldName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcGuildChangeNameReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildNewName = v.GuildNewName;
		m_GuildOldName = v.GuildOldName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcGuildChangeNameReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcGuildChangeNameReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcGuildChangeNameReply>(protoMS);
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
	//公会新名字
	public string m_GuildNewName;
	public string GuildNewName
	{
		get { return m_GuildNewName;}
		set { m_GuildNewName = value; }
	}
	//曾用名
	public string m_GuildOldName;
	public string GuildOldName
	{
		get { return m_GuildOldName;}
		set { m_GuildOldName = value; }
	}


};
//获取公会成员列表请求封装类
[System.Serializable]
public class GuildRpcAskGuildMemberAskWraper
{

	//构造函数
	public GuildRpcAskGuildMemberAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildMemberAsk ToPB()
	{
		GuildRpcAskGuildMemberAsk v = new GuildRpcAskGuildMemberAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildMemberAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildMemberAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//获取公会成员列表回应封装类
[System.Serializable]
public class GuildRpcAskGuildMemberReplyWraper
{

	//构造函数
	public GuildRpcAskGuildMemberReplyWraper()
	{
		 m_Result = -1;
		m_GuildMemberInfoList = new List<GuildMemberInfoWraper>();
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GuildMemberInfoList = new List<GuildMemberInfoWraper>();
		 m_OnlineCount = -1;
		 m_MemberCount = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcAskGuildMemberReply ToPB()
	{
		GuildRpcAskGuildMemberReply v = new GuildRpcAskGuildMemberReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GuildMemberInfoList.Count; i++)
			v.GuildMemberInfoList.Add( m_GuildMemberInfoList[i].ToPB());
		v.OnlineCount = m_OnlineCount;
		v.MemberCount = m_MemberCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcAskGuildMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GuildMemberInfoList.Clear();
		for( int i=0; i<v.GuildMemberInfoList.Count; i++)
			m_GuildMemberInfoList.Add( new GuildMemberInfoWraper());
		for( int i=0; i<v.GuildMemberInfoList.Count; i++)
			m_GuildMemberInfoList[i].FromPB(v.GuildMemberInfoList[i]);
		m_OnlineCount = v.OnlineCount;
		m_MemberCount = v.MemberCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcAskGuildMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcAskGuildMemberReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcAskGuildMemberReply>(protoMS);
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
	//公会成员列表信息
	public List<GuildMemberInfoWraper> m_GuildMemberInfoList;
	public int SizeGuildMemberInfoList()
	{
		return m_GuildMemberInfoList.Count;
	}
	public List<GuildMemberInfoWraper> GetGuildMemberInfoList()
	{
		return m_GuildMemberInfoList;
	}
	public GuildMemberInfoWraper GetGuildMemberInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuildMemberInfoList.Count)
			return new GuildMemberInfoWraper();
		return m_GuildMemberInfoList[Index];
	}
	public void SetGuildMemberInfoList( List<GuildMemberInfoWraper> v )
	{
		m_GuildMemberInfoList=v;
	}
	public void SetGuildMemberInfoList( int Index, GuildMemberInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_GuildMemberInfoList.Count)
			return;
		m_GuildMemberInfoList[Index] = v;
	}
	public void AddGuildMemberInfoList( GuildMemberInfoWraper v )
	{
		m_GuildMemberInfoList.Add(v);
	}
	public void ClearGuildMemberInfoList( )
	{
		m_GuildMemberInfoList.Clear();
	}
	//在线人数
	public int m_OnlineCount;
	public int OnlineCount
	{
		get { return m_OnlineCount;}
		set { m_OnlineCount = value; }
	}
	//成员数量
	public int m_MemberCount;
	public int MemberCount
	{
		get { return m_MemberCount;}
		set { m_MemberCount = value; }
	}


};
//退出公会请求封装类
[System.Serializable]
public class GuildRpcQuiteGuildAskWraper
{

	//构造函数
	public GuildRpcQuiteGuildAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GuildRpcQuiteGuildAsk ToPB()
	{
		GuildRpcQuiteGuildAsk v = new GuildRpcQuiteGuildAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcQuiteGuildAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcQuiteGuildAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcQuiteGuildAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcQuiteGuildAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//退出公会回应封装类
[System.Serializable]
public class GuildRpcQuiteGuildReplyWraper
{

	//构造函数
	public GuildRpcQuiteGuildReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcQuiteGuildReply ToPB()
	{
		GuildRpcQuiteGuildReply v = new GuildRpcQuiteGuildReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcQuiteGuildReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcQuiteGuildReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcQuiteGuildReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcQuiteGuildReply>(protoMS);
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
//设置职位请求封装类
[System.Serializable]
public class GuildRpcSetOfficeAskWraper
{

	//构造函数
	public GuildRpcSetOfficeAskWraper()
	{
		 m_Guid = 0;
		 m_TargetGuid = 0;
		 m_OfficeType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_TargetGuid = 0;
		 m_OfficeType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSetOfficeAsk ToPB()
	{
		GuildRpcSetOfficeAsk v = new GuildRpcSetOfficeAsk();
		v.Guid = m_Guid;
		v.TargetGuid = m_TargetGuid;
		v.OfficeType = m_OfficeType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSetOfficeAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_TargetGuid = v.TargetGuid;
		m_OfficeType = v.OfficeType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSetOfficeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSetOfficeAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcSetOfficeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//guid
	public UInt64 m_TargetGuid;
	public UInt64 TargetGuid
	{
		get { return m_TargetGuid;}
		set { m_TargetGuid = value; }
	}
	//职位枚举
	public int m_OfficeType;
	public int OfficeType
	{
		get { return m_OfficeType;}
		set { m_OfficeType = value; }
	}


};
//设置职位回应封装类
[System.Serializable]
public class GuildRpcSetOfficeReplyWraper
{

	//构造函数
	public GuildRpcSetOfficeReplyWraper()
	{
		 m_Result = -1;
		 m_SelfOfficeType = -1;
		 m_TargetOfficeType = -1;
		 m_TargetGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_SelfOfficeType = -1;
		 m_TargetOfficeType = -1;
		 m_TargetGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcSetOfficeReply ToPB()
	{
		GuildRpcSetOfficeReply v = new GuildRpcSetOfficeReply();
		v.Result = m_Result;
		v.SelfOfficeType = m_SelfOfficeType;
		v.TargetOfficeType = m_TargetOfficeType;
		v.TargetGuid = m_TargetGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcSetOfficeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SelfOfficeType = v.SelfOfficeType;
		m_TargetOfficeType = v.TargetOfficeType;
		m_TargetGuid = v.TargetGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcSetOfficeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcSetOfficeReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcSetOfficeReply>(protoMS);
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
	//自己的职位枚举
	public int m_SelfOfficeType;
	public int SelfOfficeType
	{
		get { return m_SelfOfficeType;}
		set { m_SelfOfficeType = value; }
	}
	//目标人的职位枚举
	public int m_TargetOfficeType;
	public int TargetOfficeType
	{
		get { return m_TargetOfficeType;}
		set { m_TargetOfficeType = value; }
	}
	//guid
	public UInt64 m_TargetGuid;
	public UInt64 TargetGuid
	{
		get { return m_TargetGuid;}
		set { m_TargetGuid = value; }
	}


};
//职位变化推送通知封装类
[System.Serializable]
public class GuildRpcOfficeChangeNotifyWraper
{

	//构造函数
	public GuildRpcOfficeChangeNotifyWraper()
	{
		 m_OfficeType = -1;
		 m_Optguid = 0;
		 m_OptOfficeType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OfficeType = -1;
		 m_Optguid = 0;
		 m_OptOfficeType = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcOfficeChangeNotify ToPB()
	{
		GuildRpcOfficeChangeNotify v = new GuildRpcOfficeChangeNotify();
		v.OfficeType = m_OfficeType;
		v.Optguid = m_Optguid;
		v.OptOfficeType = m_OptOfficeType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcOfficeChangeNotify v)
	{
        if (v == null)
            return;
		m_OfficeType = v.OfficeType;
		m_Optguid = v.Optguid;
		m_OptOfficeType = v.OptOfficeType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcOfficeChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcOfficeChangeNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcOfficeChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//职位枚举
	public int m_OfficeType;
	public int OfficeType
	{
		get { return m_OfficeType;}
		set { m_OfficeType = value; }
	}
	//委任者ID
	public UInt64 m_Optguid;
	public UInt64 Optguid
	{
		get { return m_Optguid;}
		set { m_Optguid = value; }
	}
	//委任者职位
	public int m_OptOfficeType;
	public int OptOfficeType
	{
		get { return m_OptOfficeType;}
		set { m_OptOfficeType = value; }
	}


};
//修改帮会宗旨请求封装类
[System.Serializable]
public class GuildRpcChangeCreedAskWraper
{

	//构造函数
	public GuildRpcChangeCreedAskWraper()
	{
		 m_Content = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Content = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcChangeCreedAsk ToPB()
	{
		GuildRpcChangeCreedAsk v = new GuildRpcChangeCreedAsk();
		v.Content = m_Content;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcChangeCreedAsk v)
	{
        if (v == null)
            return;
		m_Content = v.Content;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcChangeCreedAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcChangeCreedAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcChangeCreedAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//宗旨内容
	public string m_Content;
	public string Content
	{
		get { return m_Content;}
		set { m_Content = value; }
	}


};
//修改帮会宗旨回应封装类
[System.Serializable]
public class GuildRpcChangeCreedReplyWraper
{

	//构造函数
	public GuildRpcChangeCreedReplyWraper()
	{
		 m_Result = -1;
		 m_Content = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Content = "";

	}

 	//转化成Protobuffer类型函数
	public GuildRpcChangeCreedReply ToPB()
	{
		GuildRpcChangeCreedReply v = new GuildRpcChangeCreedReply();
		v.Result = m_Result;
		v.Content = m_Content;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcChangeCreedReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Content = v.Content;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcChangeCreedReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcChangeCreedReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcChangeCreedReply>(protoMS);
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
	//宗旨内容
	public string m_Content;
	public string Content
	{
		get { return m_Content;}
		set { m_Content = value; }
	}


};
//公会禁言请求封装类
[System.Serializable]
public class GuildRpcForbiddenChatAskWraper
{

	//构造函数
	public GuildRpcForbiddenChatAskWraper()
	{
		 m_Playerguid = -1;
		 m_IsForbidden = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Playerguid = -1;
		 m_IsForbidden = false;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcForbiddenChatAsk ToPB()
	{
		GuildRpcForbiddenChatAsk v = new GuildRpcForbiddenChatAsk();
		v.Playerguid = m_Playerguid;
		v.IsForbidden = m_IsForbidden;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcForbiddenChatAsk v)
	{
        if (v == null)
            return;
		m_Playerguid = v.Playerguid;
		m_IsForbidden = v.IsForbidden;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcForbiddenChatAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcForbiddenChatAsk pb = ProtoBuf.Serializer.Deserialize<GuildRpcForbiddenChatAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//playerguid
	public Int64 m_Playerguid;
	public Int64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//禁言
	public bool m_IsForbidden;
	public bool IsForbidden
	{
		get { return m_IsForbidden;}
		set { m_IsForbidden = value; }
	}


};
//公会禁言回应封装类
[System.Serializable]
public class GuildRpcForbiddenChatReplyWraper
{

	//构造函数
	public GuildRpcForbiddenChatReplyWraper()
	{
		 m_Result = -1;
		 m_Playerguid = -1;
		 m_IsForbidden = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Playerguid = -1;
		 m_IsForbidden = false;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcForbiddenChatReply ToPB()
	{
		GuildRpcForbiddenChatReply v = new GuildRpcForbiddenChatReply();
		v.Result = m_Result;
		v.Playerguid = m_Playerguid;
		v.IsForbidden = m_IsForbidden;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcForbiddenChatReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Playerguid = v.Playerguid;
		m_IsForbidden = v.IsForbidden;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcForbiddenChatReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcForbiddenChatReply pb = ProtoBuf.Serializer.Deserialize<GuildRpcForbiddenChatReply>(protoMS);
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
	//playerguid
	public Int64 m_Playerguid;
	public Int64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//禁言
	public bool m_IsForbidden;
	public bool IsForbidden
	{
		get { return m_IsForbidden;}
		set { m_IsForbidden = value; }
	}


};
//建筑升级完成通知封装类
[System.Serializable]
public class GuildRpcBuildLvUpCompleteNotifyWraper
{

	//构造函数
	public GuildRpcBuildLvUpCompleteNotifyWraper()
	{
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildBuildingInfo = new GuildBuildingInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildRpcBuildLvUpCompleteNotify ToPB()
	{
		GuildRpcBuildLvUpCompleteNotify v = new GuildRpcBuildLvUpCompleteNotify();
		v.GuildBuildingInfo = m_GuildBuildingInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcBuildLvUpCompleteNotify v)
	{
        if (v == null)
            return;
		m_GuildBuildingInfo.FromPB(v.GuildBuildingInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcBuildLvUpCompleteNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcBuildLvUpCompleteNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcBuildLvUpCompleteNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会建筑信息
	public GuildBuildingInfoWraper m_GuildBuildingInfo;
	public GuildBuildingInfoWraper GuildBuildingInfo
	{
		get { return m_GuildBuildingInfo;}
		set { m_GuildBuildingInfo = value; }
	}


};
//公会货币变化推送通知封装类
[System.Serializable]
public class GuildRpcGuildCurrencyChangeNotifyWraper
{

	//构造函数
	public GuildRpcGuildCurrencyChangeNotifyWraper()
	{
		 m_GuildProsper = -1;
		 m_GuildMoney = -1;
		 m_GuildResource = -1;
		 m_GuildWelfare = -1;
		 m_MaintainCost = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GuildProsper = -1;
		 m_GuildMoney = -1;
		 m_GuildResource = -1;
		 m_GuildWelfare = -1;
		 m_MaintainCost = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildRpcGuildCurrencyChangeNotify ToPB()
	{
		GuildRpcGuildCurrencyChangeNotify v = new GuildRpcGuildCurrencyChangeNotify();
		v.GuildProsper = m_GuildProsper;
		v.GuildMoney = m_GuildMoney;
		v.GuildResource = m_GuildResource;
		v.GuildWelfare = m_GuildWelfare;
		v.MaintainCost = m_MaintainCost;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildRpcGuildCurrencyChangeNotify v)
	{
        if (v == null)
            return;
		m_GuildProsper = v.GuildProsper;
		m_GuildMoney = v.GuildMoney;
		m_GuildResource = v.GuildResource;
		m_GuildWelfare = v.GuildWelfare;
		m_MaintainCost = v.MaintainCost;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildRpcGuildCurrencyChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildRpcGuildCurrencyChangeNotify pb = ProtoBuf.Serializer.Deserialize<GuildRpcGuildCurrencyChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会繁荣度
	public int m_GuildProsper;
	public int GuildProsper
	{
		get { return m_GuildProsper;}
		set { m_GuildProsper = value; }
	}
	//公会资金
	public int m_GuildMoney;
	public int GuildMoney
	{
		get { return m_GuildMoney;}
		set { m_GuildMoney = value; }
	}
	//公会资源
	public int m_GuildResource;
	public int GuildResource
	{
		get { return m_GuildResource;}
		set { m_GuildResource = value; }
	}
	//公会福利
	public int m_GuildWelfare;
	public int GuildWelfare
	{
		get { return m_GuildWelfare;}
		set { m_GuildWelfare = value; }
	}
	//维护费用
	public int m_MaintainCost;
	public int MaintainCost
	{
		get { return m_MaintainCost;}
		set { m_MaintainCost = value; }
	}


};
