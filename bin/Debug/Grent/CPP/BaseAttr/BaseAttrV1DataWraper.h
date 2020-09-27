/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     SyncWraperBaseAttr.h
* Author:       郭晓波
* Description:  基础数据同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_BASEATTR_H
#define __SYNC_WRAPER_BASEATTR_H

#include "BaseDef.h"
#include "BaseAttrV1Data.pb.h"
using namespace std;



//ObjData封装类
class BaseAttrObjDataWraperV1
{
public:
	//构造函数
	BaseAttrObjDataWraperV1()
	{
		
		m_ObjType = -1;
		m_ConfigId = -1;
		m_State = -1;
		m_OwnerObjId = 0;

	}
	//赋值构造函数
	BaseAttrObjDataWraperV1(const BaseAttrObjDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrObjDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrObjDataV1 ToPB() const
	{
		BaseAttrObjDataV1 v;
		v.set_objtype( m_ObjType );
		v.set_configid( m_ConfigId );
		v.set_state( m_State );
		v.set_ownerobjid( m_OwnerObjId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BaseAttrObjDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrObjDataV1& v)
	{
		m_ObjType = v.objtype();
		m_ConfigId = v.configid();
		m_State = v.state();
		m_OwnerObjId = v.ownerobjid();

	}

private:
	//类型
	INT32 m_ObjType;
public:
	void SetObjType( INT32 v)
	{
		m_ObjType=v;
	}
	INT32 GetObjType()
	{
		return m_ObjType;
	}
	INT32 GetObjType() const
	{
		return m_ObjType;
	}
private:
	//config id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//obj状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//拥有者
	uint64_t m_OwnerObjId;
public:
	void SetOwnerObjId( uint64_t v)
	{
		m_OwnerObjId=v;
	}
	uint64_t GetOwnerObjId()
	{
		return m_OwnerObjId;
	}
	uint64_t GetOwnerObjId() const
	{
		return m_OwnerObjId;
	}

};
//玩家基础数据封装类
class BaseAttrUserDataWraperV1
{
public:
	//构造函数
	BaseAttrUserDataWraperV1()
	{
		
		m_Exp = 0;
		m_Level = 0;
		m_ServerTime = -1;
		m_RoleId = 0;
		m_Strength = 0;
		m_Agility = 0;
		m_Intellectual = 0;
		m_Endurance = 0;
		m_Hp = 0;
		m_MaxHp = 0;
		m_PhysicAttack = 0;
		m_PhysicDefense = 0;
		m_MagicAttack = 0;
		m_MagicDefense = 0;
		m_Hit = 0;
		m_HitRate = 0;
		m_Miss = 0;
		m_MissRate = 0;
		m_Critical = 0;
		m_CriticalRate = 0;
		m_Tenacity = 0;
		m_TenacityRate = 0;
		m_Penet = 0;
		m_PenetRate = 0;
		m_Dodg = 0;
		m_DodgRate = 0;
		m_CriticalAddition = 0;
		m_CriticalAdditionRate = 0;
		m_CriticalImmune = 0;
		m_CriticalImmuneRate = 0;
		m_MissLevel = 0;
		m_CriticalLevel = 0;
		m_DodgLevel = 0;
		m_MoveSpeed = 0;
		m_DizzyState = 0;
		m_GodState = false;
		m_CantMoveState = 0;
		m_PhysicAddition = 0;
		m_MagicAddition = 0;
		m_PhysicOppose = 0;
		m_MagicOppose = 0;
		m_AccumulateSkiEnergy = 0;
		m_NickName = "";
		m_ConfigId = -1;
		m_ObjType = -1;
		m_State = -1;
		m_OwnerObjId = 0;
		m_Camp = -1;
		m_SilverMoney = 0;
		m_GoldMoney = 0;
		m_DiamondMoney = 0;
		m_BindingDiamondMoney = 0;
		m_BattleScore = -1;
		m_Energy = -1;
		m_GuildMoney = -1;
		m_HonorMoney = -1;
		m_ResourcePoolHp = -1;
		m_AttackAdd = 0;
		m_InjuryAdd = 0;
		m_FrozenState = -1;
		m_SilentState = -1;
		m_GuildContributeHistoryMax = -1;
		m_TeamId = 0;
		m_TreasureHair = -1;
		m_TreasureHead = -1;
		m_TreasureBody = -1;
		m_TreasureWeapon = -1;
		m_TreasureWing = -1;
		m_GuildGuid = 0;
		m_TreasureRiding = -1;
		m_VechicleId = -1;
		m_AnimationState = false;
		m_RefixDmgRate = 0;
		m_RefixDmgValue = 0;
		m_RefixHurtRate = 0;
		m_RefixHurtValue = 0;
		m_RefixHealRate = 0;
		m_RefixHealValue = 0;
		m_RefixCuredRate = 0;
		m_RefixCuredValue = 0;
		m_GuildContribute = -1;
		m_PvpMoney = -1;
		m_GuildResource = -1;
		m_CreateRoleTime = 0;
		m_UpdateRoleTime = 0;
		m_FightState = false;
		m_GuildName = "";
		m_IsAllowSelect = true;
		m_GoHomeState = false;
		m_CanFight = true;
		m_DoubleExp = -1;
		m_FriendPoint = -1;
		m_HisMaxHonor = -1;
		m_HurtState = false;
		m_HurtFlyState = false;
		m_HurtDownState = false;
		m_HurtRepelState = false;
		m_TodayHornor = -1;
		m_CurProfession = -1;
		m_PetCreateDelCond = -1;
		m_PetDisplay = 0;
		m_PetMoney = -1;
		m_DuelStatus = 0;
		m_ExpPool = -1;
		m_RushState = false;
		m_StareState = 0;
		m_WorldLevel = 0;
		m_DizzyHitRate = 0;
		m_DizzyResistRate = 0;
		m_ImmovableHitRate = 0;
		m_ImmovableResistRate = 0;
		m_HurtFlyHitRate = 0;
		m_HurtFlyResistRate = 0;
		m_FrozenHitRate = 0;
		m_FrozenResistRate = 0;
		m_CleanHitRate = 0;
		m_CleanResistRate = 0;
		m_DispelHitRate = 0;
		m_DispelResistRate = 0;
		m_SilenceHitRate = 0;
		m_SilenceResistRate = 0;
		m_InterruptHitRate = 0;
		m_InterruptResistRate = 0;
		m_UncurableHitRate = 0;
		m_UncurableResistRate = 0;
		m_Transform = -1;
		m_HumanHurtRate = 0;
		m_HumanSufferRate = 0;
		m_MonsterHurtRate = 0;
		m_MonsterSufferRate = 0;
		m_BossHurtRate = 0;
		m_BossSufferRate = 0;
		m_DodgReduceValue = 0;
		m_DodgReduceRate = 0;
		m_DodgAddValue = 0;
		m_DodgAddRate = 0;
		m_TreasureFootPrint = -1;
		m_EquipTitle = -1;
		m_PinchData = "";
		m_SkillCDRate = 1;
		m_AspdRate = 1;
		m_Shield = 0;
		m_EventLeftCount = -1;
		m_CanNotRush = 0;
		m_HuntPoint = 0;
		m_HuntHighTimes = 0;
		m_HuntFirePoint = 0;
		m_Starbattlestate = 1;
		m_IgnoreMotionBlock = false;
		m_EnableInteract = false;
		m_WorldMedal = 0;
		m_CureCeiling = -1;
		m_RelationUnionCurrency = 0;
		m_GuildShortName = "";
		m_GuildShortColorID = -1;

	}
	//赋值构造函数
	BaseAttrUserDataWraperV1(const BaseAttrUserDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrUserDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrUserDataV1 ToPB() const
	{
		BaseAttrUserDataV1 v;
		v.set_exp( m_Exp );
		v.set_level( m_Level );
		v.set_servertime( m_ServerTime );
		v.set_roleid( m_RoleId );
		v.set_strength( m_Strength );
		v.set_agility( m_Agility );
		v.set_intellectual( m_Intellectual );
		v.set_endurance( m_Endurance );
		v.set_hp( m_Hp );
		v.set_maxhp( m_MaxHp );
		v.set_physicattack( m_PhysicAttack );
		v.set_physicdefense( m_PhysicDefense );
		v.set_magicattack( m_MagicAttack );
		v.set_magicdefense( m_MagicDefense );
		v.set_hit( m_Hit );
		v.set_hitrate( m_HitRate );
		v.set_miss( m_Miss );
		v.set_missrate( m_MissRate );
		v.set_critical( m_Critical );
		v.set_criticalrate( m_CriticalRate );
		v.set_tenacity( m_Tenacity );
		v.set_tenacityrate( m_TenacityRate );
		v.set_penet( m_Penet );
		v.set_penetrate( m_PenetRate );
		v.set_dodg( m_Dodg );
		v.set_dodgrate( m_DodgRate );
		v.set_criticaladdition( m_CriticalAddition );
		v.set_criticaladditionrate( m_CriticalAdditionRate );
		v.set_criticalimmune( m_CriticalImmune );
		v.set_criticalimmunerate( m_CriticalImmuneRate );
		v.set_misslevel( m_MissLevel );
		v.set_criticallevel( m_CriticalLevel );
		v.set_dodglevel( m_DodgLevel );
		v.set_movespeed( m_MoveSpeed );
		v.set_dizzystate( m_DizzyState );
		v.set_godstate( m_GodState );
		v.set_cantmovestate( m_CantMoveState );
		v.set_physicaddition( m_PhysicAddition );
		v.set_magicaddition( m_MagicAddition );
		v.set_physicoppose( m_PhysicOppose );
		v.set_magicoppose( m_MagicOppose );
		v.set_accumulateskienergy( m_AccumulateSkiEnergy );
		v.set_nickname( m_NickName );
		v.set_configid( m_ConfigId );
		v.set_objtype( m_ObjType );
		v.set_state( m_State );
		v.set_ownerobjid( m_OwnerObjId );
		v.set_camp( m_Camp );
		v.set_silvermoney( m_SilverMoney );
		v.set_goldmoney( m_GoldMoney );
		v.set_diamondmoney( m_DiamondMoney );
		v.set_bindingdiamondmoney( m_BindingDiamondMoney );
		v.set_battlescore( m_BattleScore );
		v.set_energy( m_Energy );
		v.set_guildmoney( m_GuildMoney );
		v.mutable_skilllist()->Reserve(m_SkillList.size());
		for (int i=0; i<(int)m_SkillList.size(); i++)
		{
			v.add_skilllist(m_SkillList[i]);
		}
		v.set_honormoney( m_HonorMoney );
		v.set_resourcepoolhp( m_ResourcePoolHp );
		v.set_attackadd( m_AttackAdd );
		v.set_injuryadd( m_InjuryAdd );
		v.set_frozenstate( m_FrozenState );
		v.set_silentstate( m_SilentState );
		v.set_guildcontributehistorymax( m_GuildContributeHistoryMax );
		v.set_teamid( m_TeamId );
		v.set_treasurehair( m_TreasureHair );
		v.set_treasurehead( m_TreasureHead );
		v.set_treasurebody( m_TreasureBody );
		v.set_treasureweapon( m_TreasureWeapon );
		v.set_treasurewing( m_TreasureWing );
		v.set_guildguid( m_GuildGuid );
		v.set_treasureriding( m_TreasureRiding );
		v.set_vechicleid( m_VechicleId );
		v.set_animationstate( m_AnimationState );
		v.set_refixdmgrate( m_RefixDmgRate );
		v.set_refixdmgvalue( m_RefixDmgValue );
		v.set_refixhurtrate( m_RefixHurtRate );
		v.set_refixhurtvalue( m_RefixHurtValue );
		v.set_refixhealrate( m_RefixHealRate );
		v.set_refixhealvalue( m_RefixHealValue );
		v.set_refixcuredrate( m_RefixCuredRate );
		v.set_refixcuredvalue( m_RefixCuredValue );
		v.set_guildcontribute( m_GuildContribute );
		v.set_pvpmoney( m_PvpMoney );
		v.set_guildresource( m_GuildResource );
		v.set_createroletime( m_CreateRoleTime );
		v.set_updateroletime( m_UpdateRoleTime );
		v.set_fightstate( m_FightState );
		v.mutable_attackskilllist()->Reserve(m_AttackSkillList.size());
		for (int i=0; i<(int)m_AttackSkillList.size(); i++)
		{
			v.add_attackskilllist(m_AttackSkillList[i]);
		}
		v.set_guildname( m_GuildName );
		v.set_isallowselect( m_IsAllowSelect );
		v.set_gohomestate( m_GoHomeState );
		v.set_canfight( m_CanFight );
		v.set_doubleexp( m_DoubleExp );
		v.set_friendpoint( m_FriendPoint );
		v.set_hismaxhonor( m_HisMaxHonor );
		v.set_hurtstate( m_HurtState );
		v.set_hurtflystate( m_HurtFlyState );
		v.set_hurtdownstate( m_HurtDownState );
		v.set_hurtrepelstate( m_HurtRepelState );
		v.set_todayhornor( m_TodayHornor );
		v.set_curprofession( m_CurProfession );
		v.set_petcreatedelcond( m_PetCreateDelCond );
		v.set_petdisplay( m_PetDisplay );
		v.set_petmoney( m_PetMoney );
		v.set_duelstatus( m_DuelStatus );
		v.set_exppool( m_ExpPool );
		v.set_rushstate( m_RushState );
		v.set_starestate( m_StareState );
		v.set_worldlevel( m_WorldLevel );
		v.set_dizzyhitrate( m_DizzyHitRate );
		v.set_dizzyresistrate( m_DizzyResistRate );
		v.set_immovablehitrate( m_ImmovableHitRate );
		v.set_immovableresistrate( m_ImmovableResistRate );
		v.set_hurtflyhitrate( m_HurtFlyHitRate );
		v.set_hurtflyresistrate( m_HurtFlyResistRate );
		v.set_frozenhitrate( m_FrozenHitRate );
		v.set_frozenresistrate( m_FrozenResistRate );
		v.set_cleanhitrate( m_CleanHitRate );
		v.set_cleanresistrate( m_CleanResistRate );
		v.set_dispelhitrate( m_DispelHitRate );
		v.set_dispelresistrate( m_DispelResistRate );
		v.set_silencehitrate( m_SilenceHitRate );
		v.set_silenceresistrate( m_SilenceResistRate );
		v.set_interrupthitrate( m_InterruptHitRate );
		v.set_interruptresistrate( m_InterruptResistRate );
		v.set_uncurablehitrate( m_UncurableHitRate );
		v.set_uncurableresistrate( m_UncurableResistRate );
		v.set_transform( m_Transform );
		v.set_humanhurtrate( m_HumanHurtRate );
		v.set_humansufferrate( m_HumanSufferRate );
		v.set_monsterhurtrate( m_MonsterHurtRate );
		v.set_monstersufferrate( m_MonsterSufferRate );
		v.set_bosshurtrate( m_BossHurtRate );
		v.set_bosssufferrate( m_BossSufferRate );
		v.set_dodgreducevalue( m_DodgReduceValue );
		v.set_dodgreducerate( m_DodgReduceRate );
		v.set_dodgaddvalue( m_DodgAddValue );
		v.set_dodgaddrate( m_DodgAddRate );
		v.set_treasurefootprint( m_TreasureFootPrint );
		v.set_equiptitle( m_EquipTitle );
		v.mutable_objanimevent()->Reserve(m_ObjAnimEvent.size());
		for (int i=0; i<(int)m_ObjAnimEvent.size(); i++)
		{
			v.add_objanimevent(m_ObjAnimEvent[i]);
		}
		v.set_pinchdata( m_PinchData );
		v.set_skillcdrate( m_SkillCDRate );
		v.set_aspdrate( m_AspdRate );
		v.set_shield( m_Shield );
		v.set_eventleftcount( m_EventLeftCount );
		v.set_cannotrush( m_CanNotRush );
		v.set_huntpoint( m_HuntPoint );
		v.set_hunthightimes( m_HuntHighTimes );
		v.set_huntfirepoint( m_HuntFirePoint );
		v.set_starbattlestate( m_Starbattlestate );
		v.set_ignoremotionblock( m_IgnoreMotionBlock );
		v.set_enableinteract( m_EnableInteract );
		v.set_worldmedal( m_WorldMedal );
		v.set_cureceiling( m_CureCeiling );
		v.set_relationunioncurrency( m_RelationUnionCurrency );
		v.set_guildshortname( m_GuildShortName );
		v.set_guildshortcolorid( m_GuildShortColorID );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BaseAttrUserDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BaseAttrUserDataV1& v)
	{
		m_Exp = v.exp();
		m_Level = v.level();
		m_ServerTime = v.servertime();
		m_RoleId = v.roleid();
		m_Strength = v.strength();
		m_Agility = v.agility();
		m_Intellectual = v.intellectual();
		m_Endurance = v.endurance();
		m_Hp = v.hp();
		m_MaxHp = v.maxhp();
		m_PhysicAttack = v.physicattack();
		m_PhysicDefense = v.physicdefense();
		m_MagicAttack = v.magicattack();
		m_MagicDefense = v.magicdefense();
		m_Hit = v.hit();
		m_HitRate = v.hitrate();
		m_Miss = v.miss();
		m_MissRate = v.missrate();
		m_Critical = v.critical();
		m_CriticalRate = v.criticalrate();
		m_Tenacity = v.tenacity();
		m_TenacityRate = v.tenacityrate();
		m_Penet = v.penet();
		m_PenetRate = v.penetrate();
		m_Dodg = v.dodg();
		m_DodgRate = v.dodgrate();
		m_CriticalAddition = v.criticaladdition();
		m_CriticalAdditionRate = v.criticaladditionrate();
		m_CriticalImmune = v.criticalimmune();
		m_CriticalImmuneRate = v.criticalimmunerate();
		m_MissLevel = v.misslevel();
		m_CriticalLevel = v.criticallevel();
		m_DodgLevel = v.dodglevel();
		m_MoveSpeed = v.movespeed();
		m_DizzyState = v.dizzystate();
		m_GodState = v.godstate();
		m_CantMoveState = v.cantmovestate();
		m_PhysicAddition = v.physicaddition();
		m_MagicAddition = v.magicaddition();
		m_PhysicOppose = v.physicoppose();
		m_MagicOppose = v.magicoppose();
		m_AccumulateSkiEnergy = v.accumulateskienergy();
		m_NickName = v.nickname();
		m_ConfigId = v.configid();
		m_ObjType = v.objtype();
		m_State = v.state();
		m_OwnerObjId = v.ownerobjid();
		m_Camp = v.camp();
		m_SilverMoney = v.silvermoney();
		m_GoldMoney = v.goldmoney();
		m_DiamondMoney = v.diamondmoney();
		m_BindingDiamondMoney = v.bindingdiamondmoney();
		m_BattleScore = v.battlescore();
		m_Energy = v.energy();
		m_GuildMoney = v.guildmoney();
		m_SkillList.clear();
		m_SkillList.reserve(v.skilllist_size());
		for( int i=0; i<v.skilllist_size(); i++)
			m_SkillList.push_back(v.skilllist(i));
		m_HonorMoney = v.honormoney();
		m_ResourcePoolHp = v.resourcepoolhp();
		m_AttackAdd = v.attackadd();
		m_InjuryAdd = v.injuryadd();
		m_FrozenState = v.frozenstate();
		m_SilentState = v.silentstate();
		m_GuildContributeHistoryMax = v.guildcontributehistorymax();
		m_TeamId = v.teamid();
		m_TreasureHair = v.treasurehair();
		m_TreasureHead = v.treasurehead();
		m_TreasureBody = v.treasurebody();
		m_TreasureWeapon = v.treasureweapon();
		m_TreasureWing = v.treasurewing();
		m_GuildGuid = v.guildguid();
		m_TreasureRiding = v.treasureriding();
		m_VechicleId = v.vechicleid();
		m_AnimationState = v.animationstate();
		m_RefixDmgRate = v.refixdmgrate();
		m_RefixDmgValue = v.refixdmgvalue();
		m_RefixHurtRate = v.refixhurtrate();
		m_RefixHurtValue = v.refixhurtvalue();
		m_RefixHealRate = v.refixhealrate();
		m_RefixHealValue = v.refixhealvalue();
		m_RefixCuredRate = v.refixcuredrate();
		m_RefixCuredValue = v.refixcuredvalue();
		m_GuildContribute = v.guildcontribute();
		m_PvpMoney = v.pvpmoney();
		m_GuildResource = v.guildresource();
		m_CreateRoleTime = v.createroletime();
		m_UpdateRoleTime = v.updateroletime();
		m_FightState = v.fightstate();
		m_AttackSkillList.clear();
		m_AttackSkillList.reserve(v.attackskilllist_size());
		for( int i=0; i<v.attackskilllist_size(); i++)
			m_AttackSkillList.push_back(v.attackskilllist(i));
		m_GuildName = v.guildname();
		m_IsAllowSelect = v.isallowselect();
		m_GoHomeState = v.gohomestate();
		m_CanFight = v.canfight();
		m_DoubleExp = v.doubleexp();
		m_FriendPoint = v.friendpoint();
		m_HisMaxHonor = v.hismaxhonor();
		m_HurtState = v.hurtstate();
		m_HurtFlyState = v.hurtflystate();
		m_HurtDownState = v.hurtdownstate();
		m_HurtRepelState = v.hurtrepelstate();
		m_TodayHornor = v.todayhornor();
		m_CurProfession = v.curprofession();
		m_PetCreateDelCond = v.petcreatedelcond();
		m_PetDisplay = v.petdisplay();
		m_PetMoney = v.petmoney();
		m_DuelStatus = v.duelstatus();
		m_ExpPool = v.exppool();
		m_RushState = v.rushstate();
		m_StareState = v.starestate();
		m_WorldLevel = v.worldlevel();
		m_DizzyHitRate = v.dizzyhitrate();
		m_DizzyResistRate = v.dizzyresistrate();
		m_ImmovableHitRate = v.immovablehitrate();
		m_ImmovableResistRate = v.immovableresistrate();
		m_HurtFlyHitRate = v.hurtflyhitrate();
		m_HurtFlyResistRate = v.hurtflyresistrate();
		m_FrozenHitRate = v.frozenhitrate();
		m_FrozenResistRate = v.frozenresistrate();
		m_CleanHitRate = v.cleanhitrate();
		m_CleanResistRate = v.cleanresistrate();
		m_DispelHitRate = v.dispelhitrate();
		m_DispelResistRate = v.dispelresistrate();
		m_SilenceHitRate = v.silencehitrate();
		m_SilenceResistRate = v.silenceresistrate();
		m_InterruptHitRate = v.interrupthitrate();
		m_InterruptResistRate = v.interruptresistrate();
		m_UncurableHitRate = v.uncurablehitrate();
		m_UncurableResistRate = v.uncurableresistrate();
		m_Transform = v.transform();
		m_HumanHurtRate = v.humanhurtrate();
		m_HumanSufferRate = v.humansufferrate();
		m_MonsterHurtRate = v.monsterhurtrate();
		m_MonsterSufferRate = v.monstersufferrate();
		m_BossHurtRate = v.bosshurtrate();
		m_BossSufferRate = v.bosssufferrate();
		m_DodgReduceValue = v.dodgreducevalue();
		m_DodgReduceRate = v.dodgreducerate();
		m_DodgAddValue = v.dodgaddvalue();
		m_DodgAddRate = v.dodgaddrate();
		m_TreasureFootPrint = v.treasurefootprint();
		m_EquipTitle = v.equiptitle();
		m_ObjAnimEvent.clear();
		m_ObjAnimEvent.reserve(v.objanimevent_size());
		for( int i=0; i<v.objanimevent_size(); i++)
			m_ObjAnimEvent.push_back(v.objanimevent(i));
		m_PinchData = v.pinchdata();
		m_SkillCDRate = v.skillcdrate();
		m_AspdRate = v.aspdrate();
		m_Shield = v.shield();
		m_EventLeftCount = v.eventleftcount();
		m_CanNotRush = v.cannotrush();
		m_HuntPoint = v.huntpoint();
		m_HuntHighTimes = v.hunthightimes();
		m_HuntFirePoint = v.huntfirepoint();
		m_Starbattlestate = v.starbattlestate();
		m_IgnoreMotionBlock = v.ignoremotionblock();
		m_EnableInteract = v.enableinteract();
		m_WorldMedal = v.worldmedal();
		m_CureCeiling = v.cureceiling();
		m_RelationUnionCurrency = v.relationunioncurrency();
		m_GuildShortName = v.guildshortname();
		m_GuildShortColorID = v.guildshortcolorid();

	}

private:
	//经验
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//玩家等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//服务器时间
	INT32 m_ServerTime;
public:
	void SetServerTime( INT32 v)
	{
		m_ServerTime=v;
	}
	INT32 GetServerTime()
	{
		return m_ServerTime;
	}
	INT32 GetServerTime() const
	{
		return m_ServerTime;
	}
private:
	//人物唯一ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//力量
	INT32 m_Strength;
public:
	void SetStrength( INT32 v)
	{
		m_Strength=v;
	}
	INT32 GetStrength()
	{
		return m_Strength;
	}
	INT32 GetStrength() const
	{
		return m_Strength;
	}
private:
	//敏捷
	INT32 m_Agility;
public:
	void SetAgility( INT32 v)
	{
		m_Agility=v;
	}
	INT32 GetAgility()
	{
		return m_Agility;
	}
	INT32 GetAgility() const
	{
		return m_Agility;
	}
private:
	//智力
	INT32 m_Intellectual;
public:
	void SetIntellectual( INT32 v)
	{
		m_Intellectual=v;
	}
	INT32 GetIntellectual()
	{
		return m_Intellectual;
	}
	INT32 GetIntellectual() const
	{
		return m_Intellectual;
	}
private:
	//耐力
	INT32 m_Endurance;
public:
	void SetEndurance( INT32 v)
	{
		m_Endurance=v;
	}
	INT32 GetEndurance()
	{
		return m_Endurance;
	}
	INT32 GetEndurance() const
	{
		return m_Endurance;
	}
private:
	//生命值
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//生命值
	INT32 m_MaxHp;
public:
	void SetMaxHp( INT32 v)
	{
		m_MaxHp=v;
	}
	INT32 GetMaxHp()
	{
		return m_MaxHp;
	}
	INT32 GetMaxHp() const
	{
		return m_MaxHp;
	}
private:
	//物理攻击
	INT32 m_PhysicAttack;
public:
	void SetPhysicAttack( INT32 v)
	{
		m_PhysicAttack=v;
	}
	INT32 GetPhysicAttack()
	{
		return m_PhysicAttack;
	}
	INT32 GetPhysicAttack() const
	{
		return m_PhysicAttack;
	}
private:
	//物理防御
	INT32 m_PhysicDefense;
public:
	void SetPhysicDefense( INT32 v)
	{
		m_PhysicDefense=v;
	}
	INT32 GetPhysicDefense()
	{
		return m_PhysicDefense;
	}
	INT32 GetPhysicDefense() const
	{
		return m_PhysicDefense;
	}
private:
	//魔法攻击
	INT32 m_MagicAttack;
public:
	void SetMagicAttack( INT32 v)
	{
		m_MagicAttack=v;
	}
	INT32 GetMagicAttack()
	{
		return m_MagicAttack;
	}
	INT32 GetMagicAttack() const
	{
		return m_MagicAttack;
	}
private:
	//魔法防御
	INT32 m_MagicDefense;
public:
	void SetMagicDefense( INT32 v)
	{
		m_MagicDefense=v;
	}
	INT32 GetMagicDefense()
	{
		return m_MagicDefense;
	}
	INT32 GetMagicDefense() const
	{
		return m_MagicDefense;
	}
private:
	//命中值
	INT32 m_Hit;
public:
	void SetHit( INT32 v)
	{
		m_Hit=v;
	}
	INT32 GetHit()
	{
		return m_Hit;
	}
	INT32 GetHit() const
	{
		return m_Hit;
	}
private:
	//命中率
	float m_HitRate;
public:
	void SetHitRate( float v)
	{
		m_HitRate=v;
	}
	float GetHitRate()
	{
		return m_HitRate;
	}
	float GetHitRate() const
	{
		return m_HitRate;
	}
private:
	//闪避值
	INT32 m_Miss;
public:
	void SetMiss( INT32 v)
	{
		m_Miss=v;
	}
	INT32 GetMiss()
	{
		return m_Miss;
	}
	INT32 GetMiss() const
	{
		return m_Miss;
	}
private:
	//闪避率
	float m_MissRate;
public:
	void SetMissRate( float v)
	{
		m_MissRate=v;
	}
	float GetMissRate()
	{
		return m_MissRate;
	}
	float GetMissRate() const
	{
		return m_MissRate;
	}
private:
	//暴击值
	INT32 m_Critical;
public:
	void SetCritical( INT32 v)
	{
		m_Critical=v;
	}
	INT32 GetCritical()
	{
		return m_Critical;
	}
	INT32 GetCritical() const
	{
		return m_Critical;
	}
private:
	//暴击率
	float m_CriticalRate;
public:
	void SetCriticalRate( float v)
	{
		m_CriticalRate=v;
	}
	float GetCriticalRate()
	{
		return m_CriticalRate;
	}
	float GetCriticalRate() const
	{
		return m_CriticalRate;
	}
private:
	//韧性值
	INT32 m_Tenacity;
public:
	void SetTenacity( INT32 v)
	{
		m_Tenacity=v;
	}
	INT32 GetTenacity()
	{
		return m_Tenacity;
	}
	INT32 GetTenacity() const
	{
		return m_Tenacity;
	}
private:
	//韧性率
	float m_TenacityRate;
public:
	void SetTenacityRate( float v)
	{
		m_TenacityRate=v;
	}
	float GetTenacityRate()
	{
		return m_TenacityRate;
	}
	float GetTenacityRate() const
	{
		return m_TenacityRate;
	}
private:
	//穿透值
	INT32 m_Penet;
public:
	void SetPenet( INT32 v)
	{
		m_Penet=v;
	}
	INT32 GetPenet()
	{
		return m_Penet;
	}
	INT32 GetPenet() const
	{
		return m_Penet;
	}
private:
	//穿透率
	float m_PenetRate;
public:
	void SetPenetRate( float v)
	{
		m_PenetRate=v;
	}
	float GetPenetRate()
	{
		return m_PenetRate;
	}
	float GetPenetRate() const
	{
		return m_PenetRate;
	}
private:
	//格挡值
	INT32 m_Dodg;
public:
	void SetDodg( INT32 v)
	{
		m_Dodg=v;
	}
	INT32 GetDodg()
	{
		return m_Dodg;
	}
	INT32 GetDodg() const
	{
		return m_Dodg;
	}
private:
	//格挡率
	float m_DodgRate;
public:
	void SetDodgRate( float v)
	{
		m_DodgRate=v;
	}
	float GetDodgRate()
	{
		return m_DodgRate;
	}
	float GetDodgRate() const
	{
		return m_DodgRate;
	}
private:
	//暴击加伤值
	INT32 m_CriticalAddition;
public:
	void SetCriticalAddition( INT32 v)
	{
		m_CriticalAddition=v;
	}
	INT32 GetCriticalAddition()
	{
		return m_CriticalAddition;
	}
	INT32 GetCriticalAddition() const
	{
		return m_CriticalAddition;
	}
private:
	//暴击加伤率
	float m_CriticalAdditionRate;
public:
	void SetCriticalAdditionRate( float v)
	{
		m_CriticalAdditionRate=v;
	}
	float GetCriticalAdditionRate()
	{
		return m_CriticalAdditionRate;
	}
	float GetCriticalAdditionRate() const
	{
		return m_CriticalAdditionRate;
	}
private:
	//暴击免伤
	INT32 m_CriticalImmune;
public:
	void SetCriticalImmune( INT32 v)
	{
		m_CriticalImmune=v;
	}
	INT32 GetCriticalImmune()
	{
		return m_CriticalImmune;
	}
	INT32 GetCriticalImmune() const
	{
		return m_CriticalImmune;
	}
private:
	//暴击免伤率
	float m_CriticalImmuneRate;
public:
	void SetCriticalImmuneRate( float v)
	{
		m_CriticalImmuneRate=v;
	}
	float GetCriticalImmuneRate()
	{
		return m_CriticalImmuneRate;
	}
	float GetCriticalImmuneRate() const
	{
		return m_CriticalImmuneRate;
	}
private:
	//闪避等级
	INT32 m_MissLevel;
public:
	void SetMissLevel( INT32 v)
	{
		m_MissLevel=v;
	}
	INT32 GetMissLevel()
	{
		return m_MissLevel;
	}
	INT32 GetMissLevel() const
	{
		return m_MissLevel;
	}
private:
	//暴击等级
	INT32 m_CriticalLevel;
public:
	void SetCriticalLevel( INT32 v)
	{
		m_CriticalLevel=v;
	}
	INT32 GetCriticalLevel()
	{
		return m_CriticalLevel;
	}
	INT32 GetCriticalLevel() const
	{
		return m_CriticalLevel;
	}
private:
	//格挡等级
	INT32 m_DodgLevel;
public:
	void SetDodgLevel( INT32 v)
	{
		m_DodgLevel=v;
	}
	INT32 GetDodgLevel()
	{
		return m_DodgLevel;
	}
	INT32 GetDodgLevel() const
	{
		return m_DodgLevel;
	}
private:
	//移动速度
	float m_MoveSpeed;
public:
	void SetMoveSpeed( float v)
	{
		m_MoveSpeed=v;
	}
	float GetMoveSpeed()
	{
		return m_MoveSpeed;
	}
	float GetMoveSpeed() const
	{
		return m_MoveSpeed;
	}
private:
	//眩晕状态
	INT32 m_DizzyState;
public:
	void SetDizzyState( INT32 v)
	{
		m_DizzyState=v;
	}
	INT32 GetDizzyState()
	{
		return m_DizzyState;
	}
	INT32 GetDizzyState() const
	{
		return m_DizzyState;
	}
private:
	//霸体状态
	bool m_GodState;
public:
	void SetGodState( bool v)
	{
		m_GodState=v;
	}
	bool GetGodState()
	{
		return m_GodState;
	}
	bool GetGodState() const
	{
		return m_GodState;
	}
private:
	//不能移动状态
	INT32 m_CantMoveState;
public:
	void SetCantMoveState( INT32 v)
	{
		m_CantMoveState=v;
	}
	INT32 GetCantMoveState()
	{
		return m_CantMoveState;
	}
	INT32 GetCantMoveState() const
	{
		return m_CantMoveState;
	}
private:
	//物理加伤值
	float m_PhysicAddition;
public:
	void SetPhysicAddition( float v)
	{
		m_PhysicAddition=v;
	}
	float GetPhysicAddition()
	{
		return m_PhysicAddition;
	}
	float GetPhysicAddition() const
	{
		return m_PhysicAddition;
	}
private:
	//魔法加伤值
	float m_MagicAddition;
public:
	void SetMagicAddition( float v)
	{
		m_MagicAddition=v;
	}
	float GetMagicAddition()
	{
		return m_MagicAddition;
	}
	float GetMagicAddition() const
	{
		return m_MagicAddition;
	}
private:
	//物理抗性
	float m_PhysicOppose;
public:
	void SetPhysicOppose( float v)
	{
		m_PhysicOppose=v;
	}
	float GetPhysicOppose()
	{
		return m_PhysicOppose;
	}
	float GetPhysicOppose() const
	{
		return m_PhysicOppose;
	}
private:
	//魔法抗性
	float m_MagicOppose;
public:
	void SetMagicOppose( float v)
	{
		m_MagicOppose=v;
	}
	float GetMagicOppose()
	{
		return m_MagicOppose;
	}
	float GetMagicOppose() const
	{
		return m_MagicOppose;
	}
private:
	//技能积攒能量使用 目前只有应激技能用
	float m_AccumulateSkiEnergy;
public:
	void SetAccumulateSkiEnergy( float v)
	{
		m_AccumulateSkiEnergy=v;
	}
	float GetAccumulateSkiEnergy()
	{
		return m_AccumulateSkiEnergy;
	}
	float GetAccumulateSkiEnergy() const
	{
		return m_AccumulateSkiEnergy;
	}
private:
	//名字昵称
	string m_NickName;
public:
	void SetNickName( const string& v)
	{
		m_NickName=v;
	}
	string GetNickName()
	{
		return m_NickName;
	}
	string GetNickName() const
	{
		return m_NickName;
	}
private:
	//config id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//类型
	INT32 m_ObjType;
public:
	void SetObjType( INT32 v)
	{
		m_ObjType=v;
	}
	INT32 GetObjType()
	{
		return m_ObjType;
	}
	INT32 GetObjType() const
	{
		return m_ObjType;
	}
private:
	//EventObjStatu
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//归属obj ID
	uint64_t m_OwnerObjId;
public:
	void SetOwnerObjId( uint64_t v)
	{
		m_OwnerObjId=v;
	}
	uint64_t GetOwnerObjId()
	{
		return m_OwnerObjId;
	}
	uint64_t GetOwnerObjId() const
	{
		return m_OwnerObjId;
	}
private:
	//阵营
	INT32 m_Camp;
public:
	void SetCamp( INT32 v)
	{
		m_Camp=v;
	}
	INT32 GetCamp()
	{
		return m_Camp;
	}
	INT32 GetCamp() const
	{
		return m_Camp;
	}
private:
	//银币
	int64_t m_SilverMoney;
public:
	void SetSilverMoney( int64_t v)
	{
		m_SilverMoney=v;
	}
	int64_t GetSilverMoney()
	{
		return m_SilverMoney;
	}
	int64_t GetSilverMoney() const
	{
		return m_SilverMoney;
	}
private:
	//金币
	int64_t m_GoldMoney;
public:
	void SetGoldMoney( int64_t v)
	{
		m_GoldMoney=v;
	}
	int64_t GetGoldMoney()
	{
		return m_GoldMoney;
	}
	int64_t GetGoldMoney() const
	{
		return m_GoldMoney;
	}
private:
	//钻石
	int64_t m_DiamondMoney;
public:
	void SetDiamondMoney( int64_t v)
	{
		m_DiamondMoney=v;
	}
	int64_t GetDiamondMoney()
	{
		return m_DiamondMoney;
	}
	int64_t GetDiamondMoney() const
	{
		return m_DiamondMoney;
	}
private:
	//绑定钻石
	int64_t m_BindingDiamondMoney;
public:
	void SetBindingDiamondMoney( int64_t v)
	{
		m_BindingDiamondMoney=v;
	}
	int64_t GetBindingDiamondMoney()
	{
		return m_BindingDiamondMoney;
	}
	int64_t GetBindingDiamondMoney() const
	{
		return m_BindingDiamondMoney;
	}
private:
	//战力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//精力
	int64_t m_Energy;
public:
	void SetEnergy( int64_t v)
	{
		m_Energy=v;
	}
	int64_t GetEnergy()
	{
		return m_Energy;
	}
	int64_t GetEnergy() const
	{
		return m_Energy;
	}
private:
	//公会资金
	int64_t m_GuildMoney;
public:
	void SetGuildMoney( int64_t v)
	{
		m_GuildMoney=v;
	}
	int64_t GetGuildMoney()
	{
		return m_GuildMoney;
	}
	int64_t GetGuildMoney() const
	{
		return m_GuildMoney;
	}
private:
	//技能列表
	vector<INT32> m_SkillList;
public:
	int SizeSkillList()
	{
		return m_SkillList.size();
	}
	const vector<INT32>& GetSkillList() const
	{
		return m_SkillList;
	}
	INT32 GetSkillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return INT32();
		}
		return m_SkillList[Index];
	}
	void SetSkillList( const vector<INT32>& v )
	{
		m_SkillList=v;
	}
	void ClearSkillList( )
	{
		m_SkillList.clear();
	}
	void SetSkillList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return;
		}
		m_SkillList[Index] = v;
	}
	void AddSkillList( INT32 v = -1 )
	{
		m_SkillList.push_back(v);
	}
