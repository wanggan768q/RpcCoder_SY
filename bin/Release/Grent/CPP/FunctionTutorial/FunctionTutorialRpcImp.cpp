/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcFunctionTutorialImp.cpp
* Author:       甘业清
* Description:  功能引导类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "FunctionTutorialModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncFunctionStep
* Description:    功能引导-->同步同步调用操作函数
* Input:          FunctionTutorialRpcSyncFunctionStepAskWraper& Ask 同步请求
* Output:         FunctionTutorialRpcSyncFunctionStepReplyWraper& Reply 同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFunctionTutorial::RpcSyncFunctionStep( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcFinishStep
* Description:    功能引导-->完成同步调用操作函数
* Input:          FunctionTutorialRpcFinishStepAskWraper& Ask 完成请求
* Output:         FunctionTutorialRpcFinishStepReplyWraper& Reply 完成回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFunctionTutorial::RpcFinishStep( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcActiveStep
* Description:    功能引导-->激活步骤同步调用操作函数
* Input:          FunctionTutorialRpcActiveStepAskWraper& Ask 激活步骤请求
* Output:         FunctionTutorialRpcActiveStepReplyWraper& Reply 激活步骤回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFunctionTutorial::RpcActiveStep( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



