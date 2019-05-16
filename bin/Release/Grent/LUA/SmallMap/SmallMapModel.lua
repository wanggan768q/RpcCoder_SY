--将变量写入下方
local ModuleId = 14;
local RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY = 1451;
local RPC_CODE_SMALLMAP_DELOBJ_NOTIFY = 1452;





require("app.SmallMap.SmallMapRpc_pb")

SmallMapModel = class("SmallMapModel",BaseModel)

function SmallMapModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=SmallMapModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function SmallMapModel:ctor()
	SmallMapModel.super.ctor(self)
	self.rpc_pb = SmallMapRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY,handler(self,self.NewObjCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SMALLMAP_DELOBJ_NOTIFY,handler(self,self.DelObjCB))

  


end

-- 更新数据
function SmallMapModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件



-- 给c层 注册服务器通知回调
function registerNewObjCBNotify(self,_hanlder)
	if not self.NewObjCBNotifyCallBack then
		self.NewObjCBNotifyCallBack = {}
	end
	table.insert(self.NewObjCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewObjCB(self,notifyMsg)
	if self.NewObjCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SmallMapRpcNewObjNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewObjCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewObjCBNotify(self,_hanlder)
	if nil ~= self.NewObjCBNotifyCallBack then
		for i,callback in ipairs(self.NewObjCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewObjCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDelObjCBNotify(self,_hanlder)
	if not self.DelObjCBNotifyCallBack then
		self.DelObjCBNotifyCallBack = {}
	end
	table.insert(self.DelObjCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DelObjCB(self,notifyMsg)
	if self.DelObjCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SmallMapRpcDelObjNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DelObjCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDelObjCBNotify(self,_hanlder)
	if nil ~= self.DelObjCBNotifyCallBack then
		for i,callback in ipairs(self.DelObjCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DelObjCBNotifyCallBack, i )
			end
		end
	end
end





askList.SmallMap = {}

