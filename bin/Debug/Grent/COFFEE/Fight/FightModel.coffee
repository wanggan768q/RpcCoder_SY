ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcUseSkillActionNotifyCB = null
RpcShowExpActionNotifyCB = null
RpcBuffActionNotifyCB = null
RpcStateActionNotifyCB = null
RpcReviveActionNotifyCB = null
RpcComboSkillActionNotifyCB = null
RpcDropActionNotifyCB = null
RpcUseItemActionNotifyCB = null
RpcHpChangeActionNotifyCB = null
RpcHurtActionNotifyCB = null
RpcRepelActionNotifyCB = null
RpcObjDeadActionNotifyCB = null
RpcFightTipsNotifyCB = null
RpcBuffListNotifyCB = null
RpcReduceCDNotifyCB = null
RpcReliveNotifyNotifyCB = null
RpcSkillCDNotifyCB = null
RpcAutoCombatMonsterNotifyCB = null
RpcTranslateActionNotifyCB = null
RpcCantAddBuffTipNotifyCB = null
RpcAttackWarningNotifyCB = null
RpcInterruptActionNotifyCB = null
RpcSkillPrepareActionNotifyCB = null
RpcChainMagicJumpNotifyCB = null
RpcBlackHoleActionNotifyCB = null
RpcLoopActionCancelOtherNotifyCB = null
RpcSkillListNotifyCB = null
RpcRemoveModifySkillNotifyCB = null
RpcLinkMagicActionNotifyCB = null


ModuleId = 9
RPC_CODE_USESKILLACTION_NOTIFY = 951
RPC_CODE_SHOWEXPACTION_NOTIFY = 952
RPC_CODE_BUFFACTION_NOTIFY = 953
RPC_CODE_STATEACTION_NOTIFY = 954
RPC_CODE_REVIVEACTION_NOTIFY = 955
RPC_CODE_COMBOSKILLACTION_NOTIFY = 956
RPC_CODE_DROPACTION_NOTIFY = 957
RPC_CODE_USEITEMACTION_NOTIFY = 958
RPC_CODE_HPCHANGEACTION_NOTIFY = 959
RPC_CODE_USESKILL_REQUEST = 960
RPC_CODE_HURTACTION_NOTIFY = 961
RPC_CODE_REPELACTION_NOTIFY = 962
RPC_CODE_OBJDEADACTION_NOTIFY = 963
RPC_CODE_FIGHTTIPS_NOTIFY = 964
RPC_CODE_BUFFLIST_NOTIFY = 965
RPC_CODE_REDUCECD_NOTIFY = 966
RPC_CODE_RELIVENOTIFY_NOTIFY = 967
RPC_CODE_SKILLCD_NOTIFY = 968
RPC_CODE_AUTOCOMBATMONSTER_NOTIFY = 969
RPC_CODE_TRANSLATEACTION_NOTIFY = 970
RPC_CODE_CANTADDBUFFTIP_NOTIFY = 971
RPC_CODE_ATTACKWARNING_NOTIFY = 972
RPC_CODE_INTERRUPTACTION_NOTIFY = 973
RPC_CODE_SKILLPREPARE_REQUEST = 974
RPC_CODE_SKILLPREPAREACTION_NOTIFY = 975
RPC_CODE_CHAINMAGICJUMP_NOTIFY = 976
RPC_CODE_BLACKHOLEACTION_NOTIFY = 977
RPC_CODE_LOOPACTIONCANCEL_REQUEST = 978
RPC_CODE_LOOPACTIONCANCELOTHER_NOTIFY = 979
RPC_CODE_SKILLLIST_NOTIFY = 980
RPC_CODE_USEPETSKILL_REQUEST = 981
RPC_CODE_REMOVEMODIFYSKILL_NOTIFY = 982
RPC_CODE_LINKMAGICACTION_NOTIFY = 983
RPC_CODE_MONSTERINTERACT_REQUEST = 984

