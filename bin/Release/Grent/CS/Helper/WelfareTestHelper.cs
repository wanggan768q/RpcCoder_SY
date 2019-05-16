#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class WelfareRpcAccumulateSignInAskWraperHelper
{
}
[System.Serializable]
public class WelfareRpcAccumulateGetRewardAskWraperHelper
{
	public int ID;
}
[System.Serializable]
public class WelfareRpcOnlineBonusAskWraperHelper
{
}
[System.Serializable]
public class WelfareRpcOnlineGetRewardAskWraperHelper
{
	public int ID;
}
[System.Serializable]
public class WelfareRpcLevelBonusAskWraperHelper
{
}
[System.Serializable]
public class WelfareRpcLevelBonusRewardAskWraperHelper
{
	public int ID;
}
[System.Serializable]
public class WelfareRpcMonthSignInBonusAskWraperHelper
{
}
[System.Serializable]
public class WelfareRpcMonthSignInRewardAskWraperHelper
{
	public int ID;
}
[System.Serializable]
public class WelfareRpcTodaySignInNotifyWraperHelper
{
	public bool TodaySignIn;
}
[System.Serializable]
public class WelfareRpcSpecLoginNotifyWraperHelper
{
	public List<SpecLoginInfoWraper> SpecLogin;
}
[System.Serializable]
public class WelfareRpcSpecLoginRewardAskWraperHelper
{
	public int Id;
	public int Index;
}



public class WelfareTestHelper : MonoBehaviour
{
	public WelfareRpcAccumulateSignInAskWraperHelper WelfareRpcAccumulateSignInAskWraperVar;
	public WelfareRpcAccumulateGetRewardAskWraperHelper WelfareRpcAccumulateGetRewardAskWraperVar;
	public WelfareRpcOnlineBonusAskWraperHelper WelfareRpcOnlineBonusAskWraperVar;
	public WelfareRpcOnlineGetRewardAskWraperHelper WelfareRpcOnlineGetRewardAskWraperVar;
	public WelfareRpcLevelBonusAskWraperHelper WelfareRpcLevelBonusAskWraperVar;
	public WelfareRpcLevelBonusRewardAskWraperHelper WelfareRpcLevelBonusRewardAskWraperVar;
	public WelfareRpcMonthSignInBonusAskWraperHelper WelfareRpcMonthSignInBonusAskWraperVar;
	public WelfareRpcMonthSignInRewardAskWraperHelper WelfareRpcMonthSignInRewardAskWraperVar;
	public WelfareRpcTodaySignInNotifyWraperHelper WelfareRpcTodaySignInNotifyWraperVar;
	public WelfareRpcSpecLoginNotifyWraperHelper WelfareRpcSpecLoginNotifyWraperVar;
	public WelfareRpcSpecLoginRewardAskWraperHelper WelfareRpcSpecLoginRewardAskWraperVar;


	public void TestAccumulateSignIn()
	{
		WelfareRPC.Instance.AccumulateSignIn(delegate(object obj){});
	}
	public void TestAccumulateGetReward()
	{
		WelfareRPC.Instance.AccumulateGetReward(WelfareRpcAccumulateGetRewardAskWraperVar.ID,delegate(object obj){});
	}
	public void TestOnlineBonus()
	{
		WelfareRPC.Instance.OnlineBonus(delegate(object obj){});
	}
	public void TestOnlineGetReward()
	{
		WelfareRPC.Instance.OnlineGetReward(WelfareRpcOnlineGetRewardAskWraperVar.ID,delegate(object obj){});
	}
	public void TestLevelBonus()
	{
		WelfareRPC.Instance.LevelBonus(delegate(object obj){});
	}
	public void TestLevelBonusReward()
	{
		WelfareRPC.Instance.LevelBonusReward(WelfareRpcLevelBonusRewardAskWraperVar.ID,delegate(object obj){});
	}
	public void TestMonthSignInBonus()
	{
		WelfareRPC.Instance.MonthSignInBonus(delegate(object obj){});
	}
	public void TestMonthSignInReward()
	{
		WelfareRPC.Instance.MonthSignInReward(WelfareRpcMonthSignInRewardAskWraperVar.ID,delegate(object obj){});
	}
	public void TestSpecLoginReward()
	{
		WelfareRPC.Instance.SpecLoginReward(WelfareRpcSpecLoginRewardAskWraperVar.Id,WelfareRpcSpecLoginRewardAskWraperVar.Index,delegate(object obj){});
	}


}

[CustomEditor(typeof(WelfareTestHelper))]
public class WelfareTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("AccumulateSignIn"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestAccumulateSignIn();
		}
		if (GUILayout.Button("AccumulateGetReward"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestAccumulateGetReward();
		}
		if (GUILayout.Button("OnlineBonus"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestOnlineBonus();
		}
		if (GUILayout.Button("OnlineGetReward"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestOnlineGetReward();
		}
		if (GUILayout.Button("LevelBonus"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestLevelBonus();
		}
		if (GUILayout.Button("LevelBonusReward"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestLevelBonusReward();
		}
		if (GUILayout.Button("MonthSignInBonus"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestMonthSignInBonus();
		}
		if (GUILayout.Button("MonthSignInReward"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestMonthSignInReward();
		}
		if (GUILayout.Button("SpecLoginReward"))
		{
			WelfareTestHelper rpc = target as WelfareTestHelper;
			if( rpc ) rpc.TestSpecLoginReward();
		}


    }

}
#endif