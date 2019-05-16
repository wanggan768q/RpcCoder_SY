#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ItemOperationRpcItemResolveSettingSyncAskWraperHelper
{
}
[System.Serializable]
public class ItemOperationRpcItemResolveAskWraperHelper
{
	public int ItemPos;
	public int Count;
}
[System.Serializable]
public class ItemOperationRpcChangeSettingAskWraperHelper
{
	public List<ItemResolveDataWraper> SettingList;
}
[System.Serializable]
public class ItemOperationRpcBatchResolveAskWraperHelper
{
	public int Qulity;
}
[System.Serializable]
public class ItemOperationRpcItemCompoundAskWraperHelper
{
	public int ItemConfID;
}



public class ItemOperationTestHelper : MonoBehaviour
{
	public ItemOperationRpcItemResolveSettingSyncAskWraperHelper ItemOperationRpcItemResolveSettingSyncAskWraperVar;
	public ItemOperationRpcItemResolveAskWraperHelper ItemOperationRpcItemResolveAskWraperVar;
	public ItemOperationRpcChangeSettingAskWraperHelper ItemOperationRpcChangeSettingAskWraperVar;
	public ItemOperationRpcBatchResolveAskWraperHelper ItemOperationRpcBatchResolveAskWraperVar;
	public ItemOperationRpcItemCompoundAskWraperHelper ItemOperationRpcItemCompoundAskWraperVar;


	public void TestItemResolveSettingSync()
	{
		ItemOperationRPC.Instance.ItemResolveSettingSync(delegate(object obj){});
	}
	public void TestItemResolve()
	{
		ItemOperationRPC.Instance.ItemResolve(ItemOperationRpcItemResolveAskWraperVar.ItemPos,ItemOperationRpcItemResolveAskWraperVar.Count,delegate(object obj){});
	}
	public void TestChangeSetting()
	{
		ItemOperationRPC.Instance.ChangeSetting(ItemOperationRpcChangeSettingAskWraperVar.SettingList,delegate(object obj){});
	}
	public void TestBatchResolve()
	{
		ItemOperationRPC.Instance.BatchResolve(ItemOperationRpcBatchResolveAskWraperVar.Qulity,delegate(object obj){});
	}
	public void TestItemCompound()
	{
		ItemOperationRPC.Instance.ItemCompound(ItemOperationRpcItemCompoundAskWraperVar.ItemConfID,delegate(object obj){});
	}


}

[CustomEditor(typeof(ItemOperationTestHelper))]
public class ItemOperationTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("ItemResolveSettingSync"))
		{
			ItemOperationTestHelper rpc = target as ItemOperationTestHelper;
			if( rpc ) rpc.TestItemResolveSettingSync();
		}
		if (GUILayout.Button("ItemResolve"))
		{
			ItemOperationTestHelper rpc = target as ItemOperationTestHelper;
			if( rpc ) rpc.TestItemResolve();
		}
		if (GUILayout.Button("ChangeSetting"))
		{
			ItemOperationTestHelper rpc = target as ItemOperationTestHelper;
			if( rpc ) rpc.TestChangeSetting();
		}
		if (GUILayout.Button("BatchResolve"))
		{
			ItemOperationTestHelper rpc = target as ItemOperationTestHelper;
			if( rpc ) rpc.TestBatchResolve();
		}
		if (GUILayout.Button("ItemCompound"))
		{
			ItemOperationTestHelper rpc = target as ItemOperationTestHelper;
			if( rpc ) rpc.TestItemCompound();
		}


    }

}
#endif