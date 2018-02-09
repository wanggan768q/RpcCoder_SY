#include "BagV1Data.h"
//#include "BagModule.h"
#include "Obj/Obj_Character/Obj_Character.h"

SyncDataBagV1::SyncDataBagV1(Obj_Character* pObj):m_bChange(false)
{
	//SetDataWraper( &m_syncDataItemData );
		m_oCaclPropertyCallbacks.emplace(SYNCID_BAG_GUID,std::move(std::bind(&Obj_Character::CalcGuid, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BAG_LOCK,std::move(std::bind(&Obj_Character::CalcLock, pObj)));
	m_oCaclPropertyCallbacks.emplace(SYNCID_BAG_OVERLAYCOUNT,std::move(std::bind(&Obj_Character::CalcOverlayCount, pObj)));

}

SyncDataBagV1::~SyncDataBagV1()
{
}

void SyncDataBagV1::Init()
{
		RefreshGuid();
	RefreshLock();
	RefreshOverlayCount();

	m_bChange = false;
}

void SyncDataBagV1::SetSendCallBack(const send_callback_type & cb)
{
	m_oSendCallback = cb;
}

void SyncDataBagV1::CalcAllMembers()
{
		GetGuid();
	GetLock();
	GetOverlayCount();

}

void SyncDataBagV1::SendAllMembers()
{
/**
	SendGuid(OnlyToClient);
	SendLock(OnlyToClient);
	SendOverlayCount(OnlyToClient);

**/
	CalcAllMembers();
	if (!m_bChange)
	{
		return;
	}
	if (m_oSendCallback)
	{
		m_oSendCallback(m_ClientDataUserData);
		m_bChange = false;
	}
	m_ClientDataUserData.Clear();
}



//Guid
void SyncDataBagV1::SetGuid( const INT32& v )
{
	m_syncDataItemData.SetGuid(v);
	m_ClientDataUserData.set_guid(v);
	m_bChange = true;
}
INT32 SyncDataBagV1::GetGuid()
{
	CalcMethodCB(SYNCID_BAG_GUID,std::bind(&SyncDataBagV1::SetGuid,this,std::placeholders::_1));
	return m_syncDataItemData.GetGuid();
}
void SyncDataBagV1::RefreshGuid()
{
	m_vCalcPropertyIds.insert(SYNCID_BAG_GUID);
}


//Lock
void SyncDataBagV1::SetLock( const bool& v )
{
	m_syncDataItemData.SetLock(v);
	m_ClientDataUserData.set_lock(v);
	m_bChange = true;
}
bool SyncDataBagV1::GetLock()
{
	CalcMethodCB(SYNCID_BAG_LOCK,std::bind(&SyncDataBagV1::SetLock,this,std::placeholders::_1));
	return m_syncDataItemData.GetLock();
}
void SyncDataBagV1::RefreshLock()
{
	m_vCalcPropertyIds.insert(SYNCID_BAG_LOCK);
}


//OverlayCount
void SyncDataBagV1::SetOverlayCount( const INT32& v )
{
	m_syncDataItemData.SetOverlayCount(v);
	m_ClientDataUserData.set_overlaycount(v);
	m_bChange = true;
}
INT32 SyncDataBagV1::GetOverlayCount()
{
	CalcMethodCB(SYNCID_BAG_OVERLAYCOUNT,std::bind(&SyncDataBagV1::SetOverlayCount,this,std::placeholders::_1));
	return m_syncDataItemData.GetOverlayCount();
}
void SyncDataBagV1::RefreshOverlayCount()
{
	m_vCalcPropertyIds.insert(SYNCID_BAG_OVERLAYCOUNT);
}

