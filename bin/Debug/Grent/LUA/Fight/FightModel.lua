-- FightModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

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
local RPC_CODE_FIGHT_REPELACTION_NOTIFY = 962;
local RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY = 963;
local RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY = 964;
local RPC_CODE_FIGHT_BUFFLIST_NOTIFY = 965;
local RPC_CODE_FIGHT_REDUCECD_NOTIFY = 966;
local RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY = 967;
local RPC_CODE_FIGHT_SKILLCD_NOTIFY = 968;
local RPC_CODE_FIGHT_AUTOCOMBATMONSTER_NOTIFY = 969;
local RPC_CODE_FIGHT_TRANSLATEACTION_NOTIFY = 970;
local RPC_CODE_FIGHT_CANTADDBUFFTIP_NOTIFY = 971;
local RPC_CODE_FIGHT_ATTACKWARNING_NOTIFY = 972;
local RPC_CODE_FIGHT_INTERRUPTACTION_NOTIFY = 973;
local RPC_CODE_FIGHT_SKILLPREPARE_REQUEST = 974
local RPC_CODE_FIGHT_SKILLPREPAREACTION_NOTIFY = 975;
local RPC_CODE_FIGHT_CHAINMAGICJUMP_NOTIFY = 976;
local RPC_CODE_FIGHT_BLACKHOLEACTION_NOTIFY = 977;
local RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST = 978
local RPC_CODE_FIGHT_LOOPACTIONCANCELOTHER_NOTIFY = 979;
local RPC_CODE_FIGHT_SKILLLIST_NOTIFY = 980;
local RPC_CODE_FIGHT_USEPETSKILL_REQUEST = 981
local RPC_CODE_FIGHT_REMOVEMODIFYSKILL_NOTIFY = 982;
local RPC_CODE_FIGHT_LINKMAGICACTION_NOTIFY = 983;
local RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST = 984



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
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
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_REPELACTION_NOTIFY,handler(self,self.RepelActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY,handler(self,self.ObjDeadActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY,handler(self,self.FightTipsCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_BUFFLIST_NOTIFY,handler(self,self.BuffListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_REDUCECD_NOTIFY,handler(self,self.ReduceCDCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY,handler(self,self.ReliveNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_SKILLCD_NOTIFY,handler(self,self.SkillCDCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_AUTOCOMBATMONSTER_NOTIFY,handler(self,self.AutoCombatMonsterCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_TRANSLATEACTION_NOTIFY,handler(self,self.TranslateActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_CANTADDBUFFTIP_NOTIFY,handler(self,self.CantAddBuffTipCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_ATTACKWARNING_NOTIFY,handler(self,self.AttackWarningCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_INTERRUPTACTION_NOTIFY,handler(self,self.InterruptActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_SKILLPREPAREACTION_NOTIFY,handler(self,self.SkillPrepareActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_CHAINMAGICJUMP_NOTIFY,handler(self,self.ChainMagicJumpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_BLACKHOLEACTION_NOTIFY,handler(self,self.BlackHoleActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_LOOPACTIONCANCELOTHER_NOTIFY,handler(self,self.LoopActionCancelOtherCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_SKILLLIST_NOTIFY,handler(self,self.SkillListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_REMOVEMODIFYSKILL_NOTIFY,handler(self,self.RemoveModifySkillCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_LINKMAGICACTION_NOTIFY,handler(self,self.LinkMagicActionCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function UseSkill(self,ObjTargetId,SkillId,CastingDir,X,Y,Z,MomentIndex,CustomSkiData,CurrentPos,_hanlder)
	local PB = self.rpc_pb.FightRpcUseSkillAsk()
	for i,v in ipairs(ObjTargetId) do
		table.insert(PB.ObjTargetId,v)
	end
	PB.SkillId = SkillId
	PB.CastingDir = CastingDir
	PB.X = X
	PB.Y = Y
	PB.Z = Z
	PB.MomentIndex = MomentIndex
	PB.CustomSkiData.Key = CustomSkiData.Key
	PB.CustomSkiData.KeyType = CustomSkiData.KeyType
	PB.CustomSkiData.IntV = CustomSkiData.IntV
	PB.CustomSkiData.BoolV = CustomSkiData.BoolV
	PB.CurrentPos.X = CurrentPos.X
	PB.CurrentPos.Z = CurrentPos.Z
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_FIGHT_USESKILL_REQUEST',RPC_CODE_FIGHT_USESKILL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcUseSkillReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Fight => UseSkill ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_USESKILL_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_FIGHT_USESKILL_REQUEST',RPC_CODE_FIGHT_USESKILL_REQUEST)
end
function SkillPrepare(self,SkillId,Type,_hanlder)
	local PB = self.rpc_pb.FightRpcSkillPrepareAsk()
	PB.SkillId = SkillId
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_FIGHT_SKILLPREPARE_REQUEST',RPC_CODE_FIGHT_SKILLPREPARE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcSkillPrepareReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Fight => SkillPrepare ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_SKILLPREPARE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_FIGHT_SKILLPREPARE_REQUEST',RPC_CODE_FIGHT_SKILLPREPARE_REQUEST)
end
function LoopActionCancel(self,SkillId,_hanlder)
	local PB = self.rpc_pb.FightRpcLoopActionCancelAsk()
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST',RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcLoopActionCancelReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Fight => LoopActionCancel ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST',RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST)
end
function UsePetSkill(self,ObjTargetId,SkillId,CastingDir,CurrentPos,TargetPos,_hanlder)
	local PB = self.rpc_pb.FightRpcUsePetSkillAsk()
	for i,v in ipairs(ObjTargetId) do
		table.insert(PB.ObjTargetId,v)
	end
	PB.SkillId = SkillId
	PB.CastingDir = CastingDir
	PB.CurrentPos.X = CurrentPos.X
	PB.CurrentPos.Z = CurrentPos.Z
	PB.TargetPos.X = TargetPos.X
	PB.TargetPos.Z = TargetPos.Z
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_FIGHT_USEPETSKILL_REQUEST',RPC_CODE_FIGHT_USEPETSKILL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcUsePetSkillReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Fight => UsePetSkill ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_USEPETSKILL_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_FIGHT_USEPETSKILL_REQUEST',RPC_CODE_FIGHT_USEPETSKILL_REQUEST)
end
function MonsterInteract(self,TargetId,_hanlder)
	local PB = self.rpc_pb.FightRpcMonsterInteractAsk()
	PB.TargetId = TargetId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST',RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcMonsterInteractReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Fight => MonsterInteract ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST',RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST)
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
-- 给c层 注册服务器通知回调
function registerRepelActionCBNotify(self,_hanlder)
	if not self.RepelActionCBNotifyCallBack then
		self.RepelActionCBNotifyCallBack = {}
	end
	table.insert(self.RepelActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RepelActionCB(self,notifyMsg)
	if self.RepelActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcRepelActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RepelActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRepelActionCBNotify(self,_hanlder)
	if nil ~= self.RepelActionCBNotifyCallBack then
		for i,callback in ipairs(self.RepelActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RepelActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerObjDeadActionCBNotify(self,_hanlder)
	if not self.ObjDeadActionCBNotifyCallBack then
		self.ObjDeadActionCBNotifyCallBack = {}
	end
	table.insert(self.ObjDeadActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ObjDeadActionCB(self,notifyMsg)
	if self.ObjDeadActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcObjDeadActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ObjDeadActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterObjDeadActionCBNotify(self,_hanlder)
	if nil ~= self.ObjDeadActionCBNotifyCallBack then
		for i,callback in ipairs(self.ObjDeadActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ObjDeadActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerFightTipsCBNotify(self,_hanlder)
	if not self.FightTipsCBNotifyCallBack then
		self.FightTipsCBNotifyCallBack = {}
	end
	table.insert(self.FightTipsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function FightTipsCB(self,notifyMsg)
	if self.FightTipsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcFightTipsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.FightTipsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterFightTipsCBNotify(self,_hanlder)
	if nil ~= self.FightTipsCBNotifyCallBack then
		for i,callback in ipairs(self.FightTipsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.FightTipsCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBuffListCBNotify(self,_hanlder)
	if not self.BuffListCBNotifyCallBack then
		self.BuffListCBNotifyCallBack = {}
	end
	table.insert(self.BuffListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BuffListCB(self,notifyMsg)
	if self.BuffListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcBuffListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BuffListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBuffListCBNotify(self,_hanlder)
	if nil ~= self.BuffListCBNotifyCallBack then
		for i,callback in ipairs(self.BuffListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BuffListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerReduceCDCBNotify(self,_hanlder)
	if not self.ReduceCDCBNotifyCallBack then
		self.ReduceCDCBNotifyCallBack = {}
	end
	table.insert(self.ReduceCDCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReduceCDCB(self,notifyMsg)
	if self.ReduceCDCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcReduceCDNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReduceCDCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReduceCDCBNotify(self,_hanlder)
	if nil ~= self.ReduceCDCBNotifyCallBack then
		for i,callback in ipairs(self.ReduceCDCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReduceCDCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerReliveNotifyCBNotify(self,_hanlder)
	if not self.ReliveNotifyCBNotifyCallBack then
		self.ReliveNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ReliveNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReliveNotifyCB(self,notifyMsg)
	if self.ReliveNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcReliveNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReliveNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReliveNotifyCBNotify(self,_hanlder)
	if nil ~= self.ReliveNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ReliveNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReliveNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSkillCDCBNotify(self,_hanlder)
	if not self.SkillCDCBNotifyCallBack then
		self.SkillCDCBNotifyCallBack = {}
	end
	table.insert(self.SkillCDCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SkillCDCB(self,notifyMsg)
	if self.SkillCDCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcSkillCDNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SkillCDCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSkillCDCBNotify(self,_hanlder)
	if nil ~= self.SkillCDCBNotifyCallBack then
		for i,callback in ipairs(self.SkillCDCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SkillCDCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerAutoCombatMonsterCBNotify(self,_hanlder)
	if not self.AutoCombatMonsterCBNotifyCallBack then
		self.AutoCombatMonsterCBNotifyCallBack = {}
	end
	table.insert(self.AutoCombatMonsterCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AutoCombatMonsterCB(self,notifyMsg)
	if self.AutoCombatMonsterCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcAutoCombatMonsterNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AutoCombatMonsterCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAutoCombatMonsterCBNotify(self,_hanlder)
	if nil ~= self.AutoCombatMonsterCBNotifyCallBack then
		for i,callback in ipairs(self.AutoCombatMonsterCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AutoCombatMonsterCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerTranslateActionCBNotify(self,_hanlder)
	if not self.TranslateActionCBNotifyCallBack then
		self.TranslateActionCBNotifyCallBack = {}
	end
	table.insert(self.TranslateActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TranslateActionCB(self,notifyMsg)
	if self.TranslateActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcTranslateActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TranslateActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTranslateActionCBNotify(self,_hanlder)
	if nil ~= self.TranslateActionCBNotifyCallBack then
		for i,callback in ipairs(self.TranslateActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TranslateActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCantAddBuffTipCBNotify(self,_hanlder)
	if not self.CantAddBuffTipCBNotifyCallBack then
		self.CantAddBuffTipCBNotifyCallBack = {}
	end
	table.insert(self.CantAddBuffTipCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CantAddBuffTipCB(self,notifyMsg)
	if self.CantAddBuffTipCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcCantAddBuffTipNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CantAddBuffTipCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCantAddBuffTipCBNotify(self,_hanlder)
	if nil ~= self.CantAddBuffTipCBNotifyCallBack then
		for i,callback in ipairs(self.CantAddBuffTipCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CantAddBuffTipCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerAttackWarningCBNotify(self,_hanlder)
	if not self.AttackWarningCBNotifyCallBack then
		self.AttackWarningCBNotifyCallBack = {}
	end
	table.insert(self.AttackWarningCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AttackWarningCB(self,notifyMsg)
	if self.AttackWarningCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcAttackWarningNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AttackWarningCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAttackWarningCBNotify(self,_hanlder)
	if nil ~= self.AttackWarningCBNotifyCallBack then
		for i,callback in ipairs(self.AttackWarningCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AttackWarningCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerInterruptActionCBNotify(self,_hanlder)
	if not self.InterruptActionCBNotifyCallBack then
		self.InterruptActionCBNotifyCallBack = {}
	end
	table.insert(self.InterruptActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function InterruptActionCB(self,notifyMsg)
	if self.InterruptActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcInterruptActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.InterruptActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterInterruptActionCBNotify(self,_hanlder)
	if nil ~= self.InterruptActionCBNotifyCallBack then
		for i,callback in ipairs(self.InterruptActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.InterruptActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSkillPrepareActionCBNotify(self,_hanlder)
	if not self.SkillPrepareActionCBNotifyCallBack then
		self.SkillPrepareActionCBNotifyCallBack = {}
	end
	table.insert(self.SkillPrepareActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SkillPrepareActionCB(self,notifyMsg)
	if self.SkillPrepareActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcSkillPrepareActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SkillPrepareActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSkillPrepareActionCBNotify(self,_hanlder)
	if nil ~= self.SkillPrepareActionCBNotifyCallBack then
		for i,callback in ipairs(self.SkillPrepareActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SkillPrepareActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChainMagicJumpCBNotify(self,_hanlder)
	if not self.ChainMagicJumpCBNotifyCallBack then
		self.ChainMagicJumpCBNotifyCallBack = {}
	end
	table.insert(self.ChainMagicJumpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChainMagicJumpCB(self,notifyMsg)
	if self.ChainMagicJumpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcChainMagicJumpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChainMagicJumpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChainMagicJumpCBNotify(self,_hanlder)
	if nil ~= self.ChainMagicJumpCBNotifyCallBack then
		for i,callback in ipairs(self.ChainMagicJumpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChainMagicJumpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBlackHoleActionCBNotify(self,_hanlder)
	if not self.BlackHoleActionCBNotifyCallBack then
		self.BlackHoleActionCBNotifyCallBack = {}
	end
	table.insert(self.BlackHoleActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BlackHoleActionCB(self,notifyMsg)
	if self.BlackHoleActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcBlackHoleActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BlackHoleActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBlackHoleActionCBNotify(self,_hanlder)
	if nil ~= self.BlackHoleActionCBNotifyCallBack then
		for i,callback in ipairs(self.BlackHoleActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BlackHoleActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLoopActionCancelOtherCBNotify(self,_hanlder)
	if not self.LoopActionCancelOtherCBNotifyCallBack then
		self.LoopActionCancelOtherCBNotifyCallBack = {}
	end
	table.insert(self.LoopActionCancelOtherCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LoopActionCancelOtherCB(self,notifyMsg)
	if self.LoopActionCancelOtherCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcLoopActionCancelOtherNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LoopActionCancelOtherCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLoopActionCancelOtherCBNotify(self,_hanlder)
	if nil ~= self.LoopActionCancelOtherCBNotifyCallBack then
		for i,callback in ipairs(self.LoopActionCancelOtherCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LoopActionCancelOtherCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSkillListCBNotify(self,_hanlder)
	if not self.SkillListCBNotifyCallBack then
		self.SkillListCBNotifyCallBack = {}
	end
	table.insert(self.SkillListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SkillListCB(self,notifyMsg)
	if self.SkillListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcSkillListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SkillListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSkillListCBNotify(self,_hanlder)
	if nil ~= self.SkillListCBNotifyCallBack then
		for i,callback in ipairs(self.SkillListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SkillListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRemoveModifySkillCBNotify(self,_hanlder)
	if not self.RemoveModifySkillCBNotifyCallBack then
		self.RemoveModifySkillCBNotifyCallBack = {}
	end
	table.insert(self.RemoveModifySkillCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RemoveModifySkillCB(self,notifyMsg)
	if self.RemoveModifySkillCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcRemoveModifySkillNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RemoveModifySkillCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRemoveModifySkillCBNotify(self,_hanlder)
	if nil ~= self.RemoveModifySkillCBNotifyCallBack then
		for i,callback in ipairs(self.RemoveModifySkillCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RemoveModifySkillCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLinkMagicActionCBNotify(self,_hanlder)
	if not self.LinkMagicActionCBNotifyCallBack then
		self.LinkMagicActionCBNotifyCallBack = {}
	end
	table.insert(self.LinkMagicActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LinkMagicActionCB(self,notifyMsg)
	if self.LinkMagicActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcLinkMagicActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LinkMagicActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLinkMagicActionCBNotify(self,_hanlder)
	if nil ~= self.LinkMagicActionCBNotifyCallBack then
		for i,callback in ipairs(self.LinkMagicActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LinkMagicActionCBNotifyCallBack, i )
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
t.para = {{name="ObjTargetId",t=1},{name="SkillId",t=1},{name="CastingDir",t=3},{name="X",t=3},{name="Y",t=3},{name="Z",t=3},{name="MomentIndex",t=1},{name="CustomSkiData",t=3},{name="CurrentPos",t=3}}
t.hand = FightModel.UseSkill
t.pb = FightRpc_pb.FightRpcUseSkillAsk()
table.insert(askList.Fight,t)

local t = {}
t.name = "SkillPrepare"
t.para = {{name="SkillId",t=1},{name="Type",t=1}}
t.hand = FightModel.SkillPrepare
t.pb = FightRpc_pb.FightRpcSkillPrepareAsk()
table.insert(askList.Fight,t)

local t = {}
t.name = "LoopActionCancel"
t.para = {{name="SkillId",t=1}}
t.hand = FightModel.LoopActionCancel
t.pb = FightRpc_pb.FightRpcLoopActionCancelAsk()
table.insert(askList.Fight,t)

local t = {}
t.name = "UsePetSkill"
t.para = {{name="ObjTargetId",t=1},{name="SkillId",t=1},{name="CastingDir",t=3},{name="CurrentPos",t=3},{name="TargetPos",t=3}}
t.hand = FightModel.UsePetSkill
t.pb = FightRpc_pb.FightRpcUsePetSkillAsk()
table.insert(askList.Fight,t)

local t = {}
t.name = "MonsterInteract"
t.para = {{name="TargetId",t=1}}
t.hand = FightModel.MonsterInteract
t.pb = FightRpc_pb.FightRpcMonsterInteractAsk()
table.insert(askList.Fight,t)

--]]

