#include "$Template$V$SyncDataVersion$Data.h"
#include "$Template$Module.h"


SyncData$Template$V$SyncDataVersion$::SyncData$Template$V$SyncDataVersion$()
{
	$SyncDataSetWraper$
}

SyncData$Template$V$SyncDataVersion$::~SyncData$Template$V$SyncDataVersion$()
{
}

void SyncData$Template$V$SyncDataVersion$::SendAllMembers(bool OnlyToClient)
{
$SendAllFields$
}


$SyncOpImp$