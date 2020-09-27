ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcMoveNotifyCB = null
RpcStopMoveNotifyCB = null
RpcObjAttrChangeNotifyCB = null
RpcCoinChangeNotifyCB = null
RpcMovePosNotifyCB = null
RpcDirNotifyCB = null
RpcStartFadeoutNotifyCB = null
RpcCinematicStartNotifyCB = null
RpcCinematicEndNotifyCB = null


ModuleId = 5
RPC_CODE_MOVE_NOTIFY = 551
RPC_CODE_STOPMOVE_NOTIFY = 552
RPC_CODE_OBJATTRCHANGE_NOTIFY = 553
RPC_CODE_COINCHANGE_NOTIFY = 554
RPC_CODE_MOVEPOS_NOTIFY = 555
RPC_CODE_DIR_NOTIFY = 556
RPC_CODE_STARTFADEOUT_NOTIFY = 557
RPC_CODE_CINEMATICSTART_NOTIFY = 558
RPC_CODE_CINEMATICEND_NOTIFY = 559

MoveNotifyPB = null
StopMoveNotifyPB = null
ObjAttrChangeNotifyPB = null
CoinChangeNotifyPB = null
MovePosNotifyPB = null
DirNotifyPB = null
StartFadeoutNotifyPB = null
CinematicStartNotifyPB = null
CinematicEndNotifyPB = null

class EventModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcMoveNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
      }
      message  Vector3Int
      {
        optional int32 X = 1[default=-1];
        optional int32 Z = 2[default=-1];
      }
      message  RpcStopMoveNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional Vector3Int Pos = 2;
        optional float Dir = 3;
        optional int32 Type = 5[default=-1];
        optional bool BrakeRush = 6;
      }
      message  RpcObjAttrChangeNotify
      {
        optional float Speed = 1;
        optional int64 Hp = 2[default=-1];
        optional int32 Status = 3[default=-1];
        optional int32 ConfigId = 4[default=-1];
        optional uint64 ObjId = 5[default=0];
      }
      message  RpcCoinChangeNotify
      {
        optional int32 Type = 1[default=-1];
        optional int32 Value = 2[default=-1];
      }
      message  RpcMovePosNotify
      {
        optional uint64 ObjId = 1[default=0];
        repeated Vector3Int PosList = 3;
        optional float Dir = 4;
        optional bool IsAllowChangeRunAnimation = 5;
        optional int32 Follow = 6[default=-1];
        optional bool IsLookAtMoving = 7;
        optional int32 FromX = 8[default=-1];
        optional int32 FromZ = 9[default=-1];
      }
      message  RpcDirNotify
      {
        optional uint64 ObjId = 3[default=0];
        optional float Dir = 4;
      }
      message  RpcStartFadeoutNotify
      {
        optional uint64 ObjId = 1[default=0];
      }
      message  RpcCinematicStartNotify
      {
        optional int32 Text = 1[default=-1];
      }
      message  RpcCinematicEndNotify
      {
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MoveNotifyPB = Proto.build("RpcMoveNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVE_NOTIFY,@MoveCB)
    StopMoveNotifyPB = Proto.build("RpcStopMoveNotify")
    mLayerMgr.registerNotify(RPC_CODE_STOPMOVE_NOTIFY,@StopMoveCB)
    ObjAttrChangeNotifyPB = Proto.build("RpcObjAttrChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_OBJATTRCHANGE_NOTIFY,@ObjAttrChangeCB)
    CoinChangeNotifyPB = Proto.build("RpcCoinChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_COINCHANGE_NOTIFY,@CoinChangeCB)
    MovePosNotifyPB = Proto.build("RpcMovePosNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVEPOS_NOTIFY,@MovePosCB)
    DirNotifyPB = Proto.build("RpcDirNotify")
    mLayerMgr.registerNotify(RPC_CODE_DIR_NOTIFY,@DirCB)
    StartFadeoutNotifyPB = Proto.build("RpcStartFadeoutNotify")
    mLayerMgr.registerNotify(RPC_CODE_STARTFADEOUT_NOTIFY,@StartFadeoutCB)
    CinematicStartNotifyPB = Proto.build("RpcCinematicStartNotify")
    mLayerMgr.registerNotify(RPC_CODE_CINEMATICSTART_NOTIFY,@CinematicStartCB)
    CinematicEndNotifyPB = Proto.build("RpcCinematicEndNotify")
    mLayerMgr.registerNotify(RPC_CODE_CINEMATICEND_NOTIFY,@CinematicEndCB)








  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetMoveNotifyCB : (cb) -> RpcMoveNotifyCB = cb
  MoveCB : (data)->
    RpcMoveNotifyCB( MoveNotifyPB.decode(data)) if typeof(RpcMoveNotifyCB) is "function"
  SetStopMoveNotifyCB : (cb) -> RpcStopMoveNotifyCB = cb
  StopMoveCB : (data)->
    RpcStopMoveNotifyCB( StopMoveNotifyPB.decode(data)) if typeof(RpcStopMoveNotifyCB) is "function"
  SetObjAttrChangeNotifyCB : (cb) -> RpcObjAttrChangeNotifyCB = cb
  ObjAttrChangeCB : (data)->
    RpcObjAttrChangeNotifyCB( ObjAttrChangeNotifyPB.decode(data)) if typeof(RpcObjAttrChangeNotifyCB) is "function"
  SetCoinChangeNotifyCB : (cb) -> RpcCoinChangeNotifyCB = cb
  CoinChangeCB : (data)->
    RpcCoinChangeNotifyCB( CoinChangeNotifyPB.decode(data)) if typeof(RpcCoinChangeNotifyCB) is "function"
  SetMovePosNotifyCB : (cb) -> RpcMovePosNotifyCB = cb
  MovePosCB : (data)->
    RpcMovePosNotifyCB( MovePosNotifyPB.decode(data)) if typeof(RpcMovePosNotifyCB) is "function"
  SetDirNotifyCB : (cb) -> RpcDirNotifyCB = cb
  DirCB : (data)->
    RpcDirNotifyCB( DirNotifyPB.decode(data)) if typeof(RpcDirNotifyCB) is "function"
  SetStartFadeoutNotifyCB : (cb) -> RpcStartFadeoutNotifyCB = cb
  StartFadeoutCB : (data)->
    RpcStartFadeoutNotifyCB( StartFadeoutNotifyPB.decode(data)) if typeof(RpcStartFadeoutNotifyCB) is "function"
  SetCinematicStartNotifyCB : (cb) -> RpcCinematicStartNotifyCB = cb
  CinematicStartCB : (data)->
    RpcCinematicStartNotifyCB( CinematicStartNotifyPB.decode(data)) if typeof(RpcCinematicStartNotifyCB) is "function"
  SetCinematicEndNotifyCB : (cb) -> RpcCinematicEndNotifyCB = cb
  CinematicEndCB : (data)->
    RpcCinematicEndNotifyCB( CinematicEndNotifyPB.decode(data)) if typeof(RpcCinematicEndNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "EventModel",
      'AskName': []
      'ParamterList': []
      'AskList':[]
      'ParamterTypelist': []


module.exports =(()->
  if not Event?
    Event = new EventModel()
  Event)()



  

  

  


