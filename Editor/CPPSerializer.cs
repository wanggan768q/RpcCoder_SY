namespace Editor
{
    using System;
    using System.Collections;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class CPPSerializer
    {
        public static void GenClassWraperCode(Module m, DataStruct ds, ref string strWraper)
        {
            string str = "";
            StreamReader reader = new StreamReader("./Template/WraperTemplate.cpp", Encoding.GetEncoding("GBK"));
            str = reader.ReadToEnd();
            reader.Close();
            string str2 = "";
            if (ds.ProtoType == DataStruct.protoTypeE.SyncProto)
            {
                str2 = "V" + m.SyncDataVersion;
            }
            string newValue = ds.getFullName() + "Wraper" + str2;
            string str4 = ds.getFullName() + str2;
            string str5 = "";
            string str6 = "";
            string str7 = "";
            string str8 = "";
            string str9 = "";
            string str10 = "";
            string str11 = "";
            string str12 = "";
            if (((ds.DataType == DataStruct.SyncType.ModuleData) || (ds.DataType == DataStruct.SyncType.CacheData)) || (ds.DataType == DataStruct.SyncType.UserData))
            {
                //str9 = ", public ModuleDataInterface , public ModuleDataRegister<" + newValue + ">";
                //str10 = "SetDataWraper( this );\r\n";
            }
            foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
            {
                string str13;
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    str13 = str7;
                    str7 = str13 + "\t\tm_" + descriptor.FieldName + " = v." + descriptor.FieldName.ToLower() + "();\r\n";
                    str8 = str8 + "private:\r\n\t//" + descriptor.CNName + "\r\n";
                    string str14 = str8;
                    str8 = str14 + "\t" + descriptor.ToGetFieldType() + " m_" + descriptor.FieldName + ";\r\npublic:\r\n";
                    string str15 = str12;
                    //str12 = str15 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "(" + descriptor.CNName + ") [" + descriptor.FieldType + "]</li>\\r\\n\";\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        string str16 = str6;
                        str6 = str16 + "\t\tv.set_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + " );\r\n";
                        string str17 = str8;
                        str8 = str17 + "\tvoid Set" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str18 = str8;
                        str8 = str18 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str19 = str8;
                        str8 = str19 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "() const\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str20 = str5;
                        str5 = str20 + "\t\tm_" + descriptor.FieldName + " = " + descriptor.DefaultValue + ";\r\n";
                        if ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "bool"))
                        {
                            string str21 = str11;
                            //str11 = str21 + "\t\ttmpLine.Fmt(\"<li>" + descriptor.FieldName + "：%di</li>\\r\\n\",m_" + descriptor.FieldName + ");\r\n";
                            //str11 = str11 + "\t\thtmlBuff += tmpLine;\r\n";
                        }
                        else if (descriptor.FieldType == "float")
                        {
                            string str22 = str11;
                            //str11 = str22 + "\t\ttmpLine.Fmt(\"<li>" + descriptor.FieldName + "：%.2ff</li>\\r\\n\",m_" + descriptor.FieldName + ");\r\n";
                            //str11 = str11 + "\t\thtmlBuff += tmpLine;\r\n";
                        }
                        else
                        {
                            string str23 = str11;
                            //str11 = str23 + "\t\ttmpLine.Fmt(\"<li>" + descriptor.FieldName + "：%lldL</li>\\r\\n\",m_" + descriptor.FieldName + ");\r\n";
                            //str11 = str11 + "\t\thtmlBuff += tmpLine;\r\n";
                        }
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        if (descriptor.FieldType == "bytes")
                        {
                            //str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：\\\"...\\\"</li>\\r\\n\";\r\n";
                        }
                        else
                        {
                            string str24 = str11;
                            //str11 = str24 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：\\\"\"+m_" + descriptor.FieldName + "+\"\\\"</li>\\r\\n\";\r\n";
                        }
                        string str25 = str6;
                        str6 = str25 + "\t\tv.set_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + " );\r\n";
                        string str26 = str8;
                        str8 = str26 + "\tvoid Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str27 = str8;
                        str8 = str27 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str28 = str8;
                        str8 = str28 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "() const\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        str5 = str5 + "\t\tm_" + descriptor.FieldName + " = \"\";\r\n";
                    }
                    else
                    {
                        //str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：</li>\\r\\n\";\r\n";
                        //str11 = str11 + "\t\thtmlBuff += m_" + descriptor.FieldName + ".HtmlDescHeader();\r\n";
                        //str11 = str11 + "\t\thtmlBuff += m_" + descriptor.FieldName + ".ToHtml();\r\n";
                        string str29 = str6;
                        str6 = str29 + "\t\t*v.mutable_" + descriptor.FieldName.ToLower() + "()= m_" + descriptor.FieldName + ".ToPB();\r\n";
                        string str30 = str8;
                        str8 = str30 + "\tvoid Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str31 = str8;
                        str8 = str31 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str32 = str8;
                        str8 = str32 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "() const\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str33 = str5;
                        str5 = str33 + "\t\tm_" + descriptor.FieldName + " = " + descriptor.ToGetFieldType() + "();\r\n";
                    }
                }
                else
                {
                    str7 = str7 + "\t\tm_" + descriptor.FieldName + ".clear();\r\n";
                    string str34 = str7;
                    str7 = str34 + "\t\tm_" + descriptor.FieldName + ".reserve(v." + descriptor.FieldName.ToLower() + "_size());\r\n";
                    str7 = str7 + "\t\tfor( int i=0; i<v." + descriptor.FieldName.ToLower() + "_size(); i++)\r\n";
                    string str35 = str7;
                    str7 = str35 + "\t\t\tm_" + descriptor.FieldName + ".push_back(v." + descriptor.FieldName.ToLower() + "(i));\r\n";
                    str8 = str8 + "private:\r\n\t//" + descriptor.CNName + "\r\n";
                    str13 = str8;
                    str8 = str13 + "\tvector<" + descriptor.ToGetFieldType() + "> m_" + descriptor.FieldName + ";\r\npublic:\r\n";
                    str13 = str8;
                    str8 = str13 + "\tint Size" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ".size();\r\n\t}\r\n";
                    str13 = str8;
                    str8 = str13 + "\tconst vector<" + descriptor.ToGetFieldType() + ">& Get" + descriptor.FieldName + "() const\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                    str13 = str8;
                    str8 = str13 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "(int Index) const\r\n\t{\r\n";
                    str13 = str8;
                    str8 = str13 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn " + descriptor.ToGetFieldType() + "();\r\n\t\t}\r\n";
                    str8 = str8 + "\t\treturn m_" + descriptor.FieldName + "[Index];\r\n\t}\r\n";
                    str13 = str8;
                    str8 = str13 + "\tvoid Set" + descriptor.FieldName + "( const vector<" + descriptor.ToGetFieldType() + ">& v )\r\n\t{\r\n";
                    str8 = str8 + "\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                    str8 = str8 + "\tvoid Clear" + descriptor.FieldName + "( )\r\n\t{\r\n";
                    str8 = str8 + "\t\tm_" + descriptor.FieldName + ".clear();\r\n\t}\r\n";
                    str13 = str6;
                    str6 = str13 + "\t\tv.mutable_" + descriptor.FieldName.ToLower() + "()->Reserve(m_" + descriptor.FieldName + ".size());\r\n";
                    str13 = str12;
                    //str12 = str13 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "(" + descriptor.CNName + ") [" + descriptor.FieldType + "] Array</li>\\r\\n\";\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        if ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "bool"))
                        {
//                             str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：</li>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff +=\"<div style=\\\"padding-left:15px\\\"><table border=1>\\r\\n<tr>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\tfor( int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++){\r\n";
//                             str11 = str11 + "\t\t\ttmpLine.Fmt(\"<td>%di</td>\\r\\n\",m_" + descriptor.FieldName + "[i]);\r\n";
//                             str11 = str11 + "\t\t\thtmlBuff += tmpLine;\r\n";
//                             str11 = str11 + "\t\t\tif((i+1)%10==0) htmlBuff += \"</tr>\\r\\n<tr>\";\r\n";
//                             str11 = str11 + "\t\t}\r\n";
//                             str11 = str11 + "\t\tif( (m_" + descriptor.FieldName + ".size() +1)%10 != 0 ) htmlBuff += \"</tr>\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff += \"</table></div>\";\r\n";
                        }
                        else if (descriptor.FieldType == "float")
                        {
//                             str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：</li>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff +=\"<div style=\\\"padding-left:15px\\\"><table border=1>\\r\\n<tr>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\tfor( int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++){\r\n";
//                             str11 = str11 + "\t\t\ttmpLine.Fmt(\"<td>%.2ff</td>\\r\\n\",m_" + descriptor.FieldName + "[i]);\r\n";
//                             str11 = str11 + "\t\t\thtmlBuff += tmpLine;\r\n";
//                             str11 = str11 + "\t\t\tif((i+1)%10==0) htmlBuff += \"</tr>\\r\\n<tr>\";\r\n";
//                             str11 = str11 + "\t\t}\r\n";
//                             str11 = str11 + "\t\tif( (m_" + descriptor.FieldName + ".size() +1)%10 != 0 ) htmlBuff += \"</tr>\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff += \"</table></div>\";\r\n";
                        }
                        else
                        {
//                             str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：</li>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff +=\"<div style=\\\"padding-left:15px\\\"><table border=1>\\r\\n<tr>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\tfor( int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++){\r\n";
//                             str11 = str11 + "\t\t\ttmpLine.Fmt(\"<td>%lldL</td>\\r\\n\",m_" + descriptor.FieldName + "[i]);\r\n";
//                             str11 = str11 + "\t\t\thtmlBuff += tmpLine;\r\n";
//                             str11 = str11 + "\t\t\tif((i+1)%10==0) htmlBuff += \"</tr>\\r\\n<tr>\";\r\n";
//                             str11 = str11 + "\t\t}\r\n";
//                             str11 = str11 + "\t\tif( (m_" + descriptor.FieldName + ".size() +1)%10 != 0 ) htmlBuff += \"</tr>\";\r\n";
//                             str11 = str11 + "\t\thtmlBuff += \"</table></div>\";\r\n";
                        }
                        str13 = str8;
                        str8 = str13 + "\tvoid Set" + descriptor.FieldName + "( int Index, " + descriptor.ToGetFieldType() + " v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        str13 = str8;
                        str8 = str13 + "\tvoid Add" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v = " + descriptor.DefaultValue + " )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str13 = str6;
                        str6 = str13 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\tv.add_" + descriptor.FieldName.ToLower() + "(m_" + descriptor.FieldName + "[i]);\r\n\t\t}\r\n";
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        if (descriptor.FieldType == "bytes")
                        {
                            //str13 = str11;
                            //str11 = str13 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "(" + descriptor.CNName + ") [" + descriptor.FieldType + "]：</li>\\r\\n\";\r\n";
                        }
                        else
                        {
                            //str13 = str11;
//                             str11 = str13 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "(" + descriptor.CNName + ") [" + descriptor.FieldType + "]：</li>\\r\\n&nbsp;&nbsp;\"\r\n";
//                             str11 = str11 + "\t\thtmlBuff +=\"<div style=\\\"padding-left:15px\\\"><table border=1>\\r\\n\";\r\n";
//                             str11 = str11 + "\t\tfor( int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++){\r\n";
//                             str11 = str11 + "\t\t\ttmpLine.Fmt(\"<tr><td>\\\"%s\\\"</td></tr>\\r\\n\",m_" + descriptor.FieldName + "[i].c_str());\r\n";
//                             str11 = str11 + "\t\t\thtmlBuff += tmpLine;\r\n";
//                             str11 = str11 + "\t\t}\r\n";
//                             str11 = str11 + "\t\thtmlBuff += \"</table></dir>\";\r\n";
                        }
                        str13 = str8;
                        str8 = str13 + "\tvoid Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        str13 = str8;
                        str8 = str13 + "\tvoid Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str13 = str6;
                        str6 = str13 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\tv.add_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + "[i]);\r\n\t\t}\r\n";
                    }
                    else
                    {
//                         str11 = str11 + "\t\thtmlBuff += \"<li>" + descriptor.FieldName + "：</li>\\r\\n\";\r\n";
//                         str13 = str11;
//                         str11 = str13 + "\t\tif( m_" + descriptor.FieldName + ".size()>0) htmlBuff += m_" + descriptor.FieldName + "[0].HtmlDescHeader();\r\n";
//                         str11 = str11 + "\t\thtmlBuff +=\"<div style=\\\"padding-left:15px\\\"><table border=1>\\r\\n\";\r\n";
//                         str11 = str11 + "\t\tfor( int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++){\r\n";
//                         str11 = str11 + "\t\t\ttmpLine.Fmt(\"%d\",i);\r\n";
//                         str11 = str11 + "\t\t\thtmlBuff += \"<tr><td>\"+ tmpLine+\"</td><td>\"+m_" + descriptor.FieldName + "[i].ToHtml().c_str() +\"</td></tr>\";\r\n";
//                         str11 = str11 + "\t\t}\r\n";
//                         str11 = str11 + "\t\thtmlBuff += \"</table></div>\";\r\n";
                        str13 = str8;
                        str8 = str13 + "\tvoid Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        str13 = str8;
                        str8 = str13 + "\tvoid Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str13 = str6;
                        str6 = str13 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\t*v.add_" + descriptor.FieldName.ToLower() + "() = m_" + descriptor.FieldName + "[i].ToPB();\r\n\t\t}\r\n";
                    }
                }
            }
            str = str.Replace("$CNName$", ds.CNName)
                .Replace("$WraperName$", newValue)
                .Replace("$PBName$", str4)
                .Replace("$ConstructField$", str5)
                .Replace("$ToPBField$", str6)
                .Replace("$InitFuncField$", str7)
                .Replace("$GetSetSizeField$", str8)
                .Replace("$ModuleDataWraperDef$", str9)
                .Replace("$ModuleDataSetWraper$", str10)
                .Replace("$htmlField$", str11)
                .Replace("$HtmlFieldHeader$", str12)
                ;
            strWraper = strWraper + str;
        }

        private static void GenRpcCode(Module m, Module.OperaterItem operate, ref string msgId, ref string ModuleAllName, ref string OperationDeclare, ref string OperationImpl, ref string OperationImplement, ref int num, ref int num2, ref string DefMessageIdT)
        {
            string str10;
            int num6;
            string str = "";
            DataStruct struct2 = null;
            DataStruct struct3 = null;
            DataStruct struct4 = null;
            string clientNotify = "";
            Module.OperateType type = Module.OperateType.OP_NONE;
            string pbClassName = "" ;
            foreach (Module.OperaterItem.SubOperaterItem item in operate.subOperateItem)
            {
                string text1 = operate.Name + item.Name;
                if (item.Type == Module.OperateType.OP_ASK)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct2))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct2);
                    }
                    str = struct2.getFullName();
                }
                if (item.Type == Module.OperateType.OP_REPLY)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct3))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct3);
                    }
                    struct3.getFullName();
                }
                if (((item.Type == Module.OperateType.OP_NOTIFY) || (item.Type == Module.OperateType.OP_SERVER_NOTIFY)) || ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY)))
                {
                    type = item.Type;
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct4))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct4);
                    }
                    struct4.getFullName();
                    clientNotify = struct4.getFullName();
                }
                pbClassName = m.ModuleName + item.DataStructName;
            }
            string str2 = "INT64 UserId, ";
            string str3 = "RPC";
            string str4 = "Rpc";
            string str5 = "";
            string str6 = "";
            string str7 = "Request";
            string str8 = "请求";
            
            if (str.Length > 0)
            {
                str6 = "";
                str10 = str6 + "\t/********************************************************************************************\r\n";
                string str11 = str10 + "\t* Function:       " + str4 + operate.Name + "\r\n";
                string str12 = str11 + "\t* Description:    " + m.CNName + "-->" + operate.CNName + "同步调用操作函数\r\n";
                string str13 = str12 + "\t* Input:          " + struct2.getFullName() + "Wraper& Ask " + struct2.CNName + "\r\n";
                str6 = ((str13 + "\t* Output:         " + struct3.getFullName() + "Wraper& Reply " + struct3.CNName + "\r\n") + "\t* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) \r\n") + "\t*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)\r\n" + "\t********************************************************************************************/\r\n";
                OperationDeclare = OperationDeclare + str6;
                string str14 = OperationDeclare;
                OperationDeclare = str14 + "\tstatic int " + str4 + operate.Name + "( CPlayer* pPlayer, CPacket* pPacket );\r\n\r\n";
                str6 = str6.Replace("\t", "");
                OperationImplement = OperationImplement + str6;
                string str15 = OperationImplement;
                OperationImplement = str15 + "static int Module" + m.ModuleName + "::" + str4 + operate.Name + "( CPlayer* pPlayer, CPacket* pPacket)\r\n{\r\n";
                OperationImplement = OperationImplement + "\r\n\t//逻辑代码\r\n\r\n\r\n";
                OperationImplement = OperationImplement + "\t//设置返回结果\r\n";
                OperationImplement = OperationImplement + "\tReply.SetResult(0);\r\n";
                OperationImplement = OperationImplement + "\treturn 0;\r\n}\r\n\r\n";
                str5 = str3 + "_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
                //string str16 = DefMessageIdT;
                //DefMessageIdT = str16 + "template<> struct MessageIdT<" + struct2.getFullName() + "Wraper>{ enum{ID=" + str5 + "};};\r\n";
                //string str17 = DefMessageIdT;
                //DefMessageIdT = str17 + "template<> struct MessageIdT<" + struct3.getFullName() + "Wraper>{ enum{ID=" + str5 + "};};\r\n";
            }
            else
            {
                switch (type)
                {
                    case Module.OperateType.OP_NOTIFY:
                    case Module.OperateType.OP_CLIENT_NOTIFY:
                    case Module.OperateType.OP_DUPLEX_NOTIFY:
                        {
                            str7 = "Notify";
                            str8 = "通知";
                            str6 = "";
                            string str18 = str6 + "\t/********************************************************************************************\r\n";
                            string str19 = str18 + "\t* Function:       " + str4 + operate.Name + "\r\n";
                            string str20 = str19 + "\t* Description:    " + m.CNName + "-->" + operate.CNName + "异步通知操作函数\r\n";
                            str6 = ((str20 + "\t* Input:          " + struct4.getFullName() + "Wraper& Notify " + struct4.CNName + "\r\n") + "\t* Output:         无\r\n" + "\t* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) \r\n") + "\t*                     低16位无效\r\n" + "\t********************************************************************************************/\r\n";
                            OperationDeclare = OperationDeclare + str6;
                            string str21 = OperationDeclare;
                            OperationDeclare = str21 + "\tstatic int " + str4 + operate.Name + "(  CPlayer* pPlayer, CPacket* pPacket );\r\n\r\n";
                            str6 = str6.Replace("\t", "");
                            OperationImplement = OperationImplement + str6;
                            string str22 = OperationImplement;
                            OperationImplement = str22 + "int Module" + m.ModuleName + "::" + str4 + operate.Name + "( " + str2 + struct4.getFullName() + "Wraper& Notify )\r\n{\r\n";
                            foreach (DataStruct.FieldDescriptor descriptor in struct4.fieldItem)
                            {
                                if ((descriptor.GetTypeEnum() != 3) && (descriptor.PreDefine != DataStruct.FieldDescriptor.PreDefineType.repeated))
                                {
                                    object obj2;
                                    OperationImplement = OperationImplement + "\r\n\t//检测字段[" + descriptor.CNName + "]数据范围\r\n";
                                    if (descriptor.GetTypeEnum() == 1)
                                    {
                                        obj2 = OperationImplement;
                                        OperationImplement = string.Concat(new object[] { obj2, "\tif( Notify.Get", descriptor.FieldName, "()<", descriptor.MinValue, " && Notify.Get", descriptor.FieldName, "()!=", descriptor.DefaultValue, ")\r\n\t{\r\n" });
                                        OperationImplement = OperationImplement + "\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        object obj3 = OperationImplement;
                                        OperationImplement = string.Concat(new object[] { obj3, "\tif( Notify.Get", descriptor.FieldName, "()>", descriptor.MaxValue, " && Notify.Get", descriptor.FieldName, "()!=", descriptor.DefaultValue, ")\r\n\t{\r\n" });
                                        OperationImplement = OperationImplement + "\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        if (descriptor.ValueSet.Length > 0)
                                        {
                                            string[] strArray = descriptor.ValueSet.Split(new char[] { ',' });
                                            string str23 = OperationImplement;
                                            OperationImplement = str23 + "\tif( Notify.Get" + descriptor.FieldName + "()!=" + descriptor.DefaultValue + " &&\r\n";
                                            for (int i = 0; i < strArray.Length; i++)
                                            {
                                                if (strArray[i].Length != 0)
                                                {
                                                    object obj4 = OperationImplement;
                                                    OperationImplement = string.Concat(new object[] { obj4, "\t\tNotify.Get", descriptor.FieldName, "()!=", Convert.ToInt32(strArray[i]) });
                                                    if (i < (strArray.Length - 1))
                                                    {
                                                        OperationImplement = OperationImplement + " &&\r\n";
                                                    }
                                                }
                                            }
                                            OperationImplement = OperationImplement + " )\r\n\t{\r\n\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        }
                                    }
                                    if (descriptor.GetTypeEnum() == 2)
                                    {
                                        object obj5 = OperationImplement;
                                        OperationImplement = string.Concat(new object[] { obj5, "\tif( Notify.Get", descriptor.FieldName, "().length()<", descriptor.MinValue, " ) \r\n\t{\r\n" });
                                        OperationImplement = OperationImplement + "\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        obj2 = OperationImplement;
                                        OperationImplement = string.Concat(new object[] { obj2, "\tif( Notify.Get", descriptor.FieldName, "().length()>", descriptor.MaxValue, ") \r\n\t{\r\n" });
                                        OperationImplement = OperationImplement + "\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        if ((descriptor.ValueSet.Length > 0) || (descriptor.DefaultValue.Length > 0))
                                        {
                                            string[] strArray2 = descriptor.ValueSet.Split(new char[] { ',' });
                                            if (descriptor.DefaultValue.Length > 0)
                                            {
                                                str10 = OperationImplement;
                                                OperationImplement = str10 + "\tif( Notify.Get" + descriptor.FieldName + "()!=\"" + descriptor.DefaultValue;
                                                if (strArray2.Length > 0)
                                                {
                                                    OperationImplement = OperationImplement + "\" &&\r\n";
                                                }
                                                else
                                                {
                                                    OperationImplement = OperationImplement + "\"";
                                                }
                                            }
                                            else
                                            {
                                                OperationImplement = OperationImplement + "\tif(";
                                            }
                                            for (int j = 0; j < strArray2.Length; j++)
                                            {
                                                if (strArray2[j].Length != 0)
                                                {
                                                    string str9 = "\t\t";
                                                    if ((j == 0) && (descriptor.DefaultValue.Length == 0))
                                                    {
                                                        str9 = " ";
                                                    }
                                                    str10 = OperationImplement;
                                                    OperationImplement = str10 + str9 + "Notify.Get" + descriptor.FieldName + "()!=\"" + strArray2[j] + "\"";
                                                    if (j < (strArray2.Length - 1))
                                                    {
                                                        OperationImplement = OperationImplement + " &&\r\n";
                                                    }
                                                }
                                            }
                                            OperationImplement = OperationImplement + " )\r\n\t{\r\n\t\tassert(false);\r\n\t\treturn 0;\r\n\t}\r\n";
                                        }
                                    }
                                }
                            }
                            OperationImplement = OperationImplement + "\r\n\t//逻辑代码\r\n\r\n\r\n";
                            OperationImplement = OperationImplement + "\treturn 0;\r\n}\r\n\r\n";
                            break;
                        }
                }
                if ((type == Module.OperateType.OP_SERVER_NOTIFY) || (type == Module.OperateType.OP_DUPLEX_NOTIFY))
                {
                    str7 = "Notify";
                    str8 = "通知";
                    str6 = "";
                    str10 = (str6 + "\t/********************************************************************************************\r\n") + "\t* Function:       SendToClient" + operate.Name + "\r\n";
                    str10 = str10 + "\t* Description:    " + m.CNName + "-->" + operate.CNName + "异步通知操作函数\r\n";
                    str6 = ((str10 + "\t* Input:          " + struct4.getFullName() + "Wraper& Notify " + struct4.CNName + "\r\n") + "\t* Input:          INT64 UserId 需要通知到的用户ID\r\n" + "\t* Output:         无\r\n") + "\t* Return:         无\r\n" + "\t********************************************************************************************/\r\n";
                    OperationDeclare = OperationDeclare + str6;
                    str10 = OperationDeclare;
                    OperationDeclare = str10 + "\t//virtual void SendToClient" + operate.Name + "( INT64 UserId, " + struct4.getFullName() + "Wraper& Notify );\r\n\r\n";
                    str6 = str6.Replace("\t", "");
                    OperationImplement = OperationImplement + str6;
                    str10 = OperationImplement;
                    OperationImplement = str10 + "void Module" + m.ModuleName + "::SendToClient" + operate.Name + "( INT64 UserId, " + struct4.getFullName() + "Wraper& Notify )\r\n{\r\n";
                    OperationImplement = OperationImplement + "\tMsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );\r\n}\r\n\r\n";
                }
                str5 = str3 + "_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
                str10 = DefMessageIdT;
                DefMessageIdT = str10 + "template<> struct MessageIdT<" + struct4.getFullName() + "Wraper>{ enum{ID=" + str5 + "};};\r\n";
            }
            str5 = "\t" + str3 + "_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
            string enumId = str5;
            int num5 = 0x2e - str5.Length;
            while (num5-- > 0)
            {
                str5 = str5 + " ";
            }
            num2 = num6 = num2 + 1;
            str10 = str5 + "= " + ((num6 + 50) + (m.StartIdNum * 100));
            str5 = str10 + ",\t//" + m.CNName + "-->" + operate.CNName + "-->" + str8 + "\r\n";
            msgId = msgId + str5;
            str5 = str3 + "_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
            if (type != Module.OperateType.OP_SERVER_NOTIFY)
            {
                str10 = OperationImpl;
                //OperationImpl = str10 + "\tMsgIdMgr::Instance().MsgRegister( this, &Module" + m.ModuleName + "::" + str4 + operate.Name + ");\r\n";
                //g_pPacketMgr->registerHandle((Packets::PACKET_DEFINE)(ID), &ModuleBag::RpcSell);
                //g_pPacketMgr->registerPacketFacotry(RPC_CODE_LOGIN_CONNECT_REQUEST, new Some_Factory<LoginRpcConnectAsk>(), new Some_Factory<LoginRpcConnectReply>());
                //str5 = str3 + "_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
                string ssssss = "RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_" + str7.ToUpper();
                OperationImpl = str10 + "\tg_pPacketMgr->registerHandle(" + enumId + ", &Module" + m.ModuleName + "::" + str4 + operate.Name + ");\r\n";
                if (str == "")
                {
                    str = clientNotify;
                }
                //OperationImpl = str10 + "\tg_pPacketMgr->registerHandle(" + enumId + ", new Some_Factory<" + str + ">());\r\n";
                OperationImpl += "\tg_pPacketMgr->registerPacketFacotry(" + enumId + ", new Some_Factory<" + str + ">());\r\n";
            }
        }

        private static void GenSyncDataCode(Module m, DataStruct ds, ref string syncIds, ref string SyncOpDefine, ref string SyncOpImp, ref string SendAllFields, ref string DBCacheField,ref string BindCalc,ref string RefreshField, ref string GetField)
        {
            string str = "V" + m.SyncDataVersion;
            string text1 = ds.StructName + "Wraper" + str;
            string str2 = "SyncData" + m.ModuleName + str;
            string str3 = "";
            foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
            {
                //m_oCaclPropertyCallbacks.emplace(SYNCID_BASEATTR_EXP, std::move(std::bind(&Obj_Character::CalcHitValue, pObj)));
                string enumKey = "SYNCID_" + m.ModuleName.ToUpper() + "_" + descriptor.FieldName.ToUpper();
                BindCalc = BindCalc + "\tm_oCaclPropertyCallbacks.emplace(" + enumKey + ",std::move(std::bind(&Obj_Character::Calc" + descriptor.FieldName + ", pObj)));\r\n";
                SendAllFields = SendAllFields + "\tSend" + descriptor.FieldName + "(OnlyToClient);\r\n";
                string str4 = " \t" + enumKey;
                RefreshField = RefreshField + "\tRefresh" + descriptor.FieldName + "();\r\n";
                GetField = GetField + "\tGet" + descriptor.FieldName + "();\r\n";
                string str8 = str3;
                str3 = str8 + "\tcase SYNCID_" + m.ModuleName.ToUpper() + "_" + descriptor.FieldName.ToUpper() + ":\r\n";
                int num = 0x2e - str4.Length;
                while (num-- > 0)
                {
                    str4 = str4 + " ";
                }
                object obj2 = str4;
                str4 = string.Concat(new object[] { obj2, "= ", (m.StartIdNum * 100) + descriptor.FieldId, ",  //", descriptor.CNName, "\r\n" });
                syncIds = syncIds + str4;
                SyncOpDefine = SyncOpDefine + "public:\r\n\t//" + descriptor.CNName + "\r\n";
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    string str9 = SyncOpDefine;
                    SyncOpDefine = str9 + "\tvoid Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v );\r\n";
                    string str10 = SyncOpDefine;
                    SyncOpDefine = str10 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "();\r\n";
                    SyncOpDefine = SyncOpDefine + "\tvoid Refresh" + descriptor.FieldName + "();\r\n";
                    SyncOpDefine = SyncOpDefine + "\tvoid Send" + descriptor.FieldName + "(bool OnlyToClient=true);\r\n";
                }
                else
                {
                    string str11 = SyncOpDefine;
                    SyncOpDefine = str11 + "\tvoid Set" + descriptor.FieldName + "( const vector<" + descriptor.ToGetFieldType() + ">& v );\r\n";
                    string str12 = SyncOpDefine;
                    SyncOpDefine = str12 + "\tvoid Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v );\r\n";
                    string str13 = SyncOpDefine;
                    SyncOpDefine = str13 + "\tvector<" + descriptor.ToGetFieldType() + "> Get" + descriptor.FieldName + "();\r\n";
                    string str14 = SyncOpDefine;
                    SyncOpDefine = str14 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "( int Index );\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        string str15 = SyncOpDefine;
                        SyncOpDefine = str15 + "\tvoid Add" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v=" + descriptor.DefaultValue + " );\r\n";
                    }
                    else
                    {
                        string str16 = SyncOpDefine;
                        SyncOpDefine = str16 + "\tvoid Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v);\r\n";
                    }
                    SyncOpDefine = SyncOpDefine + "\tvoid Send" + descriptor.FieldName + "( int Index,bool OnlyToClient=true );\r\n";
                    SyncOpDefine = SyncOpDefine + "\tvoid Send" + descriptor.FieldName + "(bool OnlyToClient=true);\r\n";
                    string str17 = SyncOpDefine;
                    SyncOpDefine = str17 + "\tint  Size" + descriptor.FieldName + "(){ return m_syncData" + ds.StructName + ".Size" + descriptor.FieldName + "(); }\r\n";
                }
                string str5 = "SYNCID_" + m.ModuleName.ToUpper() + "_" + descriptor.FieldName.ToUpper();
                string str6 = "Module" + m.ModuleName;
                string str7 = "m_syncData" + ds.StructName;
                SyncOpImp = SyncOpImp + "\r\n//" + descriptor.CNName + "\r\n";
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    string str18 = SyncOpImp;
                    SyncOpImp = str18 + "void " + str2 + "::Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n{\r\n";
                    string str19 = SyncOpImp;
                    //SyncOpImp = str19 + "\t" + str7 + ".Set" + descriptor.FieldName + "(v);\r\n\tOnDataChange();\r\n";
                    SyncOpImp = str19 + "\t" + str7 + ".Set" + descriptor.FieldName + "(v);\r\n";
                    string str20 = SyncOpImp;
                    //SyncOpImp = str20 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ");\r\n";
                    //SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(false);\r\n}\r\n";
                    SyncOpImp = SyncOpImp + "\tm_ClientDataUserData.set_" + descriptor.FieldName.ToLower() + "(v);\r\n";

                    SyncOpImp = SyncOpImp + "\tif (g_SyncOtherProperty.IsInOtherSync(" + str5 + "))\r\n";
                    SyncOpImp = SyncOpImp + "\t{\r\n";
                    SyncOpImp = SyncOpImp + "\t\tm_OtherDataUserData.set_" + descriptor.FieldName.ToLower() + "(v);\r\n";
                    SyncOpImp = SyncOpImp + "\t\tSetOtherChange(true);\r\n";
                    SyncOpImp = SyncOpImp + "\t}\r\n";
                    
                    SyncOpImp = SyncOpImp + "\tSetChange(true);\r\n}\r\n";
                    string str21 = SyncOpImp;
                    SyncOpImp = str21 + descriptor.ToGetFieldType() + " " + str2 + "::Get" + descriptor.FieldName + "()\r\n{\r\n";
                    string str22 = SyncOpImp;
                    //CalcMethodCB(SYNCID_BASEATTR_MAXHP, std::bind(&SyncDataBaseAttrV1::SetMaxHp, this, std::placeholders::_1));
                    SyncOpImp = str22 + "\tCalcMethodCB(" + enumKey + ",std::bind(&" + str2 + "::Set" + descriptor.FieldName + ",this,std::placeholders::_1));\r\n";
                    SyncOpImp = SyncOpImp + "\treturn " + str7 + ".Get" + descriptor.FieldName + "();\r\n}\r\n";

                    SyncOpImp = SyncOpImp + "void " + str2 + "::Refresh" + descriptor.FieldName + "()\r\n{\r\n";
                    SyncOpImp = SyncOpImp + "\tm_vCalcPropertyIds.insert(" + enumKey + ");\r\n}\r\n\r\n";
                    string str23 = SyncOpImp;
                    //SyncOpImp = str23 + "void " + str2 + "::Send" + descriptor.FieldName + "(bool OnlyToClient)\r\n{\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        /*
                        if (descriptor.FieldType == "bool")
                        {
                            str3 = str3 + "\t\tpDataWraper->Set" + descriptor.FieldName + "(*(bool*)pBuffer);\r\n\t\tbreak;\r\n";
                        }
                        else if (descriptor.FieldType == "float")
                        {
                            str3 = str3 + "\t\tpDataWraper->Set" + descriptor.FieldName + "(*(float*)pBuffer);\r\n\t\tbreak;\r\n";
                        }
                        else if (descriptor.FieldType == "sint32")
                        {
                            str3 = (str3 + "\t\tReadVarint32FromArray(pBuffer,&iValue);\r\n") + "\t\tpDataWraper->Set" + descriptor.FieldName + "(iValue);\r\n\t\tbreak;\r\n";
                        }
                        else
                        {
                            str3 = (str3 + "\t\tReadVarint64FromArray(pBuffer,&lValue);\r\n") + "\t\tpDataWraper->Set" + descriptor.FieldName + "(lValue);\r\n\t\tbreak;\r\n";
                        }

                        SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        if (descriptor.FieldType == "float")
                        {
                            string str24 = SyncOpImp;
                            SyncOpImp = str24 + "\t\tMsgStreamMgr::Instance().IncrementCacheF(GetKey()," + str5 + "," + str7 + ".Get" + descriptor.FieldName + "());\r\n";
                        }
                        else
                        {
                            string str25 = SyncOpImp;
                            SyncOpImp = str25 + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + "," + str7 + ".Get" + descriptor.FieldName + "());\r\n";
                        }
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            string str26 = SyncOpImp;
                            SyncOpImp = str26 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            if (descriptor.FieldType == "float")
                            {
                                string str27 = SyncOpImp;
                                SyncOpImp = str27 + "\tMsgStreamMgr::Instance().SendSyncF(GetKey()," + str5 + "," + str7 + ".Get" + descriptor.FieldName + "());\r\n";
                            }
                            else
                            {
                                string str28 = SyncOpImp;
                                SyncOpImp = str28 + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + "," + str7 + ".Get" + descriptor.FieldName + "());\r\n";
                            }
                        }
                        SyncOpImp = SyncOpImp + "}\r\n";
                        */
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        str3 = str3 + "\t\tpDataWraper->Set" + descriptor.FieldName + "(string(pBuffer,dataLen));\r\n\t\tbreak;\r\n";
                        string str29 = SyncOpImp;
                        //SyncOpImp = str29 + "\tconst string v=" + str7 + ".Get" + descriptor.FieldName + "();\r\n";
                        //SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        //SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",v.data(),v.size());\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            string str30 = SyncOpImp;
                            //SyncOpImp = str30 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",v.data(),v.size());\r\n";
                        }
                        //SyncOpImp = SyncOpImp + "}\r\n";
                    }
                    else
                    {
                        string str31 = str3;
                        string str32 = (str31 + "\t\t{\r\n\t\t\t" + descriptor.ToGetFieldType() + " tmp" + descriptor.FieldName + "Wraper;\r\n") + "\t\t\ttmp" + descriptor.FieldName + "Wraper.ParseFromArray(pBuffer,dataLen);\r\n";
                        str3 = str32 + "\t\t\tpDataWraper->Set" + descriptor.FieldName + "(tmp" + descriptor.FieldName + "Wraper);\r\n\t\t}\r\n\t\tbreak;\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\tconst string v=" + str7 + ".Get" + descriptor.FieldName + "().SerializeAsString();\r\n";
                        //SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        //SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",v.data(),v.size());\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",v.data(),v.size());\r\n";
                        }
                        SyncOpImp = SyncOpImp + "}\r\n";
                    }
                }
                else
                {
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "void " + str2 + "::Set" + descriptor.FieldName + "( const vector<" + descriptor.ToGetFieldType() + ">& v )\r\n{\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\t" + str7 + ".Set" + descriptor.FieldName + "(v);\r\n\tOnDataChange();\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ");\r\n";
                    SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(false);\r\n}\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "void " + str2 + "::Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v )\r\n{\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\t" + str7 + ".Set" + descriptor.FieldName + "(Index,v);\r\n\tOnDataChange();\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ",Index);\r\n";
                    SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(Index,false);\r\n}\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "vector<" + descriptor.ToGetFieldType() + "> " + str2 + "::Get" + descriptor.FieldName + "()\r\n{\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\treturn " + str7 + ".Get" + descriptor.FieldName + "();\r\n}\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + descriptor.ToGetFieldType() + " " + str2 + "::Get" + descriptor.FieldName + "( int Index )\r\n{\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\treturn " + str7 + ".Get" + descriptor.FieldName + "(Index);\r\n}\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "void " + str2 + "::Send" + descriptor.FieldName + "(bool OnlyToClient)\r\n{\r\n";
                    SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(-1,OnlyToClient);\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "\tfor(int i=0; i<" + str7 + ".Size" + descriptor.FieldName + "(); i++)\r\n";
                    SyncOpImp = SyncOpImp + "\t\tSend" + descriptor.FieldName + "(i,OnlyToClient);\r\n}\r\n";
                    str3 = ((((str3 + "\t\tif( Index<0 )\r\n\t\t{\r\n") + "\t\t\tpDataWraper->Clear" + descriptor.FieldName + "();\r\n\t\t\tbreak;\r\n\t\t}\r\n") + "\t\tif (Index >= pDataWraper->Size" + descriptor.FieldName + "())\r\n\t\t{\r\n") + "\t\t\tint Count = Index -pDataWraper->Size" + descriptor.FieldName + "() + 1;\r\n") + "\t\t\tfor (int i = 0; i < Count; i++)\r\n";
                    str8 = SyncOpImp;
                    SyncOpImp = str8 + "void " + str2 + "::Send" + descriptor.FieldName + "( int Index, bool OnlyToClient )\r\n{\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        str8 = str3;
                        str3 = str8 + "\t\t\t\tpDataWraper->Add" + descriptor.FieldName + "(" + descriptor.DefaultValue + ");\r\n\t\t}\r\n";
                        if (descriptor.FieldType == "bool")
                        {
                            str3 = str3 + "\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,*(bool*)pBuffer);\r\n\t\tbreak;\r\n";
                        }
                        else if (descriptor.FieldType == "float")
                        {
                            str3 = str3 + "\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,*(float*)pBuffer);\r\n\t\tbreak;\r\n";
                        }
                        else if (descriptor.FieldType == "sint32")
                        {
                            str3 = (str3 + "\t\tReadVarint32FromArray(pBuffer,&iValue);\r\n") + "\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,iValue);\r\n\t\tbreak;\r\n";
                        }
                        else
                        {
                            str3 = (str3 + "\t\tReadVarint64FromArray(pBuffer,&lValue);\r\n") + "\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,lValue);\r\n\t\tbreak;\r\n";
                        }
                        SyncOpImp = SyncOpImp + "\tif( Index<0 )\r\n\t{\r\n\t\tif( !OnlyToClient )\r\n";
                        SyncOpImp = SyncOpImp + "\t\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\t\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        }
                        SyncOpImp = SyncOpImp + "\t\treturn;\r\n\t}\r\n";
                        SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        if (descriptor.FieldType == "float")
                        {
                            str8 = SyncOpImp;
                            SyncOpImp = str8 + "\t\tMsgStreamMgr::Instance().IncrementCacheF(GetKey()," + str5 + ",Index," + str7 + ".Get" + descriptor.FieldName + "(Index));\r\n";
                        }
                        else
                        {
                            str8 = SyncOpImp;
                            SyncOpImp = str8 + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index," + str7 + ".Get" + descriptor.FieldName + "(Index));\r\n";
                        }
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            if (descriptor.FieldType == "float")
                            {
                                str8 = SyncOpImp;
                                SyncOpImp = str8 + "\tMsgStreamMgr::Instance().SendSyncF(GetKey()," + str5 + ",Index," + str7 + ".Get" + descriptor.FieldName + "(Index));\r\n";
                            }
                            else
                            {
                                str8 = SyncOpImp;
                                SyncOpImp = str8 + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index," + str7 + ".Get" + descriptor.FieldName + "(Index));\r\n";
                            }
                        }
                        SyncOpImp = SyncOpImp + "}\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "void " + str2 + "::Add" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v )\r\n{\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str7 + ".Add" + descriptor.FieldName + "(v);\r\n\tOnDataChange();\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\tint Index = " + str7 + ".Size" + descriptor.FieldName + "()-1;\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ",Index);\r\n";
                        SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(Index,false);\r\n}\r\n";
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        str3 = (str3 + "\t\t\t\tpDataWraper->Add" + descriptor.FieldName + "(\"\");\r\n\t\t}\r\n") + "\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,string(pBuffer,dataLen));\r\n\t\tbreak;\r\n";
                        SyncOpImp = SyncOpImp + "\tif( Index<0 )\r\n\t{\r\n\t\tif( !OnlyToClient )\r\n";
                        SyncOpImp = SyncOpImp + "\t\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\t\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        }
                        SyncOpImp = SyncOpImp + "\t\treturn;\r\n\t}\r\n";
                        str8 = SyncOpImp;
                        //SyncOpImp = str8 + "\tconst string v=" + str7 + ".Get" + descriptor.FieldName + "(Index);\r\n";
                        //SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index,v.data(),v.size());\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index,v.data(),v.size());\r\n";
                        }
                        SyncOpImp = SyncOpImp + "}\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "void " + str2 + "::Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n{\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str7 + ".Add" + descriptor.FieldName + "(v);\r\n\tOnDataChange();\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\tint Index = " + str7 + ".Size" + descriptor.FieldName + "()-1;\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ",Index);\r\n";
                        SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(Index,false);\r\n}\r\n";
                    }
                    else
                    {
                        str8 = str3;
                        str8 = str8 + "\t\t\t\tpDataWraper->Add" + descriptor.FieldName + "(" + descriptor.ToGetFieldType() + "());\r\n\t\t}\r\n";
                        str8 = (str8 + "\t\t{\r\n\t\t\t" + descriptor.ToGetFieldType() + " tmp" + descriptor.FieldName + "Wraper;\r\n") + "\t\t\ttmp" + descriptor.FieldName + "Wraper.ParseFromArray(pBuffer,dataLen);\r\n";
                        str3 = str8 + "\t\t\tpDataWraper->Set" + descriptor.FieldName + "(Index,tmp" + descriptor.FieldName + "Wraper);\r\n\t\t}\r\n\t\tbreak;\r\n";
                        SyncOpImp = SyncOpImp + "\tif( Index<0 )\r\n\t{\r\n\t\tif( !OnlyToClient )\r\n";
                        SyncOpImp = SyncOpImp + "\t\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\t\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index,NULL,0);\r\n";
                        }
                        SyncOpImp = SyncOpImp + "\t\treturn;\r\n\t}\r\n";
                        SyncOpImp = SyncOpImp + "\tconst string v= Get" + descriptor.FieldName + "(Index).SerializeAsString();\r\n";
                        SyncOpImp = SyncOpImp + "\tif( !OnlyToClient )\r\n";
                        SyncOpImp = SyncOpImp + "\t\tMsgStreamMgr::Instance().IncrementCache(GetKey()," + str5 + ",Index,v.data(),v.size());\r\n";
                        if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
                        {
                            str8 = SyncOpImp;
                            //SyncOpImp = str8 + "\tif(" + str6 + "::Instance().NotSyncToClient(" + str5 + ")||GetKey()==0) return;\r\n";
                            //SyncOpImp = SyncOpImp + "\tMsgStreamMgr::Instance().SendSync(GetKey()," + str5 + ",Index,v.data(),v.size());\r\n";
                        }
                        SyncOpImp = SyncOpImp + "}\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "void " + str2 + "::Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n{\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str7 + ".Add" + descriptor.FieldName + "(v);\r\n\tOnDataChange();\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\tint Index = " + str7 + ".Size" + descriptor.FieldName + "()-1;\r\n";
                        str8 = SyncOpImp;
                        SyncOpImp = str8 + "\t" + str6 + "::Instance().NotifySyncValueChanged(" + str7 + ".GetKey()," + str5 + ",Index);\r\n";
                        SyncOpImp = SyncOpImp + "\tSend" + descriptor.FieldName + "(Index,false);\r\n}\r\n";
                    }
                }
                DBCacheField = DBCacheField + str3;
                str3 = "";
            }
        }

        public static void Serialize(Module m, ref string ModuleAllName, string dir, Label label1)
        {
            if (GenLangFlags.CPP)
            {
                string obj2;
                string path = dir + @"\CPP\" + m.ModuleName + @"\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string str2 = dir + @"\CPPDBCache\" + m.ModuleName + @"\";
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                string str3 = dir + @"\CPPDBCache\PB\";
                if (!Directory.Exists(str3))
                {
                    Directory.CreateDirectory(str3);
                }
                string str4 = dir + @"\CPP\PB\";
                if (!Directory.Exists(str4))
                {
                    Directory.CreateDirectory(str4);
                }
                string str5 = dir + @"\CPP\Config\";
                if (!Directory.Exists(str5))
                {
                    Directory.CreateDirectory(str5);
                }
                string str6 = "";
                StreamReader reader = new StreamReader("./Template/ConfigTemplate.h", Encoding.GetEncoding("GBK"));
                str6 = reader.ReadToEnd();
                reader.Close();
                string newValue = "";
                string str8 = "";
                foreach (ConfigFile file in m.configFiles)
                {
                    newValue = newValue + "\t" + file.CfgName + "Table::Instance().Load();\r\n";
                    str8 = str8 + "#include \"" + file.CfgName + "Cfg.h\"\r\n";
                    string str9 = str6;
                    string fieldName = "";
                    string fieldType = "";
                    string defaultValue = "";
                    string str13 = "";
                    string str14 = "";
                    string str15 = "";
                    string str16 = "";
                    string jsonField = "";
                    int num = 0;
                    foreach (ConfigFile.ConfigField field in file.fieldItem)
                    {
                        if (field.IsPrimary)
                        {
                            fieldName = field.FieldName;
                            fieldType = field.FieldType;
                            defaultValue = field.DefaultValue;
                            break;
                        }
                    }
                    string str17 = "";
                    if (fieldType == "int")
                    {
                        str17 = fieldName + " = " + defaultValue + ";";
                    }
                    int num2 = 0;
                    bool flag = false;
                    foreach (ConfigFile.ConfigField field2 in file.fieldItem)
                    {
                        if (!field2.IsDescribe)
                        {
                            num++;
                            flag = true;

                            string tempFieldType = field2.FieldType;
                            if (tempFieldType == "li")
                            {
                                tempFieldType = "vector<int>";
                            }
                            if (tempFieldType == "ls")
                            {
                                tempFieldType = "vector<string>";
                            }
                            if (tempFieldType == "lf")
                            {
                                tempFieldType = "vector<float>";
                            }
                            string str18 = "\t" + tempFieldType + " " + field2.FieldName + ";";
                            int num3 = 30 - str18.Length;
                            while (num3-- > 0)
                            {
                                str18 = str18 + " ";
                            }
                            string str19 = "";
                            if (field2.Comment != null)
                            {
                                str19 = field2.Comment.Replace("\r\n", " ");
                            }
                            string str49 = str18;
                            str18 = str49 + "\t//" + field2.CNName + "\t" + str19.Replace("\n", " ") + "\r\n";
                            str13 = str13 + str18;
                            obj2 = str14;
                            str14 = string.Concat(new object[] { obj2, "\t\tif(vecLine[", num2, "]!=\"", field2.FieldName, "\"){printf_message(\"", file.CfgName, ".csv中字段[", field2.FieldName, "]位置不对应 \");assert(false); return false; }\r\n" });
                            if (field2.FieldType == "int")
                            {
                                obj2 = str16;
                                str16 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=(int)atoi(vecLine[", num2, "].c_str());\r\n" });
                                str15 = str15 + "\t\t\tpContent = ReadBinInt(member." + field2.FieldName + ",pContent);\r\n";
                                jsonField += string.Concat(new object[] {"\t\t\tmember.", field2.FieldName, "=p.get<int>(\"", field2.FieldName, "\");\r\n" });
                            }
                            else if (field2.FieldType == "float")
                            {
                                obj2 = str16;
                                str16 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=(float)atof(vecLine[", num2, "].c_str());\r\n" });
                                str15 = str15 + "\t\t\tpContent = ReadBinInt(member." + field2.FieldName + ",pContent);\r\n";
                                jsonField += string.Concat(new object[] { "\t\t\tmember.", field2.FieldName, "=p.get<float>(\"", field2.FieldName, "\");\r\n" });
                            }
                            else if (field2.FieldType == "li")
                            {
                                jsonField += string.Concat(new object[] { "\t\t\tboost::property_tree::ptree sms_array_child" + field2.FieldName + " = p.get_child(\"" + field2.FieldName + "\");\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\tfor (BOOST_AUTO(pos, sms_array_child" + field2.FieldName + ".begin()); pos != sms_array_child" + field2.FieldName + ".end(); ++pos)\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\t{\r\n" });
                                
                                jsonField += string.Concat(new object[] { "\t\t\t\tint n = pos->second.get_value<int>(); \r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t\tmember.", field2.FieldName, ".push_back(n);\r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t}\r\n" });
                            }
                            else if (field2.FieldType == "ls")
                            {
                                jsonField += string.Concat(new object[] { "\t\t\tboost::property_tree::ptree sms_array_child" + field2.FieldName + " = p.get_child(\"" + field2.FieldName + "\");\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\tfor (BOOST_AUTO(pos, sms_array_child" + field2.FieldName + ".begin()); pos != sms_array_child" + field2.FieldName + ".end(); ++pos)\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\t{\r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t\tstring n = pos->second.get_value<string>(); \r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t\tmember.", field2.FieldName, ".push_back(n);\r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t}\r\n" });
                            }
                            else if (field2.FieldType == "lf")
                            {
                                jsonField += string.Concat(new object[] { "\t\t\tboost::property_tree::ptree sms_array_child" + field2.FieldName + " = p.get_child(\"" + field2.FieldName + "\");\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\tfor (BOOST_AUTO(pos, sms_array_child" + field2.FieldName + ".begin()); pos != sms_array_child" + field2.FieldName + ".end(); ++pos)\r\n" });
                                jsonField += string.Concat(new object[] { "\t\t\t{\r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t\tfloat n = pos->second.get_value<float>(); \r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t\tmember.", field2.FieldName, ".push_back(n);\r\n" });

                                jsonField += string.Concat(new object[] { "\t\t\t}\r\n" });
                            }
                            else
                            {
                                obj2 = str16;
                                str16 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=vecLine[", num2, "];\r\n" });
                                str15 = str15 + "\t\t\tpContent = ReadBinStr(member." + field2.FieldName + ",pContent);\r\n";
                                jsonField += string.Concat(new object[] { "\t\t\tmember.", field2.FieldName, "=p.get<string>(\"", field2.FieldName, "\");\r\n" });
                            }
                            num2++;
                        }
                    }
                    str9 = str9.Replace("$TEMPLATE$", file.CfgName.ToUpper()).Replace("$CNName$", file.CNName)
                        .Replace("$Template$", file.CfgName)
                        .Replace("$PrimaryKey$", fieldName)
                        .Replace("$PrimaryType$", fieldType)
                        .Replace("$InitPrimaryField$", str17)
                        .Replace("$FieldDefine$", str13)
                        .Replace("$ColCount$", num.ToString())
                        .Replace("$CheckColName$", str14)
                        .Replace("$ReadBinColValue$", str15)
                        .Replace("$ReadCsvColValue$", str16)
                        .Replace("$ReadJsonValue$", jsonField);
                    if (flag)
                    {
                        var utf8WithoutBom = new System.Text.UTF8Encoding(false);
                        StreamWriter writer = new StreamWriter(str5 + file.CfgName + "Cfg.h", false, utf8WithoutBom);
                        writer.Write(str9);
                        writer.Close();
                    }
                }
                ArrayList list = new ArrayList {
                    "./Template/ModuleTemplate.h",
                    "./Template/ModuleTemplate.cpp",
                    "./Template/CliRpcTemplateImp.cpp",
                    "./Template/RpcWraperTemplate.h",
                    "./Template/SyncDataTemplate.h",
                    "./Template/SyncDataTemplate.cpp",
                    "./Template/SyncWraperTemplate.h",
                    "./Template/PubWraperClass.h",
                    "./Template/PubWraperClass.h",
                    "./Template/DBCacheTemplate.h",
                    "./Template/DBCacheTemplate.cpp",
                    "./Template/SyncWraperTemplate.h",
                    "./Template/ModuleAllNames.h"
                };
                ArrayList list2 = new ArrayList {
                    path + m.ModuleName + "Module.h",
                    path + m.ModuleName + "Module.cpp",
                    path + m.ModuleName + "RpcImp.cpp",
                    path + m.ModuleName + "RpcWraper.h",
                    string.Concat(new object[] {
                        path,
                        m.ModuleName,
                        "V",
                        m.SyncDataVersion,
                        "Data.h"
                    }),
                    string.Concat(new object[] {
                        path,
                        m.ModuleName,
                        "V",
                        m.SyncDataVersion,
                        "Data.cpp"
                    }),
                    string.Concat(new object[] {
                        path,
                        m.ModuleName,
                        "V",
                        m.SyncDataVersion,
                        "DataWraper.h"
                    }),
                    str4 + "PublicStructWraper.h",
                    str3 + "PublicStructWraper.h",
                    str2 + m.ModuleName + "DBCache.h",
                    str2 + m.ModuleName + "DBCache.cpp",
                    string.Concat(new object[] {
                        str2,
                        m.ModuleName,
                        "V",
                        m.SyncDataVersion,
                        "DataWraper.h"
                    })
                };
                ArrayList list3 = new ArrayList();
                for (int i = 0; i < list.Count; i++)
                {
                    try
                    {
                        StreamReader reader2 = null;
                        if (((string)list[i]).ToLower().IndexOf("vcxproj") > -1)
                        {
                            reader2 = new StreamReader((string)list[i], Encoding.UTF8);
                        }
                        else
                        {
                            reader2 = new StreamReader((string)list[i], Encoding.GetEncoding("GBK"));
                        }
                        string str20 = reader2.ReadToEnd();
                        list3.Add(str20);
                        reader2.Close();
                    }
                    catch (DirectoryNotFoundException)
                    {
                        return;
                    }
                }
                label1.Text = "正在生成文件: " + path + m.ModuleName + ".h&&cpp";
                label1.Refresh();
                string operationDeclare = "";
                string operationImpl = "";
                string operationImplement = "";
                string msgId = "";
                string defMessageIdT = "";
                string str26 = m.SyncDataVersion.ToString();
                string syncIds = "";
                string strWraper = "";
                string str29 = "";
                string syncOpDefine = "";
                string syncOpImp = "";
                string str32 = "";
                string sendAllFields = "";
                string str34 = "";
                string str35 = "";
                string str36 = "";
                string str37 = "";
                string str38 = "";
                string strSyncDataSetWraper = "";
                string str40 = "";
                string str41 = "SAVE_ITEM_DATA";
                string structName = "";
                string dBCacheField = "";
                string str44 = "false";
                string str45 = "";
                string BindCalc = "";
                string RefreshField = "";
                string GetField = "";
                bool flag2 = false;
                int num5 = 0;
                int num6 = 0;
                string str46 = "\tMODULE_ID_" + m.ModuleName.ToUpper();
                int num7 = 0x2e - str46.Length;
                while (num7-- > 0)
                {
                    str46 = str46 + " ";
                }
                obj2 = str46;
                str46 = string.Concat(new object[] { obj2, "= ", m.StartIdNum, ",\t//", m.CNName, "模块ID\r\n" });
                msgId = msgId + str46;
                str46 = "\tMODULE_NAMES_" + m.ModuleName.ToUpper();
                num7 = 0x2e - str46.Length;
                while (num7-- > 0)
                {
                    str46 = str46 + " ";
                }
                obj2 = str46;
                str46 = string.Concat(new object[] { obj2, "= ", m.StartIdNum, ",\t//", m.CNName, "模块ID\r\n" });
                obj2 = ModuleAllName;
                ModuleAllName = string.Concat(new object[] { obj2, "\tModuleValue[", m.StartIdNum, "]=\"", m.CNName, "\";\n" });
                foreach (DataStruct struct2 in XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.RpcProto))
                {
                    GenClassWraperCode(m, struct2, ref str29);
                }
                foreach (DataStruct struct3 in XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.SyncProto))
                {
                    GenClassWraperCode(m, struct3, ref strWraper);
                }
                foreach (Module.OperaterItem item in m.operateItem)
                {
                    Console.WriteLine(ModuleAllName);
                    GenRpcCode(m, item, ref msgId, ref ModuleAllName, ref operationDeclare, ref operationImpl, ref operationImplement, ref num5, ref num6, ref defMessageIdT);
                }
                ArrayList list6 = XMLSerializer.OrderDataStruct(m.moduleDataStruct);
                foreach (DataStruct struct4 in list6)
                {
                    if ((((struct4.DataType != DataStruct.SyncType.CacheData) && (struct4.DataType != DataStruct.SyncType.ModuleData)) && ((struct4.DataType != DataStruct.SyncType.UserData) && (struct4.StructName.ToLower().IndexOf("rpc") >= 0))) && (struct4.ProtoType == DataStruct.protoTypeE.RpcProto))
                    {
                        GenClassWraperCode(m, struct4, ref str29);
                    }
                }
                foreach (DataStruct struct5 in list6)
                {
                    if (((struct5.DataType == DataStruct.SyncType.CacheData) || (struct5.DataType == DataStruct.SyncType.ModuleData)) || (struct5.DataType == DataStruct.SyncType.UserData))
                    {
                        flag2 = true;
                        str44 = struct5.SaveToDB.ToString();
                        structName = struct5.StructName;
                        if (struct5.DataType == DataStruct.SyncType.CacheData)
                        {
                            str41 = "SAVE_CACHE_DATA";
                        }
                        if (struct5.DataType == DataStruct.SyncType.ModuleData)
                        {
                            str41 = "SAVE_MODULE_DATA";
                        }
                        if (struct5.DataType == DataStruct.SyncType.UserData)
                        {
                            str41 = "SAVE_USER_DATA";
                        }
                        str40 = string.Concat(new object[] { "#include \"", m.ModuleName, "V", m.SyncDataVersion, "Data.h\"\r\n#include \"", m.ModuleName, "V", m.SyncDataVersion, "DataWraper.h\"\r\n" });
                        str45 = string.Concat(new object[] { "#include \"", m.ModuleName, "V", m.SyncDataVersion, "DataWraper.h\"\r\n" });
                        str32 = struct5.StructName;
                        
                        GenSyncDataCode(m, struct5, ref syncIds, ref syncOpDefine, ref syncOpImp, ref sendAllFields, ref dBCacheField,ref BindCalc,ref RefreshField, ref GetField);
                        GenClassWraperCode(m, struct5, ref strWraper);
                        str38 = string.Concat(new object[] { m.ModuleName, struct5.StructName, "WraperV", m.SyncDataVersion, " m_syncData", struct5.StructName, ";" });
                        strSyncDataSetWraper = "SetDataWraper( &m_syncData" + struct5.StructName + " );";
                    }
                }
                foreach (DataStruct struct6 in XMLSerializer.OrderDataStruct(DataStructConverter.CommDataStruct))
                {
                    GenClassWraperCode(null, struct6, ref str36);
                }
                for (int j = 0; j < list3.Count; j++)
                {
                    string str47 = (string)list3[j];
                    str47 = str47.Replace("$Date$", DateTime.Now.ToShortDateString().ToString())
                        .Replace("$LoadConfig$", newValue)
                        .Replace("$Template$", m.ModuleName)
                        .Replace("$ModCName$", m.CNName)
                        .Replace("$TEMPLATE$", m.ModuleName.ToUpper())
                        .Replace("$DeclareMsgID$", msgId)
                        .Replace("$DefMessageIdT$", defMessageIdT)
                        .Replace("$CliOperationDeclare$", operationDeclare)
                        .Replace("$CliOperationImpl$", operationImpl)
                        .Replace("$CliOperationImplement$", operationImplement)
                        .Replace("$SyncDataVersion$", str26)
                        .Replace("$syncIds$", syncIds)
                        .Replace("$SyncClassWraper$", strWraper)
                        .Replace("$RpcClassWraper$", str29)
                        .Replace("$SyncOpDefine$", syncOpDefine)
                        .Replace("$SyncOpImp$", syncOpImp)
                        .Replace("$SyncDataName$", str32)
                        .Replace("$SendAllFields$", sendAllFields)
                        .Replace("$rpcFieldSizeMacro$", str35)
                        .Replace("$syncFieldSizeMacro$", str34)
                        .Replace("$PubFieldSizeMacro$", str37)
                        .Replace("$PubClassWraper$", str36)
                        .Replace("$SyncDataDefine$", str38)
                        .Replace("$SyncDataSetWraper$", strSyncDataSetWraper)
                        .Replace("$IncludeSyncDataHeader$", str40)
                        .Replace("$HeaderConfig$", str8)
                        .Replace("$DataSaveType$", str41)
                        .Replace("$DSName$", structName)
                        .Replace("$DBCacheField$", dBCacheField)
                        .Replace("$SaveToDB$", str44.ToLower())
                        .Replace("$ModId$", m.StartIdNum.ToString())
                        .Replace("$DBCacheSyncDataHeader$", str45)
                        .Replace("$RefreshField$", RefreshField)
                        .Replace("$BindCalc$",BindCalc)
                        .Replace("$GetField$",GetField)
                        ;
                    list3[j] = str47;
                }
                for (int k = 0; k < list2.Count; k++)
                {
                    string str48 = (string)list2[k];
                    if ((((str48.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data" })) <= -1) || flag2) && ((str48.IndexOf(m.ModuleName + "DBCache") <= -1) || flag2)) && ((str48.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "DataWraper" })) <= -1) || flag2))
                    {
                        StreamWriter writer2 = null;
                        var utf8WithoutBom = new System.Text.UTF8Encoding(false);
                        writer2 = new StreamWriter((string)list2[k], false, utf8WithoutBom);
                        writer2.Write((string)list3[k]);
                        writer2.Close();
                    }
                }
            }
        }
    }
}

