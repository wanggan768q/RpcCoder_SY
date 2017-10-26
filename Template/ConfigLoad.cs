using UnityEngine;
using System.Collections;

public class ConfigLoad : MonoBehaviour {

	private string textContent;

	public IEnumerator LoadConfig () {

$loadConfItem$

		yield return true;
	}

    IEnumerator LoadData (string name) {

		string path = Ex.Utils.GetStreamingAssetsFilePath(name, "CSV");
	
		WWW www = new WWW(path);
		yield return www;

		textContent = www.text;
		yield return true;
	}
}
