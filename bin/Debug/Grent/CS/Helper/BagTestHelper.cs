#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BagRpcUseItemAskWraperHelper
{
	public int Count;
	public int Pos;
}
[System.Serializable]
public class BagRpcSyncAskWraperHelper
{
}
[System.Serializable]
public class BagRpcSaleItemAskWraperHelper
{
	public int Pos;
	public int Count;
}
[System.Serializable]
public class BagRpcLockItemAskWraperHelper
{
	public int Pos;
	public bool IsLock;
}
[System.Serializable]
public class BagRpcDeblockingAskWraperHelper
{
	public int BagType;
}
[System.Serializable]
public class BagRpcTakeItemAskWraperHelper
{
	public int FromBagType;
	public int ToBagType;
	public int FromPos;
}
[System.Serializable]
public class BagRpcTidyAskWraperHelper
{
	public int BagType;
}
[System.Serializable]
public class BagRpcTakeAllBackBagsAskWraperHelper
{
}
[System.Serializable]
public class BagRpcBagChangeNotifyWraperHelper
{
	public int Result;
	public BagDataWraper Bags;
}



public class BagTestHelper : MonoBehaviour
{
	public BagRpcUseItemAskWraperHelper BagRpcUseItemAskWraperVar;
	public BagRpcSyncAskWraperHelper BagRpcSyncAskWraperVar;
	public BagRpcSaleItemAskWraperHelper BagRpcSaleItemAskWraperVar;
	public BagRpcLockItemAskWraperHelper BagRpcLockItemAskWraperVar;
	public BagRpcDeblockingAskWraperHelper BagRpcDeblockingAskWraperVar;
	public BagRpcTakeItemAskWraperHelper BagRpcTakeItemAskWraperVar;
	public BagRpcTidyAskWraperHelper BagRpcTidyAskWraperVar;
	public BagRpcTakeAllBackBagsAskWraperHelper BagRpcTakeAllBackBagsAskWraperVar;
	public BagRpcBagChangeNotifyWraperHelper BagRpcBagChangeNotifyWraperVar;


	public void TestUseItem()
	{
		BagRPC.Instance.UseItem(BagRpcUseItemAskWraperVar.Count,BagRpcUseItemAskWraperVar.Pos,delegate(object obj){});
	}
	public void TestSync()
	{
		BagRPC.Instance.Sync(delegate(object obj){});
	}
	public void TestSaleItem()
	{
		BagRPC.Instance.SaleItem(BagRpcSaleItemAskWraperVar.Pos,BagRpcSaleItemAskWraperVar.Count,delegate(object obj){});
	}
	public void TestLockItem()
	{
		BagRPC.Instance.LockItem(BagRpcLockItemAskWraperVar.Pos,BagRpcLockItemAskWraperVar.IsLock,delegate(object obj){});
	}
	public void TestDeblocking()
	{
		BagRPC.Instance.Deblocking(BagRpcDeblockingAskWraperVar.BagType,delegate(object obj){});
	}
	public void TestTakeItem()
	{
		BagRPC.Instance.TakeItem(BagRpcTakeItemAskWraperVar.FromBagType,BagRpcTakeItemAskWraperVar.ToBagType,BagRpcTakeItemAskWraperVar.FromPos,delegate(object obj){});
	}
	public void TestTidy()
	{
		BagRPC.Instance.Tidy(BagRpcTidyAskWraperVar.BagType,delegate(object obj){});
	}
	public void TestTakeAllBackBags()
	{
		BagRPC.Instance.TakeAllBackBags(delegate(object obj){});
	}


}

[CustomEditor(typeof(BagTestHelper))]
public class BagTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("UseItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestUseItem();
		}
		if (GUILayout.Button("Sync"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestSync();
		}
		if (GUILayout.Button("SaleItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestSaleItem();
		}
		if (GUILayout.Button("LockItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestLockItem();
		}
		if (GUILayout.Button("Deblocking"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestDeblocking();
		}
		if (GUILayout.Button("TakeItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestTakeItem();
		}
		if (GUILayout.Button("Tidy"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestTidy();
		}
		if (GUILayout.Button("TakeAllBackBags"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestTakeAllBackBags();
		}


    }

}
#endif