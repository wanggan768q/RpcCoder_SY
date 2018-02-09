ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcSettlementNotifyCB = null


ModuleId = 6
RPC_CODE_CREATEDUNGEON_REQUEST = 651
RPC_CODE_EXITDUNGEON_REQUEST = 652
RPC_CODE_ENTERDUNGEON_REQUEST = 653
RPC_CODE_INFORMCREATEDUNGEON_REQUEST = 654
RPC_CODE_SETTLEMENT_NOTIFY = 655

CreateDungeonAskPB = null
CreateDungeonReplyPB = null
ExitDungeonAskPB = null
ExitDungeonReplyPB = null
EnterDungeonAskPB = null
EnterDungeonReplyPB = null
InformCreateDungeonAskPB = null
InformCreateDungeonReplyPB = null
SettlementNotifyPB = null

class DungeonModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcCreateDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 DungeonConfigId = 2[default=-1];
      }
      message  RpcCreateDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
        optional sint32 DungeonConfigId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
      }
      message  RpcExitDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
        optional sint32 SceneConfigId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
      }
      message  RpcEnterDungeonAsk
      {
        optional sint32 SceneId = 1[default=-1];
        optional sint32 DungeonConfigId = 2[default=-1];
      }
      message  RpcEnterDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcInformCreateDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 TargetSceneId = 2[default=-1];
        optional sint32 DungeonConfigId = 3[default=-1];
        optional sint32 CurSceneId = 4[default=-1];
        optional sint32 Result = 5[default=-9999];
        repeated uint64 RoleIds = 6;
      }
      message  RpcInformCreateDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcSettlementNotify
      {
        optional sint32 SettlementResult = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    CreateDungeonAskPB = Proto.build("RpcCreateDungeonAsk")
    CreateDungeonReplyPB = Proto.build("RpcCreateDungeonReply")
    ExitDungeonAskPB = Proto.build("RpcExitDungeonAsk")
    ExitDungeonReplyPB = Proto.build("RpcExitDungeonReply")
    EnterDungeonAskPB = Proto.build("RpcEnterDungeonAsk")
    EnterDungeonReplyPB = Proto.build("RpcEnterDungeonReply")
    InformCreateDungeonAskPB = Proto.build("RpcInformCreateDungeonAsk")
    InformCreateDungeonReplyPB = Proto.build("RpcInformCreateDungeonReply")
    SettlementNotifyPB = Proto.build("RpcSettlementNotify")
    mLayerMgr.registerNotify(RPC_CODE_SETTLEMENT_NOTIFY,@SettlementCB)






  CreateDungeon : (RoleId,DungeonConfigId,replyCB) ->
    CreateDungeonAsk = CreateDungeonAskPB.prototype
    CreateDungeonAsk.setRoleId RoleId
    CreateDungeonAsk.setDungeonConfigId DungeonConfigId
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEON_REQUEST,CreateDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ExitDungeon : (RoleId,SceneId,replyCB) ->
    ExitDungeonAsk = ExitDungeonAskPB.prototype
    ExitDungeonAsk.setRoleId RoleId
    ExitDungeonAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_EXITDUNGEON_REQUEST,ExitDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ExitDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EnterDungeon : (SceneId,DungeonConfigId,replyCB) ->
    EnterDungeonAsk = EnterDungeonAskPB.prototype
    EnterDungeonAsk.setSceneId SceneId
    EnterDungeonAsk.setDungeonConfigId DungeonConfigId
    mLayerMgr.sendAsk(RPC_CODE_ENTERDUNGEON_REQUEST,EnterDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformCreateDungeon : (RoleId,TargetSceneId,DungeonConfigId,CurSceneId,Result,RoleIds,replyCB) ->
    InformCreateDungeonAsk = InformCreateDungeonAskPB.prototype
    InformCreateDungeonAsk.setRoleId RoleId
    InformCreateDungeonAsk.setTargetSceneId TargetSceneId
    InformCreateDungeonAsk.setDungeonConfigId DungeonConfigId
    InformCreateDungeonAsk.setCurSceneId CurSceneId
    InformCreateDungeonAsk.setResult Result
    InformCreateDungeonAsk.setRoleIds RoleIds
    mLayerMgr.sendAsk(RPC_CODE_INFORMCREATEDUNGEON_REQUEST,InformCreateDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformCreateDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetSettlementNotifyCB : (cb) -> RpcSettlementNotifyCB = cb
  SettlementCB : (data)->
    RpcSettlementNotifyCB( SettlementNotifyPB.decode(data)) if typeof(RpcSettlementNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "DungeonModel",
      'AskName': ["CreateDungeon",
                   "ExitDungeon",
                   "EnterDungeon",
                   "InformCreateDungeon"]
      'ParamterList': [["RoleId","DungeonConfigId"],
                       ["RoleId","SceneId"],
                       ["SceneId","DungeonConfigId"],
                       ["RoleId","TargetSceneId","DungeonConfigId","CurSceneId","Result","RoleIds"]]
      'AskList':[@CreateDungeon,
                 @ExitDungeon,
                 @EnterDungeon,
                 @InformCreateDungeon]
      'ParamterTypelist': [["uint64","sint32"],
                       ["uint64","sint32"],
                       ["sint32","sint32"],
                       ["uint64","sint32","sint32","sint32","sint32","uint64"]]


module.exports =(()->
  if not Dungeon?
    Dungeon = new DungeonModel()
  Dungeon)()



  

  

  


