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