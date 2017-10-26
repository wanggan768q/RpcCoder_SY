#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class LoginRpcConnectAskWraperHelper
{
	public int Type;
}
[System.Serializable]
public class LoginRpcLoginAskWraperHelper
{
	public string Username;
	public string Passwd;
}



public class LoginTestHelper : MonoBehaviour
{
	public LoginRpcConnectAskWraperHelper LoginRpcConnectAskWraperVar;
	public LoginRpcLoginAskWraperHelper LoginRpcLoginAskWraperVar;


	public void TestConnect()
	{
		LoginRPC.Instance.Connect(LoginRpcConnectAskWraperVar.Type,delegate(object obj){});
	}
	public void TestLogin()
	{
		LoginRPC.Instance.Login(LoginRpcLoginAskWraperVar.Username,LoginRpcLoginAskWraperVar.Passwd,delegate(object obj){});
	}


}

[CustomEditor(typeof(LoginTestHelper))]
public class LoginTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Connect"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestConnect();
		}
		if (GUILayout.Button("Login"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestLogin();
		}


    }

}
#endif