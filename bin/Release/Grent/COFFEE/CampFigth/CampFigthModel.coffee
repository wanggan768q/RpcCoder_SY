ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcCampFightContributionNotifyCB = null
RpcObjKillBroadcastNotifyCB = null
RpcNpcBirthNotifyCB = null
RpcKillDeadInfoNotifyCB = null
RpcNewSeasonNotifyCB = null


ModuleId = 26
RPC_CODE_MILITARYBROKEN_REQUEST = 2651
RPC_CODE_CAMPFIGHTCONTRIBUTION_NOTIFY = 2652
RPC_CODE_OBJKILLBROADCAST_NOTIFY = 2653
RPC_CODE_NPCBIRTH_NOTIFY = 2654
RPC_CODE_GETMILITARYVALUE_REQUEST = 2655
RPC_CODE_KILLDEADINFO_NOTIFY = 2656
RPC_CODE_WORSHIP_REQUEST = 2657
RPC_CODE_WORSHIPRANK_REQUEST = 2658
RPC_CODE_NEWSEASON_NOTIFY = 2659
RPC_CODE_SYNCRANKREWARD_REQUEST = 2660
RPC_CODE_GETRANKREWARD_REQUEST = 2661
RPC_CODE_ENTERBATTLESCENE_REQUEST = 2662

MilitaryBrokenAskPB = null
MilitaryBrokenReplyPB = null
CampFightContributionNotifyPB = null
ObjKillBroadcastNotifyPB = null
NpcBirthNotifyPB = null
GetMilitaryValueAskPB = null
GetMilitaryValueReplyPB = null
KillDeadInfoNotifyPB = null
WorshipAskPB = null
WorshipReplyPB = null
WorshipRankAskPB = null
WorshipRankReplyPB = null
NewSeasonNotifyPB = null
SyncRankRewardAskPB = null
SyncRankRewardReplyPB = null
GetRankRewardAskPB = null
GetRankRewardReplyPB = null
EnterBattleSceneAskPB = null
EnterBattleSceneReplyPB = null

class CampFigthModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcMilitaryBrokenAsk
      {
        optional int32 RoleID = 1[default=-1];
      }
      message  RpcMilitaryBrokenReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Rank = 2[default=-1];
        optional int32 Star = 3[default=-1];
        optional int32 Exp = 4[default=-1];
      }
      message  RpcCampFightContributionNotify
      {
        optional int32 Camp = 1[default=-1];
        optional int32 ContributionValue = 2[default=-1];
      }
      message  RpcObjKillBroadcastNotify
      {
        optional int32 KillerObjID = 1[default=-1];
        optional int32 KillerName = 2[default=-1];
        optional int32 DeadObjID = 3[default=-1];
        optional int32 DeadObjResID = 4[default=-1];
      }
      message  RpcNpcBirthNotify
      {
        optional int32 Camp = 1[default=-1];
        optional int32 BirthObjID = 2[default=-1];
        optional int32 BirthObjResID = 3[default=-1];
      }
      message  RpcGetMilitaryValueAsk
      {
        optional int32 RoleID = 1[default=-1];
      }
      message  RpcGetMilitaryValueReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Rank = 2[default=-1];
        optional int32 Star = 3[default=-1];
        optional int32 Exp = 4[default=-1];
        optional int32 Curseason = 5[default=-1];
        optional int32 TodayHornor = 6[default=-1];
      }
      message  RpcKillDeadInfoNotify
      {
        optional int32 KillNum = 1[default=-1];
        optional int32 DeadNum = 2[default=-1];
        optional int32 Rank = 4[default=-1];
        optional int32 Exp = 5[default=-1];
        optional int32 Star = 6[default=-1];
      }
      message  RpcWorshipAsk
      {
        optional int32 WorshipRoleID = 1[default=-1];
      }
      message  RpcWorshipReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 WorshipRoleID = 2[default=-1];
        optional int32 WorshipCount = 3[default=-1];
      }
      message  RpcWorshipRankAsk
      {
        optional int32 RoleID = 1[default=-1];
      }
      message  WorshipPlayerData
      {
        optional int32 Role_id = 1[default=-1];
        optional string Role_name = 2;
        optional int32 Rank_level = 3[default=-1];
        optional int32 Worship_cout = 4[default=-1];
        optional int32 Rank = 5[default=-1];
      }
      message  RpcWorshipRankReply
      {
        optional int32 Result = 1[default=-1];
        repeated WorshipPlayerData RoleDatas = 2;
      }
      message  PvpBattleRewardInfo
      {
        optional int32 ItemID = 1[default=-1];
        optional int32 ItemCout = 2[default=-1];
      }
      message  RpcNewSeasonNotify
      {
        optional int32 Rank = 1[default=-1];
        optional int32 Star = 2[default=-1];
        optional int32 RankIndex = 3[default=-1];
        repeated PvpBattleRewardInfo RewardList = 4;
        optional int32 Lastseason = 5[default=-1];
      }
      message  RpcSyncRankRewardAsk
      {
      }
      message  RpcSyncRankRewardReply
      {
        optional int32 Result = 1[default=-1];
        repeated int32 RankRewardList = 2;
      }
      message  RpcGetRankRewardAsk
      {
        optional int32 Rank = 1[default=-1];
      }
      message  RpcGetRankRewardReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Rank = 3[default=-1];
      }
      message  RpcEnterBattleSceneAsk
      {
      }
      message  RpcEnterBattleSceneReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    MilitaryBrokenAskPB = Proto.build("RpcMilitaryBrokenAsk")
    MilitaryBrokenReplyPB = Proto.build("RpcMilitaryBrokenReply")
    CampFightContributionNotifyPB = Proto.build("RpcCampFightContributionNotify")
    mLayerMgr.registerNotify(RPC_CODE_CAMPFIGHTCONTRIBUTION_NOTIFY,@CampFightContributionCB)
    ObjKillBroadcastNotifyPB = Proto.build("RpcObjKillBroadcastNotify")
    mLayerMgr.registerNotify(RPC_CODE_OBJKILLBROADCAST_NOTIFY,@ObjKillBroadcastCB)
    NpcBirthNotifyPB = Proto.build("RpcNpcBirthNotify")
    mLayerMgr.registerNotify(RPC_CODE_NPCBIRTH_NOTIFY,@NpcBirthCB)
    GetMilitaryValueAskPB = Proto.build("RpcGetMilitaryValueAsk")
    GetMilitaryValueReplyPB = Proto.build("RpcGetMilitaryValueReply")
    KillDeadInfoNotifyPB = Proto.build("RpcKillDeadInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_KILLDEADINFO_NOTIFY,@KillDeadInfoCB)
    WorshipAskPB = Proto.build("RpcWorshipAsk")
    WorshipReplyPB = Proto.build("RpcWorshipReply")
    WorshipRankAskPB = Proto.build("RpcWorshipRankAsk")
    WorshipRankReplyPB = Proto.build("RpcWorshipRankReply")
    NewSeasonNotifyPB = Proto.build("RpcNewSeasonNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWSEASON_NOTIFY,@NewSeasonCB)
    SyncRankRewardAskPB = Proto.build("RpcSyncRankRewardAsk")
    SyncRankRewardReplyPB = Proto.build("RpcSyncRankRewardReply")
    GetRankRewardAskPB = Proto.build("RpcGetRankRewardAsk")
    GetRankRewardReplyPB = Proto.build("RpcGetRankRewardReply")
    EnterBattleSceneAskPB = Proto.build("RpcEnterBattleSceneAsk")
    EnterBattleSceneReplyPB = Proto.build("RpcEnterBattleSceneReply")






  MilitaryBroken : (RoleID,replyCB) ->
    MilitaryBrokenAsk = MilitaryBrokenAskPB.prototype
    MilitaryBrokenAsk.setRoleID RoleID
    mLayerMgr.sendAsk(RPC_CODE_MILITARYBROKEN_REQUEST,MilitaryBrokenAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MilitaryBrokenReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetMilitaryValue : (RoleID,replyCB) ->
    GetMilitaryValueAsk = GetMilitaryValueAskPB.prototype
    GetMilitaryValueAsk.setRoleID RoleID
    mLayerMgr.sendAsk(RPC_CODE_GETMILITARYVALUE_REQUEST,GetMilitaryValueAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetMilitaryValueReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Worship : (WorshipRoleID,replyCB) ->
    WorshipAsk = WorshipAskPB.prototype
    WorshipAsk.setWorshipRoleID WorshipRoleID
    mLayerMgr.sendAsk(RPC_CODE_WORSHIP_REQUEST,WorshipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( WorshipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  WorshipRank : (RoleID,replyCB) ->
    WorshipRankAsk = WorshipRankAskPB.prototype
    WorshipRankAsk.setRoleID RoleID
    mLayerMgr.sendAsk(RPC_CODE_WORSHIPRANK_REQUEST,WorshipRankAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( WorshipRankReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncRankReward : (replyCB) ->
    SyncRankRewardAsk = SyncRankRewardAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCRANKREWARD_REQUEST,SyncRankRewardAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncRankRewardReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetRankReward : (Rank,replyCB) ->
    GetRankRewardAsk = GetRankRewardAskPB.prototype
    GetRankRewardAsk.setRank Rank
    mLayerMgr.sendAsk(RPC_CODE_GETRANKREWARD_REQUEST,GetRankRewardAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetRankRewardReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EnterBattleScene : (replyCB) ->
    EnterBattleSceneAsk = EnterBattleSceneAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ENTERBATTLESCENE_REQUEST,EnterBattleSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterBattleSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetCampFightContributionNotifyCB : (cb) -> RpcCampFightContributionNotifyCB = cb
  CampFightContributionCB : (data)->
    RpcCampFightContributionNotifyCB( CampFightContributionNotifyPB.decode(data)) if typeof(RpcCampFightContributionNotifyCB) is "function"
  SetObjKillBroadcastNotifyCB : (cb) -> RpcObjKillBroadcastNotifyCB = cb
  ObjKillBroadcastCB : (data)->
    RpcObjKillBroadcastNotifyCB( ObjKillBroadcastNotifyPB.decode(data)) if typeof(RpcObjKillBroadcastNotifyCB) is "function"
  SetNpcBirthNotifyCB : (cb) -> RpcNpcBirthNotifyCB = cb
  NpcBirthCB : (data)->
    RpcNpcBirthNotifyCB( NpcBirthNotifyPB.decode(data)) if typeof(RpcNpcBirthNotifyCB) is "function"
  SetKillDeadInfoNotifyCB : (cb) -> RpcKillDeadInfoNotifyCB = cb
  KillDeadInfoCB : (data)->
    RpcKillDeadInfoNotifyCB( KillDeadInfoNotifyPB.decode(data)) if typeof(RpcKillDeadInfoNotifyCB) is "function"
  SetNewSeasonNotifyCB : (cb) -> RpcNewSeasonNotifyCB = cb
  NewSeasonCB : (data)->
    RpcNewSeasonNotifyCB( NewSeasonNotifyPB.decode(data)) if typeof(RpcNewSeasonNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "CampFigthModel",
      'AskName': ["MilitaryBroken",
                   "GetMilitaryValue",
                   "Worship",
                   "WorshipRank",
                   "SyncRankReward",
                   "GetRankReward",
                   "EnterBattleScene"]
      'ParamterList': [["RoleID"],
                       ["RoleID"],
                       ["WorshipRoleID"],
                       ["RoleID"],
                       [],
                       ["Rank"],
                       []]
      'AskList':[@MilitaryBroken,
                 @GetMilitaryValue,
                 @Worship,
                 @WorshipRank,
                 @SyncRankReward,
                 @GetRankReward,
                 @EnterBattleScene]
      'ParamterTypelist': [["int32"],
                       ["int32"],
                       ["int32"],
                       ["int32"],
                       [],
                       ["int32"],
                       []]


module.exports =(()->
  if not CampFigth?
    CampFigth = new CampFigthModel()
  CampFigth)()



  

  

  


