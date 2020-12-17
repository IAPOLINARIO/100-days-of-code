using System;
using Xunit;
using Day12.Library;

namespace Day12.Test
{
  public class Day12Test
  {
    const String MOUNTAIN = "mountain", VALLEY = "valley", NEITHER = "neither";

    [Fact]
    public void shouldBeMountain_peak5()
    {
      var landscapeType = new LandscapeType("[3, 4, 5, 4, 3]");
      String result = landscapeType.Type();
      Assert.Equal(MOUNTAIN, result);
    }

    [Fact]
    public void shouldBeValley_trough1()
    {
      var landscapeType = new LandscapeType("[9, 7, 3, 1, 2, 4]");
      String result = landscapeType.Type();
      Assert.Equal(VALLEY, result);
    }

    [Fact]
    public void shouldBeValley_trough8()
    {
      var landscapeType = new LandscapeType("[9, 8, 9]");
      String result = landscapeType.Type();
      Assert.Equal(VALLEY, result);
    }
    [Fact]
    public void shouldBeNeither()
    {
      var landscapeType = new LandscapeType("[9, 8, 9, 8]");
      String result = landscapeType.Type();
      Assert.Equal(NEITHER, result);
    }
  }
}
