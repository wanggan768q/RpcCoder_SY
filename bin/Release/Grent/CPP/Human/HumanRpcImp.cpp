/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcHumanImp.cpp
* Author:       甘业清
* Description:  玩家模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "HumanModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcMove
* Description:    玩家模块-->human move同步调用操作函数
* Input:          HumanRpcMoveAskWraper& Ask human move请求
* Output:         HumanRpcMoveReplyWraper& Reply human move回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcMove( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStopMove
* Description:    玩家模块-->客户端停止移动同步调用操作函数
* Input:          HumanRpcStopMoveAskWraper& Ask 客户端停止移动请求
* Output:         HumanRpcStopMoveReplyWraper& Reply 客户端停止移动回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcStopMove( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMoveCheck
* Description:    玩家模块-->移动检测异步通知操作函数
* Input:          HumanRpcMoveCheckNotifyWraper& Notify 移动检测通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleHuman::RpcMoveCheck( INT64 UserId, HumanRpcMoveCheckNotifyWraper& Notify )
{

	//检测字段[角色ID]数据范围
	if( Notify.GetObjId()<-1 && Notify.GetObjId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetObjId()>10000000 && Notify.GetObjId()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[方向]数据范围
	if( Notify.GetDir()<-1 && Notify.GetDir()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetDir()>10000000 && Notify.GetDir()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[x位置]数据范围
	if( Notify.GetX()<-1 && Notify.GetX()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetX()>10000000 && Notify.GetX()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[y位置]数据范围
	if( Notify.GetY()<-1 && Notify.GetY()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetY()>10000000 && Notify.GetY()!=-1)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientMoveCheck
* Description:    玩家模块-->移动检测异步通知操作函数
* Input:          HumanRpcMoveCheckNotifyWraper& Notify 移动检测通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleHuman::SendToClientMoveCheck( INT64 UserId, HumanRpcMoveCheckNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcRespawn
* Description:    玩家模块-->复活同步调用操作函数
* Input:          HumanRpcRespawnAskWraper& Ask Respawn请求
* Output:         HumanRpcRespawnReplyWraper& Reply Respawn回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcRespawn( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRespawnOther
* Description:    玩家模块-->复活其他玩家通知异步通知操作函数
* Input:          HumanRpcRespawnOtherNotifyWraper& Notify 复活其他玩家通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleHuman::SendToClientRespawnOther( INT64 UserId, HumanRpcRespawnOtherNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcMovePos
* Description:    玩家模块-->MovePos同步调用操作函数
* Input:          HumanRpcMovePosAskWraper& Ask MovePos请求
* Output:         HumanRpcMovePosReplyWraper& Reply MovePos回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcMovePos( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRoleDie
* Description:    玩家模块-->死亡通知异步通知操作函数
* Input:          HumanRpcRoleDieNotifyWraper& Notify 死亡通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleHuman::SendToClientRoleDie( INT64 UserId, HumanRpcRoleDieNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcChangeAnimationState
* Description:    玩家模块-->改变动画状态 纯客户端异步通知操作函数
* Input:          HumanRpcChangeAnimationStateNotifyWraper& Notify 改变动画状态 纯客户端通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleHuman::RpcChangeAnimationState( INT64 UserId, HumanRpcChangeAnimationStateNotifyWraper& Notify )
{

	//检测字段[动画状态 具体值由客户端定]数据范围
	if( Notify.GetAnimationState()<-1 && Notify.GetAnimationState()!=false)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetAnimationState()>10000000 && Notify.GetAnimationState()!=false)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       RpcFuncNotice
* Description:    玩家模块-->玩家功能预告同步调用操作函数
* Input:          HumanRpcFuncNoticeAskWraper& Ask 玩家功能预告请求
* Output:         HumanRpcFuncNoticeReplyWraper& Reply 玩家功能预告回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcFuncNotice( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcFuncNoticeChange
* Description:    玩家模块-->玩家功能预告同步调用操作函数
* Input:          HumanRpcFuncNoticeChangeAskWraper& Ask 玩家功能预告请求
* Output:         HumanRpcFuncNoticeChangeReplyWraper& Reply 玩家功能预告回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcFuncNoticeChange( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcClientAttributes
* Description:    玩家模块-->客户端属性双向通知异步通知操作函数
* Input:          HumanRpcClientAttributesNotifyWraper& Notify 客户端属性双向通知通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleHuman::RpcClientAttributes( INT64 UserId, HumanRpcClientAttributesNotifyWraper& Notify )
{

	//检测字段[目标ID]数据范围
	if( Notify.GetObjId()<-1 && Notify.GetObjId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetObjId()>10000000 && Notify.GetObjId()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[摇杆]数据范围
	if( Notify.GetIsTouchJoyStick()<-1 && Notify.GetIsTouchJoyStick()!=false)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetIsTouchJoyStick()>10000000 && Notify.GetIsTouchJoyStick()!=false)
	{
		assert(false);
		return 0;
	}

	//检测字段[hold]数据范围
	if( Notify.GetIsHold()<-1 && Notify.GetIsHold()!=false)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetIsHold()>10000000 && Notify.GetIsHold()!=false)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientClientAttributes
* Description:    玩家模块-->客户端属性双向通知异步通知操作函数
* Input:          HumanRpcClientAttributesNotifyWraper& Notify 客户端属性双向通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleHuman::SendToClientClientAttributes( INT64 UserId, HumanRpcClientAttributesNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



