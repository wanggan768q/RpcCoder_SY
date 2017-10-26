namespace Editor
{
    using System;
    using System.Runtime.CompilerServices;

    internal class Save
    {
        public string CNName { get; set; }

        public string Name { get; set; }

        public Save Next { get; set; }

        public bool Repet { get; set; }

        public string Type { get; set; }

        public string Value { get; set; }
    }
}

