#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class LobbyServerRpcGetServerListAskWraperHelper
{
	public string Sdk_user_id;
}



public class LobbyServerTestHelper : MonoBehaviour
{
	public LobbyServerRpcGetServerListAskWraperHelper LobbyServerRpcGetServerListAskWraperVar;


	public void TestGetServerList()
	{
		LobbyServerRPC.Instance.GetServerList(LobbyServerRpcGetServerListAskWraperVar.Sdk_user_id,delegate(object obj){});
	}


}

[CustomEditor(typeof(LobbyServerTestHelper))]
public class LobbyServerTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("GetServerList"))
		{
			LobbyServerTestHelper rpc = target as LobbyServerTestHelper;
			if( rpc ) rpc.TestGetServerList();
		}


    }

}
#endif