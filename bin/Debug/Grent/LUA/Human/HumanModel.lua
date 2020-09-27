-- HumanModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

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
local RPC_CODE_HUMAN_TIMECHECK_NOTIFY = 462;
local RPC_CODE_HUMAN_MOTIONFLAGS_NOTIFY = 463;
local RPC_CODE_HUMAN_RUSH_REQUEST = 464
local RPC_CODE_HUMAN_STARE_REQUEST = 465
local RPC_CODE_HUMAN_CHANGEPOSITION_NOTIFY = 466;
local RPC_CODE_HUMAN_ATTRCHANGE_NOTIFY = 467;
local RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST = 468
local RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST = 469



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
require("3rd/pblua/HumanRpc_pb")
local  HumanRpc_pb = HumanRpc_pb
module("HumanModel")





function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			callback(Id,Index)
		end
	end
end

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = HumanRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_MOVECHECK_NOTIFY,handler(self,self.MoveCheckCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY,handler(self,self.RespawnOtherCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_ROLEDIE_NOTIFY,handler(self,self.RoleDieCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY,handler(self,self.ClientAttributesCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_MOTIONFLAGS_NOTIFY,handler(self,self.MotionFlagsCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_CHANGEPOSITION_NOTIFY,handler(self,self.ChangePositionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_ATTRCHANGE_NOTIFY,handler(self,self.AttrChangeCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

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
		hideNetTip(self,'RPC_CODE_HUMAN_MOVE_REQUEST',RPC_CODE_HUMAN_MOVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMoveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => Move ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_MOVE_REQUEST',RPC_CODE_HUMAN_MOVE_REQUEST)
end
function StopMove(self,Dir,X,Z,ObjId,BrakeRush,_hanlder)
	local PB = self.rpc_pb.HumanRpcStopMoveAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	PB.ObjId = ObjId
	PB.BrakeRush = BrakeRush
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_STOPMOVE_REQUEST',RPC_CODE_HUMAN_STOPMOVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcStopMoveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => StopMove ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_STOPMOVE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_STOPMOVE_REQUEST',RPC_CODE_HUMAN_STOPMOVE_REQUEST)
end
function Respawn(self,ReviveType,_hanlder)
	local PB = self.rpc_pb.HumanRpcRespawnAsk()
	PB.ReviveType = ReviveType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_RESPAWN_REQUEST',RPC_CODE_HUMAN_RESPAWN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcRespawnReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => Respawn ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_RESPAWN_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_RESPAWN_REQUEST',RPC_CODE_HUMAN_RESPAWN_REQUEST)
end
function MovePos(self,PosList,Dir,ObjId,IsAllowChangeRunAnimation,IsLookAtMoving,FromX,FromZ,_hanlder)
	local PB = self.rpc_pb.HumanRpcMovePosAsk()
	for i,v in ipairs(PosList) do
		table.insert(PB.PosList,v)
	end
	PB.Dir = Dir
	PB.ObjId = ObjId
	PB.IsAllowChangeRunAnimation = IsAllowChangeRunAnimation
	PB.IsLookAtMoving = IsLookAtMoving
	PB.FromX = FromX
	PB.FromZ = FromZ
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_MOVEPOS_REQUEST',RPC_CODE_HUMAN_MOVEPOS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMovePosReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => MovePos ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVEPOS_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_MOVEPOS_REQUEST',RPC_CODE_HUMAN_MOVEPOS_REQUEST)
end
function FuncNotice(self,_hanlder)
	local PB = self.rpc_pb.HumanRpcFuncNoticeAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_FUNCNOTICE_REQUEST',RPC_CODE_HUMAN_FUNCNOTICE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcFuncNoticeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => FuncNotice ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_FUNCNOTICE_REQUEST',RPC_CODE_HUMAN_FUNCNOTICE_REQUEST)
end
function FuncNoticeChange(self,_hanlder)
	local PB = self.rpc_pb.HumanRpcFuncNoticeChangeAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST',RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcFuncNoticeChangeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => FuncNoticeChange ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST',RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST)
end
function Rush(self,Apply,_hanlder)
	local PB = self.rpc_pb.HumanRpcRushAsk()
	PB.Apply = Apply
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_RUSH_REQUEST',RPC_CODE_HUMAN_RUSH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcRushReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => Rush ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_RUSH_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_RUSH_REQUEST',RPC_CODE_HUMAN_RUSH_REQUEST)
end
function Stare(self,Apply,TargetID,Dir,_hanlder)
	local PB = self.rpc_pb.HumanRpcStareAsk()
	PB.Apply = Apply
	PB.TargetID = TargetID
	PB.Dir = Dir
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_STARE_REQUEST',RPC_CODE_HUMAN_STARE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcStareReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => Stare ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_STARE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_STARE_REQUEST',RPC_CODE_HUMAN_STARE_REQUEST)
end
function Trusteeship(self,Open,_hanlder)
	local PB = self.rpc_pb.HumanRpcTrusteeshipAsk()
	PB.Open = Open
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST',RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcTrusteeshipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => Trusteeship ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST',RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST)
end
function ChangePlayerName(self,PlayerName,_hanlder)
	local PB = self.rpc_pb.HumanRpcChangePlayerNameAsk()
	PB.PlayerName = PlayerName
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST',RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcChangePlayerNameReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Human => ChangePlayerName ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST',RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST)
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
-- 给c层 注册服务器通知回调
function TimeCheckNotify(self,Data)
	local PB = self.rpc_pb.HumanRpcTimeCheckNotify()
	PB.Data = Data
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_TIMECHECK_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerMotionFlagsCBNotify(self,_hanlder)
	if not self.MotionFlagsCBNotifyCallBack then
		self.MotionFlagsCBNotifyCallBack = {}
	end
	table.insert(self.MotionFlagsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MotionFlagsCB(self,notifyMsg)
	if self.MotionFlagsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcMotionFlagsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MotionFlagsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMotionFlagsCBNotify(self,_hanlder)
	if nil ~= self.MotionFlagsCBNotifyCallBack then
		for i,callback in ipairs(self.MotionFlagsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MotionFlagsCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChangePositionCBNotify(self,_hanlder)
	if not self.ChangePositionCBNotifyCallBack then
		self.ChangePositionCBNotifyCallBack = {}
	end
	table.insert(self.ChangePositionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChangePositionCB(self,notifyMsg)
	if self.ChangePositionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcChangePositionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChangePositionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChangePositionCBNotify(self,_hanlder)
	if nil ~= self.ChangePositionCBNotifyCallBack then
		for i,callback in ipairs(self.ChangePositionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChangePositionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerAttrChangeCBNotify(self,_hanlder)
	if not self.AttrChangeCBNotifyCallBack then
		self.AttrChangeCBNotifyCallBack = {}
	end
	table.insert(self.AttrChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AttrChangeCB(self,notifyMsg)
	if self.AttrChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcAttrChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AttrChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAttrChangeCBNotify(self,_hanlder)
	if nil ~= self.AttrChangeCBNotifyCallBack then
		for i,callback in ipairs(self.AttrChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AttrChangeCBNotifyCallBack, i )
			end
		end
	end
end


function registerDataCallback(self,_hanlder)
	if not self.DataCallback then
		self.DataCallback = {}
	end
	table.insert(self.DataCallback,_hanlder)
end

function unregisterDataCallback(self,_hanlder)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			if callback == _hanlder then
				table.remove(self.DataCallback, i )
			end
		end
	end
end

function GetValue(self, Id,Index )
	-- body
	
end

--[[
askList.Human = {}

local t = {}
t.name = "Move"
t.para = {{name="Dir",t=3},{name="X",t=3},{name="Z",t=3},{name="ObjId",t=1}}
t.hand = HumanModel.Move
t.pb = HumanRpc_pb.HumanRpcMoveAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "StopMove"
t.para = {{name="Dir",t=3},{name="X",t=1},{name="Z",t=1},{name="ObjId",t=1},{name="BrakeRush",t=3}}
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
t.para = {{name="PosList",t=3},{name="Dir",t=3},{name="ObjId",t=1},{name="IsAllowChangeRunAnimation",t=3},{name="IsLookAtMoving",t=3},{name="FromX",t=1},{name="FromZ",t=1}}
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

local t = {}
t.name = "Rush"
t.para = {{name="Apply",t=3}}
t.hand = HumanModel.Rush
t.pb = HumanRpc_pb.HumanRpcRushAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "Stare"
t.para = {{name="Apply",t=3},{name="TargetID",t=1},{name="Dir",t=3}}
t.hand = HumanModel.Stare
t.pb = HumanRpc_pb.HumanRpcStareAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "Trusteeship"
t.para = {{name="Open",t=3}}
t.hand = HumanModel.Trusteeship
t.pb = HumanRpc_pb.HumanRpcTrusteeshipAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "ChangePlayerName"
t.para = {{name="PlayerName",t=2}}
t.hand = HumanModel.ChangePlayerName
t.pb = HumanRpc_pb.HumanRpcChangePlayerNameAsk()
table.insert(askList.Human,t)

--]]

