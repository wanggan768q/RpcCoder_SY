ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 31
RPC_CODE_PETSYNC_REQUEST = 3151
RPC_CODE_UNSUMMON_REQUEST = 3152
RPC_CODE_LEVELUPGRADE_REQUEST = 3153
RPC_CODE_STARUPGRADE_REQUEST = 3154
RPC_CODE_CHANGENAME_REQUEST = 3155
RPC_CODE_INHERIT_REQUEST = 3156

PetSyncAskPB = null
PetSyncReplyPB = null
UnSummonAskPB = null
UnSummonReplyPB = null
LevelUpgradeAskPB = null
LevelUpgradeReplyPB = null
StarUpgradeAskPB = null
StarUpgradeReplyPB = null
ChangeNameAskPB = null
ChangeNameReplyPB = null
InheritAskPB = null
InheritReplyPB = null

class PetModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcPetSyncAsk
      {
      }
      message  AttrKeyValue
      {
        optional int32 Key = 1[default=-1];
        optional int64 Value = 2[default=-1];
        optional int32 Quality = 3[default=-1];
      }
      message  EquipAttr
      {
        repeated AttrKeyValue BaseAttr = 1;
        repeated AttrKeyValue ExtraAttr = 2;
        optional int32 BattleScore = 3[default=-1];
      }
      message  PetData
      {
        optional int32 Exp = 1[default=-1];
        optional int32 Level = 2[default=-1];
        optional string Name = 3;
        repeated AttrKeyValue Attrs = 5;
        optional int32 BattleScore = 6[default=-1];
        repeated AttrKeyValue Talent = 7;
        repeated int32 SkillList = 8;
        optional bool IsActive = 9;
        optional int32 TalentScore = 10[default=-1];
      }
      message  ItemData
      {
        optional bool IsLock = 2;
        optional int32 OverlayCount = 3[default=-1];
        optional int32 ConfigId = 4[default=-1];
        optional EquipAttr EquipAttr = 5;
        optional bool IsBind = 12;
        optional uint64 Guid = 13[default=0];
        optional PetData PetData = 14;
      }
      message  RpcPetSyncReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData ItemData = 2;
      }
      message  RpcUnSummonAsk
      {
      }
      message  RpcUnSummonReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcLevelUpgradeAsk
      {
        optional uint64 Guid = 2[default=0];
        repeated int32 ItemCount = 3;
      }
      message  RpcLevelUpgradeReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData ItemData = 2;
      }
      message  RpcStarUpgradeAsk
      {
        optional uint64 Guid = 1[default=0];
        optional int32 UseGuid = 2[default=-1];
      }
      message  RpcStarUpgradeReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData ItemData = 2;
      }
      message  RpcChangeNameAsk
      {
        optional uint64 Guid = 1[default=0];
        optional string NewName = 2;
      }
      message  RpcChangeNameReply
      {
        optional int32 Result = 1[default=-1];
        optional string Name = 2;
      }
      message  RpcInheritAsk
      {
        optional int32 Guid = 1[default=-1];
        optional int32 UseGuid = 2[default=-1];
      }
      message  RpcInheritReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData ItemData = 2;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    PetSyncAskPB = Proto.build("RpcPetSyncAsk")
    PetSyncReplyPB = Proto.build("RpcPetSyncReply")
    UnSummonAskPB = Proto.build("RpcUnSummonAsk")
    UnSummonReplyPB = Proto.build("RpcUnSummonReply")
    LevelUpgradeAskPB = Proto.build("RpcLevelUpgradeAsk")
    LevelUpgradeReplyPB = Proto.build("RpcLevelUpgradeReply")
    StarUpgradeAskPB = Proto.build("RpcStarUpgradeAsk")
    StarUpgradeReplyPB = Proto.build("RpcStarUpgradeReply")
    ChangeNameAskPB = Proto.build("RpcChangeNameAsk")
    ChangeNameReplyPB = Proto.build("RpcChangeNameReply")
    InheritAskPB = Proto.build("RpcInheritAsk")
    InheritReplyPB = Proto.build("RpcInheritReply")






  PetSync : (replyCB) ->
    PetSyncAsk = PetSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_PETSYNC_REQUEST,PetSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( PetSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UnSummon : (replyCB) ->
    UnSummonAsk = UnSummonAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_UNSUMMON_REQUEST,UnSummonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UnSummonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LevelUpgrade : (Guid,ItemCount,replyCB) ->
    LevelUpgradeAsk = LevelUpgradeAskPB.prototype
    LevelUpgradeAsk.setGuid Guid
    LevelUpgradeAsk.setItemCount ItemCount
    mLayerMgr.sendAsk(RPC_CODE_LEVELUPGRADE_REQUEST,LevelUpgradeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LevelUpgradeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  StarUpgrade : (Guid,UseGuid,replyCB) ->
    StarUpgradeAsk = StarUpgradeAskPB.prototype
    StarUpgradeAsk.setGuid Guid
    StarUpgradeAsk.setUseGuid UseGuid
    mLayerMgr.sendAsk(RPC_CODE_STARUPGRADE_REQUEST,StarUpgradeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( StarUpgradeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeName : (Guid,NewName,replyCB) ->
    ChangeNameAsk = ChangeNameAskPB.prototype
    ChangeNameAsk.setGuid Guid
    ChangeNameAsk.setNewName NewName
    mLayerMgr.sendAsk(RPC_CODE_CHANGENAME_REQUEST,ChangeNameAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeNameReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Inherit : (Guid,UseGuid,replyCB) ->
    InheritAsk = InheritAskPB.prototype
    InheritAsk.setGuid Guid
    InheritAsk.setUseGuid UseGuid
    mLayerMgr.sendAsk(RPC_CODE_INHERIT_REQUEST,InheritAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InheritReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "PetModel",
      'AskName': ["PetSync",
                   "UnSummon",
                   "LevelUpgrade",
                   "StarUpgrade",
                   "ChangeName",
                   "Inherit"]
      'ParamterList': [[],
                       [],
                       ["Guid","ItemCount"],
                       ["Guid","UseGuid"],
                       ["Guid","NewName"],
                       ["Guid","UseGuid"]]
      'AskList':[@PetSync,
                 @UnSummon,
                 @LevelUpgrade,
                 @StarUpgrade,
                 @ChangeName,
                 @Inherit]
      'ParamterTypelist': [[],
                       [],
                       ["uint64","int32"],
                       ["uint64","int32"],
                       ["uint64","string"],
                       ["int32","int32"]]


module.exports =(()->
  if not Pet?
    Pet = new PetModel()
  Pet)()



  

  

  


