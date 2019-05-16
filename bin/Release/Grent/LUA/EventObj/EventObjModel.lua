--将变量写入下方
local ModuleId = 16;
local RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST = 1651
local RPC_CODE_EVENTOBJ_EVENTEND_REQUEST = 1652
local RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST = 1653
local RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY = 1654;





require("app.EventObj.EventObjRpc_pb")

EventObjModel = class("EventObjModel",BaseModel)

function EventObjModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=EventObjModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function EventObjModel:ctor()
	EventObjModel.super.ctor(self)
	self.rpc_pb = EventObjRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY,handler(self,self.EventStopNotifyCB))

  


end

-- 更新数据
function EventObjModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function EventBegin(self,ObjId,_hanlder)
	local PB = self.rpc_pb.EventObjRpcEventBeginAsk()
	PB.ObjId = ObjId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST",RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EventObjRpcEventBeginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EventObj => EventBegin ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST",RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST)
end
function EventEnd(self,ObjId,_hanlder)
	local PB = self.rpc_pb.EventObjRpcEventEndAsk()
	PB.ObjId = ObjId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EVENTOBJ_EVENTEND_REQUEST",RPC_CODE_EVENTOBJ_EVENTEND_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EventObjRpcEventEndReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EventObj => EventEnd ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EVENTOBJ_EVENTEND_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EVENTOBJ_EVENTEND_REQUEST",RPC_CODE_EVENTOBJ_EVENTEND_REQUEST)
end
function EventStop(self,ObjId,_hanlder)
	local PB = self.rpc_pb.EventObjRpcEventStopAsk()
	PB.ObjId = ObjId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST",RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EventObjRpcEventStopReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EventObj => EventStop ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST",RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerEventStopNotifyCBNotify(self,_hanlder)
	if not self.EventStopNotifyCBNotifyCallBack then
		self.EventStopNotifyCBNotifyCallBack = {}
	end
	table.insert(self.EventStopNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function EventStopNotifyCB(self,notifyMsg)
	if self.EventStopNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventObjRpcEventStopNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.EventStopNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterEventStopNotifyCBNotify(self,_hanlder)
	if nil ~= self.EventStopNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.EventStopNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.EventStopNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.EventObj = {}

local t = {}
t.name = "EventBegin"
t.para = {{name="ObjId",t=1}}
t.hand = EventObjModel.EventBegin
t.pb = EventObjRpc_pb.EventObjRpcEventBeginAsk()
table.insert(askList.EventObj,t)

local t = {}
t.name = "EventEnd"
t.para = {{name="ObjId",t=1}}
t.hand = EventObjModel.EventEnd
t.pb = EventObjRpc_pb.EventObjRpcEventEndAsk()
table.insert(askList.EventObj,t)

local t = {}
t.name = "EventStop"
t.para = {{name="ObjId",t=1}}
t.hand = EventObjModel.EventStop
t.pb = EventObjRpc_pb.EventObjRpcEventStopAsk()
table.insert(askList.EventObj,t)

