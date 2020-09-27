-- BagModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 12;
local RPC_CODE_BAG_USEITEM_REQUEST = 1251
local RPC_CODE_BAG_SALEITEM_REQUEST = 1252
local RPC_CODE_BAG_LOCKITEM_REQUEST = 1253
local RPC_CODE_BAG_DEBLOCKING_REQUEST = 1254
local RPC_CODE_BAG_TAKEITEM_REQUEST = 1255
local RPC_CODE_BAG_TIDY_REQUEST = 1256
local RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST = 1257
local RPC_CODE_BAG_BAGCHANGE_NOTIFY = 1258;
local RPC_CODE_BAG_MERGEITEM_REQUEST = 1259
local RPC_CODE_BAG_BAGSYNC_REQUEST = 1260
local RPC_CODE_BAG_ADDITEM_NOTIFY = 1261;
local RPC_CODE_BAG_CONSUMEITEM_REQUEST = 1262
local RPC_CODE_BAG_ITEMCHANGE_NOTIFY = 1263;
local RPC_CODE_BAG_CLICKITEM_REQUEST = 1264
local RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST = 1265
local RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST = 1266



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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = BagRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_BAGCHANGE_NOTIFY,handler(self,self.BagChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_ADDITEM_NOTIFY,handler(self,self.AddItemCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_ITEMCHANGE_NOTIFY,handler(self,self.ItemChangeCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function UseItem(self,Count,Pos,BagType,TargetId,OptionIdx,_hanlder)
	local PB = self.rpc_pb.BagRpcUseItemAsk()
	PB.Count = Count
	PB.Pos = Pos
	PB.BagType = BagType
	PB.TargetId = TargetId
	PB.OptionIdx = OptionIdx
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_USEITEM_REQUEST',RPC_CODE_BAG_USEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcUseItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => UseItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_USEITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_USEITEM_REQUEST',RPC_CODE_BAG_USEITEM_REQUEST)
end
function SaleItem(self,Pos,Count,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcSaleItemAsk()
	PB.Pos = Pos
	PB.Count = Count
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_SALEITEM_REQUEST',RPC_CODE_BAG_SALEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSaleItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => SaleItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SALEITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_SALEITEM_REQUEST',RPC_CODE_BAG_SALEITEM_REQUEST)
end
function LockItem(self,Pos,IsLock,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcLockItemAsk()
	PB.Pos = Pos
	PB.IsLock = IsLock
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_LOCKITEM_REQUEST',RPC_CODE_BAG_LOCKITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcLockItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => LockItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_LOCKITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_LOCKITEM_REQUEST',RPC_CODE_BAG_LOCKITEM_REQUEST)
end
function Deblocking(self,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcDeblockingAsk()
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_DEBLOCKING_REQUEST',RPC_CODE_BAG_DEBLOCKING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcDeblockingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => Deblocking ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_DEBLOCKING_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_DEBLOCKING_REQUEST',RPC_CODE_BAG_DEBLOCKING_REQUEST)
end
function TakeItem(self,FromBagType,ToBagType,FromPos,_hanlder)
	local PB = self.rpc_pb.BagRpcTakeItemAsk()
	PB.FromBagType = FromBagType
	PB.ToBagType = ToBagType
	PB.FromPos = FromPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_TAKEITEM_REQUEST',RPC_CODE_BAG_TAKEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTakeItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => TakeItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TAKEITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_TAKEITEM_REQUEST',RPC_CODE_BAG_TAKEITEM_REQUEST)
end
function Tidy(self,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcTidyAsk()
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_TIDY_REQUEST',RPC_CODE_BAG_TIDY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTidyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => Tidy ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TIDY_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_TIDY_REQUEST',RPC_CODE_BAG_TIDY_REQUEST)
end
function TakeAllBackBags(self,_hanlder)
	local PB = self.rpc_pb.BagRpcTakeAllBackBagsAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST',RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTakeAllBackBagsReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => TakeAllBackBags ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST',RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST)
end
function MergeItem(self,Pos,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcMergeItemAsk()
	PB.Pos = Pos
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_MERGEITEM_REQUEST',RPC_CODE_BAG_MERGEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcMergeItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => MergeItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_MERGEITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_MERGEITEM_REQUEST',RPC_CODE_BAG_MERGEITEM_REQUEST)
end
function BagSync(self,_hanlder)
	local PB = self.rpc_pb.BagRpcBagSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_BAGSYNC_REQUEST',RPC_CODE_BAG_BAGSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => BagSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGSYNC_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_BAGSYNC_REQUEST',RPC_CODE_BAG_BAGSYNC_REQUEST)
