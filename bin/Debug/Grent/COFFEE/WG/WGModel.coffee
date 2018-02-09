ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 11
RPC_CODE_INFORMCREATETEAM_REQUEST = 1151
RPC_CODE_INFORMJOINTEAM_REQUEST = 1152
RPC_CODE_INFORMLEAVE_REQUEST = 1153
RPC_CODE_INFORMAPPOINTTEAMLEADER_REQUEST = 1154
RPC_CODE_INFORMKICKTEAMMEMBER_REQUEST = 1155
RPC_CODE_INFORMDISSMISSTEAM_REQUEST = 1156
RPC_CODE_INFORMAPPLYTEAM_REQUEST = 1157
RPC_CODE_AGREETEAMAPPLICANT_REQUEST = 1158
RPC_CODE_INFORMLOGIN_REQUEST = 1159

InformCreateTeamAskPB = null
InformCreateTeamReplyPB = null
InformJoinTeamAskPB = null
InformJoinTeamReplyPB = null
InformLeaveAskPB = null
InformLeaveReplyPB = null
InformAppointTeamLeaderAskPB = null
InformAppointTeamLeaderReplyPB = null
InformKickTeamMemberAskPB = null
InformKickTeamMemberReplyPB = null
InformDissmissTeamAskPB = null
InformDissmissTeamReplyPB = null
InformApplyTeamAskPB = null
InformApplyTeamReplyPB = null
AgreeTeamApplicantAskPB = null
AgreeTeamApplicantReplyPB = null
InformLoginAskPB = null
InformLoginReplyPB = null

