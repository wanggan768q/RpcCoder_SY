--将变量写入下方
local ModuleId = 1;




require("app.aaaa.aaaaV1Data_pb")
require("app.aaaa.aaaaRpc_pb")

aaaaModel = class("aaaaModel",BaseModel)

function aaaaModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=aaaaModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function aaaaModel:ctor()
	aaaaModel.super.ctor(self)
	self.rpc_pb = aaaaRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=aaaaV1Data_pb


end

-- 更新数据
function aaaaModel:UpdateField(Id, data, Index, len)
	if
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.aaaa = {}

