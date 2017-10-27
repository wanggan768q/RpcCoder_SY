/*gxb********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleLogin.cpp
* Author:       郭晓波
* Description:  登录模块类，包含以下内容
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

#include "LoginModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleLogin);

//登录模块实现类构造函数
ModuleLogin::ModuleLogin()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CONNECT_REQUEST, &ModuleLogin::RpcConnect);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CONNECT_REQUEST, new Some_Factory<LoginRpcConnectAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_LOGIN_REQUEST, &ModuleLogin::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_LOGIN_REQUEST, new Some_Factory<LoginRpcLoginAsk>());


}

//登录模块实现类析构函数
ModuleLogin::~ModuleLogin()
{

}


//获取模块ID
UINT8 ModuleLogin::GetModuleId()
{
	return MODULE_ID_LOGIN;
}

//获取模块名字
TStr ModuleLogin::GetModuleName()
{
	return "Login";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleLogin::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleLogin::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleLogin::GetInitializeOrder()
{
	return MODULE_ID_LOGIN;
}

//获取结束退出顺序
int ModuleLogin::GetFinalizeOrder()
{
	return MODULE_ID_LOGIN;
}

//初始化
bool ModuleLogin::Initialize()
{

	

	return true;
}

//结束退出
void ModuleLogin::Finalize()
{

}


//毫秒级Tick回调
void ModuleLogin::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleLogin::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleLogin::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleLogin::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleLogin::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleLogin::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleLogin::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleLogin::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleLogin::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleLogin::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

