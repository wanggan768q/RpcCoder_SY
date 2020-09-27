/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleDungeon.h
* Author:       郭晓波
* Description:  副本类，包含以下内容
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

#ifndef __MODULE_DUNGEON_H
#define __MODULE_DUNGEON_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "DungeonRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//副本实现类
class ModuleDungeon
{
	
public:
	//副本类的枚举定义
	enum ConstDungeonE
	{
	MODULE_ID_DUNGEON                            = 6,	//副本模块ID
	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST       = 651,	//副本-->CreateDungeon-->请求
	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST         = 652,	//副本-->退出副本-->请求
	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST        = 653,	//副本-->进入副本通知-->请求
	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654,	//副本-->队长创建副本以后通知我-->请求
	RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY           = 655,	//副本-->Settlement-->通知
	RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY          = 656,	//副本-->战况信息-->通知
	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST         = 657,	//副本-->副本数据请求-->请求
	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST     = 658,	//副本-->副本挑战信息-->请求
	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST      = 659,	//副本-->创建序章副本-->请求
	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST        = 660,	//副本-->强制退出序章-->请求
	RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY        = 661,	//副本-->副本目标-->通知
	RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY  = 662,	//副本-->副本子任务完成情况-->通知
	RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY       = 663,	//副本-->副本提示-->通知
	RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST      = 664,	//副本-->场景操作1-->请求
	RPC_CODE_DUNGEON_FORCEENTERNEXTDUNGEONLAYER_NOTIFY= 665,	//副本-->强制进入下一层-->通知
	RPC_CODE_DUNGEON_DUNGEONREWARDUPDATE_NOTIFY  = 666,	//副本-->副本更新-->通知
	RPC_CODE_DUNGEON_VICTORYOFALLLAYER_NOTIFY    = 667,	//副本-->全部层胜利-->通知
	RPC_CODE_DUNGEON_LAYERBEGIN_NOTIFY           = 668,	//副本-->层数开始-->通知
	RPC_CODE_DUNGEON_LAYERSETTLEMENT_NOTIFY      = 669,	//副本-->当前层结算-->通知
	RPC_CODE_DUNGEON_SCENEOPERATORN_NOTIFY       = 670,	//副本-->场景操作通知-->通知
	RPC_CODE_DUNGEON_ENTERLAYERDUNGEON_NOTIFY    = 671,	//副本-->进入爬塔副本-->通知
	RPC_CODE_DUNGEON_DUNGEONEXPLOITS_NOTIFY      = 672,	//副本-->副本战绩数据-->通知
	RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST= 673,	//副本-->使用机器人组队进副本-->请求
	RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST          = 674,	//副本-->使用挑战次数-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//副本实现类构造函数
	ModuleDungeon()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, &ModuleDungeon::RpcCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, &ModuleDungeon::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, new Some_Factory<DungeonRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, &ModuleDungeon::RpcEnterDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, new Some_Factory<DungeonRpcEnterDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, &ModuleDungeon::RpcInformCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcInformCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, &ModuleDungeon::RpcDungeonSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, new Some_Factory<DungeonRpcDungeonSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, &ModuleDungeon::RpcDungeonListInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, new Some_Factory<DungeonRpcDungeonListInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, &ModuleDungeon::RpcCreateTutorial);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, new Some_Factory<DungeonRpcCreateTutorialAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, &ModuleDungeon::RpcQuitTutorial);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, new Some_Factory<DungeonRpcQuitTutorialAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST, &ModuleDungeon::RpcSceneOperator1);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST, new Some_Factory<DungeonRpcSceneOperator1Ask>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST, &ModuleDungeon::RpcCreateDungeonWithRobot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST, new Some_Factory<DungeonRpcCreateDungeonWithRobotAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST, &ModuleDungeon::RpcUseBossNum);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST, new Some_Factory<DungeonRpcUseBossNumAsk>());

	}
	
	//副本实现类析构函数
	~ModuleDungeon(){}


	static ModuleDungeon & Instance()
	{
		static ModuleDungeon sInstance;
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
	* Function:       RpcCreateDungeon
	* Description:    副本-->CreateDungeon同步调用操作函数
	* Input:          DungeonRpcCreateDungeonAskWraper& Ask CreateDungeon请求
	* Output:         DungeonRpcCreateDungeonReplyWraper& Reply CreateDungeon回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcExitDungeon
	* Description:    副本-->退出副本同步调用操作函数
	* Input:          DungeonRpcExitDungeonAskWraper& Ask 退出副本请求
	* Output:         DungeonRpcExitDungeonReplyWraper& Reply 退出副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcExitDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEnterDungeon
	* Description:    副本-->进入副本通知同步调用操作函数
	* Input:          DungeonRpcEnterDungeonAskWraper& Ask 进入副本通知请求
	* Output:         DungeonRpcEnterDungeonReplyWraper& Reply 进入副本通知回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformCreateDungeon
	* Description:    副本-->队长创建副本以后通知我同步调用操作函数
	* Input:          DungeonRpcInformCreateDungeonAskWraper& Ask 队长创建副本以后通知我请求
	* Output:         DungeonRpcInformCreateDungeonReplyWraper& Reply 队长创建副本以后通知我回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformCreateDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSettlement
	* Description:    副本-->Settlement异步通知操作函数
	* Input:          DungeonRpcSettlementNotifyWraper& Notify Settlement通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSettlement( INT64 UserId, DungeonRpcSettlementNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDungeonData
	* Description:    副本-->战况信息异步通知操作函数
	* Input:          DungeonRpcDungeonDataNotifyWraper& Notify 战况信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonData( INT64 UserId, DungeonRpcDungeonDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcDungeonSync
	* Description:    副本-->副本数据请求同步调用操作函数
	* Input:          DungeonRpcDungeonSyncAskWraper& Ask 副本数据请求请求
	* Output:         DungeonRpcDungeonSyncReplyWraper& Reply 副本数据请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDungeonSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDungeonListInfo
	* Description:    副本-->副本挑战信息同步调用操作函数
	* Input:          DungeonRpcDungeonListInfoAskWraper& Ask 副本挑战信息请求
	* Output:         DungeonRpcDungeonListInfoReplyWraper& Reply 副本挑战信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDungeonListInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateTutorial
	* Description:    副本-->创建序章副本同步调用操作函数
	* Input:          DungeonRpcCreateTutorialAskWraper& Ask 创建序章副本请求
	* Output:         DungeonRpcCreateTutorialReplyWraper& Reply 创建序章副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateTutorial( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcQuitTutorial
	* Description:    副本-->强制退出序章同步调用操作函数
	* Input:          DungeonRpcQuitTutorialAskWraper& Ask 强制退出序章请求
	* Output:         DungeonRpcQuitTutorialReplyWraper& Reply 强制退出序章回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcQuitTutorial( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDungeonTarget
	* Description:    副本-->副本目标异步通知操作函数
	* Input:          DungeonRpcDungeonTargetNotifyWraper& Notify 副本目标通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonTarget( INT64 UserId, DungeonRpcDungeonTargetNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTargetContentChange
	* Description:    副本-->副本子任务完成情况异步通知操作函数
	* Input:          DungeonRpcTargetContentChangeNotifyWraper& Notify 副本子任务完成情况通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTargetContentChange( INT64 UserId, DungeonRpcTargetContentChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDungeon_Notify
	* Description:    副本-->副本提示异步通知操作函数
	* Input:          DungeonRpcDungeon_NotifyNotifyWraper& Notify 副本提示通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeon_Notify( INT64 UserId, DungeonRpcDungeon_NotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSceneOperator1
	* Description:    副本-->场景操作1同步调用操作函数
	* Input:          DungeonRpcSceneOperator1AskWraper& Ask 场景操作1请求
	* Output:         DungeonRpcSceneOperator1ReplyWraper& Reply 场景操作1回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSceneOperator1( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientForceEnterNextDungeonLayer
	* Description:    副本-->强制进入下一层异步通知操作函数
	* Input:          DungeonRpcForceEnterNextDungeonLayerNotifyWraper& Notify 强制进入下一层通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientForceEnterNextDungeonLayer( INT64 UserId, DungeonRpcForceEnterNextDungeonLayerNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDungeonRewardUpdate
	* Description:    副本-->副本更新异步通知操作函数
	* Input:          DungeonRpcDungeonRewardUpdateNotifyWraper& Notify 副本更新通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonRewardUpdate( INT64 UserId, DungeonRpcDungeonRewardUpdateNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientVictoryOfAllLayer
	* Description:    副本-->全部层胜利异步通知操作函数
	* Input:          DungeonRpcVictoryOfAllLayerNotifyWraper& Notify 全部层胜利通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientVictoryOfAllLayer( INT64 UserId, DungeonRpcVictoryOfAllLayerNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLayerBegin
	* Description:    副本-->层数开始异步通知操作函数
	* Input:          DungeonRpcLayerBeginNotifyWraper& Notify 层数开始通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLayerBegin( INT64 UserId, DungeonRpcLayerBeginNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLayerSettlement
	* Description:    副本-->当前层结算异步通知操作函数
	* Input:          DungeonRpcLayerSettlementNotifyWraper& Notify 当前层结算通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLayerSettlement( INT64 UserId, DungeonRpcLayerSettlementNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSceneOperatorN
	* Description:    副本-->场景操作通知异步通知操作函数
	* Input:          DungeonRpcSceneOperatorNNotifyWraper& Notify 场景操作通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSceneOperatorN( INT64 UserId, DungeonRpcSceneOperatorNNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientEnterLayerDungeon
	* Description:    副本-->进入爬塔副本异步通知操作函数
	* Input:          DungeonRpcEnterLayerDungeonNotifyWraper& Notify 进入爬塔副本通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientEnterLayerDungeon( INT64 UserId, DungeonRpcEnterLayerDungeonNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDungeonExploits
	* Description:    副本-->副本战绩数据异步通知操作函数
	* Input:          DungeonRpcDungeonExploitsNotifyWraper& Notify 副本战绩数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonExploits( INT64 UserId, DungeonRpcDungeonExploitsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCreateDungeonWithRobot
	* Description:    副本-->使用机器人组队进副本同步调用操作函数
	* Input:          DungeonRpcCreateDungeonWithRobotAskWraper& Ask 使用机器人组队进副本请求
	* Output:         DungeonRpcCreateDungeonWithRobotReplyWraper& Reply 使用机器人组队进副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateDungeonWithRobot( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUseBossNum
	* Description:    副本-->使用挑战次数同步调用操作函数
	* Input:          DungeonRpcUseBossNumAskWraper& Ask 使用挑战次数请求
	* Output:         DungeonRpcUseBossNumReplyWraper& Reply 使用挑战次数回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUseBossNum( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif