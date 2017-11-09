#include "BaseAttrV1Data.h"
#include "BaseAttrModule.h"


SyncDataBaseAttrV1::SyncDataBaseAttrV1()
{
	SetDataWraper( &m_syncDataUserData );
}

SyncDataBaseAttrV1::~SyncDataBaseAttrV1()
{
}

void SyncDataBaseAttrV1::SendAllMembers(bool OnlyToClient)
{
	SendExp(OnlyToClient);
	SendLevel(OnlyToClient);
	SendServerTime(OnlyToClient);
	SendRoleId(OnlyToClient);

}



//经验
void SyncDataBaseAttrV1::SetExp( const INT32& v )
{
	m_syncDataUserData.SetExp(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_EXP);
	SendExp(false);
}
INT32 SyncDataBaseAttrV1::GetExp()
{
	return m_syncDataUserData.GetExp();
}
void SyncDataBaseAttrV1::SendExp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_EXP,m_syncDataUserData.GetExp());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_EXP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_EXP,m_syncDataUserData.GetExp());
}

//玩家等级
void SyncDataBaseAttrV1::SetLevel( const INT32& v )
{
	m_syncDataUserData.SetLevel(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_LEVEL);
	SendLevel(false);
}
INT32 SyncDataBaseAttrV1::GetLevel()
{
	return m_syncDataUserData.GetLevel();
}
void SyncDataBaseAttrV1::SendLevel(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_LEVEL,m_syncDataUserData.GetLevel());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_LEVEL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_LEVEL,m_syncDataUserData.GetLevel());
}

//服务器时间
void SyncDataBaseAttrV1::SetServerTime( const INT32& v )
{
	m_syncDataUserData.SetServerTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SERVERTIME);
	SendServerTime(false);
}
INT32 SyncDataBaseAttrV1::GetServerTime()
{
	return m_syncDataUserData.GetServerTime();
}
void SyncDataBaseAttrV1::SendServerTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SERVERTIME,m_syncDataUserData.GetServerTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SERVERTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SERVERTIME,m_syncDataUserData.GetServerTime());
}

//人物唯一ID
void SyncDataBaseAttrV1::SetRoleId( const INT32& v )
{
	m_syncDataUserData.SetRoleId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_ROLEID);
	SendRoleId(false);
}
INT32 SyncDataBaseAttrV1::GetRoleId()
{
	return m_syncDataUserData.GetRoleId();
}
void SyncDataBaseAttrV1::SendRoleId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_ROLEID,m_syncDataUserData.GetRoleId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_ROLEID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_ROLEID,m_syncDataUserData.GetRoleId());
}
