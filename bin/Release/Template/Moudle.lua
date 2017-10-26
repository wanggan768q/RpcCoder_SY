--将变量写入下方
$RPCVALUES$

$TempVar$

$Require$
require("app.$TEMPLATE$.$TEMPLATE$Rpc_pb")

$TEMPLATE$Model = class("$TEMPLATE$Model",BaseModel)

function $TEMPLATE$Model:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=$TEMPLATE$Model.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function $TEMPLATE$Model:ctor()
	$TEMPLATE$Model.super.ctor(self)
	self.rpc_pb = $TEMPLATE$Rpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
$NOTIFYTD$
  
$TempVar2$

end

-- 更新数据
function $TEMPLATE$Model:UpdateField(Id, data, Index, len)
$UpdataValue$
	
	self:dataCallback(Id,Index)
end


-- 业务事件
$ASKFUNCTION$


$CALLBACK$




$TESTS$
