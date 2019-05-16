#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ActivityRpcEliteMonsterInfoNotifyWraperHelper
{
	public int State;
	public EliteMonsterInfoWraper Info;
}
[System.Serializable]
public class ActivityRpcCreateObjAskWraperHelper
{
	public int CommonId;
}
[System.Serializable]
public class ActivityRpcOpenActivityNotifyWraperHelper
{
	public int ActId;
	public int DiffTm;
	public int SceneId;
	public Vector3Wraper Pos;
}
[System.Serializable]
public class ActivityRpcXingyaoAskWraperHelper
{
	public int NPCid;
}
[System.Serializable]
public class ActivityRpcActivityTimeNotifyWraperHelper
{
	public List<ActivityTimeWraper> ActTimeList;
}
[System.Serializable]
public class ActivityRpcReqActivityTimeAskWraperHelper
{
}
[System.Serializable]
public class ActivityRpcXingyaoNPCAskWraperHelper
{
}
[System.Serializable]
public class ActivityRpcXingyaoRewardNotifyWraperHelper
{
}
[System.Serializable]
public class ActivityRpcOperationTimeNotifyWraperHelper
{
	public List<ActivityTimeWraper> ActTimeList;
}



public class ActivityTestHelper : MonoBehaviour
{
	public ActivityRpcEliteMonsterInfoNotifyWraperHelper ActivityRpcEliteMonsterInfoNotifyWraperVar;
	public ActivityRpcCreateObjAskWraperHelper ActivityRpcCreateObjAskWraperVar;
	public ActivityRpcOpenActivityNotifyWraperHelper ActivityRpcOpenActivityNotifyWraperVar;
	public ActivityRpcXingyaoAskWraperHelper ActivityRpcXingyaoAskWraperVar;
	public ActivityRpcActivityTimeNotifyWraperHelper ActivityRpcActivityTimeNotifyWraperVar;
	public ActivityRpcReqActivityTimeAskWraperHelper ActivityRpcReqActivityTimeAskWraperVar;
	public ActivityRpcXingyaoNPCAskWraperHelper ActivityRpcXingyaoNPCAskWraperVar;
	public ActivityRpcXingyaoRewardNotifyWraperHelper ActivityRpcXingyaoRewardNotifyWraperVar;
	public ActivityRpcOperationTimeNotifyWraperHelper ActivityRpcOperationTimeNotifyWraperVar;


	public void TestCreateObj()
	{
		ActivityRPC.Instance.CreateObj(ActivityRpcCreateObjAskWraperVar.CommonId,delegate(object obj){});
	}
	public void TestXingyao()
	{
		ActivityRPC.Instance.Xingyao(ActivityRpcXingyaoAskWraperVar.NPCid,delegate(object obj){});
	}
	public void TestReqActivityTime()
	{
		ActivityRPC.Instance.ReqActivityTime(delegate(object obj){});
	}
	public void TestXingyaoNPC()
	{
		ActivityRPC.Instance.XingyaoNPC(delegate(object obj){});
	}


}

[CustomEditor(typeof(ActivityTestHelper))]
public class ActivityTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("CreateObj"))
		{
			ActivityTestHelper rpc = target as ActivityTestHelper;
			if( rpc ) rpc.TestCreateObj();
		}
		if (GUILayout.Button("Xingyao"))
		{
			ActivityTestHelper rpc = target as ActivityTestHelper;
			if( rpc ) rpc.TestXingyao();
		}
		if (GUILayout.Button("ReqActivityTime"))
		{
			ActivityTestHelper rpc = target as ActivityTestHelper;
			if( rpc ) rpc.TestReqActivityTime();
		}
		if (GUILayout.Button("XingyaoNPC"))
		{
			ActivityTestHelper rpc = target as ActivityTestHelper;
			if( rpc ) rpc.TestXingyaoNPC();
		}


    }

}
#endif