private:
	//HonorMoney
	int64_t m_HonorMoney;
public:
	void SetHonorMoney( int64_t v)
	{
		m_HonorMoney=v;
	}
	int64_t GetHonorMoney()
	{
		return m_HonorMoney;
	}
	int64_t GetHonorMoney() const
	{
		return m_HonorMoney;
	}
private:
	//资源池
	int64_t m_ResourcePoolHp;
public:
	void SetResourcePoolHp( int64_t v)
	{
		m_ResourcePoolHp=v;
	}
	int64_t GetResourcePoolHp()
	{
		return m_ResourcePoolHp;
	}
	int64_t GetResourcePoolHp() const
	{
		return m_ResourcePoolHp;
	}
private:
	//伤害增加
	INT32 m_AttackAdd;
public:
	void SetAttackAdd( INT32 v)
	{
		m_AttackAdd=v;
	}
	INT32 GetAttackAdd()
	{
		return m_AttackAdd;
	}
	INT32 GetAttackAdd() const
	{
		return m_AttackAdd;
	}
private:
	//伤害减免
	INT32 m_InjuryAdd;
public:
	void SetInjuryAdd( INT32 v)
	{
		m_InjuryAdd=v;
	}
	INT32 GetInjuryAdd()
	{
		return m_InjuryAdd;
	}
	INT32 GetInjuryAdd() const
	{
		return m_InjuryAdd;
	}
