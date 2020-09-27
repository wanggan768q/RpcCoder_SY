/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleHuman.h
* Author:       郭晓波
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


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "HumanRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//玩家模块实现类
class ModuleHuman
{
	
public:
	//玩家模块类的枚举定义
	enum ConstHumanE
	{
	MODULE_ID_HUMAN                              = 4,	//玩家模块模块ID
	RPC_CODE_HUMAN_MOVE_REQUEST                  = 451,	//玩家模块-->human move-->请求
	RPC_CODE_HUMAN_STOPMOVE_REQUEST              = 452,	//玩家模块-->客户端停止移动-->请求
	RPC_CODE_HUMAN_MOVECHECK_NOTIFY              = 453,	//玩家模块-->移动检测-->通知
	RPC_CODE_HUMAN_RESPAWN_REQUEST               = 454,	//玩家模块-->复活-->请求
	RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY           = 455,	//玩家模块-->复活其他玩家通知-->通知
	RPC_CODE_HUMAN_MOVEPOS_REQUEST               = 456,	//玩家模块-->MovePos-->请求
	RPC_CODE_HUMAN_ROLEDIE_NOTIFY                = 457,	//玩家模块-->死亡通知-->通知
	RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY   = 458,	//玩家模块-->改变动画状态 纯客户端-->通知
	RPC_CODE_HUMAN_FUNCNOTICE_REQUEST            = 459,	//玩家模块-->玩家功能预告-->请求
	RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST      = 460,	//玩家模块-->玩家功能预告-->请求
	RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY       = 461,	//玩家模块-->客户端属性双向通知-->通知
	RPC_CODE_HUMAN_TIMECHECK_NOTIFY              = 462,	//玩家模块-->加速检测-->通知
	RPC_CODE_HUMAN_MOTIONFLAGS_NOTIFY            = 463,	//玩家模块-->移动标志刷新-->通知
	RPC_CODE_HUMAN_RUSH_REQUEST                  = 464,	//玩家模块-->疾跑-->请求
	RPC_CODE_HUMAN_STARE_REQUEST                 = 465,	//玩家模块-->盯防-->请求
	RPC_CODE_HUMAN_CHANGEPOSITION_NOTIFY         = 466,	//玩家模块-->瞬移-->通知
	RPC_CODE_HUMAN_ATTRCHANGE_NOTIFY             = 467,	//玩家模块-->属性变化值-->通知
	RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST           = 468,	//玩家模块-->托管-->请求
	RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST      = 469,	//玩家模块-->改名-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//玩家模块实现类构造函数
	ModuleHuman()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVE_REQUEST, &ModuleHuman::RpcMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVE_REQUEST, new Some_Factory<HumanRpcMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, &ModuleHuman::RpcStopMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, new Some_Factory<HumanRpcStopMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVECHECK_NOTIFY, &ModuleHuman::RpcMoveCheck);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVECHECK_NOTIFY, new Some_Factory<HumanRpcMoveCheckNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_RESPAWN_REQUEST, &ModuleHuman::RpcRespawn);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_RESPAWN_REQUEST, new Some_Factory<HumanRpcRespawnAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVEPOS_REQUEST, &ModuleHuman::RpcMovePos);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVEPOS_REQUEST, new Some_Factory<HumanRpcMovePosAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY, &ModuleHuman::RpcChangeAnimationState);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY, new Some_Factory<HumanRpcChangeAnimationStateNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, &ModuleHuman::RpcFuncNotice);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, new Some_Factory<HumanRpcFuncNoticeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, &ModuleHuman::RpcFuncNoticeChange);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, new Some_Factory<HumanRpcFuncNoticeChangeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, &ModuleHuman::RpcClientAttributes);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, new Some_Factory<HumanRpcClientAttributesNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_TIMECHECK_NOTIFY, &ModuleHuman::RpcTimeCheck);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_TIMECHECK_NOTIFY, new Some_Factory<HumanRpcTimeCheckNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_RUSH_REQUEST, &ModuleHuman::RpcRush);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_RUSH_REQUEST, new Some_Factory<HumanRpcRushAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_STARE_REQUEST, &ModuleHuman::RpcStare);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_STARE_REQUEST, new Some_Factory<HumanRpcStareAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST, &ModuleHuman::RpcTrusteeship);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST, new Some_Factory<HumanRpcTrusteeshipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST, &ModuleHuman::RpcChangePlayerName);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST, new Some_Factory<HumanRpcChangePlayerNameAsk>());

	}
	
	//玩家模块实现类析构函数
	~ModuleHuman(){}


	static ModuleHuman & Instance()
	{
		static ModuleHuman sInstance;
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

	/********************************************************************************************
	* Function:       RpcTimeCheck
	* Description:    玩家模块-->加速检测异步通知操作函数
	* Input:          HumanRpcTimeCheckNotifyWraper& Notify 加速检测通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcTimeCheck(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientMotionFlags
	* Description:    玩家模块-->移动标志刷新异步通知操作函数
	* Input:          HumanRpcMotionFlagsNotifyWraper& Notify 移动标志刷新通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMotionFlags( INT64 UserId, HumanRpcMotionFlagsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcRush
	* Description:    玩家模块-->疾跑同步调用操作函数
	* Input:          HumanRpcRushAskWraper& Ask 疾跑请求
	* Output:         HumanRpcRushReplyWraper& Reply 疾跑回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRush( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcStare
	* Description:    玩家模块-->盯防同步调用操作函数
	* Input:          HumanRpcStareAskWraper& Ask 盯防请求
	* Output:         HumanRpcStareReplyWraper& Reply 盯防回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcStare( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangePosition
	* Description:    玩家模块-->瞬移异步通知操作函数
	* Input:          HumanRpcChangePositionNotifyWraper& Notify 瞬移通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangePosition( INT64 UserId, HumanRpcChangePositionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientAttrChange
	* Description:    玩家模块-->属性变化值异步通知操作函数
	* Input:          HumanRpcAttrChangeNotifyWraper& Notify 属性变化值通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAttrChange( INT64 UserId, HumanRpcAttrChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcTrusteeship
	* Description:    玩家模块-->托管同步调用操作函数
	* Input:          HumanRpcTrusteeshipAskWraper& Ask 托管请求
	* Output:         HumanRpcTrusteeshipReplyWraper& Reply 托管回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTrusteeship( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChangePlayerName
	* Description:    玩家模块-->改名同步调用操作函数
	* Input:          HumanRpcChangePlayerNameAskWraper& Ask 改名请求
	* Output:         HumanRpcChangePlayerNameReplyWraper& Reply 改名回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangePlayerName( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif