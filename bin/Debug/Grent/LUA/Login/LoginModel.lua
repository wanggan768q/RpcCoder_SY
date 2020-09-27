-- LoginModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 2;
local RPC_CODE_LOGIN_LOGIN_REQUEST = 251
local RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST = 252
local RPC_CODE_LOGIN_CREATECHARACTER_REQUEST = 253
local RPC_CODE_LOGIN_DELETECHARACTER_REQUEST = 254
local RPC_CODE_LOGIN_TEST_REQUEST = 255
local RPC_CODE_LOGIN_TEST1_REQUEST = 256
local RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY = 257;
local RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY = 258;
local RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST = 259
local RPC_CODE_LOGIN_REMOTELOGIN_REQUEST = 260



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
require("3rd/pblua/LoginRpc_pb")
local  LoginRpc_pb = LoginRpc_pb
module("LoginModel")





function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			callback(Id,Index)
		end
	end
end

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = LoginRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY,handler(self,self.LoginLineUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY,handler(self,self.LoginEnterGameCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function Login(self,Username,Passwd,SnId,GameId,Mac,Token,Version,_hanlder)
	local PB = self.rpc_pb.LoginRpcLoginAsk()
	PB.Username = Username
	PB.Passwd = Passwd
	PB.SnId = SnId
	PB.GameId = GameId
	PB.Mac = Mac
	PB.Token = Token
	PB.Version = Version
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_LOGIN_REQUEST',RPC_CODE_LOGIN_LOGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcLoginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => Login ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_LOGIN_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_LOGIN_REQUEST',RPC_CODE_LOGIN_LOGIN_REQUEST)
end
function SelectCharacter(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcSelectCharacterAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST',RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcSelectCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => SelectCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST',RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST)
end
function CreateCharacter(self,Nickname,ConfigId,PinchData,PushRegId,_hanlder)
	local PB = self.rpc_pb.LoginRpcCreateCharacterAsk()
	PB.Nickname = Nickname
	PB.ConfigId = ConfigId
	for i = 1, #PinchData.DataInfo do
		table.insert( PB.PinchData.DataInfo,PinchData.DataInfo[i] )
	end
	PB.PushRegId = PushRegId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_CREATECHARACTER_REQUEST',RPC_CODE_LOGIN_CREATECHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcCreateCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => CreateCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_CREATECHARACTER_REQUEST',RPC_CODE_LOGIN_CREATECHARACTER_REQUEST)
end
function DeleteCharacter(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcDeleteCharacterAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_DELETECHARACTER_REQUEST',RPC_CODE_LOGIN_DELETECHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcDeleteCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => DeleteCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_DELETECHARACTER_REQUEST',RPC_CODE_LOGIN_DELETECHARACTER_REQUEST)
end
function Test(self,A,B,_hanlder)
	local PB = self.rpc_pb.LoginRpcTestAsk()
	for i,v in ipairs(A) do
		table.insert(PB.A,v)
	end
	for i,v in ipairs(B) do
		table.insert(PB.B,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_TEST_REQUEST',RPC_CODE_LOGIN_TEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcTestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => Test ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_TEST_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_TEST_REQUEST',RPC_CODE_LOGIN_TEST_REQUEST)
end
function Test1(self,B,_hanlder)
	local PB = self.rpc_pb.LoginRpcTest1Ask()
	for i,v in ipairs(B) do
		table.insert(PB.B,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_TEST1_REQUEST',RPC_CODE_LOGIN_TEST1_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcTest1Reply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => Test1 ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_TEST1_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_TEST1_REQUEST',RPC_CODE_LOGIN_TEST1_REQUEST)
end
function LoginQuitLineUp(self,_hanlder)
	local PB = self.rpc_pb.LoginRpcLoginQuitLineUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST',RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcLoginQuitLineUpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => LoginQuitLineUp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST',RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST)
