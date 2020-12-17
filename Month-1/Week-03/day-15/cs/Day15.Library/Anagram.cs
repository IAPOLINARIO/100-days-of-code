using System;
using System.Linq;

namespace Day15.Library
{
  public class Anagram
  {
    String _first, _second;
    public Anagram(String first, String second)
    {
      _first = first;
      _second = second;
    }
    public bool isAnagram()
    {
      return _first.OrderBy(a => a).SequenceEqual(_second.OrderBy(a => a));
    }
  }
}