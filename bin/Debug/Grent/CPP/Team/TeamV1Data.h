#ifndef __SYNC_DATA_TEAM_V1_H
#define __SYNC_DATA_TEAM_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TeamV1DataWraper.h"


//同步数据相关枚举量定义
enum TeamSyncDataItemIdE
{
 	SYNCID_TEAM_ROLEID                          = 1001,  //队员RoleId
 	SYNCID_TEAM_SCENEID                         = 1002,  //队员场景id
 	SYNCID_TEAM_LEVEL                           = 1003,  //队员等级
 	SYNCID_TEAM_NAME                            = 1004,  //name
 	SYNCID_TEAM_CONFIGID                        = 1005,  //configid
 	SYNCID_TEAM_HP                              = 1006,  //生命值
 	SYNCID_TEAM_MP                              = 1007,  //Mp
 	SYNCID_TEAM_STATUS                          = 1008,  //Status

};


//主同步数据操作类
class SyncDataTeamV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTeamV1>
{
public:
			SyncDataTeamV1();
	virtual	~SyncDataTeamV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataMember.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataMember.HtmlDescHeader(); }
public:
	//队员RoleId
	void SetRoleId( const uint64_t& v );
	uint64_t GetRoleId();
	void SendRoleId(bool OnlyToClient=true);
public:
	//队员场景id
	void SetSceneId( const INT32& v );
	INT32 GetSceneId();
	void SendSceneId(bool OnlyToClient=true);
public:
	//队员等级
	void SetLevel( const INT32& v );
	INT32 GetLevel();
	void SendLevel(bool OnlyToClient=true);
public:
	//name
	void SetName( const string& v );
	string GetName();
	void SendName(bool OnlyToClient=true);
public:
	//configid
	void SetConfigId( const INT32& v );
	INT32 GetConfigId();
	void SendConfigId(bool OnlyToClient=true);
public:
	//生命值
	void SetHp( const INT32& v );
	INT32 GetHp();
	void SendHp(bool OnlyToClient=true);
public:
	//Mp
	void SetMp( const INT32& v );
	INT32 GetMp();
	void SendMp(bool OnlyToClient=true);
public:
	//Status
	void SetStatus( const INT32& v );
	INT32 GetStatus();
	void SendStatus(bool OnlyToClient=true);


private:
	TeamMemberWraperV1 m_syncDataMember;

};



#endif
