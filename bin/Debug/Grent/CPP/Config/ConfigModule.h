/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleConfig.h
* Author:       郭晓波
* Description:  Config类，包含以下内容
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

#ifndef __MODULE_CONFIG_H
#define __MODULE_CONFIG_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "ConfigRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//Config实现类
class ModuleConfig
{
	
public:
	//Config类的枚举定义
	enum ConstConfigE
	{
	MODULE_ID_CONFIG                             = 1,	//Config模块ID

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//Config实现类构造函数
	ModuleConfig()
	{

	}
	
	//Config实现类析构函数
	~ModuleConfig(){}


	static ModuleConfig & Instance()
	{
		static ModuleConfig sInstance;
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

	reload_vec_type m_vReLoadCb;

};

#endif