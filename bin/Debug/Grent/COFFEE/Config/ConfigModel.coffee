ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 1


class ConfigModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)








  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "ConfigModel",
      'AskName': []
      'ParamterList': []
      'AskList':[]
      'ParamterTypelist': []


module.exports =(()->
  if not Config?
    Config = new ConfigModel()
  Config)()



  

  

  


