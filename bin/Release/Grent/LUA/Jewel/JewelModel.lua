--将变量写入下方
local ModuleId = 25;
local RPC_CODE_JEWEL_JEWELSYNC_REQUEST = 2551
local RPC_CODE_JEWEL_INSETJEWEL_REQUEST = 2552
local RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST = 2553
local RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST = 2554
local RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST = 2555
local RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST = 2556
local RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST = 2557





require("app.Jewel.JewelRpc_pb")

JewelModel = class("JewelModel",BaseModel)

function JewelModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=JewelModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function JewelModel:ctor()
	JewelModel.super.ctor(self)
	self.rpc_pb = JewelRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function JewelModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function JewelSync(self,_hanlder)
	local PB = self.rpc_pb.JewelRpcJewelSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_JEWELSYNC_REQUEST",RPC_CODE_JEWEL_JEWELSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcJewelSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => JewelSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_JEWELSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_JEWELSYNC_REQUEST",RPC_CODE_JEWEL_JEWELSYNC_REQUEST)
end
function InsetJewel(self,EquipSlot,JewelId,JewelSlot,_hanlder)
	local PB = self.rpc_pb.JewelRpcInsetJewelAsk()
	PB.EquipSlot = EquipSlot
	PB.JewelId = JewelId
	PB.JewelSlot = JewelSlot
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_INSETJEWEL_REQUEST",RPC_CODE_JEWEL_INSETJEWEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcInsetJewelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => InsetJewel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_INSETJEWEL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_INSETJEWEL_REQUEST",RPC_CODE_JEWEL_INSETJEWEL_REQUEST)
end
function RemoveJewel(self,EquipSlot,JewelSlot,_hanlder)
	local PB = self.rpc_pb.JewelRpcRemoveJewelAsk()
	PB.EquipSlot = EquipSlot
	PB.JewelSlot = JewelSlot
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST",RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcRemoveJewelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => RemoveJewel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST",RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST)
end
function CompoundJewel(self,JewelId,UseSafeItem,_hanlder)
	local PB = self.rpc_pb.JewelRpcCompoundJewelAsk()
	PB.JewelId = JewelId
	PB.UseSafeItem = UseSafeItem
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST",RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcCompoundJewelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => CompoundJewel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST",RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST)
end
function CompoundSetJewel(self,EquipType,JewelSlot,_hanlder)
	local PB = self.rpc_pb.JewelRpcCompoundSetJewelAsk()
	PB.EquipType = EquipType
	PB.JewelSlot = JewelSlot
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST",RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcCompoundSetJewelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => CompoundSetJewel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST",RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST)
end
function UnlockJewelSlot(self,EquipSlot,JewelSlot,_hanlder)
	local PB = self.rpc_pb.JewelRpcUnlockJewelSlotAsk()
	PB.EquipSlot = EquipSlot
	PB.JewelSlot = JewelSlot
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST",RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcUnlockJewelSlotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => UnlockJewelSlot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST",RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST)
end
function QuickCompound(self,JewelId,_hanlder)
	local PB = self.rpc_pb.JewelRpcQuickCompoundAsk()
	PB.JewelId = JewelId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST",RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.JewelRpcQuickCompoundReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Jewel => QuickCompound ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST",RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST)
end








askList.Jewel = {}

local t = {}
t.name = "JewelSync"
t.para = {}
t.hand = JewelModel.JewelSync
t.pb = JewelRpc_pb.JewelRpcJewelSyncAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "InsetJewel"
t.para = {{name="EquipSlot",t=1},{name="JewelId",t=1},{name="JewelSlot",t=1}}
t.hand = JewelModel.InsetJewel
t.pb = JewelRpc_pb.JewelRpcInsetJewelAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "RemoveJewel"
t.para = {{name="EquipSlot",t=1},{name="JewelSlot",t=1}}
t.hand = JewelModel.RemoveJewel
t.pb = JewelRpc_pb.JewelRpcRemoveJewelAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "CompoundJewel"
t.para = {{name="JewelId",t=1},{name="UseSafeItem",t=3}}
t.hand = JewelModel.CompoundJewel
t.pb = JewelRpc_pb.JewelRpcCompoundJewelAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "CompoundSetJewel"
t.para = {{name="EquipType",t=1},{name="JewelSlot",t=1}}
t.hand = JewelModel.CompoundSetJewel
t.pb = JewelRpc_pb.JewelRpcCompoundSetJewelAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "UnlockJewelSlot"
t.para = {{name="EquipSlot",t=1},{name="JewelSlot",t=1}}
t.hand = JewelModel.UnlockJewelSlot
t.pb = JewelRpc_pb.JewelRpcUnlockJewelSlotAsk()
table.insert(askList.Jewel,t)

local t = {}
t.name = "QuickCompound"
t.para = {{name="JewelId",t=1}}
t.hand = JewelModel.QuickCompound
t.pb = JewelRpc_pb.JewelRpcQuickCompoundAsk()
table.insert(askList.Jewel,t)

