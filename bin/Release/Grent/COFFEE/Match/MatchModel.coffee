ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcCancelMatchNotifyNotifyCB = null
RpcPrepareRoomNotifyCB = null
RpcRoomCancelNotifyCB = null
RpcMemberReadyNotifyCB = null


ModuleId = 39
RPC_CODE_AUTOMATCH_REQUEST = 3951
RPC_CODE_CANCELMATCH_REQUEST = 3952
RPC_CODE_CANCELMATCHNOTIFY_NOTIFY = 3953
RPC_CODE_PREPAREROOM_NOTIFY = 3954
RPC_CODE_READY_REQUEST = 3955
RPC_CODE_CANCELREADY_REQUEST = 3956
RPC_CODE_ROOMCANCEL_NOTIFY = 3957
RPC_CODE_MEMBERREADY_NOTIFY = 3958

AutoMatchAskPB = null
AutoMatchReplyPB = null
CancelMatchAskPB = null
CancelMatchReplyPB = null
CancelMatchNotifyNotifyPB = null
PrepareRoomNotifyPB = null
ReadyAskPB = null
ReadyReplyPB = null
CancelReadyAskPB = null
CancelReadyReplyPB = null
RoomCancelNotifyPB = null
MemberReadyNotifyPB = null

class MatchModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  PlayerMatchData
      {
        optional int32 MatchType = 1[default=0];
        optional int32 Elo = 2[default=0];
        optional int32 Auto = 3[default=0];
      }
      message  RpcAutoMatchAsk
      {
        optional PlayerMatchData MatchInfo = 1;
      }
      message  RpcAutoMatchReply
      {
        optional int32 Result = 1[default=-1];
        optional PlayerMatchData MatchInfo = 2;
      }
      message  RpcCancelMatchAsk
      {
      }
      message  RpcCancelMatchReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcCancelMatchNotifyNotify
      {
      }
      message  MatchInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 2[default=0];
        optional int32 ConfigId = 3[default=-1];
        optional int32 ProfessionId = 4[default=-1];
        optional string Name = 5;
        optional int32 Ready = 6[default=0];
        optional int32 Camp = 7[default=0];
        optional int32 Integral = 12[default=0];
        optional int32 Section = 13[default=0];
      }
      message  MatchRoomCamps
      {
        repeated MatchInfo Players = 1;
      }
      message  MatchTarget
      {
        optional int32 DungeonConfigId = 1[default=-1];
        optional int32 SceneConfigId = 2[default=-1];
      }
      message  PBMatchRoom
      {
        repeated MatchRoomCamps Camps = 1;
        optional MatchTarget MatchTarget = 6;
        optional uint64 RoomId = 7[default=0];
        optional int32 MatchType = 8[default=-1];
      }
      message  RpcPrepareRoomNotify
      {
        optional PBMatchRoom ReadyRoom = 1;
      }
      message  RpcReadyAsk
      {
        optional int32 MatchType = 1[default=-1];
        optional uint64 RoomId = 2[default=0];
      }
      message  RpcReadyReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcCancelReadyAsk
      {
        optional int32 MatchType = 1[default=-1];
        optional uint64 RoomId = 2[default=0];
      }
      message  RpcCancelReadyReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcRoomCancelNotify
      {
      }
      message  RpcMemberReadyNotify
      {
        optional uint64 RoleId = 1[default=0];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    AutoMatchAskPB = Proto.build("RpcAutoMatchAsk")
    AutoMatchReplyPB = Proto.build("RpcAutoMatchReply")
    CancelMatchAskPB = Proto.build("RpcCancelMatchAsk")
    CancelMatchReplyPB = Proto.build("RpcCancelMatchReply")
    CancelMatchNotifyNotifyPB = Proto.build("RpcCancelMatchNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_CANCELMATCHNOTIFY_NOTIFY,@CancelMatchNotifyCB)
    PrepareRoomNotifyPB = Proto.build("RpcPrepareRoomNotify")
    mLayerMgr.registerNotify(RPC_CODE_PREPAREROOM_NOTIFY,@PrepareRoomCB)
    ReadyAskPB = Proto.build("RpcReadyAsk")
    ReadyReplyPB = Proto.build("RpcReadyReply")
    CancelReadyAskPB = Proto.build("RpcCancelReadyAsk")
    CancelReadyReplyPB = Proto.build("RpcCancelReadyReply")
    RoomCancelNotifyPB = Proto.build("RpcRoomCancelNotify")
    mLayerMgr.registerNotify(RPC_CODE_ROOMCANCEL_NOTIFY,@RoomCancelCB)
    MemberReadyNotifyPB = Proto.build("RpcMemberReadyNotify")
    mLayerMgr.registerNotify(RPC_CODE_MEMBERREADY_NOTIFY,@MemberReadyCB)






  AutoMatch : (MatchInfo,replyCB) ->
    AutoMatchAsk = AutoMatchAskPB.prototype
    AutoMatchAsk.setMatchInfo MatchInfo
    mLayerMgr.sendAsk(RPC_CODE_AUTOMATCH_REQUEST,AutoMatchAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AutoMatchReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CancelMatch : (replyCB) ->
    CancelMatchAsk = CancelMatchAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_CANCELMATCH_REQUEST,CancelMatchAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CancelMatchReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Ready : (MatchType,RoomId,replyCB) ->
    ReadyAsk = ReadyAskPB.prototype
    ReadyAsk.setMatchType MatchType
    ReadyAsk.setRoomId RoomId
    mLayerMgr.sendAsk(RPC_CODE_READY_REQUEST,ReadyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ReadyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CancelReady : (MatchType,RoomId,replyCB) ->
    CancelReadyAsk = CancelReadyAskPB.prototype
    CancelReadyAsk.setMatchType MatchType
    CancelReadyAsk.setRoomId RoomId
    mLayerMgr.sendAsk(RPC_CODE_CANCELREADY_REQUEST,CancelReadyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CancelReadyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetCancelMatchNotifyNotifyCB : (cb) -> RpcCancelMatchNotifyNotifyCB = cb
  CancelMatchNotifyCB : (data)->
    RpcCancelMatchNotifyNotifyCB( CancelMatchNotifyNotifyPB.decode(data)) if typeof(RpcCancelMatchNotifyNotifyCB) is "function"
  SetPrepareRoomNotifyCB : (cb) -> RpcPrepareRoomNotifyCB = cb
  PrepareRoomCB : (data)->
    RpcPrepareRoomNotifyCB( PrepareRoomNotifyPB.decode(data)) if typeof(RpcPrepareRoomNotifyCB) is "function"
  SetRoomCancelNotifyCB : (cb) -> RpcRoomCancelNotifyCB = cb
  RoomCancelCB : (data)->
    RpcRoomCancelNotifyCB( RoomCancelNotifyPB.decode(data)) if typeof(RpcRoomCancelNotifyCB) is "function"
  SetMemberReadyNotifyCB : (cb) -> RpcMemberReadyNotifyCB = cb
  MemberReadyCB : (data)->
    RpcMemberReadyNotifyCB( MemberReadyNotifyPB.decode(data)) if typeof(RpcMemberReadyNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "MatchModel",
      'AskName': ["AutoMatch",
                   "CancelMatch",
                   "Ready",
                   "CancelReady"]
      'ParamterList': [["MatchInfo"],
                       [],
                       ["MatchType","RoomId"],
                       ["MatchType","RoomId"]]
      'AskList':[@AutoMatch,
                 @CancelMatch,
                 @Ready,
                 @CancelReady]
      'ParamterTypelist': [["PlayerMatchData"],
                       [],
                       ["int32","uint64"],
                       ["int32","uint64"]]


module.exports =(()->
  if not Match?
    Match = new MatchModel()
  Match)()



  

  

  


