ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcKickMemberNotifyNotifyCB = null
RpcVacationNotifyCB = null
RpcReplyVacationNotifyCB = null
RpcApplyGuildNotifyCB = null
RpcApplyGuildToOfficeNotifyCB = null
RpcBuildingCanLvUpNotifyCB = null
RpcOfficeChangeNotifyCB = null
RpcBuildLvUpCompleteNotifyCB = null
RpcGuildCurrencyChangeNotifyCB = null


ModuleId = 38
RPC_CODE_GUILDBASEINFO_REQUEST = 3851
RPC_CODE_KICKMEMBER_REQUEST = 3852
RPC_CODE_KICKMEMBERNOTIFY_NOTIFY = 3853
RPC_CODE_ASKVACATION_REQUEST = 3854
RPC_CODE_VACATION_NOTIFY = 3855
RPC_CODE_REPLYVACATION_NOTIFY = 3856
RPC_CODE_ASKAPPLYLIST_REQUEST = 3857
RPC_CODE_APPLYGUILDOPERATION_REQUEST = 3858
RPC_CODE_APPLYGUILD_NOTIFY = 3859
RPC_CODE_APPLYLIMITSETTING_REQUEST = 3860
RPC_CODE_ASKJURISDICTIONLIST_REQUEST = 3861
RPC_CODE_SETJURISDICTION_REQUEST = 3862
RPC_CODE_ASKVACATIONLIST_REQUEST = 3863
RPC_CODE_VACATIONGUILDOPERATION_REQUEST = 3864
RPC_CODE_APPLYGUILDTOOFFICE_NOTIFY = 3865
RPC_CODE_ASKBUILDINGINFO_REQUEST = 3866
RPC_CODE_BUILDINGLVUP_REQUEST = 3867
RPC_CODE_BUILDINGLVSPEEDUP_REQUEST = 3868
RPC_CODE_ASKBUILDINGCONTRIBUTIONLIST_REQUEST = 3869
RPC_CODE_BUILDINGCANLVUP_NOTIFY = 3870
RPC_CODE_ASKGUILDEVENTLIST_REQUEST = 3871
RPC_CODE_ASKGUILDINFOLIST_REQUEST = 3872
RPC_CODE_SEARCHGUILD_REQUEST = 3873
RPC_CODE_JOINGUILD_REQUEST = 3874
RPC_CODE_CREATEGUILD_REQUEST = 3875
RPC_CODE_CHANGEFLAG_REQUEST = 3876
RPC_CODE_GUILDCHANGENAME_REQUEST = 3877
RPC_CODE_ASKGUILDMEMBER_REQUEST = 3878
RPC_CODE_QUITEGUILD_REQUEST = 3879
RPC_CODE_SETOFFICE_REQUEST = 3880
RPC_CODE_OFFICECHANGE_NOTIFY = 3881
RPC_CODE_CHANGECREED_REQUEST = 3882
RPC_CODE_FORBIDDENCHAT_REQUEST = 3883
RPC_CODE_BUILDLVUPCOMPLETE_NOTIFY = 3884
RPC_CODE_GUILDCURRENCYCHANGE_NOTIFY = 3885

GuildBaseInfoAskPB = null
GuildBaseInfoReplyPB = null
KickMemberAskPB = null
KickMemberReplyPB = null
KickMemberNotifyNotifyPB = null
AskVacationAskPB = null
AskVacationReplyPB = null
VacationNotifyPB = null
ReplyVacationNotifyPB = null
AskApplyListAskPB = null
AskApplyListReplyPB = null
ApplyGuildOperationAskPB = null
ApplyGuildOperationReplyPB = null
ApplyGuildNotifyPB = null
ApplyLimitSettingAskPB = null
ApplyLimitSettingReplyPB = null
AskJurisdictionListAskPB = null
AskJurisdictionListReplyPB = null
SetJurisdictionAskPB = null
SetJurisdictionReplyPB = null
AskVacationListAskPB = null
AskVacationListReplyPB = null
VacationGuildOperationAskPB = null
VacationGuildOperationReplyPB = null
ApplyGuildToOfficeNotifyPB = null
AskBuildingInfoAskPB = null
AskBuildingInfoReplyPB = null
BuildingLvUpAskPB = null
BuildingLvUpReplyPB = null
BuildingLvSpeedUpAskPB = null
BuildingLvSpeedUpReplyPB = null
AskBuildingContributionListAskPB = null
AskBuildingContributionListReplyPB = null
BuildingCanLvUpNotifyPB = null
AskGuildEventListAskPB = null
AskGuildEventListReplyPB = null
AskGuildInfoListAskPB = null
AskGuildInfoListReplyPB = null
SearchGuildAskPB = null
SearchGuildReplyPB = null
JoinGuildAskPB = null
JoinGuildReplyPB = null
CreateGuildAskPB = null
CreateGuildReplyPB = null
ChangeFlagAskPB = null
ChangeFlagReplyPB = null
GuildChangeNameAskPB = null
GuildChangeNameReplyPB = null
AskGuildMemberAskPB = null
AskGuildMemberReplyPB = null
QuiteGuildAskPB = null
QuiteGuildReplyPB = null
SetOfficeAskPB = null
SetOfficeReplyPB = null
OfficeChangeNotifyPB = null
ChangeCreedAskPB = null
ChangeCreedReplyPB = null
ForbiddenChatAskPB = null
ForbiddenChatReplyPB = null
BuildLvUpCompleteNotifyPB = null
GuildCurrencyChangeNotifyPB = null

class GuildModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcGuildBaseInfoAsk
      {
      }
      message  GuildFlag
      {
        optional int32 FlagEquiped = 1[default=-1];
        repeated int32 FlagUnlocked = 2;
      }
      message  GuildNews
      {
        optional int32 OptionType = 3[default=-1];
        repeated string EventsParm = 4;
      }
      message  GuildInfo
      {
        optional uint64 Guid = 1[default=0];
        optional string GuildName = 2;
        optional string GuildLeader = 3;
        optional int32 GuildLevel = 4[default=-1];
        optional int32 MemberCount = 5[default=-1];
        optional int32 OnlineCount = 6[default=-1];
        optional int32 GuildProsper = 7[default=-1];
        optional int32 GuildMoney = 8[default=-1];
        optional int32 GuildResource = 9[default=-1];
        optional string GuildCreed = 10;
        optional GuildFlag Flag = 11;
        repeated GuildNews News = 12;
        optional bool IsAutoJoin = 13;
        optional string GuildOldName = 15;
        optional string GuildCreater = 16;
        optional int32 SelfOffice = 17[default=-1];
        optional int32 TotalCount = 18[default=-1];
        optional bool IsVacation = 19;
        optional bool HaveApplied = 20;
        optional int32 MaintainCost = 21[default=-1];
        optional int32 GuildWelfare = 22[default=-1];
      }
      message  RpcGuildBaseInfoReply
      {
        optional int32 Result = 1[default=-1];
        optional GuildInfo GuildBaseInfo = 2;
      }
      message  RpcKickMemberAsk
      {
        optional int32 Guid = 1[default=-1];
        optional string KickReason = 2;
        optional int32 ReasonType = 3[default=-1];
      }
      message  RpcKickMemberReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Guid = 2[default=-1];
        optional int32 OnlineCount = 3[default=-1];
        optional int32 MemberCount = 4[default=-1];
      }
      message  RpcKickMemberNotifyNotify
      {
        optional string KickReason = 1;
        optional int32 ReasonType = 2[default=-1];
      }
      message  RpcAskVacationAsk
      {
        optional int32 Guid = 1[default=-1];
        optional string Reason = 2;
        optional int32 Type = 4[default=-1];
      }
      message  RpcAskVacationReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Guid = 2[default=-1];
        optional int32 Type = 3[default=-1];
      }
      message  GuildVacationInfo
      {
        optional uint64 Guid = 1[default=0];
        optional string PlayerName = 3;
        optional int32 Level = 4[default=-1];
        optional string Reason = 5;
        optional uint64 LeftTime = 6[default=0];
      }
      message  RpcVacationNotify
      {
        optional GuildVacationInfo VacationInfo = 2;
        optional int32 Type = 3[default=-1];
      }
      message  RpcReplyVacationNotify
      {
      }
      message  RpcAskApplyListAsk
      {
      }
      message  GuildMemberTinyInfo
      {
        optional uint64 Guid = 1[default=0];
        optional string PlayerName = 2;
        optional int32 Occupition = 3[default=-1];
        optional int32 Level = 4[default=-1];
        optional int32 FightScore = 5[default=-1];
        optional int32 TotalContribute = 6[default=-1];
      }
      message  RpcAskApplyListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildMemberTinyInfo GuildMemberTinyInfoList = 2;
      }
      message  RpcApplyGuildOperationAsk
      {
        optional uint64 Guid = 1[default=0];
        optional int32 Operation = 2[default=-1];
      }
      message  GuildMemberInfo
      {
        optional int32 OfficeType = 3[default=-1];
        optional int32 WeekContribute = 4[default=-1];
        optional int32 HistoryContribute = 5[default=-1];
        optional int32 TotalContribute = 6[default=-1];
        optional int32 WeekQuestCount = 7[default=-1];
        optional int32 WeekCampCount = 8[default=-1];
        optional int64 InTime = 9[default=-1];
        optional GuildMemberTinyInfo GuildTinyInfo = 11;
        optional uint64 LeaveTime = 12[default=0];
        optional bool IsVacation = 13;
        optional bool IsForbiddenChat = 14;
      }
      message  RpcApplyGuildOperationReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Operation = 3[default=-1];
        repeated GuildMemberInfo MemberInfoList = 4;
        optional int32 OnlineCount = 5[default=-1];
        optional int32 MemberCount = 6[default=-1];
      }
      message  RpcApplyGuildNotify
      {
        optional uint64 GuildID = 1[default=0];
        optional string GuildName = 2;
      }
      message  RpcApplyLimitSettingAsk
      {
        optional bool IsAutoJoin = 1;
      }
      message  RpcApplyLimitSettingReply
      {
        optional int32 Result = 1[default=-1];
        optional bool IsAutoJoin = 2;
      }
      message  RpcAskJurisdictionListAsk
      {
      }
      message  GuildJurisdiction
      {
        optional int32 ConfigID = 1[default=-1];
        optional bool CurState = 2;
        optional bool IsCanSet = 3;
      }
      message  GuildOfficeJurisdiction
      {
        optional int32 OfficeType = 1[default=-1];
        repeated GuildJurisdiction JurisdictionList = 2;
      }
      message  RpcAskJurisdictionListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildOfficeJurisdiction JurisdictionList = 2;
      }
      message  RpcSetJurisdictionAsk
      {
        optional GuildOfficeJurisdiction SetList = 1;
      }
      message  RpcSetJurisdictionReply
      {
        optional int32 Result = 1[default=-1];
        optional GuildOfficeJurisdiction SetList = 2;
      }
      message  RpcAskVacationListAsk
      {
      }
      message  RpcAskVacationListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildVacationInfo VacationList = 2;
      }
      message  RpcVacationGuildOperationAsk
      {
        optional uint64 Guid = 2[default=0];
        optional int32 Operation = 3[default=-1];
      }
      message  RpcVacationGuildOperationReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 Guid = 2[default=0];
        optional int32 Operation = 3[default=-1];
      }
      message  RpcApplyGuildToOfficeNotify
      {
        optional GuildMemberTinyInfo GuildMemberTinyInfo = 1;
      }
      message  RpcAskBuildingInfoAsk
      {
      }
      message  GuildBuildingInfo
      {
        optional int32 BuildingType = 1[default=-1];
        optional int32 BuildingLv = 2[default=-1];
        optional uint64 LeftTime = 3[default=0];
      }
      message  RpcAskBuildingInfoReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildBuildingInfo BuildingInfoList = 2;
      }
      message  RpcBuildingLvUpAsk
      {
        optional int32 BuildingType = 2[default=-1];
      }
      message  RpcBuildingLvUpReply
      {
        optional int32 Result = 1[default=-1];
        optional GuildBuildingInfo GuildBuildingInfo = 2;
        optional int32 GuildMoney = 3[default=-1];
        optional int32 GuildResource = 4[default=-1];
      }
      message  RpcBuildingLvSpeedUpAsk
      {
        optional int32 BuildingType = 1[default=-1];
        optional int32 Time = 2[default=-1];
      }
      message  RpcBuildingLvSpeedUpReply
      {
        optional int32 Result = 1[default=-1];
        optional GuildBuildingInfo GuildBuildingInfo = 2;
      }
      message  RpcAskBuildingContributionListAsk
      {
        optional int32 BuildingType = 1[default=-1];
      }
      message  GuildBuildingContributionInfo
      {
        optional uint64 Guid = 2[default=0];
        optional string PlayerName = 3;
        optional int32 SpeedTime = 4[default=-1];
        optional uint64 Date = 5[default=0];
      }
      message  RpcAskBuildingContributionListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildBuildingContributionInfo ContributionList = 2;
        optional int32 BuildingType = 3[default=-1];
      }
      message  RpcBuildingCanLvUpNotify
      {
        optional int32 BuildingType = 2[default=-1];
      }
      message  RpcAskGuildEventListAsk
      {
      }
      message  GuildEvent
      {
        optional uint64 Guid = 2[default=0];
        optional uint64 Date = 4[default=0];
        optional int32 OptionType = 5[default=-1];
        repeated string EventsParm = 6;
      }
      message  RpcAskGuildEventListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildEvent GuildEventList = 2;
      }
      message  RpcAskGuildInfoListAsk
      {
        optional int32 PageIndex = 2[default=-1];
      }
      message  RpcAskGuildInfoListReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildInfo GuildInfoList = 2;
        optional int32 PageIndex = 3[default=-1];
        optional int32 TotalGuildCount = 4[default=-1];
      }
      message  RpcSearchGuildAsk
      {
        optional string Text = 1;
      }
      message  RpcSearchGuildReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildInfo GuildInfoList = 2;
      }
      message  RpcJoinGuildAsk
      {
        optional uint64 Guid = 1[default=0];
        optional int32 Type = 2[default=-1];
      }
      message  RpcJoinGuildReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 Guid = 2[default=0];
      }
      message  RpcCreateGuildAsk
      {
        optional string GuildName = 1;
        optional string GuildCreed = 2;
      }
      message  RpcCreateGuildReply
      {
        optional int32 Result = 1[default=-1];
        optional GuildInfo GuildBaseInfo = 2;
      }
      message  RpcChangeFlagAsk
      {
        optional int32 FlagConfigID = 1[default=-1];
      }
      message  RpcChangeFlagReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 GuildMoney = 2[default=-1];
        optional GuildFlag Flag = 5;
      }
      message  RpcGuildChangeNameAsk
      {
        optional string GuildNewName = 1;
      }
      message  RpcGuildChangeNameReply
      {
        optional int32 Result = 1[default=-1];
        optional string GuildNewName = 2;
        optional string GuildOldName = 3;
      }
      message  RpcAskGuildMemberAsk
      {
      }
      message  RpcAskGuildMemberReply
      {
        optional int32 Result = 1[default=-1];
        repeated GuildMemberInfo GuildMemberInfoList = 2;
        optional int32 OnlineCount = 3[default=-1];
        optional int32 MemberCount = 4[default=-1];
      }
      message  RpcQuiteGuildAsk
      {
      }
      message  RpcQuiteGuildReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcSetOfficeAsk
      {
        optional uint64 Guid = 1[default=0];
        optional uint64 TargetGuid = 2[default=0];
        optional int32 OfficeType = 3[default=-1];
      }
      message  RpcSetOfficeReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 SelfOfficeType = 2[default=-1];
        optional int32 TargetOfficeType = 4[default=-1];
        optional uint64 TargetGuid = 5[default=0];
      }
      message  RpcOfficeChangeNotify
      {
        optional int32 OfficeType = 1[default=-1];
        optional uint64 Optguid = 2[default=0];
        optional int32 OptOfficeType = 3[default=-1];
      }
      message  RpcChangeCreedAsk
      {
        optional string Content = 1;
      }
      message  RpcChangeCreedReply
      {
        optional int32 Result = 1[default=-1];
        optional string Content = 2;
      }
      message  RpcForbiddenChatAsk
      {
        optional int64 Playerguid = 1[default=-1];
        optional bool IsForbidden = 2;
      }
      message  RpcForbiddenChatReply
      {
        optional int32 Result = 1[default=-1];
        optional int64 Playerguid = 2[default=-1];
        optional bool IsForbidden = 3;
      }
      message  RpcBuildLvUpCompleteNotify
      {
        optional GuildBuildingInfo GuildBuildingInfo = 2;
      }
      message  RpcGuildCurrencyChangeNotify
      {
        optional int32 GuildProsper = 1[default=-1];
        optional int32 GuildMoney = 2[default=-1];
        optional int32 GuildResource = 3[default=-1];
        optional int32 GuildWelfare = 4[default=-1];
        optional int32 MaintainCost = 5[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    GuildBaseInfoAskPB = Proto.build("RpcGuildBaseInfoAsk")
    GuildBaseInfoReplyPB = Proto.build("RpcGuildBaseInfoReply")
    KickMemberAskPB = Proto.build("RpcKickMemberAsk")
    KickMemberReplyPB = Proto.build("RpcKickMemberReply")
    KickMemberNotifyNotifyPB = Proto.build("RpcKickMemberNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_KICKMEMBERNOTIFY_NOTIFY,@KickMemberNotifyCB)
    AskVacationAskPB = Proto.build("RpcAskVacationAsk")
    AskVacationReplyPB = Proto.build("RpcAskVacationReply")
    VacationNotifyPB = Proto.build("RpcVacationNotify")
    mLayerMgr.registerNotify(RPC_CODE_VACATION_NOTIFY,@VacationCB)
    ReplyVacationNotifyPB = Proto.build("RpcReplyVacationNotify")
    mLayerMgr.registerNotify(RPC_CODE_REPLYVACATION_NOTIFY,@ReplyVacationCB)
    AskApplyListAskPB = Proto.build("RpcAskApplyListAsk")
    AskApplyListReplyPB = Proto.build("RpcAskApplyListReply")
    ApplyGuildOperationAskPB = Proto.build("RpcApplyGuildOperationAsk")
    ApplyGuildOperationReplyPB = Proto.build("RpcApplyGuildOperationReply")
    ApplyGuildNotifyPB = Proto.build("RpcApplyGuildNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYGUILD_NOTIFY,@ApplyGuildCB)
    ApplyLimitSettingAskPB = Proto.build("RpcApplyLimitSettingAsk")
    ApplyLimitSettingReplyPB = Proto.build("RpcApplyLimitSettingReply")
    AskJurisdictionListAskPB = Proto.build("RpcAskJurisdictionListAsk")
    AskJurisdictionListReplyPB = Proto.build("RpcAskJurisdictionListReply")
    SetJurisdictionAskPB = Proto.build("RpcSetJurisdictionAsk")
    SetJurisdictionReplyPB = Proto.build("RpcSetJurisdictionReply")
    AskVacationListAskPB = Proto.build("RpcAskVacationListAsk")
    AskVacationListReplyPB = Proto.build("RpcAskVacationListReply")
    VacationGuildOperationAskPB = Proto.build("RpcVacationGuildOperationAsk")
    VacationGuildOperationReplyPB = Proto.build("RpcVacationGuildOperationReply")
    ApplyGuildToOfficeNotifyPB = Proto.build("RpcApplyGuildToOfficeNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYGUILDTOOFFICE_NOTIFY,@ApplyGuildToOfficeCB)
    AskBuildingInfoAskPB = Proto.build("RpcAskBuildingInfoAsk")
    AskBuildingInfoReplyPB = Proto.build("RpcAskBuildingInfoReply")
    BuildingLvUpAskPB = Proto.build("RpcBuildingLvUpAsk")
    BuildingLvUpReplyPB = Proto.build("RpcBuildingLvUpReply")
    BuildingLvSpeedUpAskPB = Proto.build("RpcBuildingLvSpeedUpAsk")
    BuildingLvSpeedUpReplyPB = Proto.build("RpcBuildingLvSpeedUpReply")
    AskBuildingContributionListAskPB = Proto.build("RpcAskBuildingContributionListAsk")
    AskBuildingContributionListReplyPB = Proto.build("RpcAskBuildingContributionListReply")
    BuildingCanLvUpNotifyPB = Proto.build("RpcBuildingCanLvUpNotify")
    mLayerMgr.registerNotify(RPC_CODE_BUILDINGCANLVUP_NOTIFY,@BuildingCanLvUpCB)
    AskGuildEventListAskPB = Proto.build("RpcAskGuildEventListAsk")
    AskGuildEventListReplyPB = Proto.build("RpcAskGuildEventListReply")
    AskGuildInfoListAskPB = Proto.build("RpcAskGuildInfoListAsk")
    AskGuildInfoListReplyPB = Proto.build("RpcAskGuildInfoListReply")
    SearchGuildAskPB = Proto.build("RpcSearchGuildAsk")
    SearchGuildReplyPB = Proto.build("RpcSearchGuildReply")
    JoinGuildAskPB = Proto.build("RpcJoinGuildAsk")
    JoinGuildReplyPB = Proto.build("RpcJoinGuildReply")
    CreateGuildAskPB = Proto.build("RpcCreateGuildAsk")
    CreateGuildReplyPB = Proto.build("RpcCreateGuildReply")
    ChangeFlagAskPB = Proto.build("RpcChangeFlagAsk")
    ChangeFlagReplyPB = Proto.build("RpcChangeFlagReply")
    GuildChangeNameAskPB = Proto.build("RpcGuildChangeNameAsk")
    GuildChangeNameReplyPB = Proto.build("RpcGuildChangeNameReply")
    AskGuildMemberAskPB = Proto.build("RpcAskGuildMemberAsk")
    AskGuildMemberReplyPB = Proto.build("RpcAskGuildMemberReply")
    QuiteGuildAskPB = Proto.build("RpcQuiteGuildAsk")
    QuiteGuildReplyPB = Proto.build("RpcQuiteGuildReply")
    SetOfficeAskPB = Proto.build("RpcSetOfficeAsk")
    SetOfficeReplyPB = Proto.build("RpcSetOfficeReply")
    OfficeChangeNotifyPB = Proto.build("RpcOfficeChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_OFFICECHANGE_NOTIFY,@OfficeChangeCB)
    ChangeCreedAskPB = Proto.build("RpcChangeCreedAsk")
    ChangeCreedReplyPB = Proto.build("RpcChangeCreedReply")
    ForbiddenChatAskPB = Proto.build("RpcForbiddenChatAsk")
    ForbiddenChatReplyPB = Proto.build("RpcForbiddenChatReply")
    BuildLvUpCompleteNotifyPB = Proto.build("RpcBuildLvUpCompleteNotify")
    mLayerMgr.registerNotify(RPC_CODE_BUILDLVUPCOMPLETE_NOTIFY,@BuildLvUpCompleteCB)
    GuildCurrencyChangeNotifyPB = Proto.build("RpcGuildCurrencyChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_GUILDCURRENCYCHANGE_NOTIFY,@GuildCurrencyChangeCB)






  GuildBaseInfo : (replyCB) ->
    GuildBaseInfoAsk = GuildBaseInfoAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_GUILDBASEINFO_REQUEST,GuildBaseInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GuildBaseInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  KickMember : (Guid,KickReason,ReasonType,replyCB) ->
    KickMemberAsk = KickMemberAskPB.prototype
    KickMemberAsk.setGuid Guid
    KickMemberAsk.setKickReason KickReason
    KickMemberAsk.setReasonType ReasonType
    mLayerMgr.sendAsk(RPC_CODE_KICKMEMBER_REQUEST,KickMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( KickMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskVacation : (Guid,Reason,Type,replyCB) ->
    AskVacationAsk = AskVacationAskPB.prototype
    AskVacationAsk.setGuid Guid
    AskVacationAsk.setReason Reason
    AskVacationAsk.setType Type
    mLayerMgr.sendAsk(RPC_CODE_ASKVACATION_REQUEST,AskVacationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskVacationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskApplyList : (replyCB) ->
    AskApplyListAsk = AskApplyListAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKAPPLYLIST_REQUEST,AskApplyListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskApplyListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyGuildOperation : (Guid,Operation,replyCB) ->
    ApplyGuildOperationAsk = ApplyGuildOperationAskPB.prototype
    ApplyGuildOperationAsk.setGuid Guid
    ApplyGuildOperationAsk.setOperation Operation
    mLayerMgr.sendAsk(RPC_CODE_APPLYGUILDOPERATION_REQUEST,ApplyGuildOperationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyGuildOperationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyLimitSetting : (IsAutoJoin,replyCB) ->
    ApplyLimitSettingAsk = ApplyLimitSettingAskPB.prototype
    ApplyLimitSettingAsk.setIsAutoJoin IsAutoJoin
    mLayerMgr.sendAsk(RPC_CODE_APPLYLIMITSETTING_REQUEST,ApplyLimitSettingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyLimitSettingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskJurisdictionList : (replyCB) ->
    AskJurisdictionListAsk = AskJurisdictionListAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKJURISDICTIONLIST_REQUEST,AskJurisdictionListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskJurisdictionListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SetJurisdiction : (SetList,replyCB) ->
    SetJurisdictionAsk = SetJurisdictionAskPB.prototype
    SetJurisdictionAsk.setSetList SetList
    mLayerMgr.sendAsk(RPC_CODE_SETJURISDICTION_REQUEST,SetJurisdictionAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SetJurisdictionReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskVacationList : (replyCB) ->
    AskVacationListAsk = AskVacationListAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKVACATIONLIST_REQUEST,AskVacationListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskVacationListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  VacationGuildOperation : (Guid,Operation,replyCB) ->
    VacationGuildOperationAsk = VacationGuildOperationAskPB.prototype
    VacationGuildOperationAsk.setGuid Guid
    VacationGuildOperationAsk.setOperation Operation
    mLayerMgr.sendAsk(RPC_CODE_VACATIONGUILDOPERATION_REQUEST,VacationGuildOperationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( VacationGuildOperationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskBuildingInfo : (replyCB) ->
    AskBuildingInfoAsk = AskBuildingInfoAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKBUILDINGINFO_REQUEST,AskBuildingInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskBuildingInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  BuildingLvUp : (BuildingType,replyCB) ->
    BuildingLvUpAsk = BuildingLvUpAskPB.prototype
    BuildingLvUpAsk.setBuildingType BuildingType
    mLayerMgr.sendAsk(RPC_CODE_BUILDINGLVUP_REQUEST,BuildingLvUpAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( BuildingLvUpReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  BuildingLvSpeedUp : (BuildingType,Time,replyCB) ->
    BuildingLvSpeedUpAsk = BuildingLvSpeedUpAskPB.prototype
    BuildingLvSpeedUpAsk.setBuildingType BuildingType
    BuildingLvSpeedUpAsk.setTime Time
    mLayerMgr.sendAsk(RPC_CODE_BUILDINGLVSPEEDUP_REQUEST,BuildingLvSpeedUpAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( BuildingLvSpeedUpReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskBuildingContributionList : (BuildingType,replyCB) ->
    AskBuildingContributionListAsk = AskBuildingContributionListAskPB.prototype
    AskBuildingContributionListAsk.setBuildingType BuildingType
    mLayerMgr.sendAsk(RPC_CODE_ASKBUILDINGCONTRIBUTIONLIST_REQUEST,AskBuildingContributionListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskBuildingContributionListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskGuildEventList : (replyCB) ->
    AskGuildEventListAsk = AskGuildEventListAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKGUILDEVENTLIST_REQUEST,AskGuildEventListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskGuildEventListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskGuildInfoList : (PageIndex,replyCB) ->
    AskGuildInfoListAsk = AskGuildInfoListAskPB.prototype
    AskGuildInfoListAsk.setPageIndex PageIndex
    mLayerMgr.sendAsk(RPC_CODE_ASKGUILDINFOLIST_REQUEST,AskGuildInfoListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskGuildInfoListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SearchGuild : (Text,replyCB) ->
    SearchGuildAsk = SearchGuildAskPB.prototype
    SearchGuildAsk.setText Text
    mLayerMgr.sendAsk(RPC_CODE_SEARCHGUILD_REQUEST,SearchGuildAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SearchGuildReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  JoinGuild : (Guid,Type,replyCB) ->
    JoinGuildAsk = JoinGuildAskPB.prototype
    JoinGuildAsk.setGuid Guid
    JoinGuildAsk.setType Type
    mLayerMgr.sendAsk(RPC_CODE_JOINGUILD_REQUEST,JoinGuildAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( JoinGuildReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateGuild : (GuildName,GuildCreed,replyCB) ->
    CreateGuildAsk = CreateGuildAskPB.prototype
    CreateGuildAsk.setGuildName GuildName
    CreateGuildAsk.setGuildCreed GuildCreed
    mLayerMgr.sendAsk(RPC_CODE_CREATEGUILD_REQUEST,CreateGuildAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateGuildReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeFlag : (FlagConfigID,replyCB) ->
    ChangeFlagAsk = ChangeFlagAskPB.prototype
    ChangeFlagAsk.setFlagConfigID FlagConfigID
    mLayerMgr.sendAsk(RPC_CODE_CHANGEFLAG_REQUEST,ChangeFlagAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeFlagReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GuildChangeName : (GuildNewName,replyCB) ->
    GuildChangeNameAsk = GuildChangeNameAskPB.prototype
    GuildChangeNameAsk.setGuildNewName GuildNewName
    mLayerMgr.sendAsk(RPC_CODE_GUILDCHANGENAME_REQUEST,GuildChangeNameAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GuildChangeNameReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AskGuildMember : (replyCB) ->
    AskGuildMemberAsk = AskGuildMemberAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ASKGUILDMEMBER_REQUEST,AskGuildMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AskGuildMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  QuiteGuild : (replyCB) ->
    QuiteGuildAsk = QuiteGuildAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_QUITEGUILD_REQUEST,QuiteGuildAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( QuiteGuildReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SetOffice : (Guid,TargetGuid,OfficeType,replyCB) ->
    SetOfficeAsk = SetOfficeAskPB.prototype
    SetOfficeAsk.setGuid Guid
    SetOfficeAsk.setTargetGuid TargetGuid
    SetOfficeAsk.setOfficeType OfficeType
    mLayerMgr.sendAsk(RPC_CODE_SETOFFICE_REQUEST,SetOfficeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SetOfficeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeCreed : (Content,replyCB) ->
    ChangeCreedAsk = ChangeCreedAskPB.prototype
    ChangeCreedAsk.setContent Content
    mLayerMgr.sendAsk(RPC_CODE_CHANGECREED_REQUEST,ChangeCreedAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeCreedReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ForbiddenChat : (Playerguid,IsForbidden,replyCB) ->
    ForbiddenChatAsk = ForbiddenChatAskPB.prototype
    ForbiddenChatAsk.setPlayerguid Playerguid
    ForbiddenChatAsk.setIsForbidden IsForbidden
    mLayerMgr.sendAsk(RPC_CODE_FORBIDDENCHAT_REQUEST,ForbiddenChatAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ForbiddenChatReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetKickMemberNotifyNotifyCB : (cb) -> RpcKickMemberNotifyNotifyCB = cb
  KickMemberNotifyCB : (data)->
    RpcKickMemberNotifyNotifyCB( KickMemberNotifyNotifyPB.decode(data)) if typeof(RpcKickMemberNotifyNotifyCB) is "function"
  SetVacationNotifyCB : (cb) -> RpcVacationNotifyCB = cb
  VacationCB : (data)->
    RpcVacationNotifyCB( VacationNotifyPB.decode(data)) if typeof(RpcVacationNotifyCB) is "function"
  SetReplyVacationNotifyCB : (cb) -> RpcReplyVacationNotifyCB = cb
  ReplyVacationCB : (data)->
    RpcReplyVacationNotifyCB( ReplyVacationNotifyPB.decode(data)) if typeof(RpcReplyVacationNotifyCB) is "function"
  SetApplyGuildNotifyCB : (cb) -> RpcApplyGuildNotifyCB = cb
  ApplyGuildCB : (data)->
    RpcApplyGuildNotifyCB( ApplyGuildNotifyPB.decode(data)) if typeof(RpcApplyGuildNotifyCB) is "function"
  SetApplyGuildToOfficeNotifyCB : (cb) -> RpcApplyGuildToOfficeNotifyCB = cb
  ApplyGuildToOfficeCB : (data)->
    RpcApplyGuildToOfficeNotifyCB( ApplyGuildToOfficeNotifyPB.decode(data)) if typeof(RpcApplyGuildToOfficeNotifyCB) is "function"
  SetBuildingCanLvUpNotifyCB : (cb) -> RpcBuildingCanLvUpNotifyCB = cb
  BuildingCanLvUpCB : (data)->
    RpcBuildingCanLvUpNotifyCB( BuildingCanLvUpNotifyPB.decode(data)) if typeof(RpcBuildingCanLvUpNotifyCB) is "function"
  SetOfficeChangeNotifyCB : (cb) -> RpcOfficeChangeNotifyCB = cb
  OfficeChangeCB : (data)->
    RpcOfficeChangeNotifyCB( OfficeChangeNotifyPB.decode(data)) if typeof(RpcOfficeChangeNotifyCB) is "function"
  SetBuildLvUpCompleteNotifyCB : (cb) -> RpcBuildLvUpCompleteNotifyCB = cb
  BuildLvUpCompleteCB : (data)->
    RpcBuildLvUpCompleteNotifyCB( BuildLvUpCompleteNotifyPB.decode(data)) if typeof(RpcBuildLvUpCompleteNotifyCB) is "function"
  SetGuildCurrencyChangeNotifyCB : (cb) -> RpcGuildCurrencyChangeNotifyCB = cb
  GuildCurrencyChangeCB : (data)->
    RpcGuildCurrencyChangeNotifyCB( GuildCurrencyChangeNotifyPB.decode(data)) if typeof(RpcGuildCurrencyChangeNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "GuildModel",
      'AskName': ["GuildBaseInfo",
                   "KickMember",
                   "AskVacation",
                   "AskApplyList",
                   "ApplyGuildOperation",
                   "ApplyLimitSetting",
                   "AskJurisdictionList",
                   "SetJurisdiction",
                   "AskVacationList",
                   "VacationGuildOperation",
                   "AskBuildingInfo",
                   "BuildingLvUp",
                   "BuildingLvSpeedUp",
                   "AskBuildingContributionList",
                   "AskGuildEventList",
                   "AskGuildInfoList",
                   "SearchGuild",
                   "JoinGuild",
                   "CreateGuild",
                   "ChangeFlag",
                   "GuildChangeName",
                   "AskGuildMember",
                   "QuiteGuild",
                   "SetOffice",
                   "ChangeCreed",
                   "ForbiddenChat"]
      'ParamterList': [[],
                       ["Guid","KickReason","ReasonType"],
                       ["Guid","Reason","Type"],
                       [],
                       ["Guid","Operation"],
                       ["IsAutoJoin"],
                       [],
                       ["SetList"],
                       [],
                       ["Guid","Operation"],
                       [],
                       ["BuildingType"],
                       ["BuildingType","Time"],
                       ["BuildingType"],
                       [],
                       ["PageIndex"],
                       ["Text"],
                       ["Guid","Type"],
                       ["GuildName","GuildCreed"],
                       ["FlagConfigID"],
                       ["GuildNewName"],
                       [],
                       [],
                       ["Guid","TargetGuid","OfficeType"],
                       ["Content"],
                       ["Playerguid","IsForbidden"]]
      'AskList':[@GuildBaseInfo,
                 @KickMember,
                 @AskVacation,
                 @AskApplyList,
                 @ApplyGuildOperation,
                 @ApplyLimitSetting,
                 @AskJurisdictionList,
                 @SetJurisdiction,
                 @AskVacationList,
                 @VacationGuildOperation,
                 @AskBuildingInfo,
                 @BuildingLvUp,
                 @BuildingLvSpeedUp,
                 @AskBuildingContributionList,
                 @AskGuildEventList,
                 @AskGuildInfoList,
                 @SearchGuild,
                 @JoinGuild,
                 @CreateGuild,
                 @ChangeFlag,
                 @GuildChangeName,
                 @AskGuildMember,
                 @QuiteGuild,
                 @SetOffice,
                 @ChangeCreed,
                 @ForbiddenChat]
      'ParamterTypelist': [[],
                       ["int32","string","int32"],
                       ["int32","string","int32"],
                       [],
                       ["uint64","int32"],
                       ["bool"],
                       [],
                       ["GuildOfficeJurisdiction"],
                       [],
                       ["uint64","int32"],
                       [],
                       ["int32"],
                       ["int32","int32"],
                       ["int32"],
                       [],
                       ["int32"],
                       ["string"],
                       ["uint64","int32"],
                       ["string","string"],
                       ["int32"],
                       ["string"],
                       [],
                       [],
                       ["uint64","uint64","int32"],
                       ["string"],
                       ["int64","bool"]]


module.exports =(()->
  if not Guild?
    Guild = new GuildModel()
  Guild)()



  

  

  


