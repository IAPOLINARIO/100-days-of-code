using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Barbecue.Test
{
    [TestClass]
    public class UnitTests
    {
        [TestMethod]
        public void Test_Should_2Vegetarian_3NonVegetarians()
        {
            string[] inputSkewers = { "--oooo-ooo--", "--xx--x--xx--", "--o---o--oo--", "--xx--x--ox--", "--xx--x--ox--" };

            var assessment = Barbecue.GetAssesment(inputSkewers);

            Assert.AreEqual(assessment["Vegetarians"], 2);
            Assert.AreEqual(assessment["NonVegetarians"], 3);
        }

        [TestMethod]
        public void Test_Should_3Vegetarian_2NonVegetarians()
        {
            string[] inputSkewers = { "--oooo-ooo--", "--xxxxxxxx--", "--o---", "-o-----o---x--", "--o---o-----" };

            var assessment = Barbecue.GetAssesment(inputSkewers);

            Assert.AreEqual(assessment["Vegetarians"], 3);
            Assert.AreEqual(assessment["NonVegetarians"], 2);
        }
    }
}
