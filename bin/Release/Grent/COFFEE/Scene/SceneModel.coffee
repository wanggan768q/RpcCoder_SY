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
RpcSEnterMirrorSceneNotifyCB = null
RpcChangeSceneLeaveNotifyCB = null
RpcSyncSceneLineStatsNotifyCB = null
RpcKickOutGameNotifyCB = null


ModuleId = 3
RPC_CODE_LOADSCENECOMPLETE_REQUEST = 351
RPC_CODE_DELETEPLAYER_NOTIFY = 352
RPC_CODE_CONNECTGAMESERVER_REQUEST = 353
RPC_CODE_CREATEOBJ_NOTIFY = 354
RPC_CODE_SURROUNDINGHUMAN_REQUEST = 355
RPC_CODE_CENTERSCENE_NOTIFY = 356
RPC_CODE_SENTERSCENE_NOTIFY = 357
RPC_CODE_OBJDIE_NOTIFY = 358
RPC_CODE_COLLIDE_CHANGESCENE_REQUEST = 359
RPC_CODE_ENTERMIRROR_REQUEST = 360
RPC_CODE_SENTERMIRRORSCENE_NOTIFY = 361
RPC_CODE_EXITMIRRORSCENE_REQUEST = 362
RPC_CODE_CHANGESCENELEAVE_NOTIFY = 363
RPC_CODE_CHANGELINE_REQUEST = 364
RPC_CODE_PING_REQUEST = 365
RPC_CODE_SYNCSCENELINESTATS_NOTIFY = 366
RPC_CODE_LOGOUTGAME_REQUEST = 367
RPC_CODE_KICKOUTGAME_NOTIFY = 368
RPC_CODE_SHOWFILMFINISH_REQUEST = 369

LoadSceneCompleteAskPB = null
LoadSceneCompleteReplyPB = null
DeletePlayerNotifyPB = null
ConnectGameServerAskPB = null
ConnectGameServerReplyPB = null
CreateObjNotifyPB = null
SurroundingHumanAskPB = null
SurroundingHumanReplyPB = null
CEnterSceneNotifyPB = null
SEnterSceneNotifyPB = null
ObjDieNotifyPB = null
Collide_ChangeSceneAskPB = null
Collide_ChangeSceneReplyPB = null
EnterMirrorAskPB = null
EnterMirrorReplyPB = null
SEnterMirrorSceneNotifyPB = null
ExitMirrorSceneAskPB = null
ExitMirrorSceneReplyPB = null
ChangeSceneLeaveNotifyPB = null
ChangeLineAskPB = null
ChangeLineReplyPB = null
PingAskPB = null
PingReplyPB = null
SyncSceneLineStatsNotifyPB = null
LogOutGameAskPB = null
LogOutGameReplyPB = null
KickOutGameNotifyPB = null
ShowFilmFinishAskPB = null
ShowFilmFinishReplyPB = null

class SceneModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcLoadSceneCompleteAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 SceneId = 2[default=-1];
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcLoadSceneCompleteReply
      {
        optional int32 Result = 1[default=-9999];
        optional int32 ObjId = 3[default=-1];
        optional Vector3 Pos = 4;
        optional float Dir = 5;
        optional bytes ObjData = 6;
      }
      message  RpcDeletePlayerNotify
      {
        optional int32 ObjId = 2[default=-1];
        optional int32 SceneId = 3[default=-1];
      }
      message  RpcConnectGameServerAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional string Key = 2;
        optional int32 SceneID = 3[default=-1];
        optional int32 LineID = 4[default=-1];
      }
      message  RpcConnectGameServerReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional int32 SceneId = 3[default=-1];
        optional int32 MapId = 5[default=-1];
      }
      message  RpcCreateObjNotify
      {
        optional int32 ObjId = 1[default=-1];
        optional Vector3 Pos = 2;
        optional float Dir = 3;
        optional int32 Status = 6[default=-1];
        optional Vector3 TargetPos = 11;
        optional bytes ObjData = 13;
      }
      message  RpcSurroundingHumanAsk
      {
      }
      message  TreasureEquipedID
      {
        optional int32 TreasureHair = 1[default=-1];
        optional int32 TreasureHead = 2[default=-1];
        optional int32 TreasureBody = 3[default=-1];
        optional int32 TreasureWeapon = 4[default=-1];
        optional int32 TreasureWing = 5[default=-1];
        optional int32 TreasureRiding = 6[default=-1];
      }
      message  CharacterInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional string Nickname = 2;
        optional int32 ConfigId = 3[default=-1];
        optional int32 Hp = 4[default=-1];
        optional int32 HpMax = 5[default=-1];
        optional int32 Level = 6[default=-1];
        optional TreasureEquipedID TreasureEquiped = 8;
      }
      message  RpcSurroundingHumanReply
      {
        optional int32 Result = 1[default=-9999];
        repeated CharacterInfo RoleList = 2;
      }
      message  RpcCEnterSceneNotify
      {
        optional int32 SceneId = 3[default=-1];
        optional int32 MapId = 6[default=-1];
        optional int32 LineId = 7[default=-1];
      }
      message  RpcSEnterSceneNotify
      {
        optional int32 Result = 1[default=-9999];
        optional int32 SceneId = 8[default=-1];
        optional int32 SceneConfigId = 9[default=-1];
        optional int32 MapId = 10[default=-1];
        optional uint64 RoleId = 11[default=0];
        optional int32 DungeonConfigId = 12[default=-1];
        optional int32 LineId = 14[default=-1];
      }
      message  RpcObjDieNotify
      {
        optional int32 ObjId = 1[default=-1];
        optional int32 RespawnTime = 2[default=-1];
        optional int32 ConfigId = 3[default=-1];
        optional int32 ObjType = 4[default=-1];
      }
      message  RpcCollide_ChangeSceneAsk
      {
        optional int32 Collide_id = 1[default=-1];
      }
      message  RpcCollide_ChangeSceneReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcEnterMirrorAsk
      {
        optional int32 MirrorID = 1[default=-1];
      }
      message  RpcEnterMirrorReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcSEnterMirrorSceneNotify
      {
        optional int32 MapID = 1[default=-1];
        optional int32 MirrorID = 2[default=-1];
      }
      message  RpcExitMirrorSceneAsk
      {
      }
      message  RpcExitMirrorSceneReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcChangeSceneLeaveNotify
      {
        optional int32 TargetLineID = 1[default=-1];
        optional int32 TargetMapID = 2[default=-1];
        optional uint64 RoleID = 4[default=0];
        optional int32 CopyID = 5[default=-1];
      }
      message  RpcChangeLineAsk
      {
        optional int32 LineID = 1[default=-1];
        optional int32 MapID = 2[default=-1];
      }
      message  RpcChangeLineReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 LineID = 2[default=-1];
        optional int32 MapID = 3[default=-1];
        optional uint64 RoleID = 4[default=0];
      }
      message  RpcPingAsk
      {
      }
      message  RpcPingReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  LineStats
      {
        optional int32 LineId = 1[default=-1];
        optional int32 LineStats = 2[default=-1];
      }
      message  SceneStats
      {
        repeated LineStats Lines = 1;
        optional int32 SceneId = 2[default=-1];
      }
      message  RpcSyncSceneLineStatsNotify
      {
        optional SceneStats Scene_stats = 1;
        optional int32 Player_lineId = 2[default=-1];
      }
      message  RpcLogOutGameAsk
      {
      }
      message  RpcLogOutGameReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcKickOutGameNotify
      {
        optional string Kick_reason = 1;
        optional int32 Reason_id = 2[default=-1];
      }
      message  RpcShowFilmFinishAsk
      {
      }
      message  RpcShowFilmFinishReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    LoadSceneCompleteAskPB = Proto.build("RpcLoadSceneCompleteAsk")
    LoadSceneCompleteReplyPB = Proto.build("RpcLoadSceneCompleteReply")
    DeletePlayerNotifyPB = Proto.build("RpcDeletePlayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_DELETEPLAYER_NOTIFY,@DeletePlayerCB)
    ConnectGameServerAskPB = Proto.build("RpcConnectGameServerAsk")
    ConnectGameServerReplyPB = Proto.build("RpcConnectGameServerReply")
    CreateObjNotifyPB = Proto.build("RpcCreateObjNotify")
    mLayerMgr.registerNotify(RPC_CODE_CREATEOBJ_NOTIFY,@CreateObjCB)
    SurroundingHumanAskPB = Proto.build("RpcSurroundingHumanAsk")
    SurroundingHumanReplyPB = Proto.build("RpcSurroundingHumanReply")
    CEnterSceneNotifyPB = Proto.build("RpcCEnterSceneNotify")
    SEnterSceneNotifyPB = Proto.build("RpcSEnterSceneNotify")
    mLayerMgr.registerNotify(RPC_CODE_SENTERSCENE_NOTIFY,@SEnterSceneCB)
    ObjDieNotifyPB = Proto.build("RpcObjDieNotify")
    mLayerMgr.registerNotify(RPC_CODE_OBJDIE_NOTIFY,@ObjDieCB)
    Collide_ChangeSceneAskPB = Proto.build("RpcCollide_ChangeSceneAsk")
    Collide_ChangeSceneReplyPB = Proto.build("RpcCollide_ChangeSceneReply")
    EnterMirrorAskPB = Proto.build("RpcEnterMirrorAsk")
    EnterMirrorReplyPB = Proto.build("RpcEnterMirrorReply")
    SEnterMirrorSceneNotifyPB = Proto.build("RpcSEnterMirrorSceneNotify")
    mLayerMgr.registerNotify(RPC_CODE_SENTERMIRRORSCENE_NOTIFY,@SEnterMirrorSceneCB)
    ExitMirrorSceneAskPB = Proto.build("RpcExitMirrorSceneAsk")
    ExitMirrorSceneReplyPB = Proto.build("RpcExitMirrorSceneReply")
    ChangeSceneLeaveNotifyPB = Proto.build("RpcChangeSceneLeaveNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGESCENELEAVE_NOTIFY,@ChangeSceneLeaveCB)
    ChangeLineAskPB = Proto.build("RpcChangeLineAsk")
    ChangeLineReplyPB = Proto.build("RpcChangeLineReply")
    PingAskPB = Proto.build("RpcPingAsk")
    PingReplyPB = Proto.build("RpcPingReply")
    SyncSceneLineStatsNotifyPB = Proto.build("RpcSyncSceneLineStatsNotify")
    mLayerMgr.registerNotify(RPC_CODE_SYNCSCENELINESTATS_NOTIFY,@SyncSceneLineStatsCB)
    LogOutGameAskPB = Proto.build("RpcLogOutGameAsk")
    LogOutGameReplyPB = Proto.build("RpcLogOutGameReply")
    KickOutGameNotifyPB = Proto.build("RpcKickOutGameNotify")
    mLayerMgr.registerNotify(RPC_CODE_KICKOUTGAME_NOTIFY,@KickOutGameCB)
    ShowFilmFinishAskPB = Proto.build("RpcShowFilmFinishAsk")
    ShowFilmFinishReplyPB = Proto.build("RpcShowFilmFinishReply")






  LoadSceneComplete : (RoleId,SceneId,replyCB) ->
    LoadSceneCompleteAsk = LoadSceneCompleteAskPB.prototype
    LoadSceneCompleteAsk.setRoleId RoleId
    LoadSceneCompleteAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_LOADSCENECOMPLETE_REQUEST,LoadSceneCompleteAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoadSceneCompleteReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ConnectGameServer : (RoleId,Key,SceneID,LineID,replyCB) ->
    ConnectGameServerAsk = ConnectGameServerAskPB.prototype
    ConnectGameServerAsk.setRoleId RoleId
    ConnectGameServerAsk.setKey Key
    ConnectGameServerAsk.setSceneID SceneID
    ConnectGameServerAsk.setLineID LineID
    mLayerMgr.sendAsk(RPC_CODE_CONNECTGAMESERVER_REQUEST,ConnectGameServerAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ConnectGameServerReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SurroundingHuman : (replyCB) ->
    SurroundingHumanAsk = SurroundingHumanAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SURROUNDINGHUMAN_REQUEST,SurroundingHumanAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SurroundingHumanReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CEnterScene : (SceneId,MapId,LineId) ->
    CEnterSceneNotify = CEnterSceneNotifyPB.prototype
    CEnterSceneNotify.setSceneId SceneId
    CEnterSceneNotify.setMapId MapId
    CEnterSceneNotify.setLineId LineId
    mLayerMgr.sendNotify(RPC_CODE_CENTERSCENE_NOTIFY,CEnterSceneNotify)
  Collide_ChangeScene : (Collide_id,replyCB) ->
    Collide_ChangeSceneAsk = Collide_ChangeSceneAskPB.prototype
    Collide_ChangeSceneAsk.setCollide_id Collide_id
    mLayerMgr.sendAsk(RPC_CODE_COLLIDE_CHANGESCENE_REQUEST,Collide_ChangeSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( Collide_ChangeSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  EnterMirror : (MirrorID,replyCB) ->
    EnterMirrorAsk = EnterMirrorAskPB.prototype
    EnterMirrorAsk.setMirrorID MirrorID
    mLayerMgr.sendAsk(RPC_CODE_ENTERMIRROR_REQUEST,EnterMirrorAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterMirrorReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ExitMirrorScene : (replyCB) ->
    ExitMirrorSceneAsk = ExitMirrorSceneAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_EXITMIRRORSCENE_REQUEST,ExitMirrorSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ExitMirrorSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeLine : (LineID,MapID,replyCB) ->
    ChangeLineAsk = ChangeLineAskPB.prototype
    ChangeLineAsk.setLineID LineID
    ChangeLineAsk.setMapID MapID
    mLayerMgr.sendAsk(RPC_CODE_CHANGELINE_REQUEST,ChangeLineAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeLineReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Ping : (replyCB) ->
    PingAsk = PingAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_PING_REQUEST,PingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( PingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LogOutGame : (replyCB) ->
    LogOutGameAsk = LogOutGameAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_LOGOUTGAME_REQUEST,LogOutGameAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LogOutGameReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ShowFilmFinish : (replyCB) ->
    ShowFilmFinishAsk = ShowFilmFinishAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SHOWFILMFINISH_REQUEST,ShowFilmFinishAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ShowFilmFinishReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


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
  SetSEnterMirrorSceneNotifyCB : (cb) -> RpcSEnterMirrorSceneNotifyCB = cb
  SEnterMirrorSceneCB : (data)->
    RpcSEnterMirrorSceneNotifyCB( SEnterMirrorSceneNotifyPB.decode(data)) if typeof(RpcSEnterMirrorSceneNotifyCB) is "function"
  SetChangeSceneLeaveNotifyCB : (cb) -> RpcChangeSceneLeaveNotifyCB = cb
  ChangeSceneLeaveCB : (data)->
    RpcChangeSceneLeaveNotifyCB( ChangeSceneLeaveNotifyPB.decode(data)) if typeof(RpcChangeSceneLeaveNotifyCB) is "function"
  SetSyncSceneLineStatsNotifyCB : (cb) -> RpcSyncSceneLineStatsNotifyCB = cb
  SyncSceneLineStatsCB : (data)->
    RpcSyncSceneLineStatsNotifyCB( SyncSceneLineStatsNotifyPB.decode(data)) if typeof(RpcSyncSceneLineStatsNotifyCB) is "function"
  SetKickOutGameNotifyCB : (cb) -> RpcKickOutGameNotifyCB = cb
  KickOutGameCB : (data)->
    RpcKickOutGameNotifyCB( KickOutGameNotifyPB.decode(data)) if typeof(RpcKickOutGameNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "SceneModel",
      'AskName': ["LoadSceneComplete",
                   "ConnectGameServer",
                   "SurroundingHuman",
                   "CEnterScene",
                   "Collide_ChangeScene",
                   "EnterMirror",
                   "ExitMirrorScene",
                   "ChangeLine",
                   "Ping",
                   "LogOutGame",
                   "ShowFilmFinish"]
      'ParamterList': [["RoleId","SceneId"],
                       ["RoleId","Key","SceneID","LineID"],
                       [],
                       ["SceneId","MapId","LineId"],
                       ["Collide_id"],
                       ["MirrorID"],
                       [],
                       ["LineID","MapID"],
                       [],
                       [],
                       []]
      'AskList':[@LoadSceneComplete,
                 @ConnectGameServer,
                 @SurroundingHuman,
                 @CEnterScene,
                 @Collide_ChangeScene,
                 @EnterMirror,
                 @ExitMirrorScene,
                 @ChangeLine,
                 @Ping,
                 @LogOutGame,
                 @ShowFilmFinish]
      'ParamterTypelist': [["uint64","int32"],
                       ["uint64","string","int32","int32"],
                       [],
                       ["int32","int32","int32"],
                       ["int32"],
                       ["int32"],
                       [],
                       ["int32","int32"],
                       [],
                       [],
                       []]


module.exports =(()->
  if not Scene?
    Scene = new SceneModel()
  Scene)()



  

  

  


