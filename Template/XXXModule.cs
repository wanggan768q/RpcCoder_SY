using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;

public class $Template$Module : IModule {

	private bool isRequestNet = false;
	
	private $Template$MainView $Template$MainView;
	
	public override void InitModule (){
		$Template$RPC.Instance.initialize();
		StartCoroutine(RequestNet_SyncData());
		
$NotifyCBDelegate$

	}
	
	public override void StartModule (int param, object data = null){
		if($Template$MainView == null){
			$Template$MainView = UILoader.LoadUI<$Template$MainView>("ModuleUI/$Template$/$Template$MainView");
		}
		UI.Instance.addChild($Template$MainView);
		$Template$MainView.Position = Vector2.zero;
	}
	//切换场景
	public override void EnterScene(SceneType sceneType){
		if(sceneType == SceneType.City){//城市
			
		}
		else if(sceneType == SceneType.Wild){//野外
			
		}
		else if(sceneType == SceneType.Copy){//副本
			
		}
	}
	//错误提示Func
	private void ErrorNotify(int statues,object dataValue = null){
		switch(statues){
		case 1:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + "error result = 1");
			break;
			
		case 2:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + "error result = 2");
			break;
			
		case 3:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + "error result = 3");
			break;
			
		case 4:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + "error result = 4");
			break;
			
		case 5:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + "error result = 5");
			break;
			
		default:
			LogManager.Log("",LogManager.LogColor.Red);
			Tips.ShowMessage(this.GetType() + " Error result = " + statues);
			break;
			
		}	
	}	
$Operations$	


}
