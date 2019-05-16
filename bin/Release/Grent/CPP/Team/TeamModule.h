/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.h
* Author:       甘业清
* Description:  Team类，包含以下内容
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

#ifndef __MODULE_TEAM_H
#define __MODULE_TEAM_H


#include "ModuleBase.h"
#include "TeamRpcWraper.h"




//Team实现类
class ModuleTeam : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTeam);
public:
	friend class			ModuleMgr;

public:
	//Team实现类构造函数
	ModuleTeam();
	
	//Team实现类析构函数
	virtual					~ModuleTeam();

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
	* Function:       RpcLeaveTeam
	* Description:    Team-->LeaveTeam同步调用操作函数
	* Input:          TeamRpcLeaveTeamAskWraper& Ask LeaveTeam请求
	* Output:         TeamRpcLeaveTeamReplyWraper& Reply LeaveTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLeaveTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAppointTeamLeader
	* Description:    Team-->AppointTeamLeader同步调用操作函数
	* Input:          TeamRpcAppointTeamLeaderAskWraper& Ask AppointTeamLeader请求
	* Output:         TeamRpcAppointTeamLeaderReplyWraper& Reply AppointTeamLeader回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateTeam
	* Description:    Team-->CreateTeam同步调用操作函数
	* Input:          TeamRpcCreateTeamAskWraper& Ask 创建队伍创建副本请求
	* Output:         TeamRpcCreateTeamReplyWraper& Reply 创建队伍创建副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDissmissTeam
	* Description:    Team-->DissmissTeam同步调用操作函数
	* Input:          TeamRpcDissmissTeamAskWraper& Ask DissmissTeam请求
	* Output:         TeamRpcDissmissTeamReplyWraper& Reply DissmissTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDissmissTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewLeader
	* Description:    Team-->NewLeader异步通知操作函数
	* Input:          TeamRpcNewLeaderNotifyWraper& Notify NewLeader通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewLeader( INT64 UserId, TeamRpcNewLeaderNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcKickMember
	* Description:    Team-->KickMember同步调用操作函数
	* Input:          TeamRpcKickMemberAskWraper& Ask KickMember请求
	* Output:         TeamRpcKickMemberReplyWraper& Reply KickMember回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcKickMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDissmissTeamNotify
	* Description:    Team-->DissmissTeamNotify异步通知操作函数
	* Input:          TeamRpcDissmissTeamNotifyNotifyWraper& Notify DissmissTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDissmissTeamNotify( INT64 UserId, TeamRpcDissmissTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientJoinTeamNotify
	* Description:    Team-->JoinTeamNotify异步通知操作函数
	* Input:          TeamRpcJoinTeamNotifyNotifyWraper& Notify JoinTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientJoinTeamNotify( INT64 UserId, TeamRpcJoinTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientKickMemberNotify
	* Description:    Team-->KickMemberNotify异步通知操作函数
	* Input:          TeamRpcKickMemberNotifyNotifyWraper& Notify KickMemberNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKickMemberNotify( INT64 UserId, TeamRpcKickMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLeaveTeamNotify
	* Description:    Team-->LeaveTeam异步通知操作函数
	* Input:          TeamRpcLeaveTeamNotifyNotifyWraper& Notify LeaveTeam通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLeaveTeamNotify( INT64 UserId, TeamRpcLeaveTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSurroundingTeam
	* Description:    Team-->SurroundingTeam同步调用操作函数
	* Input:          TeamRpcSurroundingTeamAskWraper& Ask SurroundingTeam请求
	* Output:         TeamRpcSurroundingTeamReplyWraper& Reply SurroundingTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSurroundingTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcApplyTeam
	* Description:    Team-->ApplyTeam同步调用操作函数
	* Input:          TeamRpcApplyTeamAskWraper& Ask ApplyTeam请求
	* Output:         TeamRpcApplyTeamReplyWraper& Reply ApplyTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcApplyTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientApplyTeamNotify
	* Description:    Team-->ApplyTeamNotify异步通知操作函数
	* Input:          TeamRpcApplyTeamNotifyNotifyWraper& Notify ApplyTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyTeamNotify( INT64 UserId, TeamRpcApplyTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAgreeApplicant
	* Description:    Team-->AgreeApplicant同步调用操作函数
	* Input:          TeamRpcAgreeApplicantAskWraper& Ask AgreeApplicant请求
	* Output:         TeamRpcAgreeApplicantReplyWraper& Reply AgreeApplicant回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeApplicant( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientAgreeApplicantNotify
	* Description:    Team-->AgreeApplicantNotify异步通知操作函数
	* Input:          TeamRpcAgreeApplicantNotifyNotifyWraper& Notify AgreeApplicantNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAgreeApplicantNotify( INT64 UserId, TeamRpcAgreeApplicantNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTeamInfo
	* Description:    Team-->TeamInfo异步通知操作函数
	* Input:          TeamRpcTeamInfoNotifyWraper& Notify TeamInfo通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTeamInfo( INT64 UserId, TeamRpcTeamInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateTeamMemInfo
	* Description:    Team-->UpdateTeamMemInfo异步通知操作函数
	* Input:          TeamRpcUpdateTeamMemInfoNotifyWraper& Notify UpdateTeamMemInfo通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateTeamMemInfo( INT64 UserId, TeamRpcUpdateTeamMemInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcFollowTeamLeader
	* Description:    Team-->跟随队长同步调用操作函数
	* Input:          TeamRpcFollowTeamLeaderAskWraper& Ask 跟随队长请求
	* Output:         TeamRpcFollowTeamLeaderReplyWraper& Reply 跟随队长回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcFollowTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSummonMember
	* Description:    Team-->召唤队员同步调用操作函数
	* Input:          TeamRpcSummonMemberAskWraper& Ask 召唤队员请求
	* Output:         TeamRpcSummonMemberReplyWraper& Reply 召唤队员回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSummonMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSummonMemberNotify
	* Description:    Team-->召唤队员异步通知操作函数
	* Input:          TeamRpcSummonMemberNotifyNotifyWraper& Notify 召唤队员通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSummonMemberNotify( INT64 UserId, TeamRpcSummonMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeTeamTarget
	* Description:    Team-->改变队伍目标同步调用操作函数
	* Input:          TeamRpcChangeTeamTargetAskWraper& Ask 改变队伍目标
	* Output:         TeamRpcChangeTeamTargetReplyWraper& Reply 改变队伍目标
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeTeamTarget( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeTeamTargetNotify
	* Description:    Team-->设置服务器目标异步通知操作函数
	* Input:          TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify 设置服务器目标通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeTeamTargetNotify( INT64 UserId, TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangTeamType
	* Description:    Team-->转换队伍团队同步调用操作函数
	* Input:          TeamRpcChangTeamTypeAskWraper& Ask 转换队伍团队请求
	* Output:         TeamRpcChangTeamTypeReplyWraper& Reply 转换队伍团队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangTeamType( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeTeamTypeNotify
	* Description:    Team-->转换队伍团队协议异步通知操作函数
	* Input:          TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify 转换队伍团队协议通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeTeamTypeNotify( INT64 UserId, TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcInviteTeamMember
	* Description:    Team-->邀请玩家同步调用操作函数
	* Input:          TeamRpcInviteTeamMemberAskWraper& Ask 邀请玩家请求
	* Output:         TeamRpcInviteTeamMemberReplyWraper& Reply 邀请玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInviteTeamMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientInviteTeamMemberNotify
	* Description:    Team-->邀请玩家广播异步通知操作函数
	* Input:          TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify 邀请玩家广播通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientInviteTeamMemberNotify( INT64 UserId, TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientApplyListNotify
	* Description:    Team-->列表通知异步通知操作函数
	* Input:          TeamRpcApplyListNotifyNotifyWraper& Notify 列表通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyListNotify( INT64 UserId, TeamRpcApplyListNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAgreeJoinTeam
	* Description:    Team-->AgreeJoinTeam同步调用操作函数
	* Input:          TeamRpcAgreeJoinTeamAskWraper& Ask AgreeJoinTeam请求
	* Output:         TeamRpcAgreeJoinTeamReplyWraper& Reply AgreeJoinTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeJoinTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRefuseMember
	* Description:    Team-->拒绝申请同步调用操作函数
	* Input:          TeamRpcRefuseMemberAskWraper& Ask 拒绝申请请求
	* Output:         TeamRpcRefuseMemberReplyWraper& Reply 拒绝申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRefuseMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcClearApplyList
	* Description:    Team-->清空申请列表同步调用操作函数
	* Input:          TeamRpcClearApplyListAskWraper& Ask 清空申请列表请求
	* Output:         TeamRpcClearApplyListReplyWraper& Reply 清空申请列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcClearApplyList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcNoTeamInvite
	* Description:    Team-->没有队伍邀请玩家同步调用操作函数
	* Input:          TeamRpcNoTeamInviteAskWraper& Ask 没有队伍邀请玩家请求
	* Output:         TeamRpcNoTeamInviteReplyWraper& Reply 没有队伍邀请玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcNoTeamInvite( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRejectInvite
	* Description:    Team-->拒绝邀请同步调用操作函数
	* Input:          TeamRpcRejectInviteAskWraper& Ask 拒绝邀请请求
	* Output:         TeamRpcRejectInviteReplyWraper& Reply 拒绝邀请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRejectInvite( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif