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
SYNCID_CURPROFESSION = 813  #当前专精
SYNCID_PETCREATEDELCOND = 814  #宠物创建删除条件枚举
SYNCID_PETDISPLAY = 815  #宠物是否需要隐藏1显示0隐藏
SYNCID_PETMONEY = 816  #宠物货币
SYNCID_DUELSTATUS = 817  #决斗状态
SYNCID_EXPPOOL = 818  #经验池
SYNCID_RUSHSTATE = 819  #疾跑状态
SYNCID_STARESTATE = 820  #盯防状态
SYNCID_WORLDLEVEL = 821  #世界等级
SYNCID_DIZZYHITRATE = 822  #眩晕命中率
SYNCID_DIZZYRESISTRATE = 823  #眩晕抵抗率
SYNCID_IMMOVABLEHITRATE = 824  #定身命中率
SYNCID_IMMOVABLERESISTRATE = 825  #定身抵抗率
SYNCID_HURTFLYHITRATE = 826  #击飞命中率
SYNCID_HURTFLYRESISTRATE = 827  #击飞抵抗率
SYNCID_FROZENHITRATE = 828  #冰冻命中率
SYNCID_FROZENRESISTRATE = 829  #冰冻抵抗率
SYNCID_CLEANHITRATE = 830  #净化命中率
SYNCID_CLEANRESISTRATE = 831  #净化抵抗率
SYNCID_DISPELHITRATE = 832  #驱散命中率
SYNCID_DISPELRESISTRATE = 833  #驱散抵抗率
SYNCID_SILENCEHITRATE = 834  #沉默命中率
SYNCID_SILENCERESISTRATE = 835  #沉默抵抗率
SYNCID_INTERRUPTHITRATE = 836  #打断命中率
SYNCID_INTERRUPTRESISTRATE = 837  #打断抵抗率
SYNCID_UNCURABLEHITRATE = 838  #禁疗命中率
SYNCID_UNCURABLERESISTRATE = 839  #禁疗抵抗率
SYNCID_TRANSFORM = 840  #变身
SYNCID_HUMANHURTRATE = 841  #受到玩家目标伤害比
SYNCID_HUMANSUFFERRATE = 842  #针对玩家目标伤害比
SYNCID_MONSTERHURTRATE = 843  #受到怪物目标伤害比
SYNCID_MONSTERSUFFERRATE = 844  #针对怪物目标伤害比
SYNCID_BOSSHURTRATE = 845  #受到Boss目标伤害比
SYNCID_BOSSSUFFERRATE = 846  #针对Boss目标伤害比
SYNCID_DODGREDUCEVALUE = 847  #格挡减伤值
SYNCID_DODGREDUCERATE = 848  #格挡减伤率
SYNCID_DODGADDVALUE = 849  #格挡破伤值
SYNCID_DODGADDRATE = 850  #格挡破伤率
SYNCID_TREASUREFOOTPRINT = 851  #步尘
SYNCID_EQUIPTITLE = 852  #装备称号
SYNCID_OBJANIMEVENT = 853  #当前所在动画事件
SYNCID_PINCHDATA = 854  #捏脸数据
SYNCID_SKILLCDRATE = 855  #技能冷缩比例
SYNCID_ASPDRATE = 856  #攻速
SYNCID_SHIELD = 857  #护盾值
SYNCID_EVENTLEFTCOUNT = 858  #obj剩余采集次数
SYNCID_CANNOTRUSH = 859  #不能疾跑状态
SYNCID_HUNTPOINT = 860  #猎魔点数
SYNCID_HUNTHIGHTIMES = 861  #猎魔高倍
SYNCID_HUNTFIREPOINT = 862  #猎魔引燃次数
SYNCID_STARBATTLESTATE = 863  #星耀NPC状态(1可进入 2不可进入)
SYNCID_IGNOREMOTIONBLOCK = 864  #是否忽略地图阻挡
SYNCID_ENABLEINTERACT = 865  #EnableInteract
SYNCID_WORLDMEDAL = 866  #世界奖章
SYNCID_CURECEILING = 868  #治疗上限
SYNCID_RELATIONUNIONCURRENCY = 869  #圣乐之力
m_Exp = 0
m_Level = 0
m_ServerTime = 0
m_RoleId = 0
m_Strength = 0
m_Agility = 0
m_Intellectual = 0
m_Endurance = 0
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
m_CurProfession = 0
m_PetCreateDelCond = 0
m_PetDisplay = 0
m_PetMoney = 0
m_DuelStatus = 0
m_ExpPool = 0
m_RushState = null
m_StareState = 0
m_WorldLevel = 0
m_DizzyHitRate = null
m_DizzyResistRate = null
m_ImmovableHitRate = null
m_ImmovableResistRate = null
m_HurtFlyHitRate = null
m_HurtFlyResistRate = null
m_FrozenHitRate = null
m_FrozenResistRate = null
m_CleanHitRate = null
m_CleanResistRate = null
m_DispelHitRate = null
m_DispelResistRate = null
m_SilenceHitRate = null
m_SilenceResistRate = null
m_InterruptHitRate = null
m_InterruptResistRate = null
m_UncurableHitRate = null
m_UncurableResistRate = null
m_Transform = 0
m_HumanHurtRate = null
m_HumanSufferRate = null
m_MonsterHurtRate = null
m_MonsterSufferRate = null
m_BossHurtRate = null
m_BossSufferRate = null
m_DodgReduceValue = 0
m_DodgReduceRate = null
m_DodgAddValue = 0
m_DodgAddRate = null
m_TreasureFootPrint = 0
m_EquipTitle = 0
m_ObjAnimEvent = []
m_PinchData = ""
m_SkillCDRate = null
m_AspdRate = null
m_Shield = 0
m_EventLeftCount = 0
m_CanNotRush = 0
m_HuntPoint = 0
m_HuntHighTimes = 0
m_HuntFirePoint = 0
m_Starbattlestate = 0
m_IgnoreMotionBlock = null
m_EnableInteract = null
m_WorldMedal = 0
m_CureCeiling = 0
m_RelationUnionCurrency = 0
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
        optional uint64 ObjId = 2[default=0];
        optional bytes UpdateData = 3;
      }
      message  UserDataV1
      {
        optional int32 Exp = 1[default=0];
        optional int32 Level = 3[default=0];
        optional int32 ServerTime = 4[default=-1];
        optional uint64 RoleId = 5[default=0];
        optional int32 Strength = 7[default=0];
        optional int32 Agility = 8[default=0];
        optional int32 Intellectual = 9[default=0];
        optional int32 Endurance = 10[default=0];
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
        optional uint64 OwnerObjId = 55[default=0];
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
        optional int32 CurProfession = 113[default=-1];
        optional int32 PetCreateDelCond = 114[default=-1];
        optional int32 PetDisplay = 115[default=0];
        optional int64 PetMoney = 116[default=-1];
        optional int32 DuelStatus = 117[default=0];
        optional int64 ExpPool = 118[default=-1];
        optional bool RushState = 119;
        optional uint64 StareState = 120[default=0];
        optional int32 WorldLevel = 121[default=0];
        optional float DizzyHitRate = 122;
        optional float DizzyResistRate = 123;
        optional float ImmovableHitRate = 124;
        optional float ImmovableResistRate = 125;
        optional float HurtFlyHitRate = 126;
        optional float HurtFlyResistRate = 127;
        optional float FrozenHitRate = 128;
        optional float FrozenResistRate = 129;
        optional float CleanHitRate = 130;
        optional float CleanResistRate = 131;
        optional float DispelHitRate = 132;
        optional float DispelResistRate = 133;
        optional float SilenceHitRate = 134;
        optional float SilenceResistRate = 135;
        optional float InterruptHitRate = 136;
        optional float InterruptResistRate = 137;
        optional float UncurableHitRate = 138;
        optional float UncurableResistRate = 139;
        optional int32 Transform = 140[default=-1];
        optional float HumanHurtRate = 141;
        optional float HumanSufferRate = 142;
        optional float MonsterHurtRate = 143;
        optional float MonsterSufferRate = 144;
        optional float BossHurtRate = 145;
        optional float BossSufferRate = 146;
        optional int32 DodgReduceValue = 147[default=0];
        optional float DodgReduceRate = 148;
        optional int32 DodgAddValue = 149[default=0];
        optional float DodgAddRate = 150;
        optional int32 TreasureFootPrint = 151[default=-1];
        optional int32 EquipTitle = 152[default=-1];
        repeated int32 ObjAnimEvent = 153;
        optional string PinchData = 154;
        optional float SkillCDRate = 155;
        optional float AspdRate = 156;
        optional int32 Shield = 157[default=0];
        optional int32 EventLeftCount = 158[default=-1];
        optional int32 CanNotRush = 159[default=0];
        optional int32 HuntPoint = 160[default=0];
        optional int32 HuntHighTimes = 161[default=0];
        optional int32 HuntFirePoint = 162[default=0];
        optional int32 Starbattlestate = 163[default=1];
        optional bool IgnoreMotionBlock = 164;
        optional bool EnableInteract = 165;
        optional int32 WorldMedal = 166[default=0];
        optional int32 CureCeiling = 168[default=-1];
        optional int32 RelationUnionCurrency = 169[default=0];
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
  SyncID_CurProfession : () -> return SYNCID_CURPROFESSION
  SyncID_PetCreateDelCond : () -> return SYNCID_PETCREATEDELCOND
  SyncID_PetDisplay : () -> return SYNCID_PETDISPLAY
  SyncID_PetMoney : () -> return SYNCID_PETMONEY
  SyncID_DuelStatus : () -> return SYNCID_DUELSTATUS
  SyncID_ExpPool : () -> return SYNCID_EXPPOOL
  SyncID_RushState : () -> return SYNCID_RUSHSTATE
  SyncID_StareState : () -> return SYNCID_STARESTATE
  SyncID_WorldLevel : () -> return SYNCID_WORLDLEVEL
  SyncID_DizzyHitRate : () -> return SYNCID_DIZZYHITRATE
  SyncID_DizzyResistRate : () -> return SYNCID_DIZZYRESISTRATE
  SyncID_ImmovableHitRate : () -> return SYNCID_IMMOVABLEHITRATE
  SyncID_ImmovableResistRate : () -> return SYNCID_IMMOVABLERESISTRATE
  SyncID_HurtFlyHitRate : () -> return SYNCID_HURTFLYHITRATE
  SyncID_HurtFlyResistRate : () -> return SYNCID_HURTFLYRESISTRATE
  SyncID_FrozenHitRate : () -> return SYNCID_FROZENHITRATE
  SyncID_FrozenResistRate : () -> return SYNCID_FROZENRESISTRATE
  SyncID_CleanHitRate : () -> return SYNCID_CLEANHITRATE
  SyncID_CleanResistRate : () -> return SYNCID_CLEANRESISTRATE
  SyncID_DispelHitRate : () -> return SYNCID_DISPELHITRATE
  SyncID_DispelResistRate : () -> return SYNCID_DISPELRESISTRATE
  SyncID_SilenceHitRate : () -> return SYNCID_SILENCEHITRATE
  SyncID_SilenceResistRate : () -> return SYNCID_SILENCERESISTRATE
  SyncID_InterruptHitRate : () -> return SYNCID_INTERRUPTHITRATE
  SyncID_InterruptResistRate : () -> return SYNCID_INTERRUPTRESISTRATE
  SyncID_UncurableHitRate : () -> return SYNCID_UNCURABLEHITRATE
  SyncID_UncurableResistRate : () -> return SYNCID_UNCURABLERESISTRATE
  SyncID_Transform : () -> return SYNCID_TRANSFORM
  SyncID_HumanHurtRate : () -> return SYNCID_HUMANHURTRATE
  SyncID_HumanSufferRate : () -> return SYNCID_HUMANSUFFERRATE
  SyncID_MonsterHurtRate : () -> return SYNCID_MONSTERHURTRATE
  SyncID_MonsterSufferRate : () -> return SYNCID_MONSTERSUFFERRATE
  SyncID_BossHurtRate : () -> return SYNCID_BOSSHURTRATE
  SyncID_BossSufferRate : () -> return SYNCID_BOSSSUFFERRATE
  SyncID_DodgReduceValue : () -> return SYNCID_DODGREDUCEVALUE
  SyncID_DodgReduceRate : () -> return SYNCID_DODGREDUCERATE
  SyncID_DodgAddValue : () -> return SYNCID_DODGADDVALUE
  SyncID_DodgAddRate : () -> return SYNCID_DODGADDRATE
  SyncID_TreasureFootPrint : () -> return SYNCID_TREASUREFOOTPRINT
  SyncID_EquipTitle : () -> return SYNCID_EQUIPTITLE
  SyncID_ObjAnimEvent : () -> return SYNCID_OBJANIMEVENT
  SyncID_PinchData : () -> return SYNCID_PINCHDATA
  SyncID_SkillCDRate : () -> return SYNCID_SKILLCDRATE
  SyncID_AspdRate : () -> return SYNCID_ASPDRATE
  SyncID_Shield : () -> return SYNCID_SHIELD
  SyncID_EventLeftCount : () -> return SYNCID_EVENTLEFTCOUNT
  SyncID_CanNotRush : () -> return SYNCID_CANNOTRUSH
  SyncID_HuntPoint : () -> return SYNCID_HUNTPOINT
  SyncID_HuntHighTimes : () -> return SYNCID_HUNTHIGHTIMES
  SyncID_HuntFirePoint : () -> return SYNCID_HUNTFIREPOINT
  SyncID_Starbattlestate : () -> return SYNCID_STARBATTLESTATE
  SyncID_IgnoreMotionBlock : () -> return SYNCID_IGNOREMOTIONBLOCK
  SyncID_EnableInteract : () -> return SYNCID_ENABLEINTERACT
  SyncID_WorldMedal : () -> return SYNCID_WORLDMEDAL
  SyncID_CureCeiling : () -> return SYNCID_CURECEILING
  SyncID_RelationUnionCurrency : () -> return SYNCID_RELATIONUNIONCURRENCY
  Exp : () -> return m_Exp
  Level : () -> return m_Level
  ServerTime : () -> return m_ServerTime
  RoleId : () -> return m_RoleId
  Strength : () -> return m_Strength
  Agility : () -> return m_Agility
  Intellectual : () -> return m_Intellectual
  Endurance : () -> return m_Endurance
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
  CurProfession : () -> return m_CurProfession
  PetCreateDelCond : () -> return m_PetCreateDelCond
  PetDisplay : () -> return m_PetDisplay
  PetMoney : () -> return m_PetMoney
  DuelStatus : () -> return m_DuelStatus
  ExpPool : () -> return m_ExpPool
  RushState : () -> return m_RushState
  StareState : () -> return m_StareState
  WorldLevel : () -> return m_WorldLevel
  DizzyHitRate : () -> return m_DizzyHitRate
  DizzyResistRate : () -> return m_DizzyResistRate
  ImmovableHitRate : () -> return m_ImmovableHitRate
  ImmovableResistRate : () -> return m_ImmovableResistRate
  HurtFlyHitRate : () -> return m_HurtFlyHitRate
  HurtFlyResistRate : () -> return m_HurtFlyResistRate
  FrozenHitRate : () -> return m_FrozenHitRate
  FrozenResistRate : () -> return m_FrozenResistRate
  CleanHitRate : () -> return m_CleanHitRate
  CleanResistRate : () -> return m_CleanResistRate
  DispelHitRate : () -> return m_DispelHitRate
  DispelResistRate : () -> return m_DispelResistRate
  SilenceHitRate : () -> return m_SilenceHitRate
  SilenceResistRate : () -> return m_SilenceResistRate
  InterruptHitRate : () -> return m_InterruptHitRate
  InterruptResistRate : () -> return m_InterruptResistRate
  UncurableHitRate : () -> return m_UncurableHitRate
  UncurableResistRate : () -> return m_UncurableResistRate
  Transform : () -> return m_Transform
  HumanHurtRate : () -> return m_HumanHurtRate
  HumanSufferRate : () -> return m_HumanSufferRate
  MonsterHurtRate : () -> return m_MonsterHurtRate
  MonsterSufferRate : () -> return m_MonsterSufferRate
  BossHurtRate : () -> return m_BossHurtRate
  BossSufferRate : () -> return m_BossSufferRate
  DodgReduceValue : () -> return m_DodgReduceValue
  DodgReduceRate : () -> return m_DodgReduceRate
  DodgAddValue : () -> return m_DodgAddValue
  DodgAddRate : () -> return m_DodgAddRate
  TreasureFootPrint : () -> return m_TreasureFootPrint
  EquipTitle : () -> return m_EquipTitle
  ObjAnimEvent : () -> return m_ObjAnimEvent
  PinchData : () -> return m_PinchData
  SkillCDRate : () -> return m_SkillCDRate
  AspdRate : () -> return m_AspdRate
  Shield : () -> return m_Shield
  EventLeftCount : () -> return m_EventLeftCount
  CanNotRush : () -> return m_CanNotRush
  HuntPoint : () -> return m_HuntPoint
  HuntHighTimes : () -> return m_HuntHighTimes
  HuntFirePoint : () -> return m_HuntFirePoint
  Starbattlestate : () -> return m_Starbattlestate
  IgnoreMotionBlock : () -> return m_IgnoreMotionBlock
  EnableInteract : () -> return m_EnableInteract
  WorldMedal : () -> return m_WorldMedal
  CureCeiling : () -> return m_CureCeiling
  RelationUnionCurrency : () -> return m_RelationUnionCurrency


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
        m_ServerTime = Data.readVarint32ZigZag()
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
        m_OwnerObjId = Data.readVarint64ZigZag().toNumber()
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
      when SYNCID_CURPROFESSION
        m_CurProfession = Data.readVarint32ZigZag()
      when SYNCID_PETCREATEDELCOND
        m_PetCreateDelCond = Data.readVarint32ZigZag()
      when SYNCID_PETDISPLAY
        m_PetDisplay = Data.readVarint32ZigZag()
      when SYNCID_PETMONEY
        m_PetMoney = Data.readVarint64ZigZag().toNumber()
      when SYNCID_DUELSTATUS
        m_DuelStatus = Data.readVarint32ZigZag()
      when SYNCID_EXPPOOL
        m_ExpPool = Data.readVarint64ZigZag().toNumber()
      when SYNCID_RUSHSTATE
        m_RushState = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_STARESTATE
        m_StareState = Data.readVarint64ZigZag().toNumber()
      when SYNCID_WORLDLEVEL
        m_WorldLevel = Data.readVarint32ZigZag()
      when SYNCID_DIZZYHITRATE
        m_DizzyHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DIZZYRESISTRATE
        m_DizzyResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_IMMOVABLEHITRATE
        m_ImmovableHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_IMMOVABLERESISTRATE
        m_ImmovableResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_HURTFLYHITRATE
        m_HurtFlyHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_HURTFLYRESISTRATE
        m_HurtFlyResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_FROZENHITRATE
        m_FrozenHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_FROZENRESISTRATE
        m_FrozenResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_CLEANHITRATE
        m_CleanHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_CLEANRESISTRATE
        m_CleanResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DISPELHITRATE
        m_DispelHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DISPELRESISTRATE
        m_DispelResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_SILENCEHITRATE
        m_SilenceHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_SILENCERESISTRATE
        m_SilenceResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_INTERRUPTHITRATE
        m_InterruptHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_INTERRUPTRESISTRATE
        m_InterruptResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_UNCURABLEHITRATE
        m_UncurableHitRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_UNCURABLERESISTRATE
        m_UncurableResistRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_TRANSFORM
        m_Transform = Data.readVarint32ZigZag()
      when SYNCID_HUMANHURTRATE
        m_HumanHurtRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_HUMANSUFFERRATE
        m_HumanSufferRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MONSTERHURTRATE
        m_MonsterHurtRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_MONSTERSUFFERRATE
        m_MonsterSufferRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_BOSSHURTRATE
        m_BossHurtRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_BOSSSUFFERRATE
        m_BossSufferRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DODGREDUCEVALUE
        m_DodgReduceValue = Data.readVarint32ZigZag()
      when SYNCID_DODGREDUCERATE
        m_DodgReduceRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_DODGADDVALUE
        m_DodgAddValue = Data.readVarint32ZigZag()
      when SYNCID_DODGADDRATE
        m_DodgAddRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_TREASUREFOOTPRINT
        m_TreasureFootPrint = Data.readVarint32ZigZag()
      when SYNCID_EQUIPTITLE
        m_EquipTitle = Data.readVarint32ZigZag()
      when SYNCID_OBJANIMEVENT
        if Index is -1
          m_ObjAnimEvent = []
          return
        m_ObjAnimEvent[Index] = Data.readVarint32ZigZag()
      when SYNCID_PINCHDATA
        if dataLen is 0
          return
        m_PinchData = Data.readUTF8StringBySelf(dataLen)
      when SYNCID_SKILLCDRATE
        m_SkillCDRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_ASPDRATE
        m_AspdRate = Proto.build("float").decode(Data.toBuffer())
      when SYNCID_SHIELD
        m_Shield = Data.readVarint32ZigZag()
      when SYNCID_EVENTLEFTCOUNT
        m_EventLeftCount = Data.readVarint32ZigZag()
      when SYNCID_CANNOTRUSH
        m_CanNotRush = Data.readVarint32ZigZag()
      when SYNCID_HUNTPOINT
        m_HuntPoint = Data.readVarint32ZigZag()
      when SYNCID_HUNTHIGHTIMES
        m_HuntHighTimes = Data.readVarint32ZigZag()
      when SYNCID_HUNTFIREPOINT
        m_HuntFirePoint = Data.readVarint32ZigZag()
      when SYNCID_STARBATTLESTATE
        m_Starbattlestate = Data.readVarint32ZigZag()
      when SYNCID_IGNOREMOTIONBLOCK
        m_IgnoreMotionBlock = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_ENABLEINTERACT
        m_EnableInteract = Proto.build("bool").decode(Data.toBuffer())
      when SYNCID_WORLDMEDAL
        m_WorldMedal = Data.readVarint32ZigZag()
      when SYNCID_CURECEILING
        m_CureCeiling = Data.readVarint32ZigZag()
      when SYNCID_RELATIONUNIONCURRENCY
        m_RelationUnionCurrency = Data.readVarint32ZigZag()

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



  

  

  


