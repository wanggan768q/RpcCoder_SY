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
[System.Serializable]
public class LoginRpcCharacterListAskWraperHelper
{
	public string Accountname ;
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



public class LoginTestHelper : MonoBehaviour
{
	public LoginRpcConnectAskWraperHelper LoginRpcConnectAskWraperVar;
	public LoginRpcLoginAskWraperHelper LoginRpcLoginAskWraperVar;
	public LoginRpcCharacterListAskWraperHelper LoginRpcCharacterListAskWraperVar;
	public LoginRpcSelectCharacterAskWraperHelper LoginRpcSelectCharacterAskWraperVar;
	public LoginRpcCreateCharacterAskWraperHelper LoginRpcCreateCharacterAskWraperVar;


	public void TestConnect()
	{
		LoginRPC.Instance.Connect(LoginRpcConnectAskWraperVar.Type,delegate(object obj){});
	}
	public void TestLogin()
	{
		LoginRPC.Instance.Login(LoginRpcLoginAskWraperVar.Username,LoginRpcLoginAskWraperVar.Passwd,delegate(object obj){});
	}
	public void TestCharacterList()
	{
		LoginRPC.Instance.CharacterList(LoginRpcCharacterListAskWraperVar.Accountname ,delegate(object obj){});
	}
	public void TestSelectCharacter()
	{
		LoginRPC.Instance.SelectCharacter(LoginRpcSelectCharacterAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestCreateCharacter()
	{
		LoginRPC.Instance.CreateCharacter(LoginRpcCreateCharacterAskWraperVar.Nickname,LoginRpcCreateCharacterAskWraperVar.ConfigId,delegate(object obj){});
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
		if (GUILayout.Button("CharacterList"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestCharacterList();
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


    }

}
#endif