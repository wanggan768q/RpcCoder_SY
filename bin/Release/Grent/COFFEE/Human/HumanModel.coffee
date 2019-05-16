ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcMoveCheckNotifyCB = null
RpcRespawnOtherNotifyCB = null
RpcRoleDieNotifyCB = null
RpcChangeAnimationStateNotifyCB = null
RpcClientAttributesNotifyCB = null


ModuleId = 4
RPC_CODE_MOVE_REQUEST = 451
RPC_CODE_STOPMOVE_REQUEST = 452
RPC_CODE_MOVECHECK_NOTIFY = 453
RPC_CODE_RESPAWN_REQUEST = 454
RPC_CODE_RESPAWNOTHER_NOTIFY = 455
RPC_CODE_MOVEPOS_REQUEST = 456
RPC_CODE_ROLEDIE_NOTIFY = 457
RPC_CODE_CHANGEANIMATIONSTATE_NOTIFY = 458
RPC_CODE_FUNCNOTICE_REQUEST = 459
RPC_CODE_FUNCNOTICECHANGE_REQUEST = 460
RPC_CODE_CLIENTATTRIBUTES_NOTIFY = 461

MoveAskPB = null
MoveReplyPB = null
StopMoveAskPB = null
StopMoveReplyPB = null
MoveCheckNotifyPB = null
RespawnAskPB = null
RespawnReplyPB = null
RespawnOtherNotifyPB = null
MovePosAskPB = null
MovePosReplyPB = null
RoleDieNotifyPB = null
ChangeAnimationStateNotifyPB = null
FuncNoticeAskPB = null
FuncNoticeReplyPB = null
FuncNoticeChangeAskPB = null
FuncNoticeChangeReplyPB = null
ClientAttributesNotifyPB = null

class HumanModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcMoveAsk
      {
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
        optional int32 ObjId = 5[default=-1];
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcMoveReply
      {
        optional int32 Result = 1[default=-9999];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
        optional int32 ObjId = 4[default=-1];
      }
      message  RpcStopMoveAsk
      {
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
        optional int32 ObjId = 5[default=-1];
      }
      message  RpcStopMoveReply
      {
        optional int32 Result = 1[default=-9999];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
        optional int32 ObjId = 4[default=-1];
      }
      message  RpcMoveCheckNotify
      {
        optional int32 ObjId = 1[default=-1];
        optional float Dir = 3;
        optional float X = 4;
        optional float Y = 5;
      }
      message  RpcRespawnAsk
      {
        optional int32 ReviveType = 1[default=-1];
      }
      message  RpcRespawnReply
      {
        optional int32 Result = 1[default=-9999];
        optional int32 ReviveType = 2[default=-1];
      }
      message  RpcRespawnOtherNotify
      {
        optional int32 ObjId = 1[default=-1];
      }
      message  RpcMovePosAsk
      {
        repeated Vector3 PosList = 1;
        optional float Dir = 2;
        optional int32 ObjId = 3[default=-1];
      }
      message  RpcMovePosReply
      {
        optional int32 Result = 1[default=-1];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
        optional int32 ObjId = 4[default=-1];
      }
      message  RpcRoleDieNotify
      {
        optional int64 KillerGuid = 1[default=-1];
        optional string KillerName = 2;
        optional int32 KillerType = 3[default=-1];
        optional int32 RevieCDTime = 4[default=-1];
      }
      message  RpcChangeAnimationStateNotify
      {
        optional bool AnimationState = 1;
      }
      message  RpcFuncNoticeAsk
      {
      }
      message  RpcFuncNoticeReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 FuncIndex = 2[default=-1];
      }
      message  RpcFuncNoticeChangeAsk
      {
      }
      message  RpcFuncNoticeChangeReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcClientAttributesNotify
      {
        optional int32 ObjId = 2[default=-1];
        optional bool IsTouchJoyStick = 6;
        optional bool IsHold = 7;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MoveAskPB = Proto.build("RpcMoveAsk")
    MoveReplyPB = Proto.build("RpcMoveReply")
    StopMoveAskPB = Proto.build("RpcStopMoveAsk")
    StopMoveReplyPB = Proto.build("RpcStopMoveReply")
    MoveCheckNotifyPB = Proto.build("RpcMoveCheckNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVECHECK_NOTIFY,@MoveCheckCB)
    RespawnAskPB = Proto.build("RpcRespawnAsk")
    RespawnReplyPB = Proto.build("RpcRespawnReply")
    RespawnOtherNotifyPB = Proto.build("RpcRespawnOtherNotify")
    mLayerMgr.registerNotify(RPC_CODE_RESPAWNOTHER_NOTIFY,@RespawnOtherCB)
    MovePosAskPB = Proto.build("RpcMovePosAsk")
    MovePosReplyPB = Proto.build("RpcMovePosReply")
    RoleDieNotifyPB = Proto.build("RpcRoleDieNotify")
    mLayerMgr.registerNotify(RPC_CODE_ROLEDIE_NOTIFY,@RoleDieCB)
    ChangeAnimationStateNotifyPB = Proto.build("RpcChangeAnimationStateNotify")
    FuncNoticeAskPB = Proto.build("RpcFuncNoticeAsk")
    FuncNoticeReplyPB = Proto.build("RpcFuncNoticeReply")
    FuncNoticeChangeAskPB = Proto.build("RpcFuncNoticeChangeAsk")
    FuncNoticeChangeReplyPB = Proto.build("RpcFuncNoticeChangeReply")
    ClientAttributesNotifyPB = Proto.build("RpcClientAttributesNotify")
    mLayerMgr.registerNotify(RPC_CODE_CLIENTATTRIBUTES_NOTIFY,@ClientAttributesCB)






  Move : (Dir,X,Z,ObjId,replyCB) ->
    MoveAsk = MoveAskPB.prototype
    MoveAsk.setDir Dir
    MoveAsk.setX X
    MoveAsk.setZ Z
    MoveAsk.setObjId ObjId
    mLayerMgr.sendAsk(RPC_CODE_MOVE_REQUEST,MoveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MoveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  StopMove : (Dir,X,Z,ObjId,replyCB) ->
    StopMoveAsk = StopMoveAskPB.prototype
    StopMoveAsk.setDir Dir
    StopMoveAsk.setX X
    StopMoveAsk.setZ Z
    StopMoveAsk.setObjId ObjId
    mLayerMgr.sendAsk(RPC_CODE_STOPMOVE_REQUEST,StopMoveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( StopMoveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MoveCheck : (ObjId,Dir,X,Y) ->
    MoveCheckNotify = MoveCheckNotifyPB.prototype
    MoveCheckNotify.setObjId ObjId
    MoveCheckNotify.setDir Dir
    MoveCheckNotify.setX X
    MoveCheckNotify.setY Y
    mLayerMgr.sendNotify(RPC_CODE_MOVECHECK_NOTIFY,MoveCheckNotify)
  Respawn : (ReviveType,replyCB) ->
    RespawnAsk = RespawnAskPB.prototype
    RespawnAsk.setReviveType ReviveType
    mLayerMgr.sendAsk(RPC_CODE_RESPAWN_REQUEST,RespawnAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RespawnReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MovePos : (PosList,Dir,ObjId,replyCB) ->
    MovePosAsk = MovePosAskPB.prototype
    MovePosAsk.setPosList PosList
    MovePosAsk.setDir Dir
    MovePosAsk.setObjId ObjId
    mLayerMgr.sendAsk(RPC_CODE_MOVEPOS_REQUEST,MovePosAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MovePosReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeAnimationState : (AnimationState) ->
    ChangeAnimationStateNotify = ChangeAnimationStateNotifyPB.prototype
    ChangeAnimationStateNotify.setAnimationState AnimationState
    mLayerMgr.sendNotify(RPC_CODE_CHANGEANIMATIONSTATE_NOTIFY,ChangeAnimationStateNotify)
  FuncNotice : (replyCB) ->
    FuncNoticeAsk = FuncNoticeAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_FUNCNOTICE_REQUEST,FuncNoticeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( FuncNoticeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  FuncNoticeChange : (replyCB) ->
    FuncNoticeChangeAsk = FuncNoticeChangeAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_FUNCNOTICECHANGE_REQUEST,FuncNoticeChangeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( FuncNoticeChangeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ClientAttributes : (ObjId,IsTouchJoyStick,IsHold) ->
    ClientAttributesNotify = ClientAttributesNotifyPB.prototype
    ClientAttributesNotify.setObjId ObjId
    ClientAttributesNotify.setIsTouchJoyStick IsTouchJoyStick
    ClientAttributesNotify.setIsHold IsHold
    mLayerMgr.sendNotify(RPC_CODE_CLIENTATTRIBUTES_NOTIFY,ClientAttributesNotify)


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetMoveCheckNotifyCB : (cb) -> RpcMoveCheckNotifyCB = cb
  MoveCheckCB : (data)->
    RpcMoveCheckNotifyCB( MoveCheckNotifyPB.decode(data)) if typeof(RpcMoveCheckNotifyCB) is "function"
  SetRespawnOtherNotifyCB : (cb) -> RpcRespawnOtherNotifyCB = cb
  RespawnOtherCB : (data)->
    RpcRespawnOtherNotifyCB( RespawnOtherNotifyPB.decode(data)) if typeof(RpcRespawnOtherNotifyCB) is "function"
  SetRoleDieNotifyCB : (cb) -> RpcRoleDieNotifyCB = cb
  RoleDieCB : (data)->
    RpcRoleDieNotifyCB( RoleDieNotifyPB.decode(data)) if typeof(RpcRoleDieNotifyCB) is "function"
  SetClientAttributesNotifyCB : (cb) -> RpcClientAttributesNotifyCB = cb
  ClientAttributesCB : (data)->
    RpcClientAttributesNotifyCB( ClientAttributesNotifyPB.decode(data)) if typeof(RpcClientAttributesNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "HumanModel",
      'AskName': ["Move",
                   "StopMove",
                   "MoveCheck",
                   "Respawn",
                   "MovePos",
                   "ChangeAnimationState",
                   "FuncNotice",
                   "FuncNoticeChange",
                   "ClientAttributes"]
      'ParamterList': [["Dir","X","Z","ObjId"],
                       ["Dir","X","Z","ObjId"],
                       ["ObjId","Dir","X","Y"],
                       ["ReviveType"],
                       ["PosList","Dir","ObjId"],
                       ["AnimationState"],
                       [],
                       [],
                       ["ObjId","IsTouchJoyStick","IsHold"]]
      'AskList':[@Move,
                 @StopMove,
                 @MoveCheck,
                 @Respawn,
                 @MovePos,
                 @ChangeAnimationState,
                 @FuncNotice,
                 @FuncNoticeChange,
                 @ClientAttributes]
      'ParamterTypelist': [["float","float","float","int32"],
                       ["float","float","float","int32"],
                       ["int32","float","float","float"],
                       ["int32"],
                       ["Vector3","float","int32"],
                       ["bool"],
                       [],
                       [],
                       ["int32","bool","bool"]]


module.exports =(()->
  if not Human?
    Human = new HumanModel()
  Human)()



  

  

  


