--将变量写入下方
local ModuleId = 39;
local RPC_CODE_MATCH_AUTOMATCH_REQUEST = 3951
local RPC_CODE_MATCH_CANCELMATCH_REQUEST = 3952
local RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY = 3953;
local RPC_CODE_MATCH_PREPAREROOM_NOTIFY = 3954;
local RPC_CODE_MATCH_READY_REQUEST = 3955
local RPC_CODE_MATCH_CANCELREADY_REQUEST = 3956
local RPC_CODE_MATCH_ROOMCANCEL_NOTIFY = 3957;
local RPC_CODE_MATCH_MEMBERREADY_NOTIFY = 3958;





require("app.Match.MatchRpc_pb")

MatchModel = class("MatchModel",BaseModel)

function MatchModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MatchModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MatchModel:ctor()
	MatchModel.super.ctor(self)
	self.rpc_pb = MatchRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY,handler(self,self.CancelMatchNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_MATCH_PREPAREROOM_NOTIFY,handler(self,self.PrepareRoomCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_MATCH_ROOMCANCEL_NOTIFY,handler(self,self.RoomCancelCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_MATCH_MEMBERREADY_NOTIFY,handler(self,self.MemberReadyCB))

  


end

-- 更新数据
function MatchModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function AutoMatch(self,MatchInfo,_hanlder)
	local PB = self.rpc_pb.MatchRpcAutoMatchAsk()
	PB.MatchInfo.MatchType = MatchInfo.MatchType
	PB.MatchInfo.Elo = MatchInfo.Elo
	PB.MatchInfo.Auto = MatchInfo.Auto
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MATCH_AUTOMATCH_REQUEST",RPC_CODE_MATCH_AUTOMATCH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MatchRpcAutoMatchReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Match => AutoMatch ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MATCH_AUTOMATCH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MATCH_AUTOMATCH_REQUEST",RPC_CODE_MATCH_AUTOMATCH_REQUEST)
end
function CancelMatch(self,_hanlder)
	local PB = self.rpc_pb.MatchRpcCancelMatchAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MATCH_CANCELMATCH_REQUEST",RPC_CODE_MATCH_CANCELMATCH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MatchRpcCancelMatchReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Match => CancelMatch ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MATCH_CANCELMATCH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MATCH_CANCELMATCH_REQUEST",RPC_CODE_MATCH_CANCELMATCH_REQUEST)
end
function Ready(self,MatchType,RoomId,_hanlder)
	local PB = self.rpc_pb.MatchRpcReadyAsk()
	PB.MatchType = MatchType
	PB.RoomId = RoomId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MATCH_READY_REQUEST",RPC_CODE_MATCH_READY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MatchRpcReadyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Match => Ready ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MATCH_READY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MATCH_READY_REQUEST",RPC_CODE_MATCH_READY_REQUEST)
end
function CancelReady(self,MatchType,RoomId,_hanlder)
	local PB = self.rpc_pb.MatchRpcCancelReadyAsk()
	PB.MatchType = MatchType
	PB.RoomId = RoomId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MATCH_CANCELREADY_REQUEST",RPC_CODE_MATCH_CANCELREADY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MatchRpcCancelReadyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Match => CancelReady ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MATCH_CANCELREADY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MATCH_CANCELREADY_REQUEST",RPC_CODE_MATCH_CANCELREADY_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerCancelMatchNotifyCBNotify(self,_hanlder)
	if not self.CancelMatchNotifyCBNotifyCallBack then
		self.CancelMatchNotifyCBNotifyCallBack = {}
	end
	table.insert(self.CancelMatchNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CancelMatchNotifyCB(self,notifyMsg)
	if self.CancelMatchNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MatchRpcCancelMatchNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CancelMatchNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCancelMatchNotifyCBNotify(self,_hanlder)
	if nil ~= self.CancelMatchNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.CancelMatchNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CancelMatchNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerPrepareRoomCBNotify(self,_hanlder)
	if not self.PrepareRoomCBNotifyCallBack then
		self.PrepareRoomCBNotifyCallBack = {}
	end
	table.insert(self.PrepareRoomCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PrepareRoomCB(self,notifyMsg)
	if self.PrepareRoomCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MatchRpcPrepareRoomNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PrepareRoomCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPrepareRoomCBNotify(self,_hanlder)
	if nil ~= self.PrepareRoomCBNotifyCallBack then
		for i,callback in ipairs(self.PrepareRoomCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PrepareRoomCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRoomCancelCBNotify(self,_hanlder)
	if not self.RoomCancelCBNotifyCallBack then
		self.RoomCancelCBNotifyCallBack = {}
	end
	table.insert(self.RoomCancelCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RoomCancelCB(self,notifyMsg)
	if self.RoomCancelCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MatchRpcRoomCancelNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RoomCancelCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRoomCancelCBNotify(self,_hanlder)
	if nil ~= self.RoomCancelCBNotifyCallBack then
		for i,callback in ipairs(self.RoomCancelCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RoomCancelCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerMemberReadyCBNotify(self,_hanlder)
	if not self.MemberReadyCBNotifyCallBack then
		self.MemberReadyCBNotifyCallBack = {}
	end
	table.insert(self.MemberReadyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MemberReadyCB(self,notifyMsg)
	if self.MemberReadyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MatchRpcMemberReadyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MemberReadyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMemberReadyCBNotify(self,_hanlder)
	if nil ~= self.MemberReadyCBNotifyCallBack then
		for i,callback in ipairs(self.MemberReadyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MemberReadyCBNotifyCallBack, i )
			end
		end
	end
end





askList.Match = {}

local t = {}
t.name = "AutoMatch"
t.para = {{name="MatchInfo",t=3}}
t.hand = MatchModel.AutoMatch
t.pb = MatchRpc_pb.MatchRpcAutoMatchAsk()
table.insert(askList.Match,t)

local t = {}
t.name = "CancelMatch"
t.para = {}
t.hand = MatchModel.CancelMatch
t.pb = MatchRpc_pb.MatchRpcCancelMatchAsk()
table.insert(askList.Match,t)

local t = {}
t.name = "Ready"
t.para = {{name="MatchType",t=1},{name="RoomId",t=1}}
t.hand = MatchModel.Ready
t.pb = MatchRpc_pb.MatchRpcReadyAsk()
table.insert(askList.Match,t)

local t = {}
t.name = "CancelReady"
t.para = {{name="MatchType",t=1},{name="RoomId",t=1}}
t.hand = MatchModel.CancelReady
t.pb = MatchRpc_pb.MatchRpcCancelReadyAsk()
table.insert(askList.Match,t)

