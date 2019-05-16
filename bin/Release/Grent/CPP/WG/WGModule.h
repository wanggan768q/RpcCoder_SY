/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWG.h
* Author:       甘业清
* Description:  WG类，包含以下内容
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

#ifndef __MODULE_WG_H
#define __MODULE_WG_H


#include "ModuleBase.h"
#include "WGRpcWraper.h"




//WG实现类
class ModuleWG : public ModuleBase
{
	DECLARE_INSTANCE(ModuleWG);
public:
	friend class			ModuleMgr;

public:
	//WG实现类构造函数
	ModuleWG();
	
	//WG实现类析构函数
	virtual					~ModuleWG();

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
	* Function:       RpcInformJoinTeam
	* Description:    WG-->InformJoinTeam同步调用操作函数
	* Input:          WGRpcInformJoinTeamAskWraper& Ask InformJoinTeam请求
	* Output:         WGRpcInformJoinTeamReplyWraper& Reply InformJoinTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformJoinTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformLeave
	* Description:    WG-->InformLeave同步调用操作函数
	* Input:          WGRpcInformLeaveAskWraper& Ask InformLeave请求
	* Output:         WGRpcInformLeaveReplyWraper& Reply InformLeave回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformLeave( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformAppointTeamLeader
	* Description:    WG-->InformAppointTeamLeader同步调用操作函数
	* Input:          WGRpcInformAppointTeamLeaderAskWraper& Ask InformAppointTeamLeader请求
	* Output:         WGRpcInformAppointTeamLeaderReplyWraper& Reply InformAppointTeamLeader回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformKickTeamMember
	* Description:    WG-->InformKickTeamMember同步调用操作函数
	* Input:          WGRpcInformKickTeamMemberAskWraper& Ask InformKickTeamMember请求
	* Output:         WGRpcInformKickTeamMemberReplyWraper& Reply InformKickTeamMember回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformKickTeamMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformDissmissTeam
	* Description:    WG-->InformDissmissTeam同步调用操作函数
	* Input:          WGRpcInformDissmissTeamAskWraper& Ask InformDissmissTeam请求
	* Output:         WGRpcInformDissmissTeamReplyWraper& Reply InformDissmissTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformDissmissTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformApplyTeam
	* Description:    WG-->InformApply同步调用操作函数
	* Input:          WGRpcInformApplyTeamAskWraper& Ask InformApply请求
	* Output:         WGRpcInformApplyTeamReplyWraper& Reply InformApply回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformApplyTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAgreeTeamApplicant
	* Description:    WG-->AgreeTeamApplicant同步调用操作函数
	* Input:          WGRpcAgreeTeamApplicantAskWraper& Ask AgreeTeamApplicant请求
	* Output:         WGRpcAgreeTeamApplicantReplyWraper& Reply AgreeTeamApplicant回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeTeamApplicant( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformLogin
	* Description:    WG-->InformLogin同步调用操作函数
	* Input:          WGRpcInformLoginAskWraper& Ask InformLogin请求
	* Output:         WGRpcInformLoginReplyWraper& Reply InformLogin回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformLogin( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif