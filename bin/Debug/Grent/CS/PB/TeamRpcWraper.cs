
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamRpcCreateTeamAsk ToPB()
	{
		TeamRpcCreateTeamAsk v = new TeamRpcCreateTeamAsk();
		v.TeamType = m_TeamType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcCreateTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;

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
//加入队伍请求封装类
[System.Serializable]
public class TeamRpcJoinTeamAskWraper
{

	//构造函数
	public TeamRpcJoinTeamAskWraper()
	{
		 m_TeamId = -1;
		 m_TeamType = -1;
		 m_Team = new TeamInfoWraper();
		 m_TeamMember = new TeamMemberInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = -1;
		 m_TeamType = -1;
		 m_Team = new TeamInfoWraper();
		 m_TeamMember = new TeamMemberInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcJoinTeamAsk ToPB()
	{
		TeamRpcJoinTeamAsk v = new TeamRpcJoinTeamAsk();
		v.TeamId = m_TeamId;
		v.TeamType = m_TeamType;
		v.Team = m_Team.ToPB();
		v.TeamMember = m_TeamMember.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcJoinTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_TeamType = v.TeamType;
		m_Team.FromPB(v.Team);
		m_TeamMember.FromPB(v.TeamMember);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcJoinTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcJoinTeamAsk pb = ProtoBuf.Serializer.Deserialize<TeamRpcJoinTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}
	//TeamMember
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}


};
//加入队伍回应封装类
[System.Serializable]
public class TeamRpcJoinTeamReplyWraper
{

	//构造函数
	public TeamRpcJoinTeamReplyWraper()
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
	public TeamRpcJoinTeamReply ToPB()
	{
		TeamRpcJoinTeamReply v = new TeamRpcJoinTeamReply();
		v.Result = m_Result;
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcJoinTeamReply v)
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
		ProtoBuf.Serializer.Serialize<TeamRpcJoinTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamRpcJoinTeamReply pb = ProtoBuf.Serializer.Deserialize<TeamRpcJoinTeamReply>(protoMS);
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
	//Team
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcJoinTeamNotifyNotify ToPB()
	{
		TeamRpcJoinTeamNotifyNotify v = new TeamRpcJoinTeamNotifyNotify();
		v.TeamMember = m_TeamMember.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcJoinTeamNotifyNotify v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);

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

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSurroundingTeamAsk ToPB()
	{
		TeamRpcSurroundingTeamAsk v = new TeamRpcSurroundingTeamAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcSurroundingTeamAsk v)
	{
        if (v == null)
            return;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_TeamsInfo = new List<TeamInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcSurroundingTeamReply ToPB()
	{
		TeamRpcSurroundingTeamReply v = new TeamRpcSurroundingTeamReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_TeamsInfo.Count; i++)
			v.TeamsInfo.Add( m_TeamsInfo[i].ToPB());

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


};
//ApplyTeam请求封装类
[System.Serializable]
public class TeamRpcApplyTeamAskWraper
{

	//构造函数
	public TeamRpcApplyTeamAskWraper()
	{
		 m_TeamId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = -1;

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
	public int m_TeamId;
	public int TeamId
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
		 m_TeamId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_TeamId = -1;

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
	public int m_TeamId;
	public int TeamId
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamRpcTeamInfoNotify ToPB()
	{
		TeamRpcTeamInfoNotify v = new TeamRpcTeamInfoNotify();
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamRpcTeamInfoNotify v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);

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
