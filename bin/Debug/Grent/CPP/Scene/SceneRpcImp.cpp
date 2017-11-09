/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcSceneImp.cpp
* Author:       郭晓波
* Description:  场景模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "SceneModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcEnterScene
* Description:    场景模块-->进入场景同步调用操作函数
* Input:          SceneRpcEnterSceneAskWraper& Ask 进入场景请求
* Output:         SceneRpcEnterSceneReplyWraper& Reply 进入场景回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcEnterScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLoadSceneComplete
* Description:    场景模块-->进入场景完成同步调用操作函数
* Input:          SceneRpcLoadSceneCompleteAskWraper& Ask 进入场景完成请求
* Output:         SceneRpcLoadSceneCompleteReplyWraper& Reply 进入场景完成回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcLoadSceneComplete( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDeletePlayer
* Description:    场景模块-->玩家离开视野异步通知操作函数
* Input:          SceneRpcDeletePlayerNotifyWraper& Notify 删除玩家通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientDeletePlayer( INT64 UserId, SceneRpcDeletePlayerNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcConnectGameServer
* Description:    场景模块-->连接场景服务器同步调用操作函数
* Input:          SceneRpcConnectGameServerAskWraper& Ask 连接场景服务器请求
* Output:         SceneRpcConnectGameServerReplyWraper& Reply 连接场景服务器回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcConnectGameServer( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeScene
* Description:    场景模块-->多线程移除场景上的玩家同步调用操作函数
* Input:          SceneRpcChangeSceneAskWraper& Ask 多线程移除场景上的玩家请求
* Output:         SceneRpcChangeSceneReplyWraper& Reply 多线程移除场景上的玩家回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcChangeScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewObj
* Description:    场景模块-->新物体异步通知操作函数
* Input:          SceneRpcNewObjNotifyWraper& Notify 新物体通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientNewObj( INT64 UserId, SceneRpcNewObjNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



