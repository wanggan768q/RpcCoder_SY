--将变量写入下方
local ModuleId = 7;
local RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 751
local RPC_CODE_BASEATTR_SYNC_NOTIFY = 752;


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


require("3rd/pblua/BaseAttrV1Data_pb")
local BaseAttrV1Data_pb = BaseAttrV1Data_pb

require("app.BaseAttr.BaseAttrRpc_pb")

BaseAttrModel = class("BaseAttrModel",BaseModel)

function BaseAttrModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BaseAttrModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function BaseAttrModel:ctor()
	BaseAttrModel.super.ctor(self)
	self.rpc_pb = BaseAttrRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
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


end

-- 更新数据
function BaseAttrModel:UpdateField(Id, data, Index, len)
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
	if ret_msg:HasField('Spirit') then
		oldData.Spirit = ret_msg.Spirit
		if isForceUpdate == true then
			self.m_Spirit = ret_msg.Spirit
		end
		if isNotify == true then
			self.m_Spirit = ret_msg.Spirit
			dataCallback(self,BASEATTR_SPIRIT,ret_msg.Spirit)
		end
		if main.OnUpdateField ~= nil then
			main:OnUpdateField(BASEATTR_SPIRIT,ret_msg.Spirit)
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

	
	self:dataCallback(Id,Index)
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
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[BaseAttr => SyncData ]")
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





askList.BaseAttr = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = BaseAttrModel.SyncData
t.pb = BaseAttrRpc_pb.BaseAttrRpcSyncDataAsk()
table.insert(askList.BaseAttr,t)

