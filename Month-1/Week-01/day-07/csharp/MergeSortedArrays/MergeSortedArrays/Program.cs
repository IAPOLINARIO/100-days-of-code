using System;
using System.Collections.Generic;
using System.Linq;

namespace MergeSortedArrays
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums1 = new int[6] { 1, 2, 3, 0, 0, 0 };
            int[] nums2 = new int[3] { 2, 5, 6 };

            int[] output = ArraysMgr.EasyMergeArrays(nums1, nums2);
            Console.WriteLine(output);
        }        
    }

    public static class ArraysMgr
    {
        public static int[] MergeArrays(int[] nums1, int[] nums2)
        {
            int[] output = new int[nums1.Length];
            int j = 0;

            for (int i = 0; i < nums2.Length; i++)
            {
                output[i] = nums1[i];
            }

            for (int i = nums2.Length; i < nums1.Length; i++)
            {
                output[i] = nums2[j];
                j++;
            }

            return output
                .OrderBy(i => i)
                .ToArray();
        }


        public static int[] EasyMergeArrays(int[] nums1, int[] nums2)
        {
            List<int> output = new List<int>();
            output.AddRange(nums1);
            output.AddRange(nums2);

            return output
                .Where(i => i > 0)
                .OrderBy(i => i)
                .ToArray();
        }

    }
}
