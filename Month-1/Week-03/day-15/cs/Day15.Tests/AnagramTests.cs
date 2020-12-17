using System;
using Xunit;
using Day15.Library;

namespace Day15.Tests
{
  public class UnitTest1
  {
    [Fact]
    public void Anagram_True()
    {
      var anagram = new Anagram("anagram", "nagaram");
      bool result = anagram.isAnagram();
      Assert.True(result);
    }

    [Fact]
    public void Anagram_False()
    {
      var anagram = new Anagram("rat", "car");
      bool result = anagram.isAnagram();
      Assert.False(result);
    }
  }
}
