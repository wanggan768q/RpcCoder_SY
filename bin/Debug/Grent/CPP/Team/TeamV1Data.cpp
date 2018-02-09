#include "TeamV1Data.h"
#include "TeamModule.h"


SyncDataTeamV1::SyncDataTeamV1()
{
	SetDataWraper( &m_syncDataMember );
}

SyncDataTeamV1::~SyncDataTeamV1()
{
}

void SyncDataTeamV1::SendAllMembers(bool OnlyToClient)
{
	SendRoleId(OnlyToClient);
	SendSceneId(OnlyToClient);
	SendLevel(OnlyToClient);
	SendName(OnlyToClient);
	SendConfigId(OnlyToClient);
	SendHp(OnlyToClient);
	SendMp(OnlyToClient);
	SendStatus(OnlyToClient);

}



//队员RoleId
void SyncDataTeamV1::SetRoleId( const uint64_t& v )
{
	m_syncDataMember.SetRoleId(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_ROLEID);
	SendRoleId(false);
}
uint64_t SyncDataTeamV1::GetRoleId()
{
	return m_syncDataMember.GetRoleId();
}
void SyncDataTeamV1::SendRoleId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_ROLEID,m_syncDataMember.GetRoleId());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_ROLEID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_ROLEID,m_syncDataMember.GetRoleId());
}

//队员场景id
void SyncDataTeamV1::SetSceneId( const INT32& v )
{
	m_syncDataMember.SetSceneId(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_SCENEID);
	SendSceneId(false);
}
INT32 SyncDataTeamV1::GetSceneId()
{
	return m_syncDataMember.GetSceneId();
}
void SyncDataTeamV1::SendSceneId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_SCENEID,m_syncDataMember.GetSceneId());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_SCENEID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_SCENEID,m_syncDataMember.GetSceneId());
}

//队员等级
void SyncDataTeamV1::SetLevel( const INT32& v )
{
	m_syncDataMember.SetLevel(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_LEVEL);
	SendLevel(false);
}
INT32 SyncDataTeamV1::GetLevel()
{
	return m_syncDataMember.GetLevel();
}
void SyncDataTeamV1::SendLevel(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_LEVEL,m_syncDataMember.GetLevel());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_LEVEL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_LEVEL,m_syncDataMember.GetLevel());
}

//name
void SyncDataTeamV1::SetName( const string& v )
{
	m_syncDataMember.SetName(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_NAME);
	SendName(false);
}
string SyncDataTeamV1::GetName()
{
	return m_syncDataMember.GetName();
}
void SyncDataTeamV1::SendName(bool OnlyToClient)
{
	const string v=m_syncDataMember.GetName();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_NAME,v.data(),v.size());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_NAME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_NAME,v.data(),v.size());
}

//configid
void SyncDataTeamV1::SetConfigId( const INT32& v )
{
	m_syncDataMember.SetConfigId(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_CONFIGID);
	SendConfigId(false);
}
INT32 SyncDataTeamV1::GetConfigId()
{
	return m_syncDataMember.GetConfigId();
}
void SyncDataTeamV1::SendConfigId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_CONFIGID,m_syncDataMember.GetConfigId());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_CONFIGID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_CONFIGID,m_syncDataMember.GetConfigId());
}

//生命值
void SyncDataTeamV1::SetHp( const INT32& v )
{
	m_syncDataMember.SetHp(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_HP);
	SendHp(false);
}
INT32 SyncDataTeamV1::GetHp()
{
	return m_syncDataMember.GetHp();
}
void SyncDataTeamV1::SendHp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_HP,m_syncDataMember.GetHp());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_HP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_HP,m_syncDataMember.GetHp());
}

//Mp
void SyncDataTeamV1::SetMp( const INT32& v )
{
	m_syncDataMember.SetMp(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_MP);
	SendMp(false);
}
INT32 SyncDataTeamV1::GetMp()
{
	return m_syncDataMember.GetMp();
}
void SyncDataTeamV1::SendMp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_MP,m_syncDataMember.GetMp());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_MP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_MP,m_syncDataMember.GetMp());
}

//Status
void SyncDataTeamV1::SetStatus( const INT32& v )
{
	m_syncDataMember.SetStatus(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataMember.GetKey(),SYNCID_TEAM_STATUS);
	SendStatus(false);
}
INT32 SyncDataTeamV1::GetStatus()
{
	return m_syncDataMember.GetStatus();
}
void SyncDataTeamV1::SendStatus(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_STATUS,m_syncDataMember.GetStatus());
	if(ModuleTeam::Instance().NotSyncToClient(SYNCID_TEAM_STATUS)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEAM_STATUS,m_syncDataMember.GetStatus());
}
