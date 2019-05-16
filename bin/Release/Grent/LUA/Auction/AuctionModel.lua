--将变量写入下方
local ModuleId = 52;
local RPC_CODE_AUCTION_AUCTIONINFO_REQUEST = 5251
local RPC_CODE_AUCTION_SELLITEM_REQUEST = 5252
local RPC_CODE_AUCTION_SELLAGAIN_REQUEST = 5253
local RPC_CODE_AUCTION_BUY_REQUEST = 5254
local RPC_CODE_AUCTION_GETITEM_REQUEST = 5255
local RPC_CODE_AUCTION_RECORD_REQUEST = 5256
local RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST = 5257
local RPC_CODE_AUCTION_SALEPREPARE_REQUEST = 5258
local RPC_CODE_AUCTION_GETITEMBACK_REQUEST = 5259
local RPC_CODE_AUCTION_GETMYSALELIST_REQUEST = 5260





require("app.Auction.AuctionRpc_pb")

AuctionModel = class("AuctionModel",BaseModel)

function AuctionModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=AuctionModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function AuctionModel:ctor()
	AuctionModel.super.ctor(self)
	self.rpc_pb = AuctionRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function AuctionModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function AuctionInfo(self,ItemId,QueueType,CurPage,_hanlder)
	local PB = self.rpc_pb.AuctionRpcAuctionInfoAsk()
	PB.ItemId = ItemId
	PB.QueueType = QueueType
	PB.CurPage = CurPage
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_AUCTIONINFO_REQUEST",RPC_CODE_AUCTION_AUCTIONINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcAuctionInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => AuctionInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_AUCTIONINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_AUCTIONINFO_REQUEST",RPC_CODE_AUCTION_AUCTIONINFO_REQUEST)
end
function SellItem(self,ItemGuid,ItemId,Price,Currency,Count,_hanlder)
	local PB = self.rpc_pb.AuctionRpcSellItemAsk()
	PB.ItemGuid = ItemGuid
	PB.ItemId = ItemId
	PB.Price = Price
	PB.Currency = Currency
	PB.Count = Count
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_SELLITEM_REQUEST",RPC_CODE_AUCTION_SELLITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcSellItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => SellItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_SELLITEM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_SELLITEM_REQUEST",RPC_CODE_AUCTION_SELLITEM_REQUEST)
end
function SellAgain(self,ItemGuid,Price,_hanlder)
	local PB = self.rpc_pb.AuctionRpcSellAgainAsk()
	PB.ItemGuid = ItemGuid
	PB.Price = Price
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_SELLAGAIN_REQUEST",RPC_CODE_AUCTION_SELLAGAIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcSellAgainReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => SellAgain ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_SELLAGAIN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_SELLAGAIN_REQUEST",RPC_CODE_AUCTION_SELLAGAIN_REQUEST)
end
function Buy(self,ItemGuid,Count,_hanlder)
	local PB = self.rpc_pb.AuctionRpcBuyAsk()
	PB.ItemGuid = ItemGuid
	PB.Count = Count
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_BUY_REQUEST",RPC_CODE_AUCTION_BUY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcBuyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => Buy ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_BUY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_BUY_REQUEST",RPC_CODE_AUCTION_BUY_REQUEST)
end
function GetItem(self,BuyRecGuid,SaleRecGuid,_hanlder)
	local PB = self.rpc_pb.AuctionRpcGetItemAsk()
	for i,v in ipairs(BuyRecGuid) do
		table.insert(PB.BuyRecGuid,v)
	end
	for i,v in ipairs(SaleRecGuid) do
		table.insert(PB.SaleRecGuid,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_GETITEM_REQUEST",RPC_CODE_AUCTION_GETITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcGetItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => GetItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_GETITEM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_GETITEM_REQUEST",RPC_CODE_AUCTION_GETITEM_REQUEST)
end
function Record(self,_hanlder)
	local PB = self.rpc_pb.AuctionRpcRecordAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_RECORD_REQUEST",RPC_CODE_AUCTION_RECORD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcRecordReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => Record ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_RECORD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_RECORD_REQUEST",RPC_CODE_AUCTION_RECORD_REQUEST)
