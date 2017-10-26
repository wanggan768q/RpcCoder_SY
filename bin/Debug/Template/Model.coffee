ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
$TempVar$
$TempVar2$
$MoudleVar$
$PBVar$
class $TEMPLATE$Model
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
$PBArgs$    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
$PBConfig$ 

$PBVarInit$

$DBCacheField$

$PBFun$

  updateDataField : (SyncId,Index,Data,dataLen)->
$updateWhen$
    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
$SDNotifyF$

  GetCoffeeInfo: ->
      'CoffeeName': "$TEMPLATE$Model",
$TEST$

module.exports =(()->
  if not $TEMPLATE$?
    $TEMPLATE$ = new $TEMPLATE$Model()
  $TEMPLATE$)()



  

  

  


