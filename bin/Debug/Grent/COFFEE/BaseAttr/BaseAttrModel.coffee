ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null

SYNCID_EXP = 701  #经验
SYNCID_LEVEL = 703  #玩家等级
SYNCID_SERVERTIME = 704  #服务器时间
SYNCID_ROLEID = 705  #人物唯一ID
m_Exp = 0
m_Level = 0
m_ServerTime = 0
m_RoleId = 0
UserDataV1PB = null

ModuleId = 7
RPC_CODE_SYNCDATA_REQUEST = 751

SyncDataAskPB = null
SyncDataReplyPB = null
UserDataV1PB = null

class BaseAttrModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcSyncDataAsk
      {
      }
      message  RpcSyncDataReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  UserDataV1
      {
        optional sint32 Exp = 1[default=-1];
        optional sint32 Level = 3[default=-1];
        optional sint32 ServerTime = 4[default=-1];
        optional sint32 RoleId = 5[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    SyncDataAskPB = Proto.build("RpcSyncDataAsk")
    SyncDataReplyPB = Proto.build("RpcSyncDataReply")
    UserDataV1PB = Proto.build("RpcUserDataV1")




  SyncID_Exp : () -> return SYNCID_EXP
  SyncID_Level : () -> return SYNCID_LEVEL
  SyncID_ServerTime : () -> return SYNCID_SERVERTIME
  SyncID_RoleId : () -> return SYNCID_ROLEID
  Exp : () -> return m_Exp
  Level : () -> return m_Level
  ServerTime : () -> return m_ServerTime
  RoleId : () -> return m_RoleId


  SyncData : (replyCB) ->
    SyncDataAsk = SyncDataAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCDATA_REQUEST,SyncDataAsk, (data)->
      replyCB( SyncDataReplyPB.decode(data)) if typeof(replyCB) is "function"
    )


  updateDataField : (SyncId,Index,Data,dataLen)->
    switch SyncId
      when SYNCID_EXP
        m_Exp = Data.readVarint32ZigZag()
      when SYNCID_LEVEL
        m_Level = Data.readVarint32ZigZag()
      when SYNCID_SERVERTIME
        m_ServerTime = Data.readVarint32ZigZag()
      when SYNCID_ROLEID
        m_RoleId = Data.readVarint32ZigZag()

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "BaseAttrModel",
      'AskName': ["SyncData"]
      'ParamterList': [[]]
      'AskList':[@SyncData]
      'ParamterTypelist': [[]]


module.exports =(()->
  if not BaseAttr?
    BaseAttr = new BaseAttrModel()
  BaseAttr)()



  

  

  


