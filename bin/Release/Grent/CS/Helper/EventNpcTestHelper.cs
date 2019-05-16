#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EventNpcRpcBeginEventAskWraperHelper
{
	public int EventIndex;
}
[System.Serializable]
public class EventNpcRpcEndEventAskWraperHelper
{
}
[System.Serializable]
public class EventNpcRpcActivityBeginNotifyWraperHelper
{
	public int StartTime;
	public int WayPoint;
}



public class EventNpcTestHelper : MonoBehaviour
{
	public EventNpcRpcBeginEventAskWraperHelper EventNpcRpcBeginEventAskWraperVar;
	public EventNpcRpcEndEventAskWraperHelper EventNpcRpcEndEventAskWraperVar;
	public EventNpcRpcActivityBeginNotifyWraperHelper EventNpcRpcActivityBeginNotifyWraperVar;


	public void TestBeginEvent()
	{
		EventNpcRPC.Instance.BeginEvent(EventNpcRpcBeginEventAskWraperVar.EventIndex,delegate(object obj){});
	}
	public void TestEndEvent()
	{
		EventNpcRPC.Instance.EndEvent(delegate(object obj){});
	}


}

[CustomEditor(typeof(EventNpcTestHelper))]
public class EventNpcTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("BeginEvent"))
		{
			EventNpcTestHelper rpc = target as EventNpcTestHelper;
			if( rpc ) rpc.TestBeginEvent();
		}
		if (GUILayout.Button("EndEvent"))
		{
			EventNpcTestHelper rpc = target as EventNpcTestHelper;
			if( rpc ) rpc.TestEndEvent();
		}


    }

}
#endif