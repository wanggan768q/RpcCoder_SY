/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleEvent.h
* Author:       郭晓波
* Description:  事件模块类，包含以下内容
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

#ifndef __MODULE_EVENT_H
#define __MODULE_EVENT_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "EventRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//事件模块实现类
class ModuleEvent
{
	
public:
	//事件模块类的枚举定义
	enum ConstEventE
	{
	MODULE_ID_EVENT                              = 5,	//事件模块模块ID
	RPC_CODE_EVENT_MOVE_NOTIFY                   = 551,	//事件模块-->ObjMove-->通知
	RPC_CODE_EVENT_STOPMOVE_NOTIFY               = 552,	//事件模块-->ObjStopMove-->通知
	RPC_CODE_EVENT_BOSSDIED_NOTIFY               = 553,	//事件模块-->Boss死亡-->通知

	};

public:
	//事件模块实现类构造函数
	ModuleEvent()
	{

	}
	
	//事件模块实现类析构函数
	~ModuleEvent(){}


	static ModuleEvent Instance()
	{
		static ModuleEvent sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       SendToClientMove
	* Description:    事件模块-->ObjMove异步通知操作函数
	* Input:          EventRpcMoveNotifyWraper& Notify ObjMove通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMove( INT64 UserId, EventRpcMoveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientStopMove
	* Description:    事件模块-->ObjStopMove异步通知操作函数
	* Input:          EventRpcStopMoveNotifyWraper& Notify ObjStopMove通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientStopMove( INT64 UserId, EventRpcStopMoveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBossDied
	* Description:    事件模块-->Boss死亡异步通知操作函数
	* Input:          EventRpcBossDiedNotifyWraper& Notify Boss死亡通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBossDied( INT64 UserId, EventRpcBossDiedNotifyWraper& Notify );



};

#endif