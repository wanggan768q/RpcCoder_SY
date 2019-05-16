#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BaseAttrRpcSyncDataAskWraperHelper
{
}
[System.Serializable]
public class BaseAttrRpcSyncNotifyWraperHelper
{
	public int ObjId;
	public byte[] UpdateData;
}



public class BaseAttrTestHelper : MonoBehaviour
{
	public BaseAttrRpcSyncDataAskWraperHelper BaseAttrRpcSyncDataAskWraperVar;
	public BaseAttrRpcSyncNotifyWraperHelper BaseAttrRpcSyncNotifyWraperVar;


	public void TestSyncData()
	{
		BaseAttrRPC.Instance.SyncData(delegate(object obj){});
	}


}

[CustomEditor(typeof(BaseAttrTestHelper))]
public class BaseAttrTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncData"))
		{
			BaseAttrTestHelper rpc = target as BaseAttrTestHelper;
			if( rpc ) rpc.TestSyncData();
		}


    }

}
#endif