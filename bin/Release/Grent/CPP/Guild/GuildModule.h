/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGuild.h
* Author:       甘业清
* Description:  公会类，包含以下内容
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

#ifndef __MODULE_GUILD_H
#define __MODULE_GUILD_H


#include "ModuleBase.h"
#include "GuildRpcWraper.h"




//公会实现类
class ModuleGuild : public ModuleBase
{
	DECLARE_INSTANCE(ModuleGuild);
public:
	friend class			ModuleMgr;

public:
	//公会实现类构造函数
	ModuleGuild();
	
	//公会实现类析构函数
	virtual					~ModuleGuild();

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
	* Function:       RpcGuildBaseInfo
	* Description:    公会-->公会基本信息同步调用操作函数
	* Input:          GuildRpcGuildBaseInfoAskWraper& Ask 公会基本信息请求
	* Output:         GuildRpcGuildBaseInfoReplyWraper& Reply 公会基本信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGuildBaseInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcKickMember
	* Description:    公会-->逐出成员同步调用操作函数
	* Input:          GuildRpcKickMemberAskWraper& Ask 逐出成员请求
	* Output:         GuildRpcKickMemberReplyWraper& Reply 逐出成员回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcKickMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientKickMemberNotify
	* Description:    公会-->逐出公会推送异步通知操作函数
	* Input:          GuildRpcKickMemberNotifyNotifyWraper& Notify 逐出公会推送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKickMemberNotify( INT64 UserId, GuildRpcKickMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAskVacation
	* Description:    公会-->请假或取消申请同步调用操作函数
	* Input:          GuildRpcAskVacationAskWraper& Ask 请假或取消请求
	* Output:         GuildRpcAskVacationReplyWraper& Reply 请假或取消回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskVacation( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientVacation
	* Description:    公会-->请假广播（广播给管理者）异步通知操作函数
	* Input:          GuildRpcVacationNotifyWraper& Notify 请假广播通知（广播给管理者）
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientVacation( INT64 UserId, GuildRpcVacationNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientReplyVacation
	* Description:    公会-->请假广播（广播给请假人）异步通知操作函数
	* Input:          GuildRpcReplyVacationNotifyWraper& Notify 请假广播（广播给请假人）通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReplyVacation( INT64 UserId, GuildRpcReplyVacationNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAskApplyList
	* Description:    公会-->请求公会申请列表同步调用操作函数
	* Input:          GuildRpcAskApplyListAskWraper& Ask 请求公会申请列表请求
	* Output:         GuildRpcAskApplyListReplyWraper& Reply 请求公会申请列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskApplyList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcApplyGuildOperation
	* Description:    公会-->入会操作同步调用操作函数
	* Input:          GuildRpcApplyGuildOperationAskWraper& Ask 入会操作请求
	* Output:         GuildRpcApplyGuildOperationReplyWraper& Reply 入会操作回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcApplyGuildOperation( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientApplyGuild
	* Description:    公会-->申请入会推送（推送给申请者）异步通知操作函数
	* Input:          GuildRpcApplyGuildNotifyWraper& Notify 申请入会推送（推送给申请者）通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyGuild( INT64 UserId, GuildRpcApplyGuildNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcApplyLimitSetting
	* Description:    公会-->限制入会条件同步调用操作函数
	* Input:          GuildRpcApplyLimitSettingAskWraper& Ask 限制入会条件请求
	* Output:         GuildRpcApplyLimitSettingReplyWraper& Reply 限制入会条件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcApplyLimitSetting( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAskJurisdictionList
	* Description:    公会-->权限列表申请同步调用操作函数
	* Input:          GuildRpcAskJurisdictionListAskWraper& Ask 权限列表申请请求
	* Output:         GuildRpcAskJurisdictionListReplyWraper& Reply 权限列表申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskJurisdictionList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSetJurisdiction
	* Description:    公会-->设置权限同步调用操作函数
	* Input:          GuildRpcSetJurisdictionAskWraper& Ask 设置权限请求
	* Output:         GuildRpcSetJurisdictionReplyWraper& Reply 设置权限回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSetJurisdiction( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAskVacationList
	* Description:    公会-->请假审批列表同步调用操作函数
	* Input:          GuildRpcAskVacationListAskWraper& Ask 请假审批列表请求
	* Output:         GuildRpcAskVacationListReplyWraper& Reply 请假审批列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskVacationList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcVacationGuildOperation
	* Description:    公会-->请假操作同步调用操作函数
	* Input:          GuildRpcVacationGuildOperationAskWraper& Ask 请假操作请求
	* Output:         GuildRpcVacationGuildOperationReplyWraper& Reply 请假操作回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcVacationGuildOperation( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientApplyGuildToOffice
	* Description:    公会-->申请推送（广播给管理者）异步通知操作函数
	* Input:          GuildRpcApplyGuildToOfficeNotifyWraper& Notify 申请推送（广播给管理者）通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyGuildToOffice( INT64 UserId, GuildRpcApplyGuildToOfficeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAskBuildingInfo
	* Description:    公会-->请求公会建筑信息同步调用操作函数
	* Input:          GuildRpcAskBuildingInfoAskWraper& Ask 请求公会建筑信息请求
	* Output:         GuildRpcAskBuildingInfoReplyWraper& Reply 请求公会建筑信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskBuildingInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuildingLvUp
	* Description:    公会-->公会建筑升级同步调用操作函数
	* Input:          GuildRpcBuildingLvUpAskWraper& Ask 公会建筑升级请求
	* Output:         GuildRpcBuildingLvUpReplyWraper& Reply 公会建筑升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuildingLvUp( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuildingLvSpeedUp
	* Description:    公会-->公会建筑加速升级同步调用操作函数
	* Input:          GuildRpcBuildingLvSpeedUpAskWraper& Ask 公会建筑加速升级请求
	* Output:         GuildRpcBuildingLvSpeedUpReplyWraper& Reply 公会建筑加速升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuildingLvSpeedUp( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAskBuildingContributionList
	* Description:    公会-->建筑贡献榜请求同步调用操作函数
	* Input:          GuildRpcAskBuildingContributionListAskWraper& Ask 建筑贡献榜请求请求
	* Output:         GuildRpcAskBuildingContributionListReplyWraper& Reply 建筑贡献榜请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskBuildingContributionList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientBuildingCanLvUp
	* Description:    公会-->建筑可升级推送（推送管理者）异步通知操作函数
	* Input:          GuildRpcBuildingCanLvUpNotifyWraper& Notify 建筑可升级推送（推送管理者）通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBuildingCanLvUp( INT64 UserId, GuildRpcBuildingCanLvUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAskGuildEventList
	* Description:    公会-->获取公会事件列表同步调用操作函数
	* Input:          GuildRpcAskGuildEventListAskWraper& Ask 获取公会事件列表请求
	* Output:         GuildRpcAskGuildEventListReplyWraper& Reply 获取公会事件列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskGuildEventList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAskGuildInfoList
	* Description:    公会-->获取公会列表同步调用操作函数
	* Input:          GuildRpcAskGuildInfoListAskWraper& Ask 获取公会列表请求
	* Output:         GuildRpcAskGuildInfoListReplyWraper& Reply 获取公会列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskGuildInfoList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSearchGuild
	* Description:    公会-->搜索公会同步调用操作函数
	* Input:          GuildRpcSearchGuildAskWraper& Ask 搜索公会请求
	* Output:         GuildRpcSearchGuildReplyWraper& Reply 搜索公会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSearchGuild( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcJoinGuild
	* Description:    公会-->申请入会同步调用操作函数
	* Input:          GuildRpcJoinGuildAskWraper& Ask 申请入会请求
	* Output:         GuildRpcJoinGuildReplyWraper& Reply 申请入会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcJoinGuild( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateGuild
	* Description:    公会-->建立公会同步调用操作函数
	* Input:          GuildRpcCreateGuildAskWraper& Ask 建立公会请求
	* Output:         GuildRpcCreateGuildReplyWraper& Reply 建立公会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateGuild( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChangeFlag
	* Description:    公会-->更换公会旗帜同步调用操作函数
	* Input:          GuildRpcChangeFlagAskWraper& Ask 更换公会旗帜请求
	* Output:         GuildRpcChangeFlagReplyWraper& Reply 更换公会旗帜回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeFlag( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGuildChangeName
	* Description:    公会-->公会改名同步调用操作函数
	* Input:          GuildRpcGuildChangeNameAskWraper& Ask 公会改名请求
	* Output:         GuildRpcGuildChangeNameReplyWraper& Reply 公会改名回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGuildChangeName( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAskGuildMember
	* Description:    公会-->获取公会成员列表同步调用操作函数
	* Input:          GuildRpcAskGuildMemberAskWraper& Ask 获取公会成员列表请求
	* Output:         GuildRpcAskGuildMemberReplyWraper& Reply 获取公会成员列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAskGuildMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcQuiteGuild
	* Description:    公会-->退出公会同步调用操作函数
	* Input:          GuildRpcQuiteGuildAskWraper& Ask 退出公会请求
	* Output:         GuildRpcQuiteGuildReplyWraper& Reply 退出公会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcQuiteGuild( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSetOffice
	* Description:    公会-->设置职位同步调用操作函数
	* Input:          GuildRpcSetOfficeAskWraper& Ask 设置职位请求
	* Output:         GuildRpcSetOfficeReplyWraper& Reply 设置职位回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSetOffice( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientOfficeChange
	* Description:    公会-->职位变化推送异步通知操作函数
	* Input:          GuildRpcOfficeChangeNotifyWraper& Notify 职位变化推送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOfficeChange( INT64 UserId, GuildRpcOfficeChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeCreed
	* Description:    公会-->修改帮会宗旨同步调用操作函数
	* Input:          GuildRpcChangeCreedAskWraper& Ask 修改帮会宗旨请求
	* Output:         GuildRpcChangeCreedReplyWraper& Reply 修改帮会宗旨回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeCreed( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcForbiddenChat
	* Description:    公会-->公会禁言同步调用操作函数
	* Input:          GuildRpcForbiddenChatAskWraper& Ask 公会禁言请求
	* Output:         GuildRpcForbiddenChatReplyWraper& Reply 公会禁言回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcForbiddenChat( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientBuildLvUpComplete
	* Description:    公会-->建筑升级完成异步通知操作函数
	* Input:          GuildRpcBuildLvUpCompleteNotifyWraper& Notify 建筑升级完成通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBuildLvUpComplete( INT64 UserId, GuildRpcBuildLvUpCompleteNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientGuildCurrencyChange
	* Description:    公会-->公会货币变化推送异步通知操作函数
	* Input:          GuildRpcGuildCurrencyChangeNotifyWraper& Notify 公会货币变化推送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientGuildCurrencyChange( INT64 UserId, GuildRpcGuildCurrencyChangeNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif