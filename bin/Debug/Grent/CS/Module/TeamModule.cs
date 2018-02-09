/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleTeam.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class TeamRPC
{
	public const int ModuleId = 10;
	
	public const int RPC_CODE_TEAM_JOINTEAM_REQUEST = 1051;
	public const int RPC_CODE_TEAM_LEAVETEAM_REQUEST = 1052;
	public const int RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST = 1053;
	public const int RPC_CODE_TEAM_CREATETEAM_REQUEST = 1054;
	public const int RPC_CODE_TEAM_DISSMISSTEAM_REQUEST = 1055;
	public const int RPC_CODE_TEAM_NEWLEADER_NOTIFY = 1056;
	public const int RPC_CODE_TEAM_KICKMEMBER_REQUEST = 1057;
	public const int RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY = 1058;
	public const int RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY = 1059;
	public const int RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY = 1060;
	public const int RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY = 1061;
	public const int RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST = 1062;
	public const int RPC_CODE_TEAM_APPLYTEAM_REQUEST = 1063;
	public const int RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY = 1064;
	public const int RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST = 1065;
	public const int RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY = 1066;
	public const int RPC_CODE_TEAM_TEAMINFO_NOTIFY = 1067;
	public const int RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY = 1068;

	
	private static TeamRPC m_Instance = null;
	public static TeamRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TeamRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, TeamData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_NEWLEADER_NOTIFY, NewLeaderCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY, DissmissTeamNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY, JoinTeamNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY, KickMemberNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY, LeaveTeamNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY, ApplyTeamNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY, AgreeApplicantNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_TEAMINFO_NOTIFY, TeamInfoCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY, UpdateTeamMemInfoCB);


		return true;
	}


	/**
	*Team-->加入队伍 RPC请求
	*/
	public void JoinTeam(int TeamId, int TeamType, TeamInfoWraper Team, TeamMemberInfoWraper TeamMember, ReplyHandler replyCB)
	{
		TeamRpcJoinTeamAskWraper askPBWraper = new TeamRpcJoinTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.TeamType = TeamType;
		askPBWraper.Team = Team;
		askPBWraper.TeamMember = TeamMember;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_JOINTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcJoinTeamReplyWraper replyPBWraper = new TeamRpcJoinTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->LeaveTeam RPC请求
	*/
	public void LeaveTeam(ReplyHandler replyCB)
	{
		TeamRpcLeaveTeamAskWraper askPBWraper = new TeamRpcLeaveTeamAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_LEAVETEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcLeaveTeamReplyWraper replyPBWraper = new TeamRpcLeaveTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->AppointTeamLeader RPC请求
	*/
	public void AppointTeamLeader(UInt64 RoleId, ReplyHandler replyCB)
	{
		TeamRpcAppointTeamLeaderAskWraper askPBWraper = new TeamRpcAppointTeamLeaderAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcAppointTeamLeaderReplyWraper replyPBWraper = new TeamRpcAppointTeamLeaderReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->CreateTeam RPC请求
	*/
	public void CreateTeam(int TeamType, ReplyHandler replyCB)
	{
		TeamRpcCreateTeamAskWraper askPBWraper = new TeamRpcCreateTeamAskWraper();
		askPBWraper.TeamType = TeamType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_CREATETEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcCreateTeamReplyWraper replyPBWraper = new TeamRpcCreateTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->DissmissTeam RPC请求
	*/
	public void DissmissTeam(ReplyHandler replyCB)
	{
		TeamRpcDissmissTeamAskWraper askPBWraper = new TeamRpcDissmissTeamAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_DISSMISSTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcDissmissTeamReplyWraper replyPBWraper = new TeamRpcDissmissTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->KickMember RPC请求
	*/
	public void KickMember(UInt64 KickMemberRoleId, ReplyHandler replyCB)
	{
		TeamRpcKickMemberAskWraper askPBWraper = new TeamRpcKickMemberAskWraper();
		askPBWraper.KickMemberRoleId = KickMemberRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_KICKMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcKickMemberReplyWraper replyPBWraper = new TeamRpcKickMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->SurroundingTeam RPC请求
	*/
	public void SurroundingTeam(ReplyHandler replyCB)
	{
		TeamRpcSurroundingTeamAskWraper askPBWraper = new TeamRpcSurroundingTeamAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcSurroundingTeamReplyWraper replyPBWraper = new TeamRpcSurroundingTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->ApplyTeam RPC请求
	*/
	public void ApplyTeam(int TeamId, ReplyHandler replyCB)
	{
		TeamRpcApplyTeamAskWraper askPBWraper = new TeamRpcApplyTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_APPLYTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcApplyTeamReplyWraper replyPBWraper = new TeamRpcApplyTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->AgreeApplicant RPC请求
	*/
	public void AgreeApplicant(UInt64 RoleId, ReplyHandler replyCB)
	{
		TeamRpcAgreeApplicantAskWraper askPBWraper = new TeamRpcAgreeApplicantAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcAgreeApplicantReplyWraper replyPBWraper = new TeamRpcAgreeApplicantReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*Team-->NewLeader 服务器通知回调
	*/
	public static void NewLeaderCB( ModMessage notifyMsg )
	{
		TeamRpcNewLeaderNotifyWraper notifyPBWraper = new TeamRpcNewLeaderNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewLeaderCBDelegate != null )
			NewLeaderCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewLeaderCBDelegate = null;
	/**
	*Team-->DissmissTeamNotify 服务器通知回调
	*/
	public static void DissmissTeamNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcDissmissTeamNotifyNotifyWraper notifyPBWraper = new TeamRpcDissmissTeamNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DissmissTeamNotifyCBDelegate != null )
			DissmissTeamNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DissmissTeamNotifyCBDelegate = null;
	/**
	*Team-->JoinTeamNotify 服务器通知回调
	*/
	public static void JoinTeamNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcJoinTeamNotifyNotifyWraper notifyPBWraper = new TeamRpcJoinTeamNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( JoinTeamNotifyCBDelegate != null )
			JoinTeamNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback JoinTeamNotifyCBDelegate = null;
	/**
	*Team-->KickMemberNotify 服务器通知回调
	*/
	public static void KickMemberNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcKickMemberNotifyNotifyWraper notifyPBWraper = new TeamRpcKickMemberNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( KickMemberNotifyCBDelegate != null )
			KickMemberNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback KickMemberNotifyCBDelegate = null;
	/**
	*Team-->LeaveTeam 服务器通知回调
	*/
	public static void LeaveTeamNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcLeaveTeamNotifyNotifyWraper notifyPBWraper = new TeamRpcLeaveTeamNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( LeaveTeamNotifyCBDelegate != null )
			LeaveTeamNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback LeaveTeamNotifyCBDelegate = null;
	/**
	*Team-->ApplyTeamNotify 服务器通知回调
	*/
	public static void ApplyTeamNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcApplyTeamNotifyNotifyWraper notifyPBWraper = new TeamRpcApplyTeamNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ApplyTeamNotifyCBDelegate != null )
			ApplyTeamNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ApplyTeamNotifyCBDelegate = null;
	/**
	*Team-->AgreeApplicantNotify 服务器通知回调
	*/
	public static void AgreeApplicantNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcAgreeApplicantNotifyNotifyWraper notifyPBWraper = new TeamRpcAgreeApplicantNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( AgreeApplicantNotifyCBDelegate != null )
			AgreeApplicantNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback AgreeApplicantNotifyCBDelegate = null;
	/**
	*Team-->TeamInfo 服务器通知回调
	*/
	public static void TeamInfoCB( ModMessage notifyMsg )
	{
		TeamRpcTeamInfoNotifyWraper notifyPBWraper = new TeamRpcTeamInfoNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TeamInfoCBDelegate != null )
			TeamInfoCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TeamInfoCBDelegate = null;
	/**
	*Team-->UpdateTeamMemInfo 服务器通知回调
	*/
	public static void UpdateTeamMemInfoCB( ModMessage notifyMsg )
	{
		TeamRpcUpdateTeamMemInfoNotifyWraper notifyPBWraper = new TeamRpcUpdateTeamMemInfoNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UpdateTeamMemInfoCBDelegate != null )
			UpdateTeamMemInfoCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UpdateTeamMemInfoCBDelegate = null;



}

public class TeamData
{
	public enum SyncIdE
	{

	}
	
	private static TeamData m_Instance = null;
	public static TeamData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TeamData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Ex.Logger.Log("TeamData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
