/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     BaseAttrDBCache.h
* Author:       郭晓波
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