UseSkillActionNotifyPB = null
ShowExpActionNotifyPB = null
BuffActionNotifyPB = null
StateActionNotifyPB = null
ReviveActionNotifyPB = null
ComboSkillActionNotifyPB = null
DropActionNotifyPB = null
UseItemActionNotifyPB = null
HpChangeActionNotifyPB = null
UseSkillAskPB = null
UseSkillReplyPB = null
HurtActionNotifyPB = null
RepelActionNotifyPB = null
ObjDeadActionNotifyPB = null
FightTipsNotifyPB = null
BuffListNotifyPB = null
ReduceCDNotifyPB = null
ReliveNotifyNotifyPB = null
SkillCDNotifyPB = null
AutoCombatMonsterNotifyPB = null
TranslateActionNotifyPB = null
CantAddBuffTipNotifyPB = null
AttackWarningNotifyPB = null
InterruptActionNotifyPB = null
SkillPrepareAskPB = null
SkillPrepareReplyPB = null
SkillPrepareActionNotifyPB = null
ChainMagicJumpNotifyPB = null
BlackHoleActionNotifyPB = null
LoopActionCancelAskPB = null
LoopActionCancelReplyPB = null
LoopActionCancelOtherNotifyPB = null
SkillListNotifyPB = null
UsePetSkillAskPB = null
UsePetSkillReplyPB = null
RemoveModifySkillNotifyPB = null
LinkMagicActionNotifyPB = null
MonsterInteractAskPB = null
MonsterInteractReplyPB = null

class FightModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  CustomSkiData
      {
        optional string Key = 2;
        optional int32 KeyType = 3[default=-1];
        optional int32 IntV = 4[default=0];
        optional bool BoolV = 5;
      }
      message  RpcUseSkillActionNotify
      {
        optional uint64 ObjId = 8[default=0];
        optional uint64 ObjTargetId = 9[default=0];
        optional int32 SkillId = 10[default=-1];
        optional float CastingDir = 11;
        optional float X = 12;
        optional float Y = 13;
        optional float Z = 14;
        optional int32 MomentIndex = 15[default=-1];
        optional CustomSkiData CustomSkiData = 16;
      }
      message  RpcShowExpActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 Value = 2[default=-1];
      }
      message  BuffInfo
      {
        optional uint64 ObjId = 5[default=0];
        optional uint64 CasterId = 6[default=0];
        optional int32 OpType = 7[default=-1];
        optional int32 BufId = 8[default=-1];
        optional int32 RemainTime = 9[default=-1];
        optional int32 BuffLv = 10[default=-1];
        optional int32 Sn = 11[default=-1];
        optional int32 LayerCount = 12[default=0];
      }
      message  RpcBuffActionNotify
      {
        optional BuffInfo Info = 8;
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcStateActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 Type = 2[default=-1];
        optional Vector3 Pos = 3;
        optional int32 TargetPos = 4[default=-1];
        optional int32 State = 5[default=-1];
      }
      message  RpcReviveActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional Vector3 Pos = 2;
        optional int32 CurHp = 3[default=-1];
      }
      message  RpcComboSkillActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 SkillId = 2[default=-1];
      }
      message  RpcDropActionNotify
      {
      }
      message  RpcUseItemActionNotify
      {
      }
      message  RpcHpChangeActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 IncrementHp = 2[default=0];
        optional uint64 CasterId = 6[default=0];
      }
      message  Vector3Int
      {
        optional int32 X = 1[default=-1];
        optional int32 Z = 2[default=-1];
      }
      message  RpcUseSkillAsk
      {
        repeated uint64 ObjTargetId = 1;
        optional int32 SkillId = 2[default=-1];
        optional float CastingDir = 3;
        optional float X = 4;
        optional float Y = 5;
        optional float Z = 6;
        optional int32 MomentIndex = 7[default=-1];
        optional CustomSkiData CustomSkiData = 9;
        optional Vector3Int CurrentPos = 10;
      }
      message  RpcUseSkillReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcHurtActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 SegmentIndex = 2[default=-1];
        optional int32 SkillId = 3[default=-1];
        optional uint64 TargetObjId = 4[default=0];
        optional int32 HurtValue = 5[default=0];
        optional bool IsCritical = 6;
        optional bool IsDodge = 8;
        optional bool IsMiss = 9;
        optional bool IsHurtState = 10;
        optional int32 AttackId = 11[default=-1];
        optional bool IsDead = 12;
      }
      message  RpcRepelActionNotify
      {
        optional uint64 ObjId = 5[default=0];
        optional int32 SegmentIndex = 6[default=-1];
        optional int32 SkillId = 8[default=-1];
        optional uint64 TargetObjId = 9[default=0];
        optional Vector3 SkiTargetPos = 10;
        optional bool IsPlayerDiaup = 11;
        optional float Speed = 12;
      }
      message  RpcObjDeadActionNotify
      {
        optional uint64 ObjId = 1[default=0];
      }
      message  RpcFightTipsNotify
      {
        optional int32 TipsID = 1[default=-1];
        optional int32 Durtion = 2[default=-1];
        optional int32 TypeID = 3[default=-1];
      }
      message  RpcBuffListNotify
      {
        repeated BuffInfo BuffList = 1;
      }
      message  RpcReduceCDNotify
      {
        optional int32 SkillId = 1[default=-1];
        optional int32 ModTime = 2[default=-1];
      }
      message  RpcReliveNotifyNotify
      {
        optional uint64 ObjId = 2[default=0];
      }
      message  SkillCDInfo
      {
        optional int32 SkillId = 1[default=-1];
        optional int32 SurplusTime = 2[default=-1];
        optional int32 CommonSurplusTime = 3[default=-1];
      }
      message  RpcSkillCDNotify
      {
        repeated SkillCDInfo SkillCDInfo = 1;
      }
      message  RpcAutoCombatMonsterNotify
      {
        optional uint64 MonsterGuid = 1[default=0];
      }
      message  RpcTranslateActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional Vector3 TargetPos = 2;
        optional float Dir = 3;
        optional int32 SkillId = 4[default=-1];
        optional int32 CommandIndex = 5[default=-1];
        optional bool IsEnd = 6;
        optional float Speed = 7;
      }
      message  RpcCantAddBuffTipNotify
      {
        optional int32 BuffId = 1[default=-1];
        optional uint64 CasterId = 2[default=0];
        optional uint64 ObjId = 3[default=0];
        optional int32 Sn = 4[default=-1];
      }
      message  RpcAttackWarningNotify
      {
        optional int32 AttackId = 1[default=-1];
        optional uint64 Caster = 2[default=0];
        repeated uint64 TargetList = 3;
        optional Vector3 TargetPos = 4;
        optional int32 SkillId = 5[default=-1];
      }
      message  RpcInterruptActionNotify
      {
        optional uint64 Caster = 1[default=0];
        optional uint64 Interrupter = 2[default=0];
        repeated int32 Skill = 3;
      }
      message  RpcSkillPrepareAsk
      {
        optional int32 SkillId = 1[default=-1];
        optional int32 Type = 2[default=0];
      }
      message  RpcSkillPrepareReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcSkillPrepareActionNotify
      {
        optional int64 ObjId = 1[default=-1];
        optional int32 SkillId = 2[default=-1];
        optional int32 Type = 3[default=-1];
      }
      message  RpcChainMagicJumpNotify
      {
        optional int64 ObjId = 1[default=-1];
        optional int32 SkillId = 2[default=-1];
        optional int64 JumpFromObjId = 3[default=-1];
        optional int64 JumpToObjId = 4[default=-1];
        optional int32 AttackId = 5[default=-1];
      }
      message  RpcBlackHoleActionNotify
      {
        optional int64 ObjId = 1[default=-1];
        optional float ToX = 2;
        optional float ToZ = 3;
        optional float Speed = 4;
        optional bool Apply = 7;
        optional int32 Type = 8[default=-1];
        optional uint64 TargetObjId = 9[default=0];
      }
      message  RpcLoopActionCancelAsk
      {
        optional int32 SkillId = 1[default=-1];
      }
      message  RpcLoopActionCancelReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcLoopActionCancelOtherNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional int32 SkillId = 2[default=-1];
      }
      message  RpcSkillListNotify
      {
        repeated int32 SkillList = 1;
      }
      message  RpcUsePetSkillAsk
      {
        repeated uint64 ObjTargetId = 1;
        optional int32 SkillId = 2[default=-1];
        optional float CastingDir = 3;
        optional Vector3Int CurrentPos = 8;
        optional Vector3Int TargetPos = 9;
      }
      message  RpcUsePetSkillReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcRemoveModifySkillNotify
      {
      }
      message  RpcLinkMagicActionNotify
      {
        optional uint64 ObjId = 1[default=0];
        optional uint64 LinkerId = 2[default=0];
        optional int32 AttackId = 3[default=-1];
      }
      message  RpcMonsterInteractAsk
      {
        optional uint64 TargetId = 1[default=0];
      }
      message  RpcMonsterInteractReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    UseSkillActionNotifyPB = Proto.build("RpcUseSkillActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_USESKILLACTION_NOTIFY,@UseSkillActionCB)
    ShowExpActionNotifyPB = Proto.build("RpcShowExpActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_SHOWEXPACTION_NOTIFY,@ShowExpActionCB)
    BuffActionNotifyPB = Proto.build("RpcBuffActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_BUFFACTION_NOTIFY,@BuffActionCB)
    StateActionNotifyPB = Proto.build("RpcStateActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_STATEACTION_NOTIFY,@StateActionCB)
    ReviveActionNotifyPB = Proto.build("RpcReviveActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_REVIVEACTION_NOTIFY,@ReviveActionCB)
    ComboSkillActionNotifyPB = Proto.build("RpcComboSkillActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_COMBOSKILLACTION_NOTIFY,@ComboSkillActionCB)
    DropActionNotifyPB = Proto.build("RpcDropActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_DROPACTION_NOTIFY,@DropActionCB)
    UseItemActionNotifyPB = Proto.build("RpcUseItemActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_USEITEMACTION_NOTIFY,@UseItemActionCB)
    HpChangeActionNotifyPB = Proto.build("RpcHpChangeActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_HPCHANGEACTION_NOTIFY,@HpChangeActionCB)
    UseSkillAskPB = Proto.build("RpcUseSkillAsk")
    UseSkillReplyPB = Proto.build("RpcUseSkillReply")
    HurtActionNotifyPB = Proto.build("RpcHurtActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_HURTACTION_NOTIFY,@HurtActionCB)
    RepelActionNotifyPB = Proto.build("RpcRepelActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_REPELACTION_NOTIFY,@RepelActionCB)
    ObjDeadActionNotifyPB = Proto.build("RpcObjDeadActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_OBJDEADACTION_NOTIFY,@ObjDeadActionCB)
    FightTipsNotifyPB = Proto.build("RpcFightTipsNotify")
    mLayerMgr.registerNotify(RPC_CODE_FIGHTTIPS_NOTIFY,@FightTipsCB)
    BuffListNotifyPB = Proto.build("RpcBuffListNotify")
    mLayerMgr.registerNotify(RPC_CODE_BUFFLIST_NOTIFY,@BuffListCB)
    ReduceCDNotifyPB = Proto.build("RpcReduceCDNotify")
    mLayerMgr.registerNotify(RPC_CODE_REDUCECD_NOTIFY,@ReduceCDCB)
    ReliveNotifyNotifyPB = Proto.build("RpcReliveNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_RELIVENOTIFY_NOTIFY,@ReliveNotifyCB)
    SkillCDNotifyPB = Proto.build("RpcSkillCDNotify")
    mLayerMgr.registerNotify(RPC_CODE_SKILLCD_NOTIFY,@SkillCDCB)
    AutoCombatMonsterNotifyPB = Proto.build("RpcAutoCombatMonsterNotify")
    mLayerMgr.registerNotify(RPC_CODE_AUTOCOMBATMONSTER_NOTIFY,@AutoCombatMonsterCB)
    TranslateActionNotifyPB = Proto.build("RpcTranslateActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_TRANSLATEACTION_NOTIFY,@TranslateActionCB)
    CantAddBuffTipNotifyPB = Proto.build("RpcCantAddBuffTipNotify")
    mLayerMgr.registerNotify(RPC_CODE_CANTADDBUFFTIP_NOTIFY,@CantAddBuffTipCB)
    AttackWarningNotifyPB = Proto.build("RpcAttackWarningNotify")
    mLayerMgr.registerNotify(RPC_CODE_ATTACKWARNING_NOTIFY,@AttackWarningCB)
    InterruptActionNotifyPB = Proto.build("RpcInterruptActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_INTERRUPTACTION_NOTIFY,@InterruptActionCB)
    SkillPrepareAskPB = Proto.build("RpcSkillPrepareAsk")
    SkillPrepareReplyPB = Proto.build("RpcSkillPrepareReply")
    SkillPrepareActionNotifyPB = Proto.build("RpcSkillPrepareActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_SKILLPREPAREACTION_NOTIFY,@SkillPrepareActionCB)
    ChainMagicJumpNotifyPB = Proto.build("RpcChainMagicJumpNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHAINMAGICJUMP_NOTIFY,@ChainMagicJumpCB)
    BlackHoleActionNotifyPB = Proto.build("RpcBlackHoleActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_BLACKHOLEACTION_NOTIFY,@BlackHoleActionCB)
    LoopActionCancelAskPB = Proto.build("RpcLoopActionCancelAsk")
    LoopActionCancelReplyPB = Proto.build("RpcLoopActionCancelReply")
    LoopActionCancelOtherNotifyPB = Proto.build("RpcLoopActionCancelOtherNotify")
    mLayerMgr.registerNotify(RPC_CODE_LOOPACTIONCANCELOTHER_NOTIFY,@LoopActionCancelOtherCB)
    SkillListNotifyPB = Proto.build("RpcSkillListNotify")
    mLayerMgr.registerNotify(RPC_CODE_SKILLLIST_NOTIFY,@SkillListCB)
    UsePetSkillAskPB = Proto.build("RpcUsePetSkillAsk")
    UsePetSkillReplyPB = Proto.build("RpcUsePetSkillReply")
    RemoveModifySkillNotifyPB = Proto.build("RpcRemoveModifySkillNotify")
    mLayerMgr.registerNotify(RPC_CODE_REMOVEMODIFYSKILL_NOTIFY,@RemoveModifySkillCB)
    LinkMagicActionNotifyPB = Proto.build("RpcLinkMagicActionNotify")
    mLayerMgr.registerNotify(RPC_CODE_LINKMAGICACTION_NOTIFY,@LinkMagicActionCB)
    MonsterInteractAskPB = Proto.build("RpcMonsterInteractAsk")
    MonsterInteractReplyPB = Proto.build("RpcMonsterInteractReply")






  UseSkill : (ObjTargetId,SkillId,CastingDir,X,Y,Z,MomentIndex,CustomSkiData,CurrentPos,replyCB) ->
    UseSkillAsk = UseSkillAskPB.prototype
    UseSkillAsk.setObjTargetId ObjTargetId
    UseSkillAsk.setSkillId SkillId
    UseSkillAsk.setCastingDir CastingDir
    UseSkillAsk.setX X
    UseSkillAsk.setY Y
    UseSkillAsk.setZ Z
    UseSkillAsk.setMomentIndex MomentIndex
    UseSkillAsk.setCustomSkiData CustomSkiData
    UseSkillAsk.setCurrentPos CurrentPos
    mLayerMgr.sendAsk(RPC_CODE_USESKILL_REQUEST,UseSkillAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UseSkillReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SkillPrepare : (SkillId,Type,replyCB) ->
    SkillPrepareAsk = SkillPrepareAskPB.prototype
    SkillPrepareAsk.setSkillId SkillId
    SkillPrepareAsk.setType Type
    mLayerMgr.sendAsk(RPC_CODE_SKILLPREPARE_REQUEST,SkillPrepareAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SkillPrepareReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LoopActionCancel : (SkillId,replyCB) ->
    LoopActionCancelAsk = LoopActionCancelAskPB.prototype
    LoopActionCancelAsk.setSkillId SkillId
    mLayerMgr.sendAsk(RPC_CODE_LOOPACTIONCANCEL_REQUEST,LoopActionCancelAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoopActionCancelReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UsePetSkill : (ObjTargetId,SkillId,CastingDir,CurrentPos,TargetPos,replyCB) ->
    UsePetSkillAsk = UsePetSkillAskPB.prototype
    UsePetSkillAsk.setObjTargetId ObjTargetId
    UsePetSkillAsk.setSkillId SkillId
    UsePetSkillAsk.setCastingDir CastingDir
    UsePetSkillAsk.setCurrentPos CurrentPos
    UsePetSkillAsk.setTargetPos TargetPos
    mLayerMgr.sendAsk(RPC_CODE_USEPETSKILL_REQUEST,UsePetSkillAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UsePetSkillReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MonsterInteract : (TargetId,replyCB) ->
    MonsterInteractAsk = MonsterInteractAskPB.prototype
    MonsterInteractAsk.setTargetId TargetId
    mLayerMgr.sendAsk(RPC_CODE_MONSTERINTERACT_REQUEST,MonsterInteractAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MonsterInteractReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetUseSkillActionNotifyCB : (cb) -> RpcUseSkillActionNotifyCB = cb
  UseSkillActionCB : (data)->
    RpcUseSkillActionNotifyCB( UseSkillActionNotifyPB.decode(data)) if typeof(RpcUseSkillActionNotifyCB) is "function"
  SetShowExpActionNotifyCB : (cb) -> RpcShowExpActionNotifyCB = cb
  ShowExpActionCB : (data)->
    RpcShowExpActionNotifyCB( ShowExpActionNotifyPB.decode(data)) if typeof(RpcShowExpActionNotifyCB) is "function"
  SetBuffActionNotifyCB : (cb) -> RpcBuffActionNotifyCB = cb
  BuffActionCB : (data)->
    RpcBuffActionNotifyCB( BuffActionNotifyPB.decode(data)) if typeof(RpcBuffActionNotifyCB) is "function"
  SetStateActionNotifyCB : (cb) -> RpcStateActionNotifyCB = cb
  StateActionCB : (data)->
    RpcStateActionNotifyCB( StateActionNotifyPB.decode(data)) if typeof(RpcStateActionNotifyCB) is "function"
  SetReviveActionNotifyCB : (cb) -> RpcReviveActionNotifyCB = cb
  ReviveActionCB : (data)->
    RpcReviveActionNotifyCB( ReviveActionNotifyPB.decode(data)) if typeof(RpcReviveActionNotifyCB) is "function"
  SetComboSkillActionNotifyCB : (cb) -> RpcComboSkillActionNotifyCB = cb
  ComboSkillActionCB : (data)->
    RpcComboSkillActionNotifyCB( ComboSkillActionNotifyPB.decode(data)) if typeof(RpcComboSkillActionNotifyCB) is "function"
  SetDropActionNotifyCB : (cb) -> RpcDropActionNotifyCB = cb
  DropActionCB : (data)->
    RpcDropActionNotifyCB( DropActionNotifyPB.decode(data)) if typeof(RpcDropActionNotifyCB) is "function"
  SetUseItemActionNotifyCB : (cb) -> RpcUseItemActionNotifyCB = cb
  UseItemActionCB : (data)->
    RpcUseItemActionNotifyCB( UseItemActionNotifyPB.decode(data)) if typeof(RpcUseItemActionNotifyCB) is "function"
  SetHpChangeActionNotifyCB : (cb) -> RpcHpChangeActionNotifyCB = cb
  HpChangeActionCB : (data)->
    RpcHpChangeActionNotifyCB( HpChangeActionNotifyPB.decode(data)) if typeof(RpcHpChangeActionNotifyCB) is "function"
  SetHurtActionNotifyCB : (cb) -> RpcHurtActionNotifyCB = cb
  HurtActionCB : (data)->
    RpcHurtActionNotifyCB( HurtActionNotifyPB.decode(data)) if typeof(RpcHurtActionNotifyCB) is "function"
  SetRepelActionNotifyCB : (cb) -> RpcRepelActionNotifyCB = cb
  RepelActionCB : (data)->
    RpcRepelActionNotifyCB( RepelActionNotifyPB.decode(data)) if typeof(RpcRepelActionNotifyCB) is "function"
  SetObjDeadActionNotifyCB : (cb) -> RpcObjDeadActionNotifyCB = cb
  ObjDeadActionCB : (data)->
    RpcObjDeadActionNotifyCB( ObjDeadActionNotifyPB.decode(data)) if typeof(RpcObjDeadActionNotifyCB) is "function"
  SetFightTipsNotifyCB : (cb) -> RpcFightTipsNotifyCB = cb
  FightTipsCB : (data)->
    RpcFightTipsNotifyCB( FightTipsNotifyPB.decode(data)) if typeof(RpcFightTipsNotifyCB) is "function"
  SetBuffListNotifyCB : (cb) -> RpcBuffListNotifyCB = cb
  BuffListCB : (data)->
    RpcBuffListNotifyCB( BuffListNotifyPB.decode(data)) if typeof(RpcBuffListNotifyCB) is "function"
  SetReduceCDNotifyCB : (cb) -> RpcReduceCDNotifyCB = cb
  ReduceCDCB : (data)->
    RpcReduceCDNotifyCB( ReduceCDNotifyPB.decode(data)) if typeof(RpcReduceCDNotifyCB) is "function"
  SetReliveNotifyNotifyCB : (cb) -> RpcReliveNotifyNotifyCB = cb
  ReliveNotifyCB : (data)->
    RpcReliveNotifyNotifyCB( ReliveNotifyNotifyPB.decode(data)) if typeof(RpcReliveNotifyNotifyCB) is "function"
  SetSkillCDNotifyCB : (cb) -> RpcSkillCDNotifyCB = cb
  SkillCDCB : (data)->
    RpcSkillCDNotifyCB( SkillCDNotifyPB.decode(data)) if typeof(RpcSkillCDNotifyCB) is "function"
  SetAutoCombatMonsterNotifyCB : (cb) -> RpcAutoCombatMonsterNotifyCB = cb
  AutoCombatMonsterCB : (data)->
    RpcAutoCombatMonsterNotifyCB( AutoCombatMonsterNotifyPB.decode(data)) if typeof(RpcAutoCombatMonsterNotifyCB) is "function"
  SetTranslateActionNotifyCB : (cb) -> RpcTranslateActionNotifyCB = cb
  TranslateActionCB : (data)->
    RpcTranslateActionNotifyCB( TranslateActionNotifyPB.decode(data)) if typeof(RpcTranslateActionNotifyCB) is "function"
  SetCantAddBuffTipNotifyCB : (cb) -> RpcCantAddBuffTipNotifyCB = cb
  CantAddBuffTipCB : (data)->
    RpcCantAddBuffTipNotifyCB( CantAddBuffTipNotifyPB.decode(data)) if typeof(RpcCantAddBuffTipNotifyCB) is "function"
  SetAttackWarningNotifyCB : (cb) -> RpcAttackWarningNotifyCB = cb
  AttackWarningCB : (data)->
    RpcAttackWarningNotifyCB( AttackWarningNotifyPB.decode(data)) if typeof(RpcAttackWarningNotifyCB) is "function"
  SetInterruptActionNotifyCB : (cb) -> RpcInterruptActionNotifyCB = cb
  InterruptActionCB : (data)->
    RpcInterruptActionNotifyCB( InterruptActionNotifyPB.decode(data)) if typeof(RpcInterruptActionNotifyCB) is "function"
  SetSkillPrepareActionNotifyCB : (cb) -> RpcSkillPrepareActionNotifyCB = cb
  SkillPrepareActionCB : (data)->
    RpcSkillPrepareActionNotifyCB( SkillPrepareActionNotifyPB.decode(data)) if typeof(RpcSkillPrepareActionNotifyCB) is "function"
  SetChainMagicJumpNotifyCB : (cb) -> RpcChainMagicJumpNotifyCB = cb
  ChainMagicJumpCB : (data)->
    RpcChainMagicJumpNotifyCB( ChainMagicJumpNotifyPB.decode(data)) if typeof(RpcChainMagicJumpNotifyCB) is "function"
  SetBlackHoleActionNotifyCB : (cb) -> RpcBlackHoleActionNotifyCB = cb
  BlackHoleActionCB : (data)->
    RpcBlackHoleActionNotifyCB( BlackHoleActionNotifyPB.decode(data)) if typeof(RpcBlackHoleActionNotifyCB) is "function"
  SetLoopActionCancelOtherNotifyCB : (cb) -> RpcLoopActionCancelOtherNotifyCB = cb
  LoopActionCancelOtherCB : (data)->
    RpcLoopActionCancelOtherNotifyCB( LoopActionCancelOtherNotifyPB.decode(data)) if typeof(RpcLoopActionCancelOtherNotifyCB) is "function"
  SetSkillListNotifyCB : (cb) -> RpcSkillListNotifyCB = cb
  SkillListCB : (data)->
    RpcSkillListNotifyCB( SkillListNotifyPB.decode(data)) if typeof(RpcSkillListNotifyCB) is "function"
  SetRemoveModifySkillNotifyCB : (cb) -> RpcRemoveModifySkillNotifyCB = cb
  RemoveModifySkillCB : (data)->
    RpcRemoveModifySkillNotifyCB( RemoveModifySkillNotifyPB.decode(data)) if typeof(RpcRemoveModifySkillNotifyCB) is "function"
  SetLinkMagicActionNotifyCB : (cb) -> RpcLinkMagicActionNotifyCB = cb
  LinkMagicActionCB : (data)->
    RpcLinkMagicActionNotifyCB( LinkMagicActionNotifyPB.decode(data)) if typeof(RpcLinkMagicActionNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "FightModel",
      'AskName': ["UseSkill",
                   "SkillPrepare",
                   "LoopActionCancel",
                   "UsePetSkill",
                   "MonsterInteract"]
      'ParamterList': [["ObjTargetId","SkillId","CastingDir","X","Y","Z","MomentIndex","CustomSkiData","CurrentPos"],
                       ["SkillId","Type"],
                       ["SkillId"],
                       ["ObjTargetId","SkillId","CastingDir","CurrentPos","TargetPos"],
                       ["TargetId"]]
      'AskList':[@UseSkill,
                 @SkillPrepare,
                 @LoopActionCancel,
                 @UsePetSkill,
                 @MonsterInteract]
      'ParamterTypelist': [["uint64","int32","float","float","float","float","int32","CustomSkiData","Vector3Int"],
                       ["int32","int32"],
                       ["int32"],
                       ["uint64","int32","float","Vector3Int","Vector3Int"],
                       ["uint64"]]


module.exports =(()->
  if not Fight?
    Fight = new FightModel()
  Fight)()



  

  

  


