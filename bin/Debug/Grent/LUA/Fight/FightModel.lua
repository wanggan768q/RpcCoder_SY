--将变量写入下方
local ModuleId = 9;
local RPC_CODE_FIGHT_USESKILLACTION_NOTIFY = 951;





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
require("3rd/pblua/FightRpc_pb")
local  FightRpc_pb = FightRpc_pb
module("FightModel")

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
	self.rpc_pb = FightRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_USESKILLACTION_NOTIFY,handler(self,self.UseSkillActionCB))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件



-- 给c层 注册服务器通知回调
function registerUseSkillActionCBNotify(self,_hanlder)
	if not self.UseSkillActionCBNotifyCallBack then
		self.UseSkillActionCBNotifyCallBack = {}
	end
	table.insert(self.UseSkillActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UseSkillActionCB(self,notifyMsg)
	if self.UseSkillActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcUseSkillActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UseSkillActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUseSkillActionCBNotify(self,_hanlder)
	if nil ~= self.UseSkillActionCBNotifyCallBack then
		for i,callback in ipairs(self.UseSkillActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UseSkillActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function UseSkillActionNotify(ObjTargetId,SkillId,X,Y,Dir)
	local PB = self.rpc_pb.FightRpcUseSkillActionNotify()
	PB.ObjTargetId = ObjTargetId
	PB.SkillId = SkillId
	PB.X = X
	PB.Y = Y
	PB.Dir = Dir
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_FIGHT_USESKILLACTION_NOTIFY, pb_data)
end




--[[
askList.Fight = {}

--]]