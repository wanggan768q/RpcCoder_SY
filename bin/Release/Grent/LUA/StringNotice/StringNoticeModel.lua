--将变量写入下方
local ModuleId = 55;
local RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY = 5551;





require("app.StringNotice.StringNoticeRpc_pb")

StringNoticeModel = class("StringNoticeModel",BaseModel)

function StringNoticeModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=StringNoticeModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function StringNoticeModel:ctor()
	StringNoticeModel.super.ctor(self)
	self.rpc_pb = StringNoticeRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY,handler(self,self.NoticeCB))

  


end

-- 更新数据
function StringNoticeModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件



-- 给c层 注册服务器通知回调
function registerNoticeCBNotify(self,_hanlder)
	if not self.NoticeCBNotifyCallBack then
		self.NoticeCBNotifyCallBack = {}
	end
	table.insert(self.NoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NoticeCB(self,notifyMsg)
	if self.NoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.StringNoticeRpcNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNoticeCBNotify(self,_hanlder)
	if nil ~= self.NoticeCBNotifyCallBack then
		for i,callback in ipairs(self.NoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NoticeCBNotifyCallBack, i )
			end
		end
	end
end





askList.StringNotice = {}

