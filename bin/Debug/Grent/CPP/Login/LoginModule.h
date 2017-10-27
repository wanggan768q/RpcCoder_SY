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





class CPlayer;
class CPacket;

extern PacketMgr* g_pPacketMgr;

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

	};

public:
	//登录模块实现类构造函数
	ModuleLogin()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_CONNECT_REQUEST, &ModuleLogin::RpcConnect);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_CONNECT_REQUEST, new Some_Factory<LoginRpcConnectAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_LOGIN_LOGIN_REQUEST, &ModuleLogin::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOGIN_LOGIN_REQUEST, new Some_Factory<LoginRpcLoginAsk>());

	}
	
	//登录模块实现类析构函数
	~ModuleLogin(){}


	

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



};

#endif