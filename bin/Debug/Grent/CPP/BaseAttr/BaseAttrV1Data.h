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
#include <vector>
#include "BaseDef.h"
#include "BaseAttrV1DataWraper.h"
#include "GameStruct/PropertiesModule.h"


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
 	SYNCID_BASEATTR_ACCUMULATESKIENERGY         = 750,  //技能积攒能量使用 目前只有应激技能用
 	SYNCID_BASEATTR_NICKNAME                    = 751,  //名字昵称
 	SYNCID_BASEATTR_CONFIGID                    = 752,  //config id
 	SYNCID_BASEATTR_OBJTYPE                     = 753,  //类型
 	SYNCID_BASEATTR_STATE                       = 754,  //EventObjStatu
 	SYNCID_BASEATTR_OWNEROBJID                  = 755,  //归属obj ID
 	SYNCID_BASEATTR_CAMP                        = 756,  //阵营
 	SYNCID_BASEATTR_SILVERMONEY                 = 757,  //银币
 	SYNCID_BASEATTR_GOLDMONEY                   = 758,  //金币
 	SYNCID_BASEATTR_DIAMONDMONEY                = 759,  //钻石
 	SYNCID_BASEATTR_BINDINGDIAMONDMONEY         = 760,  //绑定钻石
 	SYNCID_BASEATTR_BATTLESCORE                 = 761,  //战力
 	SYNCID_BASEATTR_ENERGY                      = 762,  //精力
 	SYNCID_BASEATTR_GUILDMONEY                  = 763,  //公会资金
 	SYNCID_BASEATTR_SKILLLIST                   = 764,  //技能列表
 	SYNCID_BASEATTR_HONORMONEY                  = 765,  //HonorMoney
 	SYNCID_BASEATTR_RESOURCEPOOLHP              = 766,  //资源池
 	SYNCID_BASEATTR_ATTACKADD                   = 767,  //伤害增加
 	SYNCID_BASEATTR_INJURYADD                   = 768,  //伤害减免
 	SYNCID_BASEATTR_FROZENSTATE                 = 769,  //冰冻状态
 	SYNCID_BASEATTR_SILENTSTATE                 = 770,  //沉默状态
 	SYNCID_BASEATTR_GUILDCONTRIBUTEHISTORYMAX   = 772,  //GuildContributeHistoryMax
 	SYNCID_BASEATTR_TEAMID                      = 774,  //队伍id
 	SYNCID_BASEATTR_TREASUREHAIR                = 775,  //头发时装ID
 	SYNCID_BASEATTR_TREASUREHEAD                = 776,  //头部时装ID
 	SYNCID_BASEATTR_TREASUREBODY                = 777,  //身体时装
 	SYNCID_BASEATTR_TREASUREWEAPON              = 778,  //武器时装
 	SYNCID_BASEATTR_TREASUREWING                = 779,  //翅膀时装
 	SYNCID_BASEATTR_GUILDGUID                   = 780,  //公会ID
 	SYNCID_BASEATTR_TREASURERIDING              = 781,  //坐骑
 	SYNCID_BASEATTR_VECHICLEID                  = 782,  //载具Id
 	SYNCID_BASEATTR_ANIMATIONSTATE              = 783,  //动画状态
 	SYNCID_BASEATTR_REFIXDMGRATE                = 784,  //修正攻击者最终伤害比率
 	SYNCID_BASEATTR_REFIXDMGVALUE               = 785,  //修正攻击者最终伤害值
 	SYNCID_BASEATTR_REFIXHURTRATE               = 786,  //修正被攻击者最终伤害比率
 	SYNCID_BASEATTR_REFIXHURTVALUE              = 787,  //修正被攻击者最终伤害值
 	SYNCID_BASEATTR_REFIXHEALRATE               = 788,  //修正治疗者最终比例
 	SYNCID_BASEATTR_REFIXHEALVALUE              = 789,  //修正治疗者最终值
 	SYNCID_BASEATTR_REFIXCUREDRATE              = 790,  //修正被治疗者最终比例
 	SYNCID_BASEATTR_REFIXCUREDVALUE             = 791,  //修正被治疗者最终值
 	SYNCID_BASEATTR_GUILDCONTRIBUTE             = 792,  //公会帮贡
 	SYNCID_BASEATTR_PVPMONEY                    = 793,  //竞技场点数
 	SYNCID_BASEATTR_GUILDRESOURCE               = 794,  //公会资源
 	SYNCID_BASEATTR_CREATEROLETIME              = 795,  //创建角色时间戳
 	SYNCID_BASEATTR_UPDATEROLETIME              = 796,  //更新角色等级时间戳
 	SYNCID_BASEATTR_FIGHTSTATE                  = 797,  //战斗状态
 	SYNCID_BASEATTR_ATTACKSKILLLIST             = 798,  //普攻技能列表
 	SYNCID_BASEATTR_GUILDNAME                   = 799,  //公会名称
 	SYNCID_BASEATTR_ISALLOWSELECT               = 800,  //是否可选中
 	SYNCID_BASEATTR_GOHOMESTATE                 = 801,  //怪物回归中
 	SYNCID_BASEATTR_CANFIGHT                    = 802,  //怪物是否可攻击
 	SYNCID_BASEATTR_DOUBLEEXP                   = 803,  //双倍经验
 	SYNCID_BASEATTR_FRIENDPOINT                 = 804,  //友情点
 	SYNCID_BASEATTR_HISMAXHONOR                 = 805,  //历史最大荣誉点
 	SYNCID_BASEATTR_HURTSTATE                   = 806,  //受击状态
 	SYNCID_BASEATTR_HURTFLYSTATE                = 807,  //击飞状态
 	SYNCID_BASEATTR_HURTDOWNSTATE               = 808,  //击倒状态
 	SYNCID_BASEATTR_HURTREPELSTATE              = 809,  //击退
 	SYNCID_BASEATTR_TODAYHORNOR                 = 811,  //今日获得的荣誉值
 	SYNCID_BASEATTR_CURPROFESSION               = 813,  //当前专精
 	SYNCID_BASEATTR_PETCREATEDELCOND            = 814,  //宠物创建删除条件枚举
 	SYNCID_BASEATTR_PETDISPLAY                  = 815,  //宠物是否需要隐藏1显示0隐藏
 	SYNCID_BASEATTR_PETMONEY                    = 816,  //宠物货币
 	SYNCID_BASEATTR_DUELSTATUS                  = 817,  //决斗状态
 	SYNCID_BASEATTR_EXPPOOL                     = 818,  //经验池
 	SYNCID_BASEATTR_RUSHSTATE                   = 819,  //疾跑状态
 	SYNCID_BASEATTR_STARESTATE                  = 820,  //盯防状态
 	SYNCID_BASEATTR_WORLDLEVEL                  = 821,  //世界等级
 	SYNCID_BASEATTR_DIZZYHITRATE                = 822,  //眩晕命中率
 	SYNCID_BASEATTR_DIZZYRESISTRATE             = 823,  //眩晕抵抗率
 	SYNCID_BASEATTR_IMMOVABLEHITRATE            = 824,  //定身命中率
 	SYNCID_BASEATTR_IMMOVABLERESISTRATE         = 825,  //定身抵抗率
 	SYNCID_BASEATTR_HURTFLYHITRATE              = 826,  //击飞命中率
 	SYNCID_BASEATTR_HURTFLYRESISTRATE           = 827,  //击飞抵抗率
 	SYNCID_BASEATTR_FROZENHITRATE               = 828,  //冰冻命中率
 	SYNCID_BASEATTR_FROZENRESISTRATE            = 829,  //冰冻抵抗率
 	SYNCID_BASEATTR_CLEANHITRATE                = 830,  //净化命中率
 	SYNCID_BASEATTR_CLEANRESISTRATE             = 831,  //净化抵抗率
 	SYNCID_BASEATTR_DISPELHITRATE               = 832,  //驱散命中率
 	SYNCID_BASEATTR_DISPELRESISTRATE            = 833,  //驱散抵抗率
 	SYNCID_BASEATTR_SILENCEHITRATE              = 834,  //沉默命中率
 	SYNCID_BASEATTR_SILENCERESISTRATE           = 835,  //沉默抵抗率
 	SYNCID_BASEATTR_INTERRUPTHITRATE            = 836,  //打断命中率
 	SYNCID_BASEATTR_INTERRUPTRESISTRATE         = 837,  //打断抵抗率
 	SYNCID_BASEATTR_UNCURABLEHITRATE            = 838,  //禁疗命中率
 	SYNCID_BASEATTR_UNCURABLERESISTRATE         = 839,  //禁疗抵抗率
 	SYNCID_BASEATTR_TRANSFORM                   = 840,  //变身
 	SYNCID_BASEATTR_HUMANHURTRATE               = 841,  //受到玩家目标伤害比
 	SYNCID_BASEATTR_HUMANSUFFERRATE             = 842,  //针对玩家目标伤害比
 	SYNCID_BASEATTR_MONSTERHURTRATE             = 843,  //受到怪物目标伤害比
 	SYNCID_BASEATTR_MONSTERSUFFERRATE           = 844,  //针对怪物目标伤害比
 	SYNCID_BASEATTR_BOSSHURTRATE                = 845,  //受到Boss目标伤害比
 	SYNCID_BASEATTR_BOSSSUFFERRATE              = 846,  //针对Boss目标伤害比
 	SYNCID_BASEATTR_DODGREDUCEVALUE             = 847,  //格挡减伤值
 	SYNCID_BASEATTR_DODGREDUCERATE              = 848,  //格挡减伤率
 	SYNCID_BASEATTR_DODGADDVALUE                = 849,  //格挡破伤值
 	SYNCID_BASEATTR_DODGADDRATE                 = 850,  //格挡破伤率
 	SYNCID_BASEATTR_TREASUREFOOTPRINT           = 851,  //步尘
 	SYNCID_BASEATTR_EQUIPTITLE                  = 852,  //装备称号
 	SYNCID_BASEATTR_OBJANIMEVENT                = 853,  //当前所在动画事件
 	SYNCID_BASEATTR_PINCHDATA                   = 854,  //捏脸数据
 	SYNCID_BASEATTR_SKILLCDRATE                 = 855,  //技能冷缩比例
 	SYNCID_BASEATTR_ASPDRATE                    = 856,  //攻速
 	SYNCID_BASEATTR_SHIELD                      = 857,  //护盾值
 	SYNCID_BASEATTR_EVENTLEFTCOUNT              = 858,  //obj剩余采集次数
 	SYNCID_BASEATTR_CANNOTRUSH                  = 859,  //不能疾跑状态
 	SYNCID_BASEATTR_HUNTPOINT                   = 860,  //猎魔点数
 	SYNCID_BASEATTR_HUNTHIGHTIMES               = 861,  //猎魔高倍
 	SYNCID_BASEATTR_HUNTFIREPOINT               = 862,  //猎魔引燃次数
 	SYNCID_BASEATTR_STARBATTLESTATE             = 863,  //星耀NPC状态(1可进入 2不可进入)
 	SYNCID_BASEATTR_IGNOREMOTIONBLOCK           = 864,  //是否忽略地图阻挡
 	SYNCID_BASEATTR_ENABLEINTERACT              = 865,  //EnableInteract
 	SYNCID_BASEATTR_WORLDMEDAL                  = 866,  //世界奖章
 	SYNCID_BASEATTR_CURECEILING                 = 868,  //治疗上限
 	SYNCID_BASEATTR_RELATIONUNIONCURRENCY       = 869,  //圣乐之力
 	SYNCID_BASEATTR_GUILDSHORTNAME              = 870,  //公会简称
 	SYNCID_BASEATTR_GUILDSHORTCOLORID           = 871,  //公会简称颜色ID

};

