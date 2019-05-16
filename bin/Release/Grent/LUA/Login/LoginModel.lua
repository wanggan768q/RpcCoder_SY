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





require("app.Login.LoginRpc_pb")

LoginModel = class("LoginModel",BaseModel)

function LoginModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=LoginModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function LoginModel:ctor()
	LoginModel.super.ctor(self)
	self.rpc_pb = LoginRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY,handler(self,self.LoginLineUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY,handler(self,self.LoginEnterGameCB))

  


end

-- 更新数据
function LoginModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Login(self,Username,Passwd,SnId,GameId,Mac,Token,_hanlder)
	local PB = self.rpc_pb.LoginRpcLoginAsk()
	PB.Username = Username
	PB.Passwd = Passwd
	PB.SnId = SnId
	PB.GameId = GameId
	PB.Mac = Mac
	PB.Token = Token
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOGIN_LOGIN_REQUEST",RPC_CODE_LOGIN_LOGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcLoginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => Login ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_LOGIN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_LOGIN_REQUEST",RPC_CODE_LOGIN_LOGIN_REQUEST)
end
function SelectCharacter(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcSelectCharacterAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST",RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcSelectCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => SelectCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST",RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST)
end
function CreateCharacter(self,Nickname,ConfigId,_hanlder)
	local PB = self.rpc_pb.LoginRpcCreateCharacterAsk()
	PB.Nickname = Nickname
	PB.ConfigId = ConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOGIN_CREATECHARACTER_REQUEST",RPC_CODE_LOGIN_CREATECHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcCreateCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => CreateCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_CREATECHARACTER_REQUEST",RPC_CODE_LOGIN_CREATECHARACTER_REQUEST)
end
function DeleteCharacter(self,RoleId,_hanlder)
	local PB = self.rpc_pb.LoginRpcDeleteCharacterAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOGIN_DELETECHARACTER_REQUEST",RPC_CODE_LOGIN_DELETECHARACTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcDeleteCharacterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => DeleteCharacter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_DELETECHARACTER_REQUEST",RPC_CODE_LOGIN_DELETECHARACTER_REQUEST)
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
		hideNetTip(self,"RPC_CODE_LOGIN_TEST_REQUEST",RPC_CODE_LOGIN_TEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcTestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => Test ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_TEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_TEST_REQUEST",RPC_CODE_LOGIN_TEST_REQUEST)
end
function Test1(self,B,_hanlder)
	local PB = self.rpc_pb.LoginRpcTest1Ask()
	for i,v in ipairs(B) do
		table.insert(PB.B,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOGIN_TEST1_REQUEST",RPC_CODE_LOGIN_TEST1_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcTest1Reply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Login => Test1 ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_TEST1_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOGIN_TEST1_REQUEST",RPC_CODE_LOGIN_TEST1_REQUEST)
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





askList.Login = {}

local t = {}
t.name = "Login"
t.para = {{name="Username",t=2},{name="Passwd",t=2},{name="SnId",t=2},{name="GameId",t=2},{name="Mac",t=2},{name="Token",t=2}}
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
t.para = {{name="Nickname",t=2},{name="ConfigId",t=1}}
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

