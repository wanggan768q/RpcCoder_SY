/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     BagDBCache.h
* Author:       郭晓波
* Description:  Bag数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __DATA_BAG_H
#define __DATA_BAG_H


#include "ModuleData.h"
#include "BagV1DataWraper.h"


//同步数据相关枚举量定义
enum DataWraperItemIdE
{
	MODULE_ID_BAG = 12,
 	SYNCID_BAG_GUID                             = 1201,  //Guid
 	SYNCID_BAG_LOCK                             = 1202,  //Lock
 	SYNCID_BAG_OVERLAYCOUNT                     = 1203,  //OverlayCount

};


//Bag数据类
class DataBag : public ModuleData
{
	DECLARE_INSTANCE(DataBag);
public:
	friend class			ModuleDataMgr;

public:
	//Bag实现类构造函数
	DataBag();
	
	//Bag实现类析构函数
	virtual					~DataBag();

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