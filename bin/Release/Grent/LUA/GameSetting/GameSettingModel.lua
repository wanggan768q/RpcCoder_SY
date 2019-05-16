--将变量写入下方
local ModuleId = 53;
local RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST = 5351
local RPC_CODE_GAMESETTING_SETTING_REQUEST = 5352
local RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY = 5353;





require("app.GameSetting.GameSettingRpc_pb")

GameSettingModel = class("GameSettingModel",BaseModel)

function GameSettingModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GameSettingModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function GameSettingModel:ctor()
	GameSettingModel.super.ctor(self)
	self.rpc_pb = GameSettingRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY,handler(self,self.GameSettingNotifyCB))

  


end

-- 更新数据
function GameSettingModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SyncGameSetting(self,_hanlder)
	local PB = self.rpc_pb.GameSettingRpcSyncGameSettingAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST",RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GameSettingRpcSyncGameSettingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[GameSetting => SyncGameSetting ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST",RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST)
end
function Setting(self,GameSetting,_hanlder)
	local PB = self.rpc_pb.GameSettingRpcSettingAsk()
	PB.GameSetting = GameSetting
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GAMESETTING_SETTING_REQUEST",RPC_CODE_GAMESETTING_SETTING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GameSettingRpcSettingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[GameSetting => Setting ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GAMESETTING_SETTING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GAMESETTING_SETTING_REQUEST",RPC_CODE_GAMESETTING_SETTING_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerGameSettingNotifyCBNotify(self,_hanlder)
	if not self.GameSettingNotifyCBNotifyCallBack then
		self.GameSettingNotifyCBNotifyCallBack = {}
	end
	table.insert(self.GameSettingNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GameSettingNotifyCB(self,notifyMsg)
	if self.GameSettingNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GameSettingRpcGameSettingNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.GameSettingNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterGameSettingNotifyCBNotify(self,_hanlder)
	if nil ~= self.GameSettingNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.GameSettingNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.GameSettingNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.GameSetting = {}

local t = {}
t.name = "SyncGameSetting"
t.para = {}
t.hand = GameSettingModel.SyncGameSetting
t.pb = GameSettingRpc_pb.GameSettingRpcSyncGameSettingAsk()
table.insert(askList.GameSetting,t)

local t = {}
t.name = "Setting"
t.para = {{name="GameSetting",t=2}}
t.hand = GameSettingModel.Setting
t.pb = GameSettingRpc_pb.GameSettingRpcSettingAsk()
table.insert(askList.GameSetting,t)

