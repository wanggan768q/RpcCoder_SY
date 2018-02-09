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



public class ChatTestHelper : MonoBehaviour
{
	public ChatRpcChatAskWraperHelper ChatRpcChatAskWraperVar;
	public ChatRpcPushChatUpdatesNotifyWraperHelper ChatRpcPushChatUpdatesNotifyWraperVar;


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