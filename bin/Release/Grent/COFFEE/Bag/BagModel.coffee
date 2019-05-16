ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcBagChangeNotifyCB = null
RpcAddItemNotifyCB = null
RpcItemChangeNotifyCB = null


ModuleId = 12
RPC_CODE_USEITEM_REQUEST = 1251
RPC_CODE_SALEITEM_REQUEST = 1252
RPC_CODE_LOCKITEM_REQUEST = 1253
RPC_CODE_DEBLOCKING_REQUEST = 1254
RPC_CODE_TAKEITEM_REQUEST = 1255
RPC_CODE_TIDY_REQUEST = 1256
RPC_CODE_TAKEALLBACKBAGS_REQUEST = 1257
RPC_CODE_BAGCHANGE_NOTIFY = 1258
RPC_CODE_MERGEITEM_REQUEST = 1259
RPC_CODE_BAGSYNC_REQUEST = 1260
RPC_CODE_ADDITEM_NOTIFY = 1261
RPC_CODE_CONSUMEITEM_REQUEST = 1262
RPC_CODE_ITEMCHANGE_NOTIFY = 1263
RPC_CODE_CLICKITEM_REQUEST = 1264

UseItemAskPB = null
UseItemReplyPB = null
SaleItemAskPB = null
SaleItemReplyPB = null
LockItemAskPB = null
LockItemReplyPB = null
DeblockingAskPB = null
DeblockingReplyPB = null
TakeItemAskPB = null
TakeItemReplyPB = null
TidyAskPB = null
TidyReplyPB = null
TakeAllBackBagsAskPB = null
TakeAllBackBagsReplyPB = null
BagChangeNotifyPB = null
MergeItemAskPB = null
MergeItemReplyPB = null
BagSyncAskPB = null
BagSyncReplyPB = null
AddItemNotifyPB = null
ConsumeItemAskPB = null
ConsumeItemReplyPB = null
ItemChangeNotifyPB = null
ClickItemAskPB = null
ClickItemReplyPB = null

class BagModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcUseItemAsk
      {
        optional int32 Count = 1[default=-1];
        optional int32 Pos = 2[default=-1];
        optional int32 BagType = 3[default=-1];
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
      message  PetSkill
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
        repeated PetSkill SkillList = 8;
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
        optional int32 BindRule = 15[default=1];
        optional int32 SaleCD = 16[default=0];
      }
      message  ItemObj
      {
        optional int32 Pos = 1[default=-1];
        optional ItemData ItemData = 2;
        optional bool RedPoint = 3;
      }
      message  RpcUseItemReply
      {
        optional int32 Result = 1[default=-9999];
        optional ItemObj Item = 2;
        optional ItemObj NowItem = 4;
      }
      message  RpcSaleItemAsk
      {
        optional int32 Pos = 5[default=-1];
        optional int32 Count = 6[default=-1];
        optional int32 BagType = 7[default=-1];
      }
      message  RpcSaleItemReply
      {
        optional int32 Result = 1[default=-9999];
        optional ItemObj Item = 4;
      }
      message  RpcLockItemAsk
      {
        optional int32 Pos = 1[default=-1];
        optional bool IsLock = 3;
        optional int32 BagType = 4[default=-1];
      }
      message  RpcLockItemReply
      {
        optional int32 Result = 1[default=-9999];
        optional ItemObj Item = 5;
      }
      message  RpcDeblockingAsk
      {
        optional int32 BagType = 1[default=-1];
      }
      message  RpcDeblockingReply
      {
        optional int32 Result = 1[default=-9999];
        optional int32 BagType = 2[default=-1];
        optional int32 CurCapacity = 3[default=-1];
      }
      message  RpcTakeItemAsk
      {
        optional int32 FromBagType = 1[default=-1];
        optional int32 ToBagType = 2[default=-1];
        optional int32 FromPos = 3[default=-1];
      }
      message  RpcTakeItemReply
      {
        optional int32 Result = 1[default=-9999];
        optional ItemObj ToItemObj = 2;
        optional ItemObj FromItemObj = 3;
        optional int32 FromBagType = 4[default=-1];
        optional int32 ToBagType = 5[default=-1];
      }
      message  RpcTidyAsk
      {
        optional int32 BagType = 2[default=-1];
      }
      message  BagData
      {
        repeated ItemObj Items = 1;
        optional int32 BagType = 2[default=-1];
        optional int32 CurCapacity = 3[default=-1];
      }
      message  RpcTidyReply
      {
        optional int32 Result = 1[default=-9999];
        optional BagData Bags = 3;
      }
      message  RpcTakeAllBackBagsAsk
      {
      }
      message  RpcTakeAllBackBagsReply
      {
        optional int32 Result = 1[default=-9999];
        repeated BagData Bags = 2;
      }
      message  RpcBagChangeNotify
      {
        optional int32 Result = 1[default=-9999];
        optional BagData Bags = 2;
      }
      message  RpcMergeItemAsk
      {
        optional int32 Pos = 1[default=-1];
        optional int32 BagType = 2[default=-1];
      }
      message  RpcMergeItemReply
      {
        optional int32 Result = 1[default=-9999];
        optional BagData Bags = 2;
      }
      message  RpcBagSyncAsk
      {
      }
      message  RpcBagSyncReply
      {
        optional int32 Result = 1[default=-1];
        repeated BagData Bags = 2;
      }
      message  RpcAddItemNotify
      {
        repeated ItemObj Item = 1;
      }
      message  ItemSimpleData
      {
        optional int32 ConfID = 1[default=-1];
        optional int32 Count = 2[default=-1];
      }
      message  RpcConsumeItemAsk
      {
        repeated int32 ConfigId = 1;
        repeated ItemSimpleData ItemData = 3;
      }
      message  RpcConsumeItemReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcItemChangeNotify
      {
        repeated ItemObj ItemList = 1;
        optional int32 BagType = 2[default=-1];
      }
      message  RpcClickItemAsk
      {
        optional uint64 Guid = 1[default=0];
      }
      message  RpcClickItemReply
      {
        optional int32 Result = 1[default=-1];
        optional ItemObj Item = 2;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    UseItemAskPB = Proto.build("RpcUseItemAsk")
    UseItemReplyPB = Proto.build("RpcUseItemReply")
    SaleItemAskPB = Proto.build("RpcSaleItemAsk")
    SaleItemReplyPB = Proto.build("RpcSaleItemReply")
    LockItemAskPB = Proto.build("RpcLockItemAsk")
    LockItemReplyPB = Proto.build("RpcLockItemReply")
    DeblockingAskPB = Proto.build("RpcDeblockingAsk")
    DeblockingReplyPB = Proto.build("RpcDeblockingReply")
    TakeItemAskPB = Proto.build("RpcTakeItemAsk")
    TakeItemReplyPB = Proto.build("RpcTakeItemReply")
    TidyAskPB = Proto.build("RpcTidyAsk")
    TidyReplyPB = Proto.build("RpcTidyReply")
    TakeAllBackBagsAskPB = Proto.build("RpcTakeAllBackBagsAsk")
    TakeAllBackBagsReplyPB = Proto.build("RpcTakeAllBackBagsReply")
    BagChangeNotifyPB = Proto.build("RpcBagChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_BAGCHANGE_NOTIFY,@BagChangeCB)
    MergeItemAskPB = Proto.build("RpcMergeItemAsk")
    MergeItemReplyPB = Proto.build("RpcMergeItemReply")
    BagSyncAskPB = Proto.build("RpcBagSyncAsk")
    BagSyncReplyPB = Proto.build("RpcBagSyncReply")
    AddItemNotifyPB = Proto.build("RpcAddItemNotify")
    mLayerMgr.registerNotify(RPC_CODE_ADDITEM_NOTIFY,@AddItemCB)
    ConsumeItemAskPB = Proto.build("RpcConsumeItemAsk")
    ConsumeItemReplyPB = Proto.build("RpcConsumeItemReply")
    ItemChangeNotifyPB = Proto.build("RpcItemChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_ITEMCHANGE_NOTIFY,@ItemChangeCB)
    ClickItemAskPB = Proto.build("RpcClickItemAsk")
    ClickItemReplyPB = Proto.build("RpcClickItemReply")






  UseItem : (Count,Pos,BagType,replyCB) ->
    UseItemAsk = UseItemAskPB.prototype
    UseItemAsk.setCount Count
    UseItemAsk.setPos Pos
    UseItemAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_USEITEM_REQUEST,UseItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UseItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SaleItem : (Pos,Count,BagType,replyCB) ->
    SaleItemAsk = SaleItemAskPB.prototype
    SaleItemAsk.setPos Pos
    SaleItemAsk.setCount Count
    SaleItemAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_SALEITEM_REQUEST,SaleItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SaleItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LockItem : (Pos,IsLock,BagType,replyCB) ->
    LockItemAsk = LockItemAskPB.prototype
    LockItemAsk.setPos Pos
    LockItemAsk.setIsLock IsLock
    LockItemAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_LOCKITEM_REQUEST,LockItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LockItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Deblocking : (BagType,replyCB) ->
    DeblockingAsk = DeblockingAskPB.prototype
    DeblockingAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_DEBLOCKING_REQUEST,DeblockingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DeblockingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  TakeItem : (FromBagType,ToBagType,FromPos,replyCB) ->
    TakeItemAsk = TakeItemAskPB.prototype
    TakeItemAsk.setFromBagType FromBagType
    TakeItemAsk.setToBagType ToBagType
    TakeItemAsk.setFromPos FromPos
    mLayerMgr.sendAsk(RPC_CODE_TAKEITEM_REQUEST,TakeItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( TakeItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Tidy : (BagType,replyCB) ->
    TidyAsk = TidyAskPB.prototype
    TidyAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_TIDY_REQUEST,TidyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( TidyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  TakeAllBackBags : (replyCB) ->
    TakeAllBackBagsAsk = TakeAllBackBagsAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_TAKEALLBACKBAGS_REQUEST,TakeAllBackBagsAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( TakeAllBackBagsReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MergeItem : (Pos,BagType,replyCB) ->
    MergeItemAsk = MergeItemAskPB.prototype
    MergeItemAsk.setPos Pos
    MergeItemAsk.setBagType BagType
    mLayerMgr.sendAsk(RPC_CODE_MERGEITEM_REQUEST,MergeItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MergeItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  BagSync : (replyCB) ->
    BagSyncAsk = BagSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_BAGSYNC_REQUEST,BagSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( BagSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ConsumeItem : (ConfigId,ItemData,replyCB) ->
    ConsumeItemAsk = ConsumeItemAskPB.prototype
    ConsumeItemAsk.setConfigId ConfigId
    ConsumeItemAsk.setItemData ItemData
    mLayerMgr.sendAsk(RPC_CODE_CONSUMEITEM_REQUEST,ConsumeItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ConsumeItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ClickItem : (Guid,replyCB) ->
    ClickItemAsk = ClickItemAskPB.prototype
    ClickItemAsk.setGuid Guid
    mLayerMgr.sendAsk(RPC_CODE_CLICKITEM_REQUEST,ClickItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ClickItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetBagChangeNotifyCB : (cb) -> RpcBagChangeNotifyCB = cb
  BagChangeCB : (data)->
    RpcBagChangeNotifyCB( BagChangeNotifyPB.decode(data)) if typeof(RpcBagChangeNotifyCB) is "function"
  SetAddItemNotifyCB : (cb) -> RpcAddItemNotifyCB = cb
  AddItemCB : (data)->
    RpcAddItemNotifyCB( AddItemNotifyPB.decode(data)) if typeof(RpcAddItemNotifyCB) is "function"
  SetItemChangeNotifyCB : (cb) -> RpcItemChangeNotifyCB = cb
  ItemChangeCB : (data)->
    RpcItemChangeNotifyCB( ItemChangeNotifyPB.decode(data)) if typeof(RpcItemChangeNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "BagModel",
      'AskName': ["UseItem",
                   "SaleItem",
                   "LockItem",
                   "Deblocking",
                   "TakeItem",
                   "Tidy",
                   "TakeAllBackBags",
                   "MergeItem",
                   "BagSync",
                   "ConsumeItem",
                   "ClickItem"]
      'ParamterList': [["Count","Pos","BagType"],
                       ["Pos","Count","BagType"],
                       ["Pos","IsLock","BagType"],
                       ["BagType"],
                       ["FromBagType","ToBagType","FromPos"],
                       ["BagType"],
                       [],
                       ["Pos","BagType"],
                       [],
                       ["ConfigId","ItemData"],
                       ["Guid"]]
      'AskList':[@UseItem,
                 @SaleItem,
                 @LockItem,
                 @Deblocking,
                 @TakeItem,
                 @Tidy,
                 @TakeAllBackBags,
                 @MergeItem,
                 @BagSync,
                 @ConsumeItem,
                 @ClickItem]
      'ParamterTypelist': [["int32","int32","int32"],
                       ["int32","int32","int32"],
                       ["int32","bool","int32"],
                       ["int32"],
                       ["int32","int32","int32"],
                       ["int32"],
                       [],
                       ["int32","int32"],
                       [],
                       ["int32","ItemSimpleData"],
                       ["uint64"]]


module.exports =(()->
  if not Bag?
    Bag = new BagModel()
  Bag)()



  

  

  


