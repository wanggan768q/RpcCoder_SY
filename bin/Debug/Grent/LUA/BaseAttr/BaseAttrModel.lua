--将变量写入下方
local ModuleId = 7;
local RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 751
local RPC_CODE_BASEATTR_SYNC_NOTIFY = 752;


require("3rd/pblua/BaseAttrV1Data_pb")
local BaseAttrV1Data_pb = BaseAttrV1Data_pb

local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/BaseAttrRpc_pb")
local  BaseAttrRpc_pb = BaseAttrRpc_pb
module("BaseAttrModel")


BASEATTR_EXP = 701
BASEATTR_LEVEL = 703
BASEATTR_SERVERTIME = 704
BASEATTR_ROLEID = 705
BASEATTR_STRENGTH = 707
BASEATTR_AGILITY = 708
BASEATTR_INTELLECTUAL = 709
BASEATTR_ENDURANCE = 710
BASEATTR_SPIRIT = 711
BASEATTR_HP = 712
BASEATTR_MAXHP = 714
BASEATTR_PHYSICATTACK = 715
BASEATTR_PHYSICDEFENSE = 716
BASEATTR_MAGICATTACK = 719
BASEATTR_MAGICDEFENSE = 720
BASEATTR_HIT = 721
BASEATTR_HITRATE = 722
BASEATTR_MISS = 723
BASEATTR_MISSRATE = 724
BASEATTR_CRITICAL = 725
BASEATTR_CRITICALRATE = 726
BASEATTR_TENACITY = 727
BASEATTR_TENACITYRATE = 728
BASEATTR_PENET = 729
BASEATTR_PENETRATE = 730
BASEATTR_DODG = 731
BASEATTR_DODGRATE = 732
BASEATTR_CRITICALADDITION = 733
BASEATTR_CRITICALADDITIONRATE = 734
BASEATTR_CRITICALIMMUNE = 735
BASEATTR_CRITICALIMMUNERATE = 736
BASEATTR_MISSLEVEL = 737
BASEATTR_CRITICALLEVEL = 738
BASEATTR_DODGLEVEL = 739
BASEATTR_MOVESPEED = 740
BASEATTR_DIZZYSTATE = 741
BASEATTR_GODSTATE = 742
BASEATTR_CANTMOVESTATE = 743
BASEATTR_PHYSICADDITION = 745
BASEATTR_MAGICADDITION = 746
BASEATTR_PHYSICOPPOSE = 747
BASEATTR_MAGICOPPOSE = 748



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
	self.rpc_pb = BaseAttrRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_BASEATTR_SYNC_NOTIFY,handler(self,self.SyncCB))

  
	self.data_pb=BaseAttrV1Data_pb
	self.m_Exp = 0
	self.m_Level = 0
	self.m_ServerTime = 0
	self.m_RoleId = 0
	self.m_Strength = 0
	self.m_Agility = 0
	self.m_Intellectual = 0
	self.m_Endurance = 0
	self.m_Spirit = 0
	self.m_Hp = 0
	self.m_MaxHp = 0
	self.m_PhysicAttack = 0
	self.m_PhysicDefense = 0
	self.m_MagicAttack = 0
	self.m_MagicDefense = 0
	self.m_Hit = 0
	self.m_HitRate = 0
	self.m_Miss = 0
	self.m_MissRate = 0
	self.m_Critical = 0
	self.m_CriticalRate = 0
	self.m_Tenacity = 0
	self.m_TenacityRate = 0
	self.m_Penet = 0
	self.m_PenetRate = 0
	self.m_Dodg = 0
	self.m_DodgRate = 0
	self.m_CriticalAddition = 0
	self.m_CriticalAdditionRate = 0
	self.m_CriticalImmune = 0
	self.m_CriticalImmuneRate = 0
	self.m_MissLevel = 0
	self.m_CriticalLevel = 0
	self.m_DodgLevel = 0
	self.m_MoveSpeed = 0
	self.m_DizzyState = false
	self.m_GodState = false
	self.m_CantMoveState = false
	self.m_PhysicAddition = 0
	self.m_MagicAddition = 0
	self.m_PhysicOppose = 0
	self.m_MagicOppose = 0


end

