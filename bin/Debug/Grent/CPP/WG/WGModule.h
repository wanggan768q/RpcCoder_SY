/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleWG.h
* Author:       郭晓波
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


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "WGRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//WG实现类
class ModuleWG
{
	
public:
	//WG类的枚举定义
	enum ConstWGE
	{
	MODULE_ID_WG                                 = 11,	//WG模块ID
	RPC_CODE_WG_INFORMJOINTEAM_REQUEST           = 1151,	//WG-->InformJoinTeam-->请求
	RPC_CODE_WG_INFORMLEAVE_REQUEST              = 1152,	//WG-->InformLeave-->请求
	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST  = 1153,	//WG-->InformAppointTeamLeader-->请求
	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST     = 1154,	//WG-->InformKickTeamMember-->请求
	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST       = 1155,	//WG-->InformDissmissTeam-->请求
	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST          = 1156,	//WG-->InformApply-->请求
	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST       = 1157,	//WG-->AgreeTeamApplicant-->请求
	RPC_CODE_WG_INFORMLOGIN_REQUEST              = 1158,	//WG-->InformLogin-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//WG实现类构造函数
	ModuleWG()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMJOINTEAM_REQUEST, &ModuleWG::RpcInformJoinTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMJOINTEAM_REQUEST, new Some_Factory<WGRpcInformJoinTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMLEAVE_REQUEST, &ModuleWG::RpcInformLeave);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMLEAVE_REQUEST, new Some_Factory<WGRpcInformLeaveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, &ModuleWG::RpcInformAppointTeamLeader);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, new Some_Factory<WGRpcInformAppointTeamLeaderAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, &ModuleWG::RpcInformKickTeamMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, new Some_Factory<WGRpcInformKickTeamMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, &ModuleWG::RpcInformDissmissTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, new Some_Factory<WGRpcInformDissmissTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, &ModuleWG::RpcInformApplyTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, new Some_Factory<WGRpcInformApplyTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, &ModuleWG::RpcAgreeTeamApplicant);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, new Some_Factory<WGRpcAgreeTeamApplicantAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMLOGIN_REQUEST, &ModuleWG::RpcInformLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMLOGIN_REQUEST, new Some_Factory<WGRpcInformLoginAsk>());

	}
	
	//WG实现类析构函数
	~ModuleWG(){}


	static ModuleWG & Instance()
	{
		static ModuleWG sInstance;
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


	reload_vec_type m_vReLoadCb;

};

#endif