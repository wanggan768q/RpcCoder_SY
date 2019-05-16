--将变量写入下方
local ModuleId = 54;
local RPC_CODE_REDDOT_SYNCREDDOT_REQUEST = 5451
local RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST = 5452
local RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY = 5453;





require("app.RedDot.RedDotRpc_pb")

RedDotModel = class("RedDotModel",BaseModel)

function RedDotModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=RedDotModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function RedDotModel:ctor()
	RedDotModel.super.ctor(self)
	self.rpc_pb = RedDotRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY,handler(self,self.UpdateRedDotCB))

  


end

-- 更新数据
function RedDotModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SyncRedDot(self,_hanlder)
	local PB = self.rpc_pb.RedDotRpcSyncRedDotAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_REDDOT_SYNCREDDOT_REQUEST",RPC_CODE_REDDOT_SYNCREDDOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.RedDotRpcSyncRedDotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[RedDot => SyncRedDot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_REDDOT_SYNCREDDOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_REDDOT_SYNCREDDOT_REQUEST",RPC_CODE_REDDOT_SYNCREDDOT_REQUEST)
end
function RemoveRedDot(self,Type,_hanlder)
	local PB = self.rpc_pb.RedDotRpcRemoveRedDotAsk()
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST",RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.RedDotRpcRemoveRedDotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[RedDot => RemoveRedDot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST",RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerUpdateRedDotCBNotify(self,_hanlder)
	if not self.UpdateRedDotCBNotifyCallBack then
		self.UpdateRedDotCBNotifyCallBack = {}
	end
	table.insert(self.UpdateRedDotCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateRedDotCB(self,notifyMsg)
	if self.UpdateRedDotCBNotifyCallBack then
		local ret_msg = self.rpc_pb.RedDotRpcUpdateRedDotNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateRedDotCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateRedDotCBNotify(self,_hanlder)
	if nil ~= self.UpdateRedDotCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateRedDotCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateRedDotCBNotifyCallBack, i )
			end
		end
	end
end





askList.RedDot = {}

local t = {}
t.name = "SyncRedDot"
t.para = {}
t.hand = RedDotModel.SyncRedDot
t.pb = RedDotRpc_pb.RedDotRpcSyncRedDotAsk()
table.insert(askList.RedDot,t)

local t = {}
t.name = "RemoveRedDot"
t.para = {{name="Type",t=1}}
t.hand = RedDotModel.RemoveRedDot
t.pb = RedDotRpc_pb.RedDotRpcRemoveRedDotAsk()
table.insert(askList.RedDot,t)