private:
	//冰冻状态
	INT32 m_FrozenState;
public:
	void SetFrozenState( INT32 v)
	{
		m_FrozenState=v;
	}
	INT32 GetFrozenState()
	{
		return m_FrozenState;
	}
	INT32 GetFrozenState() const
	{
		return m_FrozenState;
	}
private:
	//沉默状态
	INT32 m_SilentState;
public:
	void SetSilentState( INT32 v)
	{
		m_SilentState=v;
	}
	INT32 GetSilentState()
	{
		return m_SilentState;
	}
	INT32 GetSilentState() const
	{
		return m_SilentState;
	}
private:
	//GuildContributeHistoryMax
	int64_t m_GuildContributeHistoryMax;
public:
	void SetGuildContributeHistoryMax( int64_t v)
	{
		m_GuildContributeHistoryMax=v;
	}
	int64_t GetGuildContributeHistoryMax()
	{
		return m_GuildContributeHistoryMax;
	}
	int64_t GetGuildContributeHistoryMax() const
	{
		return m_GuildContributeHistoryMax;
	}
private:
	//队伍id
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//头发时装ID
	INT32 m_TreasureHair;
public:
	void SetTreasureHair( INT32 v)
	{
		m_TreasureHair=v;
	}
	INT32 GetTreasureHair()
	{
		return m_TreasureHair;
	}
	INT32 GetTreasureHair() const
	{
		return m_TreasureHair;
	}
