#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class RidingRpcRidingAskWraperHelper
{
}
[System.Serializable]
public class RidingRpcUnRidingAskWraperHelper
{
}



public class RidingTestHelper : MonoBehaviour
{
	public RidingRpcRidingAskWraperHelper RidingRpcRidingAskWraperVar;
	public RidingRpcUnRidingAskWraperHelper RidingRpcUnRidingAskWraperVar;


	public void TestRiding()
	{
		RidingRPC.Instance.Riding(delegate(object obj){});
	}
	public void TestUnRiding()
	{
		RidingRPC.Instance.UnRiding(delegate(object obj){});
	}


}

[CustomEditor(typeof(RidingTestHelper))]
public class RidingTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Riding"))
		{
			RidingTestHelper rpc = target as RidingTestHelper;
			if( rpc ) rpc.TestRiding();
		}
		if (GUILayout.Button("UnRiding"))
		{
			RidingTestHelper rpc = target as RidingTestHelper;
			if( rpc ) rpc.TestUnRiding();
		}


    }

}
#endif