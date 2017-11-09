ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 4
RPC_CODE_MOVE_REQUEST = 451
RPC_CODE_STOPMOVE_REQUEST = 452
RPC_CODE_MOVEMENTVERIFICATION_REQUEST = 453

MoveAskPB = null
MoveReplyPB = null
StopMoveAskPB = null
StopMoveReplyPB = null
MovementVerificationAskPB = null
MovementVerificationReplyPB = null

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
      message  RpcMovementVerificationAsk
      {
        optional float Dir = 1;
        optional float X = 2;
        optional float Z = 3;
      }
      message  RpcMovementVerificationReply
      {
        optional sint32 Result = 1[default=-9999];
        optional float Dir = 2;
        optional float X = 3;
        optional float Z = 4;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MoveAskPB = Proto.build("RpcMoveAsk")
    MoveReplyPB = Proto.build("RpcMoveReply")
    StopMoveAskPB = Proto.build("RpcStopMoveAsk")
    StopMoveReplyPB = Proto.build("RpcStopMoveReply")
    MovementVerificationAskPB = Proto.build("RpcMovementVerificationAsk")
    MovementVerificationReplyPB = Proto.build("RpcMovementVerificationReply")






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
  MovementVerification : (Dir,X,Z,replyCB) ->
    MovementVerificationAsk = MovementVerificationAskPB.prototype
    MovementVerificationAsk.setDir Dir
    MovementVerificationAsk.setX X
    MovementVerificationAsk.setZ Z
    mLayerMgr.sendAsk(RPC_CODE_MOVEMENTVERIFICATION_REQUEST,MovementVerificationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MovementVerificationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "HumanModel",
      'AskName': ["Move",
                   "StopMove",
                   "MovementVerification"]
      'ParamterList': [["Dir","X","Z"],
                       ["Dir","X","Z"],
                       ["Dir","X","Z"]]
      'AskList':[@Move,
                 @StopMove,
                 @MovementVerification]
      'ParamterTypelist': [["float","float","float"],
                       ["float","float","float"],
                       ["float","float","float"]]


module.exports =(()->
  if not Human?
    Human = new HumanModel()
  Human)()



  

  

  