-- 更新数据
function UpdateField(self,uf)
	local ret_msg = self.data_pb.BaseAttrUserDataV1()
	ret_msg:ParseFromString(uf)
	if ret_msg:HasField('Exp') then
		self.m_Exp = ret_msg.Exp
		dataCallback(self,BASEATTR_EXP)
	end
	if ret_msg:HasField('Level') then
		self.m_Level = ret_msg.Level
		dataCallback(self,BASEATTR_LEVEL)
	end
	if ret_msg:HasField('ServerTime') then
		self.m_ServerTime = num
		self.m_ServerTime = ret_msg.ServerTime
		dataCallback(self,BASEATTR_SERVERTIME)
	end
	if ret_msg:HasField('RoleId') then
		self.m_RoleId = num
		self.m_RoleId = ret_msg.RoleId
		dataCallback(self,BASEATTR_ROLEID)
	end
	if ret_msg:HasField('Strength') then
		self.m_Strength = ret_msg.Strength
		dataCallback(self,BASEATTR_STRENGTH)
	end
	if ret_msg:HasField('Agility') then
		self.m_Agility = ret_msg.Agility
		dataCallback(self,BASEATTR_AGILITY)
	end
	if ret_msg:HasField('Intellectual') then
		self.m_Intellectual = ret_msg.Intellectual
		dataCallback(self,BASEATTR_INTELLECTUAL)
	end
	if ret_msg:HasField('Endurance') then
		self.m_Endurance = ret_msg.Endurance
		dataCallback(self,BASEATTR_ENDURANCE)
	end
	if ret_msg:HasField('Spirit') then
		self.m_Spirit = ret_msg.Spirit
		dataCallback(self,BASEATTR_SPIRIT)
	end
	if ret_msg:HasField('Hp') then
		self.m_Hp = ret_msg.Hp
		dataCallback(self,BASEATTR_HP)
	end
	if ret_msg:HasField('MaxHp') then
		self.m_MaxHp = ret_msg.MaxHp
		dataCallback(self,BASEATTR_MAXHP)
	end
	if ret_msg:HasField('PhysicAttack') then
		self.m_PhysicAttack = ret_msg.PhysicAttack
		dataCallback(self,BASEATTR_PHYSICATTACK)
	end
	if ret_msg:HasField('PhysicDefense') then
		self.m_PhysicDefense = ret_msg.PhysicDefense
		dataCallback(self,BASEATTR_PHYSICDEFENSE)
	end
	if ret_msg:HasField('MagicAttack') then
		self.m_MagicAttack = ret_msg.MagicAttack
		dataCallback(self,BASEATTR_MAGICATTACK)
	end
	if ret_msg:HasField('MagicDefense') then
		self.m_MagicDefense = ret_msg.MagicDefense
		dataCallback(self,BASEATTR_MAGICDEFENSE)
	end
	if ret_msg:HasField('Hit') then
		self.m_Hit = ret_msg.Hit
		dataCallback(self,BASEATTR_HIT)
	end
	if ret_msg:HasField('HitRate') then
		self.m_HitRate = ret_msg.HitRate
		dataCallback(self,BASEATTR_HITRATE)
	end
	if ret_msg:HasField('Miss') then
		self.m_Miss = ret_msg.Miss
		dataCallback(self,BASEATTR_MISS)
	end
	if ret_msg:HasField('MissRate') then
		self.m_MissRate = ret_msg.MissRate
		dataCallback(self,BASEATTR_MISSRATE)
	end
	if ret_msg:HasField('Critical') then
		self.m_Critical = ret_msg.Critical
		dataCallback(self,BASEATTR_CRITICAL)
	end
	if ret_msg:HasField('CriticalRate') then
		self.m_CriticalRate = ret_msg.CriticalRate
		dataCallback(self,BASEATTR_CRITICALRATE)
	end
	if ret_msg:HasField('Tenacity') then
		self.m_Tenacity = ret_msg.Tenacity
		dataCallback(self,BASEATTR_TENACITY)
	end
	if ret_msg:HasField('TenacityRate') then
		self.m_TenacityRate = ret_msg.TenacityRate
		dataCallback(self,BASEATTR_TENACITYRATE)
	end
	if ret_msg:HasField('Penet') then
		self.m_Penet = ret_msg.Penet
		dataCallback(self,BASEATTR_PENET)
	end
	if ret_msg:HasField('PenetRate') then
		self.m_PenetRate = ret_msg.PenetRate
		dataCallback(self,BASEATTR_PENETRATE)
	end
	if ret_msg:HasField('Dodg') then
		self.m_Dodg = ret_msg.Dodg
		dataCallback(self,BASEATTR_DODG)
	end
	if ret_msg:HasField('DodgRate') then
		self.m_DodgRate = ret_msg.DodgRate
		dataCallback(self,BASEATTR_DODGRATE)
	end
	if ret_msg:HasField('CriticalAddition') then
		self.m_CriticalAddition = ret_msg.CriticalAddition
		dataCallback(self,BASEATTR_CRITICALADDITION)
	end
	if ret_msg:HasField('CriticalAdditionRate') then
		self.m_CriticalAdditionRate = ret_msg.CriticalAdditionRate
		dataCallback(self,BASEATTR_CRITICALADDITIONRATE)
	end
	if ret_msg:HasField('CriticalImmune') then
		self.m_CriticalImmune = ret_msg.CriticalImmune
		dataCallback(self,BASEATTR_CRITICALIMMUNE)
	end
	if ret_msg:HasField('CriticalImmuneRate') then
		self.m_CriticalImmuneRate = ret_msg.CriticalImmuneRate
		dataCallback(self,BASEATTR_CRITICALIMMUNERATE)
	end
	if ret_msg:HasField('MissLevel') then
		self.m_MissLevel = ret_msg.MissLevel
		dataCallback(self,BASEATTR_MISSLEVEL)
	end
	if ret_msg:HasField('CriticalLevel') then
		self.m_CriticalLevel = ret_msg.CriticalLevel
		dataCallback(self,BASEATTR_CRITICALLEVEL)
	end
	if ret_msg:HasField('DodgLevel') then
		self.m_DodgLevel = ret_msg.DodgLevel
		dataCallback(self,BASEATTR_DODGLEVEL)
	end
	if ret_msg:HasField('MoveSpeed') then
		self.m_MoveSpeed = ret_msg.MoveSpeed
		dataCallback(self,BASEATTR_MOVESPEED)
	end
	if ret_msg:HasField('DizzyState') then
		self.m_DizzyState = ret_msg.DizzyState
		dataCallback(self,BASEATTR_DIZZYSTATE)
	end
	if ret_msg:HasField('GodState') then
		self.m_GodState = ret_msg.GodState
		dataCallback(self,BASEATTR_GODSTATE)
	end
	if ret_msg:HasField('CantMoveState') then
		self.m_CantMoveState = ret_msg.CantMoveState
		dataCallback(self,BASEATTR_CANTMOVESTATE)
	end
	if ret_msg:HasField('PhysicAddition') then
		self.m_PhysicAddition = ret_msg.PhysicAddition
		dataCallback(self,BASEATTR_PHYSICADDITION)
	end
	if ret_msg:HasField('MagicAddition') then
		self.m_MagicAddition = ret_msg.MagicAddition
		dataCallback(self,BASEATTR_MAGICADDITION)
	end
	if ret_msg:HasField('PhysicOppose') then
		self.m_PhysicOppose = ret_msg.PhysicOppose
		dataCallback(self,BASEATTR_PHYSICOPPOSE)
	end
	if ret_msg:HasField('MagicOppose') then
		self.m_MagicOppose = ret_msg.MagicOppose
		dataCallback(self,BASEATTR_MAGICOPPOSE)
	end

