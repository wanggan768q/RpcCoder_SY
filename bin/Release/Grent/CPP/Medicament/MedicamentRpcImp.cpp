/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMedicamentImp.cpp
* Author:       甘业清
* Description:  药剂类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "MedicamentModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcFillHp
* Description:    药剂-->使用物品填充hp池同步调用操作函数
* Input:          MedicamentRpcFillHpAskWraper& Ask 使用物品填充hp池请求
* Output:         MedicamentRpcFillHpReplyWraper& Reply 使用物品填充hp池回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMedicament::RpcFillHp( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOneStepFillHp
* Description:    药剂-->一键添加同步调用操作函数
* Input:          MedicamentRpcOneStepFillHpAskWraper& Ask 一键添加请求
* Output:         MedicamentRpcOneStepFillHpReplyWraper& Reply 一键添加回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMedicament::RpcOneStepFillHp( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcClientRefreshMedicament
* Description:    药剂-->客户端刷新药剂同步调用操作函数
* Input:          MedicamentRpcClientRefreshMedicamentAskWraper& Ask 客户端刷新药剂请求
* Output:         MedicamentRpcClientRefreshMedicamentReplyWraper& Reply 客户端刷新药剂回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMedicament::RpcClientRefreshMedicament( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientServerRefreshMedicament
* Description:    药剂-->服务器刷新药剂异步通知操作函数
* Input:          MedicamentRpcServerRefreshMedicamentNotifyWraper& Notify 服务器刷新药剂通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMedicament::SendToClientServerRefreshMedicament( INT64 UserId, MedicamentRpcServerRefreshMedicamentNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSyncMedicamentData
* Description:    药剂-->请求数据同步调用操作函数
* Input:          MedicamentRpcSyncMedicamentDataAskWraper& Ask 请求数据请求
* Output:         MedicamentRpcSyncMedicamentDataReplyWraper& Reply 请求数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMedicament::RpcSyncMedicamentData( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMedicamentCD
* Description:    药剂-->药剂CD同步调用操作函数
* Input:          MedicamentRpcMedicamentCDAskWraper& Ask 药剂CD请求
* Output:         MedicamentRpcMedicamentCDReplyWraper& Reply 药剂CD回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMedicament::RpcMedicamentCD( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientMedicamentCDNotify
* Description:    药剂-->通知CD异步通知操作函数
* Input:          MedicamentRpcMedicamentCDNotifyNotifyWraper& Notify 通知CD通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMedicament::SendToClientMedicamentCDNotify( INT64 UserId, MedicamentRpcMedicamentCDNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



