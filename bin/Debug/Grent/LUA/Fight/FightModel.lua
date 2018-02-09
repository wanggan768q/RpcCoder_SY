--将变量写入下方
local ModuleId = 9;
local RPC_CODE_FIGHT_USESKILLACTION_NOTIFY = 951;
local RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY = 952;
local RPC_CODE_FIGHT_BUFFACTION_NOTIFY = 953;
local RPC_CODE_FIGHT_STATEACTION_NOTIFY = 954;
local RPC_CODE_FIGHT_REVIVEACTION_NOTIFY = 955;
local RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY = 956;
local RPC_CODE_FIGHT_DROPACTION_NOTIFY = 957;
local RPC_CODE_FIGHT_USEITEMACTION_NOTIFY = 958;
local RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY = 959;
local RPC_CODE_FIGHT_USESKILL_REQUEST = 960
local RPC_CODE_FIGHT_HURTACTION_NOTIFY = 961;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/FightRpc_pb")
local  FightRpc_pb = FightRpc_pb
module("FightModel")





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
	self.rpc_pb = FightRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_USESKILLACTION_NOTIFY,handler(self,self.UseSkillActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY,handler(self,self.ShowExpActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_BUFFACTION_NOTIFY,handler(self,self.BuffActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_STATEACTION_NOTIFY,handler(self,self.StateActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_REVIVEACTION_NOTIFY,handler(self,self.ReviveActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY,handler(self,self.ComboSkillActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_DROPACTION_NOTIFY,handler(self,self.DropActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_USEITEMACTION_NOTIFY,handler(self,self.UseItemActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY,handler(self,self.HpChangeActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_HURTACTION_NOTIFY,handler(self,self.HurtActionCB))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function UseSkill(self,ObjTargetId,SkillId,CastingDir,X,Y,Z,MomentIndex,_hanlder)
	local PB = self.rpc_pb.FightRpcUseSkillAsk()
	PB.ObjTargetId = ObjTargetId
	PB.SkillId = SkillId
	PB.CastingDir = CastingDir
	PB.X = X
	PB.Y = Y
	PB.Z = Z
	PB.MomentIndex = MomentIndex
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcUseSkillReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_USESKILL_REQUEST, pb_data, callback)
	showNetTip(self)
end



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
function registerShowExpActionCBNotify(self,_hanlder)
	if not self.ShowExpActionCBNotifyCallBack then
		self.ShowExpActionCBNotifyCallBack = {}
	end
	table.insert(self.ShowExpActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ShowExpActionCB(self,notifyMsg)
	if self.ShowExpActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcShowExpActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ShowExpActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterShowExpActionCBNotify(self,_hanlder)
	if nil ~= self.ShowExpActionCBNotifyCallBack then
		for i,callback in ipairs(self.ShowExpActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ShowExpActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBuffActionCBNotify(self,_hanlder)
	if not self.BuffActionCBNotifyCallBack then
		self.BuffActionCBNotifyCallBack = {}
	end
	table.insert(self.BuffActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BuffActionCB(self,notifyMsg)
	if self.BuffActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcBuffActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BuffActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBuffActionCBNotify(self,_hanlder)
	if nil ~= self.BuffActionCBNotifyCallBack then
		for i,callback in ipairs(self.BuffActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BuffActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerStateActionCBNotify(self,_hanlder)
	if not self.StateActionCBNotifyCallBack then
		self.StateActionCBNotifyCallBack = {}
	end
	table.insert(self.StateActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function StateActionCB(self,notifyMsg)
	if self.StateActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcStateActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.StateActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterStateActionCBNotify(self,_hanlder)
	if nil ~= self.StateActionCBNotifyCallBack then
		for i,callback in ipairs(self.StateActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.StateActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerReviveActionCBNotify(self,_hanlder)
	if not self.ReviveActionCBNotifyCallBack then
		self.ReviveActionCBNotifyCallBack = {}
	end
	table.insert(self.ReviveActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReviveActionCB(self,notifyMsg)
	if self.ReviveActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcReviveActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReviveActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReviveActionCBNotify(self,_hanlder)
	if nil ~= self.ReviveActionCBNotifyCallBack then
		for i,callback in ipairs(self.ReviveActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReviveActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerComboSkillActionCBNotify(self,_hanlder)
	if not self.ComboSkillActionCBNotifyCallBack then
		self.ComboSkillActionCBNotifyCallBack = {}
	end
	table.insert(self.ComboSkillActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ComboSkillActionCB(self,notifyMsg)
	if self.ComboSkillActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcComboSkillActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ComboSkillActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterComboSkillActionCBNotify(self,_hanlder)
	if nil ~= self.ComboSkillActionCBNotifyCallBack then
		for i,callback in ipairs(self.ComboSkillActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ComboSkillActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDropActionCBNotify(self,_hanlder)
	if not self.DropActionCBNotifyCallBack then
		self.DropActionCBNotifyCallBack = {}
	end
	table.insert(self.DropActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DropActionCB(self,notifyMsg)
	if self.DropActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcDropActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DropActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDropActionCBNotify(self,_hanlder)
	if nil ~= self.DropActionCBNotifyCallBack then
		for i,callback in ipairs(self.DropActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DropActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUseItemActionCBNotify(self,_hanlder)
	if not self.UseItemActionCBNotifyCallBack then
		self.UseItemActionCBNotifyCallBack = {}
	end
	table.insert(self.UseItemActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UseItemActionCB(self,notifyMsg)
	if self.UseItemActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcUseItemActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UseItemActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUseItemActionCBNotify(self,_hanlder)
	if nil ~= self.UseItemActionCBNotifyCallBack then
		for i,callback in ipairs(self.UseItemActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UseItemActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerHpChangeActionCBNotify(self,_hanlder)
	if not self.HpChangeActionCBNotifyCallBack then
		self.HpChangeActionCBNotifyCallBack = {}
	end
	table.insert(self.HpChangeActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function HpChangeActionCB(self,notifyMsg)
	if self.HpChangeActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcHpChangeActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.HpChangeActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterHpChangeActionCBNotify(self,_hanlder)
	if nil ~= self.HpChangeActionCBNotifyCallBack then
		for i,callback in ipairs(self.HpChangeActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.HpChangeActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerHurtActionCBNotify(self,_hanlder)
	if not self.HurtActionCBNotifyCallBack then
		self.HurtActionCBNotifyCallBack = {}
	end
	table.insert(self.HurtActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function HurtActionCB(self,notifyMsg)
	if self.HurtActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcHurtActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.HurtActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterHurtActionCBNotify(self,_hanlder)
	if nil ~= self.HurtActionCBNotifyCallBack then
		for i,callback in ipairs(self.HurtActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.HurtActionCBNotifyCallBack, i )
			end
		end
	end
end


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
	
end

--[[
askList.Fight = {}

local t = {}
t.name = "UseSkill"
t.para = {{name="ObjTargetId",t=1},{name="SkillId",t=1},{name="CastingDir",t=3},{name="X",t=3},{name="Y",t=3},{name="Z",t=3},{name="MomentIndex",t=1}}
t.hand = FightModel.UseSkill
t.pb = FightRpc_pb.FightRpcUseSkillAsk()
table.insert(askList.Fight,t)

--]]

