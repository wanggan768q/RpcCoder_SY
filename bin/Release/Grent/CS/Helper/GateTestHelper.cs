#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class GateRpcPingAskWraperHelper
{
	public UInt64 Sequence;
}



public class GateTestHelper : MonoBehaviour
{
	public GateRpcPingAskWraperHelper GateRpcPingAskWraperVar;


	public void TestPing()
	{
		GateRPC.Instance.Ping(GateRpcPingAskWraperVar.Sequence,delegate(object obj){});
	}


}

[CustomEditor(typeof(GateTestHelper))]
public class GateTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Ping"))
		{
			GateTestHelper rpc = target as GateTestHelper;
			if( rpc ) rpc.TestPing();
		}


    }

}
#endif