using System;
using System.Collections.Generic;
using System.Linq;

namespace Day12.Library
{
  public class LandscapeType
  {
    List<char> _input;
    public LandscapeType(String input)
    {
      this._input = input.Where(c => char.IsDigit(c)).ToList();
    }
    private bool isMontain()
    {
      int i = 1;
      while (i < _input.Count && _input[i] > _input[i - 1])
      {
        i++;
      }
      if (i == 1 || i == _input.Count) return false;
      while (i < _input.Count && _input[i] < _input[i - 1])
      {
        i++;
      }

      return i == _input.Count;
    }
    private bool isValley()
    {
      int i = 1;
      while (i < _input.Count && _input[i] < _input[i - 1])
      {
        i++;
      }
      if (i == 1 || i == _input.Count) return false;
      while (i < _input.Count && _input[i] > _input[i - 1])
      {
        i++;
      }

      return i == _input.Count;
    }
    public String Type()
    {
      if (isMontain()) return "mountain";
      else if (isValley()) return "valley";
      else return "neither";
    }
  }
}
