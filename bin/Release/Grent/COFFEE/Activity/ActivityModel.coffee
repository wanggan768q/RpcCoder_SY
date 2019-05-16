ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcEliteMonsterInfoNotifyCB = null
RpcOpenActivityNotifyCB = null
RpcActivityTimeNotifyCB = null
RpcXingyaoRewardNotifyCB = null
RpcOperationTimeNotifyCB = null


ModuleId = 24
RPC_CODE_ELITEMONSTERINFO_NOTIFY = 2451
RPC_CODE_CREATEOBJ_REQUEST = 2452
RPC_CODE_OPENACTIVITY_NOTIFY = 2453
RPC_CODE_XINGYAO_REQUEST = 2454
RPC_CODE_ACTIVITYTIME_NOTIFY = 2455
RPC_CODE_REQACTIVITYTIME_REQUEST = 2456
RPC_CODE_XINGYAONPC_REQUEST = 2457
RPC_CODE_XINGYAOREWARD_NOTIFY = 2458
RPC_CODE_OPERATIONTIME_NOTIFY = 2459

EliteMonsterInfoNotifyPB = null
CreateObjAskPB = null
CreateObjReplyPB = null
OpenActivityNotifyPB = null
XingyaoAskPB = null
XingyaoReplyPB = null
ActivityTimeNotifyPB = null
ReqActivityTimeAskPB = null
ReqActivityTimeReplyPB = null
XingyaoNPCAskPB = null
XingyaoNPCReplyPB = null
XingyaoRewardNotifyPB = null
OperationTimeNotifyPB = null

class ActivityModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  EliteMonsterInfo
      {
        optional int32 FinishTime = 3[default=-1];
        optional int32 CommonId = 4[default=-1];
      }
      message  RpcEliteMonsterInfoNotify
      {
        optional int32 State = 2[default=-1];
        optional EliteMonsterInfo Info = 3;
      }
      message  RpcCreateObjAsk
      {
        optional int32 CommonId = 1[default=-1];
      }
      message  RpcCreateObjReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcOpenActivityNotify
      {
        optional int32 ActId = 1[default=-1];
        optional int32 DiffTm = 2[default=-1];
        optional int32 SceneId = 3[default=-1];
        optional Vector3 Pos = 4;
      }
      message  RpcXingyaoAsk
      {
        optional int32 NPCid = 1[default=-1];
      }
      message  RpcXingyaoReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  ActivityTime
      {
        optional int64 Begin = 1[default=-1];
        optional int64 End = 2[default=-1];
        optional int32 Id = 3[default=-1];
      }
      message  RpcActivityTimeNotify
      {
        repeated ActivityTime ActTimeList = 1;
      }
      message  RpcReqActivityTimeAsk
      {
      }
      message  RpcReqActivityTimeReply
      {
        optional int32 Result = 1[default=-1];
        repeated ActivityTime ActTimeList = 2;
      }
      message  RpcXingyaoNPCAsk
      {
      }
      message  RpcXingyaoNPCReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 Sceneid = 2[default=-1];
        optional int32 Waypoinid = 3[default=-1];
      }
      message  RpcXingyaoRewardNotify
      {
      }
      message  RpcOperationTimeNotify
      {
        repeated ActivityTime ActTimeList = 1;
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    EliteMonsterInfoNotifyPB = Proto.build("RpcEliteMonsterInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_ELITEMONSTERINFO_NOTIFY,@EliteMonsterInfoCB)
    CreateObjAskPB = Proto.build("RpcCreateObjAsk")
    CreateObjReplyPB = Proto.build("RpcCreateObjReply")
    OpenActivityNotifyPB = Proto.build("RpcOpenActivityNotify")
    mLayerMgr.registerNotify(RPC_CODE_OPENACTIVITY_NOTIFY,@OpenActivityCB)
    XingyaoAskPB = Proto.build("RpcXingyaoAsk")
    XingyaoReplyPB = Proto.build("RpcXingyaoReply")
    ActivityTimeNotifyPB = Proto.build("RpcActivityTimeNotify")
    mLayerMgr.registerNotify(RPC_CODE_ACTIVITYTIME_NOTIFY,@ActivityTimeCB)
    ReqActivityTimeAskPB = Proto.build("RpcReqActivityTimeAsk")
    ReqActivityTimeReplyPB = Proto.build("RpcReqActivityTimeReply")
    XingyaoNPCAskPB = Proto.build("RpcXingyaoNPCAsk")
    XingyaoNPCReplyPB = Proto.build("RpcXingyaoNPCReply")
    XingyaoRewardNotifyPB = Proto.build("RpcXingyaoRewardNotify")
    mLayerMgr.registerNotify(RPC_CODE_XINGYAOREWARD_NOTIFY,@XingyaoRewardCB)
    OperationTimeNotifyPB = Proto.build("RpcOperationTimeNotify")
    mLayerMgr.registerNotify(RPC_CODE_OPERATIONTIME_NOTIFY,@OperationTimeCB)






  CreateObj : (CommonId,replyCB) ->
    CreateObjAsk = CreateObjAskPB.prototype
    CreateObjAsk.setCommonId CommonId
    mLayerMgr.sendAsk(RPC_CODE_CREATEOBJ_REQUEST,CreateObjAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateObjReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Xingyao : (NPCid,replyCB) ->
    XingyaoAsk = XingyaoAskPB.prototype
    XingyaoAsk.setNPCid NPCid
    mLayerMgr.sendAsk(RPC_CODE_XINGYAO_REQUEST,XingyaoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( XingyaoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ReqActivityTime : (replyCB) ->
    ReqActivityTimeAsk = ReqActivityTimeAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_REQACTIVITYTIME_REQUEST,ReqActivityTimeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ReqActivityTimeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  XingyaoNPC : (replyCB) ->
    XingyaoNPCAsk = XingyaoNPCAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_XINGYAONPC_REQUEST,XingyaoNPCAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( XingyaoNPCReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetEliteMonsterInfoNotifyCB : (cb) -> RpcEliteMonsterInfoNotifyCB = cb
  EliteMonsterInfoCB : (data)->
    RpcEliteMonsterInfoNotifyCB( EliteMonsterInfoNotifyPB.decode(data)) if typeof(RpcEliteMonsterInfoNotifyCB) is "function"
  SetOpenActivityNotifyCB : (cb) -> RpcOpenActivityNotifyCB = cb
  OpenActivityCB : (data)->
    RpcOpenActivityNotifyCB( OpenActivityNotifyPB.decode(data)) if typeof(RpcOpenActivityNotifyCB) is "function"
  SetActivityTimeNotifyCB : (cb) -> RpcActivityTimeNotifyCB = cb
  ActivityTimeCB : (data)->
    RpcActivityTimeNotifyCB( ActivityTimeNotifyPB.decode(data)) if typeof(RpcActivityTimeNotifyCB) is "function"
  SetXingyaoRewardNotifyCB : (cb) -> RpcXingyaoRewardNotifyCB = cb
  XingyaoRewardCB : (data)->
    RpcXingyaoRewardNotifyCB( XingyaoRewardNotifyPB.decode(data)) if typeof(RpcXingyaoRewardNotifyCB) is "function"
  SetOperationTimeNotifyCB : (cb) -> RpcOperationTimeNotifyCB = cb
  OperationTimeCB : (data)->
    RpcOperationTimeNotifyCB( OperationTimeNotifyPB.decode(data)) if typeof(RpcOperationTimeNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "ActivityModel",
      'AskName': ["CreateObj",
                   "Xingyao",
                   "ReqActivityTime",
                   "XingyaoNPC"]
      'ParamterList': [["CommonId"],
                       ["NPCid"],
                       [],
                       []]
      'AskList':[@CreateObj,
                 @Xingyao,
                 @ReqActivityTime,
                 @XingyaoNPC]
      'ParamterTypelist': [["int32"],
                       ["int32"],
                       [],
                       []]


module.exports =(()->
  if not Activity?
    Activity = new ActivityModel()
  Activity)()



  

  

  


