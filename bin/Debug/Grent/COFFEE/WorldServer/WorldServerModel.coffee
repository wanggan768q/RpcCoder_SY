ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 8
RPC_CODE_CHANGESCENE_REQUEST = 851
RPC_CODE_ENTERSCENE_REQUEST = 852
RPC_CODE_CREATEDUNGEON_REQUEST = 853
RPC_CODE_CREATETEAM_REQUEST = 854
RPC_CODE_JOINTEAM_REQUEST = 855
RPC_CODE_LEAVETEAM_REQUEST = 856
RPC_CODE_APPOINTTEAMLEADER_REQUEST = 857
RPC_CODE_DISMISSTEAM_REQUEST = 858
RPC_CODE_KICKMEMBER_REQUEST = 859
RPC_CODE_APPLYTEAM_REQUEST = 860
RPC_CODE_AGREETEAMAPPLICANT_REQUEST = 861
RPC_CODE_LOGIN_REQUEST = 862
RPC_CODE_UPDATEROLEINFO_REQUEST = 863
RPC_CODE_LOGOUT_REQUEST = 864
RPC_CODE_CREATEDUNGEONNOTIFY_REQUEST = 865
RPC_CODE_EXITDUNGEON_REQUEST = 866
RPC_CODE_RELEASEDUNGEON_REQUEST = 867

ChangeSceneAskPB = null
ChangeSceneReplyPB = null
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
ReleaseDungeonAskPB = null
ReleaseDungeonReplyPB = null

class WorldServerModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcChangeSceneAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 CurSceneId = 2[default=-1];
        optional sint32 TargetSceneId = 3[default=-1];
        optional sint32 MemId = 4[default=-1];
        optional sint32 SceneId = 5[default=-1];
      }
      message  RpcChangeSceneReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional sint32 CurSceneId = 3[default=-1];
        optional sint32 TargetSceneId = 4[default=-1];
        optional sint32 MemId = 5[default=-1];
      }
      message  RpcEnterSceneAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
        optional sint32 MemId = 3[default=-1];
      }
      message  RpcEnterSceneReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcCreateDungeonAsk
      {
        optional uint64 RoleId = 2[default=0];
        optional sint32 TargetSceneId = 3[default=-1];
        optional sint32 MemId = 4[default=-1];
        optional sint32 DungeonConfigId = 5[default=-1];
        optional sint32 CurSceneId = 6[default=-1];
        optional sint32 Result = 7[default=-9999];
        repeated uint64 RoleIds = 8;
      }
      message  RpcCreateDungeonReply
      {
      }
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
      message  RpcCreateTeamAsk
      {
        optional sint32 TeamType = 2[default=-1];
        optional TeamMemberInfo TeamMember = 5;
        optional sint32 Result = 6[default=-9999];
        optional TeamInfo Team = 7;
      }
      message  RpcCreateTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcJoinTeamAsk
      {
        optional sint32 TeamId = 1[default=-1];
        optional sint32 Result = 2[default=-9999];
        optional TeamMemberInfo TeamMember = 3;
        optional TeamInfo Team = 4;
        optional sint32 TeamType = 5[default=-1];
        optional sint32 MemId = 6[default=-1];
        optional sint32 SceneId = 7[default=-1];
      }
      message  RpcJoinTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcLeaveTeamAsk
      {
        optional sint32 TeamId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
        optional sint32 MemId = 3[default=-1];
        optional sint32 SceneId = 4[default=-1];
        optional uint64 NewLeaderRoleId = 5[default=0];
        optional sint32 Result = 6[default=-9999];
      }
      message  RpcLeaveTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcAppointTeamLeaderAsk
      {
        optional uint64 NewLeaderRoleId = 1[default=0];
        optional sint32 MemId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
        optional uint64 CurLeaderRoleId = 4[default=0];
        optional sint32 TeamId = 5[default=-1];
        optional sint32 Result = 6[default=-9999];
      }
      message  RpcAppointTeamLeaderReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcDismissTeamAsk
      {
        optional sint32 SceneId = 1[default=-1];
        optional sint32 MemId = 2[default=-1];
        optional uint64 RoleId = 3[default=0];
        optional sint32 TeamId = 4[default=-1];
        optional sint32 Result = 5[default=-9999];
      }
      message  RpcDismissTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcKickMemberAsk
      {
        optional uint64 KickMemberRoleId = 1[default=0];
        optional sint32 MemId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
        optional sint32 TeamId = 4[default=-1];
        optional uint64 LeaderRoleId = 5[default=0];
        optional sint32 Result = 6[default=-9999];
      }
      message  RpcKickMemberReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcApplyTeamAsk
      {
        optional sint32 TeamId = 1[default=-1];
        optional sint32 Result = 2[default=-9999];
        optional TeamMemberInfo TeamMember = 3;
        optional sint32 MemId = 4[default=-1];
        optional sint32 SceneId = 5[default=-1];
      }
      message  RpcApplyTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcAgreeTeamApplicantAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 LeaderRoleId = 3[default=0];
        optional sint32 Result = 4[default=-9999];
        optional sint32 MemId = 5[default=-1];
        optional sint32 SceneId = 6[default=-1];
        optional TeamInfo Team = 7;
      }
      message  RpcAgreeTeamApplicantReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  OnlineUserInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 Level = 2[default=-1];
        optional sint32 Scene_id = 3[default=-1];
        optional sint32 Memid = 4[default=-1];
      }
      message  RpcLoginAsk
      {
        optional TeamInfo Team = 1;
        optional sint32 MemId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
        optional OnlineUserInfo RoleInfo = 4;
      }
      message  RpcLoginReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcUpdateRoleInfoAsk
      {
        optional OnlineUserInfo RoleInfo = 1;
      }
      message  RpcUpdateRoleInfoReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcLogoutAsk
      {
        optional OnlineUserInfo RoleInfo = 1;
      }
      message  RpcLogoutReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcCreateDungeonNotifyAsk
      {
        optional sint32 CurSceneId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
        optional sint32 MemId = 3[default=-1];
        optional sint32 TargetSceneId = 5[default=-1];
      }
      message  RpcCreateDungeonNotifyReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcExitDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcReleaseDungeonAsk
      {
      }
      message  RpcReleaseDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    ChangeSceneAskPB = Proto.build("RpcChangeSceneAsk")
    ChangeSceneReplyPB = Proto.build("RpcChangeSceneReply")
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
    ReleaseDungeonAskPB = Proto.build("RpcReleaseDungeonAsk")
    ReleaseDungeonReplyPB = Proto.build("RpcReleaseDungeonReply")






  ChangeScene : (RoleId,CurSceneId,TargetSceneId,MemId,SceneId,replyCB) ->
    ChangeSceneAsk = ChangeSceneAskPB.prototype
    ChangeSceneAsk.setRoleId RoleId
    ChangeSceneAsk.setCurSceneId CurSceneId
    ChangeSceneAsk.setTargetSceneId TargetSceneId
    ChangeSceneAsk.setMemId MemId
    ChangeSceneAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_CHANGESCENE_REQUEST,ChangeSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EnterScene : (RoleId,SceneId,MemId,replyCB) ->
    EnterSceneAsk = EnterSceneAskPB.prototype
    EnterSceneAsk.setRoleId RoleId
    EnterSceneAsk.setSceneId SceneId
    EnterSceneAsk.setMemId MemId
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
  JoinTeam : (TeamId,Result,TeamMember,Team,TeamType,MemId,SceneId,replyCB) ->
    JoinTeamAsk = JoinTeamAskPB.prototype
    JoinTeamAsk.setTeamId TeamId
    JoinTeamAsk.setResult Result
    JoinTeamAsk.setTeamMember TeamMember
    JoinTeamAsk.setTeam Team
    JoinTeamAsk.setTeamType TeamType
    JoinTeamAsk.setMemId MemId
    JoinTeamAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_JOINTEAM_REQUEST,JoinTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( JoinTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LeaveTeam : (TeamId,RoleId,MemId,SceneId,NewLeaderRoleId,Result,replyCB) ->
    LeaveTeamAsk = LeaveTeamAskPB.prototype
    LeaveTeamAsk.setTeamId TeamId
    LeaveTeamAsk.setRoleId RoleId
    LeaveTeamAsk.setMemId MemId
    LeaveTeamAsk.setSceneId SceneId
    LeaveTeamAsk.setNewLeaderRoleId NewLeaderRoleId
    LeaveTeamAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_LEAVETEAM_REQUEST,LeaveTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LeaveTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AppointTeamLeader : (NewLeaderRoleId,MemId,SceneId,CurLeaderRoleId,TeamId,Result,replyCB) ->
    AppointTeamLeaderAsk = AppointTeamLeaderAskPB.prototype
    AppointTeamLeaderAsk.setNewLeaderRoleId NewLeaderRoleId
    AppointTeamLeaderAsk.setMemId MemId
    AppointTeamLeaderAsk.setSceneId SceneId
    AppointTeamLeaderAsk.setCurLeaderRoleId CurLeaderRoleId
    AppointTeamLeaderAsk.setTeamId TeamId
    AppointTeamLeaderAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_APPOINTTEAMLEADER_REQUEST,AppointTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AppointTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DismissTeam : (SceneId,MemId,RoleId,TeamId,Result,replyCB) ->
    DismissTeamAsk = DismissTeamAskPB.prototype
    DismissTeamAsk.setSceneId SceneId
    DismissTeamAsk.setMemId MemId
    DismissTeamAsk.setRoleId RoleId
    DismissTeamAsk.setTeamId TeamId
    DismissTeamAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_DISMISSTEAM_REQUEST,DismissTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DismissTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  KickMember : (KickMemberRoleId,MemId,SceneId,TeamId,LeaderRoleId,Result,replyCB) ->
    KickMemberAsk = KickMemberAskPB.prototype
    KickMemberAsk.setKickMemberRoleId KickMemberRoleId
    KickMemberAsk.setMemId MemId
    KickMemberAsk.setSceneId SceneId
    KickMemberAsk.setTeamId TeamId
    KickMemberAsk.setLeaderRoleId LeaderRoleId
    KickMemberAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_KICKMEMBER_REQUEST,KickMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( KickMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyTeam : (TeamId,Result,TeamMember,MemId,SceneId,replyCB) ->
    ApplyTeamAsk = ApplyTeamAskPB.prototype
    ApplyTeamAsk.setTeamId TeamId
    ApplyTeamAsk.setResult Result
    ApplyTeamAsk.setTeamMember TeamMember
    ApplyTeamAsk.setMemId MemId
    ApplyTeamAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_APPLYTEAM_REQUEST,ApplyTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeTeamApplicant : (RoleId,LeaderRoleId,Result,MemId,SceneId,Team,replyCB) ->
    AgreeTeamApplicantAsk = AgreeTeamApplicantAskPB.prototype
    AgreeTeamApplicantAsk.setRoleId RoleId
    AgreeTeamApplicantAsk.setLeaderRoleId LeaderRoleId
    AgreeTeamApplicantAsk.setResult Result
    AgreeTeamApplicantAsk.setMemId MemId
    AgreeTeamApplicantAsk.setSceneId SceneId
    AgreeTeamApplicantAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_AGREETEAMAPPLICANT_REQUEST,AgreeTeamApplicantAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeTeamApplicantReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Login : (Team,MemId,SceneId,RoleInfo,replyCB) ->
    LoginAsk = LoginAskPB.prototype
    LoginAsk.setTeam Team
    LoginAsk.setMemId MemId
    LoginAsk.setSceneId SceneId
    LoginAsk.setRoleInfo RoleInfo
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
  CreateDungeonNotify : (CurSceneId,RoleId,MemId,TargetSceneId,replyCB) ->
    CreateDungeonNotifyAsk = CreateDungeonNotifyAskPB.prototype
    CreateDungeonNotifyAsk.setCurSceneId CurSceneId
    CreateDungeonNotifyAsk.setRoleId RoleId
    CreateDungeonNotifyAsk.setMemId MemId
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
  ReleaseDungeon : (replyCB) ->
    ReleaseDungeonAsk = ReleaseDungeonAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_RELEASEDUNGEON_REQUEST,ReleaseDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ReleaseDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "WorldServerModel",
      'AskName': ["ChangeScene",
                   "EnterScene",
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
                   "ReleaseDungeon"]
      'ParamterList': [["RoleId","CurSceneId","TargetSceneId","MemId","SceneId"],
                       ["RoleId","SceneId","MemId"],
                       ["RoleId","TargetSceneId","MemId","DungeonConfigId","CurSceneId","Result","RoleIds"],
                       ["TeamType","TeamMember","Result","Team"],
                       ["TeamId","Result","TeamMember","Team","TeamType","MemId","SceneId"],
                       ["TeamId","RoleId","MemId","SceneId","NewLeaderRoleId","Result"],
                       ["NewLeaderRoleId","MemId","SceneId","CurLeaderRoleId","TeamId","Result"],
                       ["SceneId","MemId","RoleId","TeamId","Result"],
                       ["KickMemberRoleId","MemId","SceneId","TeamId","LeaderRoleId","Result"],
                       ["TeamId","Result","TeamMember","MemId","SceneId"],
                       ["RoleId","LeaderRoleId","Result","MemId","SceneId","Team"],
                       ["Team","MemId","SceneId","RoleInfo"],
                       ["RoleInfo"],
                       ["RoleInfo"],
                       ["CurSceneId","RoleId","MemId","TargetSceneId"],
                       ["RoleId"],
                       []]
      'AskList':[@ChangeScene,
                 @EnterScene,
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
                 @ReleaseDungeon]
      'ParamterTypelist': [["uint64","sint32","sint32","sint32","sint32"],
                       ["uint64","sint32","sint32"],
                       ["uint64","sint32","sint32","sint32","sint32","sint32","uint64"],
                       ["sint32","TeamMemberInfo","sint32","TeamInfo"],
                       ["sint32","sint32","TeamMemberInfo","TeamInfo","sint32","sint32","sint32"],
                       ["sint32","uint64","sint32","sint32","uint64","sint32"],
                       ["uint64","sint32","sint32","uint64","sint32","sint32"],
                       ["sint32","sint32","uint64","sint32","sint32"],
                       ["uint64","sint32","sint32","sint32","uint64","sint32"],
                       ["sint32","sint32","TeamMemberInfo","sint32","sint32"],
                       ["uint64","uint64","sint32","sint32","sint32","TeamInfo"],
                       ["TeamInfo","sint32","sint32","OnlineUserInfo"],
                       ["OnlineUserInfo"],
                       ["OnlineUserInfo"],
                       ["sint32","uint64","sint32","sint32"],
                       ["uint64"],
                       []]


module.exports =(()->
  if not WorldServer?
    WorldServer = new WorldServerModel()
  WorldServer)()



  

  

  


