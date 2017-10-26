#include "TestV1Data.h"
#include "TestModule.h"


SyncDataTestV1::SyncDataTestV1()
{
	SetDataWraper( &m_syncDataUser );
}

SyncDataTestV1::~SyncDataTestV1()
{
}

void SyncDataTestV1::SendAllMembers(bool OnlyToClient)
{
	SendHp(OnlyToClient);

}



//hp
void SyncDataTestV1::SetHp( const INT32& v )
{
	m_syncDataUser.SetHp(v);
	OnDataChange();
	ModuleTest::Instance().NotifySyncValueChanged(m_syncDataUser.GetKey(),SYNCID_TEST_HP);
	SendHp(false);
}
INT32 SyncDataTestV1::GetHp()
{
	return m_syncDataUser.GetHp();
}
void SyncDataTestV1::SendHp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEST_HP,m_syncDataUser.GetHp());
	if(ModuleTest::Instance().NotSyncToClient(SYNCID_TEST_HP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TEST_HP,m_syncDataUser.GetHp());
}
