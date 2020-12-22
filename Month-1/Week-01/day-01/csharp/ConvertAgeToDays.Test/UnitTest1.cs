using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace ConvertAgeToDays.Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void Test_65Years()
        {
            int convertedYears = AgeConverter.AgeintoDays(65);
            Assert.AreEqual(23725, convertedYears);
        }
        [TestMethod]
        public void Test_20Years()
        {
            int convertedYears = AgeConverter.AgeintoDays(20);
            Assert.AreEqual(7300, convertedYears);
        }
        [TestMethod]
        public void Test_37Years()
        {
            int convertedYears = AgeConverter.AgeintoDays(37);
            Assert.AreEqual(13505, convertedYears);
        }
        [TestMethod]
        public void Test_0Years()
        {
            int convertedYears = AgeConverter.AgeintoDays(0);
            Assert.AreEqual(0, convertedYears);
        }
    }
}
