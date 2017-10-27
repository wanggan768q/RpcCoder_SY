--将变量写入下方
local ModuleId = 2;
local RPC_CODE_LOGIN_CONNECT_REQUEST = 251
local RPC_CODE_LOGIN_LOGIN_REQUEST = 252





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
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

--]]