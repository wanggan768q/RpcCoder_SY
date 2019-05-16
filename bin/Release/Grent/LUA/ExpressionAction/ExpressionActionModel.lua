--将变量写入下方
local ModuleId = 49;
local RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST = 4951
local RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST = 4952
local RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST = 4953
local RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY = 4954;





require("app.ExpressionAction.ExpressionActionRpc_pb")

ExpressionActionModel = class("ExpressionActionModel",BaseModel)

function ExpressionActionModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ExpressionActionModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ExpressionActionModel:ctor()
	ExpressionActionModel.super.ctor(self)
	self.rpc_pb = ExpressionActionRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY,handler(self,self.UseActionNotifyCB))

  


end

-- 更新数据
function ExpressionActionModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Sync(self,_hanlder)
	local PB = self.rpc_pb.ExpressionActionRpcSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST",RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ExpressionActionRpcSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ExpressionAction => Sync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST",RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST)
end
function SetWheel(self,Index,ActionId,_hanlder)
	local PB = self.rpc_pb.ExpressionActionRpcSetWheelAsk()
	PB.Index = Index
	PB.ActionId = ActionId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST",RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ExpressionActionRpcSetWheelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ExpressionAction => SetWheel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST",RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST)
end
function UseAction(self,ActionId,_hanlder)
	local PB = self.rpc_pb.ExpressionActionRpcUseActionAsk()
	PB.ActionId = ActionId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST",RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ExpressionActionRpcUseActionReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ExpressionAction => UseAction ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST",RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerUseActionNotifyCBNotify(self,_hanlder)
	if not self.UseActionNotifyCBNotifyCallBack then
		self.UseActionNotifyCBNotifyCallBack = {}
	end
	table.insert(self.UseActionNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UseActionNotifyCB(self,notifyMsg)
	if self.UseActionNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ExpressionActionRpcUseActionNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UseActionNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUseActionNotifyCBNotify(self,_hanlder)
	if nil ~= self.UseActionNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.UseActionNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UseActionNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.ExpressionAction = {}

local t = {}
t.name = "Sync"
t.para = {}
t.hand = ExpressionActionModel.Sync
t.pb = ExpressionActionRpc_pb.ExpressionActionRpcSyncAsk()
table.insert(askList.ExpressionAction,t)

local t = {}
t.name = "SetWheel"
t.para = {{name="Index",t=1},{name="ActionId",t=1}}
t.hand = ExpressionActionModel.SetWheel
t.pb = ExpressionActionRpc_pb.ExpressionActionRpcSetWheelAsk()
table.insert(askList.ExpressionAction,t)

local t = {}
t.name = "UseAction"
t.para = {{name="ActionId",t=1}}
t.hand = ExpressionActionModel.UseAction
t.pb = ExpressionActionRpc_pb.ExpressionActionRpcUseActionAsk()
table.insert(askList.ExpressionAction,t)