private:
	//头部时装ID
	INT32 m_TreasureHead;
public:
	void SetTreasureHead( INT32 v)
	{
		m_TreasureHead=v;
	}
	INT32 GetTreasureHead()
	{
		return m_TreasureHead;
	}
	INT32 GetTreasureHead() const
	{
		return m_TreasureHead;
	}
private:
	//身体时装
	INT32 m_TreasureBody;
public:
	void SetTreasureBody( INT32 v)
	{
		m_TreasureBody=v;
	}
	INT32 GetTreasureBody()
	{
		return m_TreasureBody;
	}
	INT32 GetTreasureBody() const
	{
		return m_TreasureBody;
	}
private:
	//武器时装
	INT32 m_TreasureWeapon;
public:
	void SetTreasureWeapon( INT32 v)
	{
		m_TreasureWeapon=v;
	}
	INT32 GetTreasureWeapon()
	{
		return m_TreasureWeapon;
	}
	INT32 GetTreasureWeapon() const
	{
		return m_TreasureWeapon;
	}
private:
	//翅膀时装
	INT32 m_TreasureWing;
public:
	void SetTreasureWing( INT32 v)
	{
		m_TreasureWing=v;
	}
	INT32 GetTreasureWing()
	{
		return m_TreasureWing;
	}
	INT32 GetTreasureWing() const
	{
		return m_TreasureWing;
	}
