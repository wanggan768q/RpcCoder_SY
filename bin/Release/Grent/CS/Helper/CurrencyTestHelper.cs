#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class CurrencyRpcTransfromAskWraperHelper
{
	public int To_type;
	public int From_type;
	public Int64 From_num;
	public Int64 Diamond_bind_num;
}
[System.Serializable]
public class CurrencyRpcShowAskWraperHelper
{
}



public class CurrencyTestHelper : MonoBehaviour
{
	public CurrencyRpcTransfromAskWraperHelper CurrencyRpcTransfromAskWraperVar;
	public CurrencyRpcShowAskWraperHelper CurrencyRpcShowAskWraperVar;


	public void TestTransfrom()
	{
		CurrencyRPC.Instance.Transfrom(CurrencyRpcTransfromAskWraperVar.To_type,CurrencyRpcTransfromAskWraperVar.From_type,CurrencyRpcTransfromAskWraperVar.From_num,CurrencyRpcTransfromAskWraperVar.Diamond_bind_num,delegate(object obj){});
	}
	public void TestShow()
	{
		CurrencyRPC.Instance.Show(delegate(object obj){});
	}


}

[CustomEditor(typeof(CurrencyTestHelper))]
public class CurrencyTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Transfrom"))
		{
			CurrencyTestHelper rpc = target as CurrencyTestHelper;
			if( rpc ) rpc.TestTransfrom();
		}
		if (GUILayout.Button("Show"))
		{
			CurrencyTestHelper rpc = target as CurrencyTestHelper;
			if( rpc ) rpc.TestShow();
		}


    }

}
#endif