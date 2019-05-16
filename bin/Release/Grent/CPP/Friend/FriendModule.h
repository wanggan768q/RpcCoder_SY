/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleFriend.h
* Author:       郭晓波
* Description:  朋友类，包含以下内容
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

#ifndef __MODULE_FRIEND_H
#define __MODULE_FRIEND_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "FriendRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//朋友实现类
class ModuleFriend
{
	
public:
	//朋友类的枚举定义
	enum ConstFriendE
	{
	MODULE_ID_FRIEND                             = 46,	//朋友模块ID

	};

	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//朋友实现类构造函数
	ModuleFriend()
	{

	}
	
	//朋友实现类析构函数
	~ModuleFriend(){}


	static ModuleFriend & Instance()
	{
		static ModuleFriend sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	void OnLoad()
	{
			for (auto it : m_vReLoadCb)
		{
			it();
		}
	}
public:

	reload_vec_type m_vReLoadCb;

};

#endif