private:
	//公会ID
	uint64_t m_GuildGuid;
public:
	void SetGuildGuid( uint64_t v)
	{
		m_GuildGuid=v;
	}
	uint64_t GetGuildGuid()
	{
		return m_GuildGuid;
	}
	uint64_t GetGuildGuid() const
	{
		return m_GuildGuid;
	}
private:
	//坐骑
	INT32 m_TreasureRiding;
public:
	void SetTreasureRiding( INT32 v)
	{
		m_TreasureRiding=v;
	}
	INT32 GetTreasureRiding()
	{
		return m_TreasureRiding;
	}
	INT32 GetTreasureRiding() const
	{
		return m_TreasureRiding;
	}
private:
	//载具Id
	INT32 m_VechicleId;
public:
	void SetVechicleId( INT32 v)
	{
		m_VechicleId=v;
	}
	INT32 GetVechicleId()
	{
		return m_VechicleId;
	}
	INT32 GetVechicleId() const
	{
		return m_VechicleId;
	}
private:
	//动画状态
	bool m_AnimationState;
public:
	void SetAnimationState( bool v)
	{
		m_AnimationState=v;
	}
	bool GetAnimationState()
	{
		return m_AnimationState;
	}
	bool GetAnimationState() const
	{
		return m_AnimationState;
	}
private:
	//修正攻击者最终伤害比率
	float m_RefixDmgRate;
public:
	void SetRefixDmgRate( float v)
	{
		m_RefixDmgRate=v;
	}
	float GetRefixDmgRate()
	{
		return m_RefixDmgRate;
	}
	float GetRefixDmgRate() const
	{
		return m_RefixDmgRate;
	}
private:
	//修正攻击者最终伤害值
	INT32 m_RefixDmgValue;
public:
	void SetRefixDmgValue( INT32 v)
	{
		m_RefixDmgValue=v;
	}
	INT32 GetRefixDmgValue()
	{
		return m_RefixDmgValue;
	}
	INT32 GetRefixDmgValue() const
	{
		return m_RefixDmgValue;
	}
private:
	//修正被攻击者最终伤害比率
	float m_RefixHurtRate;
public:
	void SetRefixHurtRate( float v)
	{
		m_RefixHurtRate=v;
	}
	float GetRefixHurtRate()
	{
		return m_RefixHurtRate;
	}
	float GetRefixHurtRate() const
	{
		return m_RefixHurtRate;
	}
private:
	//修正被攻击者最终伤害值
	INT32 m_RefixHurtValue;
public:
	void SetRefixHurtValue( INT32 v)
	{
		m_RefixHurtValue=v;
	}
	INT32 GetRefixHurtValue()
	{
		return m_RefixHurtValue;
	}
	INT32 GetRefixHurtValue() const
	{
		return m_RefixHurtValue;
	}
private:
	//修正治疗者最终比例
	float m_RefixHealRate;
public:
	void SetRefixHealRate( float v)
	{
		m_RefixHealRate=v;
	}
	float GetRefixHealRate()
	{
		return m_RefixHealRate;
	}
	float GetRefixHealRate() const
	{
		return m_RefixHealRate;
	}
private:
	//修正治疗者最终值
	INT32 m_RefixHealValue;
public:
	void SetRefixHealValue( INT32 v)
	{
		m_RefixHealValue=v;
	}
	INT32 GetRefixHealValue()
	{
		return m_RefixHealValue;
	}
	INT32 GetRefixHealValue() const
	{
		return m_RefixHealValue;
	}
private:
	//修正被治疗者最终比例
	float m_RefixCuredRate;
public:
	void SetRefixCuredRate( float v)
	{
		m_RefixCuredRate=v;
	}
	float GetRefixCuredRate()
	{
		return m_RefixCuredRate;
	}
	float GetRefixCuredRate() const
	{
		return m_RefixCuredRate;
	}
private:
	//修正被治疗者最终值
	INT32 m_RefixCuredValue;
public:
	void SetRefixCuredValue( INT32 v)
	{
		m_RefixCuredValue=v;
	}
	INT32 GetRefixCuredValue()
	{
		return m_RefixCuredValue;
	}
	INT32 GetRefixCuredValue() const
	{
		return m_RefixCuredValue;
	}
private:
	//公会帮贡
	int64_t m_GuildContribute;
public:
	void SetGuildContribute( int64_t v)
	{
		m_GuildContribute=v;
	}
	int64_t GetGuildContribute()
	{
		return m_GuildContribute;
	}
	int64_t GetGuildContribute() const
	{
		return m_GuildContribute;
	}
private:
	//竞技场点数
	int64_t m_PvpMoney;
public:
	void SetPvpMoney( int64_t v)
	{
		m_PvpMoney=v;
	}
	int64_t GetPvpMoney()
	{
		return m_PvpMoney;
	}
	int64_t GetPvpMoney() const
	{
		return m_PvpMoney;
	}
private:
	//公会资源
	int64_t m_GuildResource;
public:
	void SetGuildResource( int64_t v)
	{
		m_GuildResource=v;
	}
	int64_t GetGuildResource()
	{
		return m_GuildResource;
	}
	int64_t GetGuildResource() const
	{
		return m_GuildResource;
	}
private:
	//创建角色时间戳
	INT32 m_CreateRoleTime;
public:
	void SetCreateRoleTime( INT32 v)
	{
		m_CreateRoleTime=v;
	}
	INT32 GetCreateRoleTime()
	{
		return m_CreateRoleTime;
	}
	INT32 GetCreateRoleTime() const
	{
		return m_CreateRoleTime;
	}
private:
	//更新角色等级时间戳
	INT32 m_UpdateRoleTime;
public:
	void SetUpdateRoleTime( INT32 v)
	{
		m_UpdateRoleTime=v;
	}
	INT32 GetUpdateRoleTime()
	{
		return m_UpdateRoleTime;
	}
	INT32 GetUpdateRoleTime() const
	{
		return m_UpdateRoleTime;
	}
private:
	//战斗状态
	bool m_FightState;
public:
	void SetFightState( bool v)
	{
		m_FightState=v;
	}
	bool GetFightState()
	{
		return m_FightState;
	}
	bool GetFightState() const
	{
		return m_FightState;
	}
private:
	//普攻技能列表
	vector<INT32> m_AttackSkillList;
public:
	int SizeAttackSkillList()
	{
		return m_AttackSkillList.size();
	}
	const vector<INT32>& GetAttackSkillList() const
	{
		return m_AttackSkillList;
	}
	INT32 GetAttackSkillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AttackSkillList.size())
		{
			assert(false);
			return INT32();
		}
		return m_AttackSkillList[Index];
	}
	void SetAttackSkillList( const vector<INT32>& v )
	{
		m_AttackSkillList=v;
	}
	void ClearAttackSkillList( )
	{
		m_AttackSkillList.clear();
	}
	void SetAttackSkillList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_AttackSkillList.size())
		{
			assert(false);
			return;
		}
		m_AttackSkillList[Index] = v;
	}
	void AddAttackSkillList( INT32 v = -1 )
	{
		m_AttackSkillList.push_back(v);
	}
private:
	//公会名称
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//是否可选中
	bool m_IsAllowSelect;
public:
	void SetIsAllowSelect( bool v)
	{
		m_IsAllowSelect=v;
	}
	bool GetIsAllowSelect()
	{
		return m_IsAllowSelect;
	}
	bool GetIsAllowSelect() const
	{
		return m_IsAllowSelect;
	}
private:
	//怪物回归中
	bool m_GoHomeState;
public:
	void SetGoHomeState( bool v)
	{
		m_GoHomeState=v;
	}
	bool GetGoHomeState()
	{
		return m_GoHomeState;
	}
	bool GetGoHomeState() const
	{
		return m_GoHomeState;
	}
private:
	//怪物是否可攻击
	bool m_CanFight;
public:
	void SetCanFight( bool v)
	{
		m_CanFight=v;
	}
	bool GetCanFight()
	{
		return m_CanFight;
	}
	bool GetCanFight() const
	{
		return m_CanFight;
	}
private:
	//双倍经验
	int64_t m_DoubleExp;
public:
	void SetDoubleExp( int64_t v)
	{
		m_DoubleExp=v;
	}
	int64_t GetDoubleExp()
	{
		return m_DoubleExp;
	}
	int64_t GetDoubleExp() const
	{
		return m_DoubleExp;
	}
private:
	//友情点
	int64_t m_FriendPoint;
public:
	void SetFriendPoint( int64_t v)
	{
		m_FriendPoint=v;
	}
	int64_t GetFriendPoint()
	{
		return m_FriendPoint;
	}
	int64_t GetFriendPoint() const
	{
		return m_FriendPoint;
	}
private:
	//历史最大荣誉点
	int64_t m_HisMaxHonor;
public:
	void SetHisMaxHonor( int64_t v)
	{
		m_HisMaxHonor=v;
	}
	int64_t GetHisMaxHonor()
	{
		return m_HisMaxHonor;
	}
	int64_t GetHisMaxHonor() const
	{
		return m_HisMaxHonor;
	}
private:
	//受击状态
	bool m_HurtState;
public:
	void SetHurtState( bool v)
	{
		m_HurtState=v;
	}
	bool GetHurtState()
	{
		return m_HurtState;
	}
	bool GetHurtState() const
	{
		return m_HurtState;
	}
private:
	//击飞状态
	bool m_HurtFlyState;
public:
	void SetHurtFlyState( bool v)
	{
		m_HurtFlyState=v;
	}
	bool GetHurtFlyState()
	{
		return m_HurtFlyState;
	}
	bool GetHurtFlyState() const
	{
		return m_HurtFlyState;
	}
private:
	//击倒状态
	bool m_HurtDownState;
public:
	void SetHurtDownState( bool v)
	{
		m_HurtDownState=v;
	}
	bool GetHurtDownState()
	{
		return m_HurtDownState;
	}
	bool GetHurtDownState() const
	{
		return m_HurtDownState;
	}
private:
	//击退
	bool m_HurtRepelState;
public:
	void SetHurtRepelState( bool v)
	{
		m_HurtRepelState=v;
	}
	bool GetHurtRepelState()
	{
		return m_HurtRepelState;
	}
	bool GetHurtRepelState() const
	{
		return m_HurtRepelState;
	}
private:
	//今日获得的荣誉值
	int64_t m_TodayHornor;
public:
	void SetTodayHornor( int64_t v)
	{
		m_TodayHornor=v;
	}
	int64_t GetTodayHornor()
	{
		return m_TodayHornor;
	}
	int64_t GetTodayHornor() const
	{
		return m_TodayHornor;
	}
private:
	//当前专精
	INT32 m_CurProfession;
public:
	void SetCurProfession( INT32 v)
	{
		m_CurProfession=v;
	}
	INT32 GetCurProfession()
	{
		return m_CurProfession;
	}
	INT32 GetCurProfession() const
	{
		return m_CurProfession;
	}
private:
	//宠物创建删除条件枚举
	INT32 m_PetCreateDelCond;
public:
	void SetPetCreateDelCond( INT32 v)
	{
		m_PetCreateDelCond=v;
	}
	INT32 GetPetCreateDelCond()
	{
		return m_PetCreateDelCond;
	}
	INT32 GetPetCreateDelCond() const
	{
		return m_PetCreateDelCond;
	}
private:
	//宠物是否需要隐藏1显示0隐藏
	INT32 m_PetDisplay;
public:
	void SetPetDisplay( INT32 v)
	{
		m_PetDisplay=v;
	}
	INT32 GetPetDisplay()
	{
		return m_PetDisplay;
	}
	INT32 GetPetDisplay() const
	{
		return m_PetDisplay;
	}
private:
	//宠物货币
	int64_t m_PetMoney;
public:
	void SetPetMoney( int64_t v)
	{
		m_PetMoney=v;
	}
	int64_t GetPetMoney()
	{
		return m_PetMoney;
	}
	int64_t GetPetMoney() const
	{
		return m_PetMoney;
	}
