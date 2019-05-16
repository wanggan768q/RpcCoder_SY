#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class CGAnimationRpcCgPlayAskWraperHelper
{
	public int CgId;
}
[System.Serializable]
public class CGAnimationRpcCgPlayNotifyNotifyWraperHelper
{
	public UInt64 RoleId;
	public int CgId;
}
[System.Serializable]
public class CGAnimationRpcCgOverNotifyNotifyWraperHelper
{
	public UInt64 RoleId;
	public int CgId;
}
[System.Serializable]
public class CGAnimationRpcCgSkipAskWraperHelper
{
}
[System.Serializable]
public class CGAnimationRpcScriptPlayNotifyWraperHelper
{
	public UInt64 CasterGuid;
	public string AnimantionName;
	public float Time;
	public int IsLoop;
	public int SingleTime;
}



public class CGAnimationTestHelper : MonoBehaviour
{
	public CGAnimationRpcCgPlayAskWraperHelper CGAnimationRpcCgPlayAskWraperVar;
	public CGAnimationRpcCgPlayNotifyNotifyWraperHelper CGAnimationRpcCgPlayNotifyNotifyWraperVar;
	public CGAnimationRpcCgOverNotifyNotifyWraperHelper CGAnimationRpcCgOverNotifyNotifyWraperVar;
	public CGAnimationRpcCgSkipAskWraperHelper CGAnimationRpcCgSkipAskWraperVar;
	public CGAnimationRpcScriptPlayNotifyWraperHelper CGAnimationRpcScriptPlayNotifyWraperVar;


	public void TestCgPlay()
	{
		CGAnimationRPC.Instance.CgPlay(CGAnimationRpcCgPlayAskWraperVar.CgId,delegate(object obj){});
	}
	public void TestCgSkip()
	{
		CGAnimationRPC.Instance.CgSkip(delegate(object obj){});
	}


}

[CustomEditor(typeof(CGAnimationTestHelper))]
public class CGAnimationTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("CgPlay"))
		{
			CGAnimationTestHelper rpc = target as CGAnimationTestHelper;
			if( rpc ) rpc.TestCgPlay();
		}
		if (GUILayout.Button("CgSkip"))
		{
			CGAnimationTestHelper rpc = target as CGAnimationTestHelper;
			if( rpc ) rpc.TestCgSkip();
		}


    }

}
#endif