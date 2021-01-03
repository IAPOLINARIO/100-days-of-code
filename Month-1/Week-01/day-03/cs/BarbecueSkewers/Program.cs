using System;
using System.Collections.Generic;
using System.Linq;

var sampleSkewer = new[]{"--oooo-ooo--",
  "--xx--x--xx--",
  "--o---o--oo--",
  "--xx--x--ox--",
  "--xx--x--ox--"};

Console.WriteLine($"Skewers: '{string.Join(',', sampleSkewer)}'");

var countedSkewers = new SkewersManager().CountByType(sampleSkewer);

Console.WriteLine($"Vegetarians {countedSkewers.vegeratianSkewersCount} | Non-Vegeratian {countedSkewers.otherSkewersCount}");

public class SkewersManager
{
    public (int vegeratianSkewersCount, int otherSkewersCount) CountByType(IEnumerable<string> skewers)
    {
        var vegeratianSkewersCount = skewers.Count(skewer => skewer.Contains("-o") && !skewer.Contains('x'));
        var otherSkewersCount = skewers.Count() - vegeratianSkewersCount;

        return (vegeratianSkewersCount, otherSkewersCount);
    }
}