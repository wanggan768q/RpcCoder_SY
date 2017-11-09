/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     BaseAttrDBCache.cpp
* Author:       郭晓波
* Description:  基础数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "BaseAttrDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataBaseAttr);

//基础数据实现类构造函数
DataBaseAttr::DataBaseAttr()
{
	m_mapDataWraperVersionName[1] = "BaseAttrUserDataWraperV1";
	
}

//基础数据实现类析构函数
DataBaseAttr::~DataBaseAttr()
{

}


//获取模块ID
UINT8 DataBaseAttr::GetModuleId()
{
	return MODULE_ID_BASEATTR;
}

//获取模块名字
TStr DataBaseAttr::GetModuleName()
{
	return "BaseAttr";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataBaseAttr::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataBaseAttr::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataBaseAttr::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataBaseAttr::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataBaseAttr::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	BaseAttrUserDataWraperV1* pDataWraper = (BaseAttrUserDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_BASEATTR_EXP:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetExp(iValue);
		break;
	case SYNCID_BASEATTR_LEVEL:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLevel(iValue);
		break;
	case SYNCID_BASEATTR_SERVERTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetServerTime(iValue);
		break;
	case SYNCID_BASEATTR_ROLEID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetRoleId(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