end
function ConsumeItem(self,ItemData,_hanlder)
	local PB = self.rpc_pb.BagRpcConsumeItemAsk()
	for i,v in ipairs(ItemData) do
		table.insert(PB.ItemData,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_CONSUMEITEM_REQUEST',RPC_CODE_BAG_CONSUMEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcConsumeItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => ConsumeItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_CONSUMEITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_CONSUMEITEM_REQUEST',RPC_CODE_BAG_CONSUMEITEM_REQUEST)
end
function ClickItem(self,Guid,_hanlder)
	local PB = self.rpc_pb.BagRpcClickItemAsk()
	PB.Guid = Guid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_CLICKITEM_REQUEST',RPC_CODE_BAG_CLICKITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcClickItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => ClickItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_CLICKITEM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_CLICKITEM_REQUEST',RPC_CODE_BAG_CLICKITEM_REQUEST)
end
function RemoveItemByPos(self,PosList,BagType,_hanlder)
	local PB = self.rpc_pb.BagRpcRemoveItemByPosAsk()
	for i,v in ipairs(PosList) do
		table.insert(PB.PosList,v)
	end
	PB.BagType = BagType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST',RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcRemoveItemByPosReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => RemoveItemByPos ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST',RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST)
end
function ClearBagRedPoint(self,_hanlder)
	local PB = self.rpc_pb.BagRpcClearBagRedPointAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST',RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcClearBagRedPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Bag => ClearBagRedPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST',RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST)
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
-- 给c层 注册服务器通知回调
function registerAddItemCBNotify(self,_hanlder)
	if not self.AddItemCBNotifyCallBack then
		self.AddItemCBNotifyCallBack = {}
	end
	table.insert(self.AddItemCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AddItemCB(self,notifyMsg)
	if self.AddItemCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcAddItemNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AddItemCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAddItemCBNotify(self,_hanlder)
	if nil ~= self.AddItemCBNotifyCallBack then
		for i,callback in ipairs(self.AddItemCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AddItemCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerItemChangeCBNotify(self,_hanlder)
	if not self.ItemChangeCBNotifyCallBack then
		self.ItemChangeCBNotifyCallBack = {}
	end
	table.insert(self.ItemChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ItemChangeCB(self,notifyMsg)
	if self.ItemChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcItemChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ItemChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterItemChangeCBNotify(self,_hanlder)
	if nil ~= self.ItemChangeCBNotifyCallBack then
		for i,callback in ipairs(self.ItemChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ItemChangeCBNotifyCallBack, i )
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
t.para = {{name="Count",t=1},{name="Pos",t=1},{name="BagType",t=1},{name="TargetId",t=1},{name="OptionIdx",t=1}}
t.hand = BagModel.UseItem
t.pb = BagRpc_pb.BagRpcUseItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "SaleItem"
t.para = {{name="Pos",t=1},{name="Count",t=1},{name="BagType",t=1}}
t.hand = BagModel.SaleItem
t.pb = BagRpc_pb.BagRpcSaleItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "LockItem"
t.para = {{name="Pos",t=1},{name="IsLock",t=3},{name="BagType",t=1}}
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

local t = {}
t.name = "MergeItem"
t.para = {{name="Pos",t=1},{name="BagType",t=1}}
t.hand = BagModel.MergeItem
t.pb = BagRpc_pb.BagRpcMergeItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagSync"
t.para = {}
t.hand = BagModel.BagSync
t.pb = BagRpc_pb.BagRpcBagSyncAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "ConsumeItem"
t.para = {{name="ItemData",t=3}}
t.hand = BagModel.ConsumeItem
t.pb = BagRpc_pb.BagRpcConsumeItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "ClickItem"
t.para = {{name="Guid",t=1}}
t.hand = BagModel.ClickItem
t.pb = BagRpc_pb.BagRpcClickItemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "RemoveItemByPos"
t.para = {{name="PosList",t=1},{name="BagType",t=1}}
t.hand = BagModel.RemoveItemByPos
t.pb = BagRpc_pb.BagRpcRemoveItemByPosAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "ClearBagRedPoint"
t.para = {}
t.hand = BagModel.ClearBagRedPoint
t.pb = BagRpc_pb.BagRpcClearBagRedPointAsk()
table.insert(askList.Bag,t)

--]]

