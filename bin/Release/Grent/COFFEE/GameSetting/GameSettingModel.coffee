ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 53
RPC_CODE_SYNCGAMESETTING_REQUEST = 5351
RPC_CODE_SETTING_REQUEST = 5352

SyncGameSettingAskPB = null
SyncGameSettingReplyPB = null
SettingAskPB = null
SettingReplyPB = null

class GameSettingModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcSyncGameSettingAsk
      {
      }
      message  RpcSyncGameSettingReply
      {
        optional int32 Result = 1[default=-1];
        optional string GameSetting = 2;
      }
      message  RpcSettingAsk
      {
        optional string GameSetting = 1;
      }
      message  RpcSettingReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    SyncGameSettingAskPB = Proto.build("RpcSyncGameSettingAsk")
    SyncGameSettingReplyPB = Proto.build("RpcSyncGameSettingReply")
    SettingAskPB = Proto.build("RpcSettingAsk")
    SettingReplyPB = Proto.build("RpcSettingReply")






  SyncGameSetting : (replyCB) ->
    SyncGameSettingAsk = SyncGameSettingAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCGAMESETTING_REQUEST,SyncGameSettingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncGameSettingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Setting : (GameSetting,replyCB) ->
    SettingAsk = SettingAskPB.prototype
    SettingAsk.setGameSetting GameSetting
    mLayerMgr.sendAsk(RPC_CODE_SETTING_REQUEST,SettingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SettingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "GameSettingModel",
      'AskName': ["SyncGameSetting",
                   "Setting"]
      'ParamterList': [[],
                       ["GameSetting"]]
      'AskList':[@SyncGameSetting,
                 @Setting]
      'ParamterTypelist': [[],
                       ["string"]]


module.exports =(()->
  if not GameSetting?
    GameSetting = new GameSettingModel()
  GameSetting)()



  

  

  


