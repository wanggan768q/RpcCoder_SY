/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcContactImp.cpp
* Author:       甘业清
* Description:  联系人类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ContactModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcAddFriend
* Description:    联系人-->添加好友同步调用操作函数
* Input:          ContactRpcAddFriendAskWraper& Ask 添加好友请求
* Output:         ContactRpcAddFriendReplyWraper& Reply 添加好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAddFriend( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCancelRelationShip
* Description:    联系人-->删除好友同步调用操作函数
* Input:          ContactRpcCancelRelationShipAskWraper& Ask 删除好友请求
* Output:         ContactRpcCancelRelationShipReplyWraper& Reply 删除好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcCancelRelationShip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddBlackList
* Description:    联系人-->加入黑名单同步调用操作函数
* Input:          ContactRpcAddBlackListAskWraper& Ask 加入黑名单请求
* Output:         ContactRpcAddBlackListReplyWraper& Reply 加入黑名单回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAddBlackList( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncAddressBook
* Description:    联系人-->通讯录数据同步调用操作函数
* Input:          ContactRpcSyncAddressBookAskWraper& Ask 通讯录数据请求
* Output:         ContactRpcSyncAddressBookReplyWraper& Reply 通讯录数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSyncAddressBook( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcContactSetting
* Description:    联系人-->联系人设置同步调用操作函数
* Input:          ContactRpcContactSettingAskWraper& Ask 联系人设置请求
* Output:         ContactRpcContactSettingReplyWraper& Reply 联系人设置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcContactSetting( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateFriendGroup
* Description:    联系人-->创建好友分组同步调用操作函数
* Input:          ContactRpcCreateFriendGroupAskWraper& Ask 创建好友分组请求
* Output:         ContactRpcCreateFriendGroupReplyWraper& Reply 创建好友分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcCreateFriendGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMoveToFriendGroup
* Description:    联系人-->移动到分组同步调用操作函数
* Input:          ContactRpcMoveToFriendGroupAskWraper& Ask 移动到分组请求
* Output:         ContactRpcMoveToFriendGroupReplyWraper& Reply 移动到分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcMoveToFriendGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRemoveFriendGroup
* Description:    联系人-->删除好友分组同步调用操作函数
* Input:          ContactRpcRemoveFriendGroupAskWraper& Ask 删除好友分组请求
* Output:         ContactRpcRemoveFriendGroupReplyWraper& Reply 删除好友分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcRemoveFriendGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRenameGroup
* Description:    联系人-->重命名分组同步调用操作函数
* Input:          ContactRpcRenameGroupAskWraper& Ask 重命名分组请求
* Output:         ContactRpcRenameGroupReplyWraper& Reply 重命名分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcRenameGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAgreeApplication
* Description:    联系人-->同意申请加为好友同步调用操作函数
* Input:          ContactRpcAgreeApplicationAskWraper& Ask 同意申请加为好友请求
* Output:         ContactRpcAgreeApplicationReplyWraper& Reply 同意申请加为好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAgreeApplication( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientAgreeApplicationNotify
* Description:    联系人-->同意申请通知异步通知操作函数
* Input:          ContactRpcAgreeApplicationNotifyNotifyWraper& Notify 同意申请通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientAgreeApplicationNotify( INT64 UserId, ContactRpcAgreeApplicationNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSetFriendGroup
* Description:    联系人-->设置分组同步调用操作函数
* Input:          ContactRpcSetFriendGroupAskWraper& Ask 设置分组请求
* Output:         ContactRpcSetFriendGroupReplyWraper& Reply 设置分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSetFriendGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewFriend
* Description:    联系人-->新朋友异步通知操作函数
* Input:          ContactRpcNewFriendNotifyWraper& Notify 新联系人通知,不是朋友
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientNewFriend( INT64 UserId, ContactRpcNewFriendNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientApplyList
* Description:    联系人-->申请列表异步通知操作函数
* Input:          ContactRpcApplyListNotifyWraper& Notify 申请列表通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientApplyList( INT64 UserId, ContactRpcApplyListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcRejectApply
* Description:    联系人-->拒绝申请同步调用操作函数
* Input:          ContactRpcRejectApplyAskWraper& Ask 拒绝申请请求
* Output:         ContactRpcRejectApplyReplyWraper& Reply 拒绝申请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcRejectApply( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBeRejectApply
* Description:    联系人-->被拒绝异步通知操作函数
* Input:          ContactRpcBeRejectApplyNotifyWraper& Notify 被拒绝通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientBeRejectApply( INT64 UserId, ContactRpcBeRejectApplyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBeCancelRelationShip
* Description:    联系人-->被删除好友异步通知操作函数
* Input:          ContactRpcBeCancelRelationShipNotifyWraper& Notify 被删除好友通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientBeCancelRelationShip( INT64 UserId, ContactRpcBeCancelRelationShipNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBeAddBlackList
* Description:    联系人-->被加入黑名单异步通知操作函数
* Input:          ContactRpcBeAddBlackListNotifyWraper& Notify 被加入黑名单通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientBeAddBlackList( INT64 UserId, ContactRpcBeAddBlackListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcRecommendContact
* Description:    联系人-->推荐联系人同步调用操作函数
* Input:          ContactRpcRecommendContactAskWraper& Ask 推荐联系人请求
* Output:         ContactRpcRecommendContactReplyWraper& Reply 推荐联系人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcRecommendContact( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRejectAll
* Description:    联系人-->拒绝所有申请同步调用操作函数
* Input:          ContactRpcRejectAllAskWraper& Ask 拒绝所有申请请求
* Output:         ContactRpcRejectAllReplyWraper& Reply 拒绝所有申请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcRejectAll( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddFriendShipPoint
* Description:    联系人-->添加好友度同步调用操作函数
* Input:          ContactRpcAddFriendShipPointAskWraper& Ask 添加好友度请求
* Output:         ContactRpcAddFriendShipPointReplyWraper& Reply 添加好友度回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAddFriendShipPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRoleDataUpdate
* Description:    联系人-->玩家数据更新异步通知操作函数
* Input:          ContactRpcRoleDataUpdateNotifyWraper& Notify 玩家数据更新通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientRoleDataUpdate( INT64 UserId, ContactRpcRoleDataUpdateNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientContactLogin
* Description:    联系人-->联系人登录异步通知操作函数
* Input:          ContactRpcContactLoginNotifyWraper& Notify 联系人登录通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientContactLogin( INT64 UserId, ContactRpcContactLoginNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientContactLogout
* Description:    联系人-->联系人退出游戏异步通知操作函数
* Input:          ContactRpcContactLogoutNotifyWraper& Notify 联系人退出游戏通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientContactLogout( INT64 UserId, ContactRpcContactLogoutNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDeleteRoleData
* Description:    联系人-->删除联系人数据异步通知操作函数
* Input:          ContactRpcDeleteRoleDataNotifyWraper& Notify 删除联系人数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientDeleteRoleData( INT64 UserId, ContactRpcDeleteRoleDataNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSortGroup
* Description:    联系人-->排序分组同步调用操作函数
* Input:          ContactRpcSortGroupAskWraper& Ask 排序分组请求
* Output:         ContactRpcSortGroupReplyWraper& Reply 排序分组回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSortGroup( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSetFriendAlias
* Description:    联系人-->设置好友名字同步调用操作函数
* Input:          ContactRpcSetFriendAliasAskWraper& Ask 设置好友名字请求
* Output:         ContactRpcSetFriendAliasReplyWraper& Reply 设置好友名字回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSetFriendAlias( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSendFriendGiftPoint
* Description:    联系人-->发送好友点同步调用操作函数
* Input:          ContactRpcSendFriendGiftPointAskWraper& Ask 发送好友点请求
* Output:         ContactRpcSendFriendGiftPointReplyWraper& Reply 发送好友点回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSendFriendGiftPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAcquireGiftPoint
* Description:    联系人-->获取点数同步调用操作函数
* Input:          ContactRpcAcquireGiftPointAskWraper& Ask 获取点数请求
* Output:         ContactRpcAcquireGiftPointReplyWraper& Reply 获取点数回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAcquireGiftPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUnAcquireGiftPoint
* Description:    联系人-->刷新未获取点数异步通知操作函数
* Input:          ContactRpcUnAcquireGiftPointNotifyWraper& Notify 刷新未获取点数通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientUnAcquireGiftPoint( INT64 UserId, ContactRpcUnAcquireGiftPointNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSendAllFriendGiftPoint
* Description:    联系人-->一键赠送同步调用操作函数
* Input:          ContactRpcSendAllFriendGiftPointAskWraper& Ask 一键赠送请求
* Output:         ContactRpcSendAllFriendGiftPointReplyWraper& Reply 一键赠送回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcSendAllFriendGiftPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAcquireAllGiftPoint
* Description:    联系人-->一键收取同步调用操作函数
* Input:          ContactRpcAcquireAllGiftPointAskWraper& Ask 一键收取请求
* Output:         ContactRpcAcquireAllGiftPointReplyWraper& Reply 一键收取回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAcquireAllGiftPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDeleteGroupRole
* Description:    联系人-->移出列表同步调用操作函数
* Input:          ContactRpcDeleteGroupRoleAskWraper& Ask 移出列表请求
* Output:         ContactRpcDeleteGroupRoleReplyWraper& Reply 移出列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcDeleteGroupRole( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientAddRoleData
* Description:    联系人-->新加玩家数据异步通知操作函数
* Input:          ContactRpcAddRoleDataNotifyWraper& Notify 新加玩家数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientAddRoleData( INT64 UserId, ContactRpcAddRoleDataNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSetGiftPoint
* Description:    联系人-->设置友情点数据异步通知操作函数
* Input:          ContactRpcSetGiftPointNotifyWraper& Notify 设置友情点数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientSetGiftPoint( INT64 UserId, ContactRpcSetGiftPointNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientContactsGroups
* Description:    联系人-->刷新组异步通知操作函数
* Input:          ContactRpcContactsGroupsNotifyWraper& Notify 刷新组通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientContactsGroups( INT64 UserId, ContactRpcContactsGroupsNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcAgreeAllApplication
* Description:    联系人-->同意所有申请同步调用操作函数
* Input:          ContactRpcAgreeAllApplicationAskWraper& Ask 同意所有申请请求
* Output:         ContactRpcAgreeAllApplicationReplyWraper& Reply 同意所有申请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcAgreeAllApplication( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChatTo
* Description:    联系人-->聊天同步调用操作函数
* Input:          ContactRpcChatToAskWraper& Ask 聊天请求
* Output:         ContactRpcChatToReplyWraper& Reply 聊天回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcChatTo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewChatMsg
* Description:    联系人-->新的聊天信息异步通知操作函数
* Input:          ContactRpcNewChatMsgNotifyWraper& Notify 新的聊天信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleContact::SendToClientNewChatMsg( INT64 UserId, ContactRpcNewChatMsgNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReadMsg
* Description:    联系人-->读取信息同步调用操作函数
* Input:          ContactRpcReadMsgAskWraper& Ask 读取信息请求
* Output:         ContactRpcReadMsgReplyWraper& Reply 读取信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleContact::RpcReadMsg( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



