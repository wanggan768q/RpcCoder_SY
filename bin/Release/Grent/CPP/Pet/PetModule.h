/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePet.h
* Author:       甘业清
* Description:  宠物模块类，包含以下内容
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

#ifndef __MODULE_PET_H
#define __MODULE_PET_H


#include "ModuleBase.h"
#include "PetRpcWraper.h"




//宠物模块实现类
class ModulePet : public ModuleBase
{
	DECLARE_INSTANCE(ModulePet);
public:
	friend class			ModuleMgr;

public:
	//宠物模块实现类构造函数
	ModulePet();
	
	//宠物模块实现类析构函数
	virtual					~ModulePet();

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
	* Function:       RpcPetSync
	* Description:    宠物模块-->同步同步调用操作函数
	* Input:          PetRpcPetSyncAskWraper& Ask 同步请求
	* Output:         PetRpcPetSyncReplyWraper& Reply 同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPetSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUnSummon
	* Description:    宠物模块-->召回同步调用操作函数
	* Input:          PetRpcUnSummonAskWraper& Ask 召回请求
	* Output:         PetRpcUnSummonReplyWraper& Reply 召回回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUnSummon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLevelUpgrade
	* Description:    宠物模块-->升级同步调用操作函数
	* Input:          PetRpcLevelUpgradeAskWraper& Ask 升级请求
	* Output:         PetRpcLevelUpgradeReplyWraper& Reply 升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLevelUpgrade( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcStarUpgrade
	* Description:    宠物模块-->升星同步调用操作函数
	* Input:          PetRpcStarUpgradeAskWraper& Ask 升星请求
	* Output:         PetRpcStarUpgradeReplyWraper& Reply 升星回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcStarUpgrade( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChangeName
	* Description:    宠物模块-->改名同步调用操作函数
	* Input:          PetRpcChangeNameAskWraper& Ask 改名请求
	* Output:         PetRpcChangeNameReplyWraper& Reply 改名回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeName( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInherit
	* Description:    宠物模块-->传承同步调用操作函数
	* Input:          PetRpcInheritAskWraper& Ask 传承请求
	* Output:         PetRpcInheritReplyWraper& Reply 传承回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInherit( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSkillInherit
	* Description:    宠物模块-->技能继承同步调用操作函数
	* Input:          PetRpcSkillInheritAskWraper& Ask 技能继承请求
	* Output:         PetRpcSkillInheritReplyWraper& Reply 技能继承回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSkillInherit( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcPassiveSkills
	* Description:    宠物模块-->宠物被动技能列表同步调用操作函数
	* Input:          PetRpcPassiveSkillsAskWraper& Ask 宠物被动技能列表请求
	* Output:         PetRpcPassiveSkillsReplyWraper& Reply 宠物被动技能列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPassiveSkills( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcStudySkill
	* Description:    宠物模块-->学习被动技能同步调用操作函数
	* Input:          PetRpcStudySkillAskWraper& Ask 学习被动技能请求
	* Output:         PetRpcStudySkillReplyWraper& Reply 学习被动技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcStudySkill( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLockSkill
	* Description:    宠物模块-->锁定技能同步调用操作函数
	* Input:          PetRpcLockSkillAskWraper& Ask 锁住技能请求
	* Output:         PetRpcLockSkillReplyWraper& Reply 锁住技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLockSkill( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUnLockSkill
	* Description:    宠物模块-->解除技能锁定同步调用操作函数
	* Input:          PetRpcUnLockSkillAskWraper& Ask 解除技能锁定请求
	* Output:         PetRpcUnLockSkillReplyWraper& Reply 解除技能锁定回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUnLockSkill( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif