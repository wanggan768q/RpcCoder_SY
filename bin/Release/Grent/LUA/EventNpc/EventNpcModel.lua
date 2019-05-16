--将变量写入下方
local ModuleId = 37;
local RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST = 3751
local RPC_CODE_EVENTNPC_ENDEVENT_REQUEST = 3752
local RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY = 3753;





require("app.EventNpc.EventNpcRpc_pb")

EventNpcModel = class("EventNpcModel",BaseModel)

function EventNpcModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=EventNpcModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function EventNpcModel:ctor()
	EventNpcModel.super.ctor(self)
	self.rpc_pb = EventNpcRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY,handler(self,self.ActivityBeginCB))

  


end

-- 更新数据
function EventNpcModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BeginEvent(self,EventIndex,_hanlder)
	local PB = self.rpc_pb.EventNpcRpcBeginEventAsk()
	PB.EventIndex = EventIndex
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST",RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EventNpcRpcBeginEventReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EventNpc => BeginEvent ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST",RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST)
end
function EndEvent(self,_hanlder)
	local PB = self.rpc_pb.EventNpcRpcEndEventAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_EVENTNPC_ENDEVENT_REQUEST",RPC_CODE_EVENTNPC_ENDEVENT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.EventNpcRpcEndEventReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[EventNpc => EndEvent ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_EVENTNPC_ENDEVENT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_EVENTNPC_ENDEVENT_REQUEST",RPC_CODE_EVENTNPC_ENDEVENT_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerActivityBeginCBNotify(self,_hanlder)
	if not self.ActivityBeginCBNotifyCallBack then
		self.ActivityBeginCBNotifyCallBack = {}
	end
	table.insert(self.ActivityBeginCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityBeginCB(self,notifyMsg)
	if self.ActivityBeginCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventNpcRpcActivityBeginNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ActivityBeginCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterActivityBeginCBNotify(self,_hanlder)
	if nil ~= self.ActivityBeginCBNotifyCallBack then
		for i,callback in ipairs(self.ActivityBeginCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ActivityBeginCBNotifyCallBack, i )
			end
		end
	end
end





askList.EventNpc = {}

local t = {}
t.name = "BeginEvent"
t.para = {{name="EventIndex",t=1}}
t.hand = EventNpcModel.BeginEvent
t.pb = EventNpcRpc_pb.EventNpcRpcBeginEventAsk()
table.insert(askList.EventNpc,t)

local t = {}
t.name = "EndEvent"
t.para = {}
t.hand = EventNpcModel.EndEvent
t.pb = EventNpcRpc_pb.EventNpcRpcEndEventAsk()
table.insert(askList.EventNpc,t)

