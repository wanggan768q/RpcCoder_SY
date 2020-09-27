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
#include "Game/PacketMgr.h"
#include "FightRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




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
	RPC_CODE_FIGHT_REPELACTION_NOTIFY            = 962,	//战斗-->战斗击 退、飞、撞、拉 通知-->通知
	RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY          = 963,	//战斗-->obj死亡通知-->通知
	RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY              = 964,	//战斗-->战斗辅助tips-->通知
	RPC_CODE_FIGHT_BUFFLIST_NOTIFY               = 965,	//战斗-->BuffList-->通知
	RPC_CODE_FIGHT_REDUCECD_NOTIFY               = 966,	//战斗-->减少cd-->通知
	RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY           = 967,	//战斗-->复活通知-->通知
	RPC_CODE_FIGHT_SKILLCD_NOTIFY                = 968,	//战斗-->技能同步cd-->通知
	RPC_CODE_FIGHT_AUTOCOMBATMONSTER_NOTIFY      = 969,	//战斗-->自动杀怪-->通知
	RPC_CODE_FIGHT_TRANSLATEACTION_NOTIFY        = 970,	//战斗-->战斗位移-->通知
	RPC_CODE_FIGHT_CANTADDBUFFTIP_NOTIFY         = 971,	//战斗-->添加buff失败提示-->通知
	RPC_CODE_FIGHT_ATTACKWARNING_NOTIFY          = 972,	//战斗-->生成预警圈-->通知
	RPC_CODE_FIGHT_INTERRUPTACTION_NOTIFY        = 973,	//战斗-->技能打断事件-->通知
	RPC_CODE_FIGHT_SKILLPREPARE_REQUEST          = 974,	//战斗-->技能蓄力请求-->请求
	RPC_CODE_FIGHT_SKILLPREPAREACTION_NOTIFY     = 975,	//战斗-->蓄力技能通知-->通知
	RPC_CODE_FIGHT_CHAINMAGICJUMP_NOTIFY         = 976,	//战斗-->链式法术跳跃-->通知
	RPC_CODE_FIGHT_BLACKHOLEACTION_NOTIFY        = 977,	//战斗-->黑洞拉拽效果-->通知
	RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST      = 978,	//战斗-->循环动作取消-->请求
	RPC_CODE_FIGHT_LOOPACTIONCANCELOTHER_NOTIFY  = 979,	//战斗-->循环动作取消广播-->通知
	RPC_CODE_FIGHT_SKILLLIST_NOTIFY              = 980,	//战斗-->SkillList-->通知
	RPC_CODE_FIGHT_USEPETSKILL_REQUEST           = 981,	//战斗-->使用宠物技能-->请求
	RPC_CODE_FIGHT_REMOVEMODIFYSKILL_NOTIFY      = 982,	//战斗-->RemoveModifySkill-->通知
	RPC_CODE_FIGHT_LINKMAGICACTION_NOTIFY        = 983,	//战斗-->链接magic效果-->通知
	RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST       = 984,	//战斗-->怪物交互-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//战斗实现类构造函数
	ModuleFight()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_USESKILL_REQUEST, &ModuleFight::RpcUseSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_USESKILL_REQUEST, new Some_Factory<FightRpcUseSkillAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_SKILLPREPARE_REQUEST, &ModuleFight::RpcSkillPrepare);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_SKILLPREPARE_REQUEST, new Some_Factory<FightRpcSkillPrepareAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST, &ModuleFight::RpcLoopActionCancel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_LOOPACTIONCANCEL_REQUEST, new Some_Factory<FightRpcLoopActionCancelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_USEPETSKILL_REQUEST, &ModuleFight::RpcUsePetSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_USEPETSKILL_REQUEST, new Some_Factory<FightRpcUsePetSkillAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST, &ModuleFight::RpcMonsterInteract);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_MONSTERINTERACT_REQUEST, new Some_Factory<FightRpcMonsterInteractAsk>());

	}
	
	//战斗实现类析构函数
	~ModuleFight(){}


	static ModuleFight & Instance()
	{
		static ModuleFight sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
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

	/********************************************************************************************
	* Function:       SendToClientRepelAction
	* Description:    战斗-->战斗击 退、飞、撞、拉 通知异步通知操作函数
	* Input:          FightRpcRepelActionNotifyWraper& Notify 战斗击 退、飞、撞、拉 通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRepelAction( INT64 UserId, FightRpcRepelActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientObjDeadAction
	* Description:    战斗-->obj死亡通知异步通知操作函数
	* Input:          FightRpcObjDeadActionNotifyWraper& Notify obj死亡通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjDeadAction( INT64 UserId, FightRpcObjDeadActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientFightTips
	* Description:    战斗-->战斗辅助tips异步通知操作函数
	* Input:          FightRpcFightTipsNotifyWraper& Notify 战斗辅助tips通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientFightTips( INT64 UserId, FightRpcFightTipsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBuffList
	* Description:    战斗-->BuffList异步通知操作函数
	* Input:          FightRpcBuffListNotifyWraper& Notify BuffList通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBuffList( INT64 UserId, FightRpcBuffListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientReduceCD
	* Description:    战斗-->减少cd异步通知操作函数
	* Input:          FightRpcReduceCDNotifyWraper& Notify 减少cd通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReduceCD( INT64 UserId, FightRpcReduceCDNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientReliveNotify
	* Description:    战斗-->复活通知异步通知操作函数
	* Input:          FightRpcReliveNotifyNotifyWraper& Notify 复活通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReliveNotify( INT64 UserId, FightRpcReliveNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillCD
	* Description:    战斗-->技能同步cd异步通知操作函数
	* Input:          FightRpcSkillCDNotifyWraper& Notify 技能同步cd通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSkillCD( INT64 UserId, FightRpcSkillCDNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientAutoCombatMonster
	* Description:    战斗-->自动杀怪异步通知操作函数
	* Input:          FightRpcAutoCombatMonsterNotifyWraper& Notify 自动杀怪通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAutoCombatMonster( INT64 UserId, FightRpcAutoCombatMonsterNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTranslateAction
	* Description:    战斗-->战斗位移异步通知操作函数
	* Input:          FightRpcTranslateActionNotifyWraper& Notify 战斗位移通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTranslateAction( INT64 UserId, FightRpcTranslateActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCantAddBuffTip
	* Description:    战斗-->添加buff失败提示异步通知操作函数
	* Input:          FightRpcCantAddBuffTipNotifyWraper& Notify 添加buff失败提示通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCantAddBuffTip( INT64 UserId, FightRpcCantAddBuffTipNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientAttackWarning
	* Description:    战斗-->生成预警圈异步通知操作函数
	* Input:          FightRpcAttackWarningNotifyWraper& Notify 生成预警圈通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAttackWarning( INT64 UserId, FightRpcAttackWarningNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientInterruptAction
	* Description:    战斗-->技能打断事件异步通知操作函数
	* Input:          FightRpcInterruptActionNotifyWraper& Notify 技能打断事件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientInterruptAction( INT64 UserId, FightRpcInterruptActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSkillPrepare
	* Description:    战斗-->技能蓄力请求同步调用操作函数
	* Input:          FightRpcSkillPrepareAskWraper& Ask 技能蓄力请求请求
	* Output:         FightRpcSkillPrepareReplyWraper& Reply 技能蓄力请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSkillPrepare( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSkillPrepareAction
	* Description:    战斗-->蓄力技能通知异步通知操作函数
	* Input:          FightRpcSkillPrepareActionNotifyWraper& Notify 蓄力技能通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSkillPrepareAction( INT64 UserId, FightRpcSkillPrepareActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientChainMagicJump
	* Description:    战斗-->链式法术跳跃异步通知操作函数
	* Input:          FightRpcChainMagicJumpNotifyWraper& Notify 链式法术跳跃通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChainMagicJump( INT64 UserId, FightRpcChainMagicJumpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBlackHoleAction
	* Description:    战斗-->黑洞拉拽效果异步通知操作函数
	* Input:          FightRpcBlackHoleActionNotifyWraper& Notify 黑洞拉拽效果通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBlackHoleAction( INT64 UserId, FightRpcBlackHoleActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcLoopActionCancel
	* Description:    战斗-->循环动作取消同步调用操作函数
	* Input:          FightRpcLoopActionCancelAskWraper& Ask 循环动作取消请求
	* Output:         FightRpcLoopActionCancelReplyWraper& Reply 循环动作取消回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLoopActionCancel( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientLoopActionCancelOther
	* Description:    战斗-->循环动作取消广播异步通知操作函数
	* Input:          FightRpcLoopActionCancelOtherNotifyWraper& Notify 循环动作取消广播通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLoopActionCancelOther( INT64 UserId, FightRpcLoopActionCancelOtherNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillList
	* Description:    战斗-->SkillList异步通知操作函数
	* Input:          FightRpcSkillListNotifyWraper& Notify SkillList通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSkillList( INT64 UserId, FightRpcSkillListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcUsePetSkill
	* Description:    战斗-->使用宠物技能同步调用操作函数
	* Input:          FightRpcUsePetSkillAskWraper& Ask 使用宠物技能请求
	* Output:         FightRpcUsePetSkillReplyWraper& Reply 使用宠物技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUsePetSkill( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRemoveModifySkill
	* Description:    战斗-->RemoveModifySkill异步通知操作函数
	* Input:          FightRpcRemoveModifySkillNotifyWraper& Notify RemoveModifySkill通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRemoveModifySkill( INT64 UserId, FightRpcRemoveModifySkillNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLinkMagicAction
	* Description:    战斗-->链接magic效果异步通知操作函数
	* Input:          FightRpcLinkMagicActionNotifyWraper& Notify 链接magic效果通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLinkMagicAction( INT64 UserId, FightRpcLinkMagicActionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcMonsterInteract
	* Description:    战斗-->怪物交互同步调用操作函数
	* Input:          FightRpcMonsterInteractAskWraper& Ask 怪物交互请求
	* Output:         FightRpcMonsterInteractReplyWraper& Reply 怪物交互回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMonsterInteract( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif