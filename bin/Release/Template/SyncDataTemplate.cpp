#include "$Template$V$SyncDataVersion$Data.h"
//#include "$Template$Module.h"
#include "Obj/Obj_Character/Obj_Character.h"
#include "Main/SyncOtherProperty.h"

SyncData$Template$V$SyncDataVersion$::SyncData$Template$V$SyncDataVersion$(Obj_Character* pObj):m_bChange(false),m_pObj(pObj)
{
	//$SyncDataSetWraper$
	$BindCalc$
}

SyncData$Template$V$SyncDataVersion$::~SyncData$Template$V$SyncDataVersion$()
{
}

void SyncData$Template$V$SyncDataVersion$::Init()
{
	RefreshAll();
	m_bChange = false;
	m_bOtherChange = false;
}

void SyncData$Template$V$SyncDataVersion$::InitEx()
{
	Init();
	CalcChangeMethodCB();
	m_ClientDataUserData.Clear();
	m_OtherDataUserData.Clear();
	m_bChange = false;
	m_bOtherChange = false;
}

void SyncData$Template$V$SyncDataVersion$::RefreshAll()
{
	$RefreshField$
}

void SyncData$Template$V$SyncDataVersion$::SetSendCallBack(const send_callback_type & cb)
{
	m_oSendCallback = cb;
}

void  SyncData$Template$V$SyncDataVersion$::SetSendOtherCallBack(const send_callback_type & cb)
{
	m_oSendOtherCallback = cb;
}

void SyncData$Template$V$SyncDataVersion$::CalcAllMembers()
{
	$GetField$
}

void SyncData$Template$V$SyncDataVersion$::SendAllMembers()
{
/**
$SendAllFields$
**/
	if (!m_pObj->GetLoadComplte())
    {
        return;
    }
	CalcChangeMethodCB();
	if (!m_bChange)
	{
		return;
	}
	if (m_oSendCallback)
	{
		m_bChange = false;
		m_oSendCallback(m_ClientDataUserData);
		m_ClientDataUserData.Clear();

	}

}

void SyncData$Template$V$SyncDataVersion$::SendToOthers()
{
	CalcChangeMethodCB();
	if (!m_bOtherChange)
		return;
	if (m_oSendOtherCallback)
	{
		m_bOtherChange = false;
		m_oSendOtherCallback(m_OtherDataUserData);

	}
	m_OtherDataUserData.Clear();
}

Property SyncData$Template$V$SyncDataVersion$::GetAttrByType(int attrType)
{
	switch(attrType)
	{
$GetAttrByType$
	}
	return 0;
}

void 	SyncData$Template$V$SyncDataVersion$::GetCompletePlayerData($Template$UserDataV1& base)
{

	$CompleteData$

	
}



$SyncOpImp$