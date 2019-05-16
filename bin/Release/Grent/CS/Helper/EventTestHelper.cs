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
	public Vector3Wraper Pos;
	public float Dir;
}
[System.Serializable]
public class EventRpcStopMoveNotifyWraperHelper
{
	public int ObjId;
	public Vector3IntWraper Pos;
	public float Dir;
	public int Type;
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
[System.Serializable]
public class EventRpcCoinChangeNotifyWraperHelper
{
	public int Type;
	public int Value;
}
[System.Serializable]
public class EventRpcMovePosNotifyWraperHelper
{
	public int ObjId;
	public List<Vector3IntWraper> PosList;
	public float Dir;
	public bool IsAllowChangeRunAnimation;
	public int Follow;
}



public class EventTestHelper : MonoBehaviour
{
	public EventRpcMoveNotifyWraperHelper EventRpcMoveNotifyWraperVar;
	public EventRpcStopMoveNotifyWraperHelper EventRpcStopMoveNotifyWraperVar;
	public EventRpcObjAttrChangeNotifyWraperHelper EventRpcObjAttrChangeNotifyWraperVar;
	public EventRpcCoinChangeNotifyWraperHelper EventRpcCoinChangeNotifyWraperVar;
	public EventRpcMovePosNotifyWraperHelper EventRpcMovePosNotifyWraperVar;




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