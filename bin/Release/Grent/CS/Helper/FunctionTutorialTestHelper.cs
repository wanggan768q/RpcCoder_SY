#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class FunctionTutorialRpcSyncFunctionStepAskWraperHelper
{
}
[System.Serializable]
public class FunctionTutorialRpcFinishStepAskWraperHelper
{
	public int FunctionID;
}
[System.Serializable]
public class FunctionTutorialRpcActiveStepAskWraperHelper
{
	public int FunctionID;
}



public class FunctionTutorialTestHelper : MonoBehaviour
{
	public FunctionTutorialRpcSyncFunctionStepAskWraperHelper FunctionTutorialRpcSyncFunctionStepAskWraperVar;
	public FunctionTutorialRpcFinishStepAskWraperHelper FunctionTutorialRpcFinishStepAskWraperVar;
	public FunctionTutorialRpcActiveStepAskWraperHelper FunctionTutorialRpcActiveStepAskWraperVar;


	public void TestSyncFunctionStep()
	{
		FunctionTutorialRPC.Instance.SyncFunctionStep(delegate(object obj){});
	}
	public void TestFinishStep()
	{
		FunctionTutorialRPC.Instance.FinishStep(FunctionTutorialRpcFinishStepAskWraperVar.FunctionID,delegate(object obj){});
	}
	public void TestActiveStep()
	{
		FunctionTutorialRPC.Instance.ActiveStep(FunctionTutorialRpcActiveStepAskWraperVar.FunctionID,delegate(object obj){});
	}


}

[CustomEditor(typeof(FunctionTutorialTestHelper))]
public class FunctionTutorialTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncFunctionStep"))
		{
			FunctionTutorialTestHelper rpc = target as FunctionTutorialTestHelper;
			if( rpc ) rpc.TestSyncFunctionStep();
		}
		if (GUILayout.Button("FinishStep"))
		{
			FunctionTutorialTestHelper rpc = target as FunctionTutorialTestHelper;
			if( rpc ) rpc.TestFinishStep();
		}
		if (GUILayout.Button("ActiveStep"))
		{
			FunctionTutorialTestHelper rpc = target as FunctionTutorialTestHelper;
			if( rpc ) rpc.TestActiveStep();
		}


    }

}
#endif