end
function ItemInfoByClass(self,ItemClass,ItemId,ItemSubClass,Prof,Level,_hanlder)
	local PB = self.rpc_pb.AuctionRpcItemInfoByClassAsk()
	PB.ItemClass = ItemClass
	for i,v in ipairs(ItemId) do
		table.insert(PB.ItemId,v)
	end
	PB.ItemSubClass = ItemSubClass
	PB.Prof = Prof
	PB.Level = Level
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST",RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcItemInfoByClassReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => ItemInfoByClass ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST",RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST)
end
function SalePrepare(self,ItemId,_hanlder)
	local PB = self.rpc_pb.AuctionRpcSalePrepareAsk()
	PB.ItemId = ItemId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_SALEPREPARE_REQUEST",RPC_CODE_AUCTION_SALEPREPARE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcSalePrepareReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => SalePrepare ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_SALEPREPARE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_SALEPREPARE_REQUEST",RPC_CODE_AUCTION_SALEPREPARE_REQUEST)
end
function GetItemBack(self,ItemGuid,_hanlder)
	local PB = self.rpc_pb.AuctionRpcGetItemBackAsk()
	PB.ItemGuid = ItemGuid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_GETITEMBACK_REQUEST",RPC_CODE_AUCTION_GETITEMBACK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcGetItemBackReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => GetItemBack ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_GETITEMBACK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_GETITEMBACK_REQUEST",RPC_CODE_AUCTION_GETITEMBACK_REQUEST)
end
function GetMySaleList(self,_hanlder)
	local PB = self.rpc_pb.AuctionRpcGetMySaleListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_AUCTION_GETMYSALELIST_REQUEST",RPC_CODE_AUCTION_GETMYSALELIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.AuctionRpcGetMySaleListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Auction => GetMySaleList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_AUCTION_GETMYSALELIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_AUCTION_GETMYSALELIST_REQUEST",RPC_CODE_AUCTION_GETMYSALELIST_REQUEST)
end








askList.Auction = {}

local t = {}
t.name = "AuctionInfo"
t.para = {{name="ItemId",t=1},{name="QueueType",t=1},{name="CurPage",t=1}}
t.hand = AuctionModel.AuctionInfo
t.pb = AuctionRpc_pb.AuctionRpcAuctionInfoAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "SellItem"
t.para = {{name="ItemGuid",t=1},{name="ItemId",t=1},{name="Price",t=1},{name="Currency",t=1},{name="Count",t=1}}
t.hand = AuctionModel.SellItem
t.pb = AuctionRpc_pb.AuctionRpcSellItemAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "SellAgain"
t.para = {{name="ItemGuid",t=1},{name="Price",t=1}}
t.hand = AuctionModel.SellAgain
t.pb = AuctionRpc_pb.AuctionRpcSellAgainAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "Buy"
t.para = {{name="ItemGuid",t=1},{name="Count",t=1}}
t.hand = AuctionModel.Buy
t.pb = AuctionRpc_pb.AuctionRpcBuyAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "GetItem"
t.para = {{name="BuyRecGuid",t=1},{name="SaleRecGuid",t=1}}
t.hand = AuctionModel.GetItem
t.pb = AuctionRpc_pb.AuctionRpcGetItemAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "Record"
t.para = {}
t.hand = AuctionModel.Record
t.pb = AuctionRpc_pb.AuctionRpcRecordAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "ItemInfoByClass"
t.para = {{name="ItemClass",t=1},{name="ItemId",t=1},{name="ItemSubClass",t=1},{name="Prof",t=1},{name="Level",t=1}}
t.hand = AuctionModel.ItemInfoByClass
t.pb = AuctionRpc_pb.AuctionRpcItemInfoByClassAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "SalePrepare"
t.para = {{name="ItemId",t=1}}
t.hand = AuctionModel.SalePrepare
t.pb = AuctionRpc_pb.AuctionRpcSalePrepareAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "GetItemBack"
t.para = {{name="ItemGuid",t=1}}
t.hand = AuctionModel.GetItemBack
t.pb = AuctionRpc_pb.AuctionRpcGetItemBackAsk()
table.insert(askList.Auction,t)

local t = {}
t.name = "GetMySaleList"
t.para = {}
t.hand = AuctionModel.GetMySaleList
t.pb = AuctionRpc_pb.AuctionRpcGetMySaleListAsk()
table.insert(askList.Auction,t)

