
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBTeam.cs
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


//创建队伍创建副本请求封装类
[System.Serializable]
public class TeamRpcCreateTeamAskWraper
{

	//构造函数
	public TeamRpcCreateTeamAskWraper()
	{
		 m_TeamType = -1;
		 m_TTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;
		 m_TTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcCreateTeamAsk ToPB()
	{
		TeamRpcCreateTeamAsk v = new TeamRpcCreateTeamAsk();
		v.TeamType = m_TeamType;
		v.TTarget = m_TTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcCreateTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;
		m_TTarget.FromPB(v.TTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcCreateTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcCreateTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcCreateTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//队伍目标
	public TeamTargetWraper m_TTarget;
	public TeamTargetWraper TTarget
	{
		get { return m_TTarget;}
		set { m_TTarget = value; }
	}


};
//创建队伍创建副本回应封装类
[System.Serializable]
public class TeamRpcCreateTeamReplyWraper
{

	//构造函数
	public TeamRpcCreateTeamReplyWraper()
	{
		 m_Result = -9999;
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcCreateTeamReply ToPB()
	{
		TeamRpcCreateTeamReply v = new TeamRpcCreateTeamReply();
		v.Result = m_Result;
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcCreateTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcCreateTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcCreateTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcCreateTeamReply>(protoMS);
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
	//PbTeam
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//LeaveTeam请求封装类
[System.Serializable]
public class TeamRpcLeaveTeamAskWraper
{

	//构造函数
	public TeamRpcLeaveTeamAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcLeaveTeamAsk ToPB()
	{
		TeamRpcLeaveTeamAsk v = new TeamRpcLeaveTeamAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcLeaveTeamAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcLeaveTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcLeaveTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcLeaveTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//LeaveTeam回应封装类
[System.Serializable]
public class TeamRpcLeaveTeamReplyWraper
{

	//构造函数
	public TeamRpcLeaveTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcLeaveTeamReply ToPB()
	{
		TeamRpcLeaveTeamReply v = new TeamRpcLeaveTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcLeaveTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcLeaveTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcLeaveTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcLeaveTeamReply>(protoMS);
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
//AppointTeamLeader请求封装类
[System.Serializable]
public class TeamRpcAppointTeamLeaderAskWraper
{

	//构造函数
	public TeamRpcAppointTeamLeaderAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAppointTeamLeaderAsk ToPB()
	{
		TeamRpcAppointTeamLeaderAsk v = new TeamRpcAppointTeamLeaderAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAppointTeamLeaderAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAppointTeamLeaderAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAppointTeamLeaderAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcAppointTeamLeaderAsk>(protoMS);
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


};
//AppointTeamLeader回应封装类
[System.Serializable]
public class TeamRpcAppointTeamLeaderReplyWraper
{

	//构造函数
	public TeamRpcAppointTeamLeaderReplyWraper()
	{
		 m_Result = -9999;
		 m_NewLeaderId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_NewLeaderId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAppointTeamLeaderReply ToPB()
	{
		TeamRpcAppointTeamLeaderReply v = new TeamRpcAppointTeamLeaderReply();
		v.Result = m_Result;
		v.NewLeaderId = m_NewLeaderId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAppointTeamLeaderReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewLeaderId = v.NewLeaderId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAppointTeamLeaderReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAppointTeamLeaderReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcAppointTeamLeaderReply>(protoMS);
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
	//NewLeaderId
	public UInt64 m_NewLeaderId;
	public UInt64 NewLeaderId
	{
		get { return m_NewLeaderId;}
		set { m_NewLeaderId = value; }
	}


};
//NewLeader通知封装类
[System.Serializable]
public class TeamRpcNewLeaderNotifyWraper
{

	//构造函数
	public TeamRpcNewLeaderNotifyWraper()
	{
		 m_Newleaderroleid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Newleaderroleid = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcNewLeaderNotify ToPB()
	{
		TeamRpcNewLeaderNotify v = new TeamRpcNewLeaderNotify();
		v.Newleaderroleid = m_Newleaderroleid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcNewLeaderNotify v)
	{
        if (v == null)
            return;
		m_Newleaderroleid = v.Newleaderroleid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcNewLeaderNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcNewLeaderNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcNewLeaderNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//newleaderroleid
	public UInt64 m_Newleaderroleid;
	public UInt64 Newleaderroleid
	{
		get { return m_Newleaderroleid;}
		set { m_Newleaderroleid = value; }
	}


};
//KickMember请求封装类
[System.Serializable]
public class TeamRpcKickMemberAskWraper
{

	//构造函数
	public TeamRpcKickMemberAskWraper()
	{
		 m_KickMemberRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KickMemberRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcKickMemberAsk ToPB()
	{
		TeamRpcKickMemberAsk v = new TeamRpcKickMemberAsk();
		v.KickMemberRoleId = m_KickMemberRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcKickMemberAsk v)
	{
        if (v == null)
            return;
		m_KickMemberRoleId = v.KickMemberRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcKickMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcKickMemberAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcKickMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//KickMemberRoleId
	public UInt64 m_KickMemberRoleId;
	public UInt64 KickMemberRoleId
	{
		get { return m_KickMemberRoleId;}
		set { m_KickMemberRoleId = value; }
	}


};
//KickMember回应封装类
[System.Serializable]
public class TeamRpcKickMemberReplyWraper
{

	//构造函数
	public TeamRpcKickMemberReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcKickMemberReply ToPB()
	{
		TeamRpcKickMemberReply v = new TeamRpcKickMemberReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcKickMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcKickMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcKickMemberReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcKickMemberReply>(protoMS);
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
//DissmissTeam请求封装类
[System.Serializable]
public class TeamRpcDissmissTeamAskWraper
{

	//构造函数
	public TeamRpcDissmissTeamAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcDissmissTeamAsk ToPB()
	{
		TeamRpcDissmissTeamAsk v = new TeamRpcDissmissTeamAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcDissmissTeamAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcDissmissTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcDissmissTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcDissmissTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//DissmissTeam回应封装类
[System.Serializable]
public class TeamRpcDissmissTeamReplyWraper
{

	//构造函数
	public TeamRpcDissmissTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcDissmissTeamReply ToPB()
	{
		TeamRpcDissmissTeamReply v = new TeamRpcDissmissTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcDissmissTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcDissmissTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcDissmissTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcDissmissTeamReply>(protoMS);
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
//AppointTeamLeader通知封装类
[System.Serializable]
public class TeamRpcAppointTeamLeaderNotifyWraper
{

	//构造函数
	public TeamRpcAppointTeamLeaderNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAppointTeamLeaderNotify ToPB()
	{
		TeamRpcAppointTeamLeaderNotify v = new TeamRpcAppointTeamLeaderNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAppointTeamLeaderNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAppointTeamLeaderNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAppointTeamLeaderNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcAppointTeamLeaderNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//KickMemberNotify通知封装类
[System.Serializable]
public class TeamRpcKickMemberNotifyNotifyWraper
{

	//构造函数
	public TeamRpcKickMemberNotifyNotifyWraper()
	{
		 m_KickedMemberRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KickedMemberRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcKickMemberNotifyNotify ToPB()
	{
		TeamRpcKickMemberNotifyNotify v = new TeamRpcKickMemberNotifyNotify();
		v.KickedMemberRoleId = m_KickedMemberRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcKickMemberNotifyNotify v)
	{
        if (v == null)
            return;
		m_KickedMemberRoleId = v.KickedMemberRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcKickMemberNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcKickMemberNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcKickMemberNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//KickMemberRoleId
	public UInt64 m_KickedMemberRoleId;
	public UInt64 KickedMemberRoleId
	{
		get { return m_KickedMemberRoleId;}
		set { m_KickedMemberRoleId = value; }
	}


};
//LeaveTeam通知封装类
[System.Serializable]
public class TeamRpcLeaveTeamNotifyNotifyWraper
{

	//构造函数
	public TeamRpcLeaveTeamNotifyNotifyWraper()
	{
		 m_RoleId = 0;
		 m_NewLeaderRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_NewLeaderRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcLeaveTeamNotifyNotify ToPB()
	{
		TeamRpcLeaveTeamNotifyNotify v = new TeamRpcLeaveTeamNotifyNotify();
		v.RoleId = m_RoleId;
		v.NewLeaderRoleId = m_NewLeaderRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcLeaveTeamNotifyNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_NewLeaderRoleId = v.NewLeaderRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcLeaveTeamNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcLeaveTeamNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcLeaveTeamNotifyNotify>(protoMS);
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


};
//JoinTeamNotify通知封装类
[System.Serializable]
public class TeamRpcJoinTeamNotifyNotifyWraper
{

	//构造函数
	public TeamRpcJoinTeamNotifyNotifyWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcJoinTeamNotifyNotify ToPB()
	{
		TeamRpcJoinTeamNotifyNotify v = new TeamRpcJoinTeamNotifyNotify();
		v.TeamMember = m_TeamMember.ToPB();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcJoinTeamNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcJoinTeamNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcJoinTeamNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcJoinTeamNotifyNotify>(protoMS);
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
	//PbTeam
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//DissmissTeamNotify通知封装类
[System.Serializable]
public class TeamRpcDissmissTeamNotifyNotifyWraper
{

	//构造函数
	public TeamRpcDissmissTeamNotifyNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcDissmissTeamNotifyNotify ToPB()
	{
		TeamRpcDissmissTeamNotifyNotify v = new TeamRpcDissmissTeamNotifyNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcDissmissTeamNotifyNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcDissmissTeamNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcDissmissTeamNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcDissmissTeamNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//SurroundingTeam请求封装类
[System.Serializable]
public class TeamRpcSurroundingTeamAskWraper
{

	//构造函数
	public TeamRpcSurroundingTeamAskWraper()
	{
		 m_TargetGroupId = -1;
		 m_TargetGroup = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TargetGroupId = -1;
		 m_TargetGroup = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSurroundingTeamAsk ToPB()
	{
		TeamRpcSurroundingTeamAsk v = new TeamRpcSurroundingTeamAsk();
		v.TargetGroupId = m_TargetGroupId;
		v.TargetGroup = m_TargetGroup;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSurroundingTeamAsk v)
	{
        if (v == null)
            return;
		m_TargetGroupId = v.TargetGroupId;
		m_TargetGroup = v.TargetGroup;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcSurroundingTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcSurroundingTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcSurroundingTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍类型
	public int m_TargetGroupId;
	public int TargetGroupId
	{
		get { return m_TargetGroupId;}
		set { m_TargetGroupId = value; }
	}
	//副本ID or 活动ID 
	public int m_TargetGroup;
	public int TargetGroup
	{
		get { return m_TargetGroup;}
		set { m_TargetGroup = value; }
	}


};
//SurroundingTeam回应封装类
[System.Serializable]
public class TeamRpcSurroundingTeamReplyWraper
{

	//构造函数
	public TeamRpcSurroundingTeamReplyWraper()
	{
		 m_Result = -9999;
		m_TeamsInfo = new List<TeamInfoWraper>();
		 m_TargetGroupId = -1;
		 m_TargetGroup = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_TeamsInfo = new List<TeamInfoWraper>();
		 m_TargetGroupId = -1;
		 m_TargetGroup = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSurroundingTeamReply ToPB()
	{
		TeamRpcSurroundingTeamReply v = new TeamRpcSurroundingTeamReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_TeamsInfo.Count; i++)
			v.TeamsInfo.Add( m_TeamsInfo[i].ToPB());
		v.TargetGroupId = m_TargetGroupId;
		v.TargetGroup = m_TargetGroup;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSurroundingTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TeamsInfo.Clear();
		for( int i=0; i<v.TeamsInfo.Count; i++)
			m_TeamsInfo.Add( new TeamInfoWraper());
		for( int i=0; i<v.TeamsInfo.Count; i++)
			m_TeamsInfo[i].FromPB(v.TeamsInfo[i]);
		m_TargetGroupId = v.TargetGroupId;
		m_TargetGroup = v.TargetGroup;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcSurroundingTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcSurroundingTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcSurroundingTeamReply>(protoMS);
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
	//TeamsInfo
	public List<TeamInfoWraper> m_TeamsInfo;
	public int SizeTeamsInfo()
	{
		return m_TeamsInfo.Count;
	}
	public List<TeamInfoWraper> GetTeamsInfo()
	{
		return m_TeamsInfo;
	}
	public TeamInfoWraper GetTeamsInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_TeamsInfo.Count)
			return new TeamInfoWraper();
		return m_TeamsInfo[Index];
	}
	public void SetTeamsInfo( List<TeamInfoWraper> v )
	{
		m_TeamsInfo=v;
	}
	public void SetTeamsInfo( int Index, TeamInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_TeamsInfo.Count)
			return;
		m_TeamsInfo[Index] = v;
	}
	public void AddTeamsInfo( TeamInfoWraper v )
	{
		m_TeamsInfo.Add(v);
	}
	public void ClearTeamsInfo( )
	{
		m_TeamsInfo.Clear();
	}
	//队伍类型
	public int m_TargetGroupId;
	public int TargetGroupId
	{
		get { return m_TargetGroupId;}
		set { m_TargetGroupId = value; }
	}
	//副本ID or 活动ID 
	public int m_TargetGroup;
	public int TargetGroup
	{
		get { return m_TargetGroup;}
		set { m_TargetGroup = value; }
	}


};
//ApplyTeam请求封装类
[System.Serializable]
public class TeamRpcApplyTeamAskWraper
{

	//构造函数
	public TeamRpcApplyTeamAskWraper()
	{
		 m_TeamId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcApplyTeamAsk ToPB()
	{
		TeamRpcApplyTeamAsk v = new TeamRpcApplyTeamAsk();
		v.TeamId = m_TeamId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcApplyTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcApplyTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcApplyTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcApplyTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}


};
//ApplyTeam回应封装类
[System.Serializable]
public class TeamRpcApplyTeamReplyWraper
{

	//构造函数
	public TeamRpcApplyTeamReplyWraper()
	{
		 m_Result = -9999;
		 m_TeamId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_TeamId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcApplyTeamReply ToPB()
	{
		TeamRpcApplyTeamReply v = new TeamRpcApplyTeamReply();
		v.Result = m_Result;
		v.TeamId = m_TeamId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcApplyTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TeamId = v.TeamId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcApplyTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcApplyTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcApplyTeamReply>(protoMS);
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
	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}


};
//ApplyTeamNotify通知封装类
[System.Serializable]
public class TeamRpcApplyTeamNotifyNotifyWraper
{

	//构造函数
	public TeamRpcApplyTeamNotifyNotifyWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcApplyTeamNotifyNotify ToPB()
	{
		TeamRpcApplyTeamNotifyNotify v = new TeamRpcApplyTeamNotifyNotify();
		v.TeamMember = m_TeamMember.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcApplyTeamNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcApplyTeamNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcApplyTeamNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcApplyTeamNotifyNotify>(protoMS);
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


};
//AgreeApplicant请求封装类
[System.Serializable]
public class TeamRpcAgreeApplicantAskWraper
{

	//构造函数
	public TeamRpcAgreeApplicantAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAgreeApplicantAsk ToPB()
	{
		TeamRpcAgreeApplicantAsk v = new TeamRpcAgreeApplicantAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAgreeApplicantAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAgreeApplicantAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAgreeApplicantAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcAgreeApplicantAsk>(protoMS);
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


};
//AgreeApplicant回应封装类
[System.Serializable]
public class TeamRpcAgreeApplicantReplyWraper
{

	//构造函数
	public TeamRpcAgreeApplicantReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAgreeApplicantReply ToPB()
	{
		TeamRpcAgreeApplicantReply v = new TeamRpcAgreeApplicantReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAgreeApplicantReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAgreeApplicantReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAgreeApplicantReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcAgreeApplicantReply>(protoMS);
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
//AgreeApplicantNotify通知封装类
[System.Serializable]
public class TeamRpcAgreeApplicantNotifyNotifyWraper
{

	//构造函数
	public TeamRpcAgreeApplicantNotifyNotifyWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAgreeApplicantNotifyNotify ToPB()
	{
		TeamRpcAgreeApplicantNotifyNotify v = new TeamRpcAgreeApplicantNotifyNotify();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAgreeApplicantNotifyNotify v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAgreeApplicantNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAgreeApplicantNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcAgreeApplicantNotifyNotify>(protoMS);
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
//TeamInfo通知封装类
[System.Serializable]
public class TeamRpcTeamInfoNotifyWraper
{

	//构造函数
	public TeamRpcTeamInfoNotifyWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_FollowTeamLeader = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_FollowTeamLeader = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcTeamInfoNotify ToPB()
	{
		TeamRpcTeamInfoNotify v = new TeamRpcTeamInfoNotify();
		v.Team = m_Team.ToPB();
		v.FollowTeamLeader = m_FollowTeamLeader;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcTeamInfoNotify v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);
		m_FollowTeamLeader = v.FollowTeamLeader;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcTeamInfoNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcTeamInfoNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcTeamInfoNotify>(protoMS);
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
	//跟随队长
	public int m_FollowTeamLeader;
	public int FollowTeamLeader
	{
		get { return m_FollowTeamLeader;}
		set { m_FollowTeamLeader = value; }
	}


};
//UpdateTeamMemInfo通知封装类
[System.Serializable]
public class TeamRpcUpdateTeamMemInfoNotifyWraper
{

	//构造函数
	public TeamRpcUpdateTeamMemInfoNotifyWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcUpdateTeamMemInfoNotify ToPB()
	{
		TeamRpcUpdateTeamMemInfoNotify v = new TeamRpcUpdateTeamMemInfoNotify();
		v.TeamMember = m_TeamMember.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcUpdateTeamMemInfoNotify v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcUpdateTeamMemInfoNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcUpdateTeamMemInfoNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcUpdateTeamMemInfoNotify>(protoMS);
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


};
//跟随队长请求封装类
[System.Serializable]
public class TeamRpcFollowTeamLeaderAskWraper
{

	//构造函数
	public TeamRpcFollowTeamLeaderAskWraper()
	{
		 m_FollowTeamLeader = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FollowTeamLeader = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcFollowTeamLeaderAsk ToPB()
	{
		TeamRpcFollowTeamLeaderAsk v = new TeamRpcFollowTeamLeaderAsk();
		v.FollowTeamLeader = m_FollowTeamLeader;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcFollowTeamLeaderAsk v)
	{
        if (v == null)
            return;
		m_FollowTeamLeader = v.FollowTeamLeader;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcFollowTeamLeaderAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcFollowTeamLeaderAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcFollowTeamLeaderAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//跟随队长
	public int m_FollowTeamLeader;
	public int FollowTeamLeader
	{
		get { return m_FollowTeamLeader;}
		set { m_FollowTeamLeader = value; }
	}


};
//跟随队长回应封装类
[System.Serializable]
public class TeamRpcFollowTeamLeaderReplyWraper
{

	//构造函数
	public TeamRpcFollowTeamLeaderReplyWraper()
	{
		 m_Result = -1;
		 m_FollowTeamLeader = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_FollowTeamLeader = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcFollowTeamLeaderReply ToPB()
	{
		TeamRpcFollowTeamLeaderReply v = new TeamRpcFollowTeamLeaderReply();
		v.Result = m_Result;
		v.FollowTeamLeader = m_FollowTeamLeader;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcFollowTeamLeaderReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FollowTeamLeader = v.FollowTeamLeader;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcFollowTeamLeaderReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcFollowTeamLeaderReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcFollowTeamLeaderReply>(protoMS);
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
	//跟随队长
	public int m_FollowTeamLeader;
	public int FollowTeamLeader
	{
		get { return m_FollowTeamLeader;}
		set { m_FollowTeamLeader = value; }
	}


};
//召唤队员请求封装类
[System.Serializable]
public class TeamRpcSummonMemberAskWraper
{

	//构造函数
	public TeamRpcSummonMemberAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSummonMemberAsk ToPB()
	{
		TeamRpcSummonMemberAsk v = new TeamRpcSummonMemberAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSummonMemberAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcSummonMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcSummonMemberAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcSummonMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//召唤队员回应封装类
[System.Serializable]
public class TeamRpcSummonMemberReplyWraper
{

	//构造函数
	public TeamRpcSummonMemberReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSummonMemberReply ToPB()
	{
		TeamRpcSummonMemberReply v = new TeamRpcSummonMemberReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSummonMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcSummonMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcSummonMemberReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcSummonMemberReply>(protoMS);
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
//召唤队员通知封装类
[System.Serializable]
public class TeamRpcSummonMemberNotifyNotifyWraper
{

	//构造函数
	public TeamRpcSummonMemberNotifyNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSummonMemberNotifyNotify ToPB()
	{
		TeamRpcSummonMemberNotifyNotify v = new TeamRpcSummonMemberNotifyNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSummonMemberNotifyNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcSummonMemberNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcSummonMemberNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcSummonMemberNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
//改变队伍目标封装类
[System.Serializable]
public class TeamRpcChangeTeamTargetReplyWraper
{

	//构造函数
	public TeamRpcChangeTeamTargetReplyWraper()
	{
		 m_Result = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangeTeamTargetReply ToPB()
	{
		TeamRpcChangeTeamTargetReply v = new TeamRpcChangeTeamTargetReply();
		v.Result = m_Result;
		v.TeamTarget = m_TeamTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangeTeamTargetReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TeamTarget.FromPB(v.TeamTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangeTeamTargetReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangeTeamTargetReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangeTeamTargetReply>(protoMS);
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
	//队伍目标
	public TeamTargetWraper m_TeamTarget;
	public TeamTargetWraper TeamTarget
	{
		get { return m_TeamTarget;}
		set { m_TeamTarget = value; }
	}


};
//改变队伍目标封装类
[System.Serializable]
public class TeamRpcChangeTeamTargetAskWraper
{

	//构造函数
	public TeamRpcChangeTeamTargetAskWraper()
	{
		 m_TargetType = -1;
		 m_Id = -1;
		 m_MinLevel = -1;
		 m_MaxLevel = -1;
		m_Function = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TargetType = -1;
		 m_Id = -1;
		 m_MinLevel = -1;
		 m_MaxLevel = -1;
		m_Function = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangeTeamTargetAsk ToPB()
	{
		TeamRpcChangeTeamTargetAsk v = new TeamRpcChangeTeamTargetAsk();
		v.TargetType = m_TargetType;
		v.Id = m_Id;
		v.MinLevel = m_MinLevel;
		v.MaxLevel = m_MaxLevel;
		for (int i=0; i<(int)m_Function.Count; i++)
			v.Function.Add( m_Function[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangeTeamTargetAsk v)
	{
        if (v == null)
            return;
		m_TargetType = v.TargetType;
		m_Id = v.Id;
		m_MinLevel = v.MinLevel;
		m_MaxLevel = v.MaxLevel;
		m_Function.Clear();
		for( int i=0; i<v.Function.Count; i++)
			m_Function.Add(v.Function[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangeTeamTargetAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangeTeamTargetAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangeTeamTargetAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标类型
	public int m_TargetType;
	public int TargetType
	{
		get { return m_TargetType;}
		set { m_TargetType = value; }
	}
	//副本ID or 活动ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//最小等级
	public int m_MinLevel;
	public int MinLevel
	{
		get { return m_MinLevel;}
		set { m_MinLevel = value; }
	}
	//最大等级
	public int m_MaxLevel;
	public int MaxLevel
	{
		get { return m_MaxLevel;}
		set { m_MaxLevel = value; }
	}
	//职能
	public List<int> m_Function;
	public int SizeFunction()
	{
		return m_Function.Count;
	}
	public List<int> GetFunction()
	{
		return m_Function;
	}
	public int GetFunction(int Index)
	{
		if(Index<0 || Index>=(int)m_Function.Count)
			return -1;
		return m_Function[Index];
	}
	public void SetFunction( List<int> v )
	{
		m_Function=v;
	}
	public void SetFunction( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Function.Count)
			return;
		m_Function[Index] = v;
	}
	public void AddFunction( int v=-1 )
	{
		m_Function.Add(v);
	}
	public void ClearFunction( )
	{
		m_Function.Clear();
	}


};
//设置服务器目标通知封装类
[System.Serializable]
public class TeamRpcChangeTeamTargetNotifyNotifyWraper
{

	//构造函数
	public TeamRpcChangeTeamTargetNotifyNotifyWraper()
	{
		 m_TeamTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangeTeamTargetNotifyNotify ToPB()
	{
		TeamRpcChangeTeamTargetNotifyNotify v = new TeamRpcChangeTeamTargetNotifyNotify();
		v.TeamTarget = m_TeamTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangeTeamTargetNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamTarget.FromPB(v.TeamTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangeTeamTargetNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangeTeamTargetNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangeTeamTargetNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍目标
	public TeamTargetWraper m_TeamTarget;
	public TeamTargetWraper TeamTarget
	{
		get { return m_TeamTarget;}
		set { m_TeamTarget = value; }
	}


};
//转换队伍团队请求封装类
[System.Serializable]
public class TeamRpcChangTeamTypeAskWraper
{

	//构造函数
	public TeamRpcChangTeamTypeAskWraper()
	{
		 m_TeamType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangTeamTypeAsk ToPB()
	{
		TeamRpcChangTeamTypeAsk v = new TeamRpcChangTeamTypeAsk();
		v.TeamType = m_TeamType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangTeamTypeAsk v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangTeamTypeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangTeamTypeAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangTeamTypeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍类型
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}


};
//转换队伍团队回应封装类
[System.Serializable]
public class TeamRpcChangTeamTypeReplyWraper
{

	//构造函数
	public TeamRpcChangTeamTypeReplyWraper()
	{
		 m_Result = -1;
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangTeamTypeReply ToPB()
	{
		TeamRpcChangTeamTypeReply v = new TeamRpcChangTeamTypeReply();
		v.Result = m_Result;
		v.TeamType = m_TeamType;
		v.TeamTarget = m_TeamTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangTeamTypeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TeamType = v.TeamType;
		m_TeamTarget.FromPB(v.TeamTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangTeamTypeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangTeamTypeReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangTeamTypeReply>(protoMS);
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
	//队伍类型
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//队伍目标
	public TeamTargetWraper m_TeamTarget;
	public TeamTargetWraper TeamTarget
	{
		get { return m_TeamTarget;}
		set { m_TeamTarget = value; }
	}


};
//转换队伍团队协议通知封装类
[System.Serializable]
public class TeamRpcChangeTeamTypeNotifyNotifyWraper
{

	//构造函数
	public TeamRpcChangeTeamTypeNotifyNotifyWraper()
	{
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcChangeTeamTypeNotifyNotify ToPB()
	{
		TeamRpcChangeTeamTypeNotifyNotify v = new TeamRpcChangeTeamTypeNotifyNotify();
		v.TeamType = m_TeamType;
		v.TeamTarget = m_TeamTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcChangeTeamTypeNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;
		m_TeamTarget.FromPB(v.TeamTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcChangeTeamTypeNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcChangeTeamTypeNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcChangeTeamTypeNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍类型
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//队伍目标
	public TeamTargetWraper m_TeamTarget;
	public TeamTargetWraper TeamTarget
	{
		get { return m_TeamTarget;}
		set { m_TeamTarget = value; }
	}


};
//邀请玩家请求封装类
[System.Serializable]
public class TeamRpcInviteTeamMemberAskWraper
{

	//构造函数
	public TeamRpcInviteTeamMemberAskWraper()
	{
		m_RoleId = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_RoleId = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcInviteTeamMemberAsk ToPB()
	{
		TeamRpcInviteTeamMemberAsk v = new TeamRpcInviteTeamMemberAsk();
		for (int i=0; i<(int)m_RoleId.Count; i++)
			v.RoleId.Add( m_RoleId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcInviteTeamMemberAsk v)
	{
        if (v == null)
            return;
		m_RoleId.Clear();
		for( int i=0; i<v.RoleId.Count; i++)
			m_RoleId.Add(v.RoleId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcInviteTeamMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcInviteTeamMemberAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcInviteTeamMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID列表
	public List<UInt64> m_RoleId;
	public int SizeRoleId()
	{
		return m_RoleId.Count;
	}
	public List<UInt64> GetRoleId()
	{
		return m_RoleId;
	}
	public UInt64 GetRoleId(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleId.Count)
			return 0;
		return m_RoleId[Index];
	}
	public void SetRoleId( List<UInt64> v )
	{
		m_RoleId=v;
	}
	public void SetRoleId( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleId.Count)
			return;
		m_RoleId[Index] = v;
	}
	public void AddRoleId( UInt64 v=0 )
	{
		m_RoleId.Add(v);
	}
	public void ClearRoleId( )
	{
		m_RoleId.Clear();
	}


};
//邀请玩家回应封装类
[System.Serializable]
public class TeamRpcInviteTeamMemberReplyWraper
{

	//构造函数
	public TeamRpcInviteTeamMemberReplyWraper()
	{
		 m_Result = -1;
		m_RoleId = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_RoleId = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcInviteTeamMemberReply ToPB()
	{
		TeamRpcInviteTeamMemberReply v = new TeamRpcInviteTeamMemberReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RoleId.Count; i++)
			v.RoleId.Add( m_RoleId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcInviteTeamMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId.Clear();
		for( int i=0; i<v.RoleId.Count; i++)
			m_RoleId.Add(v.RoleId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcInviteTeamMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcInviteTeamMemberReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcInviteTeamMemberReply>(protoMS);
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
	//角色ID列表
	public List<UInt64> m_RoleId;
	public int SizeRoleId()
	{
		return m_RoleId.Count;
	}
	public List<UInt64> GetRoleId()
	{
		return m_RoleId;
	}
	public UInt64 GetRoleId(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleId.Count)
			return 0;
		return m_RoleId[Index];
	}
	public void SetRoleId( List<UInt64> v )
	{
		m_RoleId=v;
	}
	public void SetRoleId( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleId.Count)
			return;
		m_RoleId[Index] = v;
	}
	public void AddRoleId( UInt64 v=0 )
	{
		m_RoleId.Add(v);
	}
	public void ClearRoleId( )
	{
		m_RoleId.Clear();
	}


};
//邀请玩家广播通知封装类
[System.Serializable]
public class TeamRpcInviteTeamMemberNotifyNotifyWraper
{

	//构造函数
	public TeamRpcInviteTeamMemberNotifyNotifyWraper()
	{
		 m_TeamId = 0;
		 m_IsLeader = -1;
		 m_InviteMemberInfo = new TeamMemberInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = 0;
		 m_IsLeader = -1;
		 m_InviteMemberInfo = new TeamMemberInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcInviteTeamMemberNotifyNotify ToPB()
	{
		TeamRpcInviteTeamMemberNotifyNotify v = new TeamRpcInviteTeamMemberNotifyNotify();
		v.TeamId = m_TeamId;
		v.IsLeader = m_IsLeader;
		v.InviteMemberInfo = m_InviteMemberInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcInviteTeamMemberNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_IsLeader = v.IsLeader;
		m_InviteMemberInfo.FromPB(v.InviteMemberInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcInviteTeamMemberNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcInviteTeamMemberNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcInviteTeamMemberNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍ID
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//是否队长邀请
	public int m_IsLeader;
	public int IsLeader
	{
		get { return m_IsLeader;}
		set { m_IsLeader = value; }
	}
	//邀请人的信息
	public TeamMemberInfoWraper m_InviteMemberInfo;
	public TeamMemberInfoWraper InviteMemberInfo
	{
		get { return m_InviteMemberInfo;}
		set { m_InviteMemberInfo = value; }
	}


};
//列表通知通知封装类
[System.Serializable]
public class TeamRpcApplyListNotifyNotifyWraper
{

	//构造函数
	public TeamRpcApplyListNotifyNotifyWraper()
	{
		m_ApplyList = new List<TeamMemberInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ApplyList = new List<TeamMemberInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcApplyListNotifyNotify ToPB()
	{
		TeamRpcApplyListNotifyNotify v = new TeamRpcApplyListNotifyNotify();
		for (int i=0; i<(int)m_ApplyList.Count; i++)
			v.ApplyList.Add( m_ApplyList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcApplyListNotifyNotify v)
	{
        if (v == null)
            return;
		m_ApplyList.Clear();
		for( int i=0; i<v.ApplyList.Count; i++)
			m_ApplyList.Add( new TeamMemberInfoWraper());
		for( int i=0; i<v.ApplyList.Count; i++)
			m_ApplyList[i].FromPB(v.ApplyList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcApplyListNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcApplyListNotifyNotify pb = ProtoBuf.Serializer.Deserialize<TeamRpcApplyListNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//成员列表
	public List<TeamMemberInfoWraper> m_ApplyList;
	public int SizeApplyList()
	{
		return m_ApplyList.Count;
	}
	public List<TeamMemberInfoWraper> GetApplyList()
	{
		return m_ApplyList;
	}
	public TeamMemberInfoWraper GetApplyList(int Index)
	{
		if(Index<0 || Index>=(int)m_ApplyList.Count)
			return new TeamMemberInfoWraper();
		return m_ApplyList[Index];
	}
	public void SetApplyList( List<TeamMemberInfoWraper> v )
	{
		m_ApplyList=v;
	}
	public void SetApplyList( int Index, TeamMemberInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ApplyList.Count)
			return;
		m_ApplyList[Index] = v;
	}
	public void AddApplyList( TeamMemberInfoWraper v )
	{
		m_ApplyList.Add(v);
	}
	public void ClearApplyList( )
	{
		m_ApplyList.Clear();
	}


};
//AgreeJoinTeam请求封装类
[System.Serializable]
public class TeamRpcAgreeJoinTeamAskWraper
{

	//构造函数
	public TeamRpcAgreeJoinTeamAskWraper()
	{
		 m_TeamId = 0;
		 m_IsLeader = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = 0;
		 m_IsLeader = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAgreeJoinTeamAsk ToPB()
	{
		TeamRpcAgreeJoinTeamAsk v = new TeamRpcAgreeJoinTeamAsk();
		v.TeamId = m_TeamId;
		v.IsLeader = m_IsLeader;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAgreeJoinTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_IsLeader = v.IsLeader;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAgreeJoinTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAgreeJoinTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcAgreeJoinTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//IsLeader
	public int m_IsLeader;
	public int IsLeader
	{
		get { return m_IsLeader;}
		set { m_IsLeader = value; }
	}


};
//AgreeJoinTeam回应封装类
[System.Serializable]
public class TeamRpcAgreeJoinTeamReplyWraper
{

	//构造函数
	public TeamRpcAgreeJoinTeamReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcAgreeJoinTeamReply ToPB()
	{
		TeamRpcAgreeJoinTeamReply v = new TeamRpcAgreeJoinTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcAgreeJoinTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAgreeJoinTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcAgreeJoinTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcAgreeJoinTeamReply>(protoMS);
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
//拒绝申请请求封装类
[System.Serializable]
public class TeamRpcRefuseMemberAskWraper
{

	//构造函数
	public TeamRpcRefuseMemberAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcRefuseMemberAsk ToPB()
	{
		TeamRpcRefuseMemberAsk v = new TeamRpcRefuseMemberAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcRefuseMemberAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcRefuseMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcRefuseMemberAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcRefuseMemberAsk>(protoMS);
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


};
//拒绝申请回应封装类
[System.Serializable]
public class TeamRpcRefuseMemberReplyWraper
{

	//构造函数
	public TeamRpcRefuseMemberReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcRefuseMemberReply ToPB()
	{
		TeamRpcRefuseMemberReply v = new TeamRpcRefuseMemberReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcRefuseMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcRefuseMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcRefuseMemberReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcRefuseMemberReply>(protoMS);
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
//清空申请列表回应封装类
[System.Serializable]
public class TeamRpcClearApplyListReplyWraper
{

	//构造函数
	public TeamRpcClearApplyListReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcClearApplyListReply ToPB()
	{
		TeamRpcClearApplyListReply v = new TeamRpcClearApplyListReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcClearApplyListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcClearApplyListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcClearApplyListReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcClearApplyListReply>(protoMS);
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
//清空申请列表请求封装类
[System.Serializable]
public class TeamRpcClearApplyListAskWraper
{

	//构造函数
	public TeamRpcClearApplyListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcClearApplyListAsk ToPB()
	{
		TeamRpcClearApplyListAsk v = new TeamRpcClearApplyListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcClearApplyListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcClearApplyListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcClearApplyListAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcClearApplyListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//没有队伍邀请玩家请求封装类
[System.Serializable]
public class TeamRpcNoTeamInviteAskWraper
{

	//构造函数
	public TeamRpcNoTeamInviteAskWraper()
	{
		 m_TeamType = -1;
		 m_TTarget = new TeamTargetWraper();
		 m_InviteRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;
		 m_TTarget = new TeamTargetWraper();
		 m_InviteRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcNoTeamInviteAsk ToPB()
	{
		TeamRpcNoTeamInviteAsk v = new TeamRpcNoTeamInviteAsk();
		v.TeamType = m_TeamType;
		v.TTarget = m_TTarget.ToPB();
		v.InviteRoleId = m_InviteRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcNoTeamInviteAsk v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;
		m_TTarget.FromPB(v.TTarget);
		m_InviteRoleId = v.InviteRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcNoTeamInviteAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcNoTeamInviteAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcNoTeamInviteAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//队伍目标
	public TeamTargetWraper m_TTarget;
	public TeamTargetWraper TTarget
	{
		get { return m_TTarget;}
		set { m_TTarget = value; }
	}
	//邀请人id
	public UInt64 m_InviteRoleId;
	public UInt64 InviteRoleId
	{
		get { return m_InviteRoleId;}
		set { m_InviteRoleId = value; }
	}


};
//没有队伍邀请玩家回应封装类
[System.Serializable]
public class TeamRpcNoTeamInviteReplyWraper
{

	//构造函数
	public TeamRpcNoTeamInviteReplyWraper()
	{
		 m_Result = -1;
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcNoTeamInviteReply ToPB()
	{
		TeamRpcNoTeamInviteReply v = new TeamRpcNoTeamInviteReply();
		v.Result = m_Result;
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcNoTeamInviteReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcNoTeamInviteReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcNoTeamInviteReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcNoTeamInviteReply>(protoMS);
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
	//PbTeam
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//拒绝邀请请求封装类
[System.Serializable]
public class TeamRpcRejectInviteAskWraper
{

	//构造函数
	public TeamRpcRejectInviteAskWraper()
	{
		 m_RoleId = 0;
		 m_Name = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Name = "";

	}

 	//转化成Protobuffer类型函数
	public TeamRpcRejectInviteAsk ToPB()
	{
		TeamRpcRejectInviteAsk v = new TeamRpcRejectInviteAsk();
		v.RoleId = m_RoleId;
		v.Name = m_Name;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcRejectInviteAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Name = v.Name;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcRejectInviteAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcRejectInviteAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcRejectInviteAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家名字
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//玩家名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}


};
//拒绝邀请回应封装类
[System.Serializable]
public class TeamRpcRejectInviteReplyWraper
{

	//构造函数
	public TeamRpcRejectInviteReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcRejectInviteReply ToPB()
	{
		TeamRpcRejectInviteReply v = new TeamRpcRejectInviteReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcRejectInviteReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcRejectInviteReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcRejectInviteReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcRejectInviteReply>(protoMS);
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
