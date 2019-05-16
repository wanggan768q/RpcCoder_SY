ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 18
RPC_CODE_EQUIP_REQUEST = 1851
RPC_CODE_UNEQUIP_REQUEST = 1852
RPC_CODE_SWITCHEQUIPSET_REQUEST = 1853
RPC_CODE_SYNCEQUIP_REQUEST = 1854
RPC_CODE_RESONANCEUNLOCK_REQUEST = 1855
RPC_CODE_EQUIPDORESONANCE_REQUEST = 1856
RPC_CODE_EQUIPRESONANCESAVE_REQUEST = 1857
RPC_CODE_EQUIPRESONANCESYNC_REQUEST = 1858
RPC_CODE_EQUIPWASHSYNC_REQUEST = 1859
RPC_CODE_EQUIPWASH_REQUEST = 1860
RPC_CODE_EQUIPWASHSAVE_REQUEST = 1861
RPC_CODE_EQUIPBUILDSYNC_REQUEST = 1862
RPC_CODE_EQUIPBUILD_REQUEST = 1863
RPC_CODE_GETPLAYERINFO_REQUEST = 1864
RPC_CODE_EQUIPINHERIT_REQUEST = 1865

EquipAskPB = null
EquipReplyPB = null
UnEquipAskPB = null
UnEquipReplyPB = null
SwitchEquipSetAskPB = null
SwitchEquipSetReplyPB = null
SyncEquipAskPB = null
SyncEquipReplyPB = null
ResonanceUnlockAskPB = null
ResonanceUnlockReplyPB = null
EquipDoResonanceAskPB = null
EquipDoResonanceReplyPB = null
EquipResonanceSaveAskPB = null
EquipResonanceSaveReplyPB = null
EquipResonanceSyncAskPB = null
EquipResonanceSyncReplyPB = null
EquipWashSyncAskPB = null
EquipWashSyncReplyPB = null
EquipWashAskPB = null
EquipWashReplyPB = null
EquipWashSaveAskPB = null
EquipWashSaveReplyPB = null
EquipBuildSyncAskPB = null
EquipBuildSyncReplyPB = null
EquipBuildAskPB = null
EquipBuildReplyPB = null
GetPlayerInfoAskPB = null
GetPlayerInfoReplyPB = null
EquipInheritAskPB = null
EquipInheritReplyPB = null

class EquipmentModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcEquipAsk
      {
        optional int32 Pos = 1[default=-1];
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
      message  PetPassiveSkill
      {
        optional int32 SkillId = 3[default=-1];
        optional int32 Lock = 4[default=-1];
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
        optional int32 ActiveSkill = 11[default=-1];
        repeated PetPassiveSkill PassiveSkills = 13;
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
      message  SuitInfo
      {
        optional int32 Suit_id = 1[default=-1];
        optional int32 Collect_num = 2[default=-1];
      }
      message  RpcEquipReply
      {
        optional int32 Result = 1[default=-9999];
        repeated ItemData Equip_data = 2;
        repeated SuitInfo Suit_infos = 3;
        optional int32 SlotType = 4[default=-1];
      }
      message  RpcUnEquipAsk
      {
        optional int32 SlotType = 1[default=-1];
      }
      message  RpcUnEquipReply
      {
        optional int32 Result = 1[default=-9999];
        repeated ItemData Equip_data = 2;
        repeated SuitInfo Suit_infos = 3;
        optional int32 SlotType = 4[default=-1];
      }
      message  RpcSwitchEquipSetAsk
      {
        optional int32 To_index = 1[default=-1];
      }
      message  RpcSwitchEquipSetReply
      {
        optional int32 Result = 1[default=-9999];
        repeated ItemData Equip_data = 2;
      }
      message  RpcSyncEquipAsk
      {
      }
      message  RpcSyncEquipReply
      {
        optional int32 Result = 1[default=-9999];
        repeated ItemData Equip_data = 3;
        repeated SuitInfo Suit_infos = 4;
      }
      message  RpcResonanceUnlockAsk
      {
        optional int32 ConfId = 1[default=-1];
      }
      message  EquipResonanceInfo
      {
        optional int32 ConfId = 2[default=-1];
        repeated AttrKeyValue ResonanceAttr = 3;
        repeated AttrKeyValue NewResonanceAttr = 4;
        optional int32 BattleScore = 5[default=-1];
        optional int32 NewBattleScore = 6[default=-1];
      }
      message  RpcResonanceUnlockReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipResonanceInfo ResonanceInfo = 2;
      }
      message  RpcEquipDoResonanceAsk
      {
        optional int32 ConfId = 1[default=-1];
      }
      message  RpcEquipDoResonanceReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipResonanceInfo AddAttr = 2;
      }
      message  RpcEquipResonanceSaveAsk
      {
        optional int32 ConfId = 1[default=-1];
      }
      message  RpcEquipResonanceSaveReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipResonanceInfo ResonanceInfo = 2;
      }
      message  RpcEquipResonanceSyncAsk
      {
      }
      message  EquipResonanceData
      {
        repeated EquipResonanceInfo ResonanceList = 1;
      }
      message  RpcEquipResonanceSyncReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipResonanceData ResonanceData = 2;
      }
      message  RpcEquipWashSyncAsk
      {
      }
      message  EquipWashInfo
      {
        optional uint64 EquipGuid = 1[default=0];
        repeated AttrKeyValue ExtraAttr = 2;
        repeated int32 LockedIndex = 3;
        optional int32 BattleScore = 4[default=-1];
      }
      message  EquipWashData
      {
        repeated EquipWashInfo EquipWashInfoList = 1;
        optional int32 LeftTimes = 2[default=-1];
      }
      message  RpcEquipWashSyncReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipWashData EquipWashData = 2;
      }
      message  RpcEquipWashAsk
      {
        optional uint64 Guid = 1[default=0];
        repeated int32 LockedIndex = 2;
      }
      message  RpcEquipWashReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipWashInfo EquipWashInfo = 2;
        optional int32 LeftTimes = 3[default=-1];
      }
      message  RpcEquipWashSaveAsk
      {
        optional uint64 Guid = 1[default=0];
      }
      message  RpcEquipWashSaveReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData ItemData = 2;
        repeated int32 LockedIndex = 3;
      }
      message  RpcEquipBuildSyncAsk
      {
      }
      message  EquipBuildAtf
      {
        optional int32 Level = 1[default=-1];
        optional int32 Atf_value = 2[default=-1];
      }
      message  RpcEquipBuildSyncReply
      {
        optional int32 Result = 1[default=-1];
        repeated EquipBuildAtf Atf_list = 2;
      }
      message  RpcEquipBuildAsk
      {
        optional int32 Level = 1[default=-1];
        optional int32 Occupation = 2[default=-1];
        optional int32 Slot_type = 3[default=-1];
      }
      message  ItemObj
      {
        optional int32 Pos = 1[default=-1];
        optional ItemData ItemData = 2;
      }
      message  RpcEquipBuildReply
      {
        optional int32 Result = 1[default=-1];
        optional EquipBuildAtf EquipBuildAtf = 2;
        optional ItemObj Equip = 3;
      }
      message  RpcGetPlayerInfoAsk
      {
        optional uint64 Player_guid = 1[default=0];
      }
      message  EquipSlotInfo
      {
        optional int32 Enhance_Level = 1[default=-1];
        optional int32 Enhance_Exp = 2[default=-1];
        repeated AttrKeyValue Enhance_Attr = 3;
        optional int32 BattleScore = 4[default=-1];
        optional int32 Slot_Type = 5[default=-1];
      }
      message  EquipSlotStarInfo
      {
        optional int32 RankUp_Level = 1[default=-1];
        optional int32 Slot_Type = 3[default=-1];
        optional int32 BattleScore = 4[default=-1];
        optional int32 NextBattleScore = 6[default=-1];
      }
      message  JewelSlot
      {
        optional int32 ItemId = 1[default=-1];
        optional bool Unlocked = 2;
      }
      message  JewelInfo
      {
        optional int32 EquipSlot = 1[default=-1];
        repeated JewelSlot JewelSlots = 2;
      }
      message  RpcGetPlayerInfoReply
      {
        optional int32 Result = 1[default=-1];
        optional string Player_name = 2;
        optional uint64 Player_guid = 3[default=0];
        optional int32 Avatar_id = 4[default=-1];
        optional int32 Player_level = 5[default=-1];
        optional int32 Avatar_frame_id = 6[default=-1];
        optional int32 Config_id = 7[default=-1];
        optional uint64 Guild_id = 8[default=0];
        optional string Guild_name = 9;
        repeated ItemData Equip_data = 10;
        repeated SuitInfo Suit_infos = 11;
        repeated EquipSlotInfo EquipSlotData = 12;
        repeated EquipSlotStarInfo EquipSlotStarList = 13;
        repeated JewelInfo JewelInfos = 14;
        optional int32 BattleScore = 16[default=-1];
        optional ItemData Pet_item_data = 18;
        optional int32 TreasureHair = 19[default=-1];
        optional int32 TreasureHead = 20[default=-1];
        optional int32 TreasureBody = 21[default=-1];
        optional int32 TreasureWeapon = 22[default=-1];
        optional int32 TreasureWing = 23[default=-1];
        optional uint64 TeamId = 24[default=0];
      }
      message  RpcEquipInheritAsk
      {
        optional uint64 ToGuid = 1[default=0];
        optional uint64 FromGuid = 2[default=0];
      }
      message  RpcEquipInheritReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemData NewEquip = 4;
        repeated ItemData EquipData = 5;
        repeated SuitInfo SuitInfos = 6;
        optional uint64 FromGuid = 7[default=0];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    EquipAskPB = Proto.build("RpcEquipAsk")
    EquipReplyPB = Proto.build("RpcEquipReply")
    UnEquipAskPB = Proto.build("RpcUnEquipAsk")
    UnEquipReplyPB = Proto.build("RpcUnEquipReply")
    SwitchEquipSetAskPB = Proto.build("RpcSwitchEquipSetAsk")
    SwitchEquipSetReplyPB = Proto.build("RpcSwitchEquipSetReply")
    SyncEquipAskPB = Proto.build("RpcSyncEquipAsk")
    SyncEquipReplyPB = Proto.build("RpcSyncEquipReply")
    ResonanceUnlockAskPB = Proto.build("RpcResonanceUnlockAsk")
    ResonanceUnlockReplyPB = Proto.build("RpcResonanceUnlockReply")
    EquipDoResonanceAskPB = Proto.build("RpcEquipDoResonanceAsk")
    EquipDoResonanceReplyPB = Proto.build("RpcEquipDoResonanceReply")
    EquipResonanceSaveAskPB = Proto.build("RpcEquipResonanceSaveAsk")
    EquipResonanceSaveReplyPB = Proto.build("RpcEquipResonanceSaveReply")
    EquipResonanceSyncAskPB = Proto.build("RpcEquipResonanceSyncAsk")
    EquipResonanceSyncReplyPB = Proto.build("RpcEquipResonanceSyncReply")
    EquipWashSyncAskPB = Proto.build("RpcEquipWashSyncAsk")
    EquipWashSyncReplyPB = Proto.build("RpcEquipWashSyncReply")
    EquipWashAskPB = Proto.build("RpcEquipWashAsk")
    EquipWashReplyPB = Proto.build("RpcEquipWashReply")
    EquipWashSaveAskPB = Proto.build("RpcEquipWashSaveAsk")
    EquipWashSaveReplyPB = Proto.build("RpcEquipWashSaveReply")
    EquipBuildSyncAskPB = Proto.build("RpcEquipBuildSyncAsk")
    EquipBuildSyncReplyPB = Proto.build("RpcEquipBuildSyncReply")
    EquipBuildAskPB = Proto.build("RpcEquipBuildAsk")
    EquipBuildReplyPB = Proto.build("RpcEquipBuildReply")
    GetPlayerInfoAskPB = Proto.build("RpcGetPlayerInfoAsk")
    GetPlayerInfoReplyPB = Proto.build("RpcGetPlayerInfoReply")
    EquipInheritAskPB = Proto.build("RpcEquipInheritAsk")
    EquipInheritReplyPB = Proto.build("RpcEquipInheritReply")






  Equip : (Pos,replyCB) ->
    EquipAsk = EquipAskPB.prototype
    EquipAsk.setPos Pos
    mLayerMgr.sendAsk(RPC_CODE_EQUIP_REQUEST,EquipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UnEquip : (SlotType,replyCB) ->
    UnEquipAsk = UnEquipAskPB.prototype
    UnEquipAsk.setSlotType SlotType
    mLayerMgr.sendAsk(RPC_CODE_UNEQUIP_REQUEST,UnEquipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UnEquipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SwitchEquipSet : (To_index,replyCB) ->
    SwitchEquipSetAsk = SwitchEquipSetAskPB.prototype
    SwitchEquipSetAsk.setTo_index To_index
    mLayerMgr.sendAsk(RPC_CODE_SWITCHEQUIPSET_REQUEST,SwitchEquipSetAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SwitchEquipSetReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncEquip : (replyCB) ->
    SyncEquipAsk = SyncEquipAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCEQUIP_REQUEST,SyncEquipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncEquipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ResonanceUnlock : (ConfId,replyCB) ->
    ResonanceUnlockAsk = ResonanceUnlockAskPB.prototype
    ResonanceUnlockAsk.setConfId ConfId
    mLayerMgr.sendAsk(RPC_CODE_RESONANCEUNLOCK_REQUEST,ResonanceUnlockAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ResonanceUnlockReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipDoResonance : (ConfId,replyCB) ->
    EquipDoResonanceAsk = EquipDoResonanceAskPB.prototype
    EquipDoResonanceAsk.setConfId ConfId
    mLayerMgr.sendAsk(RPC_CODE_EQUIPDORESONANCE_REQUEST,EquipDoResonanceAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipDoResonanceReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipResonanceSave : (ConfId,replyCB) ->
    EquipResonanceSaveAsk = EquipResonanceSaveAskPB.prototype
    EquipResonanceSaveAsk.setConfId ConfId
    mLayerMgr.sendAsk(RPC_CODE_EQUIPRESONANCESAVE_REQUEST,EquipResonanceSaveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipResonanceSaveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipResonanceSync : (replyCB) ->
    EquipResonanceSyncAsk = EquipResonanceSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_EQUIPRESONANCESYNC_REQUEST,EquipResonanceSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipResonanceSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipWashSync : (replyCB) ->
    EquipWashSyncAsk = EquipWashSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_EQUIPWASHSYNC_REQUEST,EquipWashSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipWashSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipWash : (Guid,LockedIndex,replyCB) ->
    EquipWashAsk = EquipWashAskPB.prototype
    EquipWashAsk.setGuid Guid
    EquipWashAsk.setLockedIndex LockedIndex
    mLayerMgr.sendAsk(RPC_CODE_EQUIPWASH_REQUEST,EquipWashAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipWashReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipWashSave : (Guid,replyCB) ->
    EquipWashSaveAsk = EquipWashSaveAskPB.prototype
    EquipWashSaveAsk.setGuid Guid
    mLayerMgr.sendAsk(RPC_CODE_EQUIPWASHSAVE_REQUEST,EquipWashSaveAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipWashSaveReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipBuildSync : (replyCB) ->
    EquipBuildSyncAsk = EquipBuildSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_EQUIPBUILDSYNC_REQUEST,EquipBuildSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipBuildSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipBuild : (Level,Occupation,Slot_type,replyCB) ->
    EquipBuildAsk = EquipBuildAskPB.prototype
    EquipBuildAsk.setLevel Level
    EquipBuildAsk.setOccupation Occupation
    EquipBuildAsk.setSlot_type Slot_type
    mLayerMgr.sendAsk(RPC_CODE_EQUIPBUILD_REQUEST,EquipBuildAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipBuildReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetPlayerInfo : (Player_guid,replyCB) ->
    GetPlayerInfoAsk = GetPlayerInfoAskPB.prototype
    GetPlayerInfoAsk.setPlayer_guid Player_guid
    mLayerMgr.sendAsk(RPC_CODE_GETPLAYERINFO_REQUEST,GetPlayerInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetPlayerInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EquipInherit : (ToGuid,FromGuid,replyCB) ->
    EquipInheritAsk = EquipInheritAskPB.prototype
    EquipInheritAsk.setToGuid ToGuid
    EquipInheritAsk.setFromGuid FromGuid
    mLayerMgr.sendAsk(RPC_CODE_EQUIPINHERIT_REQUEST,EquipInheritAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EquipInheritReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "EquipmentModel",
      'AskName': ["Equip",
                   "UnEquip",
                   "SwitchEquipSet",
                   "SyncEquip",
                   "ResonanceUnlock",
                   "EquipDoResonance",
                   "EquipResonanceSave",
                   "EquipResonanceSync",
                   "EquipWashSync",
                   "EquipWash",
                   "EquipWashSave",
                   "EquipBuildSync",
                   "EquipBuild",
                   "GetPlayerInfo",
                   "EquipInherit"]
      'ParamterList': [["Pos"],
                       ["SlotType"],
                       ["To_index"],
                       [],
                       ["ConfId"],
                       ["ConfId"],
                       ["ConfId"],
                       [],
                       [],
                       ["Guid","LockedIndex"],
                       ["Guid"],
                       [],
                       ["Level","Occupation","Slot_type"],
                       ["Player_guid"],
                       ["ToGuid","FromGuid"]]
      'AskList':[@Equip,
                 @UnEquip,
                 @SwitchEquipSet,
                 @SyncEquip,
                 @ResonanceUnlock,
                 @EquipDoResonance,
                 @EquipResonanceSave,
                 @EquipResonanceSync,
                 @EquipWashSync,
                 @EquipWash,
                 @EquipWashSave,
                 @EquipBuildSync,
                 @EquipBuild,
                 @GetPlayerInfo,
                 @EquipInherit]
      'ParamterTypelist': [["int32"],
                       ["int32"],
                       ["int32"],
                       [],
                       ["int32"],
                       ["int32"],
                       ["int32"],
                       [],
                       [],
                       ["uint64","int32"],
                       ["uint64"],
                       [],
                       ["int32","int32","int32"],
                       ["uint64"],
                       ["uint64","uint64"]]


module.exports =(()->
  if not Equipment?
    Equipment = new EquipmentModel()
  Equipment)()



  

  

  


