--将变量写入下方
local ModuleId = 18;
local RPC_CODE_EQUIPMENT_EQUIP_REQUEST = 1851
local RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST = 1852
local RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST = 1853
local RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST = 1854
local RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST = 1855
local RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST = 1856
local RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST = 1857
local RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST = 1858
local RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST = 1859
local RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST = 1860
local RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST = 1861
local RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST = 1862
local RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST = 1863
local RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST = 1864
local RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST = 1865





require("app.Equipment.EquipmentRpc_pb")

EquipmentModel = class("EquipmentModel",BaseModel)

function EquipmentModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=EquipmentModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function EquipmentModel:ctor()
	EquipmentModel.super.ctor(self)
	self.rpc_pb = EquipmentRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function EquipmentModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Equip(self,Pos,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipAsk()
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIP_REQUEST",RPC_CODE_EQUIPMENT_EQUIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => Equip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIP_REQUEST",RPC_CODE_EQUIPMENT_EQUIP_REQUEST)
end
function UnEquip(self,SlotType,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcUnEquipAsk()
	PB.SlotType = SlotType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST",RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcUnEquipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => UnEquip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST",RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST)
end
function SwitchEquipSet(self,To_index,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcSwitchEquipSetAsk()
	PB.To_index = To_index
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST",RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcSwitchEquipSetReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => SwitchEquipSet ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST",RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST)
end
function SyncEquip(self,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcSyncEquipAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST",RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcSyncEquipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => SyncEquip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST",RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST)
end
function ResonanceUnlock(self,ConfId,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcResonanceUnlockAsk()
	PB.ConfId = ConfId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST",RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcResonanceUnlockReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => ResonanceUnlock ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST",RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST)
end
function EquipDoResonance(self,ConfId,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipDoResonanceAsk()
	PB.ConfId = ConfId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipDoResonanceReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipDoResonance ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST)
end
function EquipResonanceSave(self,ConfId,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipResonanceSaveAsk()
	PB.ConfId = ConfId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipResonanceSaveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipResonanceSave ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST)
end
function EquipResonanceSync(self,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipResonanceSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipResonanceSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipResonanceSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST)
end
function EquipWashSync(self,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipWashSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipWashSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipWashSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST)
end
function EquipWash(self,Guid,LockedIndex,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipWashAsk()
	PB.Guid = Guid
	for i,v in ipairs(LockedIndex) do
		table.insert(PB.LockedIndex,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipWashReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipWash ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST)
end
function EquipWashSave(self,Guid,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipWashSaveAsk()
	PB.Guid = Guid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipWashSaveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipWashSave ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST",RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST)
end
function EquipBuildSync(self,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipBuildSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipBuildSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipBuildSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST",RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST)
end
function EquipBuild(self,Level,Occupation,Slot_type,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipBuildAsk()
	PB.Level = Level
	PB.Occupation = Occupation
	PB.Slot_type = Slot_type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST",RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipBuildReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipBuild ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST",RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST)
end
function GetPlayerInfo(self,Player_guid,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcGetPlayerInfoAsk()
	PB.Player_guid = Player_guid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST",RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcGetPlayerInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => GetPlayerInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST",RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST)
end
function EquipInherit(self,ToGuid,FromGuid,_hanlder)
	local PB = self.rpc_pb.EquipmentRpcEquipInheritAsk()
	PB.ToGuid = ToGuid
	PB.FromGuid = FromGuid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST",RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EquipmentRpcEquipInheritReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Equipment => EquipInherit ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST",RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST)
end








askList.Equipment = {}

local t = {}
t.name = "Equip"
t.para = {{name="Pos",t=1}}
t.hand = EquipmentModel.Equip
t.pb = EquipmentRpc_pb.EquipmentRpcEquipAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "UnEquip"
t.para = {{name="SlotType",t=1}}
t.hand = EquipmentModel.UnEquip
t.pb = EquipmentRpc_pb.EquipmentRpcUnEquipAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "SwitchEquipSet"
t.para = {{name="To_index",t=1}}
t.hand = EquipmentModel.SwitchEquipSet
t.pb = EquipmentRpc_pb.EquipmentRpcSwitchEquipSetAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "SyncEquip"
t.para = {}
t.hand = EquipmentModel.SyncEquip
t.pb = EquipmentRpc_pb.EquipmentRpcSyncEquipAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "ResonanceUnlock"
t.para = {{name="ConfId",t=1}}
t.hand = EquipmentModel.ResonanceUnlock
t.pb = EquipmentRpc_pb.EquipmentRpcResonanceUnlockAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipDoResonance"
t.para = {{name="ConfId",t=1}}
t.hand = EquipmentModel.EquipDoResonance
t.pb = EquipmentRpc_pb.EquipmentRpcEquipDoResonanceAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipResonanceSave"
t.para = {{name="ConfId",t=1}}
t.hand = EquipmentModel.EquipResonanceSave
t.pb = EquipmentRpc_pb.EquipmentRpcEquipResonanceSaveAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipResonanceSync"
t.para = {}
t.hand = EquipmentModel.EquipResonanceSync
t.pb = EquipmentRpc_pb.EquipmentRpcEquipResonanceSyncAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipWashSync"
t.para = {}
t.hand = EquipmentModel.EquipWashSync
t.pb = EquipmentRpc_pb.EquipmentRpcEquipWashSyncAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipWash"
t.para = {{name="Guid",t=1},{name="LockedIndex",t=1}}
t.hand = EquipmentModel.EquipWash
t.pb = EquipmentRpc_pb.EquipmentRpcEquipWashAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipWashSave"
t.para = {{name="Guid",t=1}}
t.hand = EquipmentModel.EquipWashSave
t.pb = EquipmentRpc_pb.EquipmentRpcEquipWashSaveAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipBuildSync"
t.para = {}
t.hand = EquipmentModel.EquipBuildSync
t.pb = EquipmentRpc_pb.EquipmentRpcEquipBuildSyncAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipBuild"
t.para = {{name="Level",t=1},{name="Occupation",t=1},{name="Slot_type",t=1}}
t.hand = EquipmentModel.EquipBuild
t.pb = EquipmentRpc_pb.EquipmentRpcEquipBuildAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "GetPlayerInfo"
t.para = {{name="Player_guid",t=1}}
t.hand = EquipmentModel.GetPlayerInfo
t.pb = EquipmentRpc_pb.EquipmentRpcGetPlayerInfoAsk()
table.insert(askList.Equipment,t)

local t = {}
t.name = "EquipInherit"
t.para = {{name="ToGuid",t=1},{name="FromGuid",t=1}}
t.hand = EquipmentModel.EquipInherit
t.pb = EquipmentRpc_pb.EquipmentRpcEquipInheritAsk()
table.insert(askList.Equipment,t)

