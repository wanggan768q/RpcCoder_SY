/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleScene.h
* Author:       甘业清
* Description:  场景模块类，包含以下内容
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

#ifndef __MODULE_SCENE_H
#define __MODULE_SCENE_H


#include "ModuleBase.h"
#include "SceneRpcWraper.h"




//场景模块实现类
class ModuleScene : public ModuleBase
{
	DECLARE_INSTANCE(ModuleScene);
public:
	friend class			ModuleMgr;

public:
	//场景模块实现类构造函数
	ModuleScene();
	
	//场景模块实现类析构函数
	virtual					~ModuleScene();

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
	* Function:       RpcLoadSceneComplete
	* Description:    场景模块-->进入场景完成同步调用操作函数
	* Input:          SceneRpcLoadSceneCompleteAskWraper& Ask 进入场景完成请求
	* Output:         SceneRpcLoadSceneCompleteReplyWraper& Reply 进入场景完成回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLoadSceneComplete( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDeletePlayer
	* Description:    场景模块-->玩家离开视野异步通知操作函数
	* Input:          SceneRpcDeletePlayerNotifyWraper& Notify 删除玩家通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDeletePlayer( INT64 UserId, SceneRpcDeletePlayerNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcConnectGameServer
	* Description:    场景模块-->连接场景服务器同步调用操作函数
	* Input:          SceneRpcConnectGameServerAskWraper& Ask 连接场景服务器请求
	* Output:         SceneRpcConnectGameServerReplyWraper& Reply 连接场景服务器回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcConnectGameServer( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCreateObj
	* Description:    场景模块-->创建物体异步通知操作函数
	* Input:          SceneRpcCreateObjNotifyWraper& Notify 创建物体通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCreateObj( INT64 UserId, SceneRpcCreateObjNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSurroundingHuman
	* Description:    场景模块-->SurroundingHuman同步调用操作函数
	* Input:          SceneRpcSurroundingHumanAskWraper& Ask SurroundingHuman请求
	* Output:         SceneRpcSurroundingHumanReplyWraper& Reply SurroundingHuman回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSurroundingHuman( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCEnterScene
	* Description:    场景模块-->进入场景异步通知操作函数
	* Input:          SceneRpcCEnterSceneNotifyWraper& Notify 进入场景通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcCEnterScene(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSEnterScene
	* Description:    场景模块-->进入场景返回异步通知操作函数
	* Input:          SceneRpcSEnterSceneNotifyWraper& Notify 进入场景返回通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSEnterScene( INT64 UserId, SceneRpcSEnterSceneNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientObjDie
	* Description:    场景模块-->ObjDie异步通知操作函数
	* Input:          SceneRpcObjDieNotifyWraper& Notify ObjDie通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjDie( INT64 UserId, SceneRpcObjDieNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCollide_ChangeScene
	* Description:    场景模块-->collide 场景切换同步调用操作函数
	* Input:          SceneRpcCollide_ChangeSceneAskWraper& Ask collide请求
	* Output:         SceneRpcCollide_ChangeSceneReplyWraper& Reply collide回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCollide_ChangeScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEnterMirror
	* Description:    场景模块-->进入镜像同步调用操作函数
	* Input:          SceneRpcEnterMirrorAskWraper& Ask 进入镜像请求
	* Output:         SceneRpcEnterMirrorReplyWraper& Reply 进入镜像回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterMirror( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSEnterMirrorScene
	* Description:    场景模块-->进入镜像场景异步通知操作函数
	* Input:          SceneRpcSEnterMirrorSceneNotifyWraper& Notify 进入镜像场景通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSEnterMirrorScene( INT64 UserId, SceneRpcSEnterMirrorSceneNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcExitMirrorScene
	* Description:    场景模块-->退出镜像同步调用操作函数
	* Input:          SceneRpcExitMirrorSceneAskWraper& Ask 退出镜像请求
	* Output:         SceneRpcExitMirrorSceneReplyWraper& Reply 退出镜像回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcExitMirrorScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeSceneLeave
	* Description:    场景模块-->ChangeSceneLeave异步通知操作函数
	* Input:          SceneRpcChangeSceneLeaveNotifyWraper& Notify ChangeSceneLeave通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeSceneLeave( INT64 UserId, SceneRpcChangeSceneLeaveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeLine
	* Description:    场景模块-->ChangeLine同步调用操作函数
	* Input:          SceneRpcChangeLineAskWraper& Ask ChangeLine请求
	* Output:         SceneRpcChangeLineReplyWraper& Reply ChangeLine回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeLine( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcPing
	* Description:    场景模块-->ping同步调用操作函数
	* Input:          SceneRpcPingAskWraper& Ask ping请求
	* Output:         SceneRpcPingReplyWraper& Reply ping回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPing( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSyncSceneLineStats
	* Description:    场景模块-->同步场景分线繁忙状态异步通知操作函数
	* Input:          SceneRpcSyncSceneLineStatsNotifyWraper& Notify 同步场景分线繁忙状态通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSyncSceneLineStats( INT64 UserId, SceneRpcSyncSceneLineStatsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcLogOutGame
	* Description:    场景模块-->离开GameServer同步调用操作函数
	* Input:          SceneRpcLogOutGameAskWraper& Ask 离开GameServer请求
	* Output:         SceneRpcLogOutGameReplyWraper& Reply 离开GameServer回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogOutGame( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientKickOutGame
	* Description:    场景模块-->被提出场景异步通知操作函数
	* Input:          SceneRpcKickOutGameNotifyWraper& Notify 被提出场景通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKickOutGame( INT64 UserId, SceneRpcKickOutGameNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcShowFilmFinish
	* Description:    场景模块-->前端通知后端剧情动画播放完毕同步调用操作函数
	* Input:          SceneRpcShowFilmFinishAskWraper& Ask 前端通知后端剧情动画播放完毕请求
	* Output:         SceneRpcShowFilmFinishReplyWraper& Reply 前端通知后端剧情动画播放完毕回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcShowFilmFinish( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSpecObjPos
	* Description:    场景模块-->SpecObjPos同步调用操作函数
	* Input:          SceneRpcSpecObjPosAskWraper& Ask SpecObjPos请求
	* Output:         SceneRpcSpecObjPosReplyWraper& Reply SpecObjPos回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSpecObjPos( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif