/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleGuild.cs
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


public class GuildRPC
{
	public const int ModuleId = 38;
	
	public const int RPC_CODE_GUILD_GUILDBASEINFO_REQUEST = 3851;
	public const int RPC_CODE_GUILD_KICKMEMBER_REQUEST = 3852;
	public const int RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY = 3853;
	public const int RPC_CODE_GUILD_ASKVACATION_REQUEST = 3854;
	public const int RPC_CODE_GUILD_VACATION_NOTIFY = 3855;
	public const int RPC_CODE_GUILD_REPLYVACATION_NOTIFY = 3856;
	public const int RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST = 3857;
	public const int RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST = 3858;
	public const int RPC_CODE_GUILD_APPLYGUILD_NOTIFY = 3859;
	public const int RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST = 3860;
	public const int RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST = 3861;
	public const int RPC_CODE_GUILD_SETJURISDICTION_REQUEST = 3862;
	public const int RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST = 3863;
	public const int RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST = 3864;
	public const int RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY = 3865;
	public const int RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST = 3866;
	public const int RPC_CODE_GUILD_BUILDINGLVUP_REQUEST = 3867;
	public const int RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST = 3868;
	public const int RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST = 3869;
	public const int RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY = 3870;
	public const int RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST = 3871;
	public const int RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST = 3872;
	public const int RPC_CODE_GUILD_SEARCHGUILD_REQUEST = 3873;
	public const int RPC_CODE_GUILD_JOINGUILD_REQUEST = 3874;
	public const int RPC_CODE_GUILD_CREATEGUILD_REQUEST = 3875;
	public const int RPC_CODE_GUILD_CHANGEFLAG_REQUEST = 3876;
	public const int RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST = 3877;
	public const int RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST = 3878;
	public const int RPC_CODE_GUILD_QUITEGUILD_REQUEST = 3879;
	public const int RPC_CODE_GUILD_SETOFFICE_REQUEST = 3880;
	public const int RPC_CODE_GUILD_OFFICECHANGE_NOTIFY = 3881;
	public const int RPC_CODE_GUILD_CHANGECREED_REQUEST = 3882;
	public const int RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST = 3883;
	public const int RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY = 3884;
	public const int RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY = 3885;

	
	private static GuildRPC m_Instance = null;
	public static GuildRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GuildRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, GuildData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY, KickMemberNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_VACATION_NOTIFY, VacationCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_REPLYVACATION_NOTIFY, ReplyVacationCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_APPLYGUILD_NOTIFY, ApplyGuildCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY, ApplyGuildToOfficeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY, BuildingCanLvUpCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_OFFICECHANGE_NOTIFY, OfficeChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY, BuildLvUpCompleteCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY, GuildCurrencyChangeCB);


		return true;
	}


	/**
	*公会-->公会基本信息 RPC请求
	*/
	public void GuildBaseInfo(ReplyHandler replyCB)
	{
		GuildRpcGuildBaseInfoAskWraper askPBWraper = new GuildRpcGuildBaseInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_GUILDBASEINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcGuildBaseInfoReplyWraper replyPBWraper = new GuildRpcGuildBaseInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->逐出成员 RPC请求
	*/
	public void KickMember(int Guid, string KickReason, int ReasonType, ReplyHandler replyCB)
	{
		GuildRpcKickMemberAskWraper askPBWraper = new GuildRpcKickMemberAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.KickReason = KickReason;
		askPBWraper.ReasonType = ReasonType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_KICKMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcKickMemberReplyWraper replyPBWraper = new GuildRpcKickMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->请假或取消申请 RPC请求
	*/
	public void AskVacation(int Guid, string Reason, int Type, ReplyHandler replyCB)
	{
		GuildRpcAskVacationAskWraper askPBWraper = new GuildRpcAskVacationAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.Reason = Reason;
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKVACATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskVacationReplyWraper replyPBWraper = new GuildRpcAskVacationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->请求公会申请列表 RPC请求
	*/
	public void AskApplyList(ReplyHandler replyCB)
	{
		GuildRpcAskApplyListAskWraper askPBWraper = new GuildRpcAskApplyListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskApplyListReplyWraper replyPBWraper = new GuildRpcAskApplyListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->入会操作 RPC请求
	*/
	public void ApplyGuildOperation(UInt64 Guid, int Operation, ReplyHandler replyCB)
	{
		GuildRpcApplyGuildOperationAskWraper askPBWraper = new GuildRpcApplyGuildOperationAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.Operation = Operation;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcApplyGuildOperationReplyWraper replyPBWraper = new GuildRpcApplyGuildOperationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->限制入会条件 RPC请求
	*/
	public void ApplyLimitSetting(bool IsAutoJoin, ReplyHandler replyCB)
	{
		GuildRpcApplyLimitSettingAskWraper askPBWraper = new GuildRpcApplyLimitSettingAskWraper();
		askPBWraper.IsAutoJoin = IsAutoJoin;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcApplyLimitSettingReplyWraper replyPBWraper = new GuildRpcApplyLimitSettingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->权限列表申请 RPC请求
	*/
	public void AskJurisdictionList(ReplyHandler replyCB)
	{
		GuildRpcAskJurisdictionListAskWraper askPBWraper = new GuildRpcAskJurisdictionListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskJurisdictionListReplyWraper replyPBWraper = new GuildRpcAskJurisdictionListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->设置权限 RPC请求
	*/
	public void SetJurisdiction(GuildOfficeJurisdictionWraper SetList, ReplyHandler replyCB)
	{
		GuildRpcSetJurisdictionAskWraper askPBWraper = new GuildRpcSetJurisdictionAskWraper();
		askPBWraper.SetList = SetList;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_SETJURISDICTION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcSetJurisdictionReplyWraper replyPBWraper = new GuildRpcSetJurisdictionReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->请假审批列表 RPC请求
	*/
	public void AskVacationList(ReplyHandler replyCB)
	{
		GuildRpcAskVacationListAskWraper askPBWraper = new GuildRpcAskVacationListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskVacationListReplyWraper replyPBWraper = new GuildRpcAskVacationListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->请假操作 RPC请求
	*/
	public void VacationGuildOperation(UInt64 Guid, int Operation, ReplyHandler replyCB)
	{
		GuildRpcVacationGuildOperationAskWraper askPBWraper = new GuildRpcVacationGuildOperationAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.Operation = Operation;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcVacationGuildOperationReplyWraper replyPBWraper = new GuildRpcVacationGuildOperationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->请求公会建筑信息 RPC请求
	*/
	public void AskBuildingInfo(ReplyHandler replyCB)
	{
		GuildRpcAskBuildingInfoAskWraper askPBWraper = new GuildRpcAskBuildingInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskBuildingInfoReplyWraper replyPBWraper = new GuildRpcAskBuildingInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->公会建筑升级 RPC请求
	*/
	public void BuildingLvUp(int BuildingType, ReplyHandler replyCB)
	{
		GuildRpcBuildingLvUpAskWraper askPBWraper = new GuildRpcBuildingLvUpAskWraper();
		askPBWraper.BuildingType = BuildingType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_BUILDINGLVUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcBuildingLvUpReplyWraper replyPBWraper = new GuildRpcBuildingLvUpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->公会建筑加速升级 RPC请求
	*/
	public void BuildingLvSpeedUp(int BuildingType, int Time, ReplyHandler replyCB)
	{
		GuildRpcBuildingLvSpeedUpAskWraper askPBWraper = new GuildRpcBuildingLvSpeedUpAskWraper();
		askPBWraper.BuildingType = BuildingType;
		askPBWraper.Time = Time;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcBuildingLvSpeedUpReplyWraper replyPBWraper = new GuildRpcBuildingLvSpeedUpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->建筑贡献榜请求 RPC请求
	*/
	public void AskBuildingContributionList(int BuildingType, ReplyHandler replyCB)
	{
		GuildRpcAskBuildingContributionListAskWraper askPBWraper = new GuildRpcAskBuildingContributionListAskWraper();
		askPBWraper.BuildingType = BuildingType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskBuildingContributionListReplyWraper replyPBWraper = new GuildRpcAskBuildingContributionListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->获取公会事件列表 RPC请求
	*/
	public void AskGuildEventList(ReplyHandler replyCB)
	{
		GuildRpcAskGuildEventListAskWraper askPBWraper = new GuildRpcAskGuildEventListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskGuildEventListReplyWraper replyPBWraper = new GuildRpcAskGuildEventListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->获取公会列表 RPC请求
	*/
	public void AskGuildInfoList(int PageIndex, ReplyHandler replyCB)
	{
		GuildRpcAskGuildInfoListAskWraper askPBWraper = new GuildRpcAskGuildInfoListAskWraper();
		askPBWraper.PageIndex = PageIndex;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskGuildInfoListReplyWraper replyPBWraper = new GuildRpcAskGuildInfoListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->搜索公会 RPC请求
	*/
	public void SearchGuild(string Text, ReplyHandler replyCB)
	{
		GuildRpcSearchGuildAskWraper askPBWraper = new GuildRpcSearchGuildAskWraper();
		askPBWraper.Text = Text;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_SEARCHGUILD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcSearchGuildReplyWraper replyPBWraper = new GuildRpcSearchGuildReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->申请入会 RPC请求
	*/
	public void JoinGuild(UInt64 Guid, int Type, ReplyHandler replyCB)
	{
		GuildRpcJoinGuildAskWraper askPBWraper = new GuildRpcJoinGuildAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_JOINGUILD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcJoinGuildReplyWraper replyPBWraper = new GuildRpcJoinGuildReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->建立公会 RPC请求
	*/
	public void CreateGuild(string GuildName, string GuildCreed, ReplyHandler replyCB)
	{
		GuildRpcCreateGuildAskWraper askPBWraper = new GuildRpcCreateGuildAskWraper();
		askPBWraper.GuildName = GuildName;
		askPBWraper.GuildCreed = GuildCreed;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_CREATEGUILD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcCreateGuildReplyWraper replyPBWraper = new GuildRpcCreateGuildReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->更换公会旗帜 RPC请求
	*/
	public void ChangeFlag(int FlagConfigID, ReplyHandler replyCB)
	{
		GuildRpcChangeFlagAskWraper askPBWraper = new GuildRpcChangeFlagAskWraper();
		askPBWraper.FlagConfigID = FlagConfigID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_CHANGEFLAG_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcChangeFlagReplyWraper replyPBWraper = new GuildRpcChangeFlagReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->公会改名 RPC请求
	*/
	public void GuildChangeName(string GuildNewName, ReplyHandler replyCB)
	{
		GuildRpcGuildChangeNameAskWraper askPBWraper = new GuildRpcGuildChangeNameAskWraper();
		askPBWraper.GuildNewName = GuildNewName;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcGuildChangeNameReplyWraper replyPBWraper = new GuildRpcGuildChangeNameReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->获取公会成员列表 RPC请求
	*/
	public void AskGuildMember(ReplyHandler replyCB)
	{
		GuildRpcAskGuildMemberAskWraper askPBWraper = new GuildRpcAskGuildMemberAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcAskGuildMemberReplyWraper replyPBWraper = new GuildRpcAskGuildMemberReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->退出公会 RPC请求
	*/
	public void QuiteGuild(ReplyHandler replyCB)
	{
		GuildRpcQuiteGuildAskWraper askPBWraper = new GuildRpcQuiteGuildAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_QUITEGUILD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcQuiteGuildReplyWraper replyPBWraper = new GuildRpcQuiteGuildReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->设置职位 RPC请求
	*/
	public void SetOffice(UInt64 Guid, UInt64 TargetGuid, int OfficeType, ReplyHandler replyCB)
	{
		GuildRpcSetOfficeAskWraper askPBWraper = new GuildRpcSetOfficeAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.TargetGuid = TargetGuid;
		askPBWraper.OfficeType = OfficeType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_SETOFFICE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcSetOfficeReplyWraper replyPBWraper = new GuildRpcSetOfficeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->修改帮会宗旨 RPC请求
	*/
	public void ChangeCreed(string Content, ReplyHandler replyCB)
	{
		GuildRpcChangeCreedAskWraper askPBWraper = new GuildRpcChangeCreedAskWraper();
		askPBWraper.Content = Content;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_CHANGECREED_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcChangeCreedReplyWraper replyPBWraper = new GuildRpcChangeCreedReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*公会-->公会禁言 RPC请求
	*/
	public void ForbiddenChat(Int64 Playerguid, bool IsForbidden, ReplyHandler replyCB)
	{
		GuildRpcForbiddenChatAskWraper askPBWraper = new GuildRpcForbiddenChatAskWraper();
		askPBWraper.Playerguid = Playerguid;
		askPBWraper.IsForbidden = IsForbidden;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GuildRpcForbiddenChatReplyWraper replyPBWraper = new GuildRpcForbiddenChatReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*公会-->逐出公会推送 服务器通知回调
	*/
	public static void KickMemberNotifyCB( ModMessage notifyMsg )
	{
		GuildRpcKickMemberNotifyNotifyWraper notifyPBWraper = new GuildRpcKickMemberNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( KickMemberNotifyCBDelegate != null )
			KickMemberNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback KickMemberNotifyCBDelegate = null;
	/**
	*公会-->请假广播（广播给管理者） 服务器通知回调
	*/
	public static void VacationCB( ModMessage notifyMsg )
	{
		GuildRpcVacationNotifyWraper notifyPBWraper = new GuildRpcVacationNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( VacationCBDelegate != null )
			VacationCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback VacationCBDelegate = null;
	/**
	*公会-->请假广播（广播给请假人） 服务器通知回调
	*/
	public static void ReplyVacationCB( ModMessage notifyMsg )
	{
		GuildRpcReplyVacationNotifyWraper notifyPBWraper = new GuildRpcReplyVacationNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReplyVacationCBDelegate != null )
			ReplyVacationCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReplyVacationCBDelegate = null;
	/**
	*公会-->申请入会推送（推送给申请者） 服务器通知回调
	*/
	public static void ApplyGuildCB( ModMessage notifyMsg )
	{
		GuildRpcApplyGuildNotifyWraper notifyPBWraper = new GuildRpcApplyGuildNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ApplyGuildCBDelegate != null )
			ApplyGuildCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ApplyGuildCBDelegate = null;
	/**
	*公会-->申请推送（广播给管理者） 服务器通知回调
	*/
	public static void ApplyGuildToOfficeCB( ModMessage notifyMsg )
	{
		GuildRpcApplyGuildToOfficeNotifyWraper notifyPBWraper = new GuildRpcApplyGuildToOfficeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ApplyGuildToOfficeCBDelegate != null )
			ApplyGuildToOfficeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ApplyGuildToOfficeCBDelegate = null;
	/**
	*公会-->建筑可升级推送（推送管理者） 服务器通知回调
	*/
	public static void BuildingCanLvUpCB( ModMessage notifyMsg )
	{
		GuildRpcBuildingCanLvUpNotifyWraper notifyPBWraper = new GuildRpcBuildingCanLvUpNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BuildingCanLvUpCBDelegate != null )
			BuildingCanLvUpCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BuildingCanLvUpCBDelegate = null;
	/**
	*公会-->职位变化推送 服务器通知回调
	*/
	public static void OfficeChangeCB( ModMessage notifyMsg )
	{
		GuildRpcOfficeChangeNotifyWraper notifyPBWraper = new GuildRpcOfficeChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OfficeChangeCBDelegate != null )
			OfficeChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OfficeChangeCBDelegate = null;
	/**
	*公会-->建筑升级完成 服务器通知回调
	*/
	public static void BuildLvUpCompleteCB( ModMessage notifyMsg )
	{
		GuildRpcBuildLvUpCompleteNotifyWraper notifyPBWraper = new GuildRpcBuildLvUpCompleteNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BuildLvUpCompleteCBDelegate != null )
			BuildLvUpCompleteCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BuildLvUpCompleteCBDelegate = null;
	/**
	*公会-->公会货币变化推送 服务器通知回调
	*/
	public static void GuildCurrencyChangeCB( ModMessage notifyMsg )
	{
		GuildRpcGuildCurrencyChangeNotifyWraper notifyPBWraper = new GuildRpcGuildCurrencyChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( GuildCurrencyChangeCBDelegate != null )
			GuildCurrencyChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback GuildCurrencyChangeCBDelegate = null;



}

public class GuildData
{
	public enum SyncIdE
	{

	}
	
	private static GuildData m_Instance = null;
	public static GuildData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GuildData();
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
			Ex.Logger.Log("GuildData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
