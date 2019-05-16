ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcSyncNotifyCB = null

SYNCID_EXP = 701  #经验
SYNCID_LEVEL = 703  #玩家等级
SYNCID_SERVERTIME = 704  #服务器时间
SYNCID_ROLEID = 705  #人物唯一ID
SYNCID_STRENGTH = 707  #力量
SYNCID_AGILITY = 708  #敏捷
SYNCID_INTELLECTUAL = 709  #智力
SYNCID_ENDURANCE = 710  #耐力
SYNCID_SPIRIT = 711  #精神
SYNCID_HP = 712  #生命值
SYNCID_MAXHP = 714  #生命值
SYNCID_PHYSICATTACK = 715  #物理攻击
SYNCID_PHYSICDEFENSE = 716  #物理防御
SYNCID_MAGICATTACK = 719  #魔法攻击
SYNCID_MAGICDEFENSE = 720  #魔法防御
SYNCID_HIT = 721  #命中值
SYNCID_HITRATE = 722  #命中率
SYNCID_MISS = 723  #闪避值
SYNCID_MISSRATE = 724  #闪避率
SYNCID_CRITICAL = 725  #暴击值
SYNCID_CRITICALRATE = 726  #暴击率
SYNCID_TENACITY = 727  #韧性值
SYNCID_TENACITYRATE = 728  #韧性率
SYNCID_PENET = 729  #穿透值
SYNCID_PENETRATE = 730  #穿透率
SYNCID_DODG = 731  #格挡值
SYNCID_DODGRATE = 732  #格挡率
SYNCID_CRITICALADDITION = 733  #暴击加伤值
SYNCID_CRITICALADDITIONRATE = 734  #暴击加伤率
SYNCID_CRITICALIMMUNE = 735  #暴击免伤
SYNCID_CRITICALIMMUNERATE = 736  #暴击免伤率
SYNCID_MISSLEVEL = 737  #闪避等级
SYNCID_CRITICALLEVEL = 738  #暴击等级
SYNCID_DODGLEVEL = 739  #格挡等级
SYNCID_MOVESPEED = 740  #移动速度
SYNCID_DIZZYSTATE = 741  #眩晕状态
SYNCID_GODSTATE = 742  #霸体状态
SYNCID_CANTMOVESTATE = 743  #不能移动状态
SYNCID_PHYSICADDITION = 745  #物理加伤值
SYNCID_MAGICADDITION = 746  #魔法加伤值
SYNCID_PHYSICOPPOSE = 747  #物理抗性
SYNCID_MAGICOPPOSE = 748  #魔法抗性
SYNCID_ACCUMULATESKIENERGY = 750  #技能积攒能量使用 目前只有应激技能用
SYNCID_NICKNAME = 751  #名字昵称
SYNCID_CONFIGID = 752  #config id
SYNCID_OBJTYPE = 753  #类型
SYNCID_STATE = 754  #EventObjStatu
SYNCID_OWNEROBJID = 755  #归属obj ID
SYNCID_CAMP = 756  #阵营
SYNCID_SILVERMONEY = 757  #银币
SYNCID_GOLDMONEY = 758  #金币
SYNCID_DIAMONDMONEY = 759  #钻石
SYNCID_BINDINGDIAMONDMONEY = 760  #绑定钻石
SYNCID_BATTLESCORE = 761  #战力
SYNCID_ENERGY = 762  #精力
SYNCID_GUILDMONEY = 763  #公会资金
SYNCID_SKILLLIST = 764  #技能列表
SYNCID_HONORMONEY = 765  #HonorMoney
SYNCID_RESOURCEPOOLHP = 766  #资源池
SYNCID_ATTACKADD = 767  #伤害增加
SYNCID_INJURYADD = 768  #伤害减免
SYNCID_FROZENSTATE = 769  #冰冻状态
SYNCID_SILENTSTATE = 770  #沉默状态
SYNCID_GUILDCONTRIBUTEHISTORYMAX = 772  #GuildContributeHistoryMax
SYNCID_TEAMID = 774  #队伍id
SYNCID_TREASUREHAIR = 775  #头发时装ID
SYNCID_TREASUREHEAD = 776  #头部时装ID
SYNCID_TREASUREBODY = 777  #身体时装
SYNCID_TREASUREWEAPON = 778  #武器时装
SYNCID_TREASUREWING = 779  #翅膀时装
SYNCID_GUILDGUID = 780  #公会ID
SYNCID_TREASURERIDING = 781  #坐骑
SYNCID_VECHICLEID = 782  #载具Id
SYNCID_ANIMATIONSTATE = 783  #动画状态
SYNCID_REFIXDMGRATE = 784  #修正攻击者最终伤害比率
SYNCID_REFIXDMGVALUE = 785  #修正攻击者最终伤害值
SYNCID_REFIXHURTRATE = 786  #修正被攻击者最终伤害比率
SYNCID_REFIXHURTVALUE = 787  #修正被攻击者最终伤害值
SYNCID_REFIXHEALRATE = 788  #修正治疗者最终比例
SYNCID_REFIXHEALVALUE = 789  #修正治疗者最终值
SYNCID_REFIXCUREDRATE = 790  #修正被治疗者最终比例
SYNCID_REFIXCUREDVALUE = 791  #修正被治疗者最终值
SYNCID_GUILDCONTRIBUTE = 792  #公会帮贡
SYNCID_PVPMONEY = 793  #竞技场点数
SYNCID_GUILDRESOURCE = 794  #公会资源
SYNCID_CREATEROLETIME = 795  #创建角色时间戳
SYNCID_UPDATEROLETIME = 796  #更新角色等级时间戳
SYNCID_FIGHTSTATE = 797  #战斗状态
SYNCID_ATTACKSKILLLIST = 798  #普攻技能列表
SYNCID_GUILDNAME = 799  #公会名称
SYNCID_ISALLOWSELECT = 800  #是否可选中
SYNCID_GOHOMESTATE = 801  #怪物回归中
SYNCID_CANFIGHT = 802  #怪物是否可攻击
SYNCID_DOUBLEEXP = 803  #双倍经验
SYNCID_FRIENDPOINT = 804  #友情点
SYNCID_HISMAXHONOR = 805  #历史最大荣誉点
SYNCID_HURTSTATE = 806  #受击状态
SYNCID_HURTFLYSTATE = 807  #击飞状态
SYNCID_HURTDOWNSTATE = 808  #击倒状态
SYNCID_HURTREPELSTATE = 809  #击退
SYNCID_TODAYHORNOR = 811  #今日获得的荣誉值
SYNCID_MILITARYMONEY = 812  #军衔值
m_Exp = 0
m_Level = 0
m_ServerTime = 0
m_RoleId = 0
m_Strength = 0
m_Agility = 0
m_Intellectual = 0
m_Endurance = 0
m_Spirit = 0
m_Hp = 0
m_MaxHp = 0
m_PhysicAttack = 0
m_PhysicDefense = 0
m_MagicAttack = 0
m_MagicDefense = 0
m_Hit = 0
m_HitRate = null
m_Miss = 0
m_MissRate = null
m_Critical = 0
m_CriticalRate = null
m_Tenacity = 0
m_TenacityRate = null
m_Penet = 0
m_PenetRate = null
m_Dodg = 0
m_DodgRate = null
m_CriticalAddition = 0
m_CriticalAdditionRate = null
m_CriticalImmune = 0
m_CriticalImmuneRate = null
m_MissLevel = 0
m_CriticalLevel = 0
m_DodgLevel = 0
m_MoveSpeed = null
m_DizzyState = 0
m_GodState = null
m_CantMoveState = 0
m_PhysicAddition = null
m_MagicAddition = null
m_PhysicOppose = null
m_MagicOppose = null
m_AccumulateSkiEnergy = null
m_NickName = ""
m_ConfigId = 0
m_ObjType = 0
m_State = 0
m_OwnerObjId = 0
m_Camp = 0
m_SilverMoney = 0
m_GoldMoney = 0
m_DiamondMoney = 0
m_BindingDiamondMoney = 0
m_BattleScore = 0
m_Energy = 0
m_GuildMoney = 0
m_SkillList = []
m_HonorMoney = 0
m_ResourcePoolHp = 0
m_AttackAdd = 0
m_InjuryAdd = 0
m_FrozenState = 0
m_SilentState = 0
m_GuildContributeHistoryMax = 0
m_TeamId = 0
m_TreasureHair = 0
m_TreasureHead = 0
m_TreasureBody = 0
m_TreasureWeapon = 0
m_TreasureWing = 0
m_GuildGuid = 0
m_TreasureRiding = 0
m_VechicleId = 0
m_AnimationState = null
m_RefixDmgRate = null
m_RefixDmgValue = 0
m_RefixHurtRate = null
m_RefixHurtValue = 0
m_RefixHealRate = null
m_RefixHealValue = 0
m_RefixCuredRate = null
m_RefixCuredValue = 0
m_GuildContribute = 0
m_PvpMoney = 0
m_GuildResource = 0
m_CreateRoleTime = 0
m_UpdateRoleTime = 0
m_FightState = null
m_AttackSkillList = []
m_GuildName = ""
m_IsAllowSelect = null
m_GoHomeState = null
m_CanFight = null
m_DoubleExp = 0
m_FriendPoint = 0
m_HisMaxHonor = 0
m_HurtState = null
m_HurtFlyState = null
m_HurtDownState = null
m_HurtRepelState = null
m_TodayHornor = 0
m_MilitaryMoney = 0
UserDataV1PB = null

