TortoiseProc.exe /command:update /path:"..\..\newsrv\Config\" /closeonend:1
TortoiseProc.exe /command:update /path:"..\..\client\unityCombat\Assets\Src\MLayer\Config\" /closeonend:1


copy /y Out\CPP\Config\*.* ..\..\newsrv\Config\
copy /y Out\CS\Config\*.*  ..\..\client\unityCombat\Assets\Src\MLayer\Config\

TortoiseProc.exe /command:commit /path:"..\..\newsrv\Config\" /closeonend:1
TortoiseProc.exe /command:commit /path:"..\..\client\unityCombat\Assets\Src\MLayer\Config\" /closeonend:1
