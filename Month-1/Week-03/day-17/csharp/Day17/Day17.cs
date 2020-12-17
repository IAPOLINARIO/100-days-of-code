using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Linq;

namespace Day17
{
  class Day17
  {
    static void Main(string[] args)
    {
      var PrisonBreak = new PrisonBreak(args[0]);
      Console.WriteLine(PrisonBreak.FreedPrisoners());
    }
  }

  public class PrisonBreak
  {
    List<Int32> lstPrisioners;
    public PrisonBreak(String input)
    {
      lstPrisioners = convertStringToList(input);
    }

    public Int32 FreedPrisoners()
    {
      int count = 0;
      bool lookForZero = false;

      if (lstPrisioners[0] == 0) return 0;

      for (int i = 0; i < lstPrisioners.Count; i++)
      {
        if (!lookForZero && lstPrisioners[i] == 1)
        {
          count++;
          lookForZero = !lookForZero;
        }
        else if (lookForZero && lstPrisioners[i] == 0)
        {
          count++;
          lookForZero = !lookForZero;
        }
      }
      return count;
    }

    private List<int> convertStringToList(String _input)
    {
      var aux = Regex.Replace(_input, "[^0-9,]", "").Split(',').ToList();
      return aux.Select(c => Int32.Parse(c)).ToList();
    }


  }
}
