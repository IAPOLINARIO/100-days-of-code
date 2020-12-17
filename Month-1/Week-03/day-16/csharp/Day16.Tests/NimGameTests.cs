using System;
using Xunit;
using Day16.Library;

namespace Day16.Tests
{
  public class UnitTest1
  {
    [Fact]
    public void True_1()
    {
      var nimGame = new NimGame("1");
      var result = nimGame.IWin();
      Assert.True(result);

    }
    [Fact]
    public void True_2()
    {
      var nimGame = new NimGame("2");
      var result = nimGame.IWin();
      Assert.True(result);

    }
    [Fact]
    public void False_4()
    {
      var nimGame = new NimGame("4");
      var result = nimGame.IWin();
      Assert.False(result);

    }
  }
}
