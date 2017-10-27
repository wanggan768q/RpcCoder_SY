namespace Editor
{
    using System;
    using System.Collections;
    using System.Diagnostics;
    using System.IO;
    using System.Text;

    internal class DrawPic
    {
        private static BinaryWriter bw;
        private static bool isCToS = false;
        private static bool isSToC = false;
        private static ArrayList saves = new ArrayList();

        public static void Draw(Module m)
        {
            try
            {
                bw = new BinaryWriter(new FileStream(m.ModuleName + ".pic", FileMode.Create));
            }
            catch (IOException)
            {
                return;
            }
            if (!Directory.Exists("Out/Txt_NoExe/"))
            {
                Directory.CreateDirectory("Out/Txt_NoExe/");
            }
            StreamWriter writer = null;
            UTF8Encoding encoding = new UTF8Encoding(false);
            writer = new StreamWriter("Out/Txt_NoExe/" + m.ModuleName + ".txt", false, encoding);
            string writesV = "";
            foreach (DataStruct struct2 in m.moduleDataStruct)
            {
                Save save = new Save();
                int mytype = 0;
                if (struct2.DataType == DataStruct.SyncType.RPCData)
                {
                    mytype = 1;
                    LookFor(m, struct2.StructName, struct2.CNName, "", ref writesV, ref save, mytype);
                }
                else if (((DataStruct.SyncType.UserData == struct2.DataType) || (DataStruct.SyncType.ItemData == struct2.DataType)) || ((DataStruct.SyncType.CacheData == struct2.DataType) && struct2.SyncToClient))
                {
                    mytype = 2;
                    LookFor(m, struct2.StructName, struct2.CNName, "", ref writesV, ref save, mytype);
                }
                writesV = writesV + "\r\n";
            }
            writer.Write(writesV);
            writer.Close();
            bw.Close();
            Process process = new Process();
            string fileName = "DrawPci.exe";
            string arguments = " Out/Pic_NoExe/ " + m.ModuleName + ".pic";
            if (!Directory.Exists("Out/Pic_NoExe/"))
            {
                Directory.CreateDirectory("Out/Pic_NoExe/");
            }
            ProcessStartInfo info = new ProcessStartInfo(fileName, arguments);
            process.StartInfo = info;
            process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            process.Start();
            while (!process.HasExited)
            {
                process.WaitForExit();
            }
            int exitCode = process.ExitCode;
        }

        public static void LookFor(Module m, string names, string shuoming, string t, ref string writesV, ref Save save, int mytype)
        {
            DataStruct struct2 = null;
            if (!DataStruct.DataStructDic.TryGetValue(names, out struct2))
            {
                DataStruct.DataStructDic.TryGetValue(m.ModuleName + names, out struct2);
            }
            if (struct2 == null)
            {
                struct2 = m.getModuleStruct(names);
            }
            if (struct2 != null)
            {
                string str = (t == "") ? struct2.getFullName() : (t + "[" + names + "]");
                writesV = writesV + str;
                byte[] bytes = Encoding.Default.GetBytes(struct2.CNName);
                int length = bytes.Length;
                bw.Write(length);
                bw.Write(bytes, 0, length);
                bw.Write(names.Length);
                bw.Write(names.ToCharArray(0, names.Length));
                Module.OperaterItem.SubOperaterItem subOperaterItem = m.GetSubOperaterItem(names, "");
                if (subOperaterItem == null)
                {
                    bw.Write(false);
                    bw.Write(false);
                }
                else if (subOperaterItem.Type == Module.OperateType.OP_ASK)
                {
                    bw.Write(true);
                    bw.Write(false);
                    writesV = writesV + "↑ " + struct2.CNName;
                }
                else if (subOperaterItem.Type == Module.OperateType.OP_REPLY)
                {
                    bw.Write(false);
                    bw.Write(true);
                    writesV = writesV + "↓ " + struct2.CNName;
                }
                else if (subOperaterItem.Type == Module.OperateType.OP_CLIENT_NOTIFY)
                {
                    bw.Write(true);
                    bw.Write(false);
                    writesV = writesV + "↑ " + struct2.CNName;
                }
                else if (subOperaterItem.Type == Module.OperateType.OP_SERVER_NOTIFY)
                {
                    bw.Write(false);
                    bw.Write(true);
                    writesV = writesV + "↓ " + struct2.CNName;
                }
                else
                {
                    bw.Write(true);
                    bw.Write(true);
                    writesV = writesV + "↑↓ " + struct2.CNName;
                }
                writesV = writesV + "\r\n";
                bw.Write(mytype);
                bw.Write(struct2.fieldItem.Count);
                foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                {
                    bw.Write(names.Length);
                    bw.Write(names.ToCharArray(0, names.Length));
                    save.Name = descriptor.FieldName;
                    int num2 = save.Name.Length;
                    bw.Write(num2);
                    bw.Write(save.Name.ToCharArray(0, num2));
                    save.Repet = descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated;
                    bw.Write(save.Repet);
                    save.Value = "";
                    if ((((descriptor.FieldType == "bool") || (descriptor.FieldType == "float")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64") || (descriptor.FieldType == "uint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                    {
                        save.Value = "[" + descriptor.DefaultValue + "]";
                    }
                    num2 = save.Value.Length;
                    bw.Write(num2);
                    bw.Write(save.Value.ToCharArray(0, num2));
                    save.CNName = descriptor.CNName;
                    byte[] buffer = Encoding.Default.GetBytes(save.CNName);
                    num2 = buffer.Length;
                    bw.Write(num2);
                    bw.Write(buffer, 0, num2);
                    save.Type = descriptor.FieldType;
                    num2 = save.Type.Length;
                    bw.Write(num2);
                    bw.Write(save.Type.ToCharArray(0, num2));
                    if (descriptor.FieldType == "string")
                    {
                        bw.Write(false);
                        string str3 = writesV;
                        writesV = str3 + t + "\t" + descriptor.FieldName + ":string" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "bytes")
                    {
                        bw.Write(false);
                        string str4 = writesV;
                        writesV = str4 + t + "\t" + descriptor.FieldName + ":bytes" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "bool")
                    {
                        bw.Write(false);
                        string str5 = writesV;
                        writesV = str5 + t + "\t" + descriptor.FieldName + ":bool" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "float")
                    {
                        bw.Write(false);
                        string str6 = writesV;
                        writesV = str6 + t + "\t" + descriptor.FieldName + ":float" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "sint32")
                    {
                        bw.Write(false);
                        string str7 = writesV;
                        writesV = str7 + t + "\t" + descriptor.FieldName + ":int32" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "sint64")
                    {
                        bw.Write(false);
                        string str8 = writesV;
                        writesV = str8 + t + "\t" + descriptor.FieldName + ":sint64" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else if (descriptor.FieldType == "uint64")
                    {
                        bw.Write(false);
                        string str8 = writesV;
                        writesV = str8 + t + "\t" + descriptor.FieldName + ":uint64" + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + ((descriptor.DefaultValue == "") ? "" : (" = " + descriptor.DefaultValue)) + "\t;" + descriptor.CNName + "\r\n";
                    }
                    else
                    {
                        bw.Write(true);
                        string str9 = writesV;
                        writesV = str9 + t + "\t" + descriptor.FieldName + ":" + descriptor.FieldType + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "*" : "") + "\t;" + descriptor.CNName + "\r\n";
                        string str2 = t + "\t";
                        save.Next = new Save();
                        Save next = save.Next;
                        LookFor(m, descriptor.FieldType, "", str2, ref writesV, ref next, mytype);
                    }
                }
            }
        }
    }
}

