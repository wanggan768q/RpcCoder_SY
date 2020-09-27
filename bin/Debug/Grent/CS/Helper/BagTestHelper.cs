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
	public int BagType;
	public UInt64 TargetId;
	public int OptionIdx;
}
[System.Serializable]
public class BagRpcSaleItemAskWraperHelper
{
	public int Pos;
	public int Count;
	public int BagType;
}
[System.Serializable]
public class BagRpcLockItemAskWraperHelper
{
	public int Pos;
	public bool IsLock;
	public int BagType;
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
[System.Serializable]
public class BagRpcMergeItemAskWraperHelper
{
	public int Pos;
	public int BagType;
}
[System.Serializable]
public class BagRpcBagSyncAskWraperHelper
{
}
[System.Serializable]
public class BagRpcAddItemNotifyWraperHelper
{
	public List<ItemObjWraper> Item;
}
[System.Serializable]
public class BagRpcConsumeItemAskWraperHelper
{
	public List<ItemSimpleDataWraper> ItemData;
}
[System.Serializable]
public class BagRpcItemChangeNotifyWraperHelper
{
	public List<ItemObjWraper> ItemList;
	public int BagType;
}
[System.Serializable]
public class BagRpcClickItemAskWraperHelper
{
	public UInt64 Guid;
}
[System.Serializable]
public class BagRpcRemoveItemByPosAskWraperHelper
{
	public List<int> PosList;
	public int BagType;
}
[System.Serializable]
public class BagRpcClearBagRedPointAskWraperHelper
{
}



public class BagTestHelper : MonoBehaviour
{
	public BagRpcUseItemAskWraperHelper BagRpcUseItemAskWraperVar;
	public BagRpcSaleItemAskWraperHelper BagRpcSaleItemAskWraperVar;
	public BagRpcLockItemAskWraperHelper BagRpcLockItemAskWraperVar;
	public BagRpcDeblockingAskWraperHelper BagRpcDeblockingAskWraperVar;
	public BagRpcTakeItemAskWraperHelper BagRpcTakeItemAskWraperVar;
	public BagRpcTidyAskWraperHelper BagRpcTidyAskWraperVar;
	public BagRpcTakeAllBackBagsAskWraperHelper BagRpcTakeAllBackBagsAskWraperVar;
	public BagRpcBagChangeNotifyWraperHelper BagRpcBagChangeNotifyWraperVar;
	public BagRpcMergeItemAskWraperHelper BagRpcMergeItemAskWraperVar;
	public BagRpcBagSyncAskWraperHelper BagRpcBagSyncAskWraperVar;
	public BagRpcAddItemNotifyWraperHelper BagRpcAddItemNotifyWraperVar;
	public BagRpcConsumeItemAskWraperHelper BagRpcConsumeItemAskWraperVar;
	public BagRpcItemChangeNotifyWraperHelper BagRpcItemChangeNotifyWraperVar;
	public BagRpcClickItemAskWraperHelper BagRpcClickItemAskWraperVar;
	public BagRpcRemoveItemByPosAskWraperHelper BagRpcRemoveItemByPosAskWraperVar;
	public BagRpcClearBagRedPointAskWraperHelper BagRpcClearBagRedPointAskWraperVar;


	public void TestUseItem()
	{
		BagRPC.Instance.UseItem(BagRpcUseItemAskWraperVar.Count,BagRpcUseItemAskWraperVar.Pos,BagRpcUseItemAskWraperVar.BagType,BagRpcUseItemAskWraperVar.TargetId,BagRpcUseItemAskWraperVar.OptionIdx,delegate(object obj){});
	}
	public void TestSaleItem()
	{
		BagRPC.Instance.SaleItem(BagRpcSaleItemAskWraperVar.Pos,BagRpcSaleItemAskWraperVar.Count,BagRpcSaleItemAskWraperVar.BagType,delegate(object obj){});
	}
	public void TestLockItem()
	{
		BagRPC.Instance.LockItem(BagRpcLockItemAskWraperVar.Pos,BagRpcLockItemAskWraperVar.IsLock,BagRpcLockItemAskWraperVar.BagType,delegate(object obj){});
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
	public void TestMergeItem()
	{
		BagRPC.Instance.MergeItem(BagRpcMergeItemAskWraperVar.Pos,BagRpcMergeItemAskWraperVar.BagType,delegate(object obj){});
	}
	public void TestBagSync()
	{
		BagRPC.Instance.BagSync(delegate(object obj){});
	}
	public void TestConsumeItem()
	{
		BagRPC.Instance.ConsumeItem(BagRpcConsumeItemAskWraperVar.ItemData,delegate(object obj){});
	}
	public void TestClickItem()
	{
		BagRPC.Instance.ClickItem(BagRpcClickItemAskWraperVar.Guid,delegate(object obj){});
	}
	public void TestRemoveItemByPos()
	{
		BagRPC.Instance.RemoveItemByPos(BagRpcRemoveItemByPosAskWraperVar.PosList,BagRpcRemoveItemByPosAskWraperVar.BagType,delegate(object obj){});
	}
	public void TestClearBagRedPoint()
	{
		BagRPC.Instance.ClearBagRedPoint(delegate(object obj){});
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
		if (GUILayout.Button("MergeItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestMergeItem();
		}
		if (GUILayout.Button("BagSync"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestBagSync();
		}
		if (GUILayout.Button("ConsumeItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestConsumeItem();
		}
		if (GUILayout.Button("ClickItem"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestClickItem();
		}
		if (GUILayout.Button("RemoveItemByPos"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestRemoveItemByPos();
		}
		if (GUILayout.Button("ClearBagRedPoint"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestClearBagRedPoint();
		}


    }

}
#endif