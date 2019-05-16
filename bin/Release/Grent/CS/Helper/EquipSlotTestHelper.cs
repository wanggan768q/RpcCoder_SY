#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EquipSlotRpcSyncEquipSlotAskWraperHelper
{
}
[System.Serializable]
public class EquipSlotRpcEnhanceEquipSlotAskWraperHelper
{
	public int Slot_Type;
	public List<ItemSimpleDataWraper> CostItemList;
}
[System.Serializable]
public class EquipSlotRpcUpStarEquipSlotAskWraperHelper
{
	public int Slot_Type;
	public bool IsProtection;
}
[System.Serializable]
public class EquipSlotRpcSyncEquipSlotStarAskWraperHelper
{
}



public class EquipSlotTestHelper : MonoBehaviour
{
	public EquipSlotRpcSyncEquipSlotAskWraperHelper EquipSlotRpcSyncEquipSlotAskWraperVar;
	public EquipSlotRpcEnhanceEquipSlotAskWraperHelper EquipSlotRpcEnhanceEquipSlotAskWraperVar;
	public EquipSlotRpcUpStarEquipSlotAskWraperHelper EquipSlotRpcUpStarEquipSlotAskWraperVar;
	public EquipSlotRpcSyncEquipSlotStarAskWraperHelper EquipSlotRpcSyncEquipSlotStarAskWraperVar;


	public void TestSyncEquipSlot()
	{
		EquipSlotRPC.Instance.SyncEquipSlot(delegate(object obj){});
	}
	public void TestEnhanceEquipSlot()
	{
		EquipSlotRPC.Instance.EnhanceEquipSlot(EquipSlotRpcEnhanceEquipSlotAskWraperVar.Slot_Type,EquipSlotRpcEnhanceEquipSlotAskWraperVar.CostItemList,delegate(object obj){});
	}
	public void TestSyncEquipSlotStar()
	{
		EquipSlotRPC.Instance.SyncEquipSlotStar(delegate(object obj){});
	}
	public void TestUpStarEquipSlot()
	{
		EquipSlotRPC.Instance.UpStarEquipSlot(EquipSlotRpcUpStarEquipSlotAskWraperVar.Slot_Type,EquipSlotRpcUpStarEquipSlotAskWraperVar.IsProtection,delegate(object obj){});
	}


}

[CustomEditor(typeof(EquipSlotTestHelper))]
public class EquipSlotTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncEquipSlot"))
		{
			EquipSlotTestHelper rpc = target as EquipSlotTestHelper;
			if( rpc ) rpc.TestSyncEquipSlot();
		}
		if (GUILayout.Button("EnhanceEquipSlot"))
		{
			EquipSlotTestHelper rpc = target as EquipSlotTestHelper;
			if( rpc ) rpc.TestEnhanceEquipSlot();
		}
		if (GUILayout.Button("SyncEquipSlotStar"))
		{
			EquipSlotTestHelper rpc = target as EquipSlotTestHelper;
			if( rpc ) rpc.TestSyncEquipSlotStar();
		}
		if (GUILayout.Button("UpStarEquipSlot"))
		{
			EquipSlotTestHelper rpc = target as EquipSlotTestHelper;
			if( rpc ) rpc.TestUpStarEquipSlot();
		}


    }

}
#endif