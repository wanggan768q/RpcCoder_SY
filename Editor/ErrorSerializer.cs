namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class ErrorSerializer
    {
        public static void DeserializeErrorTab(string dir)
        {
            string path = dir + @"\" + "error.tab";
            if (File.Exists(path))
            {
                StreamReader reader = new StreamReader(path, Encoding.GetEncoding("GBK"), false);
                for (int i = 0; i < 3; i++)
                {
                    reader.ReadLine();
                }
                for (string str3 = reader.ReadLine(); str3 != null; str3 = reader.ReadLine())
                {
                    string[] strArray = str3.Split(new char[] { '\t' });
                    Module.Error error = new Module.Error {
                        id = strArray[0],
                        name = strArray[1]
                    };
                    foreach (var pair in Module.errorDic)
                    {
                        int num2 = (Convert.ToInt32(error.id) / 100) * 100;
                        if (pair.Key == num2)
                        {
                            pair.Value.Add(error);
                            break;
                        }
                    }
                }
                reader.Close();
            }
        }

        public static void SerializeErrorTab(DataGridView dataGridView, string dir, Label label1)
        {
            string path = dir + @"\" + "error.tab";
            label1.Text = "正在生成文件: " + path;
            label1.Refresh();
            StreamWriter writer = new StreamWriter(path, false, Encoding.UTF8);
            string str3 = "INT\tSTRING\r\n#1\r\n#2ID\tNAME\r\n";
            foreach (var pair in Module.errorDic)
            {
                foreach (Module.Error error in pair.Value)
                {
                    string str4 = str3;
                    str3 = str4 + error.id + "\t" + error.name + "\r\n";
                }
            }
            writer.Write(str3);
            writer.Flush();
            writer.Close();
        }
    }
}

