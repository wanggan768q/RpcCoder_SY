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
* Function:       SendToClientCreateObj
* Description:    场景模块-->创建物体异步通知操作函数
* Input:          SceneRpcCreateObjNotifyWraper& Notify 创建物体通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientCreateObj( INT64 UserId, SceneRpcCreateObjNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSurroundingHuman
* Description:    场景模块-->SurroundingHuman同步调用操作函数
* Input:          SceneRpcSurroundingHumanAskWraper& Ask SurroundingHuman请求
* Output:         SceneRpcSurroundingHumanReplyWraper& Reply SurroundingHuman回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcSurroundingHuman( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCEnterScene
* Description:    场景模块-->进入场景异步通知操作函数
* Input:          SceneRpcCEnterSceneNotifyWraper& Notify 进入场景通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleScene::RpcCEnterScene( INT64 UserId, SceneRpcCEnterSceneNotifyWraper& Notify )
{

	//检测字段[场景id]数据范围
	if( Notify.GetSceneId()<-1 && Notify.GetSceneId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetSceneId()>10000000 && Notify.GetSceneId()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[表当中的mapid]数据范围
	if( Notify.GetMapId()<-1 && Notify.GetMapId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetMapId()>10000000 && Notify.GetMapId()!=-1)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientSEnterScene
* Description:    场景模块-->进入场景返回异步通知操作函数
* Input:          SceneRpcSEnterSceneNotifyWraper& Notify 进入场景返回通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientSEnterScene( INT64 UserId, SceneRpcSEnterSceneNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientObjDie
* Description:    场景模块-->ObjDie异步通知操作函数
* Input:          SceneRpcObjDieNotifyWraper& Notify ObjDie通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientObjDie( INT64 UserId, SceneRpcObjDieNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCollide_ChangeScene
* Description:    场景模块-->collide 场景切换同步调用操作函数
* Input:          SceneRpcCollide_ChangeSceneAskWraper& Ask collide请求
* Output:         SceneRpcCollide_ChangeSceneReplyWraper& Reply collide回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcCollide_ChangeScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



