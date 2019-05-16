#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ServerModelRpcLoginAskWraperHelper
{
	public int Result;
	public int Type;
	public string TestString;
}



public class ServerModelTestHelper : MonoBehaviour
{
	public ServerModelRpcLoginAskWraperHelper ServerModelRpcLoginAskWraperVar;


	public void TestLogin()
	{
		ServerModelRPC.Instance.Login(ServerModelRpcLoginAskWraperVar.Result,ServerModelRpcLoginAskWraperVar.Type,ServerModelRpcLoginAskWraperVar.TestString,delegate(object obj){});
	}


}

[CustomEditor(typeof(ServerModelTestHelper))]
public class ServerModelTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Login"))
		{
			ServerModelTestHelper rpc = target as ServerModelTestHelper;
			if( rpc ) rpc.TestLogin();
		}


    }

}
#endif