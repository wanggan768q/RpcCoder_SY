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
#include "Game/PacketMgr.h"
#include "EventRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




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
	RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY          = 553,	//事件模块-->属性改变-->通知
	RPC_CODE_EVENT_COINCHANGE_NOTIFY             = 554,	//事件模块-->货币的变化通知-->通知
	RPC_CODE_EVENT_MOVEPOS_NOTIFY                = 555,	//事件模块-->按点移动-->通知
	RPC_CODE_EVENT_DIR_NOTIFY                    = 556,	//事件模块-->朝向-->通知
	RPC_CODE_EVENT_STARTFADEOUT_NOTIFY           = 557,	//事件模块-->开始淡出效果-->通知
	RPC_CODE_EVENT_CINEMATICSTART_NOTIFY         = 558,	//事件模块-->通知表演开始-->通知
	RPC_CODE_EVENT_CINEMATICEND_NOTIFY           = 559,	//事件模块-->通知表演结束-->通知

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//事件模块实现类构造函数
	ModuleEvent()
	{

	}
	
	//事件模块实现类析构函数
	~ModuleEvent(){}


	static ModuleEvent & Instance()
	{
		static ModuleEvent sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
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
	* Function:       SendToClientObjAttrChange
	* Description:    事件模块-->属性改变异步通知操作函数
	* Input:          EventRpcObjAttrChangeNotifyWraper& Notify 属性改变通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjAttrChange( INT64 UserId, EventRpcObjAttrChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCoinChange
	* Description:    事件模块-->货币的变化通知异步通知操作函数
	* Input:          EventRpcCoinChangeNotifyWraper& Notify 货币的变化通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCoinChange( INT64 UserId, EventRpcCoinChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientMovePos
	* Description:    事件模块-->按点移动异步通知操作函数
	* Input:          EventRpcMovePosNotifyWraper& Notify 按点移动通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMovePos( INT64 UserId, EventRpcMovePosNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDir
	* Description:    事件模块-->朝向异步通知操作函数
	* Input:          EventRpcDirNotifyWraper& Notify 朝向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDir( INT64 UserId, EventRpcDirNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientStartFadeout
	* Description:    事件模块-->开始淡出效果异步通知操作函数
	* Input:          EventRpcStartFadeoutNotifyWraper& Notify 开始淡出效果通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientStartFadeout( INT64 UserId, EventRpcStartFadeoutNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCinematicStart
	* Description:    事件模块-->通知表演开始异步通知操作函数
	* Input:          EventRpcCinematicStartNotifyWraper& Notify 通知表演开始通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCinematicStart( INT64 UserId, EventRpcCinematicStartNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCinematicEnd
	* Description:    事件模块-->通知表演结束异步通知操作函数
	* Input:          EventRpcCinematicEndNotifyWraper& Notify 通知表演结束通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCinematicEnd( INT64 UserId, EventRpcCinematicEndNotifyWraper& Notify );


	reload_vec_type m_vReLoadCb;

};

#endif