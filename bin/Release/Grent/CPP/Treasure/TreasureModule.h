/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTreasure.h
* Author:       甘业清
* Description:  珍宝阁类，包含以下内容
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

#ifndef __MODULE_TREASURE_H
#define __MODULE_TREASURE_H


#include "ModuleBase.h"
#include "TreasureRpcWraper.h"




//珍宝阁实现类
class ModuleTreasure : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTreasure);
public:
	friend class			ModuleMgr;

public:
	//珍宝阁实现类构造函数
	ModuleTreasure();
	
	//珍宝阁实现类析构函数
	virtual					~ModuleTreasure();

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
	* Function:       RpcTreasureDepotInfo
	* Description:    珍宝阁-->珍宝阁数据同步调用操作函数
	* Input:          TreasureRpcTreasureDepotInfoAskWraper& Ask 珍宝阁数据请求
	* Output:         TreasureRpcTreasureDepotInfoReplyWraper& Reply 珍宝阁数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureDepotInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureInfo
	* Description:    珍宝阁-->珍宝数据同步调用操作函数
	* Input:          TreasureRpcTreasureInfoAskWraper& Ask 珍宝数据请求
	* Output:         TreasureRpcTreasureInfoReplyWraper& Reply 珍宝数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureUnlock
	* Description:    珍宝阁-->珍宝解锁同步调用操作函数
	* Input:          TreasureRpcTreasureUnlockAskWraper& Ask 珍宝解锁请求
	* Output:         TreasureRpcTreasureUnlockReplyWraper& Reply 珍宝解锁回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureUnlock( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureEquip
	* Description:    珍宝阁-->珍宝穿戴同步调用操作函数
	* Input:          TreasureRpcTreasureEquipAskWraper& Ask 珍宝穿戴请求
	* Output:         TreasureRpcTreasureEquipReplyWraper& Reply 珍宝穿戴回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureEquip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureEquipSyc
	* Description:    珍宝阁-->穿戴的珍宝同步调用操作函数
	* Input:          TreasureRpcTreasureEquipSycAskWraper& Ask 穿戴的珍宝请求
	* Output:         TreasureRpcTreasureEquipSycReplyWraper& Reply 穿戴的珍宝回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureEquipSyc( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureDepotLvUp
	* Description:    珍宝阁-->珍宝阁升级同步调用操作函数
	* Input:          TreasureRpcTreasureDepotLvUpAskWraper& Ask 珍宝阁升级请求
	* Output:         TreasureRpcTreasureDepotLvUpReplyWraper& Reply 珍宝阁升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureDepotLvUp( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTreasureUnEquip
	* Description:    珍宝阁-->卸下珍宝同步调用操作函数
	* Input:          TreasureRpcTreasureUnEquipAskWraper& Ask 卸下珍宝请求
	* Output:         TreasureRpcTreasureUnEquipReplyWraper& Reply 卸下珍宝回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureUnEquip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientTreasureEquipedID
	* Description:    珍宝阁-->已装备时装ID异步通知操作函数
	* Input:          TreasureRpcTreasureEquipedIDNotifyWraper& Notify 已装备时装ID通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTreasureEquipedID( INT64 UserId, TreasureRpcTreasureEquipedIDNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcTreasureDelayTime
	* Description:    珍宝阁-->续期同步调用操作函数
	* Input:          TreasureRpcTreasureDelayTimeAskWraper& Ask 续期请求
	* Output:         TreasureRpcTreasureDelayTimeReplyWraper& Reply 续期回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTreasureDelayTime( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientTreasureUnlockEquip
	* Description:    珍宝阁-->解锁并穿戴异步通知操作函数
	* Input:          TreasureRpcTreasureUnlockEquipNotifyWraper& Notify 解锁并穿戴通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTreasureUnlockEquip( INT64 UserId, TreasureRpcTreasureUnlockEquipNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif