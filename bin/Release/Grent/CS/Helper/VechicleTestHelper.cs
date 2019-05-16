#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class VechicleRpcQuitVechileAskWraperHelper
{
}



public class VechicleTestHelper : MonoBehaviour
{
	public VechicleRpcQuitVechileAskWraperHelper VechicleRpcQuitVechileAskWraperVar;


	public void TestQuitVechile()
	{
		VechicleRPC.Instance.QuitVechile(delegate(object obj){});
	}


}

[CustomEditor(typeof(VechicleTestHelper))]
public class VechicleTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("QuitVechile"))
		{
			VechicleTestHelper rpc = target as VechicleTestHelper;
			if( rpc ) rpc.TestQuitVechile();
		}


    }

}
#endif