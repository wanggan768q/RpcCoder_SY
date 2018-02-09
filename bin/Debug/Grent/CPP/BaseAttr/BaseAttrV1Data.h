#ifndef __SYNC_DATA_BASEATTR_V1_H
#define __SYNC_DATA_BASEATTR_V1_H

//#include "BASE.h"

//#include "ModuleDataInterface.h"
//#include "ModuleDataClassFactory.h"
//#include "MsgStreamMgr.h"
//#include "BaseAttrV1DataWraper.h"

#include <cstdint>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include "BaseDef.h"
#include "BaseAttrV1DataWraper.h"
#include "PropertiesModule.h"


//同步数据相关枚举量定义
enum BaseAttrSyncDataItemIdE
{
 	SYNCID_BASEATTR_EXP                         = 701,  //经验
 	SYNCID_BASEATTR_LEVEL                       = 703,  //玩家等级
 	SYNCID_BASEATTR_SERVERTIME                  = 704,  //服务器时间
 	SYNCID_BASEATTR_ROLEID                      = 705,  //人物唯一ID
 	SYNCID_BASEATTR_STRENGTH                    = 707,  //力量
 	SYNCID_BASEATTR_AGILITY                     = 708,  //敏捷
 	SYNCID_BASEATTR_INTELLECTUAL                = 709,  //智力
 	SYNCID_BASEATTR_ENDURANCE                   = 710,  //耐力
 	SYNCID_BASEATTR_SPIRIT                      = 711,  //精神
 	SYNCID_BASEATTR_HP                          = 712,  //生命值
 	SYNCID_BASEATTR_MAXHP                       = 714,  //生命值
 	SYNCID_BASEATTR_PHYSICATTACK                = 715,  //物理攻击
 	SYNCID_BASEATTR_PHYSICDEFENSE               = 716,  //物理防御
 	SYNCID_BASEATTR_MAGICATTACK                 = 719,  //魔法攻击
 	SYNCID_BASEATTR_MAGICDEFENSE                = 720,  //魔法防御
 	SYNCID_BASEATTR_HIT                         = 721,  //命中值
 	SYNCID_BASEATTR_HITRATE                     = 722,  //命中率
 	SYNCID_BASEATTR_MISS                        = 723,  //闪避值
 	SYNCID_BASEATTR_MISSRATE                    = 724,  //闪避率
 	SYNCID_BASEATTR_CRITICAL                    = 725,  //暴击值
 	SYNCID_BASEATTR_CRITICALRATE                = 726,  //暴击率
 	SYNCID_BASEATTR_TENACITY                    = 727,  //韧性值
 	SYNCID_BASEATTR_TENACITYRATE                = 728,  //韧性率
 	SYNCID_BASEATTR_PENET                       = 729,  //穿透值
 	SYNCID_BASEATTR_PENETRATE                   = 730,  //穿透率
 	SYNCID_BASEATTR_DODG                        = 731,  //格挡值
 	SYNCID_BASEATTR_DODGRATE                    = 732,  //格挡率
 	SYNCID_BASEATTR_CRITICALADDITION            = 733,  //暴击加伤值
 	SYNCID_BASEATTR_CRITICALADDITIONRATE        = 734,  //暴击加伤率
 	SYNCID_BASEATTR_CRITICALIMMUNE              = 735,  //暴击免伤
 	SYNCID_BASEATTR_CRITICALIMMUNERATE          = 736,  //暴击免伤率
 	SYNCID_BASEATTR_MISSLEVEL                   = 737,  //闪避等级
 	SYNCID_BASEATTR_CRITICALLEVEL               = 738,  //暴击等级
 	SYNCID_BASEATTR_DODGLEVEL                   = 739,  //格挡等级
 	SYNCID_BASEATTR_MOVESPEED                   = 740,  //移动速度
 	SYNCID_BASEATTR_DIZZYSTATE                  = 741,  //眩晕状态
 	SYNCID_BASEATTR_GODSTATE                    = 742,  //霸体状态
 	SYNCID_BASEATTR_CANTMOVESTATE               = 743,  //不能移动状态
 	SYNCID_BASEATTR_PHYSICADDITION              = 745,  //物理加伤值
 	SYNCID_BASEATTR_MAGICADDITION               = 746,  //魔法加伤值
 	SYNCID_BASEATTR_PHYSICOPPOSE                = 747,  //物理抗性
 	SYNCID_BASEATTR_MAGICOPPOSE                 = 748,  //魔法抗性

};

class Obj_Character;
//主同步数据操作类
class SyncDataBaseAttrV1
{
public:
	typedef std::unordered_set<int32_t> id_type;
	typedef std::function<Property()> calc_callback_type;
	typedef std::unordered_map<int32_t, calc_callback_type> function_type;
	typedef std::function<void (BaseAttrUserDataV1&)> send_callback_type;

public:
			SyncDataBaseAttrV1(Obj_Character*);
	virtual	~SyncDataBaseAttrV1();

