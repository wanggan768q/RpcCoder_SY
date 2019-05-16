/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     BagDBCache.cpp
* Author:       郭晓波
* Description:  Bag数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "BagDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataBag);

//Bag实现类构造函数
DataBag::DataBag()
{
	m_mapDataWraperVersionName[1] = "BagItemDataWraperV1";
	
}

//Bag实现类析构函数
DataBag::~DataBag()
{

}


//获取模块ID
UINT8 DataBag::GetModuleId()
{
	return MODULE_ID_BAG;
}

//获取模块名字
TStr DataBag::GetModuleName()
{
	return "Bag";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataBag::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataBag::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataBag::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataBag::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataBag::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	BagItemDataWraperV1* pDataWraper = (BagItemDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_BAG_GUID:
	case SYNCID_BAG_LOCK:
	case SYNCID_BAG_OVERLAYCOUNT:

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
