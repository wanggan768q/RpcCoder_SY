/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleHuman.h
* Author:       郭晓波
* Description:  玩家模块类，包含以下内容
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

#ifndef __MODULE_HUMAN_H
#define __MODULE_HUMAN_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "HumanRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//玩家模块实现类
class ModuleHuman
{
	
public:
	//玩家模块类的枚举定义
	enum ConstHumanE
	{
	MODULE_ID_HUMAN                              = 4,	//玩家模块模块ID
	RPC_CODE_HUMAN_MOVE_REQUEST                  = 451,	//玩家模块-->human move-->请求
	RPC_CODE_HUMAN_STOPMOVE_REQUEST              = 452,	//玩家模块-->客户端停止移动-->请求
	RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST  = 453,	//玩家模块-->移动验证-->请求
	RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY            = 454,	//玩家模块-->客户端位置校验-->通知
	RPC_CODE_HUMAN_GCMOVECHECK_NOTIFY            = 455,	//玩家模块-->服务器位置校验通知-->通知

	};

public:
	//玩家模块实现类构造函数
	ModuleHuman()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVE_REQUEST, &ModuleHuman::RpcMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVE_REQUEST, new Some_Factory<HumanRpcMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, &ModuleHuman::RpcStopMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, new Some_Factory<HumanRpcStopMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST, &ModuleHuman::RpcMovementVerification);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST, new Some_Factory<HumanRpcMovementVerificationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY, &ModuleHuman::RpcCGMoveCheck);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY, new Some_Factory<HumanRpcCGMoveCheckNotify>());

	}
	
	//玩家模块实现类析构函数
	~ModuleHuman(){}


	

public:
	/********************************************************************************************
	* Function:       RpcMove
	* Description:    玩家模块-->human move同步调用操作函数
	* Input:          HumanRpcMoveAskWraper& Ask human move请求
	* Output:         HumanRpcMoveReplyWraper& Reply human move回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMove( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcStopMove
	* Description:    玩家模块-->客户端停止移动同步调用操作函数
	* Input:          HumanRpcStopMoveAskWraper& Ask 客户端停止移动请求
	* Output:         HumanRpcStopMoveReplyWraper& Reply 客户端停止移动回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcStopMove( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMovementVerification
	* Description:    玩家模块-->移动验证同步调用操作函数
	* Input:          HumanRpcMovementVerificationAskWraper& Ask 移动验证请求
	* Output:         HumanRpcMovementVerificationReplyWraper& Reply 移动验证回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMovementVerification( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCGMoveCheck
	* Description:    玩家模块-->客户端位置校验异步通知操作函数
	* Input:          HumanRpcCGMoveCheckNotifyWraper& Notify 客户端位置校验通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcCGMoveCheck(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientGCMoveCheck
	* Description:    玩家模块-->服务器位置校验通知异步通知操作函数
	* Input:          HumanRpcGCMoveCheckNotifyWraper& Notify 服务器位置校验通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientGCMoveCheck( INT64 UserId, HumanRpcGCMoveCheckNotifyWraper& Notify );



};

#endif