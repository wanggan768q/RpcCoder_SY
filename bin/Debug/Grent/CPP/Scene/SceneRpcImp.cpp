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

	//检测字段[LineId]数据范围
	if( Notify.GetLineId()<-1 && Notify.GetLineId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetLineId()>10000000 && Notify.GetLineId()!=-1)
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

/********************************************************************************************
* Function:       RpcEnterMirror
* Description:    场景模块-->进入镜像同步调用操作函数
* Input:          SceneRpcEnterMirrorAskWraper& Ask 进入镜像请求
* Output:         SceneRpcEnterMirrorReplyWraper& Reply 进入镜像回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcEnterMirror( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSEnterMirrorScene
* Description:    场景模块-->进入镜像场景异步通知操作函数
* Input:          SceneRpcSEnterMirrorSceneNotifyWraper& Notify 进入镜像场景通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientSEnterMirrorScene( INT64 UserId, SceneRpcSEnterMirrorSceneNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcExitMirrorScene
* Description:    场景模块-->退出镜像同步调用操作函数
* Input:          SceneRpcExitMirrorSceneAskWraper& Ask 退出镜像请求
* Output:         SceneRpcExitMirrorSceneReplyWraper& Reply 退出镜像回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcExitMirrorScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientChangeSceneLeave
* Description:    场景模块-->ChangeSceneLeave异步通知操作函数
* Input:          SceneRpcChangeSceneLeaveNotifyWraper& Notify ChangeSceneLeave通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientChangeSceneLeave( INT64 UserId, SceneRpcChangeSceneLeaveNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcChangeLine
* Description:    场景模块-->ChangeLine同步调用操作函数
* Input:          SceneRpcChangeLineAskWraper& Ask ChangeLine请求
* Output:         SceneRpcChangeLineReplyWraper& Reply ChangeLine回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcChangeLine( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcPing
* Description:    场景模块-->ping同步调用操作函数
* Input:          SceneRpcPingAskWraper& Ask ping请求
* Output:         SceneRpcPingReplyWraper& Reply ping回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcPing( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncSceneLineStats
* Description:    场景模块-->同步场景分线繁忙状态异步通知操作函数
* Input:          SceneRpcSyncSceneLineStatsNotifyWraper& Notify 同步场景分线繁忙状态通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientSyncSceneLineStats( INT64 UserId, SceneRpcSyncSceneLineStatsNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcLogOutGame
* Description:    场景模块-->离开GameServer同步调用操作函数
* Input:          SceneRpcLogOutGameAskWraper& Ask 离开GameServer请求
* Output:         SceneRpcLogOutGameReplyWraper& Reply 离开GameServer回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcLogOutGame( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientKickOutGame
* Description:    场景模块-->被提出场景异步通知操作函数
* Input:          SceneRpcKickOutGameNotifyWraper& Notify 被提出场景通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientKickOutGame( INT64 UserId, SceneRpcKickOutGameNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcShowFilmFinish
* Description:    场景模块-->前端通知后端剧情动画播放完毕同步调用操作函数
* Input:          SceneRpcShowFilmFinishAskWraper& Ask 前端通知后端剧情动画播放完毕请求
* Output:         SceneRpcShowFilmFinishReplyWraper& Reply 前端通知后端剧情动画播放完毕回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcShowFilmFinish( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSpecObjPos
* Description:    场景模块-->SpecObjPos同步调用操作函数
* Input:          SceneRpcSpecObjPosAskWraper& Ask SpecObjPos请求
* Output:         SceneRpcSpecObjPosReplyWraper& Reply SpecObjPos回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcSpecObjPos( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDayNightChange
* Description:    场景模块-->昼夜变化异步通知操作函数
* Input:          SceneRpcDayNightChangeNotifyWraper& Notify 昼夜变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientDayNightChange( INT64 UserId, SceneRpcDayNightChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientWeatherChange
* Description:    场景模块-->天气变化异步通知操作函数
* Input:          SceneRpcWeatherChangeNotifyWraper& Notify 天气变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleScene::SendToClientWeatherChange( INT64 UserId, SceneRpcWeatherChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcWantChangeZone
* Description:    场景模块-->ChangeZone同步调用操作函数
* Input:          SceneRpcWantChangeZoneAskWraper& Ask ChangeZone请求
* Output:         SceneRpcWantChangeZoneReplyWraper& Reply ChangeZone回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcWantChangeZone( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcReturnSrcServer
* Description:    场景模块-->返回源服同步调用操作函数
* Input:          SceneRpcReturnSrcServerAskWraper& Ask 返回源服请求
* Output:         SceneRpcReturnSrcServerReplyWraper& Reply 返回源服回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleScene::RpcReturnSrcServer( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



