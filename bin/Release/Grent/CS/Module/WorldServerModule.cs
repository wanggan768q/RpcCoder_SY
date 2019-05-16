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
	
	public const int RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST = 851;
	public const int RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST = 852;
	public const int RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST = 853;
	public const int RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST = 854;
	public const int RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST = 855;
	public const int RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST = 856;
	public const int RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST = 857;
	public const int RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST = 858;
	public const int RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST = 859;
	public const int RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST = 860;
	public const int RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST = 861;
	public const int RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST = 862;

	
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
	*世界服务器模块-->CreateDungeonNotify RPC请求
	*/
	public void CreateDungeonNotify(int CurSceneId, UInt64 RoleId, int TargetSceneId, ReplyHandler replyCB)
	{
		WorldServerRpcCreateDungeonNotifyAskWraper askPBWraper = new WorldServerRpcCreateDungeonNotifyAskWraper();
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.RoleId = RoleId;
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
	*世界服务器模块-->UpdateTeamInfo RPC请求
	*/
	public void UpdateTeamInfo(TeamMemberInfoWraper TeamMember, UInt64 RoleId, TeamInfoWraper Team, int TeamType, ReplyHandler replyCB)
	{
		WorldServerRpcUpdateTeamInfoAskWraper askPBWraper = new WorldServerRpcUpdateTeamInfoAskWraper();
		askPBWraper.TeamMember = TeamMember;
		askPBWraper.RoleId = RoleId;
		askPBWraper.Team = Team;
		askPBWraper.TeamType = TeamType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcUpdateTeamInfoReplyWraper replyPBWraper = new WorldServerRpcUpdateTeamInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->播放动画 队伍 RPC请求
	*/
	public void PlayCgTeam(UInt64 PlayRoleId, int CgId, int State, UInt64 RoleId, ReplyHandler replyCB)
	{
		WorldServerRpcPlayCgTeamAskWraper askPBWraper = new WorldServerRpcPlayCgTeamAskWraper();
		askPBWraper.PlayRoleId = PlayRoleId;
		askPBWraper.CgId = CgId;
		askPBWraper.State = State;
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcPlayCgTeamReplyWraper replyPBWraper = new WorldServerRpcPlayCgTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->发送邮件 RPC请求
	*/
	public void SendMail(MailInfoWraper Mail, UInt64 GlobalMailID, ReplyHandler replyCB)
	{
		WorldServerRpcSendMailAskWraper askPBWraper = new WorldServerRpcSendMailAskWraper();
		askPBWraper.Mail = Mail;
		askPBWraper.GlobalMailID = GlobalMailID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcSendMailReplyWraper replyPBWraper = new WorldServerRpcSendMailReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->改变队伍类型 RPC请求
	*/
	public void ChangeTeamType(UInt64 TeamId, UInt64 RoleId, int Result, int TeamType, TeamTargetWraper Target, ReplyHandler replyCB)
	{
		WorldServerRpcChangeTeamTypeAskWraper askPBWraper = new WorldServerRpcChangeTeamTypeAskWraper();
		askPBWraper.TeamId = TeamId;
		askPBWraper.RoleId = RoleId;
		askPBWraper.Result = Result;
		askPBWraper.TeamType = TeamType;
		askPBWraper.Target = Target;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcChangeTeamTypeReplyWraper replyPBWraper = new WorldServerRpcChangeTeamTypeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->自动匹配 RPC请求
	*/
	public void AutoMatch(TeamMemberInfoWraper MemberInfo, PlayerMatchDataWraper MatchInfo, int Result, ReplyHandler replyCB)
	{
		WorldServerRpcAutoMatchAskWraper askPBWraper = new WorldServerRpcAutoMatchAskWraper();
		askPBWraper.MemberInfo = MemberInfo;
		askPBWraper.MatchInfo = MatchInfo;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcAutoMatchReplyWraper replyPBWraper = new WorldServerRpcAutoMatchReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->取消匹配 RPC请求
	*/
	public void CancelMatch(UInt64 RoleId, int Result, int IsNotify, ReplyHandler replyCB)
	{
		WorldServerRpcCancelMatchAskWraper askPBWraper = new WorldServerRpcCancelMatchAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.Result = Result;
		askPBWraper.IsNotify = IsNotify;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcCancelMatchReplyWraper replyPBWraper = new WorldServerRpcCancelMatchReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->登录服务器 RPC请求
	*/
	public void LoginGameServer(TeamInfoWraper Team, OnlineUserInfoWraper RoleInfo, CharacterLocationWraper Location, ReplyHandler replyCB)
	{
		WorldServerRpcLoginGameServerAskWraper askPBWraper = new WorldServerRpcLoginGameServerAskWraper();
		askPBWraper.Team = Team;
		askPBWraper.RoleInfo = RoleInfo;
		askPBWraper.Location = Location;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcLoginGameServerReplyWraper replyPBWraper = new WorldServerRpcLoginGameServerReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->LoginGameServer RPC请求
	*/
	public void LogoutGameServer(int Result, OnlineUserInfoWraper RoleInfo, ReplyHandler replyCB)
	{
		WorldServerRpcLogoutGameServerAskWraper askPBWraper = new WorldServerRpcLogoutGameServerAskWraper();
		askPBWraper.Result = Result;
		askPBWraper.RoleInfo = RoleInfo;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcLogoutGameServerReplyWraper replyPBWraper = new WorldServerRpcLogoutGameServerReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->获取玩家信息 RPC请求
	*/
	public void GetPlayerInfo(UInt64 Player_guid, ReplyHandler replyCB)
	{
		WorldServerRpcGetPlayerInfoAskWraper askPBWraper = new WorldServerRpcGetPlayerInfoAskWraper();
		askPBWraper.Player_guid = Player_guid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcGetPlayerInfoReplyWraper replyPBWraper = new WorldServerRpcGetPlayerInfoReplyWraper();
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
