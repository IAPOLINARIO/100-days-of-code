using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;


namespace MergeSortedArrays.Test
{
    [TestClass]
    public class UnitTest
    {
        readonly int[] nums1 = new int[6] { 1, 2, 3, 0, 0, 0 };
        readonly int[] nums2 = new int[3] { 2, 5, 6 };
        readonly int[] desiredResult = new int[6] { 1, 2, 2, 3, 5, 6 };

        [TestMethod]
        public void Test_MergeArrays()
        {
            int[] output = ArraysMgr.MergeArrays(nums1, nums2);

            desiredResult.Should().BeEquivalentTo(output);            
        }

        [TestMethod]
        public void Test_EasyMergeArrays()
        {
            int[] output = ArraysMgr.EasyMergeArrays(nums1, nums2);

            desiredResult.Should().BeEquivalentTo(output);
        }
    }
}
