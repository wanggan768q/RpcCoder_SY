#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class MailRpcInitMailAskWraperHelper
{
}
[System.Serializable]
public class MailRpcReadMailAskWraperHelper
{
	public int Mail_type;
	public int Mail_id;
}
[System.Serializable]
public class MailRpcDeleteMailAskWraperHelper
{
	public int Mail_type;
	public int Mail_id;
}
[System.Serializable]
public class MailRpcGetMailAskWraperHelper
{
	public int Mail_type;
	public int Mail_id;
}
[System.Serializable]
public class MailRpcSyncMailInfoNotifyWraperHelper
{
	public List<MailInfoWraper> InfoList;
	public List<UInt64> GuidList;
}



public class MailTestHelper : MonoBehaviour
{
	public MailRpcInitMailAskWraperHelper MailRpcInitMailAskWraperVar;
	public MailRpcReadMailAskWraperHelper MailRpcReadMailAskWraperVar;
	public MailRpcDeleteMailAskWraperHelper MailRpcDeleteMailAskWraperVar;
	public MailRpcGetMailAskWraperHelper MailRpcGetMailAskWraperVar;
	public MailRpcSyncMailInfoNotifyWraperHelper MailRpcSyncMailInfoNotifyWraperVar;


	public void TestInitMail()
	{
		MailRPC.Instance.InitMail(delegate(object obj){});
	}
	public void TestReadMail()
	{
		MailRPC.Instance.ReadMail(MailRpcReadMailAskWraperVar.Mail_type,MailRpcReadMailAskWraperVar.Mail_id,delegate(object obj){});
	}
	public void TestDeleteMail()
	{
		MailRPC.Instance.DeleteMail(MailRpcDeleteMailAskWraperVar.Mail_type,MailRpcDeleteMailAskWraperVar.Mail_id,delegate(object obj){});
	}
	public void TestGetMail()
	{
		MailRPC.Instance.GetMail(MailRpcGetMailAskWraperVar.Mail_type,MailRpcGetMailAskWraperVar.Mail_id,delegate(object obj){});
	}


}

[CustomEditor(typeof(MailTestHelper))]
public class MailTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("InitMail"))
		{
			MailTestHelper rpc = target as MailTestHelper;
			if( rpc ) rpc.TestInitMail();
		}
		if (GUILayout.Button("ReadMail"))
		{
			MailTestHelper rpc = target as MailTestHelper;
			if( rpc ) rpc.TestReadMail();
		}
		if (GUILayout.Button("DeleteMail"))
		{
			MailTestHelper rpc = target as MailTestHelper;
			if( rpc ) rpc.TestDeleteMail();
		}
		if (GUILayout.Button("GetMail"))
		{
			MailTestHelper rpc = target as MailTestHelper;
			if( rpc ) rpc.TestGetMail();
		}


    }

}
#endif