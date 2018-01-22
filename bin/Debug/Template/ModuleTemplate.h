/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     Module$Template$.h
* Author:       郭晓波
* Description:  $ModCName$类，包含以下内容
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

#ifndef __MODULE_$TEMPLATE$_H
#define __MODULE_$TEMPLATE$_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "$Template$Rpc.pb.h"
#include <memory>


$IncludeSyncDataHeader$
$HeaderConfig$

class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//$ModCName$实现类
class Module$Template$
{
	
public:
	//$ModCName$类的枚举定义
	enum Const$Template$E
	{
$DeclareMsgID$
	};

public:
	//$ModCName$实现类构造函数
	Module$Template$()
	{
$CliOperationImpl$
	}
	
	//$ModCName$实现类析构函数
	~Module$Template$(){}


	static Module$Template$ Instance()
	{
		static Module$Template$ sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
$CliOperationDeclare$

};

#endif