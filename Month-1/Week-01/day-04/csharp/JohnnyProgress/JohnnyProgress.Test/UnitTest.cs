using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JohnnyProgress.Test
{
    [TestClass]
    public class UnitTest
    {
        [TestMethod]
        public void Test_Progress_1()
        {
            int[] progressDays = new int[] { 3, 4, 1, 2 };

            int totalProgress = Progress.GetProgressCount(progressDays);

            Assert.AreEqual(2, totalProgress);
        }

        [TestMethod]
        public void Test_Progress_2()
        {
            int[] progressDays = new int[] { 10, 11, 12, 9, 10 };

            int totalProgress = Progress.GetProgressCount(progressDays);

            Assert.AreEqual(3, totalProgress);
        }

        [TestMethod]
        public void Test_Progress_3()
        {
            int[] progressDays = new int[] { 6, 5, 4, 3, 2, 9 };

            int totalProgress = Progress.GetProgressCount(progressDays);

            Assert.AreEqual(1, totalProgress);
        }

        [TestMethod]
        public void Test_Progress_4()
        {
            int[] progressDays = new int[] { 9, 9 };

            int totalProgress = Progress.GetProgressCount(progressDays);

            Assert.AreEqual(0, totalProgress);
        }
    }
}
