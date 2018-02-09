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

class FightModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcUseSkillActionNotify
      {
        optional sint32 ObjId = 8[default=-1];
        optional sint32 ObjTargetId = 9[default=-1];
        optional sint32 SkillId = 10[default=-1];
        optional float CastingDir = 11;
        optional float X = 12;
        optional float Y = 13;
        optional float Z = 14;
      }
      message  RpcShowExpActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 Value = 2[default=-1];
      }
      message  RpcBuffActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 TargetId = 2[default=-1];
        optional sint32 OpType = 3[default=-1];
        optional sint32 BufId = 4[default=-1];
        optional sint32 RemainTime = 5[default=-1];
        optional sint32 BuffLv = 6[default=-1];
        optional sint32 Sn = 7[default=-1];
      }
      message  V3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcStateActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 Type = 2[default=-1];
        optional V3 Pos = 3;
        optional sint32 TargetPos = 4[default=-1];
      }
      message  RpcReviveActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional V3 Pos = 2;
        optional sint32 CurHp = 3[default=-1];
      }
      message  RpcComboSkillActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 SkillId = 2[default=-1];
      }
      message  RpcDropActionNotify
      {
      }
      message  RpcUseItemActionNotify
      {
      }
      message  RpcHpChangeActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 CurHp = 2[default=-1];
        optional sint32 MaxHp = 3[default=-1];
      }
      message  RpcUseSkillAsk
      {
        optional sint32 ObjTargetId = 1[default=-1];
        optional sint32 SkillId = 2[default=-1];
        optional float CastingDir = 3;
        optional float X = 4;
        optional float Y = 5;
        optional float Z = 6;
      }
      message  RpcUseSkillReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcHurtActionNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 SegmentIndex = 2[default=-1];
        optional sint32 SkillId = 3[default=-1];
        optional sint32 TargetObjId = 4[default=-1];
        optional sint32 HurtValue = 5[default=0];
        optional sint32 Critical = 6[default=-1];
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






  UseSkill : (ObjTargetId,SkillId,CastingDir,X,Y,Z,replyCB) ->
    UseSkillAsk = UseSkillAskPB.prototype
    UseSkillAsk.setObjTargetId ObjTargetId
    UseSkillAsk.setSkillId SkillId
    UseSkillAsk.setCastingDir CastingDir
    UseSkillAsk.setX X
    UseSkillAsk.setY Y
    UseSkillAsk.setZ Z
    mLayerMgr.sendAsk(RPC_CODE_USESKILL_REQUEST,UseSkillAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UseSkillReplyPB.decode(data)) if typeof(replyCB) is "function"
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


  GetCoffeeInfo: ->
      'CoffeeName': "FightModel",
      'AskName': ["UseSkill"]
      'ParamterList': [["ObjTargetId","SkillId","CastingDir","X","Y","Z"]]
      'AskList':[@UseSkill]
      'ParamterTypelist': [["sint32","sint32","float","float","float","float"]]


module.exports =(()->
  if not Fight?
    Fight = new FightModel()
  Fight)()



  

  

  


