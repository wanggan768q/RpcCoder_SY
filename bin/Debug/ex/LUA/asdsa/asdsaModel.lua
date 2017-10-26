--将变量写入下方
local ModuleId = 1;





require("app.asdsa.asdsaRpc_pb")

asdsaModel = class("asdsaModel",BaseModel)

function asdsaModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdsaModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function asdsaModel:ctor()
	asdsaModel.super.ctor(self)
	self.rpc_pb = asdsaRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function asdsaModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.asdsa = {}

