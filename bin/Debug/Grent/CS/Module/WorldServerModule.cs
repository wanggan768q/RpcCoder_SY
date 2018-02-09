/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleWorldServer.cs
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


public class WorldServerRPC
{
	public const int ModuleId = 8;
	
	public const int RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST = 851;
	public const int RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST = 852;
	public const int RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST = 853;
	public const int RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST = 854;
	public const int RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST = 855;
	public const int RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST = 856;
	public const int RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST = 857;
	public const int RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST = 858;
	public const int RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST = 859;
	public const int RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST = 860;
	public const int RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST = 861;
	public const int RPC_CODE_WORLDSERVER_LOGIN_REQUEST = 862;
	public const int RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST = 863;
	public const int RPC_CODE_WORLDSERVER_LOGOUT_REQUEST = 864;
	public const int RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST = 865;
	public const int RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST = 866;
	public const int RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST = 867;

	
	private static WorldServerRPC m_Instance = null;
	public static WorldServerRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldServerRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, WorldServerData.Instance.UpdateField );
		


		return true;
	}


	/**
	*世界服务器模块-->通知世界服务器切换场景 RPC请求
	*/
	public void ChangeScene(UInt64 RoleId, int CurSceneId, int TargetSceneId, int MemId, int SceneId, ReplyHandler replyCB)
	{
		WorldServerRpcChangeSceneAskWraper askPBWraper = new WorldServerRpcChangeSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.TargetSceneId = TargetSceneId;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcChangeSceneReplyWraper replyPBWraper = new WorldServerRpcChangeSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->进入场景 RPC请求
	*/
	public void EnterScene(UInt64 RoleId, int SceneId, int MemId, ReplyHandler replyCB)
	{
		WorldServerRpcEnterSceneAskWraper askPBWraper = new WorldServerRpcEnterSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.MemId = MemId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcEnterSceneReplyWraper replyPBWraper = new WorldServerRpcEnterSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->创建副本通知 RPC请求
	*/
	public void CreateDungeon(UInt64 RoleId, int TargetSceneId, int MemId, int DungeonConfigId, int CurSceneId, int Result, List<UInt64> RoleIds, ReplyHandler replyCB)
	{
		WorldServerRpcCreateDungeonAskWraper askPBWraper = new WorldServerRpcCreateDungeonAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.TargetSceneId = TargetSceneId;
		askPBWraper.MemId = MemId;
		askPBWraper.DungeonConfigId = DungeonConfigId;
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.Result = Result;
		askPBWraper.SetRoleIds(RoleIds);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcCreateDungeonReplyWraper replyPBWraper = new WorldServerRpcCreateDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->CreateTeam RPC请求
	*/
	public void CreateTeam(int TeamType, TeamMemberInfoWraper TeamMember, int Result, TeamInfoWraper Team, ReplyHandler replyCB)
	{
		WorldServerRpcCreateTeamAskWraper askPBWraper = new WorldServerRpcCreateTeamAskWraper();
		askPBWraper.TeamType = TeamType;
		askPBWraper.TeamMember = TeamMember;
		askPBWraper.Result = Result;
		askPBWraper.Team = Team;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcCreateTeamReplyWraper replyPBWraper = new WorldServerRpcCreateTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->JoinTeam RPC请求
	*/
	public void JoinTeam(int TeamId, int Result, TeamMemberInfoWraper TeamMember, TeamInfoWraper Team, int TeamType, int MemId, int SceneId, ReplyHandler replyCB)
	{
		WorldServerRpcJoinTeamAskWraper askPBWraper = new WorldServerRpcJoinTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.Result = Result;
		askPBWraper.TeamMember = TeamMember;
		askPBWraper.Team = Team;
		askPBWraper.TeamType = TeamType;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcJoinTeamReplyWraper replyPBWraper = new WorldServerRpcJoinTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->LeaveTeam RPC请求
	*/
	public void LeaveTeam(int TeamId, UInt64 RoleId, int MemId, int SceneId, UInt64 NewLeaderRoleId, int Result, ReplyHandler replyCB)
	{
		WorldServerRpcLeaveTeamAskWraper askPBWraper = new WorldServerRpcLeaveTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.RoleId = RoleId;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.NewLeaderRoleId = NewLeaderRoleId;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcLeaveTeamReplyWraper replyPBWraper = new WorldServerRpcLeaveTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->AppointTeamLeader RPC请求
	*/
	public void AppointTeamLeader(UInt64 NewLeaderRoleId, int MemId, int SceneId, UInt64 CurLeaderRoleId, int TeamId, int Result, ReplyHandler replyCB)
	{
		WorldServerRpcAppointTeamLeaderAskWraper askPBWraper = new WorldServerRpcAppointTeamLeaderAskWraper();
		askPBWraper.NewLeaderRoleId = NewLeaderRoleId;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.CurLeaderRoleId = CurLeaderRoleId;
		askPBWraper.TeamId = TeamId;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcAppointTeamLeaderReplyWraper replyPBWraper = new WorldServerRpcAppointTeamLeaderReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->DismissTeam RPC请求
	*/
	public void DismissTeam(int SceneId, int MemId, UInt64 RoleId, int TeamId, int Result, ReplyHandler replyCB)
	{
		WorldServerRpcDismissTeamAskWraper askPBWraper = new WorldServerRpcDismissTeamAskWraper();
		askPBWraper.SceneId = SceneId;
		askPBWraper.MemId = MemId;
		askPBWraper.RoleId = RoleId;
		askPBWraper.TeamId = TeamId;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcDismissTeamReplyWraper replyPBWraper = new WorldServerRpcDismissTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->KickMember RPC请求
	*/
	public void KickMember(UInt64 KickMemberRoleId, int MemId, int SceneId, int TeamId, UInt64 LeaderRoleId, int Result, ReplyHandler replyCB)
	{
		WorldServerRpcKickMemberAskWraper askPBWraper = new WorldServerRpcKickMemberAskWraper();
		askPBWraper.KickMemberRoleId = KickMemberRoleId;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.TeamId = TeamId;
		askPBWraper.LeaderRoleId = LeaderRoleId;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcKickMemberReplyWraper replyPBWraper = new WorldServerRpcKickMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->ApplyTeam RPC请求
	*/
	public void ApplyTeam(int TeamId, int Result, TeamMemberInfoWraper TeamMember, int MemId, int SceneId, ReplyHandler replyCB)
	{
		WorldServerRpcApplyTeamAskWraper askPBWraper = new WorldServerRpcApplyTeamAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.Result = Result;
		askPBWraper.TeamMember = TeamMember;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcApplyTeamReplyWraper replyPBWraper = new WorldServerRpcApplyTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->AgreeTeamApplicant RPC请求
	*/
	public void AgreeTeamApplicant(UInt64 RoleId, UInt64 LeaderRoleId, int Result, int MemId, int SceneId, TeamInfoWraper Team, ReplyHandler replyCB)
	{
		WorldServerRpcAgreeTeamApplicantAskWraper askPBWraper = new WorldServerRpcAgreeTeamApplicantAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.LeaderRoleId = LeaderRoleId;
		askPBWraper.Result = Result;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.Team = Team;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcAgreeTeamApplicantReplyWraper replyPBWraper = new WorldServerRpcAgreeTeamApplicantReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->Login RPC请求
	*/
	public void Login(TeamInfoWraper Team, int MemId, int SceneId, OnlineUserInfoWraper RoleInfo, ReplyHandler replyCB)
	{
		WorldServerRpcLoginAskWraper askPBWraper = new WorldServerRpcLoginAskWraper();
		askPBWraper.Team = Team;
		askPBWraper.MemId = MemId;
		askPBWraper.SceneId = SceneId;
		askPBWraper.RoleInfo = RoleInfo;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_LOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcLoginReplyWraper replyPBWraper = new WorldServerRpcLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->UpdateRoleInfo RPC请求
	*/
	public void UpdateRoleInfo(OnlineUserInfoWraper RoleInfo, ReplyHandler replyCB)
	{
		WorldServerRpcUpdateRoleInfoAskWraper askPBWraper = new WorldServerRpcUpdateRoleInfoAskWraper();
		askPBWraper.RoleInfo = RoleInfo;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcUpdateRoleInfoReplyWraper replyPBWraper = new WorldServerRpcUpdateRoleInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->Logout RPC请求
	*/
	public void Logout(OnlineUserInfoWraper RoleInfo, ReplyHandler replyCB)
	{
		WorldServerRpcLogoutAskWraper askPBWraper = new WorldServerRpcLogoutAskWraper();
		askPBWraper.RoleInfo = RoleInfo;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_LOGOUT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcLogoutReplyWraper replyPBWraper = new WorldServerRpcLogoutReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->CreateDungeonNotify RPC请求
	*/
	public void CreateDungeonNotify(int CurSceneId, UInt64 RoleId, int MemId, int TargetSceneId, ReplyHandler replyCB)
	{
		WorldServerRpcCreateDungeonNotifyAskWraper askPBWraper = new WorldServerRpcCreateDungeonNotifyAskWraper();
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.RoleId = RoleId;
		askPBWraper.MemId = MemId;
		askPBWraper.TargetSceneId = TargetSceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcCreateDungeonNotifyReplyWraper replyPBWraper = new WorldServerRpcCreateDungeonNotifyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->ExitDungeon RPC请求
	*/
	public void ExitDungeon(UInt64 RoleId, ReplyHandler replyCB)
	{
		WorldServerRpcExitDungeonAskWraper askPBWraper = new WorldServerRpcExitDungeonAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcExitDungeonReplyWraper replyPBWraper = new WorldServerRpcExitDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->ReleaseDungeon RPC请求
	*/
	public void ReleaseDungeon(ReplyHandler replyCB)
	{
		WorldServerRpcReleaseDungeonAskWraper askPBWraper = new WorldServerRpcReleaseDungeonAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcReleaseDungeonReplyWraper replyPBWraper = new WorldServerRpcReleaseDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class WorldServerData
{
	public enum SyncIdE
	{

	}
	
	private static WorldServerData m_Instance = null;
	public static WorldServerData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldServerData();
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
			Ex.Logger.Log("WorldServerData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
