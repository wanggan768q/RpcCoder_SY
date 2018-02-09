ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcDeletePlayerNotifyCB = null
RpcCreateObjNotifyCB = null
RpcCEnterSceneNotifyCB = null
RpcSEnterSceneNotifyCB = null
RpcObjDieNotifyCB = null


ModuleId = 3
RPC_CODE_LOADSCENECOMPLETE_REQUEST = 351
RPC_CODE_DELETEPLAYER_NOTIFY = 352
RPC_CODE_CONNECTGAMESERVER_REQUEST = 353
RPC_CODE_CHANGESCENE_REQUEST = 354
RPC_CODE_CREATEOBJ_NOTIFY = 355
RPC_CODE_SURROUNDINGHUMAN_REQUEST = 356
RPC_CODE_CENTERSCENE_NOTIFY = 357
RPC_CODE_SENTERSCENE_NOTIFY = 358
RPC_CODE_OBJDIE_NOTIFY = 359

LoadSceneCompleteAskPB = null
LoadSceneCompleteReplyPB = null
DeletePlayerNotifyPB = null
ConnectGameServerAskPB = null
ConnectGameServerReplyPB = null
ChangeSceneAskPB = null
ChangeSceneReplyPB = null
CreateObjNotifyPB = null
SurroundingHumanAskPB = null
SurroundingHumanReplyPB = null
CEnterSceneNotifyPB = null
SEnterSceneNotifyPB = null
ObjDieNotifyPB = null

class SceneModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcLoadSceneCompleteAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
      }
      message  CharacterInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional string Nickname = 2;
        optional sint32 ConfigId = 3[default=-1];
        optional sint32 Hp = 4[default=-1];
        optional sint32 HpMax = 5[default=-1];
        optional sint32 Level = 6[default=-1];
      }
      message  V3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcLoadSceneCompleteReply
      {
        optional sint32 Result = 1[default=-9999];
        optional CharacterInfo RoleInfo = 2;
        optional sint32 ObjId = 3[default=-1];
        optional V3 Pos = 4;
        optional float Dir = 5;
      }
      message  RpcDeletePlayerNotify
      {
        optional sint32 ObjId = 2[default=-1];
        optional sint32 SceneId = 3[default=-1];
      }
      message  RpcConnectGameServerAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional string Key = 2;
      }
      message  RpcConnectGameServerReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional sint32 SceneId = 3[default=-1];
      }
      message  RpcChangeSceneAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 CurSceneId = 2[default=-1];
        optional sint32 TargetSceneId = 3[default=-1];
      }
      message  RpcChangeSceneReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional sint32 CurSceneId = 3[default=-1];
        optional sint32 TargetSceneId = 4[default=-1];
      }
      message  RpcCreateObjNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional V3 Pos = 2;
        optional float Dir = 3;
        optional sint32 ObjType = 4[default=-1];
        optional sint32 ConfigId = 5[default=-1];
        optional sint32 Status = 6[default=-1];
        optional float MoveSpeed = 7;
        optional uint64 RoleId = 8[default=0];
        optional string NickName = 9;
        optional sint32 Hp = 10[default=-1];
        optional V3 TargetPos = 11;
        optional sint64 HpMax = 12[default=-1];
      }
      message  RpcSurroundingHumanAsk
      {
      }
      message  RpcSurroundingHumanReply
      {
        optional sint32 Result = 1[default=-9999];
        repeated CharacterInfo RoleList = 2;
      }
      message  RpcCEnterSceneNotify
      {
        optional sint32 SceneId = 3[default=-1];
        optional sint32 MapId = 6[default=-1];
      }
      message  RpcSEnterSceneNotify
      {
        optional sint32 Result = 1[default=-9999];
        optional sint32 SceneId = 8[default=-1];
        optional sint32 SceneConfigId = 9[default=-1];
        optional sint32 MapId = 10[default=-1];
        optional uint64 RoleId = 11[default=0];
        optional sint32 DungeonConfigId = 12[default=-1];
      }
      message  RpcObjDieNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional sint32 RespawnTime = 2[default=-1];
        optional sint32 ConfigId = 3[default=-1];
        optional sint32 ObjType = 4[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    LoadSceneCompleteAskPB = Proto.build("RpcLoadSceneCompleteAsk")
    LoadSceneCompleteReplyPB = Proto.build("RpcLoadSceneCompleteReply")
    DeletePlayerNotifyPB = Proto.build("RpcDeletePlayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_DELETEPLAYER_NOTIFY,@DeletePlayerCB)
    ConnectGameServerAskPB = Proto.build("RpcConnectGameServerAsk")
    ConnectGameServerReplyPB = Proto.build("RpcConnectGameServerReply")
    ChangeSceneAskPB = Proto.build("RpcChangeSceneAsk")
    ChangeSceneReplyPB = Proto.build("RpcChangeSceneReply")
    CreateObjNotifyPB = Proto.build("RpcCreateObjNotify")
    mLayerMgr.registerNotify(RPC_CODE_CREATEOBJ_NOTIFY,@CreateObjCB)
    SurroundingHumanAskPB = Proto.build("RpcSurroundingHumanAsk")
    SurroundingHumanReplyPB = Proto.build("RpcSurroundingHumanReply")
    CEnterSceneNotifyPB = Proto.build("RpcCEnterSceneNotify")
    SEnterSceneNotifyPB = Proto.build("RpcSEnterSceneNotify")
    mLayerMgr.registerNotify(RPC_CODE_SENTERSCENE_NOTIFY,@SEnterSceneCB)
    ObjDieNotifyPB = Proto.build("RpcObjDieNotify")
    mLayerMgr.registerNotify(RPC_CODE_OBJDIE_NOTIFY,@ObjDieCB)






  LoadSceneComplete : (RoleId,SceneId,replyCB) ->
    LoadSceneCompleteAsk = LoadSceneCompleteAskPB.prototype
    LoadSceneCompleteAsk.setRoleId RoleId
    LoadSceneCompleteAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_LOADSCENECOMPLETE_REQUEST,LoadSceneCompleteAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoadSceneCompleteReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ConnectGameServer : (RoleId,Key,replyCB) ->
    ConnectGameServerAsk = ConnectGameServerAskPB.prototype
    ConnectGameServerAsk.setRoleId RoleId
    ConnectGameServerAsk.setKey Key
    mLayerMgr.sendAsk(RPC_CODE_CONNECTGAMESERVER_REQUEST,ConnectGameServerAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ConnectGameServerReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeScene : (RoleId,CurSceneId,TargetSceneId,replyCB) ->
    ChangeSceneAsk = ChangeSceneAskPB.prototype
    ChangeSceneAsk.setRoleId RoleId
    ChangeSceneAsk.setCurSceneId CurSceneId
    ChangeSceneAsk.setTargetSceneId TargetSceneId
    mLayerMgr.sendAsk(RPC_CODE_CHANGESCENE_REQUEST,ChangeSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SurroundingHuman : (replyCB) ->
    SurroundingHumanAsk = SurroundingHumanAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SURROUNDINGHUMAN_REQUEST,SurroundingHumanAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SurroundingHumanReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CEnterScene : (SceneId,MapId) ->
    CEnterSceneNotify = CEnterSceneNotifyPB.prototype
    CEnterSceneNotify.setSceneId SceneId
    CEnterSceneNotify.setMapId MapId
    mLayerMgr.sendNotify(RPC_CODE_CENTERSCENE_NOTIFY,CEnterSceneNotify)


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetDeletePlayerNotifyCB : (cb) -> RpcDeletePlayerNotifyCB = cb
  DeletePlayerCB : (data)->
    RpcDeletePlayerNotifyCB( DeletePlayerNotifyPB.decode(data)) if typeof(RpcDeletePlayerNotifyCB) is "function"
  SetCreateObjNotifyCB : (cb) -> RpcCreateObjNotifyCB = cb
  CreateObjCB : (data)->
    RpcCreateObjNotifyCB( CreateObjNotifyPB.decode(data)) if typeof(RpcCreateObjNotifyCB) is "function"
  SetSEnterSceneNotifyCB : (cb) -> RpcSEnterSceneNotifyCB = cb
  SEnterSceneCB : (data)->
    RpcSEnterSceneNotifyCB( SEnterSceneNotifyPB.decode(data)) if typeof(RpcSEnterSceneNotifyCB) is "function"
  SetObjDieNotifyCB : (cb) -> RpcObjDieNotifyCB = cb
  ObjDieCB : (data)->
    RpcObjDieNotifyCB( ObjDieNotifyPB.decode(data)) if typeof(RpcObjDieNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "SceneModel",
      'AskName': ["LoadSceneComplete",
                   "ConnectGameServer",
                   "ChangeScene",
                   "SurroundingHuman",
                   "CEnterScene"]
      'ParamterList': [["RoleId","SceneId"],
                       ["RoleId","Key"],
                       ["RoleId","CurSceneId","TargetSceneId"],
                       [],
                       ["SceneId","MapId"]]
      'AskList':[@LoadSceneComplete,
                 @ConnectGameServer,
                 @ChangeScene,
                 @SurroundingHuman,
                 @CEnterScene]
      'ParamterTypelist': [["uint64","sint32"],
                       ["uint64","string"],
                       ["uint64","sint32","sint32"],
                       [],
                       ["sint32","sint32"]]


module.exports =(()->
  if not Scene?
    Scene = new SceneModel()
  Scene)()



  

  

  


