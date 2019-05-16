#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ExpressionActionRpcSyncAskWraperHelper
{
}
[System.Serializable]
public class ExpressionActionRpcSetWheelAskWraperHelper
{
	public int Index;
	public int ActionId;
}
[System.Serializable]
public class ExpressionActionRpcUseActionAskWraperHelper
{
	public int ActionId;
}
[System.Serializable]
public class ExpressionActionRpcUseActionNotifyNotifyWraperHelper
{
	public int ObjId;
	public int ActionId;
}



public class ExpressionActionTestHelper : MonoBehaviour
{
	public ExpressionActionRpcSyncAskWraperHelper ExpressionActionRpcSyncAskWraperVar;
	public ExpressionActionRpcSetWheelAskWraperHelper ExpressionActionRpcSetWheelAskWraperVar;
	public ExpressionActionRpcUseActionAskWraperHelper ExpressionActionRpcUseActionAskWraperVar;
	public ExpressionActionRpcUseActionNotifyNotifyWraperHelper ExpressionActionRpcUseActionNotifyNotifyWraperVar;


	public void TestSync()
	{
		ExpressionActionRPC.Instance.Sync(delegate(object obj){});
	}
	public void TestSetWheel()
	{
		ExpressionActionRPC.Instance.SetWheel(ExpressionActionRpcSetWheelAskWraperVar.Index,ExpressionActionRpcSetWheelAskWraperVar.ActionId,delegate(object obj){});
	}
	public void TestUseAction()
	{
		ExpressionActionRPC.Instance.UseAction(ExpressionActionRpcUseActionAskWraperVar.ActionId,delegate(object obj){});
	}


}

[CustomEditor(typeof(ExpressionActionTestHelper))]
public class ExpressionActionTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Sync"))
		{
			ExpressionActionTestHelper rpc = target as ExpressionActionTestHelper;
			if( rpc ) rpc.TestSync();
		}
		if (GUILayout.Button("SetWheel"))
		{
			ExpressionActionTestHelper rpc = target as ExpressionActionTestHelper;
			if( rpc ) rpc.TestSetWheel();
		}
		if (GUILayout.Button("UseAction"))
		{
			ExpressionActionTestHelper rpc = target as ExpressionActionTestHelper;
			if( rpc ) rpc.TestUseAction();
		}


    }

}
#endif