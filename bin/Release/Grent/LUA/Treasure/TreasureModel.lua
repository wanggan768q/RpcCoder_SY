--将变量写入下方
local ModuleId = 32;
local RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST = 3251
local RPC_CODE_TREASURE_TREASUREINFO_REQUEST = 3252
local RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST = 3253
local RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST = 3254
local RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST = 3255
local RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST = 3256
local RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST = 3257
local RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY = 3258;
local RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST = 3259
local RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY = 3260;





require("app.Treasure.TreasureRpc_pb")

TreasureModel = class("TreasureModel",BaseModel)

function TreasureModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TreasureModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TreasureModel:ctor()
	TreasureModel.super.ctor(self)
	self.rpc_pb = TreasureRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY,handler(self,self.TreasureEquipedIDCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY,handler(self,self.TreasureUnlockEquipCB))

  


end

-- 更新数据
function TreasureModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TreasureDepotInfo(self,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureDepotInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST",RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureDepotInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureDepotInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST",RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST)
end
function TreasureInfo(self,Type,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureInfoAsk()
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREINFO_REQUEST",RPC_CODE_TREASURE_TREASUREINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREINFO_REQUEST",RPC_CODE_TREASURE_TREASUREINFO_REQUEST)
end
function TreasureUnlock(self,Id,Color_Type,Time_Type,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureUnlockAsk()
	PB.Id = Id
	PB.Color_Type = Color_Type
	PB.Time_Type = Time_Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST",RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureUnlockReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureUnlock ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST",RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST)
end
function TreasureEquip(self,Id,Color_Type,Time_Type,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureEquipAsk()
	PB.Id = Id
	PB.Color_Type = Color_Type
	PB.Time_Type = Time_Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST",RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureEquipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureEquip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST",RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST)
end
function TreasureEquipSyc(self,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureEquipSycAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST",RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureEquipSycReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureEquipSyc ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST",RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST)
end
function TreasureDepotLvUp(self,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureDepotLvUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST",RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureDepotLvUpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureDepotLvUp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST",RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST)
end
function TreasureUnEquip(self,Id,Color_Type,Time_Type,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureUnEquipAsk()
	PB.Id = Id
	PB.Color_Type = Color_Type
	PB.Time_Type = Time_Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST",RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureUnEquipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureUnEquip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST",RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST)
end
function TreasureDelayTime(self,Id,Color_Type,Time_Type,_hanlder)
	local PB = self.rpc_pb.TreasureRpcTreasureDelayTimeAsk()
	PB.Id = Id
	PB.Color_Type = Color_Type
	PB.Time_Type = Time_Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST",RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TreasureRpcTreasureDelayTimeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Treasure => TreasureDelayTime ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST",RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerTreasureEquipedIDCBNotify(self,_hanlder)
	if not self.TreasureEquipedIDCBNotifyCallBack then
		self.TreasureEquipedIDCBNotifyCallBack = {}
	end
	table.insert(self.TreasureEquipedIDCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TreasureEquipedIDCB(self,notifyMsg)
	if self.TreasureEquipedIDCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TreasureRpcTreasureEquipedIDNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TreasureEquipedIDCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTreasureEquipedIDCBNotify(self,_hanlder)
	if nil ~= self.TreasureEquipedIDCBNotifyCallBack then
		for i,callback in ipairs(self.TreasureEquipedIDCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TreasureEquipedIDCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerTreasureUnlockEquipCBNotify(self,_hanlder)
	if not self.TreasureUnlockEquipCBNotifyCallBack then
		self.TreasureUnlockEquipCBNotifyCallBack = {}
	end
	table.insert(self.TreasureUnlockEquipCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TreasureUnlockEquipCB(self,notifyMsg)
	if self.TreasureUnlockEquipCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TreasureRpcTreasureUnlockEquipNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TreasureUnlockEquipCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTreasureUnlockEquipCBNotify(self,_hanlder)
	if nil ~= self.TreasureUnlockEquipCBNotifyCallBack then
		for i,callback in ipairs(self.TreasureUnlockEquipCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TreasureUnlockEquipCBNotifyCallBack, i )
			end
		end
	end
end





askList.Treasure = {}

local t = {}
t.name = "TreasureDepotInfo"
t.para = {}
t.hand = TreasureModel.TreasureDepotInfo
t.pb = TreasureRpc_pb.TreasureRpcTreasureDepotInfoAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureInfo"
t.para = {{name="Type",t=1}}
t.hand = TreasureModel.TreasureInfo
t.pb = TreasureRpc_pb.TreasureRpcTreasureInfoAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureUnlock"
t.para = {{name="Id",t=1},{name="Color_Type",t=1},{name="Time_Type",t=1}}
t.hand = TreasureModel.TreasureUnlock
t.pb = TreasureRpc_pb.TreasureRpcTreasureUnlockAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureEquip"
t.para = {{name="Id",t=1},{name="Color_Type",t=1},{name="Time_Type",t=1}}
t.hand = TreasureModel.TreasureEquip
t.pb = TreasureRpc_pb.TreasureRpcTreasureEquipAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureEquipSyc"
t.para = {}
t.hand = TreasureModel.TreasureEquipSyc
t.pb = TreasureRpc_pb.TreasureRpcTreasureEquipSycAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureDepotLvUp"
t.para = {}
t.hand = TreasureModel.TreasureDepotLvUp
t.pb = TreasureRpc_pb.TreasureRpcTreasureDepotLvUpAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureUnEquip"
t.para = {{name="Id",t=1},{name="Color_Type",t=1},{name="Time_Type",t=1}}
t.hand = TreasureModel.TreasureUnEquip
t.pb = TreasureRpc_pb.TreasureRpcTreasureUnEquipAsk()
table.insert(askList.Treasure,t)

local t = {}
t.name = "TreasureDelayTime"
t.para = {{name="Id",t=1},{name="Color_Type",t=1},{name="Time_Type",t=1}}
t.hand = TreasureModel.TreasureDelayTime
t.pb = TreasureRpc_pb.TreasureRpcTreasureDelayTimeAsk()
table.insert(askList.Treasure,t)

