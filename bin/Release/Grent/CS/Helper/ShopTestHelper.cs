#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ShopRpcBuyItemAskWraperHelper
{
	public int ShopItemId;
	public int ItemNum;
}
[System.Serializable]
public class ShopRpcShopInfoAskWraperHelper
{
	public int RoleID;
}



public class ShopTestHelper : MonoBehaviour
{
	public ShopRpcBuyItemAskWraperHelper ShopRpcBuyItemAskWraperVar;
	public ShopRpcShopInfoAskWraperHelper ShopRpcShopInfoAskWraperVar;


	public void TestBuyItem()
	{
		ShopRPC.Instance.BuyItem(ShopRpcBuyItemAskWraperVar.ShopItemId,ShopRpcBuyItemAskWraperVar.ItemNum,delegate(object obj){});
	}
	public void TestShopInfo()
	{
		ShopRPC.Instance.ShopInfo(ShopRpcShopInfoAskWraperVar.RoleID,delegate(object obj){});
	}


}

[CustomEditor(typeof(ShopTestHelper))]
public class ShopTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("BuyItem"))
		{
			ShopTestHelper rpc = target as ShopTestHelper;
			if( rpc ) rpc.TestBuyItem();
		}
		if (GUILayout.Button("ShopInfo"))
		{
			ShopTestHelper rpc = target as ShopTestHelper;
			if( rpc ) rpc.TestShopInfo();
		}


    }

}
#endif