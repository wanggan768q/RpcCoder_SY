#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EventRpcMoveNotifyWraperHelper
{
	public int ObjId;
	public V3Wraper Pos;
	public float Dir;
}
[System.Serializable]
public class EventRpcStopMoveNotifyWraperHelper
{
	public int ObjId;
	public V3Wraper Pos;
	public float Dir;
}
[System.Serializable]
public class EventRpcObjAttrChangeNotifyWraperHelper
{
	public float Speed;
	public Int64 Hp;
	public int Status;
	public int ConfigId;
	public int ObjId;
}



public class EventTestHelper : MonoBehaviour
{
	public EventRpcMoveNotifyWraperHelper EventRpcMoveNotifyWraperVar;
	public EventRpcStopMoveNotifyWraperHelper EventRpcStopMoveNotifyWraperVar;
	public EventRpcObjAttrChangeNotifyWraperHelper EventRpcObjAttrChangeNotifyWraperVar;




}

[CustomEditor(typeof(EventTestHelper))]
public class EventTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif