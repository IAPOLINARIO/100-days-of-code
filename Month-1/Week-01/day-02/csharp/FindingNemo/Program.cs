using System;

namespace FindingNemo
{
    class Program
    {
        static void Main(string[] args)
        {
            string baseString = "Nemo is here";

            int indexNemo = Indexer.GetIndexNemo(baseString);

            if (indexNemo != 0)
            {
                Console.WriteLine($"I found Nemo at {indexNemo}!");
            }
            else
            {
                Console.WriteLine("I can't find Nemo :(");
            }

            Console.ReadLine();
        }
    }
    public static class Indexer
    {
        public static int GetIndexNemo(string baseString)
        {
            string[] words = baseString.Split(' ');

            for (int i = 0; i < words.Length; i++)
            {
                if (words[i] == "Nemo")
                {
                    return (i + 1);
                }
            }
            // 0 means not found
            return 0;
        }
    }
}
