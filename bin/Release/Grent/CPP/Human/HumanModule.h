/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleHuman.h
* Author:       甘业清
* Description:  玩家模块类，包含以下内容
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

#ifndef __MODULE_HUMAN_H
#define __MODULE_HUMAN_H


#include "ModuleBase.h"
#include "HumanRpcWraper.h"




//玩家模块实现类
class ModuleHuman : public ModuleBase
{
	DECLARE_INSTANCE(ModuleHuman);
public:
	friend class			ModuleMgr;

public:
	//玩家模块实现类构造函数
	ModuleHuman();
	
	//玩家模块实现类析构函数
	virtual					~ModuleHuman();

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
	* Function:       RpcMove
	* Description:    玩家模块-->human move同步调用操作函数
	* Input:          HumanRpcMoveAskWraper& Ask human move请求
	* Output:         HumanRpcMoveReplyWraper& Reply human move回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMove( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcStopMove
	* Description:    玩家模块-->客户端停止移动同步调用操作函数
	* Input:          HumanRpcStopMoveAskWraper& Ask 客户端停止移动请求
	* Output:         HumanRpcStopMoveReplyWraper& Reply 客户端停止移动回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcStopMove( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMoveCheck
	* Description:    玩家模块-->移动检测异步通知操作函数
	* Input:          HumanRpcMoveCheckNotifyWraper& Notify 移动检测通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcMoveCheck(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientMoveCheck
	* Description:    玩家模块-->移动检测异步通知操作函数
	* Input:          HumanRpcMoveCheckNotifyWraper& Notify 移动检测通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMoveCheck( INT64 UserId, HumanRpcMoveCheckNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcRespawn
	* Description:    玩家模块-->复活同步调用操作函数
	* Input:          HumanRpcRespawnAskWraper& Ask Respawn请求
	* Output:         HumanRpcRespawnReplyWraper& Reply Respawn回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRespawn( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRespawnOther
	* Description:    玩家模块-->复活其他玩家通知异步通知操作函数
	* Input:          HumanRpcRespawnOtherNotifyWraper& Notify 复活其他玩家通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRespawnOther( INT64 UserId, HumanRpcRespawnOtherNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcMovePos
	* Description:    玩家模块-->MovePos同步调用操作函数
	* Input:          HumanRpcMovePosAskWraper& Ask MovePos请求
	* Output:         HumanRpcMovePosReplyWraper& Reply MovePos回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMovePos( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRoleDie
	* Description:    玩家模块-->死亡通知异步通知操作函数
	* Input:          HumanRpcRoleDieNotifyWraper& Notify 死亡通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRoleDie( INT64 UserId, HumanRpcRoleDieNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeAnimationState
	* Description:    玩家模块-->改变动画状态 纯客户端异步通知操作函数
	* Input:          HumanRpcChangeAnimationStateNotifyWraper& Notify 改变动画状态 纯客户端通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcChangeAnimationState(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcFuncNotice
	* Description:    玩家模块-->玩家功能预告同步调用操作函数
	* Input:          HumanRpcFuncNoticeAskWraper& Ask 玩家功能预告请求
	* Output:         HumanRpcFuncNoticeReplyWraper& Reply 玩家功能预告回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcFuncNotice( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcFuncNoticeChange
	* Description:    玩家模块-->玩家功能预告同步调用操作函数
	* Input:          HumanRpcFuncNoticeChangeAskWraper& Ask 玩家功能预告请求
	* Output:         HumanRpcFuncNoticeChangeReplyWraper& Reply 玩家功能预告回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcFuncNoticeChange( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcClientAttributes
	* Description:    玩家模块-->客户端属性双向通知异步通知操作函数
	* Input:          HumanRpcClientAttributesNotifyWraper& Notify 客户端属性双向通知通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcClientAttributes(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientClientAttributes
	* Description:    玩家模块-->客户端属性双向通知异步通知操作函数
	* Input:          HumanRpcClientAttributesNotifyWraper& Notify 客户端属性双向通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientClientAttributes( INT64 UserId, HumanRpcClientAttributesNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif