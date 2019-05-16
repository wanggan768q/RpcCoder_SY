ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcOnAcceptQuestNotifyCB = null
RpcOnCompleteQuestNotifyCB = null
RpcUpdateQuestNotifyCB = null
RpcRemoveQuestNotifyNotifyCB = null
RpcDailyQuestUpdateNotifyCB = null


ModuleId = 15
RPC_CODE_ONACCEPTQUEST_NOTIFY = 1551
RPC_CODE_COMPLETEQUESTSTEP_REQUEST = 1552
RPC_CODE_ONCOMPLETEQUEST_NOTIFY = 1553
RPC_CODE_UPDATEQUEST_NOTIFY = 1554
RPC_CODE_GIVEUPQUEST_REQUEST = 1555
RPC_CODE_COMPLETEQUEST_REQUEST = 1556
RPC_CODE_COMPLETEACCEPTCHATMENU_REQUEST = 1557
RPC_CODE_ACCEPTQUEST_REQUEST = 1558
RPC_CODE_SYNCQUEST_REQUEST = 1559
RPC_CODE_GETREWARD_REQUEST = 1560
RPC_CODE_REMOVEQUESTNOTIFY_NOTIFY = 1561
RPC_CODE_GETQUESTDATA_REQUEST = 1562
RPC_CODE_SYNCDAILYQUEST_REQUEST = 1563
RPC_CODE_DAILYQUESTUPDATE_NOTIFY = 1564
RPC_CODE_CONSUMEITEM_REQUEST = 1565

OnAcceptQuestNotifyPB = null
CompleteQuestStepAskPB = null
CompleteQuestStepReplyPB = null
OnCompleteQuestNotifyPB = null
UpdateQuestNotifyPB = null
GiveUpQuestAskPB = null
GiveUpQuestReplyPB = null
CompleteQuestAskPB = null
CompleteQuestReplyPB = null
CompleteAcceptChatMenuAskPB = null
CompleteAcceptChatMenuReplyPB = null
AcceptQuestAskPB = null
AcceptQuestReplyPB = null
SyncQuestAskPB = null
SyncQuestReplyPB = null
GetRewardAskPB = null
GetRewardReplyPB = null
RemoveQuestNotifyNotifyPB = null
GetQuestDataAskPB = null
GetQuestDataReplyPB = null
SyncDailyQuestAskPB = null
SyncDailyQuestReplyPB = null
DailyQuestUpdateNotifyPB = null
ConsumeItemAskPB = null
ConsumeItemReplyPB = null

class QuestModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  QuestStepData
      {
        optional int32 Status = 2[default=-1];
        optional int32 Progress  = 3[default=-1];
      }
      message  QuestData
      {
        optional int32 ConfigId = 1[default=-1];
        optional int32 Status = 2[default=-1];
        repeated QuestStepData QuestSteps = 4;
        optional int32 QuestIndex = 6[default=-1];
        optional int32 QuestMaxIndex = 7[default=-1];
      }
      message  RpcOnAcceptQuestNotify
      {
        optional QuestData AcceptQuest = 1;
      }
      message  RpcCompleteQuestStepAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
        optional int32 QuestStep = 2[default=-1];
        optional int32 TargetId = 4[default=-1];
        optional int32 QuestStepEventType = 5[default=-1];
      }
      message  RpcCompleteQuestStepReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcOnCompleteQuestNotify
      {
        optional QuestData QuestData = 1;
      }
      message  RpcUpdateQuestNotify
      {
        optional QuestData Quest = 1;
      }
      message  RpcGiveUpQuestAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
      }
      message  RpcGiveUpQuestReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcCompleteQuestAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
        optional int32 TargetId = 2[default=-1];
        optional int32 QuestEventType = 3[default=-1];
      }
      message  RpcCompleteQuestReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcCompleteAcceptChatMenuAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
      }
      message  RpcCompleteAcceptChatMenuReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcAcceptQuestAsk
      {
        optional int32 Type = 1[default=-1];
        optional int32 QuestConfigId = 2[default=-1];
      }
      message  RpcAcceptQuestReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcSyncQuestAsk
      {
      }
      message  QuestListData
      {
        repeated QuestData QuestsList = 1;
      }
      message  RpcSyncQuestReply
      {
        optional int32 Result = 1[default=-1];
        optional QuestListData QuestList = 2;
        repeated int32 CompleteQuestIdsList = 3;
      }
      message  RpcGetRewardAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
      }
      message  RpcGetRewardReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcRemoveQuestNotifyNotify
      {
        repeated int32 QuestConfigId = 1;
      }
      message  RpcGetQuestDataAsk
      {
        repeated int32 QuestConfigId = 1;
      }
      message  RpcGetQuestDataReply
      {
        optional int32 Result = 1[default=-1];
        repeated QuestData QuestList = 2;
      }
      message  RpcSyncDailyQuestAsk
      {
      }
      message  DailyQuest
      {
        optional QuestData MainQuest = 1;
        optional QuestData AtivityQuest = 2;
        optional int32 Times = 3[default=-1];
        optional int32 ActivityId = 4[default=-1];
      }
      message  DailyQuestList
      {
        repeated DailyQuest DailyQuestList = 1;
      }
      message  RpcSyncDailyQuestReply
      {
        optional int32 Result = 1[default=-1];
        optional DailyQuestList DailyQuestList = 2;
      }
      message  RpcDailyQuestUpdateNotify
      {
        optional DailyQuest AtivityQuestData = 1;
      }
      message  ItemSimpleData
      {
        optional int32 ConfID = 1[default=-1];
        optional int32 Count = 2[default=-1];
      }
      message  RpcConsumeItemAsk
      {
        optional int32 QuestConfigId = 1[default=-1];
        repeated ItemSimpleData ItemData = 2;
      }
      message  RpcConsumeItemReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    OnAcceptQuestNotifyPB = Proto.build("RpcOnAcceptQuestNotify")
    mLayerMgr.registerNotify(RPC_CODE_ONACCEPTQUEST_NOTIFY,@OnAcceptQuestCB)
    CompleteQuestStepAskPB = Proto.build("RpcCompleteQuestStepAsk")
    CompleteQuestStepReplyPB = Proto.build("RpcCompleteQuestStepReply")
    OnCompleteQuestNotifyPB = Proto.build("RpcOnCompleteQuestNotify")
    mLayerMgr.registerNotify(RPC_CODE_ONCOMPLETEQUEST_NOTIFY,@OnCompleteQuestCB)
    UpdateQuestNotifyPB = Proto.build("RpcUpdateQuestNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATEQUEST_NOTIFY,@UpdateQuestCB)
    GiveUpQuestAskPB = Proto.build("RpcGiveUpQuestAsk")
    GiveUpQuestReplyPB = Proto.build("RpcGiveUpQuestReply")
    CompleteQuestAskPB = Proto.build("RpcCompleteQuestAsk")
    CompleteQuestReplyPB = Proto.build("RpcCompleteQuestReply")
    CompleteAcceptChatMenuAskPB = Proto.build("RpcCompleteAcceptChatMenuAsk")
    CompleteAcceptChatMenuReplyPB = Proto.build("RpcCompleteAcceptChatMenuReply")
    AcceptQuestAskPB = Proto.build("RpcAcceptQuestAsk")
    AcceptQuestReplyPB = Proto.build("RpcAcceptQuestReply")
    SyncQuestAskPB = Proto.build("RpcSyncQuestAsk")
    SyncQuestReplyPB = Proto.build("RpcSyncQuestReply")
    GetRewardAskPB = Proto.build("RpcGetRewardAsk")
    GetRewardReplyPB = Proto.build("RpcGetRewardReply")
    RemoveQuestNotifyNotifyPB = Proto.build("RpcRemoveQuestNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_REMOVEQUESTNOTIFY_NOTIFY,@RemoveQuestNotifyCB)
    GetQuestDataAskPB = Proto.build("RpcGetQuestDataAsk")
    GetQuestDataReplyPB = Proto.build("RpcGetQuestDataReply")
    SyncDailyQuestAskPB = Proto.build("RpcSyncDailyQuestAsk")
    SyncDailyQuestReplyPB = Proto.build("RpcSyncDailyQuestReply")
    DailyQuestUpdateNotifyPB = Proto.build("RpcDailyQuestUpdateNotify")
    mLayerMgr.registerNotify(RPC_CODE_DAILYQUESTUPDATE_NOTIFY,@DailyQuestUpdateCB)
    ConsumeItemAskPB = Proto.build("RpcConsumeItemAsk")
    ConsumeItemReplyPB = Proto.build("RpcConsumeItemReply")






  CompleteQuestStep : (QuestConfigId,QuestStep,TargetId,QuestStepEventType,replyCB) ->
    CompleteQuestStepAsk = CompleteQuestStepAskPB.prototype
    CompleteQuestStepAsk.setQuestConfigId QuestConfigId
    CompleteQuestStepAsk.setQuestStep QuestStep
    CompleteQuestStepAsk.setTargetId TargetId
    CompleteQuestStepAsk.setQuestStepEventType QuestStepEventType
    mLayerMgr.sendAsk(RPC_CODE_COMPLETEQUESTSTEP_REQUEST,CompleteQuestStepAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CompleteQuestStepReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GiveUpQuest : (QuestConfigId,replyCB) ->
    GiveUpQuestAsk = GiveUpQuestAskPB.prototype
    GiveUpQuestAsk.setQuestConfigId QuestConfigId
    mLayerMgr.sendAsk(RPC_CODE_GIVEUPQUEST_REQUEST,GiveUpQuestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GiveUpQuestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CompleteQuest : (QuestConfigId,TargetId,QuestEventType,replyCB) ->
    CompleteQuestAsk = CompleteQuestAskPB.prototype
    CompleteQuestAsk.setQuestConfigId QuestConfigId
    CompleteQuestAsk.setTargetId TargetId
    CompleteQuestAsk.setQuestEventType QuestEventType
    mLayerMgr.sendAsk(RPC_CODE_COMPLETEQUEST_REQUEST,CompleteQuestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CompleteQuestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CompleteAcceptChatMenu : (QuestConfigId,replyCB) ->
    CompleteAcceptChatMenuAsk = CompleteAcceptChatMenuAskPB.prototype
    CompleteAcceptChatMenuAsk.setQuestConfigId QuestConfigId
    mLayerMgr.sendAsk(RPC_CODE_COMPLETEACCEPTCHATMENU_REQUEST,CompleteAcceptChatMenuAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CompleteAcceptChatMenuReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AcceptQuest : (Type,QuestConfigId,replyCB) ->
    AcceptQuestAsk = AcceptQuestAskPB.prototype
    AcceptQuestAsk.setType Type
    AcceptQuestAsk.setQuestConfigId QuestConfigId
    mLayerMgr.sendAsk(RPC_CODE_ACCEPTQUEST_REQUEST,AcceptQuestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AcceptQuestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncQuest : (replyCB) ->
    SyncQuestAsk = SyncQuestAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCQUEST_REQUEST,SyncQuestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncQuestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetReward : (QuestConfigId,replyCB) ->
    GetRewardAsk = GetRewardAskPB.prototype
    GetRewardAsk.setQuestConfigId QuestConfigId
    mLayerMgr.sendAsk(RPC_CODE_GETREWARD_REQUEST,GetRewardAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetRewardReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetQuestData : (QuestConfigId,replyCB) ->
    GetQuestDataAsk = GetQuestDataAskPB.prototype
    GetQuestDataAsk.setQuestConfigId QuestConfigId
    mLayerMgr.sendAsk(RPC_CODE_GETQUESTDATA_REQUEST,GetQuestDataAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetQuestDataReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncDailyQuest : (replyCB) ->
    SyncDailyQuestAsk = SyncDailyQuestAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCDAILYQUEST_REQUEST,SyncDailyQuestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncDailyQuestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ConsumeItem : (QuestConfigId,ItemData,replyCB) ->
    ConsumeItemAsk = ConsumeItemAskPB.prototype
    ConsumeItemAsk.setQuestConfigId QuestConfigId
    ConsumeItemAsk.setItemData ItemData
    mLayerMgr.sendAsk(RPC_CODE_CONSUMEITEM_REQUEST,ConsumeItemAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ConsumeItemReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetOnAcceptQuestNotifyCB : (cb) -> RpcOnAcceptQuestNotifyCB = cb
  OnAcceptQuestCB : (data)->
    RpcOnAcceptQuestNotifyCB( OnAcceptQuestNotifyPB.decode(data)) if typeof(RpcOnAcceptQuestNotifyCB) is "function"
  SetOnCompleteQuestNotifyCB : (cb) -> RpcOnCompleteQuestNotifyCB = cb
  OnCompleteQuestCB : (data)->
    RpcOnCompleteQuestNotifyCB( OnCompleteQuestNotifyPB.decode(data)) if typeof(RpcOnCompleteQuestNotifyCB) is "function"
  SetUpdateQuestNotifyCB : (cb) -> RpcUpdateQuestNotifyCB = cb
  UpdateQuestCB : (data)->
    RpcUpdateQuestNotifyCB( UpdateQuestNotifyPB.decode(data)) if typeof(RpcUpdateQuestNotifyCB) is "function"
  SetRemoveQuestNotifyNotifyCB : (cb) -> RpcRemoveQuestNotifyNotifyCB = cb
  RemoveQuestNotifyCB : (data)->
    RpcRemoveQuestNotifyNotifyCB( RemoveQuestNotifyNotifyPB.decode(data)) if typeof(RpcRemoveQuestNotifyNotifyCB) is "function"
  SetDailyQuestUpdateNotifyCB : (cb) -> RpcDailyQuestUpdateNotifyCB = cb
  DailyQuestUpdateCB : (data)->
    RpcDailyQuestUpdateNotifyCB( DailyQuestUpdateNotifyPB.decode(data)) if typeof(RpcDailyQuestUpdateNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "QuestModel",
      'AskName': ["CompleteQuestStep",
                   "GiveUpQuest",
                   "CompleteQuest",
                   "CompleteAcceptChatMenu",
                   "AcceptQuest",
                   "SyncQuest",
                   "GetReward",
                   "GetQuestData",
                   "SyncDailyQuest",
                   "ConsumeItem"]
      'ParamterList': [["QuestConfigId","QuestStep","TargetId","QuestStepEventType"],
                       ["QuestConfigId"],
                       ["QuestConfigId","TargetId","QuestEventType"],
                       ["QuestConfigId"],
                       ["Type","QuestConfigId"],
                       [],
                       ["QuestConfigId"],
                       ["QuestConfigId"],
                       [],
                       ["QuestConfigId","ItemData"]]
      'AskList':[@CompleteQuestStep,
                 @GiveUpQuest,
                 @CompleteQuest,
                 @CompleteAcceptChatMenu,
                 @AcceptQuest,
                 @SyncQuest,
                 @GetReward,
                 @GetQuestData,
                 @SyncDailyQuest,
                 @ConsumeItem]
      'ParamterTypelist': [["int32","int32","int32","int32"],
                       ["int32"],
                       ["int32","int32","int32"],
                       ["int32"],
                       ["int32","int32"],
                       [],
                       ["int32"],
                       ["int32"],
                       [],
                       ["int32","ItemSimpleData"]]


module.exports =(()->
  if not Quest?
    Quest = new QuestModel()
  Quest)()



  

  

  


