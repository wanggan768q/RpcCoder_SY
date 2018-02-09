/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleWG.cs
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


public class WGRPC
{
	public const int ModuleId = 11;
	
	public const int RPC_CODE_WG_INFORMCREATETEAM_REQUEST = 1151;
	public const int RPC_CODE_WG_INFORMJOINTEAM_REQUEST = 1152;
	public const int RPC_CODE_WG_INFORMLEAVE_REQUEST = 1153;
	public const int RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST = 1154;
	public const int RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST = 1155;
	public const int RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST = 1156;
	public const int RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST = 1157;
	public const int RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST = 1158;
	public const int RPC_CODE_WG_INFORMLOGIN_REQUEST = 1159;

	
	private static WGRPC m_Instance = null;
	public static WGRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WGRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, WGData.Instance.UpdateField );
		


		return true;
	}


	/**
	*WG-->InformCreateTeam RPC请求
	*/
	public void InformCreateTeam(TeamInfoWraper Team, int Result, ReplyHandler replyCB)
	{
		WGRpcInformCreateTeamAskWraper askPBWraper = new WGRpcInformCreateTeamAskWraper();
		askPBWraper.Team = Team;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMCREATETEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformCreateTeamReplyWraper replyPBWraper = new WGRpcInformCreateTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformJoinTeam RPC请求
	*/
	public void InformJoinTeam(TeamMemberInfoWraper Member, TeamInfoWraper Team, ReplyHandler replyCB)
	{
		WGRpcInformJoinTeamAskWraper askPBWraper = new WGRpcInformJoinTeamAskWraper();
		askPBWraper.Member = Member;
		askPBWraper.Team = Team;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMJOINTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformJoinTeamReplyWraper replyPBWraper = new WGRpcInformJoinTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformLeave RPC请求
	*/
	public void InformLeave(UInt64 RoleId, UInt64 NewLeaderRoleId, int Result, ReplyHandler replyCB)
	{
		WGRpcInformLeaveAskWraper askPBWraper = new WGRpcInformLeaveAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.NewLeaderRoleId = NewLeaderRoleId;
		askPBWraper.Result = Result;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMLEAVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformLeaveReplyWraper replyPBWraper = new WGRpcInformLeaveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformAppointTeamLeader RPC请求
	*/
	public void InformAppointTeamLeader(int Result, UInt64 NewLeaderRoleId, UInt64 OldLeaderRoleId, ReplyHandler replyCB)
	{
		WGRpcInformAppointTeamLeaderAskWraper askPBWraper = new WGRpcInformAppointTeamLeaderAskWraper();
		askPBWraper.Result = Result;
		askPBWraper.NewLeaderRoleId = NewLeaderRoleId;
		askPBWraper.OldLeaderRoleId = OldLeaderRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformAppointTeamLeaderReplyWraper replyPBWraper = new WGRpcInformAppointTeamLeaderReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformKickTeamMember RPC请求
	*/
	public void InformKickTeamMember(int Result, UInt64 KickedMemberRoleId, UInt64 LeaderRoleId, ReplyHandler replyCB)
	{
		WGRpcInformKickTeamMemberAskWraper askPBWraper = new WGRpcInformKickTeamMemberAskWraper();
		askPBWraper.Result = Result;
		askPBWraper.KickedMemberRoleId = KickedMemberRoleId;
		askPBWraper.LeaderRoleId = LeaderRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformKickTeamMemberReplyWraper replyPBWraper = new WGRpcInformKickTeamMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformDissmissTeam RPC请求
	*/
	public void InformDissmissTeam(int Result, UInt64 LeaderRoleId, ReplyHandler replyCB)
	{
		WGRpcInformDissmissTeamAskWraper askPBWraper = new WGRpcInformDissmissTeamAskWraper();
		askPBWraper.Result = Result;
		askPBWraper.LeaderRoleId = LeaderRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformDissmissTeamReplyWraper replyPBWraper = new WGRpcInformDissmissTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformApply RPC请求
	*/
	public void InformApplyTeam(TeamMemberInfoWraper TeamMember, int Result, int TeamId, ReplyHandler replyCB)
	{
		WGRpcInformApplyTeamAskWraper askPBWraper = new WGRpcInformApplyTeamAskWraper();
		askPBWraper.TeamMember = TeamMember;
		askPBWraper.Result = Result;
		askPBWraper.TeamId = TeamId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformApplyTeamReplyWraper replyPBWraper = new WGRpcInformApplyTeamReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->AgreeTeamApplicant RPC请求
	*/
	public void AgreeTeamApplicant(TeamInfoWraper Team, ReplyHandler replyCB)
	{
		WGRpcAgreeTeamApplicantAskWraper askPBWraper = new WGRpcAgreeTeamApplicantAskWraper();
		askPBWraper.Team = Team;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcAgreeTeamApplicantReplyWraper replyPBWraper = new WGRpcAgreeTeamApplicantReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*WG-->InformLogin RPC请求
	*/
	public void InformLogin(TeamInfoWraper Team, ReplyHandler replyCB)
	{
		WGRpcInformLoginAskWraper askPBWraper = new WGRpcInformLoginAskWraper();
		askPBWraper.Team = Team;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WG_INFORMLOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WGRpcInformLoginReplyWraper replyPBWraper = new WGRpcInformLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class WGData
{
	public enum SyncIdE
	{

	}
	
	private static WGData m_Instance = null;
	public static WGData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WGData();
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
			Ex.Logger.Log("WGData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
