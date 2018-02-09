ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcNewLeaderNotifyCB = null
RpcDissmissTeamNotifyNotifyCB = null
RpcJoinTeamNotifyNotifyCB = null
RpcKickMemberNotifyNotifyCB = null
RpcLeaveTeamNotifyNotifyCB = null
RpcApplyTeamNotifyNotifyCB = null
RpcAgreeApplicantNotifyNotifyCB = null
RpcTeamInfoNotifyCB = null
RpcUpdateTeamMemInfoNotifyCB = null


ModuleId = 10
RPC_CODE_JOINTEAM_REQUEST = 1051
RPC_CODE_LEAVETEAM_REQUEST = 1052
RPC_CODE_APPOINTTEAMLEADER_REQUEST = 1053
RPC_CODE_CREATETEAM_REQUEST = 1054
RPC_CODE_DISSMISSTEAM_REQUEST = 1055
RPC_CODE_NEWLEADER_NOTIFY = 1056
RPC_CODE_KICKMEMBER_REQUEST = 1057
RPC_CODE_DISSMISSTEAMNOTIFY_NOTIFY = 1058
RPC_CODE_JOINTEAMNOTIFY_NOTIFY = 1059
RPC_CODE_KICKMEMBERNOTIFY_NOTIFY = 1060
RPC_CODE_LEAVETEAMNOTIFY_NOTIFY = 1061
RPC_CODE_SURROUNDINGTEAM_REQUEST = 1062
RPC_CODE_APPLYTEAM_REQUEST = 1063
RPC_CODE_APPLYTEAMNOTIFY_NOTIFY = 1064
RPC_CODE_AGREEAPPLICANT_REQUEST = 1065
RPC_CODE_AGREEAPPLICANTNOTIFY_NOTIFY = 1066
RPC_CODE_TEAMINFO_NOTIFY = 1067
RPC_CODE_UPDATETEAMMEMINFO_NOTIFY = 1068

JoinTeamAskPB = null
JoinTeamReplyPB = null
LeaveTeamAskPB = null
LeaveTeamReplyPB = null
AppointTeamLeaderAskPB = null
AppointTeamLeaderReplyPB = null
CreateTeamAskPB = null
CreateTeamReplyPB = null
DissmissTeamAskPB = null
DissmissTeamReplyPB = null
NewLeaderNotifyPB = null
KickMemberAskPB = null
KickMemberReplyPB = null
DissmissTeamNotifyNotifyPB = null
JoinTeamNotifyNotifyPB = null
KickMemberNotifyNotifyPB = null
LeaveTeamNotifyNotifyPB = null
SurroundingTeamAskPB = null
SurroundingTeamReplyPB = null
ApplyTeamAskPB = null
ApplyTeamReplyPB = null
ApplyTeamNotifyNotifyPB = null
AgreeApplicantAskPB = null
AgreeApplicantReplyPB = null
AgreeApplicantNotifyNotifyPB = null
TeamInfoNotifyPB = null
UpdateTeamMemInfoNotifyPB = null

class TeamModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  TeamMemberInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
        optional sint32 Level = 3[default=-1];
        optional string Name = 4;
        optional sint32 ConfigId = 5[default=-1];
        optional sint32 Hp = 6[default=-1];
        optional sint32 Mp = 7[default=-1];
        optional sint32 Status = 8[default=-1];
        optional sint32 MemId = 10[default=-1];
        optional sint64 MaxHp = 11[default=-1];
        optional sint64 MaxMp = 12[default=-1];
      }
      message  TeamInfo
      {
        repeated TeamMemberInfo Members = 1;
        optional uint64 LeaderRoleId = 2[default=0];
        optional sint32 TeamId = 3[default=-1];
        optional sint32 TeamType = 4[default=-1];
      }
      message  RpcJoinTeamAsk
      {
        optional sint32 TeamId = 1[default=-1];
        optional sint32 TeamType = 2[default=-1];
        optional TeamInfo Team = 3;
        optional TeamMemberInfo TeamMember = 4;
      }
      message  RpcJoinTeamReply
      {
        optional sint32 Result = 1[default=-9999];
        optional TeamInfo Team = 2;
      }
      message  RpcLeaveTeamAsk
      {
      }
      message  RpcLeaveTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcAppointTeamLeaderAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcAppointTeamLeaderReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 NewLeaderId = 2[default=0];
      }
      message  RpcCreateTeamAsk
      {
        optional sint32 TeamType = 2[default=-1];
      }
      message  RpcCreateTeamReply
      {
        optional sint32 Result = 1[default=-9999];
        optional TeamInfo Team = 2;
      }
      message  RpcDissmissTeamAsk
      {
      }
      message  RpcDissmissTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcNewLeaderNotify
      {
        optional uint64 Newleaderroleid = 1[default=0];
      }
      message  RpcKickMemberAsk
      {
        optional uint64 KickMemberRoleId = 1[default=0];
      }
      message  RpcKickMemberReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcDissmissTeamNotifyNotify
      {
      }
      message  RpcJoinTeamNotifyNotify
      {
        optional TeamMemberInfo TeamMember = 1;
      }
      message  RpcKickMemberNotifyNotify
      {
        optional uint64 KickedMemberRoleId = 1[default=0];
      }
      message  RpcLeaveTeamNotifyNotify
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 NewLeaderRoleId = 2[default=0];
      }
      message  RpcSurroundingTeamAsk
      {
      }
      message  RpcSurroundingTeamReply
      {
        optional sint32 Result = 1[default=-9999];
        repeated TeamInfo TeamsInfo = 2;
      }
      message  RpcApplyTeamAsk
      {
        optional sint32 TeamId = 1[default=-1];
      }
      message  RpcApplyTeamReply
      {
        optional sint32 Result = 1[default=-9999];
        optional sint32 TeamId = 2[default=-1];
      }
      message  RpcApplyTeamNotifyNotify
      {
        optional TeamMemberInfo TeamMember = 1;
      }
      message  RpcAgreeApplicantAsk
      {
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcAgreeApplicantReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcAgreeApplicantNotifyNotify
      {
        optional TeamInfo Team = 1;
      }
      message  RpcTeamInfoNotify
      {
        optional TeamInfo Team = 1;
      }
      message  RpcUpdateTeamMemInfoNotify
      {
        optional TeamMemberInfo TeamMember = 1;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    JoinTeamAskPB = Proto.build("RpcJoinTeamAsk")
    JoinTeamReplyPB = Proto.build("RpcJoinTeamReply")
    LeaveTeamAskPB = Proto.build("RpcLeaveTeamAsk")
    LeaveTeamReplyPB = Proto.build("RpcLeaveTeamReply")
    AppointTeamLeaderAskPB = Proto.build("RpcAppointTeamLeaderAsk")
    AppointTeamLeaderReplyPB = Proto.build("RpcAppointTeamLeaderReply")
    CreateTeamAskPB = Proto.build("RpcCreateTeamAsk")
    CreateTeamReplyPB = Proto.build("RpcCreateTeamReply")
    DissmissTeamAskPB = Proto.build("RpcDissmissTeamAsk")
    DissmissTeamReplyPB = Proto.build("RpcDissmissTeamReply")
    NewLeaderNotifyPB = Proto.build("RpcNewLeaderNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWLEADER_NOTIFY,@NewLeaderCB)
    KickMemberAskPB = Proto.build("RpcKickMemberAsk")
    KickMemberReplyPB = Proto.build("RpcKickMemberReply")
    DissmissTeamNotifyNotifyPB = Proto.build("RpcDissmissTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_DISSMISSTEAMNOTIFY_NOTIFY,@DissmissTeamNotifyCB)
    JoinTeamNotifyNotifyPB = Proto.build("RpcJoinTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_JOINTEAMNOTIFY_NOTIFY,@JoinTeamNotifyCB)
    KickMemberNotifyNotifyPB = Proto.build("RpcKickMemberNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_KICKMEMBERNOTIFY_NOTIFY,@KickMemberNotifyCB)
    LeaveTeamNotifyNotifyPB = Proto.build("RpcLeaveTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_LEAVETEAMNOTIFY_NOTIFY,@LeaveTeamNotifyCB)
    SurroundingTeamAskPB = Proto.build("RpcSurroundingTeamAsk")
    SurroundingTeamReplyPB = Proto.build("RpcSurroundingTeamReply")
    ApplyTeamAskPB = Proto.build("RpcApplyTeamAsk")
    ApplyTeamReplyPB = Proto.build("RpcApplyTeamReply")
    ApplyTeamNotifyNotifyPB = Proto.build("RpcApplyTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYTEAMNOTIFY_NOTIFY,@ApplyTeamNotifyCB)
    AgreeApplicantAskPB = Proto.build("RpcAgreeApplicantAsk")
    AgreeApplicantReplyPB = Proto.build("RpcAgreeApplicantReply")
    AgreeApplicantNotifyNotifyPB = Proto.build("RpcAgreeApplicantNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_AGREEAPPLICANTNOTIFY_NOTIFY,@AgreeApplicantNotifyCB)
    TeamInfoNotifyPB = Proto.build("RpcTeamInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_TEAMINFO_NOTIFY,@TeamInfoCB)
    UpdateTeamMemInfoNotifyPB = Proto.build("RpcUpdateTeamMemInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATETEAMMEMINFO_NOTIFY,@UpdateTeamMemInfoCB)






  JoinTeam : (TeamId,TeamType,Team,TeamMember,replyCB) ->
    JoinTeamAsk = JoinTeamAskPB.prototype
    JoinTeamAsk.setTeamId TeamId
    JoinTeamAsk.setTeamType TeamType
    JoinTeamAsk.setTeam Team
    JoinTeamAsk.setTeamMember TeamMember
    mLayerMgr.sendAsk(RPC_CODE_JOINTEAM_REQUEST,JoinTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( JoinTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LeaveTeam : (replyCB) ->
    LeaveTeamAsk = LeaveTeamAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_LEAVETEAM_REQUEST,LeaveTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LeaveTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AppointTeamLeader : (RoleId,replyCB) ->
    AppointTeamLeaderAsk = AppointTeamLeaderAskPB.prototype
    AppointTeamLeaderAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_APPOINTTEAMLEADER_REQUEST,AppointTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AppointTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateTeam : (TeamType,replyCB) ->
    CreateTeamAsk = CreateTeamAskPB.prototype
    CreateTeamAsk.setTeamType TeamType
    mLayerMgr.sendAsk(RPC_CODE_CREATETEAM_REQUEST,CreateTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DissmissTeam : (replyCB) ->
    DissmissTeamAsk = DissmissTeamAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_DISSMISSTEAM_REQUEST,DissmissTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DissmissTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  KickMember : (KickMemberRoleId,replyCB) ->
    KickMemberAsk = KickMemberAskPB.prototype
    KickMemberAsk.setKickMemberRoleId KickMemberRoleId
    mLayerMgr.sendAsk(RPC_CODE_KICKMEMBER_REQUEST,KickMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( KickMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SurroundingTeam : (replyCB) ->
    SurroundingTeamAsk = SurroundingTeamAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SURROUNDINGTEAM_REQUEST,SurroundingTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SurroundingTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyTeam : (TeamId,replyCB) ->
    ApplyTeamAsk = ApplyTeamAskPB.prototype
    ApplyTeamAsk.setTeamId TeamId
    mLayerMgr.sendAsk(RPC_CODE_APPLYTEAM_REQUEST,ApplyTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeApplicant : (RoleId,replyCB) ->
    AgreeApplicantAsk = AgreeApplicantAskPB.prototype
    AgreeApplicantAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_AGREEAPPLICANT_REQUEST,AgreeApplicantAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeApplicantReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetNewLeaderNotifyCB : (cb) -> RpcNewLeaderNotifyCB = cb
  NewLeaderCB : (data)->
    RpcNewLeaderNotifyCB( NewLeaderNotifyPB.decode(data)) if typeof(RpcNewLeaderNotifyCB) is "function"
  SetDissmissTeamNotifyNotifyCB : (cb) -> RpcDissmissTeamNotifyNotifyCB = cb
  DissmissTeamNotifyCB : (data)->
    RpcDissmissTeamNotifyNotifyCB( DissmissTeamNotifyNotifyPB.decode(data)) if typeof(RpcDissmissTeamNotifyNotifyCB) is "function"
  SetJoinTeamNotifyNotifyCB : (cb) -> RpcJoinTeamNotifyNotifyCB = cb
  JoinTeamNotifyCB : (data)->
    RpcJoinTeamNotifyNotifyCB( JoinTeamNotifyNotifyPB.decode(data)) if typeof(RpcJoinTeamNotifyNotifyCB) is "function"
  SetKickMemberNotifyNotifyCB : (cb) -> RpcKickMemberNotifyNotifyCB = cb
  KickMemberNotifyCB : (data)->
    RpcKickMemberNotifyNotifyCB( KickMemberNotifyNotifyPB.decode(data)) if typeof(RpcKickMemberNotifyNotifyCB) is "function"
  SetLeaveTeamNotifyNotifyCB : (cb) -> RpcLeaveTeamNotifyNotifyCB = cb
  LeaveTeamNotifyCB : (data)->
    RpcLeaveTeamNotifyNotifyCB( LeaveTeamNotifyNotifyPB.decode(data)) if typeof(RpcLeaveTeamNotifyNotifyCB) is "function"
  SetApplyTeamNotifyNotifyCB : (cb) -> RpcApplyTeamNotifyNotifyCB = cb
  ApplyTeamNotifyCB : (data)->
    RpcApplyTeamNotifyNotifyCB( ApplyTeamNotifyNotifyPB.decode(data)) if typeof(RpcApplyTeamNotifyNotifyCB) is "function"
  SetAgreeApplicantNotifyNotifyCB : (cb) -> RpcAgreeApplicantNotifyNotifyCB = cb
  AgreeApplicantNotifyCB : (data)->
    RpcAgreeApplicantNotifyNotifyCB( AgreeApplicantNotifyNotifyPB.decode(data)) if typeof(RpcAgreeApplicantNotifyNotifyCB) is "function"
  SetTeamInfoNotifyCB : (cb) -> RpcTeamInfoNotifyCB = cb
  TeamInfoCB : (data)->
    RpcTeamInfoNotifyCB( TeamInfoNotifyPB.decode(data)) if typeof(RpcTeamInfoNotifyCB) is "function"
  SetUpdateTeamMemInfoNotifyCB : (cb) -> RpcUpdateTeamMemInfoNotifyCB = cb
  UpdateTeamMemInfoCB : (data)->
    RpcUpdateTeamMemInfoNotifyCB( UpdateTeamMemInfoNotifyPB.decode(data)) if typeof(RpcUpdateTeamMemInfoNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "TeamModel",
      'AskName': ["JoinTeam",
                   "LeaveTeam",
                   "AppointTeamLeader",
                   "CreateTeam",
                   "DissmissTeam",
                   "KickMember",
                   "SurroundingTeam",
                   "ApplyTeam",
                   "AgreeApplicant"]
      'ParamterList': [["TeamId","TeamType","Team","TeamMember"],
                       [],
                       ["RoleId"],
                       ["TeamType"],
                       [],
                       ["KickMemberRoleId"],
                       [],
                       ["TeamId"],
                       ["RoleId"]]
      'AskList':[@JoinTeam,
                 @LeaveTeam,
                 @AppointTeamLeader,
                 @CreateTeam,
                 @DissmissTeam,
                 @KickMember,
                 @SurroundingTeam,
                 @ApplyTeam,
                 @AgreeApplicant]
      'ParamterTypelist': [["sint32","sint32","TeamInfo","TeamMemberInfo"],
                       [],
                       ["uint64"],
                       ["sint32"],
                       [],
                       ["uint64"],
                       [],
                       ["sint32"],
                       ["uint64"]]


module.exports =(()->
  if not Team?
    Team = new TeamModel()
  Team)()



  

  

  


