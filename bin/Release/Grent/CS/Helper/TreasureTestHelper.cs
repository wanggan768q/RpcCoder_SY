#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class TreasureRpcTreasureDepotInfoAskWraperHelper
{
}
[System.Serializable]
public class TreasureRpcTreasureInfoAskWraperHelper
{
	public int Type;
}
[System.Serializable]
public class TreasureRpcTreasureUnlockAskWraperHelper
{
	public int Id;
	public int Color_Type;
	public int Time_Type;
}
[System.Serializable]
public class TreasureRpcTreasureEquipAskWraperHelper
{
	public int Id;
	public int Color_Type;
	public int Time_Type;
}
[System.Serializable]
public class TreasureRpcTreasureEquipSycAskWraperHelper
{
}
[System.Serializable]
public class TreasureRpcTreasureDepotLvUpAskWraperHelper
{
}
[System.Serializable]
public class TreasureRpcTreasureUnEquipAskWraperHelper
{
	public int Id;
	public int Color_Type;
	public int Time_Type;
}
[System.Serializable]
public class TreasureRpcTreasureEquipedIDNotifyWraperHelper
{
	public TreasureEquipedIDWraper TreasureID;
	public int ObjID;
}
[System.Serializable]
public class TreasureRpcTreasureDelayTimeAskWraperHelper
{
	public int Id;
	public int Color_Type;
	public int Time_Type;
}
[System.Serializable]
public class TreasureRpcTreasureUnlockEquipNotifyWraperHelper
{
	public int Result;
	public TreasureDataWraper TreasureEquiped;
	public TreasureDataWraper TreasureUnequiped;
	public int Points;
}



public class TreasureTestHelper : MonoBehaviour
{
	public TreasureRpcTreasureDepotInfoAskWraperHelper TreasureRpcTreasureDepotInfoAskWraperVar;
	public TreasureRpcTreasureInfoAskWraperHelper TreasureRpcTreasureInfoAskWraperVar;
	public TreasureRpcTreasureUnlockAskWraperHelper TreasureRpcTreasureUnlockAskWraperVar;
	public TreasureRpcTreasureEquipAskWraperHelper TreasureRpcTreasureEquipAskWraperVar;
	public TreasureRpcTreasureEquipSycAskWraperHelper TreasureRpcTreasureEquipSycAskWraperVar;
	public TreasureRpcTreasureDepotLvUpAskWraperHelper TreasureRpcTreasureDepotLvUpAskWraperVar;
	public TreasureRpcTreasureUnEquipAskWraperHelper TreasureRpcTreasureUnEquipAskWraperVar;
	public TreasureRpcTreasureEquipedIDNotifyWraperHelper TreasureRpcTreasureEquipedIDNotifyWraperVar;
	public TreasureRpcTreasureDelayTimeAskWraperHelper TreasureRpcTreasureDelayTimeAskWraperVar;
	public TreasureRpcTreasureUnlockEquipNotifyWraperHelper TreasureRpcTreasureUnlockEquipNotifyWraperVar;


	public void TestTreasureDepotInfo()
	{
		TreasureRPC.Instance.TreasureDepotInfo(delegate(object obj){});
	}
	public void TestTreasureInfo()
	{
		TreasureRPC.Instance.TreasureInfo(TreasureRpcTreasureInfoAskWraperVar.Type,delegate(object obj){});
	}
	public void TestTreasureUnlock()
	{
		TreasureRPC.Instance.TreasureUnlock(TreasureRpcTreasureUnlockAskWraperVar.Id,TreasureRpcTreasureUnlockAskWraperVar.Color_Type,TreasureRpcTreasureUnlockAskWraperVar.Time_Type,delegate(object obj){});
	}
	public void TestTreasureEquip()
	{
		TreasureRPC.Instance.TreasureEquip(TreasureRpcTreasureEquipAskWraperVar.Id,TreasureRpcTreasureEquipAskWraperVar.Color_Type,TreasureRpcTreasureEquipAskWraperVar.Time_Type,delegate(object obj){});
	}
	public void TestTreasureEquipSyc()
	{
		TreasureRPC.Instance.TreasureEquipSyc(delegate(object obj){});
	}
	public void TestTreasureDepotLvUp()
	{
		TreasureRPC.Instance.TreasureDepotLvUp(delegate(object obj){});
	}
	public void TestTreasureUnEquip()
	{
		TreasureRPC.Instance.TreasureUnEquip(TreasureRpcTreasureUnEquipAskWraperVar.Id,TreasureRpcTreasureUnEquipAskWraperVar.Color_Type,TreasureRpcTreasureUnEquipAskWraperVar.Time_Type,delegate(object obj){});
	}
	public void TestTreasureDelayTime()
	{
		TreasureRPC.Instance.TreasureDelayTime(TreasureRpcTreasureDelayTimeAskWraperVar.Id,TreasureRpcTreasureDelayTimeAskWraperVar.Color_Type,TreasureRpcTreasureDelayTimeAskWraperVar.Time_Type,delegate(object obj){});
	}


}

[CustomEditor(typeof(TreasureTestHelper))]
public class TreasureTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("TreasureDepotInfo"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureDepotInfo();
		}
		if (GUILayout.Button("TreasureInfo"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureInfo();
		}
		if (GUILayout.Button("TreasureUnlock"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureUnlock();
		}
		if (GUILayout.Button("TreasureEquip"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureEquip();
		}
		if (GUILayout.Button("TreasureEquipSyc"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureEquipSyc();
		}
		if (GUILayout.Button("TreasureDepotLvUp"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureDepotLvUp();
		}
		if (GUILayout.Button("TreasureUnEquip"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureUnEquip();
		}
		if (GUILayout.Button("TreasureDelayTime"))
		{
			TreasureTestHelper rpc = target as TreasureTestHelper;
			if( rpc ) rpc.TestTreasureDelayTime();
		}


    }

}
#endif