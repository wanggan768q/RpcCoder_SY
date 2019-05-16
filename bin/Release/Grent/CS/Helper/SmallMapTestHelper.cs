#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SmallMapRpcNewObjNotifyWraperHelper
{
	public int ObjId;
	public int DataId;
	public Vector3Wraper WorldPos;
}
[System.Serializable]
public class SmallMapRpcDelObjNotifyWraperHelper
{
	public int ObjId;
}



public class SmallMapTestHelper : MonoBehaviour
{
	public SmallMapRpcNewObjNotifyWraperHelper SmallMapRpcNewObjNotifyWraperVar;
	public SmallMapRpcDelObjNotifyWraperHelper SmallMapRpcDelObjNotifyWraperVar;




}

[CustomEditor(typeof(SmallMapTestHelper))]
public class SmallMapTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif