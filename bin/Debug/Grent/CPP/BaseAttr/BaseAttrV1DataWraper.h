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
		m_RoleId = -1;
		m_Strength = 0;
		m_Agility = 0;
		m_Intellectual = 0;
		m_Endurance = 0;
		m_Spirit = 0;
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
		m_DizzyState = false;
		m_GodState = false;
		m_CantMoveState = false;
		m_PhysicAddition = 0;
		m_MagicAddition = 0;
		m_PhysicOppose = 0;
		m_MagicOppose = 0;

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
		v.set_spirit( m_Spirit );
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
		m_Spirit = v.spirit();
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
	int64_t m_ServerTime;
public:
	void SetServerTime( int64_t v)
	{
		m_ServerTime=v;
	}
	int64_t GetServerTime()
	{
		return m_ServerTime;
	}
	int64_t GetServerTime() const
	{
		return m_ServerTime;
	}
private:
	//人物唯一ID
	int64_t m_RoleId;
public:
	void SetRoleId( int64_t v)
	{
		m_RoleId=v;
	}
	int64_t GetRoleId()
	{
		return m_RoleId;
	}
	int64_t GetRoleId() const
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
	//精神
	INT32 m_Spirit;
public:
	void SetSpirit( INT32 v)
	{
		m_Spirit=v;
	}
	INT32 GetSpirit()
	{
		return m_Spirit;
	}
	INT32 GetSpirit() const
	{
		return m_Spirit;
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
	bool m_DizzyState;
public:
	void SetDizzyState( bool v)
	{
		m_DizzyState=v;
	}
	bool GetDizzyState()
	{
		return m_DizzyState;
	}
	bool GetDizzyState() const
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
	bool m_CantMoveState;
public:
	void SetCantMoveState( bool v)
	{
		m_CantMoveState=v;
	}
	bool GetCantMoveState()
	{
		return m_CantMoveState;
	}
	bool GetCantMoveState() const
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

};

#endif