private:
	//决斗状态
	INT32 m_DuelStatus;
public:
	void SetDuelStatus( INT32 v)
	{
		m_DuelStatus=v;
	}
	INT32 GetDuelStatus()
	{
		return m_DuelStatus;
	}
	INT32 GetDuelStatus() const
	{
		return m_DuelStatus;
	}
private:
	//经验池
	int64_t m_ExpPool;
public:
	void SetExpPool( int64_t v)
	{
		m_ExpPool=v;
	}
	int64_t GetExpPool()
	{
		return m_ExpPool;
	}
	int64_t GetExpPool() const
	{
		return m_ExpPool;
	}
private:
	//疾跑状态
	bool m_RushState;
public:
	void SetRushState( bool v)
	{
		m_RushState=v;
	}
	bool GetRushState()
	{
		return m_RushState;
	}
	bool GetRushState() const
	{
		return m_RushState;
	}
private:
	//盯防状态
	uint64_t m_StareState;
public:
	void SetStareState( uint64_t v)
	{
		m_StareState=v;
	}
	uint64_t GetStareState()
	{
		return m_StareState;
	}
	uint64_t GetStareState() const
	{
		return m_StareState;
	}
private:
	//世界等级
	INT32 m_WorldLevel;
public:
	void SetWorldLevel( INT32 v)
	{
		m_WorldLevel=v;
	}
	INT32 GetWorldLevel()
	{
		return m_WorldLevel;
	}
	INT32 GetWorldLevel() const
	{
		return m_WorldLevel;
	}
private:
	//眩晕命中率
	float m_DizzyHitRate;
public:
	void SetDizzyHitRate( float v)
	{
		m_DizzyHitRate=v;
	}
	float GetDizzyHitRate()
	{
		return m_DizzyHitRate;
	}
	float GetDizzyHitRate() const
	{
		return m_DizzyHitRate;
	}
private:
	//眩晕抵抗率
	float m_DizzyResistRate;
public:
	void SetDizzyResistRate( float v)
	{
		m_DizzyResistRate=v;
	}
	float GetDizzyResistRate()
	{
		return m_DizzyResistRate;
	}
	float GetDizzyResistRate() const
	{
		return m_DizzyResistRate;
	}
private:
	//定身命中率
	float m_ImmovableHitRate;
public:
	void SetImmovableHitRate( float v)
	{
		m_ImmovableHitRate=v;
	}
	float GetImmovableHitRate()
	{
		return m_ImmovableHitRate;
	}
	float GetImmovableHitRate() const
	{
		return m_ImmovableHitRate;
	}
private:
	//定身抵抗率
	float m_ImmovableResistRate;
public:
	void SetImmovableResistRate( float v)
	{
		m_ImmovableResistRate=v;
	}
	float GetImmovableResistRate()
	{
		return m_ImmovableResistRate;
	}
	float GetImmovableResistRate() const
	{
		return m_ImmovableResistRate;
	}
private:
	//击飞命中率
	float m_HurtFlyHitRate;
public:
	void SetHurtFlyHitRate( float v)
	{
		m_HurtFlyHitRate=v;
	}
	float GetHurtFlyHitRate()
	{
		return m_HurtFlyHitRate;
	}
	float GetHurtFlyHitRate() const
	{
		return m_HurtFlyHitRate;
	}
private:
	//击飞抵抗率
	float m_HurtFlyResistRate;
public:
	void SetHurtFlyResistRate( float v)
	{
		m_HurtFlyResistRate=v;
	}
	float GetHurtFlyResistRate()
	{
		return m_HurtFlyResistRate;
	}
	float GetHurtFlyResistRate() const
	{
		return m_HurtFlyResistRate;
	}
private:
	//冰冻命中率
	float m_FrozenHitRate;
public:
	void SetFrozenHitRate( float v)
	{
		m_FrozenHitRate=v;
	}
	float GetFrozenHitRate()
	{
		return m_FrozenHitRate;
	}
	float GetFrozenHitRate() const
	{
		return m_FrozenHitRate;
	}
private:
	//冰冻抵抗率
	float m_FrozenResistRate;
public:
	void SetFrozenResistRate( float v)
	{
		m_FrozenResistRate=v;
	}
	float GetFrozenResistRate()
	{
		return m_FrozenResistRate;
	}
	float GetFrozenResistRate() const
	{
		return m_FrozenResistRate;
	}
private:
	//净化命中率
	float m_CleanHitRate;
public:
	void SetCleanHitRate( float v)
	{
		m_CleanHitRate=v;
	}
	float GetCleanHitRate()
	{
		return m_CleanHitRate;
	}
	float GetCleanHitRate() const
	{
		return m_CleanHitRate;
	}
private:
	//净化抵抗率
	float m_CleanResistRate;
public:
	void SetCleanResistRate( float v)
	{
		m_CleanResistRate=v;
	}
	float GetCleanResistRate()
	{
		return m_CleanResistRate;
	}
	float GetCleanResistRate() const
	{
		return m_CleanResistRate;
	}
private:
	//驱散命中率
	float m_DispelHitRate;
public:
	void SetDispelHitRate( float v)
	{
		m_DispelHitRate=v;
	}
	float GetDispelHitRate()
	{
		return m_DispelHitRate;
	}
	float GetDispelHitRate() const
	{
		return m_DispelHitRate;
	}
private:
	//驱散抵抗率
	float m_DispelResistRate;
public:
	void SetDispelResistRate( float v)
	{
		m_DispelResistRate=v;
	}
	float GetDispelResistRate()
	{
		return m_DispelResistRate;
	}
	float GetDispelResistRate() const
	{
		return m_DispelResistRate;
	}
private:
	//沉默命中率
	float m_SilenceHitRate;
public:
	void SetSilenceHitRate( float v)
	{
		m_SilenceHitRate=v;
	}
	float GetSilenceHitRate()
	{
		return m_SilenceHitRate;
	}
	float GetSilenceHitRate() const
	{
		return m_SilenceHitRate;
	}
private:
	//沉默抵抗率
	float m_SilenceResistRate;
public:
	void SetSilenceResistRate( float v)
	{
		m_SilenceResistRate=v;
	}
	float GetSilenceResistRate()
	{
		return m_SilenceResistRate;
	}
	float GetSilenceResistRate() const
	{
		return m_SilenceResistRate;
	}
private:
	//打断命中率
	float m_InterruptHitRate;
public:
	void SetInterruptHitRate( float v)
	{
		m_InterruptHitRate=v;
	}
	float GetInterruptHitRate()
	{
		return m_InterruptHitRate;
	}
	float GetInterruptHitRate() const
	{
		return m_InterruptHitRate;
	}
private:
	//打断抵抗率
	float m_InterruptResistRate;
public:
	void SetInterruptResistRate( float v)
	{
		m_InterruptResistRate=v;
	}
	float GetInterruptResistRate()
	{
		return m_InterruptResistRate;
	}
	float GetInterruptResistRate() const
	{
		return m_InterruptResistRate;
	}
private:
	//禁疗命中率
	float m_UncurableHitRate;
public:
	void SetUncurableHitRate( float v)
	{
		m_UncurableHitRate=v;
	}
	float GetUncurableHitRate()
	{
		return m_UncurableHitRate;
	}
	float GetUncurableHitRate() const
	{
		return m_UncurableHitRate;
	}
private:
	//禁疗抵抗率
	float m_UncurableResistRate;
public:
	void SetUncurableResistRate( float v)
	{
		m_UncurableResistRate=v;
	}
	float GetUncurableResistRate()
	{
		return m_UncurableResistRate;
	}
	float GetUncurableResistRate() const
	{
		return m_UncurableResistRate;
	}
private:
	//变身
	INT32 m_Transform;
public:
	void SetTransform( INT32 v)
	{
		m_Transform=v;
	}
	INT32 GetTransform()
	{
		return m_Transform;
	}
	INT32 GetTransform() const
	{
		return m_Transform;
	}
private:
	//受到玩家目标伤害比
	float m_HumanHurtRate;
public:
	void SetHumanHurtRate( float v)
	{
		m_HumanHurtRate=v;
	}
	float GetHumanHurtRate()
	{
		return m_HumanHurtRate;
	}
	float GetHumanHurtRate() const
	{
		return m_HumanHurtRate;
	}
private:
	//针对玩家目标伤害比
	float m_HumanSufferRate;
public:
	void SetHumanSufferRate( float v)
	{
		m_HumanSufferRate=v;
	}
	float GetHumanSufferRate()
	{
		return m_HumanSufferRate;
	}
	float GetHumanSufferRate() const
	{
		return m_HumanSufferRate;
	}
private:
	//受到怪物目标伤害比
	float m_MonsterHurtRate;
public:
	void SetMonsterHurtRate( float v)
	{
		m_MonsterHurtRate=v;
	}
	float GetMonsterHurtRate()
	{
		return m_MonsterHurtRate;
	}
	float GetMonsterHurtRate() const
	{
		return m_MonsterHurtRate;
	}
private:
	//针对怪物目标伤害比
	float m_MonsterSufferRate;
public:
	void SetMonsterSufferRate( float v)
	{
		m_MonsterSufferRate=v;
	}
	float GetMonsterSufferRate()
	{
		return m_MonsterSufferRate;
	}
	float GetMonsterSufferRate() const
	{
		return m_MonsterSufferRate;
	}
private:
	//受到Boss目标伤害比
	float m_BossHurtRate;
