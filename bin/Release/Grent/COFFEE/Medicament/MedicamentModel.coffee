ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcServerRefreshMedicamentNotifyCB = null
RpcMedicamentCDNotifyNotifyCB = null


ModuleId = 28
RPC_CODE_FILLHP_REQUEST = 2851
RPC_CODE_ONESTEPFILLHP_REQUEST = 2852
RPC_CODE_CLIENTREFRESHMEDICAMENT_REQUEST = 2853
RPC_CODE_SERVERREFRESHMEDICAMENT_NOTIFY = 2854
RPC_CODE_SYNCMEDICAMENTDATA_REQUEST = 2855
RPC_CODE_MEDICAMENTCD_REQUEST = 2856
RPC_CODE_MEDICAMENTCDNOTIFY_NOTIFY = 2857

FillHpAskPB = null
FillHpReplyPB = null
OneStepFillHpAskPB = null
OneStepFillHpReplyPB = null
ClientRefreshMedicamentAskPB = null
ClientRefreshMedicamentReplyPB = null
ServerRefreshMedicamentNotifyPB = null
SyncMedicamentDataAskPB = null
SyncMedicamentDataReplyPB = null
MedicamentCDAskPB = null
MedicamentCDReplyPB = null
MedicamentCDNotifyNotifyPB = null

class MedicamentModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  ItemSimpleData
      {
        optional int32 ConfID = 1[default=-1];
        optional int32 Count = 2[default=-1];
      }
      message  RpcFillHpAsk
      {
        optional ItemSimpleData ItemData = 1;
      }
      message  RpcFillHpReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcOneStepFillHpAsk
      {
        repeated ItemSimpleData ItemData = 3;
      }
      message  RpcOneStepFillHpReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RecoverMedicament
      {
        repeated int32 HpMedicamentList = 1;
        optional int32 AutoHpMedicament = 2[default=-1];
        optional int32 HpPercentage = 3[default=-1];
      }
      message  RpcClientRefreshMedicamentAsk
      {
        optional RecoverMedicament Medicament = 1;
      }
      message  RpcClientRefreshMedicamentReply
      {
        optional int32 Result = 1[default=-1];
        optional RecoverMedicament Medicament = 2;
      }
      message  RpcServerRefreshMedicamentNotify
      {
        optional RecoverMedicament Medicament = 1;
      }
      message  RpcSyncMedicamentDataAsk
      {
      }
      message  RpcSyncMedicamentDataReply
      {
        optional int32 Result = 1[default=-1];
        optional RecoverMedicament Medicament = 2;
      }
      message  RpcMedicamentCDAsk
      {
      }
      message  RpcMedicamentCDReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 LeftTime = 2[default=0];
      }
      message  RpcMedicamentCDNotifyNotify
      {
        optional uint64 LeftTime = 1[default=0];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    FillHpAskPB = Proto.build("RpcFillHpAsk")
    FillHpReplyPB = Proto.build("RpcFillHpReply")
    OneStepFillHpAskPB = Proto.build("RpcOneStepFillHpAsk")
    OneStepFillHpReplyPB = Proto.build("RpcOneStepFillHpReply")
    ClientRefreshMedicamentAskPB = Proto.build("RpcClientRefreshMedicamentAsk")
    ClientRefreshMedicamentReplyPB = Proto.build("RpcClientRefreshMedicamentReply")
    ServerRefreshMedicamentNotifyPB = Proto.build("RpcServerRefreshMedicamentNotify")
    mLayerMgr.registerNotify(RPC_CODE_SERVERREFRESHMEDICAMENT_NOTIFY,@ServerRefreshMedicamentCB)
    SyncMedicamentDataAskPB = Proto.build("RpcSyncMedicamentDataAsk")
    SyncMedicamentDataReplyPB = Proto.build("RpcSyncMedicamentDataReply")
    MedicamentCDAskPB = Proto.build("RpcMedicamentCDAsk")
    MedicamentCDReplyPB = Proto.build("RpcMedicamentCDReply")
    MedicamentCDNotifyNotifyPB = Proto.build("RpcMedicamentCDNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_MEDICAMENTCDNOTIFY_NOTIFY,@MedicamentCDNotifyCB)






  FillHp : (ItemData,replyCB) ->
    FillHpAsk = FillHpAskPB.prototype
    FillHpAsk.setItemData ItemData
    mLayerMgr.sendAsk(RPC_CODE_FILLHP_REQUEST,FillHpAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( FillHpReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  OneStepFillHp : (ItemData,replyCB) ->
    OneStepFillHpAsk = OneStepFillHpAskPB.prototype
    OneStepFillHpAsk.setItemData ItemData
    mLayerMgr.sendAsk(RPC_CODE_ONESTEPFILLHP_REQUEST,OneStepFillHpAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( OneStepFillHpReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ClientRefreshMedicament : (Medicament,replyCB) ->
    ClientRefreshMedicamentAsk = ClientRefreshMedicamentAskPB.prototype
    ClientRefreshMedicamentAsk.setMedicament Medicament
    mLayerMgr.sendAsk(RPC_CODE_CLIENTREFRESHMEDICAMENT_REQUEST,ClientRefreshMedicamentAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ClientRefreshMedicamentReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncMedicamentData : (replyCB) ->
    SyncMedicamentDataAsk = SyncMedicamentDataAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCMEDICAMENTDATA_REQUEST,SyncMedicamentDataAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncMedicamentDataReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MedicamentCD : (replyCB) ->
    MedicamentCDAsk = MedicamentCDAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_MEDICAMENTCD_REQUEST,MedicamentCDAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MedicamentCDReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetServerRefreshMedicamentNotifyCB : (cb) -> RpcServerRefreshMedicamentNotifyCB = cb
  ServerRefreshMedicamentCB : (data)->
    RpcServerRefreshMedicamentNotifyCB( ServerRefreshMedicamentNotifyPB.decode(data)) if typeof(RpcServerRefreshMedicamentNotifyCB) is "function"
  SetMedicamentCDNotifyNotifyCB : (cb) -> RpcMedicamentCDNotifyNotifyCB = cb
  MedicamentCDNotifyCB : (data)->
    RpcMedicamentCDNotifyNotifyCB( MedicamentCDNotifyNotifyPB.decode(data)) if typeof(RpcMedicamentCDNotifyNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "MedicamentModel",
      'AskName': ["FillHp",
                   "OneStepFillHp",
                   "ClientRefreshMedicament",
                   "SyncMedicamentData",
                   "MedicamentCD"]
      'ParamterList': [["ItemData"],
                       ["ItemData"],
                       ["Medicament"],
                       [],
                       []]
      'AskList':[@FillHp,
                 @OneStepFillHp,
                 @ClientRefreshMedicament,
                 @SyncMedicamentData,
                 @MedicamentCD]
      'ParamterTypelist': [["ItemSimpleData"],
                       ["ItemSimpleData"],
                       ["RecoverMedicament"],
                       [],
                       []]


module.exports =(()->
  if not Medicament?
    Medicament = new MedicamentModel()
  Medicament)()



  

  

  