	void 	Init();
	void	SendAllMembers();
	void 	SetSendCallBack(const send_callback_type & cb);
	void 	CalcAllMembers();

	//string  ToHtml(){ return m_syncDataUserData.ToHtml(); }
	//string  HtmlDescHeader() { return m_syncDataUserData.HtmlDescHeader(); }

	template <typename T>
	void CalcMethodCB(int32_t nType, T&cb)
	{
		id_type::iterator it = m_vCalcPropertyIds.find(nType);
		if (it != m_vCalcPropertyIds.end())
		{
			function_type::iterator fi = m_oCaclPropertyCallbacks.find(nType);
			if (fi != m_oCaclPropertyCallbacks.end())
			{
				cb(fi->second());
			}

			m_vCalcPropertyIds.erase(it);
		}
	}

	string SerializeAsString()
	{
		CalcAllMembers();
		return m_syncDataUserData.SerializeAsString();
	}

	void SetChange(bool b)
	{
		m_bChange = b;
	}

public:
	//经验
	void SetExp( const INT32& v );
	INT32 GetExp();
	void RefreshExp();
	void SendExp(bool OnlyToClient=true);
public:
	//玩家等级
	void SetLevel( const INT32& v );
	INT32 GetLevel();
	void RefreshLevel();
	void SendLevel(bool OnlyToClient=true);
public:
	//服务器时间
	void SetServerTime( const int64_t& v );
	int64_t GetServerTime();
	void RefreshServerTime();
	void SendServerTime(bool OnlyToClient=true);
public:
	//人物唯一ID
	void SetRoleId( const int64_t& v );
	int64_t GetRoleId();
	void RefreshRoleId();
	void SendRoleId(bool OnlyToClient=true);
public:
	//力量
	void SetStrength( const INT32& v );
	INT32 GetStrength();
	void RefreshStrength();
	void SendStrength(bool OnlyToClient=true);
public:
	//敏捷
	void SetAgility( const INT32& v );
	INT32 GetAgility();
	void RefreshAgility();
	void SendAgility(bool OnlyToClient=true);
public:
	//智力
	void SetIntellectual( const INT32& v );
	INT32 GetIntellectual();
	void RefreshIntellectual();
	void SendIntellectual(bool OnlyToClient=true);
public:
	//耐力
	void SetEndurance( const INT32& v );
	INT32 GetEndurance();
	void RefreshEndurance();
	void SendEndurance(bool OnlyToClient=true);
public:
	//精神
	void SetSpirit( const INT32& v );
	INT32 GetSpirit();
	void RefreshSpirit();
	void SendSpirit(bool OnlyToClient=true);
public:
	//生命值
	void SetHp( const INT32& v );
	INT32 GetHp();
	void RefreshHp();
	void SendHp(bool OnlyToClient=true);
public:
	//生命值
	void SetMaxHp( const INT32& v );
	INT32 GetMaxHp();
	void RefreshMaxHp();
	void SendMaxHp(bool OnlyToClient=true);
public:
	//物理攻击
	void SetPhysicAttack( const INT32& v );
	INT32 GetPhysicAttack();
	void RefreshPhysicAttack();
	void SendPhysicAttack(bool OnlyToClient=true);
public:
	//物理防御
	void SetPhysicDefense( const INT32& v );
	INT32 GetPhysicDefense();
	void RefreshPhysicDefense();
	void SendPhysicDefense(bool OnlyToClient=true);
public:
	//魔法攻击
	void SetMagicAttack( const INT32& v );
	INT32 GetMagicAttack();
	void RefreshMagicAttack();
	void SendMagicAttack(bool OnlyToClient=true);
public:
	//魔法防御
	void SetMagicDefense( const INT32& v );
	INT32 GetMagicDefense();
	void RefreshMagicDefense();
	void SendMagicDefense(bool OnlyToClient=true);
public:
	//命中值
	void SetHit( const INT32& v );
	INT32 GetHit();
	void RefreshHit();
	void SendHit(bool OnlyToClient=true);
public:
	//命中率
	void SetHitRate( const float& v );
	float GetHitRate();
	void RefreshHitRate();
	void SendHitRate(bool OnlyToClient=true);
public:
	//闪避值
	void SetMiss( const INT32& v );
	INT32 GetMiss();
	void RefreshMiss();
	void SendMiss(bool OnlyToClient=true);
public:
	//闪避率
	void SetMissRate( const float& v );
	float GetMissRate();
	void RefreshMissRate();
	void SendMissRate(bool OnlyToClient=true);
public:
	//暴击值
	void SetCritical( const INT32& v );
	INT32 GetCritical();
	void RefreshCritical();
	void SendCritical(bool OnlyToClient=true);
public:
	//暴击率
	void SetCriticalRate( const float& v );
	float GetCriticalRate();
	void RefreshCriticalRate();
	void SendCriticalRate(bool OnlyToClient=true);
public:
	//韧性值
	void SetTenacity( const INT32& v );
	INT32 GetTenacity();
	void RefreshTenacity();
	void SendTenacity(bool OnlyToClient=true);
public:
	//韧性率
	void SetTenacityRate( const float& v );
	float GetTenacityRate();
	void RefreshTenacityRate();
	void SendTenacityRate(bool OnlyToClient=true);
public:
	//穿透值
	void SetPenet( const INT32& v );
	INT32 GetPenet();
	void RefreshPenet();
	void SendPenet(bool OnlyToClient=true);
public:
	//穿透率
	void SetPenetRate( const float& v );
	float GetPenetRate();
	void RefreshPenetRate();
	void SendPenetRate(bool OnlyToClient=true);
public:
	//格挡值
	void SetDodg( const INT32& v );
	INT32 GetDodg();
	void RefreshDodg();
	void SendDodg(bool OnlyToClient=true);
public:
	//格挡率
	void SetDodgRate( const float& v );
	float GetDodgRate();
	void RefreshDodgRate();
	void SendDodgRate(bool OnlyToClient=true);
public:
	//暴击加伤值
	void SetCriticalAddition( const INT32& v );
	INT32 GetCriticalAddition();
	void RefreshCriticalAddition();
	void SendCriticalAddition(bool OnlyToClient=true);
public:
	//暴击加伤率
	void SetCriticalAdditionRate( const float& v );
	float GetCriticalAdditionRate();
	void RefreshCriticalAdditionRate();
	void SendCriticalAdditionRate(bool OnlyToClient=true);
public:
	//暴击免伤
	void SetCriticalImmune( const INT32& v );
	INT32 GetCriticalImmune();
	void RefreshCriticalImmune();
	void SendCriticalImmune(bool OnlyToClient=true);
public:
	//暴击免伤率
	void SetCriticalImmuneRate( const float& v );
	float GetCriticalImmuneRate();
	void RefreshCriticalImmuneRate();
	void SendCriticalImmuneRate(bool OnlyToClient=true);
public:
	//闪避等级
	void SetMissLevel( const INT32& v );
	INT32 GetMissLevel();
	void RefreshMissLevel();
	void SendMissLevel(bool OnlyToClient=true);
public:
	//暴击等级
	void SetCriticalLevel( const INT32& v );
	INT32 GetCriticalLevel();
	void RefreshCriticalLevel();
	void SendCriticalLevel(bool OnlyToClient=true);
public:
	//格挡等级
	void SetDodgLevel( const INT32& v );
	INT32 GetDodgLevel();
	void RefreshDodgLevel();
	void SendDodgLevel(bool OnlyToClient=true);
public:
	//移动速度
	void SetMoveSpeed( const float& v );
	float GetMoveSpeed();
	void RefreshMoveSpeed();
	void SendMoveSpeed(bool OnlyToClient=true);
public:
	//眩晕状态
	void SetDizzyState( const bool& v );
	bool GetDizzyState();
	void RefreshDizzyState();
	void SendDizzyState(bool OnlyToClient=true);
public:
	//霸体状态
	void SetGodState( const bool& v );
	bool GetGodState();
	void RefreshGodState();
	void SendGodState(bool OnlyToClient=true);
public:
	//不能移动状态
	void SetCantMoveState( const bool& v );
	bool GetCantMoveState();
	void RefreshCantMoveState();
	void SendCantMoveState(bool OnlyToClient=true);
public:
	//物理加伤值
	void SetPhysicAddition( const float& v );
	float GetPhysicAddition();
	void RefreshPhysicAddition();
	void SendPhysicAddition(bool OnlyToClient=true);
public:
	//魔法加伤值
	void SetMagicAddition( const float& v );
	float GetMagicAddition();
	void RefreshMagicAddition();
	void SendMagicAddition(bool OnlyToClient=true);
public:
	//物理抗性
	void SetPhysicOppose( const float& v );
	float GetPhysicOppose();
	void RefreshPhysicOppose();
	void SendPhysicOppose(bool OnlyToClient=true);
public:
	//魔法抗性
	void SetMagicOppose( const float& v );
	float GetMagicOppose();
	void RefreshMagicOppose();
	void SendMagicOppose(bool OnlyToClient=true);


private:
	BaseAttrUserDataWraperV1 m_syncDataUserData;

	BaseAttrUserDataV1 m_ClientDataUserData;
	id_type m_vCalcPropertyIds;
	id_type m_vChangeIds;
	function_type m_oCaclPropertyCallbacks;
	send_callback_type m_oSendCallback;
	bool m_bChange;

};



#endif
