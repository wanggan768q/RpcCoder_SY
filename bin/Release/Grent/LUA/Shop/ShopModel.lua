--将变量写入下方
local ModuleId = 33;
local RPC_CODE_SHOP_BUYITEM_REQUEST = 3351
local RPC_CODE_SHOP_SHOPINFO_REQUEST = 3352





require("app.Shop.ShopRpc_pb")

ShopModel = class("ShopModel",BaseModel)

function ShopModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ShopModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ShopModel:ctor()
	ShopModel.super.ctor(self)
	self.rpc_pb = ShopRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function ShopModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BuyItem(self,ShopItemId,ItemNum,_hanlder)
	local PB = self.rpc_pb.ShopRpcBuyItemAsk()
	PB.ShopItemId = ShopItemId
	PB.ItemNum = ItemNum
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SHOP_BUYITEM_REQUEST",RPC_CODE_SHOP_BUYITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ShopRpcBuyItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Shop => BuyItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SHOP_BUYITEM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SHOP_BUYITEM_REQUEST",RPC_CODE_SHOP_BUYITEM_REQUEST)
end
function ShopInfo(self,RoleID,_hanlder)
	local PB = self.rpc_pb.ShopRpcShopInfoAsk()
	PB.RoleID = RoleID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SHOP_SHOPINFO_REQUEST",RPC_CODE_SHOP_SHOPINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ShopRpcShopInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Shop => ShopInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SHOP_SHOPINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SHOP_SHOPINFO_REQUEST",RPC_CODE_SHOP_SHOPINFO_REQUEST)
end








askList.Shop = {}

local t = {}
t.name = "BuyItem"
t.para = {{name="ShopItemId",t=1},{name="ItemNum",t=1}}
t.hand = ShopModel.BuyItem
t.pb = ShopRpc_pb.ShopRpcBuyItemAsk()
table.insert(askList.Shop,t)

local t = {}
t.name = "ShopInfo"
t.para = {{name="RoleID",t=1}}
t.hand = ShopModel.ShopInfo
t.pb = ShopRpc_pb.ShopRpcShopInfoAsk()
table.insert(askList.Shop,t)

