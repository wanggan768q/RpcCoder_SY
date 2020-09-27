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

/********************************************************************************************
* Function:       SendToClientRepelAction
* Description:    战斗-->战斗击 退、飞、撞、拉 通知异步通知操作函数
* Input:          FightRpcRepelActionNotifyWraper& Notify 战斗击 退、飞、撞、拉 通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRepelAction( INT64 UserId, FightRpcRepelActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientObjDeadAction
* Description:    战斗-->obj死亡通知异步通知操作函数
* Input:          FightRpcObjDeadActionNotifyWraper& Notify obj死亡通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientObjDeadAction( INT64 UserId, FightRpcObjDeadActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientFightTips
* Description:    战斗-->战斗辅助tips异步通知操作函数
* Input:          FightRpcFightTipsNotifyWraper& Notify 战斗辅助tips通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientFightTips( INT64 UserId, FightRpcFightTipsNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBuffList
* Description:    战斗-->BuffList异步通知操作函数
* Input:          FightRpcBuffListNotifyWraper& Notify BuffList通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientBuffList( INT64 UserId, FightRpcBuffListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientReduceCD
* Description:    战斗-->减少cd异步通知操作函数
* Input:          FightRpcReduceCDNotifyWraper& Notify 减少cd通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientReduceCD( INT64 UserId, FightRpcReduceCDNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientReliveNotify
* Description:    战斗-->复活通知异步通知操作函数
* Input:          FightRpcReliveNotifyNotifyWraper& Notify 复活通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientReliveNotify( INT64 UserId, FightRpcReliveNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSkillCD
* Description:    战斗-->技能同步cd异步通知操作函数
* Input:          FightRpcSkillCDNotifyWraper& Notify 技能同步cd通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillCD( INT64 UserId, FightRpcSkillCDNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientAutoCombatMonster
* Description:    战斗-->自动杀怪异步通知操作函数
* Input:          FightRpcAutoCombatMonsterNotifyWraper& Notify 自动杀怪通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientAutoCombatMonster( INT64 UserId, FightRpcAutoCombatMonsterNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientTranslateAction
* Description:    战斗-->战斗位移异步通知操作函数
* Input:          FightRpcTranslateActionNotifyWraper& Notify 战斗位移通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientTranslateAction( INT64 UserId, FightRpcTranslateActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientCantAddBuffTip
* Description:    战斗-->添加buff失败提示异步通知操作函数
* Input:          FightRpcCantAddBuffTipNotifyWraper& Notify 添加buff失败提示通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientCantAddBuffTip( INT64 UserId, FightRpcCantAddBuffTipNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientAttackWarning
* Description:    战斗-->生成预警圈异步通知操作函数
* Input:          FightRpcAttackWarningNotifyWraper& Notify 生成预警圈通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientAttackWarning( INT64 UserId, FightRpcAttackWarningNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientInterruptAction
* Description:    战斗-->技能打断事件异步通知操作函数
* Input:          FightRpcInterruptActionNotifyWraper& Notify 技能打断事件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientInterruptAction( INT64 UserId, FightRpcInterruptActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSkillPrepare
* Description:    战斗-->技能蓄力请求同步调用操作函数
* Input:          FightRpcSkillPrepareAskWraper& Ask 技能蓄力请求请求
* Output:         FightRpcSkillPrepareReplyWraper& Reply 技能蓄力请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFight::RpcSkillPrepare( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSkillPrepareAction
* Description:    战斗-->蓄力技能通知异步通知操作函数
* Input:          FightRpcSkillPrepareActionNotifyWraper& Notify 蓄力技能通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillPrepareAction( INT64 UserId, FightRpcSkillPrepareActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientChainMagicJump
* Description:    战斗-->链式法术跳跃异步通知操作函数
* Input:          FightRpcChainMagicJumpNotifyWraper& Notify 链式法术跳跃通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientChainMagicJump( INT64 UserId, FightRpcChainMagicJumpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBlackHoleAction
* Description:    战斗-->黑洞拉拽效果异步通知操作函数
* Input:          FightRpcBlackHoleActionNotifyWraper& Notify 黑洞拉拽效果通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientBlackHoleAction( INT64 UserId, FightRpcBlackHoleActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcLoopActionCancel
* Description:    战斗-->循环动作取消同步调用操作函数
* Input:          FightRpcLoopActionCancelAskWraper& Ask 循环动作取消请求
* Output:         FightRpcLoopActionCancelReplyWraper& Reply 循环动作取消回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFight::RpcLoopActionCancel( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientLoopActionCancelOther
* Description:    战斗-->循环动作取消广播异步通知操作函数
* Input:          FightRpcLoopActionCancelOtherNotifyWraper& Notify 循环动作取消广播通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientLoopActionCancelOther( INT64 UserId, FightRpcLoopActionCancelOtherNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSkillList
* Description:    战斗-->SkillList异步通知操作函数
* Input:          FightRpcSkillListNotifyWraper& Notify SkillList通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillList( INT64 UserId, FightRpcSkillListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcUsePetSkill
* Description:    战斗-->使用宠物技能同步调用操作函数
* Input:          FightRpcUsePetSkillAskWraper& Ask 使用宠物技能请求
* Output:         FightRpcUsePetSkillReplyWraper& Reply 使用宠物技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFight::RpcUsePetSkill( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRemoveModifySkill
* Description:    战斗-->RemoveModifySkill异步通知操作函数
* Input:          FightRpcRemoveModifySkillNotifyWraper& Notify RemoveModifySkill通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRemoveModifySkill( INT64 UserId, FightRpcRemoveModifySkillNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientLinkMagicAction
* Description:    战斗-->链接magic效果异步通知操作函数
* Input:          FightRpcLinkMagicActionNotifyWraper& Notify 链接magic效果通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientLinkMagicAction( INT64 UserId, FightRpcLinkMagicActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcMonsterInteract
* Description:    战斗-->怪物交互同步调用操作函数
* Input:          FightRpcMonsterInteractAskWraper& Ask 怪物交互请求
* Output:         FightRpcMonsterInteractReplyWraper& Reply 怪物交互回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleFight::RpcMonsterInteract( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