class Obj_Character;
//主同步数据操作类
class SyncDataBaseAttrV1
{
public:
	typedef std::unordered_set<int32_t> id_type;
	typedef std::function<Property()> calc_callback_type;
	typedef std::function<void()> after_callback_type;
	typedef std::vector<after_callback_type> after_callback_list_type;
	typedef std::unordered_map<int32_t, calc_callback_type> function_type;
	typedef std::unordered_map<int32_t, after_callback_list_type> after_calc_function_type;
	typedef std::function<void (BaseAttrUserDataV1*)> send_callback_type;

public:
			SyncDataBaseAttrV1(Obj_Character*);
	virtual	~SyncDataBaseAttrV1();

	void 	Init();
	//跨进程 切场景 用的
	void	InitEx();
	void	RefreshAll();
	void	SendAllMembers();
	void	SendToOthers();
	void 	SetSendCallBack(const send_callback_type & cb);
	void	SetSendOtherCallBack(const send_callback_type & cb);
	void 	CalcAllMembers();
	void 	GetCompletePlayerData(BaseAttrUserDataV1& base);
	void 	SendToClient()
	{
		if (m_oSendCallback)
		{
			m_oSendCallback(&m_ClientDataUserData);
			m_ClientDataUserData.Clear();
		}
		
	}
	void 	SendToOtherClient()
	{
		if (m_oSendOtherCallback)
		{
			m_oSendOtherCallback(&m_OtherDataUserData);
			m_OtherDataUserData.Clear();
		}
	}
	
	Property GetAttrByType(int attrType);

	//string  ToHtml(){ return m_syncDataUserData.ToHtml(); }
	//string  HtmlDescHeader() { return m_syncDataUserData.HtmlDescHeader(); }

	template <typename T>
	void CalcMethodCB(int32_t nType, T cb)
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
			
			AfterCallback(nType);
		}
	}
	
	void AfterCallback(int32_t nType);
	
	void CalcChangeMethodCB()
	{
		if (m_vCalcPropertyIds.empty())
 			return;
		m_vChangeIds = m_vCalcPropertyIds;
		for (auto it : m_vChangeIds)
		{
			GetAttrByType(it);
		}
        m_vChangeIds.clear();
	}
	

	string SerializeAsString()
	{
		CalcAllMembers();
		return m_syncDataUserData.SerializeAsString();
	}

	void SetChange(bool b)
	{
		m_bChange = b;
		if (!b)
		{
			m_ClientDataUserData.Clear();
		}
	}
	void SetOtherChange(bool b)
	{
		m_bOtherChange = b;
	}
	
	
	void RefreshByType(int attr_type)
	{
		m_vCalcPropertyIds.insert(attr_type);
	}
	
	void RegisterAfterCalcCallBack(int32_t attr_type, const after_callback_type& cb)
	{
		m_v_AfterCalcCallBackList[attr_type].push_back(cb);
	}
	
	void ClearAfterCalcCallBack()
	{
		m_v_AfterCalcCallBackList.clear();
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
	void SetServerTime( const INT32& v );
	INT32 GetServerTime();
	void RefreshServerTime();
	void SendServerTime(bool OnlyToClient=true);
public:
	//人物唯一ID
	void SetRoleId( const uint64_t& v );
	uint64_t GetRoleId();
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
	void SetDizzyState( const INT32& v );
	INT32 GetDizzyState();
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
	void SetCantMoveState( const INT32& v );
	INT32 GetCantMoveState();
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
public:
	//技能积攒能量使用 目前只有应激技能用
	void SetAccumulateSkiEnergy( const float& v );
	float GetAccumulateSkiEnergy();
	void RefreshAccumulateSkiEnergy();
	void SendAccumulateSkiEnergy(bool OnlyToClient=true);
public:
	//名字昵称
	void SetNickName( const string& v );
	string GetNickName();
	void RefreshNickName();
	void SendNickName(bool OnlyToClient=true);
public:
	//config id
	void SetConfigId( const INT32& v );
	INT32 GetConfigId();
	void RefreshConfigId();
	void SendConfigId(bool OnlyToClient=true);
public:
	//类型
	void SetObjType( const INT32& v );
	INT32 GetObjType();
	void RefreshObjType();
	void SendObjType(bool OnlyToClient=true);
public:
	//EventObjStatu
	void SetState( const INT32& v );
	INT32 GetState();
	void RefreshState();
	void SendState(bool OnlyToClient=true);
public:
	//归属obj ID
	void SetOwnerObjId( const uint64_t& v );
	uint64_t GetOwnerObjId();
	void RefreshOwnerObjId();
	void SendOwnerObjId(bool OnlyToClient=true);
public:
	//阵营
	void SetCamp( const INT32& v );
	INT32 GetCamp();
	void RefreshCamp();
	void SendCamp(bool OnlyToClient=true);
public:
	//银币
	void SetSilverMoney( const int64_t& v );
	int64_t GetSilverMoney();
	void RefreshSilverMoney();
	void SendSilverMoney(bool OnlyToClient=true);
public:
	//金币
	void SetGoldMoney( const int64_t& v );
	int64_t GetGoldMoney();
	void RefreshGoldMoney();
	void SendGoldMoney(bool OnlyToClient=true);
public:
	//钻石
	void SetDiamondMoney( const int64_t& v );
	int64_t GetDiamondMoney();
	void RefreshDiamondMoney();
	void SendDiamondMoney(bool OnlyToClient=true);
public:
	//绑定钻石
	void SetBindingDiamondMoney( const int64_t& v );
	int64_t GetBindingDiamondMoney();
	void RefreshBindingDiamondMoney();
	void SendBindingDiamondMoney(bool OnlyToClient=true);
public:
	//战力
	void SetBattleScore( const INT32& v );
	INT32 GetBattleScore();
	void RefreshBattleScore();
	void SendBattleScore(bool OnlyToClient=true);
public:
	//精力
	void SetEnergy( const int64_t& v );
	int64_t GetEnergy();
	void RefreshEnergy();
	void SendEnergy(bool OnlyToClient=true);
public:
	//公会资金
	void SetGuildMoney( const int64_t& v );
	int64_t GetGuildMoney();
	void RefreshGuildMoney();
	void SendGuildMoney(bool OnlyToClient=true);
public:
	//技能列表
	void SetSkillList( const vector<INT32>& v );
	vector<INT32> GetSkillList();
	void RefreshSkillList();
public:
	//HonorMoney
	void SetHonorMoney( const int64_t& v );
	int64_t GetHonorMoney();
	void RefreshHonorMoney();
	void SendHonorMoney(bool OnlyToClient=true);
public:
	//资源池
	void SetResourcePoolHp( const int64_t& v );
	int64_t GetResourcePoolHp();
	void RefreshResourcePoolHp();
	void SendResourcePoolHp(bool OnlyToClient=true);
public:
	//伤害增加
	void SetAttackAdd( const INT32& v );
	INT32 GetAttackAdd();
	void RefreshAttackAdd();
	void SendAttackAdd(bool OnlyToClient=true);
public:
	//伤害减免
	void SetInjuryAdd( const INT32& v );
	INT32 GetInjuryAdd();
	void RefreshInjuryAdd();
	void SendInjuryAdd(bool OnlyToClient=true);
public:
	//冰冻状态
	void SetFrozenState( const INT32& v );
	INT32 GetFrozenState();
	void RefreshFrozenState();
	void SendFrozenState(bool OnlyToClient=true);
public:
	//沉默状态
	void SetSilentState( const INT32& v );
	INT32 GetSilentState();
	void RefreshSilentState();
	void SendSilentState(bool OnlyToClient=true);
public:
	//GuildContributeHistoryMax
	void SetGuildContributeHistoryMax( const int64_t& v );
	int64_t GetGuildContributeHistoryMax();
	void RefreshGuildContributeHistoryMax();
	void SendGuildContributeHistoryMax(bool OnlyToClient=true);
public:
	//队伍id
	void SetTeamId( const uint64_t& v );
	uint64_t GetTeamId();
	void RefreshTeamId();
	void SendTeamId(bool OnlyToClient=true);
public:
	//头发时装ID
	void SetTreasureHair( const INT32& v );
	INT32 GetTreasureHair();
	void RefreshTreasureHair();
	void SendTreasureHair(bool OnlyToClient=true);
public:
	//头部时装ID
	void SetTreasureHead( const INT32& v );
	INT32 GetTreasureHead();
	void RefreshTreasureHead();
	void SendTreasureHead(bool OnlyToClient=true);
public:
	//身体时装
	void SetTreasureBody( const INT32& v );
	INT32 GetTreasureBody();
	void RefreshTreasureBody();
	void SendTreasureBody(bool OnlyToClient=true);
public:
	//武器时装
	void SetTreasureWeapon( const INT32& v );
	INT32 GetTreasureWeapon();
	void RefreshTreasureWeapon();
	void SendTreasureWeapon(bool OnlyToClient=true);
public:
	//翅膀时装
	void SetTreasureWing( const INT32& v );
	INT32 GetTreasureWing();
	void RefreshTreasureWing();
	void SendTreasureWing(bool OnlyToClient=true);
public:
	//公会ID
	void SetGuildGuid( const uint64_t& v );
	uint64_t GetGuildGuid();
	void RefreshGuildGuid();
	void SendGuildGuid(bool OnlyToClient=true);
public:
	//坐骑
	void SetTreasureRiding( const INT32& v );
	INT32 GetTreasureRiding();
	void RefreshTreasureRiding();
	void SendTreasureRiding(bool OnlyToClient=true);
public:
	//载具Id
	void SetVechicleId( const INT32& v );
	INT32 GetVechicleId();
	void RefreshVechicleId();
	void SendVechicleId(bool OnlyToClient=true);
public:
	//动画状态
	void SetAnimationState( const bool& v );
	bool GetAnimationState();
	void RefreshAnimationState();
	void SendAnimationState(bool OnlyToClient=true);
public:
	//修正攻击者最终伤害比率
	void SetRefixDmgRate( const float& v );
	float GetRefixDmgRate();
	void RefreshRefixDmgRate();
	void SendRefixDmgRate(bool OnlyToClient=true);
public:
	//修正攻击者最终伤害值
	void SetRefixDmgValue( const INT32& v );
	INT32 GetRefixDmgValue();
	void RefreshRefixDmgValue();
	void SendRefixDmgValue(bool OnlyToClient=true);
public:
	//修正被攻击者最终伤害比率
	void SetRefixHurtRate( const float& v );
	float GetRefixHurtRate();
	void RefreshRefixHurtRate();
	void SendRefixHurtRate(bool OnlyToClient=true);
public:
	//修正被攻击者最终伤害值
	void SetRefixHurtValue( const INT32& v );
	INT32 GetRefixHurtValue();
	void RefreshRefixHurtValue();
	void SendRefixHurtValue(bool OnlyToClient=true);
public:
	//修正治疗者最终比例
	void SetRefixHealRate( const float& v );
	float GetRefixHealRate();
	void RefreshRefixHealRate();
	void SendRefixHealRate(bool OnlyToClient=true);
public:
	//修正治疗者最终值
	void SetRefixHealValue( const INT32& v );
	INT32 GetRefixHealValue();
	void RefreshRefixHealValue();
	void SendRefixHealValue(bool OnlyToClient=true);
public:
	//修正被治疗者最终比例
	void SetRefixCuredRate( const float& v );
	float GetRefixCuredRate();
	void RefreshRefixCuredRate();
	void SendRefixCuredRate(bool OnlyToClient=true);
public:
	//修正被治疗者最终值
	void SetRefixCuredValue( const INT32& v );
	INT32 GetRefixCuredValue();
	void RefreshRefixCuredValue();
	void SendRefixCuredValue(bool OnlyToClient=true);
public:
	//公会帮贡
	void SetGuildContribute( const int64_t& v );
	int64_t GetGuildContribute();
	void RefreshGuildContribute();
	void SendGuildContribute(bool OnlyToClient=true);
public:
	//竞技场点数
	void SetPvpMoney( const int64_t& v );
	int64_t GetPvpMoney();
	void RefreshPvpMoney();
	void SendPvpMoney(bool OnlyToClient=true);
public:
	//公会资源
	void SetGuildResource( const int64_t& v );
	int64_t GetGuildResource();
	void RefreshGuildResource();
	void SendGuildResource(bool OnlyToClient=true);
public:
	//创建角色时间戳
	void SetCreateRoleTime( const INT32& v );
	INT32 GetCreateRoleTime();
	void RefreshCreateRoleTime();
	void SendCreateRoleTime(bool OnlyToClient=true);
public:
	//更新角色等级时间戳
	void SetUpdateRoleTime( const INT32& v );
	INT32 GetUpdateRoleTime();
	void RefreshUpdateRoleTime();
	void SendUpdateRoleTime(bool OnlyToClient=true);
public:
	//战斗状态
	void SetFightState( const bool& v );
	bool GetFightState();
	void RefreshFightState();
	void SendFightState(bool OnlyToClient=true);
public:
	//普攻技能列表
	void SetAttackSkillList( const vector<INT32>& v );
	vector<INT32> GetAttackSkillList();
	void RefreshAttackSkillList();
public:
	//公会名称
	void SetGuildName( const string& v );
	string GetGuildName();
	void RefreshGuildName();
	void SendGuildName(bool OnlyToClient=true);
public:
	//是否可选中
	void SetIsAllowSelect( const bool& v );
	bool GetIsAllowSelect();
	void RefreshIsAllowSelect();
	void SendIsAllowSelect(bool OnlyToClient=true);
public:
	//怪物回归中
	void SetGoHomeState( const bool& v );
	bool GetGoHomeState();
	void RefreshGoHomeState();
	void SendGoHomeState(bool OnlyToClient=true);
public:
	//怪物是否可攻击
	void SetCanFight( const bool& v );
	bool GetCanFight();
	void RefreshCanFight();
	void SendCanFight(bool OnlyToClient=true);
public:
	//双倍经验
	void SetDoubleExp( const int64_t& v );
	int64_t GetDoubleExp();
	void RefreshDoubleExp();
	void SendDoubleExp(bool OnlyToClient=true);
public:
	//友情点
	void SetFriendPoint( const int64_t& v );
	int64_t GetFriendPoint();
	void RefreshFriendPoint();
	void SendFriendPoint(bool OnlyToClient=true);
public:
	//历史最大荣誉点
	void SetHisMaxHonor( const int64_t& v );
	int64_t GetHisMaxHonor();
	void RefreshHisMaxHonor();
	void SendHisMaxHonor(bool OnlyToClient=true);
public:
	//受击状态
	void SetHurtState( const bool& v );
	bool GetHurtState();
	void RefreshHurtState();
	void SendHurtState(bool OnlyToClient=true);
public:
	//击飞状态
	void SetHurtFlyState( const bool& v );
	bool GetHurtFlyState();
	void RefreshHurtFlyState();
	void SendHurtFlyState(bool OnlyToClient=true);
public:
	//击倒状态
	void SetHurtDownState( const bool& v );
	bool GetHurtDownState();
	void RefreshHurtDownState();
	void SendHurtDownState(bool OnlyToClient=true);
public:
	//击退
	void SetHurtRepelState( const bool& v );
	bool GetHurtRepelState();
	void RefreshHurtRepelState();
	void SendHurtRepelState(bool OnlyToClient=true);
public:
	//今日获得的荣誉值
	void SetTodayHornor( const int64_t& v );
	int64_t GetTodayHornor();
	void RefreshTodayHornor();
	void SendTodayHornor(bool OnlyToClient=true);
public:
	//当前专精
	void SetCurProfession( const INT32& v );
	INT32 GetCurProfession();
	void RefreshCurProfession();
	void SendCurProfession(bool OnlyToClient=true);
public:
	//宠物创建删除条件枚举
	void SetPetCreateDelCond( const INT32& v );
	INT32 GetPetCreateDelCond();
	void RefreshPetCreateDelCond();
	void SendPetCreateDelCond(bool OnlyToClient=true);
public:
	//宠物是否需要隐藏1显示0隐藏
	void SetPetDisplay( const INT32& v );
	INT32 GetPetDisplay();
	void RefreshPetDisplay();
	void SendPetDisplay(bool OnlyToClient=true);
public:
	//宠物货币
	void SetPetMoney( const int64_t& v );
	int64_t GetPetMoney();
	void RefreshPetMoney();
	void SendPetMoney(bool OnlyToClient=true);
public:
	//决斗状态
	void SetDuelStatus( const INT32& v );
	INT32 GetDuelStatus();
	void RefreshDuelStatus();
	void SendDuelStatus(bool OnlyToClient=true);
public:
	//经验池
	void SetExpPool( const int64_t& v );
	int64_t GetExpPool();
	void RefreshExpPool();
	void SendExpPool(bool OnlyToClient=true);
public:
	//疾跑状态
	void SetRushState( const bool& v );
	bool GetRushState();
	void RefreshRushState();
	void SendRushState(bool OnlyToClient=true);
public:
	//盯防状态
	void SetStareState( const uint64_t& v );
	uint64_t GetStareState();
	void RefreshStareState();
	void SendStareState(bool OnlyToClient=true);
public:
	//世界等级
	void SetWorldLevel( const INT32& v );
	INT32 GetWorldLevel();
	void RefreshWorldLevel();
	void SendWorldLevel(bool OnlyToClient=true);
public:
	//眩晕命中率
	void SetDizzyHitRate( const float& v );
	float GetDizzyHitRate();
	void RefreshDizzyHitRate();
	void SendDizzyHitRate(bool OnlyToClient=true);
public:
	//眩晕抵抗率
	void SetDizzyResistRate( const float& v );
	float GetDizzyResistRate();
	void RefreshDizzyResistRate();
	void SendDizzyResistRate(bool OnlyToClient=true);
public:
	//定身命中率
	void SetImmovableHitRate( const float& v );
	float GetImmovableHitRate();
	void RefreshImmovableHitRate();
	void SendImmovableHitRate(bool OnlyToClient=true);
public:
	//定身抵抗率
	void SetImmovableResistRate( const float& v );
	float GetImmovableResistRate();
	void RefreshImmovableResistRate();
	void SendImmovableResistRate(bool OnlyToClient=true);
public:
	//击飞命中率
	void SetHurtFlyHitRate( const float& v );
	float GetHurtFlyHitRate();
	void RefreshHurtFlyHitRate();
	void SendHurtFlyHitRate(bool OnlyToClient=true);
public:
	//击飞抵抗率
	void SetHurtFlyResistRate( const float& v );
	float GetHurtFlyResistRate();
	void RefreshHurtFlyResistRate();
	void SendHurtFlyResistRate(bool OnlyToClient=true);
public:
	//冰冻命中率
	void SetFrozenHitRate( const float& v );
	float GetFrozenHitRate();
	void RefreshFrozenHitRate();
	void SendFrozenHitRate(bool OnlyToClient=true);
public:
	//冰冻抵抗率
	void SetFrozenResistRate( const float& v );
	float GetFrozenResistRate();
	void RefreshFrozenResistRate();
	void SendFrozenResistRate(bool OnlyToClient=true);
public:
	//净化命中率
	void SetCleanHitRate( const float& v );
	float GetCleanHitRate();
	void RefreshCleanHitRate();
	void SendCleanHitRate(bool OnlyToClient=true);
public:
	//净化抵抗率
	void SetCleanResistRate( const float& v );
	float GetCleanResistRate();
	void RefreshCleanResistRate();
	void SendCleanResistRate(bool OnlyToClient=true);
public:
	//驱散命中率
	void SetDispelHitRate( const float& v );
	float GetDispelHitRate();
	void RefreshDispelHitRate();
	void SendDispelHitRate(bool OnlyToClient=true);
public:
	//驱散抵抗率
	void SetDispelResistRate( const float& v );
	float GetDispelResistRate();
	void RefreshDispelResistRate();
	void SendDispelResistRate(bool OnlyToClient=true);
public:
	//沉默命中率
	void SetSilenceHitRate( const float& v );
	float GetSilenceHitRate();
	void RefreshSilenceHitRate();
	void SendSilenceHitRate(bool OnlyToClient=true);
public:
	//沉默抵抗率
	void SetSilenceResistRate( const float& v );
	float GetSilenceResistRate();
	void RefreshSilenceResistRate();
	void SendSilenceResistRate(bool OnlyToClient=true);
public:
	//打断命中率
	void SetInterruptHitRate( const float& v );
	float GetInterruptHitRate();
	void RefreshInterruptHitRate();
	void SendInterruptHitRate(bool OnlyToClient=true);
public:
	//打断抵抗率
	void SetInterruptResistRate( const float& v );
	float GetInterruptResistRate();
	void RefreshInterruptResistRate();
	void SendInterruptResistRate(bool OnlyToClient=true);
public:
	//禁疗命中率
	void SetUncurableHitRate( const float& v );
	float GetUncurableHitRate();
	void RefreshUncurableHitRate();
	void SendUncurableHitRate(bool OnlyToClient=true);
public:
	//禁疗抵抗率
	void SetUncurableResistRate( const float& v );
	float GetUncurableResistRate();
	void RefreshUncurableResistRate();
	void SendUncurableResistRate(bool OnlyToClient=true);
public:
	//变身
	void SetTransform( const INT32& v );
	INT32 GetTransform();
	void RefreshTransform();
	void SendTransform(bool OnlyToClient=true);
public:
	//受到玩家目标伤害比
	void SetHumanHurtRate( const float& v );
	float GetHumanHurtRate();
	void RefreshHumanHurtRate();
	void SendHumanHurtRate(bool OnlyToClient=true);
public:
	//针对玩家目标伤害比
	void SetHumanSufferRate( const float& v );
	float GetHumanSufferRate();
	void RefreshHumanSufferRate();
	void SendHumanSufferRate(bool OnlyToClient=true);
public:
	//受到怪物目标伤害比
	void SetMonsterHurtRate( const float& v );
	float GetMonsterHurtRate();
	void RefreshMonsterHurtRate();
	void SendMonsterHurtRate(bool OnlyToClient=true);
public:
	//针对怪物目标伤害比
	void SetMonsterSufferRate( const float& v );
	float GetMonsterSufferRate();
	void RefreshMonsterSufferRate();
	void SendMonsterSufferRate(bool OnlyToClient=true);
public:
	//受到Boss目标伤害比
	void SetBossHurtRate( const float& v );
	float GetBossHurtRate();
	void RefreshBossHurtRate();
	void SendBossHurtRate(bool OnlyToClient=true);
public:
	//针对Boss目标伤害比
	void SetBossSufferRate( const float& v );
	float GetBossSufferRate();
	void RefreshBossSufferRate();
	void SendBossSufferRate(bool OnlyToClient=true);
public:
	//格挡减伤值
	void SetDodgReduceValue( const INT32& v );
	INT32 GetDodgReduceValue();
	void RefreshDodgReduceValue();
	void SendDodgReduceValue(bool OnlyToClient=true);
public:
	//格挡减伤率
	void SetDodgReduceRate( const float& v );
	float GetDodgReduceRate();
	void RefreshDodgReduceRate();
	void SendDodgReduceRate(bool OnlyToClient=true);
public:
	//格挡破伤值
	void SetDodgAddValue( const INT32& v );
	INT32 GetDodgAddValue();
	void RefreshDodgAddValue();
	void SendDodgAddValue(bool OnlyToClient=true);
public:
	//格挡破伤率
	void SetDodgAddRate( const float& v );
	float GetDodgAddRate();
	void RefreshDodgAddRate();
	void SendDodgAddRate(bool OnlyToClient=true);
public:
	//步尘
	void SetTreasureFootPrint( const INT32& v );
	INT32 GetTreasureFootPrint();
	void RefreshTreasureFootPrint();
	void SendTreasureFootPrint(bool OnlyToClient=true);
public:
	//装备称号
	void SetEquipTitle( const INT32& v );
	INT32 GetEquipTitle();
	void RefreshEquipTitle();
	void SendEquipTitle(bool OnlyToClient=true);
public:
	//当前所在动画事件
	void SetObjAnimEvent( const vector<INT32>& v );
	vector<INT32> GetObjAnimEvent();
	void RefreshObjAnimEvent();
public:
	//捏脸数据
	void SetPinchData( const string& v );
	string GetPinchData();
	void RefreshPinchData();
	void SendPinchData(bool OnlyToClient=true);
public:
	//技能冷缩比例
	void SetSkillCDRate( const float& v );
	float GetSkillCDRate();
	void RefreshSkillCDRate();
	void SendSkillCDRate(bool OnlyToClient=true);
public:
	//攻速
	void SetAspdRate( const float& v );
	float GetAspdRate();
	void RefreshAspdRate();
	void SendAspdRate(bool OnlyToClient=true);
public:
	//护盾值
	void SetShield( const INT32& v );
	INT32 GetShield();
	void RefreshShield();
	void SendShield(bool OnlyToClient=true);
public:
	//obj剩余采集次数
	void SetEventLeftCount( const INT32& v );
	INT32 GetEventLeftCount();
	void RefreshEventLeftCount();
	void SendEventLeftCount(bool OnlyToClient=true);
public:
	//不能疾跑状态
	void SetCanNotRush( const INT32& v );
	INT32 GetCanNotRush();
	void RefreshCanNotRush();
	void SendCanNotRush(bool OnlyToClient=true);
public:
	//猎魔点数
	void SetHuntPoint( const INT32& v );
	INT32 GetHuntPoint();
	void RefreshHuntPoint();
	void SendHuntPoint(bool OnlyToClient=true);
public:
	//猎魔高倍
	void SetHuntHighTimes( const INT32& v );
	INT32 GetHuntHighTimes();
	void RefreshHuntHighTimes();
	void SendHuntHighTimes(bool OnlyToClient=true);
public:
	//猎魔引燃次数
	void SetHuntFirePoint( const INT32& v );
	INT32 GetHuntFirePoint();
	void RefreshHuntFirePoint();
	void SendHuntFirePoint(bool OnlyToClient=true);
public:
	//星耀NPC状态(1可进入 2不可进入)
	void SetStarbattlestate( const INT32& v );
	INT32 GetStarbattlestate();
	void RefreshStarbattlestate();
	void SendStarbattlestate(bool OnlyToClient=true);
public:
	//是否忽略地图阻挡
	void SetIgnoreMotionBlock( const bool& v );
	bool GetIgnoreMotionBlock();
	void RefreshIgnoreMotionBlock();
	void SendIgnoreMotionBlock(bool OnlyToClient=true);
public:
	//EnableInteract
	void SetEnableInteract( const bool& v );
	bool GetEnableInteract();
	void RefreshEnableInteract();
	void SendEnableInteract(bool OnlyToClient=true);
public:
	//世界奖章
	void SetWorldMedal( const INT32& v );
	INT32 GetWorldMedal();
	void RefreshWorldMedal();
	void SendWorldMedal(bool OnlyToClient=true);
public:
	//治疗上限
	void SetCureCeiling( const INT32& v );
	INT32 GetCureCeiling();
	void RefreshCureCeiling();
	void SendCureCeiling(bool OnlyToClient=true);
public:
	//圣乐之力
	void SetRelationUnionCurrency( const INT32& v );
	INT32 GetRelationUnionCurrency();
	void RefreshRelationUnionCurrency();
	void SendRelationUnionCurrency(bool OnlyToClient=true);
public:
	//公会简称
	void SetGuildShortName( const string& v );
	string GetGuildShortName();
	void RefreshGuildShortName();
	void SendGuildShortName(bool OnlyToClient=true);
public:
	//公会简称颜色ID
	void SetGuildShortColorID( const INT32& v );
	INT32 GetGuildShortColorID();
	void RefreshGuildShortColorID();
	void SendGuildShortColorID(bool OnlyToClient=true);


private:
	BaseAttrUserDataWraperV1 m_syncDataUserData;

	BaseAttrUserDataV1 m_ClientDataUserData;
	BaseAttrUserDataV1 m_OtherDataUserData;
	id_type m_vCalcPropertyIds;
	id_type m_vChangeIds;
	function_type m_oCaclPropertyCallbacks;
	after_calc_function_type m_v_AfterCalcCallBackList;
	send_callback_type m_oSendCallback;
	send_callback_type m_oSendOtherCallback;
	bool m_bChange;
	bool m_bOtherChange;
	Obj_Character * m_pObj;
};



#endif
