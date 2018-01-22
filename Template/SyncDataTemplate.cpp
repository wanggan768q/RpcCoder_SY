#include "$Template$V$SyncDataVersion$Data.h"
//#include "$Template$Module.h"
#include "Obj/Obj_Character/Obj_Character.h"

SyncData$Template$V$SyncDataVersion$::SyncData$Template$V$SyncDataVersion$(Obj_Character* pObj):m_bChange(false)
{
	//$SyncDataSetWraper$
	$BindCalc$
}

SyncData$Template$V$SyncDataVersion$::~SyncData$Template$V$SyncDataVersion$()
{
}

void SyncData$Template$V$SyncDataVersion$::Init()
{
	$RefreshField$
	m_bChange = false;
}

void SyncData$Template$V$SyncDataVersion$::SetSendCallBack(const send_callback_type & cb)
{
	m_oSendCallback = cb;
}

void SyncData$Template$V$SyncDataVersion$::SendAllMembers()
{
/*
$SendAllFields$
*/
$GetField$
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


$SyncOpImp$