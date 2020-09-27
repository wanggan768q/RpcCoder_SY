ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcLoginLineUpNotifyCB = null
RpcLoginEnterGameNotifyCB = null


ModuleId = 2
RPC_CODE_LOGIN_REQUEST = 251
RPC_CODE_SELECTCHARACTER_REQUEST = 252
RPC_CODE_CREATECHARACTER_REQUEST = 253
RPC_CODE_DELETECHARACTER_REQUEST = 254
RPC_CODE_TEST_REQUEST = 255
RPC_CODE_TEST1_REQUEST = 256
RPC_CODE_LOGINLINEUP_NOTIFY = 257
RPC_CODE_LOGINENTERGAME_NOTIFY = 258
RPC_CODE_LOGINQUITLINEUP_REQUEST = 259
RPC_CODE_REMOTELOGIN_REQUEST = 260

LoginAskPB = null
LoginReplyPB = null
SelectCharacterAskPB = null
SelectCharacterReplyPB = null
CreateCharacterAskPB = null
CreateCharacterReplyPB = null
DeleteCharacterAskPB = null
DeleteCharacterReplyPB = null
TestAskPB = null
TestReplyPB = null
Test1AskPB = null
Test1ReplyPB = null
LoginLineUpNotifyPB = null
LoginEnterGameNotifyPB = null
LoginQuitLineUpAskPB = null
LoginQuitLineUpReplyPB = null
RemoteLoginAskPB = null
RemoteLoginReplyPB = null

class LoginModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcLoginAsk
      {
        optional string Username = 1;
        optional string Passwd = 2;
        optional string SnId = 3;
        optional string GameId = 4;
        optional string Mac = 5;
        optional string Token = 6;
        optional string Version = 7;
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  TreasureEquipedID
      {
        optional int32 TreasureHair = 1[default=-1];
        optional int32 TreasureHead = 2[default=-1];
        optional int32 TreasureBody = 3[default=-1];
        optional int32 TreasureWeapon = 4[default=-1];
        optional int32 TreasureWing = 5[default=-1];
        optional int32 TreasureRiding = 6[default=-1];
        optional int32 TreasureFootPrint = 7[default=-1];
        optional int32 EquipHair = 8[default=-1];
        optional int32 EquipHead = 9[default=-1];
        optional int32 EquipBody = 10[default=-1];
        optional int32 EquipWeapon = 11[default=-1];
        optional bool Headdisplayswitch = 12;
        optional bool Fashiondisplayswitch = 13;
        optional int32 InitHair = 14[default=-1];
        optional int32 InitHead = 15[default=-1];
      }
      message  Color
      {
        optional float R = 1;
        optional float G = 2;
        optional float B = 3;
        optional float A = 4;
      }
      message  PinchFaceBase
      {
        optional int32 Id = 1[default=-1];
        optional float Value = 2;
        optional Color Color = 4;
      }
      message  PinchFaceData
      {
        repeated PinchFaceBase DataInfo = 1;
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
        optional PinchFaceData PinchData = 9;
      }
      message  RpcLoginReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional Vector3 Pos = 3;
        repeated CharacterInfo CharacterList = 4;
        optional uint64 LastSelectRoleId = 5[default=0];
        optional int32 ServerTime = 6[default=-1];
      }
      message  RpcSelectCharacterAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcSelectCharacterReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional int32 LastSceneID = 5[default=-1];
        optional string Ban_Reason = 6;
        optional int32 LineId = 7[default=-1];
        optional int32 Ban_EndTime = 8[default=-1];
      }
      message  RpcCreateCharacterAsk
      {
        optional string Nickname = 1;
        optional int32 ConfigId = 2[default=-1];
        optional PinchFaceData PinchData = 3;
        optional string PushRegId = 4;
      }
      message  RpcCreateCharacterReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional int32 TimeStamp = 3[default=0];
      }
      message  RpcDeleteCharacterAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcDeleteCharacterReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcTestAsk
      {
        repeated int64 A = 1;
        repeated uint64 B = 3;
      }
      message  RpcTestReply
      {
        optional int32 Result = 1[default=-1];
        repeated int64 A = 2;
        repeated uint64 B = 3;
      }
      message  RpcTest1Ask
      {
        repeated uint64 B = 1;
      }
      message  RpcTest1Reply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcLoginLineUpNotify
      {
        optional int32 LineUpIndex = 1[default=-1];
        optional int32 LineUpRole = 2[default=-1];
        optional int32 LineUpTime = 3[default=-1];
      }
      message  RpcLoginEnterGameNotify
      {
        optional uint64 RoleID = 1[default=0];
        optional int32 LastSceneID = 2[default=-1];
        optional int32 LineID = 3[default=-1];
      }
      message  RpcLoginQuitLineUpAsk
      {
      }
      message  RpcLoginQuitLineUpReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcRemoteLoginAsk
      {
        optional uint64 Roleid = 1[default=0];
      }
      message  RpcRemoteLoginReply
      {
        optional int32 Result = 1[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    LoginAskPB = Proto.build("RpcLoginAsk")
    LoginReplyPB = Proto.build("RpcLoginReply")
    SelectCharacterAskPB = Proto.build("RpcSelectCharacterAsk")
    SelectCharacterReplyPB = Proto.build("RpcSelectCharacterReply")
    CreateCharacterAskPB = Proto.build("RpcCreateCharacterAsk")
    CreateCharacterReplyPB = Proto.build("RpcCreateCharacterReply")
    DeleteCharacterAskPB = Proto.build("RpcDeleteCharacterAsk")
    DeleteCharacterReplyPB = Proto.build("RpcDeleteCharacterReply")
    TestAskPB = Proto.build("RpcTestAsk")
    TestReplyPB = Proto.build("RpcTestReply")
    Test1AskPB = Proto.build("RpcTest1Ask")
    Test1ReplyPB = Proto.build("RpcTest1Reply")
    LoginLineUpNotifyPB = Proto.build("RpcLoginLineUpNotify")
    mLayerMgr.registerNotify(RPC_CODE_LOGINLINEUP_NOTIFY,@LoginLineUpCB)
    LoginEnterGameNotifyPB = Proto.build("RpcLoginEnterGameNotify")
    mLayerMgr.registerNotify(RPC_CODE_LOGINENTERGAME_NOTIFY,@LoginEnterGameCB)
    LoginQuitLineUpAskPB = Proto.build("RpcLoginQuitLineUpAsk")
    LoginQuitLineUpReplyPB = Proto.build("RpcLoginQuitLineUpReply")
    RemoteLoginAskPB = Proto.build("RpcRemoteLoginAsk")
    RemoteLoginReplyPB = Proto.build("RpcRemoteLoginReply")






  Login : (Username,Passwd,SnId,GameId,Mac,Token,Version,replyCB) ->
    LoginAsk = LoginAskPB.prototype
    LoginAsk.setUsername Username
    LoginAsk.setPasswd Passwd
    LoginAsk.setSnId SnId
    LoginAsk.setGameId GameId
    LoginAsk.setMac Mac
    LoginAsk.setToken Token
    LoginAsk.setVersion Version
    mLayerMgr.sendAsk(RPC_CODE_LOGIN_REQUEST,LoginAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoginReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SelectCharacter : (RoleId,replyCB) ->
    SelectCharacterAsk = SelectCharacterAskPB.prototype
    SelectCharacterAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_SELECTCHARACTER_REQUEST,SelectCharacterAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SelectCharacterReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateCharacter : (Nickname,ConfigId,PinchData,PushRegId,replyCB) ->
    CreateCharacterAsk = CreateCharacterAskPB.prototype
    CreateCharacterAsk.setNickname Nickname
    CreateCharacterAsk.setConfigId ConfigId
    CreateCharacterAsk.setPinchData PinchData
    CreateCharacterAsk.setPushRegId PushRegId
    mLayerMgr.sendAsk(RPC_CODE_CREATECHARACTER_REQUEST,CreateCharacterAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateCharacterReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DeleteCharacter : (RoleId,replyCB) ->
    DeleteCharacterAsk = DeleteCharacterAskPB.prototype
    DeleteCharacterAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_DELETECHARACTER_REQUEST,DeleteCharacterAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DeleteCharacterReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Test : (A,B,replyCB) ->
    TestAsk = TestAskPB.prototype
    TestAsk.setA A
    TestAsk.setB B
    mLayerMgr.sendAsk(RPC_CODE_TEST_REQUEST,TestAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( TestReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Test1 : (B,replyCB) ->
    Test1Ask = Test1AskPB.prototype
    Test1Ask.setB B
    mLayerMgr.sendAsk(RPC_CODE_TEST1_REQUEST,Test1Ask, (data)->
      NetTipController.hideNetTip()
      replyCB( Test1ReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  LoginQuitLineUp : (replyCB) ->
    LoginQuitLineUpAsk = LoginQuitLineUpAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_LOGINQUITLINEUP_REQUEST,LoginQuitLineUpAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoginQuitLineUpReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RemoteLogin : (Roleid,replyCB) ->
    RemoteLoginAsk = RemoteLoginAskPB.prototype
    RemoteLoginAsk.setRoleid Roleid
    mLayerMgr.sendAsk(RPC_CODE_REMOTELOGIN_REQUEST,RemoteLoginAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RemoteLoginReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetLoginLineUpNotifyCB : (cb) -> RpcLoginLineUpNotifyCB = cb
  LoginLineUpCB : (data)->
    RpcLoginLineUpNotifyCB( LoginLineUpNotifyPB.decode(data)) if typeof(RpcLoginLineUpNotifyCB) is "function"
  SetLoginEnterGameNotifyCB : (cb) -> RpcLoginEnterGameNotifyCB = cb
  LoginEnterGameCB : (data)->
    RpcLoginEnterGameNotifyCB( LoginEnterGameNotifyPB.decode(data)) if typeof(RpcLoginEnterGameNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "LoginModel",
      'AskName': ["Login",
                   "SelectCharacter",
                   "CreateCharacter",
                   "DeleteCharacter",
                   "Test",
                   "Test1",
                   "LoginQuitLineUp",
                   "RemoteLogin"]
      'ParamterList': [["Username","Passwd","SnId","GameId","Mac","Token","Version"],
                       ["RoleId"],
                       ["Nickname","ConfigId","PinchData","PushRegId"],
                       ["RoleId"],
                       ["A","B"],
                       ["B"],
                       [],
                       ["Roleid"]]
      'AskList':[@Login,
                 @SelectCharacter,
                 @CreateCharacter,
                 @DeleteCharacter,
                 @Test,
                 @Test1,
                 @LoginQuitLineUp,
                 @RemoteLogin]
      'ParamterTypelist': [["string","string","string","string","string","string","string"],
                       ["uint64"],
                       ["string","int32","PinchFaceData","string"],
                       ["uint64"],
                       ["int64","uint64"],
                       ["uint64"],
                       [],
                       ["uint64"]]


module.exports =(()->
  if not Login?
    Login = new LoginModel()
  Login)()



  

  

  


