/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleServerModel.h
* Author:       郭晓波
* Description:  服务器内部模块类，包含以下内容
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

#ifndef __MODULE_SERVERMODEL_H
#define __MODULE_SERVERMODEL_H


#include "PacketFactory.h"
#include "Main/PacketMgr.h"
#include "ServerModelRpc.pb.h"





class CPlayer;
class CPacket;

extern PacketMgr* g_pPacketMgr;

//服务器内部模块实现类
class ModuleServerModel
{
	
public:
	//服务器内部模块类的枚举定义
	enum ConstServerModelE
	{
	MODULE_ID_SERVERMODEL                        = 3,	//服务器内部模块模块ID
	RPC_CODE_SERVERMODEL_LOGIN_REQUEST           = 351,	//服务器内部模块-->服务器使用登录-->请求

	};

public:
	//服务器内部模块实现类构造函数
	ModuleServerModel()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_SERVERMODEL_LOGIN_REQUEST, &ModuleServerModel::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SERVERMODEL_LOGIN_REQUEST, new Some_Factory<ServerModelRpcLoginAsk>(), new Some_Factory<ServerModelRpcLoginReply>());

	}
	
	//服务器内部模块实现类析构函数
	~ModuleServerModel(){}


	

public:
	/********************************************************************************************
	* Function:       RpcLogin
	* Description:    服务器内部模块-->服务器使用登录同步调用操作函数
	* Input:          ServerModelRpcLoginAskWraper& Ask 服务器使用登录请求
	* Output:         ServerModelRpcLoginReplyWraper& Reply 服务器使用登录回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogin( CPlayer* pPlayer, CPacket* pPacket );



};

#endif