--将变量写入下方
$RPCVALUES$

$Require$
local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/$TEMPLATE$Rpc_pb")
local  $TEMPLATE$Rpc_pb = $TEMPLATE$Rpc_pb
module("$TEMPLATE$Model")


$TempVar$


function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			callback(Id,Index)
		end
	end
end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = $TEMPLATE$Rpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
$NOTIFYTD$
  
$TempVar2$

end

-- 更新数据
function UpdateField(self,uf)
$UpdataValue$
end


-- 业务事件
$ASKFUNCTION$


$CALLBACK$

function registerDataCallback(self,_hanlder)
	if not self.DataCallback then
		self.DataCallback = {}
	end
	table.insert(self.DataCallback,_hanlder)
end

function unregisterDataCallback(self,_hanlder)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			if callback == _hanlder then
				table.remove(self.DataCallback, i )
			end
		end
	end
end

function GetValue(self, Id,Index )
	-- body
	$GetValue$
end

--[[
$TESTS$
--]]

