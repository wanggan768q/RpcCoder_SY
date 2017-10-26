--将变量写入下方
$RPCVALUES$

$TempVar$

$Require$
local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
require("3rd/pblua/$TEMPLATE$Rpc_pb")
local  $TEMPLATE$Rpc_pb = $TEMPLATE$Rpc_pb
module("$TEMPLATE$Model")

function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)

end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = $TEMPLATE$Rpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
$NOTIFYTD$
  
$TempVar2$

end

-- 更新数据
function UpdateField(self,Id, data, Index, len)
$UpdataValue$
	
	dataCallback(self,Id,Index)
end


-- 业务事件
$ASKFUNCTION$


$CALLBACK$



--[[
$TESTS$
--]]