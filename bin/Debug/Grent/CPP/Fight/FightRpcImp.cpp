/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcFightImp.cpp
* Author:       郭晓波
* Description:  战斗类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "FightModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientUseSkillAction
* Description:    战斗-->使用技能动作异步通知操作函数
* Input:          FightRpcUseSkillActionNotifyWraper& Notify 使用技能动作通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientUseSkillAction( INT64 UserId, FightRpcUseSkillActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientShowExpAction
* Description:    战斗-->显示经验异步通知操作函数
* Input:          FightRpcShowExpActionNotifyWraper& Notify 显示经验通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientShowExpAction( INT64 UserId, FightRpcShowExpActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBuffAction
* Description:    战斗-->buf异步通知操作函数
* Input:          FightRpcBuffActionNotifyWraper& Notify buf通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientBuffAction( INT64 UserId, FightRpcBuffActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientStateAction
* Description:    战斗-->状态事件异步通知操作函数
* Input:          FightRpcStateActionNotifyWraper& Notify 状态事件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientStateAction( INT64 UserId, FightRpcStateActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientReviveAction
* Description:    战斗-->复活事件异步通知操作函数
* Input:          FightRpcReviveActionNotifyWraper& Notify 复活事件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientReviveAction( INT64 UserId, FightRpcReviveActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientComboSkillAction
* Description:    战斗-->连击技能异步通知操作函数
* Input:          FightRpcComboSkillActionNotifyWraper& Notify 连击技能通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientComboSkillAction( INT64 UserId, FightRpcComboSkillActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDropAction
* Description:    战斗-->掉落异步通知操作函数
* Input:          FightRpcDropActionNotifyWraper& Notify 掉落通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientDropAction( INT64 UserId, FightRpcDropActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUseItemAction
* Description:    战斗-->使用道具异步通知操作函数
* Input:          FightRpcUseItemActionNotifyWraper& Notify 使用道具通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientUseItemAction( INT64 UserId, FightRpcUseItemActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientHpChangeAction
* Description:    战斗-->血量改变异步通知操作函数
* Input:          FightRpcHpChangeActionNotifyWraper& Notify 血量改变通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientHpChangeAction( INT64 UserId, FightRpcHpChangeActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcUseSkill
* Description:    战斗-->使用技能请求同步调用操作函数
* Input:          FightRpcUseSkillAskWraper& Ask 使用技能请求请求
* Output:         FightRpcUseSkillReplyWraper& Reply 使用技能请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFight::RpcUseSkill( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientHurtAction
* Description:    战斗-->伤害事件异步通知操作函数
* Input:          FightRpcHurtActionNotifyWraper& Notify 伤害事件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientHurtAction( INT64 UserId, FightRpcHurtActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



