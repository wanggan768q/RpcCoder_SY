#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class MercenaryRpcInQueueAskWraperHelper
{
	public int Id;
}
[System.Serializable]
public class MercenaryRpcOutQueueAskWraperHelper
{
	public int Id;
}
[System.Serializable]
public class MercenaryRpcAutoSetAskWraperHelper
{
}
[System.Serializable]
public class MercenaryRpcInfoAskWraperHelper
{
}



public class MercenaryTestHelper : MonoBehaviour
{
	public MercenaryRpcInQueueAskWraperHelper MercenaryRpcInQueueAskWraperVar;
	public MercenaryRpcOutQueueAskWraperHelper MercenaryRpcOutQueueAskWraperVar;
	public MercenaryRpcAutoSetAskWraperHelper MercenaryRpcAutoSetAskWraperVar;
	public MercenaryRpcInfoAskWraperHelper MercenaryRpcInfoAskWraperVar;


	public void TestInQueue()
	{
		MercenaryRPC.Instance.InQueue(MercenaryRpcInQueueAskWraperVar.Id,delegate(object obj){});
	}
	public void TestOutQueue()
	{
		MercenaryRPC.Instance.OutQueue(MercenaryRpcOutQueueAskWraperVar.Id,delegate(object obj){});
	}
	public void TestAutoSet()
	{
		MercenaryRPC.Instance.AutoSet(delegate(object obj){});
	}
	public void TestInfo()
	{
		MercenaryRPC.Instance.Info(delegate(object obj){});
	}


}

[CustomEditor(typeof(MercenaryTestHelper))]
public class MercenaryTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("InQueue"))
		{
			MercenaryTestHelper rpc = target as MercenaryTestHelper;
			if( rpc ) rpc.TestInQueue();
		}
		if (GUILayout.Button("OutQueue"))
		{
			MercenaryTestHelper rpc = target as MercenaryTestHelper;
			if( rpc ) rpc.TestOutQueue();
		}
		if (GUILayout.Button("AutoSet"))
		{
			MercenaryTestHelper rpc = target as MercenaryTestHelper;
			if( rpc ) rpc.TestAutoSet();
		}
		if (GUILayout.Button("Info"))
		{
			MercenaryTestHelper rpc = target as MercenaryTestHelper;
			if( rpc ) rpc.TestInfo();
		}


    }

}
#endif