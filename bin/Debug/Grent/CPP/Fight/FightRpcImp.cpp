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
* Function:       RpcUseSkillAction
* Description:    战斗-->使用技能动作异步通知操作函数
* Input:          FightRpcUseSkillActionNotifyWraper& Notify 使用技能动作通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleFight::RpcUseSkillAction( INT64 UserId, FightRpcUseSkillActionNotifyWraper& Notify )
{

	//检测字段[objId]数据范围
	if( Notify.GetObjTargetId()<-1 && Notify.GetObjTargetId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetObjTargetId()>10000000 && Notify.GetObjTargetId()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[技能id]数据范围
	if( Notify.GetSkillId()<-1 && Notify.GetSkillId()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetSkillId()>10000000 && Notify.GetSkillId()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[技能释放目标点]数据范围
	if( Notify.GetX()<-1 && Notify.GetX()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetX()>10000000 && Notify.GetX()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[技能释放目标点]数据范围
	if( Notify.GetY()<-1 && Notify.GetY()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetY()>10000000 && Notify.GetY()!=-1)
	{
		assert(false);
		return 0;
	}

	//检测字段[技能释放方向]数据范围
	if( Notify.GetDir()<-1 && Notify.GetDir()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetDir()>10000000 && Notify.GetDir()!=-1)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

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