class WGModel
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
      message  RpcInformCreateTeamAsk
      {
        optional TeamInfo Team = 1;
        optional sint32 Result = 2[default=-9999];
      }
      message  RpcInformCreateTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformJoinTeamAsk
      {
        optional TeamMemberInfo Member = 5;
        optional TeamInfo Team = 6;
      }
      message  RpcInformJoinTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformLeaveAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 NewLeaderRoleId = 2[default=0];
        optional sint32 Result = 3[default=-9999];
      }
      message  RpcInformLeaveReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformAppointTeamLeaderAsk
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 NewLeaderRoleId = 2[default=0];
        optional uint64 OldLeaderRoleId = 3[default=0];
      }
      message  RpcInformAppointTeamLeaderReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformKickTeamMemberAsk
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 KickedMemberRoleId = 2[default=0];
        optional uint64 LeaderRoleId = 3[default=0];
      }
      message  RpcInformKickTeamMemberReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformDissmissTeamAsk
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 LeaderRoleId = 2[default=0];
      }
      message  RpcInformDissmissTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformApplyTeamAsk
      {
        optional TeamMemberInfo TeamMember = 1;
        optional sint32 Result = 2[default=-9999];
        optional sint32 TeamId = 3[default=-1];
      }
      message  RpcInformApplyTeamReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcAgreeTeamApplicantAsk
      {
        optional TeamInfo Team = 2;
      }
      message  RpcAgreeTeamApplicantReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformLoginAsk
      {
        optional TeamInfo Team = 1;
      }
      message  RpcInformLoginReply
      {
        optional sint32 Result = 1[default=-9999];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    InformCreateTeamAskPB = Proto.build("RpcInformCreateTeamAsk")
    InformCreateTeamReplyPB = Proto.build("RpcInformCreateTeamReply")
    InformJoinTeamAskPB = Proto.build("RpcInformJoinTeamAsk")
    InformJoinTeamReplyPB = Proto.build("RpcInformJoinTeamReply")
    InformLeaveAskPB = Proto.build("RpcInformLeaveAsk")
    InformLeaveReplyPB = Proto.build("RpcInformLeaveReply")
    InformAppointTeamLeaderAskPB = Proto.build("RpcInformAppointTeamLeaderAsk")
    InformAppointTeamLeaderReplyPB = Proto.build("RpcInformAppointTeamLeaderReply")
    InformKickTeamMemberAskPB = Proto.build("RpcInformKickTeamMemberAsk")
    InformKickTeamMemberReplyPB = Proto.build("RpcInformKickTeamMemberReply")
    InformDissmissTeamAskPB = Proto.build("RpcInformDissmissTeamAsk")
    InformDissmissTeamReplyPB = Proto.build("RpcInformDissmissTeamReply")
    InformApplyTeamAskPB = Proto.build("RpcInformApplyTeamAsk")
    InformApplyTeamReplyPB = Proto.build("RpcInformApplyTeamReply")
    AgreeTeamApplicantAskPB = Proto.build("RpcAgreeTeamApplicantAsk")
    AgreeTeamApplicantReplyPB = Proto.build("RpcAgreeTeamApplicantReply")
    InformLoginAskPB = Proto.build("RpcInformLoginAsk")
    InformLoginReplyPB = Proto.build("RpcInformLoginReply")






  InformCreateTeam : (Team,Result,replyCB) ->
    InformCreateTeamAsk = InformCreateTeamAskPB.prototype
    InformCreateTeamAsk.setTeam Team
    InformCreateTeamAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_INFORMCREATETEAM_REQUEST,InformCreateTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformCreateTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformJoinTeam : (Member,Team,replyCB) ->
    InformJoinTeamAsk = InformJoinTeamAskPB.prototype
    InformJoinTeamAsk.setMember Member
    InformJoinTeamAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_INFORMJOINTEAM_REQUEST,InformJoinTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformJoinTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformLeave : (RoleId,NewLeaderRoleId,Result,replyCB) ->
    InformLeaveAsk = InformLeaveAskPB.prototype
    InformLeaveAsk.setRoleId RoleId
    InformLeaveAsk.setNewLeaderRoleId NewLeaderRoleId
    InformLeaveAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_INFORMLEAVE_REQUEST,InformLeaveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformLeaveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformAppointTeamLeader : (Result,NewLeaderRoleId,OldLeaderRoleId,replyCB) ->
    InformAppointTeamLeaderAsk = InformAppointTeamLeaderAskPB.prototype
    InformAppointTeamLeaderAsk.setResult Result
    InformAppointTeamLeaderAsk.setNewLeaderRoleId NewLeaderRoleId
    InformAppointTeamLeaderAsk.setOldLeaderRoleId OldLeaderRoleId
    mLayerMgr.sendAsk(RPC_CODE_INFORMAPPOINTTEAMLEADER_REQUEST,InformAppointTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformAppointTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformKickTeamMember : (Result,KickedMemberRoleId,LeaderRoleId,replyCB) ->
    InformKickTeamMemberAsk = InformKickTeamMemberAskPB.prototype
    InformKickTeamMemberAsk.setResult Result
    InformKickTeamMemberAsk.setKickedMemberRoleId KickedMemberRoleId
    InformKickTeamMemberAsk.setLeaderRoleId LeaderRoleId
    mLayerMgr.sendAsk(RPC_CODE_INFORMKICKTEAMMEMBER_REQUEST,InformKickTeamMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformKickTeamMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformDissmissTeam : (Result,LeaderRoleId,replyCB) ->
    InformDissmissTeamAsk = InformDissmissTeamAskPB.prototype
    InformDissmissTeamAsk.setResult Result
    InformDissmissTeamAsk.setLeaderRoleId LeaderRoleId
    mLayerMgr.sendAsk(RPC_CODE_INFORMDISSMISSTEAM_REQUEST,InformDissmissTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformDissmissTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformApplyTeam : (TeamMember,Result,TeamId,replyCB) ->
    InformApplyTeamAsk = InformApplyTeamAskPB.prototype
    InformApplyTeamAsk.setTeamMember TeamMember
    InformApplyTeamAsk.setResult Result
    InformApplyTeamAsk.setTeamId TeamId
    mLayerMgr.sendAsk(RPC_CODE_INFORMAPPLYTEAM_REQUEST,InformApplyTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformApplyTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeTeamApplicant : (Team,replyCB) ->
    AgreeTeamApplicantAsk = AgreeTeamApplicantAskPB.prototype
    AgreeTeamApplicantAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_AGREETEAMAPPLICANT_REQUEST,AgreeTeamApplicantAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeTeamApplicantReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformLogin : (Team,replyCB) ->
    InformLoginAsk = InformLoginAskPB.prototype
    InformLoginAsk.setTeam Team
    mLayerMgr.sendAsk(RPC_CODE_INFORMLOGIN_REQUEST,InformLoginAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformLoginReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "WGModel",
      'AskName': ["InformCreateTeam",
                   "InformJoinTeam",
                   "InformLeave",
                   "InformAppointTeamLeader",
                   "InformKickTeamMember",
                   "InformDissmissTeam",
                   "InformApplyTeam",
                   "AgreeTeamApplicant",
                   "InformLogin"]
      'ParamterList': [["Team","Result"],
                       ["Member","Team"],
                       ["RoleId","NewLeaderRoleId","Result"],
                       ["Result","NewLeaderRoleId","OldLeaderRoleId"],
                       ["Result","KickedMemberRoleId","LeaderRoleId"],
                       ["Result","LeaderRoleId"],
                       ["TeamMember","Result","TeamId"],
                       ["Team"],
                       ["Team"]]
      'AskList':[@InformCreateTeam,
                 @InformJoinTeam,
                 @InformLeave,
                 @InformAppointTeamLeader,
                 @InformKickTeamMember,
                 @InformDissmissTeam,
                 @InformApplyTeam,
                 @AgreeTeamApplicant,
                 @InformLogin]
      'ParamterTypelist': [["TeamInfo","sint32"],
                       ["TeamMemberInfo","TeamInfo"],
                       ["uint64","uint64","sint32"],
                       ["sint32","uint64","uint64"],
                       ["sint32","uint64","uint64"],
                       ["sint32","uint64"],
                       ["TeamMemberInfo","sint32","sint32"],
                       ["TeamInfo"],
                       ["TeamInfo"]]


module.exports =(()->
  if not WG?
    WG = new WGModel()
  WG)()



  

  

  


