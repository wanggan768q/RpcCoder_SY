#include "BaseAttrV1Data.h"
//#include "BaseAttrModule.h"
#include "Obj/Obj_Character/Obj_Character.h"
#include "Main/SyncOtherProperty.h"

SyncDataBaseAttrV1::SyncDataBaseAttrV1(Obj_Character* pObj):m_bChange(false),m_pObj(pObj)
{
	//SetDataWraper( &m_syncDataUserData );
		m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_EXP,std::move(std::bind(&Obj_Character::CalcExp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_LEVEL,std::move(std::bind(&Obj_Character::CalcLevel, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SERVERTIME,std::move(std::bind(&Obj_Character::CalcServerTime, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ROLEID,std::move(std::bind(&Obj_Character::CalcRoleId, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_STRENGTH,std::move(std::bind(&Obj_Character::CalcStrength, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_AGILITY,std::move(std::bind(&Obj_Character::CalcAgility, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_INTELLECTUAL,std::move(std::bind(&Obj_Character::CalcIntellectual, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ENDURANCE,std::move(std::bind(&Obj_Character::CalcEndurance, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HP,std::move(std::bind(&Obj_Character::CalcHp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MAXHP,std::move(std::bind(&Obj_Character::CalcMaxHp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PHYSICATTACK,std::move(std::bind(&Obj_Character::CalcPhysicAttack, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PHYSICDEFENSE,std::move(std::bind(&Obj_Character::CalcPhysicDefense, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MAGICATTACK,std::move(std::bind(&Obj_Character::CalcMagicAttack, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MAGICDEFENSE,std::move(std::bind(&Obj_Character::CalcMagicDefense, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HIT,std::move(std::bind(&Obj_Character::CalcHit, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HITRATE,std::move(std::bind(&Obj_Character::CalcHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MISS,std::move(std::bind(&Obj_Character::CalcMiss, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MISSRATE,std::move(std::bind(&Obj_Character::CalcMissRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICAL,std::move(std::bind(&Obj_Character::CalcCritical, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALRATE,std::move(std::bind(&Obj_Character::CalcCriticalRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TENACITY,std::move(std::bind(&Obj_Character::CalcTenacity, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TENACITYRATE,std::move(std::bind(&Obj_Character::CalcTenacityRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PENET,std::move(std::bind(&Obj_Character::CalcPenet, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PENETRATE,std::move(std::bind(&Obj_Character::CalcPenetRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODG,std::move(std::bind(&Obj_Character::CalcDodg, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGRATE,std::move(std::bind(&Obj_Character::CalcDodgRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALADDITION,std::move(std::bind(&Obj_Character::CalcCriticalAddition, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALADDITIONRATE,std::move(std::bind(&Obj_Character::CalcCriticalAdditionRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALIMMUNE,std::move(std::bind(&Obj_Character::CalcCriticalImmune, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALIMMUNERATE,std::move(std::bind(&Obj_Character::CalcCriticalImmuneRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MISSLEVEL,std::move(std::bind(&Obj_Character::CalcMissLevel, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CRITICALLEVEL,std::move(std::bind(&Obj_Character::CalcCriticalLevel, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGLEVEL,std::move(std::bind(&Obj_Character::CalcDodgLevel, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MOVESPEED,std::move(std::bind(&Obj_Character::CalcMoveSpeed, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DIZZYSTATE,std::move(std::bind(&Obj_Character::CalcDizzyState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GODSTATE,std::move(std::bind(&Obj_Character::CalcGodState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CANTMOVESTATE,std::move(std::bind(&Obj_Character::CalcCantMoveState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PHYSICADDITION,std::move(std::bind(&Obj_Character::CalcPhysicAddition, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MAGICADDITION,std::move(std::bind(&Obj_Character::CalcMagicAddition, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PHYSICOPPOSE,std::move(std::bind(&Obj_Character::CalcPhysicOppose, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MAGICOPPOSE,std::move(std::bind(&Obj_Character::CalcMagicOppose, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ACCUMULATESKIENERGY,std::move(std::bind(&Obj_Character::CalcAccumulateSkiEnergy, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_NICKNAME,std::move(std::bind(&Obj_Character::CalcNickName, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CONFIGID,std::move(std::bind(&Obj_Character::CalcConfigId, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_OBJTYPE,std::move(std::bind(&Obj_Character::CalcObjType, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_STATE,std::move(std::bind(&Obj_Character::CalcState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_OWNEROBJID,std::move(std::bind(&Obj_Character::CalcOwnerObjId, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CAMP,std::move(std::bind(&Obj_Character::CalcCamp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SILVERMONEY,std::move(std::bind(&Obj_Character::CalcSilverMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GOLDMONEY,std::move(std::bind(&Obj_Character::CalcGoldMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DIAMONDMONEY,std::move(std::bind(&Obj_Character::CalcDiamondMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_BINDINGDIAMONDMONEY,std::move(std::bind(&Obj_Character::CalcBindingDiamondMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_BATTLESCORE,std::move(std::bind(&Obj_Character::CalcBattleScore, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ENERGY,std::move(std::bind(&Obj_Character::CalcEnergy, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDMONEY,std::move(std::bind(&Obj_Character::CalcGuildMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SKILLLIST,std::move(std::bind(&Obj_Character::CalcSkillList, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HONORMONEY,std::move(std::bind(&Obj_Character::CalcHonorMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_RESOURCEPOOLHP,std::move(std::bind(&Obj_Character::CalcResourcePoolHp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ATTACKADD,std::move(std::bind(&Obj_Character::CalcAttackAdd, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_INJURYADD,std::move(std::bind(&Obj_Character::CalcInjuryAdd, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_FROZENSTATE,std::move(std::bind(&Obj_Character::CalcFrozenState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SILENTSTATE,std::move(std::bind(&Obj_Character::CalcSilentState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX,std::move(std::bind(&Obj_Character::CalcGuildContributeHistoryMax, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TEAMID,std::move(std::bind(&Obj_Character::CalcTeamId, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREHAIR,std::move(std::bind(&Obj_Character::CalcTreasureHair, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREHEAD,std::move(std::bind(&Obj_Character::CalcTreasureHead, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREBODY,std::move(std::bind(&Obj_Character::CalcTreasureBody, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREWEAPON,std::move(std::bind(&Obj_Character::CalcTreasureWeapon, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREWING,std::move(std::bind(&Obj_Character::CalcTreasureWing, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDGUID,std::move(std::bind(&Obj_Character::CalcGuildGuid, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASURERIDING,std::move(std::bind(&Obj_Character::CalcTreasureRiding, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_VECHICLEID,std::move(std::bind(&Obj_Character::CalcVechicleId, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ANIMATIONSTATE,std::move(std::bind(&Obj_Character::CalcAnimationState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXDMGRATE,std::move(std::bind(&Obj_Character::CalcRefixDmgRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXDMGVALUE,std::move(std::bind(&Obj_Character::CalcRefixDmgValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXHURTRATE,std::move(std::bind(&Obj_Character::CalcRefixHurtRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXHURTVALUE,std::move(std::bind(&Obj_Character::CalcRefixHurtValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXHEALRATE,std::move(std::bind(&Obj_Character::CalcRefixHealRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXHEALVALUE,std::move(std::bind(&Obj_Character::CalcRefixHealValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXCUREDRATE,std::move(std::bind(&Obj_Character::CalcRefixCuredRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_REFIXCUREDVALUE,std::move(std::bind(&Obj_Character::CalcRefixCuredValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDCONTRIBUTE,std::move(std::bind(&Obj_Character::CalcGuildContribute, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PVPMONEY,std::move(std::bind(&Obj_Character::CalcPvpMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDRESOURCE,std::move(std::bind(&Obj_Character::CalcGuildResource, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CREATEROLETIME,std::move(std::bind(&Obj_Character::CalcCreateRoleTime, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_UPDATEROLETIME,std::move(std::bind(&Obj_Character::CalcUpdateRoleTime, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_FIGHTSTATE,std::move(std::bind(&Obj_Character::CalcFightState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ATTACKSKILLLIST,std::move(std::bind(&Obj_Character::CalcAttackSkillList, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDNAME,std::move(std::bind(&Obj_Character::CalcGuildName, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ISALLOWSELECT,std::move(std::bind(&Obj_Character::CalcIsAllowSelect, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GOHOMESTATE,std::move(std::bind(&Obj_Character::CalcGoHomeState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CANFIGHT,std::move(std::bind(&Obj_Character::CalcCanFight, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DOUBLEEXP,std::move(std::bind(&Obj_Character::CalcDoubleExp, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_FRIENDPOINT,std::move(std::bind(&Obj_Character::CalcFriendPoint, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HISMAXHONOR,std::move(std::bind(&Obj_Character::CalcHisMaxHonor, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTSTATE,std::move(std::bind(&Obj_Character::CalcHurtState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTFLYSTATE,std::move(std::bind(&Obj_Character::CalcHurtFlyState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTDOWNSTATE,std::move(std::bind(&Obj_Character::CalcHurtDownState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTREPELSTATE,std::move(std::bind(&Obj_Character::CalcHurtRepelState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TODAYHORNOR,std::move(std::bind(&Obj_Character::CalcTodayHornor, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CURPROFESSION,std::move(std::bind(&Obj_Character::CalcCurProfession, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PETCREATEDELCOND,std::move(std::bind(&Obj_Character::CalcPetCreateDelCond, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PETDISPLAY,std::move(std::bind(&Obj_Character::CalcPetDisplay, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PETMONEY,std::move(std::bind(&Obj_Character::CalcPetMoney, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DUELSTATUS,std::move(std::bind(&Obj_Character::CalcDuelStatus, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_EXPPOOL,std::move(std::bind(&Obj_Character::CalcExpPool, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_RUSHSTATE,std::move(std::bind(&Obj_Character::CalcRushState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_STARESTATE,std::move(std::bind(&Obj_Character::CalcStareState, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_WORLDLEVEL,std::move(std::bind(&Obj_Character::CalcWorldLevel, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DIZZYHITRATE,std::move(std::bind(&Obj_Character::CalcDizzyHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DIZZYRESISTRATE,std::move(std::bind(&Obj_Character::CalcDizzyResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_IMMOVABLEHITRATE,std::move(std::bind(&Obj_Character::CalcImmovableHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_IMMOVABLERESISTRATE,std::move(std::bind(&Obj_Character::CalcImmovableResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTFLYHITRATE,std::move(std::bind(&Obj_Character::CalcHurtFlyHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HURTFLYRESISTRATE,std::move(std::bind(&Obj_Character::CalcHurtFlyResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_FROZENHITRATE,std::move(std::bind(&Obj_Character::CalcFrozenHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_FROZENRESISTRATE,std::move(std::bind(&Obj_Character::CalcFrozenResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CLEANHITRATE,std::move(std::bind(&Obj_Character::CalcCleanHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CLEANRESISTRATE,std::move(std::bind(&Obj_Character::CalcCleanResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DISPELHITRATE,std::move(std::bind(&Obj_Character::CalcDispelHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DISPELRESISTRATE,std::move(std::bind(&Obj_Character::CalcDispelResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SILENCEHITRATE,std::move(std::bind(&Obj_Character::CalcSilenceHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SILENCERESISTRATE,std::move(std::bind(&Obj_Character::CalcSilenceResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_INTERRUPTHITRATE,std::move(std::bind(&Obj_Character::CalcInterruptHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_INTERRUPTRESISTRATE,std::move(std::bind(&Obj_Character::CalcInterruptResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_UNCURABLEHITRATE,std::move(std::bind(&Obj_Character::CalcUncurableHitRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_UNCURABLERESISTRATE,std::move(std::bind(&Obj_Character::CalcUncurableResistRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TRANSFORM,std::move(std::bind(&Obj_Character::CalcTransform, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HUMANHURTRATE,std::move(std::bind(&Obj_Character::CalcHumanHurtRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HUMANSUFFERRATE,std::move(std::bind(&Obj_Character::CalcHumanSufferRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MONSTERHURTRATE,std::move(std::bind(&Obj_Character::CalcMonsterHurtRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_MONSTERSUFFERRATE,std::move(std::bind(&Obj_Character::CalcMonsterSufferRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_BOSSHURTRATE,std::move(std::bind(&Obj_Character::CalcBossHurtRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_BOSSSUFFERRATE,std::move(std::bind(&Obj_Character::CalcBossSufferRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGREDUCEVALUE,std::move(std::bind(&Obj_Character::CalcDodgReduceValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGREDUCERATE,std::move(std::bind(&Obj_Character::CalcDodgReduceRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGADDVALUE,std::move(std::bind(&Obj_Character::CalcDodgAddValue, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_DODGADDRATE,std::move(std::bind(&Obj_Character::CalcDodgAddRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_TREASUREFOOTPRINT,std::move(std::bind(&Obj_Character::CalcTreasureFootPrint, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_EQUIPTITLE,std::move(std::bind(&Obj_Character::CalcEquipTitle, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_OBJANIMEVENT,std::move(std::bind(&Obj_Character::CalcObjAnimEvent, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_PINCHDATA,std::move(std::bind(&Obj_Character::CalcPinchData, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SKILLCDRATE,std::move(std::bind(&Obj_Character::CalcSkillCDRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ASPDRATE,std::move(std::bind(&Obj_Character::CalcAspdRate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SHIELD,std::move(std::bind(&Obj_Character::CalcShield, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_EVENTLEFTCOUNT,std::move(std::bind(&Obj_Character::CalcEventLeftCount, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CANNOTRUSH,std::move(std::bind(&Obj_Character::CalcCanNotRush, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HUNTPOINT,std::move(std::bind(&Obj_Character::CalcHuntPoint, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HUNTHIGHTIMES,std::move(std::bind(&Obj_Character::CalcHuntHighTimes, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_HUNTFIREPOINT,std::move(std::bind(&Obj_Character::CalcHuntFirePoint, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_STARBATTLESTATE,std::move(std::bind(&Obj_Character::CalcStarbattlestate, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_IGNOREMOTIONBLOCK,std::move(std::bind(&Obj_Character::CalcIgnoreMotionBlock, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_ENABLEINTERACT,std::move(std::bind(&Obj_Character::CalcEnableInteract, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_WORLDMEDAL,std::move(std::bind(&Obj_Character::CalcWorldMedal, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_CURECEILING,std::move(std::bind(&Obj_Character::CalcCureCeiling, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_RELATIONUNIONCURRENCY,std::move(std::bind(&Obj_Character::CalcRelationUnionCurrency, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDSHORTNAME,std::move(std::bind(&Obj_Character::CalcGuildShortName, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_GUILDSHORTCOLORID,std::move(std::bind(&Obj_Character::CalcGuildShortColorID, pObj)));

}

SyncDataBaseAttrV1::~SyncDataBaseAttrV1()
{
}

void SyncDataBaseAttrV1::Init()
{
	RefreshAll();
	m_bChange = false;
	m_bOtherChange = false;
}

void SyncDataBaseAttrV1::InitEx()
{
	Init();
	CalcChangeMethodCB();
	m_ClientDataUserData.Clear();
	m_OtherDataUserData.Clear();
	m_bChange = false;
	m_bOtherChange = false;
}

void SyncDataBaseAttrV1::RefreshAll()
{
		RefreshExp();
	RefreshLevel();
	RefreshServerTime();
	RefreshRoleId();
	RefreshStrength();
	RefreshAgility();
	RefreshIntellectual();
	RefreshEndurance();
	RefreshHp();
	RefreshMaxHp();
	RefreshPhysicAttack();
	RefreshPhysicDefense();
	RefreshMagicAttack();
	RefreshMagicDefense();
	RefreshHit();
	RefreshHitRate();
	RefreshMiss();
	RefreshMissRate();
	RefreshCritical();
	RefreshCriticalRate();
	RefreshTenacity();
	RefreshTenacityRate();
	RefreshPenet();
	RefreshPenetRate();
	RefreshDodg();
	RefreshDodgRate();
	RefreshCriticalAddition();
	RefreshCriticalAdditionRate();
	RefreshCriticalImmune();
	RefreshCriticalImmuneRate();
	RefreshMissLevel();
	RefreshCriticalLevel();
	RefreshDodgLevel();
	RefreshMoveSpeed();
	RefreshDizzyState();
	RefreshGodState();
	RefreshCantMoveState();
	RefreshPhysicAddition();
	RefreshMagicAddition();
	RefreshPhysicOppose();
	RefreshMagicOppose();
	RefreshAccumulateSkiEnergy();
	RefreshNickName();
	RefreshConfigId();
	RefreshObjType();
	RefreshState();
	RefreshOwnerObjId();
	RefreshCamp();
	RefreshSilverMoney();
	RefreshGoldMoney();
	RefreshDiamondMoney();
	RefreshBindingDiamondMoney();
	RefreshBattleScore();
	RefreshEnergy();
	RefreshGuildMoney();
	RefreshSkillList();
	RefreshHonorMoney();
	RefreshResourcePoolHp();
	RefreshAttackAdd();
	RefreshInjuryAdd();
	RefreshFrozenState();
	RefreshSilentState();
	RefreshGuildContributeHistoryMax();
	RefreshTeamId();
	RefreshTreasureHair();
	RefreshTreasureHead();
	RefreshTreasureBody();
	RefreshTreasureWeapon();
	RefreshTreasureWing();
	RefreshGuildGuid();
	RefreshTreasureRiding();
	RefreshVechicleId();
	RefreshAnimationState();
	RefreshRefixDmgRate();
	RefreshRefixDmgValue();
	RefreshRefixHurtRate();
	RefreshRefixHurtValue();
	RefreshRefixHealRate();
	RefreshRefixHealValue();
	RefreshRefixCuredRate();
	RefreshRefixCuredValue();
	RefreshGuildContribute();
	RefreshPvpMoney();
	RefreshGuildResource();
	RefreshCreateRoleTime();
	RefreshUpdateRoleTime();
	RefreshFightState();
	RefreshAttackSkillList();
	RefreshGuildName();
	RefreshIsAllowSelect();
	RefreshGoHomeState();
	RefreshCanFight();
	RefreshDoubleExp();
	RefreshFriendPoint();
	RefreshHisMaxHonor();
	RefreshHurtState();
	RefreshHurtFlyState();
	RefreshHurtDownState();
	RefreshHurtRepelState();
	RefreshTodayHornor();
	RefreshCurProfession();
	RefreshPetCreateDelCond();
	RefreshPetDisplay();
	RefreshPetMoney();
	RefreshDuelStatus();
	RefreshExpPool();
	RefreshRushState();
	RefreshStareState();
	RefreshWorldLevel();
	RefreshDizzyHitRate();
	RefreshDizzyResistRate();
	RefreshImmovableHitRate();
	RefreshImmovableResistRate();
	RefreshHurtFlyHitRate();
	RefreshHurtFlyResistRate();
	RefreshFrozenHitRate();
	RefreshFrozenResistRate();
	RefreshCleanHitRate();
	RefreshCleanResistRate();
	RefreshDispelHitRate();
	RefreshDispelResistRate();
	RefreshSilenceHitRate();
	RefreshSilenceResistRate();
	RefreshInterruptHitRate();
	RefreshInterruptResistRate();
	RefreshUncurableHitRate();
	RefreshUncurableResistRate();
	RefreshTransform();
	RefreshHumanHurtRate();
	RefreshHumanSufferRate();
	RefreshMonsterHurtRate();
	RefreshMonsterSufferRate();
	RefreshBossHurtRate();
	RefreshBossSufferRate();
	RefreshDodgReduceValue();
	RefreshDodgReduceRate();
	RefreshDodgAddValue();
	RefreshDodgAddRate();
	RefreshTreasureFootPrint();
	RefreshEquipTitle();
	RefreshObjAnimEvent();
	RefreshPinchData();
	RefreshSkillCDRate();
	RefreshAspdRate();
	RefreshShield();
	RefreshEventLeftCount();
	RefreshCanNotRush();
	RefreshHuntPoint();
	RefreshHuntHighTimes();
	RefreshHuntFirePoint();
	RefreshStarbattlestate();
	RefreshIgnoreMotionBlock();
	RefreshEnableInteract();
	RefreshWorldMedal();
	RefreshCureCeiling();
	RefreshRelationUnionCurrency();
	RefreshGuildShortName();
	RefreshGuildShortColorID();

}

void SyncDataBaseAttrV1::SetSendCallBack(const send_callback_type & cb)
{
	m_oSendCallback = cb;
}

void  SyncDataBaseAttrV1::SetSendOtherCallBack(const send_callback_type & cb)
{
	m_oSendOtherCallback = cb;
}

void SyncDataBaseAttrV1::CalcAllMembers()
{
		GetExp();
	GetLevel();
	GetServerTime();
	GetRoleId();
	GetStrength();
	GetAgility();
	GetIntellectual();
	GetEndurance();
	GetHp();
	GetMaxHp();
	GetPhysicAttack();
	GetPhysicDefense();
	GetMagicAttack();
	GetMagicDefense();
	GetHit();
	GetHitRate();
	GetMiss();
	GetMissRate();
	GetCritical();
	GetCriticalRate();
	GetTenacity();
	GetTenacityRate();
	GetPenet();
	GetPenetRate();
	GetDodg();
	GetDodgRate();
	GetCriticalAddition();
	GetCriticalAdditionRate();
	GetCriticalImmune();
	GetCriticalImmuneRate();
	GetMissLevel();
	GetCriticalLevel();
	GetDodgLevel();
	GetMoveSpeed();
	GetDizzyState();
	GetGodState();
	GetCantMoveState();
	GetPhysicAddition();
	GetMagicAddition();
	GetPhysicOppose();
	GetMagicOppose();
	GetAccumulateSkiEnergy();
	GetNickName();
	GetConfigId();
	GetObjType();
	GetState();
	GetOwnerObjId();
	GetCamp();
	GetSilverMoney();
	GetGoldMoney();
	GetDiamondMoney();
	GetBindingDiamondMoney();
	GetBattleScore();
	GetEnergy();
	GetGuildMoney();
	GetSkillList();
	GetHonorMoney();
	GetResourcePoolHp();
	GetAttackAdd();
	GetInjuryAdd();
	GetFrozenState();
	GetSilentState();
	GetGuildContributeHistoryMax();
	GetTeamId();
	GetTreasureHair();
	GetTreasureHead();
	GetTreasureBody();
	GetTreasureWeapon();
	GetTreasureWing();
	GetGuildGuid();
	GetTreasureRiding();
	GetVechicleId();
	GetAnimationState();
	GetRefixDmgRate();
	GetRefixDmgValue();
	GetRefixHurtRate();
	GetRefixHurtValue();
	GetRefixHealRate();
	GetRefixHealValue();
	GetRefixCuredRate();
	GetRefixCuredValue();
	GetGuildContribute();
	GetPvpMoney();
	GetGuildResource();
	GetCreateRoleTime();
	GetUpdateRoleTime();
	GetFightState();
	GetAttackSkillList();
	GetGuildName();
	GetIsAllowSelect();
	GetGoHomeState();
	GetCanFight();
	GetDoubleExp();
	GetFriendPoint();
	GetHisMaxHonor();
	GetHurtState();
	GetHurtFlyState();
	GetHurtDownState();
	GetHurtRepelState();
	GetTodayHornor();
	GetCurProfession();
	GetPetCreateDelCond();
	GetPetDisplay();
	GetPetMoney();
	GetDuelStatus();
	GetExpPool();
	GetRushState();
	GetStareState();
	GetWorldLevel();
	GetDizzyHitRate();
	GetDizzyResistRate();
	GetImmovableHitRate();
	GetImmovableResistRate();
	GetHurtFlyHitRate();
	GetHurtFlyResistRate();
	GetFrozenHitRate();
	GetFrozenResistRate();
	GetCleanHitRate();
	GetCleanResistRate();
	GetDispelHitRate();
	GetDispelResistRate();
	GetSilenceHitRate();
	GetSilenceResistRate();
	GetInterruptHitRate();
	GetInterruptResistRate();
	GetUncurableHitRate();
	GetUncurableResistRate();
	GetTransform();
	GetHumanHurtRate();
	GetHumanSufferRate();
	GetMonsterHurtRate();
	GetMonsterSufferRate();
	GetBossHurtRate();
	GetBossSufferRate();
	GetDodgReduceValue();
	GetDodgReduceRate();
	GetDodgAddValue();
	GetDodgAddRate();
	GetTreasureFootPrint();
	GetEquipTitle();
	GetObjAnimEvent();
	GetPinchData();
	GetSkillCDRate();
	GetAspdRate();
	GetShield();
	GetEventLeftCount();
	GetCanNotRush();
	GetHuntPoint();
	GetHuntHighTimes();
	GetHuntFirePoint();
	GetStarbattlestate();
	GetIgnoreMotionBlock();
	GetEnableInteract();
	GetWorldMedal();
	GetCureCeiling();
	GetRelationUnionCurrency();
	GetGuildShortName();
	GetGuildShortColorID();

}

void SyncDataBaseAttrV1::SendAllMembers()
{
/**
	SendExp(OnlyToClient);
	SendLevel(OnlyToClient);
	SendServerTime(OnlyToClient);
	SendRoleId(OnlyToClient);
	SendStrength(OnlyToClient);
	SendAgility(OnlyToClient);
	SendIntellectual(OnlyToClient);
	SendEndurance(OnlyToClient);
	SendHp(OnlyToClient);
	SendMaxHp(OnlyToClient);
	SendPhysicAttack(OnlyToClient);
	SendPhysicDefense(OnlyToClient);
	SendMagicAttack(OnlyToClient);
	SendMagicDefense(OnlyToClient);
	SendHit(OnlyToClient);
	SendHitRate(OnlyToClient);
	SendMiss(OnlyToClient);
	SendMissRate(OnlyToClient);
	SendCritical(OnlyToClient);
	SendCriticalRate(OnlyToClient);
	SendTenacity(OnlyToClient);
	SendTenacityRate(OnlyToClient);
	SendPenet(OnlyToClient);
	SendPenetRate(OnlyToClient);
	SendDodg(OnlyToClient);
	SendDodgRate(OnlyToClient);
	SendCriticalAddition(OnlyToClient);
	SendCriticalAdditionRate(OnlyToClient);
	SendCriticalImmune(OnlyToClient);
	SendCriticalImmuneRate(OnlyToClient);
	SendMissLevel(OnlyToClient);
	SendCriticalLevel(OnlyToClient);
	SendDodgLevel(OnlyToClient);
	SendMoveSpeed(OnlyToClient);
	SendDizzyState(OnlyToClient);
	SendGodState(OnlyToClient);
	SendCantMoveState(OnlyToClient);
	SendPhysicAddition(OnlyToClient);
	SendMagicAddition(OnlyToClient);
	SendPhysicOppose(OnlyToClient);
	SendMagicOppose(OnlyToClient);
	SendAccumulateSkiEnergy(OnlyToClient);
	SendNickName(OnlyToClient);
	SendConfigId(OnlyToClient);
	SendObjType(OnlyToClient);
	SendState(OnlyToClient);
	SendOwnerObjId(OnlyToClient);
	SendCamp(OnlyToClient);
	SendSilverMoney(OnlyToClient);
	SendGoldMoney(OnlyToClient);
	SendDiamondMoney(OnlyToClient);
	SendBindingDiamondMoney(OnlyToClient);
	SendBattleScore(OnlyToClient);
	SendEnergy(OnlyToClient);
	SendGuildMoney(OnlyToClient);
	SendSkillList(OnlyToClient);
	SendHonorMoney(OnlyToClient);
	SendResourcePoolHp(OnlyToClient);
	SendAttackAdd(OnlyToClient);
	SendInjuryAdd(OnlyToClient);
	SendFrozenState(OnlyToClient);
	SendSilentState(OnlyToClient);
	SendGuildContributeHistoryMax(OnlyToClient);
	SendTeamId(OnlyToClient);
	SendTreasureHair(OnlyToClient);
	SendTreasureHead(OnlyToClient);
	SendTreasureBody(OnlyToClient);
	SendTreasureWeapon(OnlyToClient);
	SendTreasureWing(OnlyToClient);
	SendGuildGuid(OnlyToClient);
	SendTreasureRiding(OnlyToClient);
	SendVechicleId(OnlyToClient);
	SendAnimationState(OnlyToClient);
	SendRefixDmgRate(OnlyToClient);
	SendRefixDmgValue(OnlyToClient);
	SendRefixHurtRate(OnlyToClient);
	SendRefixHurtValue(OnlyToClient);
	SendRefixHealRate(OnlyToClient);
	SendRefixHealValue(OnlyToClient);
	SendRefixCuredRate(OnlyToClient);
	SendRefixCuredValue(OnlyToClient);
	SendGuildContribute(OnlyToClient);
	SendPvpMoney(OnlyToClient);
	SendGuildResource(OnlyToClient);
	SendCreateRoleTime(OnlyToClient);
	SendUpdateRoleTime(OnlyToClient);
	SendFightState(OnlyToClient);
	SendAttackSkillList(OnlyToClient);
	SendGuildName(OnlyToClient);
	SendIsAllowSelect(OnlyToClient);
	SendGoHomeState(OnlyToClient);
	SendCanFight(OnlyToClient);
	SendDoubleExp(OnlyToClient);
	SendFriendPoint(OnlyToClient);
	SendHisMaxHonor(OnlyToClient);
	SendHurtState(OnlyToClient);
	SendHurtFlyState(OnlyToClient);
	SendHurtDownState(OnlyToClient);
	SendHurtRepelState(OnlyToClient);
	SendTodayHornor(OnlyToClient);
	SendCurProfession(OnlyToClient);
	SendPetCreateDelCond(OnlyToClient);
	SendPetDisplay(OnlyToClient);
	SendPetMoney(OnlyToClient);
	SendDuelStatus(OnlyToClient);
	SendExpPool(OnlyToClient);
	SendRushState(OnlyToClient);
	SendStareState(OnlyToClient);
	SendWorldLevel(OnlyToClient);
	SendDizzyHitRate(OnlyToClient);
	SendDizzyResistRate(OnlyToClient);
	SendImmovableHitRate(OnlyToClient);
	SendImmovableResistRate(OnlyToClient);
	SendHurtFlyHitRate(OnlyToClient);
	SendHurtFlyResistRate(OnlyToClient);
	SendFrozenHitRate(OnlyToClient);
	SendFrozenResistRate(OnlyToClient);
	SendCleanHitRate(OnlyToClient);
	SendCleanResistRate(OnlyToClient);
	SendDispelHitRate(OnlyToClient);
	SendDispelResistRate(OnlyToClient);
	SendSilenceHitRate(OnlyToClient);
	SendSilenceResistRate(OnlyToClient);
	SendInterruptHitRate(OnlyToClient);
	SendInterruptResistRate(OnlyToClient);
	SendUncurableHitRate(OnlyToClient);
	SendUncurableResistRate(OnlyToClient);
	SendTransform(OnlyToClient);
	SendHumanHurtRate(OnlyToClient);
	SendHumanSufferRate(OnlyToClient);
	SendMonsterHurtRate(OnlyToClient);
	SendMonsterSufferRate(OnlyToClient);
	SendBossHurtRate(OnlyToClient);
	SendBossSufferRate(OnlyToClient);
	SendDodgReduceValue(OnlyToClient);
	SendDodgReduceRate(OnlyToClient);
	SendDodgAddValue(OnlyToClient);
	SendDodgAddRate(OnlyToClient);
	SendTreasureFootPrint(OnlyToClient);
	SendEquipTitle(OnlyToClient);
	SendObjAnimEvent(OnlyToClient);
	SendPinchData(OnlyToClient);
	SendSkillCDRate(OnlyToClient);
	SendAspdRate(OnlyToClient);
	SendShield(OnlyToClient);
	SendEventLeftCount(OnlyToClient);
	SendCanNotRush(OnlyToClient);
	SendHuntPoint(OnlyToClient);
	SendHuntHighTimes(OnlyToClient);
	SendHuntFirePoint(OnlyToClient);
	SendStarbattlestate(OnlyToClient);
	SendIgnoreMotionBlock(OnlyToClient);
	SendEnableInteract(OnlyToClient);
	SendWorldMedal(OnlyToClient);
	SendCureCeiling(OnlyToClient);
	SendRelationUnionCurrency(OnlyToClient);
	SendGuildShortName(OnlyToClient);
	SendGuildShortColorID(OnlyToClient);

**/
	if (!m_pObj->GetLoadComplte())
    {
        return;
    }
	CalcChangeMethodCB();
	if (!m_bChange)
	{
		return;
	}
	if (m_oSendCallback)
	{
		m_bChange = false;
		m_oSendCallback(&m_ClientDataUserData);
		m_ClientDataUserData.Clear();

	}

}

void SyncDataBaseAttrV1::SendToOthers()
{
	CalcChangeMethodCB();
	if (!m_bOtherChange)
		return;
	if (m_oSendOtherCallback)
	{
		m_bOtherChange = false;
		m_oSendOtherCallback(&m_OtherDataUserData);

	}
	m_OtherDataUserData.Clear();
}

Property SyncDataBaseAttrV1::GetAttrByType(int attrType)
{
	switch(attrType)
	{
	case SYNCID_BASEATTR_EXP:
		return GetExp();
	case SYNCID_BASEATTR_LEVEL:
		return GetLevel();
	case SYNCID_BASEATTR_SERVERTIME:
		return GetServerTime();
	case SYNCID_BASEATTR_ROLEID:
		return GetRoleId();
	case SYNCID_BASEATTR_STRENGTH:
		return GetStrength();
	case SYNCID_BASEATTR_AGILITY:
		return GetAgility();
	case SYNCID_BASEATTR_INTELLECTUAL:
		return GetIntellectual();
	case SYNCID_BASEATTR_ENDURANCE:
		return GetEndurance();
	case SYNCID_BASEATTR_HP:
		return GetHp();
	case SYNCID_BASEATTR_MAXHP:
		return GetMaxHp();
	case SYNCID_BASEATTR_PHYSICATTACK:
		return GetPhysicAttack();
	case SYNCID_BASEATTR_PHYSICDEFENSE:
		return GetPhysicDefense();
	case SYNCID_BASEATTR_MAGICATTACK:
		return GetMagicAttack();
	case SYNCID_BASEATTR_MAGICDEFENSE:
		return GetMagicDefense();
	case SYNCID_BASEATTR_HIT:
		return GetHit();
	case SYNCID_BASEATTR_HITRATE:
		return GetHitRate();
	case SYNCID_BASEATTR_MISS:
		return GetMiss();
	case SYNCID_BASEATTR_MISSRATE:
		return GetMissRate();
	case SYNCID_BASEATTR_CRITICAL:
		return GetCritical();
	case SYNCID_BASEATTR_CRITICALRATE:
		return GetCriticalRate();
	case SYNCID_BASEATTR_TENACITY:
		return GetTenacity();
	case SYNCID_BASEATTR_TENACITYRATE:
		return GetTenacityRate();
	case SYNCID_BASEATTR_PENET:
		return GetPenet();
	case SYNCID_BASEATTR_PENETRATE:
		return GetPenetRate();
	case SYNCID_BASEATTR_DODG:
		return GetDodg();
	case SYNCID_BASEATTR_DODGRATE:
		return GetDodgRate();
	case SYNCID_BASEATTR_CRITICALADDITION:
		return GetCriticalAddition();
	case SYNCID_BASEATTR_CRITICALADDITIONRATE:
		return GetCriticalAdditionRate();
	case SYNCID_BASEATTR_CRITICALIMMUNE:
		return GetCriticalImmune();
	case SYNCID_BASEATTR_CRITICALIMMUNERATE:
		return GetCriticalImmuneRate();
	case SYNCID_BASEATTR_MISSLEVEL:
		return GetMissLevel();
	case SYNCID_BASEATTR_CRITICALLEVEL:
		return GetCriticalLevel();
	case SYNCID_BASEATTR_DODGLEVEL:
		return GetDodgLevel();
	case SYNCID_BASEATTR_MOVESPEED:
		return GetMoveSpeed();
	case SYNCID_BASEATTR_DIZZYSTATE:
		return GetDizzyState();
	case SYNCID_BASEATTR_GODSTATE:
		return GetGodState();
	case SYNCID_BASEATTR_CANTMOVESTATE:
		return GetCantMoveState();
	case SYNCID_BASEATTR_PHYSICADDITION:
		return GetPhysicAddition();
	case SYNCID_BASEATTR_MAGICADDITION:
		return GetMagicAddition();
	case SYNCID_BASEATTR_PHYSICOPPOSE:
		return GetPhysicOppose();
	case SYNCID_BASEATTR_MAGICOPPOSE:
		return GetMagicOppose();
	case SYNCID_BASEATTR_ACCUMULATESKIENERGY:
		return GetAccumulateSkiEnergy();
	case SYNCID_BASEATTR_NICKNAME:
		return GetNickName();
	case SYNCID_BASEATTR_CONFIGID:
		return GetConfigId();
	case SYNCID_BASEATTR_OBJTYPE:
		return GetObjType();
	case SYNCID_BASEATTR_STATE:
		return GetState();
	case SYNCID_BASEATTR_OWNEROBJID:
		return GetOwnerObjId();
	case SYNCID_BASEATTR_CAMP:
		return GetCamp();
	case SYNCID_BASEATTR_SILVERMONEY:
		return GetSilverMoney();
	case SYNCID_BASEATTR_GOLDMONEY:
		return GetGoldMoney();
	case SYNCID_BASEATTR_DIAMONDMONEY:
		return GetDiamondMoney();
	case SYNCID_BASEATTR_BINDINGDIAMONDMONEY:
		return GetBindingDiamondMoney();
	case SYNCID_BASEATTR_BATTLESCORE:
		return GetBattleScore();
	case SYNCID_BASEATTR_ENERGY:
		return GetEnergy();
	case SYNCID_BASEATTR_GUILDMONEY:
		return GetGuildMoney();
	case SYNCID_BASEATTR_SKILLLIST:
		return GetSkillList();
	case SYNCID_BASEATTR_HONORMONEY:
		return GetHonorMoney();
	case SYNCID_BASEATTR_RESOURCEPOOLHP:
		return GetResourcePoolHp();
	case SYNCID_BASEATTR_ATTACKADD:
		return GetAttackAdd();
	case SYNCID_BASEATTR_INJURYADD:
		return GetInjuryAdd();
	case SYNCID_BASEATTR_FROZENSTATE:
		return GetFrozenState();
	case SYNCID_BASEATTR_SILENTSTATE:
		return GetSilentState();
	case SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX:
		return GetGuildContributeHistoryMax();
	case SYNCID_BASEATTR_TEAMID:
		return GetTeamId();
	case SYNCID_BASEATTR_TREASUREHAIR:
		return GetTreasureHair();
	case SYNCID_BASEATTR_TREASUREHEAD:
		return GetTreasureHead();
	case SYNCID_BASEATTR_TREASUREBODY:
		return GetTreasureBody();
	case SYNCID_BASEATTR_TREASUREWEAPON:
		return GetTreasureWeapon();
	case SYNCID_BASEATTR_TREASUREWING:
		return GetTreasureWing();
	case SYNCID_BASEATTR_GUILDGUID:
		return GetGuildGuid();
	case SYNCID_BASEATTR_TREASURERIDING:
		return GetTreasureRiding();
	case SYNCID_BASEATTR_VECHICLEID:
		return GetVechicleId();
	case SYNCID_BASEATTR_ANIMATIONSTATE:
		return GetAnimationState();
	case SYNCID_BASEATTR_REFIXDMGRATE:
		return GetRefixDmgRate();
	case SYNCID_BASEATTR_REFIXDMGVALUE:
		return GetRefixDmgValue();
	case SYNCID_BASEATTR_REFIXHURTRATE:
		return GetRefixHurtRate();
	case SYNCID_BASEATTR_REFIXHURTVALUE:
		return GetRefixHurtValue();
	case SYNCID_BASEATTR_REFIXHEALRATE:
		return GetRefixHealRate();
	case SYNCID_BASEATTR_REFIXHEALVALUE:
		return GetRefixHealValue();
	case SYNCID_BASEATTR_REFIXCUREDRATE:
		return GetRefixCuredRate();
	case SYNCID_BASEATTR_REFIXCUREDVALUE:
		return GetRefixCuredValue();
	case SYNCID_BASEATTR_GUILDCONTRIBUTE:
		return GetGuildContribute();
	case SYNCID_BASEATTR_PVPMONEY:
		return GetPvpMoney();
	case SYNCID_BASEATTR_GUILDRESOURCE:
		return GetGuildResource();
	case SYNCID_BASEATTR_CREATEROLETIME:
		return GetCreateRoleTime();
	case SYNCID_BASEATTR_UPDATEROLETIME:
		return GetUpdateRoleTime();
	case SYNCID_BASEATTR_FIGHTSTATE:
		return GetFightState();
	case SYNCID_BASEATTR_ATTACKSKILLLIST:
		return GetAttackSkillList();
	case SYNCID_BASEATTR_GUILDNAME:
		return GetGuildName();
	case SYNCID_BASEATTR_ISALLOWSELECT:
		return GetIsAllowSelect();
	case SYNCID_BASEATTR_GOHOMESTATE:
		return GetGoHomeState();
	case SYNCID_BASEATTR_CANFIGHT:
		return GetCanFight();
	case SYNCID_BASEATTR_DOUBLEEXP:
		return GetDoubleExp();
	case SYNCID_BASEATTR_FRIENDPOINT:
		return GetFriendPoint();
	case SYNCID_BASEATTR_HISMAXHONOR:
		return GetHisMaxHonor();
	case SYNCID_BASEATTR_HURTSTATE:
		return GetHurtState();
	case SYNCID_BASEATTR_HURTFLYSTATE:
		return GetHurtFlyState();
	case SYNCID_BASEATTR_HURTDOWNSTATE:
		return GetHurtDownState();
	case SYNCID_BASEATTR_HURTREPELSTATE:
		return GetHurtRepelState();
	case SYNCID_BASEATTR_TODAYHORNOR:
		return GetTodayHornor();
	case SYNCID_BASEATTR_CURPROFESSION:
		return GetCurProfession();
	case SYNCID_BASEATTR_PETCREATEDELCOND:
		return GetPetCreateDelCond();
	case SYNCID_BASEATTR_PETDISPLAY:
		return GetPetDisplay();
	case SYNCID_BASEATTR_PETMONEY:
		return GetPetMoney();
	case SYNCID_BASEATTR_DUELSTATUS:
		return GetDuelStatus();
	case SYNCID_BASEATTR_EXPPOOL:
		return GetExpPool();
	case SYNCID_BASEATTR_RUSHSTATE:
		return GetRushState();
	case SYNCID_BASEATTR_STARESTATE:
		return GetStareState();
	case SYNCID_BASEATTR_WORLDLEVEL:
		return GetWorldLevel();
	case SYNCID_BASEATTR_DIZZYHITRATE:
		return GetDizzyHitRate();
	case SYNCID_BASEATTR_DIZZYRESISTRATE:
		return GetDizzyResistRate();
	case SYNCID_BASEATTR_IMMOVABLEHITRATE:
		return GetImmovableHitRate();
	case SYNCID_BASEATTR_IMMOVABLERESISTRATE:
		return GetImmovableResistRate();
	case SYNCID_BASEATTR_HURTFLYHITRATE:
		return GetHurtFlyHitRate();
	case SYNCID_BASEATTR_HURTFLYRESISTRATE:
		return GetHurtFlyResistRate();
	case SYNCID_BASEATTR_FROZENHITRATE:
		return GetFrozenHitRate();
	case SYNCID_BASEATTR_FROZENRESISTRATE:
		return GetFrozenResistRate();
	case SYNCID_BASEATTR_CLEANHITRATE:
		return GetCleanHitRate();
	case SYNCID_BASEATTR_CLEANRESISTRATE:
		return GetCleanResistRate();
	case SYNCID_BASEATTR_DISPELHITRATE:
		return GetDispelHitRate();
	case SYNCID_BASEATTR_DISPELRESISTRATE:
		return GetDispelResistRate();
	case SYNCID_BASEATTR_SILENCEHITRATE:
		return GetSilenceHitRate();
	case SYNCID_BASEATTR_SILENCERESISTRATE:
		return GetSilenceResistRate();
	case SYNCID_BASEATTR_INTERRUPTHITRATE:
		return GetInterruptHitRate();
	case SYNCID_BASEATTR_INTERRUPTRESISTRATE:
		return GetInterruptResistRate();
	case SYNCID_BASEATTR_UNCURABLEHITRATE:
		return GetUncurableHitRate();
	case SYNCID_BASEATTR_UNCURABLERESISTRATE:
		return GetUncurableResistRate();
	case SYNCID_BASEATTR_TRANSFORM:
		return GetTransform();
	case SYNCID_BASEATTR_HUMANHURTRATE:
		return GetHumanHurtRate();
	case SYNCID_BASEATTR_HUMANSUFFERRATE:
		return GetHumanSufferRate();
	case SYNCID_BASEATTR_MONSTERHURTRATE:
		return GetMonsterHurtRate();
	case SYNCID_BASEATTR_MONSTERSUFFERRATE:
		return GetMonsterSufferRate();
	case SYNCID_BASEATTR_BOSSHURTRATE:
		return GetBossHurtRate();
	case SYNCID_BASEATTR_BOSSSUFFERRATE:
		return GetBossSufferRate();
	case SYNCID_BASEATTR_DODGREDUCEVALUE:
		return GetDodgReduceValue();
	case SYNCID_BASEATTR_DODGREDUCERATE:
		return GetDodgReduceRate();
	case SYNCID_BASEATTR_DODGADDVALUE:
		return GetDodgAddValue();
	case SYNCID_BASEATTR_DODGADDRATE:
		return GetDodgAddRate();
	case SYNCID_BASEATTR_TREASUREFOOTPRINT:
		return GetTreasureFootPrint();
	case SYNCID_BASEATTR_EQUIPTITLE:
		return GetEquipTitle();
	case SYNCID_BASEATTR_OBJANIMEVENT:
		return GetObjAnimEvent();
	case SYNCID_BASEATTR_PINCHDATA:
		return GetPinchData();
	case SYNCID_BASEATTR_SKILLCDRATE:
		return GetSkillCDRate();
	case SYNCID_BASEATTR_ASPDRATE:
		return GetAspdRate();
	case SYNCID_BASEATTR_SHIELD:
		return GetShield();
	case SYNCID_BASEATTR_EVENTLEFTCOUNT:
		return GetEventLeftCount();
	case SYNCID_BASEATTR_CANNOTRUSH:
		return GetCanNotRush();
	case SYNCID_BASEATTR_HUNTPOINT:
		return GetHuntPoint();
	case SYNCID_BASEATTR_HUNTHIGHTIMES:
		return GetHuntHighTimes();
	case SYNCID_BASEATTR_HUNTFIREPOINT:
		return GetHuntFirePoint();
	case SYNCID_BASEATTR_STARBATTLESTATE:
		return GetStarbattlestate();
	case SYNCID_BASEATTR_IGNOREMOTIONBLOCK:
		return GetIgnoreMotionBlock();
	case SYNCID_BASEATTR_ENABLEINTERACT:
		return GetEnableInteract();
	case SYNCID_BASEATTR_WORLDMEDAL:
		return GetWorldMedal();
	case SYNCID_BASEATTR_CURECEILING:
		return GetCureCeiling();
	case SYNCID_BASEATTR_RELATIONUNIONCURRENCY:
		return GetRelationUnionCurrency();
	case SYNCID_BASEATTR_GUILDSHORTNAME:
		return GetGuildShortName();
	case SYNCID_BASEATTR_GUILDSHORTCOLORID:
		return GetGuildShortColorID();

	}
	return 0;
}

void 	SyncDataBaseAttrV1::GetCompletePlayerData(BaseAttrUserDataV1& base)
{

		base.set_exp(GetExp());
	base.set_level(GetLevel());
	base.set_servertime(GetServerTime());
	base.set_roleid(GetRoleId());
	base.set_strength(GetStrength());
	base.set_agility(GetAgility());
	base.set_intellectual(GetIntellectual());
	base.set_endurance(GetEndurance());
	base.set_hp(GetHp());
	base.set_maxhp(GetMaxHp());
	base.set_physicattack(GetPhysicAttack());
	base.set_physicdefense(GetPhysicDefense());
	base.set_magicattack(GetMagicAttack());
	base.set_magicdefense(GetMagicDefense());
	base.set_hit(GetHit());
	base.set_hitrate(GetHitRate());
	base.set_miss(GetMiss());
	base.set_missrate(GetMissRate());
	base.set_critical(GetCritical());
	base.set_criticalrate(GetCriticalRate());
	base.set_tenacity(GetTenacity());
	base.set_tenacityrate(GetTenacityRate());
	base.set_penet(GetPenet());
	base.set_penetrate(GetPenetRate());
	base.set_dodg(GetDodg());
	base.set_dodgrate(GetDodgRate());
	base.set_criticaladdition(GetCriticalAddition());
	base.set_criticaladditionrate(GetCriticalAdditionRate());
	base.set_criticalimmune(GetCriticalImmune());
	base.set_criticalimmunerate(GetCriticalImmuneRate());
	base.set_misslevel(GetMissLevel());
	base.set_criticallevel(GetCriticalLevel());
	base.set_dodglevel(GetDodgLevel());
	base.set_movespeed(GetMoveSpeed());
	base.set_dizzystate(GetDizzyState());
	base.set_godstate(GetGodState());
	base.set_cantmovestate(GetCantMoveState());
	base.set_physicaddition(GetPhysicAddition());
	base.set_magicaddition(GetMagicAddition());
	base.set_physicoppose(GetPhysicOppose());
	base.set_magicoppose(GetMagicOppose());
	base.set_accumulateskienergy(GetAccumulateSkiEnergy());
	base.set_nickname(GetNickName());
	base.set_configid(GetConfigId());
	base.set_objtype(GetObjType());
	base.set_state(GetState());
	base.set_ownerobjid(GetOwnerObjId());
	base.set_camp(GetCamp());
	base.set_silvermoney(GetSilverMoney());
	base.set_goldmoney(GetGoldMoney());
	base.set_diamondmoney(GetDiamondMoney());
	base.set_bindingdiamondmoney(GetBindingDiamondMoney());
	base.set_battlescore(GetBattleScore());
	base.set_energy(GetEnergy());
	base.set_guildmoney(GetGuildMoney());
	const vector<INT32>& vSkillList = GetSkillList();
	for (int i = 0; i < vSkillList.size(); ++i)
		base.mutable_skilllist()->Add(vSkillList[i]);
	base.set_honormoney(GetHonorMoney());
	base.set_resourcepoolhp(GetResourcePoolHp());
	base.set_attackadd(GetAttackAdd());
	base.set_injuryadd(GetInjuryAdd());
	base.set_frozenstate(GetFrozenState());
	base.set_silentstate(GetSilentState());
	base.set_guildcontributehistorymax(GetGuildContributeHistoryMax());
	base.set_teamid(GetTeamId());
	base.set_treasurehair(GetTreasureHair());
	base.set_treasurehead(GetTreasureHead());
	base.set_treasurebody(GetTreasureBody());
	base.set_treasureweapon(GetTreasureWeapon());
	base.set_treasurewing(GetTreasureWing());
	base.set_guildguid(GetGuildGuid());
	base.set_treasureriding(GetTreasureRiding());
	base.set_vechicleid(GetVechicleId());
	base.set_animationstate(GetAnimationState());
	base.set_refixdmgrate(GetRefixDmgRate());
	base.set_refixdmgvalue(GetRefixDmgValue());
	base.set_refixhurtrate(GetRefixHurtRate());
	base.set_refixhurtvalue(GetRefixHurtValue());
	base.set_refixhealrate(GetRefixHealRate());
	base.set_refixhealvalue(GetRefixHealValue());
	base.set_refixcuredrate(GetRefixCuredRate());
	base.set_refixcuredvalue(GetRefixCuredValue());
	base.set_guildcontribute(GetGuildContribute());
	base.set_pvpmoney(GetPvpMoney());
	base.set_guildresource(GetGuildResource());
	base.set_createroletime(GetCreateRoleTime());
	base.set_updateroletime(GetUpdateRoleTime());
	base.set_fightstate(GetFightState());
	const vector<INT32>& vAttackSkillList = GetAttackSkillList();
	for (int i = 0; i < vAttackSkillList.size(); ++i)
		base.mutable_attackskilllist()->Add(vAttackSkillList[i]);
	base.set_guildname(GetGuildName());
	base.set_isallowselect(GetIsAllowSelect());
	base.set_gohomestate(GetGoHomeState());
	base.set_canfight(GetCanFight());
	base.set_doubleexp(GetDoubleExp());
	base.set_friendpoint(GetFriendPoint());
	base.set_hismaxhonor(GetHisMaxHonor());
	base.set_hurtstate(GetHurtState());
	base.set_hurtflystate(GetHurtFlyState());
	base.set_hurtdownstate(GetHurtDownState());
	base.set_hurtrepelstate(GetHurtRepelState());
	base.set_todayhornor(GetTodayHornor());
	base.set_curprofession(GetCurProfession());
	base.set_petcreatedelcond(GetPetCreateDelCond());
	base.set_petdisplay(GetPetDisplay());
	base.set_petmoney(GetPetMoney());
	base.set_duelstatus(GetDuelStatus());
	base.set_exppool(GetExpPool());
	base.set_rushstate(GetRushState());
	base.set_starestate(GetStareState());
	base.set_worldlevel(GetWorldLevel());
	base.set_dizzyhitrate(GetDizzyHitRate());
	base.set_dizzyresistrate(GetDizzyResistRate());
	base.set_immovablehitrate(GetImmovableHitRate());
	base.set_immovableresistrate(GetImmovableResistRate());
	base.set_hurtflyhitrate(GetHurtFlyHitRate());
	base.set_hurtflyresistrate(GetHurtFlyResistRate());
	base.set_frozenhitrate(GetFrozenHitRate());
	base.set_frozenresistrate(GetFrozenResistRate());
	base.set_cleanhitrate(GetCleanHitRate());
	base.set_cleanresistrate(GetCleanResistRate());
	base.set_dispelhitrate(GetDispelHitRate());
	base.set_dispelresistrate(GetDispelResistRate());
	base.set_silencehitrate(GetSilenceHitRate());
	base.set_silenceresistrate(GetSilenceResistRate());
	base.set_interrupthitrate(GetInterruptHitRate());
	base.set_interruptresistrate(GetInterruptResistRate());
	base.set_uncurablehitrate(GetUncurableHitRate());
	base.set_uncurableresistrate(GetUncurableResistRate());
	base.set_transform(GetTransform());
	base.set_humanhurtrate(GetHumanHurtRate());
	base.set_humansufferrate(GetHumanSufferRate());
	base.set_monsterhurtrate(GetMonsterHurtRate());
	base.set_monstersufferrate(GetMonsterSufferRate());
	base.set_bosshurtrate(GetBossHurtRate());
	base.set_bosssufferrate(GetBossSufferRate());
	base.set_dodgreducevalue(GetDodgReduceValue());
	base.set_dodgreducerate(GetDodgReduceRate());
	base.set_dodgaddvalue(GetDodgAddValue());
	base.set_dodgaddrate(GetDodgAddRate());
	base.set_treasurefootprint(GetTreasureFootPrint());
	base.set_equiptitle(GetEquipTitle());
	const vector<INT32>& vObjAnimEvent = GetObjAnimEvent();
	for (int i = 0; i < vObjAnimEvent.size(); ++i)
		base.mutable_objanimevent()->Add(vObjAnimEvent[i]);
	base.set_pinchdata(GetPinchData());
	base.set_skillcdrate(GetSkillCDRate());
	base.set_aspdrate(GetAspdRate());
	base.set_shield(GetShield());
	base.set_eventleftcount(GetEventLeftCount());
	base.set_cannotrush(GetCanNotRush());
	base.set_huntpoint(GetHuntPoint());
	base.set_hunthightimes(GetHuntHighTimes());
	base.set_huntfirepoint(GetHuntFirePoint());
	base.set_starbattlestate(GetStarbattlestate());
	base.set_ignoremotionblock(GetIgnoreMotionBlock());
	base.set_enableinteract(GetEnableInteract());
	base.set_worldmedal(GetWorldMedal());
	base.set_cureceiling(GetCureCeiling());
	base.set_relationunioncurrency(GetRelationUnionCurrency());
	base.set_guildshortname(GetGuildShortName());
	base.set_guildshortcolorid(GetGuildShortColorID());


	
}

void SyncDataBaseAttrV1::AfterCallback(int32_t nType)
{
	if (!m_pObj->GetLoadComplte())
    {
        return;
    }
	auto afterfi = m_v_AfterCalcCallBackList.find(nType);
	if (afterfi != m_v_AfterCalcCallBackList.end())
	{
		for (auto& af : afterfi->second)
		{
			af();
		}
	}
}


//经验
void SyncDataBaseAttrV1::SetExp( const INT32& v )
{
	m_syncDataUserData.SetExp(v);
	m_ClientDataUserData.set_exp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_EXP))
	{
		m_OtherDataUserData.set_exp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetExp()
{
	CalcMethodCB(SYNCID_BASEATTR_EXP,std::bind(&SyncDataBaseAttrV1::SetExp,this,std::placeholders::_1));
	return m_syncDataUserData.GetExp();
}
void SyncDataBaseAttrV1::RefreshExp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_EXP);
}


//玩家等级
void SyncDataBaseAttrV1::SetLevel( const INT32& v )
{
	m_syncDataUserData.SetLevel(v);
	m_ClientDataUserData.set_level(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_LEVEL))
	{
		m_OtherDataUserData.set_level(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetLevel()
{
	CalcMethodCB(SYNCID_BASEATTR_LEVEL,std::bind(&SyncDataBaseAttrV1::SetLevel,this,std::placeholders::_1));
	return m_syncDataUserData.GetLevel();
}
void SyncDataBaseAttrV1::RefreshLevel()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_LEVEL);
}


//服务器时间
void SyncDataBaseAttrV1::SetServerTime( const INT32& v )
{
	m_syncDataUserData.SetServerTime(v);
	m_ClientDataUserData.set_servertime(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SERVERTIME))
	{
		m_OtherDataUserData.set_servertime(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetServerTime()
{
	CalcMethodCB(SYNCID_BASEATTR_SERVERTIME,std::bind(&SyncDataBaseAttrV1::SetServerTime,this,std::placeholders::_1));
	return m_syncDataUserData.GetServerTime();
}
void SyncDataBaseAttrV1::RefreshServerTime()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SERVERTIME);
}


//人物唯一ID
void SyncDataBaseAttrV1::SetRoleId( const uint64_t& v )
{
	m_syncDataUserData.SetRoleId(v);
	m_ClientDataUserData.set_roleid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ROLEID))
	{
		m_OtherDataUserData.set_roleid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
uint64_t SyncDataBaseAttrV1::GetRoleId()
{
	CalcMethodCB(SYNCID_BASEATTR_ROLEID,std::bind(&SyncDataBaseAttrV1::SetRoleId,this,std::placeholders::_1));
	return m_syncDataUserData.GetRoleId();
}
void SyncDataBaseAttrV1::RefreshRoleId()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ROLEID);
}


//力量
void SyncDataBaseAttrV1::SetStrength( const INT32& v )
{
	m_syncDataUserData.SetStrength(v);
	m_ClientDataUserData.set_strength(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_STRENGTH))
	{
		m_OtherDataUserData.set_strength(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetStrength()
{
	CalcMethodCB(SYNCID_BASEATTR_STRENGTH,std::bind(&SyncDataBaseAttrV1::SetStrength,this,std::placeholders::_1));
	return m_syncDataUserData.GetStrength();
}
void SyncDataBaseAttrV1::RefreshStrength()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_STRENGTH);
}


//敏捷
void SyncDataBaseAttrV1::SetAgility( const INT32& v )
{
	m_syncDataUserData.SetAgility(v);
	m_ClientDataUserData.set_agility(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_AGILITY))
	{
		m_OtherDataUserData.set_agility(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetAgility()
{
	CalcMethodCB(SYNCID_BASEATTR_AGILITY,std::bind(&SyncDataBaseAttrV1::SetAgility,this,std::placeholders::_1));
	return m_syncDataUserData.GetAgility();
}
void SyncDataBaseAttrV1::RefreshAgility()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_AGILITY);
}


//智力
void SyncDataBaseAttrV1::SetIntellectual( const INT32& v )
{
	m_syncDataUserData.SetIntellectual(v);
	m_ClientDataUserData.set_intellectual(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_INTELLECTUAL))
	{
		m_OtherDataUserData.set_intellectual(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetIntellectual()
{
	CalcMethodCB(SYNCID_BASEATTR_INTELLECTUAL,std::bind(&SyncDataBaseAttrV1::SetIntellectual,this,std::placeholders::_1));
	return m_syncDataUserData.GetIntellectual();
}
void SyncDataBaseAttrV1::RefreshIntellectual()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_INTELLECTUAL);
}


//耐力
void SyncDataBaseAttrV1::SetEndurance( const INT32& v )
{
	m_syncDataUserData.SetEndurance(v);
	m_ClientDataUserData.set_endurance(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ENDURANCE))
	{
		m_OtherDataUserData.set_endurance(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetEndurance()
{
	CalcMethodCB(SYNCID_BASEATTR_ENDURANCE,std::bind(&SyncDataBaseAttrV1::SetEndurance,this,std::placeholders::_1));
	return m_syncDataUserData.GetEndurance();
}
void SyncDataBaseAttrV1::RefreshEndurance()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ENDURANCE);
}


//生命值
void SyncDataBaseAttrV1::SetHp( const INT32& v )
{
	m_syncDataUserData.SetHp(v);
	m_ClientDataUserData.set_hp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HP))
	{
		m_OtherDataUserData.set_hp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetHp()
{
	CalcMethodCB(SYNCID_BASEATTR_HP,std::bind(&SyncDataBaseAttrV1::SetHp,this,std::placeholders::_1));
	return m_syncDataUserData.GetHp();
}
void SyncDataBaseAttrV1::RefreshHp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HP);
}


//生命值
void SyncDataBaseAttrV1::SetMaxHp( const INT32& v )
{
	m_syncDataUserData.SetMaxHp(v);
	m_ClientDataUserData.set_maxhp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MAXHP))
	{
		m_OtherDataUserData.set_maxhp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetMaxHp()
{
	CalcMethodCB(SYNCID_BASEATTR_MAXHP,std::bind(&SyncDataBaseAttrV1::SetMaxHp,this,std::placeholders::_1));
	return m_syncDataUserData.GetMaxHp();
}
void SyncDataBaseAttrV1::RefreshMaxHp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MAXHP);
}


//物理攻击
void SyncDataBaseAttrV1::SetPhysicAttack( const INT32& v )
{
	m_syncDataUserData.SetPhysicAttack(v);
	m_ClientDataUserData.set_physicattack(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PHYSICATTACK))
	{
		m_OtherDataUserData.set_physicattack(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetPhysicAttack()
{
	CalcMethodCB(SYNCID_BASEATTR_PHYSICATTACK,std::bind(&SyncDataBaseAttrV1::SetPhysicAttack,this,std::placeholders::_1));
	return m_syncDataUserData.GetPhysicAttack();
}
void SyncDataBaseAttrV1::RefreshPhysicAttack()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PHYSICATTACK);
}


//物理防御
void SyncDataBaseAttrV1::SetPhysicDefense( const INT32& v )
{
	m_syncDataUserData.SetPhysicDefense(v);
	m_ClientDataUserData.set_physicdefense(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PHYSICDEFENSE))
	{
		m_OtherDataUserData.set_physicdefense(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetPhysicDefense()
{
	CalcMethodCB(SYNCID_BASEATTR_PHYSICDEFENSE,std::bind(&SyncDataBaseAttrV1::SetPhysicDefense,this,std::placeholders::_1));
	return m_syncDataUserData.GetPhysicDefense();
}
void SyncDataBaseAttrV1::RefreshPhysicDefense()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PHYSICDEFENSE);
}


//魔法攻击
void SyncDataBaseAttrV1::SetMagicAttack( const INT32& v )
{
	m_syncDataUserData.SetMagicAttack(v);
	m_ClientDataUserData.set_magicattack(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MAGICATTACK))
	{
		m_OtherDataUserData.set_magicattack(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetMagicAttack()
{
	CalcMethodCB(SYNCID_BASEATTR_MAGICATTACK,std::bind(&SyncDataBaseAttrV1::SetMagicAttack,this,std::placeholders::_1));
	return m_syncDataUserData.GetMagicAttack();
}
void SyncDataBaseAttrV1::RefreshMagicAttack()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MAGICATTACK);
}


//魔法防御
void SyncDataBaseAttrV1::SetMagicDefense( const INT32& v )
{
	m_syncDataUserData.SetMagicDefense(v);
	m_ClientDataUserData.set_magicdefense(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MAGICDEFENSE))
	{
		m_OtherDataUserData.set_magicdefense(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetMagicDefense()
{
	CalcMethodCB(SYNCID_BASEATTR_MAGICDEFENSE,std::bind(&SyncDataBaseAttrV1::SetMagicDefense,this,std::placeholders::_1));
	return m_syncDataUserData.GetMagicDefense();
}
void SyncDataBaseAttrV1::RefreshMagicDefense()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MAGICDEFENSE);
}


//命中值
void SyncDataBaseAttrV1::SetHit( const INT32& v )
{
	m_syncDataUserData.SetHit(v);
	m_ClientDataUserData.set_hit(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HIT))
	{
		m_OtherDataUserData.set_hit(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetHit()
{
	CalcMethodCB(SYNCID_BASEATTR_HIT,std::bind(&SyncDataBaseAttrV1::SetHit,this,std::placeholders::_1));
	return m_syncDataUserData.GetHit();
}
void SyncDataBaseAttrV1::RefreshHit()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HIT);
}


//命中率
void SyncDataBaseAttrV1::SetHitRate( const float& v )
{
	m_syncDataUserData.SetHitRate(v);
	m_ClientDataUserData.set_hitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HITRATE))
	{
		m_OtherDataUserData.set_hitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_HITRATE,std::bind(&SyncDataBaseAttrV1::SetHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetHitRate();
}
void SyncDataBaseAttrV1::RefreshHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HITRATE);
}


//闪避值
void SyncDataBaseAttrV1::SetMiss( const INT32& v )
{
	m_syncDataUserData.SetMiss(v);
	m_ClientDataUserData.set_miss(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MISS))
	{
		m_OtherDataUserData.set_miss(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetMiss()
{
	CalcMethodCB(SYNCID_BASEATTR_MISS,std::bind(&SyncDataBaseAttrV1::SetMiss,this,std::placeholders::_1));
	return m_syncDataUserData.GetMiss();
}
void SyncDataBaseAttrV1::RefreshMiss()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MISS);
}


//闪避率
void SyncDataBaseAttrV1::SetMissRate( const float& v )
{
	m_syncDataUserData.SetMissRate(v);
	m_ClientDataUserData.set_missrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MISSRATE))
	{
		m_OtherDataUserData.set_missrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMissRate()
{
	CalcMethodCB(SYNCID_BASEATTR_MISSRATE,std::bind(&SyncDataBaseAttrV1::SetMissRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetMissRate();
}
void SyncDataBaseAttrV1::RefreshMissRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MISSRATE);
}


//暴击值
void SyncDataBaseAttrV1::SetCritical( const INT32& v )
{
	m_syncDataUserData.SetCritical(v);
	m_ClientDataUserData.set_critical(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICAL))
	{
		m_OtherDataUserData.set_critical(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCritical()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICAL,std::bind(&SyncDataBaseAttrV1::SetCritical,this,std::placeholders::_1));
	return m_syncDataUserData.GetCritical();
}
void SyncDataBaseAttrV1::RefreshCritical()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICAL);
}


//暴击率
void SyncDataBaseAttrV1::SetCriticalRate( const float& v )
{
	m_syncDataUserData.SetCriticalRate(v);
	m_ClientDataUserData.set_criticalrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALRATE))
	{
		m_OtherDataUserData.set_criticalrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetCriticalRate()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALRATE,std::bind(&SyncDataBaseAttrV1::SetCriticalRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalRate();
}
void SyncDataBaseAttrV1::RefreshCriticalRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALRATE);
}


//韧性值
void SyncDataBaseAttrV1::SetTenacity( const INT32& v )
{
	m_syncDataUserData.SetTenacity(v);
	m_ClientDataUserData.set_tenacity(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TENACITY))
	{
		m_OtherDataUserData.set_tenacity(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTenacity()
{
	CalcMethodCB(SYNCID_BASEATTR_TENACITY,std::bind(&SyncDataBaseAttrV1::SetTenacity,this,std::placeholders::_1));
	return m_syncDataUserData.GetTenacity();
}
void SyncDataBaseAttrV1::RefreshTenacity()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TENACITY);
}


//韧性率
void SyncDataBaseAttrV1::SetTenacityRate( const float& v )
{
	m_syncDataUserData.SetTenacityRate(v);
	m_ClientDataUserData.set_tenacityrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TENACITYRATE))
	{
		m_OtherDataUserData.set_tenacityrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetTenacityRate()
{
	CalcMethodCB(SYNCID_BASEATTR_TENACITYRATE,std::bind(&SyncDataBaseAttrV1::SetTenacityRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetTenacityRate();
}
void SyncDataBaseAttrV1::RefreshTenacityRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TENACITYRATE);
}


//穿透值
void SyncDataBaseAttrV1::SetPenet( const INT32& v )
{
	m_syncDataUserData.SetPenet(v);
	m_ClientDataUserData.set_penet(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PENET))
	{
		m_OtherDataUserData.set_penet(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetPenet()
{
	CalcMethodCB(SYNCID_BASEATTR_PENET,std::bind(&SyncDataBaseAttrV1::SetPenet,this,std::placeholders::_1));
	return m_syncDataUserData.GetPenet();
}
void SyncDataBaseAttrV1::RefreshPenet()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PENET);
}


//穿透率
void SyncDataBaseAttrV1::SetPenetRate( const float& v )
{
	m_syncDataUserData.SetPenetRate(v);
	m_ClientDataUserData.set_penetrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PENETRATE))
	{
		m_OtherDataUserData.set_penetrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetPenetRate()
{
	CalcMethodCB(SYNCID_BASEATTR_PENETRATE,std::bind(&SyncDataBaseAttrV1::SetPenetRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetPenetRate();
}
void SyncDataBaseAttrV1::RefreshPenetRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PENETRATE);
}


//格挡值
void SyncDataBaseAttrV1::SetDodg( const INT32& v )
{
	m_syncDataUserData.SetDodg(v);
	m_ClientDataUserData.set_dodg(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODG))
	{
		m_OtherDataUserData.set_dodg(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDodg()
{
	CalcMethodCB(SYNCID_BASEATTR_DODG,std::bind(&SyncDataBaseAttrV1::SetDodg,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodg();
}
void SyncDataBaseAttrV1::RefreshDodg()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODG);
}


//格挡率
void SyncDataBaseAttrV1::SetDodgRate( const float& v )
{
	m_syncDataUserData.SetDodgRate(v);
	m_ClientDataUserData.set_dodgrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGRATE))
	{
		m_OtherDataUserData.set_dodgrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDodgRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGRATE,std::bind(&SyncDataBaseAttrV1::SetDodgRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgRate();
}
void SyncDataBaseAttrV1::RefreshDodgRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGRATE);
}


//暴击加伤值
void SyncDataBaseAttrV1::SetCriticalAddition( const INT32& v )
{
	m_syncDataUserData.SetCriticalAddition(v);
	m_ClientDataUserData.set_criticaladdition(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALADDITION))
	{
		m_OtherDataUserData.set_criticaladdition(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCriticalAddition()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALADDITION,std::bind(&SyncDataBaseAttrV1::SetCriticalAddition,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalAddition();
}
void SyncDataBaseAttrV1::RefreshCriticalAddition()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALADDITION);
}


//暴击加伤率
void SyncDataBaseAttrV1::SetCriticalAdditionRate( const float& v )
{
	m_syncDataUserData.SetCriticalAdditionRate(v);
	m_ClientDataUserData.set_criticaladditionrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALADDITIONRATE))
	{
		m_OtherDataUserData.set_criticaladditionrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetCriticalAdditionRate()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALADDITIONRATE,std::bind(&SyncDataBaseAttrV1::SetCriticalAdditionRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalAdditionRate();
}
void SyncDataBaseAttrV1::RefreshCriticalAdditionRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALADDITIONRATE);
}


//暴击免伤
void SyncDataBaseAttrV1::SetCriticalImmune( const INT32& v )
{
	m_syncDataUserData.SetCriticalImmune(v);
	m_ClientDataUserData.set_criticalimmune(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALIMMUNE))
	{
		m_OtherDataUserData.set_criticalimmune(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCriticalImmune()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALIMMUNE,std::bind(&SyncDataBaseAttrV1::SetCriticalImmune,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalImmune();
}
void SyncDataBaseAttrV1::RefreshCriticalImmune()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALIMMUNE);
}


//暴击免伤率
void SyncDataBaseAttrV1::SetCriticalImmuneRate( const float& v )
{
	m_syncDataUserData.SetCriticalImmuneRate(v);
	m_ClientDataUserData.set_criticalimmunerate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALIMMUNERATE))
	{
		m_OtherDataUserData.set_criticalimmunerate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetCriticalImmuneRate()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALIMMUNERATE,std::bind(&SyncDataBaseAttrV1::SetCriticalImmuneRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalImmuneRate();
}
void SyncDataBaseAttrV1::RefreshCriticalImmuneRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALIMMUNERATE);
}


//闪避等级
void SyncDataBaseAttrV1::SetMissLevel( const INT32& v )
{
	m_syncDataUserData.SetMissLevel(v);
	m_ClientDataUserData.set_misslevel(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MISSLEVEL))
	{
		m_OtherDataUserData.set_misslevel(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetMissLevel()
{
	CalcMethodCB(SYNCID_BASEATTR_MISSLEVEL,std::bind(&SyncDataBaseAttrV1::SetMissLevel,this,std::placeholders::_1));
	return m_syncDataUserData.GetMissLevel();
}
void SyncDataBaseAttrV1::RefreshMissLevel()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MISSLEVEL);
}


//暴击等级
void SyncDataBaseAttrV1::SetCriticalLevel( const INT32& v )
{
	m_syncDataUserData.SetCriticalLevel(v);
	m_ClientDataUserData.set_criticallevel(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CRITICALLEVEL))
	{
		m_OtherDataUserData.set_criticallevel(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCriticalLevel()
{
	CalcMethodCB(SYNCID_BASEATTR_CRITICALLEVEL,std::bind(&SyncDataBaseAttrV1::SetCriticalLevel,this,std::placeholders::_1));
	return m_syncDataUserData.GetCriticalLevel();
}
void SyncDataBaseAttrV1::RefreshCriticalLevel()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CRITICALLEVEL);
}


//格挡等级
void SyncDataBaseAttrV1::SetDodgLevel( const INT32& v )
{
	m_syncDataUserData.SetDodgLevel(v);
	m_ClientDataUserData.set_dodglevel(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGLEVEL))
	{
		m_OtherDataUserData.set_dodglevel(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDodgLevel()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGLEVEL,std::bind(&SyncDataBaseAttrV1::SetDodgLevel,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgLevel();
}
void SyncDataBaseAttrV1::RefreshDodgLevel()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGLEVEL);
}


//移动速度
void SyncDataBaseAttrV1::SetMoveSpeed( const float& v )
{
	m_syncDataUserData.SetMoveSpeed(v);
	m_ClientDataUserData.set_movespeed(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MOVESPEED))
	{
		m_OtherDataUserData.set_movespeed(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMoveSpeed()
{
	CalcMethodCB(SYNCID_BASEATTR_MOVESPEED,std::bind(&SyncDataBaseAttrV1::SetMoveSpeed,this,std::placeholders::_1));
	return m_syncDataUserData.GetMoveSpeed();
}
void SyncDataBaseAttrV1::RefreshMoveSpeed()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MOVESPEED);
}


//眩晕状态
void SyncDataBaseAttrV1::SetDizzyState( const INT32& v )
{
	m_syncDataUserData.SetDizzyState(v);
	m_ClientDataUserData.set_dizzystate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DIZZYSTATE))
	{
		m_OtherDataUserData.set_dizzystate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDizzyState()
{
	CalcMethodCB(SYNCID_BASEATTR_DIZZYSTATE,std::bind(&SyncDataBaseAttrV1::SetDizzyState,this,std::placeholders::_1));
	return m_syncDataUserData.GetDizzyState();
}
void SyncDataBaseAttrV1::RefreshDizzyState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DIZZYSTATE);
}


//霸体状态
void SyncDataBaseAttrV1::SetGodState( const bool& v )
{
	m_syncDataUserData.SetGodState(v);
	m_ClientDataUserData.set_godstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GODSTATE))
	{
		m_OtherDataUserData.set_godstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetGodState()
{
	CalcMethodCB(SYNCID_BASEATTR_GODSTATE,std::bind(&SyncDataBaseAttrV1::SetGodState,this,std::placeholders::_1));
	return m_syncDataUserData.GetGodState();
}
void SyncDataBaseAttrV1::RefreshGodState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GODSTATE);
}


//不能移动状态
void SyncDataBaseAttrV1::SetCantMoveState( const INT32& v )
{
	m_syncDataUserData.SetCantMoveState(v);
	m_ClientDataUserData.set_cantmovestate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CANTMOVESTATE))
	{
		m_OtherDataUserData.set_cantmovestate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCantMoveState()
{
	CalcMethodCB(SYNCID_BASEATTR_CANTMOVESTATE,std::bind(&SyncDataBaseAttrV1::SetCantMoveState,this,std::placeholders::_1));
	return m_syncDataUserData.GetCantMoveState();
}
void SyncDataBaseAttrV1::RefreshCantMoveState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CANTMOVESTATE);
}


//物理加伤值
void SyncDataBaseAttrV1::SetPhysicAddition( const float& v )
{
	m_syncDataUserData.SetPhysicAddition(v);
	m_ClientDataUserData.set_physicaddition(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PHYSICADDITION))
	{
		m_OtherDataUserData.set_physicaddition(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetPhysicAddition()
{
	CalcMethodCB(SYNCID_BASEATTR_PHYSICADDITION,std::bind(&SyncDataBaseAttrV1::SetPhysicAddition,this,std::placeholders::_1));
	return m_syncDataUserData.GetPhysicAddition();
}
void SyncDataBaseAttrV1::RefreshPhysicAddition()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PHYSICADDITION);
}


//魔法加伤值
void SyncDataBaseAttrV1::SetMagicAddition( const float& v )
{
	m_syncDataUserData.SetMagicAddition(v);
	m_ClientDataUserData.set_magicaddition(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MAGICADDITION))
	{
		m_OtherDataUserData.set_magicaddition(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMagicAddition()
{
	CalcMethodCB(SYNCID_BASEATTR_MAGICADDITION,std::bind(&SyncDataBaseAttrV1::SetMagicAddition,this,std::placeholders::_1));
	return m_syncDataUserData.GetMagicAddition();
}
void SyncDataBaseAttrV1::RefreshMagicAddition()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MAGICADDITION);
}


//物理抗性
void SyncDataBaseAttrV1::SetPhysicOppose( const float& v )
{
	m_syncDataUserData.SetPhysicOppose(v);
	m_ClientDataUserData.set_physicoppose(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PHYSICOPPOSE))
	{
		m_OtherDataUserData.set_physicoppose(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetPhysicOppose()
{
	CalcMethodCB(SYNCID_BASEATTR_PHYSICOPPOSE,std::bind(&SyncDataBaseAttrV1::SetPhysicOppose,this,std::placeholders::_1));
	return m_syncDataUserData.GetPhysicOppose();
}
void SyncDataBaseAttrV1::RefreshPhysicOppose()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PHYSICOPPOSE);
}


//魔法抗性
void SyncDataBaseAttrV1::SetMagicOppose( const float& v )
{
	m_syncDataUserData.SetMagicOppose(v);
	m_ClientDataUserData.set_magicoppose(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MAGICOPPOSE))
	{
		m_OtherDataUserData.set_magicoppose(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMagicOppose()
{
	CalcMethodCB(SYNCID_BASEATTR_MAGICOPPOSE,std::bind(&SyncDataBaseAttrV1::SetMagicOppose,this,std::placeholders::_1));
	return m_syncDataUserData.GetMagicOppose();
}
void SyncDataBaseAttrV1::RefreshMagicOppose()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MAGICOPPOSE);
}


//技能积攒能量使用 目前只有应激技能用
void SyncDataBaseAttrV1::SetAccumulateSkiEnergy( const float& v )
{
	m_syncDataUserData.SetAccumulateSkiEnergy(v);
	m_ClientDataUserData.set_accumulateskienergy(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ACCUMULATESKIENERGY))
	{
		m_OtherDataUserData.set_accumulateskienergy(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetAccumulateSkiEnergy()
{
	CalcMethodCB(SYNCID_BASEATTR_ACCUMULATESKIENERGY,std::bind(&SyncDataBaseAttrV1::SetAccumulateSkiEnergy,this,std::placeholders::_1));
	return m_syncDataUserData.GetAccumulateSkiEnergy();
}
void SyncDataBaseAttrV1::RefreshAccumulateSkiEnergy()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ACCUMULATESKIENERGY);
}


//名字昵称
void SyncDataBaseAttrV1::SetNickName( const string& v )
{
	m_syncDataUserData.SetNickName(v);
	m_ClientDataUserData.set_nickname(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_NICKNAME))
	{
		m_OtherDataUserData.set_nickname(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
string SyncDataBaseAttrV1::GetNickName()
{
	CalcMethodCB(SYNCID_BASEATTR_NICKNAME,std::bind(&SyncDataBaseAttrV1::SetNickName,this,std::placeholders::_1));
	return m_syncDataUserData.GetNickName();
}
void SyncDataBaseAttrV1::RefreshNickName()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_NICKNAME);
}


//config id
void SyncDataBaseAttrV1::SetConfigId( const INT32& v )
{
	m_syncDataUserData.SetConfigId(v);
	m_ClientDataUserData.set_configid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CONFIGID))
	{
		m_OtherDataUserData.set_configid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetConfigId()
{
	CalcMethodCB(SYNCID_BASEATTR_CONFIGID,std::bind(&SyncDataBaseAttrV1::SetConfigId,this,std::placeholders::_1));
	return m_syncDataUserData.GetConfigId();
}
void SyncDataBaseAttrV1::RefreshConfigId()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CONFIGID);
}


//类型
void SyncDataBaseAttrV1::SetObjType( const INT32& v )
{
	m_syncDataUserData.SetObjType(v);
	m_ClientDataUserData.set_objtype(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_OBJTYPE))
	{
		m_OtherDataUserData.set_objtype(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetObjType()
{
	CalcMethodCB(SYNCID_BASEATTR_OBJTYPE,std::bind(&SyncDataBaseAttrV1::SetObjType,this,std::placeholders::_1));
	return m_syncDataUserData.GetObjType();
}
void SyncDataBaseAttrV1::RefreshObjType()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_OBJTYPE);
}


//EventObjStatu
void SyncDataBaseAttrV1::SetState( const INT32& v )
{
	m_syncDataUserData.SetState(v);
	m_ClientDataUserData.set_state(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_STATE))
	{
		m_OtherDataUserData.set_state(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetState()
{
	CalcMethodCB(SYNCID_BASEATTR_STATE,std::bind(&SyncDataBaseAttrV1::SetState,this,std::placeholders::_1));
	return m_syncDataUserData.GetState();
}
void SyncDataBaseAttrV1::RefreshState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_STATE);
}


//归属obj ID
void SyncDataBaseAttrV1::SetOwnerObjId( const uint64_t& v )
{
	m_syncDataUserData.SetOwnerObjId(v);
	m_ClientDataUserData.set_ownerobjid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_OWNEROBJID))
	{
		m_OtherDataUserData.set_ownerobjid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
uint64_t SyncDataBaseAttrV1::GetOwnerObjId()
{
	CalcMethodCB(SYNCID_BASEATTR_OWNEROBJID,std::bind(&SyncDataBaseAttrV1::SetOwnerObjId,this,std::placeholders::_1));
	return m_syncDataUserData.GetOwnerObjId();
}
void SyncDataBaseAttrV1::RefreshOwnerObjId()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_OWNEROBJID);
}


//阵营
void SyncDataBaseAttrV1::SetCamp( const INT32& v )
{
	m_syncDataUserData.SetCamp(v);
	m_ClientDataUserData.set_camp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CAMP))
	{
		m_OtherDataUserData.set_camp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCamp()
{
	CalcMethodCB(SYNCID_BASEATTR_CAMP,std::bind(&SyncDataBaseAttrV1::SetCamp,this,std::placeholders::_1));
	return m_syncDataUserData.GetCamp();
}
void SyncDataBaseAttrV1::RefreshCamp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CAMP);
}


//银币
void SyncDataBaseAttrV1::SetSilverMoney( const int64_t& v )
{
	m_syncDataUserData.SetSilverMoney(v);
	m_ClientDataUserData.set_silvermoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SILVERMONEY))
	{
		m_OtherDataUserData.set_silvermoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetSilverMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_SILVERMONEY,std::bind(&SyncDataBaseAttrV1::SetSilverMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetSilverMoney();
}
void SyncDataBaseAttrV1::RefreshSilverMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SILVERMONEY);
}


//金币
void SyncDataBaseAttrV1::SetGoldMoney( const int64_t& v )
{
	m_syncDataUserData.SetGoldMoney(v);
	m_ClientDataUserData.set_goldmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GOLDMONEY))
	{
		m_OtherDataUserData.set_goldmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetGoldMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_GOLDMONEY,std::bind(&SyncDataBaseAttrV1::SetGoldMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetGoldMoney();
}
void SyncDataBaseAttrV1::RefreshGoldMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GOLDMONEY);
}


//钻石
void SyncDataBaseAttrV1::SetDiamondMoney( const int64_t& v )
{
	m_syncDataUserData.SetDiamondMoney(v);
	m_ClientDataUserData.set_diamondmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DIAMONDMONEY))
	{
		m_OtherDataUserData.set_diamondmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetDiamondMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_DIAMONDMONEY,std::bind(&SyncDataBaseAttrV1::SetDiamondMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetDiamondMoney();
}
void SyncDataBaseAttrV1::RefreshDiamondMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DIAMONDMONEY);
}


//绑定钻石
void SyncDataBaseAttrV1::SetBindingDiamondMoney( const int64_t& v )
{
	m_syncDataUserData.SetBindingDiamondMoney(v);
	m_ClientDataUserData.set_bindingdiamondmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_BINDINGDIAMONDMONEY))
	{
		m_OtherDataUserData.set_bindingdiamondmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetBindingDiamondMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_BINDINGDIAMONDMONEY,std::bind(&SyncDataBaseAttrV1::SetBindingDiamondMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetBindingDiamondMoney();
}
void SyncDataBaseAttrV1::RefreshBindingDiamondMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_BINDINGDIAMONDMONEY);
}


//战力
void SyncDataBaseAttrV1::SetBattleScore( const INT32& v )
{
	m_syncDataUserData.SetBattleScore(v);
	m_ClientDataUserData.set_battlescore(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_BATTLESCORE))
	{
		m_OtherDataUserData.set_battlescore(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetBattleScore()
{
	CalcMethodCB(SYNCID_BASEATTR_BATTLESCORE,std::bind(&SyncDataBaseAttrV1::SetBattleScore,this,std::placeholders::_1));
	return m_syncDataUserData.GetBattleScore();
}
void SyncDataBaseAttrV1::RefreshBattleScore()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_BATTLESCORE);
}


//精力
void SyncDataBaseAttrV1::SetEnergy( const int64_t& v )
{
	m_syncDataUserData.SetEnergy(v);
	m_ClientDataUserData.set_energy(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ENERGY))
	{
		m_OtherDataUserData.set_energy(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetEnergy()
{
	CalcMethodCB(SYNCID_BASEATTR_ENERGY,std::bind(&SyncDataBaseAttrV1::SetEnergy,this,std::placeholders::_1));
	return m_syncDataUserData.GetEnergy();
}
void SyncDataBaseAttrV1::RefreshEnergy()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ENERGY);
}


//公会资金
void SyncDataBaseAttrV1::SetGuildMoney( const int64_t& v )
{
	m_syncDataUserData.SetGuildMoney(v);
	m_ClientDataUserData.set_guildmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDMONEY))
	{
		m_OtherDataUserData.set_guildmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetGuildMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDMONEY,std::bind(&SyncDataBaseAttrV1::SetGuildMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildMoney();
}
void SyncDataBaseAttrV1::RefreshGuildMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDMONEY);
}


//技能列表
void SyncDataBaseAttrV1::SetSkillList( const vector<INT32>& v )
{
	m_syncDataUserData.SetSkillList(v);
	m_ClientDataUserData.clear_skilllist();
	for (auto iter : v)
	{
		m_ClientDataUserData.add_skilllist(iter);
	}
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SKILLLIST))
	{
		m_OtherDataUserData.clear_skilllist();
		for (auto iter : v)
		{
			m_OtherDataUserData.add_skilllist(iter);
		}
		SetOtherChange(true);
	}
	SetChange(true);
}
vector<INT32> SyncDataBaseAttrV1::GetSkillList()
{
	CalcMethodCB(SYNCID_BASEATTR_SKILLLIST,std::bind(&SyncDataBaseAttrV1::SetSkillList,this,std::placeholders::_1));
	return m_syncDataUserData.GetSkillList();
}
void SyncDataBaseAttrV1::RefreshSkillList()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SKILLLIST);
}


//HonorMoney
void SyncDataBaseAttrV1::SetHonorMoney( const int64_t& v )
{
	m_syncDataUserData.SetHonorMoney(v);
	m_ClientDataUserData.set_honormoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HONORMONEY))
	{
		m_OtherDataUserData.set_honormoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetHonorMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_HONORMONEY,std::bind(&SyncDataBaseAttrV1::SetHonorMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetHonorMoney();
}
void SyncDataBaseAttrV1::RefreshHonorMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HONORMONEY);
}


//资源池
void SyncDataBaseAttrV1::SetResourcePoolHp( const int64_t& v )
{
	m_syncDataUserData.SetResourcePoolHp(v);
	m_ClientDataUserData.set_resourcepoolhp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_RESOURCEPOOLHP))
	{
		m_OtherDataUserData.set_resourcepoolhp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetResourcePoolHp()
{
	CalcMethodCB(SYNCID_BASEATTR_RESOURCEPOOLHP,std::bind(&SyncDataBaseAttrV1::SetResourcePoolHp,this,std::placeholders::_1));
	return m_syncDataUserData.GetResourcePoolHp();
}
void SyncDataBaseAttrV1::RefreshResourcePoolHp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_RESOURCEPOOLHP);
}


//伤害增加
void SyncDataBaseAttrV1::SetAttackAdd( const INT32& v )
{
	m_syncDataUserData.SetAttackAdd(v);
	m_ClientDataUserData.set_attackadd(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ATTACKADD))
	{
		m_OtherDataUserData.set_attackadd(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetAttackAdd()
{
	CalcMethodCB(SYNCID_BASEATTR_ATTACKADD,std::bind(&SyncDataBaseAttrV1::SetAttackAdd,this,std::placeholders::_1));
	return m_syncDataUserData.GetAttackAdd();
}
void SyncDataBaseAttrV1::RefreshAttackAdd()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ATTACKADD);
}


//伤害减免
void SyncDataBaseAttrV1::SetInjuryAdd( const INT32& v )
{
	m_syncDataUserData.SetInjuryAdd(v);
	m_ClientDataUserData.set_injuryadd(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_INJURYADD))
	{
		m_OtherDataUserData.set_injuryadd(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetInjuryAdd()
{
	CalcMethodCB(SYNCID_BASEATTR_INJURYADD,std::bind(&SyncDataBaseAttrV1::SetInjuryAdd,this,std::placeholders::_1));
	return m_syncDataUserData.GetInjuryAdd();
}
void SyncDataBaseAttrV1::RefreshInjuryAdd()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_INJURYADD);
}


//冰冻状态
void SyncDataBaseAttrV1::SetFrozenState( const INT32& v )
{
	m_syncDataUserData.SetFrozenState(v);
	m_ClientDataUserData.set_frozenstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_FROZENSTATE))
	{
		m_OtherDataUserData.set_frozenstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetFrozenState()
{
	CalcMethodCB(SYNCID_BASEATTR_FROZENSTATE,std::bind(&SyncDataBaseAttrV1::SetFrozenState,this,std::placeholders::_1));
	return m_syncDataUserData.GetFrozenState();
}
void SyncDataBaseAttrV1::RefreshFrozenState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_FROZENSTATE);
}


//沉默状态
void SyncDataBaseAttrV1::SetSilentState( const INT32& v )
{
	m_syncDataUserData.SetSilentState(v);
	m_ClientDataUserData.set_silentstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SILENTSTATE))
	{
		m_OtherDataUserData.set_silentstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetSilentState()
{
	CalcMethodCB(SYNCID_BASEATTR_SILENTSTATE,std::bind(&SyncDataBaseAttrV1::SetSilentState,this,std::placeholders::_1));
	return m_syncDataUserData.GetSilentState();
}
void SyncDataBaseAttrV1::RefreshSilentState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SILENTSTATE);
}


//GuildContributeHistoryMax
void SyncDataBaseAttrV1::SetGuildContributeHistoryMax( const int64_t& v )
{
	m_syncDataUserData.SetGuildContributeHistoryMax(v);
	m_ClientDataUserData.set_guildcontributehistorymax(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX))
	{
		m_OtherDataUserData.set_guildcontributehistorymax(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetGuildContributeHistoryMax()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX,std::bind(&SyncDataBaseAttrV1::SetGuildContributeHistoryMax,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildContributeHistoryMax();
}
void SyncDataBaseAttrV1::RefreshGuildContributeHistoryMax()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX);
}


//队伍id
void SyncDataBaseAttrV1::SetTeamId( const uint64_t& v )
{
	m_syncDataUserData.SetTeamId(v);
	m_ClientDataUserData.set_teamid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TEAMID))
	{
		m_OtherDataUserData.set_teamid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
uint64_t SyncDataBaseAttrV1::GetTeamId()
{
	CalcMethodCB(SYNCID_BASEATTR_TEAMID,std::bind(&SyncDataBaseAttrV1::SetTeamId,this,std::placeholders::_1));
	return m_syncDataUserData.GetTeamId();
}
void SyncDataBaseAttrV1::RefreshTeamId()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TEAMID);
}


//头发时装ID
void SyncDataBaseAttrV1::SetTreasureHair( const INT32& v )
{
	m_syncDataUserData.SetTreasureHair(v);
	m_ClientDataUserData.set_treasurehair(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREHAIR))
	{
		m_OtherDataUserData.set_treasurehair(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureHair()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREHAIR,std::bind(&SyncDataBaseAttrV1::SetTreasureHair,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureHair();
}
void SyncDataBaseAttrV1::RefreshTreasureHair()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREHAIR);
}


//头部时装ID
void SyncDataBaseAttrV1::SetTreasureHead( const INT32& v )
{
	m_syncDataUserData.SetTreasureHead(v);
	m_ClientDataUserData.set_treasurehead(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREHEAD))
	{
		m_OtherDataUserData.set_treasurehead(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureHead()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREHEAD,std::bind(&SyncDataBaseAttrV1::SetTreasureHead,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureHead();
}
void SyncDataBaseAttrV1::RefreshTreasureHead()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREHEAD);
}


//身体时装
void SyncDataBaseAttrV1::SetTreasureBody( const INT32& v )
{
	m_syncDataUserData.SetTreasureBody(v);
	m_ClientDataUserData.set_treasurebody(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREBODY))
	{
		m_OtherDataUserData.set_treasurebody(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureBody()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREBODY,std::bind(&SyncDataBaseAttrV1::SetTreasureBody,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureBody();
}
void SyncDataBaseAttrV1::RefreshTreasureBody()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREBODY);
}


//武器时装
void SyncDataBaseAttrV1::SetTreasureWeapon( const INT32& v )
{
	m_syncDataUserData.SetTreasureWeapon(v);
	m_ClientDataUserData.set_treasureweapon(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREWEAPON))
	{
		m_OtherDataUserData.set_treasureweapon(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureWeapon()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREWEAPON,std::bind(&SyncDataBaseAttrV1::SetTreasureWeapon,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureWeapon();
}
void SyncDataBaseAttrV1::RefreshTreasureWeapon()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREWEAPON);
}


//翅膀时装
void SyncDataBaseAttrV1::SetTreasureWing( const INT32& v )
{
	m_syncDataUserData.SetTreasureWing(v);
	m_ClientDataUserData.set_treasurewing(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREWING))
	{
		m_OtherDataUserData.set_treasurewing(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureWing()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREWING,std::bind(&SyncDataBaseAttrV1::SetTreasureWing,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureWing();
}
void SyncDataBaseAttrV1::RefreshTreasureWing()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREWING);
}


//公会ID
void SyncDataBaseAttrV1::SetGuildGuid( const uint64_t& v )
{
	m_syncDataUserData.SetGuildGuid(v);
	m_ClientDataUserData.set_guildguid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDGUID))
	{
		m_OtherDataUserData.set_guildguid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
uint64_t SyncDataBaseAttrV1::GetGuildGuid()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDGUID,std::bind(&SyncDataBaseAttrV1::SetGuildGuid,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildGuid();
}
void SyncDataBaseAttrV1::RefreshGuildGuid()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDGUID);
}


//坐骑
void SyncDataBaseAttrV1::SetTreasureRiding( const INT32& v )
{
	m_syncDataUserData.SetTreasureRiding(v);
	m_ClientDataUserData.set_treasureriding(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASURERIDING))
	{
		m_OtherDataUserData.set_treasureriding(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureRiding()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASURERIDING,std::bind(&SyncDataBaseAttrV1::SetTreasureRiding,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureRiding();
}
void SyncDataBaseAttrV1::RefreshTreasureRiding()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASURERIDING);
}


//载具Id
void SyncDataBaseAttrV1::SetVechicleId( const INT32& v )
{
	m_syncDataUserData.SetVechicleId(v);
	m_ClientDataUserData.set_vechicleid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_VECHICLEID))
	{
		m_OtherDataUserData.set_vechicleid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetVechicleId()
{
	CalcMethodCB(SYNCID_BASEATTR_VECHICLEID,std::bind(&SyncDataBaseAttrV1::SetVechicleId,this,std::placeholders::_1));
	return m_syncDataUserData.GetVechicleId();
}
void SyncDataBaseAttrV1::RefreshVechicleId()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_VECHICLEID);
}


//动画状态
void SyncDataBaseAttrV1::SetAnimationState( const bool& v )
{
	m_syncDataUserData.SetAnimationState(v);
	m_ClientDataUserData.set_animationstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ANIMATIONSTATE))
	{
		m_OtherDataUserData.set_animationstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetAnimationState()
{
	CalcMethodCB(SYNCID_BASEATTR_ANIMATIONSTATE,std::bind(&SyncDataBaseAttrV1::SetAnimationState,this,std::placeholders::_1));
	return m_syncDataUserData.GetAnimationState();
}
void SyncDataBaseAttrV1::RefreshAnimationState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ANIMATIONSTATE);
}


//修正攻击者最终伤害比率
void SyncDataBaseAttrV1::SetRefixDmgRate( const float& v )
{
	m_syncDataUserData.SetRefixDmgRate(v);
	m_ClientDataUserData.set_refixdmgrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXDMGRATE))
	{
		m_OtherDataUserData.set_refixdmgrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetRefixDmgRate()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXDMGRATE,std::bind(&SyncDataBaseAttrV1::SetRefixDmgRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixDmgRate();
}
void SyncDataBaseAttrV1::RefreshRefixDmgRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXDMGRATE);
}


//修正攻击者最终伤害值
void SyncDataBaseAttrV1::SetRefixDmgValue( const INT32& v )
{
	m_syncDataUserData.SetRefixDmgValue(v);
	m_ClientDataUserData.set_refixdmgvalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXDMGVALUE))
	{
		m_OtherDataUserData.set_refixdmgvalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetRefixDmgValue()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXDMGVALUE,std::bind(&SyncDataBaseAttrV1::SetRefixDmgValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixDmgValue();
}
void SyncDataBaseAttrV1::RefreshRefixDmgValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXDMGVALUE);
}


//修正被攻击者最终伤害比率
void SyncDataBaseAttrV1::SetRefixHurtRate( const float& v )
{
	m_syncDataUserData.SetRefixHurtRate(v);
	m_ClientDataUserData.set_refixhurtrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXHURTRATE))
	{
		m_OtherDataUserData.set_refixhurtrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetRefixHurtRate()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXHURTRATE,std::bind(&SyncDataBaseAttrV1::SetRefixHurtRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixHurtRate();
}
void SyncDataBaseAttrV1::RefreshRefixHurtRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXHURTRATE);
}


//修正被攻击者最终伤害值
void SyncDataBaseAttrV1::SetRefixHurtValue( const INT32& v )
{
	m_syncDataUserData.SetRefixHurtValue(v);
	m_ClientDataUserData.set_refixhurtvalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXHURTVALUE))
	{
		m_OtherDataUserData.set_refixhurtvalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetRefixHurtValue()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXHURTVALUE,std::bind(&SyncDataBaseAttrV1::SetRefixHurtValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixHurtValue();
}
void SyncDataBaseAttrV1::RefreshRefixHurtValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXHURTVALUE);
}


//修正治疗者最终比例
void SyncDataBaseAttrV1::SetRefixHealRate( const float& v )
{
	m_syncDataUserData.SetRefixHealRate(v);
	m_ClientDataUserData.set_refixhealrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXHEALRATE))
	{
		m_OtherDataUserData.set_refixhealrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetRefixHealRate()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXHEALRATE,std::bind(&SyncDataBaseAttrV1::SetRefixHealRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixHealRate();
}
void SyncDataBaseAttrV1::RefreshRefixHealRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXHEALRATE);
}


//修正治疗者最终值
void SyncDataBaseAttrV1::SetRefixHealValue( const INT32& v )
{
	m_syncDataUserData.SetRefixHealValue(v);
	m_ClientDataUserData.set_refixhealvalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXHEALVALUE))
	{
		m_OtherDataUserData.set_refixhealvalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetRefixHealValue()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXHEALVALUE,std::bind(&SyncDataBaseAttrV1::SetRefixHealValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixHealValue();
}
void SyncDataBaseAttrV1::RefreshRefixHealValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXHEALVALUE);
}


//修正被治疗者最终比例
void SyncDataBaseAttrV1::SetRefixCuredRate( const float& v )
{
	m_syncDataUserData.SetRefixCuredRate(v);
	m_ClientDataUserData.set_refixcuredrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXCUREDRATE))
	{
		m_OtherDataUserData.set_refixcuredrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetRefixCuredRate()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXCUREDRATE,std::bind(&SyncDataBaseAttrV1::SetRefixCuredRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixCuredRate();
}
void SyncDataBaseAttrV1::RefreshRefixCuredRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXCUREDRATE);
}


//修正被治疗者最终值
void SyncDataBaseAttrV1::SetRefixCuredValue( const INT32& v )
{
	m_syncDataUserData.SetRefixCuredValue(v);
	m_ClientDataUserData.set_refixcuredvalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_REFIXCUREDVALUE))
	{
		m_OtherDataUserData.set_refixcuredvalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetRefixCuredValue()
{
	CalcMethodCB(SYNCID_BASEATTR_REFIXCUREDVALUE,std::bind(&SyncDataBaseAttrV1::SetRefixCuredValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetRefixCuredValue();
}
void SyncDataBaseAttrV1::RefreshRefixCuredValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_REFIXCUREDVALUE);
}


//公会帮贡
void SyncDataBaseAttrV1::SetGuildContribute( const int64_t& v )
{
	m_syncDataUserData.SetGuildContribute(v);
	m_ClientDataUserData.set_guildcontribute(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDCONTRIBUTE))
	{
		m_OtherDataUserData.set_guildcontribute(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetGuildContribute()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDCONTRIBUTE,std::bind(&SyncDataBaseAttrV1::SetGuildContribute,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildContribute();
}
void SyncDataBaseAttrV1::RefreshGuildContribute()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDCONTRIBUTE);
}


//竞技场点数
void SyncDataBaseAttrV1::SetPvpMoney( const int64_t& v )
{
	m_syncDataUserData.SetPvpMoney(v);
	m_ClientDataUserData.set_pvpmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PVPMONEY))
	{
		m_OtherDataUserData.set_pvpmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetPvpMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_PVPMONEY,std::bind(&SyncDataBaseAttrV1::SetPvpMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetPvpMoney();
}
void SyncDataBaseAttrV1::RefreshPvpMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PVPMONEY);
}


//公会资源
void SyncDataBaseAttrV1::SetGuildResource( const int64_t& v )
{
	m_syncDataUserData.SetGuildResource(v);
	m_ClientDataUserData.set_guildresource(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDRESOURCE))
	{
		m_OtherDataUserData.set_guildresource(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetGuildResource()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDRESOURCE,std::bind(&SyncDataBaseAttrV1::SetGuildResource,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildResource();
}
void SyncDataBaseAttrV1::RefreshGuildResource()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDRESOURCE);
}


//创建角色时间戳
void SyncDataBaseAttrV1::SetCreateRoleTime( const INT32& v )
{
	m_syncDataUserData.SetCreateRoleTime(v);
	m_ClientDataUserData.set_createroletime(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CREATEROLETIME))
	{
		m_OtherDataUserData.set_createroletime(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCreateRoleTime()
{
	CalcMethodCB(SYNCID_BASEATTR_CREATEROLETIME,std::bind(&SyncDataBaseAttrV1::SetCreateRoleTime,this,std::placeholders::_1));
	return m_syncDataUserData.GetCreateRoleTime();
}
void SyncDataBaseAttrV1::RefreshCreateRoleTime()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CREATEROLETIME);
}


//更新角色等级时间戳
void SyncDataBaseAttrV1::SetUpdateRoleTime( const INT32& v )
{
	m_syncDataUserData.SetUpdateRoleTime(v);
	m_ClientDataUserData.set_updateroletime(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_UPDATEROLETIME))
	{
		m_OtherDataUserData.set_updateroletime(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetUpdateRoleTime()
{
	CalcMethodCB(SYNCID_BASEATTR_UPDATEROLETIME,std::bind(&SyncDataBaseAttrV1::SetUpdateRoleTime,this,std::placeholders::_1));
	return m_syncDataUserData.GetUpdateRoleTime();
}
void SyncDataBaseAttrV1::RefreshUpdateRoleTime()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_UPDATEROLETIME);
}


//战斗状态
void SyncDataBaseAttrV1::SetFightState( const bool& v )
{
	m_syncDataUserData.SetFightState(v);
	m_ClientDataUserData.set_fightstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_FIGHTSTATE))
	{
		m_OtherDataUserData.set_fightstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetFightState()
{
	CalcMethodCB(SYNCID_BASEATTR_FIGHTSTATE,std::bind(&SyncDataBaseAttrV1::SetFightState,this,std::placeholders::_1));
	return m_syncDataUserData.GetFightState();
}
void SyncDataBaseAttrV1::RefreshFightState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_FIGHTSTATE);
}


//普攻技能列表
void SyncDataBaseAttrV1::SetAttackSkillList( const vector<INT32>& v )
{
	m_syncDataUserData.SetAttackSkillList(v);
	m_ClientDataUserData.clear_attackskilllist();
	for (auto iter : v)
	{
		m_ClientDataUserData.add_attackskilllist(iter);
	}
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ATTACKSKILLLIST))
	{
		m_OtherDataUserData.clear_attackskilllist();
		for (auto iter : v)
		{
			m_OtherDataUserData.add_attackskilllist(iter);
		}
		SetOtherChange(true);
	}
	SetChange(true);
}
vector<INT32> SyncDataBaseAttrV1::GetAttackSkillList()
{
	CalcMethodCB(SYNCID_BASEATTR_ATTACKSKILLLIST,std::bind(&SyncDataBaseAttrV1::SetAttackSkillList,this,std::placeholders::_1));
	return m_syncDataUserData.GetAttackSkillList();
}
void SyncDataBaseAttrV1::RefreshAttackSkillList()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ATTACKSKILLLIST);
}


//公会名称
void SyncDataBaseAttrV1::SetGuildName( const string& v )
{
	m_syncDataUserData.SetGuildName(v);
	m_ClientDataUserData.set_guildname(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDNAME))
	{
		m_OtherDataUserData.set_guildname(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
string SyncDataBaseAttrV1::GetGuildName()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDNAME,std::bind(&SyncDataBaseAttrV1::SetGuildName,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildName();
}
void SyncDataBaseAttrV1::RefreshGuildName()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDNAME);
}


//是否可选中
void SyncDataBaseAttrV1::SetIsAllowSelect( const bool& v )
{
	m_syncDataUserData.SetIsAllowSelect(v);
	m_ClientDataUserData.set_isallowselect(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ISALLOWSELECT))
	{
		m_OtherDataUserData.set_isallowselect(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetIsAllowSelect()
{
	CalcMethodCB(SYNCID_BASEATTR_ISALLOWSELECT,std::bind(&SyncDataBaseAttrV1::SetIsAllowSelect,this,std::placeholders::_1));
	return m_syncDataUserData.GetIsAllowSelect();
}
void SyncDataBaseAttrV1::RefreshIsAllowSelect()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ISALLOWSELECT);
}


//怪物回归中
void SyncDataBaseAttrV1::SetGoHomeState( const bool& v )
{
	m_syncDataUserData.SetGoHomeState(v);
	m_ClientDataUserData.set_gohomestate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GOHOMESTATE))
	{
		m_OtherDataUserData.set_gohomestate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetGoHomeState()
{
	CalcMethodCB(SYNCID_BASEATTR_GOHOMESTATE,std::bind(&SyncDataBaseAttrV1::SetGoHomeState,this,std::placeholders::_1));
	return m_syncDataUserData.GetGoHomeState();
}
void SyncDataBaseAttrV1::RefreshGoHomeState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GOHOMESTATE);
}


//怪物是否可攻击
void SyncDataBaseAttrV1::SetCanFight( const bool& v )
{
	m_syncDataUserData.SetCanFight(v);
	m_ClientDataUserData.set_canfight(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CANFIGHT))
	{
		m_OtherDataUserData.set_canfight(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetCanFight()
{
	CalcMethodCB(SYNCID_BASEATTR_CANFIGHT,std::bind(&SyncDataBaseAttrV1::SetCanFight,this,std::placeholders::_1));
	return m_syncDataUserData.GetCanFight();
}
void SyncDataBaseAttrV1::RefreshCanFight()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CANFIGHT);
}


//双倍经验
void SyncDataBaseAttrV1::SetDoubleExp( const int64_t& v )
{
	m_syncDataUserData.SetDoubleExp(v);
	m_ClientDataUserData.set_doubleexp(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DOUBLEEXP))
	{
		m_OtherDataUserData.set_doubleexp(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetDoubleExp()
{
	CalcMethodCB(SYNCID_BASEATTR_DOUBLEEXP,std::bind(&SyncDataBaseAttrV1::SetDoubleExp,this,std::placeholders::_1));
	return m_syncDataUserData.GetDoubleExp();
}
void SyncDataBaseAttrV1::RefreshDoubleExp()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DOUBLEEXP);
}


//友情点
void SyncDataBaseAttrV1::SetFriendPoint( const int64_t& v )
{
	m_syncDataUserData.SetFriendPoint(v);
	m_ClientDataUserData.set_friendpoint(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_FRIENDPOINT))
	{
		m_OtherDataUserData.set_friendpoint(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetFriendPoint()
{
	CalcMethodCB(SYNCID_BASEATTR_FRIENDPOINT,std::bind(&SyncDataBaseAttrV1::SetFriendPoint,this,std::placeholders::_1));
	return m_syncDataUserData.GetFriendPoint();
}
void SyncDataBaseAttrV1::RefreshFriendPoint()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_FRIENDPOINT);
}


//历史最大荣誉点
void SyncDataBaseAttrV1::SetHisMaxHonor( const int64_t& v )
{
	m_syncDataUserData.SetHisMaxHonor(v);
	m_ClientDataUserData.set_hismaxhonor(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HISMAXHONOR))
	{
		m_OtherDataUserData.set_hismaxhonor(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetHisMaxHonor()
{
	CalcMethodCB(SYNCID_BASEATTR_HISMAXHONOR,std::bind(&SyncDataBaseAttrV1::SetHisMaxHonor,this,std::placeholders::_1));
	return m_syncDataUserData.GetHisMaxHonor();
}
void SyncDataBaseAttrV1::RefreshHisMaxHonor()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HISMAXHONOR);
}


//受击状态
void SyncDataBaseAttrV1::SetHurtState( const bool& v )
{
	m_syncDataUserData.SetHurtState(v);
	m_ClientDataUserData.set_hurtstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTSTATE))
	{
		m_OtherDataUserData.set_hurtstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetHurtState()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTSTATE,std::bind(&SyncDataBaseAttrV1::SetHurtState,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtState();
}
void SyncDataBaseAttrV1::RefreshHurtState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTSTATE);
}


//击飞状态
void SyncDataBaseAttrV1::SetHurtFlyState( const bool& v )
{
	m_syncDataUserData.SetHurtFlyState(v);
	m_ClientDataUserData.set_hurtflystate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTFLYSTATE))
	{
		m_OtherDataUserData.set_hurtflystate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetHurtFlyState()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTFLYSTATE,std::bind(&SyncDataBaseAttrV1::SetHurtFlyState,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtFlyState();
}
void SyncDataBaseAttrV1::RefreshHurtFlyState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTFLYSTATE);
}


//击倒状态
void SyncDataBaseAttrV1::SetHurtDownState( const bool& v )
{
	m_syncDataUserData.SetHurtDownState(v);
	m_ClientDataUserData.set_hurtdownstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTDOWNSTATE))
	{
		m_OtherDataUserData.set_hurtdownstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetHurtDownState()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTDOWNSTATE,std::bind(&SyncDataBaseAttrV1::SetHurtDownState,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtDownState();
}
void SyncDataBaseAttrV1::RefreshHurtDownState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTDOWNSTATE);
}


//击退
void SyncDataBaseAttrV1::SetHurtRepelState( const bool& v )
{
	m_syncDataUserData.SetHurtRepelState(v);
	m_ClientDataUserData.set_hurtrepelstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTREPELSTATE))
	{
		m_OtherDataUserData.set_hurtrepelstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetHurtRepelState()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTREPELSTATE,std::bind(&SyncDataBaseAttrV1::SetHurtRepelState,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtRepelState();
}
void SyncDataBaseAttrV1::RefreshHurtRepelState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTREPELSTATE);
}


//今日获得的荣誉值
void SyncDataBaseAttrV1::SetTodayHornor( const int64_t& v )
{
	m_syncDataUserData.SetTodayHornor(v);
	m_ClientDataUserData.set_todayhornor(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TODAYHORNOR))
	{
		m_OtherDataUserData.set_todayhornor(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetTodayHornor()
{
	CalcMethodCB(SYNCID_BASEATTR_TODAYHORNOR,std::bind(&SyncDataBaseAttrV1::SetTodayHornor,this,std::placeholders::_1));
	return m_syncDataUserData.GetTodayHornor();
}
void SyncDataBaseAttrV1::RefreshTodayHornor()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TODAYHORNOR);
}


//当前专精
void SyncDataBaseAttrV1::SetCurProfession( const INT32& v )
{
	m_syncDataUserData.SetCurProfession(v);
	m_ClientDataUserData.set_curprofession(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CURPROFESSION))
	{
		m_OtherDataUserData.set_curprofession(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCurProfession()
{
	CalcMethodCB(SYNCID_BASEATTR_CURPROFESSION,std::bind(&SyncDataBaseAttrV1::SetCurProfession,this,std::placeholders::_1));
	return m_syncDataUserData.GetCurProfession();
}
void SyncDataBaseAttrV1::RefreshCurProfession()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CURPROFESSION);
}


//宠物创建删除条件枚举
void SyncDataBaseAttrV1::SetPetCreateDelCond( const INT32& v )
{
	m_syncDataUserData.SetPetCreateDelCond(v);
	m_ClientDataUserData.set_petcreatedelcond(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PETCREATEDELCOND))
	{
		m_OtherDataUserData.set_petcreatedelcond(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetPetCreateDelCond()
{
	CalcMethodCB(SYNCID_BASEATTR_PETCREATEDELCOND,std::bind(&SyncDataBaseAttrV1::SetPetCreateDelCond,this,std::placeholders::_1));
	return m_syncDataUserData.GetPetCreateDelCond();
}
void SyncDataBaseAttrV1::RefreshPetCreateDelCond()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PETCREATEDELCOND);
}


//宠物是否需要隐藏1显示0隐藏
void SyncDataBaseAttrV1::SetPetDisplay( const INT32& v )
{
	m_syncDataUserData.SetPetDisplay(v);
	m_ClientDataUserData.set_petdisplay(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PETDISPLAY))
	{
		m_OtherDataUserData.set_petdisplay(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetPetDisplay()
{
	CalcMethodCB(SYNCID_BASEATTR_PETDISPLAY,std::bind(&SyncDataBaseAttrV1::SetPetDisplay,this,std::placeholders::_1));
	return m_syncDataUserData.GetPetDisplay();
}
void SyncDataBaseAttrV1::RefreshPetDisplay()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PETDISPLAY);
}


//宠物货币
void SyncDataBaseAttrV1::SetPetMoney( const int64_t& v )
{
	m_syncDataUserData.SetPetMoney(v);
	m_ClientDataUserData.set_petmoney(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PETMONEY))
	{
		m_OtherDataUserData.set_petmoney(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetPetMoney()
{
	CalcMethodCB(SYNCID_BASEATTR_PETMONEY,std::bind(&SyncDataBaseAttrV1::SetPetMoney,this,std::placeholders::_1));
	return m_syncDataUserData.GetPetMoney();
}
void SyncDataBaseAttrV1::RefreshPetMoney()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PETMONEY);
}


//决斗状态
void SyncDataBaseAttrV1::SetDuelStatus( const INT32& v )
{
	m_syncDataUserData.SetDuelStatus(v);
	m_ClientDataUserData.set_duelstatus(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DUELSTATUS))
	{
		m_OtherDataUserData.set_duelstatus(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDuelStatus()
{
	CalcMethodCB(SYNCID_BASEATTR_DUELSTATUS,std::bind(&SyncDataBaseAttrV1::SetDuelStatus,this,std::placeholders::_1));
	return m_syncDataUserData.GetDuelStatus();
}
void SyncDataBaseAttrV1::RefreshDuelStatus()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DUELSTATUS);
}


//经验池
void SyncDataBaseAttrV1::SetExpPool( const int64_t& v )
{
	m_syncDataUserData.SetExpPool(v);
	m_ClientDataUserData.set_exppool(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_EXPPOOL))
	{
		m_OtherDataUserData.set_exppool(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
int64_t SyncDataBaseAttrV1::GetExpPool()
{
	CalcMethodCB(SYNCID_BASEATTR_EXPPOOL,std::bind(&SyncDataBaseAttrV1::SetExpPool,this,std::placeholders::_1));
	return m_syncDataUserData.GetExpPool();
}
void SyncDataBaseAttrV1::RefreshExpPool()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_EXPPOOL);
}


//疾跑状态
void SyncDataBaseAttrV1::SetRushState( const bool& v )
{
	m_syncDataUserData.SetRushState(v);
	m_ClientDataUserData.set_rushstate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_RUSHSTATE))
	{
		m_OtherDataUserData.set_rushstate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetRushState()
{
	CalcMethodCB(SYNCID_BASEATTR_RUSHSTATE,std::bind(&SyncDataBaseAttrV1::SetRushState,this,std::placeholders::_1));
	return m_syncDataUserData.GetRushState();
}
void SyncDataBaseAttrV1::RefreshRushState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_RUSHSTATE);
}


//盯防状态
void SyncDataBaseAttrV1::SetStareState( const uint64_t& v )
{
	m_syncDataUserData.SetStareState(v);
	m_ClientDataUserData.set_starestate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_STARESTATE))
	{
		m_OtherDataUserData.set_starestate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
uint64_t SyncDataBaseAttrV1::GetStareState()
{
	CalcMethodCB(SYNCID_BASEATTR_STARESTATE,std::bind(&SyncDataBaseAttrV1::SetStareState,this,std::placeholders::_1));
	return m_syncDataUserData.GetStareState();
}
void SyncDataBaseAttrV1::RefreshStareState()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_STARESTATE);
}


//世界等级
void SyncDataBaseAttrV1::SetWorldLevel( const INT32& v )
{
	m_syncDataUserData.SetWorldLevel(v);
	m_ClientDataUserData.set_worldlevel(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_WORLDLEVEL))
	{
		m_OtherDataUserData.set_worldlevel(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetWorldLevel()
{
	CalcMethodCB(SYNCID_BASEATTR_WORLDLEVEL,std::bind(&SyncDataBaseAttrV1::SetWorldLevel,this,std::placeholders::_1));
	return m_syncDataUserData.GetWorldLevel();
}
void SyncDataBaseAttrV1::RefreshWorldLevel()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_WORLDLEVEL);
}


//眩晕命中率
void SyncDataBaseAttrV1::SetDizzyHitRate( const float& v )
{
	m_syncDataUserData.SetDizzyHitRate(v);
	m_ClientDataUserData.set_dizzyhitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DIZZYHITRATE))
	{
		m_OtherDataUserData.set_dizzyhitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDizzyHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DIZZYHITRATE,std::bind(&SyncDataBaseAttrV1::SetDizzyHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDizzyHitRate();
}
void SyncDataBaseAttrV1::RefreshDizzyHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DIZZYHITRATE);
}


//眩晕抵抗率
void SyncDataBaseAttrV1::SetDizzyResistRate( const float& v )
{
	m_syncDataUserData.SetDizzyResistRate(v);
	m_ClientDataUserData.set_dizzyresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DIZZYRESISTRATE))
	{
		m_OtherDataUserData.set_dizzyresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDizzyResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DIZZYRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetDizzyResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDizzyResistRate();
}
void SyncDataBaseAttrV1::RefreshDizzyResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DIZZYRESISTRATE);
}


//定身命中率
void SyncDataBaseAttrV1::SetImmovableHitRate( const float& v )
{
	m_syncDataUserData.SetImmovableHitRate(v);
	m_ClientDataUserData.set_immovablehitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_IMMOVABLEHITRATE))
	{
		m_OtherDataUserData.set_immovablehitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetImmovableHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_IMMOVABLEHITRATE,std::bind(&SyncDataBaseAttrV1::SetImmovableHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetImmovableHitRate();
}
void SyncDataBaseAttrV1::RefreshImmovableHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_IMMOVABLEHITRATE);
}


//定身抵抗率
void SyncDataBaseAttrV1::SetImmovableResistRate( const float& v )
{
	m_syncDataUserData.SetImmovableResistRate(v);
	m_ClientDataUserData.set_immovableresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_IMMOVABLERESISTRATE))
	{
		m_OtherDataUserData.set_immovableresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetImmovableResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_IMMOVABLERESISTRATE,std::bind(&SyncDataBaseAttrV1::SetImmovableResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetImmovableResistRate();
}
void SyncDataBaseAttrV1::RefreshImmovableResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_IMMOVABLERESISTRATE);
}


//击飞命中率
void SyncDataBaseAttrV1::SetHurtFlyHitRate( const float& v )
{
	m_syncDataUserData.SetHurtFlyHitRate(v);
	m_ClientDataUserData.set_hurtflyhitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTFLYHITRATE))
	{
		m_OtherDataUserData.set_hurtflyhitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetHurtFlyHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTFLYHITRATE,std::bind(&SyncDataBaseAttrV1::SetHurtFlyHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtFlyHitRate();
}
void SyncDataBaseAttrV1::RefreshHurtFlyHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTFLYHITRATE);
}


//击飞抵抗率
void SyncDataBaseAttrV1::SetHurtFlyResistRate( const float& v )
{
	m_syncDataUserData.SetHurtFlyResistRate(v);
	m_ClientDataUserData.set_hurtflyresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HURTFLYRESISTRATE))
	{
		m_OtherDataUserData.set_hurtflyresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetHurtFlyResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_HURTFLYRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetHurtFlyResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetHurtFlyResistRate();
}
void SyncDataBaseAttrV1::RefreshHurtFlyResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HURTFLYRESISTRATE);
}


//冰冻命中率
void SyncDataBaseAttrV1::SetFrozenHitRate( const float& v )
{
	m_syncDataUserData.SetFrozenHitRate(v);
	m_ClientDataUserData.set_frozenhitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_FROZENHITRATE))
	{
		m_OtherDataUserData.set_frozenhitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetFrozenHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_FROZENHITRATE,std::bind(&SyncDataBaseAttrV1::SetFrozenHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetFrozenHitRate();
}
void SyncDataBaseAttrV1::RefreshFrozenHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_FROZENHITRATE);
}


//冰冻抵抗率
void SyncDataBaseAttrV1::SetFrozenResistRate( const float& v )
{
	m_syncDataUserData.SetFrozenResistRate(v);
	m_ClientDataUserData.set_frozenresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_FROZENRESISTRATE))
	{
		m_OtherDataUserData.set_frozenresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetFrozenResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_FROZENRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetFrozenResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetFrozenResistRate();
}
void SyncDataBaseAttrV1::RefreshFrozenResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_FROZENRESISTRATE);
}


//净化命中率
void SyncDataBaseAttrV1::SetCleanHitRate( const float& v )
{
	m_syncDataUserData.SetCleanHitRate(v);
	m_ClientDataUserData.set_cleanhitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CLEANHITRATE))
	{
		m_OtherDataUserData.set_cleanhitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetCleanHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_CLEANHITRATE,std::bind(&SyncDataBaseAttrV1::SetCleanHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetCleanHitRate();
}
void SyncDataBaseAttrV1::RefreshCleanHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CLEANHITRATE);
}


//净化抵抗率
void SyncDataBaseAttrV1::SetCleanResistRate( const float& v )
{
	m_syncDataUserData.SetCleanResistRate(v);
	m_ClientDataUserData.set_cleanresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CLEANRESISTRATE))
	{
		m_OtherDataUserData.set_cleanresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetCleanResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_CLEANRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetCleanResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetCleanResistRate();
}
void SyncDataBaseAttrV1::RefreshCleanResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CLEANRESISTRATE);
}


//驱散命中率
void SyncDataBaseAttrV1::SetDispelHitRate( const float& v )
{
	m_syncDataUserData.SetDispelHitRate(v);
	m_ClientDataUserData.set_dispelhitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DISPELHITRATE))
	{
		m_OtherDataUserData.set_dispelhitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDispelHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DISPELHITRATE,std::bind(&SyncDataBaseAttrV1::SetDispelHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDispelHitRate();
}
void SyncDataBaseAttrV1::RefreshDispelHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DISPELHITRATE);
}


//驱散抵抗率
void SyncDataBaseAttrV1::SetDispelResistRate( const float& v )
{
	m_syncDataUserData.SetDispelResistRate(v);
	m_ClientDataUserData.set_dispelresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DISPELRESISTRATE))
	{
		m_OtherDataUserData.set_dispelresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDispelResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DISPELRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetDispelResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDispelResistRate();
}
void SyncDataBaseAttrV1::RefreshDispelResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DISPELRESISTRATE);
}


//沉默命中率
void SyncDataBaseAttrV1::SetSilenceHitRate( const float& v )
{
	m_syncDataUserData.SetSilenceHitRate(v);
	m_ClientDataUserData.set_silencehitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SILENCEHITRATE))
	{
		m_OtherDataUserData.set_silencehitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetSilenceHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_SILENCEHITRATE,std::bind(&SyncDataBaseAttrV1::SetSilenceHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetSilenceHitRate();
}
void SyncDataBaseAttrV1::RefreshSilenceHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SILENCEHITRATE);
}


//沉默抵抗率
void SyncDataBaseAttrV1::SetSilenceResistRate( const float& v )
{
	m_syncDataUserData.SetSilenceResistRate(v);
	m_ClientDataUserData.set_silenceresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SILENCERESISTRATE))
	{
		m_OtherDataUserData.set_silenceresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetSilenceResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_SILENCERESISTRATE,std::bind(&SyncDataBaseAttrV1::SetSilenceResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetSilenceResistRate();
}
void SyncDataBaseAttrV1::RefreshSilenceResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SILENCERESISTRATE);
}


//打断命中率
void SyncDataBaseAttrV1::SetInterruptHitRate( const float& v )
{
	m_syncDataUserData.SetInterruptHitRate(v);
	m_ClientDataUserData.set_interrupthitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_INTERRUPTHITRATE))
	{
		m_OtherDataUserData.set_interrupthitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetInterruptHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_INTERRUPTHITRATE,std::bind(&SyncDataBaseAttrV1::SetInterruptHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetInterruptHitRate();
}
void SyncDataBaseAttrV1::RefreshInterruptHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_INTERRUPTHITRATE);
}


//打断抵抗率
void SyncDataBaseAttrV1::SetInterruptResistRate( const float& v )
{
	m_syncDataUserData.SetInterruptResistRate(v);
	m_ClientDataUserData.set_interruptresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_INTERRUPTRESISTRATE))
	{
		m_OtherDataUserData.set_interruptresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetInterruptResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_INTERRUPTRESISTRATE,std::bind(&SyncDataBaseAttrV1::SetInterruptResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetInterruptResistRate();
}
void SyncDataBaseAttrV1::RefreshInterruptResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_INTERRUPTRESISTRATE);
}


//禁疗命中率
void SyncDataBaseAttrV1::SetUncurableHitRate( const float& v )
{
	m_syncDataUserData.SetUncurableHitRate(v);
	m_ClientDataUserData.set_uncurablehitrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_UNCURABLEHITRATE))
	{
		m_OtherDataUserData.set_uncurablehitrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetUncurableHitRate()
{
	CalcMethodCB(SYNCID_BASEATTR_UNCURABLEHITRATE,std::bind(&SyncDataBaseAttrV1::SetUncurableHitRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetUncurableHitRate();
}
void SyncDataBaseAttrV1::RefreshUncurableHitRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_UNCURABLEHITRATE);
}


//禁疗抵抗率
void SyncDataBaseAttrV1::SetUncurableResistRate( const float& v )
{
	m_syncDataUserData.SetUncurableResistRate(v);
	m_ClientDataUserData.set_uncurableresistrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_UNCURABLERESISTRATE))
	{
		m_OtherDataUserData.set_uncurableresistrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetUncurableResistRate()
{
	CalcMethodCB(SYNCID_BASEATTR_UNCURABLERESISTRATE,std::bind(&SyncDataBaseAttrV1::SetUncurableResistRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetUncurableResistRate();
}
void SyncDataBaseAttrV1::RefreshUncurableResistRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_UNCURABLERESISTRATE);
}


//变身
void SyncDataBaseAttrV1::SetTransform( const INT32& v )
{
	m_syncDataUserData.SetTransform(v);
	m_ClientDataUserData.set_transform(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TRANSFORM))
	{
		m_OtherDataUserData.set_transform(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTransform()
{
	CalcMethodCB(SYNCID_BASEATTR_TRANSFORM,std::bind(&SyncDataBaseAttrV1::SetTransform,this,std::placeholders::_1));
	return m_syncDataUserData.GetTransform();
}
void SyncDataBaseAttrV1::RefreshTransform()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TRANSFORM);
}


//受到玩家目标伤害比
void SyncDataBaseAttrV1::SetHumanHurtRate( const float& v )
{
	m_syncDataUserData.SetHumanHurtRate(v);
	m_ClientDataUserData.set_humanhurtrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HUMANHURTRATE))
	{
		m_OtherDataUserData.set_humanhurtrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetHumanHurtRate()
{
	CalcMethodCB(SYNCID_BASEATTR_HUMANHURTRATE,std::bind(&SyncDataBaseAttrV1::SetHumanHurtRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetHumanHurtRate();
}
void SyncDataBaseAttrV1::RefreshHumanHurtRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HUMANHURTRATE);
}


//针对玩家目标伤害比
void SyncDataBaseAttrV1::SetHumanSufferRate( const float& v )
{
	m_syncDataUserData.SetHumanSufferRate(v);
	m_ClientDataUserData.set_humansufferrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HUMANSUFFERRATE))
	{
		m_OtherDataUserData.set_humansufferrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetHumanSufferRate()
{
	CalcMethodCB(SYNCID_BASEATTR_HUMANSUFFERRATE,std::bind(&SyncDataBaseAttrV1::SetHumanSufferRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetHumanSufferRate();
}
void SyncDataBaseAttrV1::RefreshHumanSufferRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HUMANSUFFERRATE);
}


//受到怪物目标伤害比
void SyncDataBaseAttrV1::SetMonsterHurtRate( const float& v )
{
	m_syncDataUserData.SetMonsterHurtRate(v);
	m_ClientDataUserData.set_monsterhurtrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MONSTERHURTRATE))
	{
		m_OtherDataUserData.set_monsterhurtrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMonsterHurtRate()
{
	CalcMethodCB(SYNCID_BASEATTR_MONSTERHURTRATE,std::bind(&SyncDataBaseAttrV1::SetMonsterHurtRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetMonsterHurtRate();
}
void SyncDataBaseAttrV1::RefreshMonsterHurtRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MONSTERHURTRATE);
}


//针对怪物目标伤害比
void SyncDataBaseAttrV1::SetMonsterSufferRate( const float& v )
{
	m_syncDataUserData.SetMonsterSufferRate(v);
	m_ClientDataUserData.set_monstersufferrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_MONSTERSUFFERRATE))
	{
		m_OtherDataUserData.set_monstersufferrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetMonsterSufferRate()
{
	CalcMethodCB(SYNCID_BASEATTR_MONSTERSUFFERRATE,std::bind(&SyncDataBaseAttrV1::SetMonsterSufferRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetMonsterSufferRate();
}
void SyncDataBaseAttrV1::RefreshMonsterSufferRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_MONSTERSUFFERRATE);
}


//受到Boss目标伤害比
void SyncDataBaseAttrV1::SetBossHurtRate( const float& v )
{
	m_syncDataUserData.SetBossHurtRate(v);
	m_ClientDataUserData.set_bosshurtrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_BOSSHURTRATE))
	{
		m_OtherDataUserData.set_bosshurtrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetBossHurtRate()
{
	CalcMethodCB(SYNCID_BASEATTR_BOSSHURTRATE,std::bind(&SyncDataBaseAttrV1::SetBossHurtRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetBossHurtRate();
}
void SyncDataBaseAttrV1::RefreshBossHurtRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_BOSSHURTRATE);
}


//针对Boss目标伤害比
void SyncDataBaseAttrV1::SetBossSufferRate( const float& v )
{
	m_syncDataUserData.SetBossSufferRate(v);
	m_ClientDataUserData.set_bosssufferrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_BOSSSUFFERRATE))
	{
		m_OtherDataUserData.set_bosssufferrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetBossSufferRate()
{
	CalcMethodCB(SYNCID_BASEATTR_BOSSSUFFERRATE,std::bind(&SyncDataBaseAttrV1::SetBossSufferRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetBossSufferRate();
}
void SyncDataBaseAttrV1::RefreshBossSufferRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_BOSSSUFFERRATE);
}


//格挡减伤值
void SyncDataBaseAttrV1::SetDodgReduceValue( const INT32& v )
{
	m_syncDataUserData.SetDodgReduceValue(v);
	m_ClientDataUserData.set_dodgreducevalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGREDUCEVALUE))
	{
		m_OtherDataUserData.set_dodgreducevalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDodgReduceValue()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGREDUCEVALUE,std::bind(&SyncDataBaseAttrV1::SetDodgReduceValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgReduceValue();
}
void SyncDataBaseAttrV1::RefreshDodgReduceValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGREDUCEVALUE);
}


//格挡减伤率
void SyncDataBaseAttrV1::SetDodgReduceRate( const float& v )
{
	m_syncDataUserData.SetDodgReduceRate(v);
	m_ClientDataUserData.set_dodgreducerate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGREDUCERATE))
	{
		m_OtherDataUserData.set_dodgreducerate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDodgReduceRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGREDUCERATE,std::bind(&SyncDataBaseAttrV1::SetDodgReduceRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgReduceRate();
}
void SyncDataBaseAttrV1::RefreshDodgReduceRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGREDUCERATE);
}


//格挡破伤值
void SyncDataBaseAttrV1::SetDodgAddValue( const INT32& v )
{
	m_syncDataUserData.SetDodgAddValue(v);
	m_ClientDataUserData.set_dodgaddvalue(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGADDVALUE))
	{
		m_OtherDataUserData.set_dodgaddvalue(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetDodgAddValue()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGADDVALUE,std::bind(&SyncDataBaseAttrV1::SetDodgAddValue,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgAddValue();
}
void SyncDataBaseAttrV1::RefreshDodgAddValue()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGADDVALUE);
}


//格挡破伤率
void SyncDataBaseAttrV1::SetDodgAddRate( const float& v )
{
	m_syncDataUserData.SetDodgAddRate(v);
	m_ClientDataUserData.set_dodgaddrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_DODGADDRATE))
	{
		m_OtherDataUserData.set_dodgaddrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetDodgAddRate()
{
	CalcMethodCB(SYNCID_BASEATTR_DODGADDRATE,std::bind(&SyncDataBaseAttrV1::SetDodgAddRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetDodgAddRate();
}
void SyncDataBaseAttrV1::RefreshDodgAddRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_DODGADDRATE);
}


//步尘
void SyncDataBaseAttrV1::SetTreasureFootPrint( const INT32& v )
{
	m_syncDataUserData.SetTreasureFootPrint(v);
	m_ClientDataUserData.set_treasurefootprint(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_TREASUREFOOTPRINT))
	{
		m_OtherDataUserData.set_treasurefootprint(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetTreasureFootPrint()
{
	CalcMethodCB(SYNCID_BASEATTR_TREASUREFOOTPRINT,std::bind(&SyncDataBaseAttrV1::SetTreasureFootPrint,this,std::placeholders::_1));
	return m_syncDataUserData.GetTreasureFootPrint();
}
void SyncDataBaseAttrV1::RefreshTreasureFootPrint()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_TREASUREFOOTPRINT);
}


//装备称号
void SyncDataBaseAttrV1::SetEquipTitle( const INT32& v )
{
	m_syncDataUserData.SetEquipTitle(v);
	m_ClientDataUserData.set_equiptitle(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_EQUIPTITLE))
	{
		m_OtherDataUserData.set_equiptitle(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetEquipTitle()
{
	CalcMethodCB(SYNCID_BASEATTR_EQUIPTITLE,std::bind(&SyncDataBaseAttrV1::SetEquipTitle,this,std::placeholders::_1));
	return m_syncDataUserData.GetEquipTitle();
}
void SyncDataBaseAttrV1::RefreshEquipTitle()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_EQUIPTITLE);
}


//当前所在动画事件
void SyncDataBaseAttrV1::SetObjAnimEvent( const vector<INT32>& v )
{
	m_syncDataUserData.SetObjAnimEvent(v);
	m_ClientDataUserData.clear_objanimevent();
	for (auto iter : v)
	{
		m_ClientDataUserData.add_objanimevent(iter);
	}
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_OBJANIMEVENT))
	{
		m_OtherDataUserData.clear_objanimevent();
		for (auto iter : v)
		{
			m_OtherDataUserData.add_objanimevent(iter);
		}
		SetOtherChange(true);
	}
	SetChange(true);
}
vector<INT32> SyncDataBaseAttrV1::GetObjAnimEvent()
{
	CalcMethodCB(SYNCID_BASEATTR_OBJANIMEVENT,std::bind(&SyncDataBaseAttrV1::SetObjAnimEvent,this,std::placeholders::_1));
	return m_syncDataUserData.GetObjAnimEvent();
}
void SyncDataBaseAttrV1::RefreshObjAnimEvent()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_OBJANIMEVENT);
}


//捏脸数据
void SyncDataBaseAttrV1::SetPinchData( const string& v )
{
	m_syncDataUserData.SetPinchData(v);
	m_ClientDataUserData.set_pinchdata(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_PINCHDATA))
	{
		m_OtherDataUserData.set_pinchdata(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
string SyncDataBaseAttrV1::GetPinchData()
{
	CalcMethodCB(SYNCID_BASEATTR_PINCHDATA,std::bind(&SyncDataBaseAttrV1::SetPinchData,this,std::placeholders::_1));
	return m_syncDataUserData.GetPinchData();
}
void SyncDataBaseAttrV1::RefreshPinchData()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_PINCHDATA);
}


//技能冷缩比例
void SyncDataBaseAttrV1::SetSkillCDRate( const float& v )
{
	m_syncDataUserData.SetSkillCDRate(v);
	m_ClientDataUserData.set_skillcdrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SKILLCDRATE))
	{
		m_OtherDataUserData.set_skillcdrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetSkillCDRate()
{
	CalcMethodCB(SYNCID_BASEATTR_SKILLCDRATE,std::bind(&SyncDataBaseAttrV1::SetSkillCDRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetSkillCDRate();
}
void SyncDataBaseAttrV1::RefreshSkillCDRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SKILLCDRATE);
}


//攻速
void SyncDataBaseAttrV1::SetAspdRate( const float& v )
{
	m_syncDataUserData.SetAspdRate(v);
	m_ClientDataUserData.set_aspdrate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ASPDRATE))
	{
		m_OtherDataUserData.set_aspdrate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
float SyncDataBaseAttrV1::GetAspdRate()
{
	CalcMethodCB(SYNCID_BASEATTR_ASPDRATE,std::bind(&SyncDataBaseAttrV1::SetAspdRate,this,std::placeholders::_1));
	return m_syncDataUserData.GetAspdRate();
}
void SyncDataBaseAttrV1::RefreshAspdRate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ASPDRATE);
}


//护盾值
void SyncDataBaseAttrV1::SetShield( const INT32& v )
{
	m_syncDataUserData.SetShield(v);
	m_ClientDataUserData.set_shield(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SHIELD))
	{
		m_OtherDataUserData.set_shield(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetShield()
{
	CalcMethodCB(SYNCID_BASEATTR_SHIELD,std::bind(&SyncDataBaseAttrV1::SetShield,this,std::placeholders::_1));
	return m_syncDataUserData.GetShield();
}
void SyncDataBaseAttrV1::RefreshShield()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SHIELD);
}


//obj剩余采集次数
void SyncDataBaseAttrV1::SetEventLeftCount( const INT32& v )
{
	m_syncDataUserData.SetEventLeftCount(v);
	m_ClientDataUserData.set_eventleftcount(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_EVENTLEFTCOUNT))
	{
		m_OtherDataUserData.set_eventleftcount(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetEventLeftCount()
{
	CalcMethodCB(SYNCID_BASEATTR_EVENTLEFTCOUNT,std::bind(&SyncDataBaseAttrV1::SetEventLeftCount,this,std::placeholders::_1));
	return m_syncDataUserData.GetEventLeftCount();
}
void SyncDataBaseAttrV1::RefreshEventLeftCount()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_EVENTLEFTCOUNT);
}


//不能疾跑状态
void SyncDataBaseAttrV1::SetCanNotRush( const INT32& v )
{
	m_syncDataUserData.SetCanNotRush(v);
	m_ClientDataUserData.set_cannotrush(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CANNOTRUSH))
	{
		m_OtherDataUserData.set_cannotrush(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCanNotRush()
{
	CalcMethodCB(SYNCID_BASEATTR_CANNOTRUSH,std::bind(&SyncDataBaseAttrV1::SetCanNotRush,this,std::placeholders::_1));
	return m_syncDataUserData.GetCanNotRush();
}
void SyncDataBaseAttrV1::RefreshCanNotRush()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CANNOTRUSH);
}


//猎魔点数
void SyncDataBaseAttrV1::SetHuntPoint( const INT32& v )
{
	m_syncDataUserData.SetHuntPoint(v);
	m_ClientDataUserData.set_huntpoint(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HUNTPOINT))
	{
		m_OtherDataUserData.set_huntpoint(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetHuntPoint()
{
	CalcMethodCB(SYNCID_BASEATTR_HUNTPOINT,std::bind(&SyncDataBaseAttrV1::SetHuntPoint,this,std::placeholders::_1));
	return m_syncDataUserData.GetHuntPoint();
}
void SyncDataBaseAttrV1::RefreshHuntPoint()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HUNTPOINT);
}


//猎魔高倍
void SyncDataBaseAttrV1::SetHuntHighTimes( const INT32& v )
{
	m_syncDataUserData.SetHuntHighTimes(v);
	m_ClientDataUserData.set_hunthightimes(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HUNTHIGHTIMES))
	{
		m_OtherDataUserData.set_hunthightimes(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetHuntHighTimes()
{
	CalcMethodCB(SYNCID_BASEATTR_HUNTHIGHTIMES,std::bind(&SyncDataBaseAttrV1::SetHuntHighTimes,this,std::placeholders::_1));
	return m_syncDataUserData.GetHuntHighTimes();
}
void SyncDataBaseAttrV1::RefreshHuntHighTimes()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HUNTHIGHTIMES);
}


//猎魔引燃次数
void SyncDataBaseAttrV1::SetHuntFirePoint( const INT32& v )
{
	m_syncDataUserData.SetHuntFirePoint(v);
	m_ClientDataUserData.set_huntfirepoint(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_HUNTFIREPOINT))
	{
		m_OtherDataUserData.set_huntfirepoint(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetHuntFirePoint()
{
	CalcMethodCB(SYNCID_BASEATTR_HUNTFIREPOINT,std::bind(&SyncDataBaseAttrV1::SetHuntFirePoint,this,std::placeholders::_1));
	return m_syncDataUserData.GetHuntFirePoint();
}
void SyncDataBaseAttrV1::RefreshHuntFirePoint()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_HUNTFIREPOINT);
}


//星耀NPC状态(1可进入 2不可进入)
void SyncDataBaseAttrV1::SetStarbattlestate( const INT32& v )
{
	m_syncDataUserData.SetStarbattlestate(v);
	m_ClientDataUserData.set_starbattlestate(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_STARBATTLESTATE))
	{
		m_OtherDataUserData.set_starbattlestate(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetStarbattlestate()
{
	CalcMethodCB(SYNCID_BASEATTR_STARBATTLESTATE,std::bind(&SyncDataBaseAttrV1::SetStarbattlestate,this,std::placeholders::_1));
	return m_syncDataUserData.GetStarbattlestate();
}
void SyncDataBaseAttrV1::RefreshStarbattlestate()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_STARBATTLESTATE);
}


//是否忽略地图阻挡
void SyncDataBaseAttrV1::SetIgnoreMotionBlock( const bool& v )
{
	m_syncDataUserData.SetIgnoreMotionBlock(v);
	m_ClientDataUserData.set_ignoremotionblock(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_IGNOREMOTIONBLOCK))
	{
		m_OtherDataUserData.set_ignoremotionblock(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetIgnoreMotionBlock()
{
	CalcMethodCB(SYNCID_BASEATTR_IGNOREMOTIONBLOCK,std::bind(&SyncDataBaseAttrV1::SetIgnoreMotionBlock,this,std::placeholders::_1));
	return m_syncDataUserData.GetIgnoreMotionBlock();
}
void SyncDataBaseAttrV1::RefreshIgnoreMotionBlock()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_IGNOREMOTIONBLOCK);
}


//EnableInteract
void SyncDataBaseAttrV1::SetEnableInteract( const bool& v )
{
	m_syncDataUserData.SetEnableInteract(v);
	m_ClientDataUserData.set_enableinteract(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_ENABLEINTERACT))
	{
		m_OtherDataUserData.set_enableinteract(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
bool SyncDataBaseAttrV1::GetEnableInteract()
{
	CalcMethodCB(SYNCID_BASEATTR_ENABLEINTERACT,std::bind(&SyncDataBaseAttrV1::SetEnableInteract,this,std::placeholders::_1));
	return m_syncDataUserData.GetEnableInteract();
}
void SyncDataBaseAttrV1::RefreshEnableInteract()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_ENABLEINTERACT);
}


//世界奖章
void SyncDataBaseAttrV1::SetWorldMedal( const INT32& v )
{
	m_syncDataUserData.SetWorldMedal(v);
	m_ClientDataUserData.set_worldmedal(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_WORLDMEDAL))
	{
		m_OtherDataUserData.set_worldmedal(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetWorldMedal()
{
	CalcMethodCB(SYNCID_BASEATTR_WORLDMEDAL,std::bind(&SyncDataBaseAttrV1::SetWorldMedal,this,std::placeholders::_1));
	return m_syncDataUserData.GetWorldMedal();
}
void SyncDataBaseAttrV1::RefreshWorldMedal()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_WORLDMEDAL);
}


//治疗上限
void SyncDataBaseAttrV1::SetCureCeiling( const INT32& v )
{
	m_syncDataUserData.SetCureCeiling(v);
	m_ClientDataUserData.set_cureceiling(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_CURECEILING))
	{
		m_OtherDataUserData.set_cureceiling(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetCureCeiling()
{
	CalcMethodCB(SYNCID_BASEATTR_CURECEILING,std::bind(&SyncDataBaseAttrV1::SetCureCeiling,this,std::placeholders::_1));
	return m_syncDataUserData.GetCureCeiling();
}
void SyncDataBaseAttrV1::RefreshCureCeiling()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_CURECEILING);
}


//圣乐之力
void SyncDataBaseAttrV1::SetRelationUnionCurrency( const INT32& v )
{
	m_syncDataUserData.SetRelationUnionCurrency(v);
	m_ClientDataUserData.set_relationunioncurrency(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_RELATIONUNIONCURRENCY))
	{
		m_OtherDataUserData.set_relationunioncurrency(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetRelationUnionCurrency()
{
	CalcMethodCB(SYNCID_BASEATTR_RELATIONUNIONCURRENCY,std::bind(&SyncDataBaseAttrV1::SetRelationUnionCurrency,this,std::placeholders::_1));
	return m_syncDataUserData.GetRelationUnionCurrency();
}
void SyncDataBaseAttrV1::RefreshRelationUnionCurrency()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_RELATIONUNIONCURRENCY);
}


//公会简称
void SyncDataBaseAttrV1::SetGuildShortName( const string& v )
{
	m_syncDataUserData.SetGuildShortName(v);
	m_ClientDataUserData.set_guildshortname(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDSHORTNAME))
	{
		m_OtherDataUserData.set_guildshortname(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
string SyncDataBaseAttrV1::GetGuildShortName()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDSHORTNAME,std::bind(&SyncDataBaseAttrV1::SetGuildShortName,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildShortName();
}
void SyncDataBaseAttrV1::RefreshGuildShortName()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDSHORTNAME);
}


//公会简称颜色ID
void SyncDataBaseAttrV1::SetGuildShortColorID( const INT32& v )
{
	m_syncDataUserData.SetGuildShortColorID(v);
	m_ClientDataUserData.set_guildshortcolorid(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_GUILDSHORTCOLORID))
	{
		m_OtherDataUserData.set_guildshortcolorid(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetGuildShortColorID()
{
	CalcMethodCB(SYNCID_BASEATTR_GUILDSHORTCOLORID,std::bind(&SyncDataBaseAttrV1::SetGuildShortColorID,this,std::placeholders::_1));
	return m_syncDataUserData.GetGuildShortColorID();
}
void SyncDataBaseAttrV1::RefreshGuildShortColorID()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_GUILDSHORTCOLORID);
}

