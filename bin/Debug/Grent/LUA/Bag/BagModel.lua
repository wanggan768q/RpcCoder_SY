--将变量写入下方
local ModuleId = 12;
local RPC_CODE_BAG_USEITEM_REQUEST = 1251
local RPC_CODE_BAG_SYNC_REQUEST = 1252
local RPC_CODE_BAG_SALEITEM_REQUEST = 1253
local RPC_CODE_BAG_LOCKITEM_REQUEST = 1254
local RPC_CODE_BAG_DEBLOCKING_REQUEST = 1255
local RPC_CODE_BAG_TAKEITEM_REQUEST = 1256
local RPC_CODE_BAG_TIDY_REQUEST = 1257
local RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST = 1258
local RPC_CODE_BAG_BAGCHANGE_NOTIFY = 1259;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/BagRpc_pb")
local  BagRpc_pb = BagRpc_pb
module("BagModel")





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
	self.rpc_pb = BagRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_BAGCHANGE_NOTIFY,handler(self,self.BagChangeCB))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function UseItem(self,Count,Pos,_hanlder)
	local PB = self.rpc_pb.BagRpcUseItemAsk()
	PB.Count = Count
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcUseItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_USEITEM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Sync(self,_hanlder)
	local PB = self.rpc_pb.BagRpcSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSyncReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SYNC_REQUEST, pb_data, callback)
	showNetTip(self)
end
function SaleItem(self,Pos,Count,_hanlder)
	local PB = self.rpc_pb.BagRpcSaleItemAsk()
	PB.Pos = Pos
	PB.Count = Count
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSaleItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SALEITEM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function LockItem(self,Pos,IsLock,_hanlder)
	local PB = self.rpc_pb.BagRpcLockItemAsk()
	PB.Pos = Pos
	PB.IsLock = IsLock
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcLockItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_LOCKITEM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Deblocking(self,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcDeblockingAsk()
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcDeblockingReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_DEBLOCKING_REQUEST, pb_data, callback)
	showNetTip(self)
end
function TakeItem(self,FromBagType,ToBagType,FromPos,_hanlder)
	local PB = self.rpc_pb.BagRpcTakeItemAsk()
	PB.FromBagType = FromBagType
	PB.ToBagType = ToBagType
	PB.FromPos = FromPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTakeItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TAKEITEM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Tidy(self,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcTidyAsk()
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTidyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TIDY_REQUEST, pb_data, callback)
	showNetTip(self)
end
function TakeAllBackBags(self,_hanlder)
	local PB = self.rpc_pb.BagRpcTakeAllBackBagsAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTakeAllBackBagsReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, pb_data, callback)
	showNetTip(self)
end



-- 给c层 注册服务器通知回调
function registerBagChangeCBNotify(self,_hanlder)
	if not self.BagChangeCBNotifyCallBack then
		self.BagChangeCBNotifyCallBack = {}
	end
	table.insert(self.BagChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BagChangeCB(self,notifyMsg)
	if self.BagChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcBagChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BagChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBagChangeCBNotify(self,_hanlder)
	if nil ~= self.BagChangeCBNotifyCallBack then
		for i,callback in ipairs(self.BagChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BagChangeCBNotifyCallBack, i )
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
askList.Bag = {}

local t = {}
t.name = "UseItem"
t.para = {{name="Count",t=1},{name="Pos",t=1}}
t.hand = BagModel.UseItem
t.pb = BagRpc_pb.BagRpcUseItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Sync"
t.para = {}
t.hand = BagModel.Sync
t.pb = BagRpc_pb.BagRpcSyncAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "SaleItem"
t.para = {{name="Pos",t=1},{name="Count",t=1}}
t.hand = BagModel.SaleItem
t.pb = BagRpc_pb.BagRpcSaleItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "LockItem"
t.para = {{name="Pos",t=1},{name="IsLock",t=3}}
t.hand = BagModel.LockItem
t.pb = BagRpc_pb.BagRpcLockItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Deblocking"
t.para = {{name="BagType",t=1}}
t.hand = BagModel.Deblocking
t.pb = BagRpc_pb.BagRpcDeblockingAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TakeItem"
t.para = {{name="FromBagType",t=1},{name="ToBagType",t=1},{name="FromPos",t=1}}
t.hand = BagModel.TakeItem
t.pb = BagRpc_pb.BagRpcTakeItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Tidy"
t.para = {{name="BagType",t=1}}
t.hand = BagModel.Tidy
t.pb = BagRpc_pb.BagRpcTidyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TakeAllBackBags"
t.para = {}
t.hand = BagModel.TakeAllBackBags
t.pb = BagRpc_pb.BagRpcTakeAllBackBagsAsk()
table.insert(askList.Bag,t)

--]]