end
function RemoteLogin(self,Roleid,_hanlder)
	local PB = self.rpc_pb.LoginRpcRemoteLoginAsk()
	PB.Roleid = Roleid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_LOGIN_REMOTELOGIN_REQUEST',RPC_CODE_LOGIN_REMOTELOGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcRemoteLoginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Login => RemoteLogin ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_REMOTELOGIN_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_LOGIN_REMOTELOGIN_REQUEST',RPC_CODE_LOGIN_REMOTELOGIN_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerLoginLineUpCBNotify(self,_hanlder)
	if not self.LoginLineUpCBNotifyCallBack then
		self.LoginLineUpCBNotifyCallBack = {}
	end
	table.insert(self.LoginLineUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LoginLineUpCB(self,notifyMsg)
	if self.LoginLineUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.LoginRpcLoginLineUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LoginLineUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLoginLineUpCBNotify(self,_hanlder)
	if nil ~= self.LoginLineUpCBNotifyCallBack then
		for i,callback in ipairs(self.LoginLineUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LoginLineUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLoginEnterGameCBNotify(self,_hanlder)
	if not self.LoginEnterGameCBNotifyCallBack then
		self.LoginEnterGameCBNotifyCallBack = {}
	end
	table.insert(self.LoginEnterGameCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LoginEnterGameCB(self,notifyMsg)
	if self.LoginEnterGameCBNotifyCallBack then
		local ret_msg = self.rpc_pb.LoginRpcLoginEnterGameNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LoginEnterGameCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLoginEnterGameCBNotify(self,_hanlder)
	if nil ~= self.LoginEnterGameCBNotifyCallBack then
		for i,callback in ipairs(self.LoginEnterGameCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LoginEnterGameCBNotifyCallBack, i )
			end
		end
	end
end


function registerDataCallback(self,_hanlder)
	if not self.DataCallback then
		self.DataCallback = {}
	end
	table.insert(self.DataCallback,_hanlder)
end

function unregisterDataCallback(self,_hanlder)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			if callback == _hanlder then
				table.remove(self.DataCallback, i )
			end
		end
	end
end

function GetValue(self, Id,Index )
	-- body
	
end

--[[
askList.Login = {}

local t = {}
t.name = "Login"
t.para = {{name="Username",t=2},{name="Passwd",t=2},{name="SnId",t=2},{name="GameId",t=2},{name="Mac",t=2},{name="Token",t=2},{name="Version",t=2}}
t.hand = LoginModel.Login
t.pb = LoginRpc_pb.LoginRpcLoginAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "SelectCharacter"
t.para = {{name="RoleId",t=1}}
t.hand = LoginModel.SelectCharacter
t.pb = LoginRpc_pb.LoginRpcSelectCharacterAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "CreateCharacter"
t.para = {{name="Nickname",t=2},{name="ConfigId",t=1},{name="PinchData",t=3},{name="PushRegId",t=2}}
t.hand = LoginModel.CreateCharacter
t.pb = LoginRpc_pb.LoginRpcCreateCharacterAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "DeleteCharacter"
t.para = {{name="RoleId",t=1}}
t.hand = LoginModel.DeleteCharacter
t.pb = LoginRpc_pb.LoginRpcDeleteCharacterAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "Test"
t.para = {{name="A",t=1},{name="B",t=1}}
t.hand = LoginModel.Test
t.pb = LoginRpc_pb.LoginRpcTestAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "Test1"
t.para = {{name="B",t=1}}
t.hand = LoginModel.Test1
t.pb = LoginRpc_pb.LoginRpcTest1Ask()
table.insert(askList.Login,t)

local t = {}
t.name = "LoginQuitLineUp"
t.para = {}
t.hand = LoginModel.LoginQuitLineUp
t.pb = LoginRpc_pb.LoginRpcLoginQuitLineUpAsk()
table.insert(askList.Login,t)

local t = {}
t.name = "RemoteLogin"
t.para = {{name="Roleid",t=1}}
t.hand = LoginModel.RemoteLogin
t.pb = LoginRpc_pb.LoginRpcRemoteLoginAsk()
table.insert(askList.Login,t)

--]]

