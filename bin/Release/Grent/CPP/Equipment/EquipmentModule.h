/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEquipment.h
* Author:       甘业清
* Description:  装备类，包含以下内容
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

#ifndef __MODULE_EQUIPMENT_H
#define __MODULE_EQUIPMENT_H


#include "ModuleBase.h"
#include "EquipmentRpcWraper.h"




//装备实现类
class ModuleEquipment : public ModuleBase
{
	DECLARE_INSTANCE(ModuleEquipment);
public:
	friend class			ModuleMgr;

public:
	//装备实现类构造函数
	ModuleEquipment();
	
	//装备实现类析构函数
	virtual					~ModuleEquipment();

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
	* Function:       RpcEquip
	* Description:    装备-->Equip同步调用操作函数
	* Input:          EquipmentRpcEquipAskWraper& Ask 装备请求
	* Output:         EquipmentRpcEquipReplyWraper& Reply 装备回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUnEquip
	* Description:    装备-->UnEquip同步调用操作函数
	* Input:          EquipmentRpcUnEquipAskWraper& Ask 卸载装备请求
	* Output:         EquipmentRpcUnEquipReplyWraper& Reply 卸载装备回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUnEquip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSwitchEquipSet
	* Description:    装备-->SwitchEquipSet同步调用操作函数
	* Input:          EquipmentRpcSwitchEquipSetAskWraper& Ask 切换装备套装请求
	* Output:         EquipmentRpcSwitchEquipSetReplyWraper& Reply 切换装备套装回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSwitchEquipSet( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSyncEquip
	* Description:    装备-->Equip同步调用操作函数
	* Input:          EquipmentRpcSyncEquipAskWraper& Ask 同步装备套装请求
	* Output:         EquipmentRpcSyncEquipReplyWraper& Reply 同步装备套装回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncEquip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcResonanceUnlock
	* Description:    装备-->激活共鸣同步调用操作函数
	* Input:          EquipmentRpcResonanceUnlockAskWraper& Ask 激活共鸣请求
	* Output:         EquipmentRpcResonanceUnlockReplyWraper& Reply 激活共鸣回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcResonanceUnlock( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipDoResonance
	* Description:    装备-->共鸣洗练同步调用操作函数
	* Input:          EquipmentRpcEquipDoResonanceAskWraper& Ask 共鸣洗练请求
	* Output:         EquipmentRpcEquipDoResonanceReplyWraper& Reply 共鸣洗练回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipDoResonance( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipResonanceSave
	* Description:    装备-->保存共鸣属性同步调用操作函数
	* Input:          EquipmentRpcEquipResonanceSaveAskWraper& Ask 保存共鸣属性请求
	* Output:         EquipmentRpcEquipResonanceSaveReplyWraper& Reply 保存共鸣属性回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipResonanceSave( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipResonanceSync
	* Description:    装备-->初始化同步调用操作函数
	* Input:          EquipmentRpcEquipResonanceSyncAskWraper& Ask 初始化请求
	* Output:         EquipmentRpcEquipResonanceSyncReplyWraper& Reply 初始化回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipResonanceSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipWashSync
	* Description:    装备-->初始化洗练数据同步调用操作函数
	* Input:          EquipmentRpcEquipWashSyncAskWraper& Ask 初始化洗练数据请求
	* Output:         EquipmentRpcEquipWashSyncReplyWraper& Reply 初始化洗练数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipWashSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipWash
	* Description:    装备-->请求洗练同步调用操作函数
	* Input:          EquipmentRpcEquipWashAskWraper& Ask 请求洗练请求
	* Output:         EquipmentRpcEquipWashReplyWraper& Reply 请求洗练回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipWash( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipWashSave
	* Description:    装备-->保存同步调用操作函数
	* Input:          EquipmentRpcEquipWashSaveAskWraper& Ask 保存请求
	* Output:         EquipmentRpcEquipWashSaveReplyWraper& Reply 保存回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipWashSave( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipBuildSync
	* Description:    装备-->装备打造同步调用操作函数
	* Input:          EquipmentRpcEquipBuildSyncAskWraper& Ask 装备打造请求
	* Output:         EquipmentRpcEquipBuildSyncReplyWraper& Reply 装备打造回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipBuildSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipBuild
	* Description:    装备-->打造请求同步调用操作函数
	* Input:          EquipmentRpcEquipBuildAskWraper& Ask 打造请求请求
	* Output:         EquipmentRpcEquipBuildReplyWraper& Reply 打造请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipBuild( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetPlayerInfo
	* Description:    装备-->获取其他玩家信息同步调用操作函数
	* Input:          EquipmentRpcGetPlayerInfoAskWraper& Ask 获取其他玩家信息请求
	* Output:         EquipmentRpcGetPlayerInfoReplyWraper& Reply 获取其他玩家信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetPlayerInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEquipInherit
	* Description:    装备-->装备继承同步调用操作函数
	* Input:          EquipmentRpcEquipInheritAskWraper& Ask 装备继承请求
	* Output:         EquipmentRpcEquipInheritReplyWraper& Reply 装备继承回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEquipInherit( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif