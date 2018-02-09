/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleBaseAttr.h
* Author:       郭晓波
* Description:  基础数据类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_BASEATTR_H
#define __MODULE_BASEATTR_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "BaseAttrRpc.pb.h"
#include <memory>


#include "BaseAttrV1Data.h"
#include "BaseAttrV1DataWraper.h"



class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//基础数据实现类
class ModuleBaseAttr
{
	
public:
	//基础数据类的枚举定义
	enum ConstBaseAttrE
	{
	MODULE_ID_BASEATTR                           = 7,	//基础数据模块ID
	RPC_CODE_BASEATTR_SYNCDATA_REQUEST           = 751,	//基础数据-->同步玩家数据-->请求
	RPC_CODE_BASEATTR_SYNC_NOTIFY                = 752,	//基础数据-->数据推送-->通知

	};

public:
	//基础数据实现类构造函数
	ModuleBaseAttr()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_BASEATTR_SYNCDATA_REQUEST, &ModuleBaseAttr::RpcSyncData);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BASEATTR_SYNCDATA_REQUEST, new Some_Factory<BaseAttrRpcSyncDataAsk>());

	}
	
	//基础数据实现类析构函数
	~ModuleBaseAttr(){}


	static ModuleBaseAttr Instance()
	{
		static ModuleBaseAttr sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcSyncData
	* Description:    基础数据-->同步玩家数据同步调用操作函数
	* Input:          BaseAttrRpcSyncDataAskWraper& Ask 同步玩家数据请求
	* Output:         BaseAttrRpcSyncDataReplyWraper& Reply 同步玩家数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncData( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSync
	* Description:    基础数据-->数据推送异步通知操作函数
	* Input:          BaseAttrRpcSyncNotifyWraper& Notify 数据推送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSync( INT64 UserId, BaseAttrRpcSyncNotifyWraper& Notify );



};

#endif