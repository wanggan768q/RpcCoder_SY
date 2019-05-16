#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class HumanRpcMoveAskWraperHelper
{
	public float Dir;
	public float X;
	public float Z;
	public int ObjId;
}
[System.Serializable]
public class HumanRpcStopMoveAskWraperHelper
{
	public float Dir;
	public int X;
	public int Z;
	public int ObjId;
}
[System.Serializable]
public class HumanRpcMoveCheckNotifyWraperHelper
{
	public int ObjId;
	public float Dir;
	public float X;
	public float Y;
}
[System.Serializable]
public class HumanRpcRespawnAskWraperHelper
{
	public int ReviveType;
}
[System.Serializable]
public class HumanRpcRespawnOtherNotifyWraperHelper
{
	public int ObjId;
}
[System.Serializable]
public class HumanRpcMovePosAskWraperHelper
{
	public List<Vector3IntWraper> PosList;
	public float Dir;
	public int ObjId;
	public bool IsAllowChangeRunAnimation;
}
[System.Serializable]
public class HumanRpcRoleDieNotifyWraperHelper
{
	public Int64 KillerGuid;
	public string KillerName;
	public int KillerType;
	public int RevieCDTime;
}
[System.Serializable]
public class HumanRpcChangeAnimationStateNotifyWraperHelper
{
	public bool AnimationState;
}
[System.Serializable]
public class HumanRpcFuncNoticeAskWraperHelper
{
}
[System.Serializable]
public class HumanRpcFuncNoticeChangeAskWraperHelper
{
}
[System.Serializable]
public class HumanRpcClientAttributesNotifyWraperHelper
{
	public int ObjId;
	public bool IsTouchJoyStick;
	public bool IsHold;
}



public class HumanTestHelper : MonoBehaviour
{
	public HumanRpcMoveAskWraperHelper HumanRpcMoveAskWraperVar;
	public HumanRpcStopMoveAskWraperHelper HumanRpcStopMoveAskWraperVar;
	public HumanRpcMoveCheckNotifyWraperHelper HumanRpcMoveCheckNotifyWraperVar;
	public HumanRpcRespawnAskWraperHelper HumanRpcRespawnAskWraperVar;
	public HumanRpcRespawnOtherNotifyWraperHelper HumanRpcRespawnOtherNotifyWraperVar;
	public HumanRpcMovePosAskWraperHelper HumanRpcMovePosAskWraperVar;
	public HumanRpcRoleDieNotifyWraperHelper HumanRpcRoleDieNotifyWraperVar;
	public HumanRpcChangeAnimationStateNotifyWraperHelper HumanRpcChangeAnimationStateNotifyWraperVar;
	public HumanRpcFuncNoticeAskWraperHelper HumanRpcFuncNoticeAskWraperVar;
	public HumanRpcFuncNoticeChangeAskWraperHelper HumanRpcFuncNoticeChangeAskWraperVar;
	public HumanRpcClientAttributesNotifyWraperHelper HumanRpcClientAttributesNotifyWraperVar;


	public void TestMove()
	{
		HumanRPC.Instance.Move(HumanRpcMoveAskWraperVar.Dir,HumanRpcMoveAskWraperVar.X,HumanRpcMoveAskWraperVar.Z,HumanRpcMoveAskWraperVar.ObjId,delegate(object obj){});
	}
	public void TestStopMove()
	{
		HumanRPC.Instance.StopMove(HumanRpcStopMoveAskWraperVar.Dir,HumanRpcStopMoveAskWraperVar.X,HumanRpcStopMoveAskWraperVar.Z,HumanRpcStopMoveAskWraperVar.ObjId,delegate(object obj){});
	}
	public void TestMoveCheck()
	{
		HumanRPC.Instance.MoveCheck(HumanRpcMoveCheckNotifyWraperVar.ObjId,HumanRpcMoveCheckNotifyWraperVar.Dir,HumanRpcMoveCheckNotifyWraperVar.X,HumanRpcMoveCheckNotifyWraperVar.Y);
	}
	public void TestRespawn()
	{
		HumanRPC.Instance.Respawn(HumanRpcRespawnAskWraperVar.ReviveType,delegate(object obj){});
	}
	public void TestMovePos()
	{
		HumanRPC.Instance.MovePos(HumanRpcMovePosAskWraperVar.PosList,HumanRpcMovePosAskWraperVar.Dir,HumanRpcMovePosAskWraperVar.ObjId,HumanRpcMovePosAskWraperVar.IsAllowChangeRunAnimation,delegate(object obj){});
	}
	public void TestChangeAnimationState()
	{
		HumanRPC.Instance.ChangeAnimationState(HumanRpcChangeAnimationStateNotifyWraperVar.AnimationState);
	}
	public void TestFuncNotice()
	{
		HumanRPC.Instance.FuncNotice(delegate(object obj){});
	}
	public void TestFuncNoticeChange()
	{
		HumanRPC.Instance.FuncNoticeChange(delegate(object obj){});
	}
	public void TestClientAttributes()
	{
		HumanRPC.Instance.ClientAttributes(HumanRpcClientAttributesNotifyWraperVar.ObjId,HumanRpcClientAttributesNotifyWraperVar.IsTouchJoyStick,HumanRpcClientAttributesNotifyWraperVar.IsHold);
	}


}

[CustomEditor(typeof(HumanTestHelper))]
public class HumanTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Move"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMove();
		}
		if (GUILayout.Button("StopMove"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestStopMove();
		}
		if (GUILayout.Button("MoveCheck"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMoveCheck();
		}
		if (GUILayout.Button("Respawn"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestRespawn();
		}
		if (GUILayout.Button("MovePos"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestMovePos();
		}
		if (GUILayout.Button("ChangeAnimationState"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestChangeAnimationState();
		}
		if (GUILayout.Button("FuncNotice"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestFuncNotice();
		}
		if (GUILayout.Button("FuncNoticeChange"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestFuncNoticeChange();
		}
		if (GUILayout.Button("ClientAttributes"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestClientAttributes();
		}


    }

}
#endif