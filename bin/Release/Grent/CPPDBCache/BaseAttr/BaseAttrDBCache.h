/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     BaseAttrDBCache.h
* Author:       甘业清
* Description:  基础数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_BASEATTR_H
#define __DATA_BASEATTR_H


#include "ModuleData.h"
#include "BaseAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_BASEATTR = 7,
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

};


//基础数据数据类
class DataBaseAttr : public ModuleData
{
	DECLARE_INSTANCE(DataBaseAttr);
public:
	friend class			ModuleDataMgr;

public:
	//基础数据实现类构造函数
	DataBaseAttr();
	
	//基础数据实现类析构函数
	virtual					~DataBaseAttr();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetDataWraperVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//是否保存数据到数据库中
	virtual bool			IsSaveModuleDataToDB();

	//模块同步(保存)数据升级函数
	virtual bool			UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur );
	
	//增量更新通知
	virtual bool			OnIncrementUpdate( INT64 key, int syncId, int IndexPos, const char* pBuffer, int dataLen );


private:
	 map<INT32,TStr>		m_mapDataWraperVersionName;
};

#endif