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
public class HumanRpcMovementVerificationAskWraperHelper
{
	public float Dir;
	public float X;
	public float Z;
}
[System.Serializable]
public class HumanRpcCGMoveCheckNotifyWraperHelper
{
	public float Dir;
	public V3Wraper Pos;
}
[System.Serializable]
public class HumanRpcGCMoveCheckNotifyWraperHelper
{
	public float Dir;
	public V3Wraper Pos;
}



public class HumanTestHelper : MonoBehaviour
{
	public HumanRpcMoveAskWraperHelper HumanRpcMoveAskWraperVar;
	public HumanRpcStopMoveAskWraperHelper HumanRpcStopMoveAskWraperVar;
	public HumanRpcMovementVerificationAskWraperHelper HumanRpcMovementVerificationAskWraperVar;
	public HumanRpcCGMoveCheckNotifyWraperHelper HumanRpcCGMoveCheckNotifyWraperVar;
	public HumanRpcGCMoveCheckNotifyWraperHelper HumanRpcGCMoveCheckNotifyWraperVar;


	public void TestMove()
	{
		HumanRPC.Instance.Move(HumanRpcMoveAskWraperVar.Dir,HumanRpcMoveAskWraperVar.X,HumanRpcMoveAskWraperVar.Z,delegate(object obj){});
	}
	public void TestStopMove()
	{
		HumanRPC.Instance.StopMove(HumanRpcStopMoveAskWraperVar.Dir,HumanRpcStopMoveAskWraperVar.X,HumanRpcStopMoveAskWraperVar.Z,delegate(object obj){});
	}
	public void TestMovementVerification()
	{
		HumanRPC.Instance.MovementVerification(HumanRpcMovementVerificationAskWraperVar.Dir,HumanRpcMovementVerificationAskWraperVar.X,HumanRpcMovementVerificationAskWraperVar.Z,delegate(object obj){});
	}
	public void TestCGMoveCheck()
	{
		HumanRPC.Instance.CGMoveCheck(HumanRpcCGMoveCheckNotifyWraperVar.Dir,HumanRpcCGMoveCheckNotifyWraperVar.Pos);
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
		if (GUILayout.Button("MovementVerification"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMovementVerification();
		}
		if (GUILayout.Button("CGMoveCheck"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestCGMoveCheck();
		}


    }

}
#endif