--将变量写入下方
local ModuleId = 28;
local RPC_CODE_MEDICAMENT_FILLHP_REQUEST = 2851
local RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST = 2852
local RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST = 2853
local RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY = 2854;
local RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST = 2855
local RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST = 2856
local RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY = 2857;





require("app.Medicament.MedicamentRpc_pb")

MedicamentModel = class("MedicamentModel",BaseModel)

function MedicamentModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MedicamentModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MedicamentModel:ctor()
	MedicamentModel.super.ctor(self)
	self.rpc_pb = MedicamentRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY,handler(self,self.ServerRefreshMedicamentCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY,handler(self,self.MedicamentCDNotifyCB))

  


end

-- 更新数据
function MedicamentModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function FillHp(self,ItemData,_hanlder)
	local PB = self.rpc_pb.MedicamentRpcFillHpAsk()
	PB.ItemData.ConfID = ItemData.ConfID
	PB.ItemData.Count = ItemData.Count
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MEDICAMENT_FILLHP_REQUEST",RPC_CODE_MEDICAMENT_FILLHP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MedicamentRpcFillHpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Medicament => FillHp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MEDICAMENT_FILLHP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MEDICAMENT_FILLHP_REQUEST",RPC_CODE_MEDICAMENT_FILLHP_REQUEST)
end
function OneStepFillHp(self,ItemData,_hanlder)
	local PB = self.rpc_pb.MedicamentRpcOneStepFillHpAsk()
	for i,v in ipairs(ItemData) do
		table.insert(PB.ItemData,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST",RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MedicamentRpcOneStepFillHpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Medicament => OneStepFillHp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST",RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST)
end
function ClientRefreshMedicament(self,Medicament,_hanlder)
	local PB = self.rpc_pb.MedicamentRpcClientRefreshMedicamentAsk()
	for i = 1, #Medicament.HpMedicamentList do
		table.insert( PB.Medicament.HpMedicamentList,Medicament.HpMedicamentList[i] )
	end
	PB.Medicament.AutoHpMedicament = Medicament.AutoHpMedicament
	PB.Medicament.HpPercentage = Medicament.HpPercentage
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST",RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MedicamentRpcClientRefreshMedicamentReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Medicament => ClientRefreshMedicament ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST",RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST)
end
function SyncMedicamentData(self,_hanlder)
	local PB = self.rpc_pb.MedicamentRpcSyncMedicamentDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST",RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MedicamentRpcSyncMedicamentDataReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Medicament => SyncMedicamentData ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST",RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST)
end
function MedicamentCD(self,_hanlder)
	local PB = self.rpc_pb.MedicamentRpcMedicamentCDAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST",RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MedicamentRpcMedicamentCDReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Medicament => MedicamentCD ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST",RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerServerRefreshMedicamentCBNotify(self,_hanlder)
	if not self.ServerRefreshMedicamentCBNotifyCallBack then
		self.ServerRefreshMedicamentCBNotifyCallBack = {}
	end
	table.insert(self.ServerRefreshMedicamentCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ServerRefreshMedicamentCB(self,notifyMsg)
	if self.ServerRefreshMedicamentCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MedicamentRpcServerRefreshMedicamentNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ServerRefreshMedicamentCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterServerRefreshMedicamentCBNotify(self,_hanlder)
	if nil ~= self.ServerRefreshMedicamentCBNotifyCallBack then
		for i,callback in ipairs(self.ServerRefreshMedicamentCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ServerRefreshMedicamentCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerMedicamentCDNotifyCBNotify(self,_hanlder)
	if not self.MedicamentCDNotifyCBNotifyCallBack then
		self.MedicamentCDNotifyCBNotifyCallBack = {}
	end
	table.insert(self.MedicamentCDNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MedicamentCDNotifyCB(self,notifyMsg)
	if self.MedicamentCDNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MedicamentRpcMedicamentCDNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MedicamentCDNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMedicamentCDNotifyCBNotify(self,_hanlder)
	if nil ~= self.MedicamentCDNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.MedicamentCDNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MedicamentCDNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.Medicament = {}

local t = {}
t.name = "FillHp"
t.para = {{name="ItemData",t=3}}
t.hand = MedicamentModel.FillHp
t.pb = MedicamentRpc_pb.MedicamentRpcFillHpAsk()
table.insert(askList.Medicament,t)

local t = {}
t.name = "OneStepFillHp"
t.para = {{name="ItemData",t=3}}
t.hand = MedicamentModel.OneStepFillHp
t.pb = MedicamentRpc_pb.MedicamentRpcOneStepFillHpAsk()
table.insert(askList.Medicament,t)

local t = {}
t.name = "ClientRefreshMedicament"
t.para = {{name="Medicament",t=3}}
t.hand = MedicamentModel.ClientRefreshMedicament
t.pb = MedicamentRpc_pb.MedicamentRpcClientRefreshMedicamentAsk()
table.insert(askList.Medicament,t)

local t = {}
t.name = "SyncMedicamentData"
t.para = {}
t.hand = MedicamentModel.SyncMedicamentData
t.pb = MedicamentRpc_pb.MedicamentRpcSyncMedicamentDataAsk()
table.insert(askList.Medicament,t)

local t = {}
t.name = "MedicamentCD"
t.para = {}
t.hand = MedicamentModel.MedicamentCD
t.pb = MedicamentRpc_pb.MedicamentRpcMedicamentCDAsk()
table.insert(askList.Medicament,t)

