namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Drawing.Design;
    using System.Windows.Forms;

    public class DataStruct
    {
        private string cnName = "";
        private string comment = "";
        public static Dictionary<string, DataStruct> DataStructDic = new Dictionary<string, DataStruct>();
        private SyncType dataType = SyncType.ItemData;
        public List<FieldDescriptor> fieldItem = new List<FieldDescriptor>();
        public int GenOrder;
        private int maxFieldId;
        public Module module;
        public protoTypeE ProtoType;
        public bool saveToDB;
        public TreeNode selfTreeNode;
        private string structName = "";
        public Module.OperaterItem.SubOperaterItem SubOperate;
        public bool syncToClient;

        public static bool ContainsKey(string name)
        {
            foreach (DataStruct struct2 in DataStructConverter.CommDataStruct)
            {
                if (struct2.StructName == name)
                {
                    return true;
                }
            }
            return IsBaseType(name);
        }

        public SyncType ConvertDataType(string t)
        {
            switch (t)
            {
                case "RPCData":
                    return SyncType.RPCData;

                case "ItemData":
                    return SyncType.ItemData;

                case "ModuleData":
                    return SyncType.ModuleData;

                case "UserData":
                    return SyncType.UserData;

                case "CacheData":
                    return SyncType.CacheData;
            }
            return SyncType.ItemData;
        }

        public static DataStruct GetDataStruct(string name, string module)
        {
            DataStruct struct2 = null;
            if (!DataStructDic.TryGetValue(name, out struct2))
            {
                DataStructDic.TryGetValue(module + "_" + name, out struct2);
            }
            return struct2;
        }

        public string getFullName() => 
            (this.getPrefix() + this.structName);

        public int GetMaxFieldId()
        {
            int num = this.maxFieldId + 1;
            foreach (FieldDescriptor descriptor in this.fieldItem)
            {
                if (descriptor.FieldId >= num)
                {
                    num = descriptor.FieldId + 1;
                }
            }
            this.maxFieldId = num;
            return this.maxFieldId;
        }

        public string getModuleName()
        {
            if (this.module != null)
            {
                return this.module.ModuleName;
            }
            return "";
        }

        public string getPrefix()
        {
            if (this.module != null)
            {
                return this.module.ModuleName;
            }
            return "";
        }

        public string getProtoTypeName(protoTypeE t)
        {
            switch (t)
            {
                case protoTypeE.UnknowProto:
                    return "UnknowProto";

                case protoTypeE.CommProto:
                    return "CommProto";

                case protoTypeE.RpcProto:
                    return "RpcProto";

                case protoTypeE.SyncProto:
                    return "SyncProto";
            }
            return "UnknowProto";
        }

        public protoTypeE getProtoTypeValue(string t)
        {
            if (t != "UnknowProto")
            {
                if (t == "CommProto")
                {
                    return protoTypeE.CommProto;
                }
                if (t == "RpcProto")
                {
                    return protoTypeE.RpcProto;
                }
                if (t == "SyncProto")
                {
                    return protoTypeE.SyncProto;
                }
            }
            return protoTypeE.UnknowProto;
        }

        public static bool IsBaseType(string name)
        {
            if ((((name != "bool") && (name != "float")) && ((name != "sint32") && (name != "int32") && (name != "sint64") && (name != "uint64") && (name != "int64"))) && ((name != "string") && (name != "bytes")))
            {
                return false;
            }
            return true;
        }

        public void Remove(FieldDescriptor fd)
        {
            this.fieldItem.Remove(fd);
        }

        public void ToSetDataType(SyncType t)
        {
            this.dataType = t;
        }

        public override string ToString() => 
            this.structName;

        public string CNName
        {
            get => 
                this.cnName;
            set
            {
                this.cnName = value;
            }
        }

        [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
        public string Comment
        {
            get => 
                this.comment;
            set
            {
                this.comment = value;
            }
        }

        public SyncType DataType
        {
            get => 
                this.dataType;
            set
            {
                if (((this.selfTreeNode != null) && (this.selfTreeNode.Parent.Name != "rpcProto")) && (value != SyncType.RPCData))
                {
                    bool flag = false;
                    foreach (DataStruct struct2 in this.module.moduleDataStruct)
                    {
                        if ((((struct2.dataType == SyncType.UserData) || (struct2.dataType == SyncType.CacheData)) || (struct2.dataType == SyncType.ModuleData)) && (struct2.structName != this.structName))
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        MessageBox.Show("More than one struct define as [UserData/CacheData/ModuleData/ModuleCacheData]");
                    }
                    else
                    {
                        this.dataType = value;
                        if (((this.dataType != SyncType.UserData) && (this.dataType != SyncType.CacheData)) && (this.dataType != SyncType.ModuleData))
                        {
                            this.saveToDB = false;
                        }
                        else
                        {
                            this.saveToDB = true;
                        }
                        if (this.dataType != SyncType.CacheData)
                        {
                            this.SyncToClient = true;
                        }
                    }
                }
            }
        }

        public int MaxFieldId
        {
            get => 
                this.maxFieldId;
            set
            {
                this.maxFieldId = value;
            }
        }

        public bool SaveToDB
        {
            get => 
                this.saveToDB;
            set
            {
                if (((this.selfTreeNode != null) && (this.selfTreeNode.Parent.Name != "rpcProto")) && (((this.dataType == SyncType.UserData) || (this.dataType == SyncType.CacheData)) || (this.dataType == SyncType.ModuleData)))
                {
                    this.saveToDB = value;
                }
            }
        }

        public string StructName
        {
            get => 
                this.structName;
            set
            {
                if (value == "")
                {
                    MessageBox.Show("DataStruct Name is empty!!!");
                }
                else
                {
                    foreach (DataStruct struct2 in DataStructConverter.CommDataStruct)
                    {
                        if (struct2.StructName == value)
                        {
                            MessageBox.Show("DataStruct :" + value + " Already Exist!!!");
                            return;
                        }
                    }
                    if ((this.structName != value) && DataStructDic.ContainsKey(this.getPrefix() + value))
                    {
                        MessageBox.Show("DataStruct :" + value + " Already Exist!!!");
                    }
                    else
                    {
                        DataStruct struct3 = null;
                        bool flag = DataStructDic.TryGetValue(this.getFullName(), out struct3);
                        if (flag)
                        {
                            DataStructDic.Remove(this.getFullName());
                        }
                        this.structName = value;
                        if (flag)
                        {
                            DataStructDic.Add(this.getFullName(), struct3);
                        }
                    }
                }
            }
        }

        public bool SyncToClient
        {
            get => 
                this.syncToClient;
            set
            {
                if (this.ProtoType == protoTypeE.SyncProto)
                {
                    switch (this.dataType)
                    {
                        case SyncType.RPCData:
                        case SyncType.ItemData:
                        case SyncType.ModuleData:
                            this.syncToClient = false;
                            return;

                        case SyncType.CacheData:
                            this.syncToClient = value;
                            return;

                        case SyncType.UserData:
                            this.syncToClient = true;
                            return;
                    }
                }
            }
        }

        public class FieldDescriptor : ICloneable
        {
            private string cnName = "";
            private string comment = "";
            public DataStruct dataStruct;
            public string defaultValue = "-1";
            public int FieldId;
            private string fieldName = "";
            //private string fieldType = "sint32";
            private string fieldType = "int32";
            private int maxValue = 0x989680;
            private int minValue = -1;
            private PreDefineType preDefine;
            private string valueSet = "";

            public object Clone() => 
                new DataStruct.FieldDescriptor { 
                    fieldType = this.fieldType,
                    fieldName = this.fieldName,
                    cnName = this.cnName,
                    defaultValue = this.defaultValue,
                    comment = this.comment,
                    preDefine = this.preDefine,
                    dataStruct = this.dataStruct,
                    maxValue = this.maxValue,
                    minValue = this.minValue
                };

            public int GetTypeEnum()
            {
                switch (this.FieldType)
                {
                    case "bool":
                        return 1;

                    case "float":
                        return 1;
                    case "int32":
                        return 1;
                    case "sint32":
                        return 1;

                    case "sint64":
                        return 1;
                    case "uint64":
                        return 1;
                    case "int64":
                        return 1;

                    case "string":
                        return 2;

                    case "bytes":
                        return 2;
                }
                return 3;
            }

            public void Remove()
            {
                this.dataStruct.Remove(this);
            }

            public string ToGetCSFieldType()
            {
                switch (this.FieldType)
                {
                    case "bool":
                        return "bool";

                    case "float":
                        return "float";

                    case "string":
                        return "string";

                    case "sint32":
                        return "int";
                    case "int32":
                        return "int";

                    case "sint64":
                        return "Int64";
                    case "uint64":
                        return "UInt64";
                    case "int64":
                        return "Int64";

                    case "bytes":
                        return "byte[]";
                }
                DataStruct ds = null;
                if (DataStructConverter.ContainsKey(this.FieldType, ref ds))
                {
                    return (this.FieldType + "Wraper");
                }
                if (this.dataStruct.selfTreeNode.Parent.Name == "syncData")
                {
                    return string.Concat(new object[] { this.dataStruct.module.ModuleName, this.FieldType, "WraperV", this.dataStruct.module.SyncDataVersion });
                }
                return (this.dataStruct.module.ModuleName + this.FieldType + "Wraper");
            }

            public string ToGetFieldType()
            {
                switch (this.FieldType)
                {
                    case "bool":
                        return "bool";

                    case "float":
                        return "float";

                    case "string":
                        return "string";

                    case "int32":
                        return "INT32";
                    case "sint32":
                        return "INT32";

                    case "sint64":
                        return "INT64";
                    case "uint64":
                        return "uint64_t";
                    case "int64":
                        return "int64_t";

                    case "bytes":
                        return "string";
                }
                DataStruct ds = null;
                if (DataStructConverter.ContainsKey(this.FieldType, ref ds))
                {
                    return (this.FieldType + "Wraper");
                }
                if (this.dataStruct.selfTreeNode.Parent.Name == "syncData")
                {
                    return string.Concat(new object[] { this.dataStruct.module.ModuleName, this.FieldType, "WraperV", this.dataStruct.module.SyncDataVersion });
                }
                return (this.dataStruct.module.ModuleName + this.FieldType + "Wraper");
            }

            public override string ToString() => 
                this.fieldName;

            public string CNName
            {
                get => 
                    this.cnName;
                set
                {
                    this.cnName = value;
                }
            }

            [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
            public string Comment
            {
                get => 
                    this.comment;
                set
                {
                    this.comment = value;
                }
            }

            public string DefaultValue
            {
                get => 
                    this.defaultValue;
                set
                {
                    if (this.FieldType == "bool")
                    {
                        if (value == "true")
                        {
                            this.defaultValue = "true";
                        }
                        else
                        {
                            this.defaultValue = "false";
                        }
                    }
                    else
                    {
                        this.defaultValue = value;
                    }
                }
            }

            public string FieldName
            {
                get => 
                    this.fieldName;
                set
                {
                    if (value == "")
                    {
                        MessageBox.Show("FieldName Name is empty!!!");
                    }
                    else
                    {
                        value = value.Substring(0, 1).ToUpper() + value.Substring(1);
                        foreach (DataStruct.FieldDescriptor descriptor in this.dataStruct.fieldItem)
                        {
                            if (descriptor.FieldName == value)
                            {
                                MessageBox.Show("FieldName :" + value + " Already Exist!!!");
                                return;
                            }
                        }
                        this.fieldName = value;
                    }
                }
            }

            [TypeConverter(typeof(DataStructConverter))]
            public string FieldType
            {
                get => 
                    this.fieldType;
                set
                {
                    if (this.CNName.Length == 0)
                    {
                        MessageBox.Show("[CNName] cant be empty!!");
                    }
                    else if ((this.FieldName.Length >= 8) && (this.FieldName.Substring(0, 8) == "NewField"))
                    {
                        MessageBox.Show("[Name] cant head of[NewField]!!");
                    }
                    else
                    {
                        if (value == "sint32")
                        {
                            value = "int32";
                        }
                        if (value == "sint64")
                        {
                            value = "int64";
                            long v = -1;
                            if (!Int64.TryParse(this.DefaultValue, out v))
                            {
                                this.DefaultValue = v + "";
                            }
                        }
                        this.fieldType = value;
                        if (value == "bool")
                        {
                            if ((this.DefaultValue != "true") && (this.DefaultValue != "false"))
                            {
                                this.DefaultValue = "false";
                            }
                        }
                        else if (((value == "sint32") || (value == "int32") || (value == "float")) || (value == "sint64") || (value == "int64"))
                        {
                            this.DefaultValue = "-1";
                        }
                        else if (value == "uint64" || value == "int64")
                        {
                            UInt64 t = 0;
                            if (!UInt64.TryParse(this.DefaultValue,out t))
                            {
                                this.DefaultValue = "0";
                            }
                        }
                        else
                        {
                            this.DefaultValue = "";
                            this.MinValue = 6;
                            this.MaxValue = 0x80;
                            this.valueSet = "";
                        }
                    }
                }
            }

            public bool IsBytesField =>
                (this.FieldType == "bytes");

            public int MaxValue
            {
                get => 
                    this.maxValue;
                set
                {
                    this.maxValue = value;
                }
            }

            public int MinValue
            {
                get => 
                    this.minValue;
                set
                {
                    this.minValue = value;
                }
            }

            public PreDefineType PreDefine
            {
                get => 
                    this.preDefine;
                set
                {
                    if (this.CNName.Length == 0)
                    {
                        MessageBox.Show("[CNName] cant be empty!!");
                    }
                    else if ((this.FieldName.Length >= 8) && (this.FieldName.Substring(0, 8) == "NewField"))
                    {
                        MessageBox.Show("[Name] cant head of[NewField]!!");
                    }
                    else
                    {
                        this.preDefine = value;
                    }
                }
            }

            public string ValueSet
            {
                get => 
                    this.valueSet;
                set
                {
                    this.valueSet = value;
                }
            }

            public enum PreDefineType
            {
                optional,
                repeated
            }
        }

        public enum protoTypeE
        {
            UnknowProto,
            CommProto,
            RpcProto,
            SyncProto
        }

        public enum SyncType
        {
            RPCData,
            ItemData,
            ModuleData,
            CacheData,
            UserData
        }
    }
}

