using System;
using Xunit;
using Day17;

namespace Day17
{
  public class Day17Tests
  {
    [Fact]
    public void freedPrisoners_1()
    {
      var prisonBreak = new PrisonBreak("[1, 1, 0, 0, 0, 1, 0]");
      var result = prisonBreak.FreedPrisoners();
      Assert.Equal(4, result);
    }

    [Fact]
    public void freedPrisoners_2()
    {
      var prisonBreak = new PrisonBreak("[1, 1, 1]");
      var result = prisonBreak.FreedPrisoners();
      Assert.Equal(1, result);
    }

    [Fact]
    public void freedPrisoners_3()
    {
      var prisonBreak = new PrisonBreak("[0, 0, 0]");
      var result = prisonBreak.FreedPrisoners();
      Assert.Equal(0, result);
    }

    [Fact]
    public void freedPrisoners_4()
    {
      var prisonBreak = new PrisonBreak("[0, 1, 1, 1]");
      var result = prisonBreak.FreedPrisoners();
      Assert.Equal(0, result);
    }
  }
}