using System;
using System.Collections.Generic;
using System.Linq;

namespace SockPairs
{
    class Program
    {
        static void Main(string[] args)
        {
            string sockets = "CABBACCC";

            int socketPairs = Sockets.FindPairs(sockets);

            Console.WriteLine($"Found [{socketPairs}] pairs");
        }
    }

    public static class Sockets
    {
        public static int FindPairs(string sockets)
        {
            int socketPairs = 0;
            var uniqueSocketList = new HashSet<char>(sockets);

            foreach (char socket in uniqueSocketList)
            {
                socketPairs += CountPairs(socket, sockets);
            }
            return socketPairs / 2;
        }

        private static int CountPairs(char socket, string sockets)
        {
            return sockets.Count(item => item == socket);
        }
    }
}
