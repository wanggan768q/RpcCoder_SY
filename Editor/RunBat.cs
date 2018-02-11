using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.IO;

namespace Editor
{
    class RunBat
    {


        public static void Run(string batFileName)
        {
            string root = Directory.GetCurrentDirectory();
            Process proc = null;
            try
            {
                proc = new Process();
                proc.StartInfo.FileName = root + @"/" + batFileName;
                proc.StartInfo.CreateNoWindow = true;
                proc.Start();
                proc.WaitForExit();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Occurred :{0},{1}", ex.Message, ex.StackTrace.ToString());
            }
        }
    }


}
