using System;

namespace JohnnyProgress
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] progressDays = new int[] { 3, 4, 1, 2 };

            int totalProgress = Progress.GetProgressCount(progressDays);

            Console.WriteLine($"Total Progress is: [{totalProgress}]");
        }
    }

    public static class Progress
    {
        public static int GetProgressCount(int[] progressDays)
        {
            int progressCount = 0;
            for (int i=1; i < progressDays.Length; i++)
            {
                if (progressDays[i] > progressDays[i - 1])
                    progressCount++;

            }

            return progressCount;
        }

    }
}
