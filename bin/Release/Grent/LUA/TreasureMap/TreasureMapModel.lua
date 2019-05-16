--将变量写入下方
local ModuleId = 35;
local RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST = 3551
local RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY = 3552;





require("app.TreasureMap.TreasureMapRpc_pb")

TreasureMapModel = class("TreasureMapModel",BaseModel)

function TreasureMapModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TreasureMapModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TreasureMapModel:ctor()
	TreasureMapModel.super.ctor(self)
	self.rpc_pb = TreasureMapRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY,handler(self,self.TreasureMapChangeCB))

  


end

-- 更新数据
function TreasureMapModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TreasureMapSync(self,_hanlder)
	local PB = self.rpc_pb.TreasureMapRpcTreasureMapSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST",RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureMapRpcTreasureMapSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[TreasureMap => TreasureMapSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST",RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerTreasureMapChangeCBNotify(self,_hanlder)
	if not self.TreasureMapChangeCBNotifyCallBack then
		self.TreasureMapChangeCBNotifyCallBack = {}
	end
	table.insert(self.TreasureMapChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TreasureMapChangeCB(self,notifyMsg)
	if self.TreasureMapChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TreasureMapRpcTreasureMapChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TreasureMapChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTreasureMapChangeCBNotify(self,_hanlder)
	if nil ~= self.TreasureMapChangeCBNotifyCallBack then
		for i,callback in ipairs(self.TreasureMapChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TreasureMapChangeCBNotifyCallBack, i )
			end
		end
	end
end





askList.TreasureMap = {}

local t = {}
t.name = "TreasureMapSync"
t.para = {}
t.hand = TreasureMapModel.TreasureMapSync
t.pb = TreasureMapRpc_pb.TreasureMapRpcTreasureMapSyncAsk()
table.insert(askList.TreasureMap,t)

