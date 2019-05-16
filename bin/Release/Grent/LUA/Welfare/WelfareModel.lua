--将变量写入下方
local ModuleId = 42;
local RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST = 4251
local RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST = 4252
local RPC_CODE_WELFARE_ONLINEBONUS_REQUEST = 4253
local RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST = 4254
local RPC_CODE_WELFARE_LEVELBONUS_REQUEST = 4255
local RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST = 4256
local RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST = 4257
local RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST = 4258
local RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY = 4259;
local RPC_CODE_WELFARE_SPECLOGIN_NOTIFY = 4260;
local RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST = 4261





require("app.Welfare.WelfareRpc_pb")

WelfareModel = class("WelfareModel",BaseModel)

function WelfareModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=WelfareModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function WelfareModel:ctor()
	WelfareModel.super.ctor(self)
	self.rpc_pb = WelfareRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY,handler(self,self.TodaySignInCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_WELFARE_SPECLOGIN_NOTIFY,handler(self,self.SpecLoginCB))

  


end

-- 更新数据
function WelfareModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function AccumulateSignIn(self,_hanlder)
	local PB = self.rpc_pb.WelfareRpcAccumulateSignInAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST",RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcAccumulateSignInReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => AccumulateSignIn ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST",RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST)
end
function AccumulateGetReward(self,ID,_hanlder)
	local PB = self.rpc_pb.WelfareRpcAccumulateGetRewardAsk()
	PB.ID = ID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST",RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcAccumulateGetRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => AccumulateGetReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST",RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST)
end
function OnlineBonus(self,_hanlder)
	local PB = self.rpc_pb.WelfareRpcOnlineBonusAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_ONLINEBONUS_REQUEST",RPC_CODE_WELFARE_ONLINEBONUS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcOnlineBonusReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => OnlineBonus ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_ONLINEBONUS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_ONLINEBONUS_REQUEST",RPC_CODE_WELFARE_ONLINEBONUS_REQUEST)
end
function OnlineGetReward(self,ID,_hanlder)
	local PB = self.rpc_pb.WelfareRpcOnlineGetRewardAsk()
	PB.ID = ID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST",RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcOnlineGetRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => OnlineGetReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST",RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST)
end
function LevelBonus(self,_hanlder)
	local PB = self.rpc_pb.WelfareRpcLevelBonusAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_LEVELBONUS_REQUEST",RPC_CODE_WELFARE_LEVELBONUS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcLevelBonusReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => LevelBonus ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_LEVELBONUS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_LEVELBONUS_REQUEST",RPC_CODE_WELFARE_LEVELBONUS_REQUEST)
end
function LevelBonusReward(self,ID,_hanlder)
	local PB = self.rpc_pb.WelfareRpcLevelBonusRewardAsk()
	PB.ID = ID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST",RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcLevelBonusRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => LevelBonusReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST",RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST)
end
function MonthSignInBonus(self,_hanlder)
	local PB = self.rpc_pb.WelfareRpcMonthSignInBonusAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST",RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcMonthSignInBonusReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => MonthSignInBonus ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST",RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST)
end
function MonthSignInReward(self,ID,_hanlder)
	local PB = self.rpc_pb.WelfareRpcMonthSignInRewardAsk()
	PB.ID = ID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST",RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcMonthSignInRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => MonthSignInReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST",RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST)
end
function SpecLoginReward(self,Id,Index,_hanlder)
	local PB = self.rpc_pb.WelfareRpcSpecLoginRewardAsk()
	PB.Id = Id
	PB.Index = Index
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST",RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WelfareRpcSpecLoginRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Welfare => SpecLoginReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST",RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerTodaySignInCBNotify(self,_hanlder)
	if not self.TodaySignInCBNotifyCallBack then
		self.TodaySignInCBNotifyCallBack = {}
	end
	table.insert(self.TodaySignInCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TodaySignInCB(self,notifyMsg)
	if self.TodaySignInCBNotifyCallBack then
		local ret_msg = self.rpc_pb.WelfareRpcTodaySignInNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TodaySignInCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTodaySignInCBNotify(self,_hanlder)
	if nil ~= self.TodaySignInCBNotifyCallBack then
		for i,callback in ipairs(self.TodaySignInCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TodaySignInCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSpecLoginCBNotify(self,_hanlder)
	if not self.SpecLoginCBNotifyCallBack then
		self.SpecLoginCBNotifyCallBack = {}
	end
	table.insert(self.SpecLoginCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SpecLoginCB(self,notifyMsg)
	if self.SpecLoginCBNotifyCallBack then
		local ret_msg = self.rpc_pb.WelfareRpcSpecLoginNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SpecLoginCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSpecLoginCBNotify(self,_hanlder)
	if nil ~= self.SpecLoginCBNotifyCallBack then
		for i,callback in ipairs(self.SpecLoginCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SpecLoginCBNotifyCallBack, i )
			end
		end
	end
end





askList.Welfare = {}

local t = {}
t.name = "AccumulateSignIn"
t.para = {}
t.hand = WelfareModel.AccumulateSignIn
t.pb = WelfareRpc_pb.WelfareRpcAccumulateSignInAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "AccumulateGetReward"
t.para = {{name="ID",t=1}}
t.hand = WelfareModel.AccumulateGetReward
t.pb = WelfareRpc_pb.WelfareRpcAccumulateGetRewardAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "OnlineBonus"
t.para = {}
t.hand = WelfareModel.OnlineBonus
t.pb = WelfareRpc_pb.WelfareRpcOnlineBonusAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "OnlineGetReward"
t.para = {{name="ID",t=1}}
t.hand = WelfareModel.OnlineGetReward
t.pb = WelfareRpc_pb.WelfareRpcOnlineGetRewardAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "LevelBonus"
t.para = {}
t.hand = WelfareModel.LevelBonus
t.pb = WelfareRpc_pb.WelfareRpcLevelBonusAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "LevelBonusReward"
t.para = {{name="ID",t=1}}
t.hand = WelfareModel.LevelBonusReward
t.pb = WelfareRpc_pb.WelfareRpcLevelBonusRewardAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "MonthSignInBonus"
t.para = {}
t.hand = WelfareModel.MonthSignInBonus
t.pb = WelfareRpc_pb.WelfareRpcMonthSignInBonusAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "MonthSignInReward"
t.para = {{name="ID",t=1}}
t.hand = WelfareModel.MonthSignInReward
t.pb = WelfareRpc_pb.WelfareRpcMonthSignInRewardAsk()
table.insert(askList.Welfare,t)

local t = {}
t.name = "SpecLoginReward"
t.para = {{name="Id",t=1},{name="Index",t=1}}
t.hand = WelfareModel.SpecLoginReward
t.pb = WelfareRpc_pb.WelfareRpcSpecLoginRewardAsk()
table.insert(askList.Welfare,t)

