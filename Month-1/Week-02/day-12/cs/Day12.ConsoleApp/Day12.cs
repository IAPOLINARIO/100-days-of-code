using System;
using Day12.Library;

namespace Day12.ConsoleApp
{
  class Day12
  {
    static void Main(string[] args)
    {
      Console.WriteLine("Let me Identify if its a montain, a valley or nothing");
      var input = Console.ReadLine();
      Console.WriteLine(input);
      Console.WriteLine(new LandscapeType(input).Type());
    }
  }

}
