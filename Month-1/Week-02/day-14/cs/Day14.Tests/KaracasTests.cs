using System;
using Xunit;
using Day14.Library;

namespace Day14.Tests
{
  public class KaracasTests
  {
    [Fact]
    public void banana_0n0n0baca()
    {
      var karacas = new Karacas("banana");
      String result = "0n0n0baca";
      Assert.Equal(result, karacas.Encrypt());
    }
    [Fact]
    public void karaca()
    {
      var karacas = new Karacas("karaca");
      String result = "0c0r0kaca";
      Assert.Equal(result, karacas.Encrypt());
    }
    [Fact]
    public void burak()
    {
      var karacas = new Karacas("burak");
      String result = "k0r3baca";
      Assert.Equal(result, karacas.Encrypt());
    }
    [Fact]
    public void alpaca()
    {
      var karacas = new Karacas("alpaca");
      String result = "0c0pl0aca";
      Assert.Equal(result, karacas.Encrypt());
    }
  }
}
