/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcEquipmentImp.cpp
* Author:       甘业清
* Description:  装备类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "EquipmentModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcEquip
* Description:    装备-->Equip同步调用操作函数
* Input:          EquipmentRpcEquipAskWraper& Ask 装备请求
* Output:         EquipmentRpcEquipReplyWraper& Reply 装备回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUnEquip
* Description:    装备-->UnEquip同步调用操作函数
* Input:          EquipmentRpcUnEquipAskWraper& Ask 卸载装备请求
* Output:         EquipmentRpcUnEquipReplyWraper& Reply 卸载装备回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcUnEquip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSwitchEquipSet
* Description:    装备-->SwitchEquipSet同步调用操作函数
* Input:          EquipmentRpcSwitchEquipSetAskWraper& Ask 切换装备套装请求
* Output:         EquipmentRpcSwitchEquipSetReplyWraper& Reply 切换装备套装回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcSwitchEquipSet( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncEquip
* Description:    装备-->Equip同步调用操作函数
* Input:          EquipmentRpcSyncEquipAskWraper& Ask 同步装备套装请求
* Output:         EquipmentRpcSyncEquipReplyWraper& Reply 同步装备套装回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcSyncEquip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcResonanceUnlock
* Description:    装备-->激活共鸣同步调用操作函数
* Input:          EquipmentRpcResonanceUnlockAskWraper& Ask 激活共鸣请求
* Output:         EquipmentRpcResonanceUnlockReplyWraper& Reply 激活共鸣回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcResonanceUnlock( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipDoResonance
* Description:    装备-->共鸣洗练同步调用操作函数
* Input:          EquipmentRpcEquipDoResonanceAskWraper& Ask 共鸣洗练请求
* Output:         EquipmentRpcEquipDoResonanceReplyWraper& Reply 共鸣洗练回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipDoResonance( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipResonanceSave
* Description:    装备-->保存共鸣属性同步调用操作函数
* Input:          EquipmentRpcEquipResonanceSaveAskWraper& Ask 保存共鸣属性请求
* Output:         EquipmentRpcEquipResonanceSaveReplyWraper& Reply 保存共鸣属性回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipResonanceSave( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipResonanceSync
* Description:    装备-->初始化同步调用操作函数
* Input:          EquipmentRpcEquipResonanceSyncAskWraper& Ask 初始化请求
* Output:         EquipmentRpcEquipResonanceSyncReplyWraper& Reply 初始化回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipResonanceSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipWashSync
* Description:    装备-->初始化洗练数据同步调用操作函数
* Input:          EquipmentRpcEquipWashSyncAskWraper& Ask 初始化洗练数据请求
* Output:         EquipmentRpcEquipWashSyncReplyWraper& Reply 初始化洗练数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipWashSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipWash
* Description:    装备-->请求洗练同步调用操作函数
* Input:          EquipmentRpcEquipWashAskWraper& Ask 请求洗练请求
* Output:         EquipmentRpcEquipWashReplyWraper& Reply 请求洗练回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipWash( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipWashSave
* Description:    装备-->保存同步调用操作函数
* Input:          EquipmentRpcEquipWashSaveAskWraper& Ask 保存请求
* Output:         EquipmentRpcEquipWashSaveReplyWraper& Reply 保存回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipWashSave( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipBuildSync
* Description:    装备-->装备打造同步调用操作函数
* Input:          EquipmentRpcEquipBuildSyncAskWraper& Ask 装备打造请求
* Output:         EquipmentRpcEquipBuildSyncReplyWraper& Reply 装备打造回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipBuildSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipBuild
* Description:    装备-->打造请求同步调用操作函数
* Input:          EquipmentRpcEquipBuildAskWraper& Ask 打造请求请求
* Output:         EquipmentRpcEquipBuildReplyWraper& Reply 打造请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipBuild( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetPlayerInfo
* Description:    装备-->获取其他玩家信息同步调用操作函数
* Input:          EquipmentRpcGetPlayerInfoAskWraper& Ask 获取其他玩家信息请求
* Output:         EquipmentRpcGetPlayerInfoReplyWraper& Reply 获取其他玩家信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcGetPlayerInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEquipInherit
* Description:    装备-->装备继承同步调用操作函数
* Input:          EquipmentRpcEquipInheritAskWraper& Ask 装备继承请求
* Output:         EquipmentRpcEquipInheritReplyWraper& Reply 装备继承回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEquipment::RpcEquipInherit( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



