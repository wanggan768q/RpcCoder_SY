/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     aaaaDBCache.cpp
* Author:       甘业清
* Description:  aaa数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "aaaaDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(Dataaaaa);

//aaa实现类构造函数
Dataaaaa::Dataaaaa()
{
	m_mapDataWraperVersionName[1] = "aaaassssssWraperV1";
	
}

//aaa实现类析构函数
Dataaaaa::~Dataaaaa()
{

}


//获取模块ID
UINT8 Dataaaaa::GetModuleId()
{
	return MODULE_ID_AAAA;
}

//获取模块名字
TStr Dataaaaa::GetModuleName()
{
	return "aaaa";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> Dataaaaa::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool Dataaaaa::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	Dataaaaa::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool Dataaaaa::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool Dataaaaa::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	aaaassssssWraperV1* pDataWraper = (aaaassssssWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
