
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBWG.cs
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


//InformJoinTeam请求封装类
[System.Serializable]
public class WGRpcInformJoinTeamAskWraper
{

	//构造函数
	public WGRpcInformJoinTeamAskWraper()
	{
		 m_Member = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Member = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformJoinTeamAsk ToPB()
	{
		WGRpcInformJoinTeamAsk v = new WGRpcInformJoinTeamAsk();
		v.Member = m_Member.ToPB();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformJoinTeamAsk v)
	{
        if (v == null)
            return;
		m_Member.FromPB(v.Member);
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformJoinTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformJoinTeamAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformJoinTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamMember
	public TeamMemberInfoWraper m_Member;
	public TeamMemberInfoWraper Member
	{
		get { return m_Member;}
		set { m_Member = value; }
	}
	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//InformJoinTeam回应封装类
[System.Serializable]
public class WGRpcInformJoinTeamReplyWraper
{

	//构造函数
	public WGRpcInformJoinTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformJoinTeamReply ToPB()
	{
		WGRpcInformJoinTeamReply v = new WGRpcInformJoinTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformJoinTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformJoinTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformJoinTeamReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformJoinTeamReply>(protoMS);
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
//InformLeave请求封装类
[System.Serializable]
public class WGRpcInformLeaveAskWraper
{

	//构造函数
	public WGRpcInformLeaveAskWraper()
	{
		 m_RoleId = 0;
		 m_NewLeaderRoleId = 0;
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_NewLeaderRoleId = 0;
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformLeaveAsk ToPB()
	{
		WGRpcInformLeaveAsk v = new WGRpcInformLeaveAsk();
		v.RoleId = m_RoleId;
		v.NewLeaderRoleId = m_NewLeaderRoleId;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformLeaveAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_NewLeaderRoleId = v.NewLeaderRoleId;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformLeaveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformLeaveAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformLeaveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//NewLeader
	public UInt64 m_NewLeaderRoleId;
	public UInt64 NewLeaderRoleId
	{
		get { return m_NewLeaderRoleId;}
		set { m_NewLeaderRoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//InformLeave回应封装类
[System.Serializable]
public class WGRpcInformLeaveReplyWraper
{

	//构造函数
	public WGRpcInformLeaveReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformLeaveReply ToPB()
	{
		WGRpcInformLeaveReply v = new WGRpcInformLeaveReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformLeaveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformLeaveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformLeaveReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformLeaveReply>(protoMS);
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
//InformAppointTeamLeader请求封装类
[System.Serializable]
public class WGRpcInformAppointTeamLeaderAskWraper
{

	//构造函数
	public WGRpcInformAppointTeamLeaderAskWraper()
	{
		 m_Result = -9999;
		 m_NewLeaderRoleId = 0;
		 m_OldLeaderRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_NewLeaderRoleId = 0;
		 m_OldLeaderRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformAppointTeamLeaderAsk ToPB()
	{
		WGRpcInformAppointTeamLeaderAsk v = new WGRpcInformAppointTeamLeaderAsk();
		v.Result = m_Result;
		v.NewLeaderRoleId = m_NewLeaderRoleId;
		v.OldLeaderRoleId = m_OldLeaderRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformAppointTeamLeaderAsk v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewLeaderRoleId = v.NewLeaderRoleId;
		m_OldLeaderRoleId = v.OldLeaderRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformAppointTeamLeaderAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformAppointTeamLeaderAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformAppointTeamLeaderAsk>(protoMS);
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
	//RoleId
	public UInt64 m_NewLeaderRoleId;
	public UInt64 NewLeaderRoleId
	{
		get { return m_NewLeaderRoleId;}
		set { m_NewLeaderRoleId = value; }
	}
	//OldLeaderRoleId
	public UInt64 m_OldLeaderRoleId;
	public UInt64 OldLeaderRoleId
	{
		get { return m_OldLeaderRoleId;}
		set { m_OldLeaderRoleId = value; }
	}


};
//InformAppointTeamLeader回应封装类
[System.Serializable]
public class WGRpcInformAppointTeamLeaderReplyWraper
{

	//构造函数
	public WGRpcInformAppointTeamLeaderReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformAppointTeamLeaderReply ToPB()
	{
		WGRpcInformAppointTeamLeaderReply v = new WGRpcInformAppointTeamLeaderReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformAppointTeamLeaderReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformAppointTeamLeaderReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformAppointTeamLeaderReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformAppointTeamLeaderReply>(protoMS);
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
//InformKickTeamMember请求封装类
[System.Serializable]
public class WGRpcInformKickTeamMemberAskWraper
{

	//构造函数
	public WGRpcInformKickTeamMemberAskWraper()
	{
		 m_Result = -9999;
		 m_KickedMemberRoleId = 0;
		 m_LeaderRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_KickedMemberRoleId = 0;
		 m_LeaderRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformKickTeamMemberAsk ToPB()
	{
		WGRpcInformKickTeamMemberAsk v = new WGRpcInformKickTeamMemberAsk();
		v.Result = m_Result;
		v.KickedMemberRoleId = m_KickedMemberRoleId;
		v.LeaderRoleId = m_LeaderRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformKickTeamMemberAsk v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_KickedMemberRoleId = v.KickedMemberRoleId;
		m_LeaderRoleId = v.LeaderRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformKickTeamMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformKickTeamMemberAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformKickTeamMemberAsk>(protoMS);
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
	//KickMemberRoleId
	public UInt64 m_KickedMemberRoleId;
	public UInt64 KickedMemberRoleId
	{
		get { return m_KickedMemberRoleId;}
		set { m_KickedMemberRoleId = value; }
	}
	//LeaderRoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}


};
//InformKickTeamMember回应封装类
[System.Serializable]
public class WGRpcInformKickTeamMemberReplyWraper
{

	//构造函数
	public WGRpcInformKickTeamMemberReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformKickTeamMemberReply ToPB()
	{
		WGRpcInformKickTeamMemberReply v = new WGRpcInformKickTeamMemberReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformKickTeamMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformKickTeamMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformKickTeamMemberReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformKickTeamMemberReply>(protoMS);
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
//InformDissmissTeam请求封装类
[System.Serializable]
public class WGRpcInformDissmissTeamAskWraper
{

	//构造函数
	public WGRpcInformDissmissTeamAskWraper()
	{
		 m_Result = -9999;
		 m_LeaderRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_LeaderRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformDissmissTeamAsk ToPB()
	{
		WGRpcInformDissmissTeamAsk v = new WGRpcInformDissmissTeamAsk();
		v.Result = m_Result;
		v.LeaderRoleId = m_LeaderRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformDissmissTeamAsk v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_LeaderRoleId = v.LeaderRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformDissmissTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformDissmissTeamAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformDissmissTeamAsk>(protoMS);
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
	//LeaderRoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}


};
//InformDissmissTeam回应封装类
[System.Serializable]
public class WGRpcInformDissmissTeamReplyWraper
{

	//构造函数
	public WGRpcInformDissmissTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformDissmissTeamReply ToPB()
	{
		WGRpcInformDissmissTeamReply v = new WGRpcInformDissmissTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformDissmissTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformDissmissTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformDissmissTeamReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformDissmissTeamReply>(protoMS);
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
//InformApply请求封装类
[System.Serializable]
public class WGRpcInformApplyTeamAskWraper
{

	//构造函数
	public WGRpcInformApplyTeamAskWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Result = -9999;
		 m_TeamId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Result = -9999;
		 m_TeamId = 0;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformApplyTeamAsk ToPB()
	{
		WGRpcInformApplyTeamAsk v = new WGRpcInformApplyTeamAsk();
		v.TeamMember = m_TeamMember.ToPB();
		v.Result = m_Result;
		v.TeamId = m_TeamId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformApplyTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);
		m_Result = v.Result;
		m_TeamId = v.TeamId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformApplyTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformApplyTeamAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformApplyTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamMember
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}


};
//InformApply回应封装类
[System.Serializable]
public class WGRpcInformApplyTeamReplyWraper
{

	//构造函数
	public WGRpcInformApplyTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformApplyTeamReply ToPB()
	{
		WGRpcInformApplyTeamReply v = new WGRpcInformApplyTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformApplyTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformApplyTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformApplyTeamReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformApplyTeamReply>(protoMS);
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
//AgreeTeamApplicant请求封装类
[System.Serializable]
public class WGRpcAgreeTeamApplicantAskWraper
{

	//构造函数
	public WGRpcAgreeTeamApplicantAskWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WGRpcAgreeTeamApplicantAsk ToPB()
	{
		WGRpcAgreeTeamApplicantAsk v = new WGRpcAgreeTeamApplicantAsk();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcAgreeTeamApplicantAsk v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcAgreeTeamApplicantAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcAgreeTeamApplicantAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcAgreeTeamApplicantAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//AgreeTeamApplicant回应封装类
[System.Serializable]
public class WGRpcAgreeTeamApplicantReplyWraper
{

	//构造函数
	public WGRpcAgreeTeamApplicantReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcAgreeTeamApplicantReply ToPB()
	{
		WGRpcAgreeTeamApplicantReply v = new WGRpcAgreeTeamApplicantReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcAgreeTeamApplicantReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcAgreeTeamApplicantReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcAgreeTeamApplicantReply pb = ProtoBuf.Serializer.Deserialize<WGRpcAgreeTeamApplicantReply>(protoMS);
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
//InformLogin请求封装类
[System.Serializable]
public class WGRpcInformLoginAskWraper
{

	//构造函数
	public WGRpcInformLoginAskWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformLoginAsk ToPB()
	{
		WGRpcInformLoginAsk v = new WGRpcInformLoginAsk();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformLoginAsk v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformLoginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformLoginAsk pb = ProtoBuf.Serializer.Deserialize<WGRpcInformLoginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//InformLogin回应封装类
[System.Serializable]
public class WGRpcInformLoginReplyWraper
{

	//构造函数
	public WGRpcInformLoginReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WGRpcInformLoginReply ToPB()
	{
		WGRpcInformLoginReply v = new WGRpcInformLoginReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WGRpcInformLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WGRpcInformLoginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WGRpcInformLoginReply pb = ProtoBuf.Serializer.Deserialize<WGRpcInformLoginReply>(protoMS);
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
