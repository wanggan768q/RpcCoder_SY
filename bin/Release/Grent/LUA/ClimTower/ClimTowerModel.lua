--将变量写入下方
local ModuleId = 47;
local RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY = 4751;
local RPC_CODE_CLIMTOWER_ENTER_REQUEST = 4752
local RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST = 4753
local RPC_CODE_CLIMTOWER_RANK_REQUEST = 4754
local RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST = 4755
local RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY = 4756;
local RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY = 4757;
local RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY = 4758;





require("app.ClimTower.ClimTowerRpc_pb")

ClimTowerModel = class("ClimTowerModel",BaseModel)

function ClimTowerModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ClimTowerModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ClimTowerModel:ctor()
	ClimTowerModel.super.ctor(self)
	self.rpc_pb = ClimTowerRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY,handler(self,self.OpenRuleCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY,handler(self,self.NextLayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY,handler(self,self.ChallengeEndCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY,handler(self,self.WaveRefreshCB))

  


end

-- 更新数据
function ClimTowerModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Enter(self,_hanlder)
	local PB = self.rpc_pb.ClimTowerRpcEnterAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CLIMTOWER_ENTER_REQUEST",RPC_CODE_CLIMTOWER_ENTER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ClimTowerRpcEnterReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ClimTower => Enter ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CLIMTOWER_ENTER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CLIMTOWER_ENTER_REQUEST",RPC_CODE_CLIMTOWER_ENTER_REQUEST)
end
function Challenge(self,Layer,_hanlder)
	local PB = self.rpc_pb.ClimTowerRpcChallengeAsk()
	PB.Layer = Layer
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST",RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ClimTowerRpcChallengeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ClimTower => Challenge ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST",RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST)
end
function Rank(self,_hanlder)
	local PB = self.rpc_pb.ClimTowerRpcRankAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CLIMTOWER_RANK_REQUEST",RPC_CODE_CLIMTOWER_RANK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ClimTowerRpcRankReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ClimTower => Rank ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CLIMTOWER_RANK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CLIMTOWER_RANK_REQUEST",RPC_CODE_CLIMTOWER_RANK_REQUEST)
end
function FirstVicReward(self,Layer,_hanlder)
	local PB = self.rpc_pb.ClimTowerRpcFirstVicRewardAsk()
	PB.Layer = Layer
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST",RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ClimTowerRpcFirstVicRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ClimTower => FirstVicReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST",RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerOpenRuleCBNotify(self,_hanlder)
	if not self.OpenRuleCBNotifyCallBack then
		self.OpenRuleCBNotifyCallBack = {}
	end
	table.insert(self.OpenRuleCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OpenRuleCB(self,notifyMsg)
	if self.OpenRuleCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ClimTowerRpcOpenRuleNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OpenRuleCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOpenRuleCBNotify(self,_hanlder)
	if nil ~= self.OpenRuleCBNotifyCallBack then
		for i,callback in ipairs(self.OpenRuleCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OpenRuleCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNextLayerCBNotify(self,_hanlder)
	if not self.NextLayerCBNotifyCallBack then
		self.NextLayerCBNotifyCallBack = {}
	end
	table.insert(self.NextLayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NextLayerCB(self,notifyMsg)
	if self.NextLayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ClimTowerRpcNextLayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NextLayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNextLayerCBNotify(self,_hanlder)
	if nil ~= self.NextLayerCBNotifyCallBack then
		for i,callback in ipairs(self.NextLayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NextLayerCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChallengeEndCBNotify(self,_hanlder)
	if not self.ChallengeEndCBNotifyCallBack then
		self.ChallengeEndCBNotifyCallBack = {}
	end
	table.insert(self.ChallengeEndCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChallengeEndCB(self,notifyMsg)
	if self.ChallengeEndCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ClimTowerRpcChallengeEndNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChallengeEndCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChallengeEndCBNotify(self,_hanlder)
	if nil ~= self.ChallengeEndCBNotifyCallBack then
		for i,callback in ipairs(self.ChallengeEndCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChallengeEndCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerWaveRefreshCBNotify(self,_hanlder)
	if not self.WaveRefreshCBNotifyCallBack then
		self.WaveRefreshCBNotifyCallBack = {}
	end
	table.insert(self.WaveRefreshCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function WaveRefreshCB(self,notifyMsg)
	if self.WaveRefreshCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ClimTowerRpcWaveRefreshNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.WaveRefreshCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterWaveRefreshCBNotify(self,_hanlder)
	if nil ~= self.WaveRefreshCBNotifyCallBack then
		for i,callback in ipairs(self.WaveRefreshCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.WaveRefreshCBNotifyCallBack, i )
			end
		end
	end
end





askList.ClimTower = {}

local t = {}
t.name = "Enter"
t.para = {}
t.hand = ClimTowerModel.Enter
t.pb = ClimTowerRpc_pb.ClimTowerRpcEnterAsk()
table.insert(askList.ClimTower,t)

local t = {}
t.name = "Challenge"
t.para = {{name="Layer",t=1}}
t.hand = ClimTowerModel.Challenge
t.pb = ClimTowerRpc_pb.ClimTowerRpcChallengeAsk()
table.insert(askList.ClimTower,t)

local t = {}
t.name = "Rank"
t.para = {}
t.hand = ClimTowerModel.Rank
t.pb = ClimTowerRpc_pb.ClimTowerRpcRankAsk()
table.insert(askList.ClimTower,t)

local t = {}
t.name = "FirstVicReward"
t.para = {{name="Layer",t=1}}
t.hand = ClimTowerModel.FirstVicReward
t.pb = ClimTowerRpc_pb.ClimTowerRpcFirstVicRewardAsk()
table.insert(askList.ClimTower,t)

