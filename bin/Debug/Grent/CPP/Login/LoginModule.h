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
#include "include/PacketMgr.h"
#include "LoginRpc.pb.h"
#include <memory>





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
	RPC_CODE_LOGIN_CONNECT_REQUEST               = 251,	//登录模块-->连接验证-->请求
	RPC_CODE_LOGIN_LOGIN_REQUEST                 = 252,	//登录模块-->登录-->请求
	RPC_CODE_LOGIN_CHARACTERLIST_REQUEST         = 253,	//登录模块-->角色列表-->请求
	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST       = 254,	//登录模块-->选择角色-->请求
	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST       = 255,	//登录模块-->创建角色-->请求
	RPC_CODE_LOGIN_SELECTSAVEUSER_REQUEST        = 256,	//登录模块-->选择角色存储redis-->请求
	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST       = 257,	//登录模块-->删除角色-->请求

	};

public:
	//登录模块实现类构造函数
	ModuleLogin()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CONNECT_REQUEST, &ModuleLogin::RpcConnect);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CONNECT_REQUEST, new Some_Factory<LoginRpcConnectAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_LOGIN_REQUEST, &ModuleLogin::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_LOGIN_REQUEST, new Some_Factory<LoginRpcLoginAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CHARACTERLIST_REQUEST, &ModuleLogin::RpcCharacterList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CHARACTERLIST_REQUEST, new Some_Factory<LoginRpcCharacterListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, &ModuleLogin::RpcSelectCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST, new Some_Factory<LoginRpcSelectCharacterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, &ModuleLogin::RpcCreateCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST, new Some_Factory<LoginRpcCreateCharacterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_SELECTSAVEUSER_REQUEST, &ModuleLogin::RpcSelectSaveUser);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_SELECTSAVEUSER_REQUEST, new Some_Factory<LoginRpcSelectSaveUserAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, &ModuleLogin::RpcDeleteCharacter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST, new Some_Factory<LoginRpcDeleteCharacterAsk>());

	}
	
	//登录模块实现类析构函数
	~ModuleLogin(){}


	static ModuleLogin Instance()
	{
		static ModuleLogin sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcConnect
	* Description:    登录模块-->连接验证同步调用操作函数
	* Input:          LoginRpcConnectAskWraper& Ask 连接验证请求
	* Output:         LoginRpcConnectReplyWraper& Reply 连接验证回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcConnect( CPlayer* pPlayer, CPacket* pPacket );

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
	* Function:       RpcCharacterList
	* Description:    登录模块-->角色列表同步调用操作函数
	* Input:          LoginRpcCharacterListAskWraper& Ask 角色列表请求
	* Output:         LoginRpcCharacterListReplyWraper& Reply 角色列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCharacterList( CPlayer* pPlayer, CPacket* pPacket );

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
	* Function:       RpcSelectSaveUser
	* Description:    登录模块-->选择角色存储redis同步调用操作函数
	* Input:          LoginRpcSelectSaveUserAskWraper& Ask 选择角色存储redis请求
	* Output:         LoginRpcSelectSaveUserReplyWraper& Reply 选择角色存储redis回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSelectSaveUser( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDeleteCharacter
	* Description:    登录模块-->删除角色同步调用操作函数
	* Input:          LoginRpcDeleteCharacterAskWraper& Ask 删除角色请求
	* Output:         LoginRpcDeleteCharacterReplyWraper& Reply 删除角色回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDeleteCharacter( CPlayer* pPlayer, CPacket* pPacket );



};

#endif