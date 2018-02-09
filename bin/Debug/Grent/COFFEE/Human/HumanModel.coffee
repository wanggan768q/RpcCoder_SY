ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcMoveCheckNotifyCB = null
RpcMoveByPosNotifyCB = null


ModuleId = 4
RPC_CODE_MOVE_REQUEST = 451
RPC_CODE_STOPMOVE_REQUEST = 452
RPC_CODE_MOVECHECK_NOTIFY = 453
RPC_CODE_MOVEBYPOS_NOTIFY = 454
RPC_CODE_RESPAWN_REQUEST = 455

MoveAskPB = null
MoveReplyPB = null
StopMoveAskPB = null
StopMoveReplyPB = null
MoveCheckNotifyPB = null
MoveByPosNotifyPB = null
RespawnAskPB = null
RespawnReplyPB = null

class HumanModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcMoveAsk
      {
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
      }
      message  V3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcMoveReply
      {
        optional sint32 Result = 1[default=-9999];
        optional V3 Pos = 2;
        optional float Dir = 3;
      }
      message  RpcStopMoveAsk
      {
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
      }
      message  RpcStopMoveReply
      {
        optional sint32 Result = 1[default=-9999];
        optional V3 Pos = 2;
        optional float Dir = 3;
      }
      message  RpcMoveCheckNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional float Dir = 3;
        optional float X = 4;
        optional float Y = 5;
      }
      message  RpcMoveByPosNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional float TargetX = 2;
        optional float TargetY = 3;
      }
      message  RpcRespawnAsk
      {
      }
      message  RpcRespawnReply
      {
        optional sint32 Result = 1[default=-9999];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MoveAskPB = Proto.build("RpcMoveAsk")
    MoveReplyPB = Proto.build("RpcMoveReply")
    StopMoveAskPB = Proto.build("RpcStopMoveAsk")
    StopMoveReplyPB = Proto.build("RpcStopMoveReply")
    MoveCheckNotifyPB = Proto.build("RpcMoveCheckNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVECHECK_NOTIFY,@MoveCheckCB)
    MoveByPosNotifyPB = Proto.build("RpcMoveByPosNotify")
    mLayerMgr.registerNotify(RPC_CODE_MOVEBYPOS_NOTIFY,@MoveByPosCB)
    RespawnAskPB = Proto.build("RpcRespawnAsk")
    RespawnReplyPB = Proto.build("RpcRespawnReply")






  Move : (Dir,X,Z,replyCB) ->
    MoveAsk = MoveAskPB.prototype
    MoveAsk.setDir Dir
    MoveAsk.setX X
    MoveAsk.setZ Z
    mLayerMgr.sendAsk(RPC_CODE_MOVE_REQUEST,MoveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MoveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  StopMove : (Dir,X,Z,replyCB) ->
    StopMoveAsk = StopMoveAskPB.prototype
    StopMoveAsk.setDir Dir
    StopMoveAsk.setX X
    StopMoveAsk.setZ Z
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
  Respawn : (replyCB) ->
    RespawnAsk = RespawnAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_RESPAWN_REQUEST,RespawnAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RespawnReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetMoveCheckNotifyCB : (cb) -> RpcMoveCheckNotifyCB = cb
  MoveCheckCB : (data)->
    RpcMoveCheckNotifyCB( MoveCheckNotifyPB.decode(data)) if typeof(RpcMoveCheckNotifyCB) is "function"
  SetMoveByPosNotifyCB : (cb) -> RpcMoveByPosNotifyCB = cb
  MoveByPosCB : (data)->
    RpcMoveByPosNotifyCB( MoveByPosNotifyPB.decode(data)) if typeof(RpcMoveByPosNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "HumanModel",
      'AskName': ["Move",
                   "StopMove",
                   "MoveCheck",
                   "Respawn"]
      'ParamterList': [["Dir","X","Z"],
                       ["Dir","X","Z"],
                       ["ObjId","Dir","X","Y"],
                       []]
      'AskList':[@Move,
                 @StopMove,
                 @MoveCheck,
                 @Respawn]
      'ParamterTypelist': [["float","float","float"],
                       ["float","float","float"],
                       ["sint32","float","float","float"],
                       []]


module.exports =(()->
  if not Human?
    Human = new HumanModel()
  Human)()



  

  

  


