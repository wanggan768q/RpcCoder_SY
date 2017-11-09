ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 6
RPC_CODE_CREATEDUNGEON_REQUEST = 651
RPC_CODE_EXITDUNGEON_REQUEST = 652

CreateDungeonAskPB = null
CreateDungeonReplyPB = null
ExitDungeonAskPB = null
ExitDungeonReplyPB = null

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
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
      }
      message  RpcExitDungeonReply
      {
        optional sint32 Result = 1[default=-9999];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    CreateDungeonAskPB = Proto.build("RpcCreateDungeonAsk")
    CreateDungeonReplyPB = Proto.build("RpcCreateDungeonReply")
    ExitDungeonAskPB = Proto.build("RpcExitDungeonAsk")
    ExitDungeonReplyPB = Proto.build("RpcExitDungeonReply")






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


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "DungeonModel",
      'AskName': ["CreateDungeon",
                   "ExitDungeon"]
      'ParamterList': [["RoleId","DungeonConfigId"],
                       ["RoleId","SceneId"]]
      'AskList':[@CreateDungeon,
                 @ExitDungeon]
      'ParamterTypelist': [["uint64","sint32"],
                       ["uint64","sint32"]]


module.exports =(()->
  if not Dungeon?
    Dungeon = new DungeonModel()
  Dungeon)()



  

  

  


