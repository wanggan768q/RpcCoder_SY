ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcNewPlayerNotifyCB = null
RpcDeletePlayerNotifyCB = null


ModuleId = 3
RPC_CODE_ENTERSCENE_REQUEST = 351
RPC_CODE_LOADSCENECOMPLETE_REQUEST = 352
RPC_CODE_NEWPLAYER_NOTIFY = 353
RPC_CODE_DELETEPLAYER_NOTIFY = 354
RPC_CODE_CONNECTGAMESERVER_REQUEST = 355

EnterSceneAskPB = null
EnterSceneReplyPB = null
LoadSceneCompleteAskPB = null
LoadSceneCompleteReplyPB = null
NewPlayerNotifyPB = null
DeletePlayerNotifyPB = null
ConnectGameServerAskPB = null
ConnectGameServerReplyPB = null

class SceneModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcEnterSceneAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
      }
      message  CharacterInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional string Nickname = 2;
        optional sint32 ConfigId = 3[default=-1];
      }
      message  RpcEnterSceneReply
      {
        optional sint32 Result = 1[default=-9999];
        optional CharacterInfo RoleInfo = 2;
      }
      message  RpcLoadSceneCompleteAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional sint32 SceneId = 2[default=-1];
      }
      message  RpcLoadSceneCompleteReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  V3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  RpcNewPlayerNotify
      {
        optional sint32 ObjId = 1[default=-1];
        optional V3 Pos = 2;
        optional float Dir = 3;
        optional sint32 ObjType = 4[default=-1];
        optional sint32 ConfigId = 5[default=-1];
        optional sint32 Status = 6[default=-1];
        optional float MoveSpeed = 7;
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
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    EnterSceneAskPB = Proto.build("RpcEnterSceneAsk")
    EnterSceneReplyPB = Proto.build("RpcEnterSceneReply")
    LoadSceneCompleteAskPB = Proto.build("RpcLoadSceneCompleteAsk")
    LoadSceneCompleteReplyPB = Proto.build("RpcLoadSceneCompleteReply")
    NewPlayerNotifyPB = Proto.build("RpcNewPlayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWPLAYER_NOTIFY,@NewPlayerCB)
    DeletePlayerNotifyPB = Proto.build("RpcDeletePlayerNotify")
    mLayerMgr.registerNotify(RPC_CODE_DELETEPLAYER_NOTIFY,@DeletePlayerCB)
    ConnectGameServerAskPB = Proto.build("RpcConnectGameServerAsk")
    ConnectGameServerReplyPB = Proto.build("RpcConnectGameServerReply")






  EnterScene : (RoleId,SceneId,replyCB) ->
    EnterSceneAsk = EnterSceneAskPB.prototype
    EnterSceneAsk.setRoleId RoleId
    EnterSceneAsk.setSceneId SceneId
    mLayerMgr.sendAsk(RPC_CODE_ENTERSCENE_REQUEST,EnterSceneAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( EnterSceneReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
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


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetNewPlayerNotifyCB : (cb) -> RpcNewPlayerNotifyCB = cb
  NewPlayerCB : (data)->
    RpcNewPlayerNotifyCB( NewPlayerNotifyPB.decode(data)) if typeof(RpcNewPlayerNotifyCB) is "function"
  SetDeletePlayerNotifyCB : (cb) -> RpcDeletePlayerNotifyCB = cb
  DeletePlayerCB : (data)->
    RpcDeletePlayerNotifyCB( DeletePlayerNotifyPB.decode(data)) if typeof(RpcDeletePlayerNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "SceneModel",
      'AskName': ["EnterScene",
                   "LoadSceneComplete",
                   "ConnectGameServer"]
      'ParamterList': [["RoleId","SceneId"],
                       ["RoleId","SceneId"],
                       ["RoleId","Key"]]
      'AskList':[@EnterScene,
                 @LoadSceneComplete,
                 @ConnectGameServer]
      'ParamterTypelist': [["uint64","sint32"],
                       ["uint64","sint32"],
                       ["uint64","string"]]


module.exports =(()->
  if not Scene?
    Scene = new SceneModel()
  Scene)()



  

  

  


