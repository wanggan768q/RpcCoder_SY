TortoiseProc.exe /command:update /path:"..\..\client\unityCombat\Assets\SubAssets\Res\" /closeonend:1
TortoiseProc.exe /command:update /path:"..\..\client\unityCombat\Assets\StreamingAssets\" /closeonend:1

copy /y ..\..\client\unityCombat\Assets\SubAssets\Res\ActionData\*.bytes ..\..\client\unityCombat\Assets\StreamingAssets\ActionData\
copy /y ..\..\client\unityCombat\Assets\SubAssets\Res\LevelData\*.bytes  ..\..\client\unityCombat\Assets\StreamingAssets\LevelData\
TortoiseProc.exe /command:commit /path:"..\..\client\unityCombat\Assets\StreamingAssets\" /closeonend:1

copy /y ..\..\client\unityCombat\Assets\SubAssets\Res\ActionData\*.bytes ..\..\newsrv\bin\ActionData\
copy /y ..\..\client\unityCombat\Assets\SubAssets\Res\LevelData\*.bytes  ..\..\newsrv\bin\LevelData\
copy /y ..\..\client\unityCombat\Assets\SubAssets\Res\Pos\*.xyz ..\..\newsrv\bin\ActionData\

TortoiseProc.exe /command:commit /path:"..\..\newsrv\bin\ActionData\" /closeonend:1
TortoiseProc.exe /command:commit /path:"..\..\newsrv\bin\LevelData\" /closeonend:1
