TortoiseProc.exe /command:update /path:"..\..\newsrv\C30BattleNode\Fight\" /closeonend:1
TortoiseProc.exe /command:update /path:"..\..\newsrv\PB\" /closeonend:1

copy /y ..\..\cscommon\RpcCoder\Out\CPP\Fight\Action.cpp ..\..\newsrv\C30BattleNode\Fight\
copy /y ..\..\cscommon\RpcCoder\Out\CPP\Fight\Action.h ..\..\newsrv\C30BattleNode\Fight\
copy /y ..\..\cscommon\RpcCoder\Out\CPP\Fight\FightRpc.pb.cc ..\..\newsrv\C30BattleNode\Fight\
copy /y ..\..\cscommon\RpcCoder\Out\CPP\Fight\FightRpc.pb.h ..\..\newsrv\C30BattleNode\Fight\
copy /y ..\..\cscommon\RpcCoder\Out\CPP\Fight\FightRpcWraper.h ..\..\newsrv\C30BattleNode\Fight\
copy /y ..\..\cscommon\RpcCoder\Out\CPP\PB\*.* ..\..\newsrv\PB\
TortoiseProc.exe /command:commit /path:"..\..\newsrv\C30BattleNode\Fight\" /closeonend:1
TortoiseProc.exe /command:commit /path:"..\..\newsrv\PB\" /closeonend:1


TortoiseProc.exe /command:update /path:"..\..\client\unityCombat\Assets\Src\MLayer\PB\" /closeonend:1
copy /y ..\..\cscommon\RpcCoder\Out\CS\PB\FightRpcWraper.cs ..\..\client\unityCombat\Assets\Src\MLayer\PB\
copy /y ..\..\cscommon\RpcCoder\Out\CS\PB\FightRpc.cs ..\..\client\unityCombat\Assets\Src\MLayer\PB\
copy /y ..\..\cscommon\RpcCoder\Out\CS\PB\Action.cs ..\..\client\unityCombat\Assets\Src\MLayer\PB\
copy /y ..\..\cscommon\RpcCoder\Out\CS\PB\PublicStructWraper.cs ..\..\client\unityCombat\Assets\Src\MLayer\PB\
copy /y ..\..\cscommon\RpcCoder\Out\CS\PB\PublicStruct.cs ..\..\client\unityCombat\Assets\Src\MLayer\PB\
TortoiseProc.exe /command:commit /path:"..\..\client\unityCombat\Assets\Src\MLayer\PB\" /closeonend:1

