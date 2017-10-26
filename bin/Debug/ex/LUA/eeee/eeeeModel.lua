--将变量写入下方
local ModuleId = 1;





require("app.eeee.eeeeRpc_pb")

eeeeModel = class("eeeeModel",BaseModel)

function eeeeModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=eeeeModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function eeeeModel:ctor()
	eeeeModel.super.ctor(self)
	self.rpc_pb = eeeeRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function eeeeModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.eeee = {}

