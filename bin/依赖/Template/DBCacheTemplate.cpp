/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     $Template$DBCache.cpp
* Author:       甘业清
* Description:  $ModCName$数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "$Template$DBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(Data$Template$);

//$ModCName$实现类构造函数
Data$Template$::Data$Template$()
{
	m_mapDataWraperVersionName[$SyncDataVersion$] = "$Template$$DSName$WraperV$SyncDataVersion$";
	
}

//$ModCName$实现类析构函数
Data$Template$::~Data$Template$()
{

}


//获取模块ID
UINT8 Data$Template$::GetModuleId()
{
	return MODULE_ID_$TEMPLATE$;
}

//获取模块名字
TStr Data$Template$::GetModuleName()
{
	return "$Template$";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> Data$Template$::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool Data$Template$::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	Data$Template$::GetSavedDataType()
{
	return $DataSaveType$;
}

//是否保存数据到数据库中
bool Data$Template$::IsSaveModuleDataToDB()
{

	return $SaveToDB$;
}

//增量更新通知
bool Data$Template$::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	$Template$$DSName$WraperV$SyncDataVersion$* pDataWraper = ($Template$$DSName$WraperV$SyncDataVersion$*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
$DBCacheField$
	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
