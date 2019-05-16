/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleContact.h
* Author:       甘业清
* Description:  联系人类，包含以下内容
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

#ifndef __MODULE_CONTACT_H
#define __MODULE_CONTACT_H


#include "ModuleBase.h"
#include "ContactRpcWraper.h"




//联系人实现类
class ModuleContact : public ModuleBase
{
	DECLARE_INSTANCE(ModuleContact);
public:
	friend class			ModuleMgr;

public:
	//联系人实现类构造函数
	ModuleContact();
	
	//联系人实现类析构函数
	virtual					~ModuleContact();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:
	/********************************************************************************************
	* Function:       RpcAddFriend
	* Description:    联系人-->添加好友同步调用操作函数
	* Input:          ContactRpcAddFriendAskWraper& Ask 添加好友请求
	* Output:         ContactRpcAddFriendReplyWraper& Reply 添加好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAddFriend( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCancelRelationShip
	* Description:    联系人-->删除好友同步调用操作函数
	* Input:          ContactRpcCancelRelationShipAskWraper& Ask 删除好友请求
	* Output:         ContactRpcCancelRelationShipReplyWraper& Reply 删除好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCancelRelationShip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAddBlackList
	* Description:    联系人-->加入黑名单同步调用操作函数
	* Input:          ContactRpcAddBlackListAskWraper& Ask 加入黑名单请求
	* Output:         ContactRpcAddBlackListReplyWraper& Reply 加入黑名单回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAddBlackList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSyncAddressBook
	* Description:    联系人-->通讯录数据同步调用操作函数
	* Input:          ContactRpcSyncAddressBookAskWraper& Ask 通讯录数据请求
	* Output:         ContactRpcSyncAddressBookReplyWraper& Reply 通讯录数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncAddressBook( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcContactSetting
	* Description:    联系人-->联系人设置同步调用操作函数
	* Input:          ContactRpcContactSettingAskWraper& Ask 联系人设置请求
	* Output:         ContactRpcContactSettingReplyWraper& Reply 联系人设置回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcContactSetting( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateFriendGroup
	* Description:    联系人-->创建好友分组同步调用操作函数
	* Input:          ContactRpcCreateFriendGroupAskWraper& Ask 创建好友分组请求
	* Output:         ContactRpcCreateFriendGroupReplyWraper& Reply 创建好友分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateFriendGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMoveToFriendGroup
	* Description:    联系人-->移动到分组同步调用操作函数
	* Input:          ContactRpcMoveToFriendGroupAskWraper& Ask 移动到分组请求
	* Output:         ContactRpcMoveToFriendGroupReplyWraper& Reply 移动到分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMoveToFriendGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRemoveFriendGroup
	* Description:    联系人-->删除好友分组同步调用操作函数
	* Input:          ContactRpcRemoveFriendGroupAskWraper& Ask 删除好友分组请求
	* Output:         ContactRpcRemoveFriendGroupReplyWraper& Reply 删除好友分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRemoveFriendGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRenameGroup
	* Description:    联系人-->重命名分组同步调用操作函数
	* Input:          ContactRpcRenameGroupAskWraper& Ask 重命名分组请求
	* Output:         ContactRpcRenameGroupReplyWraper& Reply 重命名分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRenameGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAgreeApplication
	* Description:    联系人-->同意申请加为好友同步调用操作函数
	* Input:          ContactRpcAgreeApplicationAskWraper& Ask 同意申请加为好友请求
	* Output:         ContactRpcAgreeApplicationReplyWraper& Reply 同意申请加为好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeApplication( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientAgreeApplicationNotify
	* Description:    联系人-->同意申请通知异步通知操作函数
	* Input:          ContactRpcAgreeApplicationNotifyNotifyWraper& Notify 同意申请通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAgreeApplicationNotify( INT64 UserId, ContactRpcAgreeApplicationNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSetFriendGroup
	* Description:    联系人-->设置分组同步调用操作函数
	* Input:          ContactRpcSetFriendGroupAskWraper& Ask 设置分组请求
	* Output:         ContactRpcSetFriendGroupReplyWraper& Reply 设置分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSetFriendGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewFriend
	* Description:    联系人-->新朋友异步通知操作函数
	* Input:          ContactRpcNewFriendNotifyWraper& Notify 新联系人通知,不是朋友
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewFriend( INT64 UserId, ContactRpcNewFriendNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientApplyList
	* Description:    联系人-->申请列表异步通知操作函数
	* Input:          ContactRpcApplyListNotifyWraper& Notify 申请列表通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyList( INT64 UserId, ContactRpcApplyListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcRejectApply
	* Description:    联系人-->拒绝申请同步调用操作函数
	* Input:          ContactRpcRejectApplyAskWraper& Ask 拒绝申请请求
	* Output:         ContactRpcRejectApplyReplyWraper& Reply 拒绝申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRejectApply( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientBeRejectApply
	* Description:    联系人-->被拒绝异步通知操作函数
	* Input:          ContactRpcBeRejectApplyNotifyWraper& Notify 被拒绝通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBeRejectApply( INT64 UserId, ContactRpcBeRejectApplyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBeCancelRelationShip
	* Description:    联系人-->被删除好友异步通知操作函数
	* Input:          ContactRpcBeCancelRelationShipNotifyWraper& Notify 被删除好友通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBeCancelRelationShip( INT64 UserId, ContactRpcBeCancelRelationShipNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBeAddBlackList
	* Description:    联系人-->被加入黑名单异步通知操作函数
	* Input:          ContactRpcBeAddBlackListNotifyWraper& Notify 被加入黑名单通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBeAddBlackList( INT64 UserId, ContactRpcBeAddBlackListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcRecommendContact
	* Description:    联系人-->推荐联系人同步调用操作函数
	* Input:          ContactRpcRecommendContactAskWraper& Ask 推荐联系人请求
	* Output:         ContactRpcRecommendContactReplyWraper& Reply 推荐联系人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRecommendContact( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRejectAll
	* Description:    联系人-->拒绝所有申请同步调用操作函数
	* Input:          ContactRpcRejectAllAskWraper& Ask 拒绝所有申请请求
	* Output:         ContactRpcRejectAllReplyWraper& Reply 拒绝所有申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRejectAll( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAddFriendShipPoint
	* Description:    联系人-->添加好友度同步调用操作函数
	* Input:          ContactRpcAddFriendShipPointAskWraper& Ask 添加好友度请求
	* Output:         ContactRpcAddFriendShipPointReplyWraper& Reply 添加好友度回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAddFriendShipPoint( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRoleDataUpdate
	* Description:    联系人-->玩家数据更新异步通知操作函数
	* Input:          ContactRpcRoleDataUpdateNotifyWraper& Notify 玩家数据更新通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRoleDataUpdate( INT64 UserId, ContactRpcRoleDataUpdateNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientContactLogin
	* Description:    联系人-->联系人登录异步通知操作函数
	* Input:          ContactRpcContactLoginNotifyWraper& Notify 联系人登录通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientContactLogin( INT64 UserId, ContactRpcContactLoginNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientContactLogout
	* Description:    联系人-->联系人退出游戏异步通知操作函数
	* Input:          ContactRpcContactLogoutNotifyWraper& Notify 联系人退出游戏通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientContactLogout( INT64 UserId, ContactRpcContactLogoutNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDeleteRoleData
	* Description:    联系人-->删除联系人数据异步通知操作函数
	* Input:          ContactRpcDeleteRoleDataNotifyWraper& Notify 删除联系人数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDeleteRoleData( INT64 UserId, ContactRpcDeleteRoleDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSortGroup
	* Description:    联系人-->排序分组同步调用操作函数
	* Input:          ContactRpcSortGroupAskWraper& Ask 排序分组请求
	* Output:         ContactRpcSortGroupReplyWraper& Reply 排序分组回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSortGroup( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSetFriendAlias
	* Description:    联系人-->设置好友名字同步调用操作函数
	* Input:          ContactRpcSetFriendAliasAskWraper& Ask 设置好友名字请求
	* Output:         ContactRpcSetFriendAliasReplyWraper& Reply 设置好友名字回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSetFriendAlias( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSendFriendGiftPoint
	* Description:    联系人-->发送好友点同步调用操作函数
	* Input:          ContactRpcSendFriendGiftPointAskWraper& Ask 发送好友点请求
	* Output:         ContactRpcSendFriendGiftPointReplyWraper& Reply 发送好友点回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSendFriendGiftPoint( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAcquireGiftPoint
	* Description:    联系人-->获取点数同步调用操作函数
	* Input:          ContactRpcAcquireGiftPointAskWraper& Ask 获取点数请求
	* Output:         ContactRpcAcquireGiftPointReplyWraper& Reply 获取点数回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAcquireGiftPoint( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientUnAcquireGiftPoint
	* Description:    联系人-->刷新未获取点数异步通知操作函数
	* Input:          ContactRpcUnAcquireGiftPointNotifyWraper& Notify 刷新未获取点数通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUnAcquireGiftPoint( INT64 UserId, ContactRpcUnAcquireGiftPointNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSendAllFriendGiftPoint
	* Description:    联系人-->一键赠送同步调用操作函数
	* Input:          ContactRpcSendAllFriendGiftPointAskWraper& Ask 一键赠送请求
	* Output:         ContactRpcSendAllFriendGiftPointReplyWraper& Reply 一键赠送回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSendAllFriendGiftPoint( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAcquireAllGiftPoint
	* Description:    联系人-->一键收取同步调用操作函数
	* Input:          ContactRpcAcquireAllGiftPointAskWraper& Ask 一键收取请求
	* Output:         ContactRpcAcquireAllGiftPointReplyWraper& Reply 一键收取回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAcquireAllGiftPoint( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDeleteGroupRole
	* Description:    联系人-->移出列表同步调用操作函数
	* Input:          ContactRpcDeleteGroupRoleAskWraper& Ask 移出列表请求
	* Output:         ContactRpcDeleteGroupRoleReplyWraper& Reply 移出列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDeleteGroupRole( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientAddRoleData
	* Description:    联系人-->新加玩家数据异步通知操作函数
	* Input:          ContactRpcAddRoleDataNotifyWraper& Notify 新加玩家数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAddRoleData( INT64 UserId, ContactRpcAddRoleDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSetGiftPoint
	* Description:    联系人-->设置友情点数据异步通知操作函数
	* Input:          ContactRpcSetGiftPointNotifyWraper& Notify 设置友情点数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSetGiftPoint( INT64 UserId, ContactRpcSetGiftPointNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientContactsGroups
	* Description:    联系人-->刷新组异步通知操作函数
	* Input:          ContactRpcContactsGroupsNotifyWraper& Notify 刷新组通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientContactsGroups( INT64 UserId, ContactRpcContactsGroupsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAgreeAllApplication
	* Description:    联系人-->同意所有申请同步调用操作函数
	* Input:          ContactRpcAgreeAllApplicationAskWraper& Ask 同意所有申请请求
	* Output:         ContactRpcAgreeAllApplicationReplyWraper& Reply 同意所有申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeAllApplication( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChatTo
	* Description:    联系人-->聊天同步调用操作函数
	* Input:          ContactRpcChatToAskWraper& Ask 聊天请求
	* Output:         ContactRpcChatToReplyWraper& Reply 聊天回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChatTo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewChatMsg
	* Description:    联系人-->新的聊天信息异步通知操作函数
	* Input:          ContactRpcNewChatMsgNotifyWraper& Notify 新的聊天信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewChatMsg( INT64 UserId, ContactRpcNewChatMsgNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReadMsg
	* Description:    联系人-->读取信息同步调用操作函数
	* Input:          ContactRpcReadMsgAskWraper& Ask 读取信息请求
	* Output:         ContactRpcReadMsgReplyWraper& Reply 读取信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReadMsg( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif