/*gxb********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleHuman.cpp
* Author:       郭晓波
* Description:  玩家模块类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "HumanModule.h"



//初始化
bool ModuleHuman::Initialize()
{

	
	return OnLoad();
}

bool ModuleHuman::Reinitialize()
{
	
	return OnLoad();
}
