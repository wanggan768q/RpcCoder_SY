-- BaseAttrModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

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
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
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
BASEATTR_ACCUMULATESKIENERGY = 750
BASEATTR_NICKNAME = 751
BASEATTR_CONFIGID = 752
BASEATTR_OBJTYPE = 753
BASEATTR_STATE = 754
BASEATTR_OWNEROBJID = 755
BASEATTR_CAMP = 756
BASEATTR_SILVERMONEY = 757
BASEATTR_GOLDMONEY = 758
BASEATTR_DIAMONDMONEY = 759
BASEATTR_BINDINGDIAMONDMONEY = 760
BASEATTR_BATTLESCORE = 761
BASEATTR_ENERGY = 762
BASEATTR_GUILDMONEY = 763
BASEATTR_SKILLLIST = 764
BASEATTR_HONORMONEY = 765
BASEATTR_RESOURCEPOOLHP = 766
BASEATTR_ATTACKADD = 767
BASEATTR_INJURYADD = 768
BASEATTR_FROZENSTATE = 769
BASEATTR_SILENTSTATE = 770
BASEATTR_GUILDCONTRIBUTEHISTORYMAX = 772
BASEATTR_TEAMID = 774
BASEATTR_TREASUREHAIR = 775
BASEATTR_TREASUREHEAD = 776
BASEATTR_TREASUREBODY = 777
BASEATTR_TREASUREWEAPON = 778
BASEATTR_TREASUREWING = 779
BASEATTR_GUILDGUID = 780
BASEATTR_TREASURERIDING = 781
BASEATTR_VECHICLEID = 782
BASEATTR_ANIMATIONSTATE = 783
BASEATTR_REFIXDMGRATE = 784
BASEATTR_REFIXDMGVALUE = 785
BASEATTR_REFIXHURTRATE = 786
BASEATTR_REFIXHURTVALUE = 787
BASEATTR_REFIXHEALRATE = 788
BASEATTR_REFIXHEALVALUE = 789
BASEATTR_REFIXCUREDRATE = 790
BASEATTR_REFIXCUREDVALUE = 791
BASEATTR_GUILDCONTRIBUTE = 792
BASEATTR_PVPMONEY = 793
BASEATTR_GUILDRESOURCE = 794
BASEATTR_CREATEROLETIME = 795
BASEATTR_UPDATEROLETIME = 796
BASEATTR_FIGHTSTATE = 797
BASEATTR_ATTACKSKILLLIST = 798
BASEATTR_GUILDNAME = 799
BASEATTR_ISALLOWSELECT = 800
BASEATTR_GOHOMESTATE = 801
BASEATTR_CANFIGHT = 802
BASEATTR_DOUBLEEXP = 803
BASEATTR_FRIENDPOINT = 804
BASEATTR_HISMAXHONOR = 805
BASEATTR_HURTSTATE = 806
BASEATTR_HURTFLYSTATE = 807
BASEATTR_HURTDOWNSTATE = 808
BASEATTR_HURTREPELSTATE = 809
BASEATTR_TODAYHORNOR = 811
BASEATTR_CURPROFESSION = 813
BASEATTR_PETCREATEDELCOND = 814
BASEATTR_PETDISPLAY = 815
BASEATTR_PETMONEY = 816
BASEATTR_DUELSTATUS = 817
BASEATTR_EXPPOOL = 818
BASEATTR_RUSHSTATE = 819
BASEATTR_STARESTATE = 820
BASEATTR_WORLDLEVEL = 821
BASEATTR_DIZZYHITRATE = 822
BASEATTR_DIZZYRESISTRATE = 823
BASEATTR_IMMOVABLEHITRATE = 824
BASEATTR_IMMOVABLERESISTRATE = 825
BASEATTR_HURTFLYHITRATE = 826
BASEATTR_HURTFLYRESISTRATE = 827
BASEATTR_FROZENHITRATE = 828
BASEATTR_FROZENRESISTRATE = 829
BASEATTR_CLEANHITRATE = 830
BASEATTR_CLEANRESISTRATE = 831
BASEATTR_DISPELHITRATE = 832
BASEATTR_DISPELRESISTRATE = 833
BASEATTR_SILENCEHITRATE = 834
BASEATTR_SILENCERESISTRATE = 835
BASEATTR_INTERRUPTHITRATE = 836
BASEATTR_INTERRUPTRESISTRATE = 837
BASEATTR_UNCURABLEHITRATE = 838
BASEATTR_UNCURABLERESISTRATE = 839
BASEATTR_TRANSFORM = 840
BASEATTR_HUMANHURTRATE = 841
BASEATTR_HUMANSUFFERRATE = 842
BASEATTR_MONSTERHURTRATE = 843
BASEATTR_MONSTERSUFFERRATE = 844
BASEATTR_BOSSHURTRATE = 845
BASEATTR_BOSSSUFFERRATE = 846
BASEATTR_DODGREDUCEVALUE = 847
BASEATTR_DODGREDUCERATE = 848
BASEATTR_DODGADDVALUE = 849
BASEATTR_DODGADDRATE = 850
BASEATTR_TREASUREFOOTPRINT = 851
BASEATTR_EQUIPTITLE = 852
BASEATTR_OBJANIMEVENT = 853
BASEATTR_PINCHDATA = 854
BASEATTR_SKILLCDRATE = 855
BASEATTR_ASPDRATE = 856
BASEATTR_SHIELD = 857
BASEATTR_EVENTLEFTCOUNT = 858
BASEATTR_CANNOTRUSH = 859
BASEATTR_HUNTPOINT = 860
BASEATTR_HUNTHIGHTIMES = 861
BASEATTR_HUNTFIREPOINT = 862
BASEATTR_STARBATTLESTATE = 863
BASEATTR_IGNOREMOTIONBLOCK = 864
BASEATTR_ENABLEINTERACT = 865
BASEATTR_WORLDMEDAL = 866
BASEATTR_CURECEILING = 868
BASEATTR_RELATIONUNIONCURRENCY = 869
BASEATTR_GUILDSHORTNAME = 870
BASEATTR_GUILDSHORTCOLORID = 871



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
	self.m_DizzyState = 0
	self.m_GodState = false
	self.m_CantMoveState = 0
	self.m_PhysicAddition = 0
	self.m_MagicAddition = 0
	self.m_PhysicOppose = 0
	self.m_MagicOppose = 0
	self.m_AccumulateSkiEnergy = 0
	self.m_NickName = ""
	self.m_ConfigId = 0
	self.m_ObjType = 0
	self.m_State = 0
	self.m_OwnerObjId = 0
	self.m_Camp = 0
	self.m_SilverMoney = 0
	self.m_GoldMoney = 0
	self.m_DiamondMoney = 0
	self.m_BindingDiamondMoney = 0
	self.m_BattleScore = 0
	self.m_Energy = 0
	self.m_GuildMoney = 0
	self.m_SkillList = {}
	self.m_HonorMoney = 0
	self.m_ResourcePoolHp = 0
	self.m_AttackAdd = 0
	self.m_InjuryAdd = 0
	self.m_FrozenState = 0
	self.m_SilentState = 0
	self.m_GuildContributeHistoryMax = 0
	self.m_TeamId = 0
	self.m_TreasureHair = 0
	self.m_TreasureHead = 0
	self.m_TreasureBody = 0
	self.m_TreasureWeapon = 0
	self.m_TreasureWing = 0
	self.m_GuildGuid = 0
	self.m_TreasureRiding = 0
	self.m_VechicleId = 0
	self.m_AnimationState = false
	self.m_RefixDmgRate = 0
	self.m_RefixDmgValue = 0
	self.m_RefixHurtRate = 0
	self.m_RefixHurtValue = 0
	self.m_RefixHealRate = 0
	self.m_RefixHealValue = 0
	self.m_RefixCuredRate = 0
	self.m_RefixCuredValue = 0
	self.m_GuildContribute = 0
	self.m_PvpMoney = 0
	self.m_GuildResource = 0
	self.m_CreateRoleTime = 0
	self.m_UpdateRoleTime = 0
	self.m_FightState = false
	self.m_AttackSkillList = {}
	self.m_GuildName = ""
	self.m_IsAllowSelect = false
	self.m_GoHomeState = false
	self.m_CanFight = false
	self.m_DoubleExp = 0
	self.m_FriendPoint = 0
	self.m_HisMaxHonor = 0
	self.m_HurtState = false
	self.m_HurtFlyState = false
	self.m_HurtDownState = false
	self.m_HurtRepelState = false
	self.m_TodayHornor = 0
	self.m_CurProfession = 0
	self.m_PetCreateDelCond = 0
	self.m_PetDisplay = 0
	self.m_PetMoney = 0
	self.m_DuelStatus = 0
	self.m_ExpPool = 0
	self.m_RushState = false
	self.m_StareState = 0
	self.m_WorldLevel = 0
	self.m_DizzyHitRate = 0
	self.m_DizzyResistRate = 0
	self.m_ImmovableHitRate = 0
	self.m_ImmovableResistRate = 0
	self.m_HurtFlyHitRate = 0
	self.m_HurtFlyResistRate = 0
	self.m_FrozenHitRate = 0
	self.m_FrozenResistRate = 0
	self.m_CleanHitRate = 0
	self.m_CleanResistRate = 0
	self.m_DispelHitRate = 0
	self.m_DispelResistRate = 0
	self.m_SilenceHitRate = 0
	self.m_SilenceResistRate = 0
	self.m_InterruptHitRate = 0
	self.m_InterruptResistRate = 0
	self.m_UncurableHitRate = 0
	self.m_UncurableResistRate = 0
	self.m_Transform = 0
	self.m_HumanHurtRate = 0
	self.m_HumanSufferRate = 0
	self.m_MonsterHurtRate = 0
	self.m_MonsterSufferRate = 0
	self.m_BossHurtRate = 0
	self.m_BossSufferRate = 0
	self.m_DodgReduceValue = 0
	self.m_DodgReduceRate = 0
	self.m_DodgAddValue = 0
	self.m_DodgAddRate = 0
	self.m_TreasureFootPrint = 0
	self.m_EquipTitle = 0
	self.m_ObjAnimEvent = {}
	self.m_PinchData = ""
	self.m_SkillCDRate = 0
	self.m_AspdRate = 0
	self.m_Shield = 0
	self.m_EventLeftCount = 0
	self.m_CanNotRush = 0
	self.m_HuntPoint = 0
	self.m_HuntHighTimes = 0
	self.m_HuntFirePoint = 0
	self.m_Starbattlestate = 0
	self.m_IgnoreMotionBlock = false
	self.m_EnableInteract = false
	self.m_WorldMedal = 0
	self.m_CureCeiling = 0
	self.m_RelationUnionCurrency = 0
	self.m_GuildShortName = ""
	self.m_GuildShortColorID = 0


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)
	local ret_msg = self.data_pb.BaseAttrUserDataV1()
	ret_msg:ParseFromString(uf)
	if ret_msg:HasField('Exp') then
		oldData.Exp = ret_msg.Exp
		if isForceUpdate == true then
			self.m_Exp = ret_msg.Exp
		end
		if isNotify == true then
			self.m_Exp = ret_msg.Exp
			dataCallback(self,BASEATTR_EXP,ret_msg.Exp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_EXP,ret_msg.Exp)
		end
	end
	if ret_msg:HasField('Level') then
		oldData.Level = ret_msg.Level
		if isForceUpdate == true then
			self.m_Level = ret_msg.Level
		end
		if isNotify == true then
			self.m_Level = ret_msg.Level
			dataCallback(self,BASEATTR_LEVEL,ret_msg.Level)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_LEVEL,ret_msg.Level)
		end
	end
	if ret_msg:HasField('ServerTime') then
		oldData.ServerTime = ret_msg.ServerTime
		if isForceUpdate == true then
			self.m_ServerTime = ret_msg.ServerTime
		end
		if isNotify == true then
			self.m_ServerTime = ret_msg.ServerTime
			dataCallback(self,BASEATTR_SERVERTIME,ret_msg.ServerTime)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SERVERTIME,ret_msg.ServerTime)
		end
	end
	if ret_msg:HasField('RoleId') then
		oldData.RoleId = ret_msg.RoleId
		if isForceUpdate == true then
			self.m_RoleId = ret_msg.RoleId
		end
		if isNotify == true then
			self.m_RoleId = ret_msg.RoleId
			dataCallback(self,BASEATTR_ROLEID,ret_msg.RoleId)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ROLEID,ret_msg.RoleId)
		end
	end
	if ret_msg:HasField('Strength') then
		oldData.Strength = ret_msg.Strength
		if isForceUpdate == true then
			self.m_Strength = ret_msg.Strength
		end
		if isNotify == true then
			self.m_Strength = ret_msg.Strength
			dataCallback(self,BASEATTR_STRENGTH,ret_msg.Strength)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_STRENGTH,ret_msg.Strength)
		end
	end
	if ret_msg:HasField('Agility') then
		oldData.Agility = ret_msg.Agility
		if isForceUpdate == true then
			self.m_Agility = ret_msg.Agility
		end
		if isNotify == true then
			self.m_Agility = ret_msg.Agility
			dataCallback(self,BASEATTR_AGILITY,ret_msg.Agility)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_AGILITY,ret_msg.Agility)
		end
	end
	if ret_msg:HasField('Intellectual') then
		oldData.Intellectual = ret_msg.Intellectual
		if isForceUpdate == true then
			self.m_Intellectual = ret_msg.Intellectual
		end
		if isNotify == true then
			self.m_Intellectual = ret_msg.Intellectual
			dataCallback(self,BASEATTR_INTELLECTUAL,ret_msg.Intellectual)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_INTELLECTUAL,ret_msg.Intellectual)
		end
	end
	if ret_msg:HasField('Endurance') then
		oldData.Endurance = ret_msg.Endurance
		if isForceUpdate == true then
			self.m_Endurance = ret_msg.Endurance
		end
		if isNotify == true then
			self.m_Endurance = ret_msg.Endurance
			dataCallback(self,BASEATTR_ENDURANCE,ret_msg.Endurance)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ENDURANCE,ret_msg.Endurance)
		end
	end
	if ret_msg:HasField('Hp') then
		oldData.Hp = ret_msg.Hp
		if isForceUpdate == true then
			self.m_Hp = ret_msg.Hp
		end
		if isNotify == true then
			self.m_Hp = ret_msg.Hp
			dataCallback(self,BASEATTR_HP,ret_msg.Hp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HP,ret_msg.Hp)
		end
	end
	if ret_msg:HasField('MaxHp') then
		oldData.MaxHp = ret_msg.MaxHp
		if isForceUpdate == true then
			self.m_MaxHp = ret_msg.MaxHp
		end
		if isNotify == true then
			self.m_MaxHp = ret_msg.MaxHp
			dataCallback(self,BASEATTR_MAXHP,ret_msg.MaxHp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MAXHP,ret_msg.MaxHp)
		end
	end
	if ret_msg:HasField('PhysicAttack') then
		oldData.PhysicAttack = ret_msg.PhysicAttack
		if isForceUpdate == true then
			self.m_PhysicAttack = ret_msg.PhysicAttack
		end
		if isNotify == true then
			self.m_PhysicAttack = ret_msg.PhysicAttack
			dataCallback(self,BASEATTR_PHYSICATTACK,ret_msg.PhysicAttack)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PHYSICATTACK,ret_msg.PhysicAttack)
		end
	end
	if ret_msg:HasField('PhysicDefense') then
		oldData.PhysicDefense = ret_msg.PhysicDefense
		if isForceUpdate == true then
			self.m_PhysicDefense = ret_msg.PhysicDefense
		end
		if isNotify == true then
			self.m_PhysicDefense = ret_msg.PhysicDefense
			dataCallback(self,BASEATTR_PHYSICDEFENSE,ret_msg.PhysicDefense)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PHYSICDEFENSE,ret_msg.PhysicDefense)
		end
	end
	if ret_msg:HasField('MagicAttack') then
		oldData.MagicAttack = ret_msg.MagicAttack
		if isForceUpdate == true then
			self.m_MagicAttack = ret_msg.MagicAttack
		end
		if isNotify == true then
			self.m_MagicAttack = ret_msg.MagicAttack
			dataCallback(self,BASEATTR_MAGICATTACK,ret_msg.MagicAttack)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MAGICATTACK,ret_msg.MagicAttack)
		end
	end
	if ret_msg:HasField('MagicDefense') then
		oldData.MagicDefense = ret_msg.MagicDefense
		if isForceUpdate == true then
			self.m_MagicDefense = ret_msg.MagicDefense
		end
		if isNotify == true then
			self.m_MagicDefense = ret_msg.MagicDefense
			dataCallback(self,BASEATTR_MAGICDEFENSE,ret_msg.MagicDefense)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MAGICDEFENSE,ret_msg.MagicDefense)
		end
	end
	if ret_msg:HasField('Hit') then
		oldData.Hit = ret_msg.Hit
		if isForceUpdate == true then
			self.m_Hit = ret_msg.Hit
		end
		if isNotify == true then
			self.m_Hit = ret_msg.Hit
			dataCallback(self,BASEATTR_HIT,ret_msg.Hit)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HIT,ret_msg.Hit)
		end
	end
	if ret_msg:HasField('HitRate') then
		oldData.HitRate = ret_msg.HitRate
		if isForceUpdate == true then
			self.m_HitRate = ret_msg.HitRate
		end
		if isNotify == true then
			self.m_HitRate = ret_msg.HitRate
			dataCallback(self,BASEATTR_HITRATE,ret_msg.HitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HITRATE,ret_msg.HitRate)
		end
	end
	if ret_msg:HasField('Miss') then
		oldData.Miss = ret_msg.Miss
		if isForceUpdate == true then
			self.m_Miss = ret_msg.Miss
		end
		if isNotify == true then
			self.m_Miss = ret_msg.Miss
			dataCallback(self,BASEATTR_MISS,ret_msg.Miss)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MISS,ret_msg.Miss)
		end
	end
	if ret_msg:HasField('MissRate') then
		oldData.MissRate = ret_msg.MissRate
		if isForceUpdate == true then
			self.m_MissRate = ret_msg.MissRate
		end
		if isNotify == true then
			self.m_MissRate = ret_msg.MissRate
			dataCallback(self,BASEATTR_MISSRATE,ret_msg.MissRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MISSRATE,ret_msg.MissRate)
		end
	end
	if ret_msg:HasField('Critical') then
		oldData.Critical = ret_msg.Critical
		if isForceUpdate == true then
			self.m_Critical = ret_msg.Critical
		end
		if isNotify == true then
			self.m_Critical = ret_msg.Critical
			dataCallback(self,BASEATTR_CRITICAL,ret_msg.Critical)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICAL,ret_msg.Critical)
		end
	end
	if ret_msg:HasField('CriticalRate') then
		oldData.CriticalRate = ret_msg.CriticalRate
		if isForceUpdate == true then
			self.m_CriticalRate = ret_msg.CriticalRate
		end
		if isNotify == true then
			self.m_CriticalRate = ret_msg.CriticalRate
			dataCallback(self,BASEATTR_CRITICALRATE,ret_msg.CriticalRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALRATE,ret_msg.CriticalRate)
		end
	end
	if ret_msg:HasField('Tenacity') then
		oldData.Tenacity = ret_msg.Tenacity
		if isForceUpdate == true then
			self.m_Tenacity = ret_msg.Tenacity
		end
		if isNotify == true then
			self.m_Tenacity = ret_msg.Tenacity
			dataCallback(self,BASEATTR_TENACITY,ret_msg.Tenacity)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TENACITY,ret_msg.Tenacity)
		end
	end
	if ret_msg:HasField('TenacityRate') then
		oldData.TenacityRate = ret_msg.TenacityRate
		if isForceUpdate == true then
			self.m_TenacityRate = ret_msg.TenacityRate
		end
		if isNotify == true then
			self.m_TenacityRate = ret_msg.TenacityRate
			dataCallback(self,BASEATTR_TENACITYRATE,ret_msg.TenacityRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TENACITYRATE,ret_msg.TenacityRate)
		end
	end
	if ret_msg:HasField('Penet') then
		oldData.Penet = ret_msg.Penet
		if isForceUpdate == true then
			self.m_Penet = ret_msg.Penet
		end
		if isNotify == true then
			self.m_Penet = ret_msg.Penet
			dataCallback(self,BASEATTR_PENET,ret_msg.Penet)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PENET,ret_msg.Penet)
		end
	end
	if ret_msg:HasField('PenetRate') then
		oldData.PenetRate = ret_msg.PenetRate
		if isForceUpdate == true then
			self.m_PenetRate = ret_msg.PenetRate
		end
		if isNotify == true then
			self.m_PenetRate = ret_msg.PenetRate
			dataCallback(self,BASEATTR_PENETRATE,ret_msg.PenetRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PENETRATE,ret_msg.PenetRate)
		end
	end
	if ret_msg:HasField('Dodg') then
		oldData.Dodg = ret_msg.Dodg
		if isForceUpdate == true then
			self.m_Dodg = ret_msg.Dodg
		end
		if isNotify == true then
			self.m_Dodg = ret_msg.Dodg
			dataCallback(self,BASEATTR_DODG,ret_msg.Dodg)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODG,ret_msg.Dodg)
		end
	end
	if ret_msg:HasField('DodgRate') then
		oldData.DodgRate = ret_msg.DodgRate
		if isForceUpdate == true then
			self.m_DodgRate = ret_msg.DodgRate
		end
		if isNotify == true then
			self.m_DodgRate = ret_msg.DodgRate
			dataCallback(self,BASEATTR_DODGRATE,ret_msg.DodgRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGRATE,ret_msg.DodgRate)
		end
	end
	if ret_msg:HasField('CriticalAddition') then
		oldData.CriticalAddition = ret_msg.CriticalAddition
		if isForceUpdate == true then
			self.m_CriticalAddition = ret_msg.CriticalAddition
		end
		if isNotify == true then
			self.m_CriticalAddition = ret_msg.CriticalAddition
			dataCallback(self,BASEATTR_CRITICALADDITION,ret_msg.CriticalAddition)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALADDITION,ret_msg.CriticalAddition)
		end
	end
	if ret_msg:HasField('CriticalAdditionRate') then
		oldData.CriticalAdditionRate = ret_msg.CriticalAdditionRate
		if isForceUpdate == true then
			self.m_CriticalAdditionRate = ret_msg.CriticalAdditionRate
		end
		if isNotify == true then
			self.m_CriticalAdditionRate = ret_msg.CriticalAdditionRate
			dataCallback(self,BASEATTR_CRITICALADDITIONRATE,ret_msg.CriticalAdditionRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALADDITIONRATE,ret_msg.CriticalAdditionRate)
		end
	end
	if ret_msg:HasField('CriticalImmune') then
		oldData.CriticalImmune = ret_msg.CriticalImmune
		if isForceUpdate == true then
			self.m_CriticalImmune = ret_msg.CriticalImmune
		end
		if isNotify == true then
			self.m_CriticalImmune = ret_msg.CriticalImmune
			dataCallback(self,BASEATTR_CRITICALIMMUNE,ret_msg.CriticalImmune)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALIMMUNE,ret_msg.CriticalImmune)
		end
	end
	if ret_msg:HasField('CriticalImmuneRate') then
		oldData.CriticalImmuneRate = ret_msg.CriticalImmuneRate
		if isForceUpdate == true then
			self.m_CriticalImmuneRate = ret_msg.CriticalImmuneRate
		end
		if isNotify == true then
			self.m_CriticalImmuneRate = ret_msg.CriticalImmuneRate
			dataCallback(self,BASEATTR_CRITICALIMMUNERATE,ret_msg.CriticalImmuneRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALIMMUNERATE,ret_msg.CriticalImmuneRate)
		end
	end
	if ret_msg:HasField('MissLevel') then
		oldData.MissLevel = ret_msg.MissLevel
		if isForceUpdate == true then
			self.m_MissLevel = ret_msg.MissLevel
		end
		if isNotify == true then
			self.m_MissLevel = ret_msg.MissLevel
			dataCallback(self,BASEATTR_MISSLEVEL,ret_msg.MissLevel)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MISSLEVEL,ret_msg.MissLevel)
		end
	end
	if ret_msg:HasField('CriticalLevel') then
		oldData.CriticalLevel = ret_msg.CriticalLevel
		if isForceUpdate == true then
			self.m_CriticalLevel = ret_msg.CriticalLevel
		end
		if isNotify == true then
			self.m_CriticalLevel = ret_msg.CriticalLevel
			dataCallback(self,BASEATTR_CRITICALLEVEL,ret_msg.CriticalLevel)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CRITICALLEVEL,ret_msg.CriticalLevel)
		end
	end
	if ret_msg:HasField('DodgLevel') then
		oldData.DodgLevel = ret_msg.DodgLevel
		if isForceUpdate == true then
			self.m_DodgLevel = ret_msg.DodgLevel
		end
		if isNotify == true then
			self.m_DodgLevel = ret_msg.DodgLevel
			dataCallback(self,BASEATTR_DODGLEVEL,ret_msg.DodgLevel)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGLEVEL,ret_msg.DodgLevel)
		end
	end
	if ret_msg:HasField('MoveSpeed') then
		oldData.MoveSpeed = ret_msg.MoveSpeed
		if isForceUpdate == true then
			self.m_MoveSpeed = ret_msg.MoveSpeed
		end
		if isNotify == true then
			self.m_MoveSpeed = ret_msg.MoveSpeed
			dataCallback(self,BASEATTR_MOVESPEED,ret_msg.MoveSpeed)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MOVESPEED,ret_msg.MoveSpeed)
		end
	end
	if ret_msg:HasField('DizzyState') then
		oldData.DizzyState = ret_msg.DizzyState
		if isForceUpdate == true then
			self.m_DizzyState = ret_msg.DizzyState
		end
		if isNotify == true then
			self.m_DizzyState = ret_msg.DizzyState
			dataCallback(self,BASEATTR_DIZZYSTATE,ret_msg.DizzyState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DIZZYSTATE,ret_msg.DizzyState)
		end
	end
	if ret_msg:HasField('GodState') then
		oldData.GodState = ret_msg.GodState
		if isForceUpdate == true then
			self.m_GodState = ret_msg.GodState
		end
		if isNotify == true then
			self.m_GodState = ret_msg.GodState
			dataCallback(self,BASEATTR_GODSTATE,ret_msg.GodState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GODSTATE,ret_msg.GodState)
		end
	end
	if ret_msg:HasField('CantMoveState') then
		oldData.CantMoveState = ret_msg.CantMoveState
		if isForceUpdate == true then
			self.m_CantMoveState = ret_msg.CantMoveState
		end
		if isNotify == true then
			self.m_CantMoveState = ret_msg.CantMoveState
			dataCallback(self,BASEATTR_CANTMOVESTATE,ret_msg.CantMoveState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CANTMOVESTATE,ret_msg.CantMoveState)
		end
	end
	if ret_msg:HasField('PhysicAddition') then
		oldData.PhysicAddition = ret_msg.PhysicAddition
		if isForceUpdate == true then
			self.m_PhysicAddition = ret_msg.PhysicAddition
		end
		if isNotify == true then
			self.m_PhysicAddition = ret_msg.PhysicAddition
			dataCallback(self,BASEATTR_PHYSICADDITION,ret_msg.PhysicAddition)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PHYSICADDITION,ret_msg.PhysicAddition)
		end
	end
	if ret_msg:HasField('MagicAddition') then
		oldData.MagicAddition = ret_msg.MagicAddition
		if isForceUpdate == true then
			self.m_MagicAddition = ret_msg.MagicAddition
		end
		if isNotify == true then
			self.m_MagicAddition = ret_msg.MagicAddition
			dataCallback(self,BASEATTR_MAGICADDITION,ret_msg.MagicAddition)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MAGICADDITION,ret_msg.MagicAddition)
		end
	end
	if ret_msg:HasField('PhysicOppose') then
		oldData.PhysicOppose = ret_msg.PhysicOppose
		if isForceUpdate == true then
			self.m_PhysicOppose = ret_msg.PhysicOppose
		end
		if isNotify == true then
			self.m_PhysicOppose = ret_msg.PhysicOppose
			dataCallback(self,BASEATTR_PHYSICOPPOSE,ret_msg.PhysicOppose)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PHYSICOPPOSE,ret_msg.PhysicOppose)
		end
	end
	if ret_msg:HasField('MagicOppose') then
		oldData.MagicOppose = ret_msg.MagicOppose
		if isForceUpdate == true then
			self.m_MagicOppose = ret_msg.MagicOppose
		end
		if isNotify == true then
			self.m_MagicOppose = ret_msg.MagicOppose
			dataCallback(self,BASEATTR_MAGICOPPOSE,ret_msg.MagicOppose)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MAGICOPPOSE,ret_msg.MagicOppose)
		end
	end
	if ret_msg:HasField('AccumulateSkiEnergy') then
		oldData.AccumulateSkiEnergy = ret_msg.AccumulateSkiEnergy
		if isForceUpdate == true then
			self.m_AccumulateSkiEnergy = ret_msg.AccumulateSkiEnergy
		end
		if isNotify == true then
			self.m_AccumulateSkiEnergy = ret_msg.AccumulateSkiEnergy
			dataCallback(self,BASEATTR_ACCUMULATESKIENERGY,ret_msg.AccumulateSkiEnergy)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ACCUMULATESKIENERGY,ret_msg.AccumulateSkiEnergy)
		end
	end
	if ret_msg:HasField('NickName') then
		oldData.NickName = ret_msg.NickName
		if isForceUpdate == true then
			self.m_NickName = ret_msg.NickName
		end
		if isNotify == true then
			dataCallback(self,BASEATTR_NICKNAME,ret_msg.NickName)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_NICKNAME,ret_msg.NickName)
		end
	end
	if ret_msg:HasField('ConfigId') then
		oldData.ConfigId = ret_msg.ConfigId
		if isForceUpdate == true then
			self.m_ConfigId = ret_msg.ConfigId
		end
		if isNotify == true then
			self.m_ConfigId = ret_msg.ConfigId
			dataCallback(self,BASEATTR_CONFIGID,ret_msg.ConfigId)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CONFIGID,ret_msg.ConfigId)
		end
	end
	if ret_msg:HasField('ObjType') then
		oldData.ObjType = ret_msg.ObjType
		if isForceUpdate == true then
			self.m_ObjType = ret_msg.ObjType
		end
		if isNotify == true then
			self.m_ObjType = ret_msg.ObjType
			dataCallback(self,BASEATTR_OBJTYPE,ret_msg.ObjType)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_OBJTYPE,ret_msg.ObjType)
		end
	end
	if ret_msg:HasField('State') then
		oldData.State = ret_msg.State
		if isForceUpdate == true then
			self.m_State = ret_msg.State
		end
		if isNotify == true then
			self.m_State = ret_msg.State
			dataCallback(self,BASEATTR_STATE,ret_msg.State)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_STATE,ret_msg.State)
		end
	end
	if ret_msg:HasField('OwnerObjId') then
		oldData.OwnerObjId = ret_msg.OwnerObjId
		if isForceUpdate == true then
			self.m_OwnerObjId = ret_msg.OwnerObjId
		end
		if isNotify == true then
			self.m_OwnerObjId = ret_msg.OwnerObjId
			dataCallback(self,BASEATTR_OWNEROBJID,ret_msg.OwnerObjId)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_OWNEROBJID,ret_msg.OwnerObjId)
		end
	end
	if ret_msg:HasField('Camp') then
		oldData.Camp = ret_msg.Camp
		if isForceUpdate == true then
			self.m_Camp = ret_msg.Camp
		end
		if isNotify == true then
			self.m_Camp = ret_msg.Camp
			dataCallback(self,BASEATTR_CAMP,ret_msg.Camp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CAMP,ret_msg.Camp)
		end
	end
	if ret_msg:HasField('SilverMoney') then
		oldData.SilverMoney = ret_msg.SilverMoney
		if isForceUpdate == true then
			self.m_SilverMoney = ret_msg.SilverMoney
		end
		if isNotify == true then
			self.m_SilverMoney = ret_msg.SilverMoney
			dataCallback(self,BASEATTR_SILVERMONEY,ret_msg.SilverMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SILVERMONEY,ret_msg.SilverMoney)
		end
	end
	if ret_msg:HasField('GoldMoney') then
		oldData.GoldMoney = ret_msg.GoldMoney
		if isForceUpdate == true then
			self.m_GoldMoney = ret_msg.GoldMoney
		end
		if isNotify == true then
			self.m_GoldMoney = ret_msg.GoldMoney
			dataCallback(self,BASEATTR_GOLDMONEY,ret_msg.GoldMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GOLDMONEY,ret_msg.GoldMoney)
		end
	end
	if ret_msg:HasField('DiamondMoney') then
		oldData.DiamondMoney = ret_msg.DiamondMoney
		if isForceUpdate == true then
			self.m_DiamondMoney = ret_msg.DiamondMoney
		end
		if isNotify == true then
			self.m_DiamondMoney = ret_msg.DiamondMoney
			dataCallback(self,BASEATTR_DIAMONDMONEY,ret_msg.DiamondMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DIAMONDMONEY,ret_msg.DiamondMoney)
		end
	end
	if ret_msg:HasField('BindingDiamondMoney') then
		oldData.BindingDiamondMoney = ret_msg.BindingDiamondMoney
		if isForceUpdate == true then
			self.m_BindingDiamondMoney = ret_msg.BindingDiamondMoney
		end
		if isNotify == true then
			self.m_BindingDiamondMoney = ret_msg.BindingDiamondMoney
			dataCallback(self,BASEATTR_BINDINGDIAMONDMONEY,ret_msg.BindingDiamondMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_BINDINGDIAMONDMONEY,ret_msg.BindingDiamondMoney)
		end
	end
	if ret_msg:HasField('BattleScore') then
		oldData.BattleScore = ret_msg.BattleScore
		if isForceUpdate == true then
			self.m_BattleScore = ret_msg.BattleScore
		end
		if isNotify == true then
			self.m_BattleScore = ret_msg.BattleScore
			dataCallback(self,BASEATTR_BATTLESCORE,ret_msg.BattleScore)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_BATTLESCORE,ret_msg.BattleScore)
		end
	end
	if ret_msg:HasField('Energy') then
		oldData.Energy = ret_msg.Energy
		if isForceUpdate == true then
			self.m_Energy = ret_msg.Energy
		end
		if isNotify == true then
			self.m_Energy = ret_msg.Energy
			dataCallback(self,BASEATTR_ENERGY,ret_msg.Energy)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ENERGY,ret_msg.Energy)
		end
	end
	if ret_msg:HasField('GuildMoney') then
		oldData.GuildMoney = ret_msg.GuildMoney
		if isForceUpdate == true then
			self.m_GuildMoney = ret_msg.GuildMoney
		end
		if isNotify == true then
			self.m_GuildMoney = ret_msg.GuildMoney
			dataCallback(self,BASEATTR_GUILDMONEY,ret_msg.GuildMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDMONEY,ret_msg.GuildMoney)
		end
	end
	if #ret_msg.SkillList > 0 and oldData.SkillList then
		m_SkillList = {}
		removeTableData(oldData.SkillList)
		for i = 1, #ret_msg.SkillList do
			table.insert( oldData.SkillList,ret_msg.SkillList[i])
		end
		if isForceUpdate == true then
			for i = 1, #ret_msg.SkillList do
				self.m_SkillList[i] = ret_msg.SkillList[i]
			end
		end
		if isNotify == true then
			for i = 1, #ret_msg.SkillList do
				self.m_SkillList[i] = ret_msg.SkillList[i]
			end
			dataCallback(self,BASEATTR_SKILLLIST,ret_msg.SkillList)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SKILLLIST,ret_msg.SkillList)
		end
	end
	if ret_msg:HasField('HonorMoney') then
		oldData.HonorMoney = ret_msg.HonorMoney
		if isForceUpdate == true then
			self.m_HonorMoney = ret_msg.HonorMoney
		end
		if isNotify == true then
			self.m_HonorMoney = ret_msg.HonorMoney
			dataCallback(self,BASEATTR_HONORMONEY,ret_msg.HonorMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HONORMONEY,ret_msg.HonorMoney)
		end
	end
	if ret_msg:HasField('ResourcePoolHp') then
		oldData.ResourcePoolHp = ret_msg.ResourcePoolHp
		if isForceUpdate == true then
			self.m_ResourcePoolHp = ret_msg.ResourcePoolHp
		end
		if isNotify == true then
			self.m_ResourcePoolHp = ret_msg.ResourcePoolHp
			dataCallback(self,BASEATTR_RESOURCEPOOLHP,ret_msg.ResourcePoolHp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_RESOURCEPOOLHP,ret_msg.ResourcePoolHp)
		end
	end
	if ret_msg:HasField('AttackAdd') then
		oldData.AttackAdd = ret_msg.AttackAdd
		if isForceUpdate == true then
			self.m_AttackAdd = ret_msg.AttackAdd
		end
		if isNotify == true then
			self.m_AttackAdd = ret_msg.AttackAdd
			dataCallback(self,BASEATTR_ATTACKADD,ret_msg.AttackAdd)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ATTACKADD,ret_msg.AttackAdd)
		end
	end
	if ret_msg:HasField('InjuryAdd') then
		oldData.InjuryAdd = ret_msg.InjuryAdd
		if isForceUpdate == true then
			self.m_InjuryAdd = ret_msg.InjuryAdd
		end
		if isNotify == true then
			self.m_InjuryAdd = ret_msg.InjuryAdd
			dataCallback(self,BASEATTR_INJURYADD,ret_msg.InjuryAdd)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_INJURYADD,ret_msg.InjuryAdd)
		end
	end
	if ret_msg:HasField('FrozenState') then
		oldData.FrozenState = ret_msg.FrozenState
		if isForceUpdate == true then
			self.m_FrozenState = ret_msg.FrozenState
		end
		if isNotify == true then
			self.m_FrozenState = ret_msg.FrozenState
			dataCallback(self,BASEATTR_FROZENSTATE,ret_msg.FrozenState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_FROZENSTATE,ret_msg.FrozenState)
		end
	end
	if ret_msg:HasField('SilentState') then
		oldData.SilentState = ret_msg.SilentState
		if isForceUpdate == true then
			self.m_SilentState = ret_msg.SilentState
		end
		if isNotify == true then
			self.m_SilentState = ret_msg.SilentState
			dataCallback(self,BASEATTR_SILENTSTATE,ret_msg.SilentState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SILENTSTATE,ret_msg.SilentState)
		end
	end
	if ret_msg:HasField('GuildContributeHistoryMax') then
		oldData.GuildContributeHistoryMax = ret_msg.GuildContributeHistoryMax
		if isForceUpdate == true then
			self.m_GuildContributeHistoryMax = ret_msg.GuildContributeHistoryMax
		end
		if isNotify == true then
			self.m_GuildContributeHistoryMax = ret_msg.GuildContributeHistoryMax
			dataCallback(self,BASEATTR_GUILDCONTRIBUTEHISTORYMAX,ret_msg.GuildContributeHistoryMax)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDCONTRIBUTEHISTORYMAX,ret_msg.GuildContributeHistoryMax)
		end
	end
	if ret_msg:HasField('TeamId') then
		oldData.TeamId = ret_msg.TeamId
		if isForceUpdate == true then
			self.m_TeamId = ret_msg.TeamId
		end
		if isNotify == true then
			self.m_TeamId = ret_msg.TeamId
			dataCallback(self,BASEATTR_TEAMID,ret_msg.TeamId)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TEAMID,ret_msg.TeamId)
		end
	end
	if ret_msg:HasField('TreasureHair') then
		oldData.TreasureHair = ret_msg.TreasureHair
		if isForceUpdate == true then
			self.m_TreasureHair = ret_msg.TreasureHair
		end
		if isNotify == true then
			self.m_TreasureHair = ret_msg.TreasureHair
			dataCallback(self,BASEATTR_TREASUREHAIR,ret_msg.TreasureHair)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREHAIR,ret_msg.TreasureHair)
		end
	end
	if ret_msg:HasField('TreasureHead') then
		oldData.TreasureHead = ret_msg.TreasureHead
		if isForceUpdate == true then
			self.m_TreasureHead = ret_msg.TreasureHead
		end
		if isNotify == true then
			self.m_TreasureHead = ret_msg.TreasureHead
			dataCallback(self,BASEATTR_TREASUREHEAD,ret_msg.TreasureHead)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREHEAD,ret_msg.TreasureHead)
		end
	end
	if ret_msg:HasField('TreasureBody') then
		oldData.TreasureBody = ret_msg.TreasureBody
		if isForceUpdate == true then
			self.m_TreasureBody = ret_msg.TreasureBody
		end
		if isNotify == true then
			self.m_TreasureBody = ret_msg.TreasureBody
			dataCallback(self,BASEATTR_TREASUREBODY,ret_msg.TreasureBody)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREBODY,ret_msg.TreasureBody)
		end
	end
	if ret_msg:HasField('TreasureWeapon') then
		oldData.TreasureWeapon = ret_msg.TreasureWeapon
		if isForceUpdate == true then
			self.m_TreasureWeapon = ret_msg.TreasureWeapon
		end
		if isNotify == true then
			self.m_TreasureWeapon = ret_msg.TreasureWeapon
			dataCallback(self,BASEATTR_TREASUREWEAPON,ret_msg.TreasureWeapon)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREWEAPON,ret_msg.TreasureWeapon)
		end
	end
	if ret_msg:HasField('TreasureWing') then
		oldData.TreasureWing = ret_msg.TreasureWing
		if isForceUpdate == true then
			self.m_TreasureWing = ret_msg.TreasureWing
		end
		if isNotify == true then
			self.m_TreasureWing = ret_msg.TreasureWing
			dataCallback(self,BASEATTR_TREASUREWING,ret_msg.TreasureWing)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREWING,ret_msg.TreasureWing)
		end
	end
	if ret_msg:HasField('GuildGuid') then
		oldData.GuildGuid = ret_msg.GuildGuid
		if isForceUpdate == true then
			self.m_GuildGuid = ret_msg.GuildGuid
		end
		if isNotify == true then
			self.m_GuildGuid = ret_msg.GuildGuid
			dataCallback(self,BASEATTR_GUILDGUID,ret_msg.GuildGuid)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDGUID,ret_msg.GuildGuid)
		end
	end
	if ret_msg:HasField('TreasureRiding') then
		oldData.TreasureRiding = ret_msg.TreasureRiding
		if isForceUpdate == true then
			self.m_TreasureRiding = ret_msg.TreasureRiding
		end
		if isNotify == true then
			self.m_TreasureRiding = ret_msg.TreasureRiding
			dataCallback(self,BASEATTR_TREASURERIDING,ret_msg.TreasureRiding)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASURERIDING,ret_msg.TreasureRiding)
		end
	end
	if ret_msg:HasField('VechicleId') then
		oldData.VechicleId = ret_msg.VechicleId
		if isForceUpdate == true then
			self.m_VechicleId = ret_msg.VechicleId
		end
		if isNotify == true then
			self.m_VechicleId = ret_msg.VechicleId
			dataCallback(self,BASEATTR_VECHICLEID,ret_msg.VechicleId)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_VECHICLEID,ret_msg.VechicleId)
		end
	end
	if ret_msg:HasField('AnimationState') then
		oldData.AnimationState = ret_msg.AnimationState
		if isForceUpdate == true then
			self.m_AnimationState = ret_msg.AnimationState
		end
		if isNotify == true then
			self.m_AnimationState = ret_msg.AnimationState
			dataCallback(self,BASEATTR_ANIMATIONSTATE,ret_msg.AnimationState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ANIMATIONSTATE,ret_msg.AnimationState)
		end
	end
	if ret_msg:HasField('RefixDmgRate') then
		oldData.RefixDmgRate = ret_msg.RefixDmgRate
		if isForceUpdate == true then
			self.m_RefixDmgRate = ret_msg.RefixDmgRate
		end
		if isNotify == true then
			self.m_RefixDmgRate = ret_msg.RefixDmgRate
			dataCallback(self,BASEATTR_REFIXDMGRATE,ret_msg.RefixDmgRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXDMGRATE,ret_msg.RefixDmgRate)
		end
	end
	if ret_msg:HasField('RefixDmgValue') then
		oldData.RefixDmgValue = ret_msg.RefixDmgValue
		if isForceUpdate == true then
			self.m_RefixDmgValue = ret_msg.RefixDmgValue
		end
		if isNotify == true then
			self.m_RefixDmgValue = ret_msg.RefixDmgValue
			dataCallback(self,BASEATTR_REFIXDMGVALUE,ret_msg.RefixDmgValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXDMGVALUE,ret_msg.RefixDmgValue)
		end
	end
	if ret_msg:HasField('RefixHurtRate') then
		oldData.RefixHurtRate = ret_msg.RefixHurtRate
		if isForceUpdate == true then
			self.m_RefixHurtRate = ret_msg.RefixHurtRate
		end
		if isNotify == true then
			self.m_RefixHurtRate = ret_msg.RefixHurtRate
			dataCallback(self,BASEATTR_REFIXHURTRATE,ret_msg.RefixHurtRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXHURTRATE,ret_msg.RefixHurtRate)
		end
	end
	if ret_msg:HasField('RefixHurtValue') then
		oldData.RefixHurtValue = ret_msg.RefixHurtValue
		if isForceUpdate == true then
			self.m_RefixHurtValue = ret_msg.RefixHurtValue
		end
		if isNotify == true then
			self.m_RefixHurtValue = ret_msg.RefixHurtValue
			dataCallback(self,BASEATTR_REFIXHURTVALUE,ret_msg.RefixHurtValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXHURTVALUE,ret_msg.RefixHurtValue)
		end
	end
	if ret_msg:HasField('RefixHealRate') then
		oldData.RefixHealRate = ret_msg.RefixHealRate
		if isForceUpdate == true then
			self.m_RefixHealRate = ret_msg.RefixHealRate
		end
		if isNotify == true then
			self.m_RefixHealRate = ret_msg.RefixHealRate
			dataCallback(self,BASEATTR_REFIXHEALRATE,ret_msg.RefixHealRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXHEALRATE,ret_msg.RefixHealRate)
		end
	end
	if ret_msg:HasField('RefixHealValue') then
		oldData.RefixHealValue = ret_msg.RefixHealValue
		if isForceUpdate == true then
			self.m_RefixHealValue = ret_msg.RefixHealValue
		end
		if isNotify == true then
			self.m_RefixHealValue = ret_msg.RefixHealValue
			dataCallback(self,BASEATTR_REFIXHEALVALUE,ret_msg.RefixHealValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXHEALVALUE,ret_msg.RefixHealValue)
		end
	end
	if ret_msg:HasField('RefixCuredRate') then
		oldData.RefixCuredRate = ret_msg.RefixCuredRate
		if isForceUpdate == true then
			self.m_RefixCuredRate = ret_msg.RefixCuredRate
		end
		if isNotify == true then
			self.m_RefixCuredRate = ret_msg.RefixCuredRate
			dataCallback(self,BASEATTR_REFIXCUREDRATE,ret_msg.RefixCuredRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXCUREDRATE,ret_msg.RefixCuredRate)
		end
	end
	if ret_msg:HasField('RefixCuredValue') then
		oldData.RefixCuredValue = ret_msg.RefixCuredValue
		if isForceUpdate == true then
			self.m_RefixCuredValue = ret_msg.RefixCuredValue
		end
		if isNotify == true then
			self.m_RefixCuredValue = ret_msg.RefixCuredValue
			dataCallback(self,BASEATTR_REFIXCUREDVALUE,ret_msg.RefixCuredValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_REFIXCUREDVALUE,ret_msg.RefixCuredValue)
		end
	end
	if ret_msg:HasField('GuildContribute') then
		oldData.GuildContribute = ret_msg.GuildContribute
		if isForceUpdate == true then
			self.m_GuildContribute = ret_msg.GuildContribute
		end
		if isNotify == true then
			self.m_GuildContribute = ret_msg.GuildContribute
			dataCallback(self,BASEATTR_GUILDCONTRIBUTE,ret_msg.GuildContribute)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDCONTRIBUTE,ret_msg.GuildContribute)
		end
	end
	if ret_msg:HasField('PvpMoney') then
		oldData.PvpMoney = ret_msg.PvpMoney
		if isForceUpdate == true then
			self.m_PvpMoney = ret_msg.PvpMoney
		end
		if isNotify == true then
			self.m_PvpMoney = ret_msg.PvpMoney
			dataCallback(self,BASEATTR_PVPMONEY,ret_msg.PvpMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PVPMONEY,ret_msg.PvpMoney)
		end
	end
	if ret_msg:HasField('GuildResource') then
		oldData.GuildResource = ret_msg.GuildResource
		if isForceUpdate == true then
			self.m_GuildResource = ret_msg.GuildResource
		end
		if isNotify == true then
			self.m_GuildResource = ret_msg.GuildResource
			dataCallback(self,BASEATTR_GUILDRESOURCE,ret_msg.GuildResource)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDRESOURCE,ret_msg.GuildResource)
		end
	end
	if ret_msg:HasField('CreateRoleTime') then
		oldData.CreateRoleTime = ret_msg.CreateRoleTime
		if isForceUpdate == true then
			self.m_CreateRoleTime = ret_msg.CreateRoleTime
		end
		if isNotify == true then
			self.m_CreateRoleTime = ret_msg.CreateRoleTime
			dataCallback(self,BASEATTR_CREATEROLETIME,ret_msg.CreateRoleTime)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CREATEROLETIME,ret_msg.CreateRoleTime)
		end
	end
	if ret_msg:HasField('UpdateRoleTime') then
		oldData.UpdateRoleTime = ret_msg.UpdateRoleTime
		if isForceUpdate == true then
			self.m_UpdateRoleTime = ret_msg.UpdateRoleTime
		end
		if isNotify == true then
			self.m_UpdateRoleTime = ret_msg.UpdateRoleTime
			dataCallback(self,BASEATTR_UPDATEROLETIME,ret_msg.UpdateRoleTime)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_UPDATEROLETIME,ret_msg.UpdateRoleTime)
		end
	end
	if ret_msg:HasField('FightState') then
		oldData.FightState = ret_msg.FightState
		if isForceUpdate == true then
			self.m_FightState = ret_msg.FightState
		end
		if isNotify == true then
			self.m_FightState = ret_msg.FightState
			dataCallback(self,BASEATTR_FIGHTSTATE,ret_msg.FightState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_FIGHTSTATE,ret_msg.FightState)
		end
	end
	if #ret_msg.AttackSkillList > 0 and oldData.AttackSkillList then
		m_AttackSkillList = {}
		removeTableData(oldData.AttackSkillList)
		for i = 1, #ret_msg.AttackSkillList do
			table.insert( oldData.AttackSkillList,ret_msg.AttackSkillList[i])
		end
		if isForceUpdate == true then
			for i = 1, #ret_msg.AttackSkillList do
				self.m_AttackSkillList[i] = ret_msg.AttackSkillList[i]
			end
		end
		if isNotify == true then
			for i = 1, #ret_msg.AttackSkillList do
				self.m_AttackSkillList[i] = ret_msg.AttackSkillList[i]
			end
			dataCallback(self,BASEATTR_ATTACKSKILLLIST,ret_msg.AttackSkillList)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ATTACKSKILLLIST,ret_msg.AttackSkillList)
		end
	end
	if ret_msg:HasField('GuildName') then
		oldData.GuildName = ret_msg.GuildName
		if isForceUpdate == true then
			self.m_GuildName = ret_msg.GuildName
		end
		if isNotify == true then
			dataCallback(self,BASEATTR_GUILDNAME,ret_msg.GuildName)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDNAME,ret_msg.GuildName)
		end
	end
	if ret_msg:HasField('IsAllowSelect') then
		oldData.IsAllowSelect = ret_msg.IsAllowSelect
		if isForceUpdate == true then
			self.m_IsAllowSelect = ret_msg.IsAllowSelect
		end
		if isNotify == true then
			self.m_IsAllowSelect = ret_msg.IsAllowSelect
			dataCallback(self,BASEATTR_ISALLOWSELECT,ret_msg.IsAllowSelect)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ISALLOWSELECT,ret_msg.IsAllowSelect)
		end
	end
	if ret_msg:HasField('GoHomeState') then
		oldData.GoHomeState = ret_msg.GoHomeState
		if isForceUpdate == true then
			self.m_GoHomeState = ret_msg.GoHomeState
		end
		if isNotify == true then
			self.m_GoHomeState = ret_msg.GoHomeState
			dataCallback(self,BASEATTR_GOHOMESTATE,ret_msg.GoHomeState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GOHOMESTATE,ret_msg.GoHomeState)
		end
	end
	if ret_msg:HasField('CanFight') then
		oldData.CanFight = ret_msg.CanFight
		if isForceUpdate == true then
			self.m_CanFight = ret_msg.CanFight
		end
		if isNotify == true then
			self.m_CanFight = ret_msg.CanFight
			dataCallback(self,BASEATTR_CANFIGHT,ret_msg.CanFight)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CANFIGHT,ret_msg.CanFight)
		end
	end
	if ret_msg:HasField('DoubleExp') then
		oldData.DoubleExp = ret_msg.DoubleExp
		if isForceUpdate == true then
			self.m_DoubleExp = ret_msg.DoubleExp
		end
		if isNotify == true then
			self.m_DoubleExp = ret_msg.DoubleExp
			dataCallback(self,BASEATTR_DOUBLEEXP,ret_msg.DoubleExp)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DOUBLEEXP,ret_msg.DoubleExp)
		end
	end
	if ret_msg:HasField('FriendPoint') then
		oldData.FriendPoint = ret_msg.FriendPoint
		if isForceUpdate == true then
			self.m_FriendPoint = ret_msg.FriendPoint
		end
		if isNotify == true then
			self.m_FriendPoint = ret_msg.FriendPoint
			dataCallback(self,BASEATTR_FRIENDPOINT,ret_msg.FriendPoint)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_FRIENDPOINT,ret_msg.FriendPoint)
		end
	end
	if ret_msg:HasField('HisMaxHonor') then
		oldData.HisMaxHonor = ret_msg.HisMaxHonor
		if isForceUpdate == true then
			self.m_HisMaxHonor = ret_msg.HisMaxHonor
		end
		if isNotify == true then
			self.m_HisMaxHonor = ret_msg.HisMaxHonor
			dataCallback(self,BASEATTR_HISMAXHONOR,ret_msg.HisMaxHonor)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HISMAXHONOR,ret_msg.HisMaxHonor)
		end
	end
	if ret_msg:HasField('HurtState') then
		oldData.HurtState = ret_msg.HurtState
		if isForceUpdate == true then
			self.m_HurtState = ret_msg.HurtState
		end
		if isNotify == true then
			self.m_HurtState = ret_msg.HurtState
			dataCallback(self,BASEATTR_HURTSTATE,ret_msg.HurtState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTSTATE,ret_msg.HurtState)
		end
	end
	if ret_msg:HasField('HurtFlyState') then
		oldData.HurtFlyState = ret_msg.HurtFlyState
		if isForceUpdate == true then
			self.m_HurtFlyState = ret_msg.HurtFlyState
		end
		if isNotify == true then
			self.m_HurtFlyState = ret_msg.HurtFlyState
			dataCallback(self,BASEATTR_HURTFLYSTATE,ret_msg.HurtFlyState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTFLYSTATE,ret_msg.HurtFlyState)
		end
	end
	if ret_msg:HasField('HurtDownState') then
		oldData.HurtDownState = ret_msg.HurtDownState
		if isForceUpdate == true then
			self.m_HurtDownState = ret_msg.HurtDownState
		end
		if isNotify == true then
			self.m_HurtDownState = ret_msg.HurtDownState
			dataCallback(self,BASEATTR_HURTDOWNSTATE,ret_msg.HurtDownState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTDOWNSTATE,ret_msg.HurtDownState)
		end
	end
	if ret_msg:HasField('HurtRepelState') then
		oldData.HurtRepelState = ret_msg.HurtRepelState
		if isForceUpdate == true then
			self.m_HurtRepelState = ret_msg.HurtRepelState
		end
		if isNotify == true then
			self.m_HurtRepelState = ret_msg.HurtRepelState
			dataCallback(self,BASEATTR_HURTREPELSTATE,ret_msg.HurtRepelState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTREPELSTATE,ret_msg.HurtRepelState)
		end
	end
	if ret_msg:HasField('TodayHornor') then
		oldData.TodayHornor = ret_msg.TodayHornor
		if isForceUpdate == true then
			self.m_TodayHornor = ret_msg.TodayHornor
		end
		if isNotify == true then
			self.m_TodayHornor = ret_msg.TodayHornor
			dataCallback(self,BASEATTR_TODAYHORNOR,ret_msg.TodayHornor)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TODAYHORNOR,ret_msg.TodayHornor)
		end
	end
	if ret_msg:HasField('CurProfession') then
		oldData.CurProfession = ret_msg.CurProfession
		if isForceUpdate == true then
			self.m_CurProfession = ret_msg.CurProfession
		end
		if isNotify == true then
			self.m_CurProfession = ret_msg.CurProfession
			dataCallback(self,BASEATTR_CURPROFESSION,ret_msg.CurProfession)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CURPROFESSION,ret_msg.CurProfession)
		end
	end
	if ret_msg:HasField('PetCreateDelCond') then
		oldData.PetCreateDelCond = ret_msg.PetCreateDelCond
		if isForceUpdate == true then
			self.m_PetCreateDelCond = ret_msg.PetCreateDelCond
		end
		if isNotify == true then
			self.m_PetCreateDelCond = ret_msg.PetCreateDelCond
			dataCallback(self,BASEATTR_PETCREATEDELCOND,ret_msg.PetCreateDelCond)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PETCREATEDELCOND,ret_msg.PetCreateDelCond)
		end
	end
	if ret_msg:HasField('PetDisplay') then
		oldData.PetDisplay = ret_msg.PetDisplay
		if isForceUpdate == true then
			self.m_PetDisplay = ret_msg.PetDisplay
		end
		if isNotify == true then
			self.m_PetDisplay = ret_msg.PetDisplay
			dataCallback(self,BASEATTR_PETDISPLAY,ret_msg.PetDisplay)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PETDISPLAY,ret_msg.PetDisplay)
		end
	end
	if ret_msg:HasField('PetMoney') then
		oldData.PetMoney = ret_msg.PetMoney
		if isForceUpdate == true then
			self.m_PetMoney = ret_msg.PetMoney
		end
		if isNotify == true then
			self.m_PetMoney = ret_msg.PetMoney
			dataCallback(self,BASEATTR_PETMONEY,ret_msg.PetMoney)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PETMONEY,ret_msg.PetMoney)
		end
	end
	if ret_msg:HasField('DuelStatus') then
		oldData.DuelStatus = ret_msg.DuelStatus
		if isForceUpdate == true then
			self.m_DuelStatus = ret_msg.DuelStatus
		end
		if isNotify == true then
			self.m_DuelStatus = ret_msg.DuelStatus
			dataCallback(self,BASEATTR_DUELSTATUS,ret_msg.DuelStatus)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DUELSTATUS,ret_msg.DuelStatus)
		end
	end
	if ret_msg:HasField('ExpPool') then
		oldData.ExpPool = ret_msg.ExpPool
		if isForceUpdate == true then
			self.m_ExpPool = ret_msg.ExpPool
		end
		if isNotify == true then
			self.m_ExpPool = ret_msg.ExpPool
			dataCallback(self,BASEATTR_EXPPOOL,ret_msg.ExpPool)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_EXPPOOL,ret_msg.ExpPool)
		end
	end
	if ret_msg:HasField('RushState') then
		oldData.RushState = ret_msg.RushState
		if isForceUpdate == true then
			self.m_RushState = ret_msg.RushState
		end
		if isNotify == true then
			self.m_RushState = ret_msg.RushState
			dataCallback(self,BASEATTR_RUSHSTATE,ret_msg.RushState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_RUSHSTATE,ret_msg.RushState)
		end
	end
	if ret_msg:HasField('StareState') then
		oldData.StareState = ret_msg.StareState
		if isForceUpdate == true then
			self.m_StareState = ret_msg.StareState
		end
		if isNotify == true then
			self.m_StareState = ret_msg.StareState
			dataCallback(self,BASEATTR_STARESTATE,ret_msg.StareState)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_STARESTATE,ret_msg.StareState)
		end
	end
	if ret_msg:HasField('WorldLevel') then
		oldData.WorldLevel = ret_msg.WorldLevel
		if isForceUpdate == true then
			self.m_WorldLevel = ret_msg.WorldLevel
		end
		if isNotify == true then
			self.m_WorldLevel = ret_msg.WorldLevel
			dataCallback(self,BASEATTR_WORLDLEVEL,ret_msg.WorldLevel)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_WORLDLEVEL,ret_msg.WorldLevel)
		end
	end
	if ret_msg:HasField('DizzyHitRate') then
		oldData.DizzyHitRate = ret_msg.DizzyHitRate
		if isForceUpdate == true then
			self.m_DizzyHitRate = ret_msg.DizzyHitRate
		end
		if isNotify == true then
			self.m_DizzyHitRate = ret_msg.DizzyHitRate
			dataCallback(self,BASEATTR_DIZZYHITRATE,ret_msg.DizzyHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DIZZYHITRATE,ret_msg.DizzyHitRate)
		end
	end
	if ret_msg:HasField('DizzyResistRate') then
		oldData.DizzyResistRate = ret_msg.DizzyResistRate
		if isForceUpdate == true then
			self.m_DizzyResistRate = ret_msg.DizzyResistRate
		end
		if isNotify == true then
			self.m_DizzyResistRate = ret_msg.DizzyResistRate
			dataCallback(self,BASEATTR_DIZZYRESISTRATE,ret_msg.DizzyResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DIZZYRESISTRATE,ret_msg.DizzyResistRate)
		end
	end
	if ret_msg:HasField('ImmovableHitRate') then
		oldData.ImmovableHitRate = ret_msg.ImmovableHitRate
		if isForceUpdate == true then
			self.m_ImmovableHitRate = ret_msg.ImmovableHitRate
		end
		if isNotify == true then
			self.m_ImmovableHitRate = ret_msg.ImmovableHitRate
			dataCallback(self,BASEATTR_IMMOVABLEHITRATE,ret_msg.ImmovableHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_IMMOVABLEHITRATE,ret_msg.ImmovableHitRate)
		end
	end
	if ret_msg:HasField('ImmovableResistRate') then
		oldData.ImmovableResistRate = ret_msg.ImmovableResistRate
		if isForceUpdate == true then
			self.m_ImmovableResistRate = ret_msg.ImmovableResistRate
		end
		if isNotify == true then
			self.m_ImmovableResistRate = ret_msg.ImmovableResistRate
			dataCallback(self,BASEATTR_IMMOVABLERESISTRATE,ret_msg.ImmovableResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_IMMOVABLERESISTRATE,ret_msg.ImmovableResistRate)
		end
	end
	if ret_msg:HasField('HurtFlyHitRate') then
		oldData.HurtFlyHitRate = ret_msg.HurtFlyHitRate
		if isForceUpdate == true then
			self.m_HurtFlyHitRate = ret_msg.HurtFlyHitRate
		end
		if isNotify == true then
			self.m_HurtFlyHitRate = ret_msg.HurtFlyHitRate
			dataCallback(self,BASEATTR_HURTFLYHITRATE,ret_msg.HurtFlyHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTFLYHITRATE,ret_msg.HurtFlyHitRate)
		end
	end
	if ret_msg:HasField('HurtFlyResistRate') then
		oldData.HurtFlyResistRate = ret_msg.HurtFlyResistRate
		if isForceUpdate == true then
			self.m_HurtFlyResistRate = ret_msg.HurtFlyResistRate
		end
		if isNotify == true then
			self.m_HurtFlyResistRate = ret_msg.HurtFlyResistRate
			dataCallback(self,BASEATTR_HURTFLYRESISTRATE,ret_msg.HurtFlyResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HURTFLYRESISTRATE,ret_msg.HurtFlyResistRate)
		end
	end
	if ret_msg:HasField('FrozenHitRate') then
		oldData.FrozenHitRate = ret_msg.FrozenHitRate
		if isForceUpdate == true then
			self.m_FrozenHitRate = ret_msg.FrozenHitRate
		end
		if isNotify == true then
			self.m_FrozenHitRate = ret_msg.FrozenHitRate
			dataCallback(self,BASEATTR_FROZENHITRATE,ret_msg.FrozenHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_FROZENHITRATE,ret_msg.FrozenHitRate)
		end
	end
	if ret_msg:HasField('FrozenResistRate') then
		oldData.FrozenResistRate = ret_msg.FrozenResistRate
		if isForceUpdate == true then
			self.m_FrozenResistRate = ret_msg.FrozenResistRate
		end
		if isNotify == true then
			self.m_FrozenResistRate = ret_msg.FrozenResistRate
			dataCallback(self,BASEATTR_FROZENRESISTRATE,ret_msg.FrozenResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_FROZENRESISTRATE,ret_msg.FrozenResistRate)
		end
	end
	if ret_msg:HasField('CleanHitRate') then
		oldData.CleanHitRate = ret_msg.CleanHitRate
		if isForceUpdate == true then
			self.m_CleanHitRate = ret_msg.CleanHitRate
		end
		if isNotify == true then
			self.m_CleanHitRate = ret_msg.CleanHitRate
			dataCallback(self,BASEATTR_CLEANHITRATE,ret_msg.CleanHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CLEANHITRATE,ret_msg.CleanHitRate)
		end
	end
	if ret_msg:HasField('CleanResistRate') then
		oldData.CleanResistRate = ret_msg.CleanResistRate
		if isForceUpdate == true then
			self.m_CleanResistRate = ret_msg.CleanResistRate
		end
		if isNotify == true then
			self.m_CleanResistRate = ret_msg.CleanResistRate
			dataCallback(self,BASEATTR_CLEANRESISTRATE,ret_msg.CleanResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CLEANRESISTRATE,ret_msg.CleanResistRate)
		end
	end
	if ret_msg:HasField('DispelHitRate') then
		oldData.DispelHitRate = ret_msg.DispelHitRate
		if isForceUpdate == true then
			self.m_DispelHitRate = ret_msg.DispelHitRate
		end
		if isNotify == true then
			self.m_DispelHitRate = ret_msg.DispelHitRate
			dataCallback(self,BASEATTR_DISPELHITRATE,ret_msg.DispelHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DISPELHITRATE,ret_msg.DispelHitRate)
		end
	end
	if ret_msg:HasField('DispelResistRate') then
		oldData.DispelResistRate = ret_msg.DispelResistRate
		if isForceUpdate == true then
			self.m_DispelResistRate = ret_msg.DispelResistRate
		end
		if isNotify == true then
			self.m_DispelResistRate = ret_msg.DispelResistRate
			dataCallback(self,BASEATTR_DISPELRESISTRATE,ret_msg.DispelResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DISPELRESISTRATE,ret_msg.DispelResistRate)
		end
	end
	if ret_msg:HasField('SilenceHitRate') then
		oldData.SilenceHitRate = ret_msg.SilenceHitRate
		if isForceUpdate == true then
			self.m_SilenceHitRate = ret_msg.SilenceHitRate
		end
		if isNotify == true then
			self.m_SilenceHitRate = ret_msg.SilenceHitRate
			dataCallback(self,BASEATTR_SILENCEHITRATE,ret_msg.SilenceHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SILENCEHITRATE,ret_msg.SilenceHitRate)
		end
	end
	if ret_msg:HasField('SilenceResistRate') then
		oldData.SilenceResistRate = ret_msg.SilenceResistRate
		if isForceUpdate == true then
			self.m_SilenceResistRate = ret_msg.SilenceResistRate
		end
		if isNotify == true then
			self.m_SilenceResistRate = ret_msg.SilenceResistRate
			dataCallback(self,BASEATTR_SILENCERESISTRATE,ret_msg.SilenceResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SILENCERESISTRATE,ret_msg.SilenceResistRate)
		end
	end
	if ret_msg:HasField('InterruptHitRate') then
		oldData.InterruptHitRate = ret_msg.InterruptHitRate
		if isForceUpdate == true then
			self.m_InterruptHitRate = ret_msg.InterruptHitRate
		end
		if isNotify == true then
			self.m_InterruptHitRate = ret_msg.InterruptHitRate
			dataCallback(self,BASEATTR_INTERRUPTHITRATE,ret_msg.InterruptHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_INTERRUPTHITRATE,ret_msg.InterruptHitRate)
		end
	end
	if ret_msg:HasField('InterruptResistRate') then
		oldData.InterruptResistRate = ret_msg.InterruptResistRate
		if isForceUpdate == true then
			self.m_InterruptResistRate = ret_msg.InterruptResistRate
		end
		if isNotify == true then
			self.m_InterruptResistRate = ret_msg.InterruptResistRate
			dataCallback(self,BASEATTR_INTERRUPTRESISTRATE,ret_msg.InterruptResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_INTERRUPTRESISTRATE,ret_msg.InterruptResistRate)
		end
	end
	if ret_msg:HasField('UncurableHitRate') then
		oldData.UncurableHitRate = ret_msg.UncurableHitRate
		if isForceUpdate == true then
			self.m_UncurableHitRate = ret_msg.UncurableHitRate
		end
		if isNotify == true then
			self.m_UncurableHitRate = ret_msg.UncurableHitRate
			dataCallback(self,BASEATTR_UNCURABLEHITRATE,ret_msg.UncurableHitRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_UNCURABLEHITRATE,ret_msg.UncurableHitRate)
		end
	end
	if ret_msg:HasField('UncurableResistRate') then
		oldData.UncurableResistRate = ret_msg.UncurableResistRate
		if isForceUpdate == true then
			self.m_UncurableResistRate = ret_msg.UncurableResistRate
		end
		if isNotify == true then
			self.m_UncurableResistRate = ret_msg.UncurableResistRate
			dataCallback(self,BASEATTR_UNCURABLERESISTRATE,ret_msg.UncurableResistRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_UNCURABLERESISTRATE,ret_msg.UncurableResistRate)
		end
	end
	if ret_msg:HasField('Transform') then
		oldData.Transform = ret_msg.Transform
		if isForceUpdate == true then
			self.m_Transform = ret_msg.Transform
		end
		if isNotify == true then
			self.m_Transform = ret_msg.Transform
			dataCallback(self,BASEATTR_TRANSFORM,ret_msg.Transform)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TRANSFORM,ret_msg.Transform)
		end
	end
	if ret_msg:HasField('HumanHurtRate') then
		oldData.HumanHurtRate = ret_msg.HumanHurtRate
		if isForceUpdate == true then
			self.m_HumanHurtRate = ret_msg.HumanHurtRate
		end
		if isNotify == true then
			self.m_HumanHurtRate = ret_msg.HumanHurtRate
			dataCallback(self,BASEATTR_HUMANHURTRATE,ret_msg.HumanHurtRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HUMANHURTRATE,ret_msg.HumanHurtRate)
		end
	end
	if ret_msg:HasField('HumanSufferRate') then
		oldData.HumanSufferRate = ret_msg.HumanSufferRate
		if isForceUpdate == true then
			self.m_HumanSufferRate = ret_msg.HumanSufferRate
		end
		if isNotify == true then
			self.m_HumanSufferRate = ret_msg.HumanSufferRate
			dataCallback(self,BASEATTR_HUMANSUFFERRATE,ret_msg.HumanSufferRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HUMANSUFFERRATE,ret_msg.HumanSufferRate)
		end
	end
	if ret_msg:HasField('MonsterHurtRate') then
		oldData.MonsterHurtRate = ret_msg.MonsterHurtRate
		if isForceUpdate == true then
			self.m_MonsterHurtRate = ret_msg.MonsterHurtRate
		end
		if isNotify == true then
			self.m_MonsterHurtRate = ret_msg.MonsterHurtRate
			dataCallback(self,BASEATTR_MONSTERHURTRATE,ret_msg.MonsterHurtRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MONSTERHURTRATE,ret_msg.MonsterHurtRate)
		end
	end
	if ret_msg:HasField('MonsterSufferRate') then
		oldData.MonsterSufferRate = ret_msg.MonsterSufferRate
		if isForceUpdate == true then
			self.m_MonsterSufferRate = ret_msg.MonsterSufferRate
		end
		if isNotify == true then
			self.m_MonsterSufferRate = ret_msg.MonsterSufferRate
			dataCallback(self,BASEATTR_MONSTERSUFFERRATE,ret_msg.MonsterSufferRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_MONSTERSUFFERRATE,ret_msg.MonsterSufferRate)
		end
	end
	if ret_msg:HasField('BossHurtRate') then
		oldData.BossHurtRate = ret_msg.BossHurtRate
		if isForceUpdate == true then
			self.m_BossHurtRate = ret_msg.BossHurtRate
		end
		if isNotify == true then
			self.m_BossHurtRate = ret_msg.BossHurtRate
			dataCallback(self,BASEATTR_BOSSHURTRATE,ret_msg.BossHurtRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_BOSSHURTRATE,ret_msg.BossHurtRate)
		end
	end
	if ret_msg:HasField('BossSufferRate') then
		oldData.BossSufferRate = ret_msg.BossSufferRate
		if isForceUpdate == true then
			self.m_BossSufferRate = ret_msg.BossSufferRate
		end
		if isNotify == true then
			self.m_BossSufferRate = ret_msg.BossSufferRate
			dataCallback(self,BASEATTR_BOSSSUFFERRATE,ret_msg.BossSufferRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_BOSSSUFFERRATE,ret_msg.BossSufferRate)
		end
	end
	if ret_msg:HasField('DodgReduceValue') then
		oldData.DodgReduceValue = ret_msg.DodgReduceValue
		if isForceUpdate == true then
			self.m_DodgReduceValue = ret_msg.DodgReduceValue
		end
		if isNotify == true then
			self.m_DodgReduceValue = ret_msg.DodgReduceValue
			dataCallback(self,BASEATTR_DODGREDUCEVALUE,ret_msg.DodgReduceValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGREDUCEVALUE,ret_msg.DodgReduceValue)
		end
	end
	if ret_msg:HasField('DodgReduceRate') then
		oldData.DodgReduceRate = ret_msg.DodgReduceRate
		if isForceUpdate == true then
			self.m_DodgReduceRate = ret_msg.DodgReduceRate
		end
		if isNotify == true then
			self.m_DodgReduceRate = ret_msg.DodgReduceRate
			dataCallback(self,BASEATTR_DODGREDUCERATE,ret_msg.DodgReduceRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGREDUCERATE,ret_msg.DodgReduceRate)
		end
	end
	if ret_msg:HasField('DodgAddValue') then
		oldData.DodgAddValue = ret_msg.DodgAddValue
		if isForceUpdate == true then
			self.m_DodgAddValue = ret_msg.DodgAddValue
		end
		if isNotify == true then
			self.m_DodgAddValue = ret_msg.DodgAddValue
			dataCallback(self,BASEATTR_DODGADDVALUE,ret_msg.DodgAddValue)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGADDVALUE,ret_msg.DodgAddValue)
		end
	end
	if ret_msg:HasField('DodgAddRate') then
		oldData.DodgAddRate = ret_msg.DodgAddRate
		if isForceUpdate == true then
			self.m_DodgAddRate = ret_msg.DodgAddRate
		end
		if isNotify == true then
			self.m_DodgAddRate = ret_msg.DodgAddRate
			dataCallback(self,BASEATTR_DODGADDRATE,ret_msg.DodgAddRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_DODGADDRATE,ret_msg.DodgAddRate)
		end
	end
	if ret_msg:HasField('TreasureFootPrint') then
		oldData.TreasureFootPrint = ret_msg.TreasureFootPrint
		if isForceUpdate == true then
			self.m_TreasureFootPrint = ret_msg.TreasureFootPrint
		end
		if isNotify == true then
			self.m_TreasureFootPrint = ret_msg.TreasureFootPrint
			dataCallback(self,BASEATTR_TREASUREFOOTPRINT,ret_msg.TreasureFootPrint)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_TREASUREFOOTPRINT,ret_msg.TreasureFootPrint)
		end
	end
	if ret_msg:HasField('EquipTitle') then
		oldData.EquipTitle = ret_msg.EquipTitle
		if isForceUpdate == true then
			self.m_EquipTitle = ret_msg.EquipTitle
		end
		if isNotify == true then
			self.m_EquipTitle = ret_msg.EquipTitle
			dataCallback(self,BASEATTR_EQUIPTITLE,ret_msg.EquipTitle)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_EQUIPTITLE,ret_msg.EquipTitle)
		end
	end
	if #ret_msg.ObjAnimEvent > 0 and oldData.ObjAnimEvent then
		m_ObjAnimEvent = {}
		removeTableData(oldData.ObjAnimEvent)
		for i = 1, #ret_msg.ObjAnimEvent do
			table.insert( oldData.ObjAnimEvent,ret_msg.ObjAnimEvent[i])
		end
		if isForceUpdate == true then
			for i = 1, #ret_msg.ObjAnimEvent do
				self.m_ObjAnimEvent[i] = ret_msg.ObjAnimEvent[i]
			end
		end
		if isNotify == true then
			for i = 1, #ret_msg.ObjAnimEvent do
				self.m_ObjAnimEvent[i] = ret_msg.ObjAnimEvent[i]
			end
			dataCallback(self,BASEATTR_OBJANIMEVENT,ret_msg.ObjAnimEvent)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_OBJANIMEVENT,ret_msg.ObjAnimEvent)
		end
	end
	if ret_msg:HasField('PinchData') then
		oldData.PinchData = ret_msg.PinchData
		if isForceUpdate == true then
			self.m_PinchData = ret_msg.PinchData
		end
		if isNotify == true then
			dataCallback(self,BASEATTR_PINCHDATA,ret_msg.PinchData)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_PINCHDATA,ret_msg.PinchData)
		end
	end
	if ret_msg:HasField('SkillCDRate') then
		oldData.SkillCDRate = ret_msg.SkillCDRate
		if isForceUpdate == true then
			self.m_SkillCDRate = ret_msg.SkillCDRate
		end
		if isNotify == true then
			self.m_SkillCDRate = ret_msg.SkillCDRate
			dataCallback(self,BASEATTR_SKILLCDRATE,ret_msg.SkillCDRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SKILLCDRATE,ret_msg.SkillCDRate)
		end
	end
	if ret_msg:HasField('AspdRate') then
		oldData.AspdRate = ret_msg.AspdRate
		if isForceUpdate == true then
			self.m_AspdRate = ret_msg.AspdRate
		end
		if isNotify == true then
			self.m_AspdRate = ret_msg.AspdRate
			dataCallback(self,BASEATTR_ASPDRATE,ret_msg.AspdRate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ASPDRATE,ret_msg.AspdRate)
		end
	end
	if ret_msg:HasField('Shield') then
		oldData.Shield = ret_msg.Shield
		if isForceUpdate == true then
			self.m_Shield = ret_msg.Shield
		end
		if isNotify == true then
			self.m_Shield = ret_msg.Shield
			dataCallback(self,BASEATTR_SHIELD,ret_msg.Shield)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SHIELD,ret_msg.Shield)
		end
	end
	if ret_msg:HasField('EventLeftCount') then
		oldData.EventLeftCount = ret_msg.EventLeftCount
		if isForceUpdate == true then
			self.m_EventLeftCount = ret_msg.EventLeftCount
		end
		if isNotify == true then
			self.m_EventLeftCount = ret_msg.EventLeftCount
			dataCallback(self,BASEATTR_EVENTLEFTCOUNT,ret_msg.EventLeftCount)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_EVENTLEFTCOUNT,ret_msg.EventLeftCount)
		end
	end
	if ret_msg:HasField('CanNotRush') then
		oldData.CanNotRush = ret_msg.CanNotRush
		if isForceUpdate == true then
			self.m_CanNotRush = ret_msg.CanNotRush
		end
		if isNotify == true then
			self.m_CanNotRush = ret_msg.CanNotRush
			dataCallback(self,BASEATTR_CANNOTRUSH,ret_msg.CanNotRush)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CANNOTRUSH,ret_msg.CanNotRush)
		end
	end
	if ret_msg:HasField('HuntPoint') then
		oldData.HuntPoint = ret_msg.HuntPoint
		if isForceUpdate == true then
			self.m_HuntPoint = ret_msg.HuntPoint
		end
		if isNotify == true then
			self.m_HuntPoint = ret_msg.HuntPoint
			dataCallback(self,BASEATTR_HUNTPOINT,ret_msg.HuntPoint)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HUNTPOINT,ret_msg.HuntPoint)
		end
	end
	if ret_msg:HasField('HuntHighTimes') then
		oldData.HuntHighTimes = ret_msg.HuntHighTimes
		if isForceUpdate == true then
			self.m_HuntHighTimes = ret_msg.HuntHighTimes
		end
		if isNotify == true then
			self.m_HuntHighTimes = ret_msg.HuntHighTimes
			dataCallback(self,BASEATTR_HUNTHIGHTIMES,ret_msg.HuntHighTimes)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HUNTHIGHTIMES,ret_msg.HuntHighTimes)
		end
	end
	if ret_msg:HasField('HuntFirePoint') then
		oldData.HuntFirePoint = ret_msg.HuntFirePoint
		if isForceUpdate == true then
			self.m_HuntFirePoint = ret_msg.HuntFirePoint
		end
		if isNotify == true then
			self.m_HuntFirePoint = ret_msg.HuntFirePoint
			dataCallback(self,BASEATTR_HUNTFIREPOINT,ret_msg.HuntFirePoint)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_HUNTFIREPOINT,ret_msg.HuntFirePoint)
		end
	end
	if ret_msg:HasField('Starbattlestate') then
		oldData.Starbattlestate = ret_msg.Starbattlestate
		if isForceUpdate == true then
			self.m_Starbattlestate = ret_msg.Starbattlestate
		end
		if isNotify == true then
			self.m_Starbattlestate = ret_msg.Starbattlestate
			dataCallback(self,BASEATTR_STARBATTLESTATE,ret_msg.Starbattlestate)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_STARBATTLESTATE,ret_msg.Starbattlestate)
		end
	end
	if ret_msg:HasField('IgnoreMotionBlock') then
		oldData.IgnoreMotionBlock = ret_msg.IgnoreMotionBlock
		if isForceUpdate == true then
			self.m_IgnoreMotionBlock = ret_msg.IgnoreMotionBlock
		end
		if isNotify == true then
			self.m_IgnoreMotionBlock = ret_msg.IgnoreMotionBlock
			dataCallback(self,BASEATTR_IGNOREMOTIONBLOCK,ret_msg.IgnoreMotionBlock)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_IGNOREMOTIONBLOCK,ret_msg.IgnoreMotionBlock)
		end
	end
	if ret_msg:HasField('EnableInteract') then
		oldData.EnableInteract = ret_msg.EnableInteract
		if isForceUpdate == true then
			self.m_EnableInteract = ret_msg.EnableInteract
		end
		if isNotify == true then
			self.m_EnableInteract = ret_msg.EnableInteract
			dataCallback(self,BASEATTR_ENABLEINTERACT,ret_msg.EnableInteract)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_ENABLEINTERACT,ret_msg.EnableInteract)
		end
	end
	if ret_msg:HasField('WorldMedal') then
		oldData.WorldMedal = ret_msg.WorldMedal
		if isForceUpdate == true then
			self.m_WorldMedal = ret_msg.WorldMedal
		end
		if isNotify == true then
			self.m_WorldMedal = ret_msg.WorldMedal
			dataCallback(self,BASEATTR_WORLDMEDAL,ret_msg.WorldMedal)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_WORLDMEDAL,ret_msg.WorldMedal)
		end
	end
	if ret_msg:HasField('CureCeiling') then
		oldData.CureCeiling = ret_msg.CureCeiling
		if isForceUpdate == true then
			self.m_CureCeiling = ret_msg.CureCeiling
		end
		if isNotify == true then
			self.m_CureCeiling = ret_msg.CureCeiling
			dataCallback(self,BASEATTR_CURECEILING,ret_msg.CureCeiling)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_CURECEILING,ret_msg.CureCeiling)
		end
	end
	if ret_msg:HasField('RelationUnionCurrency') then
		oldData.RelationUnionCurrency = ret_msg.RelationUnionCurrency
		if isForceUpdate == true then
			self.m_RelationUnionCurrency = ret_msg.RelationUnionCurrency
		end
		if isNotify == true then
			self.m_RelationUnionCurrency = ret_msg.RelationUnionCurrency
			dataCallback(self,BASEATTR_RELATIONUNIONCURRENCY,ret_msg.RelationUnionCurrency)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_RELATIONUNIONCURRENCY,ret_msg.RelationUnionCurrency)
		end
	end
	if ret_msg:HasField('GuildShortName') then
		oldData.GuildShortName = ret_msg.GuildShortName
		if isForceUpdate == true then
			self.m_GuildShortName = ret_msg.GuildShortName
		end
		if isNotify == true then
			dataCallback(self,BASEATTR_GUILDSHORTNAME,ret_msg.GuildShortName)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDSHORTNAME,ret_msg.GuildShortName)
		end
	end
	if ret_msg:HasField('GuildShortColorID') then
		oldData.GuildShortColorID = ret_msg.GuildShortColorID
		if isForceUpdate == true then
			self.m_GuildShortColorID = ret_msg.GuildShortColorID
		end
		if isNotify == true then
			self.m_GuildShortColorID = ret_msg.GuildShortColorID
			dataCallback(self,BASEATTR_GUILDSHORTCOLORID,ret_msg.GuildShortColorID)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_GUILDSHORTCOLORID,ret_msg.GuildShortColorID)
		end
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
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[BaseAttr => SyncData ]")
			end
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
	elseif  Id == BASEATTR_ACCUMULATESKIENERGY then
		return self.m_AccumulateSkiEnergy
	elseif  Id == BASEATTR_NICKNAME then
		return  self.m_NickName
	elseif  Id == BASEATTR_CONFIGID then
		return self.m_ConfigId
	elseif  Id == BASEATTR_OBJTYPE then
		return self.m_ObjType
	elseif  Id == BASEATTR_STATE then
		return self.m_State
	elseif  Id == BASEATTR_OWNEROBJID then
		return self.m_OwnerObjId
	elseif  Id == BASEATTR_CAMP then
		return self.m_Camp
	elseif  Id == BASEATTR_SILVERMONEY then
		return self.m_SilverMoney
	elseif  Id == BASEATTR_GOLDMONEY then
		return self.m_GoldMoney
	elseif  Id == BASEATTR_DIAMONDMONEY then
		return self.m_DiamondMoney
	elseif  Id == BASEATTR_BINDINGDIAMONDMONEY then
		return self.m_BindingDiamondMoney
	elseif  Id == BASEATTR_BATTLESCORE then
		return self.m_BattleScore
	elseif  Id == BASEATTR_ENERGY then
		return self.m_Energy
	elseif  Id == BASEATTR_GUILDMONEY then
		return self.m_GuildMoney
	elseif  Id == BASEATTR_SKILLLIST then
		if Index<0 then
			return self.m_SkillList
		else
			return self.m_SkillList[Index]
		end
	elseif  Id == BASEATTR_HONORMONEY then
		return self.m_HonorMoney
	elseif  Id == BASEATTR_RESOURCEPOOLHP then
		return self.m_ResourcePoolHp
	elseif  Id == BASEATTR_ATTACKADD then
		return self.m_AttackAdd
	elseif  Id == BASEATTR_INJURYADD then
		return self.m_InjuryAdd
	elseif  Id == BASEATTR_FROZENSTATE then
		return self.m_FrozenState
	elseif  Id == BASEATTR_SILENTSTATE then
		return self.m_SilentState
	elseif  Id == BASEATTR_GUILDCONTRIBUTEHISTORYMAX then
		return self.m_GuildContributeHistoryMax
	elseif  Id == BASEATTR_TEAMID then
		return self.m_TeamId
	elseif  Id == BASEATTR_TREASUREHAIR then
		return self.m_TreasureHair
	elseif  Id == BASEATTR_TREASUREHEAD then
		return self.m_TreasureHead
	elseif  Id == BASEATTR_TREASUREBODY then
		return self.m_TreasureBody
	elseif  Id == BASEATTR_TREASUREWEAPON then
		return self.m_TreasureWeapon
	elseif  Id == BASEATTR_TREASUREWING then
		return self.m_TreasureWing
	elseif  Id == BASEATTR_GUILDGUID then
		return self.m_GuildGuid
	elseif  Id == BASEATTR_TREASURERIDING then
		return self.m_TreasureRiding
	elseif  Id == BASEATTR_VECHICLEID then
		return self.m_VechicleId
	elseif  Id == BASEATTR_ANIMATIONSTATE then
		return self.m_AnimationState
	elseif  Id == BASEATTR_REFIXDMGRATE then
		return self.m_RefixDmgRate
	elseif  Id == BASEATTR_REFIXDMGVALUE then
		return self.m_RefixDmgValue
	elseif  Id == BASEATTR_REFIXHURTRATE then
		return self.m_RefixHurtRate
	elseif  Id == BASEATTR_REFIXHURTVALUE then
		return self.m_RefixHurtValue
	elseif  Id == BASEATTR_REFIXHEALRATE then
		return self.m_RefixHealRate
	elseif  Id == BASEATTR_REFIXHEALVALUE then
		return self.m_RefixHealValue
	elseif  Id == BASEATTR_REFIXCUREDRATE then
		return self.m_RefixCuredRate
	elseif  Id == BASEATTR_REFIXCUREDVALUE then
		return self.m_RefixCuredValue
	elseif  Id == BASEATTR_GUILDCONTRIBUTE then
		return self.m_GuildContribute
	elseif  Id == BASEATTR_PVPMONEY then
		return self.m_PvpMoney
	elseif  Id == BASEATTR_GUILDRESOURCE then
		return self.m_GuildResource
	elseif  Id == BASEATTR_CREATEROLETIME then
		return self.m_CreateRoleTime
	elseif  Id == BASEATTR_UPDATEROLETIME then
		return self.m_UpdateRoleTime
	elseif  Id == BASEATTR_FIGHTSTATE then
		return self.m_FightState
	elseif  Id == BASEATTR_ATTACKSKILLLIST then
		if Index<0 then
			return self.m_AttackSkillList
		else
			return self.m_AttackSkillList[Index]
		end
	elseif  Id == BASEATTR_GUILDNAME then
		return  self.m_GuildName
	elseif  Id == BASEATTR_ISALLOWSELECT then
		return self.m_IsAllowSelect
	elseif  Id == BASEATTR_GOHOMESTATE then
		return self.m_GoHomeState
	elseif  Id == BASEATTR_CANFIGHT then
		return self.m_CanFight
	elseif  Id == BASEATTR_DOUBLEEXP then
		return self.m_DoubleExp
	elseif  Id == BASEATTR_FRIENDPOINT then
		return self.m_FriendPoint
	elseif  Id == BASEATTR_HISMAXHONOR then
		return self.m_HisMaxHonor
	elseif  Id == BASEATTR_HURTSTATE then
		return self.m_HurtState
	elseif  Id == BASEATTR_HURTFLYSTATE then
		return self.m_HurtFlyState
	elseif  Id == BASEATTR_HURTDOWNSTATE then
		return self.m_HurtDownState
	elseif  Id == BASEATTR_HURTREPELSTATE then
		return self.m_HurtRepelState
	elseif  Id == BASEATTR_TODAYHORNOR then
		return self.m_TodayHornor
	elseif  Id == BASEATTR_CURPROFESSION then
		return self.m_CurProfession
	elseif  Id == BASEATTR_PETCREATEDELCOND then
		return self.m_PetCreateDelCond
	elseif  Id == BASEATTR_PETDISPLAY then
		return self.m_PetDisplay
	elseif  Id == BASEATTR_PETMONEY then
		return self.m_PetMoney
	elseif  Id == BASEATTR_DUELSTATUS then
		return self.m_DuelStatus
	elseif  Id == BASEATTR_EXPPOOL then
		return self.m_ExpPool
	elseif  Id == BASEATTR_RUSHSTATE then
		return self.m_RushState
	elseif  Id == BASEATTR_STARESTATE then
		return self.m_StareState
	elseif  Id == BASEATTR_WORLDLEVEL then
		return self.m_WorldLevel
	elseif  Id == BASEATTR_DIZZYHITRATE then
		return self.m_DizzyHitRate
	elseif  Id == BASEATTR_DIZZYRESISTRATE then
		return self.m_DizzyResistRate
	elseif  Id == BASEATTR_IMMOVABLEHITRATE then
		return self.m_ImmovableHitRate
	elseif  Id == BASEATTR_IMMOVABLERESISTRATE then
		return self.m_ImmovableResistRate
	elseif  Id == BASEATTR_HURTFLYHITRATE then
		return self.m_HurtFlyHitRate
	elseif  Id == BASEATTR_HURTFLYRESISTRATE then
		return self.m_HurtFlyResistRate
	elseif  Id == BASEATTR_FROZENHITRATE then
		return self.m_FrozenHitRate
	elseif  Id == BASEATTR_FROZENRESISTRATE then
		return self.m_FrozenResistRate
	elseif  Id == BASEATTR_CLEANHITRATE then
		return self.m_CleanHitRate
	elseif  Id == BASEATTR_CLEANRESISTRATE then
		return self.m_CleanResistRate
	elseif  Id == BASEATTR_DISPELHITRATE then
		return self.m_DispelHitRate
	elseif  Id == BASEATTR_DISPELRESISTRATE then
		return self.m_DispelResistRate
	elseif  Id == BASEATTR_SILENCEHITRATE then
		return self.m_SilenceHitRate
	elseif  Id == BASEATTR_SILENCERESISTRATE then
		return self.m_SilenceResistRate
	elseif  Id == BASEATTR_INTERRUPTHITRATE then
		return self.m_InterruptHitRate
	elseif  Id == BASEATTR_INTERRUPTRESISTRATE then
		return self.m_InterruptResistRate
	elseif  Id == BASEATTR_UNCURABLEHITRATE then
		return self.m_UncurableHitRate
	elseif  Id == BASEATTR_UNCURABLERESISTRATE then
		return self.m_UncurableResistRate
	elseif  Id == BASEATTR_TRANSFORM then
		return self.m_Transform
	elseif  Id == BASEATTR_HUMANHURTRATE then
		return self.m_HumanHurtRate
	elseif  Id == BASEATTR_HUMANSUFFERRATE then
		return self.m_HumanSufferRate
	elseif  Id == BASEATTR_MONSTERHURTRATE then
		return self.m_MonsterHurtRate
	elseif  Id == BASEATTR_MONSTERSUFFERRATE then
		return self.m_MonsterSufferRate
	elseif  Id == BASEATTR_BOSSHURTRATE then
		return self.m_BossHurtRate
	elseif  Id == BASEATTR_BOSSSUFFERRATE then
		return self.m_BossSufferRate
	elseif  Id == BASEATTR_DODGREDUCEVALUE then
		return self.m_DodgReduceValue
	elseif  Id == BASEATTR_DODGREDUCERATE then
		return self.m_DodgReduceRate
	elseif  Id == BASEATTR_DODGADDVALUE then
		return self.m_DodgAddValue
	elseif  Id == BASEATTR_DODGADDRATE then
		return self.m_DodgAddRate
	elseif  Id == BASEATTR_TREASUREFOOTPRINT then
		return self.m_TreasureFootPrint
	elseif  Id == BASEATTR_EQUIPTITLE then
		return self.m_EquipTitle
	elseif  Id == BASEATTR_OBJANIMEVENT then
		if Index<0 then
			return self.m_ObjAnimEvent
		else
			return self.m_ObjAnimEvent[Index]
		end
	elseif  Id == BASEATTR_PINCHDATA then
		return  self.m_PinchData
	elseif  Id == BASEATTR_SKILLCDRATE then
		return self.m_SkillCDRate
	elseif  Id == BASEATTR_ASPDRATE then
		return self.m_AspdRate
	elseif  Id == BASEATTR_SHIELD then
		return self.m_Shield
	elseif  Id == BASEATTR_EVENTLEFTCOUNT then
		return self.m_EventLeftCount
	elseif  Id == BASEATTR_CANNOTRUSH then
		return self.m_CanNotRush
	elseif  Id == BASEATTR_HUNTPOINT then
		return self.m_HuntPoint
	elseif  Id == BASEATTR_HUNTHIGHTIMES then
		return self.m_HuntHighTimes
	elseif  Id == BASEATTR_HUNTFIREPOINT then
		return self.m_HuntFirePoint
	elseif  Id == BASEATTR_STARBATTLESTATE then
		return self.m_Starbattlestate
	elseif  Id == BASEATTR_IGNOREMOTIONBLOCK then
		return self.m_IgnoreMotionBlock
	elseif  Id == BASEATTR_ENABLEINTERACT then
		return self.m_EnableInteract
	elseif  Id == BASEATTR_WORLDMEDAL then
		return self.m_WorldMedal
	elseif  Id == BASEATTR_CURECEILING then
		return self.m_CureCeiling
	elseif  Id == BASEATTR_RELATIONUNIONCURRENCY then
		return self.m_RelationUnionCurrency
	elseif  Id == BASEATTR_GUILDSHORTNAME then
		return  self.m_GuildShortName
	elseif  Id == BASEATTR_GUILDSHORTCOLORID then
		return self.m_GuildShortColorID
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

