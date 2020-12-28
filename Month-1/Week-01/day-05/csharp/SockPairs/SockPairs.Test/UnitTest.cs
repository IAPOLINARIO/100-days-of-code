using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SockPairs.Test
{
    [TestClass]
    public class UnitTest
    {
        [TestMethod]
        public void Test_Should_Find_1_Pair()
        {
            string sockets = "AA";

            int socketPairs = Sockets.FindPairs(sockets);

            Assert.AreEqual(1, socketPairs);
        }

        [TestMethod]
        public void Test_Should_Find_2_Pairs()
        {
            string sockets = "ABABC";

            int socketPairs = Sockets.FindPairs(sockets);

            Assert.AreEqual(2, socketPairs);
        }

        [TestMethod]
        public void Test_Should_Find_4_Pairs()
        {
            string sockets = "CABBACCC";

            int socketPairs = Sockets.FindPairs(sockets);

            Assert.AreEqual(4, socketPairs);
        }

        [TestMethod]
        public void Test_Should_Find_0_Pair()
        {
            string sockets = string.Empty;

            int socketPairs = Sockets.FindPairs(sockets);

            Assert.AreEqual(0, socketPairs);
        }

        [TestMethod]
        public void Test_Should_Find_6_Pairs()
        {
            string sockets = "CCABCBCCACCC";

            int socketPairs = Sockets.FindPairs(sockets);

            Assert.AreEqual(6, socketPairs);
        }
    }
}
