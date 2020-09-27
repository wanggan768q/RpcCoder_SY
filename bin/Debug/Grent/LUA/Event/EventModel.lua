-- EventModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 5;
local RPC_CODE_EVENT_MOVE_NOTIFY = 551;
local RPC_CODE_EVENT_STOPMOVE_NOTIFY = 552;
local RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY = 553;
local RPC_CODE_EVENT_COINCHANGE_NOTIFY = 554;
local RPC_CODE_EVENT_MOVEPOS_NOTIFY = 555;
local RPC_CODE_EVENT_DIR_NOTIFY = 556;
local RPC_CODE_EVENT_STARTFADEOUT_NOTIFY = 557;
local RPC_CODE_EVENT_CINEMATICSTART_NOTIFY = 558;
local RPC_CODE_EVENT_CINEMATICEND_NOTIFY = 559;



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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = EventRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_MOVE_NOTIFY,handler(self,self.MoveCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_STOPMOVE_NOTIFY,handler(self,self.StopMoveCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY,handler(self,self.ObjAttrChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_COINCHANGE_NOTIFY,handler(self,self.CoinChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_MOVEPOS_NOTIFY,handler(self,self.MovePosCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_DIR_NOTIFY,handler(self,self.DirCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_STARTFADEOUT_NOTIFY,handler(self,self.StartFadeoutCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_CINEMATICSTART_NOTIFY,handler(self,self.CinematicStartCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_EVENT_CINEMATICEND_NOTIFY,handler(self,self.CinematicEndCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

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
-- 给c层 注册服务器通知回调
function registerCoinChangeCBNotify(self,_hanlder)
	if not self.CoinChangeCBNotifyCallBack then
		self.CoinChangeCBNotifyCallBack = {}
	end
	table.insert(self.CoinChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CoinChangeCB(self,notifyMsg)
	if self.CoinChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcCoinChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CoinChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCoinChangeCBNotify(self,_hanlder)
	if nil ~= self.CoinChangeCBNotifyCallBack then
		for i,callback in ipairs(self.CoinChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CoinChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerMovePosCBNotify(self,_hanlder)
	if not self.MovePosCBNotifyCallBack then
		self.MovePosCBNotifyCallBack = {}
	end
	table.insert(self.MovePosCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MovePosCB(self,notifyMsg)
	if self.MovePosCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcMovePosNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MovePosCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMovePosCBNotify(self,_hanlder)
	if nil ~= self.MovePosCBNotifyCallBack then
		for i,callback in ipairs(self.MovePosCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MovePosCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDirCBNotify(self,_hanlder)
	if not self.DirCBNotifyCallBack then
		self.DirCBNotifyCallBack = {}
	end
	table.insert(self.DirCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DirCB(self,notifyMsg)
	if self.DirCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcDirNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DirCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDirCBNotify(self,_hanlder)
	if nil ~= self.DirCBNotifyCallBack then
		for i,callback in ipairs(self.DirCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DirCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerStartFadeoutCBNotify(self,_hanlder)
	if not self.StartFadeoutCBNotifyCallBack then
		self.StartFadeoutCBNotifyCallBack = {}
	end
	table.insert(self.StartFadeoutCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function StartFadeoutCB(self,notifyMsg)
	if self.StartFadeoutCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcStartFadeoutNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.StartFadeoutCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterStartFadeoutCBNotify(self,_hanlder)
	if nil ~= self.StartFadeoutCBNotifyCallBack then
		for i,callback in ipairs(self.StartFadeoutCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.StartFadeoutCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCinematicStartCBNotify(self,_hanlder)
	if not self.CinematicStartCBNotifyCallBack then
		self.CinematicStartCBNotifyCallBack = {}
	end
	table.insert(self.CinematicStartCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CinematicStartCB(self,notifyMsg)
	if self.CinematicStartCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcCinematicStartNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CinematicStartCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCinematicStartCBNotify(self,_hanlder)
	if nil ~= self.CinematicStartCBNotifyCallBack then
		for i,callback in ipairs(self.CinematicStartCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CinematicStartCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCinematicEndCBNotify(self,_hanlder)
	if not self.CinematicEndCBNotifyCallBack then
		self.CinematicEndCBNotifyCallBack = {}
	end
	table.insert(self.CinematicEndCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CinematicEndCB(self,notifyMsg)
	if self.CinematicEndCBNotifyCallBack then
		local ret_msg = self.rpc_pb.EventRpcCinematicEndNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CinematicEndCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCinematicEndCBNotify(self,_hanlder)
	if nil ~= self.CinematicEndCBNotifyCallBack then
		for i,callback in ipairs(self.CinematicEndCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CinematicEndCBNotifyCallBack, i )
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

