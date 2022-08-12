using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ListSpecialFolder
{
    class Program
    {
        static void Main(string[] args)
        {
            foreach ( var enumValue in Enum.GetValues( typeof( Environment.SpecialFolder )))
            {
                var folder = ( Environment.SpecialFolder )enumValue;
                var folderPath = Environment.GetFolderPath(folder );
                Console.WriteLine( "Folder <{0}> = <{1}>", folder, folderPath );
            }
        }
    }
}
