/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFight.h
* Author:       甘业清
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


#include "ModuleBase.h"
#include "FightRpcWraper.h"




//战斗实现类
class ModuleFight : public ModuleBase
{
	DECLARE_INSTANCE(ModuleFight);
public:
	friend class			ModuleMgr;

public:
	//战斗实现类构造函数
	ModuleFight();
	
	//战斗实现类析构函数
	virtual					~ModuleFight();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

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



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif