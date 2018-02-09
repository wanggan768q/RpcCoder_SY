--将变量写入下方
local ModuleId = 5;
local RPC_CODE_EVENT_MOVE_NOTIFY = 551;
local RPC_CODE_EVENT_STOPMOVE_NOTIFY = 552;
local RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY = 553;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/EventRpc_pb")
local  EventRpc_pb = EventRpc_pb
module("EventModel")





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

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = EventRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_MOVE_NOTIFY,handler(self,self.MoveCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_STOPMOVE_NOTIFY,handler(self,self.StopMoveCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY,handler(self,self.ObjAttrChangeCB))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件



-- 给c层 注册服务器通知回调
function registerMoveCBNotify(self,_hanlder)
	if not self.MoveCBNotifyCallBack then
		self.MoveCBNotifyCallBack = {}
	end
	table.insert(self.MoveCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MoveCB(self,notifyMsg)
	if self.MoveCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcMoveNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MoveCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMoveCBNotify(self,_hanlder)
	if nil ~= self.MoveCBNotifyCallBack then
		for i,callback in ipairs(self.MoveCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MoveCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerStopMoveCBNotify(self,_hanlder)
	if not self.StopMoveCBNotifyCallBack then
		self.StopMoveCBNotifyCallBack = {}
	end
	table.insert(self.StopMoveCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function StopMoveCB(self,notifyMsg)
	if self.StopMoveCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcStopMoveNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.StopMoveCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterStopMoveCBNotify(self,_hanlder)
	if nil ~= self.StopMoveCBNotifyCallBack then
		for i,callback in ipairs(self.StopMoveCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.StopMoveCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerObjAttrChangeCBNotify(self,_hanlder)
	if not self.ObjAttrChangeCBNotifyCallBack then
		self.ObjAttrChangeCBNotifyCallBack = {}
	end
	table.insert(self.ObjAttrChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ObjAttrChangeCB(self,notifyMsg)
	if self.ObjAttrChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcObjAttrChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ObjAttrChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterObjAttrChangeCBNotify(self,_hanlder)
	if nil ~= self.ObjAttrChangeCBNotifyCallBack then
		for i,callback in ipairs(self.ObjAttrChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ObjAttrChangeCBNotifyCallBack, i )
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
askList.Event = {}

--]]

