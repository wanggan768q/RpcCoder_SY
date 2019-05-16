--将变量写入下方
local ModuleId = 4;
local RPC_CODE_HUMAN_MOVE_REQUEST = 451
local RPC_CODE_HUMAN_STOPMOVE_REQUEST = 452
local RPC_CODE_HUMAN_MOVECHECK_NOTIFY = 453;
local RPC_CODE_HUMAN_RESPAWN_REQUEST = 454
local RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY = 455;
local RPC_CODE_HUMAN_MOVEPOS_REQUEST = 456
local RPC_CODE_HUMAN_ROLEDIE_NOTIFY = 457;
local RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY = 458;
local RPC_CODE_HUMAN_FUNCNOTICE_REQUEST = 459
local RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST = 460
local RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY = 461;





require("app.Human.HumanRpc_pb")

HumanModel = class("HumanModel",BaseModel)

function HumanModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=HumanModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function HumanModel:ctor()
	HumanModel.super.ctor(self)
	self.rpc_pb = HumanRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_MOVECHECK_NOTIFY,handler(self,self.MoveCheckCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY,handler(self,self.RespawnOtherCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_ROLEDIE_NOTIFY,handler(self,self.RoleDieCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY,handler(self,self.ClientAttributesCB))

  


end

-- 更新数据
function HumanModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Move(self,Dir,X,Z,ObjId,_hanlder)
	local PB = self.rpc_pb.HumanRpcMoveAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	PB.ObjId = ObjId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_MOVE_REQUEST",RPC_CODE_HUMAN_MOVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMoveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => Move ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_MOVE_REQUEST",RPC_CODE_HUMAN_MOVE_REQUEST)
end
function StopMove(self,Dir,X,Z,ObjId,_hanlder)
	local PB = self.rpc_pb.HumanRpcStopMoveAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	PB.ObjId = ObjId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_STOPMOVE_REQUEST",RPC_CODE_HUMAN_STOPMOVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcStopMoveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => StopMove ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_STOPMOVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_STOPMOVE_REQUEST",RPC_CODE_HUMAN_STOPMOVE_REQUEST)
end
function Respawn(self,ReviveType,_hanlder)
	local PB = self.rpc_pb.HumanRpcRespawnAsk()
	PB.ReviveType = ReviveType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_RESPAWN_REQUEST",RPC_CODE_HUMAN_RESPAWN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcRespawnReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => Respawn ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_RESPAWN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_RESPAWN_REQUEST",RPC_CODE_HUMAN_RESPAWN_REQUEST)
end
function MovePos(self,PosList,Dir,ObjId,IsAllowChangeRunAnimation,_hanlder)
	local PB = self.rpc_pb.HumanRpcMovePosAsk()
	for i,v in ipairs(PosList) do
		table.insert(PB.PosList,v)
	end
	PB.Dir = Dir
	PB.ObjId = ObjId
	PB.IsAllowChangeRunAnimation = IsAllowChangeRunAnimation
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_MOVEPOS_REQUEST",RPC_CODE_HUMAN_MOVEPOS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMovePosReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => MovePos ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVEPOS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_MOVEPOS_REQUEST",RPC_CODE_HUMAN_MOVEPOS_REQUEST)
end
function FuncNotice(self,_hanlder)
	local PB = self.rpc_pb.HumanRpcFuncNoticeAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_FUNCNOTICE_REQUEST",RPC_CODE_HUMAN_FUNCNOTICE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcFuncNoticeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => FuncNotice ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_FUNCNOTICE_REQUEST",RPC_CODE_HUMAN_FUNCNOTICE_REQUEST)
