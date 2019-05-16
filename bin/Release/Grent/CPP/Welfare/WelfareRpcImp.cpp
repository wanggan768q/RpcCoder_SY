/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcWelfareImp.cpp
* Author:       甘业清
* Description:  福利类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "WelfareModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcAccumulateSignIn
* Description:    福利-->累计登陆福利同步调用操作函数
* Input:          WelfareRpcAccumulateSignInAskWraper& Ask 累计登陆福利请求
* Output:         WelfareRpcAccumulateSignInReplyWraper& Reply 累计登陆福利回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcAccumulateSignIn( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAccumulateGetReward
* Description:    福利-->领取累计登陆奖励同步调用操作函数
* Input:          WelfareRpcAccumulateGetRewardAskWraper& Ask 领取累计登陆奖励请求
* Output:         WelfareRpcAccumulateGetRewardReplyWraper& Reply 领取累计登陆奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcAccumulateGetReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOnlineBonus
* Description:    福利-->今日在线福利同步调用操作函数
* Input:          WelfareRpcOnlineBonusAskWraper& Ask 今日在线福利请求
* Output:         WelfareRpcOnlineBonusReplyWraper& Reply 今日在线福利回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcOnlineBonus( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOnlineGetReward
* Description:    福利-->领取今日在线奖励同步调用操作函数
* Input:          WelfareRpcOnlineGetRewardAskWraper& Ask 领取今日在线奖励请求
* Output:         WelfareRpcOnlineGetRewardReplyWraper& Reply 领取今日在线奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcOnlineGetReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLevelBonus
* Description:    福利-->等级福利同步调用操作函数
* Input:          WelfareRpcLevelBonusAskWraper& Ask 等级福利请求
* Output:         WelfareRpcLevelBonusReplyWraper& Reply 等级福利回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcLevelBonus( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLevelBonusReward
* Description:    福利-->领取等级福利奖励同步调用操作函数
* Input:          WelfareRpcLevelBonusRewardAskWraper& Ask 领取等级福利奖励请求
* Output:         WelfareRpcLevelBonusRewardReplyWraper& Reply 领取等级福利奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcLevelBonusReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMonthSignInBonus
* Description:    福利-->签到福利同步调用操作函数
* Input:          WelfareRpcMonthSignInBonusAskWraper& Ask 签到福利请求
* Output:         WelfareRpcMonthSignInBonusReplyWraper& Reply 签到福利回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcMonthSignInBonus( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMonthSignInReward
* Description:    福利-->签到同步调用操作函数
* Input:          WelfareRpcMonthSignInRewardAskWraper& Ask 签到请求
* Output:         WelfareRpcMonthSignInRewardReplyWraper& Reply 签到回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcMonthSignInReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTodaySignIn
* Description:    福利-->今日签到提醒异步通知操作函数
* Input:          WelfareRpcTodaySignInNotifyWraper& Notify 今日签到提醒通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleWelfare::SendToClientTodaySignIn( INT64 UserId, WelfareRpcTodaySignInNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSpecLogin
* Description:    福利-->运营登录活动异步通知操作函数
* Input:          WelfareRpcSpecLoginNotifyWraper& Notify 运营登录活动通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleWelfare::SendToClientSpecLogin( INT64 UserId, WelfareRpcSpecLoginNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSpecLoginReward
* Description:    福利-->运营登录活动领取奖励同步调用操作函数
* Input:          WelfareRpcSpecLoginRewardAskWraper& Ask 运营登录活动领取奖励请求
* Output:         WelfareRpcSpecLoginRewardReplyWraper& Reply 运营登录活动领取奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWelfare::RpcSpecLoginReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



