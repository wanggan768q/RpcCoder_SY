#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class GameSettingRpcSyncGameSettingAskWraperHelper
{
}
[System.Serializable]
public class GameSettingRpcSettingAskWraperHelper
{
	public string GameSetting;
}
[System.Serializable]
public class GameSettingRpcGameSettingNotifyNotifyWraperHelper
{
	public string GameSetting;
}



public class GameSettingTestHelper : MonoBehaviour
{
	public GameSettingRpcSyncGameSettingAskWraperHelper GameSettingRpcSyncGameSettingAskWraperVar;
	public GameSettingRpcSettingAskWraperHelper GameSettingRpcSettingAskWraperVar;
	public GameSettingRpcGameSettingNotifyNotifyWraperHelper GameSettingRpcGameSettingNotifyNotifyWraperVar;


	public void TestSyncGameSetting()
	{
		GameSettingRPC.Instance.SyncGameSetting(delegate(object obj){});
	}
	public void TestSetting()
	{
		GameSettingRPC.Instance.Setting(GameSettingRpcSettingAskWraperVar.GameSetting,delegate(object obj){});
	}


}

[CustomEditor(typeof(GameSettingTestHelper))]
public class GameSettingTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncGameSetting"))
		{
			GameSettingTestHelper rpc = target as GameSettingTestHelper;
			if( rpc ) rpc.TestSyncGameSetting();
		}
		if (GUILayout.Button("Setting"))
		{
			GameSettingTestHelper rpc = target as GameSettingTestHelper;
			if( rpc ) rpc.TestSetting();
		}


    }

}
#endif