--将变量写入下方
local ModuleId = 1;





require("app.Config.ConfigRpc_pb")

ConfigModel = class("ConfigModel",BaseModel)

function ConfigModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ConfigModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ConfigModel:ctor()
	ConfigModel.super.ctor(self)
	self.rpc_pb = ConfigRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function ConfigModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.Config = {}

