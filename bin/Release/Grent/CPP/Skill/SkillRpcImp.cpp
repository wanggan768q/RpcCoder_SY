/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcSkillImp.cpp
* Author:       甘业清
* Description:  技能模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "SkillModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSkillInfo
* Description:    技能模块-->技能信息同步调用操作函数
* Input:          SkillRpcSkillInfoAskWraper& Ask 技能信息请求
* Output:         SkillRpcSkillInfoReplyWraper& Reply 技能信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleSkill::RpcSkillInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUpdateSkillInfo
* Description:    技能模块-->更新技能信息同步调用操作函数
* Input:          SkillRpcUpdateSkillInfoAskWraper& Ask 更新技能信息请求
* Output:         SkillRpcUpdateSkillInfoReplyWraper& Reply 更新技能信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleSkill::RpcUpdateSkillInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLevelUpSkillPos
* Description:    技能模块-->技能栏位升级同步调用操作函数
* Input:          SkillRpcLevelUpSkillPosAskWraper& Ask 技能栏位升级请求
* Output:         SkillRpcLevelUpSkillPosReplyWraper& Reply 技能栏位升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleSkill::RpcLevelUpSkillPos( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSkillLevelInfo
* Description:    技能模块-->技能栏位等级信息同步调用操作函数
* Input:          SkillRpcSkillLevelInfoAskWraper& Ask 技能栏位等级信息请求
* Output:         SkillRpcSkillLevelInfoReplyWraper& Reply 技能栏位等级信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleSkill::RpcSkillLevelInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



