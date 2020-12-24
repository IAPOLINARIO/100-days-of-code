using System;
using System.Collections.Generic;

namespace Barbecue
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputSkewers = { "--oooo-ooo--", "--xx--x--xx--", "--o---o--oo--", "--xx--x--ox--", "--xx--x--ox--" };

            var assessment = Barbecue.GetAssesment(inputSkewers);

            Console.WriteLine($"[{assessment["Vegetarians"]}, {assessment["NonVegetarians"]}]");            
        }
    }

    public static class Barbecue
    {
        public static Dictionary<string, int> GetAssesment(string[] skewers)
        {
            int vegetarians = 0;
            int nonVegetarians = 0;

            foreach (string skewer in skewers)
            {
                if (IsVegetarian(skewer))
                {
                    vegetarians++;
                }
                else
                {
                    nonVegetarians++;
                }
            }

            return new Dictionary<string, int>()
            {
                { "Vegetarians", vegetarians },
                { "NonVegetarians", nonVegetarians }
            };
        }

        private static bool IsVegetarian(string skewer)
        {
            return skewer.Contains("-o") && !skewer.Contains("x");
        }        
    }
}
