using NUnit.Framework;

namespace FindingNemo.Tests
{
    public class NemoFinderTests
    {
        private NemoFinder nemoFinder;

        [SetUp]
        public void Setup() => nemoFinder = new NemoFinder();

        [TestCase("I am finding Nemo !", 4)]
        [TestCase("Nemo is me", 1)]
        [TestCase("I Nemo am", 2)]
        [TestCase("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer sed ex dui. Proin gravida quam in turpis rutrum fermentum. Cras suscipit gravida elit non viverra. In sit amet tortor et dolor ornare malesuada. Cras placerat augue non enim dictum, ut tempus dui posuere. Aliquam vitae purus euismod, iaculis lorem at, tempus orci. Fusce vulputate magna sed ullamcorper lobortis. Nunc vehicula orci in sapien rutrum, ut dapibus orci volutpat. Praesent rhoncus aliquam ligula, in dapibus enim tristique nec. Nulla et dictum eros. Nullam sollicitudin ante tellus, quis consectetur leo vulputate Nemo eget. Phasellus a molestie nisl, sed ornare elit. Aenean sem nunc, porttitor et odio et, vestibulum fringilla est.", 90)]
        public void NemoFinder_WithValidPhrasing_ReturnsValidResult(string message, int expectedIndex)
        {
            var expected = $"I found Nemo at {expectedIndex}!";
            var actual = nemoFinder.FindNemo(message);

            Assert.AreEqual(expected, actual);
        }

        [TestCase("")]
        [TestCase("Message without the expected value")]
        [TestCase("NeMo casing shouldn't work")]
        [TestCase("Nemo's shouldn't work")]
        [TestCase("PrefixedNemo shouldn't work")]
        public void NemoFinder_WithNoNemo_ReturnsProperMessage(string message)
        {
            var expected = "I can't find Nemo :(";
            var actual = nemoFinder.FindNemo(message);

            Assert.AreEqual(expected, actual);
        }
    }
}