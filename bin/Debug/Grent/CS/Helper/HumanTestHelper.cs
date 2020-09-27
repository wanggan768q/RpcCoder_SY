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
	public UInt64 ObjId;
}
[System.Serializable]
public class HumanRpcStopMoveAskWraperHelper
{
	public float Dir;
	public int X;
	public int Z;
	public UInt64 ObjId;
	public bool BrakeRush;
}
[System.Serializable]
public class HumanRpcMoveCheckNotifyWraperHelper
{
	public UInt64 ObjId;
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
	public UInt64 ObjId;
}
[System.Serializable]
public class HumanRpcMovePosAskWraperHelper
{
	public List<Vector3IntWraper> PosList;
	public float Dir;
	public UInt64 ObjId;
	public bool IsAllowChangeRunAnimation;
	public bool IsLookAtMoving;
	public int FromX;
	public int FromZ;
}
[System.Serializable]
public class HumanRpcRoleDieNotifyWraperHelper
{
	public Int64 KillerGuid;
	public string KillerName;
	public int KillerType;
	public int RevieCDTime;
	public int DungeonReviveCounts;
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
	public UInt64 ObjId;
	public bool IsTouchJoyStick;
	public bool IsHold;
}
[System.Serializable]
public class HumanRpcTimeCheckNotifyWraperHelper
{
	public Int64 Data;
}
[System.Serializable]
public class HumanRpcMotionFlagsNotifyWraperHelper
{
	public UInt64 ObjId;
	public int MotionFlags;
}
[System.Serializable]
public class HumanRpcRushAskWraperHelper
{
	public bool Apply;
}
[System.Serializable]
public class HumanRpcStareAskWraperHelper
{
	public bool Apply;
	public UInt64 TargetID;
	public float Dir;
}
[System.Serializable]
public class HumanRpcChangePositionNotifyWraperHelper
{
	public UInt64 ObjID;
	public Vector3IntWraper Pos;
	public float Dir;
}
[System.Serializable]
public class HumanRpcAttrChangeNotifyWraperHelper
{
	public int AttrType;
	public int Value;
	public UInt64 Playerguid;
}
[System.Serializable]
public class HumanRpcTrusteeshipAskWraperHelper
{
	public bool Open;
}
[System.Serializable]
public class HumanRpcChangePlayerNameAskWraperHelper
{
	public string PlayerName;
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
	public HumanRpcTimeCheckNotifyWraperHelper HumanRpcTimeCheckNotifyWraperVar;
	public HumanRpcMotionFlagsNotifyWraperHelper HumanRpcMotionFlagsNotifyWraperVar;
	public HumanRpcRushAskWraperHelper HumanRpcRushAskWraperVar;
	public HumanRpcStareAskWraperHelper HumanRpcStareAskWraperVar;
	public HumanRpcChangePositionNotifyWraperHelper HumanRpcChangePositionNotifyWraperVar;
	public HumanRpcAttrChangeNotifyWraperHelper HumanRpcAttrChangeNotifyWraperVar;
	public HumanRpcTrusteeshipAskWraperHelper HumanRpcTrusteeshipAskWraperVar;
	public HumanRpcChangePlayerNameAskWraperHelper HumanRpcChangePlayerNameAskWraperVar;


	public void TestMove()
	{
		HumanRPC.Instance.Move(HumanRpcMoveAskWraperVar.Dir,HumanRpcMoveAskWraperVar.X,HumanRpcMoveAskWraperVar.Z,HumanRpcMoveAskWraperVar.ObjId,delegate(object obj){});
	}
	public void TestStopMove()
	{
		HumanRPC.Instance.StopMove(HumanRpcStopMoveAskWraperVar.Dir,HumanRpcStopMoveAskWraperVar.X,HumanRpcStopMoveAskWraperVar.Z,HumanRpcStopMoveAskWraperVar.ObjId,HumanRpcStopMoveAskWraperVar.BrakeRush,delegate(object obj){});
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
		HumanRPC.Instance.MovePos(HumanRpcMovePosAskWraperVar.PosList,HumanRpcMovePosAskWraperVar.Dir,HumanRpcMovePosAskWraperVar.ObjId,HumanRpcMovePosAskWraperVar.IsAllowChangeRunAnimation,HumanRpcMovePosAskWraperVar.IsLookAtMoving,HumanRpcMovePosAskWraperVar.FromX,HumanRpcMovePosAskWraperVar.FromZ,delegate(object obj){});
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
	public void TestTimeCheck()
	{
		HumanRPC.Instance.TimeCheck(HumanRpcTimeCheckNotifyWraperVar.Data);
	}
	public void TestRush()
	{
		HumanRPC.Instance.Rush(HumanRpcRushAskWraperVar.Apply,delegate(object obj){});
	}
	public void TestStare()
	{
		HumanRPC.Instance.Stare(HumanRpcStareAskWraperVar.Apply,HumanRpcStareAskWraperVar.TargetID,HumanRpcStareAskWraperVar.Dir,delegate(object obj){});
	}
	public void TestTrusteeship()
	{
		HumanRPC.Instance.Trusteeship(HumanRpcTrusteeshipAskWraperVar.Open,delegate(object obj){});
	}
	public void TestChangePlayerName()
	{
		HumanRPC.Instance.ChangePlayerName(HumanRpcChangePlayerNameAskWraperVar.PlayerName,delegate(object obj){});
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
		if (GUILayout.Button("TimeCheck"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestTimeCheck();
		}
		if (GUILayout.Button("Rush"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestRush();
		}
		if (GUILayout.Button("Stare"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestStare();
		}
		if (GUILayout.Button("Trusteeship"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestTrusteeship();
		}
		if (GUILayout.Button("ChangePlayerName"))
		{
			HumanTestHelper rpc = target as HumanTestHelper;
			if( rpc ) rpc.TestChangePlayerName();
		}


    }

}
#endif