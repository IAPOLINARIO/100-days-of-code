using Microsoft.VisualStudio.TestTools.UnitTesting;
using PhoneLetterCombinations;
using FluentAssertions;
using System.Collections.Generic;

namespace LetterCombinations.Test
{
    [TestClass]
    public class UnitTest
    {
        [TestMethod]
        public void Test_Input_Empty()
        {
            string input = "";
            var letterCombined = Letters.Combiner(input);

            Assert.AreEqual(letterCombined.Count, 0);
        }

        [TestMethod]
        public void Test_Input_2()
        {
            string input = "2";

            var letterCombined = Letters.Combiner(input);
            var desiredCombination = new List<string>() { "a", "b", "c" };

            desiredCombination.Should().BeEquivalentTo(letterCombined);
        }

        [TestMethod]
        public void Test_Input_23()
        {
            string input = "23";

            var letterCombined = Letters.Combiner(input);
            var desiredCombination = new List<string>() { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };

            desiredCombination.Should().BeEquivalentTo(letterCombined);
        }

        [TestMethod]
        public void Test_Input_234()
        {
            string input = "234";

            var letterCombined = Letters.Combiner(input);
            var desiredCombination = new List<string>()
            { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf", "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" };

            desiredCombination.Should().BeEquivalentTo(letterCombined);
        }

        [TestMethod]
        public void Test_Input_123_InputValidation()
        {
            string input = "1234";

            var validationInput = Letters.IsValidInput(input);

            Assert.AreEqual(validationInput, false);
        }
    }
}
