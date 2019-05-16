ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 23
RPC_CODE_WORLDBOSSINFO_REQUEST = 2351
RPC_CODE_WORLDBOSSRANKINFO_REQUEST = 2352

WorldBossInfoAskPB = null
WorldBossInfoReplyPB = null
WorldBossRankInfoAskPB = null
WorldBossRankInfoReplyPB = null

class WorldBossModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcWorldBossInfoAsk
      {
        optional int32 BossID = 2[default=-1];
      }
      message  WorldBossInfo
      {
        optional int32 LineID = 1[default=-1];
        optional int32 HPRate = 2[default=-1];
      }
      message  RpcWorldBossInfoReply
      {
        optional int32 Result = 1[default=-1];
        repeated WorldBossInfo WorldBossInfos = 2;
        optional int32 BossID = 3[default=-1];
      }
      message  RpcWorldBossRankInfoAsk
      {
        optional int32 BossID = 1[default=-1];
        optional int32 Occupation = 2[default=-1];
      }
      message  WorldBossRankInfo
      {
        optional int32 Rank = 1[default=-1];
        optional string Name = 2;
        optional int32 Level = 3[default=-1];
        optional int32 Score = 4[default=-1];
      }
      message  RpcWorldBossRankInfoReply
      {
        optional int32 Result = 1[default=-1];
        repeated WorldBossRankInfo RankInfo = 2;
        optional string LastKillName = 3;
        optional string MaxDamageName = 4;
        optional int32 MyRank = 5[default=-1];
        optional int32 Occupation = 6[default=-1];
        optional int32 BossID = 7[default=-1];
        optional int32 MyOccupationRank = 8[default=-1];
        optional int32 MyScore = 9[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    WorldBossInfoAskPB = Proto.build("RpcWorldBossInfoAsk")
    WorldBossInfoReplyPB = Proto.build("RpcWorldBossInfoReply")
    WorldBossRankInfoAskPB = Proto.build("RpcWorldBossRankInfoAsk")
    WorldBossRankInfoReplyPB = Proto.build("RpcWorldBossRankInfoReply")






  WorldBossInfo : (BossID,replyCB) ->
    WorldBossInfoAsk = WorldBossInfoAskPB.prototype
    WorldBossInfoAsk.setBossID BossID
    mLayerMgr.sendAsk(RPC_CODE_WORLDBOSSINFO_REQUEST,WorldBossInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( WorldBossInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  WorldBossRankInfo : (BossID,Occupation,replyCB) ->
    WorldBossRankInfoAsk = WorldBossRankInfoAskPB.prototype
    WorldBossRankInfoAsk.setBossID BossID
    WorldBossRankInfoAsk.setOccupation Occupation
    mLayerMgr.sendAsk(RPC_CODE_WORLDBOSSRANKINFO_REQUEST,WorldBossRankInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( WorldBossRankInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "WorldBossModel",
      'AskName': ["WorldBossInfo",
                   "WorldBossRankInfo"]
      'ParamterList': [["BossID"],
                       ["BossID","Occupation"]]
      'AskList':[@WorldBossInfo,
                 @WorldBossRankInfo]
      'ParamterTypelist': [["int32"],
                       ["int32","int32"]]


module.exports =(()->
  if not WorldBoss?
    WorldBoss = new WorldBossModel()
  WorldBoss)()



  

  

  


