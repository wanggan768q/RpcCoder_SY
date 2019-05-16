#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class AuctionRpcAuctionInfoAskWraperHelper
{
	public int ItemId;
	public int QueueType;
	public int CurPage;
}
[System.Serializable]
public class AuctionRpcSellItemAskWraperHelper
{
	public UInt64 ItemGuid;
	public int ItemId;
	public int Price;
	public int Currency;
	public int Count;
}
[System.Serializable]
public class AuctionRpcBuyAskWraperHelper
{
	public UInt64 ItemGuid;
	public int Count;
}
[System.Serializable]
public class AuctionRpcSellAgainAskWraperHelper
{
	public UInt64 ItemGuid;
	public int Price;
}
[System.Serializable]
public class AuctionRpcGetItemAskWraperHelper
{
	public List<UInt64> BuyRecGuid;
	public List<UInt64> SaleRecGuid;
}
[System.Serializable]
public class AuctionRpcRecordAskWraperHelper
{
}
[System.Serializable]
public class AuctionRpcItemInfoByClassAskWraperHelper
{
	public int ItemClass;
	public List<int> ItemId;
	public int ItemSubClass;
	public int Prof;
	public int Level;
}
[System.Serializable]
public class AuctionRpcSalePrepareAskWraperHelper
{
	public int ItemId;
}
[System.Serializable]
public class AuctionRpcGetItemBackAskWraperHelper
{
	public UInt64 ItemGuid;
}
[System.Serializable]
public class AuctionRpcGetMySaleListAskWraperHelper
{
}



public class AuctionTestHelper : MonoBehaviour
{
	public AuctionRpcAuctionInfoAskWraperHelper AuctionRpcAuctionInfoAskWraperVar;
	public AuctionRpcSellItemAskWraperHelper AuctionRpcSellItemAskWraperVar;
	public AuctionRpcBuyAskWraperHelper AuctionRpcBuyAskWraperVar;
	public AuctionRpcSellAgainAskWraperHelper AuctionRpcSellAgainAskWraperVar;
	public AuctionRpcGetItemAskWraperHelper AuctionRpcGetItemAskWraperVar;
	public AuctionRpcRecordAskWraperHelper AuctionRpcRecordAskWraperVar;
	public AuctionRpcItemInfoByClassAskWraperHelper AuctionRpcItemInfoByClassAskWraperVar;
	public AuctionRpcSalePrepareAskWraperHelper AuctionRpcSalePrepareAskWraperVar;
	public AuctionRpcGetItemBackAskWraperHelper AuctionRpcGetItemBackAskWraperVar;
	public AuctionRpcGetMySaleListAskWraperHelper AuctionRpcGetMySaleListAskWraperVar;


	public void TestAuctionInfo()
	{
		AuctionRPC.Instance.AuctionInfo(AuctionRpcAuctionInfoAskWraperVar.ItemId,AuctionRpcAuctionInfoAskWraperVar.QueueType,AuctionRpcAuctionInfoAskWraperVar.CurPage,delegate(bool connedServer,object obj){});
	}
	public void TestSellItem()
	{
		AuctionRPC.Instance.SellItem(AuctionRpcSellItemAskWraperVar.ItemGuid,AuctionRpcSellItemAskWraperVar.ItemId,AuctionRpcSellItemAskWraperVar.Price,AuctionRpcSellItemAskWraperVar.Currency,AuctionRpcSellItemAskWraperVar.Count,delegate(bool connedServer,object obj){});
	}
	public void TestSellAgain()
	{
		AuctionRPC.Instance.SellAgain(AuctionRpcSellAgainAskWraperVar.ItemGuid,AuctionRpcSellAgainAskWraperVar.Price,delegate(bool connedServer,object obj){});
	}
	public void TestBuy()
	{
		AuctionRPC.Instance.Buy(AuctionRpcBuyAskWraperVar.ItemGuid,AuctionRpcBuyAskWraperVar.Count,delegate(bool connedServer,object obj){});
	}
	public void TestGetItem()
	{
		AuctionRPC.Instance.GetItem(AuctionRpcGetItemAskWraperVar.BuyRecGuid,AuctionRpcGetItemAskWraperVar.SaleRecGuid,delegate(bool connedServer,object obj){});
	}
	public void TestRecord()
	{
		AuctionRPC.Instance.Record(delegate(bool connedServer,object obj){});
	}
	public void TestItemInfoByClass()
	{
		AuctionRPC.Instance.ItemInfoByClass(AuctionRpcItemInfoByClassAskWraperVar.ItemClass,AuctionRpcItemInfoByClassAskWraperVar.ItemId,AuctionRpcItemInfoByClassAskWraperVar.ItemSubClass,AuctionRpcItemInfoByClassAskWraperVar.Prof,AuctionRpcItemInfoByClassAskWraperVar.Level,delegate(bool connedServer,object obj){});
	}
	public void TestSalePrepare()
	{
		AuctionRPC.Instance.SalePrepare(AuctionRpcSalePrepareAskWraperVar.ItemId,delegate(bool connedServer,object obj){});
	}
	public void TestGetItemBack()
	{
		AuctionRPC.Instance.GetItemBack(AuctionRpcGetItemBackAskWraperVar.ItemGuid,delegate(bool connedServer,object obj){});
	}
	public void TestGetMySaleList()
	{
		AuctionRPC.Instance.GetMySaleList(delegate(bool connedServer,object obj){});
	}


}

[CustomEditor(typeof(AuctionTestHelper))]
public class AuctionTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("AuctionInfo"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestAuctionInfo();
		}
		if (GUILayout.Button("SellItem"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestSellItem();
		}
		if (GUILayout.Button("SellAgain"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestSellAgain();
		}
		if (GUILayout.Button("Buy"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestBuy();
		}
		if (GUILayout.Button("GetItem"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestGetItem();
		}
		if (GUILayout.Button("Record"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestRecord();
		}
		if (GUILayout.Button("ItemInfoByClass"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestItemInfoByClass();
		}
		if (GUILayout.Button("SalePrepare"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestSalePrepare();
		}
		if (GUILayout.Button("GetItemBack"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestGetItemBack();
		}
		if (GUILayout.Button("GetMySaleList"))
		{
			AuctionTestHelper rpc = target as AuctionTestHelper;
			if( rpc ) rpc.TestGetMySaleList();
		}


    }

}
#endif