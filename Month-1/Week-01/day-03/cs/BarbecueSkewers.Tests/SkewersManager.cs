using NUnit.Framework;

namespace BarbecueSkewers.Tests
{
    public class SkewersManagerTests
    {
        private SkewersManager skewersManager;

        [SetUp]
        public void Setup() => skewersManager = new SkewersManager();

        [Test]
        public void CountByType_WithValidInput_ReturnsCorrectCount()
        {
            var inputsAndExpectedResults = new (string[] input, (int, int) expectedOutput)[]{
                (new[] {"--xo--x--ox--","--xx--x--xx--","--oo--o--oo--","--xx--x--ox--","--xx--x--ox--"},expectedOutput:(1,4)),
                (new[] { "--oooo-ooo--", "--xx--x--xx--", "--o---o--oo--", "--xx--x--ox--", "--xx--x--ox--" },expectedOutput: (2,3)),
                (new[] { "--oooo-ooo--", "--xxxxxxxx--", "--o---", "-o-----o---x--", "--o---o-----" },expectedOutput: (3,2))
            };

            foreach (var item in inputsAndExpectedResults)
            {
                var actual = skewersManager.CountByType(item.input);

                Assert.AreEqual(item.expectedOutput, actual);
            }
        }
    }
}