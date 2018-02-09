/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleFight.h
* Author:       郭晓波
* Description:  战斗类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_FIGHT_H
#define __MODULE_FIGHT_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "FightRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//战斗实现类
class ModuleFight
{
	
public:
	//战斗类的枚举定义
	enum ConstFightE
	{
	MODULE_ID_FIGHT                              = 9,	//战斗模块ID
	RPC_CODE_FIGHT_USESKILLACTION_NOTIFY         = 951,	//战斗-->使用技能动作-->通知
	RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY          = 952,	//战斗-->显示经验-->通知
	RPC_CODE_FIGHT_BUFFACTION_NOTIFY             = 953,	//战斗-->buf-->通知
	RPC_CODE_FIGHT_STATEACTION_NOTIFY            = 954,	//战斗-->状态事件-->通知
	RPC_CODE_FIGHT_REVIVEACTION_NOTIFY           = 955,	//战斗-->复活事件-->通知
	RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY       = 956,	//战斗-->连击技能-->通知
	RPC_CODE_FIGHT_DROPACTION_NOTIFY             = 957,	//战斗-->掉落-->通知
	RPC_CODE_FIGHT_USEITEMACTION_NOTIFY          = 958,	//战斗-->使用道具-->通知
	RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY         = 959,	//战斗-->血量改变-->通知
	RPC_CODE_FIGHT_USESKILL_REQUEST              = 960,	//战斗-->使用技能请求-->请求
	RPC_CODE_FIGHT_HURTACTION_NOTIFY             = 961,	//战斗-->伤害事件-->通知

	};

public:
	//战斗实现类构造函数
	ModuleFight()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_USESKILL_REQUEST, &ModuleFight::RpcUseSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_USESKILL_REQUEST, new Some_Factory<FightRpcUseSkillAsk>());

	}
	
	//战斗实现类析构函数
	~ModuleFight(){}


	static ModuleFight Instance()
	{
		static ModuleFight sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       SendToClientUseSkillAction
	* Description:    战斗-->使用技能动作异步通知操作函数
	* Input:          FightRpcUseSkillActionNotifyWraper& Notify 使用技能动作通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUseSkillAction( INT64 UserId, FightRpcUseSkillActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientShowExpAction
	* Description:    战斗-->显示经验异步通知操作函数
	* Input:          FightRpcShowExpActionNotifyWraper& Notify 显示经验通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientShowExpAction( INT64 UserId, FightRpcShowExpActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBuffAction
	* Description:    战斗-->buf异步通知操作函数
	* Input:          FightRpcBuffActionNotifyWraper& Notify buf通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBuffAction( INT64 UserId, FightRpcBuffActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientStateAction
	* Description:    战斗-->状态事件异步通知操作函数
	* Input:          FightRpcStateActionNotifyWraper& Notify 状态事件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientStateAction( INT64 UserId, FightRpcStateActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientReviveAction
	* Description:    战斗-->复活事件异步通知操作函数
	* Input:          FightRpcReviveActionNotifyWraper& Notify 复活事件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReviveAction( INT64 UserId, FightRpcReviveActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientComboSkillAction
	* Description:    战斗-->连击技能异步通知操作函数
	* Input:          FightRpcComboSkillActionNotifyWraper& Notify 连击技能通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientComboSkillAction( INT64 UserId, FightRpcComboSkillActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDropAction
	* Description:    战斗-->掉落异步通知操作函数
	* Input:          FightRpcDropActionNotifyWraper& Notify 掉落通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDropAction( INT64 UserId, FightRpcDropActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUseItemAction
	* Description:    战斗-->使用道具异步通知操作函数
	* Input:          FightRpcUseItemActionNotifyWraper& Notify 使用道具通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUseItemAction( INT64 UserId, FightRpcUseItemActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientHpChangeAction
	* Description:    战斗-->血量改变异步通知操作函数
	* Input:          FightRpcHpChangeActionNotifyWraper& Notify 血量改变通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientHpChangeAction( INT64 UserId, FightRpcHpChangeActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcUseSkill
	* Description:    战斗-->使用技能请求同步调用操作函数
	* Input:          FightRpcUseSkillAskWraper& Ask 使用技能请求请求
	* Output:         FightRpcUseSkillReplyWraper& Reply 使用技能请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUseSkill( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientHurtAction
	* Description:    战斗-->伤害事件异步通知操作函数
	* Input:          FightRpcHurtActionNotifyWraper& Notify 伤害事件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientHurtAction( INT64 UserId, FightRpcHurtActionNotifyWraper& Notify );



};

#endif