end
function FuncNoticeChange(self,_hanlder)
	local PB = self.rpc_pb.HumanRpcFuncNoticeChangeAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST",RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcFuncNoticeChangeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Human => FuncNoticeChange ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST",RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerMoveCheckCBNotify(self,_hanlder)
	if not self.MoveCheckCBNotifyCallBack then
		self.MoveCheckCBNotifyCallBack = {}
	end
	table.insert(self.MoveCheckCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MoveCheckCB(self,notifyMsg)
	if self.MoveCheckCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcMoveCheckNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MoveCheckCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMoveCheckCBNotify(self,_hanlder)
	if nil ~= self.MoveCheckCBNotifyCallBack then
		for i,callback in ipairs(self.MoveCheckCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MoveCheckCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function MoveCheckNotify(self,ObjId,Dir,X,Y)
	local PB = self.rpc_pb.HumanRpcMoveCheckNotify()
	PB.ObjId = ObjId
	PB.Dir = Dir
	PB.X = X
	PB.Y = Y
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_MOVECHECK_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerRespawnOtherCBNotify(self,_hanlder)
	if not self.RespawnOtherCBNotifyCallBack then
		self.RespawnOtherCBNotifyCallBack = {}
	end
	table.insert(self.RespawnOtherCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RespawnOtherCB(self,notifyMsg)
	if self.RespawnOtherCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcRespawnOtherNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RespawnOtherCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRespawnOtherCBNotify(self,_hanlder)
	if nil ~= self.RespawnOtherCBNotifyCallBack then
		for i,callback in ipairs(self.RespawnOtherCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RespawnOtherCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRoleDieCBNotify(self,_hanlder)
	if not self.RoleDieCBNotifyCallBack then
		self.RoleDieCBNotifyCallBack = {}
	end
	table.insert(self.RoleDieCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RoleDieCB(self,notifyMsg)
	if self.RoleDieCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcRoleDieNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RoleDieCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRoleDieCBNotify(self,_hanlder)
	if nil ~= self.RoleDieCBNotifyCallBack then
		for i,callback in ipairs(self.RoleDieCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RoleDieCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ChangeAnimationStateNotify(self,AnimationState)
	local PB = self.rpc_pb.HumanRpcChangeAnimationStateNotify()
	PB.AnimationState = AnimationState
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerClientAttributesCBNotify(self,_hanlder)
	if not self.ClientAttributesCBNotifyCallBack then
		self.ClientAttributesCBNotifyCallBack = {}
	end
	table.insert(self.ClientAttributesCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ClientAttributesCB(self,notifyMsg)
	if self.ClientAttributesCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcClientAttributesNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ClientAttributesCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterClientAttributesCBNotify(self,_hanlder)
	if nil ~= self.ClientAttributesCBNotifyCallBack then
		for i,callback in ipairs(self.ClientAttributesCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ClientAttributesCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ClientAttributesNotify(self,ObjId,IsTouchJoyStick,IsHold)
	local PB = self.rpc_pb.HumanRpcClientAttributesNotify()
	PB.ObjId = ObjId
	PB.IsTouchJoyStick = IsTouchJoyStick
	PB.IsHold = IsHold
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, pb_data)
end





askList.Human = {}

local t = {}
t.name = "Move"
t.para = {{name="Dir",t=3},{name="X",t=3},{name="Z",t=3},{name="ObjId",t=1}}
t.hand = HumanModel.Move
t.pb = HumanRpc_pb.HumanRpcMoveAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "StopMove"
t.para = {{name="Dir",t=3},{name="X",t=1},{name="Z",t=1},{name="ObjId",t=1}}
t.hand = HumanModel.StopMove
t.pb = HumanRpc_pb.HumanRpcStopMoveAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "Respawn"
t.para = {{name="ReviveType",t=1}}
t.hand = HumanModel.Respawn
t.pb = HumanRpc_pb.HumanRpcRespawnAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "MovePos"
t.para = {{name="PosList",t=3},{name="Dir",t=3},{name="ObjId",t=1},{name="IsAllowChangeRunAnimation",t=3}}
t.hand = HumanModel.MovePos
t.pb = HumanRpc_pb.HumanRpcMovePosAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "FuncNotice"
t.para = {}
t.hand = HumanModel.FuncNotice
t.pb = HumanRpc_pb.HumanRpcFuncNoticeAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "FuncNoticeChange"
t.para = {}
t.hand = HumanModel.FuncNoticeChange
t.pb = HumanRpc_pb.HumanRpcFuncNoticeChangeAsk()
table.insert(askList.Human,t)

