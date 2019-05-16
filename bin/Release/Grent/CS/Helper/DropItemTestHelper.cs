#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class DropItemRpcDropTtemsNotifyWraperHelper
{
	public List<DropItemWraper> Dropitems;
	public int KillObjID;
	public int KillerObjID;
	public int OwnerObjID;
	public Vector3Wraper Pos;
	public int NetWorkType;
}



public class DropItemTestHelper : MonoBehaviour
{
	public DropItemRpcDropTtemsNotifyWraperHelper DropItemRpcDropTtemsNotifyWraperVar;




}

[CustomEditor(typeof(DropItemTestHelper))]
public class DropItemTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif