#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class JewelRpcJewelSyncAskWraperHelper
{
}
[System.Serializable]
public class JewelRpcInsetJewelAskWraperHelper
{
	public int EquipSlot;
	public int JewelId;
	public int JewelSlot;
}
[System.Serializable]
public class JewelRpcRemoveJewelAskWraperHelper
{
	public int EquipSlot;
	public int JewelSlot;
}
[System.Serializable]
public class JewelRpcCompoundJewelAskWraperHelper
{
	public int JewelId;
	public bool UseSafeItem;
}
[System.Serializable]
public class JewelRpcCompoundSetJewelAskWraperHelper
{
	public int EquipType;
	public int JewelSlot;
}
[System.Serializable]
public class JewelRpcUnlockJewelSlotAskWraperHelper
{
	public int EquipSlot;
	public int JewelSlot;
}
[System.Serializable]
public class JewelRpcQuickCompoundAskWraperHelper
{
	public int JewelId;
}



public class JewelTestHelper : MonoBehaviour
{
	public JewelRpcJewelSyncAskWraperHelper JewelRpcJewelSyncAskWraperVar;
	public JewelRpcInsetJewelAskWraperHelper JewelRpcInsetJewelAskWraperVar;
	public JewelRpcRemoveJewelAskWraperHelper JewelRpcRemoveJewelAskWraperVar;
	public JewelRpcCompoundJewelAskWraperHelper JewelRpcCompoundJewelAskWraperVar;
	public JewelRpcCompoundSetJewelAskWraperHelper JewelRpcCompoundSetJewelAskWraperVar;
	public JewelRpcUnlockJewelSlotAskWraperHelper JewelRpcUnlockJewelSlotAskWraperVar;
	public JewelRpcQuickCompoundAskWraperHelper JewelRpcQuickCompoundAskWraperVar;


	public void TestJewelSync()
	{
		JewelRPC.Instance.JewelSync(delegate(object obj){});
	}
	public void TestInsetJewel()
	{
		JewelRPC.Instance.InsetJewel(JewelRpcInsetJewelAskWraperVar.EquipSlot,JewelRpcInsetJewelAskWraperVar.JewelId,JewelRpcInsetJewelAskWraperVar.JewelSlot,delegate(object obj){});
	}
	public void TestRemoveJewel()
	{
		JewelRPC.Instance.RemoveJewel(JewelRpcRemoveJewelAskWraperVar.EquipSlot,JewelRpcRemoveJewelAskWraperVar.JewelSlot,delegate(object obj){});
	}
	public void TestCompoundJewel()
	{
		JewelRPC.Instance.CompoundJewel(JewelRpcCompoundJewelAskWraperVar.JewelId,JewelRpcCompoundJewelAskWraperVar.UseSafeItem,delegate(object obj){});
	}
	public void TestCompoundSetJewel()
	{
		JewelRPC.Instance.CompoundSetJewel(JewelRpcCompoundSetJewelAskWraperVar.EquipType,JewelRpcCompoundSetJewelAskWraperVar.JewelSlot,delegate(object obj){});
	}
	public void TestUnlockJewelSlot()
	{
		JewelRPC.Instance.UnlockJewelSlot(JewelRpcUnlockJewelSlotAskWraperVar.EquipSlot,JewelRpcUnlockJewelSlotAskWraperVar.JewelSlot,delegate(object obj){});
	}
	public void TestQuickCompound()
	{
		JewelRPC.Instance.QuickCompound(JewelRpcQuickCompoundAskWraperVar.JewelId,delegate(object obj){});
	}


}

[CustomEditor(typeof(JewelTestHelper))]
public class JewelTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("JewelSync"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestJewelSync();
		}
		if (GUILayout.Button("InsetJewel"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestInsetJewel();
		}
		if (GUILayout.Button("RemoveJewel"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestRemoveJewel();
		}
		if (GUILayout.Button("CompoundJewel"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestCompoundJewel();
		}
		if (GUILayout.Button("CompoundSetJewel"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestCompoundSetJewel();
		}
		if (GUILayout.Button("UnlockJewelSlot"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestUnlockJewelSlot();
		}
		if (GUILayout.Button("QuickCompound"))
		{
			JewelTestHelper rpc = target as JewelTestHelper;
			if( rpc ) rpc.TestQuickCompound();
		}


    }

}
#endif