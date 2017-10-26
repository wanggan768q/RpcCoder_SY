using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Data_$Template$ {
	public delegate void DataChangeEvent(int id);
	public event DataChangeEvent onDataChange;//数据变化

	private static Data_$Template$ m_Instance = null;

	private List<$Template$DataInfo> $Template$DataInfoList;//本地数据队列

	private Data_$Template$(){
		
	}
	public static Data_$Template$ Instance{
		get{
			if (m_Instance == null) {
				m_Instance = new Data_$Template$();
			}
			return m_Instance;
		}
	}
	//初始化数据队列
	public void init(){
		$Template$DataInfoList = new List<$Template$DataInfo>();
		
		//初始化过程
		
		
		//监听数据更新主推协议
		$Template$Data.Instance.NotifySyncValueChanged = NotifySyncValueChangedHandle;
	}
	//数据更新
	private void NotifySyncValueChangedHandle(int SyncId, int nIndex = -1){
		LogManager.Log("<color=#ffff00ff>$Template$数据更新: SyncId=" + SyncId + " Index=" + nIndex + "</color>");
		
	}
}
//单个数据体
public class $Template$DataInfo{
	public $Template$DataInfo(int Id){
		
	}
}
