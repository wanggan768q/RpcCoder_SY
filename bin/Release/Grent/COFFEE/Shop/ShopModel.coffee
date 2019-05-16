ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 33
RPC_CODE_BUYITEM_REQUEST = 3351
RPC_CODE_SHOPINFO_REQUEST = 3352

BuyItemAskPB = null
BuyItemReplyPB = null
ShopInfoAskPB = null
ShopInfoReplyPB = null

class ShopModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcBuyItemAsk
      {
        optional int32 ShopItemId = 1[default=-1];
        optional int32 ItemNum = 2[default=-1];
      }
      message  ShopItem
      {
        optional int32 ShopItemID = 1[default=-1];
        optional int32 TotalBuyCount = 2[default=-1];
      }
      message  RpcBuyItemReply
      {
        optional int32 Result = 1[default=-1];
        optional ShopItem ItemInfo = 2;
      }
      message  RpcShopInfoAsk
      {
        optional int32 RoleID = 1[default=-1];
      }
      message  RpcShopInfoReply
      {
        optional int32 Result = 1[default=-1];
        repeated ShopItem ItemInfo = 2;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    BuyItemAskPB = Proto.build("RpcBuyItemAsk")
    BuyItemReplyPB = Proto.build("RpcBuyItemReply")
    ShopInfoAskPB = Proto.build("RpcShopInfoAsk")
    ShopInfoReplyPB = Proto.build("RpcShopInfoReply")






  BuyItem : (ShopItemId,ItemNum,replyCB) ->
    BuyItemAsk = BuyItemAskPB.prototype
    BuyItemAsk.setShopItemId ShopItemId
    BuyItemAsk.setItemNum ItemNum
    mLayerMgr.sendAsk(RPC_CODE_BUYITEM_REQUEST,BuyItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( BuyItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ShopInfo : (RoleID,replyCB) ->
    ShopInfoAsk = ShopInfoAskPB.prototype
    ShopInfoAsk.setRoleID RoleID
    mLayerMgr.sendAsk(RPC_CODE_SHOPINFO_REQUEST,ShopInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ShopInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "ShopModel",
      'AskName': ["BuyItem",
                   "ShopInfo"]
      'ParamterList': [["ShopItemId","ItemNum"],
                       ["RoleID"]]
      'AskList':[@BuyItem,
                 @ShopInfo]
      'ParamterTypelist': [["int32","int32"],
                       ["int32"]]


module.exports =(()->
  if not Shop?
    Shop = new ShopModel()
  Shop)()



  

  

  


