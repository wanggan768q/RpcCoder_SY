ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcOpenRuleNotifyCB = null
RpcNextLayerNotifyCB = null
RpcChallengeEndNotifyCB = null


ModuleId = 47
RPC_CODE_OPENRULE_NOTIFY = 4751
RPC_CODE_ENTER_REQUEST = 4752
RPC_CODE_CHALLENGE_REQUEST = 4753
RPC_CODE_RANK_REQUEST = 4754
RPC_CODE_FIRSTVICREWARD_REQUEST = 4755
RPC_CODE_NEXTLAYER_NOTIFY = 4756
RPC_CODE_CHALLENGEEND_NOTIFY = 4757

OpenRuleNotifyPB = null
EnterAskPB = null
EnterReplyPB = null
ChallengeAskPB = null
ChallengeReplyPB = null
RankAskPB = null
RankReplyPB = null
FirstVicRewardAskPB = null
FirstVicRewardReplyPB = null
NextLayerNotifyPB = null
ChallengeEndNotifyPB = null

class ClimTowerModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcOpenRuleNotify
      {
      }
      message  RpcEnterAsk
      {
      }
      message  FirstVicGet
      {
        optional int32 Id = 1[default=-1];
        optional int32 Get = 2[default=0];
      }
      message  ClimTowerInfo
      {
        optional int64 LastTime = 1[default=0];
        optional int32 CurLayer = 2[default=1];
        optional int32 MaxLayer = 3[default=0];
        optional int64 ResetLayerTime = 12[default=0];
        repeated FirstVicGet FirstGet = 14;
      }
      message  RpcEnterReply
      {
        optional int32 Result = 1[default=-1];
        optional ClimTowerInfo EnterInfo = 2;
        optional int32 RemainTimes = 3[default=0];
      }
      message  RpcChallengeAsk
      {
        optional int32 Layer = 1[default=1];
      }
      message  RpcChallengeReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 DungeonId = 2[default=-1];
        optional int32 SceneId = 3[default=-1];
        optional int32 WayPoint = 4[default=-1];
      }
      message  RpcRankAsk
      {
      }
      message  RpcRankReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcFirstVicRewardAsk
      {
        optional int32 Layer = 1[default=-1];
      }
      message  RpcFirstVicRewardReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcNextLayerNotify
      {
      }
      message  RpcChallengeEndNotify
      {
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    OpenRuleNotifyPB = Proto.build("RpcOpenRuleNotify")
    mLayerMgr.registerNotify(RPC_CODE_OPENRULE_NOTIFY,@OpenRuleCB)
    EnterAskPB = Proto.build("RpcEnterAsk")
    EnterReplyPB = Proto.build("RpcEnterReply")
    ChallengeAskPB = Proto.build("RpcChallengeAsk")
    ChallengeReplyPB = Proto.build("RpcChallengeReply")
    RankAskPB = Proto.build("RpcRankAsk")
    RankReplyPB = Proto.build("RpcRankReply")
    FirstVicRewardAskPB = Proto.build("RpcFirstVicRewardAsk")
    FirstVicRewardReplyPB = Proto.build("RpcFirstVicRewardReply")
    NextLayerNotifyPB = Proto.build("RpcNextLayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEXTLAYER_NOTIFY,@NextLayerCB)
    ChallengeEndNotifyPB = Proto.build("RpcChallengeEndNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHALLENGEEND_NOTIFY,@ChallengeEndCB)






  Enter : (replyCB) ->
    EnterAsk = EnterAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ENTER_REQUEST,EnterAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Challenge : (Layer,replyCB) ->
    ChallengeAsk = ChallengeAskPB.prototype
    ChallengeAsk.setLayer Layer
    mLayerMgr.sendAsk(RPC_CODE_CHALLENGE_REQUEST,ChallengeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChallengeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Rank : (replyCB) ->
    RankAsk = RankAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_RANK_REQUEST,RankAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RankReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  FirstVicReward : (Layer,replyCB) ->
    FirstVicRewardAsk = FirstVicRewardAskPB.prototype
    FirstVicRewardAsk.setLayer Layer
    mLayerMgr.sendAsk(RPC_CODE_FIRSTVICREWARD_REQUEST,FirstVicRewardAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( FirstVicRewardReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetOpenRuleNotifyCB : (cb) -> RpcOpenRuleNotifyCB = cb
  OpenRuleCB : (data)->
    RpcOpenRuleNotifyCB( OpenRuleNotifyPB.decode(data)) if typeof(RpcOpenRuleNotifyCB) is "function"
  SetNextLayerNotifyCB : (cb) -> RpcNextLayerNotifyCB = cb
  NextLayerCB : (data)->
    RpcNextLayerNotifyCB( NextLayerNotifyPB.decode(data)) if typeof(RpcNextLayerNotifyCB) is "function"
  SetChallengeEndNotifyCB : (cb) -> RpcChallengeEndNotifyCB = cb
  ChallengeEndCB : (data)->
    RpcChallengeEndNotifyCB( ChallengeEndNotifyPB.decode(data)) if typeof(RpcChallengeEndNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "ClimTowerModel",
      'AskName': ["Enter",
                   "Challenge",
                   "Rank",
                   "FirstVicReward"]
      'ParamterList': [[],
                       ["Layer"],
                       [],
                       ["Layer"]]
      'AskList':[@Enter,
                 @Challenge,
                 @Rank,
                 @FirstVicReward]
      'ParamterTypelist': [[],
                       ["int32"],
                       [],
                       ["int32"]]


module.exports =(()->
  if not ClimTower?
    ClimTower = new ClimTowerModel()
  ClimTower)()



  

  

  