public:
	void SetBossHurtRate( float v)
	{
		m_BossHurtRate=v;
	}
	float GetBossHurtRate()
	{
		return m_BossHurtRate;
	}
	float GetBossHurtRate() const
	{
		return m_BossHurtRate;
	}
private:
	//针对Boss目标伤害比
	float m_BossSufferRate;
public:
	void SetBossSufferRate( float v)
	{
		m_BossSufferRate=v;
	}
	float GetBossSufferRate()
	{
		return m_BossSufferRate;
	}
	float GetBossSufferRate() const
	{
		return m_BossSufferRate;
	}
private:
	//格挡减伤值
	INT32 m_DodgReduceValue;
public:
	void SetDodgReduceValue( INT32 v)
	{
		m_DodgReduceValue=v;
	}
	INT32 GetDodgReduceValue()
	{
		return m_DodgReduceValue;
	}
	INT32 GetDodgReduceValue() const
	{
		return m_DodgReduceValue;
	}
private:
	//格挡减伤率
	float m_DodgReduceRate;
public:
	void SetDodgReduceRate( float v)
	{
		m_DodgReduceRate=v;
	}
	float GetDodgReduceRate()
	{
		return m_DodgReduceRate;
	}
	float GetDodgReduceRate() const
	{
		return m_DodgReduceRate;
	}
private:
	//格挡破伤值
	INT32 m_DodgAddValue;
public:
	void SetDodgAddValue( INT32 v)
	{
		m_DodgAddValue=v;
	}
	INT32 GetDodgAddValue()
	{
		return m_DodgAddValue;
	}
	INT32 GetDodgAddValue() const
	{
		return m_DodgAddValue;
	}
private:
	//格挡破伤率
	float m_DodgAddRate;
public:
	void SetDodgAddRate( float v)
	{
		m_DodgAddRate=v;
	}
	float GetDodgAddRate()
	{
		return m_DodgAddRate;
	}
	float GetDodgAddRate() const
	{
		return m_DodgAddRate;
	}
private:
	//步尘
	INT32 m_TreasureFootPrint;
public:
	void SetTreasureFootPrint( INT32 v)
	{
		m_TreasureFootPrint=v;
	}
	INT32 GetTreasureFootPrint()
	{
		return m_TreasureFootPrint;
	}
	INT32 GetTreasureFootPrint() const
	{
		return m_TreasureFootPrint;
	}
private:
	//装备称号
	INT32 m_EquipTitle;
public:
	void SetEquipTitle( INT32 v)
	{
		m_EquipTitle=v;
	}
	INT32 GetEquipTitle()
	{
		return m_EquipTitle;
	}
	INT32 GetEquipTitle() const
	{
		return m_EquipTitle;
	}
private:
	//当前所在动画事件
	vector<INT32> m_ObjAnimEvent;
public:
	int SizeObjAnimEvent()
	{
		return m_ObjAnimEvent.size();
	}
	const vector<INT32>& GetObjAnimEvent() const
	{
		return m_ObjAnimEvent;
	}
	INT32 GetObjAnimEvent(int Index) const
	{
		if(Index<0 || Index>=(int)m_ObjAnimEvent.size())
		{
			assert(false);
			return INT32();
		}
		return m_ObjAnimEvent[Index];
	}
	void SetObjAnimEvent( const vector<INT32>& v )
	{
		m_ObjAnimEvent=v;
	}
	void ClearObjAnimEvent( )
	{
		m_ObjAnimEvent.clear();
	}
	void SetObjAnimEvent( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ObjAnimEvent.size())
		{
			assert(false);
			return;
		}
		m_ObjAnimEvent[Index] = v;
	}
	void AddObjAnimEvent( INT32 v = -1 )
	{
		m_ObjAnimEvent.push_back(v);
	}
private:
	//捏脸数据
	string m_PinchData;
public:
	void SetPinchData( const string& v)
	{
		m_PinchData=v;
	}
	string GetPinchData()
	{
		return m_PinchData;
	}
	string GetPinchData() const
	{
		return m_PinchData;
	}
private:
	//技能冷缩比例
	float m_SkillCDRate;
public:
	void SetSkillCDRate( float v)
	{
		m_SkillCDRate=v;
	}
	float GetSkillCDRate()
	{
		return m_SkillCDRate;
	}
	float GetSkillCDRate() const
	{
		return m_SkillCDRate;
	}
private:
	//攻速
	float m_AspdRate;
public:
	void SetAspdRate( float v)
	{
		m_AspdRate=v;
	}
	float GetAspdRate()
	{
		return m_AspdRate;
	}
	float GetAspdRate() const
	{
		return m_AspdRate;
	}
private:
	//护盾值
	INT32 m_Shield;
public:
	void SetShield( INT32 v)
	{
		m_Shield=v;
	}
	INT32 GetShield()
	{
		return m_Shield;
	}
	INT32 GetShield() const
	{
		return m_Shield;
	}
private:
	//obj剩余采集次数
	INT32 m_EventLeftCount;
public:
	void SetEventLeftCount( INT32 v)
	{
		m_EventLeftCount=v;
	}
	INT32 GetEventLeftCount()
	{
		return m_EventLeftCount;
	}
	INT32 GetEventLeftCount() const
	{
		return m_EventLeftCount;
	}
private:
	//不能疾跑状态
	INT32 m_CanNotRush;
public:
	void SetCanNotRush( INT32 v)
	{
		m_CanNotRush=v;
	}
	INT32 GetCanNotRush()
	{
		return m_CanNotRush;
	}
	INT32 GetCanNotRush() const
	{
		return m_CanNotRush;
	}
private:
	//猎魔点数
	INT32 m_HuntPoint;
public:
	void SetHuntPoint( INT32 v)
	{
		m_HuntPoint=v;
	}
	INT32 GetHuntPoint()
	{
		return m_HuntPoint;
	}
	INT32 GetHuntPoint() const
	{
		return m_HuntPoint;
	}
private:
	//猎魔高倍
	INT32 m_HuntHighTimes;
public:
	void SetHuntHighTimes( INT32 v)
	{
		m_HuntHighTimes=v;
	}
	INT32 GetHuntHighTimes()
	{
		return m_HuntHighTimes;
	}
	INT32 GetHuntHighTimes() const
	{
		return m_HuntHighTimes;
	}
private:
	//猎魔引燃次数
	INT32 m_HuntFirePoint;
public:
	void SetHuntFirePoint( INT32 v)
	{
		m_HuntFirePoint=v;
	}
	INT32 GetHuntFirePoint()
	{
		return m_HuntFirePoint;
	}
	INT32 GetHuntFirePoint() const
	{
		return m_HuntFirePoint;
	}
private:
	//星耀NPC状态(1可进入 2不可进入)
	INT32 m_Starbattlestate;
public:
	void SetStarbattlestate( INT32 v)
	{
		m_Starbattlestate=v;
	}
	INT32 GetStarbattlestate()
	{
		return m_Starbattlestate;
	}
	INT32 GetStarbattlestate() const
	{
		return m_Starbattlestate;
	}
private:
	//是否忽略地图阻挡
	bool m_IgnoreMotionBlock;
public:
	void SetIgnoreMotionBlock( bool v)
	{
		m_IgnoreMotionBlock=v;
	}
	bool GetIgnoreMotionBlock()
	{
		return m_IgnoreMotionBlock;
	}
	bool GetIgnoreMotionBlock() const
	{
		return m_IgnoreMotionBlock;
	}
private:
	//EnableInteract
	bool m_EnableInteract;
public:
	void SetEnableInteract( bool v)
	{
		m_EnableInteract=v;
	}
	bool GetEnableInteract()
	{
		return m_EnableInteract;
	}
	bool GetEnableInteract() const
	{
		return m_EnableInteract;
	}
private:
	//世界奖章
	INT32 m_WorldMedal;
public:
	void SetWorldMedal( INT32 v)
	{
		m_WorldMedal=v;
	}
	INT32 GetWorldMedal()
	{
		return m_WorldMedal;
	}
	INT32 GetWorldMedal() const
	{
		return m_WorldMedal;
	}
private:
	//治疗上限
	INT32 m_CureCeiling;
public:
	void SetCureCeiling( INT32 v)
	{
		m_CureCeiling=v;
	}
	INT32 GetCureCeiling()
	{
		return m_CureCeiling;
	}
	INT32 GetCureCeiling() const
	{
		return m_CureCeiling;
	}
private:
	//圣乐之力
	INT32 m_RelationUnionCurrency;
public:
	void SetRelationUnionCurrency( INT32 v)
	{
		m_RelationUnionCurrency=v;
	}
	INT32 GetRelationUnionCurrency()
	{
		return m_RelationUnionCurrency;
	}
	INT32 GetRelationUnionCurrency() const
	{
		return m_RelationUnionCurrency;
	}
private:
	//公会简称
	string m_GuildShortName;
public:
	void SetGuildShortName( const string& v)
	{
		m_GuildShortName=v;
	}
	string GetGuildShortName()
	{
		return m_GuildShortName;
	}
	string GetGuildShortName() const
	{
		return m_GuildShortName;
	}
private:
	//公会简称颜色ID
	INT32 m_GuildShortColorID;
public:
	void SetGuildShortColorID( INT32 v)
	{
		m_GuildShortColorID=v;
	}
	INT32 GetGuildShortColorID()
	{
		return m_GuildShortColorID;
	}
	INT32 GetGuildShortColorID() const
	{
		return m_GuildShortColorID;
	}

};

#endif
