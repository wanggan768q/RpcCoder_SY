#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class LoginRpcLoginAskWraperHelper
{
	public string Username;
	public string Passwd;
	public string SnId;
	public string GameId;
	public string Mac;
	public string Token;
}
[System.Serializable]
public class LoginRpcSelectCharacterAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class LoginRpcCreateCharacterAskWraperHelper
{
	public string Nickname;
	public int ConfigId;
}
[System.Serializable]
public class LoginRpcDeleteCharacterAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class LoginRpcTestAskWraperHelper
{
	public List<Int64> A;
	public List<UInt64> B;
}
[System.Serializable]
public class LoginRpcTest1AskWraperHelper
{
	public List<UInt64> B;
}
[System.Serializable]
public class LoginRpcLoginLineUpNotifyWraperHelper
{
	public int LineUpIndex;
}
[System.Serializable]
public class LoginRpcLoginEnterGameNotifyWraperHelper
{
	public UInt64 RoleID;
	public int LastSceneID;
	public int LineID;
}



public class LoginTestHelper : MonoBehaviour
{
	public LoginRpcLoginAskWraperHelper LoginRpcLoginAskWraperVar;
	public LoginRpcSelectCharacterAskWraperHelper LoginRpcSelectCharacterAskWraperVar;
	public LoginRpcCreateCharacterAskWraperHelper LoginRpcCreateCharacterAskWraperVar;
	public LoginRpcDeleteCharacterAskWraperHelper LoginRpcDeleteCharacterAskWraperVar;
	public LoginRpcTestAskWraperHelper LoginRpcTestAskWraperVar;
	public LoginRpcTest1AskWraperHelper LoginRpcTest1AskWraperVar;
	public LoginRpcLoginLineUpNotifyWraperHelper LoginRpcLoginLineUpNotifyWraperVar;
	public LoginRpcLoginEnterGameNotifyWraperHelper LoginRpcLoginEnterGameNotifyWraperVar;


	public void TestLogin()
	{
		LoginRPC.Instance.Login(LoginRpcLoginAskWraperVar.Username,LoginRpcLoginAskWraperVar.Passwd,LoginRpcLoginAskWraperVar.SnId,LoginRpcLoginAskWraperVar.GameId,LoginRpcLoginAskWraperVar.Mac,LoginRpcLoginAskWraperVar.Token,delegate(object obj){});
	}
	public void TestSelectCharacter()
	{
		LoginRPC.Instance.SelectCharacter(LoginRpcSelectCharacterAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestCreateCharacter()
	{
		LoginRPC.Instance.CreateCharacter(LoginRpcCreateCharacterAskWraperVar.Nickname,LoginRpcCreateCharacterAskWraperVar.ConfigId,delegate(object obj){});
	}
	public void TestDeleteCharacter()
	{
		LoginRPC.Instance.DeleteCharacter(LoginRpcDeleteCharacterAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestTest()
	{
		LoginRPC.Instance.Test(LoginRpcTestAskWraperVar.A,LoginRpcTestAskWraperVar.B,delegate(object obj){});
	}
	public void TestTest1()
	{
		LoginRPC.Instance.Test1(LoginRpcTest1AskWraperVar.B,delegate(object obj){});
	}


}

[CustomEditor(typeof(LoginTestHelper))]
public class LoginTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Login"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestLogin();
		}
		if (GUILayout.Button("SelectCharacter"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestSelectCharacter();
		}
		if (GUILayout.Button("CreateCharacter"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestCreateCharacter();
		}
		if (GUILayout.Button("DeleteCharacter"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestDeleteCharacter();
		}
		if (GUILayout.Button("Test"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestTest();
		}
		if (GUILayout.Button("Test1"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestTest1();
		}


    }

}
#endif