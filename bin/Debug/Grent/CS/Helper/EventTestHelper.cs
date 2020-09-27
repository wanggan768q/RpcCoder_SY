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
	public UInt64 ObjId;
	public Vector3Wraper Pos;
	public float Dir;
}
[System.Serializable]
public class EventRpcStopMoveNotifyWraperHelper
{
	public UInt64 ObjId;
	public Vector3IntWraper Pos;
	public float Dir;
	public int Type;
	public bool BrakeRush;
}
[System.Serializable]
public class EventRpcObjAttrChangeNotifyWraperHelper
{
	public float Speed;
	public Int64 Hp;
	public int Status;
	public int ConfigId;
	public UInt64 ObjId;
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
	public UInt64 ObjId;
	public List<Vector3IntWraper> PosList;
	public float Dir;
	public bool IsAllowChangeRunAnimation;
	public int Follow;
	public bool IsLookAtMoving;
	public int FromX;
	public int FromZ;
}
[System.Serializable]
public class EventRpcDirNotifyWraperHelper
{
	public UInt64 ObjId;
	public float Dir;
}
[System.Serializable]
public class EventRpcStartFadeoutNotifyWraperHelper
{
	public UInt64 ObjId;
}
[System.Serializable]
public class EventRpcCinematicStartNotifyWraperHelper
{
	public int Text;
}
[System.Serializable]
public class EventRpcCinematicEndNotifyWraperHelper
{
}



public class EventTestHelper : MonoBehaviour
{
	public EventRpcMoveNotifyWraperHelper EventRpcMoveNotifyWraperVar;
	public EventRpcStopMoveNotifyWraperHelper EventRpcStopMoveNotifyWraperVar;
	public EventRpcObjAttrChangeNotifyWraperHelper EventRpcObjAttrChangeNotifyWraperVar;
	public EventRpcCoinChangeNotifyWraperHelper EventRpcCoinChangeNotifyWraperVar;
	public EventRpcMovePosNotifyWraperHelper EventRpcMovePosNotifyWraperVar;
	public EventRpcDirNotifyWraperHelper EventRpcDirNotifyWraperVar;
	public EventRpcStartFadeoutNotifyWraperHelper EventRpcStartFadeoutNotifyWraperVar;
	public EventRpcCinematicStartNotifyWraperHelper EventRpcCinematicStartNotifyWraperVar;
	public EventRpcCinematicEndNotifyWraperHelper EventRpcCinematicEndNotifyWraperVar;




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