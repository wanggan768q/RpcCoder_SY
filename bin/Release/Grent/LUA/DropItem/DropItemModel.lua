--将变量写入下方
local ModuleId = 20;
local RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY = 2051;





require("app.DropItem.DropItemRpc_pb")

DropItemModel = class("DropItemModel",BaseModel)

function DropItemModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DropItemModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function DropItemModel:ctor()
	DropItemModel.super.ctor(self)
	self.rpc_pb = DropItemRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY,handler(self,self.DropTtemsCB))

  


end

-- 更新数据
function DropItemModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件



-- 给c层 注册服务器通知回调
function registerDropTtemsCBNotify(self,_hanlder)
	if not self.DropTtemsCBNotifyCallBack then
		self.DropTtemsCBNotifyCallBack = {}
	end
	table.insert(self.DropTtemsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DropTtemsCB(self,notifyMsg)
	if self.DropTtemsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DropItemRpcDropTtemsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DropTtemsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDropTtemsCBNotify(self,_hanlder)
	if nil ~= self.DropTtemsCBNotifyCallBack then
		for i,callback in ipairs(self.DropTtemsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DropTtemsCBNotifyCallBack, i )
			end
		end
	end
end





askList.DropItem = {}

