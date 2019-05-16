/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcPetImp.cpp
* Author:       甘业清
* Description:  宠物模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "PetModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcPetSync
* Description:    宠物模块-->同步同步调用操作函数
* Input:          PetRpcPetSyncAskWraper& Ask 同步请求
* Output:         PetRpcPetSyncReplyWraper& Reply 同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcPetSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUnSummon
* Description:    宠物模块-->召回同步调用操作函数
* Input:          PetRpcUnSummonAskWraper& Ask 召回请求
* Output:         PetRpcUnSummonReplyWraper& Reply 召回回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcUnSummon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLevelUpgrade
* Description:    宠物模块-->升级同步调用操作函数
* Input:          PetRpcLevelUpgradeAskWraper& Ask 升级请求
* Output:         PetRpcLevelUpgradeReplyWraper& Reply 升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcLevelUpgrade( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStarUpgrade
* Description:    宠物模块-->升星同步调用操作函数
* Input:          PetRpcStarUpgradeAskWraper& Ask 升星请求
* Output:         PetRpcStarUpgradeReplyWraper& Reply 升星回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcStarUpgrade( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeName
* Description:    宠物模块-->改名同步调用操作函数
* Input:          PetRpcChangeNameAskWraper& Ask 改名请求
* Output:         PetRpcChangeNameReplyWraper& Reply 改名回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcChangeName( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInherit
* Description:    宠物模块-->传承同步调用操作函数
* Input:          PetRpcInheritAskWraper& Ask 传承请求
* Output:         PetRpcInheritReplyWraper& Reply 传承回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcInherit( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSkillInherit
* Description:    宠物模块-->技能继承同步调用操作函数
* Input:          PetRpcSkillInheritAskWraper& Ask 技能继承请求
* Output:         PetRpcSkillInheritReplyWraper& Reply 技能继承回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcSkillInherit( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcPassiveSkills
* Description:    宠物模块-->宠物被动技能列表同步调用操作函数
* Input:          PetRpcPassiveSkillsAskWraper& Ask 宠物被动技能列表请求
* Output:         PetRpcPassiveSkillsReplyWraper& Reply 宠物被动技能列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcPassiveSkills( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStudySkill
* Description:    宠物模块-->学习被动技能同步调用操作函数
* Input:          PetRpcStudySkillAskWraper& Ask 学习被动技能请求
* Output:         PetRpcStudySkillReplyWraper& Reply 学习被动技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcStudySkill( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLockSkill
* Description:    宠物模块-->锁定技能同步调用操作函数
* Input:          PetRpcLockSkillAskWraper& Ask 锁住技能请求
* Output:         PetRpcLockSkillReplyWraper& Reply 锁住技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcLockSkill( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUnLockSkill
* Description:    宠物模块-->解除技能锁定同步调用操作函数
* Input:          PetRpcUnLockSkillAskWraper& Ask 解除技能锁定请求
* Output:         PetRpcUnLockSkillReplyWraper& Reply 解除技能锁定回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePet::RpcUnLockSkill( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



