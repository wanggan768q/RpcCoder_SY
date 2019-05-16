#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class GGRpcGGChangeSceneNotifyWraperHelper
{
}



public class GGTestHelper : MonoBehaviour
{
	public GGRpcGGChangeSceneNotifyWraperHelper GGRpcGGChangeSceneNotifyWraperVar;




}

[CustomEditor(typeof(GGTestHelper))]
public class GGTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif