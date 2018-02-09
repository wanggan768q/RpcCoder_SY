ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null


ModuleId = 2
RPC_CODE_CONNECT_REQUEST = 251
RPC_CODE_LOGIN_REQUEST = 252
RPC_CODE_CHARACTERLIST_REQUEST = 253
RPC_CODE_SELECTCHARACTER_REQUEST = 254
RPC_CODE_CREATECHARACTER_REQUEST = 255
RPC_CODE_SELECTSAVEUSER_REQUEST = 256
RPC_CODE_DELETECHARACTER_REQUEST = 257

ConnectAskPB = null
ConnectReplyPB = null
LoginAskPB = null
LoginReplyPB = null
CharacterListAskPB = null
CharacterListReplyPB = null
SelectCharacterAskPB = null
SelectCharacterReplyPB = null
CreateCharacterAskPB = null
CreateCharacterReplyPB = null
SelectSaveUserAskPB = null
SelectSaveUserReplyPB = null
DeleteCharacterAskPB = null
DeleteCharacterReplyPB = null

class LoginModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcConnectAsk
      {
        optional sint32 Type = 1[default=-1];
      }
      message  RpcConnectReply
      {
        optional sint32 Result = 1[default=-9999];
        optional sint32 Type = 2[default=0];
      }
      message  RpcLoginAsk
      {
        optional string Username = 1;
        optional string Passwd = 2;
      }
      message  RpcLoginReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcCharacterListAsk
      {
        optional string Accountname  = 1;
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
      message  RpcCharacterListReply
      {
        optional sint32 Result = 1[default=-9999];
        repeated CharacterInfo CharacterList = 2;
        optional uint64 LastSelectRoleId = 4[default=0];
      }
      message  RpcSelectCharacterAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcSelectCharacterReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
        optional string Ip = 3;
        optional sint32 Port = 4[default=0];
      }
      message  RpcCreateCharacterAsk
      {
        optional string Nickname = 1;
        optional sint32 ConfigId = 2[default=-1];
      }
      message  RpcCreateCharacterReply
      {
        optional sint32 Result = 1[default=-9999];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcSelectSaveUserAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcSelectSaveUserReply
      {
        optional sint32 Result = 1[default=-9999];
      }
      message  RpcDeleteCharacterAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcDeleteCharacterReply
      {
        optional sint32 Result = 1[default=-9999];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    ConnectAskPB = Proto.build("RpcConnectAsk")
    ConnectReplyPB = Proto.build("RpcConnectReply")
    LoginAskPB = Proto.build("RpcLoginAsk")
    LoginReplyPB = Proto.build("RpcLoginReply")
    CharacterListAskPB = Proto.build("RpcCharacterListAsk")
    CharacterListReplyPB = Proto.build("RpcCharacterListReply")
    SelectCharacterAskPB = Proto.build("RpcSelectCharacterAsk")
    SelectCharacterReplyPB = Proto.build("RpcSelectCharacterReply")
    CreateCharacterAskPB = Proto.build("RpcCreateCharacterAsk")
    CreateCharacterReplyPB = Proto.build("RpcCreateCharacterReply")
    SelectSaveUserAskPB = Proto.build("RpcSelectSaveUserAsk")
    SelectSaveUserReplyPB = Proto.build("RpcSelectSaveUserReply")
    DeleteCharacterAskPB = Proto.build("RpcDeleteCharacterAsk")
    DeleteCharacterReplyPB = Proto.build("RpcDeleteCharacterReply")






  Connect : (Type,replyCB) ->
    ConnectAsk = ConnectAskPB.prototype
    ConnectAsk.setType Type
    mLayerMgr.sendAsk(RPC_CODE_CONNECT_REQUEST,ConnectAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ConnectReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  Login : (Username,Passwd,replyCB) ->
    LoginAsk = LoginAskPB.prototype
    LoginAsk.setUsername Username
    LoginAsk.setPasswd Passwd
    mLayerMgr.sendAsk(RPC_CODE_LOGIN_REQUEST,LoginAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LoginReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CharacterList : (Accountname ,replyCB) ->
    CharacterListAsk = CharacterListAskPB.prototype
    CharacterListAsk.setAccountname  Accountname 
    mLayerMgr.sendAsk(RPC_CODE_CHARACTERLIST_REQUEST,CharacterListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CharacterListReplyPB.decode(data)) if typeof(replyCB) is "function"
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
  CreateCharacter : (Nickname,ConfigId,replyCB) ->
    CreateCharacterAsk = CreateCharacterAskPB.prototype
    CreateCharacterAsk.setNickname Nickname
    CreateCharacterAsk.setConfigId ConfigId
    mLayerMgr.sendAsk(RPC_CODE_CREATECHARACTER_REQUEST,CreateCharacterAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateCharacterReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SelectSaveUser : (RoleId,replyCB) ->
    SelectSaveUserAsk = SelectSaveUserAskPB.prototype
    SelectSaveUserAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_SELECTSAVEUSER_REQUEST,SelectSaveUserAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SelectSaveUserReplyPB.decode(data)) if typeof(replyCB) is "function"
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


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb


  GetCoffeeInfo: ->
      'CoffeeName': "LoginModel",
      'AskName': ["Connect",
                   "Login",
                   "CharacterList",
                   "SelectCharacter",
                   "CreateCharacter",
                   "SelectSaveUser",
                   "DeleteCharacter"]
      'ParamterList': [["Type"],
                       ["Username","Passwd"],
                       ["Accountname "],
                       ["RoleId"],
                       ["Nickname","ConfigId"],
                       ["RoleId"],
                       ["RoleId"]]
      'AskList':[@Connect,
                 @Login,
                 @CharacterList,
                 @SelectCharacter,
                 @CreateCharacter,
                 @SelectSaveUser,
                 @DeleteCharacter]
      'ParamterTypelist': [["sint32"],
                       ["string","string"],
                       ["string"],
                       ["uint64"],
                       ["string","sint32"],
                       ["uint64"],
                       ["uint64"]]


module.exports =(()->
  if not Login?
    Login = new LoginModel()
  Login)()



  

  

  


