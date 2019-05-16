#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BuinessRpcBuinessSyncAskWraperHelper
{
}
[System.Serializable]
public class BuinessRpcBuinessUnlockAskWraperHelper
{
	public int SkillID;
}
[System.Serializable]
public class BuinessRpcBuinessStudyAskWraperHelper
{
	public int SkillID;
	public int StudyType;
}
[System.Serializable]
public class BuinessRpcBuinessMakeAskWraperHelper
{
	public int SkillID;
}



public class BuinessTestHelper : MonoBehaviour
{
	public BuinessRpcBuinessSyncAskWraperHelper BuinessRpcBuinessSyncAskWraperVar;
	public BuinessRpcBuinessUnlockAskWraperHelper BuinessRpcBuinessUnlockAskWraperVar;
	public BuinessRpcBuinessStudyAskWraperHelper BuinessRpcBuinessStudyAskWraperVar;
	public BuinessRpcBuinessMakeAskWraperHelper BuinessRpcBuinessMakeAskWraperVar;


	public void TestBuinessSync()
	{
		BuinessRPC.Instance.BuinessSync(delegate(object obj){});
	}
	public void TestBuinessUnlock()
	{
		BuinessRPC.Instance.BuinessUnlock(BuinessRpcBuinessUnlockAskWraperVar.SkillID,delegate(object obj){});
	}
	public void TestBuinessStudy()
	{
		BuinessRPC.Instance.BuinessStudy(BuinessRpcBuinessStudyAskWraperVar.SkillID,BuinessRpcBuinessStudyAskWraperVar.StudyType,delegate(object obj){});
	}
	public void TestBuinessMake()
	{
		BuinessRPC.Instance.BuinessMake(BuinessRpcBuinessMakeAskWraperVar.SkillID,delegate(object obj){});
	}


}

[CustomEditor(typeof(BuinessTestHelper))]
public class BuinessTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("BuinessSync"))
		{
			BuinessTestHelper rpc = target as BuinessTestHelper;
			if( rpc ) rpc.TestBuinessSync();
		}
		if (GUILayout.Button("BuinessUnlock"))
		{
			BuinessTestHelper rpc = target as BuinessTestHelper;
			if( rpc ) rpc.TestBuinessUnlock();
		}
		if (GUILayout.Button("BuinessStudy"))
		{
			BuinessTestHelper rpc = target as BuinessTestHelper;
			if( rpc ) rpc.TestBuinessStudy();
		}
		if (GUILayout.Button("BuinessMake"))
		{
			BuinessTestHelper rpc = target as BuinessTestHelper;
			if( rpc ) rpc.TestBuinessMake();
		}


    }

}
#endif