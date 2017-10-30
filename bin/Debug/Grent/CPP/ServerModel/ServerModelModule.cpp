/*gxb********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleServerModel.cpp
* Author:       郭晓波
* Description:  服务器内部模块类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ServerModelModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleServerModel);

//服务器内部模块实现类构造函数
ModuleServerModel::ModuleServerModel()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_SERVERMODEL_LOGIN_REQUEST, &ModuleServerModel::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SERVERMODEL_LOGIN_REQUEST, new Some_Factory<ServerModelRpcLoginAsk>(), new Some_Factory<ServerModelRpcLoginReply>());


}

//服务器内部模块实现类析构函数
ModuleServerModel::~ModuleServerModel()
{

}


//获取模块ID
UINT8 ModuleServerModel::GetModuleId()
{
	return MODULE_ID_SERVERMODEL;
}

//获取模块名字
TStr ModuleServerModel::GetModuleName()
{
	return "ServerModel";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleServerModel::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleServerModel::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleServerModel::GetInitializeOrder()
{
	return MODULE_ID_SERVERMODEL;
}

//获取结束退出顺序
int ModuleServerModel::GetFinalizeOrder()
{
	return MODULE_ID_SERVERMODEL;
}

//初始化
bool ModuleServerModel::Initialize()
{

	

	return true;
}

//结束退出
void ModuleServerModel::Finalize()
{

}


//毫秒级Tick回调
void ModuleServerModel::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleServerModel::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleServerModel::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleServerModel::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleServerModel::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleServerModel::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleServerModel::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleServerModel::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleServerModel::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleServerModel::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

