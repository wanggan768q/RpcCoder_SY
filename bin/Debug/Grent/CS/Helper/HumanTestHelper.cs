#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class HumanRpcMoveAskWraperHelper
{
	public float Dir;
	public float X;
	public float Z;
}
[System.Serializable]
public class HumanRpcStopMoveAskWraperHelper
{
	public float Dir;
	public float X;
	public float Z;
}
[System.Serializable]
public class HumanRpcMoveCheckNotifyWraperHelper
{
	public int Obj_id;
	public float Dir;
	public float X;
	public float Y;
}



public class HumanTestHelper : MonoBehaviour
{
	public HumanRpcMoveAskWraperHelper HumanRpcMoveAskWraperVar;
	public HumanRpcStopMoveAskWraperHelper HumanRpcStopMoveAskWraperVar;
	public HumanRpcMoveCheckNotifyWraperHelper HumanRpcMoveCheckNotifyWraperVar;


	public void TestMove()
	{
		HumanRPC.Instance.Move(HumanRpcMoveAskWraperVar.Dir,HumanRpcMoveAskWraperVar.X,HumanRpcMoveAskWraperVar.Z,delegate(object obj){});
	}
	public void TestStopMove()
	{
		HumanRPC.Instance.StopMove(HumanRpcStopMoveAskWraperVar.Dir,HumanRpcStopMoveAskWraperVar.X,HumanRpcStopMoveAskWraperVar.Z,delegate(object obj){});
	}
	public void TestMoveCheck()
	{
		HumanRPC.Instance.MoveCheck(HumanRpcMoveCheckNotifyWraperVar.Obj_id,HumanRpcMoveCheckNotifyWraperVar.Dir,HumanRpcMoveCheckNotifyWraperVar.X,HumanRpcMoveCheckNotifyWraperVar.Y);
	}


}

[CustomEditor(typeof(HumanTestHelper))]
public class HumanTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Move"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMove();
		}
		if (GUILayout.Button("StopMove"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestStopMove();
		}
		if (GUILayout.Button("MoveCheck"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMoveCheck();
		}


    }

}
#endif