namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Drawing.Design;

    public class ConfigFile
    {
        public string CfgName = "";
        private string cnName = "";
        private string comment = "";
        public static Dictionary<string, ConfigFile> ConfigFileDic = new Dictionary<string, ConfigFile>();
        private string configName = "";
        public ArrayList fieldItem = new ArrayList();
        public Module module;

        public bool ContainField(string value)
        {
            foreach (ConfigField field in this.fieldItem)
            {
                if (value == field.FieldName)
                {
                    return true;
                }
            }
            return false;
        }

        public static bool ContainsKey(string name) => 
            ConfigFileDic.ContainsKey(name);

        public static ConfigFile GetConfigFile(string name)
        {
            ConfigFile file = null;
            ConfigFileDic.TryGetValue(name, out file);
            return file;
        }

        public string getModuleName()
        {
            if (this.module != null)
            {
                return this.module.ModuleName;
            }
            return "";
        }

        public static bool IsBaseType(string name)
        {
            if ((name != "int") && (name != "string"))
            {
                return false;
            }
            return true;
        }

        public void Remove(ConfigField fd)
        {
            this.fieldItem.Remove(fd);
        }

        public void toSetConfigName(string value)
        {
            this.configName = value;
            this.CfgName = value;
        }

        public override string ToString() => 
            this.configName;

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

        public string ConfigName
        {
            get => 
                this.configName;
            set
            {
            }
        }

        public class ConfigField
        {
            private string checkIndex = "";
            private string cnName = "";
            private string comment = "";
            public ConfigFile configFile;
            private string defaultValue = "-1";
            private string fieldName = "";
            private string fieldType = "int";
            private bool isDes;
            private bool isPri;
            private bool isSvr;
            private int maxValue = 0x989680;
            private int minValue = -1;
            private string valueSet = "";

            public void toSetCheckIndex(string value)
            {
                this.checkIndex = value;
            }

            public void toSetCnName(string value)
            {
                this.cnName = value;
            }

            public void toSetComment(string value)
            {
                this.comment = value;
            }

            public void toSetDefaultValue(string value)
            {
                this.defaultValue = value;
            }

            public void toSetFieldName(string value)
            {
                this.fieldName = value;
            }

            public void toSetFieldType(string value)
            {
                this.fieldType = value;
            }

            public void toSetIsDes(bool value)
            {
                this.isDes = value;
            }

            public void toSetIsPri(bool value)
            {
                this.isPri = value;
            }

            public void toSetIsSvr(bool value)
            {
                this.isSvr = value;
            }

            public void toSetMaxValue(int value)
            {
                this.maxValue = value;
            }

            public void toSetMinValue(int value)
            {
                this.minValue = value;
            }

            public void toSetValueSet(string value)
            {
                this.valueSet = value;
            }

            public override string ToString() => 
                this.fieldName;

            public string CheckIndex
            {
                get => 
                    this.checkIndex;
                set
                {
                }
            }

            public string CNName
            {
                get => 
                    this.cnName;
                set
                {
                }
            }

            [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
            public string Comment
            {
                get => 
                    this.comment;
                set
                {
                }
            }

            public string DefaultValue
            {
                get => 
                    this.defaultValue;
                set
                {
                }
            }

            public string FieldName
            {
                get => 
                    this.fieldName;
                set
                {
                }
            }

            public string FieldType
            {
                get => 
                    this.fieldType;
                set
                {
                }
            }

            public bool IsDescribe
            {
                get => 
                    this.isDes;
                set
                {
                }
            }

            public bool IsPrimary
            {
                get => 
                    this.isPri;
                set
                {
                }
            }

            public bool IsServer
            {
                get => 
                    this.isSvr;
                set
                {
                }
            }

            public int MaxValue
            {
                get => 
                    this.maxValue;
                set
                {
                }
            }

            public int MinValue
            {
                get => 
                    this.minValue;
                set
                {
                }
            }

            public string ValueSet
            {
                get => 
                    this.valueSet;
                set
                {
                }
            }
        }
    }
}

