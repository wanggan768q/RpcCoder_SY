--将变量写入下方
local ModuleId = 1;





require("app.asd.asdRpc_pb")

asdModel = class("asdModel",BaseModel)

function asdModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function asdModel:ctor()
	asdModel.super.ctor(self)
	self.rpc_pb = asdRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function asdModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.asd = {}

