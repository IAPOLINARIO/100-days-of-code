using System;
using Xunit;

namespace Day18
{
  public class Day18Tests
  {
    [Fact]
    public void MyIntegrationTest()
    {
      var uniquePath = new UniquePath("3","2");
      var result = uniquePath.Calculate();
      Assert.Equal(3, result);
    }

    [Fact]
    public void MyIntegrationTest_2()
    {
      var uniquePath = new UniquePath("7", "3");
      var result = uniquePath.Calculate();
      Assert.Equal(28, result);
    }

    [Fact]
    public void MyIntegrationTest_3()
    {
      var uniquePath = new UniquePath("3", "3");
      var result = uniquePath.Calculate();
      Assert.Equal(6, result);
    }
  }
}