ModuleId = 7
RPC_CODE_SYNCDATA_REQUEST = 751
RPC_CODE_SYNC_NOTIFY = 752

SyncDataAskPB = null
SyncDataReplyPB = null
SyncNotifyPB = null
UserDataV1PB = null

class BaseAttrModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcSyncDataAsk
      {
      }
      message  RpcSyncDataReply
      {
        optional int32 Result = 1[default=-9999];
        optional bytes UpdateData = 2;
      }
      message  RpcSyncNotify
      {
        optional int32 ObjId = 2[default=-1];
        optional bytes UpdateData = 3;
      }
      message  UserDataV1
      {
        optional int32 Exp = 1[default=0];
        optional int32 Level = 3[default=0];
        optional int64 ServerTime = 4[default=-1];
        optional uint64 RoleId = 5[default=0];
        optional int32 Strength = 7[default=0];
        optional int32 Agility = 8[default=0];
        optional int32 Intellectual = 9[default=0];
        optional int32 Endurance = 10[default=0];
        optional int32 Spirit = 11[default=0];
        optional int32 Hp = 12[default=0];
        optional int32 MaxHp = 14[default=0];
        optional int32 PhysicAttack = 15[default=0];
        optional int32 PhysicDefense = 16[default=0];
        optional int32 MagicAttack = 19[default=0];
        optional int32 MagicDefense = 20[default=0];
        optional int32 Hit = 21[default=0];
        optional float HitRate = 22;
        optional int32 Miss = 23[default=0];
        optional float MissRate = 24;
        optional int32 Critical = 25[default=0];
        optional float CriticalRate = 26;
        optional int32 Tenacity = 27[default=0];
        optional float TenacityRate = 28;
        optional int32 Penet = 29[default=0];
        optional float PenetRate = 30;
        optional int32 Dodg = 31[default=0];
        optional float DodgRate = 32;
        optional int32 CriticalAddition = 33[default=0];
        optional float CriticalAdditionRate = 34;
        optional int32 CriticalImmune = 35[default=0];
        optional float CriticalImmuneRate = 36;
        optional int32 MissLevel = 37[default=0];
        optional int32 CriticalLevel = 38[default=0];
        optional int32 DodgLevel = 39[default=0];
        optional float MoveSpeed = 40;
        optional int32 DizzyState = 41[default=0];
        optional bool GodState = 42;
        optional int32 CantMoveState = 43[default=0];
        optional float PhysicAddition = 45;
        optional float MagicAddition = 46;
        optional float PhysicOppose = 47;
        optional float MagicOppose = 48;
        optional float AccumulateSkiEnergy = 50;
        optional string NickName = 51;
        optional int32 ConfigId = 52[default=-1];
        optional int32 ObjType = 53[default=-1];
        optional int32 State = 54[default=-1];
        optional int32 OwnerObjId = 55[default=-1];
        optional int32 Camp = 56[default=-1];
        optional int64 SilverMoney = 57[default=0];
        optional int64 GoldMoney = 58[default=0];
        optional int64 DiamondMoney = 59[default=0];
        optional int64 BindingDiamondMoney = 60[default=0];
        optional int32 BattleScore = 61[default=-1];
        optional int64 Energy = 62[default=-1];
        optional int64 GuildMoney = 63[default=-1];
        repeated int32 SkillList = 64;
        optional int64 HonorMoney = 65[default=-1];
        optional int64 ResourcePoolHp = 66[default=-1];
        optional int32 AttackAdd = 67[default=0];
        optional int32 InjuryAdd = 68[default=0];
        optional int32 FrozenState = 69[default=-1];
        optional int32 SilentState = 70[default=-1];
        optional int64 GuildContributeHistoryMax = 72[default=-1];
        optional uint64 TeamId = 74[default=0];
        optional int32 TreasureHair = 75[default=-1];
        optional int32 TreasureHead = 76[default=-1];
        optional int32 TreasureBody = 77[default=-1];
        optional int32 TreasureWeapon = 78[default=-1];
        optional int32 TreasureWing = 79[default=-1];
        optional uint64 GuildGuid = 80[default=0];
        optional int32 TreasureRiding = 81[default=-1];
        optional int32 VechicleId = 82[default=-1];
        optional bool AnimationState = 83;
        optional float RefixDmgRate = 84;
        optional int32 RefixDmgValue = 85[default=0];
        optional float RefixHurtRate = 86;
        optional int32 RefixHurtValue = 87[default=0];
        optional float RefixHealRate = 88;
        optional int32 RefixHealValue = 89[default=0];
        optional float RefixCuredRate = 90;
        optional int32 RefixCuredValue = 91[default=0];
        optional int64 GuildContribute = 92[default=-1];
        optional int64 PvpMoney = 93[default=-1];
        optional int64 GuildResource = 94[default=-1];
        optional int32 CreateRoleTime = 95[default=0];
        optional int32 UpdateRoleTime = 96[default=0];
        optional bool FightState = 97;
        repeated int32 AttackSkillList = 98;
        optional string GuildName = 99;
        optional bool IsAllowSelect = 100;
        optional bool GoHomeState = 101;
        optional bool CanFight = 102;
        optional int64 DoubleExp = 103[default=-1];
        optional int64 FriendPoint = 104[default=-1];
        optional int64 HisMaxHonor = 105[default=-1];
        optional bool HurtState = 106;
        optional bool HurtFlyState = 107;
        optional bool HurtDownState = 108;
        optional bool HurtRepelState = 109;
        optional int64 TodayHornor = 111[default=-1];
        optional int64 MilitaryMoney = 112[default=-1];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    SyncDataAskPB = Proto.build("RpcSyncDataAsk")
    SyncDataReplyPB = Proto.build("RpcSyncDataReply")
    SyncNotifyPB = Proto.build("RpcSyncNotify")
    mLayerMgr.registerNotify(RPC_CODE_SYNC_NOTIFY,@SyncCB)
    UserDataV1PB = Proto.build("RpcUserDataV1")




  SyncID_Exp : () -> return SYNCID_EXP
  SyncID_Level : () -> return SYNCID_LEVEL
  SyncID_ServerTime : () -> return SYNCID_SERVERTIME
  SyncID_RoleId : () -> return SYNCID_ROLEID
  SyncID_Strength : () -> return SYNCID_STRENGTH
  SyncID_Agility : () -> return SYNCID_AGILITY
  SyncID_Intellectual : () -> return SYNCID_INTELLECTUAL
  SyncID_Endurance : () -> return SYNCID_ENDURANCE
  SyncID_Spirit : () -> return SYNCID_SPIRIT
  SyncID_Hp : () -> return SYNCID_HP
  SyncID_MaxHp : () -> return SYNCID_MAXHP
  SyncID_PhysicAttack : () -> return SYNCID_PHYSICATTACK
  SyncID_PhysicDefense : () -> return SYNCID_PHYSICDEFENSE
  SyncID_MagicAttack : () -> return SYNCID_MAGICATTACK
  SyncID_MagicDefense : () -> return SYNCID_MAGICDEFENSE
  SyncID_Hit : () -> return SYNCID_HIT
  SyncID_HitRate : () -> return SYNCID_HITRATE
  SyncID_Miss : () -> return SYNCID_MISS
  SyncID_MissRate : () -> return SYNCID_MISSRATE
  SyncID_Critical : () -> return SYNCID_CRITICAL
  SyncID_CriticalRate : () -> return SYNCID_CRITICALRATE
  SyncID_Tenacity : () -> return SYNCID_TENACITY
  SyncID_TenacityRate : () -> return SYNCID_TENACITYRATE
  SyncID_Penet : () -> return SYNCID_PENET
  SyncID_PenetRate : () -> return SYNCID_PENETRATE
  SyncID_Dodg : () -> return SYNCID_DODG
  SyncID_DodgRate : () -> return SYNCID_DODGRATE
  SyncID_CriticalAddition : () -> return SYNCID_CRITICALADDITION
  SyncID_CriticalAdditionRate : () -> return SYNCID_CRITICALADDITIONRATE
  SyncID_CriticalImmune : () -> return SYNCID_CRITICALIMMUNE
  SyncID_CriticalImmuneRate : () -> return SYNCID_CRITICALIMMUNERATE
  SyncID_MissLevel : () -> return SYNCID_MISSLEVEL
  SyncID_CriticalLevel : () -> return SYNCID_CRITICALLEVEL
  SyncID_DodgLevel : () -> return SYNCID_DODGLEVEL
  SyncID_MoveSpeed : () -> return SYNCID_MOVESPEED
  SyncID_DizzyState : () -> return SYNCID_DIZZYSTATE
  SyncID_GodState : () -> return SYNCID_GODSTATE
  SyncID_CantMoveState : () -> return SYNCID_CANTMOVESTATE
  SyncID_PhysicAddition : () -> return SYNCID_PHYSICADDITION
  SyncID_MagicAddition : () -> return SYNCID_MAGICADDITION
  SyncID_PhysicOppose : () -> return SYNCID_PHYSICOPPOSE
  SyncID_MagicOppose : () -> return SYNCID_MAGICOPPOSE
  SyncID_AccumulateSkiEnergy : () -> return SYNCID_ACCUMULATESKIENERGY
  SyncID_NickName : () -> return SYNCID_NICKNAME
  SyncID_ConfigId : () -> return SYNCID_CONFIGID
  SyncID_ObjType : () -> return SYNCID_OBJTYPE
  SyncID_State : () -> return SYNCID_STATE
  SyncID_OwnerObjId : () -> return SYNCID_OWNEROBJID
  SyncID_Camp : () -> return SYNCID_CAMP
  SyncID_SilverMoney : () -> return SYNCID_SILVERMONEY
  SyncID_GoldMoney : () -> return SYNCID_GOLDMONEY
  SyncID_DiamondMoney : () -> return SYNCID_DIAMONDMONEY
  SyncID_BindingDiamondMoney : () -> return SYNCID_BINDINGDIAMONDMONEY
  SyncID_BattleScore : () -> return SYNCID_BATTLESCORE
  SyncID_Energy : () -> return SYNCID_ENERGY
  SyncID_GuildMoney : () -> return SYNCID_GUILDMONEY
  SyncID_SkillList : () -> return SYNCID_SKILLLIST
  SyncID_HonorMoney : () -> return SYNCID_HONORMONEY
  SyncID_ResourcePoolHp : () -> return SYNCID_RESOURCEPOOLHP
  SyncID_AttackAdd : () -> return SYNCID_ATTACKADD
  SyncID_InjuryAdd : () -> return SYNCID_INJURYADD
  SyncID_FrozenState : () -> return SYNCID_FROZENSTATE
  SyncID_SilentState : () -> return SYNCID_SILENTSTATE
  SyncID_GuildContributeHistoryMax : () -> return SYNCID_GUILDCONTRIBUTEHISTORYMAX
  SyncID_TeamId : () -> return SYNCID_TEAMID
  SyncID_TreasureHair : () -> return SYNCID_TREASUREHAIR
  SyncID_TreasureHead : () -> return SYNCID_TREASUREHEAD
  SyncID_TreasureBody : () -> return SYNCID_TREASUREBODY
  SyncID_TreasureWeapon : () -> return SYNCID_TREASUREWEAPON
  SyncID_TreasureWing : () -> return SYNCID_TREASUREWING
  SyncID_GuildGuid : () -> return SYNCID_GUILDGUID
  SyncID_TreasureRiding : () -> return SYNCID_TREASURERIDING
  SyncID_VechicleId : () -> return SYNCID_VECHICLEID
  SyncID_AnimationState : () -> return SYNCID_ANIMATIONSTATE
  SyncID_RefixDmgRate : () -> return SYNCID_REFIXDMGRATE
  SyncID_RefixDmgValue : () -> return SYNCID_REFIXDMGVALUE
  SyncID_RefixHurtRate : () -> return SYNCID_REFIXHURTRATE
  SyncID_RefixHurtValue : () -> return SYNCID_REFIXHURTVALUE
  SyncID_RefixHealRate : () -> return SYNCID_REFIXHEALRATE
  SyncID_RefixHealValue : () -> return SYNCID_REFIXHEALVALUE
  SyncID_RefixCuredRate : () -> return SYNCID_REFIXCUREDRATE
  SyncID_RefixCuredValue : () -> return SYNCID_REFIXCUREDVALUE
  SyncID_GuildContribute : () -> return SYNCID_GUILDCONTRIBUTE
  SyncID_PvpMoney : () -> return SYNCID_PVPMONEY
  SyncID_GuildResource : () -> return SYNCID_GUILDRESOURCE
  SyncID_CreateRoleTime : () -> return SYNCID_CREATEROLETIME
  SyncID_UpdateRoleTime : () -> return SYNCID_UPDATEROLETIME
  SyncID_FightState : () -> return SYNCID_FIGHTSTATE
  SyncID_AttackSkillList : () -> return SYNCID_ATTACKSKILLLIST
  SyncID_GuildName : () -> return SYNCID_GUILDNAME
  SyncID_IsAllowSelect : () -> return SYNCID_ISALLOWSELECT
  SyncID_GoHomeState : () -> return SYNCID_GOHOMESTATE
  SyncID_CanFight : () -> return SYNCID_CANFIGHT
  SyncID_DoubleExp : () -> return SYNCID_DOUBLEEXP
  SyncID_FriendPoint : () -> return SYNCID_FRIENDPOINT
  SyncID_HisMaxHonor : () -> return SYNCID_HISMAXHONOR
  SyncID_HurtState : () -> return SYNCID_HURTSTATE
  SyncID_HurtFlyState : () -> return SYNCID_HURTFLYSTATE
  SyncID_HurtDownState : () -> return SYNCID_HURTDOWNSTATE
  SyncID_HurtRepelState : () -> return SYNCID_HURTREPELSTATE
  SyncID_TodayHornor : () -> return SYNCID_TODAYHORNOR
  SyncID_MilitaryMoney : () -> return SYNCID_MILITARYMONEY
  Exp : () -> return m_Exp
  Level : () -> return m_Level
  ServerTime : () -> return m_ServerTime
  RoleId : () -> return m_RoleId
  Strength : () -> return m_Strength
  Agility : () -> return m_Agility
  Intellectual : () -> return m_Intellectual
  Endurance : () -> return m_Endurance
  Spirit : () -> return m_Spirit
  Hp : () -> return m_Hp
  MaxHp : () -> return m_MaxHp
  PhysicAttack : () -> return m_PhysicAttack
  PhysicDefense : () -> return m_PhysicDefense
  MagicAttack : () -> return m_MagicAttack
  MagicDefense : () -> return m_MagicDefense
  Hit : () -> return m_Hit
  HitRate : () -> return m_HitRate
  Miss : () -> return m_Miss
  MissRate : () -> return m_MissRate
  Critical : () -> return m_Critical
  CriticalRate : () -> return m_CriticalRate
  Tenacity : () -> return m_Tenacity
  TenacityRate : () -> return m_TenacityRate
  Penet : () -> return m_Penet
  PenetRate : () -> return m_PenetRate
  Dodg : () -> return m_Dodg
  DodgRate : () -> return m_DodgRate
  CriticalAddition : () -> return m_CriticalAddition
  CriticalAdditionRate : () -> return m_CriticalAdditionRate
  CriticalImmune : () -> return m_CriticalImmune
  CriticalImmuneRate : () -> return m_CriticalImmuneRate
  MissLevel : () -> return m_MissLevel
  CriticalLevel : () -> return m_CriticalLevel
  DodgLevel : () -> return m_DodgLevel
  MoveSpeed : () -> return m_MoveSpeed
  DizzyState : () -> return m_DizzyState
  GodState : () -> return m_GodState
  CantMoveState : () -> return m_CantMoveState
  PhysicAddition : () -> return m_PhysicAddition
  MagicAddition : () -> return m_MagicAddition
  PhysicOppose : () -> return m_PhysicOppose
  MagicOppose : () -> return m_MagicOppose
  AccumulateSkiEnergy : () -> return m_AccumulateSkiEnergy
  NickName : () -> return m_NickName
  ConfigId : () -> return m_ConfigId
  ObjType : () -> return m_ObjType
  State : () -> return m_State
  OwnerObjId : () -> return m_OwnerObjId
  Camp : () -> return m_Camp
  SilverMoney : () -> return m_SilverMoney
  GoldMoney : () -> return m_GoldMoney
  DiamondMoney : () -> return m_DiamondMoney
  BindingDiamondMoney : () -> return m_BindingDiamondMoney
  BattleScore : () -> return m_BattleScore
  Energy : () -> return m_Energy
  GuildMoney : () -> return m_GuildMoney
  SkillList : () -> return m_SkillList
  HonorMoney : () -> return m_HonorMoney
  ResourcePoolHp : () -> return m_ResourcePoolHp
  AttackAdd : () -> return m_AttackAdd
  InjuryAdd : () -> return m_InjuryAdd
  FrozenState : () -> return m_FrozenState
  SilentState : () -> return m_SilentState
  GuildContributeHistoryMax : () -> return m_GuildContributeHistoryMax
  TeamId : () -> return m_TeamId
  TreasureHair : () -> return m_TreasureHair
  TreasureHead : () -> return m_TreasureHead
  TreasureBody : () -> return m_TreasureBody
  TreasureWeapon : () -> return m_TreasureWeapon
  TreasureWing : () -> return m_TreasureWing
  GuildGuid : () -> return m_GuildGuid
  TreasureRiding : () -> return m_TreasureRiding
  VechicleId : () -> return m_VechicleId
  AnimationState : () -> return m_AnimationState
  RefixDmgRate : () -> return m_RefixDmgRate
  RefixDmgValue : () -> return m_RefixDmgValue
  RefixHurtRate : () -> return m_RefixHurtRate
  RefixHurtValue : () -> return m_RefixHurtValue
  RefixHealRate : () -> return m_RefixHealRate
  RefixHealValue : () -> return m_RefixHealValue
  RefixCuredRate : () -> return m_RefixCuredRate
  RefixCuredValue : () -> return m_RefixCuredValue
  GuildContribute : () -> return m_GuildContribute
  PvpMoney : () -> return m_PvpMoney
  GuildResource : () -> return m_GuildResource
  CreateRoleTime : () -> return m_CreateRoleTime
  UpdateRoleTime : () -> return m_UpdateRoleTime
  FightState : () -> return m_FightState
  AttackSkillList : () -> return m_AttackSkillList
  GuildName : () -> return m_GuildName
  IsAllowSelect : () -> return m_IsAllowSelect
  GoHomeState : () -> return m_GoHomeState
  CanFight : () -> return m_CanFight
  DoubleExp : () -> return m_DoubleExp
  FriendPoint : () -> return m_FriendPoint
  HisMaxHonor : () -> return m_HisMaxHonor
  HurtState : () -> return m_HurtState
  HurtFlyState : () -> return m_HurtFlyState
  HurtDownState : () -> return m_HurtDownState
  HurtRepelState : () -> return m_HurtRepelState
  TodayHornor : () -> return m_TodayHornor
  MilitaryMoney : () -> return m_MilitaryMoney


  SyncData : (replyCB) ->
    SyncDataAsk = SyncDataAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCDATA_REQUEST,SyncDataAsk, (data)->
      replyCB( SyncDataReplyPB.decode(data)) if typeof(replyCB) is "function"
    )


  updateDataField : (SyncId,Index,Data,dataLen)->
    switch SyncId
      when SYNCID_EXP
        m_Exp = Data.readVarint32ZigZag()
      when SYNCID_LEVEL
        m_Level = Data.readVarint32ZigZag()
      when SYNCID_SERVERTIME
        m_ServerTime = Data.readVarint64ZigZag().toNumber()
      when SYNCID_ROLEID
        m_RoleId = Data.readVarint64ZigZag().toNumber()
      when SYNCID_STRENGTH
        m_Strength = Data.readVarint32ZigZag()
      when SYNCID_AGILITY
        m_Agility = Data.readVarint32ZigZag()
      when SYNCID_INTELLECTUAL
        m_Intellectual = Data.readVarint32ZigZag()
      when SYNCID_ENDURANCE
        m_Endurance = Data.readVarint32ZigZag()
      when SYNCID_SPIRIT
        m_Spirit = Data.readVarint32ZigZag()
      when SYNCID_HP
        m_Hp = Data.readVarint32ZigZag()
      when SYNCID_MAXHP
        m_MaxHp = Data.readVarint32ZigZag()
      when SYNCID_PHYSICATTACK
        m_PhysicAttack = Data.readVarint32ZigZag()
      when SYNCID_PHYSICDEFENSE
        m_PhysicDefense = Data.readVarint32ZigZag()
      when SYNCID_MAGICATTACK
        m_MagicAttack = Data.readVarint32ZigZag()
      when SYNCID_MAGICDEFENSE
        m_MagicDefense = Data.readVarint32ZigZag()
      when SYNCID_HIT
        m_Hit = Data.readVarint32ZigZag()
      when SYNCID_HITRATE
        m_HitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MISS
        m_Miss = Data.readVarint32ZigZag()
      when SYNCID_MISSRATE
        m_MissRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_CRITICAL
        m_Critical = Data.readVarint32ZigZag()
      when SYNCID_CRITICALRATE
        m_CriticalRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_TENACITY
        m_Tenacity = Data.readVarint32ZigZag()
      when SYNCID_TENACITYRATE
        m_TenacityRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_PENET
        m_Penet = Data.readVarint32ZigZag()
      when SYNCID_PENETRATE
        m_PenetRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DODG
        m_Dodg = Data.readVarint32ZigZag()
      when SYNCID_DODGRATE
        m_DodgRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_CRITICALADDITION
        m_CriticalAddition = Data.readVarint32ZigZag()
      when SYNCID_CRITICALADDITIONRATE
        m_CriticalAdditionRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_CRITICALIMMUNE
        m_CriticalImmune = Data.readVarint32ZigZag()
      when SYNCID_CRITICALIMMUNERATE
        m_CriticalImmuneRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MISSLEVEL
        m_MissLevel = Data.readVarint32ZigZag()
      when SYNCID_CRITICALLEVEL
        m_CriticalLevel = Data.readVarint32ZigZag()
      when SYNCID_DODGLEVEL
        m_DodgLevel = Data.readVarint32ZigZag()
      when SYNCID_MOVESPEED
        m_MoveSpeed = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DIZZYSTATE
        m_DizzyState = Data.readVarint32ZigZag()
      when SYNCID_GODSTATE
        m_GodState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_CANTMOVESTATE
        m_CantMoveState = Data.readVarint32ZigZag()
      when SYNCID_PHYSICADDITION
        m_PhysicAddition = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MAGICADDITION
        m_MagicAddition = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_PHYSICOPPOSE
        m_PhysicOppose = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MAGICOPPOSE
        m_MagicOppose = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_ACCUMULATESKIENERGY
        m_AccumulateSkiEnergy = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_NICKNAME
        if dataLen is 0
          return
        m_NickName = Data.readUTF8StringBySelf(dataLen)
      when SYNCID_CONFIGID
        m_ConfigId = Data.readVarint32ZigZag()
      when SYNCID_OBJTYPE
        m_ObjType = Data.readVarint32ZigZag()
      when SYNCID_STATE
        m_State = Data.readVarint32ZigZag()
      when SYNCID_OWNEROBJID
        m_OwnerObjId = Data.readVarint32ZigZag()
      when SYNCID_CAMP
        m_Camp = Data.readVarint32ZigZag()
      when SYNCID_SILVERMONEY
        m_SilverMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_GOLDMONEY
        m_GoldMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_DIAMONDMONEY
        m_DiamondMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_BINDINGDIAMONDMONEY
        m_BindingDiamondMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_BATTLESCORE
        m_BattleScore = Data.readVarint32ZigZag()
      when SYNCID_ENERGY
        m_Energy = Data.readVarint64ZigZag().toNumber()
      when SYNCID_GUILDMONEY
        m_GuildMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_SKILLLIST
        if Index is -1
          m_SkillList = []
          return
        m_SkillList[Index] = Data.readVarint32ZigZag()
      when SYNCID_HONORMONEY
        m_HonorMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_RESOURCEPOOLHP
        m_ResourcePoolHp = Data.readVarint64ZigZag().toNumber()
      when SYNCID_ATTACKADD
        m_AttackAdd = Data.readVarint32ZigZag()
      when SYNCID_INJURYADD
        m_InjuryAdd = Data.readVarint32ZigZag()
      when SYNCID_FROZENSTATE
        m_FrozenState = Data.readVarint32ZigZag()
      when SYNCID_SILENTSTATE
        m_SilentState = Data.readVarint32ZigZag()
      when SYNCID_GUILDCONTRIBUTEHISTORYMAX
        m_GuildContributeHistoryMax = Data.readVarint64ZigZag().toNumber()
      when SYNCID_TEAMID
        m_TeamId = Data.readVarint64ZigZag().toNumber()
      when SYNCID_TREASUREHAIR
        m_TreasureHair = Data.readVarint32ZigZag()
      when SYNCID_TREASUREHEAD
        m_TreasureHead = Data.readVarint32ZigZag()
      when SYNCID_TREASUREBODY
        m_TreasureBody = Data.readVarint32ZigZag()
      when SYNCID_TREASUREWEAPON
        m_TreasureWeapon = Data.readVarint32ZigZag()
      when SYNCID_TREASUREWING
        m_TreasureWing = Data.readVarint32ZigZag()
      when SYNCID_GUILDGUID
        m_GuildGuid = Data.readVarint64ZigZag().toNumber()
      when SYNCID_TREASURERIDING
        m_TreasureRiding = Data.readVarint32ZigZag()
      when SYNCID_VECHICLEID
        m_VechicleId = Data.readVarint32ZigZag()
      when SYNCID_ANIMATIONSTATE
        m_AnimationState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_REFIXDMGRATE
        m_RefixDmgRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_REFIXDMGVALUE
        m_RefixDmgValue = Data.readVarint32ZigZag()
      when SYNCID_REFIXHURTRATE
        m_RefixHurtRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_REFIXHURTVALUE
        m_RefixHurtValue = Data.readVarint32ZigZag()
      when SYNCID_REFIXHEALRATE
        m_RefixHealRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_REFIXHEALVALUE
        m_RefixHealValue = Data.readVarint32ZigZag()
      when SYNCID_REFIXCUREDRATE
        m_RefixCuredRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_REFIXCUREDVALUE
        m_RefixCuredValue = Data.readVarint32ZigZag()
      when SYNCID_GUILDCONTRIBUTE
        m_GuildContribute = Data.readVarint64ZigZag().toNumber()
      when SYNCID_PVPMONEY
        m_PvpMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_GUILDRESOURCE
        m_GuildResource = Data.readVarint64ZigZag().toNumber()
      when SYNCID_CREATEROLETIME
        m_CreateRoleTime = Data.readVarint32ZigZag()
      when SYNCID_UPDATEROLETIME
        m_UpdateRoleTime = Data.readVarint32ZigZag()
      when SYNCID_FIGHTSTATE
        m_FightState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_ATTACKSKILLLIST
        if Index is -1
          m_AttackSkillList = []
          return
        m_AttackSkillList[Index] = Data.readVarint32ZigZag()
      when SYNCID_GUILDNAME
        if dataLen is 0
          return
        m_GuildName = Data.readUTF8StringBySelf(dataLen)
      when SYNCID_ISALLOWSELECT
        m_IsAllowSelect = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_GOHOMESTATE
        m_GoHomeState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_CANFIGHT
        m_CanFight = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_DOUBLEEXP
        m_DoubleExp = Data.readVarint64ZigZag().toNumber()
      when SYNCID_FRIENDPOINT
        m_FriendPoint = Data.readVarint64ZigZag().toNumber()
      when SYNCID_HISMAXHONOR
        m_HisMaxHonor = Data.readVarint64ZigZag().toNumber()
      when SYNCID_HURTSTATE
        m_HurtState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_HURTFLYSTATE
        m_HurtFlyState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_HURTDOWNSTATE
        m_HurtDownState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_HURTREPELSTATE
        m_HurtRepelState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_TODAYHORNOR
        m_TodayHornor = Data.readVarint64ZigZag().toNumber()
      when SYNCID_MILITARYMONEY
        m_MilitaryMoney = Data.readVarint64ZigZag().toNumber()

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetSyncNotifyCB : (cb) -> RpcSyncNotifyCB = cb
  SyncCB : (data)->
    RpcSyncNotifyCB( SyncNotifyPB.decode(data)) if typeof(RpcSyncNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "BaseAttrModel",
      'AskName': ["SyncData"]
      'ParamterList': [[]]
      'AskList':[@SyncData]
      'ParamterTypelist': [[]]


module.exports =(()->
  if not BaseAttr?
    BaseAttr = new BaseAttrModel()
  BaseAttr)()



  

  

  


