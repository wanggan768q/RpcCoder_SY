--将变量写入下方
local ModuleId = 2;
local RPC_CODE_LOGIN_CONNECT_REQUEST = 251
local RPC_CODE_LOGIN_LOGIN_REQUEST = 252
local RPC_CODE_LOGIN_CHARACTERLIST_REQUEST = 253
local RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST = 254
local RPC_CODE_LOGIN_CREATECHARACTER_REQUEST = 255
local RPC_CODE_LOGIN_SELECTSAVEUSER_REQUEST = 256





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
require("3rd/pblua/LoginRpc_pb")
local  LoginRpc_pb = LoginRpc_pb
module("LoginModel")

function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)

end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = LoginRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function Connect(self,Type,_hanlder)
	local PB = self.rpc_pb.LoginRpcConnectAsk()
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcConnectReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_CONNECT_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Login(self,Username,Passwd,_hanlder)
	local PB = self.rpc_pb.LoginRpcLoginAsk()
	PB.Username = Username
	PB.Passwd = Passwd
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcLoginReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_LOGIN_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CharacterList(self,Accountname ,_hanlder)
	local PB = self.rpc_pb.LoginRpcCharacterListAsk()
	PB.Accountname  = Accountname 
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcCharacterListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_CHARACTERLIST_REQUEST, pb_data, callback)
	showNetTip(self)
end
function SelectCharacter(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcSelectCharacterAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcSelectCharacterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CreateCharacter(self,Nickname,ConfigId,_hanlder)
	local PB = self.rpc_pb.LoginRpcCreateCharacterAsk()
	PB.Nickname = Nickname
	PB.ConfigId = ConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcCreateCharacterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function SelectSaveUser(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcSelectSaveUserAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcSelectSaveUserReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_SELECTSAVEUSER_REQUEST, pb_data, callback)
	showNetTip(self)
end







--[[
askList.Login = {}

local t = {}
t.name = "Connect"
t.para = {{name="Type",t=1}}
t.hand = LoginModel.Connect
t.pb = LoginRpc_pb.LoginRpcConnectAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "Login"
t.para = {{name="Username",t=2},{name="Passwd",t=2}}
t.hand = LoginModel.Login
t.pb = LoginRpc_pb.LoginRpcLoginAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "CharacterList"
t.para = {{name="Accountname ",t=2}}
t.hand = LoginModel.CharacterList
t.pb = LoginRpc_pb.LoginRpcCharacterListAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "SelectCharacter"
t.para = {{name="RoleId",t=1}}
t.hand = LoginModel.SelectCharacter
t.pb = LoginRpc_pb.LoginRpcSelectCharacterAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "CreateCharacter"
t.para = {{name="Nickname",t=2},{name="ConfigId",t=1}}
t.hand = LoginModel.CreateCharacter
t.pb = LoginRpc_pb.LoginRpcCreateCharacterAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "SelectSaveUser"
t.para = {{name="RoleId",t=1}}
t.hand = LoginModel.SelectSaveUser
t.pb = LoginRpc_pb.LoginRpcSelectSaveUserAsk()
table.insert(askList.Login,t)

--]]