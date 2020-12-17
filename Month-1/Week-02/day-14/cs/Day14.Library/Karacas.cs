using System;
using System.Linq;

namespace Day14.Library
{
  public class Karacas
  {
    String _input;
    public Karacas(String input)
    {
      _input = input;
    }

    public String Encrypt()
    {
      String result = new string(_input.Reverse().ToArray());

      result = doReplaces(result);

      result += "aca";

      return result;
    }

    private static string doReplaces(string result)
    {
      result = result.Replace("a", "0");
      result = result.Replace("e", "1");
      result = result.Replace("i", "2");
      result = result.Replace("o", "2");
      result = result.Replace("u", "3");
      return result;
    }
  }
}