end


-- 业务事件
function SyncData(self,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_SYNCDATA_REQUEST, pb_data, callback)
end



-- 给c层 注册服务器通知回调
function registerSyncCBNotify(self,_hanlder)
	if not self.SyncCBNotifyCallBack then
		self.SyncCBNotifyCallBack = {}
	end
	table.insert(self.SyncCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SyncCB(self,notifyMsg)
	if self.SyncCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BaseAttrRpcSyncNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSyncCBNotify(self,_hanlder)
	if nil ~= self.SyncCBNotifyCallBack then
		for i,callback in ipairs(self.SyncCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncCBNotifyCallBack, i )
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
		if  Id == BASEATTR_EXP then
		return self.m_Exp
	elseif  Id == BASEATTR_LEVEL then
		return self.m_Level
	elseif  Id == BASEATTR_SERVERTIME then
		return self.m_ServerTime
	elseif  Id == BASEATTR_ROLEID then
		return self.m_RoleId
	elseif  Id == BASEATTR_STRENGTH then
		return self.m_Strength
	elseif  Id == BASEATTR_AGILITY then
		return self.m_Agility
	elseif  Id == BASEATTR_INTELLECTUAL then
		return self.m_Intellectual
	elseif  Id == BASEATTR_ENDURANCE then
		return self.m_Endurance
	elseif  Id == BASEATTR_SPIRIT then
		return self.m_Spirit
	elseif  Id == BASEATTR_HP then
		return self.m_Hp
	elseif  Id == BASEATTR_MAXHP then
		return self.m_MaxHp
	elseif  Id == BASEATTR_PHYSICATTACK then
		return self.m_PhysicAttack
	elseif  Id == BASEATTR_PHYSICDEFENSE then
		return self.m_PhysicDefense
	elseif  Id == BASEATTR_MAGICATTACK then
		return self.m_MagicAttack
	elseif  Id == BASEATTR_MAGICDEFENSE then
		return self.m_MagicDefense
	elseif  Id == BASEATTR_HIT then
		return self.m_Hit
	elseif  Id == BASEATTR_HITRATE then
		return self.m_HitRate
	elseif  Id == BASEATTR_MISS then
		return self.m_Miss
	elseif  Id == BASEATTR_MISSRATE then
		return self.m_MissRate
	elseif  Id == BASEATTR_CRITICAL then
		return self.m_Critical
	elseif  Id == BASEATTR_CRITICALRATE then
		return self.m_CriticalRate
	elseif  Id == BASEATTR_TENACITY then
		return self.m_Tenacity
	elseif  Id == BASEATTR_TENACITYRATE then
		return self.m_TenacityRate
	elseif  Id == BASEATTR_PENET then
		return self.m_Penet
	elseif  Id == BASEATTR_PENETRATE then
		return self.m_PenetRate
	elseif  Id == BASEATTR_DODG then
		return self.m_Dodg
	elseif  Id == BASEATTR_DODGRATE then
		return self.m_DodgRate
	elseif  Id == BASEATTR_CRITICALADDITION then
		return self.m_CriticalAddition
	elseif  Id == BASEATTR_CRITICALADDITIONRATE then
		return self.m_CriticalAdditionRate
	elseif  Id == BASEATTR_CRITICALIMMUNE then
		return self.m_CriticalImmune
	elseif  Id == BASEATTR_CRITICALIMMUNERATE then
		return self.m_CriticalImmuneRate
	elseif  Id == BASEATTR_MISSLEVEL then
		return self.m_MissLevel
	elseif  Id == BASEATTR_CRITICALLEVEL then
		return self.m_CriticalLevel
	elseif  Id == BASEATTR_DODGLEVEL then
		return self.m_DodgLevel
	elseif  Id == BASEATTR_MOVESPEED then
		return self.m_MoveSpeed
	elseif  Id == BASEATTR_DIZZYSTATE then
		return self.m_DizzyState
	elseif  Id == BASEATTR_GODSTATE then
		return self.m_GodState
	elseif  Id == BASEATTR_CANTMOVESTATE then
		return self.m_CantMoveState
	elseif  Id == BASEATTR_PHYSICADDITION then
		return self.m_PhysicAddition
	elseif  Id == BASEATTR_MAGICADDITION then
		return self.m_MagicAddition
	elseif  Id == BASEATTR_PHYSICOPPOSE then
		return self.m_PhysicOppose
	elseif  Id == BASEATTR_MAGICOPPOSE then
		return self.m_MagicOppose
	else
		 print("error Get")
	end

end

--[[
askList.BaseAttr = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = BaseAttrModel.SyncData
t.pb = BaseAttrRpc_pb.BaseAttrRpcSyncDataAsk()
table.insert(askList.BaseAttr,t)

--]]

