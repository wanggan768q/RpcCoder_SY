/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTreasureImp.cpp
* Author:       甘业清
* Description:  珍宝阁类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TreasureModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcTreasureDepotInfo
* Description:    珍宝阁-->珍宝阁数据同步调用操作函数
* Input:          TreasureRpcTreasureDepotInfoAskWraper& Ask 珍宝阁数据请求
* Output:         TreasureRpcTreasureDepotInfoReplyWraper& Reply 珍宝阁数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureDepotInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureInfo
* Description:    珍宝阁-->珍宝数据同步调用操作函数
* Input:          TreasureRpcTreasureInfoAskWraper& Ask 珍宝数据请求
* Output:         TreasureRpcTreasureInfoReplyWraper& Reply 珍宝数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureUnlock
* Description:    珍宝阁-->珍宝解锁同步调用操作函数
* Input:          TreasureRpcTreasureUnlockAskWraper& Ask 珍宝解锁请求
* Output:         TreasureRpcTreasureUnlockReplyWraper& Reply 珍宝解锁回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureUnlock( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureEquip
* Description:    珍宝阁-->珍宝穿戴同步调用操作函数
* Input:          TreasureRpcTreasureEquipAskWraper& Ask 珍宝穿戴请求
* Output:         TreasureRpcTreasureEquipReplyWraper& Reply 珍宝穿戴回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureEquip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureEquipSyc
* Description:    珍宝阁-->穿戴的珍宝同步调用操作函数
* Input:          TreasureRpcTreasureEquipSycAskWraper& Ask 穿戴的珍宝请求
* Output:         TreasureRpcTreasureEquipSycReplyWraper& Reply 穿戴的珍宝回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureEquipSyc( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureDepotLvUp
* Description:    珍宝阁-->珍宝阁升级同步调用操作函数
* Input:          TreasureRpcTreasureDepotLvUpAskWraper& Ask 珍宝阁升级请求
* Output:         TreasureRpcTreasureDepotLvUpReplyWraper& Reply 珍宝阁升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureDepotLvUp( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTreasureUnEquip
* Description:    珍宝阁-->卸下珍宝同步调用操作函数
* Input:          TreasureRpcTreasureUnEquipAskWraper& Ask 卸下珍宝请求
* Output:         TreasureRpcTreasureUnEquipReplyWraper& Reply 卸下珍宝回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureUnEquip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTreasureEquipedID
* Description:    珍宝阁-->已装备时装ID异步通知操作函数
* Input:          TreasureRpcTreasureEquipedIDNotifyWraper& Notify 已装备时装ID通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTreasure::SendToClientTreasureEquipedID( INT64 UserId, TreasureRpcTreasureEquipedIDNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcTreasureDelayTime
* Description:    珍宝阁-->续期同步调用操作函数
* Input:          TreasureRpcTreasureDelayTimeAskWraper& Ask 续期请求
* Output:         TreasureRpcTreasureDelayTimeReplyWraper& Reply 续期回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasure::RpcTreasureDelayTime( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTreasureUnlockEquip
* Description:    珍宝阁-->解锁并穿戴异步通知操作函数
* Input:          TreasureRpcTreasureUnlockEquipNotifyWraper& Notify 解锁并穿戴通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTreasure::SendToClientTreasureUnlockEquip( INT64 UserId, TreasureRpcTreasureUnlockEquipNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



