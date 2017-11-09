ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcMoveNotifyCB = null
RpcStopMoveNotifyCB = null
RpcBossDiedNotifyCB = null


ModuleId = 5
RPC_CODE_MOVE_NOTIFY = 551
RPC_CODE_STOPMOVE_NOTIFY = 552
RPC_CODE_BOSSDIED_NOTIFY = 553

MoveNotifyPB = null
StopMoveNotifyPB = null
BossDiedNotifyPB = null

class EventModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  V3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcMoveNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional V3 Pos = 2;
        optional float Dir = 3;
      }
      message  RpcStopMoveNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional V3 Pos = 2;
        optional float Dir = 3;
      }
      message  RpcBossDiedNotify
      {
        optional sint32 SceneId = 1[default=-1];
        optional sint32 ObjId = 2[default=-1];
        optional bool IsEndingBoss = 3;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MoveNotifyPB = Proto.build("RpcMoveNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVE_NOTIFY,@MoveCB)
    StopMoveNotifyPB = Proto.build("RpcStopMoveNotify")
    mLayerMgr.registerNotify(RPC_CODE_STOPMOVE_NOTIFY,@StopMoveCB)
    BossDiedNotifyPB = Proto.build("RpcBossDiedNotify")
    mLayerMgr.registerNotify(RPC_CODE_BOSSDIED_NOTIFY,@BossDiedCB)








  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetMoveNotifyCB : (cb) -> RpcMoveNotifyCB = cb
  MoveCB : (data)->
    RpcMoveNotifyCB( MoveNotifyPB.decode(data)) if typeof(RpcMoveNotifyCB) is "function"
  SetStopMoveNotifyCB : (cb) -> RpcStopMoveNotifyCB = cb
  StopMoveCB : (data)->
    RpcStopMoveNotifyCB( StopMoveNotifyPB.decode(data)) if typeof(RpcStopMoveNotifyCB) is "function"
  SetBossDiedNotifyCB : (cb) -> RpcBossDiedNotifyCB = cb
  BossDiedCB : (data)->
    RpcBossDiedNotifyCB( BossDiedNotifyPB.decode(data)) if typeof(RpcBossDiedNotifyCB) is "function"


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



  

  

  


