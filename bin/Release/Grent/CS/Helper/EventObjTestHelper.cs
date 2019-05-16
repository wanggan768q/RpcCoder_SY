#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EventObjRpcEventBeginAskWraperHelper
{
	public int ObjId;
}
[System.Serializable]
public class EventObjRpcEventEndAskWraperHelper
{
	public int ObjId;
}
[System.Serializable]
public class EventObjRpcEventStopAskWraperHelper
{
	public int ObjId;
}
[System.Serializable]
public class EventObjRpcEventStopNotifyNotifyWraperHelper
{
}



public class EventObjTestHelper : MonoBehaviour
{
	public EventObjRpcEventBeginAskWraperHelper EventObjRpcEventBeginAskWraperVar;
	public EventObjRpcEventEndAskWraperHelper EventObjRpcEventEndAskWraperVar;
	public EventObjRpcEventStopAskWraperHelper EventObjRpcEventStopAskWraperVar;
	public EventObjRpcEventStopNotifyNotifyWraperHelper EventObjRpcEventStopNotifyNotifyWraperVar;


	public void TestEventBegin()
	{
		EventObjRPC.Instance.EventBegin(EventObjRpcEventBeginAskWraperVar.ObjId,delegate(object obj){});
	}
	public void TestEventEnd()
	{
		EventObjRPC.Instance.EventEnd(EventObjRpcEventEndAskWraperVar.ObjId,delegate(object obj){});
	}
	public void TestEventStop()
	{
		EventObjRPC.Instance.EventStop(EventObjRpcEventStopAskWraperVar.ObjId,delegate(object obj){});
	}


}

[CustomEditor(typeof(EventObjTestHelper))]
public class EventObjTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("EventBegin"))
		{
			EventObjTestHelper rpc = target as EventObjTestHelper;
			if( rpc ) rpc.TestEventBegin();
		}
		if (GUILayout.Button("EventEnd"))
		{
			EventObjTestHelper rpc = target as EventObjTestHelper;
			if( rpc ) rpc.TestEventEnd();
		}
		if (GUILayout.Button("EventStop"))
		{
			EventObjTestHelper rpc = target as EventObjTestHelper;
			if( rpc ) rpc.TestEventStop();
		}


    }

}
#endif