using System;
using NUnit.Framework;

namespace AppTests
{

    public class AgeCalculatorTests
    {
        private AgeCalculator ageCalculator;

        [SetUp]
        public void Setup() => ageCalculator = new AgeCalculator();

        [Test]
        public void CalcAge_WithValidStringInput_ReturnsValidResult()
        {
            var expected = 3650;
            var input = "10";
            var actual = ageCalculator.CalcAge(input);

            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void CalcAge_WithInvalidStringInput_ThrowsException()
        {
            var input = "1.0";
            TestDelegate action = () => { ageCalculator.CalcAge(input); };

            Assert.Throws<Exception>(action);
        }

        [Test]
        public void CalcAge_WithSpacedStringInput_ReturnsValidResult()
        {
            var expected = 7300;
            var input = "    20\t";
            var actual = ageCalculator.CalcAge(input);

            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void CalcAge_WithValidIntInput_ReturnsValidResult()
        {
            var expected = 10950;
            var input = 30;
            var actual = ageCalculator.CalcAge(input);

            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void CalcAge_WithNegativeInput_ThrowsException()
        {
            var input = -1;
            TestDelegate action = () => { ageCalculator.CalcAge(input); };

            Assert.Throws<Exception>(action);
        }

        [Test]
        public void CalcAge_WithZeroedInput_ThrowsException()
        {
            var input = 0;
            TestDelegate action = () => { ageCalculator.CalcAge(input); };

            Assert.Throws<Exception>(action);
        }
    }
}