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

	};

public:
	//战斗实现类构造函数
	ModuleFight()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_USESKILLACTION_NOTIFY, &ModuleFight::RpcUseSkillAction);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_USESKILLACTION_NOTIFY, new Some_Factory<FightRpcUseSkillActionNotify>());

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
	* Function:       RpcUseSkillAction
	* Description:    战斗-->使用技能动作异步通知操作函数
	* Input:          FightRpcUseSkillActionNotifyWraper& Notify 使用技能动作通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcUseSkillAction(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientUseSkillAction
	* Description:    战斗-->使用技能动作异步通知操作函数
	* Input:          FightRpcUseSkillActionNotifyWraper& Notify 使用技能动作通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUseSkillAction( INT64 UserId, FightRpcUseSkillActionNotifyWraper& Notify );



};

#endif