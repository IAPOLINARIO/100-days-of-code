using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FindingNemo.Test
{
    [TestClass]
    public class UnitTests
    {
        [TestMethod]
        public void Test_ShouldFindNemo_Index4()
        {
            string stringTest = "I am finding Nemo !";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(4, indexNemo);
        }

        [TestMethod]
        public void Test_ShouldFindNemo_Index1()
        {
            string stringTest = "Nemo is me";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(1, indexNemo);
        }

        [TestMethod]
        public void Test_ShouldFindNemo_Index2()
        {
            string stringTest = "I Nemo am";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(2, indexNemo);
        }

        [TestMethod]
        public void Test_ShouldFindFirstNemo()
        {
            string stringTest = "I Nemo am, and there is another Nemo";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(2, indexNemo);
        }

        [TestMethod]
        public void Test_ShouldNotFindNemo_CaseInsensitive()
        {
            string stringTest = "I NeMO am";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(0, indexNemo);
        }

        [TestMethod]
        public void Test_ShouldNotFindNemo_LastIndex()
        {
            string stringTest = "I lost here but I am Nemo";

            int indexNemo = Indexer.GetIndexNemo(stringTest);

            Assert.AreEqual(7, indexNemo);
        }
    }
}
