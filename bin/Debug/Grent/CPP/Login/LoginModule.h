/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleLogin.h
* Author:       郭晓波
* Description:  登录模块类，包含以下内容
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

#ifndef __MODULE_LOGIN_H
#define __MODULE_LOGIN_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "LoginRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//登录模块实现类
class ModuleLogin
{
	
public:
	//登录模块类的枚举定义
	enum ConstLoginE
	{
	MODULE_ID_LOGIN                              = 2,	//登录模块模块ID
	RPC_CODE_LOGIN_LOGIN_REQUEST                 = 251,	//登录模块-->登录-->请求
	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST       = 252,	//登录模块-->选择角色-->请求
	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST       = 253,	//登录模块-->创建角色-->请求
	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST       = 254,	//登录模块-->删除角色-->请求
	RPC_CODE_LOGIN_TEST_REQUEST                  = 255,	//登录模块-->Test-->请求
	RPC_CODE_LOGIN_TEST1_REQUEST                 = 256,	//登录模块-->Test1-->请求
	RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY            = 257,	//登录模块-->登录 排队通知-->通知
	RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY         = 258,	//登录模块-->可以登录服务器的通知-->通知
	RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST       = 259,	//登录模块-->退出排队-->请求
	RPC_CODE_LOGIN_REMOTELOGIN_REQUEST           = 260,	//登录模块-->login-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//登录模块实现类构造函数
	ModuleLogin()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_LOGIN_REQUEST, &ModuleLogin::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_LOGIN_REQUEST, new Some_Factory<LoginRpcLoginAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, &ModuleLogin::RpcSelectCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, new Some_Factory<LoginRpcSelectCharacterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, &ModuleLogin::RpcCreateCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, new Some_Factory<LoginRpcCreateCharacterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, &ModuleLogin::RpcDeleteCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, new Some_Factory<LoginRpcDeleteCharacterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_TEST_REQUEST, &ModuleLogin::RpcTest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_TEST_REQUEST, new Some_Factory<LoginRpcTestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_TEST1_REQUEST, &ModuleLogin::RpcTest1);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_TEST1_REQUEST, new Some_Factory<LoginRpcTest1Ask>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST, &ModuleLogin::RpcLoginQuitLineUp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST, new Some_Factory<LoginRpcLoginQuitLineUpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_REMOTELOGIN_REQUEST, &ModuleLogin::RpcRemoteLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_REMOTELOGIN_REQUEST, new Some_Factory<LoginRpcRemoteLoginAsk>());

	}
	
	//登录模块实现类析构函数
	~ModuleLogin(){}


	static ModuleLogin & Instance()
	{
		static ModuleLogin sInstance;
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
	* Function:       RpcLogin
	* Description:    登录模块-->登录同步调用操作函数
	* Input:          LoginRpcLoginAskWraper& Ask 登录请求
	* Output:         LoginRpcLoginReplyWraper& Reply 登录回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogin( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSelectCharacter
	* Description:    登录模块-->选择角色同步调用操作函数
	* Input:          LoginRpcSelectCharacterAskWraper& Ask 选择角色请求
	* Output:         LoginRpcSelectCharacterReplyWraper& Reply 选择角色回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSelectCharacter( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateCharacter
	* Description:    登录模块-->创建角色同步调用操作函数
	* Input:          LoginRpcCreateCharacterAskWraper& Ask 创建角色请求
	* Output:         LoginRpcCreateCharacterReplyWraper& Reply 创建角色回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateCharacter( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDeleteCharacter
	* Description:    登录模块-->删除角色同步调用操作函数
	* Input:          LoginRpcDeleteCharacterAskWraper& Ask 删除角色请求
	* Output:         LoginRpcDeleteCharacterReplyWraper& Reply 删除角色回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDeleteCharacter( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTest
	* Description:    登录模块-->Test同步调用操作函数
	* Input:          LoginRpcTestAskWraper& Ask Test请求
	* Output:         LoginRpcTestReplyWraper& Reply Test回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTest1
	* Description:    登录模块-->Test1同步调用操作函数
	* Input:          LoginRpcTest1AskWraper& Ask Test1请求
	* Output:         LoginRpcTest1ReplyWraper& Reply Test1回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTest1( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientLoginLineUp
	* Description:    登录模块-->登录 排队通知异步通知操作函数
	* Input:          LoginRpcLoginLineUpNotifyWraper& Notify 登录 排队通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLoginLineUp( INT64 UserId, LoginRpcLoginLineUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLoginEnterGame
	* Description:    登录模块-->可以登录服务器的通知异步通知操作函数
	* Input:          LoginRpcLoginEnterGameNotifyWraper& Notify 可以登录服务器的通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLoginEnterGame( INT64 UserId, LoginRpcLoginEnterGameNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcLoginQuitLineUp
	* Description:    登录模块-->退出排队同步调用操作函数
	* Input:          LoginRpcLoginQuitLineUpAskWraper& Ask 退出排队请求
	* Output:         LoginRpcLoginQuitLineUpReplyWraper& Reply 退出排队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLoginQuitLineUp( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRemoteLogin
	* Description:    登录模块-->login同步调用操作函数
	* Input:          LoginRpcRemoteLoginAskWraper& Ask login请求
	* Output:         LoginRpcRemoteLoginReplyWraper& Reply login回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRemoteLogin( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif