#include "BaseAttrV1Data.h"
//#include "BaseAttrModule.h"
#include "Obj/Obj_Character/Obj_Character.h"

SyncDataBaseAttrV1::SyncDataBaseAttrV1(Obj_Character* pObj):m_bChange(false)
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
	m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_SPIRIT,std::move(std::bind(&Obj_Character::CalcSpirit, pObj)));
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

}

SyncDataBaseAttrV1::~SyncDataBaseAttrV1()
{
}

void SyncDataBaseAttrV1::Init()
{
		RefreshExp();
	RefreshLevel();
	RefreshServerTime();
	RefreshRoleId();
	RefreshStrength();
	RefreshAgility();
	RefreshIntellectual();
	RefreshEndurance();
	RefreshSpirit();
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

	m_bChange = false;
}

void SyncDataBaseAttrV1::SetSendCallBack(const send_callback_type & cb)
{
	m_oSendCallback = cb;
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
	GetSpirit();
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

**/
	CalcAllMembers();
	if (!m_bChange)
	{
		return;
	}
	if (m_oSendCallback)
	{
		m_oSendCallback(m_ClientDataUserData);
		m_bChange = false;
	}
	m_ClientDataUserData.Clear();
}



//经验
void SyncDataBaseAttrV1::SetExp( const INT32& v )
{
	m_syncDataUserData.SetExp(v);
	m_ClientDataUserData.set_exp(v);
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
void SyncDataBaseAttrV1::SetRoleId( const int64_t& v )
{
	m_syncDataUserData.SetRoleId(v);
	m_ClientDataUserData.set_roleid(v);
	m_bChange = true;
}
int64_t SyncDataBaseAttrV1::GetRoleId()
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
void SyncDataBaseAttrV1::SetDizzyState( const bool& v )
{
	m_syncDataUserData.SetDizzyState(v);
	m_ClientDataUserData.set_dizzystate(v);
	m_bChange = true;
}
bool SyncDataBaseAttrV1::GetDizzyState()
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
	m_bChange = true;
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
void SyncDataBaseAttrV1::SetCantMoveState( const bool& v )
{
	m_syncDataUserData.SetCantMoveState(v);
	m_ClientDataUserData.set_cantmovestate(v);
	m_bChange = true;
}
bool SyncDataBaseAttrV1::GetCantMoveState()
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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
	m_bChange = true;
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

