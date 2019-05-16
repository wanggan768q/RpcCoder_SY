/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMailImp.cpp
* Author:       甘业清
* Description:  邮件类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "MailModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcInitMail
* Description:    邮件-->初始化邮件信息同步调用操作函数
* Input:          MailRpcInitMailAskWraper& Ask 初始化邮件信息请求
* Output:         MailRpcInitMailReplyWraper& Reply 初始化邮件信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMail::RpcInitMail( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcReadMail
* Description:    邮件-->已读邮件同步调用操作函数
* Input:          MailRpcReadMailAskWraper& Ask 已读邮件请求
* Output:         MailRpcReadMailReplyWraper& Reply 已读邮件回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMail::RpcReadMail( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDeleteMail
* Description:    邮件-->删除邮件同步调用操作函数
* Input:          MailRpcDeleteMailAskWraper& Ask 删除邮件请求
* Output:         MailRpcDeleteMailReplyWraper& Reply 删除邮件回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMail::RpcDeleteMail( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetMail
* Description:    邮件-->领取邮件同步调用操作函数
* Input:          MailRpcGetMailAskWraper& Ask 领取邮件请求
* Output:         MailRpcGetMailReplyWraper& Reply 领取邮件回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMail::RpcGetMail( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncMailInfo
* Description:    邮件-->同步邮件信息异步通知操作函数
* Input:          MailRpcSyncMailInfoNotifyWraper& Notify 同步邮件信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMail::SendToClientSyncMailInfo( INT64 UserId, MailRpcSyncMailInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



