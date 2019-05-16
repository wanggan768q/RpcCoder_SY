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
	
	public const int RPC_CODE_TEAM_LEAVETEAM_REQUEST = 1051;
	public const int RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST = 1052;
	public const int RPC_CODE_TEAM_CREATETEAM_REQUEST = 1053;
	public const int RPC_CODE_TEAM_DISSMISSTEAM_REQUEST = 1054;
	public const int RPC_CODE_TEAM_NEWLEADER_NOTIFY = 1055;
	public const int RPC_CODE_TEAM_KICKMEMBER_REQUEST = 1056;
	public const int RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY = 1057;
	public const int RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY = 1058;
	public const int RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY = 1059;
	public const int RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY = 1060;
	public const int RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST = 1061;
	public const int RPC_CODE_TEAM_APPLYTEAM_REQUEST = 1062;
	public const int RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY = 1063;
	public const int RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST = 1064;
	public const int RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY = 1065;
	public const int RPC_CODE_TEAM_TEAMINFO_NOTIFY = 1066;
	public const int RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY = 1067;
	public const int RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST = 1068;
	public const int RPC_CODE_TEAM_SUMMONMEMBER_REQUEST = 1069;
	public const int RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY = 1070;
	public const int RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST = 1071;
	public const int RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY = 1072;
	public const int RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST = 1073;
	public const int RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY = 1074;
	public const int RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST = 1075;
	public const int RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY = 1076;
	public const int RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY = 1077;
	public const int RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST = 1078;
	public const int RPC_CODE_TEAM_REFUSEMEMBER_REQUEST = 1079;
	public const int RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST = 1080;
	public const int RPC_CODE_TEAM_NOTEAMINVITE_REQUEST = 1081;
	public const int RPC_CODE_TEAM_REJECTINVITE_REQUEST = 1082;

	
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
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY, SummonMemberNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY, ChangeTeamTargetNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY, ChangeTeamTypeNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY, InviteTeamMemberNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY, ApplyListNotifyCB);


		return true;
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
	public void CreateTeam(int TeamType, TeamTargetWraper TTarget, ReplyHandler replyCB)
	{
		TeamRpcCreateTeamAskWraper askPBWraper = new TeamRpcCreateTeamAskWraper();
		askPBWraper.TeamType = TeamType;
		askPBWraper.TTarget = TTarget;
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
	public void SurroundingTeam(int TargetGroupId, int TargetGroup, ReplyHandler replyCB)
	{
		TeamRpcSurroundingTeamAskWraper askPBWraper = new TeamRpcSurroundingTeamAskWraper();
		askPBWraper.TargetGroupId = TargetGroupId;
		askPBWraper.TargetGroup = TargetGroup;
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
	public void ApplyTeam(UInt64 TeamId, ReplyHandler replyCB)
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
	*Team-->跟随队长 RPC请求
	*/
	public void FollowTeamLeader(int FollowTeamLeader, ReplyHandler replyCB)
	{
		TeamRpcFollowTeamLeaderAskWraper askPBWraper = new TeamRpcFollowTeamLeaderAskWraper();
		askPBWraper.FollowTeamLeader = FollowTeamLeader;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcFollowTeamLeaderReplyWraper replyPBWraper = new TeamRpcFollowTeamLeaderReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->召唤队员 RPC请求
	*/
	public void SummonMember(ReplyHandler replyCB)
	{
		TeamRpcSummonMemberAskWraper askPBWraper = new TeamRpcSummonMemberAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_SUMMONMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcSummonMemberReplyWraper replyPBWraper = new TeamRpcSummonMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->改变队伍目标 RPC请求
	*/
	public void ChangeTeamTarget(int TargetType, int Id, int MinLevel, int MaxLevel, List<int> Function, ReplyHandler replyCB)
	{
		TeamRpcChangeTeamTargetAskWraper askPBWraper = new TeamRpcChangeTeamTargetAskWraper();
		askPBWraper.TargetType = TargetType;
		askPBWraper.Id = Id;
		askPBWraper.MinLevel = MinLevel;
		askPBWraper.MaxLevel = MaxLevel;
		askPBWraper.SetFunction(Function);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcChangeTeamTargetReplyWraper replyPBWraper = new TeamRpcChangeTeamTargetReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->转换队伍团队 RPC请求
	*/
	public void ChangTeamType(int TeamType, ReplyHandler replyCB)
	{
		TeamRpcChangTeamTypeAskWraper askPBWraper = new TeamRpcChangTeamTypeAskWraper();
		askPBWraper.TeamType = TeamType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcChangTeamTypeReplyWraper replyPBWraper = new TeamRpcChangTeamTypeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->邀请玩家 RPC请求
	*/
	public void InviteTeamMember(List<UInt64> RoleId, ReplyHandler replyCB)
	{
		TeamRpcInviteTeamMemberAskWraper askPBWraper = new TeamRpcInviteTeamMemberAskWraper();
		askPBWraper.SetRoleId(RoleId);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcInviteTeamMemberReplyWraper replyPBWraper = new TeamRpcInviteTeamMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->AgreeJoinTeam RPC请求
	*/
	public void AgreeJoinTeam(UInt64 TeamId, int IsLeader, ReplyHandler replyCB)
	{
		TeamRpcAgreeJoinTeamAskWraper askPBWraper = new TeamRpcAgreeJoinTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.IsLeader = IsLeader;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcAgreeJoinTeamReplyWraper replyPBWraper = new TeamRpcAgreeJoinTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->拒绝申请 RPC请求
	*/
	public void RefuseMember(UInt64 RoleId, ReplyHandler replyCB)
	{
		TeamRpcRefuseMemberAskWraper askPBWraper = new TeamRpcRefuseMemberAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_REFUSEMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcRefuseMemberReplyWraper replyPBWraper = new TeamRpcRefuseMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->清空申请列表 RPC请求
	*/
	public void ClearApplyList(ReplyHandler replyCB)
	{
		TeamRpcClearApplyListAskWraper askPBWraper = new TeamRpcClearApplyListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcClearApplyListReplyWraper replyPBWraper = new TeamRpcClearApplyListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->没有队伍邀请玩家 RPC请求
	*/
	public void NoTeamInvite(int TeamType, TeamTargetWraper TTarget, UInt64 InviteRoleId, ReplyHandler replyCB)
	{
		TeamRpcNoTeamInviteAskWraper askPBWraper = new TeamRpcNoTeamInviteAskWraper();
		askPBWraper.TeamType = TeamType;
		askPBWraper.TTarget = TTarget;
		askPBWraper.InviteRoleId = InviteRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_NOTEAMINVITE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcNoTeamInviteReplyWraper replyPBWraper = new TeamRpcNoTeamInviteReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Team-->拒绝邀请 RPC请求
	*/
	public void RejectInvite(UInt64 RoleId, string Name, ReplyHandler replyCB)
	{
		TeamRpcRejectInviteAskWraper askPBWraper = new TeamRpcRejectInviteAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.Name = Name;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TEAM_REJECTINVITE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcRejectInviteReplyWraper replyPBWraper = new TeamRpcRejectInviteReplyWraper();
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
	/**
	*Team-->召唤队员 服务器通知回调
	*/
	public static void SummonMemberNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcSummonMemberNotifyNotifyWraper notifyPBWraper = new TeamRpcSummonMemberNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SummonMemberNotifyCBDelegate != null )
			SummonMemberNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SummonMemberNotifyCBDelegate = null;
	/**
	*Team-->设置服务器目标 服务器通知回调
	*/
	public static void ChangeTeamTargetNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcChangeTeamTargetNotifyNotifyWraper notifyPBWraper = new TeamRpcChangeTeamTargetNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ChangeTeamTargetNotifyCBDelegate != null )
			ChangeTeamTargetNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ChangeTeamTargetNotifyCBDelegate = null;
	/**
	*Team-->转换队伍团队协议 服务器通知回调
	*/
	public static void ChangeTeamTypeNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcChangeTeamTypeNotifyNotifyWraper notifyPBWraper = new TeamRpcChangeTeamTypeNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ChangeTeamTypeNotifyCBDelegate != null )
			ChangeTeamTypeNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ChangeTeamTypeNotifyCBDelegate = null;
	/**
	*Team-->邀请玩家广播 服务器通知回调
	*/
	public static void InviteTeamMemberNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcInviteTeamMemberNotifyNotifyWraper notifyPBWraper = new TeamRpcInviteTeamMemberNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( InviteTeamMemberNotifyCBDelegate != null )
			InviteTeamMemberNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback InviteTeamMemberNotifyCBDelegate = null;
	/**
	*Team-->列表通知 服务器通知回调
	*/
	public static void ApplyListNotifyCB( ModMessage notifyMsg )
	{
		TeamRpcApplyListNotifyNotifyWraper notifyPBWraper = new TeamRpcApplyListNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ApplyListNotifyCBDelegate != null )
			ApplyListNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ApplyListNotifyCBDelegate = null;



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
