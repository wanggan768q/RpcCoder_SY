ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 8
RPC_CODE_UPDATEROLEINFO_REQUEST = 851
RPC_CODE_CREATEDUNGEONNOTIFY_REQUEST = 852
RPC_CODE_EXITDUNGEON_REQUEST = 853
RPC_CODE_UPDATETEAMINFO_REQUEST = 854
RPC_CODE_PLAYCGTEAM_REQUEST = 855
RPC_CODE_SENDMAIL_REQUEST = 856
RPC_CODE_CHANGETEAMTYPE_REQUEST = 857
RPC_CODE_AUTOMATCH_REQUEST = 858
RPC_CODE_CANCELMATCH_REQUEST = 859
RPC_CODE_LOGINGAMESERVER_REQUEST = 860
RPC_CODE_LOGOUTGAMESERVER_REQUEST = 861
RPC_CODE_GETPLAYERINFO_REQUEST = 862

UpdateRoleInfoAskPB = null
UpdateRoleInfoReplyPB = null
CreateDungeonNotifyAskPB = null
CreateDungeonNotifyReplyPB = null
ExitDungeonAskPB = null
ExitDungeonReplyPB = null
UpdateTeamInfoAskPB = null
UpdateTeamInfoReplyPB = null
PlayCgTeamAskPB = null
PlayCgTeamReplyPB = null
SendMailAskPB = null
SendMailReplyPB = null
ChangeTeamTypeAskPB = null
ChangeTeamTypeReplyPB = null
AutoMatchAskPB = null
AutoMatchReplyPB = null
CancelMatchAskPB = null
CancelMatchReplyPB = null
LoginGameServerAskPB = null
LoginGameServerReplyPB = null
LogoutGameServerAskPB = null
LogoutGameServerReplyPB = null
GetPlayerInfoAskPB = null
GetPlayerInfoReplyPB = null

class WorldServerModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  CharacterLocation
      {
        optional int32 SceneId = 2[default=-1];
        optional Vector3 Pos = 3;
        optional int32 MapId = 5[default=-1];
        optional int32 DungeonConfigId = 6[default=-1];
        optional int32 LineId = 7[default=-1];
        optional int32 SceneConfigId = 8[default=-1];
        optional int32 MirrorId = 9[default=-1];
        optional int32 ServerId = 10[default=-1];
      }
      message  PlayerMatchData
      {
        optional int32 MatchType = 1[default=0];
        optional int32 Elo = 2[default=0];
        optional int32 Auto = 3[default=0];
      }
      message  OnlineUserInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 2[default=-1];
        optional CharacterLocation Location = 5;
        optional uint64 Guildguid = 6[default=0];
        optional PlayerMatchData PlayerMatchData = 7;
        optional string RoleName = 8;
        optional int32 ConfigID = 9[default=-1];
        optional int32 TreasureCount = 10[default=-1];
        optional int32 TreasureLevel = 11[default=-1];
        optional int32 PetConfigID = 12[default=-1];
        optional int32 PetLevel = 13[default=-1];
        optional int32 PvP3v3WinCount = 14[default=-1];
        optional int32 PvP5v5WinCount = 15[default=-1];
        optional int32 Roam_zone = 16[default=-1];
        optional string Account = 17;
        optional int32 ProfessionId = 18[default=-1];
      }
      message  RpcUpdateRoleInfoAsk
      {
        optional OnlineUserInfo RoleInfo = 1;
      }
      message  RpcUpdateRoleInfoReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcCreateDungeonNotifyAsk
      {
        optional int32 CurSceneId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
        optional int32 TargetSceneId = 5[default=-1];
      }
      message  RpcCreateDungeonNotifyReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcExitDungeonAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcExitDungeonReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  TeamMemberInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 3[default=0];
        optional string Name = 4;
        optional int32 ConfigId = 5[default=-1];
        optional int32 Hp = 6[default=-1];
        optional int32 Status = 8[default=-1];
        optional int64 MaxHp = 11[default=-1];
        optional CharacterLocation Location = 15;
        optional int32 ProfessionId = 16[default=-1];
        optional int32 OnLine = 17[default=1];
        optional int32 FollowTeam = 18[default=-1];
        repeated int32 BuffIdList = 19;
        optional bool Robot = 20;
      }
      message  TeamProfessionTarget
      {
        optional int32 ProfessionId = 1[default=-1];
        optional int32 Size = 2[default=-1];
      }
      message  TeamTarget
      {
        optional int32 Id = 1[default=0];
        optional int32 MinLevel = 2[default=0];
        optional int32 MaxLevel = 3[default=0];
        repeated TeamProfessionTarget Profession = 4;
        optional int32 TargetType = 5[default=0];
      }
      message  TeamInfo
      {
        repeated TeamMemberInfo Members = 1;
        optional uint64 LeaderRoleId = 2[default=0];
        optional uint64 TeamId = 3[default=0];
        optional int32 TeamType = 4[default=-1];
        optional TeamTarget TeamTarget = 5;
      }
      message  RpcUpdateTeamInfoAsk
      {
        optional TeamMemberInfo TeamMember = 1;
        optional uint64 RoleId = 2[default=0];
        optional TeamInfo Team = 4;
        optional int32 TeamType = 5[default=-1];
      }
      message  RpcUpdateTeamInfoReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcPlayCgTeamAsk
      {
        optional uint64 PlayRoleId = 1[default=0];
        optional int32 CgId = 2[default=-1];
        optional int32 State = 3[default=-1];
        optional uint64 RoleId = 4[default=0];
      }
      message  RpcPlayCgTeamReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  AppendString
      {
        optional int32 TransID = 1[default=-1];
        optional int32 Key = 2[default=-1];
        repeated string StringList = 3;
      }
      message  MailItem
      {
        optional int32 ItemID = 1[default=-1];
        optional int32 ItemCount = 2[default=-1];
        optional bool Transit = 3;
      }
      message  MailInfo
      {
        optional int32 Mail_type = 1[default=0];
        optional int32 Mail_id = 2[default=0];
        optional bool IsRead = 3;
        optional bool IsGet = 4;
        optional AppendString Title = 5;
        optional AppendString Salutation = 6;
        optional AppendString Content = 7;
        optional AppendString Sender_name = 8;
        repeated MailItem ItemList = 9;
        optional uint64 Sender_id = 10[default=0];
        optional int32 Start_time = 11[default=-1];
        optional int32 Expire_time = 12[default=-1];
        optional uint64 Receiver_id = 13[default=0];
      }
      message  RpcSendMailAsk
      {
        optional MailInfo Mail = 1;
        optional uint64 GlobalMailID = 2[default=0];
      }
      message  RpcSendMailReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcChangeTeamTypeAsk
      {
        optional uint64 TeamId = 1[default=0];
        optional uint64 RoleId = 2[default=0];
        optional int32 Result = 3[default=-1];
        optional int32 TeamType = 4[default=-1];
        optional TeamTarget Target = 5;
      }
      message  RpcChangeTeamTypeReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcAutoMatchAsk
      {
        optional TeamMemberInfo MemberInfo = 1;
        optional PlayerMatchData MatchInfo = 3;
        optional int32 Result = 4[default=-1];
      }
      message  RpcAutoMatchReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcCancelMatchAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Result = 2[default=-1];
        optional int32 IsNotify = 3[default=0];
      }
      message  RpcCancelMatchReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcLoginGameServerAsk
      {
        optional TeamInfo Team = 1;
        optional OnlineUserInfo RoleInfo = 4;
        optional CharacterLocation Location = 5;
      }
      message  RpcLoginGameServerReply
      {
        optional int32 Result = 1[default=-1];
        optional TeamInfo Team = 2;
        optional OnlineUserInfo RoleInfo = 3;
        optional CharacterLocation Location = 4;
      }
      message  RpcLogoutGameServerAsk
      {
        optional int32 Result = 1[default=-9999];
        optional OnlineUserInfo RoleInfo = 2;
      }
      message  RpcLogoutGameServerReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcGetPlayerInfoAsk
      {
        optional uint64 Player_guid = 1[default=0];
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
      message  SuitInfo
      {
        optional int32 Suit_id = 1[default=-1];
        optional int32 Collect_num = 2[default=-1];
      }
      message  EquipSlotInfo
      {
        optional int32 Enhance_Level = 1[default=-1];
        optional int32 Enhance_Exp = 2[default=-1];
        repeated AttrKeyValue Enhance_Attr = 3;
        optional int32 BattleScore = 4[default=-1];
        optional int32 Slot_Type = 5[default=-1];
      }
      message  EquipSlotStarInfo
      {
        optional int32 RankUp_Level = 1[default=-1];
        optional int32 Slot_Type = 3[default=-1];
        optional int32 BattleScore = 4[default=-1];
        optional int32 NextBattleScore = 6[default=-1];
      }
      message  JewelSlot
      {
        optional int32 ItemId = 1[default=-1];
        optional bool Unlocked = 2;
      }
      message  JewelInfo
      {
        optional int32 EquipSlot = 1[default=-1];
        repeated JewelSlot JewelSlots = 2;
      }
      message  RpcGetPlayerInfoReply
      {
        optional int32 Result = 1[default=-1];
        optional string Player_name = 2;
        optional uint64 Player_guid = 3[default=0];
        optional int32 Avatar_id = 4[default=-1];
        optional int32 Player_level = 5[default=-1];
        optional int32 Avatar_frame_id = 6[default=-1];
        optional int32 Config_id = 7[default=-1];
        optional uint64 Guild_id = 8[default=0];
        optional string Guild_name = 9;
        repeated ItemData Equip_data = 10;
        repeated SuitInfo Suit_infos = 11;
        repeated EquipSlotInfo EquipSlotData = 12;
        repeated EquipSlotStarInfo EquipSlotStarList = 13;
        repeated JewelInfo JewelInfos = 14;
        optional int32 BattleScore = 16[default=-1];
        repeated ItemData Pet_item_data = 18;
        optional int32 TreasureHair = 19[default=-1];
        optional int32 TreasureHead = 20[default=-1];
        optional int32 TreasureBody = 21[default=-1];
        optional int32 TreasureWeapon = 22[default=-1];
        optional int32 TreasureWing = 23[default=-1];
        optional uint64 TeamId = 24[default=0];
        optional int32 Pet_Use_Index = 25[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    UpdateRoleInfoAskPB = Proto.build("RpcUpdateRoleInfoAsk")
    UpdateRoleInfoReplyPB = Proto.build("RpcUpdateRoleInfoReply")
    CreateDungeonNotifyAskPB = Proto.build("RpcCreateDungeonNotifyAsk")
    CreateDungeonNotifyReplyPB = Proto.build("RpcCreateDungeonNotifyReply")
    ExitDungeonAskPB = Proto.build("RpcExitDungeonAsk")
    ExitDungeonReplyPB = Proto.build("RpcExitDungeonReply")
    UpdateTeamInfoAskPB = Proto.build("RpcUpdateTeamInfoAsk")
    UpdateTeamInfoReplyPB = Proto.build("RpcUpdateTeamInfoReply")
    PlayCgTeamAskPB = Proto.build("RpcPlayCgTeamAsk")
    PlayCgTeamReplyPB = Proto.build("RpcPlayCgTeamReply")
    SendMailAskPB = Proto.build("RpcSendMailAsk")
    SendMailReplyPB = Proto.build("RpcSendMailReply")
    ChangeTeamTypeAskPB = Proto.build("RpcChangeTeamTypeAsk")
    ChangeTeamTypeReplyPB = Proto.build("RpcChangeTeamTypeReply")
    AutoMatchAskPB = Proto.build("RpcAutoMatchAsk")
    AutoMatchReplyPB = Proto.build("RpcAutoMatchReply")
    CancelMatchAskPB = Proto.build("RpcCancelMatchAsk")
    CancelMatchReplyPB = Proto.build("RpcCancelMatchReply")
    LoginGameServerAskPB = Proto.build("RpcLoginGameServerAsk")
    LoginGameServerReplyPB = Proto.build("RpcLoginGameServerReply")
    LogoutGameServerAskPB = Proto.build("RpcLogoutGameServerAsk")
    LogoutGameServerReplyPB = Proto.build("RpcLogoutGameServerReply")
    GetPlayerInfoAskPB = Proto.build("RpcGetPlayerInfoAsk")
    GetPlayerInfoReplyPB = Proto.build("RpcGetPlayerInfoReply")






  UpdateRoleInfo : (RoleInfo,replyCB) ->
    UpdateRoleInfoAsk = UpdateRoleInfoAskPB.prototype
    UpdateRoleInfoAsk.setRoleInfo RoleInfo
    mLayerMgr.sendAsk(RPC_CODE_UPDATEROLEINFO_REQUEST,UpdateRoleInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UpdateRoleInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateDungeonNotify : (CurSceneId,RoleId,TargetSceneId,replyCB) ->
    CreateDungeonNotifyAsk = CreateDungeonNotifyAskPB.prototype
    CreateDungeonNotifyAsk.setCurSceneId CurSceneId
    CreateDungeonNotifyAsk.setRoleId RoleId
    CreateDungeonNotifyAsk.setTargetSceneId TargetSceneId
    mLayerMgr.sendAsk(RPC_CODE_CREATEDUNGEONNOTIFY_REQUEST,CreateDungeonNotifyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateDungeonNotifyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ExitDungeon : (RoleId,replyCB) ->
    ExitDungeonAsk = ExitDungeonAskPB.prototype
    ExitDungeonAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_EXITDUNGEON_REQUEST,ExitDungeonAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ExitDungeonReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  UpdateTeamInfo : (TeamMember,RoleId,Team,TeamType,replyCB) ->
    UpdateTeamInfoAsk = UpdateTeamInfoAskPB.prototype
    UpdateTeamInfoAsk.setTeamMember TeamMember
    UpdateTeamInfoAsk.setRoleId RoleId
    UpdateTeamInfoAsk.setTeam Team
    UpdateTeamInfoAsk.setTeamType TeamType
    mLayerMgr.sendAsk(RPC_CODE_UPDATETEAMINFO_REQUEST,UpdateTeamInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( UpdateTeamInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  PlayCgTeam : (PlayRoleId,CgId,State,RoleId,replyCB) ->
    PlayCgTeamAsk = PlayCgTeamAskPB.prototype
    PlayCgTeamAsk.setPlayRoleId PlayRoleId
    PlayCgTeamAsk.setCgId CgId
    PlayCgTeamAsk.setState State
    PlayCgTeamAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_PLAYCGTEAM_REQUEST,PlayCgTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( PlayCgTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SendMail : (Mail,GlobalMailID,replyCB) ->
    SendMailAsk = SendMailAskPB.prototype
    SendMailAsk.setMail Mail
    SendMailAsk.setGlobalMailID GlobalMailID
    mLayerMgr.sendAsk(RPC_CODE_SENDMAIL_REQUEST,SendMailAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SendMailReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeTeamType : (TeamId,RoleId,Result,TeamType,Target,replyCB) ->
    ChangeTeamTypeAsk = ChangeTeamTypeAskPB.prototype
    ChangeTeamTypeAsk.setTeamId TeamId
    ChangeTeamTypeAsk.setRoleId RoleId
    ChangeTeamTypeAsk.setResult Result
    ChangeTeamTypeAsk.setTeamType TeamType
    ChangeTeamTypeAsk.setTarget Target
    mLayerMgr.sendAsk(RPC_CODE_CHANGETEAMTYPE_REQUEST,ChangeTeamTypeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeTeamTypeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AutoMatch : (MemberInfo,MatchInfo,Result,replyCB) ->
    AutoMatchAsk = AutoMatchAskPB.prototype
    AutoMatchAsk.setMemberInfo MemberInfo
    AutoMatchAsk.setMatchInfo MatchInfo
    AutoMatchAsk.setResult Result
    mLayerMgr.sendAsk(RPC_CODE_AUTOMATCH_REQUEST,AutoMatchAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AutoMatchReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CancelMatch : (RoleId,Result,IsNotify,replyCB) ->
    CancelMatchAsk = CancelMatchAskPB.prototype
    CancelMatchAsk.setRoleId RoleId
    CancelMatchAsk.setResult Result
    CancelMatchAsk.setIsNotify IsNotify
    mLayerMgr.sendAsk(RPC_CODE_CANCELMATCH_REQUEST,CancelMatchAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CancelMatchReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LoginGameServer : (Team,RoleInfo,Location,replyCB) ->
    LoginGameServerAsk = LoginGameServerAskPB.prototype
    LoginGameServerAsk.setTeam Team
    LoginGameServerAsk.setRoleInfo RoleInfo
    LoginGameServerAsk.setLocation Location
    mLayerMgr.sendAsk(RPC_CODE_LOGINGAMESERVER_REQUEST,LoginGameServerAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoginGameServerReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LogoutGameServer : (Result,RoleInfo,replyCB) ->
    LogoutGameServerAsk = LogoutGameServerAskPB.prototype
    LogoutGameServerAsk.setResult Result
    LogoutGameServerAsk.setRoleInfo RoleInfo
    mLayerMgr.sendAsk(RPC_CODE_LOGOUTGAMESERVER_REQUEST,LogoutGameServerAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LogoutGameServerReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GetPlayerInfo : (Player_guid,replyCB) ->
    GetPlayerInfoAsk = GetPlayerInfoAskPB.prototype
    GetPlayerInfoAsk.setPlayer_guid Player_guid
    mLayerMgr.sendAsk(RPC_CODE_GETPLAYERINFO_REQUEST,GetPlayerInfoAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GetPlayerInfoReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "WorldServerModel",
      'AskName': ["UpdateRoleInfo",
                   "CreateDungeonNotify",
                   "ExitDungeon",
                   "UpdateTeamInfo",
                   "PlayCgTeam",
                   "SendMail",
                   "ChangeTeamType",
                   "AutoMatch",
                   "CancelMatch",
                   "LoginGameServer",
                   "LogoutGameServer",
                   "GetPlayerInfo"]
      'ParamterList': [["RoleInfo"],
                       ["CurSceneId","RoleId","TargetSceneId"],
                       ["RoleId"],
                       ["TeamMember","RoleId","Team","TeamType"],
                       ["PlayRoleId","CgId","State","RoleId"],
                       ["Mail","GlobalMailID"],
                       ["TeamId","RoleId","Result","TeamType","Target"],
                       ["MemberInfo","MatchInfo","Result"],
                       ["RoleId","Result","IsNotify"],
                       ["Team","RoleInfo","Location"],
                       ["Result","RoleInfo"],
                       ["Player_guid"]]
      'AskList':[@UpdateRoleInfo,
                 @CreateDungeonNotify,
                 @ExitDungeon,
                 @UpdateTeamInfo,
                 @PlayCgTeam,
                 @SendMail,
                 @ChangeTeamType,
                 @AutoMatch,
                 @CancelMatch,
                 @LoginGameServer,
                 @LogoutGameServer,
                 @GetPlayerInfo]
      'ParamterTypelist': [["OnlineUserInfo"],
                       ["int32","uint64","int32"],
                       ["uint64"],
                       ["TeamMemberInfo","uint64","TeamInfo","int32"],
                       ["uint64","int32","int32","uint64"],
                       ["MailInfo","uint64"],
                       ["uint64","uint64","int32","int32","TeamTarget"],
                       ["TeamMemberInfo","PlayerMatchData","int32"],
                       ["uint64","int32","int32"],
                       ["TeamInfo","OnlineUserInfo","CharacterLocation"],
                       ["int32","OnlineUserInfo"],
                       ["uint64"]]


module.exports =(()->
  if not WorldServer?
    WorldServer = new WorldServerModel()
  WorldServer)()



  

  

  


