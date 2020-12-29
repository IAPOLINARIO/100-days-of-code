using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NextPrime.Test
{
    [TestClass]
    public class UnitTest
    {
        [TestMethod]
        public void Test_Number_12()
        {
            int number = 12;
            int primeNumber = Numbers.GetPrimeNumberOrNext(number);
            Assert.AreEqual(13, primeNumber);
        }

        [TestMethod]
        public void Test_Number_24()
        {
            int number = 24;
            int primeNumber = Numbers.GetPrimeNumberOrNext(number);
            Assert.AreEqual(29, primeNumber);
        }

        [TestMethod]
        public void Test_Number_11()
        {
            int number = 11;
            int primeNumber = Numbers.GetPrimeNumberOrNext(number);
            Assert.AreEqual(11, primeNumber);
        }

        [TestMethod]
        public void Test_Number_200()
        {
            int number = 200;
            int primeNumber = Numbers.GetPrimeNumberOrNext(number);
            Assert.AreEqual(211, primeNumber);
        }
    }
}
