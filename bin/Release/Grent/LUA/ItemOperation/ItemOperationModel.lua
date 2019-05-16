--将变量写入下方
local ModuleId = 17;
local RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST = 1751
local RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST = 1752
local RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST = 1753
local RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST = 1754
local RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST = 1755





require("app.ItemOperation.ItemOperationRpc_pb")

ItemOperationModel = class("ItemOperationModel",BaseModel)

function ItemOperationModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ItemOperationModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ItemOperationModel:ctor()
	ItemOperationModel.super.ctor(self)
	self.rpc_pb = ItemOperationRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function ItemOperationModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ItemResolveSettingSync(self,_hanlder)
	local PB = self.rpc_pb.ItemOperationRpcItemResolveSettingSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST",RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ItemOperationRpcItemResolveSettingSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ItemOperation => ItemResolveSettingSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST",RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST)
end
function ItemResolve(self,ItemPos,Count,_hanlder)
	local PB = self.rpc_pb.ItemOperationRpcItemResolveAsk()
	PB.ItemPos = ItemPos
	PB.Count = Count
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST",RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ItemOperationRpcItemResolveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ItemOperation => ItemResolve ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST",RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST)
end
function ChangeSetting(self,SettingList,_hanlder)
	local PB = self.rpc_pb.ItemOperationRpcChangeSettingAsk()
	for i,v in ipairs(SettingList) do
		table.insert(PB.SettingList,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST",RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ItemOperationRpcChangeSettingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ItemOperation => ChangeSetting ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST",RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST)
end
function BatchResolve(self,Qulity,_hanlder)
	local PB = self.rpc_pb.ItemOperationRpcBatchResolveAsk()
	PB.Qulity = Qulity
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST",RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ItemOperationRpcBatchResolveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ItemOperation => BatchResolve ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST",RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST)
end
function ItemCompound(self,ItemConfID,_hanlder)
	local PB = self.rpc_pb.ItemOperationRpcItemCompoundAsk()
	PB.ItemConfID = ItemConfID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST",RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ItemOperationRpcItemCompoundReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[ItemOperation => ItemCompound ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST",RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST)
end








askList.ItemOperation = {}

local t = {}
t.name = "ItemResolveSettingSync"
t.para = {}
t.hand = ItemOperationModel.ItemResolveSettingSync
t.pb = ItemOperationRpc_pb.ItemOperationRpcItemResolveSettingSyncAsk()
table.insert(askList.ItemOperation,t)

local t = {}
t.name = "ItemResolve"
t.para = {{name="ItemPos",t=1},{name="Count",t=1}}
t.hand = ItemOperationModel.ItemResolve
t.pb = ItemOperationRpc_pb.ItemOperationRpcItemResolveAsk()
table.insert(askList.ItemOperation,t)

local t = {}
t.name = "ChangeSetting"
t.para = {{name="SettingList",t=3}}
t.hand = ItemOperationModel.ChangeSetting
t.pb = ItemOperationRpc_pb.ItemOperationRpcChangeSettingAsk()
table.insert(askList.ItemOperation,t)

local t = {}
t.name = "BatchResolve"
t.para = {{name="Qulity",t=1}}
t.hand = ItemOperationModel.BatchResolve
t.pb = ItemOperationRpc_pb.ItemOperationRpcBatchResolveAsk()
table.insert(askList.ItemOperation,t)

local t = {}
t.name = "ItemCompound"
t.para = {{name="ItemConfID",t=1}}
t.hand = ItemOperationModel.ItemCompound
t.pb = ItemOperationRpc_pb.ItemOperationRpcItemCompoundAsk()
table.insert(askList.ItemOperation,t)

