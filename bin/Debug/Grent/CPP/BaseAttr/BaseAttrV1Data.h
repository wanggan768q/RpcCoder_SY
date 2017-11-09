#ifndef __SYNC_DATA_BASEATTR_V1_H
#define __SYNC_DATA_BASEATTR_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "BaseAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum BaseAttrSyncDataItemIdE
{
 	SYNCID_BASEATTR_EXP                         = 701,  //经验
 	SYNCID_BASEATTR_LEVEL                       = 703,  //玩家等级
 	SYNCID_BASEATTR_SERVERTIME                  = 704,  //服务器时间
 	SYNCID_BASEATTR_ROLEID                      = 705,  //人物唯一ID

};


//主同步数据操作类
class SyncDataBaseAttrV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataBaseAttrV1>
{
public:
			SyncDataBaseAttrV1();
	virtual	~SyncDataBaseAttrV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUserData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUserData.HtmlDescHeader(); }
public:
	//经验
	void SetExp( const INT32& v );
	INT32 GetExp();
	void SendExp(bool OnlyToClient=true);
public:
	//玩家等级
	void SetLevel( const INT32& v );
	INT32 GetLevel();
	void SendLevel(bool OnlyToClient=true);
public:
	//服务器时间
	void SetServerTime( const INT32& v );
	INT32 GetServerTime();
	void SendServerTime(bool OnlyToClient=true);
public:
	//人物唯一ID
	void SetRoleId( const INT32& v );
	INT32 GetRoleId();
	void SendRoleId(bool OnlyToClient=true);


private:
	BaseAttrUserDataWraperV1 m_syncDataUserData;

};



#endif
