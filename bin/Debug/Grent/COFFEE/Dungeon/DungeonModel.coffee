ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcSettlementNotifyCB = null
RpcDungeonDataNotifyCB = null
RpcDungeonTargetNotifyCB = null
RpcTargetContentChangeNotifyCB = null
RpcDungeon_NotifyNotifyCB = null
RpcForceEnterNextDungeonLayerNotifyCB = null
RpcDungeonRewardUpdateNotifyCB = null
RpcVictoryOfAllLayerNotifyCB = null
RpcLayerBeginNotifyCB = null
RpcLayerSettlementNotifyCB = null
RpcSceneOperatorNNotifyCB = null
RpcEnterLayerDungeonNotifyCB = null
RpcDungeonExploitsNotifyCB = null


ModuleId = 6
RPC_CODE_CREATEDUNGEON_REQUEST = 651
RPC_CODE_EXITDUNGEON_REQUEST = 652
RPC_CODE_ENTERDUNGEON_REQUEST = 653
RPC_CODE_INFORMCREATEDUNGEON_REQUEST = 654
RPC_CODE_SETTLEMENT_NOTIFY = 655
RPC_CODE_DUNGEONDATA_NOTIFY = 656
RPC_CODE_DUNGEONSYNC_REQUEST = 657
RPC_CODE_DUNGEONLISTINFO_REQUEST = 658
RPC_CODE_CREATETUTORIAL_REQUEST = 659
RPC_CODE_QUITTUTORIAL_REQUEST = 660
RPC_CODE_DUNGEONTARGET_NOTIFY = 661
RPC_CODE_TARGETCONTENTCHANGE_NOTIFY = 662
RPC_CODE_DUNGEON_NOTIFY_NOTIFY = 663
RPC_CODE_SCENEOPERATOR1_REQUEST = 664
RPC_CODE_FORCEENTERNEXTDUNGEONLAYER_NOTIFY = 665
RPC_CODE_DUNGEONREWARDUPDATE_NOTIFY = 666
RPC_CODE_VICTORYOFALLLAYER_NOTIFY = 667
RPC_CODE_LAYERBEGIN_NOTIFY = 668
RPC_CODE_LAYERSETTLEMENT_NOTIFY = 669
RPC_CODE_SCENEOPERATORN_NOTIFY = 670
RPC_CODE_ENTERLAYERDUNGEON_NOTIFY = 671
RPC_CODE_DUNGEONEXPLOITS_NOTIFY = 672
RPC_CODE_CREATEDUNGEONWITHROBOT_REQUEST = 673
RPC_CODE_USEBOSSNUM_REQUEST = 674

CreateDungeonAskPB = null
CreateDungeonReplyPB = null
ExitDungeonAskPB = null
ExitDungeonReplyPB = null
EnterDungeonAskPB = null
EnterDungeonReplyPB = null
InformCreateDungeonAskPB = null
InformCreateDungeonReplyPB = null
SettlementNotifyPB = null
DungeonDataNotifyPB = null
DungeonSyncAskPB = null
DungeonSyncReplyPB = null
DungeonListInfoAskPB = null
DungeonListInfoReplyPB = null
CreateTutorialAskPB = null
CreateTutorialReplyPB = null
QuitTutorialAskPB = null
QuitTutorialReplyPB = null
DungeonTargetNotifyPB = null
TargetContentChangeNotifyPB = null
Dungeon_NotifyNotifyPB = null
SceneOperator1AskPB = null
SceneOperator1ReplyPB = null
ForceEnterNextDungeonLayerNotifyPB = null
DungeonRewardUpdateNotifyPB = null
VictoryOfAllLayerNotifyPB = null
LayerBeginNotifyPB = null
LayerSettlementNotifyPB = null
SceneOperatorNNotifyPB = null
EnterLayerDungeonNotifyPB = null
DungeonExploitsNotifyPB = null
CreateDungeonWithRobotAskPB = null
CreateDungeonWithRobotReplyPB = null
UseBossNumAskPB = null
UseBossNumReplyPB = null

class DungeonModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcCreateDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 DungeonConfigId = 2[default=-1];
      }
      message  RpcCreateDungeonReply
      {
        optional int32 Result = 1[default=-9999];
        optional int32 DungeonConfigId = 2[default=-1];
        optional int32 SceneConfigId = 3[default=-1];
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 SceneId = 2[default=-1];
      }
      message  RpcExitDungeonReply
      {
        optional int32 Result = 1[default=-9999];
        optional int32 SceneConfigId = 2[default=-1];
        optional int32 SceneId = 3[default=-1];
      }
      message  RpcEnterDungeonAsk
      {
        optional int32 SceneId = 1[default=-1];
        optional int32 DungeonConfigId = 2[default=-1];
      }
      message  RpcEnterDungeonReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcInformCreateDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 TargetSceneId = 2[default=-1];
        optional int32 DungeonConfigId = 3[default=-1];
        optional int32 CurSceneId = 4[default=-1];
        optional int32 Result = 5[default=-9999];
        repeated uint64 RoleIds = 6;
      }
      message  RpcInformCreateDungeonReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  PlayerRealTimeExploit
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 PlayerLevel = 2[default=0];
        optional string PlayerName = 3;
        optional int32 Occupation = 4[default=0];
        optional int32 ExploitsValue = 5[default=0];
      }
      message  RealTimeExploits
      {
        repeated PlayerRealTimeExploit PlayerList = 1;
        optional int32 ExploitsType = 2[default=0];
      }
      message  DungeonExploits
      {
        repeated RealTimeExploits Exploits = 1;
      }
      message  AttrKeyValue
      {
        optional int32 Key = 1[default=-1];
        optional int64 Value = 2[default=-1];
        optional int32 Quality = 3[default=-1];
        optional int32 Key2 = 4[default=-1];
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
        optional bool Wild = 15;
      }
      message  SoulStoneData
      {
        repeated AttrKeyValue Attr = 1;
        optional int32 SuitId = 2[default=-1];
        optional int32 BattleScore = 3[default=0];
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
        optional SoulStoneData SoulStone = 19;
      }
      message  ItemObj
      {
        optional int32 Pos = 1[default=-1];
        optional ItemData ItemData = 2;
        optional bool RedPoint = 3;
      }
      message  RpcSettlementNotify
      {
        optional int32 SettlementResult = 1[default=-1];
        optional DungeonExploits Exploits = 2;
        optional int32 Exp = 3[default=-1];
        repeated ItemObj UiItemInfoList = 4;
        optional int32 Gold = 5[default=-1];
        optional int32 DungeonPassTime = 6[default=-1];
        optional int64 ForceRetreatSceneTime = 7[default=-1];
        optional int64 RemainTime = 8[default=-1];
        optional int32 Starbattleid = 9[default=-1];
        optional int32 SceneType = 10[default=-1];
      }
      message  DungeonData
      {
        optional int32 DurationMentTime = 2[default=0];
        optional int32 ConclusionTime = 3[default=0];
        optional int32 PrepareTime = 4[default=0];
        optional int32 RewardTime = 7[default=0];
      }
      message  RpcDungeonDataNotify
      {
        optional int32 BeginTime = 1[default=0];
        optional DungeonData Data = 3;
        optional DungeonExploits Exploits = 4;
      }
      message  RpcDungeonSyncAsk
      {
      }
      message  RpcDungeonSyncReply
      {
        optional int32 Result = 1[default=-1];
        optional DungeonData Data = 2;
        optional DungeonExploits Exploits = 3;
      }
      message  RpcDungeonListInfoAsk
      {
      }
      message  DungeonBossInfo
      {
        optional int32 Bossid = 1[default=-1];
        optional int32 Number = 2[default=-1];
        optional int32 Dungeonid = 3[default=-1];
        optional int32 MaxNumber = 4[default=-1];
        optional int32 RefreshType = 5[default=-1];
        optional int32 HoldNum = 6[default=0];
        optional int32 Killed = 7[default=0];
        optional int32 DungeonType = 8[default=-1];
        optional int32 BossIndex = 9[default=-1];
      }
      message  RpcDungeonListInfoReply
      {
        optional int32 Result = 1[default=-1];
        repeated DungeonBossInfo DungeonBossData = 3;
      }
      message  RpcCreateTutorialAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 DungeonConfigId = 2[default=-1];
      }
      message  RpcCreateTutorialReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 DungeonConfigId = 3[default=-1];
        optional int32 SceneConfigId = 4[default=-1];
      }
      message  RpcQuitTutorialAsk
      {
      }
      message  RpcQuitTutorialReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  DungeonTargetContent
      {
        optional int32 Index = 1[default=-1];
        optional int32 TemplateId = 2[default=-1];
        optional int32 MaxCount = 3[default=-1];
        optional int32 CurCount = 4[default=-1];
        optional int32 Description = 5[default=-1];
        optional int32 IParam = 6[default=-1];
      }
      message  DungeonTarget
      {
        optional int32 TypeId = 1[default=-1];
        optional int32 Index = 2[default=-1];
        repeated DungeonTargetContent TargetContent = 3;
        optional int32 Description = 4[default=-1];
        optional int32 IParam = 5[default=-1];
      }
      message  RpcDungeonTargetNotify
      {
        repeated DungeonTarget DungeonTarget = 1;
      }
      message  RpcTargetContentChangeNotify
      {
        optional int32 Index = 1[default=-1];
        optional int32 SubIndex = 2[default=-1];
        optional int32 CurCount = 3[default=-1];
      }
      message  RpcDungeon_NotifyNotify
      {
        optional int32 TextId = 1[default=-1];
      }
      message  RpcSceneOperator1Ask
      {
        optional int32 OpCode = 1[default=0];
        optional int32 OpExtraParam = 2[default=0];
      }
      message  RpcSceneOperator1Reply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcForceEnterNextDungeonLayerNotify
      {
        optional int32 NextLayer = 1[default=1];
        optional bool Breward = 6;
      }
      message  RpcDungeonRewardUpdateNotify
      {
        repeated uint64 OpenRoleIdList = 1;
        optional uint64 NewRoleId = 2[default=0];
        optional int32 NewIndex = 3[default=0];
      }
      message  RpcVictoryOfAllLayerNotify
      {
        optional int32 LastLayer = 1[default=-1];
      }
      message  RpcLayerBeginNotify
      {
      }
      message  PBUIRewardData
      {
        optional int32 ItemId = 1[default=0];
        optional int32 ItemCount = 2[default=0];
        optional uint64 RoleId = 3[default=0];
        optional string PlayerName = 4;
      }
      message  RpcLayerSettlementNotify
      {
        optional int32 NextLayer = 1[default=1];
        repeated PBUIRewardData RewardList = 2;
      }
      message  RpcSceneOperatorNNotify
      {
        optional int32 OpCode = 1[default=0];
      }
      message  RpcEnterLayerDungeonNotify
      {
        optional int32 CurrentLayer = 1[default=-1];
        optional int32 CurentLayerRemainTime = 2[default=-1];
      }
      message  RpcDungeonExploitsNotify
      {
        optional DungeonExploits Exploits = 1;
      }
      message  RpcCreateDungeonWithRobotAsk
      {
        optional int32 DungeonConfigId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcCreateDungeonWithRobotReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcUseBossNumAsk
      {
        optional bool BUse = 1;
      }
      message  RpcUseBossNumReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    CreateDungeonAskPB = Proto.build("RpcCreateDungeonAsk")
    CreateDungeonReplyPB = Proto.build("RpcCreateDungeonReply")
    ExitDungeonAskPB = Proto.build("RpcExitDungeonAsk")
    ExitDungeonReplyPB = Proto.build("RpcExitDungeonReply")
    EnterDungeonAskPB = Proto.build("RpcEnterDungeonAsk")
    EnterDungeonReplyPB = Proto.build("RpcEnterDungeonReply")
    InformCreateDungeonAskPB = Proto.build("RpcInformCreateDungeonAsk")
    InformCreateDungeonReplyPB = Proto.build("RpcInformCreateDungeonReply")
    SettlementNotifyPB = Proto.build("RpcSettlementNotify")
    mLayerMgr.registerNotify(RPC_CODE_SETTLEMENT_NOTIFY,@SettlementCB)
    DungeonDataNotifyPB = Proto.build("RpcDungeonDataNotify")
    mLayerMgr.registerNotify(RPC_CODE_DUNGEONDATA_NOTIFY,@DungeonDataCB)
    DungeonSyncAskPB = Proto.build("RpcDungeonSyncAsk")
    DungeonSyncReplyPB = Proto.build("RpcDungeonSyncReply")
    DungeonListInfoAskPB = Proto.build("RpcDungeonListInfoAsk")
    DungeonListInfoReplyPB = Proto.build("RpcDungeonListInfoReply")
    CreateTutorialAskPB = Proto.build("RpcCreateTutorialAsk")
    CreateTutorialReplyPB = Proto.build("RpcCreateTutorialReply")
    QuitTutorialAskPB = Proto.build("RpcQuitTutorialAsk")
    QuitTutorialReplyPB = Proto.build("RpcQuitTutorialReply")
    DungeonTargetNotifyPB = Proto.build("RpcDungeonTargetNotify")
    mLayerMgr.registerNotify(RPC_CODE_DUNGEONTARGET_NOTIFY,@DungeonTargetCB)
    TargetContentChangeNotifyPB = Proto.build("RpcTargetContentChangeNotify")
    mLayerMgr.registerNotify(RPC_CODE_TARGETCONTENTCHANGE_NOTIFY,@TargetContentChangeCB)
    Dungeon_NotifyNotifyPB = Proto.build("RpcDungeon_NotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_DUNGEON_NOTIFY_NOTIFY,@Dungeon_NotifyCB)
    SceneOperator1AskPB = Proto.build("RpcSceneOperator1Ask")
    SceneOperator1ReplyPB = Proto.build("RpcSceneOperator1Reply")
    ForceEnterNextDungeonLayerNotifyPB = Proto.build("RpcForceEnterNextDungeonLayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_FORCEENTERNEXTDUNGEONLAYER_NOTIFY,@ForceEnterNextDungeonLayerCB)
    DungeonRewardUpdateNotifyPB = Proto.build("RpcDungeonRewardUpdateNotify")
    mLayerMgr.registerNotify(RPC_CODE_DUNGEONREWARDUPDATE_NOTIFY,@DungeonRewardUpdateCB)
    VictoryOfAllLayerNotifyPB = Proto.build("RpcVictoryOfAllLayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_VICTORYOFALLLAYER_NOTIFY,@VictoryOfAllLayerCB)
    LayerBeginNotifyPB = Proto.build("RpcLayerBeginNotify")
    mLayerMgr.registerNotify(RPC_CODE_LAYERBEGIN_NOTIFY,@LayerBeginCB)
    LayerSettlementNotifyPB = Proto.build("RpcLayerSettlementNotify")
    mLayerMgr.registerNotify(RPC_CODE_LAYERSETTLEMENT_NOTIFY,@LayerSettlementCB)
    SceneOperatorNNotifyPB = Proto.build("RpcSceneOperatorNNotify")
    mLayerMgr.registerNotify(RPC_CODE_SCENEOPERATORN_NOTIFY,@SceneOperatorNCB)
    EnterLayerDungeonNotifyPB = Proto.build("RpcEnterLayerDungeonNotify")
    mLayerMgr.registerNotify(RPC_CODE_ENTERLAYERDUNGEON_NOTIFY,@EnterLayerDungeonCB)
    DungeonExploitsNotifyPB = Proto.build("RpcDungeonExploitsNotify")
    mLayerMgr.registerNotify(RPC_CODE_DUNGEONEXPLOITS_NOTIFY,@DungeonExploitsCB)
    CreateDungeonWithRobotAskPB = Proto.build("RpcCreateDungeonWithRobotAsk")
    CreateDungeonWithRobotReplyPB = Proto.build("RpcCreateDungeonWithRobotReply")
    UseBossNumAskPB = Proto.build("RpcUseBossNumAsk")
    UseBossNumReplyPB = Proto.build("RpcUseBossNumReply")






  CreateDungeon : (RoleId,DungeonConfigId,replyCB) ->
    CreateDungeonAsk = CreateDungeonAskPB.prototype
    CreateDungeonAsk.setRoleId RoleId
    CreateDungeonAsk.setDungeonConfigId DungeonConfigId
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEON_REQUEST,CreateDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ExitDungeon : (RoleId,SceneId,replyCB) ->
    ExitDungeonAsk = ExitDungeonAskPB.prototype
    ExitDungeonAsk.setRoleId RoleId
    ExitDungeonAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_EXITDUNGEON_REQUEST,ExitDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ExitDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EnterDungeon : (SceneId,DungeonConfigId,replyCB) ->
    EnterDungeonAsk = EnterDungeonAskPB.prototype
    EnterDungeonAsk.setSceneId SceneId
    EnterDungeonAsk.setDungeonConfigId DungeonConfigId
    mLayerMgr.sendAsk(RPC_CODE_ENTERDUNGEON_REQUEST,EnterDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InformCreateDungeon : (RoleId,TargetSceneId,DungeonConfigId,CurSceneId,Result,RoleIds,replyCB) ->
    InformCreateDungeonAsk = InformCreateDungeonAskPB.prototype
    InformCreateDungeonAsk.setRoleId RoleId
    InformCreateDungeonAsk.setTargetSceneId TargetSceneId
    InformCreateDungeonAsk.setDungeonConfigId DungeonConfigId
    InformCreateDungeonAsk.setCurSceneId CurSceneId
    InformCreateDungeonAsk.setResult Result
    InformCreateDungeonAsk.setRoleIds RoleIds
    mLayerMgr.sendAsk(RPC_CODE_INFORMCREATEDUNGEON_REQUEST,InformCreateDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InformCreateDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DungeonSync : (replyCB) ->
    DungeonSyncAsk = DungeonSyncAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_DUNGEONSYNC_REQUEST,DungeonSyncAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DungeonSyncReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DungeonListInfo : (replyCB) ->
    DungeonListInfoAsk = DungeonListInfoAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_DUNGEONLISTINFO_REQUEST,DungeonListInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DungeonListInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateTutorial : (RoleId,DungeonConfigId,replyCB) ->
    CreateTutorialAsk = CreateTutorialAskPB.prototype
    CreateTutorialAsk.setRoleId RoleId
    CreateTutorialAsk.setDungeonConfigId DungeonConfigId
    mLayerMgr.sendAsk(RPC_CODE_CREATETUTORIAL_REQUEST,CreateTutorialAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateTutorialReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  QuitTutorial : (replyCB) ->
    QuitTutorialAsk = QuitTutorialAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_QUITTUTORIAL_REQUEST,QuitTutorialAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( QuitTutorialReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SceneOperator1 : (OpCode,OpExtraParam,replyCB) ->
    SceneOperator1Ask = SceneOperator1AskPB.prototype
    SceneOperator1Ask.setOpCode OpCode
    SceneOperator1Ask.setOpExtraParam OpExtraParam
    mLayerMgr.sendAsk(RPC_CODE_SCENEOPERATOR1_REQUEST,SceneOperator1Ask, (data)->
      NetTipController.hideNetTip()
      replyCB( SceneOperator1ReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateDungeonWithRobot : (DungeonConfigId,RoleId,replyCB) ->
    CreateDungeonWithRobotAsk = CreateDungeonWithRobotAskPB.prototype
    CreateDungeonWithRobotAsk.setDungeonConfigId DungeonConfigId
    CreateDungeonWithRobotAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEONWITHROBOT_REQUEST,CreateDungeonWithRobotAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonWithRobotReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UseBossNum : (BUse,replyCB) ->
    UseBossNumAsk = UseBossNumAskPB.prototype
    UseBossNumAsk.setBUse BUse
    mLayerMgr.sendAsk(RPC_CODE_USEBOSSNUM_REQUEST,UseBossNumAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UseBossNumReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetSettlementNotifyCB : (cb) -> RpcSettlementNotifyCB = cb
  SettlementCB : (data)->
    RpcSettlementNotifyCB( SettlementNotifyPB.decode(data)) if typeof(RpcSettlementNotifyCB) is "function"
  SetDungeonDataNotifyCB : (cb) -> RpcDungeonDataNotifyCB = cb
  DungeonDataCB : (data)->
    RpcDungeonDataNotifyCB( DungeonDataNotifyPB.decode(data)) if typeof(RpcDungeonDataNotifyCB) is "function"
  SetDungeonTargetNotifyCB : (cb) -> RpcDungeonTargetNotifyCB = cb
  DungeonTargetCB : (data)->
    RpcDungeonTargetNotifyCB( DungeonTargetNotifyPB.decode(data)) if typeof(RpcDungeonTargetNotifyCB) is "function"
  SetTargetContentChangeNotifyCB : (cb) -> RpcTargetContentChangeNotifyCB = cb
  TargetContentChangeCB : (data)->
    RpcTargetContentChangeNotifyCB( TargetContentChangeNotifyPB.decode(data)) if typeof(RpcTargetContentChangeNotifyCB) is "function"
  SetDungeon_NotifyNotifyCB : (cb) -> RpcDungeon_NotifyNotifyCB = cb
  Dungeon_NotifyCB : (data)->
    RpcDungeon_NotifyNotifyCB( Dungeon_NotifyNotifyPB.decode(data)) if typeof(RpcDungeon_NotifyNotifyCB) is "function"
  SetForceEnterNextDungeonLayerNotifyCB : (cb) -> RpcForceEnterNextDungeonLayerNotifyCB = cb
  ForceEnterNextDungeonLayerCB : (data)->
    RpcForceEnterNextDungeonLayerNotifyCB( ForceEnterNextDungeonLayerNotifyPB.decode(data)) if typeof(RpcForceEnterNextDungeonLayerNotifyCB) is "function"
  SetDungeonRewardUpdateNotifyCB : (cb) -> RpcDungeonRewardUpdateNotifyCB = cb
  DungeonRewardUpdateCB : (data)->
    RpcDungeonRewardUpdateNotifyCB( DungeonRewardUpdateNotifyPB.decode(data)) if typeof(RpcDungeonRewardUpdateNotifyCB) is "function"
  SetVictoryOfAllLayerNotifyCB : (cb) -> RpcVictoryOfAllLayerNotifyCB = cb
  VictoryOfAllLayerCB : (data)->
    RpcVictoryOfAllLayerNotifyCB( VictoryOfAllLayerNotifyPB.decode(data)) if typeof(RpcVictoryOfAllLayerNotifyCB) is "function"
  SetLayerBeginNotifyCB : (cb) -> RpcLayerBeginNotifyCB = cb
  LayerBeginCB : (data)->
    RpcLayerBeginNotifyCB( LayerBeginNotifyPB.decode(data)) if typeof(RpcLayerBeginNotifyCB) is "function"
  SetLayerSettlementNotifyCB : (cb) -> RpcLayerSettlementNotifyCB = cb
  LayerSettlementCB : (data)->
    RpcLayerSettlementNotifyCB( LayerSettlementNotifyPB.decode(data)) if typeof(RpcLayerSettlementNotifyCB) is "function"
  SetSceneOperatorNNotifyCB : (cb) -> RpcSceneOperatorNNotifyCB = cb
  SceneOperatorNCB : (data)->
    RpcSceneOperatorNNotifyCB( SceneOperatorNNotifyPB.decode(data)) if typeof(RpcSceneOperatorNNotifyCB) is "function"
  SetEnterLayerDungeonNotifyCB : (cb) -> RpcEnterLayerDungeonNotifyCB = cb
  EnterLayerDungeonCB : (data)->
    RpcEnterLayerDungeonNotifyCB( EnterLayerDungeonNotifyPB.decode(data)) if typeof(RpcEnterLayerDungeonNotifyCB) is "function"
  SetDungeonExploitsNotifyCB : (cb) -> RpcDungeonExploitsNotifyCB = cb
  DungeonExploitsCB : (data)->
    RpcDungeonExploitsNotifyCB( DungeonExploitsNotifyPB.decode(data)) if typeof(RpcDungeonExploitsNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "DungeonModel",
      'AskName': ["CreateDungeon",
                   "ExitDungeon",
                   "EnterDungeon",
                   "InformCreateDungeon",
                   "DungeonSync",
                   "DungeonListInfo",
                   "CreateTutorial",
                   "QuitTutorial",
                   "SceneOperator1",
                   "CreateDungeonWithRobot",
                   "UseBossNum"]
      'ParamterList': [["RoleId","DungeonConfigId"],
                       ["RoleId","SceneId"],
                       ["SceneId","DungeonConfigId"],
                       ["RoleId","TargetSceneId","DungeonConfigId","CurSceneId","Result","RoleIds"],
                       [],
                       [],
                       ["RoleId","DungeonConfigId"],
                       [],
                       ["OpCode","OpExtraParam"],
                       ["DungeonConfigId","RoleId"],
                       ["BUse"]]
      'AskList':[@CreateDungeon,
                 @ExitDungeon,
                 @EnterDungeon,
                 @InformCreateDungeon,
                 @DungeonSync,
                 @DungeonListInfo,
                 @CreateTutorial,
                 @QuitTutorial,
                 @SceneOperator1,
                 @CreateDungeonWithRobot,
                 @UseBossNum]
      'ParamterTypelist': [["uint64","int32"],
                       ["uint64","int32"],
                       ["int32","int32"],
                       ["uint64","int32","int32","int32","int32","uint64"],
                       [],
                       [],
                       ["uint64","int32"],
                       [],
                       ["int32","int32"],
                       ["int32","uint64"],
                       ["bool"]]


module.exports =(()->
  if not Dungeon?
    Dungeon = new DungeonModel()
  Dungeon)()



  

  

  


