--将变量写入下方
local ModuleId = 27;
local RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST = 2751
local RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST = 2752
local RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST = 2753
local RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST = 2754





require("app.EquipSlot.EquipSlotRpc_pb")

EquipSlotModel = class("EquipSlotModel",BaseModel)

function EquipSlotModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=EquipSlotModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function EquipSlotModel:ctor()
	EquipSlotModel.super.ctor(self)
	self.rpc_pb = EquipSlotRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function EquipSlotModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SyncEquipSlot(self,_hanlder)
	local PB = self.rpc_pb.EquipSlotRpcSyncEquipSlotAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipSlotRpcSyncEquipSlotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EquipSlot => SyncEquipSlot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST)
end
function EnhanceEquipSlot(self,Slot_Type,CostItemList,_hanlder)
	local PB = self.rpc_pb.EquipSlotRpcEnhanceEquipSlotAsk()
	PB.Slot_Type = Slot_Type
	for i,v in ipairs(CostItemList) do
		table.insert(PB.CostItemList,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipSlotRpcEnhanceEquipSlotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EquipSlot => EnhanceEquipSlot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST)
end
function SyncEquipSlotStar(self,_hanlder)
	local PB = self.rpc_pb.EquipSlotRpcSyncEquipSlotStarAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST",RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipSlotRpcSyncEquipSlotStarReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EquipSlot => SyncEquipSlotStar ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST",RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST)
end
function UpStarEquipSlot(self,Slot_Type,IsProtection,_hanlder)
	local PB = self.rpc_pb.EquipSlotRpcUpStarEquipSlotAsk()
	PB.Slot_Type = Slot_Type
	PB.IsProtection = IsProtection
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipSlotRpcUpStarEquipSlotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EquipSlot => UpStarEquipSlot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST",RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST)
end








askList.EquipSlot = {}

local t = {}
t.name = "SyncEquipSlot"
t.para = {}
t.hand = EquipSlotModel.SyncEquipSlot
t.pb = EquipSlotRpc_pb.EquipSlotRpcSyncEquipSlotAsk()
table.insert(askList.EquipSlot,t)

local t = {}
t.name = "EnhanceEquipSlot"
t.para = {{name="Slot_Type",t=1},{name="CostItemList",t=3}}
t.hand = EquipSlotModel.EnhanceEquipSlot
t.pb = EquipSlotRpc_pb.EquipSlotRpcEnhanceEquipSlotAsk()
table.insert(askList.EquipSlot,t)

local t = {}
t.name = "SyncEquipSlotStar"
t.para = {}
t.hand = EquipSlotModel.SyncEquipSlotStar
t.pb = EquipSlotRpc_pb.EquipSlotRpcSyncEquipSlotStarAsk()
table.insert(askList.EquipSlot,t)

local t = {}
t.name = "UpStarEquipSlot"
t.para = {{name="Slot_Type",t=1},{name="IsProtection",t=3}}
t.hand = EquipSlotModel.UpStarEquipSlot
t.pb = EquipSlotRpc_pb.EquipSlotRpcUpStarEquipSlotAsk()
table.insert(askList.EquipSlot,t)

