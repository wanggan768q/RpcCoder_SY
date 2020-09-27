#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ChatRpcChatAskWraperHelper
{
	public ChatMsgWraper Chat_msg;
	public int Chat_channel;
}
[System.Serializable]
public class ChatRpcPushChatUpdatesNotifyWraperHelper
{
	public List<ChatChannelDataWraper> Chat_channels;
}
[System.Serializable]
public class ChatRpcPushMarqueeNotifyWraperHelper
{
	public List<AppendStringWraper> Marquee;
	public int Priority;
}
[System.Serializable]
public class ChatRpcSayNotifyWraperHelper
{
	public UInt64 ObjId;
	public int ChatId;
	public int Duration;
	public int ChatType;
	public int Interval;
}
[System.Serializable]
public class ChatRpcServerChatNotifyWraperHelper
{
	public int Id;
	public int Channel;
	public List<int> IParams;
	public List<string> SParams;
	public List<ItemDataWraper> Items;
}



public class ChatTestHelper : MonoBehaviour
{
	public ChatRpcChatAskWraperHelper ChatRpcChatAskWraperVar;
	public ChatRpcPushChatUpdatesNotifyWraperHelper ChatRpcPushChatUpdatesNotifyWraperVar;
	public ChatRpcPushMarqueeNotifyWraperHelper ChatRpcPushMarqueeNotifyWraperVar;
	public ChatRpcSayNotifyWraperHelper ChatRpcSayNotifyWraperVar;
	public ChatRpcServerChatNotifyWraperHelper ChatRpcServerChatNotifyWraperVar;


	public void TestChat()
	{
		ChatRPC.Instance.Chat(ChatRpcChatAskWraperVar.Chat_msg,ChatRpcChatAskWraperVar.Chat_channel,delegate(object obj){});
	}


}

[CustomEditor(typeof(ChatTestHelper))]
public class ChatTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Chat"))
		{
			ChatTestHelper rpc = target as ChatTestHelper;
			if( rpc ) rpc.TestChat();
		}


    }

}
#endif