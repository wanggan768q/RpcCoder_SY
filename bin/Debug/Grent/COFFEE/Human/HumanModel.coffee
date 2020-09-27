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
RpcTimeCheckNotifyCB = null
RpcMotionFlagsNotifyCB = null
RpcChangePositionNotifyCB = null
RpcAttrChangeNotifyCB = null


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
RPC_CODE_TIMECHECK_NOTIFY = 462
RPC_CODE_MOTIONFLAGS_NOTIFY = 463
RPC_CODE_RUSH_REQUEST = 464
RPC_CODE_STARE_REQUEST = 465
RPC_CODE_CHANGEPOSITION_NOTIFY = 466
RPC_CODE_ATTRCHANGE_NOTIFY = 467
RPC_CODE_TRUSTEESHIP_REQUEST = 468

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
TimeCheckNotifyPB = null
MotionFlagsNotifyPB = null
RushAskPB = null
RushReplyPB = null
StareAskPB = null
StareReplyPB = null
ChangePositionNotifyPB = null
AttrChangeNotifyPB = null
TrusteeshipAskPB = null
TrusteeshipReplyPB = null

class HumanModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcMoveAsk
      {
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
        optional uint64 ObjId = 5[default=0];
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
        optional uint64 ObjId = 4[default=0];
      }
      message  RpcStopMoveAsk
      {
        optional float Dir = 2;
        optional int32 X = 3[default=-1];
        optional int32 Z = 4[default=-1];
        optional uint64 ObjId = 5[default=0];
        optional bool BrakeRush = 6;
      }
      message  Vector3Int
      {
        optional int32 X = 1[default=-1];
        optional int32 Z = 2[default=-1];
      }
      message  RpcStopMoveReply
      {
        optional int32 Result = 1[default=-9999];
        optional Vector3Int Pos = 2;
        optional float Dir = 3;
        optional uint64 ObjId = 4[default=0];
      }
      message  RpcMoveCheckNotify
      {
        optional uint64 ObjId = 1[default=0];
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
        optional uint64 ObjId = 1[default=0];
      }
      message  RpcMovePosAsk
      {
        repeated Vector3Int PosList = 1;
        optional float Dir = 2;
        optional uint64 ObjId = 3[default=0];
        optional bool IsAllowChangeRunAnimation = 4;
        optional bool IsLookAtMoving = 5;
        optional int32 FromX = 6[default=-1];
        optional int32 FromZ = 7[default=-1];
      }
      message  RpcMovePosReply
      {
        optional int32 Result = 1[default=-1];
        optional Vector3Int Pos = 2;
        optional float Dir = 3;
        optional uint64 ObjId = 4[default=0];
      }
      message  RpcRoleDieNotify
      {
        optional int64 KillerGuid = 1[default=-1];
        optional string KillerName = 2;
        optional int32 KillerType = 3[default=-1];
        optional int32 RevieCDTime = 4[default=-1];
        optional int32 DungeonReviveCounts = 5[default=-1];
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
        optional uint64 ObjId = 2[default=0];
        optional bool IsTouchJoyStick = 6;
        optional bool IsHold = 7;
      }
      message  RpcTimeCheckNotify
      {
        optional int64 Data = 1[default=-1];
      }
      message  RpcMotionFlagsNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 MotionFlags = 2[default=-1];
      }
      message  RpcRushAsk
      {
        optional bool Apply = 1;
      }
      message  RpcRushReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcStareAsk
      {
        optional bool Apply = 1;
        optional uint64 TargetID = 2[default=0];
        optional float Dir = 3;
      }
      message  RpcStareReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 TargetID = 2[default=0];
      }
      message  RpcChangePositionNotify
      {
        optional uint64 ObjID = 1[default=0];
        optional Vector3Int Pos = 2;
        optional float Dir = 4;
      }
      message  RpcAttrChangeNotify
      {
        optional int32 AttrType = 1[default=-1];
        optional int32 Value = 2[default=-1];
        optional uint64 Playerguid = 3[default=0];
      }
      message  RpcTrusteeshipAsk
      {
        optional bool Open = 1;
      }
      message  RpcTrusteeshipReply
      {
        optional int32 Result = 1[default=-1];
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
    TimeCheckNotifyPB = Proto.build("RpcTimeCheckNotify")
    MotionFlagsNotifyPB = Proto.build("RpcMotionFlagsNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOTIONFLAGS_NOTIFY,@MotionFlagsCB)
    RushAskPB = Proto.build("RpcRushAsk")
    RushReplyPB = Proto.build("RpcRushReply")
    StareAskPB = Proto.build("RpcStareAsk")
    StareReplyPB = Proto.build("RpcStareReply")
    ChangePositionNotifyPB = Proto.build("RpcChangePositionNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGEPOSITION_NOTIFY,@ChangePositionCB)
    AttrChangeNotifyPB = Proto.build("RpcAttrChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_ATTRCHANGE_NOTIFY,@AttrChangeCB)
    TrusteeshipAskPB = Proto.build("RpcTrusteeshipAsk")
    TrusteeshipReplyPB = Proto.build("RpcTrusteeshipReply")






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
  StopMove : (Dir,X,Z,ObjId,BrakeRush,replyCB) ->
    StopMoveAsk = StopMoveAskPB.prototype
    StopMoveAsk.setDir Dir
    StopMoveAsk.setX X
    StopMoveAsk.setZ Z
    StopMoveAsk.setObjId ObjId
    StopMoveAsk.setBrakeRush BrakeRush
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
  MovePos : (PosList,Dir,ObjId,IsAllowChangeRunAnimation,IsLookAtMoving,FromX,FromZ,replyCB) ->
    MovePosAsk = MovePosAskPB.prototype
    MovePosAsk.setPosList PosList
    MovePosAsk.setDir Dir
    MovePosAsk.setObjId ObjId
    MovePosAsk.setIsAllowChangeRunAnimation IsAllowChangeRunAnimation
    MovePosAsk.setIsLookAtMoving IsLookAtMoving
    MovePosAsk.setFromX FromX
    MovePosAsk.setFromZ FromZ
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
  TimeCheck : (Data) ->
    TimeCheckNotify = TimeCheckNotifyPB.prototype
    TimeCheckNotify.setData Data
    mLayerMgr.sendNotify(RPC_CODE_TIMECHECK_NOTIFY,TimeCheckNotify)
  Rush : (Apply,replyCB) ->
    RushAsk = RushAskPB.prototype
    RushAsk.setApply Apply
    mLayerMgr.sendAsk(RPC_CODE_RUSH_REQUEST,RushAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RushReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Stare : (Apply,TargetID,Dir,replyCB) ->
    StareAsk = StareAskPB.prototype
    StareAsk.setApply Apply
    StareAsk.setTargetID TargetID
    StareAsk.setDir Dir
    mLayerMgr.sendAsk(RPC_CODE_STARE_REQUEST,StareAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( StareReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Trusteeship : (Open,replyCB) ->
    TrusteeshipAsk = TrusteeshipAskPB.prototype
    TrusteeshipAsk.setOpen Open
    mLayerMgr.sendAsk(RPC_CODE_TRUSTEESHIP_REQUEST,TrusteeshipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( TrusteeshipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


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
  SetMotionFlagsNotifyCB : (cb) -> RpcMotionFlagsNotifyCB = cb
  MotionFlagsCB : (data)->
    RpcMotionFlagsNotifyCB( MotionFlagsNotifyPB.decode(data)) if typeof(RpcMotionFlagsNotifyCB) is "function"
  SetChangePositionNotifyCB : (cb) -> RpcChangePositionNotifyCB = cb
  ChangePositionCB : (data)->
    RpcChangePositionNotifyCB( ChangePositionNotifyPB.decode(data)) if typeof(RpcChangePositionNotifyCB) is "function"
  SetAttrChangeNotifyCB : (cb) -> RpcAttrChangeNotifyCB = cb
  AttrChangeCB : (data)->
    RpcAttrChangeNotifyCB( AttrChangeNotifyPB.decode(data)) if typeof(RpcAttrChangeNotifyCB) is "function"


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
                   "ClientAttributes",
                   "TimeCheck",
                   "Rush",
                   "Stare",
                   "Trusteeship"]
      'ParamterList': [["Dir","X","Z","ObjId"],
                       ["Dir","X","Z","ObjId","BrakeRush"],
                       ["ObjId","Dir","X","Y"],
                       ["ReviveType"],
                       ["PosList","Dir","ObjId","IsAllowChangeRunAnimation","IsLookAtMoving","FromX","FromZ"],
                       ["AnimationState"],
                       [],
                       [],
                       ["ObjId","IsTouchJoyStick","IsHold"],
                       ["Data"],
                       ["Apply"],
                       ["Apply","TargetID","Dir"],
                       ["Open"]]
      'AskList':[@Move,
                 @StopMove,
                 @MoveCheck,
                 @Respawn,
                 @MovePos,
                 @ChangeAnimationState,
                 @FuncNotice,
                 @FuncNoticeChange,
                 @ClientAttributes,
                 @TimeCheck,
                 @Rush,
                 @Stare,
                 @Trusteeship]
      'ParamterTypelist': [["float","float","float","uint64"],
                       ["float","int32","int32","uint64","bool"],
                       ["uint64","float","float","float"],
                       ["int32"],
                       ["Vector3Int","float","uint64","bool","bool","int32","int32"],
                       ["bool"],
                       [],
                       [],
                       ["uint64","bool","bool"],
                       ["int64"],
                       ["bool"],
                       ["bool","uint64","float"],
                       ["bool"]]


module.exports =(()->
  if not Human?
    Human = new HumanModel()
  Human)()



  

  

  


