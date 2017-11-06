--将变量写入下方
local ModuleId = 4;
local RPC_CODE_HUMAN_MOVE_REQUEST = 451
local RPC_CODE_HUMAN_STOPMOVE_REQUEST = 452
local RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST = 453
local RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY = 454;
local RPC_CODE_HUMAN_GCMOVECHECK_NOTIFY = 455;





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
require("3rd/pblua/HumanRpc_pb")
local  HumanRpc_pb = HumanRpc_pb
module("HumanModel")

function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)

end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = HumanRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_GCMOVECHECK_NOTIFY,handler(self,self.GCMoveCheckCB))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function Move(self,Dir,X,Z,_hanlder)
	local PB = self.rpc_pb.HumanRpcMoveAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMoveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function StopMove(self,Dir,X,Z,_hanlder)
	local PB = self.rpc_pb.HumanRpcStopMoveAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcStopMoveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_STOPMOVE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function MovementVerification(self,Dir,X,Z,_hanlder)
	local PB = self.rpc_pb.HumanRpcMovementVerificationAsk()
	PB.Dir = Dir
	PB.X = X
	PB.Z = Z
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.HumanRpcMovementVerificationReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST, pb_data, callback)
	showNetTip(self)
end



-- 给c层 注册服务器通知回调
function HumanModel:CGMoveCheckNotify(DirPos)
	local PB = self.rpc_pb.HumanRpcCGMoveCheckNotify()
	PB.Dir = Dir
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerGCMoveCheckCBNotify(self,_hanlder)
	if not self.GCMoveCheckCBNotifyCallBack then
		self.GCMoveCheckCBNotifyCallBack = {}
	end
	table.insert(self.GCMoveCheckCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GCMoveCheckCB(self,notifyMsg)
	if self.GCMoveCheckCBNotifyCallBack then
		local ret_msg = self.rpc_pb.HumanRpcGCMoveCheckNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.GCMoveCheckCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterGCMoveCheckCBNotify(self,_hanlder)
	if nil ~= self.GCMoveCheckCBNotifyCallBack then
		for i,callback in ipairs(self.GCMoveCheckCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.GCMoveCheckCBNotifyCallBack, i )
			end
		end
	end
end




--[[
askList.Human = {}

local t = {}
t.name = "Move"
t.para = {{name="Dir",t=3},{name="X",t=3},{name="Z",t=3}}
t.hand = HumanModel.Move
t.pb = HumanRpc_pb.HumanRpcMoveAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "StopMove"
t.para = {{name="Dir",t=3},{name="X",t=3},{name="Z",t=3}}
t.hand = HumanModel.StopMove
t.pb = HumanRpc_pb.HumanRpcStopMoveAsk()
table.insert(askList.Human,t)

local t = {}
t.name = "MovementVerification"
t.para = {{name="Dir",t=3},{name="X",t=3},{name="Z",t=3}}
t.hand = HumanModel.MovementVerification
t.pb = HumanRpc_pb.HumanRpcMovementVerificationAsk()
table.insert(askList.Human,t)

--]]