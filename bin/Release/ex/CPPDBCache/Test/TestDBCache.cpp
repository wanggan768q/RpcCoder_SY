/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TestDBCache.cpp
* Author:       甘业清
* Description:  test数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TestDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTest);

//test实现类构造函数
DataTest::DataTest()
{
	m_mapDataWraperVersionName[1] = "TestUserWraperV1";
	
}

//test实现类析构函数
DataTest::~DataTest()
{

}


//获取模块ID
UINT8 DataTest::GetModuleId()
{
	return MODULE_ID_TEST;
}

//获取模块名字
TStr DataTest::GetModuleName()
{
	return "Test";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTest::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTest::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTest::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataTest::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataTest::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TestUserWraperV1* pDataWraper = (TestUserWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_TEST_HP:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetHp(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
