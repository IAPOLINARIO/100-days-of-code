using System;
using Xunit;
using Day13.Library;

namespace Day13.Tests
{
  public class UnitTest1
  {
    [Fact]
    public void firstFit_true()
    {
      int[] arr = { 7, 3, 7, 3 };
      var canFit = new CanFit(arr, 2);
      bool result = canFit.checkFit();
      Assert.True(result);
    }

    [Fact]
    public void secondFit_true()
    {
      int[] arr = { 2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2 };
      var canFit = new CanFit(arr, 4);
      bool result = canFit.checkFit();
      Assert.True(result);
    }

    [Fact]
    public void thirdFit_false()
    {
      int[] arr = { 2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2 };
      var canFit = new CanFit(arr, 4);
      bool result = canFit.checkFit();
      Assert.False(result);
    }
  }
}
