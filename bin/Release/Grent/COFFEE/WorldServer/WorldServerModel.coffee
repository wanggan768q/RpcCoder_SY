ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcChangeSceneAskNotifyCB = null
RpcChangeSceneReplyNotifyCB = null


ModuleId = 8
RPC_CODE_CHANGESCENEASK_NOTIFY = 851
RPC_CODE_CHANGESCENEREPLY_NOTIFY = 852
RPC_CODE_ENTERSCENE_REQUEST = 853
RPC_CODE_CREATEDUNGEON_REQUEST = 854
RPC_CODE_CREATETEAM_REQUEST = 855
RPC_CODE_JOINTEAM_REQUEST = 856
RPC_CODE_LEAVETEAM_REQUEST = 857
RPC_CODE_APPOINTTEAMLEADER_REQUEST = 858
RPC_CODE_DISMISSTEAM_REQUEST = 859
RPC_CODE_KICKMEMBER_REQUEST = 860
RPC_CODE_APPLYTEAM_REQUEST = 861
RPC_CODE_AGREETEAMAPPLICANT_REQUEST = 862
RPC_CODE_LOGIN_REQUEST = 863
RPC_CODE_UPDATEROLEINFO_REQUEST = 864
RPC_CODE_LOGOUT_REQUEST = 865
RPC_CODE_CREATEDUNGEONNOTIFY_REQUEST = 866
RPC_CODE_EXITDUNGEON_REQUEST = 867
RPC_CODE_UPDATETEAMINFO_REQUEST = 868
RPC_CODE_SUMMONMEMBER_REQUEST = 869
RPC_CODE_PLAYCGTEAM_REQUEST = 870
RPC_CODE_SENDMAIL_REQUEST = 871

ChangeSceneAskNotifyPB = null
ChangeSceneReplyNotifyPB = null
EnterSceneAskPB = null
EnterSceneReplyPB = null
CreateDungeonAskPB = null
CreateDungeonReplyPB = null
CreateTeamAskPB = null
CreateTeamReplyPB = null
JoinTeamAskPB = null
JoinTeamReplyPB = null
LeaveTeamAskPB = null
LeaveTeamReplyPB = null
AppointTeamLeaderAskPB = null
AppointTeamLeaderReplyPB = null
DismissTeamAskPB = null
DismissTeamReplyPB = null
KickMemberAskPB = null
KickMemberReplyPB = null
ApplyTeamAskPB = null
ApplyTeamReplyPB = null
AgreeTeamApplicantAskPB = null
AgreeTeamApplicantReplyPB = null
LoginAskPB = null
LoginReplyPB = null
UpdateRoleInfoAskPB = null
UpdateRoleInfoReplyPB = null
LogoutAskPB = null
LogoutReplyPB = null
CreateDungeonNotifyAskPB = null
CreateDungeonNotifyReplyPB = null
ExitDungeonAskPB = null
ExitDungeonReplyPB = null
UpdateTeamInfoAskPB = null
UpdateTeamInfoReplyPB = null
SummonMemberAskPB = null
SummonMemberReplyPB = null
PlayCgTeamAskPB = null
PlayCgTeamReplyPB = null
SendMailAskPB = null
SendMailReplyPB = null

class WorldServerModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcChangeSceneAskNotify
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 CurSceneID = 2[default=-1];
        optional int32 TargetSceneID = 3[default=-1];
        optional int32 MemId = 4[default=-1];
        optional int32 CurLineID = 5[default=-1];
        optional int32 CurServerID = 6[default=-1];
      }
      message  RpcChangeSceneReplyNotify
      {
        optional int32 Result = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
        optional int32 MemId = 3[default=-1];
        optional int32 TargetSceneID = 4[default=-1];
        optional int32 CurSceneID = 5[default=-1];
        optional int32 TargetLineID = 6[default=-1];
        optional int32 TargetServerID = 7[default=-1];
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  CharacterLocation
      {
        optional int32 SceneId = 2[default=-1];
        optional Vector3 Pos = 3;
        optional int32 MapId = 5[default=-1];
        optional int32 DungeonConfigId = 6[default=-1];
      }
      message  RpcEnterSceneAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional CharacterLocation Location = 6;
      }
      message  RpcEnterSceneReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcCreateDungeonAsk
      {
        optional uint64 RoleId = 2[default=0];
        optional int32 TargetSceneId = 3[default=-1];
        optional int32 MemId = 4[default=-1];
        optional int32 DungeonConfigId = 5[default=-1];
        optional int32 CurSceneId = 6[default=-1];
        optional int32 Result = 7[default=-9999];
        repeated uint64 RoleIds = 8;
      }
      message  RpcCreateDungeonReply
      {
      }
      message  TeamMemberInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 3[default=-1];
        optional string Name = 4;
        optional int32 ConfigId = 5[default=-1];
        optional int32 Hp = 6[default=-1];
        optional int32 Mp = 7[default=-1];
        optional int32 Status = 8[default=-1];
        optional int64 MaxHp = 11[default=-1];
        optional int64 MaxMp = 12[default=-1];
        optional CharacterLocation Location = 15;
      }
      message  TeamInfo
      {
        repeated TeamMemberInfo Members = 1;
        optional uint64 LeaderRoleId = 2[default=0];
        optional int32 TeamId = 3[default=-1];
        optional int32 TeamType = 4[default=-1];
      }
      message  RpcCreateTeamAsk
      {
        optional int32 TeamType = 2[default=-1];
        optional TeamMemberInfo TeamMember = 5;
        optional int32 Result = 6[default=-9999];
        optional TeamInfo Team = 7;
      }
      message  RpcCreateTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcJoinTeamAsk
      {
        optional int32 TeamId = 1[default=-1];
        optional int32 Result = 2[default=-9999];
        optional TeamMemberInfo TeamMember = 3;
        optional TeamInfo Team = 4;
        optional int32 TeamType = 5[default=-1];
        optional int32 SceneId = 7[default=-1];
        optional uint64 RoleId = 8[default=0];
      }
      message  RpcJoinTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcLeaveTeamAsk
      {
        optional int32 TeamId = 1[default=-1];
        optional uint64 LeaveRoleId = 2[default=0];
        optional int32 SceneId = 4[default=-1];
        optional uint64 NewLeaderRoleId = 5[default=0];
        optional int32 Result = 6[default=-9999];
        optional uint64 RoleId = 7[default=0];
      }
      message  RpcLeaveTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcAppointTeamLeaderAsk
      {
        optional uint64 NewLeaderRoleId = 1[default=0];
        optional int32 SceneId = 3[default=-1];
        optional uint64 CurLeaderRoleId = 4[default=0];
        optional int32 TeamId = 5[default=-1];
        optional int32 Result = 6[default=-9999];
        optional uint64 RoleId = 7[default=0];
      }
      message  RpcAppointTeamLeaderReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcDismissTeamAsk
      {
        optional int32 SceneId = 1[default=-1];
        optional uint64 RoleId = 3[default=0];
        optional int32 TeamId = 4[default=-1];
        optional int32 Result = 5[default=-9999];
      }
      message  RpcDismissTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcKickMemberAsk
      {
        optional uint64 KickMemberRoleId = 1[default=0];
        optional int32 SceneId = 3[default=-1];
        optional int32 TeamId = 4[default=-1];
        optional uint64 LeaderRoleId = 5[default=0];
        optional int32 Result = 6[default=-9999];
        optional uint64 RoleId = 7[default=0];
      }
      message  RpcKickMemberReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcApplyTeamAsk
      {
        optional int32 TeamId = 1[default=-1];
        optional int32 Result = 2[default=-9999];
        optional TeamMemberInfo TeamMember = 3;
        optional uint64 RoleId = 4[default=0];
        optional int32 SceneId = 5[default=-1];
      }
      message  RpcApplyTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcAgreeTeamApplicantAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 LeaderRoleId = 3[default=0];
        optional int32 Result = 4[default=-9999];
        optional int32 SceneId = 6[default=-1];
        optional TeamInfo Team = 7;
      }
      message  RpcAgreeTeamApplicantReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  OnlineUserInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 2[default=-1];
        optional CharacterLocation Location = 5;
      }
      message  RpcLoginAsk
      {
        optional TeamInfo Team = 1;
        optional OnlineUserInfo RoleInfo = 4;
        optional CharacterLocation Location = 5;
      }
      message  RpcLoginReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcUpdateRoleInfoAsk
      {
        optional OnlineUserInfo RoleInfo = 1;
      }
      message  RpcUpdateRoleInfoReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcLogoutAsk
      {
        optional OnlineUserInfo RoleInfo = 1;
      }
      message  RpcLogoutReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcCreateDungeonNotifyAsk
      {
        optional int32 CurSceneId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
        optional int32 TargetSceneId = 5[default=-1];
      }
      message  RpcCreateDungeonNotifyReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcExitDungeonReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcUpdateTeamInfoAsk
      {
        optional TeamMemberInfo TeamMember = 1;
        optional uint64 RoleId = 2[default=0];
        optional int32 SceneId = 3[default=-1];
      }
      message  RpcUpdateTeamInfoReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcSummonMemberAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcSummonMemberReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcPlayCgTeamAsk
      {
        optional uint64 PlayRoleId = 1[default=0];
        optional int32 CgId = 2[default=-1];
        optional int32 State = 3[default=-1];
        optional uint64 RoleId = 4[default=0];
      }
      message  RpcPlayCgTeamReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  DropItem
      {
        optional int32 ItemType = 1[default=-1];
        optional int32 ItemID = 2[default=-1];
        optional int32 ItemNum = 3[default=-1];
        optional bool Bind = 4;
        optional bool Transit = 5;
      }
      message  MailInfo
      {
        optional uint64 Guid = 1[default=0];
        optional int32 TableId = 2[default=-1];
        optional bool IsRead = 3;
        optional bool IsGet = 4;
        optional uint64 TimeStamp = 5[default=0];
        repeated DropItem ItemList = 6;
        repeated string ParamList = 7;
        optional uint64 RoleID = 8[default=0];
      }
      message  RpcSendMailAsk
      {
        optional MailInfo Mail = 1;
        optional uint64 GlobalMailID = 2[default=0];
      }
      message  RpcSendMailReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    ChangeSceneAskNotifyPB = Proto.build("RpcChangeSceneAskNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGESCENEASK_NOTIFY,@ChangeSceneAskCB)
    ChangeSceneReplyNotifyPB = Proto.build("RpcChangeSceneReplyNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGESCENEREPLY_NOTIFY,@ChangeSceneReplyCB)
    EnterSceneAskPB = Proto.build("RpcEnterSceneAsk")
    EnterSceneReplyPB = Proto.build("RpcEnterSceneReply")
    CreateDungeonAskPB = Proto.build("RpcCreateDungeonAsk")
    CreateDungeonReplyPB = Proto.build("RpcCreateDungeonReply")
    CreateTeamAskPB = Proto.build("RpcCreateTeamAsk")
    CreateTeamReplyPB = Proto.build("RpcCreateTeamReply")
    JoinTeamAskPB = Proto.build("RpcJoinTeamAsk")
    JoinTeamReplyPB = Proto.build("RpcJoinTeamReply")
    LeaveTeamAskPB = Proto.build("RpcLeaveTeamAsk")
    LeaveTeamReplyPB = Proto.build("RpcLeaveTeamReply")
    AppointTeamLeaderAskPB = Proto.build("RpcAppointTeamLeaderAsk")
    AppointTeamLeaderReplyPB = Proto.build("RpcAppointTeamLeaderReply")
    DismissTeamAskPB = Proto.build("RpcDismissTeamAsk")
    DismissTeamReplyPB = Proto.build("RpcDismissTeamReply")
    KickMemberAskPB = Proto.build("RpcKickMemberAsk")
    KickMemberReplyPB = Proto.build("RpcKickMemberReply")
    ApplyTeamAskPB = Proto.build("RpcApplyTeamAsk")
    ApplyTeamReplyPB = Proto.build("RpcApplyTeamReply")
    AgreeTeamApplicantAskPB = Proto.build("RpcAgreeTeamApplicantAsk")
    AgreeTeamApplicantReplyPB = Proto.build("RpcAgreeTeamApplicantReply")
    LoginAskPB = Proto.build("RpcLoginAsk")
    LoginReplyPB = Proto.build("RpcLoginReply")
    UpdateRoleInfoAskPB = Proto.build("RpcUpdateRoleInfoAsk")
    UpdateRoleInfoReplyPB = Proto.build("RpcUpdateRoleInfoReply")
    LogoutAskPB = Proto.build("RpcLogoutAsk")
    LogoutReplyPB = Proto.build("RpcLogoutReply")
    CreateDungeonNotifyAskPB = Proto.build("RpcCreateDungeonNotifyAsk")
    CreateDungeonNotifyReplyPB = Proto.build("RpcCreateDungeonNotifyReply")
    ExitDungeonAskPB = Proto.build("RpcExitDungeonAsk")
    ExitDungeonReplyPB = Proto.build("RpcExitDungeonReply")
    UpdateTeamInfoAskPB = Proto.build("RpcUpdateTeamInfoAsk")
    UpdateTeamInfoReplyPB = Proto.build("RpcUpdateTeamInfoReply")
    SummonMemberAskPB = Proto.build("RpcSummonMemberAsk")
    SummonMemberReplyPB = Proto.build("RpcSummonMemberReply")
    PlayCgTeamAskPB = Proto.build("RpcPlayCgTeamAsk")
    PlayCgTeamReplyPB = Proto.build("RpcPlayCgTeamReply")
    SendMailAskPB = Proto.build("RpcSendMailAsk")
    SendMailReplyPB = Proto.build("RpcSendMailReply")






  EnterScene : (RoleId,Location,replyCB) ->
    EnterSceneAsk = EnterSceneAskPB.prototype
    EnterSceneAsk.setRoleId RoleId
    EnterSceneAsk.setLocation Location
    mLayerMgr.sendAsk(RPC_CODE_ENTERSCENE_REQUEST,EnterSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateDungeon : (RoleId,TargetSceneId,MemId,DungeonConfigId,CurSceneId,Result,RoleIds,replyCB) ->
    CreateDungeonAsk = CreateDungeonAskPB.prototype
    CreateDungeonAsk.setRoleId RoleId
    CreateDungeonAsk.setTargetSceneId TargetSceneId
    CreateDungeonAsk.setMemId MemId
    CreateDungeonAsk.setDungeonConfigId DungeonConfigId
    CreateDungeonAsk.setCurSceneId CurSceneId
    CreateDungeonAsk.setResult Result
    CreateDungeonAsk.setRoleIds RoleIds
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEON_REQUEST,CreateDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateTeam : (TeamType,TeamMember,Result,Team,replyCB) ->
    CreateTeamAsk = CreateTeamAskPB.prototype
    CreateTeamAsk.setTeamType TeamType
    CreateTeamAsk.setTeamMember TeamMember
    CreateTeamAsk.setResult Result
    CreateTeamAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_CREATETEAM_REQUEST,CreateTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  JoinTeam : (TeamId,Result,TeamMember,Team,TeamType,SceneId,RoleId,replyCB) ->
    JoinTeamAsk = JoinTeamAskPB.prototype
    JoinTeamAsk.setTeamId TeamId
    JoinTeamAsk.setResult Result
    JoinTeamAsk.setTeamMember TeamMember
    JoinTeamAsk.setTeam Team
    JoinTeamAsk.setTeamType TeamType
    JoinTeamAsk.setSceneId SceneId
    JoinTeamAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_JOINTEAM_REQUEST,JoinTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( JoinTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LeaveTeam : (TeamId,LeaveRoleId,SceneId,NewLeaderRoleId,Result,RoleId,replyCB) ->
    LeaveTeamAsk = LeaveTeamAskPB.prototype
    LeaveTeamAsk.setTeamId TeamId
    LeaveTeamAsk.setLeaveRoleId LeaveRoleId
    LeaveTeamAsk.setSceneId SceneId
    LeaveTeamAsk.setNewLeaderRoleId NewLeaderRoleId
    LeaveTeamAsk.setResult Result
    LeaveTeamAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_LEAVETEAM_REQUEST,LeaveTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LeaveTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AppointTeamLeader : (NewLeaderRoleId,SceneId,CurLeaderRoleId,TeamId,Result,RoleId,replyCB) ->
    AppointTeamLeaderAsk = AppointTeamLeaderAskPB.prototype
    AppointTeamLeaderAsk.setNewLeaderRoleId NewLeaderRoleId
    AppointTeamLeaderAsk.setSceneId SceneId
    AppointTeamLeaderAsk.setCurLeaderRoleId CurLeaderRoleId
    AppointTeamLeaderAsk.setTeamId TeamId
    AppointTeamLeaderAsk.setResult Result
    AppointTeamLeaderAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_APPOINTTEAMLEADER_REQUEST,AppointTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AppointTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DismissTeam : (SceneId,RoleId,TeamId,Result,replyCB) ->
    DismissTeamAsk = DismissTeamAskPB.prototype
    DismissTeamAsk.setSceneId SceneId
    DismissTeamAsk.setRoleId RoleId
    DismissTeamAsk.setTeamId TeamId
    DismissTeamAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_DISMISSTEAM_REQUEST,DismissTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DismissTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  KickMember : (KickMemberRoleId,SceneId,TeamId,LeaderRoleId,Result,RoleId,replyCB) ->
    KickMemberAsk = KickMemberAskPB.prototype
    KickMemberAsk.setKickMemberRoleId KickMemberRoleId
    KickMemberAsk.setSceneId SceneId
    KickMemberAsk.setTeamId TeamId
    KickMemberAsk.setLeaderRoleId LeaderRoleId
    KickMemberAsk.setResult Result
    KickMemberAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_KICKMEMBER_REQUEST,KickMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( KickMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyTeam : (TeamId,Result,TeamMember,RoleId,SceneId,replyCB) ->
    ApplyTeamAsk = ApplyTeamAskPB.prototype
    ApplyTeamAsk.setTeamId TeamId
    ApplyTeamAsk.setResult Result
    ApplyTeamAsk.setTeamMember TeamMember
    ApplyTeamAsk.setRoleId RoleId
    ApplyTeamAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_APPLYTEAM_REQUEST,ApplyTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeTeamApplicant : (RoleId,LeaderRoleId,Result,SceneId,Team,replyCB) ->
    AgreeTeamApplicantAsk = AgreeTeamApplicantAskPB.prototype
    AgreeTeamApplicantAsk.setRoleId RoleId
    AgreeTeamApplicantAsk.setLeaderRoleId LeaderRoleId
    AgreeTeamApplicantAsk.setResult Result
    AgreeTeamApplicantAsk.setSceneId SceneId
    AgreeTeamApplicantAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_AGREETEAMAPPLICANT_REQUEST,AgreeTeamApplicantAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeTeamApplicantReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Login : (Team,RoleInfo,Location,replyCB) ->
    LoginAsk = LoginAskPB.prototype
    LoginAsk.setTeam Team
    LoginAsk.setRoleInfo RoleInfo
    LoginAsk.setLocation Location
    mLayerMgr.sendAsk(RPC_CODE_LOGIN_REQUEST,LoginAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoginReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UpdateRoleInfo : (RoleInfo,replyCB) ->
    UpdateRoleInfoAsk = UpdateRoleInfoAskPB.prototype
    UpdateRoleInfoAsk.setRoleInfo RoleInfo
    mLayerMgr.sendAsk(RPC_CODE_UPDATEROLEINFO_REQUEST,UpdateRoleInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UpdateRoleInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Logout : (RoleInfo,replyCB) ->
    LogoutAsk = LogoutAskPB.prototype
    LogoutAsk.setRoleInfo RoleInfo
    mLayerMgr.sendAsk(RPC_CODE_LOGOUT_REQUEST,LogoutAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LogoutReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateDungeonNotify : (CurSceneId,RoleId,TargetSceneId,replyCB) ->
    CreateDungeonNotifyAsk = CreateDungeonNotifyAskPB.prototype
    CreateDungeonNotifyAsk.setCurSceneId CurSceneId
    CreateDungeonNotifyAsk.setRoleId RoleId
    CreateDungeonNotifyAsk.setTargetSceneId TargetSceneId
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEONNOTIFY_REQUEST,CreateDungeonNotifyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonNotifyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ExitDungeon : (RoleId,replyCB) ->
    ExitDungeonAsk = ExitDungeonAskPB.prototype
    ExitDungeonAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_EXITDUNGEON_REQUEST,ExitDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ExitDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UpdateTeamInfo : (TeamMember,RoleId,SceneId,replyCB) ->
    UpdateTeamInfoAsk = UpdateTeamInfoAskPB.prototype
    UpdateTeamInfoAsk.setTeamMember TeamMember
    UpdateTeamInfoAsk.setRoleId RoleId
    UpdateTeamInfoAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_UPDATETEAMINFO_REQUEST,UpdateTeamInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UpdateTeamInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SummonMember : (RoleId,replyCB) ->
    SummonMemberAsk = SummonMemberAskPB.prototype
    SummonMemberAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_SUMMONMEMBER_REQUEST,SummonMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SummonMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  PlayCgTeam : (PlayRoleId,CgId,State,RoleId,replyCB) ->
    PlayCgTeamAsk = PlayCgTeamAskPB.prototype
    PlayCgTeamAsk.setPlayRoleId PlayRoleId
    PlayCgTeamAsk.setCgId CgId
    PlayCgTeamAsk.setState State
    PlayCgTeamAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_PLAYCGTEAM_REQUEST,PlayCgTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( PlayCgTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SendMail : (Mail,GlobalMailID,replyCB) ->
    SendMailAsk = SendMailAskPB.prototype
    SendMailAsk.setMail Mail
    SendMailAsk.setGlobalMailID GlobalMailID
    mLayerMgr.sendAsk(RPC_CODE_SENDMAIL_REQUEST,SendMailAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SendMailReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetChangeSceneAskNotifyCB : (cb) -> RpcChangeSceneAskNotifyCB = cb
  ChangeSceneAskCB : (data)->
    RpcChangeSceneAskNotifyCB( ChangeSceneAskNotifyPB.decode(data)) if typeof(RpcChangeSceneAskNotifyCB) is "function"
  SetChangeSceneReplyNotifyCB : (cb) -> RpcChangeSceneReplyNotifyCB = cb
  ChangeSceneReplyCB : (data)->
    RpcChangeSceneReplyNotifyCB( ChangeSceneReplyNotifyPB.decode(data)) if typeof(RpcChangeSceneReplyNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "WorldServerModel",
      'AskName': ["EnterScene",
                   "CreateDungeon",
                   "CreateTeam",
                   "JoinTeam",
                   "LeaveTeam",
                   "AppointTeamLeader",
                   "DismissTeam",
                   "KickMember",
                   "ApplyTeam",
                   "AgreeTeamApplicant",
                   "Login",
                   "UpdateRoleInfo",
                   "Logout",
                   "CreateDungeonNotify",
                   "ExitDungeon",
                   "UpdateTeamInfo",
                   "SummonMember",
                   "PlayCgTeam",
                   "SendMail"]
      'ParamterList': [["RoleId","Location"],
                       ["RoleId","TargetSceneId","MemId","DungeonConfigId","CurSceneId","Result","RoleIds"],
                       ["TeamType","TeamMember","Result","Team"],
                       ["TeamId","Result","TeamMember","Team","TeamType","SceneId","RoleId"],
                       ["TeamId","LeaveRoleId","SceneId","NewLeaderRoleId","Result","RoleId"],
                       ["NewLeaderRoleId","SceneId","CurLeaderRoleId","TeamId","Result","RoleId"],
                       ["SceneId","RoleId","TeamId","Result"],
                       ["KickMemberRoleId","SceneId","TeamId","LeaderRoleId","Result","RoleId"],
                       ["TeamId","Result","TeamMember","RoleId","SceneId"],
                       ["RoleId","LeaderRoleId","Result","SceneId","Team"],
                       ["Team","RoleInfo","Location"],
                       ["RoleInfo"],
                       ["RoleInfo"],
                       ["CurSceneId","RoleId","TargetSceneId"],
                       ["RoleId"],
                       ["TeamMember","RoleId","SceneId"],
                       ["RoleId"],
                       ["PlayRoleId","CgId","State","RoleId"],
                       ["Mail","GlobalMailID"]]
      'AskList':[@EnterScene,
                 @CreateDungeon,
                 @CreateTeam,
                 @JoinTeam,
                 @LeaveTeam,
                 @AppointTeamLeader,
                 @DismissTeam,
                 @KickMember,
                 @ApplyTeam,
                 @AgreeTeamApplicant,
                 @Login,
                 @UpdateRoleInfo,
                 @Logout,
                 @CreateDungeonNotify,
                 @ExitDungeon,
                 @UpdateTeamInfo,
                 @SummonMember,
                 @PlayCgTeam,
                 @SendMail]
      'ParamterTypelist': [["uint64","CharacterLocation"],
                       ["uint64","int32","int32","int32","int32","int32","uint64"],
                       ["int32","TeamMemberInfo","int32","TeamInfo"],
                       ["int32","int32","TeamMemberInfo","TeamInfo","int32","int32","uint64"],
                       ["int32","uint64","int32","uint64","int32","uint64"],
                       ["uint64","int32","uint64","int32","int32","uint64"],
                       ["int32","uint64","int32","int32"],
                       ["uint64","int32","int32","uint64","int32","uint64"],
                       ["int32","int32","TeamMemberInfo","uint64","int32"],
                       ["uint64","uint64","int32","int32","TeamInfo"],
                       ["TeamInfo","OnlineUserInfo","CharacterLocation"],
                       ["OnlineUserInfo"],
                       ["OnlineUserInfo"],
                       ["int32","uint64","int32"],
                       ["uint64"],
                       ["TeamMemberInfo","uint64","int32"],
                       ["uint64"],
                       ["uint64","int32","int32","uint64"],
                       ["MailInfo","uint64"]]


module.exports =(()->
  if not WorldServer?
    WorldServer = new WorldServerModel()
  WorldServer)()



  

  

  


