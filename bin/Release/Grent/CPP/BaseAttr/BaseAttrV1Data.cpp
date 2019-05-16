#include "BaseAttrV1Data.h"
#include "BaseAttrModule.h"


SyncDataBaseAttrV1::SyncDataBaseAttrV1()
{
	SetDataWraper( &m_syncDataUserData );
}

SyncDataBaseAttrV1::~SyncDataBaseAttrV1()
{
}

void SyncDataBaseAttrV1::SendAllMembers(bool OnlyToClient)
{
	SendExp(OnlyToClient);
	SendLevel(OnlyToClient);
	SendServerTime(OnlyToClient);
	SendRoleId(OnlyToClient);
	SendStrength(OnlyToClient);
	SendAgility(OnlyToClient);
	SendIntellectual(OnlyToClient);
	SendEndurance(OnlyToClient);
	SendSpirit(OnlyToClient);
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
void SyncDataBaseAttrV1::SetServerTime( const int64_t& v )
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
int64_t SyncDataBaseAttrV1::GetServerTime()
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


//精神
void SyncDataBaseAttrV1::SetSpirit( const INT32& v )
{
	m_syncDataUserData.SetSpirit(v);
	m_ClientDataUserData.set_spirit(v);
	if (g_SyncOtherProperty.IsInOtherSync(SYNCID_BASEATTR_SPIRIT))
	{
		m_OtherDataUserData.set_spirit(v);
		SetOtherChange(true);
	}
	SetChange(true);
}
INT32 SyncDataBaseAttrV1::GetSpirit()
{
	CalcMethodCB(SYNCID_BASEATTR_SPIRIT,std::bind(&SyncDataBaseAttrV1::SetSpirit,this,std::placeholders::_1));
	return m_syncDataUserData.GetSpirit();
}
void SyncDataBaseAttrV1::RefreshSpirit()
{
	m_vCalcPropertyIds.insert(SYNCID_BASEATTR_SPIRIT);
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
void SyncDataBaseAttrV1::SetOwnerObjId( const INT32& v )
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
INT32 SyncDataBaseAttrV1::GetOwnerObjId()
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

