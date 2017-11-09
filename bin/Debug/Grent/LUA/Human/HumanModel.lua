--将变量写入下方
local ModuleId = 4;
local RPC_CODE_HUMAN_MOVE_REQUEST = 451
local RPC_CODE_HUMAN_STOPMOVE_REQUEST = 452
local RPC_CODE_HUMAN_MOVECHECK_NOTIFY = 453;





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
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
	MLayerMgr.RegNotifyHd(RPC_CODE_HUMAN_MOVECHECK_NOTIFY,handler(self,self.MoveCheckCB))

  


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
function MoveCheckNotify(Obj_id,Dir,X,Y)
	local PB = self.rpc_pb.HumanRpcMoveCheckNotify()
	PB.Obj_id = Obj_id
	PB.Dir = Dir
	PB.X = X
	PB.Y = Y
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_HUMAN_MOVECHECK_NOTIFY, pb_data)
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

--]]