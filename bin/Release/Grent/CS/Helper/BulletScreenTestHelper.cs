#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BulletScreenRpcBulletScreenOptAskWraperHelper
{
	public int BulletScreenType;
	public int OptType;
}
[System.Serializable]
public class BulletScreenRpcCGBulletScreenAskWraperHelper
{
	public int CGid;
}
[System.Serializable]
public class BulletScreenRpcSendBulletScreenCGAskWraperHelper
{
	public int CGid;
	public string Content;
}



public class BulletScreenTestHelper : MonoBehaviour
{
	public BulletScreenRpcBulletScreenOptAskWraperHelper BulletScreenRpcBulletScreenOptAskWraperVar;
	public BulletScreenRpcCGBulletScreenAskWraperHelper BulletScreenRpcCGBulletScreenAskWraperVar;
	public BulletScreenRpcSendBulletScreenCGAskWraperHelper BulletScreenRpcSendBulletScreenCGAskWraperVar;


	public void TestBulletScreenOpt()
	{
		BulletScreenRPC.Instance.BulletScreenOpt(BulletScreenRpcBulletScreenOptAskWraperVar.BulletScreenType,BulletScreenRpcBulletScreenOptAskWraperVar.OptType,delegate(object obj){});
	}
	public void TestCGBulletScreen()
	{
		BulletScreenRPC.Instance.CGBulletScreen(BulletScreenRpcCGBulletScreenAskWraperVar.CGid,delegate(object obj){});
	}
	public void TestSendBulletScreenCG()
	{
		BulletScreenRPC.Instance.SendBulletScreenCG(BulletScreenRpcSendBulletScreenCGAskWraperVar.CGid,BulletScreenRpcSendBulletScreenCGAskWraperVar.Content,delegate(object obj){});
	}


}

[CustomEditor(typeof(BulletScreenTestHelper))]
public class BulletScreenTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("BulletScreenOpt"))
		{
			BulletScreenTestHelper rpc = target as BulletScreenTestHelper;
			if( rpc ) rpc.TestBulletScreenOpt();
		}
		if (GUILayout.Button("CGBulletScreen"))
		{
			BulletScreenTestHelper rpc = target as BulletScreenTestHelper;
			if( rpc ) rpc.TestCGBulletScreen();
		}
		if (GUILayout.Button("SendBulletScreenCG"))
		{
			BulletScreenTestHelper rpc = target as BulletScreenTestHelper;
			if( rpc ) rpc.TestSendBulletScreenCG();
		}


    }

}
#endif