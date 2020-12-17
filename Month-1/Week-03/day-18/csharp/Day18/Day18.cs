using System;

namespace Day18
{
  class Day18
  {
    static void Main(string[] args)
    {
      Console.WriteLine("Hello World!");
    }
  }

  public class UniquePath
  {
    Int32 m, n, result = 1;
    public UniquePath(String _m, String _n)
    {
      m = Int32.Parse(_m);
      n = Int32.Parse(_n);
    }

    public Int32 Calculate()
    {

      int[][] unique = new int[n - 1][];

      for (int i = 0; i < unique.Length; i++)
      {
        unique[i] = new int[m - 1];
        for (int j = 0; j < unique[i].Length; j++)
        {
          if (j == 0 || i == 0)
            unique[i][j] = 1;
          else
            unique[i][j] = unique[i][j - 1] + unique[i - 1][j];

          result += unique[i][j];
        }
      }
      return result;
    }

  }
}
