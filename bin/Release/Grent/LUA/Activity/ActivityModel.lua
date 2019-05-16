--将变量写入下方
local ModuleId = 24;
local RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY = 2451;
local RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST = 2452
local RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY = 2453;
local RPC_CODE_ACTIVITY_XINGYAO_REQUEST = 2454
local RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY = 2455;
local RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST = 2456
local RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST = 2457
local RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY = 2458;
local RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY = 2459;





require("app.Activity.ActivityRpc_pb")

ActivityModel = class("ActivityModel",BaseModel)

function ActivityModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActivityModel:ctor()
	ActivityModel.super.ctor(self)
	self.rpc_pb = ActivityRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY,handler(self,self.EliteMonsterInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY,handler(self,self.OpenActivityCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY,handler(self,self.ActivityTimeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY,handler(self,self.XingyaoRewardCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY,handler(self,self.OperationTimeCB))

  


end

-- 更新数据
function ActivityModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function CreateObj(self,CommonId,_hanlder)
	local PB = self.rpc_pb.ActivityRpcCreateObjAsk()
	PB.CommonId = CommonId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST",RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityRpcCreateObjReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Activity => CreateObj ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST",RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST)
end
function Xingyao(self,NPCid,_hanlder)
	local PB = self.rpc_pb.ActivityRpcXingyaoAsk()
	PB.NPCid = NPCid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ACTIVITY_XINGYAO_REQUEST",RPC_CODE_ACTIVITY_XINGYAO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityRpcXingyaoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Activity => Xingyao ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITY_XINGYAO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ACTIVITY_XINGYAO_REQUEST",RPC_CODE_ACTIVITY_XINGYAO_REQUEST)
end
function ReqActivityTime(self,_hanlder)
	local PB = self.rpc_pb.ActivityRpcReqActivityTimeAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST",RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityRpcReqActivityTimeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Activity => ReqActivityTime ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST",RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST)
end
function XingyaoNPC(self,_hanlder)
	local PB = self.rpc_pb.ActivityRpcXingyaoNPCAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST",RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityRpcXingyaoNPCReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Activity => XingyaoNPC ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST",RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerEliteMonsterInfoCBNotify(self,_hanlder)
	if not self.EliteMonsterInfoCBNotifyCallBack then
		self.EliteMonsterInfoCBNotifyCallBack = {}
	end
	table.insert(self.EliteMonsterInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function EliteMonsterInfoCB(self,notifyMsg)
	if self.EliteMonsterInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityRpcEliteMonsterInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.EliteMonsterInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterEliteMonsterInfoCBNotify(self,_hanlder)
	if nil ~= self.EliteMonsterInfoCBNotifyCallBack then
		for i,callback in ipairs(self.EliteMonsterInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.EliteMonsterInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerOpenActivityCBNotify(self,_hanlder)
	if not self.OpenActivityCBNotifyCallBack then
		self.OpenActivityCBNotifyCallBack = {}
	end
	table.insert(self.OpenActivityCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OpenActivityCB(self,notifyMsg)
	if self.OpenActivityCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityRpcOpenActivityNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OpenActivityCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOpenActivityCBNotify(self,_hanlder)
	if nil ~= self.OpenActivityCBNotifyCallBack then
		for i,callback in ipairs(self.OpenActivityCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OpenActivityCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerActivityTimeCBNotify(self,_hanlder)
	if not self.ActivityTimeCBNotifyCallBack then
		self.ActivityTimeCBNotifyCallBack = {}
	end
	table.insert(self.ActivityTimeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityTimeCB(self,notifyMsg)
	if self.ActivityTimeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityRpcActivityTimeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ActivityTimeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterActivityTimeCBNotify(self,_hanlder)
	if nil ~= self.ActivityTimeCBNotifyCallBack then
		for i,callback in ipairs(self.ActivityTimeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ActivityTimeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerXingyaoRewardCBNotify(self,_hanlder)
	if not self.XingyaoRewardCBNotifyCallBack then
		self.XingyaoRewardCBNotifyCallBack = {}
	end
	table.insert(self.XingyaoRewardCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function XingyaoRewardCB(self,notifyMsg)
	if self.XingyaoRewardCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityRpcXingyaoRewardNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.XingyaoRewardCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterXingyaoRewardCBNotify(self,_hanlder)
	if nil ~= self.XingyaoRewardCBNotifyCallBack then
		for i,callback in ipairs(self.XingyaoRewardCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.XingyaoRewardCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerOperationTimeCBNotify(self,_hanlder)
	if not self.OperationTimeCBNotifyCallBack then
		self.OperationTimeCBNotifyCallBack = {}
	end
	table.insert(self.OperationTimeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OperationTimeCB(self,notifyMsg)
	if self.OperationTimeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityRpcOperationTimeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OperationTimeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOperationTimeCBNotify(self,_hanlder)
	if nil ~= self.OperationTimeCBNotifyCallBack then
		for i,callback in ipairs(self.OperationTimeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OperationTimeCBNotifyCallBack, i )
			end
		end
	end
end





askList.Activity = {}

local t = {}
t.name = "CreateObj"
t.para = {{name="CommonId",t=1}}
t.hand = ActivityModel.CreateObj
t.pb = ActivityRpc_pb.ActivityRpcCreateObjAsk()
table.insert(askList.Activity,t)

local t = {}
t.name = "Xingyao"
t.para = {{name="NPCid",t=1}}
t.hand = ActivityModel.Xingyao
t.pb = ActivityRpc_pb.ActivityRpcXingyaoAsk()
table.insert(askList.Activity,t)

local t = {}
t.name = "ReqActivityTime"
t.para = {}
t.hand = ActivityModel.ReqActivityTime
t.pb = ActivityRpc_pb.ActivityRpcReqActivityTimeAsk()
table.insert(askList.Activity,t)

local t = {}
t.name = "XingyaoNPC"
t.para = {}
t.hand = ActivityModel.XingyaoNPC
t.pb = ActivityRpc_pb.ActivityRpcXingyaoNPCAsk()
table.insert(askList.Activity,t)

