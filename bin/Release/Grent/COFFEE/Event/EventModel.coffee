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


ModuleId = 5
RPC_CODE_MOVE_NOTIFY = 551
RPC_CODE_STOPMOVE_NOTIFY = 552
RPC_CODE_OBJATTRCHANGE_NOTIFY = 553
RPC_CODE_COINCHANGE_NOTIFY = 554
RPC_CODE_MOVEPOS_NOTIFY = 555

MoveNotifyPB = null
StopMoveNotifyPB = null
ObjAttrChangeNotifyPB = null
CoinChangeNotifyPB = null
MovePosNotifyPB = null

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
        optional int32 ObjId = 1[default=-1];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
      }
      message  RpcStopMoveNotify
      {
        optional int32 ObjId = 1[default=-1];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
        optional int32 Type = 5[default=-1];
      }
      message  RpcObjAttrChangeNotify
      {
        optional float Speed = 1;
        optional int64 Hp = 2[default=-1];
        optional int32 Status = 3[default=-1];
        optional int32 ConfigId = 4[default=-1];
        optional int32 ObjId = 5[default=-1];
      }
      message  RpcCoinChangeNotify
      {
        optional int32 Type = 1[default=-1];
        optional int32 Value = 2[default=-1];
      }
      message  RpcMovePosNotify
      {
        optional int32 ObjId = 1[default=-1];
        repeated Vector3 PosList = 3;
        optional float Dir = 4;
        optional bool IsAllowChangeRunAnimation = 5;
        optional int32 Follow = 6[default=-1];
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



  

  

  


