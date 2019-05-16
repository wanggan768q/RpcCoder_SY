/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMail.h
* Author:       甘业清
* Description:  邮件类，包含以下内容
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

#ifndef __MODULE_MAIL_H
#define __MODULE_MAIL_H


#include "ModuleBase.h"
#include "MailRpcWraper.h"




//邮件实现类
class ModuleMail : public ModuleBase
{
	DECLARE_INSTANCE(ModuleMail);
public:
	friend class			ModuleMgr;

public:
	//邮件实现类构造函数
	ModuleMail();
	
	//邮件实现类析构函数
	virtual					~ModuleMail();

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
	* Function:       RpcInitMail
	* Description:    邮件-->初始化邮件信息同步调用操作函数
	* Input:          MailRpcInitMailAskWraper& Ask 初始化邮件信息请求
	* Output:         MailRpcInitMailReplyWraper& Reply 初始化邮件信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInitMail( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcReadMail
	* Description:    邮件-->已读邮件同步调用操作函数
	* Input:          MailRpcReadMailAskWraper& Ask 已读邮件请求
	* Output:         MailRpcReadMailReplyWraper& Reply 已读邮件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReadMail( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDeleteMail
	* Description:    邮件-->删除邮件同步调用操作函数
	* Input:          MailRpcDeleteMailAskWraper& Ask 删除邮件请求
	* Output:         MailRpcDeleteMailReplyWraper& Reply 删除邮件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDeleteMail( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetMail
	* Description:    邮件-->领取邮件同步调用操作函数
	* Input:          MailRpcGetMailAskWraper& Ask 领取邮件请求
	* Output:         MailRpcGetMailReplyWraper& Reply 领取邮件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetMail( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSyncMailInfo
	* Description:    邮件-->同步邮件信息异步通知操作函数
	* Input:          MailRpcSyncMailInfoNotifyWraper& Notify 同步邮件信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSyncMailInfo( INT64 UserId, MailRpcSyncMailInfoNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif