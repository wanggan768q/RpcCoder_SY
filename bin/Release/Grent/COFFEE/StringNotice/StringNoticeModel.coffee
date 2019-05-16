ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcNoticeNotifyCB = null


ModuleId = 55
RPC_CODE_NOTICE_NOTIFY = 5551

NoticeNotifyPB = null

class StringNoticeModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcNoticeNotify
      {
        optional int32 ConfigId = 1[default=-1];
        optional string Param = 2;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    NoticeNotifyPB = Proto.build("RpcNoticeNotify")
    mLayerMgr.registerNotify(RPC_CODE_NOTICE_NOTIFY,@NoticeCB)








  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetNoticeNotifyCB : (cb) -> RpcNoticeNotifyCB = cb
  NoticeCB : (data)->
    RpcNoticeNotifyCB( NoticeNotifyPB.decode(data)) if typeof(RpcNoticeNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "StringNoticeModel",
      'AskName': []
      'ParamterList': []
      'AskList':[]
      'ParamterTypelist': []


module.exports =(()->
  if not StringNotice?
    StringNotice = new StringNoticeModel()
  StringNotice)()



  

  

  


